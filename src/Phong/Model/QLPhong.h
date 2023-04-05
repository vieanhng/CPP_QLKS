//
// Created by Andy Nguyen on 31/03/2023.
//

#ifndef CPP_QLKS_QLPHONG_H
#define CPP_QLKS_QLPHONG_H

#include <iostream>
#include "../Phong.h"
#include "../../QLBase/QLBase.h"

class QLPhong : protected QLBase {
public:
    bool taoPhong();
    void xoaPhong();
    void suaPhong();
    Phong* loadPhong(int roomNumber);
    std::vector<Phong*> getAllRooms();
    void danhSachPhong(std::string where = "");
    string tinhTrangPhong(int tinhTrangPhong);
    void capNhatPhong(Phong* p);
    bool existPhong(int ma_phong);
};


#endif //CPP_QLKS_QLPHONG_H
