#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include<cstring>
#include <random>
#include <ctime>

using namespace std;



class Axis
{
public:
	double ra;
	double dec;
	double pr;
};

inline void read_t(vector<Axis>(&mass), string file)
{
	mass.clear();
	Axis axs;
	string str;
	ifstream fp(file.c_str());
	if (!fp.is_open())
	{
		cout << "not opened" << endl;
	}
	while(fp >> axs.ra)
	{
		fp >> axs.dec;
		fp >> axs.pr;
		mass.push_back(axs);
	}
}


int main()
{
	vector<Axis> data;
	read_t(data, "test_dip.txt");
	ofstream fout("sort_test_dip.txt");
	if (!fout.is_open())
	{
		cout << "not opened" << endl;
		return 1;
	}
	cout << data.size()<<endl;
	cout << data[2700].ra << endl;
	cout << data[2700].dec << endl;
	sort(begin(data), end(data),[](const Axis& a, const Axis& b) 
		{
			return a.pr > b.pr;
		});

	for (int i = 0; i <data.size(); i++) {
		fout << i<< '\t'  << data[i].ra << '\t' << data[i].dec << '\t' << data[i].pr << endl ;
		
	}

	/*Galaxy data1[77840];
	read_t(data1, "test_quadr.csv");
	ofstream fout1("sort_test_quadr.txt");
	if (!fout.is_open())
	{
		cout << "not opened" << endl;
		return 1;
	}




	sort(begin(data1), end(data1),
		[](const Galaxy& a, const Galaxy& b) {
			return a.dec > b.dec;
		});

	for (int i = 0; i < 77840; i++) {
		fout1<<i +1 << '\t'<< data1[i].cw << '\t' << data1[i].ra << '\t' << data1[i].dec << endl ;

	}*/
	return 0;
}