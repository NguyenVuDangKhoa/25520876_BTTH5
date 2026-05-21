#include<iostream>
#include "GiaoDich.h"

using namespace std;

int main()
{

    int n;

    cout << "Nhap so giao dich: ";
    cin >> n;
    CongTy ct(n);

    cout << "Nhap danh sach giao dich\n";

        ct.NhapDSGiaoDich();

    cout << "\n========== DANH SACH GIAO DICH ==========\n";
    ct.XuatDSGiaoDich();

    cout << "\n========== SO LUONG TUNG LOAI ==========\n";
    ct.SLTungLoai();

    cout << "\n========== TRUNG BINH THANH TIEN CHUNG CU ==========\n";

    double tb = ct.TBChungCu();

    if(tb == 0)
        cout << "Khong co giao dich chung cu\n";
    else
        cout << "Trung binh thanh tien: " << tb << endl;

    cout << "\n========== NHA PHO CO GIA TRI CAO NHAT ==========\n";
    ct.maxNhaPho();

    cout << "\n========== GIAO DICH THANG 12/2024 ==========\n";
    ct.GDTrongthang12Nam2024();

    return 0;
}
