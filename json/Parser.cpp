//
// Created by ASUS on 2023/4/12.
//

#include "Parser.h"
#include <iostream>
#include <string>
using namespace DrunkerL;
using namespace json;


Parser::Parser() : m_str(""),m_index(0){

}
void Parser::load(const std::string &str) {
    m_str = str;
    m_index = 0;
}

void Parser::skip_white_space(){
    while (m_str[m_index] == ' ' || m_str[m_index] == '\n' || m_str[m_index] == '\r' || m_str[m_index] == '\t'){
        m_index ++;
    }
}

char Parser::get_next(){
    skip_white_space();
    return m_str[m_index++];
}

Json Parser::parse() {
    char ch = get_next();
    switch (ch) {
        case 'n':
            m_index--;
            return parse_null();
        case 't':
        case 'f':
            m_index--;
            return parse_bool();
        case '-':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            m_index--;
            return parse_number();
        case '"':
            return Json(parse_string());
        case '[':
            return parse_array();
        case '{':
            return parse_object();
        default:
            break;
    }
    throw new logic_error("unexcepted char");
}
Json Parser::parse_null(){
    if(m_str.compare(m_index,4,"null") == 0){
        m_index += 4;
        return Json();
    }
    throw new logic_error("parse null error");
}
Json Parser::parse_bool(){
    if(m_str.compare(m_index,4,"true") == 0){
        m_index += 4;
        return Json(true);
    }else if(m_str.compare(m_index,5,"false") == 0){
        m_index += 5;
        return Json(false);
    }
    throw new logic_error("parse bool error");
}
Json Parser::parse_number(){
    int pos = m_index;
    if(m_str[m_index] == '-'){
        m_index++;
    }
    if(m_str[m_index] < '0' || m_str[m_index] > '9'){
        throw new logic_error("parse number error");
    }
    while (m_str[m_index] >= '0' && m_str[m_index] <= '9'){
        m_index++;
    }
    if(m_str[m_index] != '.'){
        int number = atoi(m_str.c_str() + pos);
        return Json(number);
    }
    m_index++;
    if(m_str[m_index] < '0' || m_str[m_index] > '9'){
        throw new logic_error("parse number error");
    }
    while (m_str[m_index] >= '0' && m_str[m_index] <= '9'){
        m_index++;
    }
    double f = atof(m_str.c_str() + pos);
    return Json(f);
}
string Parser::parse_string(){
    string out;
    while (true){
        char ch = m_str[m_index++];
        if(ch == '"'){
            break;
        }
        if(ch == '\\'){
            ch = m_str[m_index++];
            switch (ch) {
                case '\n':
                    out += '\n';
                    break;
                case '\r':
                    out += '\r';
                    break;
                case '\t':
                    out += '\t';
                    break;
                case '\b':
                    out += '\b';
                    break;
                case '\f':
                    out += '\f';
                    break;
                case '"':
                    out += "\\\"";
                    break;
                case '\\':
                    out += "\\\\";
                    break;
                case 'u':
                    out += "\\u";
                    for(int i = 0; i < 4; i++){
                        out += m_str[m_index++];
                    }
                    break;
                default:
                    break;
            }
        }else{
            out += ch;
        }
    }
    return Json(out);
}
Json Parser::parse_array(){
    Json arr(Json::json_array);
    char ch = get_next();
    if(ch == ']'){
        return arr;
    }
    m_index--;
    while (true){
        arr.append(parse());
        ch = get_next();
        if(ch == ']'){
            break;
        }
        if(ch != ','){
            throw new logic_error("parse array error");
        }
        m_index++;
    }
    return arr;
}
Json Parser::parse_object(){
    Json obj(Json::json_object);
    char ch = get_next();
    if(ch == '}'){
        return obj;
    }
    m_index--;
    while (true){
        ch = get_next();
        if(ch != '"'){
            throw new logic_error("parse object error");
        }
        string key = parse_string();
        ch = get_next();
        if(ch != ':'){
            throw new logic_error("parse object error");
        }
        obj[key] = parse();
        ch = get_next();
        if(ch == '}'){
            break;
        }
        if(ch != ','){
            throw new logic_error("parse object error");
        }
    }
    return obj;
}