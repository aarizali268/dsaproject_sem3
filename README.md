# 💰 Debt Destroyer

**Debt Destroyer** is a menu-driven **C application** designed to help users manage their debts and make payments efficiently.

The project demonstrates the practical use of multiple **Data Structures** including **Linked Lists, Binary Search Trees (BST), and Stacks**.

---

## 📌 Project Overview

Managing multiple debts manually can become difficult, especially when tracking the remaining balance and previous payments.

**Debt Destroyer** provides a simple system where users can:

* Add new debts
* View all recorded debts
* Search for a debt using its ID
* Make payments
* Undo the most recent payment

The project combines different data structures to perform these operations efficiently and demonstrate their real-world applications.

---

## 🎯 Objectives

The main objectives of the project are:

1. To develop a practical application using **C programming**.
2. To demonstrate the use of different data structures in one system.
3. To manage debt records using a **Linked List**.
4. To perform fast debt searching using a **Binary Search Tree**.
5. To implement payment undo functionality using a **Stack**.
6. To provide a simple and user-friendly menu-driven interface.

---

## 🧠 Data Structures Used

### 1. Linked List

A **Singly Linked List** is used to store all debt records.

Each node contains:

* Debt ID
* Creditor name
* Original debt amount
* Current balance
* Pointer to the next debt

**Purpose:**
The linked list allows debts to be dynamically added without requiring a fixed-size array.

```text
HEAD
 ↓
[Debt 1] → [Debt 2] → [Debt 3] → NULL
```

---

### 2. Binary Search Tree (BST)

A **Binary Search Tree** is used to search for debts based on their ID.

The debt ID determines where each record is placed:

```text
              20
             /  \
           10    30
          / \    / \
         5  15  25  40
```

For searching:

* If the required ID is smaller → search the left subtree.
* If the required ID is larger → search the right subtree.
* If the ID matches → debt is found.

**Purpose:**
The BST demonstrates efficient searching compared with checking every node sequentially.

---

### 3. Stack

A **Stack** is used to implement the **Undo Payment** feature.

The stack follows the:

> **LIFO — Last In, First Out**

principle.

For example:

```text
Payment 3  ← TOP
Payment 2
Payment 1
```

When the user chooses **Undo Payment**, Payment 3 is removed first.

Each payment stores:

* Debt ID
* Payment amount
* Balance before payment
* Pointer to the previous payment

This allows the previous balance to be restored.

---

## ⚙️ Features

### ➕ 1. Add Debt

Allows the user to create a new debt record.

The user enters:

* Debt ID
* Creditor name
* Debt amount

The initial balance is automatically set equal to the debt amount.

---

### 📋 2. Display Debts

Displays all currently stored debts.

Example:

```text
========== ALL DEBTS ==========

ID       : 101
Creditor : Bank
Amount   : 50000.00
Balance  : 35000.00

ID       : 102
Creditor : Friend
Amount   : 10000.00
Balance  : 7000.00
```

---

### 🔎 3. Search Debt

Allows the user to search for a debt using its **Debt ID**.

The search is performed using the **Binary Search Tree**.

If the debt exists, the system displays:

* Debt ID
* Creditor
* Original amount
* Current balance

---

### 💳 4. Make Payment

Allows the user to make a payment toward a debt.

The program:

1. Finds the debt using its ID.
2. Displays the current balance.
3. Takes the payment amount.
4. Checks that the payment does not exceed the balance.
5. Stores the previous balance in the payment stack.
6. Deducts the payment from the current balance.

Example:

```text
Current Balance: 5000.00
Enter Payment Amount: 1500

Payment successful!
Remaining Balance: 3500.00
```

---

### ↩️ 5. Undo Payment

Reverses the most recent payment.

The program retrieves the latest payment from the stack and restores the previous balance.

Example:

```text
Before Payment:
Balance = ₹5000

Payment:
₹1500

After Payment:
Balance = ₹3500

Undo:
Balance = ₹5000
```

---

## 🖥️ Menu

The program provides the following menu:

```text
================================
        DEBT DESTROYER
================================
1. Add Debt
2. Display Debts
3. Search Debt
4. Make Payment
5. Undo Payment
0. Exit
```

---

## 🔄 Program Flow

