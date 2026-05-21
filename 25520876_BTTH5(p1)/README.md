Hàm CheckDate(string s)
Chức năng: Kiểm tra chuỗi ngày sinh có đúng định dạng dd/mm/yyyy hay không.
Input: s: chuỗi ngày sinh kiểu string. VD: "01/01/2000"
Output: true: nếu đúng định dạng; false: nếu sai định dạng.
Hướng giải thuật
Kiểm tra độ dài chuỗi phải bằng 10.
Kiểm tra ký tự thứ 2 và 5 phải là dấu '/'.
Nếu tất cả đúng thì trả về true.
Ngược lại trả về false.

Hàm Trans(string s)
Chức năng: Chuyển ngày sinh dạng chuỗi sang số nguyên để dễ so sánh tuổi.
Input: s: chuỗi ngày sinh dạng dd/mm/yyyy.
Output: Số nguyên dạng: yyyymmdd VD:20040520
Hướng giải thuật
Dùng substr() cắt:ngày,tháng,năm.
Dùng stoi() chuyển sang số nguyên.
Ghép thành:
nam*10000 + thang*100 + ngay
Trả về kết quả.

Hàm NhanVien::Nhap()
Chức năng: Nhập thông tin cơ bản của nhân viên.
Input: Người dùng nhập: Họ tên, Ngày sinh
Output: Không trả về giá trị, Cập nhật dữ liệu cho đối tượng nhân viên.
Hướng giải thuật
Nhập họ tên bằng getline().
Nhập ngày sinh.
Gọi CheckDate() kiểm tra định dạng.
Nếu sai:
báo lỗi,
yêu cầu nhập lại.
Lặp đến khi hợp lệ.

Hàm NVSanXuat::Nhap()
Chức năng: Nhập thông tin nhân viên sản xuất.
Input: Người dùng nhập: Họ tên, Ngày sinh, Lương cơ bản, Số sản phẩm
Output:Không trả về giá trị, Cập nhật dữ liệu cho đối tượng.
Hướng giải thuật
Gọi:
NhanVien::Nhap()
để nhập thông tin chung.
Nhập:
LuongCB
SP

Hàm NVSanXuat::Xuat()
Chức năng: Xuất thông tin nhân viên sản xuất.
Input:Không có.
Output: In thông tin nhân viên ra màn hình.
Hướng giải thuật
In dòng:
Nhan vien San Xuat
Gọi:
NhanVien::Xuat()
để xuất thông tin chung

Hàm NVSanXuat::TinhLuong()
Chức năng: Tính lương nhân viên sản xuất.
Input:Dữ liệu thuộc tính, LuongCB, SP
Output:Giá trị lương kiểu double, Công thức: Luong=LuongCB+SP×5000
Hướng giải thuật
Lấy lương cơ bản.
Nhân số sản phẩm với 5000.
Cộng hai giá trị.
Gán vào biến Luong.
Trả về kết quả

Hàm NVVanPhong::Nhap()
Chức năng: Nhập thông tin nhân viên văn phòng.
Input: Người dùng nhập:Họ tên, Ngày sinh, Số ngày làm
Output:Không trả về giá trị.
Hướng giải thuật
Gọi:
NhanVien::Nhap()
Nhập số ngày làm việc

Hàm NVVanPhong::Xuat()
Chức năng:Xuất thông tin nhân viên văn phòng.
Input: Không có.
Output: In thông tin ra màn hình.
Hướng giải thuật
In:Nhan vien Van Phong
Gọi:NhanVien::Xuat()

Hàm NVVanPhong::TinhLuong()
Chức năng: Tính lương nhân viên văn phòng.
Input: SoNgayLam
Output: Lương kiểu double.
Công thức: Luong=SoNgayLam×100000
Hướng giải thuật
Lấy số ngày làm.
Nhân với 100000.
Gán vào Luong.
Trả về kết quả.

Hàm CongTy::NhapDSNhanVien()
Chức năng: Nhập danh sách nhân viên cho công ty.
Input: Người dùng nhập:Loại nhân viên: 0: sản xuất; 1: văn phòng
Thông tin nhân viên tương ứng.
Output:Thêm các nhân viên vào vector ds.
Hướng giải thuật
Duyệt từ 0 -> n-1.
Nhập loại nhân viên.
Kiểm tra loại hợp lệ.
Nếu:
0 → cấp phát động NVSanXuat
1 → cấp phát động NVVanPhong
Dùng con trỏ cha:
NhanVien* nv;
để lưu địa chỉ object con.
Gọi:
nv->Nhap();
Đưa vào vector:
ds.push_back(nv);

Hàm CongTy::XuatDSNhanVien()
Chức năng:Xuất toàn bộ danh sách nhân viên.
Input: Vector ds.
Output:In danh sách nhân viên ra màn hình.
Hướng giải thuật
Duyệt từng phần tử trong vector.
Gọi:
i->Xuat();
Nhờ đa hình:
đúng hàm Xuat() của lớp con sẽ được gọi

Hàm CongTy::TongLuong()
Chức năng: Tính tổng lương toàn công ty.
Input: Danh sách nhân viên ds.
Output:Tổng lương kiểu double.
Hướng giải thuật
Tạo biến Tong = 0.
Duyệt từng nhân viên.
Gọi:
i->TinhLuong();
Cộng dồn vào Tong.
Trả về kết quả

Hàm CongTy::maxTuoiVP()
Chức năng

Tìm nhân viên văn phòng lớn tuổi nhất.

Input: Vector nhân viên ds.
Outputp: In thông tin nhân viên văn phòng lớn tuổi nhất.
Hướng giải thuật
Tạo con trỏ:
NhanVien* LonNhat = NULL;
Duyệt danh sách nhân viên.
Dùng:
typeid(*i)==typeid(NVVanPhong) để kiểm tra đúng kiểu.
So sánh ngày sinh bằng: Trans()
Người có ngày sinh nhỏ hơn:
19990101 < 20020101
=> lớn tuổi hơn.
Cập nhật LonNhat.
Xuất kết quả

Hàm CongTy::minLuongSX()
Chức năng: Tìm nhân viên sản xuất có lương thấp nhất.
Input: Vector ds.
Output: In thông tin nhân viên sản xuất có lương nhỏ nhất.
Hướng giải thuật
Tạo con trỏ:
NhanVien* NhoNhat = NULL;
Duyệt danh sách.
Dùng:
typeid(*i)==typeid(NVSanXuat) để lọc nhân viên sản xuất.
So sánh lương: NhoNhat->TinhLuong() > i->TinhLuong()
Nếu nhỏ hơn: cập nhật NhoNhat.
Xuất nhân viên tìm được
