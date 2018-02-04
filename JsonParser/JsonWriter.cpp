//
// Created by Thomas on 2018-01-28.
//

#include "JsonWriter.h"

std::string JsonWriter::parseToJson(std::vector<double> data) {
    json j_vector = data;

    std::string response = j_vector.dump();
    return response;
}
