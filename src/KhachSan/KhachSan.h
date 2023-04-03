//
// Created by Andy Nguyen on 03/04/2023.
//

#ifndef CPP_QLKS_KHACHSAN_H
#define CPP_QLKS_KHACHSAN_H
#include <iostream>
#include "../Utils/Utils.h"

using namespace std;
class KhachSan {
private:
    static int ma_ks;
    string ten_ks;
    string dia_chi;
    string sdt;
    string email;
public:
    KhachSan();

    KhachSan(const string &tenKs, const string &diaChi, const string &sdt, const string &email);

    virtual ~KhachSan();

    static int getMaKs();

    static void setMaKs(int maKs);

    const string &getTenKs() const;

    void setTenKs(const string &tenKs);

    const string &getDiaChi() const;

    void setDiaChi(const string &diaChi);

    const string &getSdt() const;

    void setSdt(const string &sdt);

    const string &getEmail() const;

    void setEmail(const string &email);
};


#endif //CPP_QLKS_KHACHSAN_H
