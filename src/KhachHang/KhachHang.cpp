//
// Created by anhvu on 3/30/2023.
//

#include "KhachHang.h"

/**
 * ham khoi tao khach hang khong tham so
 */
KhachHang::KhachHang() {}

/**
 * Ham khoi tao khach hang co tham so
 * @param maKh
 * @param tenKh
 * @param diaChi
 * @param sdt
 * @param email
 * @param cccd
 */
KhachHang::KhachHang(
        int maKh,
        const std::string &tenKh,
        const std::string &diaChi,
        const std::string &sdt,
        const std::string &email,
        const std::string &cccd )
        : ma_kh(maKh),
        ten_kh(tenKh),
        dia_chi(diaChi),
        sdt(sdt),
        email(email),
        cccd(cccd) {}

/**
 * Ham huy
 */
KhachHang::~KhachHang() {

}

/**
 * get ma khach hang
 * @return
 */
int KhachHang::getMaKh() const {
    return ma_kh;
}

/**
 * set ma khach hang
 * @param maKh
 */
void KhachHang::setMaKh(int maKh) {
    ma_kh = maKh;
}

/**
 * get ten khach hang
 * @return
 */
const std::string &KhachHang::getTenKh() const {
    return ten_kh;
}

/**
 * set ten khach hang
 * @param tenKh
 */
void KhachHang::setTenKh(const std::string &tenKh) {
    ten_kh = tenKh;
}

/**
 * get dia chi
 * @return
 */
const std::string &KhachHang::getDiaChi() const {
    return dia_chi;
}

/**
 * set dia chi
 * @param diaChi
 */
void KhachHang::setDiaChi(const std::string &diaChi) {
    dia_chi = diaChi;
}

/**
 * get so dien thoai
 * @return
 */
const std::string &KhachHang::getSdt() const {
    return sdt;
}

/**
 * set so dien thoai
 * @param sdt
 */
void KhachHang::setSdt(const std::string &sdt) {
    KhachHang::sdt = sdt;
}

/**
 * get email
 * @return
 */
const std::string &KhachHang::getEmail() const {
    return email;
}

/**
 * set email khach hang
 * @param email
 */
void KhachHang::setEmail(const std::string &email) {
    KhachHang::email = email;
}

/**
 * get cccd khach hang
 * @return
 */
const std::string &KhachHang::getCccd() const {
    return cccd;
}

/**
 * set cccd khach hang
 * @param cccd
 */
void KhachHang::setCccd(const std::string &cccd) {
    KhachHang::cccd = cccd;
}

/**
 * hien thi thong tin khach hang
 */
void KhachHang::hienThi() {
    std::cout << "Thong tin khach hang";
    std::cout <<"\n----------------------";
    std::cout <<"\nTen:"<<getTenKh();
    std::cout <<"\nDia chi:"<<getDiaChi();
    std::cout <<"\nSo dien thoai:"<<getSdt();
    std::cout<<"\nEmail:"<<getEmail();
    std::cout<<"\nCan cuoc cong dan: "<<getCccd()<<std::endl;
}

/**
 * Nhap thong tin khach hang
 */
void KhachHang::nhap() {
    this->ten_kh = getString("Nhap ten khach hang: ",50);
    this->dia_chi = getString("Nhap dia chi: ",100);
    this->sdt = getString("Nhap so dien thoai: ",20);
    this->email = getString("Nhap email: ",100);
    this->cccd= getString("Nhap can cuoc cong dan: ",20);
}

