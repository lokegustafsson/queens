#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<ll>

int main()
{
    vector<string> paths = {
        "results/1_queens.out", "results/2_queens.out",
        "results/3_queens.out", "results/4_queens.out",
        "results/5_queens.out", "results/6_queens.out",
        "results/7_queens.out", "results/8_queens.out",
        "results/9_queens.out", "results/10_queens.out",
        "results/11_queens.out", "results/12_queens.out",
        "results/13_queens.out", "results/14_queens.out",
        "results/15_queens.out", "results/16_queens.out",
        "results/17_queens.out", "results/18_queens.out",
        "results/19_queens.out", "results/20_queens.out",
    };

    ifstream fin;
    double total = 0;

    fstream fscore("scores.txt", ios::in);
    double oldSum; fscore >> oldSum;
    vi scores(20);

    for (int i = 0; i < 20; i++)
    {
        fscore >> scores[i];
        fin.open(paths[i]);
        int n, s;
        fin >> n >> s;
        total += s;
        cout << n << ": " << s;
        if (scores[i] != s)
        {
            cout << " (From " << scores[i] << ")";
        }
        cout << endl;
        scores[i] = s;
        fin.close();
    }
    cout << "-------" << endl;
    cout << "Sum went from " << oldSum << " to " << total << endl;
    fscore.close();
    fscore.open("scores.txt", ios::out|ios::trunc);
    fscore << total << endl;
    for (int i = 0; i < 20; i++)
    {
        fscore << scores[i] << " ";
    }
    fscore << endl;
    fscore.close();
    return 0;
}