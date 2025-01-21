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
class SinhVien {
private:
    string ma, ten, lop, ns;
    double gpa;
public:
    SinhVien() {}
    SinhVien(string ma, string ten, string lop, string ns, double gpa)
    {
        this->ma = "SV001";
        this->ten = ten;
        this->lop = lop;
        this->ns = ns;
        this->gpa = gpa;
    }
    void chuanHoa() {
        if (ns[1] == '/')
        {
            ns = "0" + ns;
        }
        if (ns[4] == '/')
        {
            ns.insert(3, "0");
        }
    }
    void hienThi() {
        cout << ma << " " << ten << " " << lop << " " << ns<< " " << fixed << setprecision(1) << gpa << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string ma, ten, lop, ns;
    double gpa; 
    getline(cin, ten);
    getline(cin, lop);
    getline(cin, ns);
    cin >> gpa;
    SinhVien sv(ma, ten, lop, ns, gpa);
    sv.chuanHoa();
    sv.hienThi();
}
