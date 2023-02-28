//
// Created by m4x on 2/28/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVertex(const vector<vector<int>> vec){
    for(int x = 0; x < vec.size(); x++){
        cout << vec[x][0];
        for(int y = 1; y < vec[x].size(); y++){
            cout  << "," << vec[x][y];
        }
        cout << "\n";
    }
}

vector<vector<int>> workWithVertex(const string path){
    vector<vector<int>> vertex;
    ifstream ifs{path}; // open file as a stream
    if (ifs.fail()) {
        cerr << "cannot find: " << path << endl;
        return vertex;
    }

    string line;
    int count = 0;
    while ( getline (ifs,line) ){
        string tmp = "";
        vector<int> tmp_V;
        for(int i = 0; i < line.length(); i++){
            char c = line[i];
            if(c == ','){
                if(tmp.empty()) continue;
                tmp_V.push_back(stod(tmp));
                tmp = "";
                continue;
            }else if(c == '-') {
                tmp_V.push_back(0);
            }else tmp+=c;
        }
        vertex.push_back(tmp_V);
        count++;
    }
}

int main() {

    string path = "/home/m4x/CLionProjects/VL09/02/vertex_1.txt";
    vector<vector<int>> vec = workWithVertex(path);


    return 1;
}
