//
// Created by Andy Nguyen on 03/04/2023.
//

#include "KhachSan.h"

int KhachSan::ma_ks = 1;

KhachSan::KhachSan(
        const string &tenKs,
        const string &diaChi,
        const string &sdt,
        const string &email) :
        ten_ks(tenKs),
        dia_chi(diaChi),
        sdt(sdt),
        email(email)
        {}

KhachSan::KhachSan() {}

KhachSan::~KhachSan() {

}

int KhachSan::getMaKs() {
    return ma_ks;
}

const string &KhachSan::getTenKs() const {
    return ten_ks;
}

void KhachSan::setTenKs(const string &tenKs) {
    ten_ks = tenKs;
}

const string &KhachSan::getDiaChi() const {
    return dia_chi;
}

void KhachSan::setDiaChi(const string &diaChi) {
    dia_chi = diaChi;
}

const string &KhachSan::getSdt() const {
    return sdt;
}

void KhachSan::setSdt(const string &sdt) {
    KhachSan::sdt = sdt;
}

const string &KhachSan::getEmail() const {
    return email;
}

void KhachSan::setEmail(const string &email) {
    KhachSan::email = email;
}
