#include <string>
#include "ReadConfigFile.h"

ReadJson::ReadJson(const std::string& path):inff(path, std::ios::binary){
    if (!inff.is_open() || !this->reader.parse(inff, this->root))
        std::cout << "Error opening <<" << path << "json file! " << std::endl;
}

// key: value
std::string ReadJson::getJsonValue(const std::string& key){
    this->members = this->root.getMemberNames();
    return this->root[key].asString();
}

// key:[{key1: value1, ....}]
std::string ReadJson::getJsonValue(const std::string& key, const int& index, const std::string& childKey) {
    this->members = this->root.getMemberNames();
    return this->root[key][index][childKey].asString();
}
