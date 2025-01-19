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
class customer
{
public:
	customer() {

	}
	customer(string ma, string ten, string diachi, string phone, string email)
	{
		this->ma = ma;
		this->ten = ten;
		this->diachi = diachi;
		this->phone = phone;
		this->email = email;
	}
	void nhap()
	{
		getline(cin, ma);
		getline(cin, ten);
		getline(cin, diachi);
		getline(cin, phone);
		getline(cin, email);
	}
	void in()
	{
		cout << ma << " " << ten << " " << diachi << " " << phone << " " << email;
	}
private:
	string ma, ten, diachi, phone, email;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	customer a;
	a.nhap();
	a.in();
}
