#include <iostream>

using namespace std;

bool isrotatable(int x)
{
    int arr[5] = {};
    int i = 0;
    bool isokay = true;

    while (x != 0)
    {
        i++;
        arr[i] = x % 10;
        x /= 10;
    }

    for (int j = 0; j <= i; j++)
    {
        if (arr[j] == 0 && arr[i - j + 1] == 0)
            continue;
        if (arr[j] == 1 && arr[i - j + 1] == 1)
            continue;
        if (arr[j] == 8 && arr[i - j + 1] == 8)
            continue;
        if (arr[j] == 6 && arr[i - j + 1] == 9)
            continue;
        if (arr[j] == 9 && arr[i - j + 1] == 6)
            continue;
        else
            isokay = false;
    }

    return isokay;
}

int main()
{
    int low, high;
    int count = 0;

    cout << "Enter the lower bound of the interval:" << endl;
    cin >> low;
    cout << "Enter the upper bound of the interval:" << endl;
    cin >> high;

    for (int i = low; i <= high; i++)
        if (isrotatable(i))
            count++;

    cout << count << endl;

    return 0;
}
