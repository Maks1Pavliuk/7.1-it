#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Q, const int rowCount, const int colCount);
void Sort(int** Q, const int rowCount, const int colCount);
void ChangeColumns(int** Q, const int col1, const int col2, const int rowCount);
void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    const int Low = -26;
    const int High = 23;
    const int rowCount = 8;
    const int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Q, rowCount, colCount);

    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Q[i][j];
        cout << endl;
    }
    cout << endl;
}

void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (Q[i][j] > 0 && Q[i][j] % 2 != 0) {
                S += Q[i][j];
                k++;
                Q[i][j] = 0;
            }
        }
    }
}

void Sort(int** Q, const int rowCount, const int colCount) {
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            bool swapNeeded = false;

            // Перевірка на перший рядок за зростанням
            if (Q[0][j] > Q[0][j + 1]) {
                swapNeeded = true;
            }
            // Якщо у першому рядку однакові елементи - другий рядок за спаданням
            else if (Q[0][j] == Q[0][j + 1] && Q[1][j] < Q[1][j + 1]) {
                swapNeeded = true;
            }
            // Якщо у першому та другому рядках однакові елементи - третій рядок за зростанням
            else if (Q[0][j] == Q[0][j + 1] && Q[1][j] == Q[1][j + 1] && Q[2][j] > Q[2][j + 1]) {
                swapNeeded = true;
            }

            if (swapNeeded)
                ChangeColumns(Q, j, j + 1, rowCount);
        }
    }
}

void ChangeColumns(int** Q, const int col1, const int col2, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = tmp;
    }
}
