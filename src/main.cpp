#include <iostream>
#include "Database/Database.h"
#include "Phong/Phong.h"
#include "Phong/Model/QLPhong.h"
#include "KhachHang/Model/QLKhachHang.h"

int main(int argc, char** argv) {
    QLKhachHang kh;
    kh.dsKhachHang();
    return 0;
}
