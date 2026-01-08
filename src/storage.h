#pragma once
#include <string>
#include <unordered_set>

class Storage {
public:
    Storage(const std::string& base);
    std::string store_chunk(const std::string& data);
private:
    std::string base_dir;
    std::unordered_set<std::string> index;
};
