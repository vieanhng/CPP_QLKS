//
// Created by HP on 11/4/2023.
//

#include "QLHoaDon.h"


void QLHoaDon::taoHoaDon() {
    try
    {
        HoaDon* hd = new HoaDon;
        hd->nhap();
        hd->hienThiThongTin();
        std::string taoHoaDonQuery;
        ss.str("");
        ss << "INSERT INTO hoa_don(so_hd,ngay_lap,so_tien,tinh_trang_thanh_toan,ma_dat_phong) "
              "VALUES ("
           << "'" << hd->getSoHd() << "',"
           << hd->getNgayLap() << ","
           << hd->getTinhTrangThanhToan() << ","
           << hd->getSoTien()<< ","
           << hd->getDatPhong()<< ","
           << ")";
        taoHoaDonQuery = ss.str();
        db.queryToDatabase(taoHoaDonQuery);
        delete hd;
        dsHoaDon();
        std::cout << "Tao phong thanh cong!";
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

void QLHoaDon::xoaHoaDon() {

}

void QLHoaDon::suaHoaDon() {
    try{
        int choice;
        HoaDon* hd=new HoaDon();
        do {
            hd->hienThiThongTin();
            cout << "Chon truong muon sua:\n"
                    "1.So hoa don\n"
                    "2.Ngay lap\n"
                    "3.Tinh trang thanh toan\n"
                    "4.So tien\n"
                    "Lua chon khac:\n"
                    "5.Luu\n"
                    "6.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    hd->setSoHd(getNumber("Nhap so hoa don: "));
                    break;
                case 2:
                    hd->setNgayLap(getDate("Nhap ngay lap:"));
                    break;
                case 3:
                    hd->setTinhTrangThanhToan(getNumber("Nhap tinh trang thanh toan (1:Xong,0:Chua): "));
                    break;
                case 4:
                    hd->setSoTien(getNumber("Nhap so tien"));
                    break;
                case 5:
                    capNhatHoaDon(hd);
                    delete hd;
                    break;
            }
        } while ( choice != 6 && choice !=5 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}


void QLHoaDon::dsHoaDon() {

}

HoaDon *QLHoaDon::loadHoaDon(int soHD) {

}

void QLHoaDon::capNhatHoaDon(HoaDon *hd) {

}

bool QLHoaDon::existHoaDon(int so_HD) {

}

void QLHoaDon::xemHoaDon() {

}
