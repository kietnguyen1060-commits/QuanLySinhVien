# Quản lý sinh viên (C++ OOP)

Bài tập lập trình hướng đối tượng: chương trình quản lý danh sách sinh viên viết bằng C++ thuần, **không dùng thư viện `<string>`/`<cstring>`** — tự cài đặt lớp chuỗi `MyString` bằng mảng `char*` cấp phát động và tự nạp chồng các toán tử.

## Cấu trúc

| File | Nội dung |
|---|---|
| `MyString.h` / `MyString.cpp` | Lớp chuỗi tự cài: cấp phát động, hàm tạo sao chép, hàm hủy, tự viết `strlen`/`strcpy`/`strcmp` |
| `SinhVien.h` / `SinhVien.cpp` | Lớp `SinhVien`: mã sinh viên, họ tên, lớp, điểm, xếp loại |
| `main.cpp` | Mảng đối tượng `SinhVien` + menu chức năng |

## Các toán tử được nạp chồng

**`MyString`**

| Toán tử | Ý nghĩa |
|---|---|
| `=` | Gán chuỗi (từ `MyString` hoặc `const char*`), có chống tự gán |
| `[]` | Truy cập ký tự theo chỉ số (bản `const` và không `const`) |
| `+`, `+=` | Nối chuỗi |
| `==`, `!=`, `<`, `>` | So sánh chuỗi theo thứ tự từ điển |
| `!` | Kiểm tra chuỗi rỗng |
| `<<`, `>>` | Xuất ra màn hình / nhập cả dòng (họ tên có dấu cách) |

**`SinhVien`**

| Toán tử | Ý nghĩa |
|---|---|
| `==`, `!=` | So sánh theo mã sinh viên (dùng để kiểm tra trùng mã khi thêm và tìm khi xóa) |
| `<`, `>` | So sánh theo điểm (dùng cho sắp xếp) |
| `+`, `+=` | Cộng điểm thưởng (tự giới hạn trong khoảng 0–10) |
| `[]` | Lấy thông tin theo chỉ số: `0` mã, `1` họ tên, `2` lớp, `3` xếp loại |
| `<<`, `>>` | Xuất một dòng trong bảng / nhập thông tin sinh viên |

## Chức năng

1. Thêm sinh viên (kiểm tra trùng mã)
2. Xóa sinh viên theo mã
3. Sắp xếp: điểm giảm dần, điểm tăng dần, hoặc theo tên A→Z
4. Hiển thị danh sách dạng bảng
5. Tìm sinh viên theo mã
6. Cộng điểm thưởng

## Biên dịch và chạy

```bash
g++ -o QuanLySinhVien main.cpp MyString.cpp SinhVien.cpp
./QuanLySinhVien
```

Chương trình chỉ dùng `<iostream>` và `<iomanip>` của thư viện chuẩn.
