# Rubik's Cube Solver

Welcome to the **Rubik's Cube Solver** — a versatile solver implementation featuring multiple cube representations and advanced search algorithms.

---

## 🚩 Project Overview

This project explores the solving of the classic 3x3 Rubik’s Cube puzzle using a modular, object-oriented design powered by **abstract classes**.

---

## 🧩 Features

- **Multiple Cube Representations**  
  - **Bitboard Representation:** Compact and efficient binary encoding of cube state.  
  - **3D Array Representation:** Intuitive 3-dimensional array modeling of the cube.  
  - **1D Array Representation:** Linearized cube state for fast processing.

- **Advanced Search Algorithms**  
  - **Breadth-First Search (BFS):** Explores states level-by-level for shortest path solutions.  
  - **Depth-First Search (DFS):** Explores deeply to find solutions with backtracking.  
  - **Iterative Deepening DFS (IDDFS):** Combines DFS depth-limiting with BFS completeness.  
  - **Iterative Deepening A* (IDA*):** Heuristic-guided search combining A* with iterative deepening for optimal solutions.

---

## 🛠️ Architecture

The solver is built using **abstract classes** to define a flexible framework that supports multiple cube representations and algorithms with clean separation of concerns and extensibility.

---

## 🚀 Getting Started

To compile and run the solver:

```bash
g++ main.cpp -o solver
./solver
