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
class HocSinh {
private:
    string ten, ngaysinh;
    double toan, ly, hoa;
public:
    HocSinh() {}
    HocSinh(string ten, string ngaysinh, double toan, double ly, double hoa)
    {
        this->ten = ten;
        this->ngaysinh = ngaysinh;
        this->toan = toan;
        this->ly = ly;
        this->hoa = hoa;
    }
    void hienthi() {
        cout << ten << " " << ngaysinh << " " << fixed << setprecision(1) << toan + ly + hoa;
    }
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string ten, ngaysinh;
    double toan, ly, hoa;
    getline(cin, ten);
    getline(cin, ngaysinh);
    cin >> toan >> ly >> hoa;
    cin.ignore();
    HocSinh hs(ten, ngaysinh, toan, ly, hoa);
    hs.hienthi();
}
