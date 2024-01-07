#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string name;
    vector<string> best, second;
    int r, s, d;
    int R1 = 0, S1 = 0, D1 = 0;
    int R2 = 0, S2 = 0, D2 = 0;

    int num;
    cin >> num;
    if (num == 0)
        return 0;
    for (int z = 0; z < num; z++)
    {
        cin >> name >> r >> s >> d;
        if (2 * r + 3 * s + d > 2 * R1 + 3 * S1 + D1)
        {
            second = best;
            best.clear();
            best.push_back(name);
            R2 = R1; R1 = r;
            S2 = S1; S1 = s;
            D2 = D1; D1 = d;
        }
        else if (2 * r + 3 * s + d == 2 * R1 + 3 * S1 + D1)
            best.push_back(name);
        else if (2 * r + 3 * s + d > 2 * R2 + 3 * S2 + D2)
        {
            second.clear();
            second.push_back(name);
            R2 = r;
            S2 = s;
            D2 = d;
        }
        else if (2 * r + 3 * s + d == 2 * R2 + 3 * S2 + D2)
            second.push_back(name);
    }

    sort(best.begin(), best.end());
    sort(second.begin(), second.end());
    if (best.size() == 1)
    {
        cout << best[0] << '\n';
        if (!second.empty())
            cout << second[0] << '\n';
    }
    else
    {
        cout << best[0] << '\n';
        cout << best[1] << '\n';
    }

    return 0;
}