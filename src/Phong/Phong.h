//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_PHONG_H
#define CPP_QLKS_PHONG_H
#include <iostream>
#include "../Utils/Utils.h"


class Phong {
private:
    int ma_phong;
    std::string loai_phong;
    int so_phong;
    int gia_phong;
    int tinh_trang_phong;
public:
    Phong(int maPhong, std::string loaiPhong,int soPhong,int giaPhong,int tinhtrangPhong);
    Phong(){};

    void nhap();


    void hienThiThongTin();

    int getMaPhong() const;

    void setMaPhong(int maPhong);

    const std::string &getLoaiPhong() const;

    void setLoaiPhong(const std::string &loaiPhong);

    int getSoPhong() const;

    void setSoPhong(int soPhong);

    int getGiaPhong() const;

    void setGiaPhong(int giaPhong);

    int getTinhTrangPhong() const;

    void setTinhTrangPhong(int tinhTrangPhong);
};


#endif //CPP_QLKS_PHONG_H
