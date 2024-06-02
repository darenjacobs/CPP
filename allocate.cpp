#include <__config>
#include <iostream>
#include <new>

/* C++ memory allocation keywords are "new" and "delete" */

int main() {
    // int* is a pointer to a dynamic integer
    int* num_ptr = nullptr; // Allocate space for one dynamic integer

    try {
        // The new keyword is responsible for allocating the space to store the dynamic integer
        num_ptr = new int;
        *num_ptr = 42;
        std::cout << "Dynamic number: " << *num_ptr << std::endl;
    } catch (const std::bad_alloc) {
        return 1;
    }
    // Delete will free up the memory and allocate it back to the OS
    delete num_ptr;

    return 0;
}
