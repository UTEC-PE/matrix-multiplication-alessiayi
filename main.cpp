
#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

void multiply_threading(int a[], int b[][3], int mult[][3], int n, int i){
  for (int j=0; j< n; j++){
    int sum=0;
    for (int k=0; k< n; k++){
      sum+=a[k] * b[k][j];
    }
    mult[i][j]=sum;
  }
}

int main(){
  const int n=3;
  int a[n][n]={ {0,1,2},
                {3,4,5},
                {6,7,8}};
  int b[n][n]={ {0,1,2},
                {3,4,5},
                {6,7,8}};
  int mult[n][n];

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        mult[i][j]=0;
    }

  int THREADS_NUMBER=n;

  thread threads[THREADS_NUMBER];

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i] = thread(multiply_threading, a[i], b, mult, n, i);
  }

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i].join();
  }

  cout << endl << "Rpt: " << endl;
  for(int i = 0; i < x; ++i){
    for(int j = 0; j < x; ++j){
        cout << " " << mult[i][j];
      }
      cout << endl;
    }

    return 0;
}
