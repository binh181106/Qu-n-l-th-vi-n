#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class Sach {
private:
    string MaSach;
    string TenSach;
    string TheLoai;
    string TacGia;
    string NamXB;

public:
    Sach() {}
    Sach(string ma, string ten, string loai, string tg, string nam)
        : MaSach(ma), TenSach(ten), TheLoai(loai), TacGia(tg), NamXB(nam) {}

    void setSach(string ma, string ten, string loai, string tg, string nam) {
        MaSach = ma;
        TenSach = ten;
        TheLoai = loai;
        TacGia = tg;
        NamXB = nam;
    }

    string getMaSach() const { return MaSach; }
    string getTenSach() const { return TenSach; }
    string getTheLoai() const { return TheLoai; }
    string getTacGia() const { return TacGia; }
    string getNamXB() const { return NamXB; }

    string toFileString() const {
        return MaSach + "|" + TenSach + "|" + TheLoai + "|" + TacGia + "|" + NamXB;
    }

    static Sach fromFileString(const string &line) {
        stringstream ss(line);
        string ma, ten, loai, tg, nam;
        getline(ss, ma, '|');
        getline(ss, ten, '|');
        getline(ss, loai, '|');
        getline(ss, tg, '|');
        getline(ss, nam, '|');
        return Sach(ma, ten, loai, tg, nam);
    }
};

#endif
