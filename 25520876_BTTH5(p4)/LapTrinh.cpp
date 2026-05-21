#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
#include "LapTrinh.h"
using namespace std;
// Hàm nhập xuất và TinhLuong() được viết đè lên hàm ở lớp cha(class NhanVien)
void NVLapTrinh::Nhap(){
    cout<<"Nhan Vien Lap Trinh:"<<endl;
    NhanVien::Nhap();
    cout<<"Nhap So Gio lam them:";
    cin>>SoOVT;
    cin.ignore(1000,'\n');

}
void NVLapTrinh::Xuat(){
    cout<<"Nhan Vien Lap Trinh:"<<endl;
    NhanVien::Xuat();
    cout<<"So gio lam them:"<<SoOVT<<endl;
    cout<<"Luong:"<<TinhLuong()<<endl;

}
double NVLapTrinh::TinhLuong(){
    return LuongCB+SoOVT*200000;
}
void NVKiemDinh::Nhap(){
    cout<<"Nhan Vien Kiem Dinh:"<<endl;
    NhanVien::Nhap();
    cout<<"Nhap So Loi tim duoc:";
    cin>>SoLoi;
    cin.ignore(1000,'\n');

}
// Hàm nhập xuất và TinhLuong() được viết đè lên hàm ở lớp cha(class NhanVien)

void NVKiemDinh::Xuat(){
    cout<<"Nhan Vien Kiem Dinh:"<<endl;
    NhanVien::Xuat();
    cout<<"So loi tim duoc:"<<SoLoi<<endl;
    cout<<"Luong:"<<TinhLuong()<<endl;

}
double NVKiemDinh::TinhLuong(){
    return LuongCB+SoLoi*50000;
}
void CongTy::NhapDSNhanVien(){
    cout<<"Nhap DS Nhan Vien:"<<endl;
    for(int i=0;i<n;i++)
    {
        NhanVien*nv;
        int loai;
        cout<<"Nhap loai Nhan Vien (0--Lap Trinh, 1--Kiem Dinh):";
        cin>>loai; // nhập loại nhân viên để cấp phát địa chỉ
        cin.ignore(1000,'\n');
        while(loai!=0 && loai!=1)
        {
            cout<<"Loai Nhan Vien ko ton tai, Nhap lai (0--Lap Trinh, 1--Kiem Dinh): ";
            cin>>loai;
            cin.ignore(1000,'\n');
        }
        if(loai==0)
        {
            nv=new NVLapTrinh();
        }
        else
        nv=new NVKiemDinh();
        nv->Nhap();
        ds.push_back(nv); // thêm địa chỉ vảo DS thuộc tính vector
    }

}
void CongTy::XuatDSNhanVien(){
    cout<<"DS Nhan Vien:"<<endl;
    for(auto i:ds)
    {
        i->Xuat();
        cout<<endl;
    }
}
void CongTy::DS_ThapHonTB(){
    double tongluong=0; // tạo biến để lưu tỏng lương
    for(auto i:ds)
    {
        tongluong+=i->TinhLuong();// cộng dồn lương của các nhân viên
    }
    double tb=tongluong/n; //tính TB lương NV tring CTY 
    cout<<"Luong TB cua cac Nhan Vien:"<<tb<<endl;
     cout<<"DS Nhan Vien co luong thap hon TB luong cua cac NV:"<<endl;
    for(auto i:ds)
    {
        if(i->TinhLuong()<tb){
        i->Xuat();
        cout<<endl;
        }
    }
}
void CongTy::maxLuong(){
    NhanVien*max=nullptr; // tạo con trỏ lưu dịa chỉ biến nhân viên có lương MAX
    for(auto i:ds)
    {
        if(max==nullptr || max->TinhLuong() < i->TinhLuong()) // so sánh lương
        max=i; // gán max băng i nếu i có lương lớn hơn max
    }
    if(max!=nullptr)
    {
        cout<<"Nhan Vien co luong Cao Nhat:"<<endl;
        max->Xuat();
    }
}
void CongTy::minLuong(){
    NhanVien*min=nullptr; // tạo con trỏ lưu dịa chỉ biến nhân viên có lương MIN
    for(auto i:ds)
    {
        if(min==nullptr || min->TinhLuong() > i->TinhLuong()) // so sánh lương
        min=i; //gán min băng i nếu i có lương bé hơn min
    }
    if(min!=nullptr)
    {
        cout<<"Nhan Vien co luong Thap Nhat:"<<endl;
        min->Xuat();
    }
    
}
void CongTy::maxLuong_LapTrinh(){
    NhanVien*lt=nullptr; //tạo con trỏ lưu địa chỉ
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(NVLapTrinh) ) //so sánh kiểu dữ liệu
        {
          if(lt==nullptr || lt->TinhLuong()<i->TinhLuong()) // so sánh lương
          lt=i; // gán lt bằng i nếu lương lt bé hon lương i
        }
    }
    if(lt!=nullptr)
    cout<<"Nhan Vien Lap Trinh co luong Cao Nhat:"<<endl;
    lt->Xuat();
}
void CongTy::minLuong_KiemDinh(){
    NhanVien*kd=nullptr; // tạo con trỏ lưu địa chỉ
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(NVKiemDinh)) // so sánh kiểu dữ liệu
        {
            if(kd==nullptr || kd->TinhLuong()>i->TinhLuong()) // so sánh lương
            kd=i; // gán kd bằng i nếu i có lương bé hơn lương của kd
        }
    }
    if(kd!=nullptr)
    {
        cout<<"Nhan Vien Kiem Dinh co luong Thap Nhat:"<<endl;
        kd->Xuat();
    }
}
