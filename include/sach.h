#ifndef SACH_H
#define SACH_H

#include <string>
#include <sstream>
using namespace std;

class Sach
{
protected:
    char MaSach[10];
    char TenSach[100];
    char TheLoai[100];
    char TacGia[100];
    int NamXuatBan;

public:
    Sach() {}
    // Constructor tương thích với string
    Sach(const string& ma, const string& ten, const string& loai, const string& tg, int namXB);

    // Setters
    void setSach(const char[], const char[], const char[], const char[], int);
    void setMaSach(const char[]);
    void setTenSach(const char[]);
    void setTheLoai(const char[]);
    void setTacGia(const char[]);
    void setNamXuatBan(int);

    // Getters
    string getMaSach() const;
    string getTenSach() const;
    string getTheLoai() const;
    string getTacGia() const;
    int getNamXB() const;

    // Hàm hỗ trợ đọc/ghi file
    string toFileString() const;
    static Sach fromFileString(const string& line);
};

#endif
