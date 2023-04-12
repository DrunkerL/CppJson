//
// Created by ASUS on 2023/4/12.
//

#ifndef CPPJSON_PARSER_H
#define CPPJSON_PARSER_H

#include <iostream>
#include <string>
#include "Json.h"
using namespace std;

namespace DrunkerL{
    namespace json{
        class Parser{
        public:
            Parser();
            void load(const string & str);
            Json parse();

        private:
            void skip_white_space();
            char get_next();
            Json parse_null();
            Json parse_bool();
            Json parse_number();
            string parse_string();
            Json parse_array();
            Json parse_object();

        private:
            string m_str;
            int m_index;
        };
    }
}

#endif //CPPJSON_PARSER_H
