//
// Created by Thomas on 2018-01-28.
//

#include "JsonWriter.h"

std::string JsonWriter::parseToJson(std::vector<double> data) {
    json resp;
    resp["results"] = data;
    std::string response = resp.dump();
    return response;
}
