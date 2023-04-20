//
// Created by Quynh Anh on 11/4/2023.
//

#include "HoaDon.h"

HoaDon::HoaDon(int soHd, const std::string &ngayLap, int soTien, std::string tinhTrangThanhToan, DatPhong *datPhong) : so_HD(
        soHd), ngay_lap(ngayLap), so_tien(soTien), tinh_trang_thanh_toan(tinhTrangThanhToan), datPhong(datPhong) {}

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

DatPhong *HoaDon::getDatPhong() const {
    return datPhong;
}

void HoaDon::setDatPhong(DatPhong *datPhong) {
    HoaDon::datPhong = datPhong;
}

void HoaDon::hienThi() {
    std::cout << "Thong tin hoa don:";
    std::cout << "\n====================================\n";
    std::cout << "So hoa don: " << this->so_HD;
    std::cout << "\nNgay lap: " << this->ngay_lap;
    std::cout << "\nSo tien: " << this->so_tien;
    std::cout << "\nTinh trang thanh toan: " << this->tinh_trang_thanh_toan;
    std::cout << "\nMa dat phong: " << this->datPhong->getMaDatPhong();
    std::cout << "\n====================================\n";
}

const std::string &HoaDon::getTinhTrangThanhToan() const {
    return tinh_trang_thanh_toan;
}

void HoaDon::setTinhTrangThanhToan(const std::string &tinhTrangThanhToan) {
    tinh_trang_thanh_toan = tinhTrangThanhToan;
}






