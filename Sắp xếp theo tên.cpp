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
const int mod = 1e9 + 7;
class person
{
public:
	person() {

	}
	person(string ten, string ns, string diachi)
	{
		this->ten = ten;
		this->ns = ns;
		this->diachi = diachi;
	}
	void chuanhoaTen()
	{
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
	void chuanhoaNS() {
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
	}
	string getTen() {
		return ten;
	}
	string getNS() {
		return ns;
	}
	string getDiachi() {
		return diachi;
	}
	string getSortedName() {
		stringstream ss(ten);
		string w;
		vector<string>v;
		while (ss >> w)
		{
			v.push_back(w);
		}
		string res = v[v.size() - 1];
		for (int i = 0; i < v.size() - 1; i++)
		{
			res += " " + v[i];
		}
		return res;
	}
private:
	string ten, ns, diachi;
};
class student : public person {
private:
	string msv, lop;
	double gpa;
public:
	student() {

	}
	student(string msv, string ten, string ns, string diachi, string lop, double gpa) : person(ten, ns, diachi)
	{
		this->msv = msv;
		this->lop = lop;
		this->gpa = gpa;
	}
	void in()
	{
		cout << msv << " " << getTen() << " " << getNS() << " " << getDiachi() << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
	}
};
bool cmp(student x, student y)
{
	return x.getSortedName() < y.getSortedName();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;	
	cin.ignore();
	vector<student> v;
	for (int i = 0; i < n; i++)
	{	
		string msv, ten, ns, diachi, lop;
		double gpa;
		msv = to_string(i + 1);
		while (msv.size() < 4)
		{
			msv = "0" + msv;
		}
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, diachi);
		getline(cin, lop);
		cin >> gpa;
		cin.ignore();
		student sv(msv, ten, ns, diachi, lop, gpa);
		sv.chuanhoaTen();
		sv.chuanhoaNS();
		v.push_back(sv);
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		x.in();
	}
}
