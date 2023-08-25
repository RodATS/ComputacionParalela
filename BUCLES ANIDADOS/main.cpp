
#include <chrono>
#include <iostream>

#define MAX 10000
using namespace std;

double A[MAX][MAX], x[MAX], y[MAX];


int main() {
  int i, j;
  
  for(int aux = 0; aux < MAX; aux++)
    {
      x[aux] = aux;
      y[aux] = aux;
    }

  for(i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      A[i][j] = 1;

  
  const auto start = std::chrono::steady_clock::now();
  

  
  for(i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[j]; 


  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> timepo = end - start;
  cout<< "Prueba Bucle 1: " << timepo.count() <<endl;

  
  const auto start2 = std::chrono::steady_clock::now();
  
  for (j = 0; j < MAX; j++)
    for (i = 0; i < MAX; i++)
      y[i] += A[i][j] * x[j];

  const auto end2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> elapsed_seconds2 = end2 - start2;

  cout << "Prueba Bucle 2: "<<elapsed_seconds2.count() <<endl;

}
