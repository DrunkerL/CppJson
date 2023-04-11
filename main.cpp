#include <iostream>
using namespace std;

#include "json/Json.h"
using namespace DrunkerL;
using namespace json;
int main() {

    Json obj;
    obj["bool"] = true;
    obj["int"] = 1;
    obj["double"] = 1.23;
    obj["str"] = "hello world";
    obj.remove("bool");
    cout << obj.str();
    obj.clear();

    return 0;
}
