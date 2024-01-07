#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    char letter [20];
    string code [20];
    string binary, answer = "";

    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> letter[i] >> code[i];
    cin >> binary;

    while (binary.size() != 0)
    {
        int i = 0;
        while (binary.find(code[i]) != 0)
            i++;

        answer += letter[i];
        binary = binary.substr(code[i].length());
    }

    cout << answer << '\n';

    return 0;
}