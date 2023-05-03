#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifile;
	ofstream ofile;

	ifile.open("dpa.in", ios::in);
	ofile.open("dpa.out", ios::out);

	int a, b;

	ifile >> a;

	int sum;

	for (int i = 0; i < a; i++)
	{
		sum = 0;

		ifile >> b;

		for (int j = 1; j < b; j++)
		{
			if (b % j == 0)
			{
				sum = sum + j;
			}
		}

		if (b == sum)
		{
			ofile << b << " is a perfect integer. \n" << endl;
		}
		else if (b < sum)
		{
			ofile << b << " is an abundant integer. \n" << endl;
		}
		else
		{
			ofile << b << " is a deficient integer. \n" << endl;
		}
	}

	ifile.close();
	ofile.close();

	return 0;
}