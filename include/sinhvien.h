#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class SinhVien {
private:
    string MSV;
    string HoTen;
    string NganhHoc;

public:
    SinhVien() {}
    SinhVien(string msv, string hoten, string nganhhoc)
        : MSV(msv), HoTen(hoten), NganhHoc(nganhhoc) {}

    // setter
    void setSinhVien(string msv, string hoten, string nganhhoc) {
        MSV = msv; HoTen = hoten; NganhHoc = nganhhoc;
    }
    void setMSV(string msv) { MSV = msv; }
    void setHoTen(string hoten) { HoTen = hoten; }
    void setNganhHoc(string nganhhoc) { NganhHoc = nganhhoc; }

    // getter
    string getMSV() const { return MSV; }
    string getHoTen() const { return HoTen; }
    string getNganhHoc() const { return NganhHoc; }

    // file I/O dạng text
    string toFileString() const {
        return MSV + "|" + HoTen + "|" + NganhHoc;
    }

    static SinhVien fromFileString(const string &line) {
        stringstream ss(line);
        string msv, hoten, nganh;
        getline(ss, msv, '|');
        getline(ss, hoten, '|');
        getline(ss, nganh, '|');
        return SinhVien(msv, hoten, nganh);
    }
};

#endif
