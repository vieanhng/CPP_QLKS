//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_QLKHACHHANG_H
#define CPP_QLKS_QLKHACHHANG_H
#include <iostream>
#include "../KhachHang.h"
#include "../../QLBase/QLBase.h"

class QLKhachHang : protected QLBase {
public:
    void taoKhachHang();
    void xoaKhachHang();
    void suaKhachHang();
    void dsKhachHang();
    KhachHang* loadKhachHang(int maKh);
    void capNhatKhachHang(KhachHang* kh);
    bool existKhachHang(int ma_kh);

};


#endif //CPP_QLKS_QLKHACHHANG_H
