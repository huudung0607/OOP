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

class product
{
public:
	product() {

	}
	product(string ma, string ten, int gia)
	{
		this->ma = ma;
		this->ten = ten;
		this->gia = gia;
	}
	void in()
	{
		cout << ma << " " << ten << " " << gia << endl;
	}
	bool operator < (product a)
	{
		return gia < a.gia;
	}
	friend bool operator > (product a, product b)
	{
		return a.gia > b.gia;
	}
	friend ostream& operator << (ostream &out, product X) {
		out << X.ma << " " << X.ten << " " << X.gia << endl;
		return out;
	}
	friend istream& operator >> (istream &in, product &x) {
		getline(in, x.ma);
		getline(in, x.ten);
		in >> x.gia;
		return in;
	}
private:
	string ma, ten;
	int gia;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	product X;
	cin >> X;
	cout << X << endl;
}
