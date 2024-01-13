#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    map<int, int> freq;
    int N, R;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> R;
        if (freq.find(R) == freq.end())
            freq.insert({R, 1});
        else
            freq[R]++;
    }

    int firstf = 0, secondf = 0;
    vector<int> firstr, secondr;

    for (auto const &[r, f] : freq)
    {
        if (f > firstf)
        {
            secondf = firstf;
            firstf = f;
            secondr = firstr;
            firstr.clear();
            firstr.push_back(r);
        }
        else if (f == firstf)
            firstr.push_back(r);
        else if (f > secondf)
        {
            secondf = f;
            secondr.clear();
            secondr.push_back(r);
        }
        else if (f == secondf)
            secondr.push_back(r);
    }

    sort(firstr.begin(), firstr.end());
    sort(secondr.begin(), secondr.end());

    if (firstr.size() > 2)
        cout << firstr[firstr.size() - 1] - firstr[0];
    else if (firstr.size() == 2)
        cout << firstr[1] - firstr[0];
    else
        cout << firstr[0] - secondr[0];
    cout << '\n';

    return 0;
}