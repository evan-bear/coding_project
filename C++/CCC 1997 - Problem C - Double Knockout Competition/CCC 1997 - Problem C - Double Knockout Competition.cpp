#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("dkc.in", ios::in);
    ofile.open("dkc.out", ios::out);

    int n, x, ud, ol, el, count;
    ifile >> n;

    for (int i = 0; i < n; i++)
    {
        ifile >> x;
        ud = x;
        ol = 0;
        el = 0;
        count = 0;

        while (ud != 0 || ol != 1)
        {
            ofile << "Round " << count << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated" << endl;

            if (ud == 1 && ol == 1)
            {
                ol++;
                ud--;
            }
            else
            {
                el += ol / 2;
                ol = ol / 2 + ud / 2;
                ud /= 2;
            }

            count++;
        }

        ofile << "Round " << count << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated" << endl;
        ofile << "There are " << count << " rounds." << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
