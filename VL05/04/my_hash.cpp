// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

// helper macros for timings
#define TIMERSTART(label)                                                      \
  std::chrono::time_point<std::chrono::system_clock> a##label, b##label;       \
  a##label = std::chrono::system_clock::now();

#define TIMERSTOP(label)                                                       \
  b##label = std::chrono::system_clock::now();                                 \
  std::chrono::duration<double> delta##label = b##label - a##label;            \
  std::cout << #label << ": " << std::setprecision(4) << delta##label.count()  \
            << " seconds" << std::endl;

using namespace std;

// Standard library container classes provide member functions begin() and end()
// so the program can obtain an iterator range to search. C-style arrays are
// more primitive, and offer no such functions. However, a little template magic
// provides typesafe template functions for this purpose. Since they take an
// array type as an argument, the array does not decay to a pointer as it
// normally would get size and begin / end from a C-style array.
template <typename T, int N> size_t size(T (&a)[N]) { return N; }
// template <typename T, int N> T *begin(T (&a)[N]) { return &a[0]; }
// template <typename T, int N> T *end(T (&a)[N]) { return &a[N]; }

struct kv { // (key,value) pairs
    const string key;
    uint32_t value;
};

/************** begin assignment **************/
// Write a minimal perfect hash function for the strings in the table below.

static kv table[] = {
        {"John Smith", 29},
        {"Lisa Smith", 32},
        {"Sam Doe", 31},
        {"Sandra Dee", 26}};

// for your convenience, the key is a C++ string and not a C-style pointer
uint32_t my_hash(const string &key) {
    switch(key[0]){
        case 'S':   if(key[1] == 'a'){
                        if(key[2] == 'm'){
                            return 2;
                        }else if(key[2] == 'n'){
                            return 3;
                        }else return UINT32_MAX;
                    }else return UINT32_MAX;
        case 'J':   return 0;
        case 'L':   return 1;
        default:    return UINT32_MAX;
    }
    // Remarks:
    //   - return the index of the string in the kv table to be compared with the
    //     key entered by the user
    //   - if you can exclude the possibility that the key is a string in
    //     the table, return UINT32_MAX (in this case strings are not compared at all
    //     --> see "find_hash" function)
    //   - prefer "switch" statements over "if else"

}

/*************** end assignment ***************/

// similar interface as std::unordered_map
kv *find_hash(kv *first, kv *last, const string &key) {
    uint32_t i = my_hash(key);
    // you don't need to call strcmp if you return UINT32_MAX from my_hash
    // function (UINT32_MAX indicates that the key is not in the hash table)
    if (i == UINT32_MAX)
        return last;
    // strcmp returns 0 if C strings are equal
    return strcmp(first[i].key.c_str(), key.c_str()) ? last : first + i;
}

int definitely_not_main_04() {
    // test correctness

    {
        for (size_t i = 0; i < size(table); ++i) {
            auto result = find_hash(begin(table), end(table), table[i].key);
            assert(result->key == table[i].key);
            assert(result->value == table[i].value);
        }
    }
    {
        string search_string; // empty string has only the special character \0
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert empty string is not in the hash table
    }
    {
        string search_string = "S";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "S" is not in the hash table
    }
    {
        string search_string = "Sa";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "Sa" is not in the hash table
    }
    {
        string search_string = "john Smith";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "john Smith" is not in the hash table
    }
    {
        string search_string = "Sam Doi";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "Sam Doi" is not in the hash table
    }
    {
        string search_string = "John Smithh";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "John Smithh" is not in the hash table
    }
    {
        string search_string = "$John Smith";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result == end(table)); // assert "$John Smith" is not in the hash table
    }
    {
        string search_string = "John Smith";
        auto result = find_hash(begin(table), end(table), search_string);
        assert(result != end(table)); // assert "John Smith" is in the hash table
        assert(result->key == search_string);
    }

    // lets compare the speed to c++ unordered_map
    // all 4 words from the table and some random 4 words
    vector<string> queries{"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee",
                           "cookie",     "disaster",   "lake",    "teacher"};

    // shuffle queries
    auto rng = default_random_engine{random_device{}()};
    std::shuffle(begin(queries), end(queries), rng);
    unordered_map<string, unsigned int> hash_map{{"John Smith", 29},
                                                 {"Lisa Smith", 32},
                                                 {"Sam Doe", 31},
                                                 {"Sandra Dee", 26}};

    int repetitions = 10000000;

    int matches_count_cpp = 0;
    TIMERSTART(unordered_map)
    for (int i = 0; i < repetitions; ++i) {
        for (const auto &query : queries) {
            matches_count_cpp += hash_map.find(query) != hash_map.end();
        }
    }
    TIMERSTOP(unordered_map)

    int matches_count_min_hash = 0;
    TIMERSTART(perfect_min_hash)
    for (int i = 0; i < repetitions; ++i) {
        for (const auto &query : queries) {
            matches_count_min_hash +=
                    find_hash(begin(table), end(table), query) != end(table);
        }
    }
    TIMERSTOP(perfect_min_hash)

    assert(matches_count_cpp == matches_count_min_hash);

}