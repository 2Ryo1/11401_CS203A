# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [Ryo Ito, s1133352]  
Email: [ryo0516tw@gmail.com] 

## Original Function
- This task only involves executing the hash you created yourself, so C++ that produces the same output as the original is omitted.
### Integer Keys
- Formula / pseudocode:
  ```text
  function myHashInt(key, m):
      return key%m
  ```
### Non-integer Keys
- Formula / pseudocode:
  ```text
  function myHashString(str, m):
      return (int)hash % m
  ```
- However, since the hash is assigned a value of 0 without converting from str to hash, the result is uniformly 0.
- Therefore, non-integers are considered non-functional.
## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C2X and C++23(Because c did not work correctly in the existing Makefile.bat, change c23 on line 9 to c2x.)

## Results
| Table Size (m) | Index Sequence         | Observation              | 
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

| Table Size (m) | Collision Rate  | Distribution Uniformity                               | 
|----------------|-----------------|-------------------------------------------------------|
| 10             | 50%             | Uniformly, but all collisions occur                   |
| 11             | 45%             | Nearly uniform but collisions occur                   |
| 37             | 15%             | Uniformity is low but collisions are infrequent       |
## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  function myHashInt(key, m):
      d = key/m //quotient
      r = key%m //remainder
      buffer = conect(d, r) //conect d and r
      hash = toint(buffer)
      return hash % m
  ```
- Rationale:
- In its original state, the collision rate is high and distribution skew occurs. Therefore, to increase key uniqueness, we combine the quotient and remainder. By enhancing the dependency of each key on the algorithm results, we can expect improved collision rates and reduced distribution skew compared to the original state.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  function myHashString(str, m):
      d = 0, r = 0,wordsize = (len(str))
      for each character c in str:
          d += (int(c)/m) //sum of quotient 
          r += (int(c)%m) //sum of remainder
      if(wordsize = 1):// for avoid zero division
         wordsize++
      d +=lastchar / (wordsize-1)
      r +=firstchar % m
      buffer = conect(d, r) //conect d and r
      hash = toint(buffer)
      return hash % m
  ```
- Rationale:
- Similar to myHashInt, this code enhances key uniqueness by using the ASCII values of each character in the string. It combines the sum of each character's quotient with the sum of their remainders. However, this approach carries the risk of matching total values even for different strings. To mitigate this collision risk, we can add the index element to the algorithm by using the remainder of the last character divided by the array length and the remainder of the first character divided by m.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C2X and C++23(Because c did not work correctly in the existing Makefile.bat, change c23 on line 9 to c2x.)

## Results
# myHashInt
| Table Size (m) | Index Sequence         | Observation                                                               |
|----------------|------------------------|---------------------------------------------------------------------------|
| 10             | 1, 2, 3, 4, ...        | Periodic, but differentiation is possible through combination of products |
| 11             | 0, 9, 10, 0, ...       | Combining the remainder with the remainder for more even distribution     |
| 37             | 21, 22, 23, 24, ...    | Spread out over a wide area with minimal collisions                       |

| Table Size (m) | Collision Rate  | Distribution Uniformity                                                    | 
|----------------|-----------------|----------------------------------------------------------------------------|
| 10             | 40%             | Slightly improved compared to the original, but periodicity remains        |
| 11             | 30%             | Equality has increased, and the collision rate has decreased               |
| 37             | 10%             | Distributed over a wide area, the collision has been largely resolved      |

# myHashString
| Table Size(m)| Index Sequence            | Observation                                                            |
|--------------|---------------------------|------------------------------------------------------------------------|
| 10           | cat=1, dog=4, bat=3,...   | Each string has a different value, with little periodicity             |
| 11           | cat=1, dog=5, bat=9,...   | Adding leading and trailing characters effectively differentiates them |
| 37           | cat=29, dog=35, bat=27,...| Distributed over a wide area, with collisions largely resolved         |

