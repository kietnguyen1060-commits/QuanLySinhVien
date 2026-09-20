// =====================================================================
//  QUAN LY SINH VIEN (C++ OOP) - them / xoa / sap xep
//  Bien dich: g++ -o QuanLySinhVien main.cpp MyString.cpp SinhVien.cpp
// =====================================================================
#include "SinhVien.h"
#include <iomanip>

using namespace std;

const int MAX = 100;

SinhVien danhSach[MAX];
int      soLuong = 0;

// Tra ve vi tri cua sinh vien co ma nay, -1 neu khong co
int timViTri(const MyString& ma)
{
    SinhVien can(ma, "", "", 0);                // doi tuong tam de so sanh
    for (int i = 0; i < soLuong; i++)
        if (danhSach[i] == can) return i;       // toan tu ==
    return -1;
}

// Hoi ma sinh vien roi tra ve vi tri, -1 kem thong bao neu khong tim thay
int hoiViTri()
{
    cout << " Nhap ma sinh vien: ";
    MyString ma;
    cin >> ma;

    int vt = timViTri(ma);
    if (vt < 0) cout << "   [!] Khong tim thay ma " << ma << "\n";
    return vt;
}

// ---------------------- Hien thi ----------------------
void hienThi()
{
    if (soLuong == 0) { cout << "\n   Danh sach rong!\n"; return; }

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
    if (soLuong >= MAX) { cout << "\n   [!] Danh sach da day!\n"; return; }

    cout << "\n--- THEM SINH VIEN ---\n";
    SinhVien sv;
    cin >> sv;                                  // toan tu >>

    if (timViTri(sv.layMa()) >= 0)
    {
        cout << "   [!] Ma " << sv.layMa() << " da ton tai!\n";
        return;
    }

    danhSach[soLuong] = sv;
    soLuong++;
    cout << "   => Da them " << sv.layHoTen() << "\n";
}

// ---------------------- Xoa ----------------------
void xoa()
{
    cout << "\n--- XOA SINH VIEN ---\n";
    int vt = hoiViTri();
    if (vt < 0) return;

    cout << "   Da xoa: " << danhSach[vt] << "\n";

    for (int i = vt; i < soLuong - 1; i++)
        danhSach[i] = danhSach[i + 1];          // don mang len
    soLuong--;
}

// ---------------------- Sap xep ----------------------
void sapXep()
{
    cout << "\n--- SAP XEP ---\n";
    cout << " 1. Theo diem giam dan\n";
    cout << " 2. Theo diem tang dan\n";
    cout << " 3. Theo ho ten (A -> Z)\n";
    cout << " Chon: ";

    int chon;
    if (!(cin >> chon)) return;

    // Sap xep noi bot, so sanh bang cac toan tu cua lop
    for (int i = 0; i < soLuong - 1; i++)
        for (int j = 0; j < soLuong - 1 - i; j++)
        {
            bool doiCho;
            if      (chon == 1) doiCho = danhSach[j] < danhSach[j + 1];   // toan tu <
            else if (chon == 2) doiCho = danhSach[j] > danhSach[j + 1];   // toan tu >
            else                doiCho = danhSach[j].layHoTen().inHoa()
                                       > danhSach[j + 1].layHoTen().inHoa();

            if (doiCho)
            {
                SinhVien tam    = danhSach[j];
                danhSach[j]     = danhSach[j + 1];
                danhSach[j + 1] = tam;
            }
        }

    cout << "   => Da sap xep xong.\n";
    hienThi();
}

// ---------------------- Tim kiem ----------------------
void tim()
{
    cout << "\n--- TIM SINH VIEN ---\n";
    int vt = hoiViTri();
    if (vt < 0) return;

    cout << "   Ma sinh vien : " << danhSach[vt][0] << "\n";     // toan tu []
    cout << "   Ho va ten    : " << danhSach[vt][1] << "\n";
    cout << "   Lop          : " << danhSach[vt][2] << "\n";
    cout << "   Diem         : " << fixed << setprecision(2)
                                 << danhSach[vt].layDiem() << "\n";
    cout << "   Xep loai     : " << danhSach[vt][3] << "\n";
}

// ---------------------- Cong diem thuong ----------------------
void congDiemThuong()
{
    cout << "\n--- CONG DIEM THUONG ---\n";
    int vt = hoiViTri();
    if (vt < 0) return;

    cout << " Diem thuong: ";
    double thuong;
    if (!(cin >> thuong)) return;

    danhSach[vt] += thuong;                     // toan tu +=
    cout << "   => " << danhSach[vt] << "\n";
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
        cout << " Chon chuc nang: ";

        if (!(cin >> chon)) return 0;           // gap loi hoac het du lieu nhap

        switch (chon)
        {
        case 1: them();           break;
        case 2: xoa();            break;
        case 3: sapXep();         break;
        case 4: hienThi();        break;
        case 5: tim();            break;
        case 6: congDiemThuong(); break;
        case 0: cout << "\n   Tam biet!\n"; break;
        default: cout << "\n   [!] Lua chon khong hop le!\n";
        }
    } while (chon != 0);

    return 0;
}
