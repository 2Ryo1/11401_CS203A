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

#include "hash_fn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int myHashInt(int key, int m) {
    int d = key/m;   //d denote the sum of the divisors and r denote the sum of the remainders
    int r = key%m;
    /*
    Since it's within the range of int,
    each can be an integer of up to about 10 digits.
    Combining the two results in 10 digits+10 digits = 20 digits.
    Additionally, a terminating character \0 is needed, 
    making a total of 21 characters.
    Therefore, I use 25 characters to allow for extra space.
    */
    char buffer[25];
    sprintf(buffer,"%d%d", d,r);//Combine the remainder with the sum
    int hash = atoi(buffer);
    return hash%m; // 2025/11/25 PM11:35 created
}

int myHashString(const char* str, int m) {
    int wordsize = strlen(str);
    int d = 0, r = 0; //d denote the sum of the divisors and r denote the sum of the remainders
    for(int i= 0; i<wordsize; i++){
        d+=(int)str[i]/m;
        r+=(int)str[i]%m;
    }
    if(wordsize == 1) wordsize++;
    d+=(int)str[wordsize-1]/(wordsize-1);
    r+=(int)str[0]%m;

    char buffer[25];//For the same reason as myHashInt, I use 25 characters

    sprintf(buffer,"%d%d", d,r);//Combine the remainder with the sum
    int hash = atoi(buffer);// 2025/11/25 PM11:35 created

    return hash % m;
}
