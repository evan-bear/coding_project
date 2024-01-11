#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, s = 0, t = 0;
    string line;

    cin >> N;
    getline(cin, line);
    for (int z = 0; z < N; z++)
    {
        getline(cin, line);
        for (int i = 0; i < line.size(); i++)
            if (line[i] == 's' || line[i] == 'S')
                s++;
            else if (line[i] == 't' || line[i] == 'T')
                t++;
    }

    if (t > s)
        cout << "English\n";
    else
        cout << "French\n";

    return 0;
}
