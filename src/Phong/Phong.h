//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_PHONG_H
#define CPP_QLKS_PHONG_H
#include <iostream>
#include "sstream"
#include "../Database/Database.h"
#include "../Utils/Utils.h"


class Phong: protected Database{
private:
    int ma_phong;
    std::string loai_phong;
    int so_phong;
    int gia_phong;
    int tinh_trang_phong;
    std::stringstream ss;
public:

    bool taoPhong();

    void suaPhong();

    void hienThiThongTin();

    void xoaPhong();

    int getMaPhong() const;

    void setMaPhong(int maPhong);

    const string &getLoaiPhong() const;

    void setLoaiPhong(const string &loaiPhong);

    int getSoPhong() const;

    void setSoPhong(int soPhong);

    int getGiaPhong() const;

    void setGiaPhong(int giaPhong);

    std::string getTinhTrangPhong() const;

    std::string getTinhTrangPhong(int tinh_trang) const;

    void setTinhTrangPhong(int tinhTrangPhong);

    void loadPhong(int maPhong);

    void showFullTable();
};


#endif //CPP_QLKS_PHONG_H
