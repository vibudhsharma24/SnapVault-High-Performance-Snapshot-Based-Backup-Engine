cmake_minimum_required(VERSION 3.10)
project(backup_engine)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(backup_engine
    src/main.cpp
    src/thread_pool.cpp
    src/file_scanner.cpp
    src/chunker.cpp
    src/hasher.cpp
    src/storage.cpp
    src/snapshot.cpp
    src/restore.cpp
)

target_link_libraries(backup_engine OpenSSL::Crypto ZLIB::ZLIB)
