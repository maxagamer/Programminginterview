// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// source: lecture script
inline int string_to_int(const string &s) {
    bool is_negative = s[0] == '-';
    int result = 0;
    // if integer is negative start with index i = 1
    for (size_t i = is_negative; i < s.size(); ++i) {
        result = result * 10 + s[i] - '0';
    }
    return is_negative ? -result : result;
}

/************** begin assignment **************/
// Sudoku is a popular logic-based combinatorial number placement puzzle. The
// objective is to fill a 9 x 9 grid with digits subject to the constraint that
// each column, each row, and each of the nine 3 x 3 sub-grids that compose the
// grid contains unique integers.
// In case you need an introduction to Sudoku:
// https://www.learn-sudoku.com/sudoku-rules.html

// We define three different states in which a Sudoku board can be.
enum class state { invalid, valid, solved };
// invalid --> board violates the Sudoku rules
// valid --> board corresponds to the Sudoku rules
// solved --> the puzzle is solved

// Note that the only valid characters are "123456789" and the space ' ' meaning
// an empty field.
// Note that we do not care if a board can actually be solved, we only check if
// it violates the rules, or is valid, or is in a solved state.
// Of course a solved board is also valid, but we only return solved.

// TODO: implement a function that returns the state of a Sudoku board

// is to increase the count of the array

