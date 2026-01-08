# High-Performance Backup & Deduplication Engine (C++)

## Features
- Directory scanning using std::filesystem
- Fixed-size chunking (4MB)
- SHA-256 based deduplication
- Multithreaded chunk processing
- Memory-mapped file I/O
- Compression using zlib
- Snapshot-based restore

## Build
```bash
mkdir build && cd build
cmake ..
make
```

## Run
```bash
./backup_engine <directory_to_backup>
```
