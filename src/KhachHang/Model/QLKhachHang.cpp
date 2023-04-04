//
// Created by Andy Nguyen on 03/04/2023.
//

#include "QLKhachHang.h"

void QLKhachHang::taoKhachHang() {

}

void QLKhachHang::xoaKhachHang() {

}

void QLKhachHang::suaKhachHang() {

}

void QLKhachHang::dsKhachHang() {
    try {
        tabulate::Table khachhangTable;
        cout << "DANH SACH KHACH HANG"<<endl;
        khachhangTable.add_row({"ma khach hang","ten khach hang","dia chi","so dien thoai","email"});
        ss.str("");
        ss << "select * from khach hang";
        std::string query = ss.str();
        MYSQL_RES* res = exec_query(query.c_str());
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            khachhangTable.add_row({row[0], row[1],row[2],row[3],row[4]});
        }
        std::cout << khachhangTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

KhachHang *QLKhachHang::loadKhachHang(int maKh) {
    KhachHang* khachhang = NULL;
    ss.str("");
    ss << "SELECT * FROM khachhang WHERE ma_kh=" << maKh;
    std::string query = ss.str();

    MYSQL_RES* res = exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);

    if (row != NULL) {
        khachhang = new KhachHang();
        khachhang->setMaKh(maKh);
        khachhang->setTenKh(row[1]);
        khachhang->setDiaChi(row[2]);
        khachhang->setSdt(row[3]);
        khachhang->setEmail(row[4]);
    }

    mysql_free_result(res);
    return khachhang;
}

bool QLKhachHang::existKhachHang(int ma_kh) {
    return false;
}
