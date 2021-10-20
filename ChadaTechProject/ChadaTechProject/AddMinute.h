#pragma once
#include "Source.h"


void AddMinute(int& min1, int& min2, int& clock12Hr1, int& clock12Hr2, int& clock24Hr1, int& clock24Hr2, char& dayOrNight) {
	if (min2 < 10) {
		min2 += 1;
	}
	if (min2 == 10 && min1 < 5) {
		min2 = 0;
		min1 += 1;
	}
	if (min2 == 10 && min1 == 5) {
		min1 = 0;
		min2 = 0;
		AddHour(clock12Hr1, clock12Hr2, clock24Hr1, clock24Hr2, dayOrNight);
	}
	return;
}
