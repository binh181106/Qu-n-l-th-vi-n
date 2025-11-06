#include "../include/sinhvien.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void themSinhVien(vector<SinhVien>& dsSV) {
    string msv, hoten, nganh;
    cout << "Nhap ma sinh vien: ";
    getline(cin, msv);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap nganh hoc: ";
    getline(cin, nganh);

    dsSV.push_back(SinhVien(msv, hoten, nganh));

    ofstream file("data/sinhvien.txt");
    for (auto& sv : dsSV)
        file << sv.toFileString() << "\n";

    cout << "Da them sinh vien thanh cong!\n";
}

void docFileSinhVien(vector<SinhVien>& dsSV) {
    dsSV.clear();
    ifstream file("data/sinhvien.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            dsSV.push_back(SinhVien::fromFileString(line));
    }
}

void hienThiDanhSachSV(const vector<SinhVien>& dsSV) {
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (const auto& sv : dsSV)
        cout << sv.getMSV() << " | " << sv.getHoTen() << " | " << sv.getNganhHoc() << "\n";
    cout << "===============================\n";
}

void xoaSinhVien(vector<SinhVien>& dsSV) {
    string msv;
    cout << "Nhap ma sinh vien can xoa: ";
    getline(cin, msv);

    bool found = false;
    for (auto it = dsSV.begin(); it != dsSV.end(); ++it) {
        if (it->getMSV() == msv) {
            dsSV.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        ofstream file("data/sinhvien.txt");
        for (auto& sv : dsSV)
            file << sv.toFileString() << "\n";
        cout << "Da xoa sinh vien " << msv << " thanh cong!\n";
    } else {
        cout << "Khong tim thay sinh vien co ma " << msv << ".\n";
    }
}

void suaSinhVien(vector<SinhVien>& dsSV) {
    string msv;
    cout << "Nhap ma sinh vien can sua: ";
    getline(cin, msv);

    for (auto& sv : dsSV) {
        if (sv.getMSV() == msv) {
            string hoten, nganh;
            cout << "Nhap ho ten moi (bo trong neu giu nguyen): ";
            getline(cin, hoten);
            cout << "Nhap nganh hoc moi (bo trong neu giu nguyen): ";
            getline(cin, nganh);

            if (!hoten.empty()) sv.setHoTen(hoten);
            if (!nganh.empty()) sv.setNganhHoc(nganh);

            ofstream file("data/sinhvien.txt");
            for (auto& sv2 : dsSV)
                file << sv2.toFileString() << "\n";
            cout << "Da cap nhat thong tin sinh vien " << msv << ".\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}
