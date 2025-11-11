#include "../include/menu.h"
#include <iostream>
using namespace std;

int main() {
    system("if not exist data mkdir data");

    cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
    menu();

    return 0;
}
