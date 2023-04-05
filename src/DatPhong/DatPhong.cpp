//
// Created by Andy Nguyen on 03/04/2023.
//

#include "DatPhong.h"

DatPhong::DatPhong() {}

DatPhong::~DatPhong() {

}

DatPhong::DatPhong(int maDatPhong, const std::string &thoiGianDat, const std::string &thoiGianTra,
                   const std::string &tinhTrangDatPhong, KhachHang *kh, Phong *p) : ma_dat_phong(maDatPhong),
                                                                                    thoi_gian_dat(thoiGianDat),
                                                                                    thoi_gian_tra(thoiGianTra),
                                                                                    tinh_trang_dat_phong(
                                                                                            tinhTrangDatPhong), kh(kh),
                                                                                    p(p) {}

int DatPhong::getMaDatPhong() const {
    return ma_dat_phong;
}

void DatPhong::setMaDatPhong(int maDatPhong) {
    ma_dat_phong = maDatPhong;
}

const std::string &DatPhong::getThoiGianDat() const {
    return thoi_gian_dat;
}

void DatPhong::setThoiGianDat(const std::string &thoiGianDat) {
    thoi_gian_dat = thoiGianDat;
}

const std::string &DatPhong::getThoiGianTra() const {
    return thoi_gian_tra;
}

void DatPhong::setThoiGianTra(const std::string &thoiGianTra) {
    thoi_gian_tra = thoiGianTra;
}

const std::string &DatPhong::getTinhTrangDatPhong() const {
    return tinh_trang_dat_phong;
}

void DatPhong::setTinhTrangDatPhong(const std::string &tinhTrangDatPhong) {
    tinh_trang_dat_phong = tinhTrangDatPhong;
}

KhachHang *DatPhong::getKh() const {
    return kh;
}

void DatPhong::setKh(KhachHang *kh) {
    DatPhong::kh = kh;
}

Phong *DatPhong::getP() const {
    return p;
}

void DatPhong::setP(Phong *p) {
    DatPhong::p = p;
}

void DatPhong::nhap() {
this->thoi_gian_dat = getDate("Nhap thoi gian dat: ") ;
this->thoi_gian_tra = getDate("Nhap thoi gian tra: ");
}

void DatPhong::hienThiThongTin() {
    std::cout << "Thong tin dat phong:";
    std::cout << "\n====================================\n";
    std::cout << "\nTen khach hang: " << kh->getTenKh();
    std::cout << "\nSo phong: " << p->getSoPhong();
    std::cout << "\nThoi gian dat: " << getThoiGianDat();
    std::cout << "\nThoi gian tra: " << getThoiGianTra();
    std::cout << "\nTinh trang dat phong: " << getTinhTrangDatPhong();
    std::cout << "\n====================================\n";
}


