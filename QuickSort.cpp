#include <iostream>
using namespace std;

const int SIZE = 10;
int partition(int* input, int p, int q) {
    int x = input[q];
    int i = p-1, tmp;
    for (int k=p;k<=q-1;k++) {
        if (x >= input[k]){
            i++;
            tmp = input[i];
            input[i] = input[k];
            input[k] = tmp;
        }
    }
    tmp = input[i+1];
    input[i+1] = input[q];
    input[q] = tmp;
    
    return i+1;
}

void quicksort(int* input, int p, int r) {
    if ( p < r ) {
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

void print(int *A) {
    for ( int i = 0; i < SIZE; i++ )
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int input[SIZE] = {9,5,4,6,2,1,2,0,7,8};
    cout << "Before: ";
    print(input);
    quicksort(input, 0, 9);
    cout << "After: ";
    print(input);
    return 0;
}
