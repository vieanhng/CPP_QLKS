//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_QLDATPHONG_H
#define CPP_QLKS_QLDATPHONG_H
#include <iostream>
#include "../DatPhong.h"
#include "../../KhachHang/Model/QLKhachHang.h"
#include "../../Phong/Model/QLPhong.h"
#include "../../QLBase/QLBase.h"

class QLDatPhong: protected QLBase{
private:
    QLKhachHang qlKH;
    QLPhong qlP;
public:
    void taoDatPhong();
    void xoaDatPhong();
    void suaDatPhong();
    void dsDatPhong(std::string where = "");
    DatPhong* loadDatPhong(int ma_dat_phong);
    bool existDatPhong(int ma_dat_phong);
    void capNhatDatPhong(DatPhong *dp);

    QLPhong &getQlP();
};


#endif //CPP_QLKS_QLDATPHONG_H
