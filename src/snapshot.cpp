#include "snapshot.h"
#include <fstream>

void Snapshot::add(const std::string& file, const std::string& chunk) {
    files[file].push_back(chunk);
}

void Snapshot::save(const std::string& path) {
    std::ofstream out(path);
    for (auto& [file, chunks] : files) {
        out << file << "\n";
        for (auto& c : chunks) out << "  " << c << "\n";
    }
}
