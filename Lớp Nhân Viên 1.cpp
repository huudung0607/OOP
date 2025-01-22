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
	nv.in();
}
