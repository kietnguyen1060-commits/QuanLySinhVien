#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

// =====================================================================
//  Lop MyString - tu cai dat chuoi ky tu, KHONG dung <string>/<cstring>
// =====================================================================
class MyString
{
private:
    char* duLieu;       // mang ky tu cap phat dong, ket thuc bang '\0'
    int   doDai;

    static int  tinhDoDai(const char* s);                 // thay strlen
    static void chepChuoi(char* dich, const char* nguon); // thay strcpy
    static int  soSanh(const char* a, const char* b);     // thay strcmp

public:
    // Khoi tao / huy
    MyString();
    MyString(const char* s);
    MyString(const MyString& khac);
    ~MyString();

    // Toan tu gan =
    MyString& operator=(const MyString& khac);
    MyString& operator=(const char* s);

    // Toan tu truy cap phan tu []
    char&       operator[](int i);
    const char& operator[](int i) const;

    // Toan tu noi chuoi + va +=
    MyString  operator+(const MyString& khac) const;
    MyString& operator+=(const MyString& khac);
    MyString& operator+=(char c);

    // Toan tu so sanh
    bool operator==(const MyString& khac) const;
    bool operator!=(const MyString& khac) const;
    bool operator< (const MyString& khac) const;
    bool operator> (const MyString& khac) const;

    // Toan tu ! : true neu chuoi rong
    bool operator!() const;

    // Tien ich
    int      layDoDai() const;
    MyString inHoa() const;

    // Toan tu nhap / xuat
    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
    friend std::istream& operator>>(std::istream& in,  MyString& s);
};

#endif // MYSTRING_H
