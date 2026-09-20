#include "SinhVien.h"
#include <iomanip>

using namespace std;

// ---------- Khoi tao ----------
SinhVien::SinhVien() : maSV(""), hoTen(""), lop(""), diem(0.0) {}

SinhVien::SinhVien(const MyString& ma, const MyString& ten, const MyString& lop, double diem)
    : maSV(ma), hoTen(ten), lop(lop), diem(diem) {}

// ---------- Nghiep vu ----------
MyString SinhVien::tenRieng() const
{
    int viTri = -1;
    for (int i = 0; i < hoTen.layDoDai(); i++)
        if (hoTen[i] == ' ') viTri = i;         // vi tri dau cach cuoi cung

    if (viTri < 0) return hoTen;

    MyString kq;
    for (int i = viTri + 1; i < hoTen.layDoDai(); i++) kq += hoTen[i];
    return kq;
}

MyString SinhVien::xepLoai() const
{
    if (diem >= 9.0) return MyString("Xuat sac");
    if (diem >= 8.0) return MyString("Gioi");
    if (diem >= 7.0) return MyString("Kha");
    if (diem >= 5.0) return MyString("Trung binh");
    return MyString("Yeu");
}

// ---------- Toan tu so sanh ----------
bool SinhVien::operator==(const SinhVien& khac) const { return maSV.inHoa() == khac.maSV.inHoa(); }
bool SinhVien::operator!=(const SinhVien& khac) const { return !(*this == khac); }
bool SinhVien::operator< (const SinhVien& khac) const { return diem <  khac.diem; }
bool SinhVien::operator> (const SinhVien& khac) const { return diem >  khac.diem; }

// ---------- Toan tu + va += (cong diem thuong) ----------
SinhVien SinhVien::operator+(double diemThuong) const
{
    SinhVien kq(*this);
    kq.diem += diemThuong;
    if (kq.diem > 10) kq.diem = 10;
    if (kq.diem < 0)  kq.diem = 0;
    return kq;
}

SinhVien& SinhVien::operator+=(double diemThuong)
{
    *this = *this + diemThuong;
    return *this;
}

// ---------- Toan tu [] : lay thong tin theo chi so ----------
MyString SinhVien::operator[](int i) const
{
    if (i == 0) return maSV;
    if (i == 1) return hoTen;
    if (i == 2) return lop;
    if (i == 3) return xepLoai();
    return MyString("");
}

// ---------- Toan tu xuat ----------
ostream& operator<<(ostream& out, const SinhVien& sv)
{
    out << left
        << setw(10) << sv.maSV
        << setw(24) << sv.hoTen
        << setw(10) << sv.lop
        << right << fixed << setprecision(2) << setw(6) << sv.diem
        << "   " << left << setw(12) << sv.xepLoai();
    return out;
}

// ---------- Toan tu nhap ----------
istream& operator>>(istream& in, SinhVien& sv)
{
    cout << " Ma sinh vien : ";  in >> sv.maSV;
    cout << " Ho va ten    : ";  in >> sv.hoTen;
    cout << " Lop          : ";  in >> sv.lop;
    cout << " Diem (0-10)  : ";

    while (true)
    {
        if (in >> sv.diem)
        {
            if (sv.diem >= 0 && sv.diem <= 10) break;
            cout << "   [!] Diem phai tu 0 den 10, nhap lai: ";
        }
        else
        {
            if (in.eof()) { sv.diem = 0; break; }
            in.clear();
            char boQua;                                     // bo qua phan nhap sai
            while (in.get(boQua) && boQua != '\n') {}
            cout << "   [!] Phai nhap so, nhap lai: ";
        }
    }
    return in;
}
