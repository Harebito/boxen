#include <iostream>
#include <cstdint>

uint16_t* find_subset(uint16_t arr[], size_t size, bool (*func)(uint16_t[], size_t), int& subset_length) {
    uint16_t* result = nullptr;
    subset_length = 0;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; j < size; ++j) {
            int current_length = j - i + 1;
            if (func(arr + i, current_length)) {
                if (current_length > subset_length) {
                    result = arr + i;
                    subset_length = current_length;
                }
            }
        }
    }

    return result;
}

bool is_strictly_increasing(uint16_t arr[], size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool are_zero_even_bits(uint16_t arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] & 0xAAAA) { // 0xAAAA represents even bits set to 1
            return false;
        }
    }
    return true;
}

int main() {
    uint16_t arr[] = {1, 2, 5, 2, 2, 10, 11, 12, 8, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int length;
    uint16_t* subset;

    // Using is_strictly_increasing() function
    subset = find_subset(arr, size, is_strictly_increasing, length);
    std::cout << "Subset with strictly increasing elements:" << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << subset[i] << " ";
    }
    std::cout << std::endl;

    // Using are_zero_even_bits() function
    subset = find_subset(arr, size, are_zero_even_bits, length);
    std::cout << "Subset with zero even bits:" << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << subset[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
