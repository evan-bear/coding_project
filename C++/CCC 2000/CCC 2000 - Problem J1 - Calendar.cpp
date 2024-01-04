#include <iostream>

#include <string>

using namespace std;

int main()
{
    int wd, ndm;

    cout << "Enter day:" << endl;
    cin >> wd;
    cout << endl;

    cout << "Enter the number of days in the month:" << endl;
    cin >> ndm;
    cout << endl;

    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;

    for (int i = 1; i <= wd; i++)
    {
        if (i == 1)
            cout << "  ";
        else
            cout << "    ";
    }

    for (int i = 1; i <= ndm; i++)
    {
        if (i == 1)
            cout << i << "   ";
        else
        {
            if (i < 9)
                cout << i << "   ";
            else
                cout << i << "  ";
        }

        wd++;
        if (wd > 7)
        {
            if (i <= 9)
                cout << endl << "  ";
            else
                cout << endl << " ";

            wd = 1;
        }
    }

    return 0;
}
