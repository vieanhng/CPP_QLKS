//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_DATPHONG_H
#define CPP_QLKS_DATPHONG_H
#include <iostream>
#include "../Utils/Utils.h"

class DatPhong {
private:
    int ma_dat_phong;
    std::string thoi_gian_dat;
    std::string thoi_gian_nhan;
    std::string thoi_gian_tra;
    std::string tinh_trang_dat_phong;
    int ma_phong;
    int ma_kh;
public:
    DatPhong();

    virtual ~DatPhong();

    DatPhong(int maDatPhong, const std::string &thoiGianDat, const std::string &thoiGianNhan, const std::string &thoiGianTra,
             const std::string &tinhTrangDatPhong, int maPhong, int maKh);

    int getMaDatPhong() const;

    void setMaDatPhong(int maDatPhong);

    const std::string &getThoiGianDat() const;

    void setThoiGianDat(const std::string &thoiGianDat);

    const std::string &getThoiGianNhan() const;

    void setThoiGianNhan(const std::string &thoiGianNhan);

    const std::string &getThoiGianTra() const;

    void setThoiGianTra(const std::string &thoiGianTra);

    const std::string &getTinhTrangDatPhong() const;

    void setTinhTrangDatPhong(const std::string &tinhTrangDatPhong);

    int getMaPhong() const;

    void setMaPhong(int maPhong);

    int getMaKh() const;

    void setMaKh(int maKh);

    void nhap();

    void hienThiThongTin();
};


#endif //CPP_QLKS_DATPHONG_H
