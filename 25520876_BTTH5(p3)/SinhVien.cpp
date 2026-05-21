#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "SinhVien.h"
using namespace std;
// sử dụng đa hình
// Hàm nhập xuát và hàm XetTotNghiep() được viết dè lên hàm của lớp cha
void SVDaiHoc::Nhap(){
    cout<<"Sinh Vien Dai Hoc"<<endl;
    SinhVien::Nhap();
    cout<<"Nhap ten Luan Van:";
    getline(cin,LuanVan);
    cout<<"Nhap Diem Luan Van:";
    cin>>DiemLuanVan;
    cin.ignore(1000,'\n');
}
void SVDaiHoc::Xuat(){
    cout<<"Sinh Vien Dai Hoc"<<endl;
    SinhVien::Xuat();
    cout<<"Luan Van:"<<LuanVan<<endl;
    cout<<"Diem Luan Van:"<<DiemLuanVan<<endl;

}
bool SVDaiHoc::XetTotNgiep(){
    if(TongTinChi>=170 && DTB>=5 && DiemLuanVan>=5)
    return true;
    else return false;

}
// sử dụng đa hình
// Hàm nhập xuát và hàm XetTotNghiep() được viết dè lên hàm của lớp cha

void SVCaoDang::Nhap(){
    cout<<"Sinh Vien Cao Dang"<<endl;
    SinhVien::Nhap();
    cout<<"Nhap Diem Thi TN:";
    cin>>DiemThiTN;
    cin.ignore(1000,'\n');
}
void SVCaoDang::Xuat(){
    cout<<"Sinh Vien Cao Dang"<<endl;
    SinhVien::Xuat();
    cout<<"Diem Thi TN:"<<DiemThiTN<<endl;
}
bool SVCaoDang::XetTotNgiep(){
    if(TongTinChi>=120 && DTB>=5 && DiemThiTN>=5)
    return true;
    else return false;

}
// Hàm nhập ds sinh viên
void TruongDH::NhapDSSinhVien(){
    cout<<"Nhap DS Sinh Vien:"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        SinhVien*sv;
        int loai;
        cout<<"Nhap loai Sinh Vien (0--Cao Dang,1--Dai Hoc ):";
        cin>>loai;
        cin.ignore(1000,'\n');
        while(loai!=0 && loai!=1)
        {
            cout<<"Loai Sinh Vien ko ton tai, Nhap lai:";
            cin>>loai;
            cin.ignore(1000,'\n');
        }
        if(loai==0)
        {
            sv=new SVCaoDang();
        }
        else
        sv=new SVDaiHoc();
        sv->Nhap();
        ds.push_back(sv);
    }
}
//Hàm xuát ds sinh viên
void TruongDH::XuatDSSinhVien(){
    cout<<"DS Sinh Vien "<<endl;
    for(auto i:ds)
    {
        i->Xuat();
        cout<<endl;
    }
}
// Hàm xuất các sinh viên tốt nghiệp
void TruongDH::DSSV_TotNghiep(){
    cout<<"Danh sach Sinh Vien Tot Nghiep:"<<endl;
    for(auto i:ds)
    {
        if(i->XetTotNgiep())
        i->Xuat();
        cout<<endl;
    }
}
// Hàm xuất các sinh viên KO tốt nghiệp
void TruongDH::DSSV_KoTotNghiep(){
    cout<<"Danh sach Sinh Vien KO Tot Nghiep:"<<endl;
    for(auto i:ds)
    {
        if(!(i->XetTotNgiep()))
        i->Xuat();
        cout<<endl;

    }
}
// Hàm tìm sv cao đẳng có điểm TB cao nhất
void TruongDH::SV_maxDTB_CaoDang(){
    cout<<"Sinh Vien Cao Dang co dtb Cao Nhat:"<<endl;
    SinhVien*max=nullptr;
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(SVCaoDang)) // so sánh kiểu dữ liệu
        {
            if(max==nullptr || max->getDTB()< i->getDTB())
            max=i;
        }
    }
    if(max!=nullptr)
    {
        max->Xuat();
    }
}
// Hàm tìm sv đại học có diểm TB cao nhất
void TruongDH::SV_maxDTB_DaiHoc(){
cout<<"Sinh Vien Dai Hoc co dtb Cao Nhat:"<<endl;
    SinhVien*max=nullptr;
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(SVDaiHoc))
        {
            if(max==nullptr || max->getDTB()< i->getDTB()) // so sánh DTB
            max=i;
        }
    }
    if(max!=nullptr)
    {
        max->Xuat();
    }

}
// Hàm tính số lượng sv ko tốt nghiệp theo từng loại
void TruongDH::SL_KoTotNghiep(){
    int caodang=0;
    int daihoc=0;
    for(auto i:ds)
    {
        if(typeid(*i)==typeid(SVCaoDang) && !(i->XetTotNgiep()))
        caodang++;
        if(typeid(*i)==typeid(SVDaiHoc) && !(i->XetTotNgiep()))
        daihoc++;
        
    }
    cout<<"SL Sinh Vien Cao Dang KO Tot Nghiep:"<<caodang<<endl;
    cout<<"SL Sinh Vien Dai Hoc KO Tot Nghiep:"<<daihoc<<endl;


}



