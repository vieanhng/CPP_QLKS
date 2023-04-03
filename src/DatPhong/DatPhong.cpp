//
// Created by Andy Nguyen on 03/04/2023.
//

#include "DatPhong.h"

DatPhong::DatPhong() {}

DatPhong::~DatPhong() {

}

DatPhong::DatPhong(
        int maDatPhong,
        const string &thoiGianDat,
        const string &thoiGianNhan,
        const string &thoiGianTra,
        const string &tinhTrangDatPhong,
        int maPhong,
        int maKh
        ) :
        ma_dat_phong(maDatPhong),
        thoi_gian_dat(thoiGianDat),
        thoi_gian_nhan(thoiGianNhan),
        thoi_gian_tra(thoiGianTra),
        tinh_trang_dat_phong(tinhTrangDatPhong),
        ma_phong(maPhong),
        ma_kh(maKh)
        {}

int DatPhong::getMaDatPhong() const {
    return ma_dat_phong;
}

void DatPhong::setMaDatPhong(int maDatPhong) {
    ma_dat_phong = maDatPhong;
}

const string &DatPhong::getThoiGianDat() const {
    return thoi_gian_dat;
}

void DatPhong::setThoiGianDat(const string &thoiGianDat) {
    thoi_gian_dat = thoiGianDat;
}

const string &DatPhong::getThoiGianNhan() const {
    return thoi_gian_nhan;
}

void DatPhong::setThoiGianNhan(const string &thoiGianNhan) {
    thoi_gian_nhan = thoiGianNhan;
}

const string &DatPhong::getThoiGianTra() const {
    return thoi_gian_tra;
}

void DatPhong::setThoiGianTra(const string &thoiGianTra) {
    thoi_gian_tra = thoiGianTra;
}

const string &DatPhong::getTinhTrangDatPhong() const {
    return tinh_trang_dat_phong;
}

void DatPhong::setTinhTrangDatPhong(const string &tinhTrangDatPhong) {
    tinh_trang_dat_phong = tinhTrangDatPhong;
}

int DatPhong::getMaPhong() const {
    return ma_phong;
}

void DatPhong::setMaPhong(int maPhong) {
    ma_phong = maPhong;
}

int DatPhong::getMaKh() const {
    return ma_kh;
}

void DatPhong::setMaKh(int maKh) {
    ma_kh = maKh;
}

void DatPhong::nhap() {

}

void DatPhong::hienThiThongTin() {

}


