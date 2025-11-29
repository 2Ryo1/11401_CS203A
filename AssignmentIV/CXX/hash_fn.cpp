/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.
    These codes were designed with the concept of improving 
    distribution skew and collision rates in a simple manner, without unnecessary complexity.

    myHashInt:
    the remainder of the key value divided by m was used directly as the index.
    This was further modified by combining it with the key value divided by m.
    This enhances the uniqueness of each key value, thereby reducing distribution skew and collision rates.

    myHashString:
    This code converts each character in the string from ASCII to an int type,
    processes the division result similarly to myHashInt, and concatenates their sums.
    Since the converted values of different strings may match, this code aims to 
    enhance key uniqueness by adding a value combining the string's last character and
    its index to the division sum, and further adding the remainder value of
    the first character divided by m to the total remainder sum.

   Development History:
    - 2025/11/24: replace with my design in hash_fn.hpp

   Developer: Ryo Ito <s1133352@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <string>
#include <cstdlib>
using namespace std; 

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    int d = key/m;          //d denote the sum of the divisors and r denote the sum of the remainders
    string sd =to_string(d);
    int r = key%m;
    string sr =to_string(r);
    
    string stringhash = sd + sr;
    int hash = stoi(stringhash);
    return hash%m; // 2025/11/24 AM6:50 created
}

int myHashString(const std::string& str, int m) {
    // TODO: replace with your own design
    int wordsize = str.size();
    int d = 0, r = 0;             //d denote the sum of the divisors and r denote the sum of the remainders
    for(int i=0; i<wordsize; i++){
        d+=int(str[i])/m;
        r+=int(str[i])%m;
    }
    if(wordsize==1)wordsize++; //To avoid dividing by zero
    d+=int(str[wordsize-1])/(wordsize-1);
    r+=int(str[0])%m;

    string sd =to_string(d);
    string sr =to_string(r);
    string stringhash = sd + sr;
    int hash = stoi(stringhash);
    return hash%m;  // 2025/11/24 AM6:50 created
}
