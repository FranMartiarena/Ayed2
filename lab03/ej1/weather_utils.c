#include "weather_utils.h"
#include "array_helpers.h"
#include "weather.h"

int min_min_temp(WeatherTable array){
    int min = array[0][0][0]._min_temp;
    for (int i = 0; i<YEARS; i++){
        for (int j = 0; j<MONTHS; j++){
            for (int k = 0; k<DAYS; k++){
                if (array[i][j][k]._min_temp < min){
                    min = array[i][j][k]._min_temp;
                }
            }
        }
    }
    return min;

}

void max_max_temp(WeatherTable array, int temps[YEARS]){
    for (int i = 0; i<YEARS; i++){
        int max = array[i][0][0]._max_temp;
        for (int j = 0; j<MONTHS; j++){
            for (int k = 0; k<DAYS; k++){
                if (max < array[i][j][k]._max_temp){
                    max = array[i][j][k]._max_temp;
                }
            }
        }
        temps[i] = max;
    }
}

void max_prec_month(WeatherTable array, int monthly_max_prec[YEARS]){
    for (int i = 0; i<YEARS; i++){
        int max_month = 0;
        int max_prec = 0;
        for (int j = 0; j<MONTHS; j++){
            int sum = 0;
            for (int k = 0; k<DAYS; k++){
                sum = sum + array[i][j][k]._rainfall;
            }
            if (max_prec < sum){
                max_month = j;
                max_prec = sum;
            }
        }
        monthly_max_prec[i] = max_month+1;
    }


}
