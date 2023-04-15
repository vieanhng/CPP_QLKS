//
// Created by Andy Nguyen on 15/04/2023.
//

#include "Menu.h"

Menu::Menu() {
    int choice;
    QLDatPhong * qlDatPhong = new QLDatPhong();
    do {
        // Display the menu with a border
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(11) << " " << "MENU QL KHACH SAN" << setfill(' ') << setw(11) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Dat Phong" << endl;
        cout << "\t2. QL Khach San" << endl;
        cout << "\t3. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        cout << "Lua Chon: ";
        cin >> choice;

        switch(choice) {
            case 1:
                qlDatPhong->taoDatPhong();
                break;
            case 2:
                this->menuQLKhachSan();
                break;
            case 3:
                cout << "Dang thoat chuong trinh..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    delete qlDatPhong;
    ::exit(0);
}

Menu::~Menu() {

}

void Menu::menuPhong() {
    int choice;
    QLPhong *qlPhong = new QLPhong;
    do {
        // Display the menu with a border
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(12) << " " << "MENU QL TT PHONG" << setfill(' ') << setw(12) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Tao Phong" << endl;
        cout << "\t2. Sua Phong" << endl;
        cout << "\t3. Xoa Phong" << endl;
        cout << "\t4. Xem Danh Sach Phong" << endl;
        cout << "\t5. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon");


        switch (choice) {
            case 1:
                qlPhong->taoPhong();
                break;
            case 2:
                qlPhong->suaPhong();
                break;
            case 3:
                qlPhong->xoaPhong();
            case 4:
                int tinh_trang_phong;
                std::string where;
                do {
                    std::cout << "Xem danh sach phong: ";
                    std::cout << "1. Phong trong" << std::endl;
                    std::cout << "2. Phong da dat" << std::endl;
                    std::cout << "3. Thoat" << std::endl;
                    tinh_trang_phong = getNumber("Nhap tinh trang phong muon hien thi: ");
                    if (tinh_trang_phong == 1) {
                        where = "tinh_trang_phong = 1";
                    }        else{
                        where = "tinh_trang_phong = 0";
                    }

                    qlPhong->danhSachPhong(where);
                }while(tinh_trang_phong!=3);
                break;

        }
    }while(choice != 5);
    delete qlPhong;
}

void Menu::menuHoaDon() {
    int choice;
    QLHoaDon * qlHoaDon = new QLHoaDon();

    do {
        // Display the menu with a border
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(11) << " " << "MENU QL TT HOA DON" << setfill(' ') << setw(10) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Tao hoa don" << endl;
        cout << "\t2. Xem hoa don" << endl;
        cout << "\t3. Sua hoa don" << endl;
        cout << "\t4. Xoa hoa don" << endl;
        cout << "\t5. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon:");

        switch(choice) {
            case 1:
                qlHoaDon->taoHoaDon();
                break;
            case 2:
                qlHoaDon->xemHoaDon();
                break;
            case 3:
                qlHoaDon->suaHoaDon();
                break;
            case 4:
                qlHoaDon->xoaHoaDon();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    delete qlHoaDon;
}

void Menu::menuTtKhachSan() {
    int choice;
    QLKhachSan * qlKhachSan = new QLKhachSan();

    do {
        // Display the menu with a border
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(10) << " " << "MENU QL TT KHACH SAN" << setfill(' ') << setw(10) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Sua thong tin khach san" << endl;
        cout << "\t2. Xem thong tin khach san" << endl;
        cout << "\t3. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon:");

        switch(choice) {
            case 1:
                qlKhachSan->suaKhachSan();
                break;
            case 2:
                qlKhachSan->getKhachSan().hienThiThongTin();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    delete qlKhachSan;
}

void Menu::menuKhachHang() {
    int choice;
    QLKhachHang * qlKhachHang = new QLKhachHang();

    do {
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(9) << " " << "MENU QL TT KHACH HANG" << setfill(' ') << setw(9) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Them khach hang" << endl;
        cout << "\t2. Sua khach hang" << endl;
        cout << "\t3. Xoa khach hang" << endl;
        cout << "\t4. Danh sach khach hang" << endl;
        cout << "\t5. Xem TT khach hang" << endl;
        cout << "\t6. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon:");

        switch(choice) {
            case 1:
                qlKhachHang->taoKhachHang();
                break;
            case 2:
                qlKhachHang->suaKhachHang();
                break;
            case 3:
                qlKhachHang->xoaKhachHang();
                break;
            case 4:
                qlKhachHang->dsKhachHang();
                break;
            case 5:
                qlKhachHang->xemKhachHang();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    delete qlKhachHang;
}

void Menu::menuDatPhong() {
    int choice;
    QLDatPhong * qlDatPhong = new QLDatPhong();

    do {
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(10) << " " << "MENU QL TT DAT PHONG" << setfill(' ') << setw(10) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. Dat Phong" << endl;
        cout << "\t2. Sua TT Dat Phong" << endl;
        cout << "\t3. Huy Dat Phong" << endl;
        cout << "\t4. DS Dat Phong" << endl;
        cout << "\t5. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon:");

        switch(choice) {
            case 1:
                qlDatPhong->taoDatPhong();
                break;
            case 2:
                qlDatPhong->suaDatPhong();
                break;
            case 3:
               qlDatPhong->xoaDatPhong();
                break;
            case 4:
                qlDatPhong->dsDatPhong();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    delete qlDatPhong;
}

void Menu::menuQLKhachSan() {
    int choice;
    do {
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "|" << setfill(' ') << setw(11) << " " << "MENU QL KHACH SAN" << setfill(' ') << setw(11) << "|" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "\t1. QL PHONG" << endl;
        cout << "\t2. QL KHACH HANG" << endl;
        cout << "\t3. QL DAT PHONG" << endl;
        cout << "\t4. QL HOA DON" << endl;
        cout << "\t5. QL TT KHACH SAN" << endl;
        cout << "\t6. Thoat" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;

        choice = getNumber("Lua chon:");

        switch(choice) {
            case 1:
               this->menuPhong();
                break;
            case 2:
                this->menuKhachHang();
                break;
            case 3:
                this->menuDatPhong();
                break;
            case 4:
                this->menuHoaDon();
                break;
            case 5:
                this->menuTtKhachSan();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}
