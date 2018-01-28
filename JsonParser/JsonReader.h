//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_JSONREADER_H
#define AET_JSONREADER_H


#include <vector>
#include <iostream>
#include "../JsonLib/include/rapidjson/document.h"

class JsonReader {
public:
    std::string parseAction(std::string);
    std::vector<double> parseData(std::string);
};


#endif //AET_JSONREADER_H
