//
// Created by Andy Nguyen on 31/03/2023.
//

#include "QLPhong.h"


bool QLPhong::taoPhong() {
    try
    {
        Phong* room = new Phong;
        room->nhap();
        room->hienThiThongTin();
        std::string taoPhongQuery;
        ss.str("");
        ss << "INSERT INTO phong(loai_phong,so_phong,gia_phong,tinh_trang_phong) "
              "VALUES ("
           << "'" << room->getLoaiPhong() << "',"
           << room->getSoPhong() << ","
           << room->getGiaPhong() << ","
           << room->getTinhTrangPhong()
           << ")";
        taoPhongQuery = ss.str();
        db.queryToDatabase(taoPhongQuery);
        delete room;
        danhSachPhong();
        std::cout << "Tao phong thanh cong!";
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
        return false;
    }
    return true;
}

void QLPhong::xoaPhong() {
    danhSachPhong();
    int phong_can_xoa = getNumber("Nhap ma phong can xoa: ");
    Phong *p;
    p = loadPhong(phong_can_xoa);
    cout << "Ban chac chan muon xoa phong:\n";
    p->hienThiThongTin();
    cout << "1. Xoa\n"
            "2. Huy\n";
    int choice = getNumber("Lua chon: ");
    switch (choice) {
        case 1:
            ss.str("");
            ss << "DELETE from phong where ma_phong=" << phong_can_xoa;
            db.queryToDatabase(ss.str(),"Xoa phong thanh cong!\n");
            danhSachPhong();
            break;
        case 2:
            break;
    }
    delete p;
}

void QLPhong::suaPhong() {
    try{
        int choice;
        danhSachPhong();
        int phong_can_sua = getNumber("Nhap ma phong can sua: ");
        while(!existPhong(phong_can_sua)){
            phong_can_sua = getNumber("Sai ma phong! Vui long nhap lai: ");
        }
        Phong* p;
        p = loadPhong(phong_can_sua);
        do {
            p->hienThiThongTin();
            cout << "Chon truong muon sua:\n"
                    "1.Loai phong\n"
                    "2.So phong\n"
                    "3.Gia phong\n"
                    "4.Tinh trang phong\n"
                    "Lua chon khac:\n"
                    "5.Luu\n"
                    "6.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    p->setLoaiPhong(getString("Nhap loai phong: ", 20));
                    break;
                case 2:
                    p->setSoPhong(getNumber("Nhap so phong: "));
                    break;
                case 3:
                    p->setGiaPhong(getNumber("Nhap gia phong: "));
                    break;
                case 4:
                    p->setTinhTrangPhong(getNumber("Nhap tinh trang phong (1:Con,0:Het): "));
                    break;
                case 5:
                    capNhatPhong(p);
                    delete p;
                    break;
            }
        } while ( choice != 6 && choice !=5 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

Phong* QLPhong::loadPhong(int maPhong) {
    Phong* room = NULL;
    ss.str("");
    ss << "SELECT * FROM phong WHERE ma_phong= " << maPhong;
    std::string query = ss.str();

    MYSQL_RES* res = db.exec_query(query.c_str());
    MYSQL_ROW row = mysql_fetch_row(res);

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


void QLPhong::danhSachPhong(std::string where){
    try {
        tabulate::Table phongTable;
        cout << "DANH SACH PHONG"<<endl;
        phongTable.add_row({"ma_phong","loai_phong","so_phong","gia_phong","tinh_trang_phong"});
        ss.str("");
        ss << "select * from phong";
        if(where != ""){
            ss << " where " << where;
        };
        std::string query = ss.str();
        MYSQL_RES* res = db.exec_query(query.c_str());
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

void QLPhong::capNhatPhong(Phong* p){
    ss.str("");
    ss << "UPDATE phong SET loai_phong = '" << p->getLoaiPhong() << "', "
       << "so_phong = " << p->getSoPhong() << ", "
       << "gia_phong = " << p->getGiaPhong() << ", "
       << "tinh_trang_phong = " << p->getTinhTrangPhong() << " "
       << "WHERE ma_phong = " << p->getMaPhong() << ";";
    string updatePhongQuery = ss.str();
    db.queryToDatabase(updatePhongQuery,"Cap nhat phong thanh cong!");
}

bool QLPhong::existPhong(int ma_phong, string filter) {
    ss.str("");
    ss << "Select ma_phong from phong where ma_phong=" << ma_phong;
    if(filter!=""){
        ss << " and " << filter;
    }
    if(db.checkLength(ss.str())>0){
        return true;
    }

    return false;
}