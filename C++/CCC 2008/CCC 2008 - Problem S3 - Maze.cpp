#include <bits/stdc++.h>

using namespace std;

int t;
int r, c;
int visited[20][20];
vector<pair<int, int>> adj[20][20];
int bfs(pair<int, int> start, pair<int, int> destination);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int z = 0; z < t; z++)
    {
        cin >> r >> c;
        pair<int, int> start(0, 0), end(r - 1, c - 1);
        char map[r][c];

        for (int i = 0; i < r; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < c; j++)
                map[i][j] = row[j];
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] == '+')
                {
                    if (i - 1 >= 0 && map[i - 1][j] != '*')
                        adj[i][j].push_back(pair<int, int>(i - 1, j));
                    if (j - 1 >= 0 && map[i][j - 1] != '*')
                        adj[i][j].push_back(pair<int, int>(i, j - 1));
                    if (i + 1 < r && map[i + 1][j] != '*')
                        adj[i][j].push_back(pair<int, int>(i + 1, j));
                    if (j + 1 < c && map[i][j + 1] != '*')
                        adj[i][j].push_back(pair<int, int>(i, j + 1));
                }
                else if (map[i][j] == '|')
                {
                    if (i - 1 >= 0 && map[i - 1][j] != '*')
                        adj[i][j].push_back(pair<int, int>(i - 1, j));
                    if (i + 1 < r && map[i + 1][j] != '*')
                        adj[i][j].push_back(pair<int, int>(i + 1, j));
                }
                else if (map[i][j] == '-')
                {
                    if (j - 1 >= 0 && map[i][j - 1] != '*')
                        adj[i][j].push_back(pair<int, int>(i, j - 1));
                    if (j + 1 < c && map[i][j + 1] != '*')
                        adj[i][j].push_back(pair<int, int>(i, j + 1));
                }
            }

        cout << bfs(start, end) + 1 << '\n';
    }

    return 0;
}

int bfs(pair<int, int> start, pair<int, int> destination)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            visited[i][j] = -1;

    // finish from here...
}
