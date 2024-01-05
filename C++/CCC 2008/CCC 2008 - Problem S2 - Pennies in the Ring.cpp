#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int radius;

    cin >> radius;
    while (radius != 0)
    {
        int count = 0;
        for (int y = -radius; y <= radius; y++)
        {
            int x_limit = sqrt(pow(radius, 2) - pow(y, 2));
            for (int x = -x_limit; x <= x_limit; x++)
                if (pow(x, 2) + pow(y, 2) <= pow(radius, 2))
                    count++;
        }

        cout << count << '\n';
        cin >> radius;
    }

    return 0;
}
