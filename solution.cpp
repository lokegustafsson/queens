#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

typedef long long ll;

#define vi vector<ll>
#define pii pair<ll,ll>
#define rep(i, j, k) for(ll i = j; i < k; i++)

struct storage
{
    vi index; // the inverse of value
    vector<unordered_set<ll>> neighbors;
    vi value; // stores positions considered part of the storage set among the first `size` items
    ll size;
    ll len;
    ll greediness;
    storage(const ll n, const vector<vector<char>> board, const ll greedy)
    {
        greediness = greedy;
        len = n;
        size = n*n;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if (board[i][j] != 'E')
                {
                    continue;
                }
                index.push_back(i*n + j);
                value.push_back(i*n + j);
                rep(dx, -1, 2)
                {
                    rep(dy, -1, 2)
                    {
                        ll xp = i; ll yp = i;
                        while (0 <= xp && xp < n && 0 <= yp && yp < n && board[xp][yp]=='E')
                        {
                            neighbors[n*i+j].insert(n*xp+yp);
                            xp+=dx; yp+=dy;
                        }
                    }
                }
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
        }
    }
    pii pop()
    {
        ll best;
        rep(i, 0, greediness)
        {
            ll p = value[rand() % size];
            if (neighbors[p].size() < neighbors[best].size())
            {
                best = p;
            }
        }
        for (ll x : neighbors[best])
        {
            remove(pii(x/len, x%len));
            rep(i, 0, len*len)
            {
                neighbors[i].erase(x);
            }
        }
        return pii(best/len, best%len);
    }
};

pair<ll, vector<vector<char>>> solve(ll n, vector<vector<char>> board)
{
    assert(n==board.size() && n==board[0].size());

    storage possible(n, board, 1);
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            assert(board[i][j] != 'Q');
        }
    }

    pii queen;
    ll q = 0;
    while ( (queen = possible.pop()).first != -1 )
    {
        board[queen.first][queen.second] = 'Q';
        q++;
    }
    return make_pair(q, board);
}