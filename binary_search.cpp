#include <iostream>

using namespace std;

int binary_search(int a[], int search, int len, int start = 0) {
    int mid = (start + len) / 2;

    if (a[mid] < search) {
        return binary_search(a, search, len, mid + 1);
    }

    if (a[mid] > search) {
        return binary_search(a, search, mid - 1, start);
    }

    return mid;
}

int main() {
    int a[] = {1, 2, 4, 5, 7, 99, 102, 144, 201};

    cout << binary_search(a, 7, 9);

    return 0;
}