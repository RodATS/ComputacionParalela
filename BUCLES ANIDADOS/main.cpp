#include <chrono>
#include <iostream>

#define MAX 10
using namespace std;

double A[MAX][MAX], x[MAX], y[MAX];


int main() {
  int i, j;

  const auto start = std::chrono::steady_clock::now();
  

  
  for(i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[j]; 


  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> timepo = end - start;
  cout << timepo.count() <<endl;

  
  const auto start2 = std::chrono::steady_clock::now();
  
  for (j = 0; j < MAX; j++)
    for (i = 0; i < MAX; i++)
      y[i] += A[i][j] * x[j];

  const auto end2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> elapsed_seconds2 = end2 - start2;

  cout << elapsed_seconds2.count() <<endl;

}
