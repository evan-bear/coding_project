#include <iostream>

using namespace std;

int main()
{
    int squarenum = 1;
    int dicenum;

    cout << "Enter sum of dice:\n ";
    cin >> dicenum;

    while (squarenum != 100)
    {
        if (dicenum == 0 || dicenum == 1)
        {
            cout << "You Quit!" << endl;
            return 0;
        }
        else
        {
            squarenum += dicenum;

            if (squarenum == 54)
                squarenum = 19;
            if (squarenum == 90)
                squarenum = 48;
            if (squarenum == 99)
                squarenum = 77;

            if (squarenum == 9)
                squarenum = 34;
            if (squarenum == 40)
                squarenum = 64;
            if (squarenum == 67)
                squarenum = 86;

            if (squarenum > 100)
                squarenum -= dicenum;

            cout << "You are now on square " << squarenum << endl;
        }

        if (squarenum != 100)
        {
            cout << "Enter sum of dice:\n ";
            cin >> dicenum;
        }
    }

    cout << "You Win!" << endl;
}