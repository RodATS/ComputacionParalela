
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//definir tamaños de las matrices
int n = 10;
int m = 10;
int p = 10;

// Función para multiplicar dos matrices por bloques
vector<vector<int>> multiplyMatricesByBlocks(vector<vector<int>>& A, vector<vector<int>>& B, int blockSize) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();

    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < m; j += blockSize) {
            for (int k = 0; k < p; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, n); ii++) {
                    for (int jj = j; jj < min(j + blockSize, m); jj++) {
                        for (int kk = k; kk < min(k + blockSize, p); kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }

    return C;
}

//funcion multplicacion de matrices clasica
vector<vector<int>> multiplicacionClasica(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();

    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int filas = 0; filas < n; filas++) {
        for (int columnasC = 0; columnasC < m; columnasC++) {
            for (int columnas = 0; columnas < p; columnas++) {
                C[filas][columnasC] += A[filas][columnas] * B[columnas][filas];
            }
        }
    }

    return C;

}


void imprimir(vector<vector<int>> C) {
    // Imprimir el resultado
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A(n, vector<int>(p, 5));
    vector<vector<int>> B(p, vector<int>(m, 2));

    imprimir(A);
    imprimir(B);
    // Especificar el tamaño del bloque
    int blockSize = 2;
    
    // Multiplicar las matrices por bloques

    const auto start = std::chrono::steady_clock::now();
    vector<vector<int>> C = multiplyMatricesByBlocks(A, B, blockSize);
    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> timepo = end - start;
    cout << "Prueba multiplicacion clasica: " << timepo.count() << endl;


    imprimir(C);
    
     //multiplicacion clasica
    cout << "\n\nMultplicacion normal:\n";
   
    const auto start2 = std::chrono::steady_clock::now();

    vector<vector<int>> C2 = multiplicacionClasica(A, B);
    const auto end2 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> timepo2 = end2 - start2;
    cout << "Prueba multiplicacion clasica: " << timepo2.count() << endl;

    imprimir(C2);


    return 0;
}
