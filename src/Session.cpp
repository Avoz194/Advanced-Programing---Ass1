#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "../include/Session.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) : g(vector<vector<int>>()) {

    //read JSON file
    ifstream i("path.json");
    json j;
    j << i;

    //build initial agent list
    for (auto &elem: j["agents"]) {
        if (elem[0] = 'V') {
            addAgent();
        }
        if (elem[0] = 'C') {
            addAgent((Agent &) ContactTracer());
        }
    }
    setGraph(j["graph"])
    cout << j["graph"] << endl
}

};




