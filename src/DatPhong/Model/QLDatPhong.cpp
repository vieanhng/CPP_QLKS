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
    while(!qlP.existPhong(ma_phong, "tinh_trang_phong=1")){
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
    dsDatPhong();
    int ma_dp = getNumber("Nhap ma dat phong can xoa: ");
    DatPhong *dp;
    dp = loadDatPhong(ma_dp);
    cout << "Ban chac chan muon xoa dat phong:\n";
    dp->hienThiThongTin();
    cout << "1. Xoa\n"
            "2. Huy\n";
    int choice = getNumber("Lua chon: ");
    switch (choice) {
        case 1:
            ss.str("");
            ss << "DELETE from dat_phong where ma_dat_phong=" << ma_dp;
            db.queryToDatabase(ss.str(),"Xoa dat phong thanh cong!\n");
            dsDatPhong();
            break;
        case 2:
            break;
    }
    delete dp;
}

void QLDatPhong::suaDatPhong() {
    try{
        int choice;
        dsDatPhong();
        int ma_dp = getNumber("Nhap ma dat phong can sua: ");
        while(!existDatPhong(ma_dp)){
            ma_dp = getNumber("Sai ma dat phong! Vui long nhap lai: ");
        }
        DatPhong* dp;
        dp = loadDatPhong(ma_dp);
        Phong *p;
        int ma_phong_cu = dp->getP()->getMaPhong();
        int ma_phong;
        do {
            dp->hienThiThongTin();
            cout <<"\n Chon truong muon sua:\n"
                   "1.Ngay tra phong\n"
                   "2.Doi phong\n"
                   "Lua chon khac:\n"
                   "3.Luu\n"
                   "4.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    dp->setThoiGianTra(getDate("Nhap ngay tra phong"));
                    break;
                case 2:
                    std::cout<<"Danh sach phong trong\n";
                    qlP.danhSachPhong("tinh_trang_phong=1");
                    ma_phong = getNumber("Nhap ma phong muon chon: ");
                    while(!qlP.existPhong(ma_phong, "tinh_trang_phong=1")){
                        ma_phong = getNumber("Sai ma phong! Vui long nhap lai: ");
                    }
                    p = qlP.loadPhong(ma_phong);
                    dp->setP(p);
                    break;
                case 3:
                    if(p->getMaPhong() != ma_phong_cu){
                        p->setTinhTrangPhong(0);
                        qlP.capNhatPhong(p);
                        p = qlP.loadPhong(ma_phong_cu);
                        dp->setP(p);
                        p->setTinhTrangPhong(1);
                        qlP.capNhatPhong(p);
                    }
                    capNhatDatPhong(dp);
                    delete p;
                    delete dp;
                    break;
            }
        } while ( choice != 3 && choice !=4 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }

}

void QLDatPhong::dsDatPhong(string where) {
    try {
        tabulate::Table datPhongTable;
        cout << "DANH SACH DAT PHONG"<<endl;
        datPhongTable.add_row({"ma_dat_phong","thoi_gian_dat","thoi_gian_tra","tinh_trang_dat_phong","ma phong","tenkhachhang"});
        ss.str("");
        ss << "select ma_dat_phong,thoi_gian_dat,thoi_gian_tra,tinh_trang_dat_phong,ma_phong,ten_kh"
              " from dat_phong inner join khach_hang on dat_phong.ma_kh = khach_hang.ma_kh";

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
    DatPhong* dp = NULL;
    ss.str("");
    ss << "SELECT * FROM dat_phong WHERE ma_dat_phong=" << ma_dat_phong;
    std::string query = ss.str();

    MYSQL_RES* res = db.exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);


    if (row != NULL) {
        dp = new DatPhong();
        dp->setMaDatPhong(ma_dat_phong);
        dp->setThoiGianDat(row[1]);
        dp->setThoiGianTra(row[2]);
        dp->setTinhTrangDatPhong(row[3]);
        dp->setP(qlP.loadPhong(std::atoi(row[4])));
        dp->setKh(qlKH.loadKhachHang(std::atoi(row[5])));
    }

    mysql_free_result(res);
    return dp;
}

bool QLDatPhong::existDatPhong(int ma_dat_phong) {
    ss.str("");
    ss << "Select ma_dat_phong from dat_phong where ma_dat_phong=" << ma_dat_phong;
    if(db.checkLength(ss.str())>0){
        return true;
    }
    return false;
}

void QLDatPhong::capNhatDatPhong(DatPhong *dp){
    ss.str("");
    ss << "UPDATE dat_phong SET "
       << "thoi_gian_tra = '" << dp->getThoiGianTra() << "', "
       << "ma_phong = '" << dp->getP()->getMaPhong() << "' "
       << "WHERE ma_dat_phong = " << dp->getMaDatPhong() << ";";
    string updateDatPhongQuery = ss.str();
    db.queryToDatabase(updateDatPhongQuery);
}

 QLPhong &QLDatPhong::getQlP() {
    return qlP;
}



