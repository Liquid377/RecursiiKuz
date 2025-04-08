#include <iostream>
#include <string>
#include <fstream>

#include "windows.h"
#include "math.h"

using namespace std;

string GpFile(int);

string ReadFromFile(string);
void WriteInFile(string, string);



bool isPrimeHelper(int, int, bool);
bool isPrime(int);

double Check(int);

int iMenu();