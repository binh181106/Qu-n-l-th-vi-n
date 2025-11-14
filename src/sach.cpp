#include "../include/sach.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;



#include <cstring>
#include <limits>


static inline string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

// Implementations for Sach methods
Sach::Sach(const string& ma, const string& ten, const string& loai, const string& tg, int namXB) {
    setSach(ma.c_str(), ten.c_str(), loai.c_str(), tg.c_str(), namXB);
}

void Sach::setSach(const char ma[], const char ten[], const char loai[], const char tg[], int namXB) {
    strncpy(MaSach, ma, sizeof(MaSach) - 1); MaSach[sizeof(MaSach)-1] = '\0';
    strncpy(TenSach, ten, sizeof(TenSach) - 1); TenSach[sizeof(TenSach)-1] = '\0';
    strncpy(TheLoai, loai, sizeof(TheLoai) - 1); TheLoai[sizeof(TheLoai)-1] = '\0';
    strncpy(TacGia, tg, sizeof(TacGia) - 1); TacGia[sizeof(TacGia)-1] = '\0';
    NamXuatBan = namXB;
}

void Sach::setMaSach(const char m[])    { strncpy(MaSach, m, sizeof(MaSach)-1); MaSach[sizeof(MaSach)-1]='\0'; }
void Sach::setTenSach(const char t[])   { strncpy(TenSach, t, sizeof(TenSach)-1); TenSach[sizeof(TenSach)-1]='\0'; }
void Sach::setTheLoai(const char l[])   { strncpy(TheLoai, l, sizeof(TheLoai)-1); TheLoai[sizeof(TheLoai)-1]='\0'; }
void Sach::setTacGia(const char tg[])   { strncpy(TacGia, tg, sizeof(TacGia)-1); TacGia[sizeof(TacGia)-1]='\0'; }
void Sach::setNamXuatBan(int n)         { NamXuatBan = n; }

string Sach::getMaSach() const   { return string(MaSach); }
string Sach::getTenSach() const  { return string(TenSach); }
string Sach::getTheLoai() const  { return string(TheLoai); }
string Sach::getTacGia() const   { return string(TacGia); }
int Sach::getNamXB() const       { return NamXuatBan; }

string Sach::toFileString() const {
    ostringstream oss;
    oss << MaSach << '|' << TenSach << '|' << TheLoai << '|' << TacGia << '|' << NamXuatBan;
    return oss.str();
}

Sach Sach::fromFileString(const string& line) {
    stringstream ss(line);
    string ma, ten, loai, tg, nam;
    getline(ss, ma,  '|');
    getline(ss, ten, '|');
    getline(ss, loai,'|');
    getline(ss, tg,  '|');
    getline(ss, nam, '|');

    ma = trim(ma);
    ten = trim(ten);
    loai = trim(loai);
    tg = trim(tg);
    nam = trim(nam);

    int namXB = 0;
    if (!nam.empty()) {
        stringstream sn(nam);
        sn >> namXB;
    }
    return Sach(ma, ten, loai, tg, namXB);
}


// Đọc danh sách sách từ file
void docFileSach(vector<Sach>& dsSach) {
    dsSach.clear();
    ifstream file("data/sach.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            dsSach.push_back(Sach::fromFileString(line));
    }
    file.close();
}

// Ghi danh sách sách vào file
void ghiFileSach(const vector<Sach>& dsSach) {
    ofstream file("data/sach.txt");
    for (const auto& s : dsSach)
        file << s.toFileString() << "\n";
    file.close();
}

// Thêm sách mới 
void themSach(vector<Sach>& dsSach) {
    string ma, ten, loai, tacGia;
    int namXB;

    cout << "Nhap ma sach: ";
    cin >> ma;

    // Kiểm tra trùng mã
    for (const auto& s : dsSach) {
        if (s.getMaSach() == ma) {
            cout << "Ma sach da ton tai! Khong the them trung.\n";
            return;
        }
    }

    cin.ignore();
    cout << "Nhap ten sach: ";
    getline(cin, ten);
    cout << "Nhap the loai: ";
    getline(cin, loai);
    cout << "Nhap tac gia: ";
    getline(cin, tacGia);
    cout << "Nhap nam xuat ban: ";
    cin >> namXB;

    dsSach.emplace_back(ma, ten, loai, tacGia, namXB);
    ghiFileSach(dsSach);

    cout << "Da them sach thanh cong!\n";
}

// Hiển thị danh sách sách
void hienThiDanhSachSach(const vector<Sach>& dsSach) {
    cout << left
         << setw(10) << "MaSach"
         << setw(30) << "TenSach"
         << setw(20) << "TheLoai"
         << setw(20) << "TacGia"
         << setw(6)  << "Nam" << "\n";
    cout << string(86, '-') << "\n";

    for (const auto& s : dsSach) {
        string ma = s.getMaSach();
        string ten = s.getTenSach();
        string loai = s.getTheLoai();
        string tg = s.getTacGia();

        if (ma.size() > 10) ma = ma.substr(0,10);
        if (ten.size() > 30) ten = ten.substr(0,30);
        if (loai.size() > 20) loai = loai.substr(0,20);
        if (tg.size() > 20) tg = tg.substr(0,20);

        cout << left
             << setw(10) << ma
             << setw(30) << ten
             << setw(20) << loai
             << setw(20) << tg
             << setw(6)  << s.getNamXB() << "\n";
    }
}
// Xóa sách theo mã
void xoaSach(vector<Sach>& dsSach) {
    string ma;
    cout << "Nhap ma sach can xoa: ";
    cin >> ma;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (auto it = dsSach.begin(); it != dsSach.end(); ++it) {
        if (it->getMaSach() == ma) {
            dsSach.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        ghiFileSach(dsSach);
        cout << "Da xoa sach thanh cong.\n";
    } else {
        cout << "Khong tim thay ma sach.\n";
    }
}

// Sửa thông tin sách theo mã
void suaSach(vector<Sach>& dsSach) {
    string ma;
    cout << "Nhap ma sach can sua: ";
    cin >> ma;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto& s : dsSach) {
        if (s.getMaSach() == ma) {
            string ten, loai, tg, namStr;
            int namXB = s.getNamXB();

            cout << "Nhap ten sach moi (bo trong neu giu nguyen): ";
            getline(cin, ten);
            cout << "Nhap the loai moi (bo trong neu giu nguyen): ";
            getline(cin, loai);
            cout << "Nhap tac gia moi (bo trong neu giu nguyen): ";
            getline(cin, tg);
            cout << "Nhap nam xuat ban moi (bo trong neu giu nguyen): ";
            getline(cin, namStr);

            if (!namStr.empty()) {
                stringstream ss(namStr);
                ss >> namXB;
            }

            // Cập nhật thông tin
            s = Sach(
                ma,
                ten.empty() ? s.getTenSach() : ten,
                loai.empty() ? s.getTheLoai() : loai,
                tg.empty() ? s.getTacGia() : tg,
                namXB
            );

            ghiFileSach(dsSach);
            cout << "Da cap nhat sach thanh cong.\n";
            return;
        }
    }
    cout << "Khong tim thay ma sach.\n";
}
