#include <iostream>
#include "SinhVien.h"

using namespace std;

int main() {
    
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(1000, '\n');
    TruongDH t(n);



    cout << "==============================" << endl;
    t.NhapDSSinhVien();

    cout << "\n==============================" << endl;
    t.XuatDSSinhVien();

    cout << "\n==============================" << endl;
    t.DSSV_TotNghiep();

    cout << "\n==============================" << endl;
    t.DSSV_KoTotNghiep();

    cout << "\n==============================" << endl;
    t.SV_maxDTB_CaoDang();

    cout << "\n==============================" << endl;
    t.SV_maxDTB_DaiHoc();

    cout << "\n==============================" << endl;
    t.SL_KoTotNghiep();

    return 0;
}