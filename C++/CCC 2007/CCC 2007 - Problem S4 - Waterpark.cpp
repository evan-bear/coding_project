#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> dq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, n, K;
    cin >> T;

    for (int z = 0; z < T; z++) {
        cin >> n >> K;
        int tmp = n;
        while (tmp != 0) {
            int x = tmp % 10;
            push(x);
            tmp /= 10;
        }

        while (!dq.empty()) {
            cout << dq.front().first << '\n';
            pop();
        }
    }

    return 0;
}

void push(int val)
{
    int count = 0;
    while (!dq.empty() && dq.back().first < val)
    {
        count += dq.back().second + 1;
        dq.pop_back();
    }
    dq.push_back({val, count});
}
int max()
{
    return dq.front().first;
}
void pop()
{
    if (dq.front().second > 0)
    {
        dq.front().second--;
        return;
    }
    dq.pop_front();
}