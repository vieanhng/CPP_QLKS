//
// Created by anhvu on 3/30/2023.
//

#include "KhachHang.h"

KhachHang::KhachHang() {}

KhachHang::KhachHang(int maKh, const std::string &tenKh, const std::string &diaChi, const std::string &sdt, const std::string &email)
        : ma_kh(maKh), ten_kh(tenKh), dia_chi(diaChi), sdt(sdt), email(email) {}

KhachHang::~KhachHang() {

}

int KhachHang::getMaKh() const {
    return ma_kh;
}

void KhachHang::setMaKh(int maKh) {
    ma_kh = maKh;
}

const std::string &KhachHang::getTenKh() const {
    return ten_kh;
}

void KhachHang::setTenKh(const std::string &tenKh) {
    ten_kh = tenKh;
}

const std::string &KhachHang::getDiaChi() const {
    return dia_chi;
}

void KhachHang::setDiaChi(const std::string &diaChi) {
    dia_chi = diaChi;
}

const std::string &KhachHang::getSdt() const {
    return sdt;
}

void KhachHang::setSdt(const std::string &sdt) {
    KhachHang::sdt = sdt;
}

const std::string &KhachHang::getEmail() const {
    return email;
}

void KhachHang::setEmail(const std::string &email) {
    KhachHang::email = email;
}

void KhachHang::hienThiThongTin() {

}

void KhachHang::nhap() {

}

