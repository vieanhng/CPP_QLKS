//
// Created by test1 on 11/4/2023.
//

#ifndef CPP_QLKS_HOADON_H
#define CPP_QLKS_HOADON_H

#include <iostream>
#include "../Utils/Utils.h"
#include "../DatPhong/DatPhong.h"

class HoaDon {
private:
    int so_HD;
    std::string ngay_lap;
    int so_tien;
    int tinh_trang_thanh_toan;
    DatPhong * datPhong;
public:
    HoaDon(int soHD, std::string ngaylap,int soTien,int tinhtrangThanhToan,int madatPhong);
    HoaDon(){}

    HoaDon(int soHd, const std::string &ngayLap, int soTien, int tinhTrangThanhToan, DatPhong *datPhong);;

    ~HoaDon(){}

    void nhap();

    void hienThiThongTin();

    int getSoHd() const;

    void setSoHd(int soHd);

    const std::string &getNgayLap() const;

    void setNgayLap(const std::string &ngayLap);

    int getSoTien() const;

    void setSoTien(int soTien);

    int getTinhTrangThanhToan() const;

    void setTinhTrangThanhToan(int tinhTrangThanhToan);

    DatPhong *getDatPhong() const;

    void setDatPhong(DatPhong *datPhong);
};


#endif //CPP_QLKS_HOADON_H





