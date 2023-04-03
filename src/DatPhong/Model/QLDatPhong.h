//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_QLDATPHONG_H
#define CPP_QLKS_QLDATPHONG_H
#include <iostream>
#include "../DatPhong.h"
#include "../../QLBase/QLBase.h"

class QLDatPhong: protected QLBase{
    void taoDatPhong();
    void xoaDatPhong();
    void suaDatPhong();
    void dsDatPhong();
    DatPhong* loadDatPhong(int ma_dat_phong);
    bool existDatPhong(int ma_dat_phong);
};


#endif //CPP_QLKS_QLDATPHONG_H
