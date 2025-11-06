#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "sinhvien.h"
#include "sach.h"
#include "muontra.h"
using namespace std;

// Khai báo danh sách dùng chung
extern vector<SinhVien> dsSinhVien;
extern vector<Sach> dsSach;
extern vector<MuonTra> dsMuonTra;

// Hàm quản lý sinh viên
void themSinhVien(vector<SinhVien>& dsSV);
void docFileSinhVien(vector<SinhVien>& dsSV);
void hienThiDanhSachSV(const vector<SinhVien>& dsSV);
void xoaSinhVien(vector<SinhVien>& dsSV);
void suaSinhVien(vector<SinhVien>& dsSV);

// Hàm quản lý sách
void themSach(vector<Sach>& dsSach);
void docFileSach(vector<Sach>& dsSach);
void hienThiDanhSachSach(const vector<Sach>& dsSach);
void xoaSach(vector<Sach>& dsSach);
void suaSach(vector<Sach>& dsSach);

// Hàm quản lý mượn - trả
void muonSach(vector<MuonTra>& dsMuon);
void traSach(vector<MuonTra>& dsMuon);
void hienThiDanhSachMuon(const vector<MuonTra>& dsMuon);
void docFileMuonTra(vector<MuonTra>& dsMuon);

// Hàm menu chính
void menu();

#endif
