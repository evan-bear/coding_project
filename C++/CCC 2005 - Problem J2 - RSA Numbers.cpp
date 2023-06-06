#include <iostream>

using namespace std;

int main()
{
    int upper, lower;
    int counter = 0;
    cout << "Enter lower limit of range" << endl;
    cin >> lower;
    cout << "Enter upper limit of range" << endl;
    cin >> upper;

    for (int i = lower; i <= upper; i++)
    {
        int divisor = 0;
        for (int j = 1; j <= i; j++)
            if (i % j == 0)
                divisor++;

        if (divisor == 4)
            counter++;
    }

    cout << "The number of RSA numbers between " << lower << " and " << upper << " is " << counter << endl;

    return 0;
}
