#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifile;
	ofstream ofile;

	ifile.open("div.in", ios::in);
	ofile.open("div.out", ios::out);

	int a;
	ifile >> a;

	for (int i = 0; i < a; i++)
	{
		unsigned long long int b;
		ifile >> b;

		ofile << b << endl;
		
		unsigned long long int tmp = b;

		int counter = 0;
		while (tmp > 0)
		{
			tmp /= 10;
			counter++;
		}

		tmp = b;
		for (int j = 0; j < counter - 1; j++)
		{
			if (tmp > 100)
			{
				tmp = tmp / 10 - tmp % 10;
				ofile << tmp << endl;
			}
			else
			{
				break;
			}
		}

		if (tmp % 11 == 0)
		{
			ofile << "The number " << b << " is divisible by 11." << endl;
		}
		else
		{
			ofile << "The number " << b << " is not divisible by 11." << endl;
		}
	}

	ifile.close();
	ofile.close();

	return 0;
}
