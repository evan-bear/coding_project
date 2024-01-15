#include <bits/stdc++.h>

using namespace std;

bool winning(string s, int t)
{
    int score[4];

    if (s[0] == 'W')
    {
        score[0] += 3;
        score[1] += 0;
    }
    else if (s[0] == 'L')
    {
        score[0] += 1;
        score[1] += 1;
    }
    else
    {
        score[0] += 0;
        score[1] += 3;
    }

    if (s[1] == 'W')
    {
        score[0] += 3;
        score[2] += 0;
    }
    else if (s[1] == 'L')
    {
        score[0] += 1;
        score[2] += 1;
    }
    else
    {
        score[0] += 0;
        score[2] += 3;
    }

    if (s[2] == 'W')
    {
        score[0] += 3;
        score[3] += 0;
    }
    else if (s[2] == 'L')
    {
        score[0] += 1;
        score[3] += 1;
    }
    else
    {
        score[0] += 0;
        score[3] += 3;
    }

    if (s[3] == 'W')
    {
        score[1] += 3;
        score[2] += 0;
    }
    else if (s[3] == 'L')
    {
        score[1] += 1;
        score[2] += 1;
    }
    else
    {
        score[1] += 0;
        score[2] += 3;
    }

    if (s[4] == 'W')
    {
        score[1] += 3;
        score[3] += 0;
    }
    else if (s[4] == 'L')
    {
        score[1] += 1;
        score[3] += 1;
    }
    else
    {
        score[1] += 0;
        score[3] += 3;
    }

    if (s[5] == 'W')
    {
        score[2] += 3;
        score[3] += 0;
    }
    else if (s[5] == 'L')
    {
        score[2] += 1;
        score[3] += 1;
    }
    else
    {
        score[2] += 0;
        score[3] += 3;
    }

    for (int i = 0; i < 4 && i != t; i++)
        if (score[i] >= score[t])
            return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, G;
    int A, B, Sa, Sb;
    string original = "------";

    cin >> T >> G;
    T--;
    for (int i = 0; i < G; i++)
    {
        cin >> A >> B >> Sa >> Sb;
        char ch;
        if (Sa > Sb)
            ch = 'W';
        else if (Sa < Sb)
            ch = 'L';
        else
            ch = 'T';

        if (A == 0 && B == 1)
            original = ch + original.substr(1);
        else if (A == 0 && B == 2)
            original = original.substr(0, 1) + ch + original.substr(2);
        else if (A == 0 && B == 3)
            original = original.substr(0, 1) + ch + original.substr(2);
        else if (A == 1 && B == 2)
            original = original.substr(0, 1) + ch + original.substr(2);
        else if (A == 1 && B == 3)
            original = original.substr(0, 1) + ch + original.substr(2);
        else if (A == 2 && B == 3)
            original = original.substr(0, 1) + ch + original.substr(2);
    }

    string choice = "WLT";
    vector<string> possible;
    vector<int> gto;
    for (int i = 0; i < 6; i++)
        if (original[i] == '-')
            gto.push_back(3);
        else
            gto.push_back(1);

    for (int a = 0; a < gto[0]; a++)
        for (int b = 0; b < gto[1]; b++)
            for (int c = 0; c < gto[2]; c++)
                for (int d = 0; d < gto[3]; d++)
                    for (int e = 0; e < gto[4]; e++)
                        for (int f = 0; f < gto[5]; f++)
                        {
                            string s = "";

                            if (gto[0] == 1)
                                s += original[0];
                            else
                                s += choice[a];

                            if (gto[1] == 1)
                                s += original[0];
                            else
                                s += choice[b];

                            if (gto[2] == 1)
                                s += original[0];
                            else
                                s += choice[c];

                            if (gto[3] == 1)
                                s += original[0];
                            else
                                s += choice[d];

                            if (gto[4] == 1)
                                s += original[0];
                            else
                                s += choice[e];

                            if (gto[5] == 1)
                                s += original[0];
                            else
                                s += choice[f];

                            possible.push_back(s);
                        }

    int count = 0;
    for (auto s : possible)
        if (winning(s, T))
            count++;

    cout << count << '\n';

    return 0;
}