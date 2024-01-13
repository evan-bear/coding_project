#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int J;
    cin >> J;

    cout << ((J - 1) * (J - 2) * (J - 3)) / 6 << '\n';

    return 0;
}