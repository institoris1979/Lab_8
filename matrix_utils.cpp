#include "matrix_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void readMatrix(string filename, double matr[][MAX_COLS], int& m, int& n) {
    ifstream in(filename);
    if (!in.is_open()) { 
        cout << "Помилка відкриття файлу " << filename << endl; 
        m = 0; n = 0;
        return; 
    }
    in >> m >> n; 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matr[i][j];
        }
    }
    in.close();
}

// Дописування результату у той самий файл (ios::app)
void writeMatrixMaxCols(string filename, const double maxCols[], int n) {
    ofstream out(filename, ios::app);
    if (!out.is_open()) { 
        cout << "Помилка відкриття файлу " << filename << endl; 
        return; 
    }
    out << "\nМаксимальні елементи по стовпцях:\n";
    for (int j = 0; j < n; ++j) {
        out << maxCols[j] << " ";
    }
    out << endl;
    out.close();
}

// Завдання 2: Максимальний елемент у кожному стовпці
void findMaxInColumns(const double matr[][MAX_COLS], int m, int n, double maxCols[]) {
    for (int j = 0; j < n; ++j) {
        double max_val = matr[0][j];
        for (int i = 1; i < m; ++i) {
            if (matr[i][j] > max_val) {
                max_val = matr[i][j];
            }
        }
        maxCols[j] = max_val;
    }
}