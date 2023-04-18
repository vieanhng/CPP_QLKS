//
// Created by Van Anh on 11/4/2023
//

#ifndef CPP_QLKS_QLHOADON_H
#define CPP_QLKS_QLHOADON_H
#include <iostream>
#include "../HoaDon.h"
#include "../../QLBase/QLBase.h"
#include "../../DatPhong/Model/QLDatPhong.h"

class QLHoaDon : protected QLBase {
private:
    QLDatPhong qlDp;
public:
    void taoHoaDon();
    void xoaHoaDon();
    void suaHoaDon();
    void dsHoaDon();
    HoaDon* loadHoaDon(int so_HD);
    void capNhatHoaDon(HoaDon* hd);
    bool existHoaDon(int so_HD);
    void xemHoaDon();
};


#endif //CPP_QLKS_QLHOADON_H
