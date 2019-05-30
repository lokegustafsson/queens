#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

typedef long long ll;

#define vi vector<ll>
#define pii pair<ll,ll>
#define rep(i, j, k) for(ll i = j; i < k; i++)

struct storage
{
    vi index;
    vi value;
    ll size;
    ll len;
    storage(ll n)
    {
        len = n;
        size = n*n;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                index.push_back(i*n + j);
                value.push_back(i*n + j);
            }
        }
    }
    void remove(pii p)
    {
        ll a = p.first*len+p.second;
        if (index[a] < size)
        {
            size--;
            value[index[a]] = value[size];
            index[value[size]] = index[a];
            value[size] = a;
            index[a] = size;
        }
    }
    pii popRand()
    {
        if (size == 0)  return  pii(-1,-1);
        ll a = value[rand() % size];
        pii p = pii(a/len, a%len);
        remove(p);
        return p;
    }
};

// Places queens randomly until no more can be placed. Runs in O(n) time.
pair<ll, vector<vector<char>>> solve(ll n, vector<vector<char>> board)
{
    assert(n==board.size() && n==board[0].size());

    storage unblocked(n);
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            assert(board[i][j] != 'Q');
            if (board[i][j] == 'W')  unblocked.remove(pii(i,j));
        }
    }

    pii queen;
    ll q = 0;
    while ( (queen = unblocked.popRand()).first != -1 )
    {
        board[queen.first][queen.second] = 'Q';
        q++;
        rep (dx, -1, 2)
        {
            rep (dy, -1, 2)
            {
                pii p(queen.first + dx, queen.second+dy);
                while (0 <= p.first && p.first < n && 
                       0 <= p.second && p.second < n && 
                       board[p.first][p.second] == 'E')
                {
                    unblocked.remove(p);
                    p.first += dx; p.second += dy;
                }
            }
        }
    }
    return make_pair(q, board);
}