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
	student(string msv, string ten, string ns, string lop, double gpa,int dlr)
	{
		this->msv = msv;
		this->ten = ten;
		this->ns = ns;
		this->lop = lop;
		this->gpa = gpa;
		this->dlr = dlr;
	}
	void chuanhoaten() {
		stringstream ss(ten);
		string temp, res = "";
		while (ss >> temp)
		{
			res += toupper(temp[0]);
			for (int i = 1; i < temp.size(); i++)
			{
				res += tolower(temp[i]);
			}
			res += " ";
		}
		res.pop_back();
		ten = res;
	}
	void chuanhoaNS()
	{
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
	}
	int getDLR()
	{
		return dlr;
	}
	double getGPA() {
		return gpa;
	}
	void in()
	{
		cout << msv << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa << " " << dlr << endl;
	}
private:
	string msv, ten, ns, lop;
	double gpa;
	int dlr;
};
bool cmp(student x, student y)
{
	if (x.getGPA() != y.getGPA())
	{
		return x.getGPA() > y.getGPA();
	}
	return x.getDLR() > y.getDLR();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	vector<student> danhsach;
	for (int i = 0; i < n; i++)
	{
		string msv, ten, ns, lop;
		double gpa;
		int dlr;
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, lop);
		cin >> gpa;
		cin.ignore();
		cin >> dlr;
		cin.ignore();
		student sv(msv, ten, ns, lop, gpa,dlr);
		sv.chuanhoaNS();
		sv.chuanhoaten();
		danhsach.push_back(sv);
	}	
	sort(danhsach.begin(), danhsach.end(), cmp);
	for (auto x : danhsach)
	{
		x.in();
	}
}
