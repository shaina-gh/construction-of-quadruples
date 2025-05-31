# 🛠️ Construction of Quadruples 

## 🎯 Aim

To implement a program that converts an infix expression to postfix notation and then generates the intermediate code in the form of **Quadruples**, which are used in compiler intermediate representations.

---

## 📘 Explanation

In compiler design, intermediate code generation is a crucial step for optimization and translation. One common form is **Quadruples**, which consist of four fields:

- `op`: Operator  
- `arg1`: First operand  
- `arg2`: Second operand  
- `result`: Result (usually a temporary variable)

This project does the following:

1. Takes an infix expression (e.g., `a+b*c`)
2. Converts it to postfix notation (`abc*+`)
3. Generates quadruples from the postfix expression

---

## 🔍 Logic

### 1. Infix to Postfix Conversion
- Uses a stack to reorder operators based on precedence and parentheses.
- Higher precedence operators (`*`, `/`) are evaluated before lower ones (`+`, `-`).

### 2. Quadruple Generation
- Reads postfix expression character-by-character.
- Pushes operands onto a stack.
- When an operator is encountered, it pops the top two operands.
- Forms a quadruple: `(op, arg1, arg2, result)`
- `result` is a temporary variable (`T1`, `T2`, etc.)
- Pushes the `result` back on the stack for further operations.

### 3. Output
- All generated quadruples are printed sequentially.

---

## 🧪 Sample Input/Output

### 💬 Input:
```cpp
Enter an infix expression: a+b*c
```
### 🧾 Output:
```cpp
Postfix expression: abc*+
Quadruples:
(*, b, c, T1)
(+, a, T1, T2)
```

---

## 🌐 Real-World Applications

- **Compiler Construction**: Intermediate representation for syntax-directed translation.
- **Expression Evaluators**: Used in interpreters and calculators.
- **Optimization Engines**: Helpful in local and global optimization.
- **Target Code Generation**: Basis for generating low-level machine or assembly code.

---



