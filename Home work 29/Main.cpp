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
	cout << "������ 1.\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);

	if (out.is_open()) {
		cout << "���� ������ ��� ������.\n";
		string tmp;
		do {
		cout << "������� ������: ";
		getline(cin, tmp);
		out << tmp + '\n';
		} while (tmp != "end");
		
	}
	else
		cout << "������ �������� �����.\n";

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
		cout << "������ �������� �����.\n";
	in.close();
	remove("file.txt");

	cout << "������ 2.\n";
	string n;
	cout << "������� ������: \n";
	cout << overwrite(n);

	return 0;
}