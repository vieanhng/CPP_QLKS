//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_DATPHONG_H
#define CPP_QLKS_DATPHONG_H
#include <iostream>
#include "../DoiTuong/DoiTuong.h"
#include "../KhachHang/KhachHang.h"
#include "../Phong/Phong.h"
#include "../Utils/Utils.h"

class DatPhong: public DoiTuong{
private:
    int ma_dat_phong;
    std::string thoi_gian_dat;
    std::string thoi_gian_tra;
    std::string tinh_trang_dat_phong;
    KhachHang *kh;
    Phong *p;
public:
    DatPhong();

    DatPhong(int maDatPhong, const std::string &thoiGianDat, const std::string &thoiGianTra,
             const std::string &tinhTrangDatPhong, KhachHang *kh, Phong *p);


    virtual ~DatPhong();



    int getMaDatPhong() const;

    void setMaDatPhong(int maDatPhong);

    const std::string &getThoiGianDat() const;

    void setThoiGianDat(const std::string &thoiGianDat);

    const std::string &getThoiGianTra() const;

    void setThoiGianTra(const std::string &thoiGianTra);

    const std::string &getTinhTrangDatPhong() const;

    void setTinhTrangDatPhong(const std::string &tinhTrangDatPhong);

    void nhap();

    void hienThi();

    KhachHang *getKh() const;

    void setKh(KhachHang *kh);

    Phong *getP() const;

    void setP(Phong *p);
};


#endif //CPP_QLKS_DATPHONG_H
