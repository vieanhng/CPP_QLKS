//
// Created by anhvu on 3/30/2023.
//

#ifndef CPP_QLKS_KHACHHANG_H
#define CPP_QLKS_KHACHHANG_H
#include <iostream>
#include "../Utils/Utils.h"

using namespace std;

class KhachHang {
private:
    int ma_kh;
    string ten_kh;
    string dia_chi;
    string sdt;
    string email;
public:
    KhachHang();

    KhachHang(int maKh, const string &tenKh, const string &diaChi, const string &sdt, const string &email);

    virtual ~KhachHang();

    int getMaKh() const;

    void setMaKh(int maKh);

    const string &getTenKh() const;

    void setTenKh(const string &tenKh);

    const string &getDiaChi() const;

    void setDiaChi(const string &diaChi);

    const string &getSdt() const;

    void setSdt(const string &sdt);

    const string &getEmail() const;

    void setEmail(const string &email);

    void hienThiThongTin();

    void nhap();
};


#endif //CPP_QLKS_KHACHHANG_H
