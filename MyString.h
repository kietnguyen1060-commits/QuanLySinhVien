#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

const int MAX_KY_TU = 100;      

class MyString
{
private:
    char duLieu[MAX_KY_TU];  

public:
    MyString(const char* s = "");                       // tao chuoi rong hoac tu chuoi co san

    MyString  operator+(const MyString& khac) const;    // noi hai chuoi
    MyString& operator+=(char c);                       // noi them mot ky tu

    bool operator==(const MyString& khac) const;        // hai chuoi giong nhau?
    bool operator> (const MyString& khac) const;        // dung sau theo thu tu tu dien?

    MyString inHoa() const;                         

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
    friend std::istream& operator>>(std::istream& in,  MyString& s);
};

#endif
