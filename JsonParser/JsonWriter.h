//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_JSONWRITER_H
#define AET_JSONWRITER_H

#include <vector>
#include <iostream>
#include "../JsonLib/include/rapidjson/document.h"
#include "../JsonLib/include/rapidjson/stringbuffer.h"
#include "../JsonLib/include/rapidjson/prettywriter.h"

class JsonWriter {
public:
    std::string parseToJson(std::vector<double>);
};


#endif //AET_JSONWRITER_H
