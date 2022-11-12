#include <fstream>
#include <string>
#include <iostream>
using namespace std;

bool overwrite(string word) {
	string roud = "xxx.txt";
	ofstream out;
	out.open(roud, ios::out);
	if(out.is_open()){
		getline(cin, word);
		out << word;
		out.close();
	return true;
	}
	
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Задача 1.\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);

	if (out.is_open()) {
		cout << "Файл открыт для записи.\n";
		string tmp;
		do {
		cout << "Введите строку: ";
		getline(cin, tmp);
		out << tmp + '\n';
		} while (tmp != "end");
		
	}
	else
		cout << "Ошибка открытия файла.\n";

	out.close();

	ifstream in;
	in.open("file.txt");

	if (in.is_open()) {
		while (in.eof()) {
			string str;
			getline(cin, str);
			cout << str << '\n';
		}
	}
	else
		cout << "Ошибка открытия файла.\n";
	in.close();
	remove("file.txt");

	cout << "Задача 2.\n";
	string n;
	cout << "Введите строку: \n";
	cout << overwrite(n);

	return 0;
}