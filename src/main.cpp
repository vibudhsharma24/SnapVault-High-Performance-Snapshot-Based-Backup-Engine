#include "file_scanner.h"
#include "thread_pool.h"
#include "storage.h"
#include "snapshot.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: backup_engine <directory>\n";
        return 1;
    }

    ThreadPool pool(std::thread::hardware_concurrency());
    Storage storage("storage");
    Snapshot snapshot;

    scan_directory(argv[1], pool, storage, snapshot);

    snapshot.save("storage/snapshot.json");
    std::cout << "Backup completed successfully.\n";
    return 0;
}
