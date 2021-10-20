#pragma once
#include "Source.h"

using namespace std;

void PrintClock(int sec1, int sec2, int min1, int min2, int clock12Hr1, int clock12Hr2, int clock24Hr1, int clock24Hr2, char colon, char dayOrNight) {

	cout << "\t**************************\t" << "**************************" << endl;
	cout << "\t*      12-Hour Clock     *\t" << "*      24-Hour Clock     *" << endl;
	cout << "\t*       " << clock12Hr1 << clock12Hr2 << colon << min1 << min2 << colon << sec1 << sec2 << " " << dayOrNight << "M" << "      *\t";
	cout << "*        " << clock24Hr1 << clock24Hr2 << colon << min1 << min2 << colon << sec1 << sec2 << "        *" << endl;
	cout << "\t**************************\t" << "**************************";
	cout << endl;

	cout << "\t                          Options" << endl;
	cout << "\t                **************************" << endl;
	cout << "\t                * 1-Add one hour         *" << endl;
	cout << "\t                * 2-Add one minute       *" << endl;
	cout << "\t                * 3-Add one second       *" << endl;
	cout << "\t                * 4-Quit                 *" << endl;
	cout << "\t                **************************" << endl;
}