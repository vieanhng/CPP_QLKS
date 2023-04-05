#include <iostream>
#include "Database/Database.h"
#include "Phong/Phong.h"
#include "Phong/Model/QLPhong.h"
#include "KhachHang/Model/QLKhachHang.h"
#include "DatPhong/Model/QLDatPhong.h"
#include "Utils/Utils.h"

int main(int argc, char** argv) {
   // QLKhachHang kh;
//    QLPhong p;
//    p.danhSachPhong("tinh_trang_phong = 1");
 // kh.taoKhachHang();
//   kh.suaKhachHang();
//   kh.xoaKhachHang();
QLDatPhong dp;
dp.taoDatPhong();
//std::string date = getDate("Nhap ngay:");


    return 0;
}
