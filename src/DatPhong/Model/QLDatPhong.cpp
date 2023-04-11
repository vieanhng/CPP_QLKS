//
// Created by Andy Nguyen on 03/04/2023.
//

#include "QLDatPhong.h"


void QLDatPhong::taoDatPhong() {
    std::string cccd;
    KhachHang *kh;
    Phong* p;
    DatPhong* dp = new DatPhong;
    cccd = getString("Nhap can cuoc cong dan: ",20);
    if(!qlKH.existKhachHang(cccd)){
        qlKH.taoKhachHang();
    }
    kh = qlKH.loadKhachHang(cccd);
    dp->setKh(kh);
    qlP.danhSachPhong("tinh_trang_phong = 1");
    int ma_phong = getNumber("Nhap ma phong muon chon: ");
    while(!qlP.existPhong(ma_phong)){
        ma_phong = getNumber("Sai ma phong! Vui long nhap lai: ");
    }
    p = qlP.loadPhong(ma_phong);
    dp->setP(p);
    dp->nhap();
    dp->setTinhTrangDatPhong("Thanh cong");
    dp->hienThiThongTin();
    std::string datPhongQuery;
    ss.str("");
    ss << "INSERT INTO dat_phong(thoi_gian_dat,thoi_gian_tra,tinh_trang_dat_phong,ma_phong,ma_kh) "
          "VALUES ("
       << "'" << dp->getThoiGianDat()<< "',"
            << "'"<< dp->getThoiGianTra()<< "',"
            << "'" << dp->getTinhTrangDatPhong()<< "',"
            << dp->getP()->getMaPhong() << ","
            << dp->getKh()->getMaKh()
       << ")";
    datPhongQuery = ss.str();
    db.queryToDatabase(datPhongQuery);
    p->setTinhTrangPhong(0);
    qlP.capNhatPhong(p);
    dp->hienThiThongTin();
    delete p;
    delete dp;
    delete kh;
}

void QLDatPhong::xoaDatPhong() {

}

void QLDatPhong::suaDatPhong() {

}

void QLDatPhong::dsDatPhong(string where) {
    try {
        tabulate::Table datPhongTable;
        cout << "DANH SACH DAT PHONG"<<endl;
        datPhongTable.add_row({"ma_dat_phong","thoi_gian_dat","thoi_gian_tra","tinh_trang_dat_phong","so phong","tenkhachhang"});
        ss.str("");
        ss << "select ma_dat_phong,thoi_gian_dat,tinh_trang_dat_phong,so_phong,ten_kh"
              " from dat_phong inner join khach_hang on dat_phong.ma_kh = khach_hang.ma_kh"
              " inner join phong on dat_phong.ma_phong = phong.ma_phong";

        if(where != ""){
            ss << " where " << where;
        };
        std::string query = ss.str();
        MYSQL_RES* res = db.exec_query(query.c_str());
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            datPhongTable.add_row({row[0], row[1],row[2],row[3],row[4],row[5]});
        }
        std::cout << datPhongTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

DatPhong *QLDatPhong::loadDatPhong(int ma_dat_phong) {
    return nullptr;
}

bool QLDatPhong::existDatPhong(int ma_dat_phong) {
    return false;
}
