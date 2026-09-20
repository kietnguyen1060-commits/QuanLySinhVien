#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char* duLieu;       
    int   doDai;

    static int  tinhDoDai(const char* s);                 // thay strlen
    static void chepChuoi(char* dich, const char* nguon); // thay strcpy
    static int  soSanh(const char* a, const char* b);     // thay strcmp

public:

    MyString();
    MyString(const char* s);
    MyString(const MyString& khac);
    ~MyString();

    
    MyString& operator=(const MyString& khac);
    MyString& operator=(const char* s);

    // Toan tu noi chuoi + va +=
    MyString  operator+(const MyString& khac) const;
    MyString& operator+=(char c);

    // Toan tu so sanh
    bool operator==(const MyString& khac) const;
    bool operator> (const MyString& khac) const;

    // Tien ich
    MyString inHoa() const;

    // Toan tu nhap / xuat
    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
    friend std::istream& operator>>(std::istream& in,  MyString& s);
};

#endif // MYSTRING_H
