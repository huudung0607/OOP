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
#include <queue>
#include <stack>
using namespace std;
class Time {
private:
	int gio, phut, giay;
public:
	Time() {}
	Time(int gio, int phut, int giay)
	{
		this->gio = gio;
		this->phut = phut;
		this->giay = giay;
	}
	friend istream& operator >> (istream& in, Time &x)
	{
		in >> x.gio >> x.phut >> x.giay;
		return in;
	}
	friend ostream& operator << (ostream& out, Time x)
	{
		out << x.gio << " " << x.phut << " " << x.giay << endl;
		return out;
	}
	friend bool operator < (Time a, Time b)
	{
		if (a.gio != b.gio)
		{
			return a.gio < b.gio;
		}
		else
		{
			if (a.phut != b.phut)
			{
				return a.phut < b.phut;
			}
			else
			{
				return a.giay < b.giay;
			}
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<Time> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (auto x : a)
	{
		cout << x;
	}
}
