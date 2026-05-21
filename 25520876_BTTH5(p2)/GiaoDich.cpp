#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include "GiaoDich.h"
using namespace std;
// Hàm kiểm tra dạng nhập vào của ngày giao dịch
bool CheckDate(string s)
{
    return s.length() == 10 &&
           s[2] == '/' &&
           s[5] == '/';
}

// Hàm nhập xuất của lớp cha
void GiaoDich::Nhap()
{
        cout<<"Nhap Ma Giao Dich:";
        cin>>MaGD;
        cin.ignore(1000,'\n');
        cout<<"Nhap Ngay Giao Dich theo dang (VD: 01/01/1000):";
        do
        {
           getline(cin,NgayGD);
           if(!CheckDate(NgayGD))
           { cout<<"Nhap lai Ngay Giao Dich theo dang (VD:01/01/1000)"<<endl;}
        } while (!CheckDate(NgayGD));
        cout<<"Nhap don gia:";
        cin>>DonGia;
        cout<<"Nhap Dien Tich:";
        cin>>DienTich;
        cin.ignore(1000,'\n');
        
}
void GiaoDich::Xuat()
{
    cout<<"Ma Giao Dich:";
        cout<<MaGD<<endl;
        cout<<"Ngay Giao Dich:";
        cout<<NgayGD<<endl;
        cout<<"Don Gia:";
        cout<<DonGia<<endl;
        cout<<"Dien Tich:";
        cout<<DienTich<<endl;
        cout<<"Thanh Tien:";
        cout<<ThanhTien()<<endl;

}
// Sử dụng đa hình để viết lại hàm nhập xuất và ThanhTien của lớp cha
void GDDat::Nhap() 
{
    cout<<"Giao Dich Dat"<<endl;
    GiaoDich::Nhap();
    cout<<"Nhap loai dat (A , B , C):"<<endl;
    do
    {
        cin>>LoaiDat;
        if(LoaiDat != 'A' && LoaiDat != 'B' && LoaiDat != 'C')
        cout<<"Loai dat ko ton tại, Nhap lai (A , B , C): "<<endl;

    } while (LoaiDat != 'A' && LoaiDat != 'B' && LoaiDat != 'C');
    
};
void GDDat::Xuat()
{
        cout<<"Giao Dich Dat"<<endl;
        cout<<"Loai dat:"<<LoaiDat<<endl;
        GiaoDich::Xuat();

}
double  GDDat::ThanhTien()
{
        if(LoaiDat=='B' || LoaiDat=='C')
         return DienTich*DonGia;
        else 
        return DienTich*DonGia*1.5;
}
// Sử dụng đa hình để viết lại hàm nhập xuất và ThanhTien của lớp cha
void GDNhaPho::Nhap()
{
        cout<<"Giao Dich Nha Pho:"<<endl;
        GiaoDich::Nhap();
    cout<<"Nhap loai nha (  cao cap , thuong ):"<<endl;
    do
    {
        getline(cin,LoaiNha);
        if(LoaiNha != "cao cap" && LoaiNha != "thuong" )
        cout<<"Loai dat ko ton tại, Nhap lai ( cao cap, thuong): "<<endl;

    } while (LoaiNha != "cao cap" && LoaiNha != "thuong");
}
void GDNhaPho::Xuat()
{
        cout<<"Giao Dich Nha Pho:"<<endl;
        cout<<"Loai Nha:"<<LoaiNha<<endl;
        GiaoDich::Xuat();
        
}
double GDNhaPho::ThanhTien()
{
        if(LoaiNha=="cao cap")
          return DienTich*DonGia;
        else 
        return DienTich*DonGia*0.9;
}
void GDChungCu::Nhap()
{
        cout<<"Giao Dich Chung Cu:"<<endl;
        GiaoDich::Nhap();
        cout<<"Nhap vi tri tang:";
        cin>>SoTang;
        cin.ignore(1000,'\n');
}
void GDChungCu::Xuat()
{
        cout<<"Giao Dich Chung Cu:"<<endl;
        cout<<"Vi tri tang:"<<SoTang<<endl;
        GiaoDich::Xuat();
}
double GDChungCu::ThanhTien()
{
        if(SoTang==1)
        return DienTich*DonGia*2;
        else if (SoTang>=15)
        return DienTich*DonGia*1.2;
        else
        return DienTich*DonGia;
        
}
void CongTy::NhapDSGiaoDich()
{
        int loai;
        GiaoDich*gd;
        for(int i=0;i<n;i++){
        cout<<"Giao dich thu"<<i+1<<":"<<endl;
        cout<<"Nhap loai Giao Dich (0--Dat, 1--Nha Pho, 2--Chung Cu):";
        cin>>loai;
        while(loai!=1 && loai!=0 && loai!=2)
        {
                cout<<"Loai Giao Dich ko ton tại, Nhap lai:";
                cin>>loai;
        }
        // Nếu nhập 0 thì có địa chỉ của lớp con GDDat
        if (loai==0)
        gd=new GDDat();
        // Nếu nhập 1 thì có địa chỉ của lớp con GDNhaPho
        else if(loai==1)
        gd=new GDNhaPho();
        else
       // Nếu nhập 2 thì có địa chỉ của lớp con GDChungCu
        gd=new GDChungCu();
        gd->Nhap();
        ds.push_back(gd);} //thêm vào danh sách địa chỉ
}
void CongTy::XuatDSGiaoDich()
{
        for(auto i:ds)
        {
                cout<<"Giao dich thu"<<n+1<<":"<<endl;
                i->Xuat();
                cout<<endl;
        }
}
void CongTy::SLTungLoai()
{
        int dat=0;
        int nhapho=0;
        int chungcu=0;
        for(auto i:ds)
        {
                if(typeid(*i)==typeid(GDDat)) //kiểm tra kiểu dữ liệu
                dat++;
                else if(typeid(*i)==typeid(GDNhaPho)) // kiểm tra kiểu dữ liệu 
                nhapho++;
                else
                chungcu++;
        }
        cout<<"Giao Dich Dat:"<<dat<<"\n Giao Dich Nha Pho:"<<nhapho<<"\nGiao Dich Chung Cu:"<<chungcu<<endl;

}
double CongTy::TBChungCu()
{
        double tb=0;
        int sl=0;
        for(auto i:ds)
        {
                if(typeid(*i)==typeid(GDChungCu)) //kiểm tra kiểu dữ liệu
                {
                        tb+=i->ThanhTien();
                        sl++;
                }
        }
        if(sl == 0) // nếu ko có giao dịch chung cư thì trả về 0
        return 0;
        return tb/sl ;
}
void CongTy::maxNhaPho()
{
        GiaoDich*max=nullptr;
        for(auto i:ds)
        {
                if(typeid(*i)==typeid(GDNhaPho)) //kiểm tra kiểu dữ liệu
                {
                        if(max==nullptr || max->ThanhTien() < i->ThanhTien()) // thành tiền của i lớn hơn max thì gán max=i
                        max=i;
                }
        }
        if(max!=nullptr)
        {
                cout<<"Giao Dich Nha Pho co gia tri cao nhat:\n";
                max->Xuat();
        }
}
void CongTy::GDTrongthang12Nam2024()
{
        for(auto i:ds)
        {
                if(i->getNgay().substr(3,2)=="12" && i->getNgay().substr(6,4)=="2024") // lấy 2 kí tự thứ 3,4 có giống "12" ko, lấy 4 kí tự 6,7,8,9 có giống "2024 ko"
                i->Xuat();
        }
}