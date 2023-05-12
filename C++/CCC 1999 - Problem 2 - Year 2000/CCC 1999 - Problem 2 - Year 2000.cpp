#include <iostream>
#include <fstream>

#include <string>

using namespace std;

bool lord(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    else if (c >= 'A' && c <= 'Z')
        return true;
    else if (c >= '0' && c <= '9')
        return true;
    else
        return false;

}

bool isfound(string& str, string& input)
{
    int i = str.find(input);

    if (i != -1)
        return true;
    else
        return false;
}

bool isday(string& str, int m)
{
    if (m == 2)
    {
        int i = stoi(str);

        if (i >= 1 && i <= 28)
            return true;
        else
            return false;
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        int i = stoi(str);

        if (i >= 1 && i <= 31)
            return true;
        else
            return false;
    }
    else
    {
        int i = stoi(str);

        if (i >= 1 && i <= 30)
            return true;
        else
            return false;
    }
}

bool ismonth(string& str)
{
    int i = stoi(str);

    if (i >= 1 && i <= 12)
        return true;
    else
        return false;
}

bool isyear(string& str)
{
    int i = stoi(str);

    if (i >= 0 && i <= 99)
        return true;
    else
        return false;
}

void dmy(string& str)
    // dd/mm/yy -> dd/mm/yyyy
{
    int idx = str.find("/");

    if (idx != -1)
    {
        string sub1 = str.substr(0, idx - 2);
        string sub2 = str.substr(idx - 2, 8);
        string sub3 = str.substr(idx + 6);

        if (!lord(sub1[sub1.size() - 1]) && !lord(sub3[0]))
        {
            string day = sub2.substr(0, 2);
            string month1 = sub2.substr(3, 2);
            string year1 = sub2.substr(6, 2);

            if (ismonth(month1))
            {
                int month2 = stoi(month1);

                if (isyear(year1) && isday(day, month2))
                {
                    int year2 = stoi(year1);

                    if (year2 <= 24)
                        str = sub1 + day + "/" + month1 + "/20" + year1 + sub3;
                    else
                        str = sub1 + day + "/" + month1 + "/19" + year1 + sub3;
                }
            }
        }
    }
}

void ymd(string& str)
    // yy.mm.dd -> yyyy.mm.dd
{
    int idx = str.find(".");

    if (idx != -1)
    {
        if (idx + 6 < str[str.size() - 1])
        {
            string sub1 = str.substr(0, idx - 2);
            string sub2 = str.substr(idx - 2, 8);
            string sub3 = str.substr(idx + 6);

            if (!lord(sub1[sub1.size() - 1]) && !lord(sub3[0]))
            {
                string year1 = sub2.substr(0, 2);
                string month1 = sub2.substr(3, 2);
                string day = sub2.substr(6, 2);

                if (ismonth(month1))
                {
                    int month2 = stoi(month1);

                    if (isyear(year1) && isday(day, month2))
                    {
                        int year2 = stoi(year1);

                        if (year2 <= 24)
                            str = sub1 + "20" + sub2 + sub3;
                        else
                            str = sub1 + "19" + sub2 + sub3;
                    }
                }
            }
        }
        else
            return;
    }
}

void mdy(string& str1)
    // Month dd, yy -> Month dd, yyyy
{
    string month[12] = {};
    month[0] = "January";
    month[1] = "February";
    month[2] = "March";
    month[3] = "April";
    month[4] = "May";
    month[5] = "June";
    month[6] = "July";
    month[7] = "August";
    month[8] = "September";
    month[9] = "October";
    month[10] = "November";
    month[11] = "December";
    
    for (int i = 0; i < 12; i++)
        if (isfound(str1, month[i]))
            if (str1[str1.find(month[i]) - 1] == ' ')
            {
                string str2 = str1.substr(0, str1.find(month[i]));
                string str3 = str1.substr(str1.find(month[i]));

                int idx = str1.find(month[i]);
                int sz = month[i].size();
                string sub1;

                if (!lord(str1[idx + sz]))
                {
                    sub1 = str1.substr(idx + sz + 1);

                    if (isday(sub1, i + 1))
                        if (sub1[2] == ',' && sub1[3] == ' ') {
                            string sub2 = sub1.substr(4);

                            if (isyear(sub2))
                                if (!lord(sub2[2]))
                                {
                                    int year = stoi(sub2);

                                    if (year <= 24)
                                        str1 = str2 + month[i] + " " + sub1.substr(0, 4) + "20" + sub2.substr(0, 2) + str3.substr(sz + 7);
                                    else
                                        str1 = str2 + month[i] + " " + sub1.substr(0, 4) + "19" + sub2.substr(0, 2) + str3.substr(sz + 7);
                                }
                        }
                }
            }
}

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("y2k.in", ios::in);
    ofile.open("y2k.out", ios::out);

    int a;
    ifile >> a;

    string line = "";
    getline(ifile, line);

    for (int i = 0; i < a; i++)
    {
        getline(ifile, line);

        dmy(line);
        dmy(line);
        ymd(line);
        ymd(line);
        mdy(line);
        mdy(line);

        ofile << line << endl;
    }

    ifile.close();
    ofile.close();
    
    return 0;
}
