Hàm CheckDate(string s)
Chức năng: Kiểm tra chuỗi ngày giao dịch có đúng định dạng dd/mm/yyyy.
Input: s: chuỗi ngày giao dịch, Ví dụ:"21/05/2026"
Output:true: đúng định dạng ,false: sai định dạng.
Hướng giải thuật
Kiểm tra độ dài chuỗi bằng 10.
Kiểm tra ký tự thứ 2 và 5 là '/'.
Nếu thỏa hết:
trả về true.
Ngược lại:
trả về false.

Hàm GiaoDich::Nhap()
Chức năng: Nhập thông tin chung của một giao dịch.
Input:Người dùng nhập: Mã giao dịch, Ngày giao dịch, Đơn giá, Diện tích
Output: Không trả về giá trị, Cập nhật dữ liệu cho object giao dịch.
Hướng giải thuật
Nhập mã giao dịch.
Nhập ngày giao dịch.
Dùng CheckDate() để kiểm tra định dạng.
Nếu sai:
báo lỗi,
yêu cầu nhập lại.
Nhập:
đơn giá,
diện tích.
Xử lý cin.ignore() để tránh lỗi bộ nhớ đệm.

Hàm GiaoDich::Xuat()
Chức năng: Xuất thông tin giao dịch.
Input: Dữ liệu thuộc tính của object.
Output: In thông tin giao dịch ra màn hình.
Hướng giải thuật
In: mã giao dịch, ngày giao dịch, đơn giá, diện tích.
Gọi:
ThanhTien() để in thành tiền.

Hàm GDDat::Nhap()
Chức năng: Nhập thông tin giao dịch đất.
Input: Người dùng nhập: thông tin giao dịch chung, loại đất (A, B, C).
Output: Không trả về giá trị.
Hướng giải thuật
In loại giao dịch.
Gọi:
GiaoDich::Nhap()
Nhập loại đất.
Kiểm tra:
A || B || C
Nếu sai:
yêu cầu nhập lại.

Hàm GDDat::Xuat()
Chức năng: Xuất thông tin giao dịch đất.
Input: Dữ liệu object.
Output: In thông tin giao dịch đất.
Hướng giải thuật
In:
Giao Dich Dat
In loại đất.
Gọi: GiaoDich::Xuat()

Hàm GDDat::ThanhTien()
Chức năng: Tính thành tiền giao dịch đất.
Input: LoaiDat, DienTich, DonGia
Output: Thành tiền kiểu double, Công thức: Đất loại B hoặc C (ThanhTien=DienTich×DonGia); Đất loại A (ThanhTien=DienTich×DonGia×1.5)
Hướng giải thuật
Kiểm tra loại đất.
Nếu:
B hoặc C:
tính bình thường.
Nếu:
A:
nhân thêm 1.5.
Trả kết quả

Hàm GDNhaPho::Nhap()
Chức năng: Nhập thông tin giao dịch nhà phố.
Input: Người dùng nhập: thông tin chung, loại nhà:"cao cap", "thuong"
Output: Không trả về giá trị.
Hướng giải thuật
Gọi:
GiaoDich::Nhap()
Nhập loại nhà bằng getline().
Kiểm tra dữ liệu hợp lệ.
Nếu sai:
yêu cầu nhập lại

Hàm GDNhaPho::Xuat()
Chức năng: Xuất thông tin giao dịch nhà phố.
Input: Dữ liệu object.
Output: In ra màn hình.
Hướng giải thuật
In tiêu đề.
In loại nhà.
Gọi: GiaoDich::Xuat()

Hàm GDNhaPho::ThanhTien()
Chức năng: Tính thành tiền giao dịch nhà phố.
Input: LoaiNha, DienTich, DonGia
Output:Thành tiền kiểu double, Công thức: Nhà cao cấp (ThanhTien=DienTich×DonGia); Nhà thường (ThanhTien=DienTich×DonGia×0.9)
Hướng giải thuật
Kiểm tra loại nhà.
Nếu "cao cap":
tính bình thường.
Nếu "thuong":
giảm còn 90%.
Trả kết quả

