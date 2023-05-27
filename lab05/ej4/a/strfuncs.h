#ifndef	_STRFUNCS_H_
#define _STRFUNCS_H_

#include <stdlib.h>

size_t string_length(const char *str);
/*
	@returns length of the string {$str}
*/

char *string_filter(const char *str, char c);
/*
	@returns NEW string in heap, wich consists
	of the string {$str} without {$c} chars
*/

#endif