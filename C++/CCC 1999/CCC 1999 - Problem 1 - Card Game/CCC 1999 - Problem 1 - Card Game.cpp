#include <iostream>
#include <fstream>

#include <string>

using namespace std;

bool nohigh(int i, int x, string cards[52])
// checking if next x cards, starting at i, contain a high card.
// at the end of deck return false because no points are scored.
{
    if (i + x > 52)
        return false;

    for (int j = i + 1; j <= i + x; j++)
        if (cards[j] == "ace" || cards[j] == "king" || cards[j] == "queen" || cards[j] == "jack")
            return false;

    return true;
}

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("card.in", ios::in);
    ofile.open("card.out", ios::out);

    string cards[52] = {};
    int a = 0, b = 0, v;

    for (int i = 0; i < 52; i++)
        ifile >> cards[i];

    for (int i = 0; i < 52; i++)
    {
        if (cards[i] == "ace" && nohigh(i, 4, cards))
            v = 4;
        else if (cards[i] == "king" && nohigh(i, 3, cards))
            v = 3;
        else if (cards[i] == "queen" && nohigh(i, 2, cards))
            v = 2;
        else if (cards[i] == "jack" && nohigh(i, 1, cards))
            v = 1;
        else
            v = 0;

        if (v > 0)
        {
            string p;

            if (i % 2 == 0)
            {
                p = "A";
                a += v;
            }
            else
            {
                p = "B";
                b += v;
            }

            ofile << "Player " << p << " scores " << v << " point(s)." << endl;
        }
    }

    ofile << "Player A: " << a << " point(s)." << endl;
    ofile << "Player B: " << b << " point(s)." << endl;

    ifile.close();
    ofile.close();

    return 0;
}
