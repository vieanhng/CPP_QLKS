#include <iostream>
#include "Database/Database.h"
#include "Phong/Phong.h"
#include "Phong/Model/QLPhong.h"

using namespace std;
int main(int argc, char** argv) {
    QLPhong ql;
    Phong* p1 = ql.loadPhong(7);
    if (p1 != NULL) {
        p1->hienThiThongTin();
    } else {
        std::cout << "Khong tim thay phong\n";
    }
    delete p1;
    return 0;
}
