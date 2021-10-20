#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("program");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"program");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"program");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main()
{   //temporary variable to hold the users choice as a string
	string tempChoice;
	//variable to hold the users choice after validation
	int userChoice;
	//temporary variable to hold the users value as a string
	string tempValue;
	//variable to hold the users number after validation
	int userNum;

	//a do while loop to iterate until the user selects option 3
	do {
		//main display to user showing options and prompting for a user input choice
		cout << "1 : Display a Multiplication Table" << endl;
		cout << "2 : Double a Value" << endl;
		cout << "3 : Exit" << endl;
		cout << "Enter your selection as a number 1, 2, or 3." << endl;
		//temporary variable storing users choice as string until validated
		cin >> tempChoice;
		//a try block to test and validate the users input consists of digits
		try {
			//for loop that iterates over each element of users input
			for (unsigned int i = 0; i < tempChoice.length(); ++i) {
				//if statement that throws an error if one of the elements is not a nuber
				if (tempChoice.at(i) != '0' && tempChoice.at(i) != '1' && tempChoice.at(i) != '2' && tempChoice.at(i) != '3' && tempChoice.at(i) != '4' &&
					tempChoice.at(i) != '5' && tempChoice.at(i) != '6' && tempChoice.at(i) != '7' && tempChoice.at(i) != '8' && tempChoice.at(i) != '9') {
					throw(0);
				}
				//else statement that stores the users choice into an int variable if all elements are numeric
				else {
					userChoice = stoi(tempChoice);
				}
			}
		}
		//catch block if an error of type 0 is thrown that prints error message to user and sets userChoice variable to null
		catch (int num) {
			if (num == 0) {
				cout << "That option is not Available: Please choose one of the following options" << endl;
				cout << endl;
				userChoice = NULL;
			}
		}
		//clears the screen 
		system("CLS");

		//if statement that is taken if the userChoice is 1
		if (userChoice == 1) {
			//asks user for a number to be multiplied and saves in to a temp string variable to be verified
			cout << "enter a number to be multiplied: ";
			cin >> tempValue;
			//a try block to test and validate the users input consists of digits 
			try {
				//for loop that iterates over each element of users input
				for (unsigned int i = 0; i < tempValue.length(); ++i) {
					//if statement that throws an error if one of the elements is not a nuber
					if (tempValue.at(i) != '0' && tempValue.at(i) != '1' && tempValue.at(i) != '2' && tempValue.at(i) != '3' && tempValue.at(i) != '4' &&
						tempValue.at(i) != '5' && tempValue.at(i) != '6' && tempValue.at(i) != '7' && tempValue.at(i) != '8' && tempValue.at(i) != '9') {
						throw(1);
					}
					//else statement that stores the users choice into an int variable if all elements are numeric
					else {
						userNum = stoi(tempValue);
					}
				}
				//display that prints a header and calls on the multiplicationTabel function from python passing the users number as an argument
				cout << endl;
				cout << "=====Multiplication Table=====" << endl;
				cout << callIntFunc("MultiplicationTable", userNum) << endl;
				cout << endl;
			}
			//catch block if an error of type 1 is thrown that prints error message to user
			catch (int num) {
				if (num == 1) {
					cout << endl;
					cout << "(You must enter a numeric value to show the multiplication table)" << endl;
					cout << endl;
				}
			}
		}

		//else if statement that executes if user choice is 2
		else if (userChoice == 2) {
			//asks user for a number to be doubled and stores it to a temp variable to be verified
			cout << "enter a number to be Doubled: ";
			cin >> tempValue;
			//a try block to test and validate the users input consists of digits
			try {
				//for loop that iterates over each element of users input
				for (unsigned int i = 0; i < tempValue.length(); ++i) {
					//if statement that throws an error if one of the elements is not a nuber
					if (tempValue.at(i) != '0' && tempValue.at(i) != '1' && tempValue.at(i) != '2' && tempValue.at(i) != '3' && tempValue.at(i) != '4' &&
						tempValue.at(i) != '5' && tempValue.at(i) != '6' && tempValue.at(i) != '7' && tempValue.at(i) != '8' && tempValue.at(i) != '9') {
						throw(2);
					}
					//else statement that stores the users choice into an int variable if all elements are numeric
					else {
						userNum = stoi(tempValue);
					}
				}
				//display that prints a header and calls on the DoubleValue function from python passing the users number as an argument
				cout << endl;
				cout << "=====Number Doubled=====" << endl;
				cout << callIntFunc("DoubleValue", userNum) << endl;
				cout << endl;
			}
			//catch block if an error of type 2 is thrown that prints error message to user
			catch (int num) {
				if (num == 2) {
					cout << endl;
					cout << "(You must enter a numeric value to be doubled) " << endl;
					cout << endl;
				}
			}
		}

		//else if statement that executes if user choice is 3 and terminates the program
		else if (userChoice == 3) {
			terminate;
		}

		//else statement that executes if no other path is taken and prints error message
		else {
			cout << "(That option is not Available: Please choose one of the following options)" << endl;
			cout << endl;
		}


	}while(userChoice != 3);

}