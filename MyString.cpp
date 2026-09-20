#include "MyString.h"

using namespace std;

// ---------- Ham tien ich tu viet (thay cho <cstring>) ----------
int MyString::tinhDoDai(const char* s)
{
    if (s == 0) return 0;
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void MyString::chepChuoi(char* dich, const char* nguon)
{
    int i = 0;
    if (nguon != 0)
        while (nguon[i] != '\0') { dich[i] = nguon[i]; i++; }
    dich[i] = '\0';
}

int MyString::soSanh(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) i++;
    return (int)(unsigned char)a[i] - (int)(unsigned char)b[i];
}

// ---------- Khoi tao / huy ----------
MyString::MyString()
{
    doDai     = 0;
    duLieu    = new char[1];
    duLieu[0] = '\0';
}

MyString::MyString(const char* s)
{
    doDai  = tinhDoDai(s);
    duLieu = new char[doDai + 1];
    chepChuoi(duLieu, s);
}

MyString::MyString(const MyString& khac)      // ham tao sao chep
{
    doDai  = khac.doDai;
    duLieu = new char[doDai + 1];
    chepChuoi(duLieu, khac.duLieu);
}

MyString::~MyString()
{
    delete[] duLieu;
}

// ---------- Toan tu gan ----------
MyString& MyString::operator=(const MyString& khac)
{
    if (this == &khac) return *this;          // tranh tu gan chinh minh
    delete[] duLieu;
    doDai  = khac.doDai;
    duLieu = new char[doDai + 1];
    chepChuoi(duLieu, khac.duLieu);
    return *this;
}

MyString& MyString::operator=(const char* s)
{
    delete[] duLieu;
    doDai  = tinhDoDai(s);
    duLieu = new char[doDai + 1];
    chepChuoi(duLieu, s);
    return *this;
}

// ---------- Toan tu [] ----------
char& MyString::operator[](int i)
{
    static char rac = '\0';                   // tranh loi khi vuot chi so
    if (i < 0 || i >= doDai) { rac = '\0'; return rac; }
    return duLieu[i];
}

const char& MyString::operator[](int i) const
{
    static const char rong = '\0';
    if (i < 0 || i >= doDai) return rong;
    return duLieu[i];
}

// ---------- Toan tu + va += ----------
MyString MyString::operator+(const MyString& khac) const
{
    MyString kq;
    delete[] kq.duLieu;
    kq.doDai  = doDai + khac.doDai;
    kq.duLieu = new char[kq.doDai + 1];

    int i = 0;
    for (; i < doDai; i++)          kq.duLieu[i] = duLieu[i];
    for (int j = 0; j < khac.doDai; j++) kq.duLieu[i + j] = khac.duLieu[j];
    kq.duLieu[kq.doDai] = '\0';
    return kq;
}

MyString& MyString::operator+=(const MyString& khac)
{
    *this = *this + khac;
    return *this;
}

MyString& MyString::operator+=(char c)
{
    char tam[2] = { c, '\0' };
    *this = *this + MyString(tam);
    return *this;
}

// ---------- Toan tu so sanh ----------
bool MyString::operator==(const MyString& k) const { return soSanh(duLieu, k.duLieu) == 0; }
bool MyString::operator!=(const MyString& k) const { return soSanh(duLieu, k.duLieu) != 0; }
bool MyString::operator< (const MyString& k) const { return soSanh(duLieu, k.duLieu) <  0; }
bool MyString::operator> (const MyString& k) const { return soSanh(duLieu, k.duLieu) >  0; }

bool MyString::operator!() const { return doDai == 0; }

// ---------- Tien ich ----------
int MyString::layDoDai() const { return doDai; }

MyString MyString::inHoa() const
{
    MyString kq(*this);
    for (int i = 0; i < kq.doDai; i++)
        if (kq.duLieu[i] >= 'a' && kq.duLieu[i] <= 'z')
            kq.duLieu[i] = (char)(kq.duLieu[i] - 'a' + 'A');
    return kq;
}

// ---------- Nhap / xuat ----------
ostream& operator<<(ostream& out, const MyString& s)
{
    out << s.duLieu;
    return out;
}

// Doc ca dong (de nhap duoc ho ten co khoang trang)
istream& operator>>(istream& in, MyString& s)
{
    char c;
    while (in.get(c))                         // bo qua cac ky tu trang dung truoc
        if (c != '\n' && c != '\r' && c != ' ' && c != '\t') { in.putback(c); break; }

    s = "";
    while (in.get(c) && c != '\n')
        if (c != '\r') s += c;
    return in;
}
