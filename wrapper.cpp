#include <bits/stdc++.h>
#include "solution.h"
using namespace std;
typedef long long ll;

// USAGE
// ./queens <inPath> <outPath> <iterations>
int main(int argc, char *argv[])
{
    srand(time(0));
    assert(argc == 4);
    vector<vector<char>> board; 
    ll n;
    {
        ifstream fin(argv[1]);
        fin >> n;
        board = vector<vector<char>>(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> board[i][j];
            }
        }
        fin.close();
    }
    for (ll iteration = 1; iteration < stoi(argv[3]); iteration++)
    {
        auto p = solve(n, board);
        ll ans = p.first;
        vector<vector<char>> ansBoard = p.second; 

        ll oldAns = -1;
        bool doWrite = true;
        fstream fout(argv[2], ios::in);
        if (fout.is_open())
        {
            ll temp;
            fout >> temp >> oldAns;
            assert(temp==n);
            doWrite = (ans > oldAns);
            fout.close();
        }
        if (doWrite)
        {
            cout << n << ", " << iteration << ":  Improved from " << oldAns << " to " << ans << endl;
            fout.open(argv[2], ios::out|ios::trunc);
            fout << n << " " << ans << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << ansBoard[i][j];
                }
                fout << endl;
            }
            fout.close();
        }
    }
}