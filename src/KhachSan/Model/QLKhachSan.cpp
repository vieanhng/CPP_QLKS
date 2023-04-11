//
// Created by Andy Nguyen on 03/04/2023.
//

#include "QLKhachSan.h"

void QLKhachSan::suaKhachSan() {
    try{
        int choice;
        danhSachKhachSan();
        int KhachSan_can_sua = getNumber("Nhap ma khach san can sua: ");
        while(!existKhachSan(KhachSan_can_sua)){
            KhachSan_can_sua = getNumber("Sai ma khach san! Vui long nhap lai: ");
        }
        KhachSan* x;
        x = loadKhachSan(KhachSan_can_sua);
        do {
            x->hienthithongtin();
            cout << "Chon truong muon sua:\n"
                    "1.Ma khach san\n"
                    "2.Ten khach san\n"
                    "3.Dia chi\n"
                    "4.Email\n"
                    "5.So dien thoai\n"
                    "Lua chon khac:\n"
                    "5.Luu\n"
                    "6.Thoat\n";
            choice = getNumber("Lua chon: ");
            switch (choice) {
                case 1:
                    x->setMaKs(getNumber("Nhap ma khach san: "));
                    break;
                case 2:
                    x->setTenKs(getString("Nhap ten khach san: ",40));
                    break;
                case 3:
                    x->setEmail(getString("Nhap email: ",20));
                    break;
                case 4:
                    x->setSdt(getString("Nhap so dien thoai: ",10));
                    break;
                case 5:
                    x->setDiaChi(getString("Nhap dia chi: ",100));
                    break;
                case 6:
                    capNhatThongTin(x);
                    delete x;
                    break;
            }
        } while ( choice != 7 && choice !=6 );
    } catch (const char* msg)
    {
        std::cout << msg << '\n';
    }
}

void QLKhachSan::capNhatThongTin(KhachSan* x) {
//    KhachSan *x= new KhachSan;
    ss.str("");
    ss << "UPDATE thongtin SET ten_ks = '" << x->getTenKs() << "', "
       << "dia_chi = " << x->getDiaChi() << ", "
       << "ma_ks = " << x->getMaKs()<<", "
       << "sdt = " << x->getSdt() << ", "
       << "email = " << x->getEmail() << " ";
    string updateThongtinQuery = ss.str();
    db.queryToDatabase(updateThongtinQuery,"Cap nhat phong thanh cong!");
}

bool QLKhachSan::existKhachSan(int ma_ks) {
    ss.str("");
    ss << "Select ma_ks from KhachSan where ma_ks=" << ma_ks;
    if(db.checkLength(ss.str())>0){
        return true;
    }

    return false;}