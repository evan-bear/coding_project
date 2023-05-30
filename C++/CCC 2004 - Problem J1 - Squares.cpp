#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Number of tiles?" << endl;
    cin >> n;
    int sroot = sqrt(n);

    cout << "The largest square has side length " << sroot << endl;

    return 0;
}
