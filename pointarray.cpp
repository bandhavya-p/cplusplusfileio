#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Missing: " << argv[0] << " <array_size>" << std::endl;
        return 1;
    }

    int size = std::atoi(argv[1]);

    if (size <= 0) {
        std::cerr << "Array size must be a positive integer." << std::endl;
        return 1;
    }

    int *arr = new int[size];

    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int *pointer = arr;

    int sum = 0;
    int min = *pointer;
    int max = *pointer;

    for (int i = 0; i < size; i++) {
        sum += *pointer;
        if (*pointer < min) {
            min = *pointer;
        }
        if (*pointer > max) {
            max = *pointer;
        }
        pointer++;
    }

    std::cout << "Sum of the array: " << sum << std::endl;
    std::cout << "Minimum value: " << min << std::endl;
    std::cout << "Maximum value: " << max << std::endl;

   pointer = arr;

    int *reversed = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        reversed[i] = *pointer;
    pointer++;
    }

    std::cout << "Reversed array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << reversed[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] reversed;

    return 0;
}
