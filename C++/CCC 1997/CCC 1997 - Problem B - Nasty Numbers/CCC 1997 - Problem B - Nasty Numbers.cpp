#include <iostream>
#include <fstream>

#include <vector>
#include <cmath>

using namespace std;

bool nastyornot(int n)
{
	vector<int> factors;

	for (int i = 1; i < sqrt(n) + 1; i++)
		//Each factor has a corresponding factor.
		//Therefore, we can just record the first few up until the square root of n.
	{
		if (n % i == 0)
		{
			factors.push_back(i);
		}
	}

	for (int i = 0; i < factors.size(); i++)
	{
		for (int j = 0; j < factors.size(); j++)
		{
			int factor1 = factors[i];
			int factor2 = n / factor1;

			int factor3 = factors[j];
			int factor4 = n / factor3;

			if (abs(factor1 - factor2) == factor3 + factor4)
				return true;

		}
	}

	return false;
}

int main()
{
	ifstream ifile;
	ofstream ofile;

	ifile.open("nasty.in", ios::in);
	ofile.open("nasty.out", ios::out);

	int nn;
	ifile >> nn;

	int num;
	bool isnasty;
	for (int i = 0; i < nn; i++)
	{
		ifile >> num;

		isnasty = nastyornot(num);

		if (isnasty == true)
		{
			ofile << num << " is nasty" << endl;
		}
		else
		{
			ofile << num << " is not nasty" << endl;
		}
	}
	
	ifile.close();
	ofile.close();
}