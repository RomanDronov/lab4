#include <iostream>
#include<string>
using namespace std;
int main() {
	char str[300];
	gets_s(str);
	//cout << str << endl;
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
// getting when the word starts
	star_coor[0] = 0;
	int j = 0;
	for (int i = 1; i < word + 1; i++) {
			star_coor[i] = end_coor[j] + 1;
			j++;
		}
	/*cout << "star coor1 ";
	for (int i = 0; i < word + 1; i++) {
		cout << star_coor[i] << " ";
	}
	cout << endl;
	cout << "end coor ";
	for (int i = 0; i < word + 1; i++) {
		cout << end_coor[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i < word + 1; i++) {
		length[i] = end_coor[i] - star_coor[i];
	}
	/*cout << "lenght" << " ";
	for (int i = 0;i < word + 1; i++) {
		cout << length[i] << " ";
	}*/
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
	int tmp = star_coor[max_pos];
	star_coor[max_pos] = star_coor[min_pos];
	star_coor[min_pos] = tmp;
	tmp = end_coor[max_pos];
	end_coor[max_pos] = end_coor[min_pos];
	end_coor[min_pos] = tmp;
	//cout << "star coor2 ";
	//for (int i = 0; i < word + 1; i++) {
	//	cout << star_coor[i] << " ";
	//}
	//cout << endl;
	/*cout << "end coor2 ";
	for (int i = 0; i < word + 1; i++) {
		cout << end_coor[i] << " ";
	}
	cout << endl;*/
	//вывод на экран
	cout << "Your string has been modified: "<<endl;
	int mass_size = 0;
	for (int p = 0; p < word + 1; p++) {
		for (int i = star_coor[p]; i < end_coor[p]; i++) {
			cout << str[i];
		}
		cout << " ";
}
	cout << endl;
	delete star_coor;
	delete end_coor;
	delete length;
	system("pause");
	return 0;
}