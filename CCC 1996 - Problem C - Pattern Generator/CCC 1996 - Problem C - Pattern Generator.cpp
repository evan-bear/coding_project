#include <iostream>
#include <fstream>

#include <string>

using namespace std;

string reverse(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    return str;
}

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("pat.in", ios::in);
    ofile.open("pat.out", ios::out);

    string s;
    int number, i, k, n, x;
    ifile >> number;

    for (int j = 0; j < number; j++)
    {
        ifile >> n;
        ifile >> k;
        s = "";

        for (i = 0; i < k; i++)
            s = s + "1";
        for (; i < n; i++)
            s = s + "0";
        x = s.rfind("10");

        ofile << "The bit patterns are: " << endl << endl;

        while (x >= 0)
        {
            ofile << s << endl;

            string temp = s.substr(x + 2);
            s = s.substr(0, x) + "01" + reverse(temp);
            x = s.rfind("10");
        }

        ofile << s << endl << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}