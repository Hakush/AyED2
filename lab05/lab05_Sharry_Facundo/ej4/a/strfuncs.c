#include <stdlib.h>
#include <stdio.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
	size_t length = 0u;
	while(str[length] != '\0') {
		++length;
	}
	return(length);
}

char *string_filter(const char *str, char c) {
	size_t i = 0u;
	size_t j = 0u;
	size_t length = string_length(str);
	char * str_res = calloc(length, sizeof(char));
	while(i < length) {
		if (str[i] != c) {
			str_res[j] = str[i]; 
			++j;
		}
		++i;
	}

	return str_res;
}