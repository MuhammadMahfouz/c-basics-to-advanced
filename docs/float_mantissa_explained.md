# 🧮 Understanding IEEE 754 Floating-Point Representation in C

> This documentation provides a detailed explanation of how floating-point numbers are represented in the C programming language using the IEEE 754 standard. It covers binary formatting, mantissa significance, precision limitations, and includes practical examples to solidify understanding.

---

## 📚 Table of Contents

- [Introduction](#introduction)
- [Scientific vs Binary Notation](#scientific-vs-binary-notation)
- [What Is IEEE 754 Format?](#what-is-ieee-754-format)
- [IEEE 754 (32-bit Float) Breakdown](#ieee-754-32-bit-float-breakdown)
- [Example: Binary Representation of 5.75](#example-binary-representation-of-575)
- [What Is a Mantissa?](#what-is-a-mantissa)
- [Mantissa and Precision](#mantissa-and-precision)
- [Precision Demo in C](#precision-demo-in-c)
- [Special Cases](#special-cases)
- [Summary](#summary)
- [References](#references)

---

## 📝 Introduction

In C, floating-point values (`float`, `double`, `long double`) are implemented using a standardized binary representation called **IEEE 754**. This format enables accurate and consistent storage of real numbers using a fixed number of bits.

Understanding how this format works is essential for writing numerically robust code, avoiding precision errors, and working efficiently with scientific and mathematical applications.

---

## 🔬 Scientific vs Binary Notation

In decimal (base-10), we often represent numbers using **scientific notation**:
`N = M × 10^E`

Where:
- `N` is the number
- `M` is the **mantissa** (also called the **significand**)
- `E` is the **exponent** (a power of 10)

IEEE 754 adapts this to **binary scientific notation**: `N = (-1)^S × 1.M × 2^(E - Bias)`

Where:
- `S` is the sign bit (0 for positive, 1 for negative)
- `M` is the mantissa (the fractional part of the binary number)
- `E` is the exponent
- `Bias` is a fixed value used to encode positive and negative exponents

For 32-bit `float`, the bias is 127.

---

## 📦 What Is IEEE 754 Format?

IEEE 754 defines the structure of a floating-point number in memory.

### 🧱 32-bit Float Structure:

| Field     | Size (bits) | Purpose                         |
|-----------|-------------|---------------------------------|
| Sign      | 1           | 0 for positive, 1 for negative  |
| Exponent  | 8           | Encodes exponent (with bias)    |
| Mantissa  | 23          | Fractional binary digits        |

There is also an **implicit leading 1** in normalized numbers, giving us **24 effective bits** of precision.

---

## 🧮 IEEE 754 (32-bit Float) Breakdown

Let’s consider the binary layout of a float:


| Field     | Size (bits) | Description                                |
|-----------|-------------|--------------------------------------------|
| Sign      | 1           | 0 for positive, 1 for negative              |
| Exponent  | 8           | Encodes the power of two (with bias 127)   |
| Mantissa  | 23          | Holds the fractional part of the number    |

### Formula:
Value = (-1)^S × 1.M × 2^(E - 127)


The leading 1 before the mantissa is **implicit** in normalized numbers.

---

## 🔢 Binary Example: 5.75

Let’s represent `5.75` in IEEE 754 format:

1. Convert 5.75 to binary:
- 5 = 101
- 0.75 = 0.11
- 5.75 = 101.11


2. Normalize it:
- 101.11 = 1.0111 × 2^2


3. Determine the IEEE fields:
- Sign bit: 0 (positive)
- Exponent: 127 + 2 = 129 → 10000001
- Mantissa: 01110000000000000000000

### Final IEEE 754 Representation:
0 | 10000001 | 01110000000000000000000


In hexadecimal: `0x40B80000`

---

## 🧮 What is a Mantissa?

The **mantissa** (also called the **significand**) contains the precision bits of the number. For normalized values, it is always treated as `1.M`, where the `1` is **not stored**, only the bits after the decimal point are stored.

The mantissa determines the **accuracy** of the number.

For example:
1.011 = 1 + 0×1/2 + 1×1/4 + 1×1/8 = 1.375


---

## 📏 Mantissa and Precision

The number of bits in the mantissa affects how many decimal digits a float can store **accurately**.

| Type     | Mantissa Bits | Effective Bits | Decimal Precision |
|----------|----------------|----------------|-------------------|
| float    | 23             | 24 (including implicit 1) | ~7 digits  |
| double   | 52             | 53             | ~15–16 digits     |

### Why 7 digits?
log10(2^24) ≈ 7.22


So, a 32-bit float can store **about 7 accurate decimal digits**.

---

## 💻 Precision Demo in C

```c
#include <stdio.h>

int main() {
    float a = 1234567.0f;
    float b = 12345678.0f;

    printf("a: %.10f\n", a);
    printf("b: %.10f\n", b);
    return 0;
}
```
**Output:**

a: 1234567.0000000000

b: 12345680.0000000000