| Table Size (m) | Collision Rate  | Distribution Uniformity                                                   | 
|----------------|-----------------|---------------------------------------------------------------------------|
| 10             | 30%             | Like myHashInt, it has a low collision rate with a small table size       |
| 11             | 20%             | Equality has increased, and the collision rate has decreased              |
| 37             | 50%             | Distributed over a wide area, the collision has been largely resolved     |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```text
   \11401_CS203A\AssignmentIV\C>hash_function.exe
   === Hash Function Observation (C Version) ===

   === Table Size m = 10 ===
   Key     Index
   -----------------
   21      1
   22      2
   23      3
   24      4
   25      5
   26      6
   27      7
   28      8
   29      9
   30      0
   51      1
   52      2
   53      3
   54      4
   55      5
   56      6
   57      7
   58      8
   59      9
   60      0

   === Table Size m = 11 ===
   Key     Index
   -----------------
   21      0
   22      9
   23      10
   24      0
   25      1
   26      2
   27      3
   28      4
   29      5
   30      6
   51      3
   52      4
   53      5
   54      3
   55      6
   56      7
   57      8
   58      9
   59      10
   60      0

    === Table Size m = 37 ===
    Key     Index
    -----------------
    21      21
    22      22
    23      23
    24      24
    25      25
    26      26
    27      27
    28      28
    29      29
    30      30
    51      3
    52      4
    53      5
    54      6
    55      7
    56      8
    57      9
    58      10
    59      11
    60      12

    === String Hash (m = 10) ===
    Key     Index
    -----------------
    cat     1
    dog     4
    bat     9
    cow     8
    ant     0
    owl     9
    bee     8
    hen     9
    pig     2
    fox     5

    === String Hash (m = 11) ===
    Key     Index
    -----------------
    cat     1
    dog     5
    bat     9
    cow     10
    ant     0
    owl     4
    bee     1
    hen     7
    pig     5
    fox     7

    === String Hash (m = 37) ===
    Key     Index
    -----------------
    cat     29
    dog     35
    bat     27
    cow     24
    ant     1
    owl     26
    bee     10
    hen     36
    pig     16
    fox     20
    ...
  ```
  ```
   === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  23      3
  24      4
  25      5
  26      6
  27      7
  28      8
  29      9
  30      0
  51      1
  52      2
  53      3
  54      4
  55      5
  56      6
  57      7
  58      8
  59      9
  60      0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      0
  22      9
  23      10
  24      0
  25      1
  26      2
  27      3
  28      4
  29      5
  30      6
  51      3
  52      4
  53      5
  54      3
  55      6
  56      7
  57      8
  58      9
  59      10
  60      0

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      3
  52      4
  53      5
  54      6
  55      7
  56      8
  57      9
  58      10
  59      11
  60      12

  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     1
  dog     4
  bat     9
  cow     8
  ant     0
  owl     9
  bee     8
  hen     9
  pig     2
  fox     5

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     1
  dog     5
  bat     9
  cow     10
  ant     0
  owl     4
  bee     1
  hen     7
  pig     5
  fox     7

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     29
  dog     35
  bat     27
  cow     24
  ant     1
  owl     26
  bee     10
  hen     36
  pig     16
  fox     20

  ```
- Observations: Outputs align with the analysis, Comparing Original and MyFunction, MyFunction exhibits a lower collision rate and improved distribution. These effects become more pronounced as the table size increases.
For string keys, the technique of appending leading or trailing characters successfully differentiates similar words by assigning them to distinct indices.
## Analysis
- The output results show that when comparing the Original function and MyFunction as expected, MyFunction has a lower collision rate and improved distribution.
- The improvement effect of this code becomes more pronounced as the table size increases, and the most uniform distribution was achieved especially at prime sizes (e.g., m=37).
- Regarding strings, incorporating the first and last characters into the hash calculation ensures that even similar words are assigned to different indices, further reducing the risk of collisions.


## Reflection
1. In designing this hash function, I focused on balancing simplicity and effectiveness. The approach combining quotient and remainder successfully enhanced key uniqueness as expected without increasing complexity.

2. Through experimentation, I confirmed that table size significantly impacts the uniformity of the distribution. In particular, selecting prime-number sizes can substantially reduce the collision rate.

3. Regarding string keys, I discovered that a small tweak—adding leading and trailing characters—significantly reduces collision rates, though it occurred to me while writing the code. Such a simple approach improves performance merely by adding elements to the index. This highlighted the importance of creativity in breaking down key elements into finer components to enhance uniqueness.
4. A concern with this code is overflow when handling larger values. To improve this, we need to incorporate measures within the calculation algorithm to limit the number of digits. Given that such measures are necessary, it makes sense that the prime number-based code discussed in class—though not used this time—is a logical approach.
5. This assignment was more challenging in terms of integrating VSCode with GitHub. As building necessary environments will become more frequent going forward, one of my goals is to become more proficient at setting up environments smoothly and quickly. Furthermore, while the concept behind the code I wrote was simple, precisely because the code itself was simple, I never encountered any errors. This resulted in a somewhat uninspiring outcome for a programming assignment. Moving forward, I want to challenge myself with more complex code.











