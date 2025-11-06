#include "../include/muontra.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void docFileMuonTra(vector<MuonTra>& dsMuon) {
    dsMuon.clear();
    ifstream file("data/muontra.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            dsMuon.push_back(MuonTra::fromFileString(line));
    }
}

void ghiFileMuonTra(const vector<MuonTra>& dsMuon) {
    ofstream file("data/muontra.txt");
    for (const auto& mt : dsMuon)
        file << mt.toFileString() << "\n";
}

void muonSach(vector<MuonTra>& dsMuon) {
    string msv, ma;
    cout << "Nhap ma sinh vien: ";
    getline(cin, msv);
    cout << "Nhap ma sach: ";
    getline(cin, ma);

    for (const auto& mt : dsMuon) {
        if (mt.getMSV() == msv && mt.getMaSach() == ma) {
            cout << "Sinh vien nay da muon sach nay roi.\n";
            return;
        }
    }

    dsMuon.push_back(MuonTra(msv, ma));
    ghiFileMuonTra(dsMuon);
    cout << "Da ghi nhan viec muon sach.\n";
}

void traSach(vector<MuonTra>& dsMuon) {
    string msv, ma;
    cout << "Nhap ma sinh vien: ";
    getline(cin, msv);
    cout << "Nhap ma sach: ";
    getline(cin, ma);

    bool found = false;
    for (auto it = dsMuon.begin(); it != dsMuon.end(); ++it) {
        if (it->getMSV() == msv && it->getMaSach() == ma) {
            dsMuon.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        ghiFileMuonTra(dsMuon);
        cout << "Da tra sach thanh cong.\n";
    } else {
        cout << "Khong tim thay thong tin muon sach nay.\n";
    }
}

void hienThiDanhSachMuon(const vector<MuonTra>& dsMuon) {
    cout << "\n===== DANH SACH MUON SACH =====\n";
    for (const auto& mt : dsMuon)
        cout << "MSV: " << mt.getMSV() << " | Ma sach: " << mt.getMaSach() << "\n";
    cout << "===============================\n";
}
