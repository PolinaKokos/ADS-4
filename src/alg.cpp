// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
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
            int leftVal = arr[left];
            int rightVal = arr[right];
            if (leftVal == rightVal) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 0;
                int tempLeft = left;
                while (tempLeft <= right && arr[tempLeft] == leftVal) {
                    leftCount++;
                    tempLeft++;
                }
                int rightCount = 0;
                int tempRight = right;
                while (tempRight >= left && arr[tempRight] == rightVal) {
                    rightCount++;
                    tempRight--;
                }
                count += leftCount * rightCount;
                left = tempLeft;
                right = tempRight;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            while (mid > left && arr[mid - 1] == target) {
                mid--;
            }
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        if (target >= 0 && target >= arr[i]) {
            int pos = binarySearch(arr, i + 1, len - 1, target);
            if (pos != -1) {
                int targetCount = 0;
                int j = pos;
                while (j < len && arr[j] == target) {
                    targetCount++;
                    j++;
                }
                count += targetCount;
                while (i + 1 < len && arr[i] == arr[i + 1]) {
                    i++;
                }
            }
        }
    }
    return count;
}
