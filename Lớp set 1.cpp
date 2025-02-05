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
class IntSet {
private:
	set<int> list;
public:
	IntSet() {}
	IntSet(vector<int> v)
	{
		list.insert(v.begin(), v.end());
	}
	IntSet intersection(IntSet other)
	{
		IntSet tmp;
		for (auto x : other.list)
		{
			if(list.count(x)) tmp.list.insert(x);
		}
		return tmp;
	}
	friend ostream& operator << (ostream& out, IntSet se)
	{
		for (auto x : se.list)
		{
			out << x << " ";
		}
		return out;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a, b;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		b.push_back(x);
	}
	IntSet A(a);
	IntSet B(b);
	cout << A.intersection(B);
}
