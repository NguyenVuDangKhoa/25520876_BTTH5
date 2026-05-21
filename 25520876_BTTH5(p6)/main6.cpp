#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "KhachHang.h"
using namespace std;
int main(){

    ifstream fin("XYZ.INP"); // đọc và lấy dữ liệu từ file XYZ.INP
    ofstream fout("XYZ.OUT"); // Xuất và ghi dữ liệu vào file XYZ.OUT

    int x, y, z;
    fin >> x >> y >> z;
    fin.ignore();
    // Tạo danh sách địa chỉ để quản lý
    vector<KhachHang*> ds;

    // Loai A
    for(int i = 0; i < x; i++){
        KhachHang* p = new KhachHangA();
        p->Nhap(fin); // lấy dữ liệu và gán cho p từ file XYZ.INP
        ds.push_back(p);
    }

    // Loai B
    for(int i = 0; i < y; i++){
        KhachHang* p = new KhachHangB();
         p->Nhap(fin); // lấy dữ liệu và gán cho p từ file XYZ.INP
        ds.push_back(p);
    }

    // Loai C
    for(int i = 0; i < z; i++){
        KhachHang* p = new KhachHangC();
        p->Nhap(fin); // lấy dữ liệu và gán cho p từ file XYZ.INP
        ds.push_back(p);
    }

    double TongCongTy = 0;

    fout << x << " " << y << " " << z << endl;

    for(KhachHang* p : ds){
        p->Xuat(fout); // Xuất và ghi dữ liệu đầu ra vào file XYZ.OUT
        TongCongTy += p->TinhTien(); //cộng dồn tiền 
    }

    fout << TongCongTy;

    // Giai phong
    for(KhachHang* p : ds)
        delete p;
}