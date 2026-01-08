#include "chunker.h"
#include <fstream>

static const size_t CHUNK_SIZE = 4 * 1024 * 1024;

std::vector<std::string> chunk_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    std::vector<std::string> chunks;
    while (!file.eof()) {
        std::string buffer(CHUNK_SIZE, '\0');
        file.read(buffer.data(), CHUNK_SIZE);
        buffer.resize(file.gcount());
        if (!buffer.empty()) chunks.push_back(buffer);
    }
    return chunks;
}
