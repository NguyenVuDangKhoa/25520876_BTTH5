#include <iostream>
#include "LapTrinh.h"
using namespace std;

int main() {

    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    CongTy ct(n);



    ct.NhapDSNhanVien();

    cout << "\n========================\n";
    ct.XuatDSNhanVien();

    cout << "\n========================\n";
    ct.DS_ThapHonTB();

    cout << "\n========================\n";
    ct.maxLuong();

    cout << "\n========================\n";
    ct.minLuong();

    cout << "\n========================\n";
    ct.maxLuong_LapTrinh();

    cout << "\n========================\n";
    ct.minLuong_KiemDinh();

    return 0;
}