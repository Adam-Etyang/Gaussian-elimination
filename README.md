# Gaussian Elimination Solver

This C++ implementation solves systems of linear equations using the Gaussian Elimination method with partial pivoting.

## Overview

Gaussian Elimination is a method for solving systems of linear equations by transforming the system's augmented matrix into row echelon form through a sequence of elementary row operations, followed by back-substitution to find the solution vector.

## Features

- Solves systems of linear equations using Gaussian Elimination
- Implements partial pivoting for numerical stability
- Detects and reports unsolvable systems
- Simple interface for matrix input and solution output

## Requirements

- C++ compiler with C++11 support
- Standard C++ libraries: `iostream`, `string`, `cmath`, `algorithm`, `vector`

## Usage

1. Include the necessary headers:
   ```cpp
   #include <iostream>
   #include <string>
   #include <cmath>
   #include <algorithm>
   #include <vector>
   using namespace std;
   ```

2. Define your system of equations as an augmented matrix:
   ```cpp
   vector<vector<double>> matrix = {
       {2, 4, -1, 8},     // 2x + 4y - z = 8
       {-3, -1, 2, -11},  // -3x - y + 2z = -11
       {-2, 1, 2, -3}     // -2x + y + 2z = -3
   };
   ```

3. Call the `GaussianElimination` function:
   ```cpp
   try {
       vector<double> solution = GaussianElimination(matrix);
       // Process the solution
   } catch (const runtime_error &e) {
       cout << "Error: " << e.what() << endl;
   }
   ```

## Algorithm Details

The implementation follows these steps:

1. **Forward Elimination with Partial Pivoting**:
   - For each pivot position, find the row with the largest absolute value in the current column
   - Swap the current row with the row containing the largest value
   - Check if the pivot is zero (indicating no unique solution)
   - Eliminate all entries below the pivot

2. **Back Substitution**:
   - Starting from the last equation, solve for each variable
   - Substitute each solved variable into the previous equations

## Example

For the system:
```
2x + 4y - z = 8
-3x - y + 2z = -11
-2x + y + 2z = -3
```

The expected output is:
```
Solution:
x1 = 1
x2 = 2
x3 = 3
```

## Error Handling

The implementation throws a `runtime_error` when the system has no unique solution, which occurs when a pivot becomes zero during elimination.

## Time Complexity

For an n×n system:
- Forward elimination: O(n³)
- Back substitution: O(n²)
- Overall complexity: O(n³)

## Limitations

- The implementation assumes the system has a unique solution
- No special handling for nearly singular matrices beyond partial pivoting
- May encounter numerical stability issues for very large or ill-conditioned systems
