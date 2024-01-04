#include <iostream>
#include <fstream>

using namespace std;

void ahead(int& x, int& y, int& direction, int& steps)
{
    if (direction == 0)
        x += steps;
    else if (direction == 1)
        y += steps;
    else if (direction == 2)
        x -= steps;
    else if (direction == 3)
        y -= steps;
}

void horizontal(int x, int y, int direction, ofstream& fo);
void vertical(int x, int y, int direction, ofstream& fo)
{
    if (y > 0)
    {
        if (direction == 0)
            fo << 2 << endl;
        else if (direction == 2)
            fo << 3 << endl;
        direction = 3;

        fo << 1 << endl << y << endl;
        y = 0;
    }
    else if (y < 0)
    {
        if (direction == 0)
            fo << 3 << endl;
        if (direction == 2)
            fo << 2 << endl;
        direction = 1;

        fo << 1 << endl << -y << endl;
        y = 0;
    }
    else
    {
        if (x != 0)
        {
            fo << 3 << endl;
            direction = (direction + 1) % 4;
        }
    }

    if (x != 0)
        horizontal(x, y, direction, fo);
}
void horizontal(int x, int y, int direction, ofstream& fo)
{
    if (x > 0)
    {
        if (direction == 3)
            fo << 2 << endl;
        else if (direction == 1)
            fo << 3 << endl;
        direction = 2;

        fo << 1 << endl << x << endl;
        x = 0;
    }
    else if (x < 0)
    {
        if (direction == 3)
            fo << 3 << endl;
        if (direction == 1)
            fo << 2 << endl;
        direction = 0;

        fo << 1 << endl << -x << endl;
        x = 0;
    }
    else
        if (y != 0)
        {
            fo << 3 << endl;
            direction = (direction + 1) % 4;
        }

    if (y != 0)
        vertical(x, y, direction, fo);
}
void home(int x, int y, int direction, ofstream& fo)
{
    if (x < 0 && direction == 0)
        fo << 1 << endl << -x << endl;
    else if (x > 0 && direction == 2)
        fo << 1 << endl << x << endl;
    else if (y < 0 && direction == 1)
        fo << 1 << endl << -y << endl;
    else if (y > 0 && direction == 3)
        fo << 1 << endl << y << endl;

    if (direction == 0 || direction == 2)
        vertical(x, y, direction, fo);
    else
        horizontal(x, y, direction, fo);
}

int main()
{
    ifstream fi;
    ofstream fo;
    fi.open("rover.in", ios::in);
    fo.open("rover.out", ios::out);

    int datasets = 0;
    fi >> datasets;

    for (int i = 0; i < datasets; i++)
    {
        int x = 0, y = 0;
        int dir = 0;

        int command = 0;
        int steps = 0;
        fi >> command;

        while (command != 0)
        {
            if (command == 1)
            {
                fi >> steps;
                ahead(x, y, dir, steps);
            }
            else if (command == 2)
                dir = (dir + 3) % 4;
            else if (command == 3)
                dir = (dir + 1) % 4;

            fi >> command;
        }

        fo << "Distance: " << abs(x) + abs(y) << endl;

        home(x, y, dir, fo);
        fo << endl;
    }

    return 0;
}