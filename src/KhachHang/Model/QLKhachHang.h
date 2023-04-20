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
    void tao();
    void xoa();
    void sua();
    void danhSach();
    KhachHang* loadKhachHang(int maKh);
    KhachHang* loadKhachHang(std::string cccd);
    void xemKhachHang();
    void capNhatKhachHang(KhachHang* kh);
    bool existKhachHang(int ma_kh);
    bool existKhachHang(std::string cccd);
};


#endif //CPP_QLKS_QLKHACHHANG_H
