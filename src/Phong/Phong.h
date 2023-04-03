//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_PHONG_H
#define CPP_QLKS_PHONG_H
#include <iostream>
#include "../Utils/Utils.h"

using namespace std;

class Phong {
private:
    int ma_phong;
    string loai_phong;
    int so_phong;
    int gia_phong;
    int tinh_trang_phong;
public:
    Phong(string loaiPhong,int soPhong,int giaPhong,int tinhtrangPhong);
    Phong(){};

    void nhap();
    
    void hienThiThongTin();

    int getMaPhong() const;

    void setMaPhong(int maPhong);

    const string &getLoaiPhong() const;

    void setLoaiPhong(const string &loaiPhong);

    int getSoPhong() const;

    void setSoPhong(int soPhong);

    int getGiaPhong() const;

    void setGiaPhong(int giaPhong);

    int getTinhTrangPhong() const;

    void setTinhTrangPhong(int tinhTrangPhong);
};


#endif //CPP_QLKS_PHONG_H
