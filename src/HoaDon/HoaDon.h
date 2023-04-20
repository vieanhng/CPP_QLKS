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
    std::string tinh_trang_thanh_toan;
    DatPhong * datPhong;
public:
    HoaDon(int soHD, std::string ngaylap,int soTien,std::string tinhtrangThanhToan,int madatPhong);
    HoaDon(){}

    HoaDon(int soHd, const std::string &ngayLap, int soTien, std::string tinhTrangThanhToan, DatPhong *datPhong);;

    ~HoaDon(){}

    void nhap();

    void hienThi();

    int getSoHd() const;

    void setSoHd(int soHd);

    const std::string &getNgayLap() const;

    void setNgayLap(const std::string &ngayLap);

    int getSoTien() const;

    void setSoTien(int soTien);

    const std::string &getTinhTrangThanhToan() const;

    void setTinhTrangThanhToan(const std::string &tinhTrangThanhToan);

    DatPhong *getDatPhong() const;

    void setDatPhong(DatPhong *datPhong);
};


#endif //CPP_QLKS_HOADON_H





