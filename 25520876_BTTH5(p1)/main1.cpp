#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
#include "NhanVien.h"
using namespace std;
int main()
{
    int n;
    cout<<"Nhap so luong nhan vien Cong Ty can quan ly"<<endl;
    cin>>n;
    CongTy a(n);
    cout<<"Nhap DS nhan vien"<<endl;
    a.NhapDSNhanVien();

    cout<<"DS nhan vien:"<<endl;
    a.XuatDSNhanVien();

    cout<<"Tong luong ma cong ty phai tra:"<<endl;
    cout<<a.TongLuong()<<endl;


    a.maxTuoiVP();
    a.minLuongSX();

}