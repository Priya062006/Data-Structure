// Merge Sort
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int temp[100];
    int i = l;
    int j = m + 1;
    int k = l;

    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;   

    int arr[100];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];   
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
