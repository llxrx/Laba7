#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int x,y;
	x = y = 0;
	while (y < 10) {
		x += ++y;
	}
	cout << x << ' ' << y;

}

//int main() {
//    setlocale(LC_ALL, "Rus");
//    int digitals[10] = { 4, 6, 2, 3, 1, 7, 8, 5, 9, 10 };
//    
//
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 9; j++) {
//            if (digitals[j] > digitals[j + 1]) {
//                int b = digitals[j]; // создали дополнительную переменную
//                digitals[j] = digitals[j + 1]; // меняем местами
//                digitals[j + 1] = b; // значения элементов
//            }
//        }
//    }
//
//    cout << "Массив в отсортированном виде: ";
//
//    for (int i = 0; i < 10; i++) {
//        cout << digitals[i] << " "; // выводим элементы массива
//    }
//    return 0;
//}