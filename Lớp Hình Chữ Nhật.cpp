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
class hcn {
private:
	int rong, cao;
	string mausac;
public:
	hcn() {}
	hcn(int rong, int cao, string mausac)
	{
		this->rong = rong;
		this->cao = cao;
		this->mausac = mausac;
	}
	void chuanhoa()
	{
		stringstream ss(mausac);
		string w, res = "";
		while (ss>> w)
		{
			res += toupper(w[0]);
			for (int i = 1; i < w.size(); i++)
			{
				res += tolower(w[i]);
			}
		}
		mausac = res;
	}
	long long dientich()
	{
		return rong * cao;
	}
	long long chuvi()
	{
		return (rong + cao) * 2;
	}
	void in()
	{
		if (rong > 0 && cao > 0)
		{
			cout << chuvi() << " " << dientich() << " " << mausac << endl;
		}
		else
		{
			cout << "INVALID";
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int rong, cao;
	string mausac;
	cin >> rong >> cao;
	cin.ignore();
	getline(cin, mausac);
	hcn a(rong, cao, mausac);
	a.chuanhoa();
	a.in();
}
