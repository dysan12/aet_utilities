//
// Created by Thomas on 2018-01-28.
//


#include "JsonReader.h"

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

std::vector<double> JsonReader::parseFirstCurrency(std::string data) {
    std::vector<double> parsedData = {};
    const char *json = data.c_str();
    rapidjson::Document document;
    document.Parse(json);

    try {
        assert(document.HasMember("data"));

        for (rapidjson::SizeType i = 0; i < document["data"]["firstCurrency"].Size(); i++) {
            parsedData.push_back(atof(document["data"]["firstCurrency"][i].GetString()));
        }

        return parsedData;
    } catch (...) {
        std::cout << "Bad data provided!";
    }
}


std::vector<double> JsonReader::parseSecondCurrency(std::string data) {
    std::vector<double> parsedData = {};
    const char *json = data.c_str();
    rapidjson::Document document;
    document.Parse(json);

    try {
        assert(document.HasMember("data"));

        for (rapidjson::SizeType i = 0; i < document["data"]["secondCurrency"].Size(); i++) {
            parsedData.push_back(atof(document["data"]["secondCurrency"][i].GetString()));
        }

        return parsedData;
    } catch (...) {
        std::cout << "Bad data provided!";
    }
}
