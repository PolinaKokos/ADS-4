// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                break;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int leftVal = arr[left];
            int rightVal = arr[right];
            while (left < len && arr[left] == leftVal) left++;
            while (right >= 0 && arr[right] == rightVal) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int target = value - arr[i];
        if (target < arr[i]) continue;
        int left = i + 1;
        int right = len - 1;
        int found = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                found = 1;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (found) {
            count++;
        }
    }
    return count;
}
