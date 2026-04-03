// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value)
{
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
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int countPairs3(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    if (target >= arr[i]) {
      int left = i + 1;
      int right = len - 1;
      int firstPos = -1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
          firstPos = mid;
          right = mid - 1;
        } else if (arr[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      if (firstPos != -1) {
        int lastPos = firstPos;
        while (lastPos + 1 < len && arr[lastPos + 1] == target) {
          lastPos++;
        }
        count += (lastPos - firstPos + 1);
        while (i + 1 < len && arr[i] == arr[i + 1]) {
          i++;
        }
      }
    }
  }
  return count;
}
