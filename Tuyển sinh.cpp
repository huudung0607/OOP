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
	double toan, ly, hoa, diemtong, uutien,khuvuc;
public:
	hocsinh() {}
	hocsinh(string ma, string ten, double toan, double ly, double hoa)
	{
		this->ma = ma;
		this->ten = ten;
		this->toan = toan;
		this->ly = ly;
		this->hoa = hoa;
		this->khuvuc = 0;
		this->diemtong = 0;
		this->uutien = 0;
	}
	void diemuutien()
	{
		string kv = ma.substr(0, 3);
		if (kv == "KV1")
		{
			uutien = 0.5;
		}
		if (kv == "KV2")
		{
			uutien = 1;
		}
		if (kv == "KV3")
		{
			uutien = 2.5;
		}
		int c = 0;
		for (int i = 0; i < kv.size(); i++)
		{
			if (isdigit(kv[i]))
			{
				c = (kv[i] - '0');
			}
		}
		khuvuc = c;
		diemtong = toan + ly + hoa + uutien;
	}
	void in()
	{
		if (diemtong < 24)
		{
			cout << ma << " " << ten << " " << khuvuc << " " << diemtong << " " << "TRUOT";
		}
		else
		{
			cout << ma << " " << ten << " " << khuvuc << " " << diemtong << " " << "TRUNG TUYEN";
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string ma, ten;
	double toan, ly, hoa;
	getline(cin, ma);
	getline(cin, ten);
	cin >> toan >> ly >> hoa;
	hocsinh hs(ma, ten, toan, ly, hoa);
	hs.diemuutien();
	hs.in();
}
