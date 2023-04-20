//
// Created by HP on 11/4/2023.
//

#include "QLHoaDon.h"

/**
 * Ham tao hoa don
 */
void QLHoaDon::tao() {
    try
    {
        HoaDon* hd = new HoaDon;
        qlDp.danhSach();
        int ma_dp = getNumber("Nhap ma dat phong muon tao hoa don:");
        while (!qlDp.existDatPhong(ma_dp)){
            cout << "Sai ma dp vui long nhap lai!" << endl;
            ma_dp = getNumber("Nhap ma dat phong muon tao hoa don:");
        };
        DatPhong * dp = qlDp.loadDatPhong(ma_dp);
        hd->setDatPhong(dp);
        hd->nhap();
        hd->setSoTien(calculateTimeDiff(dp->getThoiGianDat(),dp->getThoiGianTra())*dp->getP()->getGiaPhong());
        hd->setTinhTrangThanhToan("Thanh cong");
        std::string taoHoaDonQuery;
        ss.str("");
        ss << "INSERT INTO hoa_don (ngay_lap,tinh_trang_thanh_toan,so_tien,ma_dat_phong) "
              "VALUES ("
           <<"'" << hd->getNgayLap() << "',"
           <<"'" << hd->getTinhTrangThanhToan() << "',"
           << hd->getSoTien()<< ","
           << hd->getDatPhong()->getMaDatPhong()
           << ")";
        taoHoaDonQuery = ss.str();
        db.queryToDatabase(taoHoaDonQuery);
        hd->hienThi();
        dp->setTinhTrangDatPhong("Da lap hoa don");
        dp->getP()->setTinhTrangPhong(1);
        qlDp.capNhatDatPhong(dp);
        qlDp.getQlP().capNhatPhong(dp->getP());
        delete hd;
        delete dp;
        danhSach();
        std::cout << "Tao hoa don thanh cong!"<< std::endl;
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

/**
 * Ham xoa hoa don
 */
void QLHoaDon::xoa() {
    danhSach();
    int so_hd = getNumber("Nhap so hoa don can xoa: ");
    while(!existHoaDon(so_hd)){
        cout << "Hoa don khong ton tai!"<< endl;
        so_hd = getNumber("Nhap so hoa don can xoa: ");
    }
    HoaDon *hd;
    hd = loadHoaDon(so_hd);
    cout << "Ban chac chan muon hoa don:\n";
    hd->hienThi();
    cout << "1. Xoa\n"
            "2. Huy\n";
    int choice = getNumber("Lua chon: ");
    switch (choice) {
        case 1:
            ss.str("");
            ss << "DELETE from hoa_don where so_hd=" << so_hd;
            db.queryToDatabase(ss.str(),"Xoa hoa don thanh cong!\n");
            danhSach();
            break;
        case 2:
            break;
    }
    delete hd;
}

/**
 * Ham sua hoa don
 */
void QLHoaDon::sua() {
    try{
        int choice;
        HoaDon* hd=new HoaDon();
        do {
            hd->hienThi();
            cout << "Chon truong muon sua:\n"
                    "1.Ngay lap\n"
                    "2.Tinh trang thanh toan\n"
                    "Lua chon khac:\n"
                    "3.Luu\n"
                    "4.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    hd->setNgayLap(getDate("Nhap ngay lap:"));
                    break;
                case 2:
                    hd->setTinhTrangThanhToan(getString("Nhap tinh trang thanh toan:", 50));
                    break;
                case 3:
                    capNhatHoaDon(hd);
                    delete hd;
                    break;
            }
        } while ( choice != 3 && choice !=4 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

/**
 * Hien thi danh sach hoa don
 */
void QLHoaDon::danhSach() {
    try {
        tabulate::Table hoaDonTable;
        cout << "DANH SACH HOA DON"<<endl;
        hoaDonTable.add_row({"So HD","Ngay lap","So Tien","Tinh trang thanh toan","Ma dat phong"});
        ss.str("");
        ss << "select * from hoa_don";
        std::string query = ss.str();
        MYSQL_RES* res = db.exec_query(query.c_str());
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            hoaDonTable.add_row({row[0], row[1],row[2],row[3],row[4]});
        }
        std::cout << hoaDonTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * Load hoá đơn từ database
 * @param soHD
 * @return
 */
HoaDon *QLHoaDon::loadHoaDon(int soHD) {
    HoaDon* hd = NULL;
    ss.str("");
    ss << "SELECT * FROM hoa_don WHERE so_hd=" << soHD;
    std::string query = ss.str();

    MYSQL_RES* res = db.exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);


    if (row != NULL) {
        hd = new HoaDon();
        hd->setSoHd(soHD);
        hd->setNgayLap(row[1]);
        hd->setSoTien(std::atoi(row[2]));
        hd->setTinhTrangThanhToan(row[3]);
        hd->setDatPhong(qlDp.loadDatPhong(std::atoi(row[4])));
    }

    mysql_free_result(res);
    return hd;
}

/**
 * Cap nhat hoa don vao database
 * @param hd
 */
void QLHoaDon::capNhatHoaDon(HoaDon *hd) {
    ss.str("");
    ss << "UPDATE hoa_don SET "
       << "ngay_lap = '" << hd->getNgayLap() << "', "
       << "so_tien = " << hd->getSoTien() <<","
            << "tinh_trang_thanh_toan = '" << hd->getTinhTrangThanhToan() << "', "
            << "ma_dat_phong = " << hd->getDatPhong()->getMaDatPhong()
            << " WHERE so_hd = " << hd->getSoHd() << ";";
    string updateHoaDonQuery = ss.str();
    db.queryToDatabase(updateHoaDonQuery,"Cap nhat thong tin hoa don thanh cong!\n");
}

bool QLHoaDon::existHoaDon(int so_HD) {
    ss.str("");
    ss << "Select so_hd from hoa_don where so_hd=" << so_HD;
    if(db.checkLength(ss.str())>0){
        return true;
    }
    return false;
}

/**
 * Xem 1 hoa don
 */
void QLHoaDon::xemHoaDon() {
    danhSach();
    int so_hd = getNumber("Nhap so hoa don can xem: ");
    while(!existHoaDon(so_hd)){
        cout << "Hoa don khong ton tai!"<< endl;
        so_hd = getNumber("Nhap so hoa don can xem: ");
    }
    HoaDon *hd;
    hd = loadHoaDon(so_hd);
    hd->hienThi();
}


