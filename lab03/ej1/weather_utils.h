#ifndef WEATHER_UTILS
#define WEATHER_UTILS
#include "array_helpers.h"

int min_min_temp(WeatherTable array);

void max_max_temp(WeatherTable array, int temps[YEARS]);

void max_prec_month(WeatherTable array, int monthly_max_prec[YEARS]);

#endif
