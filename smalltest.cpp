#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int indexToRemove = 2;

    // Remove the element at the specified index
    if (indexToRemove >= 0 && indexToRemove < numbers.size()) {
        numbers.erase(numbers.begin() + indexToRemove);
    }

    // Output the updated vector
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}