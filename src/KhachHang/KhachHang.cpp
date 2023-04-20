//
// Created by anhvu on 3/30/2023.
//

#include "KhachHang.h"

KhachHang::KhachHang() {}

KhachHang::KhachHang(int maKh, const std::string &tenKh, const std::string &diaChi, const std::string &sdt, const std::string &email, const std::string &cccd )
        : ma_kh(maKh), ten_kh(tenKh), dia_chi(diaChi), sdt(sdt), email(email), cccd(cccd) {}

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

const std::string &KhachHang::getCccd() const {
    return cccd;
}

void KhachHang::setCccd(const std::string &cccd) {
    KhachHang::cccd = cccd;
}

void KhachHang::hienThi() {
    std::cout << "Thong tin khach hang";
    std::cout <<"\n----------------------";
    std::cout <<"\nTen:"<<getTenKh();
    std::cout <<"\nDia chi:"<<getDiaChi();
    std::cout <<"\nSo dien thoai:"<<getSdt();
    std::cout<<"\nEmail:"<<getEmail();
    std::cout<<"\nCan cuoc cong dan: "<<getCccd()<<std::endl;
}
void KhachHang::nhap() {
    this->ten_kh = getString("Nhap ten khach hang: ",50);
    this->dia_chi = getString("Nhap dia chi: ",100);
    this->sdt = getString("Nhap so dien thoai: ",20);
    this->email = getString("Nhap email: ",100);
    this->cccd= getString("Nhap can cuoc cong dan: ",20);
}

