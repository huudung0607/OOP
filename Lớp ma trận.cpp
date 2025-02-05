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
class matrix {
private:
	vector<vector<int>> v;
	int hang, cot;
public:
	matrix() {}
	matrix(int hang, int cot)
	{
		this->hang = hang;
		this->cot = cot;
		v.resize(hang, vector<int>(cot));
		for (int i = 0; i < hang; i++)
		{
			for (int j = 0; j < cot; j++)
			{
				cin >> v[i][j];
			}
		}
	}
	matrix mul(matrix other)
	{
		int n = hang, m = cot, p = other.cot;
		matrix tmp;
		tmp.v.resize(n, vector<int>(p));
		tmp.hang = n, tmp.cot = p;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < p; j++)
			{
				for (int k = 0; k < m; k++)
				{
					tmp.v[i][j] += v[i][k] * other.v[k][j];
				}
			}
		}
		return tmp;
	}
	friend ostream& operator << (ostream& out, matrix x)
	{
		for (int i = 0; i < x.hang; i++)
		{
			for (int j = 0; j < x.cot; j++)
			{
				out << x.v[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	matrix a(n, m), b(m, p);
	cout << a.mul(b);
}
