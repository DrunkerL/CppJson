//
// Created by ASUS on 2023/4/10.
//
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace DrunkerL{
namespace json{

class Json{
public:
    enum Type{
        json_null = 0,
        json_bool,
        json_int,
        json_double,
        json_string,
        json_array,
        json_object
    };
    //构造器
    Json();
    Json(bool value);
    Json(int value);
    Json(double value);
    Json(const char* value);
    Json(string &value);
    Json(Type type);
    Json(const Json &other);

    //运算符重载
    operator bool();
    operator int();
    operator double();
    operator string();

    /**
     * //重载[]运算符，以下标的方式访问Json对象
     * @param index 下标
     * @return
     */
    Json & operator [](int index);
    /**
     * 重载[]运算符，以下标的方式访问Json对象
     * @param json
     * @return
     */
    Json & operator [](const char *key);
    Json & operator [](const string &key);

    //json操作

    /**
     * 追加一个元素
     * @param other json对象
     */
    void append(const Json & other);

    /**
     * 输出json内容
     * @return
     */
    string str() const;
private:
    union Value{
        bool m_bool;
        int m_int;
        double m_double;
        string *m_string;
        vector<Json> *m_array;
        map<string,Json> *m_object;
    };
    Type m_type;
    Value m_value;
};

}}

