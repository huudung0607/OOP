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
class point {
private:
	double x, y;
public:
	point() {}
	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double getdistance(point diem1)
	{
		return sqrt((x - diem1.x) * (x - diem1.x) + (y - diem1.y) * (y - diem1.y));
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		point diem(x1, y1);
		point diem2(x2, y2);
		cout << fixed << setprecision(4) << diem.getdistance(diem2) << endl;
	}
}
