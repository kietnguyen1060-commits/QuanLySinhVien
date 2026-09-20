#include "MyString.h"

using namespace std;

MyString::MyString(const char* s)
{
    int i = 0;
    while (s[i] != '\0' && i < MAX_KY_TU - 1)
    {
        duLieu[i] = s[i];
        i++;
    }
    duLieu[i] = '\0';           // danh dau ket thuc chuoi
}

// ---------- Toan tu + : noi hai chuoi ----------
MyString MyString::operator+(const MyString& khac) const
{
    MyString kq = *this;        // chep chuoi thu nhat sang ket qua

    int i = 0;
    while (kq.duLieu[i] != '\0') i++;               // tim vi tri cuoi chuoi

    int j = 0;
    while (khac.duLieu[j] != '\0' && i < MAX_KY_TU - 1)
    {
        kq.duLieu[i] = khac.duLieu[j];              // noi chuoi thu hai vao sau
        i++;
        j++;
    }
    kq.duLieu[i] = '\0';
    return kq;
}


MyString& MyString::operator+=(char c)
{
    int i = 0;
    while (duLieu[i] != '\0') i++;

    if (i < MAX_KY_TU - 1)
    {
        duLieu[i]     = c;
        duLieu[i + 1] = '\0';
    }
    return *this;
}

bool MyString::operator==(const MyString& khac) const
{
    int i = 0;
    while (duLieu[i] != '\0' && duLieu[i] == khac.duLieu[i]) i++;
    return duLieu[i] == khac.duLieu[i];             // cung dung o mot cho => giong nhau
}

bool MyString::operator>(const MyString& khac) const
{
    int i = 0;
    while (duLieu[i] != '\0' && duLieu[i] == khac.duLieu[i]) i++;
    return duLieu[i] > khac.duLieu[i];              // so ky tu dau tien khac nhau
}


MyString MyString::inHoa() const
{
    MyString kq = *this;
    for (int i = 0; kq.duLieu[i] != '\0'; i++)
        if (kq.duLieu[i] >= 'a' && kq.duLieu[i] <= 'z')
            kq.duLieu[i] = kq.duLieu[i] - 'a' + 'A';
    return kq;
}

ostream& operator<<(ostream& out, const MyString& s)
{
    out << s.duLieu;
    return out;
}

istream& operator>>(istream& in, MyString& s)
{
    char c;
    while (in.get(c))                               // bo qua ky tu trang dung truoc
        if (c != '\n' && c != '\r' && c != ' ' && c != '\t') { in.putback(c); break; }

    s = "";                                         // xoa noi dung cu
    while (in.get(c) && c != '\n')
        if (c != '\r') s += c;                      // dung toan tu += o tren
    return in;
}
