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
class teacher : public person {
private:
	string msv, khoa, lop;
	int luong;
public:
	teacher() {}
	teacher(string msv, string ten, string ns, string diachi, string khoa, int luong,string lop) : person(ten, ns, diachi)
	{
		this->msv = msv;
		this->khoa = khoa;
		this->luong = luong;
		this->lop = lop;
	}
	void in()
	{
		cout << msv << " " << getTen() << " " << getNS() << " " << getDiachi() << " " << khoa << " " << luong << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;	
	vector<student> hocsinh;
	vector<teacher> giaovien;
	for (int i = 0; i < n; i++)
	{	
		cin.ignore();
		string msv, ten, ns, diachi, lop, khoa;
		double gpa; int luong;
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, diachi);
		if (msv[0] == 'G')
		{
			getline(cin, khoa);
			cin >> luong;
			cin >> lop;
			teacher gv(msv, ten, ns, diachi, khoa, luong,lop);
			gv.chuanhoaTen();
			gv.chuanhoaNS();
			giaovien.push_back(gv);
		}
		else
		{
			getline(cin, lop);
			cin >> gpa;
			student hs(msv, ten, ns, diachi, lop, gpa);
			hs.chuanhoaNS();
			hs.chuanhoaTen();
			hocsinh.push_back(hs);
		}
	}
	cin.ignore();
	string dc;
	getline(cin, dc);
	cout << "DANH SACH GIAO VIEN CO DIA CHI TAI " << dc << " : " << endl;
	for (auto x : giaovien){
		if (x.getDiachi() == dc)
		{
			x.in();
		}
	}
	cout << "DANH SACH SINH VIEN CO DIA CHI TAI " << dc << " : " << endl;
	for (auto x : hocsinh) {
		if (x.getDiachi() == dc)
		{
			x.in();
		}
	}
}
