// =====================================================================
//  QUAN LY SINH VIEN (C++ OOP) - them / xoa / sap xep
//  Khong dung <string>: tu cai lop MyString va nap chong toan tu
//  Bien dich: g++ -o QuanLySinhVien main.cpp MyString.cpp SinhVien.cpp
// =====================================================================
#include "SinhVien.h"
#include <iomanip>

using namespace std;

const int MAX = 100;

SinhVien danhSach[MAX];     // mang cac doi tuong SinhVien
int      soLuong = 0;

// ---------------------- Hien thi ----------------------
void hienThi()
{
    if (soLuong == 0)
    {
        cout << "\n   Danh sach rong!\n";
        return;
    }

    cout << "\n" << left
         << setw(5)  << "STT"
         << setw(10) << "MA SV"
         << setw(24) << "HO VA TEN"
         << setw(10) << "LOP"
         << setw(9)  << "  DIEM"
         << "XEP LOAI\n";
    cout << "----------------------------------------------------------------------\n";

    for (int i = 0; i < soLuong; i++)
        cout << left << setw(5) << (i + 1) << danhSach[i] << "\n";   // toan tu <<

    cout << "----------------------------------------------------------------------\n";
    cout << " Tong so: " << soLuong << " sinh vien\n";
}

// ---------------------- Them ----------------------
void them()
{
    if (soLuong >= MAX)
    {
        cout << "\n   [!] Danh sach da day!\n";
        return;
    }

    cout << "\n--- THEM SINH VIEN ---\n";
    SinhVien sv;
    cin >> sv;                                  // toan tu >> da nap chong

    // Kiem tra trung ma bang toan tu ==
    for (int i = 0; i < soLuong; i++)
        if (danhSach[i] == sv)
        {
            cout << "   [!] Ma " << sv.layMa() << " da ton tai!\n";
            return;
        }

    danhSach[soLuong] = sv;                     // toan tu = cua SinhVien / MyString
    soLuong++;
    cout << "   => Da them sinh vien " << sv.layHoTen() << "\n";
}

// ---------------------- Xoa ----------------------
void xoa()
{
    if (soLuong == 0) { cout << "\n   Danh sach rong!\n"; return; }

    cout << "\n--- XOA SINH VIEN ---\n";
    cout << " Nhap ma sinh vien can xoa: ";
    MyString ma;
    cin >> ma;

    SinhVien can(ma, "", "", 0);                // doi tuong tam de so sanh
    int viTri = -1;
    for (int i = 0; i < soLuong; i++)
        if (danhSach[i] == can) { viTri = i; break; }   // toan tu ==

    if (viTri < 0)
    {
        cout << "   [!] Khong tim thay sinh vien co ma " << ma << "\n";
        return;
    }

    cout << "   Da xoa: " << danhSach[viTri] << "\n";
    for (int i = viTri; i < soLuong - 1; i++)
        danhSach[i] = danhSach[i + 1];          // don mang len
    soLuong--;
}

// ---------------------- Sap xep ----------------------
void sapXep()
{
    if (soLuong == 0) { cout << "\n   Danh sach rong!\n"; return; }

    cout << "\n--- SAP XEP ---\n";
    cout << " 1. Theo diem giam dan\n";
    cout << " 2. Theo diem tang dan\n";
    cout << " 3. Theo ho ten (A -> Z)\n";
    cout << " Chon: ";

    int chon;
    if (!(cin >> chon)) return;

    // Sap xep noi bot, so sanh bang cac toan tu > , < cua lop SinhVien
    for (int i = 0; i < soLuong - 1; i++)
        for (int j = 0; j < soLuong - 1 - i; j++)
        {
            bool doiCho = false;
            if      (chon == 1) doiCho = danhSach[j] < danhSach[j + 1];     // toan tu <
            else if (chon == 2) doiCho = danhSach[j] > danhSach[j + 1];     // toan tu >
            else                doiCho = danhSach[j].layHoTen().inHoa()
                                       > danhSach[j + 1].layHoTen().inHoa();

            if (doiCho)
            {
                SinhVien tam      = danhSach[j];
                danhSach[j]       = danhSach[j + 1];
                danhSach[j + 1]   = tam;
            }
        }

    cout << "   => Da sap xep xong.\n";
    hienThi();
}

// ---------------------- Tim kiem ----------------------
void tim()
{
    cout << "\n--- TIM SINH VIEN ---\n";
    cout << " Nhap ma sinh vien: ";
    MyString ma;
    cin >> ma;

    for (int i = 0; i < soLuong; i++)
        if (danhSach[i].layMa().inHoa() == ma.inHoa())
        {
            cout << "\n   Tim thay:\n";
            cout << "   Ma sinh vien : " << danhSach[i][0] << "\n";   // toan tu []
            cout << "   Ho va ten    : " << danhSach[i][1] << "\n";
            cout << "   Lop          : " << danhSach[i][2] << "\n";
            cout << "   Diem         : " << fixed << setprecision(2)
                                         << danhSach[i].layDiem() << "\n";
            cout << "   Xep loai     : " << danhSach[i][3] << "\n";
            return;
        }

    cout << "   [!] Khong tim thay sinh vien co ma " << ma << "\n";
}

// ---------------------- Cong diem thuong ----------------------
void congDiemThuong()
{
    cout << "\n--- CONG DIEM THUONG ---\n";
    cout << " Nhap ma sinh vien: ";
    MyString ma;
    cin >> ma;

    for (int i = 0; i < soLuong; i++)
        if (danhSach[i].layMa().inHoa() == ma.inHoa())
        {
            cout << " Diem thuong: ";
            double thuong;
            if (!(cin >> thuong)) return;

            danhSach[i] += thuong;              // toan tu += cua SinhVien
            cout << "   => " << danhSach[i] << "\n";
            return;
        }

    cout << "   [!] Khong tim thay sinh vien co ma " << ma << "\n";
}

// ---------------------- Chuong trinh chinh ----------------------
int main()
{
    int chon;
    do
    {
        cout << "\n========== QUAN LY SINH VIEN ==========\n";
        cout << " 1. Them sinh vien\n";
        cout << " 2. Xoa sinh vien\n";
        cout << " 3. Sap xep danh sach\n";
        cout << " 4. Hien thi danh sach\n";
        cout << " 5. Tim sinh vien theo ma\n";
        cout << " 6. Cong diem thuong\n";
        cout << " 0. Thoat\n";
        cout << "=======================================\n";
        cout << " Chon chuc nang: ";

        if (!(cin >> chon))                     // gap loi hoac het du lieu nhap
        {
            cout << "\n   Ket thuc chuong trinh.\n";
            return 0;
        }

        switch (chon)
        {
        case 1: them();             break;
        case 2: xoa();              break;
        case 3: sapXep();           break;
        case 4: hienThi();          break;
        case 5: tim();              break;
        case 6: congDiemThuong();   break;
        case 0: cout << "\n   Tam biet!\n"; break;
        default: cout << "\n   [!] Lua chon khong hop le!\n";
        }
    } while (chon != 0);

    return 0;
}
