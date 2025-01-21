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
class PhanSo {
private:
    long long tu, mau;
public:
    PhanSo();
    PhanSo(long long tu, long long mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    long long gcd(long long a, long long b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    void toiGian()
    {
        long long kq = gcd(abs(tu), abs(mau));
        tu /= kq;
        mau /= kq;
    }
    void hienThi()
    {
        cout << tu << "/" << mau << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    long long tu, mau;
    cin >> tu >> mau;
    PhanSo ps(tu, mau);
    ps.toiGian();
    ps.hienThi();
}
