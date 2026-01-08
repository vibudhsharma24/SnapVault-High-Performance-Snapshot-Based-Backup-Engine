#include "storage.h"
#include "hasher.h"
#include <filesystem>
#include <fstream>

Storage::Storage(const std::string& base) : base_dir(base) {
    std::filesystem::create_directories(base_dir);
}

std::string Storage::store_chunk(const std::string& data) {
    auto hash = sha256(data);
    if (index.insert(hash).second) {
        std::ofstream out(base_dir + "/" + hash, std::ios::binary);
        out.write(data.data(), data.size());
    }
    return hash;
}
