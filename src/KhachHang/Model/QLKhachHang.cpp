//
// Created by Andy Nguyen on 03/04/2023.
//

#include "QLKhachHang.h"

void QLKhachHang::taoKhachHang() {
    try
    {
        KhachHang* khachhang = new KhachHang;
        khachhang->nhap();
        khachhang->hienThiThongTin();
        std::string taoKhachHangQuery;
        ss << "INSERT INTO khach_hang(ten_KH,dia_chi,sdt,email) "
              "VALUES ("
           << "'" << khachhang->getTenKh() << "',"
                << "'"<< khachhang->getDiaChi()<< "'" << ","
                << "'"<< khachhang->getSdt()<< "'" << ","
                << "'"<< khachhang->getEmail()<< "'"
           << ")";
        taoKhachHangQuery = ss.str();
        queryToDatabase(taoKhachHangQuery);
        delete khachhang;
        dsKhachHang();
        cout << "Tao thong tin khach hang thanh cong!";
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

void QLKhachHang::xoaKhachHang() {
    dsKhachHang();
    int khach_hang_can_xoa = getNumber("Nhap ma khach hang can xoa: ");
    KhachHang *kh;
    kh = loadKhachHang(khach_hang_can_xoa);
    cout << "Ban chac chan muon xoa khach hang:\n";
    kh->hienThiThongTin();
    cout << "1. Xoa\n"
            "2. Huy\n";
    int choice = getNumber("Lua chon: ");
    switch (choice) {
        case 1:
            ss.str("");
            ss << "DELETE from khach_hang where ma_kh=" << khach_hang_can_xoa;
            queryToDatabase(ss.str(),"Xoa khach hang thanh cong!\n");
            dsKhachHang();
            break;
        case 2:
            break;
    }
    delete &kh;
}

void QLKhachHang::suaKhachHang() {
    try{
        int choice;
        dsKhachHang();
        int khach_hang_can_sua = getNumber("Nhap ma khach hang can sua: ");
        while(!existKhachHang(khach_hang_can_sua)){
            khach_hang_can_sua = getNumber("Sai ma phong! Vui long nhap lai: ");
        }
        KhachHang* kh;
        kh = loadKhachHang(khach_hang_can_sua);
        do {
            kh->hienThiThongTin();
            cout << "Chon truong muon sua:\n"
                    "1.Ten khach hang\n"
                    "2.Dia chi\n"
                    "3.So dien thoai\n"
                    "4.Email\n"
                    "Lua chon khac:\n"
                    "5.Luu\n"
                    "6.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    kh->setTenKh(getString("Nhap ten khach hang: ", 20));
                    break;
                case 2:
                    kh->setDiaChi(getString("Nhap dia chi khach hang: ", 100));
                    break;
                case 3:
                    kh->setSdt(getString("Nhap so dien thoai khach hang: ",20));
                    break;
                case 4:
                    kh->setEmail(getString("Nhap email khach hang: ",100));
                    break;
                case 5:
                    capNhatKhachHang(kh);
                    delete kh;
                    break;
            }
        } while ( choice != 6 && choice !=5 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}




void QLKhachHang::dsKhachHang() {
    try {
        tabulate::Table khachhangTable;
        cout << "DANH SACH KHACH HANG"<<endl;
        khachhangTable.add_row({"ma khach hang","ten khach hang","dia chi","so dien thoai","email"});
        ss.str("");
        ss << "select * from khach_hang";
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
void QLKhachHang::capNhatKhachHang(KhachHang *kh) {
    ss.str("");
    ss << "UPDATE khach_hang SET ten_kh = '" << kh->getTenKh() << "', "
       << "dia_chi = '" << kh->getDiaChi() << "', "
       << "so_dien_thoai = '" << kh->getSdt() << "', "
       << "email = '" << kh->getEmail() << "' "
       << "WHERE ma_kh = " << kh->getMaKh() << ";";
    string updateKhachHangQuery = ss.str();
    queryToDatabase(updateKhachHangQuery,"Cap nhat thong tin khach hang thanh cong!");
}
bool QLKhachHang::existKhachHang(int ma_kh) {
    ss.str("");
    ss << "Select ma_kh from khach_hang where ma_kh=" << ma_kh;
    if(checkLength(ss.str())>0){
        return true;
    }

    return false;
}
