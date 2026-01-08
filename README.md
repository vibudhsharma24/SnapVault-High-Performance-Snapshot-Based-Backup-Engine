# SnapVault – High-Performance Snapshot-Based Backup Engine (C++)

SnapVault is a high-performance, snapshot-based backup and deduplication engine written in modern C++.
It demonstrates core storage-system concepts such as chunk-based data layout, cryptographic deduplication, multithreaded ingestion, and snapshot metadata management.

---

## 🚀 Features

* **Directory-based backup** using `std::filesystem`
* **Fixed-size chunking** for efficient storage layout
* **SHA-256 based deduplication** to eliminate redundant data
* **Multithreaded ingestion pipeline** using a custom thread pool
* **Snapshot metadata generation** for versioned backups
* **Modular C++17 design** for extensibility and maintainability

---

## 🗂 Project Structure

```
backup_engine/
├── CMakeLists.txt          # Build configuration
├── README.md               # Project documentation
├── src/
│   ├── main.cpp            # Entry point
│   ├── thread_pool.h/.cpp  # Custom thread pool implementation
│   ├── file_scanner.h/.cpp # Recursive directory scanning
│   ├── chunker.h/.cpp      # File chunking logic (4MB chunks)
│   ├── hasher.h/.cpp       # SHA-256 hashing for deduplication
│   ├── storage.h/.cpp      # Chunk storage and dedup index
│   ├── snapshot.h/.cpp     # Snapshot metadata management
│   └── restore.cpp         # Restore logic (extendable)
```

---

## ⚙️ Build Instructions

### Prerequisites

* Linux
* CMake ≥ 3.10
* C++17 compatible compiler (g++ / clang++)
* OpenSSL (for SHA-256)
* zlib

### Build

```bash
git clone <your-repo-url>
cd backup_engine
mkdir build && cd build
cmake ..
make
```

---

## ▶️ Running the Backup Engine

```bash
./backup_engine <directory_to_backup>
```

### Example

```bash
./backup_engine /home/user/documents
```

This will:

* Recursively scan the directory
* Split files into chunks
* Deduplicate chunks using SHA-256
* Store unique chunks on disk
* Generate snapshot metadata for restore

---

## 🧠 How It Works (High Level)

1. **Directory Scanner**
   Recursively identifies regular files using `std::filesystem`.

2. **Chunking Engine**
   Files are split into fixed-size chunks (4MB) to enable efficient storage and reuse.

3. **Deduplication**
   Each chunk is hashed using SHA-256. Identical chunks are stored only once.

4. **Multithreaded Processing**
   Chunk processing is parallelized using a custom thread pool to maximize throughput.

5. **Snapshot Metadata**
   Metadata maps files to chunk hashes, enabling accurate restores and incremental backups.

---

## 🔮 Future Enhancements

* Memory-mapped (mmap) zero-copy file I/O
* Compression using zstd
* Content-defined chunking (Rabin fingerprinting)
* Crash-safe metadata journaling
* Incremental and differential backups
* Distributed replication

---

