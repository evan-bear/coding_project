#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream ifile;
	ofstream ofile;

	ifile.open("sent.in", ios::in);
	ofile.open("sent.out", ios::out);

	int ds;
	ifile >> ds;

	int s, v, o;
	vector<string> p_s, p_v, p_o;

	for (int i = 0; i < ds; i++)
	{
		ifile >> s;
		ifile >> v;
		ifile >> o;

		string tmp;
		getline(ifile, tmp);
		for (int i = 0; i < s; i++)
		{
			getline(ifile, tmp);
			p_s.push_back(tmp);
		}
		for (int j = 0; j < v; j++)
		{
			getline(ifile, tmp);
			p_v.push_back(tmp);
		}
		for (int k = 0; k < o; k++)
		{
			getline(ifile, tmp);
			p_o.push_back(tmp);
		}

		for (int i = 0; i < s; i++) {
			for (int j = 0; j < v; j++) {
				for (int k = 0; k < o; k++) {
					ofile << p_s[i] << " " << p_v[j] << " " << p_o[k] << endl;
				}
			}
		}
		ofile << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}
