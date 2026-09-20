#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

// Lop chuoi tu cai dat, khong dung <string> va <cstring>
class MyString
{
private:
    char* duLieu;                                      // mang ky tu dong, ket thuc bang '\0'

    static int  doDai(const char* s);                  // thay strlen
    static void chep(char* dich, const char* nguon);   // thay strcpy
    static int  soSanh(const char* a, const char* b);  // thay strcmp

public:
    MyString(const char* s = "");                      // tao chuoi rong hoac tu chuoi C
    MyString(const MyString& khac);                    // tao ban sao
    ~MyString();

    MyString& operator=(const MyString& khac);         // gan
    MyString  operator+(const MyString& khac) const;   // noi hai chuoi
    MyString& operator+=(char c);                      // noi them mot ky tu

    bool operator==(const MyString& khac) const;       // so sanh bang
    bool operator> (const MyString& khac) const;       // so sanh thu tu tu dien

    MyString inHoa() const;                            // doi sang chu in hoa

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
    friend std::istream& operator>>(std::istream& in,  MyString& s);
};

#endif
