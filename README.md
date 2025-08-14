# Fract-ol

An interactive fractal explorer that renders beautiful mathematical fractals in real-time using computer graphics and complex number mathematics.

## Overview

Fract-ol is a graphics programming project in the 42 curriculum that combines mathematics, computer graphics, and interactive programming. The project involves rendering famous fractals like the Mandelbrot set, Julia sets, and the Burning Ship fractal with real-time interaction capabilities.

## Features

### Supported Fractals
- **Mandelbrot Set**: The classic fractal defined by the iteration z = z² + c
- **Julia Sets**: Parametric fractals with customizable complex parameters
- **Burning Ship**: A variant fractal with absolute value operations

### Interactive Controls
- **Mouse Zoom**: Zoom in/out using mouse wheel
- **Dynamic Parameters**: Change Julia set parameters in real-time
- **Color Schemes**: Multiple color palettes and effects
- **Fractal Switching**: Toggle between different fractal types
- **Real-time Rendering**: Smooth performance with optimized calculations

## Controls

### Mouse
- **Scroll Wheel**: Zoom in/out at mouse cursor position
- **Click**: Center fractal at clicked point (some implementations)

### Keyboard
- **ESC**: Exit the program
- **Arrow Keys**: Navigate around the fractal
- **Number Keys**: Switch between fractal types
- **Space**: Change color schemes
- **+/-**: Increase/decrease iteration depth

## Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

### Basic Usage
```bash
./fractol mandelbrot
./fractol julia
./fractol burningship
```

### Julia Set with Parameters
```bash
./fractol julia [real] [imaginary]
# Example:
./fractol julia -0.7 0.27015
./fractol julia -0.8 0.156
```

## Technical Implementation

### Graphics Library
- **MLX42**: Modern graphics library for 42 projects
- **OpenGL Backend**: Hardware-accelerated rendering
- **Real-time Performance**: Optimized for smooth interaction

### Mathematical Concepts
- **Complex Numbers**: z = a + bi arithmetic
- **Iterative Functions**: Escape-time algorithms
- **Convergence Testing**: Determining fractal membership
- **Coordinate Transformations**: Screen to complex plane mapping

### Key Algorithms

#### Mandelbrot Set
```c
z = 0
for (i = 0; i < max_iterations; i++)
{
    if (|z| > 2)
        return i;  // Point escapes
    z = z² + c;    // c is the point being tested
}
return max_iterations;  // Point is in the set
```

#### Julia Set
```c
z = c  // c is the point being tested
for (i = 0; i < max_iterations; i++)
{
    if (|z| > 2)
        return i;  // Point escapes
    z = z² + parameter;  // parameter is constant
}
return max_iterations;  // Point is in the set
```

## Project Structure

```
2-fractol/
├── Makefile
├── fractol.h           # Main header with structures and prototypes
├── MLX42/             # Graphics library (submodule/dependency)
└── src/
    ├── main.c                    # Program entry and argument parsing
    ├── parsing.c                 # Input validation and parameter parsing
    ├── init_*.c                  # Initialization functions for each fractal
    ├── calc.c                    # Core fractal calculation functions
    ├── color*.c                  # Color palette and effect functions
    ├── *_hook.c                  # Event handling (mouse, keyboard, resize)
    ├── zoom.c                    # Zoom functionality implementation
    ├── print_fractol.c           # Rendering and display functions
    └── utils/                    # Utility functions (string, math, etc.)
```

## Key Learning Objectives

- **Computer Graphics Programming**: Understanding pixels, colors, and rendering
- **Mathematical Visualization**: Translating mathematical concepts into visual representations
- **Complex Number Mathematics**: Working with complex arithmetic and transformations
- **Event-Driven Programming**: Handling user input and real-time interactions
- **Performance Optimization**: Efficient algorithms for real-time rendering
- **Coordinate Systems**: Converting between screen coordinates and mathematical spaces
- **Interactive Applications**: Creating responsive user interfaces

## Color Systems

### Available Color Schemes
- **Rainbow Flow**: Smooth color transitions across the spectrum
- **Classic**: Traditional fractal coloring (black set, colored escape)
- **Heat Map**: Temperature-like color progression
- **Psychedelic**: High-contrast, vibrant colors
- **Monochrome**: Grayscale variations

### Color Calculation Methods
- **Linear Interpolation**: Smooth transitions between colors
- **Escape Time Coloring**: Based on iteration count
- **Orbit Traps**: Advanced coloring techniques
- **Palette Cycling**: Animated color effects

## Mathematical Background

### The Mandelbrot Set
The Mandelbrot set is defined as the set of complex numbers c for which the iteration z(n+1) = z(n)² + c does not diverge when starting from z(0) = 0.

### Julia Sets
Julia sets are related to the Mandelbrot set but use a fixed parameter and vary the starting point: z(n+1) = z(n)² + c, where c is constant and z(0) varies.

### Escape Conditions
A point is considered to "escape" (not in the set) if |z| > 2, as this guarantees divergence to infinity.

## Performance Considerations

- **Iteration Limits**: Balancing detail vs. performance
- **Precision**: Using appropriate data types for calculations
- **Memory Management**: Efficient image buffer handling
- **Threading**: Potential for parallel computation (advanced)
- **Viewport Optimization**: Only calculating visible regions

## Advanced Features

- **Deep Zoom**: Maintaining precision at high zoom levels
- **Animation**: Smooth parameter transitions
- **Export**: Saving fractal images to files
- **Custom Parameters**: User-defined fractal constants
- **Multi-threading**: Parallel computation for faster rendering

This project combines mathematical beauty with programming challenges, creating visually stunning and interactive applications while learning fundamental computer graphics concepts.