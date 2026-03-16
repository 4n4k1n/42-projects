# Minishell

A simplified shell implementation that mimics bash behavior, featuring command execution, built-ins, environment variables, redirections, and pipes.

## Overview

Minishell is one of the most comprehensive projects in the 42 curriculum, combining everything learned from previous projects into a functional Unix shell. This project covers parsing, process management, signal handling, file operations, and system programming to create a working command-line interface.

## Features

### Core Functionality
- **Command Execution**: Execute system commands and programs
- **Built-in Commands**: Implement essential shell built-ins
- **Environment Variables**: Manage and expand environment variables
- **Input/Output Redirections**: Handle file redirections (`<`, `>`, `<<`, `>>`)
- **Pipes**: Chain commands with pipe operations (`|`)
- **Quote Handling**: Process single and double quotes correctly
- **Signal Management**: Handle Ctrl+C, Ctrl+D, and Ctrl+\ signals

### Built-in Commands
- **echo**: Display text with `-n` option support
- **cd**: Change directory with relative and absolute paths
- **pwd**: Print working directory
- **export**: Set environment variables
- **unset**: Remove environment variables
- **env**: Display environment variables
- **exit**: Exit the shell with optional exit code

## Compilation

```bash
make        # Compile minishell
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

### Starting the Shell
```bash
./minishell
```

### Example Commands
```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep ".c" | wc -l
42

minishell$ export MY_VAR="test"
minishell$ echo $MY_VAR
test

minishell$ cd /tmp && pwd
/tmp

minishell$ cat < input.txt | sort > output.txt
```

## Technical Architecture

### Project Structure
```
3-minishell/
├── Makefile
├── include/
│   ├── minishell.h          # Main header file
│   ├── builtins.h           # Built-in command prototypes
│   ├── lexical_analysis.h   # Tokenization structures
│   ├── parser.h             # Parsing structures
│   ├── execution.h          # Execution engine
│   ├── expansion.h          # Variable expansion
│   ├── redirects.h          # Redirection handling
│   ├── signals.h            # Signal management
│   ├── env_list.h           # Environment management
│   └── libft/               # Custom library
└── src/
    ├── main.c               # Program entry point
    ├── lexical_analysis/    # Tokenization module
    ├── parser/              # Command parsing
    ├── expansion/           # Variable and quote expansion
    ├── execution/           # Command execution engine
    ├── builtins/           # Built-in command implementations
    ├── redirect/           # I/O redirection handling
    ├── env_list/           # Environment variable management
    ├── signals.c           # Signal handling
    └── utilities/          # Helper functions
```

## Core Components

### 1. Lexical Analysis
Tokenize input into meaningful components:
```c
typedef enum e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,    // <
    TOKEN_REDIRECT_OUT,   // >
    TOKEN_REDIRECT_APPEND, // >>
    TOKEN_REDIRECT_HEREDOC, // <<
    TOKEN_EOF
}   t_token_type;
```

### 2. Parser
Build command structures from tokens:
```c
typedef struct s_cmd
{
    char            **args;        // Command arguments
    t_redirect      *redirects;    // I/O redirections
    struct s_cmd    *next;         // Next command in pipe chain
}   t_cmd;
```

### 3. Expansion Engine
Handle variable substitution and quote processing:
- **Environment variables**: `$HOME`, `$USER`, `$PATH`
- **Exit status**: `$?` 
- **Quote removal**: Process single/double quotes
- **Tilde expansion**: `~` → `$HOME`

### 4. Execution Engine
Execute parsed commands with proper setup:
- **Process creation**: Fork and exec for external commands
- **Pipe management**: Create and manage pipe chains
- **Built-in execution**: Handle built-ins in current process
- **Redirection setup**: Configure file descriptors

## Advanced Features

### Signal Handling
```c
// Interactive mode signals
SIGINT (Ctrl+C)  → Display new prompt
SIGQUIT (Ctrl+\) → Ignore
EOF (Ctrl+D)     → Exit shell

