#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, bool ascending) {
    int n = arr.size();a
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap elements based on the sorting order
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Validate input
    if (n <= 0) {
        std::cout << "Please enter a valid number of elements." << std::endl;
        return 1; // Exit with an error code
    }

    std::vector<int> arr(n);
    
    // Input array elements
    std::cout << "Enter the elements of the array: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Element " << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    char order;
    std::cout << "Sort in ascending (a) or descending (d) order? (Enter 'a' or 'd'): ";
    std::cin >> order;

    // Determine sorting order
    bool ascending = (order == 'a' || order == 'A');

    // Sort the array
    bubbleSort(arr, ascending);

    // Display the sorted array
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0; // Successful completion
}
