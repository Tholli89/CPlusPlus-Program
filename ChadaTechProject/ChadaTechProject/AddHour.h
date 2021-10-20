#pragma once
#include "Source.h"

void AddHour(int& clock12Hr1, int& clock12Hr2, int& clock24Hr1, int& clock24Hr2, char& dayOrNight) {
if (clock12Hr2 < 10) {
	clock12Hr2 += 1;
}
if (clock12Hr2 == 10) {
	clock12Hr1 = 1;
	clock12Hr2 = 0;
}
if (clock12Hr1 == 1 && clock12Hr2 == 3) {
	clock12Hr1 = 0;
	clock12Hr2 = 1;
	if (dayOrNight == 'A') {
		dayOrNight = 'P';
	}
	else if (dayOrNight == 'P') {
		dayOrNight = 'A';
	}
}
if (clock24Hr2 < 10) {
	clock24Hr2 += 1;
}
if (clock24Hr1 == 0 && clock24Hr2 == 10) {
	clock24Hr1 = 1;
	clock24Hr2 = 0;
}
if (clock24Hr1 == 1 && clock24Hr2 == 10) {
	clock24Hr1 = 2;
	clock24Hr2 = 0;
}
if (clock24Hr1 == 2 && clock24Hr2 == 4) {
	clock24Hr1 = 0;
	clock24Hr2 = 0;
}
return;
}
