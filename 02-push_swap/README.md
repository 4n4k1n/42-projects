# Push Swap

An efficient sorting algorithm implementation using two stacks and a limited set of operations, with a focus on minimizing the number of moves.

## Overview

Push_swap is an algorithmic project in the 42 curriculum that challenges students to sort a stack of integers using the minimum number of operations possible. The project combines algorithm design, optimization strategies, and data structure manipulation to create an efficient sorting solution.

## The Challenge

Given a stack of integers in random order, sort them using only two stacks (stack_a and stack_b) and a specific set of allowed operations. The goal is to minimize the total number of operations needed.

### Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack_a |
| `sb` | Swap the first 2 elements at the top of stack_b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push first element of stack_b to top of stack_a |
| `pb` | Push first element of stack_a to top of stack_b |
| `ra` | Rotate stack_a (first element becomes last) |
| `rb` | Rotate stack_b (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack_a (last element becomes first) |
| `rrb` | Reverse rotate stack_b (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Compilation

```bash
make        # Compile push_swap
make bonus  # Compile checker (bonus)
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Recompile everything
```

## Usage

### Basic Usage
```bash
./push_swap 2 1 3 6 5 8    # Sort these numbers
./push_swap "4 67 3 87"    # Can also pass as single quoted string
```

### With Checker (Bonus)
```bash
# Generate moves and verify with checker
./push_swap 4 67 3 87 | ./checker 4 67 3 87
# Output: "OK" if correctly sorted, "KO" if not
```

### Testing with Random Numbers
```bash
# Generate random numbers for testing
ARG=$(shuf -i 1-100 -n 10 | tr '\n' ' '); ./push_swap $ARG
```

## Algorithm Strategies

### Small Stack Optimization (≤ 5 elements)
- **3 elements**: Simple conditional swaps and rotations
- **4-5 elements**: Push smallest to stack_b, sort remaining, then push back
- **Hardcoded solutions**: Optimized move sequences for each case

### Medium Stack (6-100 elements)
- **Simple sorting algorithms** with stack-specific adaptations
- **Insertion-like approaches** using both stacks
- **Chunk-based sorting** for better performance

### Large Stack (100+ elements)
- **Radix Sort adaptation**: Using binary representation of numbers
- **Quick Sort variation**: Partitioning using both stacks
- **Merge Sort approach**: Divide and conquer with stacks
- **Hybrid algorithms**: Combining multiple strategies

## Project Structure

```
2-push_swap/
├── Makefile
├── inc/
│   └── push_swap.h           # Header with structures and prototypes
├── libft/                    # Custom library
└── src/
    ├── main.c                # Program entry and main logic
    ├── parsing/
    │   ├── parsing.c         # Input validation and parsing
    │   ├── alloc_args.c      # Argument allocation
    │   ├── valid_input.c     # Input validation
    │   ├── is_unique.c       # Duplicate detection
    │   └── index_llist.c     # Index assignment
    ├── llist/
    │   └── create_llist.c    # Linked list operations
    ├── operations/
    │   ├── sa_sb_ss.c        # Swap operations
    │   ├── pa_pb.c           # Push operations
    │   ├── ra_rb_rr.c        # Rotate operations
    │   └── rra_rrb_rrr.c     # Reverse rotate operations
    ├── logic/
    │   ├── logic.c           # Main sorting algorithm
    │   └── edge_cases.c      # Special case handling
    ├── utils/                # Utility functions
    └── checker/
        └── checker.c         # Bonus: operation validator
```

## Algorithm Implementation

### Data Structure
```c
typedef struct s_node
{
    int             value;    // Original value
    int             index;    // Assigned index for sorting
    struct s_node   *next;    // Pointer to next node
}   t_node;

typedef struct s_stacks
{
    t_node  *stack_a;        // Main stack
    t_node  *stack_b;        // Auxiliary stack
    int     size_a;          // Size of stack_a
    int     size_b;          // Size of stack_b
}   t_stacks;
```

### Index Assignment
Convert input values to indices (0 to n-1) based on their sorted order:
```
Input:  [100, 1, 50, 200, 75]
Sorted: [1, 50, 75, 100, 200]
Indices:[3, 0, 1, 4, 2]
```

### Radix Sort Implementation
For large stacks, using binary representation of indices:
```c
void radix_sort(t_stacks *stacks, int max_bits)
{
    int bit;
    
    for (bit = 0; bit < max_bits; bit++)
    {
        // Push numbers with bit=0 to stack_b
        push_zeros_to_b(stacks, bit);
        
        // Push everything back to stack_a
        push_all_to_a(stacks);
    }
}
```

## Performance Benchmarks

### Evaluation Criteria
- **3 elements**: ≤ 3 operations
- **5 elements**: ≤ 12 operations  
- **100 elements**: ≤ 700 operations (5 points), ≤ 900 (4 points), ≤ 1100 (3 points)
- **500 elements**: ≤ 5500 operations (5 points), ≤ 7000 (4 points), ≤ 8500 (3 points)

### Optimization Techniques
- **Precomputed moves**: Hardcode optimal solutions for small cases
- **Cost analysis**: Calculate cost of different move combinations
- **Lookahead**: Consider multiple moves ahead for better decisions
- **Stack manipulation**: Minimize unnecessary rotations

## Input Validation

### Requirements
- Only integers within int range
- No duplicate numbers
- Handle both individual arguments and quoted strings
- Proper error handling for invalid input

### Error Cases
```bash
./push_swap 1 2 3 2        # Error: duplicate
./push_swap 1 2147483648   # Error: overflow  
./push_swap 1 2 three      # Error: non-numeric
./push_swap ""             # Error: empty string
```

## Checker Implementation (Bonus)

The checker validates that a sequence of operations correctly sorts the stack:

```c
// Read operations from stdin
// Apply each operation to the stacks
// Check if final result is sorted with empty stack_b
if (is_sorted(stack_a) && is_empty(stack_b))
    ft_printf("OK\n");
else
    ft_printf("KO\n");
```

## Testing and Debugging

### Automated Testing
```bash
# Test with different stack sizes
for i in {1..100}; do
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
    MOVES=$(./push_swap $ARG | wc -l)
    echo "Test $i: $MOVES moves"
done
```

### Visualization Tools
- **Custom visualizers**: Show stack states and operations
- **Operation counting**: Track moves for optimization
- **Performance analysis**: Compare different algorithm approaches

### Debugging Techniques
- **Step-by-step execution**: Manual trace through operations
- **Stack state printing**: Debug intermediate states
- **Operation validation**: Ensure operations are applied correctly

## Key Learning Objectives

- **Algorithm Design**: Creating efficient sorting strategies
- **Data Structure Manipulation**: Working with stacks and linked lists
- **Optimization**: Minimizing operations through careful analysis
- **Problem Decomposition**: Breaking complex problems into manageable parts
- **Performance Analysis**: Understanding time/space complexity trade-offs
- **Edge Case Handling**: Managing special cases and error conditions

## Advanced Optimizations

### Chunk-Based Approaches
- Divide numbers into chunks and sort each chunk
- Use both stacks strategically for intermediate storage
- Optimize chunk size based on total stack size

### Hybrid Algorithms
- Use different strategies based on stack size
- Combine multiple sorting techniques
- Dynamic algorithm selection based on input characteristics

### Move Optimization
- Combine operations when possible (rr instead of ra + rb)
- Minimize stack rotations through careful planning
- Use both directions (rotate vs reverse rotate) optimally

This project develops critical thinking about algorithms and optimization while working with fundamental data structures and operations.