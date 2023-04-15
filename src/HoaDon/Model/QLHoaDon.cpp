//
// Created by HP on 11/4/2023.
//

#include "QLHoaDon.h"


void QLHoaDon::taoHoaDon() {

}

void QLHoaDon::xoaHoaDon() {

}

void QLHoaDon::suaHoaDon() {
}


void QLHoaDon::dsHoaDon() {
    try {
        tabulate::Table hoadonTable;
        cout << "DANH SACH HOA DON"<<endl;
        hoadonTable.add_row({"so_hd","ngay_lap","so_tien","tinh_trang_thanh_toan","ma_dat_phong"});
        ss.str("");
        ss << "select * from hoa_don";
        std::string query = ss.str();
        MYSQL_RES* res = db.exec_query(query.c_str());
        MYSQL_ROW row;
        int i = 1;
        while ((row = mysql_fetch_row(res))) {
            hoadonTable.add_row({std::to_string(i),row[0], row[1],row[2],row[3],row[4],row[5]});
            i++;
        }
        std::cout << hoadonTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

HoaDon *QLHoaDon::loadHoaDon(int soHD) {

}

void QLHoaDon::capNhatHoaDon(HoaDon *hd) {

}

bool QLHoaDon::existHoaDon(int so_HD) {

}

void QLHoaDon::xemHoaDon() {

}
