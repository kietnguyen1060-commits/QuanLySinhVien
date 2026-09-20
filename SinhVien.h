#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "MyString.h"

// =====================================================================
//  Lop SinhVien - dung MyString thay cho string
// =====================================================================
class SinhVien
{
private:
    MyString maSV;
    MyString hoTen;
    MyString lop;
    double   diem;          // diem trung binh, thang 10

public:
    // Khoi tao
    SinhVien();
    SinhVien(const MyString& ma, const MyString& ten, const MyString& lop, double diem);

    // Truy xuat
    MyString layMa()    const { return maSV;  }
    MyString layHoTen() const { return hoTen; }
    MyString layLop()   const { return lop;   }
    double   layDiem()  const { return diem;  }

    MyString tenRieng() const;      // lay ten goi (phan sau dau cach cuoi cung)
    MyString xepLoai()  const;

    // ---------- Cac toan tu nap chong ----------
    bool operator==(const SinhVien& khac) const;   // cung ma sinh vien
    bool operator!=(const SinhVien& khac) const;
    bool operator< (const SinhVien& khac) const;   // diem thap hon
    bool operator> (const SinhVien& khac) const;   // diem cao hon

    SinhVien  operator+(double diemThuong) const;  // cong diem thuong, tra ve ban sao
    SinhVien& operator+=(double diemThuong);       // cong diem thuong ngay tren doi tuong

    MyString operator[](int i) const;              // 0:ma  1:ho ten  2:lop  3:xep loai

    friend std::ostream& operator<<(std::ostream& out, const SinhVien& sv);
    friend std::istream& operator>>(std::istream& in,  SinhVien& sv);
};

#endif // SINHVIEN_H
