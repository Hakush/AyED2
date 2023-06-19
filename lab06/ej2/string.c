#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _s_string {
    char *content;
    unsigned int length;
};

string string_create(const char *word) {
    string str = NULL;
    str = calloc(1, sizeof(struct _s_string));
    str->length = strlen(word);
    str->content = calloc(str->length + 1, sizeof(char));
    str->content = strncpy(str->content, word, str->length + 1);
    return (str);
}

unsigned int string_length(string str) {
    return (str->length);
}

bool string_less(const string str1, const string str2) {
    bool less_eq = true;
    unsigned int i = 0;
    unsigned int length1 = string_length(str1);
    unsigned int length2 = string_length(str2);
	
	// If we are not at the end of one of the strings, continue 
    while ( (str1->content[i] != '\0') && 
        (str2->content[i] != '\0')) 
    {
        // If the number i character in the string s1 is
        // less than his counterpart in s2, it means it's
        // alphabeticaly less in order
        if (str1->content[i] < str2->content[i]) {
            return true;
        // If the i position in the string 1 is greater
        // than his counterpart, then its alphabeticaly
        // bigger in order   
        } else if (str1->content[i] > str2->content[i]) {
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
    if (length1 >= length2) {
        return false;
    // Else if the length of 2nd string is bigger than the 1st string
    // it means that the 1st string is less than the 2nd string
    } else {
    	return true;
    }
    return less_eq;
}

bool string_eq(const string str1, const string str2) {
    int cmp = strcmp(str1->content, str2->content);
    return (cmp == 0);
}

string string_clone(const string str) {
    return (string_create(str->content));
}

string string_destroy(string str) {
    free(str->content);
    free(str);
    str = NULL;
    return (str);
}

void string_dump(string str, FILE *file) {
    fprintf(file, "%s", str->content);
}

const char *string_ref(string str) {
    return (str->content);
}
