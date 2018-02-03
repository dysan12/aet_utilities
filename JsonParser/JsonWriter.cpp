//
// Created by Thomas on 2018-01-28.
//

#include "JsonWriter.h"

std::string JsonWriter::parseToJson(std::vector<double> data) {
    rapidjson::Document document;
    document.SetObject();

    rapidjson::Value values(rapidjson::kArrayType);
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    for (auto &value: data){
        values.PushBack(rapidjson::Value().SetDouble(value), allocator);
    }

    rapidjson::StringBuffer strbuf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);

    return strbuf.GetString();
}
