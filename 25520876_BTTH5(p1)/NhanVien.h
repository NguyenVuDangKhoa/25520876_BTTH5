#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
using namespace std;

class NhanVien
{
protected:
string HoTen;
string NgaySinh;
double Luong;
public:
// Contructor khởi tạo giá trị mặc định có tham số mặc nhiên
NhanVien(string ht="",string ns="",double l=0){
    HoTen=ht;
    NgaySinh=ns;
    Luong=l;
}
// Destructor 
virtual ~NhanVien(){}
// Hàm nhập và xuất của lớp Nhân Viên có virtual để lớp con có thể viết lại
 virtual void Nhap();
virtual void Xuat(){
    cout<<"Ho ten:"<<HoTen<<endl;
    cout<<"NgaySinh:"<<NgaySinh<<endl;
    cout<<"Luong:"<<TinhLuong()<<endl;
}
// Thuần ảo Tính Lương
 virtual double TinhLuong()=0;
 // Hàm lấy ngày sinh
string getNgaySinh(){
    return NgaySinh;

}


};
class NVSanXuat : public NhanVien{
    private:
double LuongCB;
int SP;
public:

void Nhap()override;
void Xuat()override;
double TinhLuong() override;

};
class NVVanPhong : public NhanVien{
    private:
    int SoNgayLam;
    public:
    void Nhap()override;
    void Xuat()override;
    double TinhLuong()override;
};
class CongTy{
private:
vector<NhanVien*>ds;
int n;
public:
// Contructor khởi tạo giá trị mặc định có tham số mặc nhiên
CongTy(int k=0){
    n=k;
}
// Destructor mảng địa chỉ
~CongTy()
{
    for(auto i:ds)
    {
        delete i;
    }
}
void NhapDSNhanVien();
void XuatDSNhanVien();
double TongLuong();
void minLuongSX();
void maxTuoiVP();

};