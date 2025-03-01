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
	double getGPA() {
		return gpa;
	}
	string getMSV()
	{
		return msv;
	}
};
class teacher : public person {
private:
	string msv, khoa;
	int luong;
public:
	teacher() {}
	teacher(string msv, string ten, string ns, string diachi, string khoa, int luong) : person(ten, ns, diachi)
	{
		this->msv = msv;
		this->khoa = khoa;
		this->luong = luong;
	}
	void in()
	{
		cout << msv << " " << getTen() << " " << getNS() << " " << getDiachi() << " " << khoa << " " << luong << endl;
	}
	int getLuong()
	{
		return luong;
	}
	string getMSV() {
		return msv;
	}
};
bool cmp1(teacher x, teacher y)
{
	if (x.getLuong() != y.getLuong())
	{
		return x.getLuong() > y.getLuong();
	}
	return x.getMSV() < y.getMSV();
}
bool cmp2(student x, student y)
{
	if (x.getGPA() != y.getGPA())
	{
		return x.getGPA() > y.getGPA();
	}
	return x.getMSV() < y.getMSV();
}
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
			teacher gv(msv, ten, ns, diachi, khoa, luong);
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
	cout << "DANH SACH GIAO VIEN :" << endl;
	sort(giaovien.begin(), giaovien.end(), cmp1);
	for (auto x : giaovien)
	{
		x.in();
	}
	cout << "DANH SACH SINH VIEN :" << endl;
	sort(hocsinh.begin(), hocsinh.end(), cmp2);
	for (auto x : hocsinh)
	{
		x.in();
	}
}
