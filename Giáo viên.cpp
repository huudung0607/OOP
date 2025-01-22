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
class luong {
private:
	string ma, hoten;
	long long salary;
public:
	luong() {}
	luong(string ma, string hoten, long long salary)
	{
		this->ma = ma;
		this->hoten = hoten;
		this->salary = salary;
	}
	long long getHeSo()
	{
		string res = "";
		for (int i = 0; i < ma.size(); i++)
		{
			if (isdigit(ma[i]))
			{
				res += ma[i];
			}
		}
		long long ans = stoll(res);
		return ans;
	}
	long long getSalary()
	{
		return salary;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string ma, hoten;
	long long salary;
	getline(cin, ma);
	getline(cin, hoten);
	cin >> salary;
	cin.ignore();
	luong truong(ma, hoten, salary);
	if (ma[1] == 'T')
	{
		long long salaryMax = truong.getHeSo() * salary + 2000000;
		cout << ma << " " << hoten << " " << truong.getHeSo() << " " << salaryMax;
	}
	if (ma[1] == 'P')
	{
		long long salaryMax = truong.getHeSo() * salary + 900000;
		cout << ma << " " << hoten << " " << truong.getHeSo() << " " << salaryMax;
	}
	if (ma[1] == 'V')
	{
		long long salaryMax = truong.getHeSo() * salary + 500000;
		cout << ma << " " << hoten << " " << truong.getHeSo() << " " << salaryMax;
	}
}
