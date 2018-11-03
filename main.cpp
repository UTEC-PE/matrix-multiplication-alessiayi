
#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

void multiply_threading(int *a, int **b, int **mult, int x, int i){
  for (int j=0; j< x; j++){
    int sum=0;
    for (int k=0; k< x; k++){
      sum+=a[j] * b[j][k];
    }
    mult[i][j]=sum;
  }
}

int main(){
  const int x=3;
  int a[x][x]={ {0,1,2},
                {3,4,5},
                {6,7,8}};
  int b[x][x]={ {0,1,2},
                {3,4,5},
                {6,7,8}};
  int mult[x][x];

  for(int i = 0; i < x; ++i)
    for(int j = 0; j < x; ++j){
        mult[i][j]=0;
    }

  int THREADS_NUMBER=x;

  thread threads[THREADS_NUMBER];

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i] = thread(multiply_threading, a[i], b, mult, x, i);
  }

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i].join();
  }

  cout << endl << "Rpt: " << endl;
  for(int i = 0; i < x; ++i){
    for(int j = 0; j < x; ++j){
        cout << " " << mult[i][j];
      }
    }

    return 0;
}
