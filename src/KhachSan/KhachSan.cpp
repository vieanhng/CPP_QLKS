//
// Created by Andy Nguyen on 03/04/2023.
//

#include "KhachSan.h"

/**
 * Dat ma khach san bang 1
 */
int KhachSan::ma_ks = 1;

/**
 * ham khoi tao khach san
 * @param tenKs
 * @param diaChi
 * @param sdt
 * @param email
 */
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

/**
 * ham khoi tao khong tham so
 */
KhachSan::KhachSan() {
    Database* db = new Database;
    std::string query = "SELECT * FROM khach_san WHERE ma_ks=1";
    MYSQL_RES* res = db->exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);

    if (row != NULL) {
        setTenKs(row[1]);
        setDiaChi(row[2]);
        setSdt(row[3]);
        setEmail(row[4]);
    }

    mysql_free_result(res);
    delete db;
}

/**
 * ham huy
 */
KhachSan::~KhachSan() {

}

/**
 * Get ma khach san
 * @return
 */
int KhachSan::getMaKs() {
    return KhachSan::ma_ks;
}

/**
 * get ten khach san
 * @return
 */
const std::string &KhachSan::getTenKs() const {
    return ten_ks;
}

/**
 * set ten khach san
 * @param tenKs
 */
void KhachSan::setTenKs(const std::string &tenKs) {
    ten_ks = tenKs;
}

/**
 * get dia chi khach san
 * @return
 */
const std::string &KhachSan::getDiaChi() const {
    return dia_chi;
}

/**
 * set dia chi khach san
 * @param diaChi
 */
void KhachSan::setDiaChi(const std::string &diaChi) {
    dia_chi = diaChi;
}

/**
 * get sdt khach san
 * @return
 */
const std::string &KhachSan::getSdt() const {
    return sdt;
}

/**
 * set so dien thoai khach san
 * @param sdt
 */
void KhachSan::setSdt(const std::string &sdt) {
    KhachSan::sdt = sdt;
}

/**
 * get email khach san
 * @return
 */
const std::string &KhachSan::getEmail() const {
    return email;
}

/**
 * set email khach san
 * @param email
 */
void KhachSan::setEmail(const std::string &email) {
    KhachSan::email = email;
}

/**
 * hien thi thong tin khach san
 */
void KhachSan::hienThiThongTin() const{
    std::cout<<"Ten khach san: "<<getTenKs() << std::endl;
    std::cout<<"Dia chi: "<<getDiaChi()<< std::endl;
    std::cout<<"Email: "<<getEmail()<< std::endl;
    std::cout<<"So dien thoai: "<<getSdt()<< std::endl;
}
