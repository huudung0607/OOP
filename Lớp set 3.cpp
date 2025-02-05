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
	set<string> list;
public:
	IntSet() {}
	IntSet(vector<string> v)
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
	IntSet Union(IntSet other)
	{
		IntSet tmp;
		for (auto x : list)
		{
			tmp.list.insert(x);
		}
		for (auto x : other.list) {
			tmp.list.insert(x);
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
	string a, b;
	getline(cin, a);
	getline(cin, b);
	stringstream ss(a), ss2(b);
	vector<string> va, vb;
	string tmp, tmp2;
	while (ss >> tmp)
	{
		va.push_back(tmp);
	}
	while (ss2 >> tmp2)
	{
		vb.push_back(tmp2);
	}
	IntSet A(va);
	IntSet B(vb);	
	cout << A.Union(B);
	cout << A.intersection(B) << endl;
}
