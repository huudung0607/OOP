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
const double pi = 3.14;
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
		double xx = x - A.x;
		double yy = y - A.y;
		return sqrt(xx * xx + yy * yy);
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
		point a(x1, y1), b(x2, y2), c(x3, y3);
		double ab = a.getDistance(b);
		double bc = b.getDistance(c);
		double ac = a.getDistance(c);
		if (ab > 0 && ac > 0 && bc > 0 && ab + ac > bc && ab + bc > ac && ac + bc > ab)
		{
			double cv = ab + bc + ac;
			double p = cv / 2;
			double dt = sqrt(p * (p - ac) * (p - bc) * (p - ab));
			double r = (ab * bc * ac) / (4 * dt);
			cout << fixed << setprecision(3) << r * r * 3.14 << endl;
		}
		else
		{
			cout << "INVALID" << endl;
		}
	}
}
