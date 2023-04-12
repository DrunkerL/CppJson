#include <iostream>
#include <fstream>
#include <sstream>
#include "json/Json.h"
using namespace std;
using namespace DrunkerL;
using namespace json;
int main() {

    const string & data = "[1, 2, 3]";
    Json v;
    v.parse(data);
    cout << v.str();
    v.clear();
    return 0;
}
