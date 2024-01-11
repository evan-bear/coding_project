#include <bits/stdc++.h>

using namespace std;

int crystal(int m, int x)
{
    if (m >= 1)
    {
        int power = (int)pow(5, m - 1);
        int loc = (int)(x / power);

        if (loc == 0 || loc == 4)
            return 0;
        else if (loc == 1 || loc == 3)
            return 1 * power + crystal(m - 1, x % power);
        else if (loc == 2)
            return 2 * power + crystal(m - 1, x % power);
    }
    return 0;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, m, x, y;

    cin >> T;
    for (int z = 0; z < T; z++)
    {
        cin >> m >> x >> y;
        if (y < crystal(m, x))
            cout << "crystal\n";
        else
            cout << "empty\n";
    }

    return 0;
}
