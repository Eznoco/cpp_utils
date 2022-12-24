//Ezra Billings
//general purpose functions for strings
#include <string>
#include "stringutils.h"
using namespace std;

#define IS_WHITESPACE(x) ((x) == ' ' || (x) == '\n' || (x) == '\t' || (x) == '\r')
#define IS_UPPER(x) ((x) >= 'A' && (x) <= 'Z') //boolean expression. is true when x is upper case
#define TO_LOWER(x) (IS_UPPER(x) ? ((x) - 'A' + 'a') : (x)) //ternary operator to convert x to lower case

/*
 * a > b returns positive. a < b returns negative. a == b returns 0. case insensitive
 */ 
int cicompare(string a, string b) {
    for (int i = 0; i < a.length() && i < b.length(); i++) {
        int cmp = TO_LOWER(a[i]) - TO_LOWER(b[i]);
        if (cmp != 0) {
            return cmp;
        }
    }
    return a.length() - b.length();
}

/*
 * returns true is a is a substring of b. case insensitive
 */
bool cicontains(string a, string b) {
    if (a.length() > b.length()) {
        return false;
    }
    for (int i = 0; i < b.length() - a.length() + 1; i++) {
        if (cicompare(a, b.substr(i, a.length())) == 0) {
            return true;
        }
    }
    return false;
}

/*
 * trims whitespace from front and back of string
 */
string trim(string s) {
    int start, end, i;
    for (start = 0; start < s.length() && IS_WHITESPACE(s[start]); start++);
    for (end = s.length() - 1; end >= 0 && IS_WHITESPACE(s[end]); end--);
    
    int length = end - start + 1;
    if (length <= 0) {
        return "";
    }
    return s.substr(start, length);
}
