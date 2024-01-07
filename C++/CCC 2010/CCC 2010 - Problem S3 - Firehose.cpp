#include <bits/stdc++.h>

using namespace std;

int H, k;
int house[1000];

void sortHouses()
{
    int hold;
    for (int i = 0; i < H; i++)
    {
        hold = house[i];
        int j = i - 1;
        while (j >= 0 && hold < house[j])
        {
            house[j + 1] = house[j];
            j--;
        }
        house[j + 1] = hold;
    }
}

void shiftHouses()
{
    int largestGap = 1000000 - house[H - 1] + house[0];
    int largestI = 0, hold;
    for (int i = 1; i < H; i++)
        if (house[i] - house[i - 1] > largestGap)
        {
            largestGap = house[i] - house[i - 1];
            largestI = i;
        }

    hold = house[largestI];
    for (int i = 0; i < largestI; i++)
        house[i] += 1000000 - hold;
    for (int i = largestI; i < H; i++)
        house[i] -= hold;

    sortHouses();
}

int check(int diameter)
{
    int count = 0, start;

    int i = 0;
    while (i < H)
    {
        start = house[i];
        while (i < H && start + diameter > house[i])
            i++;
        count++;
        if (i < H && start + diameter == house[i])
            i++;
    }

    if (count < k)
        return 1;
    else if (count > k)
        return -1;
    else
        return 0;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> H;
    for (int i = 0; i < H; i++)
        cin >> house[i];
    cin >> k;

    if (k >= H)
        cout << "0\n";
    else
    {
        sortHouses();
        shiftHouses();

        int diameter = 1000000 / k;
        int high = diameter, low = 0;
        int x = check(diameter);

        while (x != 0)
        {
            if (x < 0) low = diameter;
            else high = diameter;
            diameter = (low + high) / 2;
            x = check(diameter);
        }

        x = check(diameter);
        while (x == 0)
        {
            diameter--;
            x = check(diameter);
        }
        cout << (diameter + 2) / 2;
    }

    return 0;
}