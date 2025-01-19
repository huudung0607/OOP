#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
class student
{
public:
	student() {

	}
	student(string msv, string ten, string ns, string lop, double gpa)
	{
		this->msv = msv;
		this->ten = ten;
		this->ns = ns;
		this->lop = lop;
		this->gpa = gpa;
	}
	void nhap()
	{
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, lop);
		cin >> gpa;
	}
	void in()
	{
		cout << msv << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa;
	}

private:
	string msv, ten, ns, lop;
	double gpa;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	student x;
	x.nhap();
	x.in();
}