Hàm GDChungCu::Nhap()
Chức năng: Nhập thông tin giao dịch chung cư.
Input: Người dùng nhập: thông tin chung, số tầng.
Output: Không trả về giá trị.
Hướng giải thuật
Gọi: GiaoDich::Nhap()
Nhập số tầng.
Dùng cin.ignore() xử lý bộ đệm

Hàm GDChungCu::Xuat()
Chức năng: Xuất thông tin giao dịch chung cư.
Input: Dữ liệu object.
Output: In thông tin ra màn hình.
Hướng giải thuật
In tiêu đề.
In số tầng.
Gọi: GiaoDich::Xuat()

Hàm GDChungCu::ThanhTien()
Chức năng: Tính thành tiền giao dịch chung cư.
Input: SoTang, DienTich, DonGia
Output: Thành tiền kiểu double, Công thức: Tầng 1 (ThanhTien=DienTich×DonGia×2); Tầng ≥ 15(ThanhTien=DienTich×DonGia×1.2); Các tầng khác(ThanhTien=DienTich×DonGia)
Hướng giải thuật
Kiểm tra số tầng.
Nếu: tầng 1:nhân 2.
Nếu: tầng >=15: nhân 1.2.
Ngược lại:
tính bình thường.
Trả kết quả.

Hàm CongTy::NhapDSGiaoDich()
Chức năng: Nhập danh sách giao dịch.
Input: Người dùng nhập: loại giao dịch:0: đất, 1: nhà phố, 2: chung cư, dữ liệu tương ứng.
Output: Thêm giao dịch vào vector ds.
Hướng giải thuật
Duyệt từ 0 -> n-1.
Nhập loại giao dịch.
Kiểm tra hợp lệ.
Dùng con trỏ:
GiaoDich* gd;
Cấp phát động:
new GDDat
new GDNhaPho
new GDChungCu
Gọi: gd->Nhap();
Thêm vào vector:
ds.push_back(gd);

Hàm CongTy::XuatDSGiaoDich()
Chức năng: Xuất toàn bộ danh sách giao dịch.
Input: Vector ds.
Output: In danh sách giao dịch.
Hướng giải thuật
Duyệt vector.
Gọi: i->Xuat();
Nhờ đa hình:
đúng hàm lớp con sẽ chạy

Hàm CongTy::SLTungLoai()
Chức năng: Đếm số lượng từng loại giao dịch.
Input: Vector ds.
Output: 
In: số giao dịch đất, nhà phố, chung cư. 
Hướng giải thuật
Tạo 3 biến đếm:dat, nhapho, chungcu
Duyệt vector.
Dùng typeid() xác định kiểu object.
Tăng biến đếm tương ứng.
In kết quả

Hàm CongTy::TBChungCu()
Chức năng: Tính trung bình thành tiền giao dịch chung cư.
Input: Danh sách giao dịch.
Output: Giá trị trung bình kiểu double, Công thức:TB=∑ThanhTien/SoLuong
Hướng giải thuật
Tạo: tổng tb, số lượng sl
Duyệt danh sách.
Nếu là GDChungCu:
cộng thành tiền,
tăng số lượng.
Nếu sl == 0:
trả 0.
Ngược lại:
trả tb/sl

Hàm CongTy::maxNhaPho()
Chức năng: Tìm giao dịch nhà phố có giá trị lớn nhất.
Input: Vector giao dịch.
Output: In giao dịch có thành tiền lớn nhất.
Hướng giải thuật
Tạo con trỏ: GiaoDich* max = nullptr;
Duyệt danh sách.
Lọc GDNhaPho.
So sánh: max->ThanhTien() < i->ThanhTien()
Nếu lớn hơn: cập nhật max.
Xuất kết quả.

Hàm CongTy::GDTrongthang12Nam2024()
Chức năng: Xuất các giao dịch trong tháng 12 năm 2024.
Input:Vector giao dịch.
Output: In các giao dịch thỏa điều kiện.
Hướng giải thuật
Duyệt danh sách.
Dùng: substr(3,2) để lấy tháng.
Dùng: substr(6,4) để lấy năm.
Nếu: thang == "12" && nam == "2024"
Gọi: i->Xuat();
