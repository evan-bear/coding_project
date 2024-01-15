#include <bits/stdc++.h>

using namespace std;

bool distinct(int year)
{
    string s = to_string(year);
    for (auto digit : s)
        if (count(s.begin(), s.end(), digit) > 1)
            return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;

    year++;
    while (!distinct(year))
        year++;
    cout << year << '\n';

    return 0;
}