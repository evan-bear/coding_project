#include <bits/stdc++.h>

using namespace std;

int answer;

void recurse(int i, stack<int> s, int card[4], bool used[4])
{
    if (s.size() == 1 && i == 4)
    {
        if (s.top() > answer && s.top() <= 24)
            answer = s.top();
        return;
    }

    if (i < 4)
        for (int j = 0; j < 4; j++)
            if (!used[j])
            {
                used[j] = true;
                stack<int> s2 = s;
                s2.push(card[j]);
                recurse(i + 1, s2, card, used);
                used[j] = false;
            }

    if (s.size() >= 2)
    {
        stack<int> t1 = s;
        int b = t1.top(); t1.pop();
        int a = t1.top(); t1.pop();

        stack<int> t2 = t1;
        t2.push(a + b);
        recurse(i, t2, card, used);

        t2 = t1;
        t2.push(a - b);
        recurse(i, t2, card, used);

        t2 = t1;
        t2.push(a * b);
        recurse(i, t2, card, used);

        if (b != 0 && a % b == 0)
        {
            t2 = t1;
            t2.push(a / b);
            recurse(i, t2, card, used);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int card[4];
    bool used[4];

    for (int z = 0; z < N; z++)
    {
        answer = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> card[i];
            used[i] = false;
        }

        stack<int> st;
        recurse(0, st, card, used);
        cout << answer << '\n';
    }

    return 0;
}
