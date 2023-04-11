//
// Created by Andy Nguyen on 31/03/2023.
//

#ifndef CPP_QLKS_QLBASE_H
#define CPP_QLKS_QLBASE_H
#include "../Database/Database.h"
#include "sstream"
#include "../Utils/Utils.h"
#include <iostream>



class QLBase {
protected:
    std::stringstream ss;
    Database db;
public:
    virtual void tao();
    virtual void load();
    virtual void danhSach();
};


#endif //CPP_QLKS_QLBASE_H
