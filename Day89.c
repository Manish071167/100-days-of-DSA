#include <stdio.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to find sum of array
int findSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0;

        if(currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if(students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }
    return 1;
}

// Main function to solve the problem
int allocateBooks(int arr[], int n, int m) {
    if(m > n) return -1;

    int low = findMax(arr, n);
    int high = findSum(arr, n);
    int result = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);
    printf("%d\n", result);

    return 0;
}
