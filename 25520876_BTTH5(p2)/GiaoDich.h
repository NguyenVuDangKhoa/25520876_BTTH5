#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;
class GiaoDich {
    protected:
    int MaGD;
    string NgayGD;
    double DonGia;
    int DienTich;

    public:
    // Contructor mặc định có tham số mặc nhiên
    GiaoDich(int m=0, string n="",double g=0,int gt=0) {
        MaGD=m;
        NgayGD=n;
        DonGia=g;
        DienTich=gt;
    }
    // Destructor
    virtual ~GiaoDich(){}
    // Hàm nhập, xuất, ThanhTien mang virtual để lớp con viết lại
    virtual void Nhap() ;

    virtual void Xuat() ;
    virtual double ThanhTien()=0 ;
    // hàm getter lấy ngày
    string getNgay()
    {
        return NgayGD;
    }


};

class GDDat : public GiaoDich {
private:
char LoaiDat;
public:
// Hàm nhập xuất, ThanhTien viết lại 
void Nhap()override;
void Xuat()override;
double ThanhTien()override;
};

class GDNhaPho : public GiaoDich {
private:
  string LoaiNha;
public:
// Hàm nhập xuất, ThanhTien viết lại 
    void Nhap()override;
    void Xuat()override;
    double ThanhTien()override;
};

class GDChungCu : public GiaoDich {
    private:
    int SoTang;
    public:
    // Hàm nhập xuất, ThanhTien viết lại 
    void Nhap()override;
    void Xuat()override;
    double ThanhTien()override;

};

class CongTy {
private:
// mảng địa chỉ của lớp cha để quản lý
vector<GiaoDich*>ds;
int n;
public:
//Constructor
    CongTy(int k=0)
    {
       n=k;
    }
//Destructor xóa địa chỉ mà con trỏ đc cấp phát trong quá trình 
    ~CongTy(){
        for(auto i:ds)
        {
            delete i;
        }
    }
    void NhapDSGiaoDich();
    void XuatDSGiaoDich();
    void SLTungLoai();
    double TBChungCu();
    void maxNhaPho();
    void GDTrongthang12Nam2024();



};