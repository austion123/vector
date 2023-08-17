#include <iostream>

class MyVector {
private:
    int* arr;
    int capacity;
    int size;

public:
    MyVector() : arr(nullptr), capacity(0), size(0) {}

    ~MyVector() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArr = new int[newCapacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size++] = value;
    }

    int at(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        throw std::out_of_range("Index out of bounds");
    }

    int getSize() {
        return size;
    }
};

int main() {
    MyVector myVec;
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);

    std::cout << "Vector size: " << myVec.getSize() << std::endl;

    try {
        std::cout << "Element at index 1: " << myVec.at(1) << std::endl;
        std::cout << "Element at index 5: " << myVec.at(5) << std::endl;  // This will throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

