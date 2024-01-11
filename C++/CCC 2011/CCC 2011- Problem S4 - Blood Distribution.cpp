#include <bits/stdc++.h>

using namespace std;

int blood[8], patients[8];

int units(int b, int p)
{
    int u = min(blood[b], patients[p]);
    blood[b] -= u;
    patients[p] -= u;
    return u;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; i++)
        cin >> blood[i];
    for (int i = 0; i < 8; i++)
        cin >> patients[i];

    int t1 = 0, t2 = 0;
    t1 += units(0, 0); // O-
    t1 += units(1, 1) + units(0, 1); // O+, O-
    t1 += units(2, 2) + units(0, 2); // A-, O-
    t1 += units(4, 4) + units(0, 4); // B-, O-
    t1 += units(3, 3) + units(1, 3) + units(2, 3) + units(0, 3); // A+, O+, A-, O-
    t1 += units(5, 5) + units(1, 5) + units(4, 5) + units(0, 5); // B+, O+, B-, O-
    t1 += units(6, 6) + units(4, 6) + units(2, 6) + units(0, 6); // AB-, B-, A-, O-
    t1 += units(7, 7) + units(6, 7) + units(5, 7) + units(4, 7) + units(3, 7) + units(2, 7) + units(1, 7) + units(0, 7); // AB+, leftovers

    t1 += units(0, 0); // O-
    t1 += units(1, 1) + units(0, 1); // O+, O-
    t1 += units(2, 2) + units(0, 2); // A-, O-
    t1 += units(4, 4) + units(0, 4); // B-, O-
    t1 += units(3, 3) + units(2, 3) + units(1, 3) + units(0, 3); // A+, A-, O+, O-
    t1 += units(5, 5) + units(4, 5) + units(1, 5) + units(0, 5); // B+, B-, O+, O-
    t1 += units(6, 6) + units(4, 6) + units(2, 6) + units(0, 6); // AB-, B-, A-, O-
    t1 += units(7, 7) + units(6, 7) + units(5, 7) + units(4, 7) + units(3, 7) + units(2, 7) + units(1, 7) + units(0, 7); // AB+, leftovers

    cout << max(t1, t2) << '\n';

    return 0;
}
