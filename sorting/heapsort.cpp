#include <iostream>
#include <array>
#include <cassert>

// indexing functions dont follow The Book because
// the book is 1-indexed (and cpp is not)
int parent(int i) { return (i-1) / 2; }
int left(int i) { return (i*2) + 1; }
int right(int i) { return (i*2) + 2; }

template<int N>
void maxHeapify(std::array<int, N>& A, int heapSize, int i) {
    assert(heapSize <= N && "Heap cannot be larger than original array");
    int L = left(i);
    int R = right(i);
    int largest = i;
    if (L < heapSize && A[L] > A[i]) {
        largest = L;
    }
    if (R < heapSize && A[R] > A[largest]) {
        largest = R;
    }
    if (largest != i) {
        std::swap(A[i], A[largest]);
        maxHeapify<N>(A, heapSize, largest);
    }
}

template<int N>
void buildMaxHeap(std::array<int, N>& A) {
    for (int i = parent(N-1); i >= 0; i--) {
        maxHeapify<N>(A, N, i);
    }
}

template<int N>
void heapSort(std::array<int, N>& A) {
    int heapSize = N;
    buildMaxHeap<N>(A); 
    for (int i = N-1; i>=1; i--) {
        std::swap(A[0], A[i]); 
        heapSize--;
        maxHeapify<N>(A, heapSize, 0);
    }
}


int main() {
    constexpr int N = 10; 
    std::array<int, N> A = {6, 2, 9, 4, 0, 8, 7, 1, 5, 3};
    //buildMaxHeap<N>(A);
    heapSort<N>(A);
    for (int el: A) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    return 0;
}
