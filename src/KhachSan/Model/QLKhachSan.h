//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_QLKHACHSAN_H
#define CPP_QLKS_QLKHACHSAN_H
#include <iostream>
#include "../KhachSan.h"
#include "../../QLBase/QLBase.h"

class QLKhachSan : protected QLBase{
private:
        KhachSan khachSan;
public:
    void capNhatThongTin(KhachSan* x);
    void suaKhachSan();
    KhachSan getKhachSan();
};


#endif //CPP_QLKS_QLKHACHSAN_H
