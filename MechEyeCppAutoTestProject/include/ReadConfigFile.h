#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <json/json.h>

class ReadJson 
{
public:
    ReadJson(const std::string& path);    
    std::string getJsonValue(const std::string& key);
    std::string getJsonValue(const std::string& key, const int& index, const std::string& childKey);

private:
    std::ifstream inff;
    Json::Value root;
    Json::Reader reader;
    Json::Value::Members members;
};