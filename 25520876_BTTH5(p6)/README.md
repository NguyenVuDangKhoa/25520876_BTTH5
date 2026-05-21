Biến static VAT
double KhachHang::VAT = 0.1;
Chức năng: Thiết lập thuế VAT dùng chung cho tất cả khách hàng.
Ý nghĩa: VAT là biến static.
Mọi object của:
KhachHangA
KhachHangB
KhachHangC
đều dùng chung một giá trị VAT.
Giá trị
VAT = 0.1
→ tương ứng 10%.

Hàm KhachHang::Nhap(ifstream& fin)
Chức năng: Nhập thông tin khách hàng từ file.
Input: File input stream fin, Dữ liệu đọc: tên khách hàng, số lượng hàng, đơn giá.
Output: Không trả về giá trị.
Cập nhật dữ liệu object.
Hướng giải thuật
Dùng: getline(fin, TenKH) để đọc tên.
Đọc: SLHang, DonGia
Dùng: fin.ignore() để bỏ ký tự xuống dòng còn dư.
Kiến thức sử dụng: File handling (ifstream)

Hàm KhachHang::Xuat(ofstream& fout)
Chức năng: Xuất thông tin khách hàng ra file.
Input: File output stream fout.
Output: Ghi vào file:tên khách hàng, tổng tiền.
Hướng giải thuật
Ghi: TenKH
Gọi: TinhTien() để tính tổng tiền.
Ghi kết quả vào file.
Kiến thức sử dụng: ofstream
Đa hình: TinhTien() sẽ gọi đúng phiên bản lớp con

Hàm KhachHangA::TinhTien()
Chức năng: Tính tổng tiền cho khách hàng loại A.
Input: Các thuộc tính: SLHang, DonGia, VAT
Output: Tổng tiền kiểu double, Công thức: Tiền hàng (Tong=SLHang×DonGia), Sau thuế VAT (TongSauVAT=Tong+Tong×VAT)
Hướng giải thuật
Tính: tong = SLHang * DonGia
Tính VAT: tong * VAT
Cộng VAT vào tổng tiền.
Trả kết quả.

Hàm KhachHangB::Nhap(ifstream& fin)
Chức năng:
Nhập dữ liệu khách hàng loại B từ file.
Input: File input stream fin; Dữ liệu đọc: thông tin khách hàng chung, số năm thân thiết.
Output: Không trả về giá trị, Cập nhật dữ liệu object.
Hướng giải thuật
Gọi: KhachHang::Nhap(fin) để đọc thông tin chung.
Đọc: SoNamThanThiet
Dùng: fin.ignore() để bỏ ký tự xuống dòng còn dư.
Kiến thức sử dụng
File handling (ifstream)
Kế thừa
Gọi hàm lớp cha

Hàm KhachHangB::TinhTien()
Chức năng: Tính tổng tiền cho khách hàng loại B có giảm giá theo số năm thân thiết.
Input: SLHang, DonGia, SoNamThanThiet, VAT
Output: Tổng tiền kiểu double, Quy tắc giảm giá, Mỗi năm thân thiết:5%, Giảm tối đa:50%
Công thức giảm giá: KhuyenMai=SoNamThanThiet×5
Giới hạn khuyến mãi: KhuyenMai≤50
Thành tiền: Tong=SLHang×DonGia× (100−KhuyenMai)/100
Sau VAT: TongSauVAT=Tong+Tong×VAT
Hướng giải thuật
Tính phần trăm khuyến mãi: KhuyenMai = SoNamThanThiet * 5
Nếu lớn hơn 50: gán bằng 50.
Tính tiền hàng.
Áp dụng giảm giá.
Cộng thêm VAT.
Trả kết quả

Hàm KhachHangC::TinhTien()
Chức năng: Tính tổng tiền cho khách hàng loại C.
Input: SLHang, DonGia, VAT
Output: Tổng tiền kiểu double, Quy tắc: Khách hàng loại C chỉ trả: 50% giá trị đơn hàng trước VAT.
Công thức:
Tiền sau giảm: Tong=SLHang×DonGia×0.5
Sau VAT: TongSauVAT=Tong+Tong×VAT
Hướng giải thuật
Tính:
tong = SLHang * DonGia * 0.5
Tính VAT.
Cộng VAT vào tổng tiền.
Trả kết quả
