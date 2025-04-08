#pragma once
#include "my.cpp"



string GpFile(int i) {
	string File;

	if (i == 1) {
		cout << "������� �������� ������ ����� ��� ���������� ��������(�� ��������� input.txt)." << endl;
		cout << "��� ������� '1' ��� �������� ������ �����." << endl;
		cout << "����: ";
		getline(cin, File);
		if (File == "") {
			File = "input.txt";
		}
		if (File == "1") {
			system("cls");
			cout << "������� �������� �������� �����(�� ��������� input.txt): ";
			getline(cin, File);
			if (File == "") {
				File = "input.txt";
			}
			ofstream file(File);
			cout << "���� ������� ������." << endl;
			system("pause");
			system("cls");
			cout << "������� �����, ������� ����� �������� � ���� � ����� �������������� � ���������� ��� ��������: ";
			string sString;
			getline(cin, sString);
			file << sString;
			cout << "��������� '" << sString << "' ������� � ��� ����." << endl;
			system("pause");
			system("cls");
		}
	} else {
		cout << endl << "������� �������� ������ ����� ��� ������ ��������(�� ��������� output.txt)." << endl;
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
		cout << "����� � ����� ��������� �� ����������. ���������� ���." << endl << endl;
		pFile = GpFile(1);
		ReadFromFile(pFile);
	}
	file >> sFile;

	try {
		n = stoi(sFile);
	}
	catch (...) {
		sFile = 2;
		cout << "���� �������� �� ������������� �����, ������� ���������" 
			L"������������� ������� �������� ��� ������� - 2." << endl << endl;
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
		sString = sString + " - ������� �����.";
	else 
		sString = sString + " - �� ������� �����.";
	file << sString;
	cout << endl << "��������� '" << sString << "' ������� � ����." << endl << endl;
}

int iMenu() {
	system("cls");
	string input;
	int i;
	bool valid = false;

	cout << "����:" << endl;
	cout << "1. ��������� ������� ����������� ��������." << endl;
	cout << "2. ��������� ���������� �������� � ������." << endl;
	cout << "3. �������� ���������� � ����." << endl;
	cout << "4. ������� ���������� �� �����." << endl;
	cout << "5. �����." << endl;
	cout << "�������� ����� ����: ";

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
			cout << endl << endl << "������������ ����. ���������� ���! " << endl;
			cout << "�������� ����� ����: ";

		}
	}
	return i;
}