#include <iostream>
#include <array>

template <int N>
int partition(std::array<int, N>& A, int p, int r) {
    int x = A[r-1];  
    int i = p-1;
    for (int j = p; j<r-1; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r-1]); 
    return i+1;
}

template <int N>
void quickSort(std::array<int, N>& A, int p = 0, int r = N) {
    if (p < r) {
        int q = partition<N>(A, p, r);
        quickSort<N>(A, p, q);
        quickSort<N>(A, q+1, r);
    }
}

int main() {
    constexpr int N = 10;
    std::array<int, N> A = {5, 4, 9, 7, 1, 0, 2, 6, 3, 8};
    
    quickSort<N>(A);
   // std::cout << "q: " << partition<N>(A, 0, N) << '\n';
   // std::cout << "q: " << partition<N>(A, 0, 8) << '\n';
   // std::cout << "q: " << partition<N>(A, 0, 3) << '\n';
   // std::cout << "q: " << partition<N>(A, 0, 2) << '\n';
    
    for (int el: A) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    return 0;
}
