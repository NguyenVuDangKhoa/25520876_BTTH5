Hàm SVDaiHoc::Nhap()
Chức năng: Nhập thông tin sinh viên đại học.
Input: Người dùng nhập: thông tin chung sinh viên, tên luận văn, điểm luận văn.
Output: Không trả về giá trị, Cập nhật dữ liệu cho object sinh viên đại học.
Hướng giải thuật
In tiêu đề:
Sinh Vien Dai Hoc
Gọi: SinhVien::Nhap() để nhập thông tin chung.
Nhập:tên luận văn, điểm luận văn.
Dùng cin.ignore() để xử lý bộ đệm

Hàm SVDaiHoc::Xuat()
Chức năng: Xuất thông tin sinh viên đại học.
Input: Dữ liệu object.
Output: In thông tin sinh viên ra màn hình.
Hướng giải thuật
In tiêu đề.
Gọi: SinhVien::Xuat()
In:tên luận văn, điểm luận văn.

Hàm SVDaiHoc::XetTotNgiep()
Chức năng: Xét điều kiện tốt nghiệp cho sinh viên đại học.
Input: Các thuộc tính: TongTinChi, DTB, DiemLuanVan
Output:
true: đủ điều kiện tốt nghiệp.
false: không đủ điều kiện.
Điều kiện tốt nghiệp (TongTinChi ≥ 170 ∧ DTB ≥ 5 ∧ DiemLuanVan ≥ 5)
Hướng giải thuật
Kiểm tra: tổng tín chỉ ≥ 170, điểm trung bình ≥ 5, điểm luận văn ≥ 5.
Nếu thỏa hết: trả true.
Ngược lại: trả false

Hàm SVCaoDang::Nhap()
Chức năng: Nhập thông tin sinh viên cao đẳng.
Input: Người dùng nhập: thông tin chung, điểm thi tốt nghiệp.
Output: Không trả về giá trị.
Hướng giải thuật
In tiêu đề.
Gọi: SinhVien::Nhap()
Nhập điểm thi tốt nghiệp.
Xử lý cin.ignore()

Hàm SVCaoDang::Xuat()
Chức năng: Xuất thông tin sinh viên cao đẳng.
Input: Dữ liệu object.
Output: In thông tin sinh viên.
Hướng giải thuật
In tiêu đề.
Gọi: SinhVien::Xuat()
In điểm thi tốt nghiệp.

Hàm SVCaoDang::XetTotNgiep()
Chức năng: Xét điều kiện tốt nghiệp cho sinh viên cao đẳng.
Input: TongTinChi, DTB, DiemThiTN
Output: true: đủ điều kiện, false: không đủ điều kiện.
Điều kiện tốt nghiệp (TongTinChi ≥ 120 ∧ DTB ≥ 5 ∧ DiemThiTN ≥ 5)
Hướng giải thuật
Kiểm tra: tín chỉ ≥ 120, DTB ≥ 5, điểm thi TN ≥ 5.
Nếu đúng: trả true.
Ngược lại: trả false

Hàm TruongDH::NhapDSSinhVien()
Chức năng: Nhập danh sách sinh viên.
Input: Người dùng nhập: loại sinh viên: 0: cao đẳng, 1: đại học, dữ liệu tương ứng.
Output: Thêm sinh viên vào vector ds.
Hướng giải thuật
Duyệt từ 0 -> n-1.
Nhập loại sinh viên.
Kiểm tra hợp lệ.
Dùng con trỏ:
SinhVien* sv;
Nếu: 0:sv = new SVCaoDang(); 1:sv = new SVDaiHoc();
Gọi: sv->Nhap();
Thêm vào vector: ds.push_back(sv);

Hàm TruongDH::XuatDSSinhVien()
Chức năng: Xuất danh sách sinh viên.
Input: Vector ds.
Output: In toàn bộ sinh viên.
Hướng giải thuật
Duyệt vector.
Gọi: i->Xuat();
Nhờ đa hình: đúng hàm lớp con được gọi

Hàm TruongDH::DSSV_TotNghiep()
Chức năng: Xuất danh sách sinh viên tốt nghiệp.
Input: Danh sách sinh viên.
Output: In các sinh viên đủ điều kiện tốt nghiệp.
Hướng giải thuật
Duyệt vector.
Gọi: i->XetTotNgiep()
Nếu trả true:
gọi:i->Xuat();

Hàm TruongDH::DSSV_KoTotNghiep()
Chức năng: Xuất danh sách sinh viên không tốt nghiệp.
Input: Vector sinh viên.
Output: In sinh viên không đạt điều kiện.
Hướng giải thuật
Duyệt vector.
Nếu: !(i->XetTotNgiep())
Gọi: i->Xuat();

Hàm TruongDH::SV_maxDTB_CaoDang()
Chức năng: Tìm sinh viên cao đẳng có điểm trung bình cao nhất.
Input: Vector sinh viên.
Output: In sinh viên cao đẳng có DTB lớn nhất.
Hướng giải thuật
Tạo: SinhVien* max = nullptr;
Duyệt danh sách.
Dùng: typeid(*i)==typeid(SVCaoDang) để lọc sinh viên cao đẳng.
So sánh:max->getDTB() < i->getDTB()
Nếu lớn hơn: cập nhật max.
Xuất kết quả.

Hàm TruongDH::SV_maxDTB_DaiHoc()
Chức năng: Tìm sinh viên đại học có điểm trung bình cao nhất.
Input: Vector sinh viên.
Output: In sinh viên đại học có DTB cao nhất.
Hướng giải thuật
Tạo: SinhVien* max = nullptr;
Duyệt vector.
Dùng: typeid(*i)==typeid(SVDaiHoc)
So sánh DTB.
Cập nhật max.
Xuất kết quả

Hàm TruongDH::SL_KoTotNghiep()
Chức năng: Đếm số lượng sinh viên không tốt nghiệp theo từng loại.
Input: Vector sinh viên.
Output: In: số sinh viên cao đẳng không tốt nghiệp, số sinh viên đại học không tốt nghiệp.
Hướng giải thuật
Tạo: caodang = 0, daihoc = 0
Duyệt danh sách.
Nếu: là SVCaoDang và không tốt nghiệp
→ tăng caodang.
Nếu: là SVDaiHoc và không tốt nghiệp
→ tăng daihoc.
In kết quả
