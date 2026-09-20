#ifndef SINHVIEN_H
#define SINHVIEN_H
// nap 2 lan thu vien : MyString , SinhVien
#include "MyString.h"

class SinhVien
{
private:
    MyString maSV;
    MyString hoTen;
    MyString lop;
    double   diem;         

public:
  
    SinhVien();
    SinhVien(const MyString& ma, const MyString& ten, const MyString& lop, double diem);

    MyString layMa()    const { return maSV;  }
    MyString layHoTen() const { return hoTen; }
    MyString layLop()   const { return lop;   }
    double   layDiem()  const { return diem;  }


    MyString xepLoai()  const;
    

    // da nang hoa toan tu 

    bool operator==(const SinhVien& khac) const;   
    bool operator< (const SinhVien& khac) const;   
    bool operator> (const SinhVien& khac) const;   

    SinhVien& operator+=(double diemThuong);       // cong diem thuong ngay tren doi tuong

    MyString operator[](int i) const;              // 0:ma  1:ho ten  2:lop  3:xep loai

    friend std::ostream& operator<<(std::ostream& out, const SinhVien& sv);
    // truy cap vao phan tu private
    // toan tu ostream thuoc std , khong viet duoc vao class
    friend std::istream& operator>>(std::istream& in,  SinhVien& sv);
};

#endif // SINHVIEN_H
