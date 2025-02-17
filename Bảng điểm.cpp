#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>
using namespace std;
class student {
private:
	string ten;
	double a[10];
	double diemtb;
	int mts;
	static int ans;
public:
	friend istream& operator >> (istream& in, student &x)
	{
		++ans;
		x.mts = ans;
		scanf("\n");
		getline(in, x.ten);
		x.diemtb = 0;
		for (int i = 0; i < 10; i++)
		{
			in >> x.a[i];
			x.diemtb += x.a[i];
		}
		x.diemtb /= 10;
		return in;
	}
	friend ostream& operator << (ostream& out, student x)
	{
		out << "HS" << setw(2) << setfill('0') << x.mts << " " << x.ten << " " << fixed << setprecision(1) << x.diemtb << " ";
		if (x.diemtb >= 9)
		{
			out << "XUAT SAC";
		}
		else if (x.diemtb >= 8)
		{
			out << "GIOI";
		}
		else if (x.diemtb >= 7)
		{
			out << "KHA";
		}
		else if (x.diemtb >= 5)
		{
			out << "TB";
		}
		else
		{
			out << "YEU";
		}
		return out;
	}
	friend bool operator < (student a, student b)
	{
		return a.diemtb > b.diemtb;
	}
};
int student::ans = 0;
int main()
{
	int n;
	cin >> n;
	vector<student> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (auto x : a)
	{
		cout << x << endl;
	}
}
