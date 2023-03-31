//
// Created by Andy Nguyen on 31/03/2023.
//

#ifndef CPP_QLKS_QLBASE_H
#define CPP_QLKS_QLBASE_H
#include "../Database/Database.h"
#include "sstream"
#include "../Utils/Utils.h"


class QLBase : public Database{
protected:
    std::stringstream ss;
};


#endif //CPP_QLKS_QLBASE_H