state compute_sudoku_state(const string &board) {
    //--------------------------------------------Variable Zone--------------------------------------------\\
    // checks if the string has the right size, if not returns invalid
    // no use to go any further if it doesn't suit
    if (board.size() != 81) return state::invalid;

    // has_empty is checked, if it contains only one empty cell
    bool has_empty = 0;

    // function wide iterator for the two "for"loops
    size_t i;

    // temporary char
    char ctmp;


    // used to store the checkSum
    uint16_t checkSum = 0;

    // vector to store temporary chars
    vector<char> tmp;

    //--------------------------------------------Checking for invalid Characters--------------------------------------------\\
    // first loops looks if it contains any empty char, so we know we
    // can't solve it anymore
    // second we check if the char is between 1 and 9 if it is not we return invalid
    // in the second loop we already know it has at least one empty spot, so we just
    // check if the chars are correct
    for (i = 0; i < board.size(); i++) {
        ctmp = board[i];
        // we subtract '1' and not '0',
        // because we have to make it suit
        // our indices which are reduced by 1
        if (ctmp == ' ') {
            has_empty = 1;
            break;
        } else {
            if (!(ctmp >= '1' && ctmp <= '9')) return state::invalid;
            // only until we reach here to add the number,
            // because otherwise I cannot be sure that
            // itmp is a number between 1 and 9
        }
    }
    i++;
    for (; i < board.size(); ++i) {
        ctmp = board[i];
        if (!((ctmp >= '1' && ctmp <= '9') || ctmp == ' '))return state::invalid;
    }

    //--------------------------------------------Look for duplicates--------------------------------------------\\

    //________Vertical________\\
    // check if a char occurs more than one time
    {
        for (int j = 0; j < 9; j++) {
            // clear to have a clean vector every loop
            tmp.clear();
            for (int h = 0; h < 9; h++) {
                ctmp = board[j + h * 9];
                // if tmp is empty(what it should be) we push back a number
                if (tmp.empty()) tmp.push_back(ctmp);
                    // every other case we just add look if a char is already in tmp and
                    // unequal to space/empty (' ')
                    // if so we give back invalid
                    // if not we add it and continue
                else for (char c: tmp)  if (c != ' ' && c == ctmp) return state::invalid;
                tmp.push_back(ctmp);
            }
        }
    }

    //________Horizontally________\\

    {
        for (int i = 0; i < 73; i += 9) {
            tmp.clear();
            for (int j = 0; j < 9; j++) {
                ctmp = board[i + j];
                if (tmp.empty()) tmp.push_back(ctmp);
                else for (char c: tmp) if (c != ' ' && c == ctmp) return state::invalid;
                tmp.push_back(board[i + j]);
            }

        }
    }

    //________Boxes________\\

    {
    // last we check for all the squares inside
    // if they are also equal to 45
    // every square is build like the following:
    // "i       i+1     i+2"
    // "i+9     i+10    i+11"
    // "i+18    i+19    i+20"

        for(i = 0; i < 81; i+=27){
            for(int j = 0; j < 7; j+=3){
                tmp.clear();
                int addedInt[8] = { 1, 2, 9, 10, 11, 18, 19, 20};
                if(tmp.empty()){
                    ctmp = board[i+j];
                    tmp.push_back(ctmp);
                }
                for(int x: addedInt){
                    ctmp = board[i+j+x];
                    for(char c: tmp) if (c != ' ' && c == ctmp) return state::invalid;
                    tmp.push_back(board[i+j+x]);
                }
            }
            // wrote this function after the "Checksum 45"
            // sorry if you mental after reading this, cuz I did
        }
    }
    // until here everything should be valid, and we can check for solved
    // if there was one empty spot/char we know it can not be solved and return valid
    if (has_empty == 1) return state::valid;

    //--------------------------------------------Check for 45 Checksum--------------------------------------------\\

    // we start checking if everything is in order by looking if
    // everything is on order horizontally and vertically

    //________Vertical________\\

    {
        for(int j = 0; j < 9; j++){
            checkSum = board[j] - '0';
            for(int h = 1; h < 9; h++) checkSum += board[j+h*9] - '0';
            if(checkSum != 45) return state::invalid;
        }
    }

    // loop for horizontally starting at the second row
    for(int i = 0; i < 73; i+=9){
        checkSum = 0;
        for(int j = 0; j < 9; j++) {
            checkSum += board[i + j] - '0';
        }
        // if the checkSum doesn't equal 45 there is another number in there
        // if they are the same numbers they would fail the check before
        if(checkSum != 45) return state::invalid;
    }

    //________Boxes________\\

    for(i = 0; i < 81; i+=27){
        // it is only written this way,
        // because it is way more readable
        // Box 1
            checkSum = 0;
            checkSum += board[i   ] - '0'     + board[i+ 1] - '0' + board[i+ 2] - '0';
            checkSum += board[i+ 9] - '0'     + board[i+10] - '0' + board[i+11] - '0';
            checkSum += board[i+18] - '0'     + board[i+19] - '0' + board[i+20] - '0';
        // if the checkSum doesn't equal 45 there is another number in there
        // if they are the same numbers they would fail the check before
        if(checkSum != 45) return state::invalid;

        // Box 2
        uint8_t itmp = i + 3;
            checkSum = 0;
            checkSum += board[itmp   ] - '0'     + board[itmp+ 1] - '0' + board[itmp+ 2] - '0';
            checkSum += board[itmp+ 9] - '0'     + board[itmp+10] - '0' + board[itmp+11] - '0';
            checkSum += board[itmp+18] - '0'     + board[itmp+19] - '0' + board[itmp+20] - '0';
        // if the checkSum doesn't equal 45 there is another number in there
        // if they are the same numbers they would fail the check before
        if(checkSum != 45) return state::invalid;

        // Box 3
        itmp = i + 6;
            checkSum = 0;
            checkSum += board[itmp   ] - '0'     + board[itmp+ 1] - '0' + board[itmp+ 2] - '0';
            checkSum += board[itmp+ 9] - '0'     + board[itmp+10] - '0' + board[itmp+11] - '0';
            checkSum += board[itmp+18] - '0'     + board[itmp+19] - '0' + board[itmp+20] - '0';
        // if the checkSum doesn't equal 45 there is another number in there
        // if they are the same numbers they would fail the check before
        if(checkSum != 45) return state::invalid;
    }

    return state::solved;
}

/*************** end assignment ***************/

