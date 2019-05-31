#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

typedef long long ll;

#define vi vector<ll>
#define pii pair<ll,ll>
#define rep(i, j, k) for(ll i = j; i < k; i++)

struct storage
{
    vi index; // the inverse of value, maps pos->index such that value[index[x]]==x for all x in the set
    vector<unordered_set<ll>> neighbors;
    vi value; // stores positions considered part of the storage set
    ll size;
    ll N;
    ll greediness;
    storage(const ll n, const vector<vector<char>> board, const ll greedy)
    {
        greediness = greedy;
        N = n;
        size = 0;
        neighbors = vector<unordered_set<ll>>(n*n);
        index = vi(n*n);
        rep(x, 0, n)
        {
            rep(y, 0, n)
            {
                if (board[x][y] != 'E')
                {
                    continue;
                }
                value.push_back(x*n + y);
                index[x*n + y] = size;
                size++;
                rep(dx, -1, 2)
                {
                    rep(dy, -1, 2)
                    {
                        if (dx == 0 && dy == 0)
                        {
                            continue;
                        }
                        ll xp = x; ll yp = y;
                        while (0 <= xp && xp < n && 0 <= yp && yp < n && board[xp][yp]=='E')
                        {
                            neighbors[x*n + y].insert(n*xp + yp);
                            xp+=dx; yp+=dy;
                        }
                    }
                }
            }
        }
    }
    void remove(ll a)
    {
        assert(index[a] < size);
        size--;
        value[index[a]] = value[size];
        index[value[size]] = index[a];
        index[a] = size;
        value.erase(value.end()-1);
    }
    pii pop()
    {
        ll best = -1;
        rep(i, 0, greediness)
        {
            ll p = value[rand() % size];
            if (best == -1 || neighbors[p].size() < neighbors[best].size())
            {
                best = p;
            }
        }
        for (ll x : neighbors[best]) // for each square seen by the new queen
        {
            remove(x);
            for (ll i : neighbors[x]) // for every square where one visible has been taken
            {
                if (neighbors[best].count(i) != 0) continue; // dont remove stuff we iterate over, also unnecessary since already called 'remove(x)'
                neighbors[i].erase(x);
            }
        }
        return pii(best/N, best%N);
    }
};

pair<ll, vector<vector<char>>> solve(ll n, vector<vector<char>> board, ll greediness)
{
    assert(n==board.size() && n==board[0].size());
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            assert(board[i][j] != 'Q');
        }
    }
    
    storage possible(n, board, greediness);

    ll q = 0;
    while ( possible.size != 0 )
    {
        pii queen = possible.pop();
        board[queen.first][queen.second] = 'Q';
        q++;
    }
    return make_pair(q, board);
}