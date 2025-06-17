#include <iostream>
#include <array>
#include <cmath>

struct Bounds {
    int low;
    int high;
    int sum;
};

template <int N>
Bounds findMaxCrossingSubarray(const std::array<int, N>& A, int low, int mid, int high) {
    int leftSum = A[low];
    int sum = 0;
    int maxLeft = low, maxRight = high;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = A[mid+1];
    sum = 0;
    for (int j = mid+1; j<high; j++) {
        sum += A[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }
    return Bounds{maxLeft, maxRight, leftSum + rightSum};
}

template <int N>
Bounds findMaximumSubarray(const std::array<int, N>& A, int low, int high) {
    if (high == low) {
        return Bounds{low, high, A[low]};
    }
    int mid = (low + high) / 2;
    Bounds left = findMaximumSubarray<N>(A, low, mid); 
    Bounds right = findMaximumSubarray<N>(A, mid+1, high);
    Bounds cross = findMaxCrossingSubarray<N>(A, low, mid, high);
    if (left.sum >= right.sum && left.sum >= cross.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= cross.sum) {
        return right;
    } else {
        return cross;
    }
}

int main() {
    constexpr int N = 16;
    std::array<int, N> arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    Bounds max = findMaximumSubarray<N>(arr, 0, N-1);

    std::cout << max.low << ' ' << max.high << ' ' << max.sum << '\n';
    return 0;
}
