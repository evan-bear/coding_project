#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, C = 0;
    cin >> N;
    char ans[N], res;

    for (int i = 0; i < N; i++)
        cin >> ans[i];

    for (int i = 0; i < N; i++)
    {
        cin >> res;
        if (res == ans[i])
            C++;
    }

    cout << C << '\n';

    return 0;
}