#include <iostream>

using namespace std;

int main()
{
    //Question 1
    for (int i = 1000; i <= 9999; i++)
    {
        int sum = 0;

        for (int j = 1; j < i; j++)
            if (i % j == 0)
                sum += j;

        if (i == sum)
            cout << i << endl;
    }

    cout << endl;

    //Question 2
    for (int i = 100; i <= 999; i++)
    {
        int sum = 0;

        int a = i / 100, b = i / 10 - 10 * a, c = i - 100 * a - 10 * b;
        //cout << i << ": " << a << ", " << b << ", " << c << endl;
        sum += a * a * a;
        sum += b * b * b;
        sum += c * c * c;

        if (sum == i)
            cout << i << endl;
    }

    cout << endl;

    //Question 3
    cout << "| 8 | 1 | 2 | 8 |" << endl;
    cout << "| - | 1 | - | 2 |" << endl;
    cout << "| 8 | 1 | 1 | 8 |" << endl;
    cout << "| - | 3 | 7 | 1 |" << endl;

    return 0;
}