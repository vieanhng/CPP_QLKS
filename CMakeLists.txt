cmake_minimum_required(VERSION 3.24)
project(CPP_QLKS)

if(WIN32)
    include_directories("mysql\\include")
    link_directories("mysql\\lib")
    link_libraries(libmysql)
elseif(APPLE)
    set(MYSOL_HEADER /usr/local/mysql/include)
    set(MYSQL_LIB /usr/local/mysql/lib)

    include_directories(${MYSOL_HEADER})
    link_libraries(${MYSQL_LIB})
endif()
set(MYSOL_HEADER /usr/local/mysql/include)
set(MYSQL_LIB /usr/local/mysql/lib)

include_directories(${MYSOL_HEADER})
link_libraries(${MYSQL_LIB})

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_QLKS main.cpp)

if(WIN32)
    target_link_libraries(CPP_QLKS libmysql)
elseif(APPLE)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libmysqlclient.a)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libmysqlservices.a)
    target_link_libraries (CPP_QLKS ${MYSQL_LIB}/libssl.1.1.dylib)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libcrypto.1.1.dylib)
endif()
