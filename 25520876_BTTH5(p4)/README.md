Hàm NVLapTrinh::Nhap()
Chức năng: Nhập thông tin nhân viên lập trình.
Input: Người dùng nhập: thông tin chung nhân viên, số giờ làm thêm (SoOVT).
Output: Không trả về giá trị, Cập nhật dữ liệu cho object.
Hướng giải thuật
In tiêu đề: Nhan Vien Lap Trinh
Gọi: NhanVien::Nhap() để nhập thông tin chung.
Nhập số giờ overtime.
Dùng cin.ignore() xử lý bộ đệm

Hàm NVLapTrinh::Xuat()
Chức năng: Xuất thông tin nhân viên lập trình.
Input: Dữ liệu object.
Output: In thông tin ra màn hình.
Hướng giải thuật
In tiêu đề.
Gọi: NhanVien::Xuat()
In: số giờ làm thêm, lương.
Gọi: TinhLuong() để tính lương

Hàm NVLapTrinh::TinhLuong()
Chức năng: Tính lương nhân viên lập trình.
Input: LuongCB, SoOVT, Output, Lương kiểu double, Công thức (Luong=LuongCB+SoOVT×200000)
Hướng giải thuật
Lấy lương cơ bản.
Nhân số giờ overtime với 200000.
Cộng vào lương cơ bản.
Trả về kết quả

Hàm NVKiemDinh::Nhap()
Chức năng: Nhập thông tin nhân viên kiểm định.
Input: Người dùng nhập: thông tin chung, số lỗi tìm được.
Output: Không trả về giá trị.
Hướng giải thuật
In tiêu đề.
Gọi: NhanVien::Nhap()
Nhập số lỗi.
Dùng cin.ignore() xử lý bộ nhớ đệm

Hàm NVKiemDinh::Xuat()
Chức năng: Xuất thông tin nhân viên kiểm định.
Input: Dữ liệu object.
Output: In thông tin nhân viên.
Hướng giải thuật
In tiêu đề.
Gọi: NhanVien::Xuat()
In:số lỗi tìm được, lương

Hàm NVKiemDinh::TinhLuong()
Chức năng: Tính lương nhân viên kiểm định.
Input: LuongCB, SoLoi, Output, Giá trị lương kiểu double, Công thức (Luong=LuongCB+SoLoi×50000)
Hướng giải thuật
Lấy lương cơ bản.
Nhân số lỗi với 50000.
Cộng vào lương cơ bản.
Trả kết quả

Hàm CongTy::NhapDSNhanVien()
Chức năng: Nhập danh sách nhân viên công ty.
Input: Người dùng nhập: loại nhân viên: 0: lập trình, 1: kiểm định, dữ liệu tương ứng.
Output: Thêm nhân viên vào vector ds.
Hướng giải thuật
Duyệt từ 0 -> n-1.
Nhập loại nhân viên.
Kiểm tra dữ liệu hợp lệ.
Dùng con trỏ:
NhanVien* nv;
Nếu: 0: nv = new NVLapTrinh(); 1: nv = new NVKiemDinh();
Gọi: nv->Nhap();
Thêm vào vector: ds.push_back(nv);

Hàm CongTy::XuatDSNhanVien()
Chức năng: Xuất danh sách nhân viên.
Input: Vector ds.
Output: In toàn bộ nhân viên.
Hướng giải thuật
Duyệt vector.
Gọi: i->Xuat();
Nhờ đa hình: đúng hàm lớp con được gọi

Hàm CongTy::DS_ThapHonTB()
Chức năng: Xuất danh sách nhân viên có lương thấp hơn mức lương trung bình.
Input: Danh sách nhân viên.
Output: In: lương trung bình, các nhân viên có lương thấp hơn trung bình, Công thức trung bình (LuongTB=TongLuong/n)
Hướng giải thuật
Tạo biến: tongluong = 0
Duyệt danh sách: tongluong += i->TinhLuong()
Tính: tb = tongluong / n
Duyệt lại danh sách.
Nếu: i->TinhLuong() < tb
→ xuất nhân viên đó.

Hàm CongTy::maxLuong()
Chức năng: Tìm nhân viên có lương cao nhất.
Input: Vector nhân viên.
Output: In nhân viên lương cao nhất.
Hướng giải thuật
Tạo: NhanVien* max = nullptr;
Duyệt danh sách.
So sánh: max->TinhLuong() < i->TinhLuong()
Nếu lớn hơn: cập nhật max.
Xuất kết quả

Hàm CongTy::minLuong()
Chức năng: Tìm nhân viên có lương thấp nhất.
Input: Danh sách nhân viên.
Output: In nhân viên có lương thấp nhất.
Hướng giải thuật
Tạo: NhanVien* min = nullptr;
Duyệt vector.
So sánh: min->TinhLuong() > i->TinhLuong()
Nếu nhỏ hơn: cập nhật min.
Xuất kết quả

Hàm CongTy::maxLuong_LapTrinh()
Chức năng: Tìm nhân viên lập trình có lương cao nhất.
Input: Vector nhân viên.
Output: In nhân viên lập trình lương cao nhất.
Hướng giải thuật
Tạo: NhanVien* lt = nullptr;
Duyệt danh sách.
Dùng: typeid(*i)==typeid(NVLapTrinh) để lọc nhân viên lập trình.
So sánh lương.
Cập nhật lt.
Xuất kết quả

Hàm CongTy::minLuong_KiemDinh()
Chức năng: Tìm nhân viên kiểm định có lương thấp nhất.
Input: Danh sách nhân viên.
Output:In nhân viên kiểm định lương thấp nhất.
Hướng giải thuật
Tạo: NhanVien* kd = nullptr;
Duyệt vector.
Dùng: typeid(*i)==typeid(NVKiemDinh) để lọc nhân viên kiểm định.
So sánh lương.
Nếu nhỏ hơn: cập nhật kd.
Xuất kết quả
