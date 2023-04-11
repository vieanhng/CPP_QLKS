//
// Created by Andy Nguyen on 03/04/2023.
//

#include "KhachSan.h"

int KhachSan::ma_ks = 1;

KhachSan::KhachSan(
        const std::string &tenKs,
        const std::string &diaChi,
        const std::string &sdt,
        const std::string &email) :
        ten_ks(tenKs),
        dia_chi(diaChi),
        sdt(sdt),
        email(email)
        {}

KhachSan::KhachSan() {
    Database* db = new Database;
    std::string query = "SELECT * FROM khach_san WHERE ma_ks=1";

    MYSQL_RES* res = db->exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);

    if (row != NULL) {
        setTenKs(row[1]);

    }

    mysql_free_result(res);
    delete db;
}

KhachSan::~KhachSan() {

}

int KhachSan::getMaKs() {
    return ma_ks;
}

const std::string &KhachSan::getTenKs() const {
    return ten_ks;
}

void KhachSan::setTenKs(const std::string &tenKs) {
    ten_ks = tenKs;
}

const std::string &KhachSan::getDiaChi() const {
    return dia_chi;
}

void KhachSan::setDiaChi(const std::string &diaChi) {
    dia_chi = diaChi;
}

const std::string &KhachSan::getSdt() const {
    return sdt;
}

void KhachSan::setSdt(const std::string &sdt) {
    KhachSan::sdt = sdt;
}

const std::string &KhachSan::getEmail() const {
    return email;
}

void KhachSan::setEmail(const std::string &email) {
    KhachSan::email = email;
}
void KhachSan::hienThiThongTin(){
    std::cout<<"Ten khach san: "<<getTenKs() << std::endl;
    std::cout<<"Dia chi: "<<getDiaChi()<< std::endl;
    std::cout<<"Email: "<<getEmail()<< std::endl;
    std::cout<<"So dien thoai: "<<getSdt()<< std::endl;
}
