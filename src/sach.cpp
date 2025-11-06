#include "../include/sach.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void docFileSach(vector<Sach>& dsSach) {
    dsSach.clear();
    ifstream file("data/sach.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            dsSach.push_back(Sach::fromFileString(line));
    }
}

void ghiFileSach(const vector<Sach>& dsSach) {
    ofstream file("data/sach.txt");
    for (const auto& s : dsSach)
        file << s.toFileString() << "\n";
}

void themSach(vector<Sach>& dsSach) {
    string ma, ten, loai, tg, nam;
    cout << "Nhap ma sach: ";
    getline(cin, ma);
    cout << "Nhap ten sach: ";
    getline(cin, ten);
    cout << "Nhap the loai: ";
    getline(cin, loai);
    cout << "Nhap tac gia: ";
    getline(cin, tg);
    cout << "Nhap nam xuat ban: ";
    getline(cin, nam);

    dsSach.push_back(Sach(ma, ten, loai, tg, nam));
    ghiFileSach(dsSach);
    cout << "Da them sach thanh cong.\n";
}

void hienThiDanhSachSach(const vector<Sach>& dsSach) {
    cout << "\n===== DANH SACH SACH =====\n";
    for (const auto& s : dsSach)
        cout << s.getMaSach() << " | " << s.getTenSach()
             << " | " << s.getTheLoai()
             << " | " << s.getTacGia()
             << " | " << s.getNamXB() << "\n";
    cout << "==========================\n";
}

void xoaSach(vector<Sach>& dsSach) {
    string ma;
    cout << "Nhap ma sach can xoa: ";
    getline(cin, ma);

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

void suaSach(vector<Sach>& dsSach) {
    string ma;
    cout << "Nhap ma sach can sua: ";
    getline(cin, ma);

    for (auto& s : dsSach) {
        if (s.getMaSach() == ma) {
            string ten, loai, tg, nam;
            cout << "Nhap ten sach moi (bo trong neu giu nguyen): ";
            getline(cin, ten);
            cout << "Nhap the loai moi (bo trong neu giu nguyen): ";
            getline(cin, loai);
            cout << "Nhap tac gia moi (bo trong neu giu nguyen): ";
            getline(cin, tg);
            cout << "Nhap nam xuat ban moi (bo trong neu giu nguyen): ";
            getline(cin, nam);

            if (!ten.empty()) s = Sach(ma, ten, loai.empty() ? s.getTheLoai() : loai,
                                       tg.empty() ? s.getTacGia() : tg,
                                       nam.empty() ? s.getNamXB() : nam);
            ghiFileSach(dsSach);
            cout << "Da cap nhat sach thanh cong.\n";
            return;
        }
    }
    cout << "Khong tim thay ma sach.\n";
}
