#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;

    while(s[i] != '\0' && i < FIXSTRING_MAX -1 ) {
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool eq = true;
    unsigned int i = 0;
    unsigned int length1 = fstring_length(s1);
    unsigned int length2 = fstring_length(s2);

    if (length2 != length1) {
        return false;
    }

    while (eq && 
        (s1[i] != '\0') && 
        (s2[i] != '\0') && 
        (i < length1)) {

        eq = eq && (s1[i] == s2[i]);
        i++;

    }

    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool less_eq = true;
    unsigned int i = 0;
    unsigned int length1 = fstring_length(s1);
    unsigned int length2 = fstring_length(s2);

    while ( (s1[i] != '\0') && 
        (s2[i] != '\0') && 
        (i < FIXSTRING_MAX - 1)) 
    {
        
        if (s1[i] < s2[i]) {
            return true;
        } else if (s1[i] > s2[i]) {
            return false;
        }

        i++;
    
    }

    if (length1 > length2) {
        return false;
    }

    return less_eq;
}

