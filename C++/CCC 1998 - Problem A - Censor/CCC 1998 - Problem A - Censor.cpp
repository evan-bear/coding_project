#include <iostream>
#include <fstream>

#include <string>

using namespace std;

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("censor.in", ios::in);
	ofile.open("censor.out", ios::out);

	int a;
	ifile >> a;

	string temp;
	getline(ifile, temp);

	for (int i = 0; i < a; i++)
	{
		string b = "";
		getline(ifile, b);

		int c = 0;

		for (int j = 0; j < b.size(); j++)
		{
			if (b[j] == '\0')
			{
				if (c == 4)
				{
					for (int k = j - 4; k < j; k++)
					{
						b[k] = '*';
					}
				}

				break;
			}

			if (b[j] == ' ')
			{
				if (c == 4)
				{
					for (int k = j - 4; k < j; k++)
					{
						b[k] = '*';
					}
				}

				c = 0;
			}
			else
			{
				c++;
			}
		}

		ofile << b << endl << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}