#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int target;
    std::cout << "Enter the element to search: ";
    std::cin >> target;

    std::vector<int>::iterator result = std::find(numbers.begin(), numbers.end(), target);

    if (result != numbers.end()) {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), result);
    } else {
        std::cout << "Element not found in the vector." << std::endl;
    }

    return 0;
}


