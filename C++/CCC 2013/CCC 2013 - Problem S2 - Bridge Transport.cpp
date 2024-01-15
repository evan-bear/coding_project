#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int W, N, w;
    int sum = 0, count = 0;
    queue<int> bridge;

    cin >> W >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w;
        if ((bridge.size() < 4 && sum + w <= W) ||
            (bridge.size() == 4 && sum + w - bridge.front() <= W))
        {
            count++;
            sum += w;
            bridge.push(w);
            if (bridge.size() > 4)
            {
                sum -= bridge.front();
                bridge.pop();
            }
        }
        else
            break;
    }

    cout << count << '\n';

    return 0;
}
