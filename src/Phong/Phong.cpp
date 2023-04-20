//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Phong.h"

/**
 * ham khoi tao phong
 * @param maPhong
 * @param loaiPhong
 * @param soPhong
 * @param giaPhong
 * @param tinhtrangPhong
 */
Phong::Phong(int maPhong, std::string loaiPhong, int soPhong, int giaPhong, int tinhtrangPhong):
ma_phong(maPhong),loai_phong(loaiPhong),so_phong(soPhong),gia_phong(giaPhong),tinh_trang_phong(tinhtrangPhong) {}

/**
 * nhap thong tin phong
 */
void Phong::nhap() {
    {
        this->loai_phong = getString("Nhap loai phong:", 20);
        this->so_phong = getNumber("Nhap so phong: ");
        this->gia_phong = getNumber("Nhap gia phong: ");
        this->tinh_trang_phong = getNumber("Nhap tinh trang phong(1:Con, 0:Het): ");
    }
}

/**
 * get ma phong
 * @return
 */
int Phong::getMaPhong() const {
    return ma_phong;
}

/**
 * set ma phong
 * @param maPhong
 */
void Phong::setMaPhong(int maPhong) {
    ma_phong = maPhong;
}

/**
 * get loai phong
 * @return
 */
const std::string &Phong::getLoaiPhong() const {
    return loai_phong;
}

/**
 * set loai phong
 * @param loaiPhong
 */
void Phong::setLoaiPhong(const std::string &loaiPhong) {
    this->loai_phong = loaiPhong;
}

/**
 * get so phong
 * @return
 */
int Phong::getSoPhong() const {
    return so_phong;
}

/**
 * set so phong
 * @param soPhong
 */
void Phong::setSoPhong(int soPhong) {
    this->so_phong = soPhong;
}

/**
 * get gia phong
 * @return
 */
int Phong::getGiaPhong() const {
    return gia_phong;
}

/**
 * set gia phong
 * @param giaPhong
 */
void Phong::setGiaPhong(int giaPhong) {
    this->gia_phong = giaPhong;
}

/**
 * get tinh trang phong
 * @return
 */
int Phong::getTinhTrangPhong() const {
    return tinh_trang_phong;
}

/**
 * set tinh trang phong
 * @param tinhTrangPhong
 */
void Phong::setTinhTrangPhong(int tinhTrangPhong) {
    this->tinh_trang_phong = tinhTrangPhong;
}

/**
 * hien thi thong tin phong
 */
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



