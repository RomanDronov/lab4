#include <iostream>
#include<string>
using namespace std;
int main() {
	string s2;
	int start;
	char str[300];
	gets_s(str);
	cout << str << endl;
	cout << strlen(str) << endl;
	int word = 0;
	//size of the massive for the coordinates of the word, i like cats
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			word++;
		}
	}
	int *star_coor = new int[word + 1];
	int *end_coor = new int[word + 1];
	int *length = new int[word + 1];
	cout << "word" << word << endl;
	int a = 0;
	//looking for the ccordinates of the word
	for (int i = 0; i < strlen(str)+2; i++) {
		if (str[i] == ' ') {
			end_coor[a] = i;
			a++;
		}
		if (str[i] == '\0') {
			end_coor[a] = i;
			a++;
			break;
		}
	}
	cout << "a" << a << endl;
	cout << "mass" << endl;
	for (int i = 0; i < word + 1; i++) {
		cout << end_coor[i] << " ";
}
// getting when the word starts
	star_coor[0] = 0;
	int j = 0;
	for (int i = 1; i < word + 1; i++) {
			star_coor[i] = end_coor[j] + 1;
			j++;
		}
	cout << "mass2";
	for (int i = 0; i < word + 1; i++) {
		cout << star_coor[i] << " ";
	}
	for (int i = 0; i < word + 1; i++) {
		length[i] = end_coor[i] - star_coor[i];
	}
	cout << "lenght" << " ";
	for (int i = 0;i < word + 1; i++) {
		cout << length[i] << " ";
	}
	int max = 0;
	int max_pos;
	for (int i = 0; i < word + 1; i++) {
		if (length[i] > max) {
			max = length[i];
			max_pos = i;
		}
	}
	int min = length[0];
	int min_pos;
	for (int i = 0; i < word + 1; i++) {
		if (length[i]<min) {
			min = length[i];
			min_pos = i;
		}
	}
	cout << "min pos" << min_pos << endl;
//	cout << "number of words" << word << endl;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			start = i;
			break;
			}
		//else cout<<"p";
		//cout << "num" << i << endl;
		}
	/*for (int i = 0; i < start; i++) {
		cout << str[i];
	}*/
	cout << endl;
	delete star_coor;
	delete end_coor;
	delete length;
	system("pause");
	return 0;
}








//#include <iostream>
//#include <conio.h>
//#include <cstring>
//#include <windows.h>
//using namespace std;
//
//int main()
//{
//	SetConsoleCP(1251); 
//	setlocale(LC_ALL, "Russian");
//
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	char str[80];
//	char token[80];
//	int t, g;
//	cout << "Enter string:\n";
//	gets_s(str);
//
//	cout << "\n\Your entered: " << str << '\n';
//	cout << "Lenght: " << strlen(str) << '\n';
//	cout << "\n";
//
//	// Считываем лексему из строки.
//	for (t = 0; ; t++)
//	{
//		for (g = 0; str[t] != ' ' && str[t]; g++, t++)
//			token[g] = str[t];
//		token[g] = '\0'; // Завершаем лексему нулевым символом.
//
//		cout << "\nWord: " << token << '\t';
//		cout << "Lenght: " << strlen(token) << '\n';
//		for (int i = 0; i < 80; i++) {
//
//		}
//		if (!str[t]) break;
//	}
//	_kbhit();
//	system("pause");
//	return 0;
//}
