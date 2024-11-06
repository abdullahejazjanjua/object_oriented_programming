# introduction

This repository contains assignments and a final semester project for the Object-Oriented Programming course (CS112), provided by [Dr. Zahid Halim](https://scholar.google.com.sg/citations?user=2TQuYtwAAAAJ&hl=en) as part of my studies at [GIKI](https://giki.edu.pk/).

---

## Table of Contents
1. [Assignment 1: Console-Based Car Racing Game](#assignment-1-console-based-car-racing-game)
2. [Assignment 2: Strategic Five Game](#assignment-2-strategic-five-game)
3. [Assignment 3: Terminal Animation – Spinning Doughnut](#assignment-3-terminal-animation--spinning-doughnut)
4. [Assignment 4: Car and Engine Composition](#assignment-4-car-and-engine-composition)
5. [Assignment 5: Custom String Class with Operator Overloading](#assignment-5-custom-string-class-with-operator-overloading)
6. [Assignment 6: Sparse Polynomial Addition](#assignment-6-sparse-polynomial-addition)
7. [Semester Project: Clustering Using OOP in C++/CLI](#semester-project-clustering-using-oop-in-ccli)

---

### Assignment 1: Console-Based Car Racing Game

**Objective**:  
Build a console-based car racing game where two cars compete on a track, controlled through specific keyboard keys. The game keeps track of each car’s position and score using a structured approach.

**Requirements**:
- Define a `Car` structure with position and points as attributes.
- Create a nested `RacingTrack` structure with `trackLength`.
- Use keys (e.g., 'a'/'d' for Car 1, 'j'/'l' for Car 2) to control each car’s movement.
- Display a racing track of set length, restricting car movement within track boundaries.
- Implement a scoring system, accumulating points for each car.
- Show each car's position and points and include an option to quit the game.

### Assignment 2: Strategic Five Game

**Objective**:  
Develop a classic strategy board game called "Strategic Five," playable in both Human vs. Human and Human vs. Bot modes.

**Requirements**:
- Allow users to select board size (either 9x9 or 15x15).
- Offer two modes: Human vs. Human and Human vs. Bot.
- Implement strategic logic in the Bot to create a challenging experience.
- Use classes to encapsulate game logic and functionality.

### Assignment 3: Terminal Animation – Spinning Doughnut

**Objective**:  
Create an animation of an infinitely spinning doughnut displayed in the terminal.

**Requirements**:
- Use a continuous loop to render a rotating doughnut in the console.
- Employ ASCII art or similar techniques for a visually engaging spinning effect.

### Assignment 4: Car and Engine Composition

**Objective**:  
Illustrate the concept of composition by modeling a relationship between a `Car` and an `Engine`.

**Requirements**:
- Define two classes: `Engine` (with attributes for cylinders and horsepower) and `Car` (with make, model, and an `Engine` instance).
- Provide getter and setter methods for the car’s make, model, cylinders, and horsepower.
- Include a `printInfo` function in the `Car` class to display the car’s make, model, and engine details.

### Assignment 5: Custom String Class with Operator Overloading

**Objective**:  
Create a custom string class in C++ with various functionalities through operator overloading.

**Requirements**:
- Define a class `CMyString` with a dynamic character array for storing strings.
- Implement multiple constructors: a default constructor, one that accepts a character array, and another that takes the string size.
- Add functions to retrieve the string’s size and character array.
- Overload operators (`+`, `+=`, `[]`, `==`, `!=`, `>`, `<`, `()`, `<<`, `>>`, `=`, left/right shift) for string manipulation, comparison, and assignment.
- Test all operations in `main`, displaying the string before and after each operation.

### Assignment 6: Sparse Polynomial Addition

**Objective**:  
Implement sparse polynomial addition by reading coefficients from a file and summing them.

**Requirements**:
- Read polynomial data from a file in a specified format.
- Display file contents with scrolling if necessary.
- Add each polynomial to a cumulative result and display the final sum.
- Save the result in a file (`result_addition.txt`) with detailed information.
- Show additional details like file name, polynomial count, variable count, non-zero values, data structure used, and addition time.
- Avoid built-in functions; implement custom logic for reading, displaying, and adding polynomials.

### Semester Project: Clustering Using OOP in C++/CLI

This project implements a clustering technique using an Object-Oriented Programming (OOP) approach in C++/CLI, with tasks focused on correlation analysis, matrix manipulation, and visualization.

**Project Overview**  
The project consists of the following main tasks:

1. **Correlation Matrix Calculation and Discretization**  
   - Computes the Pearson Correlation Matrix.
   - Discretizes and visualizes the correlation matrix as a zoomable bitmap image.

2. **Permutation and Signature Technique**  
   - Permutes the data matrix and applies a signature technique to identify clusters.
   - Visualizes the sorted and rearranged matrix based on clustering results.

**Key Functionalities**  
- **Task 1 Functions**: Includes Pearson correlation calculation, matrix discretization, and bitmap image generation with green shading to visualize correlation intensity.
- **Task 2 Functions**: Handles matrix permutation, signature value computation for clustering, and matrix sorting based on similarity.

**Collaborators**  
- Muhammad Ahmad Amjad (GitHub: [ahmadamjadd](https://github.com/ahmadamjadd))
- Abdullah Ejaz Janjua