int main() {

    {
        string board = "274935168"
                       "198726435"
                       "563814729"
                       "356187294"
                       "419562873"
                       "782493516"
                       "821349657"
                       "947651382"
                       "63527894"; // invalid size
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "274935168"
                       "198726435"
                       "563814729"
                       "356187294"
                       "419562873"
                       "782493516"
                       "821349657"
                       "947651382"
                       "6352789412"; // invalid size
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "   9  1 4"
                       " 2  5 7  "
                       "     25 6"
                       "    194 5"
                       " 6574391 "
                       "4 1 26  8"
                       " 18375 4 "
                       " : 4  631" // |:|
                       " 4  6    ";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "586937124"
                       "129654783"
                       "734182596"
                       "372819465"
                       "865743912"
                       "491526308" // |0|
                       "618375249"
                       "257498631"
                       "943261857";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "586937124"
                       "129654783"
                       "734182596"
                       "372819465"
                       "865743912"
                       "4915263a8" // |a|
                       "618375249"
                       "257498631"
                       "943261857";
        assert(compute_sudoku_state(board) == state::invalid);
    }

    {
        string board = "145673829"
                       "389215674"
                       "762948135"
                       "296157483"
                       "814369752"
                       "573824961"
                       "957436218"
                       "628591347"
                       "431782596";
        assert(compute_sudoku_state(board) == state::solved);
    }
    {
        string board = "495287163"
                       "821369547"
                       "367145298"
                       "179854632"
                       "634972815"
                       "582613974"
                       "216438759"
                       "953721486"
                       "748596321";
        assert(compute_sudoku_state(board) == state::solved);
    }
    {
        string board = "145673829"
                       "381215674" // 38|1|
                       "762948135"
                       "296157483"
                       "814369752"
                       "573824961"
                       "957436218"
                       "628591347"
                       "431782596";
        assert(compute_sudoku_state(board) == state::invalid);
    }
     {
        string board = "145673829"
                       "38 215674"
                       "762948135"
                       "296157483"
                       "814369752"
                       "573824961"
                       "957436 18"
                       "628591347"
                       "431782596";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = " 4    897"
                       " 379   52"
                       "8 27  3  "
                       "9  4 7  6"
                       " 8  9  3 "
                       "6 3 18 49"
                       "  83 192 "
                       "26   4  3"
                       " 142596  ";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = " 4    897"
                       " 379   52"
                       "8 27  3  "
                       "9  6 7  6" // 9  |6|
                       " 8  9  3 "
                       "6 3 18 49"
                       "  83 192 "
                       "26   4  3"
                       " 142596  ";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = " 4    897"
                       " 379   52"
                       "8 27  3  "
                       "9  4 7  6"
                       " 8  9  3 "
                       "6 3 18 49"
                       "  83 193 " //   83 19|3|
                       "26   4  3"
                       " 142596  ";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "   9  1 4"
                       " 2  5 7  "
                       "     25 6"
                       "    194 5"
                       " 6574391 "
                       "4 1 26  8"
                       " 18375 4 "
                       "   4  631"
                       " 4  6    ";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = "2  9  1 4" // |2|
                       " 2  5 7  "
                       "     25 6"
                       "    194 5"
                       " 6574391 "
                       "4 1 26  8"
                       " 18375 4 "
                       "   4  631"
                       " 4  6    ";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "         "
                       "         "
                       "         "
                       "         "
                       "         "
                       "         "
                       "         "
                       "         "
                       "         ";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   4     "
                       "    5    "
                       "     6   "
                       "      7  "
                       "       8 "
                       "        9";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   1     "
                       "    2    "
                       "     3   "
                       "      1  "
                       "       2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::valid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   1     "
                       "    2    "
                       "     3   "
                       "      1  "
                       "      32 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   1    7"
                       "    2 7  "
                       "     3   "
                       "      1  "
                       "       2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   1     "
                       "    2    "
                       "     3   "
                       "  4   1  "
                       " 4     2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "1        "
                       " 2 1     "
                       "  3      "
                       "   1     "
                       "    2    "
                       "     3   "
                       "      1  "
                       "       2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       "   1 6   "
                       "   62    "
                       "     3   "
                       "      1  "
                       "       2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    {
        string board = "1        "
                       " 2       "
                       "  3      "
                       " 5 1     "
                       "5   2    "
                       "     3   "
                       "      1  "
                       "       2 "
                       "        3";
        assert(compute_sudoku_state(board) == state::invalid);
    }
    cout << "all tests passed" << endl;

}

/*
Indices:
0       1       2       3       4       5       6       7       8

9       10      11      12      13      14      15      16      17

18      19      20      21      22      23      24      25      26

27      28      29      30      31      32      33      34      35

36      37      38      39      40      41      42      43      44

45      46      47      48      49      50      51      52      53

54      55      56      57      58      59      60      61      62

63      64      65      66      67      68      69      70      71

72      73      74      75      76      77      78      79      80

 */