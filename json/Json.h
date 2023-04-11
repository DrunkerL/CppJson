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

    /**
     * 重载赋值运算符
     * @param other
     */
    void operator = (const Json & other);

    /**
     * 重载==运算符
     * @param other
     */
    bool operator == (const Json & other);

    /**
     * 重载 ！= 运算符
     * @param other
     */
    bool operator != (const Json & other);

    bool isNull() const {return m_type == json_null;}
    bool isBool() const {return m_type == json_bool;}
    bool isInt() const {return m_type == json_int;}
    bool isDouble() const {return m_type == json_double;}
    bool isString() const {return m_type == json_string;}
    bool isArray() const {return m_type == json_array;}
    bool isObj() const {return m_type == json_object;}

    /**
     * 显式类型转换
     * @return
     */
    bool asBool() const;
    int asInt() const;
    double asDouble() const;
    string asString() const;

    /**
     * has方法
     * @param index
     * @return
     */
    bool has(int index);
    bool has(const char * key);
    bool has(const string &key);

    /**
     * remove方法
     * @param index
     */
    void remove(int index);
    void remove(const char * key);
    void remove(const string & key);

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

    /**
     * 拷贝
     * @param other
     */
    void copy(const Json & other);

    /**
     * 释放内存
     */
    void clear();

    typedef vector<Json> :: iterator iterator;
    iterator begin(){
        return (m_value.m_array)->begin();
    }
    iterator end(){
        return (m_value.m_array)->end();
    }
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

