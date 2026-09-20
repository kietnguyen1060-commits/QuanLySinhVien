#include "MyString.h"

using namespace std;

// ---------- Ba ham tien ich tu viet ----------
int MyString::doDai(const char* s)
{
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void MyString::chep(char* dich, const char* nguon)
{
    int i = 0;
    while (nguon[i] != '\0') { dich[i] = nguon[i]; i++; }
    dich[i] = '\0';
}

int MyString::soSanh(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) i++;
    return a[i] - b[i];            // <0, =0 hoac >0
}

// ---------- Khoi tao / huy ----------
MyString::MyString(const char* s)
{
    duLieu = new char[doDai(s) + 1];
    chep(duLieu, s);
}

MyString::MyString(const MyString& khac)
{
    duLieu = new char[doDai(khac.duLieu) + 1];
    chep(duLieu, khac.duLieu);
}

MyString::~MyString()
{
    delete[] duLieu;
}

// ---------- Toan tu gan ----------
MyString& MyString::operator=(const MyString& khac)
{
    if (this != &khac)                       // tranh tu gan chinh minh
    {
        delete[] duLieu;                     // tra lai vung nho cu
        duLieu = new char[doDai(khac.duLieu) + 1];
        chep(duLieu, khac.duLieu);
    }
    return *this;
}

// ---------- Toan tu noi chuoi ----------
MyString MyString::operator+(const MyString& khac) const
{
    int n = doDai(duLieu);

    char* tam = new char[n + doDai(khac.duLieu) + 1];
    chep(tam, duLieu);                       // chep chuoi thu nhat
    chep(tam + n, khac.duLieu);              // chep chuoi thu hai vao ngay sau

    MyString kq(tam);
    delete[] tam;
    return kq;
}

MyString& MyString::operator+=(char c)
{
    char tam[2] = { c, '\0' };
    *this = *this + tam;                     // tam tu dong thanh MyString
    return *this;
}

// ---------- Toan tu so sanh ----------
bool MyString::operator==(const MyString& khac) const { return soSanh(duLieu, khac.duLieu) == 0; }
bool MyString::operator> (const MyString& khac) const { return soSanh(duLieu, khac.duLieu) >  0; }

// ---------- Tien ich ----------
MyString MyString::inHoa() const
{
    MyString kq(*this);
    for (int i = 0; kq.duLieu[i] != '\0'; i++)
        if (kq.duLieu[i] >= 'a' && kq.duLieu[i] <= 'z')
            kq.duLieu[i] = kq.duLieu[i] - 'a' + 'A';
    return kq;
}

// ---------- Nhap / xuat ----------
ostream& operator<<(ostream& out, const MyString& s)
{
    out << s.duLieu;
    return out;
}

istream& operator>>(istream& in, MyString& s)
{
    char c;
    while (in.get(c))                        // bo qua ky tu trang dung truoc
        if (c != '\n' && c != '\r' && c != ' ' && c != '\t') { in.putback(c); break; }

    s = "";                                  // xoa noi dung cu
    while (in.get(c) && c != '\n')           // doc ca dong, ke ca dau cach
        if (c != '\r') s += c;
    return in;
}
