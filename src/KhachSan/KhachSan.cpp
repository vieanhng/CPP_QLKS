//
// Created by Andy Nguyen on 03/04/2023.
//

#include "KhachSan.h"

int KhachSan::ma_ks = 1;

KhachSan::KhachSan(
        const std::string &tenKs,
        const std::string &diaChi,
        const std::string &sdt,
        const std::string &email) :
        ten_ks(tenKs),
        dia_chi(diaChi),
        sdt(sdt),
        email(email)
        {}

KhachSan::KhachSan() {

}

KhachSan::~KhachSan() {

}

int KhachSan::getMaKs() {
    return ma_ks;
}

const std::string &KhachSan::getTenKs() const {
    return ten_ks;
}

void KhachSan::setTenKs(const std::string &tenKs) {
    ten_ks = tenKs;
}

const std::string &KhachSan::getDiaChi() const {
    return dia_chi;
}

void KhachSan::setDiaChi(const std::string &diaChi) {
    dia_chi = diaChi;
}

const std::string &KhachSan::getSdt() const {
    return sdt;
}

void KhachSan::setSdt(const std::string &sdt) {
    KhachSan::sdt = sdt;
}

const std::string &KhachSan::getEmail() const {
    return email;
}

void KhachSan::setEmail(const std::string &email) {
    KhachSan::email = email;
}
void KhachSan::hienthithongtin(){
    std::cout<<"Ten khach san:"<<getTenKs();
    std::cout<<"Dia chi:"<<getDiaChi();
    std::cout<<"Email:"<<getEmail();
    std::cout<<"So dien thoai:"<<getSdt();
}
