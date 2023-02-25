// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include "Node.h"

using namespace std;


void workWithString(){
    string s = "Arcturus          HR 5340      alf   α     Boo -    14157+1911 -0.05   69673 124897 213.915300  19.182409 2016-06-30";
    for(int i = 0; i < s.length(); i++){
        cout << i << ": " << s[i] << "\n";
    }
}

void printStarVec(vector<Star> stars){
    for(Star s: stars){
        cout << "{" << s.name << "}{" << s.vmag << "}\n";
    }
}

void printStar(int count, string name, string Vmag){
    cout << "count: " << count - 17 << " Name: " << name << " Vmag: " << Vmag << "\n";
}


/************** begin assignment **************/
// Find k (= 8) brightest stars in a stream. To measure the brightness we use
// the visual magnitude (Vmag). The smaller Vmag the brighter the star appears
// to us. If you want to know more about Vmag read this:
// https://de.wikipedia.org/wiki/Scheinbare_Helligkeit
// We work with the file stars.txt. Look at the structure of the file, because
// you will parse it line by line to extract information about the stars.

/*
    struct Star {
        string name; // name of the star
        double vmag; // stars brightness (the smaller vmag the brighter the star)
    };
*/

// You get the input file stream "ifs" to the "stars.txt" file and a parameter
// "k". "k" is the amount of the brightest stars we want to extract from the
// stream. Try to extract the "k" brightest stars in O(n * log(k)) time with
// O(log n) extra space.


vector<Star> find_k_brightest_stars(ifstream &ifs, const size_t k) {
    // "result" contains in the end the k brightest stars in sorted order
    // (brightest first)
    vector<Star> result;
    // this is used to store lowest number inside "stars"
    double maximum = NULL;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    RBTree bs;

    // check only lines between 18 and 352 (18 <= x <= 352)
    // line is a string that holds the current line
    // count is to know on which line we currently are,
    // therefore also an indicator which lines contains useful information
    string line;
    int count = 0;
    while ( getline (ifs,line) ){
        // after line 352 there is no useful data anymore
        // useful data starts at line 18
        // compiler should skip to line 18 (not sure has to be checked)
        if(count > 351) break;
        // k elements need to be inside the tree so we add until we reach them (17 + k)
        if(count > 17 && count <= 17 + k){
            // this is where name could be
            string name = line.substr(0, 17);
            // here is where the Vmag is found as string
            // this will later be cast to double
            string data = line.substr(64, 5);
            // this is where the last character of the
            // name can be found
            size_t i = name.find_last_of(alpha);
            // this is to re-allocate the memory and
            // to resize the string to only the name
            name.resize(i + 1);
            name.shrink_to_fit();

            //here is the data cast to double
            double temp = stod(data);
            // first fill to maximum
            if(maximum == NULL) maximum = temp;
            // here we save the "largest" number we will
            // put inside the tree
            if(temp > maximum) maximum = temp;
            bs.insert(temp, name);
        }else{
            // now we check if a given information is bigger then the
            // minimum we already saved
            // if so we add it to the tree but delete the last minimum so we only have k elements
            if(count > 17){
                string name = line.substr(0, 17);
                string data = line.substr(64, 5);
                size_t i = name.find_last_of(alpha);
                name.resize(i + 1);
                name.shrink_to_fit();

                double temp = stod(data);
                // if a give value is lower (therefore brighter)
                // it has to be smaller than the biggest number
                // inside the tree, so we will add it to the tree
                // and delete the oldest biggest number and update
                // the tree
                if(temp < maximum){
                    if(temp < bs.findMaximum()){
                        // cout << "1." << "Name: " << name << " Vmag: " << data << " Minimum: " << maximum << " bs.findMinimum(): " << bs.findMinimum() << "\n";
                        bs.deleteNode(bs.findMaximum());
                        maximum = bs.findMaximum();
                        bs.insert(temp, name);
                    }else{
                        // cout << "2." << "Name: " << name << " Vmag: " << data << " Minimum: " << maximum << " bs.findMinimum(): " << bs.findMinimum() << "\n";
                        bs.deleteNode(bs.findMaximum());
                        maximum = temp;
                        bs.insert(temp, name);
                    }
                }
            }
        }
        count++;
    }

    // we now add every star to the vector using this function
    bs.inorderVec(result);

    return result;
}
/*************** end assignment ***************/

int main() {


    string path = "/home/m4x/CLionProjects/VL05/1/stars.txt";
    ifstream ifs{path}; // open file as a stream
    if (ifs.fail()) {
        cerr << "cannot find: " << path << endl;
        return 1;
    }


    size_t k = 8;
    vector<Star> brightest_stars = find_k_brightest_stars(ifs, k);

    vector<Star> correct_stars{{"Sirius", -1.45},   {"Canopus", -0.62},
                               {"Arcturus", -0.05}, {"Rigil Kentaurus", -0.01},
                               {"Vega", 0.03},      {"Capella", 0.08},
                               {"Rigel", 0.18},     {"Procyon", 0.4}};

    // test correctness of solution
    assert(brightest_stars.size() == correct_stars.size());
    const double epsilon = 1.0e-12; // almost 0
    for (size_t i = 0; i < brightest_stars.size(); ++i) {
        assert(abs(brightest_stars[i].vmag - correct_stars[i].vmag) < epsilon);
        assert(brightest_stars[i].name == correct_stars[i].name);
    }

    // output brightest stars
    for (const auto &star : brightest_stars) {
        cout << star.name << endl;
        cout << star.vmag << endl;
        cout << endl;
    }

}
