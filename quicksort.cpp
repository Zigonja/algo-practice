#include <iostream>

using namespace std;

int get_max(int arr[]) {
    int max = INT_MIN;

    for (int i = 0; i < 3; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int get_min(int arr[]) {
    int min = INT_MAX;

    for (int i = 0; i < 3; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int pivot(int arr[], int start, int end) {
    int pivot = arr[end];
    int item_from_left  = NULL; arr[i];
    int item_from_right = NULL; arr[end - i];
    
    for (int i = start; i < end - 1; i++) {
        if (item_from_left == NULL && arr[i] > pivot) {
            item_from_left = i;
        }
        
        if (item_from_right == NULL && arr[end - i - 1] < pivot) {
            item_from_right = end - i - 1;
        }

        if (item_from_left < item_from_right) {
            int tmp = arr[item_from_left];
            arr[item_from_left] = arr[item_from_right];
            arr[item_from_right] = tmp;
        }

        arr[end] = arr[item_from_right];
        arr[item_from_right] = pivot;
    }
}

void quicksort(int arr[], int start, int end) {
    if (end <= start) {
        return;
    }

    pivot(arr, start, end / 2);
    pivot(arr, end / 2 + 1, end);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n = 10;
    int arr[] = {5, 7, 2, 1, 9, 0, 3, 6, 4, 8};
    print_array(arr, n);
    quicksort(arr, 0, n - 1);
    cout << "\n";
    print_array(arr, n);
}