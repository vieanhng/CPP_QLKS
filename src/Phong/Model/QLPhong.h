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
    void tao();
    void xoa();
    void sua();
    Phong* loadPhong(int roomNumber);
    void danhSach(std::string where = "");
    string tinhTrangPhong(int tinhTrangPhong);
    void capNhatPhong(Phong* p);
    bool existPhong(int ma_phong, std::string filter = "");
};


#endif //CPP_QLKS_QLPHONG_H
