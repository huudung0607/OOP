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
class nhanvien {
private:
	string ma, name, gioitinh, ns, dc, hopdong;
	string mathue;
public:
	nhanvien() {}
	nhanvien(string ma, string name, string gioitinh, string ns, string dc, string mathue, string hopdong)
	{
		this->ma = "00001";
		this->name = name;
		this->gioitinh = gioitinh;
		this->ns = ns;
		this->dc = dc;
		this->mathue = mathue;
		this->hopdong = hopdong;
	}
	void chuanHoaNS() {
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
	}
	void chuanHoaHD() {
		if (hopdong[1] == '/')
		{
			hopdong = "0" + hopdong;
		}
		if (hopdong[4] == '/')
		{
			hopdong.insert(3, "0");
		}
	}
	void chuanhoaTen()
	{
		stringstream ss(name);
		string w, res = "";
		while (ss >> w)
		{
			res += toupper(w[0]);
			for (int i = 1; i < w.size(); i++)
			{
				res += tolower(w[i]);
			}
			res += " ";
		}
		res.pop_back();
		name = res;
	}
	void in()
	{
		cout << ma << " " << name << " " << gioitinh << " " << ns << " " << dc << " " << mathue << " " << hopdong << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string ma, name, gioitinh, ns, dc, hopdong;
	string mathue;
	getline(cin, name);
	getline(cin, gioitinh);
	getline(cin, ns);
	getline(cin, dc);
	getline(cin, mathue);
	getline(cin, hopdong);
	nhanvien nv(ma, name, gioitinh, ns, dc, mathue, hopdong);
	nv.chuanHoaHD();
	nv.chuanHoaNS();
	nv.chuanhoaTen();
	nv.in();
}
