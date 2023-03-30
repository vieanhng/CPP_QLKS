//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Phong.h"


int Phong::getMaPhong() const {
    return ma_phong;
}

void Phong::setMaPhong(int maPhong) {
    ma_phong = maPhong;
}

const string &Phong::getLoaiPhong() const {
    return loai_phong;
}

void Phong::setLoaiPhong(const string &loaiPhong) {
    this->loai_phong = loaiPhong;
}

int Phong::getSoPhong() const {
    return so_phong;
}

void Phong::setSoPhong(int soPhong) {
    this->so_phong = soPhong;
}

int Phong::getGiaPhong() const {
    return gia_phong;
}

void Phong::setGiaPhong(int giaPhong) {
    this->gia_phong = giaPhong;
}

std::string Phong::getTinhTrangPhong() const {
    switch (tinh_trang_phong) {
        case 0:
            return "Het";
            break;
        case 1:
            return "Con";
            break;
        default:
            return "-";
    }
}

std::string Phong::getTinhTrangPhong(int tinh_trang) const {
    switch (tinh_trang) {
        case 0:
            return "Het";
            break;
        case 1:
            return "Con";
            break;
        default:
            return "-";
    }
}

void Phong::setTinhTrangPhong(int tinhTrangPhong) {
    this->tinh_trang_phong = tinhTrangPhong;
}

bool Phong::taoPhong() {
    try
    {
        string _loai_phong = getString("Nhap loai phong: ", 20);
        int _so_phong = getNumber("Nhap so phong: ");
        int _gia_phong = getNumber("Nhap gia phong: ");
        int _tinh_trang_phong = getNumber("Nhap tinh trang phong (1:Con, 0:Het): ");

        std::cout << "\nDo you want to save the book.\n";
        std::string createBookQuery;
        ss << "INSERT INTO phong(loai_phong,so_phong,gia_phong,tinh_trang_phong) "
              "VALUES ("
              << "'" << _loai_phong << "',"
              << _so_phong << ","
              << _gia_phong << ","
               << _tinh_trang_phong
              << ")";
        createBookQuery = ss.str();
        queryToDatabase(createBookQuery, "Tao phong thanh cong!");
    }
    catch (const char* msg)
    {
        std::cout << msg << '\n';
        return false;
    }
}

void Phong::showFullTable() {
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
            phongTable.add_row({row[0], row[1],row[2],row[3], getTinhTrangPhong(std::atoi(row[4]))});
        }
        std::cout << phongTable << std::endl;
        mysql_free_result(res);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

void Phong::suaPhong() {
    try{
            showFullTable();
            setMaPhong(getNumber("Nhap ma phong can sua: "));
            system("clear");
            loadPhong(ma_phong);
        int choice;
        do {
            hienThiThongTin();
            cout << "Chon truong muon sua:\n"
                    "1.Loai phong\n"
                    "2.So phong\n"
                    "3.Gia phong\n"
                    "4.Tinh trang phong\n"
                    "5.Luu\n"
                    "6.Thoat";
             choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    setLoaiPhong(getString("Nhap loai phong: ", 20));
                    break;
                case 2:
                    setSoPhong(getNumber("Nhap so phong: "));
                    break;
                case 3:
                    setGiaPhong(getNumber("Nhap gia phong: "));
                    break;
                case 4:
                    setTinhTrangPhong(getNumber("Nhap tinh trang phong (1:Con,0:Het): "));
                    break;
                case 5:
                    ss.str("");
                    ss << "UPDATE phong SET loai_phong = '" << loai_phong << "', "
                       << "so_phong = " << so_phong << ", "
                       << "gia_phong = " << gia_phong << ", "
                       << "tinh_trang_phong = " << tinh_trang_phong << " "
                       << "WHERE ma_phong = " << ma_phong << ";";
                    string updatePhongQuery = ss.str();
                    queryToDatabase(updatePhongQuery,"Cap nhat phong thanh cong!");
                    break;
            }
        } while ( choice != 6);
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

void Phong::hienThiThongTin() {
    std::cout << "Thong tin phong:";
    std::cout << "\n====================================\n";
    std::cout << "Ma phong: " << getMaPhong();
    std::cout << "\nLoai phong: " << getLoaiPhong();
    std::cout << "\nSo phong: " << getSoPhong();
    std::cout << "\nGia phong: " << getGiaPhong();
    std::cout << "\nTinh trang phong: " << getTinhTrangPhong();
    std::cout << "\n====================================\n";
}

void Phong::xoaPhong() {
        showFullTable();
        int phong_can_xoa = getNumber("Nhap ma phong can xoa: ");
    loadPhong(phong_can_xoa);
    cout << "Ban chac chan muon xoa phong:\n";
    hienThiThongTin();
    cout << "1. Xoa\n"
            "2. Huy\n";
    int choice = getNumber("Lua chon: ");
    switch (choice) {
        case 1:
            ss.str("");
            ss << "DELETE from phong where ma_phong=" << phong_can_xoa;
            queryToDatabase(ss.str().c_str(),"Xoa phong thanh cong!\n");
            showFullTable();
            break;
        case 2:
            break;
    }
}

void Phong::loadPhong(int maPhong) {
    ss.str("");
    ss << "select * from phong where ma_phong="<< maPhong;
    std::string query = ss.str();
    MYSQL_RES* res = exec_query(query.c_str());
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(res))) {
            setMaPhong(maPhong);
            setLoaiPhong(row[1]);
            setSoPhong(std::atoi(row[2]));
            setGiaPhong(std::atoi(row[3]));
            setTinhTrangPhong(std::atoi(row[4]));
        std::cout << std::endl;
    } else {
        std::cout << "Phong khong ton tai trong co so du lieu.\n";
    }
    mysql_free_result(res);
}
