#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
using  namespace std;
class NhanVien {
    protected:
    int MaNV;
    string HoTen;
    int Tuoi;
    string SDT;
    string Email;
    double LuongCB;
    public:
    // ConTructor thiết lặp tham số mặc định có tham số mặc nhiên
    NhanVien(int ma=0, string ht="", int t=0, string sdt ="",string email="",double l=0 ){
        MaNV=ma;
        HoTen=ht;
        Tuoi=t;
        SDT=sdt;
        Email=email;
        LuongCB=l;

    }
    // Destrucctor
    virtual ~NhanVien(){}
    // Hàm nhập xuất và TinhLuong() của lớp cha(class NhanVien)
    virtual void Nhap(){
        cout<<"Nhap Ma Nhan Vien:";
        cin>>MaNV;
        cin.ignore(1000,'\n');
        cout<<"Nhap Ho Ten Nhan Vien:";
        getline(cin,HoTen);
        cout<<"Nhap Tuoi:";
        cin>>Tuoi;
        cin.ignore(1000,'\n');
        cout<<"Nhap SDT:";
        getline(cin,SDT);
        cout<<"Nhap Email:";
        getline(cin,Email);
        cout<<"Nhap Luong Co Ban:";
        cin>>LuongCB;

    }
    virtual void Xuat(){
        cout<<"Ma Nhan Vien:"<<MaNV<<endl;
        cout<<"Ho va Ten:"<<HoTen<<endl;
        cout<<"Tuoi:"<<Tuoi<<endl;
        cout<<"SDT:"<<SDT<<endl;
        cout<<"Email:"<<Email<<endl;
        cout<<"Luong Co Ban:"<<LuongCB<<endl;
    }
    // Hàm thuần ảo TinhLuong()
    virtual double TinhLuong()=0;

};

class NVLapTrinh : public NhanVien {
    private:
    double SoOVT;
    public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};

class NVKiemDinh : public NhanVien{
    private:
    int SoLoi;
    public:
    void Nhap();
    void Xuat();
    double TinhLuong();

};

class CongTy {
    private:
    vector<NhanVien*>ds; // mảng vector chứ các địa chỉ Nhân viên
    int n;
    public:
    // Constructor thiết lặp tham số mặc định có tham số mặc nhiên
    CongTy(int k=0){
        n=k;
    }
    // Destructor xóa giá trị địa chỉ của mảng vector
    ~CongTy(){
        for(auto i:ds)
        {
            delete i;
        }
    }
    void NhapDSNhanVien();
    void XuatDSNhanVien();
    void DS_ThapHonTB();
    void maxLuong();
    void minLuong();
    void maxLuong_LapTrinh();
    void minLuong_KiemDinh();
    
};