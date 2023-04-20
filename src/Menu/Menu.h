//
// Created by Andy Nguyen on 15/04/2023.
//

#ifndef CPP_QLKS_MENU_H
#define CPP_QLKS_MENU_H
#include "../DatPhong/Model/QLDatPhong.h"
#include "../HoaDon/Model/QLHoaDon.h"
#include "../KhachHang/Model/QLKhachHang.h"
#include "../Phong/Model/QLPhong.h"
#include "../KhachSan//Model/QLKhachSan.h"

class Menu {
public:

    Menu();
    ~Menu();
    void menuPhong();
    void menuHoaDon();
    void menuTtKhachSan();
    void menuKhachHang();
    void menuDatPhong();
    void menuQLKhachSan();
};


#endif //CPP_QLKS_MENU_H
