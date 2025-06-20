#include <iostream>
#include <cassert>
#include <vector>

// indexing functions dont follow The Book because
// the book is 1-indexed (and cpp is not)
int parent(int i) { return (i-1) / 2; }
int left(int i) { return (i*2) + 1; }
int right(int i) { return (i*2) + 2; }

int maximum(const std::vector<int>& S) {
    return S[0]; 
}

void maxHeapify(std::vector<int>& S, int i) {
    int L = left(i);
    int R = right(i);
    int largest = i;
    if (L < S.size() && S[L] > S[i]) {
        largest = L;
    }
    if (R < S.size() && S[R] > S[largest]) {
        largest = R;
    }
    if (largest != i) {
        std::swap(S[i], S[largest]);
        maxHeapify(S, largest);
    }
}

int extractMaximum(std::vector<int>& S) {
    assert(!S.empty() && "Cannot extract on an empty heap");
    int max = S[0];
    S[0] = S[S.size() - 1];
    S.pop_back();
    maxHeapify(S, 0);
    return max;
}

void increaseKey(std::vector<int>& S, int i, int key) {
    assert(key >= S[i] && "Key is smaller than current value");
    S[i] = key;
    for (; i > 0 && S[parent(i)] < S[i]; i = parent(i)) {
        std::swap(S[i], S[parent(i)]);
    }
}

void insert(std::vector<int>& S, int x) {
    S.push_back(x);
    increaseKey(S, S.size()-1, x);
}

int main() {
    std::vector<int> S; 

    insert(S, 5);
    insert(S, 1);
    insert(S, 10);
    insert(S, 2);
    insert(S, 7);

    for (int el: S) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    return 0;
}
