// INCLUDES
#include "weather_utils.h"
#include <stdlib.h>
#include "weather.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

//FUNCTIONS

int min_tempMin_hist(WeatherTable a) {
	int min = a[0][0][0]._min_temp;
	for (int i = 0; i < YEARS; ++i)
	{
		for (int j = 0; j < MONTHS; ++j)
		{
			for (int k = 0; k < DAYS; ++k)
			{
				if (a[i][j][k]._min_temp < min )
				{
					min = a[i][j][k]._min_temp;
				}
			}
		}
	}
	return min;
}

void max_tempMax_eachY(WeatherTable a, int output[YEARS]) {
	int max = a[0][0][0]._max_temp;
	for (int i = 0; i < YEARS; ++i)
	{
		max = a[i][0][0]._max_temp;

		for (int j = 0; j < MONTHS; ++j)
		{
			for (int k = 0; k < DAYS; ++k)
			{
				if (a[i][j][k]._max_temp > max)
				{
					max = a[i][j][k]._max_temp;
				}
			}
		}

		output[i] = max;

	}
}

void month_with_max_prec_eachY(WeatherTable a, unsigned int output[YEARS]) {
	int sumPrec = 0;
	int monthBeforeSumPrec = 0;
	unsigned int monthMaxSumPrec;
	for (unsigned int i = 0; i < YEARS; ++i)
	{
		monthMaxSumPrec = 0u;
		monthBeforeSumPrec = 0u;

		for (unsigned int j = 0; j < MONTHS; ++j)
		{
			sumPrec = 0;

			for (unsigned int k = 0; k < DAYS; ++k)
			{
				sumPrec = sumPrec + a[i][j][k]._rainfall;
			}

			if (sumPrec > monthBeforeSumPrec)
				{
					monthBeforeSumPrec = sumPrec;
					monthMaxSumPrec = j;
				}
		}

		output[i] = monthMaxSumPrec;

	}
}