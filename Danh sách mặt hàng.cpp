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
class mathang
{
private:
	int ma;
	string ten, donvi;
	long long giamua, giaban;
public:
	mathang() {}
	mathang(int ma, string ten, string donvi, long long giamua, long long giaban)
	{
		this->ma = ma;
		this->ten = ten;
		this->donvi = donvi;
		this->giamua = giamua;
		this->giaban = giaban;
	}
	friend ostream& operator << (ostream& out, mathang& x)
	{
		out << "MH" << setw(4) << setfill('0') << x.ma << " " << x.ten
			<< " " << x.donvi << " " << x.giamua << " " << x.giaban << " " << x.giaban - x.giamua << endl;
		return out;
	}
	friend bool operator < (mathang a, mathang b)
	{
		long long loinhuanA = a.giaban - a.giamua;
		long long loinhuanB = b.giaban - b.giamua;
		if (loinhuanA != loinhuanB)
		{
			return loinhuanB < loinhuanA;
		}
		else
		{
			return a.ma < b.ma;
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<mathang> a;
	for (int i = 1; i <= n; i++)
	{
		cin.ignore();
		string ten, donvi;
		getline(cin, ten);
		getline(cin, donvi);
		long long giaban, giamua;
		cin >> giamua >> giaban;
		a.push_back(mathang(i, ten, donvi, giamua, giaban));
	}
	sort(a.begin(), a.end());
	for (auto x : a)
	{
		cout << x;
	}
}
