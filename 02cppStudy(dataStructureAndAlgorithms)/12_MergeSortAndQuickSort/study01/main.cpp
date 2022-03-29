#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <time.h>
#include <stack>
#include <opencv2/opencv.hpp>

using namespace std;


void Merge(vector<int>& nums, vector<int>& numsTemp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            numsTemp[k++] = nums[i++];
        else
            numsTemp[k++] = nums[j++];
    }
    while (i <= mid)
        numsTemp[k++] = nums[i++];
    while (j <= right)
        numsTemp[k++] = nums[j++];

    k = left;
    while (k <= right)
    {
        nums[k] = numsTemp[k];
        k++;
    }
}

void Sort(vector<int>& nums, vector<int>& numsTemp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        Sort(nums, numsTemp, left, mid);
        Sort(nums, numsTemp, mid + 1, right);
        Merge(nums, numsTemp, left, mid, right);
    }
}
void MergeSort(vector<int>& arr) {
    int lenght = arr.size();
    vector<int> numsTemp(lenght, 0);
    Sort(arr, numsTemp, 0, lenght - 1);
}

void _QuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    while (i < j)
    {        
        while (i < j && arr[j] >= arr[left]) j--;
        while (i < j && arr[i] <= arr[left]) i++;

        swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);
    _QuickSort(arr, left, i - 1);
    _QuickSort(arr, i + 1, right);
}
void QuickSort(vector<int>& arr) {
    _QuickSort(arr, 0, arr.size()-1);
}

void _QuickSort(vector<int>& arr, int k, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= arr[left]) j--;
        while (i < j && arr[i] <= arr[left]) i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);
    if (i < k) _QuickSort(arr, k, left, i - 1);
    if (i < k) _QuickSort(arr, k, i + 1, right);
}

vector<int> QuickSort(vector<int>& arr, int k) {
    _QuickSort(arr, k, 0, arr.size());
    vector<int> res(k);
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}


int main() {

    return 0;
}

