#include <iostream>

#include <string>

using namespace std;

void points(string& s, int& p)
{
    int i = 0;
    p = 0;

    while (i <= s.size() && s[i] != 'C' && s[i] != 'D' && s[i] != 'H' && s[i] != 'S')
    {
        cout << s[i] << " ";
        
        if (s[i] == 'J')
            p++;
        else if (s[i] == 'Q')
            p += 2;
        else if (s[i] == 'K')
            p += 3;
        else if (s[i] == 'A')
            p += 4;

        i++;
    }

    if (i + 1 == 1)
        p += 3;
    else if (i + 1 == 2)
        p += 2;
    else if (i + 1 == 3)
        p++;

    bool end = true;
    for (int j = 0; j < s.size(); j++)
        if (s[j] == 'C' || s[j] == 'D' || s[j] == 'H' || s[j] == 'S')
            end = false;
    if (!end)
        s = s.substr(i + 1);

    for (; i < 14; i++)
        cout << "  ";
}

int main()
{
    int p = 0, tp = 0;
    string s;
    
    cout << "Enter cards:" << endl;
    getline(cin, s);

    cout << endl << "Cards Dealt                          Points" << endl;

    s = s.substr(1);
    cout << "Clubs ";
    points(s, p);
    if (p < 10)
        cout << "      " << p << endl;
    else
        cout << "     " << p << endl;
    tp += p;

    cout << "Diamonds ";
    points(s, p);
    if (p < 10)
        cout << "   " << p << endl;
    else
        cout << "  " << p << endl;
    tp += p;

    cout << "Hearts ";
    points(s, p);
    if (p < 10)
        cout << "     " << p << endl;
    else
        cout << "    " << p << endl;
    tp += p;

    cout << "Spades ";
    points(s, p);
    if (p < 10)
        cout << "      " << p << endl;
    else
        cout << "     " << p << endl;
    tp += p;

    if (tp > 10)
        cout << "                                 Total " << tp;
    else
        cout << "                                  Total " << tp;

    return 0;
}

/*
Enter cards:
C258TJKD69QAHSTJA
Cards Dealt                          Points
Clubs 2 3 4 5 6 7 8 9 T J Q K A         4
Diamonds 2 3 4 5 6 7 8 9 T J Q K A      6
Hearts 2 3 4 5 6 7 8 9 T J Q K A        3
Spades 2 3 4 5 6 7 8 9 T J Q K A        5
                                   Total 18
*/
