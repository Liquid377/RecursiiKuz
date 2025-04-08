#pragma once
#include "my.cpp"



string GpFile(int i) {
	string File;

	if (i == 1) {
		cout << "Введите название вашего файла для считывания значений(по умолчанию input.txt)." << endl;
		cout << "Или введите '1' для создания нового файла." << endl;
		cout << "Ввод: ";
		getline(cin, File);
		if (File == "") {
			File = "input.txt";
		}
		if (File == "1") {
			system("cls");
			cout << "Введите желаемое название файла(по умолчанию input.txt): ";
			getline(cin, File);
			if (File == "") {
				File = "input.txt";
			}
			ofstream file(File);
			cout << "Файл успешно создан." << endl;
			system("pause");
			system("cls");
			cout << "Введите число, которое будет записано в файл и будет использоваться в дальнейшем при расчётах: ";
			string sString;
			getline(cin, sString);
			file << sString;
			cout << "Результат '" << sString << "' записан в ваш файл." << endl;
			system("pause");
			system("cls");
		}
	} else {
		cout << endl << "Введите название вашего файла для вывода значений(по умолчанию output.txt)." << endl;
		getline(cin, File);
		if (File == "") {
			File = "output.txt";
		}
	}

	return File;
}

string ReadFromFile(string pFile) {
	ifstream file(pFile);
	string sFile;
	int n;

	if (!file) {
		cout << "Файла с таким названием не существует. Попробуйте ещё." << endl << endl;
		pFile = GpFile(1);
		ReadFromFile(pFile);
	}
	file >> sFile;

	try {
		n = stoi(sFile);
	}
	catch (...) {
		sFile = 2;
		cout << "Файл содержал не целочисленное число, поэтому программа" 
			L"автоматически выбрала значение для расчёта - 2." << endl << endl;
	}

	return sFile;
}


bool isPrimeHelper(int n, int divisor, bool isDivisible) {
	if (n < 2)
		isDivisible = true;
	else if (n % divisor == 0)
		isDivisible = true;
	else if (divisor * divisor > n)
		isDivisible = !isDivisible;

	if (divisor * divisor <= n)
		isDivisible = isPrimeHelper(n, divisor + 1, isDivisible);

	return isDivisible;
}

bool isPrime(int n) {
	return isPrimeHelper(n, 2, false);
}

double Check(int n) {
	bool isDivisible = false;

	if (n < 2)
		isDivisible = true;
	else {
		int divisor = 2;
		while (divisor * divisor <= n && !isDivisible) {
			if (n % divisor == 0)
				isDivisible = true;
			++divisor;
		}
	}

	return !isDivisible;
}

void WriteInFile(string path, string sString) {
	ofstream file(path);
	if (isPrime(stoi(sString)))
		sString = sString + " - простое число.";
	else 
		sString = sString + " - не простое число.";
	file << sString;
	cout << endl << "Результат '" << sString << "' записан в файл." << endl << endl;
}

int iMenu() {
	system("cls");
	string input;
	int i;
	bool valid = false;

	cout << "Меню:" << endl;
	cout << "1. Выполнить задание рекурсивной функцией." << endl;
	cout << "2. Проверить результаты функцией с циклом." << endl;
	cout << "3. Записать результаты в файл." << endl;
	cout << "4. Вывести результаты из файла." << endl;
	cout << "5. Выход." << endl;
	cout << "Выберите пункт меню: ";

	while (valid == false) {
		try {
			getline(cin, input);
			i = stoi(input);
			cout << i;
			if (i >= 1 && i <= 5) {
				valid = true;
			}
		}
		catch (...) {
			cout << endl << endl << "Некорректный ввод. Попробуйте ещё! " << endl;
			cout << "Выберите пункт меню: ";

		}
	}
	return i;
}