#include <bits/stdc++.h>

using namespace std;

int R(char x)
{
    if (x == 'I')
        return 1;
    else if (x == 'V')
        return 5;
    else if (x == 'X')
        return 10;
    else if (x == 'L')
        return 50;
    else if (x == 'C')
        return 100;
    else if (x == 'D')
        return 500;
    else
        return 1000;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string aromatic;
    int oldr = 99999, olds = 0;
    int value = 0;

    cin >> aromatic;

    for (int i = 0; i < aromatic.size(); i += 2)
    {
        int a = aromatic[i] - 48;
        int r = R(aromatic[i + 1]);
        int s = a * r;

        value += s;
        if (r > oldr)
            value -= 2 * olds;

        olds = s;
        oldr = r;
    }

    cout << value << endl;

    return 0;
}