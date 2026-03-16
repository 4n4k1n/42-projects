# 42 School Projects

A comprehensive collection of all my completed projects from the 42 School curriculum, showcasing a journey from fundamental C programming to advanced system programming and computer graphics.

## Overview

This repository serves as a centralized portfolio of my 42 School projects, organized using git subtrees. Each project represents a milestone in learning low-level programming, algorithms, system design, and software engineering principles.

## Projects by Tier

### Tier 00 - Foundation
The essential building blocks of C programming.

#### [00-libft](00-libft/)
**Your First C Library**

Re-implementation of standard C library functions plus additional utilities. This foundational project teaches memory management, string manipulation, and linked lists.

- 📦 45+ standard library functions reimplemented
- 🔗 Bonus: Linked list operations
- 🎯 Core foundation used in all subsequent projects

---

### Tier 01 - Core Skills
Building essential programming utilities and understanding file operations.

#### [01-ft_printf](01-ft_printf/)
**Formatted Output Function**

A complete reimplementation of the printf() function, handling variadic arguments and multiple format specifiers.

- 🔧 Variadic function implementation
- 📝 9 format specifiers (c, s, p, d, i, u, x, X, %)
- 🎓 Deep dive into type conversion and string formatting

#### [01-get_next_line](01-get_next_line/)
**File Reading Function**

A function that reads a file line by line, managing static variables and buffer operations.

- 📖 Efficient file reading with customizable buffer size
- 🧠 Static variable management
- 📁 Handles multiple file descriptors simultaneously

---

### Tier 02 - Algorithms & Graphics
Exploring algorithmic thinking and graphical programming.

#### [02-fractol](02-fractol/)
**Fractal Explorer**

An interactive fractal visualization program using the MLX42 graphics library.

- 🎨 Mandelbrot and Julia set rendering
- 🖱️ Real-time mouse and keyboard controls
- 🌈 Dynamic color schemes and zoom functionality

#### [02-pipex](02-pipex/)
**Unix Pipes Implementation**

A program that mimics shell pipe behavior, executing commands with input/output redirection.

- 🔗 Process creation with fork()
- 📤 Inter-process communication via pipes
- 🛠️ File descriptor manipulation and redirection

#### [02-push_swap](02-push_swap/)
**Sorting Algorithm Challenge**

An efficient sorting algorithm using two stacks and a limited set of operations.

- 🧮 Optimized sorting with minimal operations
- 📊 Radix sort adaptation for stack operations
- 🎯 Achieves < 700 moves for 100 numbers, < 5500 for 500 numbers

---

### Tier 03 - System Programming
Advanced system-level programming with concurrency and process management.

#### [03-philosophers](03-philosophers/)
**Dining Philosophers Problem**

A classic concurrency problem implementation using threads and mutexes.

- 🍝 Simulation of the dining philosophers problem
- 🔒 Thread synchronization with mutexes
- ⏱️ Precise timing and deadlock prevention

#### [03-minishell](03-minishell/)
**Bash-like Shell Implementation**

A fully functional Unix shell with command execution, pipes, redirections, and built-in commands.

- 💻 Command parsing and execution
- 🔄 Pipe chains and I/O redirections
- 📝 7 built-in commands (echo, cd, pwd, export, unset, env, exit)
- 🔍 Environment variable expansion and quote handling
- ⚡ Signal management (Ctrl+C, Ctrl+D, Ctrl+\\)

---

### Tier 04 - Computer Graphics
Advanced rendering and distributed computing.

#### [04-miniRT](04-miniRT/)
**Distributed Ray Tracing Renderer**

A sophisticated ray tracing engine with multi-threading, BVH acceleration, and distributed rendering capabilities.

