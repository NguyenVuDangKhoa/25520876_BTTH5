#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class KhachHang{
protected:
    string TenKH;
    int SLHang;
    double DonGia;
    static double VAT; // khai báo biến static VAT

public:
// Constructor thiết lập giá trị mặc định có tham số mặc nhiên
    KhachHang(string ten="", int sl=0, double dg=0)
    : TenKH(ten), SLHang(sl), DonGia(dg)
{
}
// Destructor của lớp cha
    virtual ~KhachHang(){}
// Hàm nhập xuất của lớp cha (class KhachHang)
// Hàm nhập lấy dữ liệu từ file văn bản XYZ.INP bằng ifstream
    virtual void Nhap(ifstream& fin){
        getline(fin, TenKH);
        fin >> SLHang;
        fin >> DonGia;
        fin.ignore();
    }
// Hàm thuần ảo TinhTien()
    virtual double TinhTien() = 0;
// Hàm xuất ghi dữ liệu đầu ra vào file XYZ.OUT
    virtual void Xuat(ofstream& fout){
        fout << TenKH << endl;
        fout << TinhTien() << endl;
    }
};

class KhachHangA : public KhachHang{
public:
    double TinhTien() override;

};

class KhachHangB : public KhachHang{
private:
    int SoNamThanThiet;

public:
    void Nhap(ifstream& fin) override;
    

    double TinhTien() override;
};

class KhachHangC : public KhachHang{
public:
    double TinhTien() override;
};