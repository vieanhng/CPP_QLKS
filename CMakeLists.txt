cmake_minimum_required(VERSION 3.24)
project(CPP_QLKS)

set(SRC_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB SRC_FILES ${SRC_FOLDER}/*.cpp  ${SRC_FOLDER}/*.h ${SRC_FOLDER}/*/*.h ${SRC_FOLDER}/*/*.cpp)


include_directories("tabulate-1.5\\include")
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


set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_QLKS ${SRC_FILES} src/Utils/Utils.cpp)


if(WIN32)
    target_link_libraries(CPP_QLKS libmysql)
elseif(APPLE)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libmysqlclient.a)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libmysqlservices.a)
    target_link_libraries (CPP_QLKS ${MYSQL_LIB}/libssl.1.1.dylib)
    target_link_libraries(CPP_QLKS ${MYSQL_LIB}/libcrypto.1.1.dylib)
endif()


