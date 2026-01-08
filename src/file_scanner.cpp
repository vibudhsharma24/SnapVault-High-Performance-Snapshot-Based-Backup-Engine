#include "file_scanner.h"
#include "chunker.h"
#include <filesystem>

void scan_directory(const std::string& path, ThreadPool& pool, Storage& storage, Snapshot& snapshot) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;
        auto filepath = entry.path().string();
        pool.enqueue([filepath, &storage, &snapshot]() {
            auto chunks = chunk_file(filepath);
            for (auto& chunk : chunks) {
                auto hash = storage.store_chunk(chunk);
                snapshot.add(filepath, hash);
            }
        });
    }
}
