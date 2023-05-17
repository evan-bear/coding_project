#include <iostream>

using namespace std;

int main()
{
    int quarters, slot1, slot2, slot3;
    int count = 0;

    cout << "How many quarters does Martha have in the jar?" << endl;
    cin >> quarters;
    cout << endl << "How many times has the first machine been played since paying out?" << endl;
    cin >> slot1;
    cout << endl << "How many times has the second machine been played since paying out?" << endl;
    cin >> slot2;
    cout << endl << "How many times has the third machine been played since paying out?" << endl;
    cin >> slot3;

    while (quarters > 0)
    {
        quarters--;
        count++;

        slot1++;
        if (slot1 == 35)
        {
            slot1 = 0;
            quarters += 30;
        }
        if (quarters <= 0)
            break;

        quarters--;
        count++;

        slot2++;
        if (slot2 == 100)
        {
            slot2 = 0;
            quarters += 60;
        }
        if (quarters <= 0)
            break;

        quarters--;
        count++;

        slot3++;
        if (slot3 == 10)
        {
            slot3 = 0;
            quarters += 9;
        }
        if (quarters <= 0)
            break;
    }

    cout << endl << "Martha plays " << count << " times before going broke." << endl;

    return 0;
}