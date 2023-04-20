//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_KHACHSAN_H
#define CPP_QLKS_KHACHSAN_H
#include <iostream>
#include "../Database/Database.h"
#include "../Utils/Utils.h"

class KhachSan {
private:
    static int ma_ks;
    std::string ten_ks;
    std::string dia_chi;
    std::string sdt;
    std::string email;
public:
    KhachSan();

    KhachSan(const std::string &tenKs, const std::string &diaChi, const std::string &sdt, const std::string &email);

    virtual ~KhachSan();

    static int getMaKs();

    static void setMaKs(int maKs);

    const std::string &getTenKs() const;

    void setTenKs(const std::string &tenKs);

    const std::string &getDiaChi() const;

    void setDiaChi(const std::string &diaChi);

    const std::string &getSdt() const;

    void setSdt(const std::string &sdt);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    void hienThiThongTin() const;
};


#endif //CPP_QLKS_KHACHSAN_H
