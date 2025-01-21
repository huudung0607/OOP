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
class vehicle {
private:
	string ma, ten, hang, color;
public:
	vehicle() {}
	vehicle(string ma, string ten, string hang, string color) {
		this->ma = ma;
		this->ten = ten;
		this->hang = hang;
		this->color = color;
	}
	string getMa()
	{
		return ma;
	}
	string getTen()
	{
		return ten;
	}
	string getHang()
	{
		return hang;
	}
	string getColor()
	{
		return color;
	}
};
class motorbike : public vehicle {
private:
	int velocity, gia;
public:
	motorbike() {}
	motorbike(string ma, string ten, string hang, string color, int velocity, int gia) : vehicle(ma, ten, hang, color) {
		this->velocity = velocity;
		this->gia = gia;
	}
	void in() {
		cout << getMa() << " " << getTen() << " " << getHang() << " " << getColor() << " " << velocity << " " << gia << endl;
	}
};
class car : public vehicle {
private:
	int hp, gia;
public:
	car() {}
	car(string ma, string ten, string hang, string color, int hp, int gia) : vehicle(ma, ten, hang, color)
	{
		this->hp = hp;
		this->gia = gia;
	}
	void in()
	{
		cout << getMa() << " " << getTen() << " " << getHang() << " " << getColor() << " " << hp << " " << gia << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<motorbike> xemay;
	vector<car> xehoi;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		string ma, ten, hang, color;
		int hp, gia, velocity;
		getline(cin, ma);
		getline(cin, ten);
		getline(cin, hang);
		getline(cin, color);
		if (ma[0] == 'X')
		{
			cin >> velocity;
			cin >> gia;
			motorbike moto(ma, ten, hang, color, velocity, gia);
			xemay.push_back(moto);
		}
		else
		{
			cin >> hp;
			cin >> gia;
			car oto(ma, ten, hang, color, hp, gia);
			xehoi.push_back(oto);
		}
	}
	cin.ignore();
	string s;
	cin >> s;
	cout << "DANH SACH XE HANG " << s <<  " :" << endl;
	for (auto x : xehoi)
	{
		if (x.getHang() == s)
		{
			x.in();
		}
	}
	for (auto x : xemay)
	{
		if (x.getHang() == s)
		{
			x.in();
		}
	}
}
