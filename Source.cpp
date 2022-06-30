#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Задача 1
int randomNumber(int &min, int &max) {
	if (max <= min)
		throw invalid_argument("Конец диапазона должен быть больше, чем его начало");
	srand(time(NULL));
	int z = rand() % (max - min) + min;
	return z;
}

// Задача 2
bool word_and_size() {
	string str, str1;
	int number, space = 0, sumWords = 0;
	cout << "Введите слово и его длину (через пробел): ";
	getline(cin, str);
	// Подсчёт пробелов
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			space++;
	}
	// Если пробелов больше одного
	if (space != 1)
		throw runtime_error("Неверный формат.\nПодсказка: Необходимо ввести слово и его длину (через пробел)");

	int index = str.find(" ");
	// Проверка на наличие посторонних символов в слове до пробела
	for (int i = 0; i < index; i++) {
		if (str[i] < char(65))
			throw runtime_error("Слова должны содержать только буквы");
	}
	// Проверка на наличие цифры после пробела
	for (int i = index + 1; i < str.size(); i++) {
		if (str[i] != char(48) && str[i] != char(49) && str[i] != char(50) && str[i] != char(51) && str[i] != char(52) && str[i] != char(53) && str[i] != char(54) && str[i] != char(55) && str[i] != char(56) && str[i] != char(57))
			throw runtime_error("После пробела должна быть указана длина слова (в циферном обозначении)");
	}
	// Получение введённого числа
	for (int i = index + 1; i < str.size(); i++)
		str1 += str[i];
	number = stoi(str1);
	// Подсчёт реального количества букв в слове
	for (int i = 0; i < index; i++) {
		str1 += str[i];
		sumWords++;
	}
	// Сравнение реального количества букв в слове с введённым значением
	if (sumWords != number)
		return false;
	return true;
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, m;
	bool f = false;


	// Задача 1.
	cout << "Задача 1.\n\n";
	do {
		cout << "Введите начало диапазона: ";
		cin >> n;
		cin.ignore();
		cout << "Введите конец диапазона: ";
		cin >> m;
		cin.ignore();
		try {
			cout << "Случайное число входящее в диапазон = " << randomNumber(n, m) << "\n\n";
			f = true;
		}
		catch (const invalid_argument& ex) {
			cout << "Ошибка! " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (f == false);
	

	// Задача 2.
	cout << "Задача 2.\n\n";
	f = false;

	do {
		try {
			if (word_and_size() == true) {
				cout << "\nПравда! Введённое слово равно введённой длине.\n\n";
				f = true;
			}
			else {
				cout << "\nНе правда! Введённое слово не равно введённой длине.\n\n";
				f == false;

			}
		}
		catch (const runtime_error& ex) {
			cout << "Ошибка! " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (f == false);

	return 0;
}