# Deployment Guide

## 1. Purpose
This document describes how to build and run CS351 Project 0 (Two Sum) in a reproducible way for local validation and grading.

## 2. Current Deployment Scope
- Deployment target: local CLI execution
- Language standard: C++20
- Source files:
	- `Src/main.cpp`
	- `Src/twosum.cpp`

## 3. Prerequisites
- A C++ compiler with C++20 support
	- Windows: `g++` (MinGW) or MSVC (`cl`)
	- Linux/macOS: `g++` or `clang++`
- Terminal access in repository root

## 4. Build and Run (g++ / clang++)

### 4.1 Build
Run from project root:

```bash
g++ -std=c++20 Src/main.cpp Src/twosum.cpp -o twosum_app
```

### 4.2 Run

On Windows (PowerShell):

```powershell
.\twosum_app.exe
```

On Linux/macOS:

```bash
./twosum_app
```

### 4.3 Expected Output (default sample)
The default `main.cpp` sample uses `nums = [2, 7, 11, 15]` and `target = 9`, and should print a valid index pair such as `[0, 1]`.

## 5. Build and Run (MSVC `cl` on Windows)

From a Developer Command Prompt (or terminal with MSVC environment loaded):

```bat
cl /std:c++20 /EHsc Src\main.cpp Src\twosum.cpp /Fe:twosum_app.exe
twosum_app.exe
```

## 6. Verification After Deployment
- Program starts successfully.
- Program prints input and either:
	- valid indices for a matching pair, or
	- `No solution found.` when no pair exists.
- Manual smoke test aligns with:
	- `Docs/04_test_plan.md`
	- `Docs/05_acceptance_tests.md`

## 7. Packaging and Automation Status
- Unit test binaries in `tests/`: not implemented yet.
- GitHub Actions workflow (`.github/workflows/`): not implemented yet.
- Dockerfile/container deployment: not implemented yet.

## 8. Planned Deployment Improvements
1. Add automated test executable(s) under `tests/` and include in build commands.
2. Add GitHub Actions workflow for build and test on `push` and `pull_request`.
3. Add Dockerfile for reproducible build/test environment.
4. Document versioned release process once CI is active.
