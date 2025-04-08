#include "my.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int iM;
	int n;
	string sFile;
	sFile = GpFile(1);
	try {
		system("cls");
		n = stoi(ReadFromFile(sFile));
		cout << "Файл содержит в себе следующее число: " << n << endl << endl;
		system("pause");
	}
	catch (...) {
		n = 2;
		cout << "Файл содержал не целочисленное число, поэтому программа автоматически выбрала значение для расчёта - 2." << endl << endl;
		system("pause");
	}
	do {
		iM = iMenu();
		switch (iM) {
		case 1:
			system("cls");
			if (isPrime(n))
				cout << "Простое число." << endl;
			else
				cout << "Не простое число." << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			if (Check(n))
				cout << "Простое число." << endl;
			else
				cout << "Не простое число." << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			sFile = GpFile(2);
			WriteInFile(sFile, to_string(n));
			system("pause");
			break;
		case 4:
			system("cls");
			sFile = GpFile(1);
			cout << ReadFromFile(sFile) << endl << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			cout << endl << "Программа завершила свою работу." << endl << endl;
		}
	} while (iM != 5);

}
