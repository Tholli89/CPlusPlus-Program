#pragma once
#include "Source.h"

void AddSecond(int& sec1, int& sec2, int& min1, int& min2, int& clock12Hr1, int& clock12Hr2, int& clock24Hr1, int& clock24Hr2, char& dayOrNight) {
	if (sec2 < 10) {
		sec2 += 1;
	}
	if (sec2 == 10 && sec1 < 5) {
		sec2 = 0;
		sec1 += 1;
	}
	if (sec2 == 10 && sec1 == 5) {
		sec2 = 0;
		sec1 = 0;
		AddMinute(min1, min2, clock12Hr1, clock12Hr2, clock24Hr1, clock24Hr2, dayOrNight);
	}
	return;
}