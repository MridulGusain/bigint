
# Big Number Calculator

This is a C-based command-line calculator that supports basic arithmetic operations (addition, subtraction, multiplication) on arbitrarily large integers. The numbers are stored and manipulated using linked lists, allowing you to compute values beyond the limits of standard integer types.

---

## ✨ Features

- Supports **addition (+)**, **subtraction (-)**, **multiplication (\*)**
- Handles arbitrarily large numbers using linked list representation
- User input-based interaction
- Extendable: Placeholder functions for **division (÷)** and **modulo (%)** operations

---

## 📂 Project Structure

```plaintext
├── main.c         # Main driver code for user input and output
├── bignum.c       # Implementation of linked list and arithmetic operations
├── bignum.h       # Header file with function declarations and structure
├── README.md      # Project documentation (this file)
````

---

## 🛠️ How to Compile and Run

Using GCC (Linux / Windows with MinGW):

```bash
gcc main.c bignum.c -o bigmath
./bigmath
```

---

## 💡 How to Use the Header File

The `bignum.h` file contains all the necessary declarations for using the big number functions and the `Node` structure.

To use it in your C files, include it at the top:

```c
#include "bignum.h"
```

**Ensure that:**

* The `bignum.h` file is in the same directory as your `.c` files.
* You compile both `main.c` and `bignum.c` together using `gcc` as shown above.

---

## 🧠 How It Works

* Each digit of a number is stored in a node of a singly linked list.
* Operations are implemented using digit-wise logic (e.g., digit-by-digit addition with carry).
* Input is taken as strings and converted into linked list format.

---

## 🎮 Sample Run

```
Enter first number: 12345678901234567890
Enter second number: 98765432109876543210
Enter operation (+, -, *, /, %): +
Result: 111111111011111111100
```

---

## 🚀 To Do / Future Improvements

* [ ] Implement full **division** logic
* [ ] Implement **modulo** operation
* [ ] Add input validation and error handling
* [ ] Support negative numbers
* [ ] Add unit tests

---

## 📄 License

This project is open-source and free to use under the MIT License.

```
