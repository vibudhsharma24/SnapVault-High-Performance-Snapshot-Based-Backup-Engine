#pragma once
#include <unordered_map>
#include <vector>
#include <string>

class Snapshot {
public:
    void add(const std::string& file, const std::string& chunk);
    void save(const std::string& path);
private:
    std::unordered_map<std::string, std::vector<std::string>> files;
};
