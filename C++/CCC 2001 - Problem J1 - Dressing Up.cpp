#include <iostream>

using namespace std;

void stars(int i)
{
    for (int j = 0; j < i; j++)
        cout << "*";
}

void spaces(int i, int s)
{
    for (int j = 0; j < s - i; j++)
        cout << " ";
}

int main()
{
    int a = 0;
    cin >> a;

    for (int i = 1; i <= a; i += 2)
    {
        stars(i);
        spaces(i, a);
        spaces(i, a);
        stars(i);
        cout << endl;
    }

    if (a % 2 == 0)
        for (int i = a - 1; i > 0; i -= 2)
        {
            stars(i);
            spaces(i, a);
            spaces(i, a);
            stars(i);
            cout << endl;
        }
    else
        for (int i = a - 2; i > 0; i -= 2)
        {
            stars(i);
            spaces(i, a);
            spaces(i, a);
            stars(i);
            cout << endl;
        }

    return 0;
}