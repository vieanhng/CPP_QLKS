//
// Created by Quynh Anh on 11/4/2023.
//

#include "HoaDon.h"

HoaDon::HoaDon(int soHD, std::string ngaylap, int soTien, int tinhtrangThanhToan, int madatPhong):
        so_HD(soHD),ngay_lap(ngaylap),so_tien(soTien),tinh_trang_thanh_toan(tinhtrangThanhToan),ma_dat_phong(madatPhong) {}

void HoaDon::nhap() {
    {
        this->ngay_lap = getString("Nhap ngay lap:", 50);
        this->so_tien = getNumber("Nhap so tien: ");
        this->tinh_trang_thanh_toan = getNumber("Nhap tinh trang thanh toan(1:Da thanh toan, 0:Chua thanh toan): ");
        this->ma_dat_phong = getNumber("Nhap ma dat phong: ");
    }
}

int HoaDon::getsoHD() const {
    return so_HD;
}

void HoaDon::setsoHD(int soHD) {
    so_HD = soHD;
}

const std::string &HoaDon::getngaylap() const {
    return ngay_lap;
}

void HoaDon::setngaylap(const std::string &ngaylap) {
    this->ngay_lap = ngaylap;
}

int HoaDon::getsoTien() const {
    return so_tien;
}

void HoaDon::setsoTien(int soTien) {
    this->so_tien = soTien;
}

int HoaDon::gettinhtrangThanhToan() const {
    return tinh_trang_thanh_toan;
}

void HoaDon::settinhtrangThanhToan(int tinhtrangThanhToan) {
    this->tinh_trang_thanh_toan = tinhtrangThanhToan;
}

int HoaDon::getmadatPhong() const {
    return ma_dat_phong;
}

void HoaDon::setmadatPhong(int madatPhong) {
    this->ma_dat_phong = madatPhong;
}

void HoaDon::hienThiThongTin() {
    std::cout << "Thong tin phong:";
    std::cout << "\n====================================\n";
    std::cout << "Ma phong: " << getsoHD();
    std::cout << "\nLoai phong: " << getngaylap();
    std::cout << "\nSo phong: " << getsoTien();
    std::cout << "\nGia phong: " << gettinhtrangThanhToan();
    std::cout << "\nTinh trang phong: " << getmadatPhong();
    std::cout << "\n====================================\n";
}


