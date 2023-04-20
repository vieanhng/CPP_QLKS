//
// Created by Quynh Anh on 11/4/2023.
//

#include "HoaDon.h"

/**
 * Ham khoi tao co tham so
 * @param soHd
 * @param ngayLap
 * @param soTien
 * @param tinhTrangThanhToan
 * @param datPhong
 */
HoaDon::HoaDon(
        int soHd,
        const std::string &ngayLap,
        int soTien,
        std::string tinhTrangThanhToan,
        DatPhong *datPhong) :
        so_HD(soHd),
        ngay_lap(ngayLap),
        so_tien(soTien),
        tinh_trang_thanh_toan(tinhTrangThanhToan),
        datPhong(datPhong) {}

/**
 * ham khoi tao khong tham so
 */
HoaDon::HoaDon() {}

/**
 * Nhap thong tin hoa don
 */
void HoaDon::nhap() {
    {
        this->ngay_lap = getDate("Nhap ngay lap:");
    }
}

/**
 * get so hoa don
 * @return
 */
int HoaDon::getSoHd() const {
    return so_HD;
}

/**
 * set so hoa don
 * @param soHd
 */
void HoaDon::setSoHd(int soHd) {
    so_HD = soHd;
}

/**
 * get ngay lap
 * @return
 */
const std::string &HoaDon::getNgayLap() const {
    return ngay_lap;
}

/**
 * set ngay lap
 * @param ngayLap
 */
void HoaDon::setNgayLap(const std::string &ngayLap) {
    ngay_lap = ngayLap;
}

/**
 * get so tien
 * @return
 */
int HoaDon::getSoTien() const {
    return so_tien;
}

/**
 * set so tien
 * @param soTien
 */
void HoaDon::setSoTien(int soTien) {
    so_tien = soTien;
}

/**
 * Get dat phong
 * @return
 */
DatPhong *HoaDon::getDatPhong() const {
    return datPhong;
}

/**
 * set dat phong
 * @param datPhong
 */
void HoaDon::setDatPhong(DatPhong *datPhong) {
    HoaDon::datPhong = datPhong;
}

/**
 * Hien thi thong tin hoa don
 */
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

/**
 * Get tinh trang thanh toan
 * @return
 */
const std::string &HoaDon::getTinhTrangThanhToan() const {
    return tinh_trang_thanh_toan;
}

/**
 * Set tinh trang thanh toan
 * @param tinhTrangThanhToan
 */
void HoaDon::setTinhTrangThanhToan(const std::string &tinhTrangThanhToan) {
    tinh_trang_thanh_toan = tinhTrangThanhToan;
}








