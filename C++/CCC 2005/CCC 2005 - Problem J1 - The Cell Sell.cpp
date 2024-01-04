#include <iostream>

using namespace std;

int main()
{
    int daytime, evening, weekend;
    cout << "Number of daytime minutes?" << endl;
    cin >> daytime;
    cout << "Number of evening minutes?" << endl;
    cin >> evening;
    cout << "Number of weekend minutes?" << endl;
    cin >> weekend;

    float planA = 0, planB = 0;

    if (daytime > 100)
        planA += ((daytime - 100) * 0.25);
    if (daytime > 250)
        planB += ((daytime - 250) * 0.45);

    planA += (evening * 0.15);
    planB += (evening * 0.35);

    planA += (weekend * 0.20);
    planB += (weekend * 0.25);

    cout << "Plan A costs " << planA << endl;
    cout << "Plan B costs " << planB << endl;
    if (planA == planB)
        cout << "Plan A and B are the same price" << endl;
    else if (planA > planB)
        cout << "Plan B is cheapest." << endl;
    else
        cout << "Plan A is cheapest." << endl;

    return 0;
}