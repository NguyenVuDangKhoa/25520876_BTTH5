#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
class SinhVien {
    protected:
    int MaSV;
    string HoTen;
    string DiaChi;
    int TongTinChi;
    double DTB;
    public:
    // Constructor thiết lập tham số mặc định có tham số mặc nhiên
    SinhVien (int ma=0,string ht="",string dc="",int tc=0,double dtb=0){
        MaSV=ma;
        HoTen=ht;
        DiaChi=dc;
        TongTinChi=tc;
        DTB=dtb;
        
    }
    // Destructor của lớp cha (lớp SinhVien)
    virtual ~SinhVien(){}
    // Hàm nhập xuất và XetTotNghiep() của lớp cha (lớp SinhVien)
    virtual void Nhap(){
        cout<<"Nhap Ma So Sinh Vien:";
        cin>>MaSV;
        cin.ignore(1000,'\n');
        cout<<"Nhap Ho Ten:";
        getline(cin,HoTen);
        cout<<"Nhap Dia Chi:";
        getline(cin,DiaChi);
        cout<<"Nhap Tong Tin Chi:";
        cin>>TongTinChi;
        cout<<"Nhap Diem Trung Binh:";
        cin>>DTB;
        cin.ignore(1000,'\n');
        
    }
    virtual void Xuat(){
        cout<<"Ma so SV:"<<MaSV<<endl;
        cout<<"Ho Ten:"<< HoTen<<endl;
        cout<<"Dia Chi:"<<DiaChi<<endl;
        cout<<"Tong Tin Chi:"<<TongTinChi<<endl;
        cout<<"DTB:"<<DTB<<endl;
    }
    // Hàm thuần ảo
    virtual bool XetTotNgiep()=0;
    // Hàm getter lấy DTB
    double getDTB(){
        return DTB;
    }

    
};

class SVDaiHoc : public SinhVien {
    private:
    string LuanVan;
    double DiemLuanVan;
    public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNgiep() override;

};

class SVCaoDang : public SinhVien{
    private:
    double DiemThiTN;
    public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNgiep() override;

};

class TruongDH {
    private:
    vector<SinhVien*>ds;
    int n;
    public:
    // Constructor thiết lặp tham số mặc định có tham số mặc nhiên
    TruongDH (int k=0){
        n=k;
    }
    // Destructor hủy địa chỉ đã cấp phát cho amngr con trỏ
    ~TruongDH() {
        for(auto i:ds)
        {
            delete i;
        }
    }
    void NhapDSSinhVien();
    void XuatDSSinhVien();
    void DSSV_TotNghiep();
    void DSSV_KoTotNghiep();
    void SV_maxDTB_DaiHoc();
    void SV_maxDTB_CaoDang();
    void SL_KoTotNghiep();
};