#include "array_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void readArray(string filename, double arr[], int& n) {
    ifstream in(filename);
    if (!in.is_open()) { 
        cout << "Помилка відкриття файлу " << filename << endl; 
        n = 0;
        return; 
    }
    in >> n; // Зчитуємо розмір
    for (int i = 0; i < n; ++i) {
        in >> arr[i];
    }
    in.close();
}

void writeArray(string filename, const double arr[], int n) {
    ofstream out(filename);
    if (!out.is_open()) { 
        cout << "Помилка відкриття файлу " << filename << endl; 
        return; 
    }
    out << n << endl;
    for (int i = 0; i < n; ++i) {
        out << arr[i] << " ";
    }
    out << endl;
    out.close();
}

// Завдання 1: Вставка 0 після K-го елемента
void insertZeroAfterK(double arr[], int& n, int k) {
    if (k < 1 || k > n || n >= MAX_SIZE) {
        cout << "Помилка: Недопустиме значення K або масив переповнений." << endl;
        return;
    }
    // Зсув елементів вправо, починаючи з кінця, щоб звільнити місце після K
    // k - порядковий номер (1..N), індекс елемента k-1. Вставляємо на індекс k.
    for (int i = n; i > k; --i) {
        arr[i] = arr[i - 1];
    }
    arr[k] = 0.0;
    n++; // Збільшуємо розмір масиву
}

// Завдання 3: Сортування вибором за спаданням
void sortSelectionDescending(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        double temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}