```text
                 START
                   |
                   v
             Display Menu
                   |
        +----------+----------+
        |          |          |
     Add Debt   Search      Payment
        |          |          |
     Linked      BST        Stack
      List       Search     Records
        |          |          |
        +----------+----------+
                   |
                   v
              Undo Payment
                   |
                   v
                Stack
                   |
                   v
              Restore Balance
                   |
                   v
                 EXIT
```

---

## 🗂️ Structure of the Program

The program uses four main structures.

### Debt Structure

```c
struct Debt
{
    int id;
    char creditor[30];
    float amount;
    float balance;
};
```

Stores the information about an individual debt.

### Linked List Node

```c
struct Node
{
    struct Debt data;
    struct Node *next;
};
```

Stores debt records dynamically.

### BST Node

```c
struct Tree
{
    struct Debt data;
    struct Tree *left;
    struct Tree *right;
};
```

Used for searching debts by ID.

### Payment Stack Node

```c
struct Payment
{
    int id;
    float amount;
    float oldBalance;
    struct Payment *next;
};
```

Stores payment information required for the undo operation.

---

## 📊 Complexity Analysis

| Operation       | Data Structure      |  Time Complexity |
| --------------- | ------------------- | ---------------: |
| Add Debt        | Linked List         |             O(n) |
| Display Debts   | Linked List         |             O(n) |
| Search Debt     | BST                 | O(log n) average |
| Make Payment    | Linked List         |             O(n) |
| Undo Payment    | Stack + Linked List |             O(n) |
| Insert into BST | BST                 | O(log n) average |

> **Note:** A BST can become unbalanced. In the worst case, BST insertion and searching can take **O(n)** time.

---

## 🛠️ Technologies Used

* **Language:** C
* **Compiler:** GCC / MinGW
* **IDE:** Code::Blocks / VS Code
* **Concepts:**

  * Structures
  * Pointers
  * Dynamic Memory Allocation
  * Linked Lists
  * Binary Search Trees
  * Stacks
  * Recursion
  * Menu-driven programming

---

## 📁 Project Structure

```text
Debt-Destroyer/
│
├── DebtDestroyer.c
└── README.md
```

---

## ▶️ How to Run

### Using Code::Blocks

1. Open **Code::Blocks**.
2. Create a new C project.
3. Add `DebtDestroyer.c`.
4. Build the project.
5. Run the program.
6. Select an option from the menu.

### Using GCC

Compile the program:

```bash
gcc DebtDestroyer.c -o DebtDestroyer
```

Run it:

```bash
./DebtDestroyer
```

On Windows:

```bash
DebtDestroyer.exe
```

---

## 🧪 Example Usage

```text
================================
        DEBT DESTROYER
================================
1. Add Debt
2. Display Debts
3. Search Debt
4. Make Payment
5. Undo Payment
0. Exit

Enter choice: 1

Enter Debt ID: 101
Enter Creditor Name: Bank
Enter Debt Amount: 50000

Debt added successfully!
```

Making a payment:

```text
Enter choice: 4

Enter Debt ID: 101
Current Balance: 50000.00
Enter Payment Amount: 10000

Payment successful!
Remaining Balance: 40000.00
```

Undoing the payment:

```text
Enter choice: 5

Last payment undone!
Restored Balance: 50000.00
```

---

## 🎓 DSA Concepts Demonstrated

This project demonstrates how different data structures can work together in a single real-world application.

| Concept                   | Application                         |
| ------------------------- | ----------------------------------- |
| Structures                | Store debt and payment information  |
| Pointers                  | Connect dynamically allocated nodes |
| Dynamic Memory Allocation | Create nodes using `malloc()`       |
| Linked List               | Store multiple debt records         |
| BST                       | Search debts by ID                  |
| Stack                     | Undo the latest payment             |
| Recursion                 | BST insertion and searching         |
| Menu-driven Programming   | User interaction                    |

---

## 🚀 Future Improvements

The project can be extended with features such as:

* Delete debt records
* Update creditor information
* Payment history
* Due dates
* Interest calculation
* Debt priority management
* File handling for permanent storage
* Graphical user interface
* Sorting debts by balance
* Debt completion status

---

## 👨‍💻 Project Purpose

**Debt Destroyer** was developed as a **Data Structures and Algorithms project** to demonstrate the practical implementation of fundamental data structures in C.

The main focus is not only on storing data, but on selecting an appropriate data structure for different operations:

> **Linked List → Debt Management**
> **BST → Searching**
> **Stack → Undo Payment**

---

## 📜 License

This project is created for **educational purposes** and can be modified or extended for learning and academic use.
