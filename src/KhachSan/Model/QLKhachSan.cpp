//
// Created by Andy Nguyen on 03/04/2023.
//

#include "QLKhachSan.h"

void QLKhachSan::suaKhachSan() {
    try{
        int choice;
        KhachSan* x=new KhachSan();
        do {
            x->hienThiThongTin();
            cout << "Chon truong muon sua:\n"
                    "1.Ten khach san\n"
                    "2.Dia chi\n"
                    "3.Email\n"
                    "4.So dien thoai\n"
                    "Lua chon khac:\n"
                    "5.Luu\n"
                    "6.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    x->setTenKs(getString("Nhap ten khach san: ",40));
                    break;
                case 2:
                    x->setEmail(getString("Nhap email: ",20));
                    break;
                case 3:
                    x->setSdt(getString("Nhap so dien thoai: ",10));
                    break;
                case 4:
                    x->setDiaChi(getString("Nhap dia chi: ",100));
                    break;
                case 5:
                    capNhatThongTin(x);
                    delete x;
                    break;
            }
        } while ( choice != 6 && choice !=5 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

void QLKhachSan::capNhatThongTin(KhachSan* x) {
    ss.str("");
    ss << "UPDATE khach_san SET ten_ks = '" << x->getTenKs() << "', "
       << "dia_chi = '" << x->getDiaChi() << "', "
       << "sdt = '" << x->getSdt() << "', "
       << "email = '" << x->getEmail() << "' ";
    string updateKhachSanQuery = ss.str();
    db.queryToDatabase(updateKhachSanQuery,"Cap nhat khach san thanh cong!");
}

KhachSan QLKhachSan::getKhachSan() {
    return khachSan;
}
