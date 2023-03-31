//
// Created by Andy Nguyen on 31/03/2023.
//

#include "QLPhong.h"


bool QLPhong::taoPhong() {
    try
    {
        Phong room("1234",2,2,1);
        room.hienThiThongTin();
        std::string taoPhongQuery;
        ss << "INSERT INTO phong(loai_phong,so_phong,gia_phong,tinh_trang_phong) "
              "VALUES ("
           << "'" << room.getLoaiPhong() << "',"
           << room.getSoPhong() << ","
           << room.getGiaPhong() << ","
           << room.getTinhTrangPhong()
           << ")";
        taoPhongQuery = ss.str();
        queryToDatabase(taoPhongQuery, "Tao phong thanh cong!");
        danhSachPhong();
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
        return false;
    }
}

void QLPhong::xoaPhong(int roomNumber) {

}

Phong* QLPhong::loadPhong(int maPhong) {
    std::stringstream ss;
    ss << "SELECT * FROM phong WHERE ma_phong=" << maPhong;
    std::string query = ss.str();

    MYSQL_RES* res = exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);

    Phong* room = NULL;
    if (row != NULL) {
        room = new Phong();
        room->setMaPhong(maPhong);
        room->setLoaiPhong(row[1]);
        room->setSoPhong(std::atoi(row[2]));
        room->setGiaPhong(std::atoi(row[3]));
        room->setTinhTrangPhong(std::atoi(row[4]));
    }

    mysql_free_result(res);
    return room;
}


std::vector<Phong *> QLPhong::getAllRooms() {
    return std::vector<Phong *>();
}

void QLPhong::danhSachPhong(){
    try {
        tabulate::Table phongTable;
        cout << "DANH SACH PHONG"<<endl;
        phongTable.add_row({"ma_phong","loai_phong","so_phong","gia_phong","tinh_trang_phong"});
        ss.str("");
        ss << "select * from phong";
        std::string query = ss.str();
        MYSQL_RES* res = exec_query(query.c_str());
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            phongTable.add_row({row[0], row[1],row[2],row[3], tinhTrangPhong(std::atoi(row[4]))});
        }
        std::cout << phongTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

string QLPhong::tinhTrangPhong(int tinhTrangPhong) {
    return tinhTrangPhong ? "Con" : "Het";
}
