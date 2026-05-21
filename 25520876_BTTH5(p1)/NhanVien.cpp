#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
#include "NhanVien.h"
using namespace std;
// Hàm kiểm tra dạng nhập ngày sinh (hợp lệ : VD:01/01/1000)
bool CheckDate(string s)
{
    return s.length() == 10 &&
           s[2] == '/' &&
           s[5] == '/';
}
// Hàm chuyển ngày sinh từ string sang số để so sánh
int Trans(string s)
{
    int ngay=stoi(s.substr(0,2)); // lấy và chuyển thành số 2 kí tự đầu (tương ứng với ngày)
    int thang=stoi(s.substr(3,2)); // lấy và chuyển thành só 2 kí tự thứ 3 và 4 (tương ứng với tháng)
    int nam=stoi(s.substr(6,4)); // lấy và chuyển thành số 4 kí tự cuối (tương ứng với năm)
    return nam*10000+thang*100+ngay; // chuyển thành số của nguyên ngày tháng năm
}
// Hàm nhập của class NhanVien
void NhanVien::Nhap(){
    cout<<"Nhap ho ten:"<<endl;
    getline(cin,HoTen);
    cout<<"Nhap ngay sinh:"<<endl;
    do
{
    getline(cin, NgaySinh);

    if(!CheckDate(NgaySinh))
    {
        cout<<"Nhap lai ngay..."<<endl;
    }

} while(!CheckDate(NgaySinh)); // kiểm tra nhập đúng dạng ngày sinh
}
// class NVSanXuat viết lại hàm nhập, xuất, TinhLuong của lớp cha( class NhanVien)
void NVSanXuat::Nhap(){
    NhanVien::Nhap();
    cout<<"Nhap Luong co ban"<<endl;
    cin>> LuongCB;
    cout<<"Nhap So luong san pham"<<endl;
    cin>> SP;


}

void NVSanXuat::Xuat(){
    cout<<"Nhan vien San Xuat"<<endl;
    NhanVien::Xuat();
    
}
double NVSanXuat::TinhLuong(){
    Luong=LuongCB + SP*5000;
    return Luong;
}

// class NVVanPhong viết lại hàm nhập, xuất, TinhLuong của lớp cha( class NhanVien)
void NVVanPhong::Nhap(){
    NhanVien::Nhap();
    cout<<"Nhap so ngay lam viec:"<<endl;
    cin>>SoNgayLam;

}
void NVVanPhong::Xuat(){
    cout<<"Nhan vien Van Phong"<<endl;
    NhanVien::Xuat();

}
double NVVanPhong::TinhLuong(){
    Luong=SoNgayLam*100000;
    return Luong;
}
void CongTy::NhapDSNhanVien(){
    for(int i=0;i<n;i++)
    {
        int loai; // tạo biến loai và phân biệt dựa trên loai
        NhanVien*nv; // tạo con trỏ
        cout<<"Nhap loai nhan vien (San Xuat -- 0,Van Phong -- 1):"<<endl;
        cin>>loai;
        cin.ignore(1000, '\n');
        while(loai !=1 && loai !=0)
        {
            cout<<"Loai NV khong ton tai, Nhap lai:"<<endl; 
            cin>>loai;
            cin.ignore(1000, '\n');
        }
        // nếu loai =0 thì con trỏ mang giá trị địa chỉ của NVSanXuat
        if(loai==0){
            nv=new NVSanXuat();
        } // nếu loai=1 thì con trỏ mang giá trị địa chỉ của NVVanPhong
        else
        nv=new NVVanPhong();
        nv->Nhap();
        ds.push_back(nv); //  thêm con trỏ vào mảng địa chỉ
        
    }
}
void CongTy::XuatDSNhanVien(){
    for(auto i:ds)
    { 
        i->Xuat();
    }
}
double CongTy::TongLuong(){
    double Tong=0;
    // sử dụng da hình để tính tổng lương
    for(auto i:ds)
    {
        Tong+=i->TinhLuong();
    }
    return Tong;
}
void CongTy::maxTuoiVP(){
    NhanVien*LonNhat=NULL; //tạo con trỏ mang địa chỉ biến có tuổi lớn nhất
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(NVVanPhong)) // so sánh kiểu dữ liệu để tìm kiểu NVVanPhong
        {
           if(LonNhat==NULL || Trans(i->getNgaySinh())<Trans(LonNhat->getNgaySinh())) //so sánh ngày sinh bằng chức năng của Trans
           {
            LonNhat=i;
           }

        }
    }
    if(LonNhat!=NULL)
    {
        cout<<"Nhan vien Van Phong lon tuoi nhat:"<<endl;
        LonNhat->Xuat();
    }
    

}
void CongTy::minLuongSX(){
    NhanVien*NhoNhat=NULL;
    for(auto i: ds)
    {
        if(typeid(*i)==typeid(NVSanXuat)) // so sánh kiểu dữ liệu để tìm kiểu NVSanXuat
        {
            if(NhoNhat==NULL || NhoNhat->TinhLuong() > i->TinhLuong()) //so sánh lương 
            {
                NhoNhat=i;
            }
        }
    }
    if(NhoNhat!=NULL)
    {
        cout<<" Nhan vien San Xuat co luong thap nhat: "<<endl;
        NhoNhat->Xuat();
    }
}


