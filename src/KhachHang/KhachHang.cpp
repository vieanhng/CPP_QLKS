//
// Created by anhvu on 3/30/2023.
//

#include "KhachHang.h"

KhachHang::KhachHang() {}

KhachHang::KhachHang(int maKh, const string &tenKh, const string &diaChi, const string &sdt, const string &email)
        : ma_kh(maKh), ten_kh(tenKh), dia_chi(diaChi), sdt(sdt), email(email) {}

KhachHang::~KhachHang() {

}

int KhachHang::getMaKh() const {
    return ma_kh;
}

void KhachHang::setMaKh(int maKh) {
    ma_kh = maKh;
}

const string &KhachHang::getTenKh() const {
    return ten_kh;
}

void KhachHang::setTenKh(const string &tenKh) {
    ten_kh = tenKh;
}

const string &KhachHang::getDiaChi() const {
    return dia_chi;
}

void KhachHang::setDiaChi(const string &diaChi) {
    dia_chi = diaChi;
}

const string &KhachHang::getSdt() const {
    return sdt;
}

void KhachHang::setSdt(const string &sdt) {
    KhachHang::sdt = sdt;
}

const string &KhachHang::getEmail() const {
    return email;
}

void KhachHang::setEmail(const string &email) {
    KhachHang::email = email;
}

void KhachHang::hienThiThongTin() {

}

void KhachHang::nhap() {

}

