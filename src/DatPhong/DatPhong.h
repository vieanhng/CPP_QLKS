//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_DATPHONG_H
#define CPP_QLKS_DATPHONG_H
#include <iostream>
#include "../Utils/Utils.h"

using namespace std;
class DatPhong {
private:
    int ma_dat_phong;
    string thoi_gian_dat;
    string thoi_gian_nhan;
    string thoi_gian_tra;
    string tinh_trang_dat_phong;
    int ma_phong;
    int ma_kh;
public:
    DatPhong();

    virtual ~DatPhong();

    DatPhong(int maDatPhong, const string &thoiGianDat, const string &thoiGianNhan, const string &thoiGianTra,
             const string &tinhTrangDatPhong, int maPhong, int maKh);

    int getMaDatPhong() const;

    void setMaDatPhong(int maDatPhong);

    const string &getThoiGianDat() const;

    void setThoiGianDat(const string &thoiGianDat);

    const string &getThoiGianNhan() const;

    void setThoiGianNhan(const string &thoiGianNhan);

    const string &getThoiGianTra() const;

    void setThoiGianTra(const string &thoiGianTra);

    const string &getTinhTrangDatPhong() const;

    void setTinhTrangDatPhong(const string &tinhTrangDatPhong);

    int getMaPhong() const;

    void setMaPhong(int maPhong);

    int getMaKh() const;

    void setMaKh(int maKh);

    void nhap();

    void hienThiThongTin();
};


#endif //CPP_QLKS_DATPHONG_H
