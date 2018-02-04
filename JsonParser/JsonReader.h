//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_JSONREADER_H
#define AET_JSONREADER_H


#include <vector>
#include <iostream>
#include "../JsonLib/include/rapidjson/document.h"
#include "Json.h"

using json = nlohmann::json;

class JsonReader {
public:
    std::string parseAction(std::string);
    std::vector<double> parseFirstCurrency(std::string);
    std::vector<double> parseSecondCurrency(std::string);
};


#endif //AET_JSONREADER_H
