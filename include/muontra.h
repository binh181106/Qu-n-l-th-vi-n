#ifndef MUONTRA_H
#define MUONTRA_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class MuonTra {
private:
    string MSV;      // mã sinh viên
    string MaSach;   // mã sách

public:
    MuonTra() {}
    MuonTra(string msv, string ma) : MSV(msv), MaSach(ma) {}

    void setMuon(string msv, string ma) { MSV = msv; MaSach = ma; }
    void setTra(string msv, string ma) { MSV = msv; MaSach = ma; }

    string getMSV() const { return MSV; }
    string getMaSach() const { return MaSach; }

    string toFileString() const {
        return MSV + "|" + MaSach;
    }

    static MuonTra fromFileString(const string &line) {
        stringstream ss(line);
        string msv, ma;
        getline(ss, msv, '|');
        getline(ss, ma, '|');
        return MuonTra(msv, ma);
    }
};

#endif
