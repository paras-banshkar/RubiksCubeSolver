# Rubik's Cube Solver in C++

A high-performance **3×3 Rubik's Cube solver** implemented in modern C++ using **bitboard-based state representation**, **graph search algorithms**, and **pattern database heuristics**.

This project is designed for learning and experimenting with **state-space search**, **heuristic optimization**, and **efficient low-level cube representations**.

---

## Features

- Multiple cube representations
  - 3D array
  - 1D array
  - Optimized bitboard representation
- Search algorithms
  - DFS
  - BFS
  - IDDFS
  - IDA* (heuristic search)
- Corner Pattern Database heuristic
- Generic template-based solver architecture
- Hashable cube states for unordered containers
- Random cube shuffling and solution reconstruction

---

## Project Structure

```text
Rubiks-Cube-Solver/
│
├── Databases/
│   └── cornerDepth5V1.txt
│
├── Model/
│   ├── RubiksCube.h
│   ├── RubiksCube3dArray.cpp
│   ├── RubiksCube1dArray.cpp
│   └── RubiksCubeBitboard.cpp
│
├── Solver/
│   ├── DFSSolver.h
│   ├── BFSSolver.h
│   ├── IDDFSSolver.h
│   └── IDAstarSolver.h
│
├── PatternDatabases/
│   ├── CornerPatternDatabase.h
│   └── CornerDBMaker.h
│
├── main.cpp
└── README.md
```

---

## State Representation

### Bitboard Representation (Recommended)

The fastest implementation uses a **bitboard-based cube model**.

- Each face is stored in a `uint64_t`
- Entire cube state fits in **48 bytes**
- Fast rotations using **bit shifts and masks**
- Efficient hashing and copying

This representation is optimized for search algorithms where millions of states may be explored.

---

## Search Algorithms

| Algorithm | Optimal | Memory | Use Case |
|----------|----------|--------|----------|
| DFS | ❌ | Low | Small depth exploration |
| BFS | ✅ | High | Optimal shallow solutions |
| IDDFS | ✅ | Low | Memory-efficient uninformed search |
| IDA* | ✅* | Medium | Heuristic-guided solving |

\*Assuming the heuristic is admissible.

---

## Pattern Database Heuristic

The solver uses a **Corner Pattern Database (PDB)**.

- Encodes all 8 corner cubies
- Stores minimum moves from solved state
- Precomputed using BFS
- Significantly improves search performance compared to uninformed search

---

## Building the Project

### Requirements

- C++17 or later
- CMake (optional) or any modern C++ compiler

### Compile with g++

```bash
g++ -std=c++17 main.cpp -O2 -o cube_solver
```

### Run

```bash
./cube_solver
```

---

## Example Output

```text
Shuffled Cube:
U R F' L2 D B ...

Solving...

Solution (13 moves):
B' D' L2 F R' U ...

Solved!
```

---

## Generating the Pattern Database

To generate a new corner database, enable the database generation section in `main.cpp` and run:

```cpp
CornerDBMaker dbMaker(fileName, 5);
dbMaker.bfsAndStore();
```

This creates a file such as:

```text
Databases/cornerDepth5V1.txt
```

---

## Usage

Example using the bitboard representation and IDA* solver:

```cpp
RubiksCubeBitboard cube;
cube.randomShuffleCube(13);

CornerPatternDatabase db(fileName);

IDAstarSolver<RubiksCubeBitboard, HashBitboard> solver(cube, &db);

auto solution = solver.solve();
```

---

## Design Highlights

- **Template-based generic solvers**
- **Separation of model, solver, and heuristic**
- **Low-level bit manipulation for performance**
- **Reusable hashable cube states**
- **Support for experimenting with new heuristics**

---

## Performance

Typical performance on a modern desktop:

| Scramble Length | Expected Time |
|----------------|---------------|
| 5–8 moves | Instant |
| 10–13 moves | Very fast |
| 15–18 moves | Moderate |
| 20+ random moves | May become slow |

This project is intended as an **educational and research-oriented solver**, not a production-grade speedcubing solver such as Kociemba's two-phase algorithm.

---

## Future Improvements

- Move pruning (avoid inverse/redundant moves)
- True recursive IDA*
- Edge pattern database
- Better hash combining
- CMake build system
- Unit tests for all cube moves
- Command-line interface

---

## Learning Topics

This project demonstrates:

- State-space search
- Heuristic search
- Pattern databases
- Bitboards
- Hashing complex objects
- Generic programming in C++
- Memory vs. speed tradeoffs

---

## Acknowledgements

Inspired by classical Rubik's Cube search techniques and heuristic pattern database methods used in AI and combinatorial search research.

---

## License

This project is open source. Add a license such as **MIT** if you plan to distribute it publicly.
