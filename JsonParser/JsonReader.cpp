//
// Created by Thomas on 2018-01-28.
//


#include "JsonReader.h"


std::vector<double> JsonReader::parseData(std::string data) {
    std::vector<double> parsedData = {};
    const char *json = data.c_str();
    rapidjson::Document document;
    document.Parse(json);

    try {
        assert(document.HasMember("module"));
        assert(document["module"].IsString());

        parsedData.push_back(atof(document["module"].GetString()));
        for (rapidjson::SizeType i = 1; i < document.Size(); i++) {
            parsedData.push_back(atof(document[i].GetString()));
        }

        return parsedData;
    } catch (...) {
        std::cout << "Bad data provided!";
    }
}

std::string JsonReader::parseAction(std::string data) {
    const char *json = data.c_str();
    rapidjson::Document document;
    document.Parse(json);
    try {
        assert(document.HasMember("module"));
        assert(document["module"].IsString());

        return document["module"].GetString();
    } catch (...) {
        std::cout << "Bad data provided!";
    }
}
