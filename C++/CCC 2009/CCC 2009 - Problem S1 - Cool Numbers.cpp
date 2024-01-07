#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int count = 0;
    int n = pow(a, 1.0 / 6), pow = n * n * n * n * n * n;

    while (pow < a)
    {
        n++;
        pow = n * n * n * n * n * n;
    }
    while (pow < b)
    {
        count++; n++;
        pow = n * n * n * n * n * n;
    }

    cout << count << '\n';

    return 0;
}