- 🎬 Physically-based ray tracing with global illumination
- 🎨 Advanced materials: Lambertian, Metal, Dielectric (glass)
- 🚀 Multi-threaded rendering with BVH acceleration (500x speedup)
- 🌐 Distributed rendering across multiple machines
- 🎮 Real-time camera controls and interactive preview
- 📐 6 geometric primitives (sphere, plane, cylinder, cone, pyramid, triangle)
- 🖼️ Bump mapping and procedural textures

---

## Repository Structure

```
42-projects/
├── 00-libft/              # C standard library reimplementation
├── 01-ft_printf/          # Printf function clone
├── 01-get_next_line/      # Line-by-line file reader
├── 02-fractol/            # Fractal visualization
├── 02-pipex/              # Unix pipes simulation
├── 02-push_swap/          # Stack sorting algorithm
├── 03-minishell/          # Unix shell implementation
├── 03-philosophers/       # Threading and synchronization
└── 04-miniRT/             # Ray tracing renderer
```

## Key Learning Outcomes

Throughout these projects, I've developed expertise in:

### Low-Level Programming
- Memory management and allocation strategies
- Pointer manipulation and data structures
- System calls and Unix APIs

### Algorithms & Data Structures
- Sorting algorithms and optimization
- Binary search trees and spatial indexing
- Linked lists, stacks, and queues

### System Programming
- Process management (fork, exec, wait)
- Inter-process communication (pipes, signals)
- File descriptor manipulation
- Thread synchronization and concurrency

### Software Architecture
- Modular design and code organization
- Parser implementation and state machines
- Error handling and resource management
- Performance optimization techniques

### Graphics Programming
- Ray tracing and rendering pipelines
- Vector mathematics and transformations
- Shader-like material systems
- Real-time interactive graphics

## Technologies Used

- **Language**: C (C99/C11 standard)
- **Build System**: Make
- **Graphics**: MLX42 (minilibx)
- **Networking**: BSD Sockets
- **Threading**: POSIX Threads (pthreads)
- **Version Control**: Git (with subtrees)

## Compilation

Each project contains its own Makefile with standard targets:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Recompile everything
make bonus  # Compile bonus features (where applicable)
```

## About 42 School

42 is a tuition-free, peer-to-peer learning programming school with campuses worldwide. The curriculum is project-based, requiring students to learn independently and collaboratively without traditional teachers or lectures.

### Key Principles
- **Peer-to-peer learning**: Students learn from each other
- **Project-based**: Hands-on coding from day one
- **No teachers**: Self-learning and collaboration
- **24/7 access**: Study at your own pace
- **Real-world skills**: Industry-relevant technologies

## Stats

- **Total Projects**: 9
- **Lines of Code**: ~25,000+
- **Total Development Time**: ~6-12 months
- **Language**: 100% C
- **Norm Compliance**: All projects follow 42 Norm coding standards

## About This Repository

This repository was created using git subtrees to consolidate all completed 42 projects into a single portfolio. Each project maintains its own commit history and can be updated independently.

### Git Subtree Structure

Projects were added as subtrees from their original repositories:

```bash
# Example of how projects were added
git subtree add --prefix=00-libft/ <repo-url> main
```

### Extracting Individual Projects

You can extract any project back into its own standalone repository with full commit history using `git subtree split`:

```bash
# Extract a project into its own branch
git subtree split --prefix=00-libft/ -b libft-standalone

# Create a new repository from that branch
mkdir ../libft-extracted
cd ../libft-extracted
git init
git pull ../projects libft-standalone

# Or push directly to a remote repository
cd ../projects
git push git@github.com:yourusername/libft.git libft-standalone:main
```

This preserves the complete commit history for just that project, making it easy to maintain separate repositories while keeping this consolidated portfolio.

## License

All projects are developed for educational purposes as part of the 42 School curriculum. Each project may have its own license - please refer to individual project directories.

## Acknowledgments

- 42 School for the comprehensive curriculum
- Fellow 42 students for peer learning and collaboration
- The open-source community for tools and resources

---

Made with dedication at 42 School
