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
            << dp->getKh()->getMaKh() << ","
       << ")";
    datPhongQuery = ss.str();
    db.queryToDatabase(datPhongQuery);
    p->setTinhTrangPhong(0);
    qlP.capNhatPhong(p);

    delete p;
    delete dp;
    delete kh;
}

void QLDatPhong::xoaDatPhong() {

}

void QLDatPhong::suaDatPhong() {

}

void QLDatPhong::dsDatPhong() {

}

DatPhong *QLDatPhong::loadDatPhong(int ma_dat_phong) {
    return nullptr;
}

bool QLDatPhong::existDatPhong(int ma_dat_phong) {
    return false;
}
