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
	double getDistance(point A)
	{
		return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
	}
	double getDientich(point B, point C)
	{
		return 0.5 * abs((B.x - x) * (C.y - y) - (C.x - x) * (B.y - y));
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
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		point A(x1, y1);
		point B(x2, y2);
		point C(x3, y3);
		if (A.getDistance(B) + B.getDistance(C) > C.getDistance(A) || B.getDistance(C) + C.getDistance(A) > A.getDistance(B) ||
			A.getDistance(B) + C.getDistance(A) > B.getDistance(C))	
		{
			cout << fixed << setprecision(3) << A.getDistance(B) + B.getDistance(C) + C.getDistance(A) << " ";
			cout << fixed << setprecision(3) << A.getDientich(B, C) << endl;
		}
		else
		{
			cout << "INVALID" << endl;
		}
	}
}
