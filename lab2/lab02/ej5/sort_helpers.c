#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fstring_swap(a[i],a[j]);
}

bool goes_before(fixstring x, fixstring y) {
    bool goes_before = true;
    unsigned int i = 0;
    unsigned int length1 = fstring_length(x);
    unsigned int length2 = fstring_length(y);
	// If the strings are not equal, then the one with
    // less characters is lesser in aplhabetical order
    if (length1 > length2) {
        return false;
    } else if (length2 > length1) {
        return true;
    }
    
	// If the strings are equally large and we are not at the end of one of the strings, continue 
    while ( (x[i] != '\0') && 
        (y[i] != '\0') && 
        (i < FIXSTRING_MAX - 1)) 
    {
        // If the number i character in the string x is
        // less than his counterpart in y, it means it's
        // alphabeticaly less in order
        if (x[i] < y[i]) {
            return true;
        // If the i position in the string 1 is greater
        // than his counterpart, then its alphabeticaly
        // bigger in order   
        } else if (x[i] > y[i]) {
            return false;
        }
		
		// Add one to i so we check the next character inline
        i++;
    
    }

    return goes_before;
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

