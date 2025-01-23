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
#include <fstream>
using namespace std;
class NhanVien {
private:
    string ma, ten, chucvu;
    int luongCoBan, soNgayCong, thuong, phuCap, thuNhap;
public:
    NhanVien(string ma, string ten, int luongCoBan, int soNgayCong, string chucvu) {
        this->ma = "NV01";
        this->ten = ten;
        this->luongCoBan = luongCoBan;
        this->soNgayCong = soNgayCong;
        this->chucvu = chucvu;
        this->thuong = 0;
        this->phuCap = 0;
        this->thuNhap = 0;
    }
    void tinhLuong() {
        int luongThang = luongCoBan * soNgayCong;
        if (soNgayCong >= 25) {
            thuong = luongThang * 0.2;
        }
        else if (soNgayCong >= 22) {
            thuong = luongThang * 0.1;
        }
        else {
            thuong = 0;
        }
        if (chucvu == "GD") {
            phuCap = 250000;
        }
        else if (chucvu == "PGD") {
            phuCap = 200000;
        }
        else if (chucvu == "TP") {
            phuCap = 180000;
        }
        else if (chucvu == "NV") {
            phuCap = 150000;
        }
        thuNhap = luongThang + thuong + phuCap;
    }
    void print() {
        cout << ma << " " << ten << " " << (luongCoBan * soNgayCong) << " "
            << thuong << " " << phuCap << " " << thuNhap << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ma,ten, chucvu;
    int luongCoBan, soNgayCong;
    getline(cin, ten);
    cin >> luongCoBan >> soNgayCong;
    cin.ignore();
    getline(cin, chucvu);
    NhanVien nv(ma, ten, luongCoBan, soNgayCong, chucvu);
    nv.tinhLuong();
    nv.print();
}
