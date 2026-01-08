#pragma once
#include <string>
#include "thread_pool.h"
#include "storage.h"
#include "snapshot.h"

void scan_directory(const std::string& path, ThreadPool& pool, Storage& storage, Snapshot& snapshot);