// Command execution mode
SIGINT  → Terminate current command
SIGQUIT → Quit with core dump
```

### Quote Processing
- **Single quotes**: Preserve literal values `'$HOME'` → `$HOME`
- **Double quotes**: Allow variable expansion `"$HOME"` → `/home/user`
- **Mixed quoting**: Handle complex combinations

### Heredoc Implementation
```bash
minishell$ cat << EOF
> line 1
> line 2  
> EOF
line 1
line 2
```

### Environment Management
- **Variable inheritance**: Inherit from parent shell
- **Dynamic updates**: Modify environment during execution
- **Export functionality**: Control variable visibility

## Memory Management

### Key Principles
- **No memory leaks**: All allocated memory must be freed
- **Proper cleanup**: Clean up on exit and errors
- **Signal safety**: Handle cleanup during signal interruption
- **Resource management**: Close file descriptors and clean pipes

### Garbage Collection System
```c
typedef struct s_garbage
{
    void                *ptr;
    struct s_garbage    *next;
}   t_garbage;

// Track all allocations for easy cleanup
void    *gc_malloc(t_garbage **gc, size_t size);
void    gc_free_all(t_garbage **gc);
```

## Error Handling

### Command Errors
- **Command not found**: Handle invalid commands gracefully
- **Permission denied**: Check file permissions
- **Syntax errors**: Detect and report parsing errors
- **Memory allocation**: Handle malloc failures

### Exit Codes
```bash
0     # Success
1     # General error
126   # Command found but not executable
127   # Command not found  
130   # Terminated by Ctrl+C
```

## Parsing Algorithm

### Input Processing Pipeline
1. **Lexical Analysis**: Split input into tokens
2. **Quote Processing**: Handle quoted strings
3. **Variable Expansion**: Substitute variables
4. **Command Parsing**: Build command structures
5. **Redirection Setup**: Prepare I/O redirections
6. **Execution**: Execute command pipeline

### Token State Machine
```c
typedef enum e_state
{
    STATE_GENERAL,
    STATE_IN_SINGLE_QUOTE,
    STATE_IN_DOUBLE_QUOTE,
    STATE_IN_WORD
}   t_state;
```

## Testing Strategies

### Functionality Tests
```bash
# Basic commands
echo "test" | cat
ls -la | grep minishell | wc -l

# Redirections
echo "hello" > test.txt
cat < test.txt > output.txt

# Built-ins
cd /tmp && pwd
export TEST=42 && echo $TEST

# Error handling
invalidcommand
cat nonexistent.txt
```

### Edge Cases
- Empty commands
- Multiple spaces and tabs
- Unclosed quotes
- Invalid redirections
- Signal handling during execution
- Memory exhaustion scenarios

## Performance Considerations

### Optimization Areas
- **Efficient parsing**: Minimize string copying
- **Process management**: Optimize fork/exec usage
- **Memory usage**: Reuse allocations when possible
- **I/O buffering**: Efficient redirection handling

### Scalability
- Handle large command lines
- Manage many simultaneous processes
- Efficient environment variable lookup
- Minimal memory footprint

## Learning Objectives

### System Programming
- **Process management**: fork, exec, wait
- **Inter-process communication**: pipes and signals
- **File descriptor manipulation**: dup2, close
- **Signal handling**: sigaction, signal masks

### Software Architecture  
- **Modular design**: Clean separation of concerns
- **Parser implementation**: Formal language processing
- **State management**: Complex program state handling
- **Error propagation**: Robust error handling strategies

### Unix Environment
- **Shell behavior**: Understanding shell semantics
- **Environment variables**: Variable scoping and inheritance
- **File system operations**: Path resolution and permissions
- **Command execution**: Program loading and execution

## Advanced Extensions

### Potential Enhancements
- **Command history**: Implement command recall
- **Tab completion**: Auto-complete commands and files
- **Job control**: Background process management (`&`, `fg`, `bg`)
- **Advanced redirection**: Process substitution (`<()`, `>()`)
- **Aliases**: Command aliasing system
- **Functions**: User-defined shell functions

This project represents the culmination of C programming skills learned throughout the 42 curriculum, combining low-level system programming with high-level software architecture to create a functional and robust shell implementation.