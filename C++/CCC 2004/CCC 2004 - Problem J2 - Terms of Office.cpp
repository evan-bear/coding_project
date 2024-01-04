#include <iostream>

using namespace std;

int main()
{
	int yearx, yeary;
	cout << "Enter the current year:" << endl;
	cin >> yearx;
	cout << "Enter a future year:" << endl;
	cin >> yeary;

	for (int i = yearx; i <= yeary; i += 60) //the lcm of 2, 3, 4, 5 is 60
		cout << "All positions change in year " << i << endl;

	return 0;
}
