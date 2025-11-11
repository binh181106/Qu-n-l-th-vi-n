#include "../include/menu.h"
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

// Danh sách toàn cục
vector<SinhVien> dsSinhVien;
vector<Sach> dsSach;
vector<MuonTra> dsMuonTra;

void menuSinhVien() {
    while (true) {
        cout << "\n===== QUAN LY SINH VIEN =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Sua thong tin\n";
        cout << "4. Xoa sinh vien\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";

        int ch;
        if (!(cin >> ch)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai. Thu lai.\n";
            continue;
        }
        cin.ignore();

        switch (ch) {
            case 1: themSinhVien(dsSinhVien); break;
            case 2: hienThiDanhSachSV(dsSinhVien); break;
            case 3: suaSinhVien(dsSinhVien); break;
            case 4: xoaSinhVien(dsSinhVien); break;
            case 0: return;
            default: cout << "Lua chon khong hop le.\n"; break;
        }
    }
}

void menuSach() {
    while (true) {

        cout << "\n===== QUAN LY SACH =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Sua thong tin\n";
        cout << "4. Xoa sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai. Thu lai.\n";
            continue;
        }
        cin.ignore();

        switch (ch) {
            case 1: themSach(dsSach); break;
            case 2: hienThiDanhSachSach(dsSach); break;
            case 3: suaSach(dsSach); break;
            case 4: xoaSach(dsSach); break;
            case 0: return;
            default: cout << "Lua chon khong hop le.\n"; break;
        }
    }
}

void menuMuonTra() {
    while (true) {

        cout << "\n===== QUAN LY MUON TRA =====\n";
        cout << "1. Muon sach\n";
        cout << "2. Tra sach\n";
        cout << "3. Hien thi danh sach muon\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai. Thu lai.\n";
            continue;
        }
        cin.ignore();

        switch (ch) {
            case 1: muonSach(dsMuonTra); break;
            case 2: traSach(dsMuonTra); break;
            case 3: hienThiDanhSachMuon(dsMuonTra); break;
            case 0: return;
            default: cout << "Lua chon khong hop le.\n"; break;
        }
    }
}

void menu() {
    // đọc dữ liệu ban đầu từ file txt
    docFileSinhVien(dsSinhVien);
    docFileSach(dsSach);
    docFileMuonTra(dsMuonTra);

    while (true) {
        cout << "\n===== CHUONG TRINH QUAN LY THU VIEN =====\n";
        cout << "1. Quan ly sinh vien\n";
        cout << "2. Quan ly sach\n";
        cout << "3. Quan ly muon/tra sach\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai. Thu lai.\n";
            continue;
        }
        cin.ignore();

        switch (ch) {
            case 1: menuSinhVien(); break;
            case 2: menuSach(); break;
            case 3: menuMuonTra(); break;
            case 0:
                cout << "Ket thuc chuong trinh.\n";
                return;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    }
}
