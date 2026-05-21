#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "KhachHang.h"
using namespace std;
double KhachHang::VAT = 0.1; //thiết lập VAT
// Hàm TinhTien() ghi đè lên lớp cha
double KhachHangA::TinhTien(){
    double tong = SLHang * DonGia;
        tong += tong * VAT;
        return tong;
}
// Hàm nhập ghi đè lên lớp cha
void KhachHangB::Nhap(ifstream&fin){
    KhachHang::Nhap(fin);
        fin >> SoNamThanThiet;
        fin.ignore();

}
// Hàm TinhTien() ghi đè lên lớp cha
double KhachHangB::TinhTien(){
    double KhuyenMai = SoNamThanThiet * 5;

        if(KhuyenMai > 50) // max là 50, lớn hơn thì lấy 50, 
            KhuyenMai = 50;
        // Tính tổng tiền 
        double tong = SLHang * DonGia;

        tong = tong * (100 - KhuyenMai) / 100.0;

        tong += tong * VAT;

        return tong;
}
// Hàm TinhTien() ghi đè lên lớp cha
double KhachHangC::TinhTien(){
    double tong = SLHang * DonGia * 0.5;
        tong += tong * VAT;
        return tong;
}