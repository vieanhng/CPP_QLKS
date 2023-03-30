//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Phong.h"

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

bool Phong::taoPhong() {
    try
    {
        std::string _loaiPhong = getString("Nhap loai phong: ", 20);
        setLoaiPhong(_loaiPhong);
        std::cout << "\nDo you want to save the book.\n";
        std::string createBookQuery;
        ss << "INSERT INTO phong(loai_phong) VALUES ( "<< "'" << this->loai_phong << "'" << ")";
        createBookQuery = ss.str();
        queryToDatabase(createBookQuery, "Book successfully added to database");
        std::cout << "Creating book operation aborted.\n";
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
        return false;
    }
}

void Phong::suaPhong() {

}

void Phong::hienThiThongTin() {

}

void Phong::xoaPhong() {

}
