# IN2029-Programming-in-C-Coursework

# Coursework Project: Programming in C++

## Project Overview
This project is a C++ application designed to simulate simple database operations by processing purchase data from two input files: `payments.txt` and `people.txt`. The program outputs a summary of each person's purchases and total expenditure while validating input files for errors.

---

## Features

### Input Files
1. **payments.txt**  
   - Format: `<Name> <Object> <Price>` (e.g., `Bob pen 3.5`).  
   - Each line contains:
     - A person's name.
     - The name of an object purchased.
     - The price of the object.  

2. **people.txt**  
   - Contains a list of names, one per line.  
   - These names are a subset of those present in `payments.txt`.  

### Program Output
For each person listed in `people.txt`, the program:  
1. Displays the person's name.  
2. Lists the objects they purchased along with the amount paid for each object.  
3. Calculates and displays the total expenditure.  

Example Output:  
Bob
eggs 2.5
pen 3.5
Total: 6

Alice
apple 1.5
eggs 2
Total: 3.5


---

## Error Handling
The program validates input files and handles errors gracefully:
- Detects empty files and prints an error message (e.g., `The people.txt file is empty.`).
- Validates the structure of `payments.txt`:
  - Ensures each line contains exactly three fields.
  - Checks that the price is a valid numeric value.
  - Flags negative prices as errors.
- Ignores duplicate entries in `payments.txt`.

---

## Key Concepts Utilized
- **Classes**: Encapsulates purchase records and processing logic.  
- **Standard Containers**: Uses `std::map` to organize data efficiently.  
- **Error Handling**: Robust validation of input file structure and content.  
- **Code Style**: Modular implementation with clear commenting and separation of concerns.  

---

## Marking Feedback
- **Correctness**: 57/60  
  - Accurate calculations and correct output format.  
  - Some edge cases missed (e.g., negative prices).  

- **Error Detection**: 8/10  
  - Correctly identifies missing fields and non-numeric prices.  
  - Does not handle empty lines or negative prices properly.  

- **Programming Style**: 18/20  
  - Clear comments and good structure.  
  - Effective use of `.h` and `.cpp` files and standard containers.  

**Total Score**: 91/100  
