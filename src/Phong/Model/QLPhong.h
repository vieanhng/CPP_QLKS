//
// Created by Andy Nguyen on 31/03/2023.
//

#ifndef CPP_QLKS_QLPHONG_H
#define CPP_QLKS_QLPHONG_H

#include <ostream>
#include "../Phong.h"
#include "../../QLBase/QLBase.h"

class QLPhong : public QLBase {
public:
    bool taoPhong();
    void xoaPhong(int roomNumber);
    Phong* loadPhong(int roomNumber);
    std::vector<Phong*> getAllRooms();
    void danhSachPhong();
    string tinhTrangPhong(int tinhTrangPhong);
};


#endif //CPP_QLKS_QLPHONG_H
