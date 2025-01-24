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
#include <fstream>
using namespace std;
class phanso {
private:
	long long tu, mau;
public:
	phanso() {}
	phanso(long long tu, long long mau)
	{
		this->tu = tu;
		this->mau = mau;
	}
	long long gcd(long long a, long long b)
	{
		if (b == 0)
		{
			return a;
		}
		return gcd(b, a % b);
	}
	void rutgon()
	{
		long long kq = gcd(tu, mau);
		tu /= kq;
		mau /= kq;
	}
	friend phanso operator + (phanso a, phanso b)
	{
		long long tuso = a.tu * b.mau + a.mau * b.tu;
		long long mauso = a.mau * b.mau;
		phanso ps(tuso, mauso);
		ps.rutgon();
		return ps;
	}
	friend phanso operator * (phanso a, phanso b)
	{
		long long tuso = a.tu * b.tu;
		long long mauso = a.mau * b.mau;
		phanso ps(tuso, mauso);
		ps.rutgon();
		return ps;
	}
	phanso pow()
	{
		return phanso(tu * tu, mau * mau);
	}
	void in()
	{
		cout << tu << "/" << mau;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		phanso A(x1, y1);
		phanso B(x2, y2);
		phanso C = (A + B).pow();
		phanso D = A * B * C;
		C.in();
		cout << " ";
		D.in();
		cout << endl;
	}
}
