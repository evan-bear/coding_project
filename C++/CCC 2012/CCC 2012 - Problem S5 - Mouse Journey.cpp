#include <bits/stdc++.h>

using namespace std;

int R, C, K;
int lab[26][26];
bool fix[26][26];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        lab[r][c] = 0;
        fix[r][c] = true;
    }

    lab[1][1] = 1;
    fix[1][1] = true;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (!fix[i][j])
                lab[i][j] = lab[i - 1][j] + lab[i][j - 1];

    cout << lab[R][C] << '\n';

    return 0;
}
