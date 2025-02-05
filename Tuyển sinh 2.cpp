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
class hocsinh {
private:
	string ma, ten;
	double toan, ly, hoa, diemtong;
public:
	friend istream& operator >> (istream& in, hocsinh& x)
	{
		in >> x.ma;
		in.ignore();
		getline(in, x.ten);
		in >> x.toan >> x.ly >> x.hoa;
		x.diemtong = x.toan + x.ly + x.hoa;
		return in;
	}
	friend ostream& operator << (ostream& out, hocsinh x)
	{
		int kv = x.ma[2] - '0';
		out << x.ma << " " << x.ten << " " << kv << " ";
		if (kv == 1)
		{
			x.diemtong += 0.5;
		}
		else if (kv == 2)
		{
			x.diemtong += 1;
		}
		else x.diemtong += 2.5;
		out << x.diemtong << " " << (x.diemtong >= 24 ? "TRUNG TUYEN" : "TRUOT");
		return out;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	hocsinh x;
	cin >> x;
	cout << x;
}
