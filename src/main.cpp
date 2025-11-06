#include "../include/menu.h"
#include <iostream>
using namespace std;

int main() {
    // Tự tạo thư mục data nếu chưa tồn tại
    system("mkdir -p data");

    cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
    menu();

    return 0;
}
