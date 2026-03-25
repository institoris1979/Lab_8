#include <iostream>
#include <string>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

// Три функції для 3х завдань без параметрів
void task1() {
    double arr[MAX_SIZE];
    int n, k;
    string inFile = "array_in_8.txt";
    string outFile = "array_out_8.txt";

    cout << "--- Завдання 1 (Вставка 0 після K) ---\n";
    cout << "Введіть ціле число K (порядковий номер): ";
    cin >> k;

    readArray(inFile, arr, n);
    if (n > 0) {
        insertZeroAfterK(arr, n, k);
        writeArray(outFile, arr, n);
        cout << "Завдання 1 виконано. Результат у " << outFile << "\n";
    }
}

void task2() {
    double matr[MAX_ROWS][MAX_COLS];
    double maxCols[MAX_COLS];
    int m, n;
    string file = "matr_in_8.txt";

    cout << "--- Завдання 2 (Макс. елементи стовпців) ---\n";
    
    readMatrix(file, matr, m, n);
    if (m > 0 && n > 0) {
        findMaxInColumns(matr, m, n, maxCols);
        writeMatrixMaxCols(file, maxCols, n); // Дописуємо у той же файл
        cout << "Завдання 2 виконано. Результати дописано у " << file << "\n";
    }
}

void task3() {
    double arr[MAX_SIZE];
    int n;
    string inFile = "array_in_8.txt"; // Беремо той же файл для тесту
    string outFile = "sort_out_8.txt";

    cout << "--- Завдання 3 (Сортування вибором за спаданням) ---\n";
    
    readArray(inFile, arr, n);
    if (n > 0) {
        sortSelectionDescending(arr, n);
        writeArray(outFile, arr, n);
        cout << "Завдання 3 виконано. Відсортований масив у " << outFile << "\n";
    }
}

// Основна функція з багаторазовим вибором
int main() {
    setlocale(LC_ALL, "Ukrainian");
    int choice;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Завдання 1 (Обробка одновимірного масиву)\n";
        cout << "2. Завдання 2 (Обробка матриці)\n";
        cout << "3. Завдання 3 (Сортування)\n";
        cout << "0. Вихід\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Вихід з програми.\n"; break;
            default: cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}