#include <iostream>

using namespace std;

bool isinverse(int x, int n, int m)
{
    if ((x * n) % m == 1)
        return true;
    else
        return false;
}

int main()
{
    int x, m;

    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter m:" << endl;
    cin >> m;
    cout << endl;
    
    for (int i = 1; i < m; i++)
    {
        bool tmp = isinverse(x, i, m);

        if (tmp)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "No such integer exists." << endl;

    return 0;
}