//
// Created by anhvu on 3/30/2023.
//

#ifndef CPP_QLKS_KHACHHANG_H
#define CPP_QLKS_KHACHHANG_H
#include <iostream>
#include "../Utils/Utils.h"
#include "../DoiTuong/DoiTuong.h"



class KhachHang: public DoiTuong{
private:
    int ma_kh;
    std::string ten_kh;
    std::string dia_chi;
    std::string sdt;
    std::string email;
    std::string cccd;
public:
    KhachHang();

    KhachHang(int maKh, const std::string &tenKh, const std::string &diaChi, const std::string &sdt, const std::string &email,const std::string &cccd );

    virtual ~KhachHang();

    int getMaKh() const;

    void setMaKh(int maKh);

    const std::string &getTenKh() const;

    void setTenKh(const std::string &tenKh);

    const std::string &getDiaChi() const;

    void setDiaChi(const std::string &diaChi);

    const std::string &getSdt() const;

    void setSdt(const std::string &sdt);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    void hienThi();

    void nhap();

    const std::string &getCccd() const;

    void setCccd(const std::string &cccd);
};


#endif //CPP_QLKS_KHACHHANG_H
