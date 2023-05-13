#include <iomanip>
#include <iostream>

#include <fstream>

#include <cmath>

using namespace std;

int main()
{
    ifstream fi;
    ofstream fo;
    fi.open("frac.in", ios::in);
    fo.open("frac.out", ios::out);
    
    char fractal[243][243] = {};

    int d, n;
    fi >> d;

    for (int i = 0; i < d; i++)
    {
        fi >> n;
        for (int j = 0; j < pow(3, n); j++)
            for (int k = 0; k < pow(3, n); k++)
            {
                int x = j;
                int y = k;
                char c = '*';

                for (int l = n; l > 0; l--)
                {
                    x = x % int(pow(3, l));
                    y = y % int(pow(3, l));
                    if (x / int(pow(3, l - 1)) == 1 && y / int(pow(3, l - 1)) == 1)
                    {
                        c = ' ';
                        break;
                    }
                }

                fractal[j][k] = c;
            }

        int b, t, l, r;
        fi >> b >> t >> l >> r;

        t = int(pow(3, n)) - t;
        b = int(pow(3, n)) - b;
        for (int j = t; j <= b; j++)
        {
            for (int k = l - 1; k <= r - 1; k++)
                fo << fractal[j][k] << "  ";
            fo << endl;
        }
    }

    return 0;
}