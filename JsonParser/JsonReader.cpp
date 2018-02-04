//
// Created by Thomas on 2018-01-28.
//


#include "JsonReader.h"

std::string JsonReader::parseAction(std::string data) {
    json j = json::parse(data);
    std::string module = j["module"];
    return module;
}

std::vector<double> JsonReader::parseFirstCurrency(std::string data) {
    std::vector<double> parsedData = {};
    json j = json::parse(data);

    parsedData = j["data"]["firstCurrency"].get<std::vector<double>>();

    /*for (rapidjson::SizeType i = 0; i < document["data"]["firstCurrency"].Size(); i++) {
        parsedData.push_back(atof(document["data"]["firstCurrency"][i].GetString()));
    }*/

    return parsedData;
}


std::vector<double> JsonReader::parseSecondCurrency(std::string data) {
    std::vector<double> parsedData = {};
    json j = json::parse(data);

    parsedData = j["data"]["secondCurrency"].get<std::vector<double>>();

    /*for (rapidjson::SizeType i = 0; i < document["data"]["firstCurrency"].Size(); i++) {
        parsedData.push_back(atof(document["data"]["firstCurrency"][i].GetString()));
    }*/

    return parsedData;
}
