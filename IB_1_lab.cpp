#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int k1[5] = { 1,3,5,2,4 };
const int k2[5] = { 2,4,1,5,3 };
char word[] = ("ШИФРОВАНИЕ_ПЕРЕСТАНОВКОЙ_");

void crypt(char** mat, char* newWord, int row, int col) {
	//запись открытого текста word в матрицу mat по ключу k1
	int l = 0, p = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat[k1[l] - 1][j] = word[p];
			p++;
		}
		l++;
	}

	cout << "Промежуточный результат шифровки:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	//запись в массив newWord из матрицы mat по ключу k2
	l = 0; p = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			newWord[p] = mat[j][k2[l] - 1];
			p++;
		}
		l++;
	}

	cout << "Зашифрованный текст: " << newWord << endl << endl;
}

void decrypt(char** mat, char* newWord, int row, int col) {
	//запись в матрицу mat из массива newWord по ключу k2
	int l = 0, p = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat[j][k2[l] - 1] = newWord[p];
			p++;
		}
		l++;
	}

	cout << "Промежуточный результат расшифровки:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	//запись из матрицы mat в массив word по ключу k1  
	l = 0; p = 0;
	memset(word, 0, sizeof(word));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			word[p] = mat[k1[l] - 1][j];
			p++;
		}
		l++;
	}

	cout << "Расшифрованный текст: " << word << endl;
}


int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Шифрование перестановкой\nОткрытый текст: ШИФРОВАНИЕ_ПЕРЕСТАНОВКОЙ_" << endl << endl;

	int row = sizeof(k1) / sizeof(int); //кол-во строк матрицы
	int col = sizeof(k2) / sizeof(int); //кол-во столбцов матрицы
	char** mat = new char* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new char[col];
	char newWord[sizeof(word)] = { '\0' };
	crypt(mat, newWord, row, col);
	decrypt(mat, newWord, row, col);
	system("pause");
	return 0;
}