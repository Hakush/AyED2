#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdbool.h>
#include "weather.h"
#include "array_helpers.h"
#include <stdio.h>


int min_tempMin_hist(WeatherTable a);
/**/

void max_tempMax_eachY(WeatherTable a, int output[YEARS]);
/**/

void month_with_max_prec_eachY(WeatherTable a, unsigned int output[YEARS]);
/**/

#endif