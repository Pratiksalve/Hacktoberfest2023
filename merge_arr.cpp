#include <iostream>
#include <algorithm>
using namespace std;

void minHeapify(int brr[], int i, int M) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < M && brr[left] < brr[smallest]) {
        smallest = left;
    }

    if (right < M && brr[right] < brr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(brr[i], brr[smallest]);
        minHeapify(brr, smallest, M);
    }
}

void merge(int arr[], int brr[], int N, int M) {
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] > brr[0]) {
            swap(arr[i], brr[0]);
            minHeapify(brr, 0, M);
        }
    }

    sort(arr, arr + N);
    sort(brr, brr + M);
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}

int main() {
    int N, M;
    cout << "Enter the size of arr: ";
    cin >> N;
    int arr[N];

    cout << "Enter elements for arr: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Enter the size of brr: ";
    cin >> M;
    int brr[M];

    cout << "Enter elements for brr: ";
    for (int i = 0; i < M; i++) {
        cin >> brr[i];
    }

    merge(arr, brr, N, M);

    cout << "Merged arr: ";
    printArray(arr, N);

    cout << "\nMerged brr: ";
    printArray(brr, M);

    int mergedArray[N + M];
    int k = 0;

    for (int i = 0; i < N; i++) {
        mergedArray[k++] = arr[i];
    }

    for (int i = 0; i < M; i++) {
        mergedArray[k++] = brr[i];
    }

    sort(mergedArray, mergedArray + (N + M));

    cout << "\nMerged array: ";
    for (int i = 0; i < N + M; i++) {
        cout << mergedArray[i] << " ";
    }

    return 0;
}
