# Custom C++ Containers Project

This project showcases custom implementations of essential C++ containers - `vector`, `stack`, and `map`. The implementation was done from scratch in C++, providing an opportunity to delve deep into the intricacies of data structures and algorithms. Notably, the `map` container was designed using a binary search tree, offering a practical application of this fundamental data structure.

## Motivation

The primary motivation behind this project was to gain a comprehensive understanding of data structures and algorithms. By implementing these containers from scratch, I aimed to deepen my knowledge of how these fundamental building blocks of programming languages work under the hood.

## Features

### Custom Vector

- The custom vector implementation mimics the behavior of the standard C++ `std::vector`.
- It dynamically resizes to accommodate new elements.
- Supports efficient element access, insertion, and deletion operations.

### Custom Stack

- The custom stack mirrors the functionality of the standard C++ `std::stack`.
- Follows the Last In, First Out (LIFO) principle.
- Implemented with various operations like push, pop, and top.

### Custom Map (Binary Search Tree)

- The custom map is implemented using a binary search tree.
- It provides key-value pair storage with fast retrieval based on keys.
- Supports operations like insertion, deletion, and search with logarithmic time complexity.

## Learning Experience

Building these custom containers provided invaluable insights into various aspects of programming:

- **Data Structures:** Deepened understanding of how vectors, stacks, and binary search trees are structured and manipulated.
- **Memory Management:** Learned about dynamic memory allocation and deallocation strategies for efficient container implementations.
- **Algorithmic Complexity:** Explored the time and space complexity of various container operations, aiding in better algorithm selection for different scenarios.
- **Debugging and Testing:** Developed skills in debugging and testing custom implementations to ensure correctness and efficiency.

## Usage

To compile the project, you can use the provided Makefile. Here's how to use it:

1. Open your terminal or command prompt.

2. Navigate to the project directory.

3. Run the following command to compile the project:

    ```bash
    make
    ```

   This command will compile the project and generate the executable named `con`.

4. To clean up the compiled files, run:

    ```bash
    make clean
    ```

   This command will remove the object files generated during compilation.

5. If you want to rebuild the project from scratch, you can use:

    ```bash
    make re
    ```

   This command will clean the project and then compile it again.

## Testing

The `my_main.cpp` file includes test code comparing my custom containers with STL containers. This allows for thorough testing and validation of the custom implementations against established standards.

---
