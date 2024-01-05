#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string coldest_city, curr_city;
    int coldest_temp, curr_temp;

    cin >> curr_city >> curr_temp;
    coldest_city = curr_city;
    coldest_temp = curr_temp;
    while (curr_city != "Waterloo")
    {
        if (curr_temp < coldest_temp)
        {
            coldest_temp = curr_temp;
            coldest_city = curr_city;
        }
        cin >> curr_city >> curr_temp;

        if (curr_city == "Waterloo" && curr_temp < coldest_temp)
            coldest_city = curr_city;
    }

    cout << coldest_city << '\n';

    return 0;
}
