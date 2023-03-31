//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Phong.h"

Phong::Phong(string loaiPhong, int soPhong, int giaPhong, int tinhtrangPhong):
loai_phong(loaiPhong),so_phong(soPhong),gia_phong(giaPhong),tinh_trang_phong(tinhtrangPhong) {}

void Phong::init() {
    {
        this->loai_phong = getString("Nhap loai phong:", 20);
        this->so_phong = getNumber("Nhap so phong: ");
        this->gia_phong = getNumber("Nhap gia phong: ");
        this->tinh_trang_phong = getNumber("Nhap loai phong: ");
    }
}

int Phong::getMaPhong() const {
    return ma_phong;
}

void Phong::setMaPhong(int maPhong) {
    ma_phong = maPhong;
}

const string &Phong::getLoaiPhong() const {
    return loai_phong;
}

void Phong::setLoaiPhong(const string &loaiPhong) {
    this->loai_phong = loaiPhong;
}

int Phong::getSoPhong() const {
    return so_phong;
}

void Phong::setSoPhong(int soPhong) {
    this->so_phong = soPhong;
}

int Phong::getGiaPhong() const {
    return gia_phong;
}

void Phong::setGiaPhong(int giaPhong) {
    this->gia_phong = giaPhong;
}

int Phong::getTinhTrangPhong() const {
    return tinh_trang_phong;
}

void Phong::setTinhTrangPhong(int tinhTrangPhong) {
    this->tinh_trang_phong = tinhTrangPhong;
}

void Phong::hienThiThongTin() {
    std::cout << "Thong tin phong:";
    std::cout << "\n====================================\n";
    std::cout << "Ma phong: " << getMaPhong();
    std::cout << "\nLoai phong: " << getLoaiPhong();
    std::cout << "\nSo phong: " << getSoPhong();
    std::cout << "\nGia phong: " << getGiaPhong();
    std::cout << "\nTinh trang phong: " << getTinhTrangPhong();
    std::cout << "\n====================================\n";
}


