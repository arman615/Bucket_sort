#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<double>& arr) {
    int n = arr.size();
    std::vector<std::vector<double>> buckets(n);
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }
    int index = 0;
    for (const auto& bucket : buckets) {
        for (double num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<double> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    std::cout << "Original array: ";
    for (double num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
    bucketSort(arr);
    std::cout << "Sorted array: ";
    for (double num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
