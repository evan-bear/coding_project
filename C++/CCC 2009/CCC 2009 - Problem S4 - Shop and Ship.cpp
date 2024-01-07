#include <bits/stdc++.h>

using namespace std;

const int FILL = 999999999;

int N, T, K, D;
int ship[5001][5001], shop[5001];
bool visited[5001], improvement;

int cheapest(int d)
{
    if (visited[d])
        return shop[d];
    visited[d] = true;
    int smallest = shop[d];
    
    for (int i = 1; i <= N; i++)
        if (ship[max(i, d)][min(i, d)] + cheapest(i) < smallest)
            smallest = ship[max(i, d)][min(i, d)] + cheapest(i);
    shop[d] = smallest;

    return smallest;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        shop[i] = FILL;
        for (int j = 1; j <= N; j++)
            ship[i][j] = FILL;
        ship[i][i] = 0;
    }
    cin >> T;
    int x, y, c;
    for (int z = 0; z < T; z++)
    {
        cin >> x >> y >> c;
        if (x < y && y <= N)
            ship[y][x] = c;
        else if (y < x && x <= N)
            ship[x][y] = c;
    }
    cin >> K;
    int z, p;
    for (int i = 0; i < K; i++)
    {
        cin >> z >> p;
        if (z <= N)
            shop[z] = p;
    }
    cin >> D;

    int old = 0;
    int cheap = cheapest(D);
    while (cheap != old)
    {
        old = cheap;
        for (int i = 1; i <= N; i++)
            visited[i] = false;
        cheap = cheapest(D);
    }

    cout << cheap << '\n';

    return 0;
}