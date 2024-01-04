#include <iostream>

#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<string> adj;
    vector<string> noun;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        adj.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        noun.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << adj[i] << " as " << noun[j] << endl;

    return 0;
}
