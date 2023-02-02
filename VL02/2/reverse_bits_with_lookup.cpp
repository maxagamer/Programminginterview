// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <random>
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Lookup table to get a reversed byte. For example you want to know the
// reversed byte of "2" (00000010), you find it out by executing lookup[2]
// --> 64 (01000000)
const uint32_t lookup[256] = {
        0,  128, 64, 192, 32, 160, 96,  224, 16, 144, 80, 208, 48, 176, 112, 240,
        8,  136, 72, 200, 40, 168, 104, 232, 24, 152, 88, 216, 56, 184, 120, 248,
        4,  132, 68, 196, 36, 164, 100, 228, 20, 148, 84, 212, 52, 180, 116, 244,
        12, 140, 76, 204, 44, 172, 108, 236, 28, 156, 92, 220, 60, 188, 124, 252,
        2,  130, 66, 194, 34, 162, 98,  226, 18, 146, 82, 210, 50, 178, 114, 242,
        10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 90, 218, 58, 186, 122, 250,
        6,  134, 70, 198, 38, 166, 102, 230, 22, 150, 86, 214, 54, 182, 118, 246,
        14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 94, 222, 62, 190, 126, 254,
        1,  129, 65, 193, 33, 161, 97,  225, 17, 145, 81, 209, 49, 177, 113, 241,
        9,  137, 73, 201, 41, 169, 105, 233, 25, 153, 89, 217, 57, 185, 121, 249,
        5,  133, 69, 197, 37, 165, 101, 229, 21, 149, 85, 213, 53, 181, 117, 245,
        13, 141, 77, 205, 45, 173, 109, 237, 29, 157, 93, 221, 61, 189, 125, 253,
        3,  131, 67, 195, 35, 163, 99,  227, 19, 147, 83, 211, 51, 179, 115, 243,
        11, 139, 75, 203, 43, 171, 107, 235, 27, 155, 91, 219, 59, 187, 123, 251,
        7,  135, 71, 199, 39, 167, 103, 231, 23, 151, 87, 215, 55, 183, 119, 247,
        15, 143, 79, 207, 47, 175, 111, 239, 31, 159, 95, 223, 63, 191, 127, 255};

/************** begin assignment **************/
// Write a program that takes a 32-bit unsigned integer and returns the 32-bit
// unsigned integer consisting of the bits of the input number in reverse order.
// For example, if the input is alternating 1s and Os, i.e., (1010 ... 10), the
// output should be alternating Os and 1s, i.e., (0101 ... 01).
// Use a lookup table to reverse individual bytes of the unsigned integer.

// A simple solution to reverse the bits in a 32-bit unsigned integer (no lookup table)
inline uint32_t reverse_simple(uint32_t num) {
    uint32_t result = 0;
    for (uint32_t offset = 31; num; num >>= 1u) {
        // extract least significant bit and left shift by offset
        // update result
        result |= (num & 1u) << offset--;
    }
    return result;
}

int bitExtracted(int number, int k, int p){
    return (((1 << k) - 1) & (number >> (p - 1)));
}

// TODO: Use the lookup table at line 18 to reverse the bits of an unsigned 32-bit integer.
inline uint32_t reverse_with_lookup(uint32_t num) {
    // Declaration and Initialization of Variables
    bitset<32>  sum = 0;

    // here the bits are extracted from most significant to least significant
    bitset<8>   first       = bitExtracted(num, 8, 25);
    bitset<8>   second      = bitExtracted(num, 8, 17);
    bitset<8>   third       = bitExtracted(num, 8, 9);
    bitset<8>   fourth      = bitExtracted(num, 8, 1);

    // first the 8 bits of the bit sets are "ORed" in in reversed order and after that
    // they are thrown in the lookup table
    // after that they get shifted a hole byte to be in the right place
    // only three times shifter because the last one will aleady be at the right place
    sum |= lookup[fourth.to_ulong()];
    sum <<= 8u;
    sum |= lookup[third.to_ulong()];
    sum <<= 8u;
    sum |= lookup[second.to_ulong()];
    sum <<= 8u;
    sum |= lookup[first.to_ulong()];

    /*
    first                   = lookup[first.to_ulong()];     // -> aa XX XX XX <-> XX XX XX aa
    second                  = lookup[second.to_ulong()];    // -> XX aa XX XX <-> XX XX aa XX
    third                   = lookup[third.to_ulong()];     // -> XX XX aa XX <-> XX aa XX XX
    fourth                  = lookup[fourth.to_ulong()];    // -> XX XX XX aa <-> aa XX XX XX

    //sum = sum | fourth;
    */
    // TODO: write code here
    return sum.to_ulong();
}

inline void reverse_myMaxa(uint32_t num){
    bitset<32> first;
    bitset<32> last;

    first ^= num;

    int size = first.size() - 1;
    for (int i = size; i >= 0; i--) {
        last[size - i] = first[i];
    }

    cout << "first:\t" << first << endl;
    cout << "last:\t" << last << endl;
}

/*************** end assignment ***************/

int main() {
    int n = 1000;
    auto rand_uint32 = bind(uniform_int_distribution<uint32_t>{0, UINT32_MAX},
                            default_random_engine{std::random_device{}()});
    // first correctness
    for (int i = 0; i < n; ++i) {
        // generate a random unsigned integer
        uint32_t num = rand_uint32();
        // first if lookup version produces the correct results
        assert(reverse_simple(num) == reverse_with_lookup(num));
    }
    cout << "all tests passed" << endl;

    return 0;
}


