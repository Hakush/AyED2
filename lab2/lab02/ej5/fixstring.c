#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
	// <i> its the length of the fstring	
    unsigned int i = 0;
	
	// If we are not at the end of the string, continue
    while(s[i] != '\0' && i < FIXSTRING_MAX -1 ) {
    	// Add one to the length of the fstring
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
	
	// If we are not at the end of one of the strings, continue 
    while ( (s1[i] != '\0') && 
        (s2[i] != '\0') && 
        (i < FIXSTRING_MAX - 1)) 
    {
        // If the number i character in the string s1 is
        // less than his counterpart in s2, it means it's
        // alphabeticaly less in order
        if (s1[i] < s2[i]) {
            return true;
        // If the i position in the string 1 is greater
        // than his counterpart, then its alphabeticaly
        // bigger in order   
        } else if (s1[i] > s2[i]) {
            return false;
        }
		
		// Add one to i so we check the next character inline
        i++;
    
    }

	// Assuming we landed here after finishing one of the strings
	// it means that the first i characters are equal, so if one of
	// the strings left has more characters than the other, it means
	// that its alphabetically bigger, since a character its always bigger
	// than an empty space
    if (length1 > length2) {
        return false;
    // Else if the length of 2nd string is bigger or equal to the 1st string
    // it means that the 1st string is less or equal than the 2nd string
    } else {
    	return true;
    }

    return less_eq;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
	
}


