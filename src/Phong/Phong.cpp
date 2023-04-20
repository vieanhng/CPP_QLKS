//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Phong.h"

Phong::Phong(int maPhong, std::string loaiPhong, int soPhong, int giaPhong, int tinhtrangPhong):
ma_phong(maPhong),loai_phong(loaiPhong),so_phong(soPhong),gia_phong(giaPhong),tinh_trang_phong(tinhtrangPhong) {}

void Phong::nhap() {
    {
        this->loai_phong = getString("Nhap loai phong:", 20);
        this->so_phong = getNumber("Nhap so phong: ");
        this->gia_phong = getNumber("Nhap gia phong: ");
        this->tinh_trang_phong = getNumber("Nhap tinh trang phong(1:Con, 0:Het): ");
    }
}

int Phong::getMaPhong() const {
    return ma_phong;
}

void Phong::setMaPhong(int maPhong) {
    ma_phong = maPhong;
}

const std::string &Phong::getLoaiPhong() const {
    return loai_phong;
}

void Phong::setLoaiPhong(const std::string &loaiPhong) {
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

void Phong::hienThi() {
    std::cout << "Thong tin phong:";
    std::cout << "\n====================================\n";
    std::cout << "Ma phong: " << getMaPhong();
    std::cout << "\nLoai phong: " << getLoaiPhong();
    std::cout << "\nSo phong: " << getSoPhong();
    std::cout << "\nGia phong: " << getGiaPhong();
    std::cout << "\nTinh trang phong: " << getTinhTrangPhong();
    std::cout << "\n====================================\n";
}



