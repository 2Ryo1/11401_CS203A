/*
   Description:
    This file contains the hash functions for integer and string keys.
    These codes were designed with the concept of improving 
    distribution skew and collision rates in a simple manner,
    without unnecessary complexity.

    myHashInt:
    * @brief Using both the remainder and quotient of the key/m,
        it enhances the uniqueness of the value,
        reducing distribution skew and collisions.
    * @param key The integer key to hash.
    * @param m The table size.
    * @return The computed hash index.


    myHashString:
    * @brief Computes the hash index for a string key.
        Converts characters to integers and combines quotient and remainder sums
        similar to myHashInt. Enhances uniqueness uniqueness of the value by also using the last
        character's quotient and the first character's remainder.
    * @param m The table size.
    * @return The computed hash index.


   Development History:
    - 2025/11/24: replace with my design in hash_fn.hpp

   Developer: Ryo Ito <s1133352@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <string>
#include <cstdlib>
using namespace std; 

int myHashInt(int key, int m) {
    int d = key/m;       //d denote the sum of the divisors and r denote the sum of the remainders
    string sd =to_string(d);
    int r = key%m;
    string sr =to_string(r);
    
    string stringhash = sd + sr;//Combine the remainder with the sum
    int hash = stoi(stringhash);
    return hash%m; // 2025/11/24 AM6:50 created
}

int myHashString(const std::string& str, int m) {
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
    string stringhash = sd + sr;//Combine the remainder with the sum
    int hash = stoi(stringhash);
    return hash%m;  // 2025/11/24 AM6:50 created
}
