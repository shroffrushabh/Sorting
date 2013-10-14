#include <iostream>
using namespace std;

const int SIZE = 10;
void print(int *A) {
    for ( int i = 0; i < SIZE; i++ )
        cout << A[i] << " ";
    cout << endl;
}

void maxHeapify(int* A, int low, int high)
{
    int i = low;
    int leftChild = (i * 2) + 1;
    int rightChild = (i * 2) + 2;
    int largest = i;

    if(leftChild<=high && A[leftChild] > A[i])    
        largest=leftChild;
    if(rightChild<=high && A[rightChild] > A[largest])
        largest=rightChild;

    if(largest != i){
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
        maxHeapify(A,largest,high);
    }        

    return;
}

void heapify(int* A, int low, int high) {
    int mid = (high - low -1)/2;
    while (mid >= 0) {
        maxHeapify(A, mid, high);
        --mid;
    }
    return;
}

void heapSort(int* A, int size) {
    heapify(A, 0, size-1);
    int high = size - 1;
    while (high > 0) {
        int tmp = A[high];
        A[high] = A[0];
        A[0] = tmp;
        --high;
        maxHeapify(A, 0, high);
    }
    return;
}


int main() {
    int input[SIZE] = {9,5,4,6,2,1,2,0,7,8};
    cout << "Before: ";
    print(input);
    heapSort(input, SIZE);
    cout << "After: ";
    print(input);
    return 0;
}
