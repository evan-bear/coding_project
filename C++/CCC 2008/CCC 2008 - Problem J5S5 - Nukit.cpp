#include <bits/stdc++.h>

using namespace std;

int n;
char used[1000000];

bool AABDD(int a, int b, int c, int d);
bool ABCD(int a, int b, int c, int d);
bool CCD(int a, int b, int c, int d);
bool BBB(int a, int b, int c, int d);
bool AD(int a, int b, int c, int d);
bool move(int a, int b, int c, int d);

bool LCombo(int a, int b, int c, int d);
bool WCombo(int a, int b, int c, int d);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int z = 0; z < n; z++)
    {
        for (int i = 0; i < 1000000; i++)
            used[i] = '?';

        int A, B, C, D;
        cin >> A >> B >> C >> D;

        if (WCombo(A, B, C, D)) cout << "Patrick\n";
        else cout << "Roland\n";
    }

    return 0;
}

bool AABDD(int a, int b, int c, int d)
{
    return (a >= 2 && b >= 1 && d >= 2);
}
bool ABCD(int a, int b, int c, int d)
{
    return (a >= 1 && b >= 1 && c >= 1 && d >= 1);
}
bool CCD(int a, int b, int c, int d)
{
    return (c >= 2 && d >= 1);
}
bool BBB(int a, int b, int c, int d)
{
    return (b >= 3);
}
bool AD(int a, int b, int c, int d)
{
    return (a >= 1 && d >= 1);
}
bool move(int a, int b, int c, int d)
{
    return AABDD(a, b, c, d) || ABCD(a, b, c, d) || CCD(a, b, c, d) || BBB(a, b, c, d) || AD(a, b, c, d);
}

bool LCombo(int a, int b, int c, int d)
{
    int x = a * 27000 + b * 900 + c * 30 + d;
    if (used[x] != '?')
        return used[x] == 'l';
    if (!move(a, b, c, d))
    {
        used[x] = 'l';
        return true;
    }
    else
    {
        bool tmp = true;
        if (AABDD(a, b, c, d))
            tmp = tmp && WCombo(a - 2, b - 1, c, d - 2);
        if (ABCD(a, b, c, d))
            tmp = tmp && WCombo(a - 1, b - 1, c - 1, d - 1);
        if (CCD(a, b, c, d))
            tmp = tmp && WCombo(a, b, c - 2, d - 1);
        if (BBB(a, b, c, d))
            tmp = tmp && WCombo(a, b - 3, c, d);
        if (AD(a, b, c, d))
            tmp = tmp && WCombo(a - 1, b, c, d - 1);

        if (tmp)
        {
            used[x] = 'l';
            return true;
        }
        else
        {
            used[x] = 'w';
            return false;
        }
    }
}
bool WCombo(int a, int b, int c, int d)
{
    int x = a * 27000 + b * 900 + c * 30 + d;
    if (used[x] != '?')
        return used[x] == 'w';
    if ((AABDD(a, b, c, d) && LCombo(a - 2, b - 1, c, d - 2)) ||
        (ABCD(a, b, c, d) && LCombo(a - 1, b - 1, c - 1, d - 1)) ||
        (CCD(a, b, c, d) && LCombo(a, b, c - 2, d - 1)) ||
        (BBB(a, b, c, d) && LCombo(a, b - 3, c, d)) ||
        (AD(a, b, c, d) && LCombo(a - 1, b, c, d - 1)))
    {
        used[x] = 'w';
        return true;
    }
    else
    {
        used[x] = 'l';
        return false;
    }
}
