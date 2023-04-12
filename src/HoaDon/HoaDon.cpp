//
// Created by Quynh Anh on 11/4/2023.
//

#include "HoaDon.h"

HoaDon::HoaDon(int soHD, std::string ngaylap, int soTien, int tinhtrangThanhToan, int madatPhong):
        so_HD(soHD),ngay_lap(ngaylap),so_tien(soTien),tinh_trang_thanh_toan(tinhtrangThanhToan),ma_dat_phong(madatPhong) {}

void HoaDon::nhap() {
    {
        this->ngay_lap = getDate("Nhap ngay lap:");
    }
}

int HoaDon::getSoHd() const {
    return so_HD;
}

void HoaDon::setSoHd(int soHd) {
    so_HD = soHd;
}

const std::string &HoaDon::getNgayLap() const {
    return ngay_lap;
}

void HoaDon::setNgayLap(const std::string &ngayLap) {
    ngay_lap = ngayLap;
}

int HoaDon::getSoTien() const {
    return so_tien;
}

void HoaDon::setSoTien(int soTien) {
    so_tien = soTien;
}

int HoaDon::getTinhTrangThanhToan() const {
    return tinh_trang_thanh_toan;
}

void HoaDon::setTinhTrangThanhToan(int tinhTrangThanhToan) {
    tinh_trang_thanh_toan = tinhTrangThanhToan;
}

DatPhong *HoaDon::getDatPhong() const {
    return datPhong;
}

void HoaDon::setDatPhong(DatPhong *datPhong) {
    HoaDon::datPhong = datPhong;
}

void HoaDon::hienThiThongTin() {
    std::cout << "Thong tin hoa don:";
    std::cout << "\n====================================\n";
    std::cout << "So hoa don: " << this->so_HD;
    std::cout << "\nNgay lap: " << this->ngay_lap;
    std::cout << "\nSo tien: " << this->so_tien;
    std::cout << "\nTinh trang thanh toan: " << this->tinh_trang_thanh_toan;
    std::cout << "\nMa dat phong: " << this->datPhong->getMaDatPhong();
    std::cout << "\n====================================\n";
}






