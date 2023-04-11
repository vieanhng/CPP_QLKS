//
// Created by test1 on 11/4/2023.
//

#ifndef CPP_QLKS_HOADON_H
#define CPP_QLKS_HOADON_H

#include <iostream>
#include "../Utils/Utils.h"

class HoaDon {
private:
    int so_HD;
    std::string ngay_lap;
    int so_tien;
    int tinh_trang_thanh_toan;
    int ma_dat_phong;
public:
    HoaDon(int soHD, std::string ngaylap,int soTien,int tinhtrangThanhToan,int madatPhong);
    HoaDon(){};

    void nhap();


    void hienThiThongTin();

    int getsoHD() const;

    void setsoHD(int soHD);

    const std::string &getngaylap() const;

    void setngaylap(const std::string &ngaylap);

    int getsoTien() const;

    void setsoTien(int soTien);

    int gettinhtrangThanhToan() const;

    void settinhtrangThanhToan(int tinhtrangThanhToan);

    int getmadatPhong() const;

    void setmadatPhong(int madatPhong);
};


#endif //CPP_QLKS_HOADON_H





