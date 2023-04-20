//
// Created by Andy Nguyen on 03/04/2023.
//

#include "DatPhong.h"

/**
 * Ham khoi tao khong tham so
 */
DatPhong::DatPhong() {}

/**
 * Ham huy
 */
DatPhong::~DatPhong() {
}

/**
 * Ham khoi tao co tham so
 * @param maDatPhong
 * @param thoiGianDat
 * @param thoiGianTra
 * @param tinhTrangDatPhong
 * @param kh
 * @param p
 */
DatPhong::DatPhong(
        int maDatPhong,
        const std::string &thoiGianDat,
        const std::string &thoiGianTra,
        const std::string &tinhTrangDatPhong,
        KhachHang *kh,
        Phong *p
        ) : ma_dat_phong(maDatPhong),
            thoi_gian_dat(thoiGianDat),
            thoi_gian_tra(thoiGianTra),
            tinh_trang_dat_phong(tinhTrangDatPhong),
            kh(kh),
            p(p) {}


/**
 * Get ma dat phong
 * @return
 */
int DatPhong::getMaDatPhong() const {
    return ma_dat_phong;
}

/**
 * Set ma dat phong
 * @param maDatPhong
 */
void DatPhong::setMaDatPhong(int maDatPhong) {
    ma_dat_phong = maDatPhong;
}

/**
 * Get thoi gian dat
 * @return
 */
const std::string &DatPhong::getThoiGianDat() const {
    return thoi_gian_dat;
}

/**
 * Set thoi gian dat
 * @param thoiGianDat
 */
void DatPhong::setThoiGianDat(const std::string &thoiGianDat) {
    thoi_gian_dat = thoiGianDat;
}

/**
 * Get thoi gian tra
 * @return
 */
const std::string &DatPhong::getThoiGianTra() const {
    return thoi_gian_tra;
}

/**
 * Set thoi gian tra
 * @param thoiGianTra
 */
void DatPhong::setThoiGianTra(const std::string &thoiGianTra) {
    thoi_gian_tra = thoiGianTra;
}

/**
 * Get tinh trang dat phong
 * @return
 */
const std::string &DatPhong::getTinhTrangDatPhong() const {
    return tinh_trang_dat_phong;
}

/**
 * Set tinh trang dat phong
 * @param tinhTrangDatPhong
 */
void DatPhong::setTinhTrangDatPhong(const std::string &tinhTrangDatPhong) {
    tinh_trang_dat_phong = tinhTrangDatPhong;
}

/**
 * get Khach hang
 * @return
 */
KhachHang *DatPhong::getKh() const {
    return kh;
}

/**
 * set Khach hang
 * @param kh
 */
void DatPhong::setKh(KhachHang *kh) {
    DatPhong::kh = kh;
}

/**
 * get Phong
 * @return
 */
Phong *DatPhong::getP() const {
    return p;
}

/**
 * set Phong
 * @param p
 */
void DatPhong::setP(Phong *p) {
    DatPhong::p = p;
}


/**
 * Ham nhap thong tin
 */
void DatPhong::nhap() {
    this->thoi_gian_dat = getDate("Nhap thoi gian dat: ") ;
    this->thoi_gian_tra = getDate("Nhap thoi gian tra: ");
}

/**
 * Ham hien thi thong tin
 */
void DatPhong::hienThi() {
    std::cout << "Thong tin dat phong:";
    std::cout << "\n====================================\n";
    std::cout << "\nTen khach hang: " << kh->getTenKh();
    std::cout << "\nMa phong: " << p->getMaPhong();
    std::cout << "\nThoi gian dat: " << getThoiGianDat();
    std::cout << "\nThoi gian tra: " << getThoiGianTra();
    std::cout << "\nTinh trang dat phong: " << getTinhTrangDatPhong();
    std::cout << "\n====================================\n";
}


