#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class teacher {
private:
	int ma;
	string ten, mon;
public:
	teacher() {}
	teacher(int ma, string ten, string mon)
	{
		this->ma = ma;
		this->ten = ten;
		this->mon = mon;
	}
	void chuanhoaten()
	{
		stringstream ss(ten);
		string res = "", tmp;
		while (ss >> tmp)
		{
			res += toupper(tmp[0]);
			for (int i = 1; i < tmp.size(); i++)
			{
				res += tolower(tmp[i]);
			}
			res += " ";
		}
		res.pop_back();
		ten = res;
	}
	void chuanhoaMon()
	{
		stringstream ss(mon);
		string res = "", tmp;
		while (ss >> tmp)
		{
			res += toupper(tmp[0]);
		}
		mon = res;
	}
	string getTen()
	{
		vector<string> name;
		stringstream ss(ten);
		string temp;
		while (ss >> temp)
		{
			name.push_back(temp);
		}
		return name[name.size() - 1];
	}
	int getMa()
	{
		return ma;
	}
	void in()
	{
		cout << "GV" << setw(2) << setfill('0') << ma << " " << ten << " " << mon << endl;
	}
};
bool cmp(teacher x, teacher y)
{
	if (x.getTen() == y.getTen())
	{
		return x.getMa() < y.getMa();
	}
	return x.getTen() < y.getTen();
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<teacher> v;
	for (int i = 1; i <= n; i++)
	{
		int ma;
		string ten, mon;
		getline(cin, ten);
		getline(cin, mon);
		teacher gv(i, ten, mon);
		gv.chuanhoaMon();
		gv.chuanhoaten();
		v.push_back(gv);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		x.in();
	}
}
