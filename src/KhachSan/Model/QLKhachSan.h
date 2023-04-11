//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_QLKHACHSAN_H
#define CPP_QLKS_QLKHACHSAN_H
#include <iostream>
#include "../KhachSan.h"
#include "../../QLBase/QLBase.h"

class QLKhachSan : protected QLBase{
public:
    void capNhatThongTin(KhachSan* x);
    void suaKhachSan();
    KhachSan* loadKhachSan(int HotelNumber);
    std::vector<KhachSan*> getAllHotels();
    void danhSachKhachSan(std::string where = "");
    bool existKhachSan(int ma_phong);
};


#endif //CPP_QLKS_QLKHACHSAN_H
