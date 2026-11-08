#include<stdio.h>
int tool(int *arr,int left, int right) {
    int high = right;
    int low = left;
    int temp = arr[left];
    while (low < high) {
        while (arr[high] > temp && low < high) {
            high--;
        }
        arr[low] = arr[high];
        while (arr[low] < temp && low < high) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}
void quicksort(int *arr, int left, int right) {
    if (left < right) {
        int low = tool(arr, left, right);
        quicksort(arr, left, low - 1);
        quicksort(arr, low + 1, right);
    }
}
int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9, -1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}