# Requirements Traceability Matrix (RTM)

## 1. Purpose
This document links project requirements to design elements, source code, and verification artifacts. It also identifies current coverage gaps.

## 2. Artifact IDs

### Source Documents
- SRS: `Docs/02_SRS.md`
- SDS: `Docs/03_SDS.md`
- Test Plan: `Docs/04_test_plan.md`
- Acceptance Tests: `Docs/05_acceptance_tests.md`
- Intended Use: `Docs/00_intended_use.md`
- Planning Notes: `README.md`, `Docs/01_plan.md`

### Design and Code Artifacts
- D1: Main module and CLI flow (`Src/main.cpp`)
- D2: Array algorithm module (`Src/twosum.cpp::twoSumArray`)
- D3: Hash map algorithm module (`Src/twosum.cpp::twoSumHashMap`)

### Verification Artifact IDs
- TP-UT: Unit tests in test plan (`Docs/04_test_plan.md`)
- TP-IT: Integration tests in test plan (`Docs/04_test_plan.md`)
- AT: Acceptance tests (`Docs/05_acceptance_tests.md`)
- EXE: Manual execution through `main.cpp`

## 3. Requirement ID Scheme
- FR1.x: Functional requirements for Array approach (from SRS 2.1)
- FR2.x: Functional requirements for Hash Table approach (from SRS 2.2)
- NFR.x: Non-functional requirements (from SRS 3 and README constraints)
- C.x: Constraints (from SRS 4)

## 4. Forward Traceability (Requirement -> Design -> Code -> Verification)

| Req ID | Requirement Summary | Design Mapping | Code Mapping | Verification Mapping | Status |
|---|---|---|---|---|---|
| FR1.1 | Accept integer array and target input (array approach) | D1, D2 | `Src/main.cpp`, `Src/twosum.cpp` (`twoSumArray`) | EXE | Implemented / Partially Verified |
| FR1.2 | Find two distinct indices summing to target (array) | D2 | `Src/twosum.cpp` (`twoSumArray`) | EXE | Implemented / Partially Verified |
| FR1.3 | Return indices or empty if not found (array) | D2 | `Src/twosum.cpp` (`twoSumArray`) | EXE | Implemented / Partially Verified |
| FR1.4 | Handle arrays with 2+ elements (array) | D2 | `Src/twosum.cpp` (`twoSumArray`) | TP-UT (planned) | Implemented / Not Fully Verified |
| FR2.1 | Accept integer array and target input (hash table approach) | D1, D3 | `Src/main.cpp`, `Src/twosum.cpp` (`twoSumHashMap`) | EXE | Implemented / Partially Verified |
| FR2.2 | Use hash table for O(n) lookup | D3 | `Src/twosum.cpp` (`unordered_map` in `twoSumHashMap`) | TP-UT (planned), Performance check (planned) | Implemented / Not Fully Verified |
| FR2.3 | Return indices of two numbers summing to target | D3 | `Src/twosum.cpp` (`twoSumHashMap`) | EXE | Implemented / Partially Verified |
| FR2.4 | Handle duplicate values in array | D3 | `Src/twosum.cpp` (`twoSumHashMap`) | TP-UT (planned) | Implemented / Not Fully Verified |
| NFR.1 | Array approach time complexity O(n^2) | D2 | `Src/twosum.cpp` (`twoSumArray` nested loops) | Code review / performance test (planned) | Implemented / Not Measured |
| NFR.2 | Hash approach time complexity O(n) | D3 | `Src/twosum.cpp` (`twoSumHashMap` single pass) | Code review / performance test (planned) | Implemented / Not Measured |
| NFR.3 | Array approach space complexity O(1) | D2 | `Src/twosum.cpp` (`twoSumArray`) | Code review (planned) | Implemented / Not Measured |
| NFR.4 | Hash approach space complexity O(n) | D3 | `Src/twosum.cpp` (`twoSumHashMap`) | Code review (planned) | Implemented / Not Measured |
| NFR.5 | Use C++ standard and STL containers | D1, D2, D3 | `Src/main.cpp`, `Src/twosum.cpp` (`vector`, `unordered_map`) | Build pipeline (planned) | Implemented / Build Not Automated |
| NFR.6 | Automated CI build and test execution | N/A (pipeline design missing) | `.github/workflows/*` expected | CI run (missing) | Not Implemented |
| NFR.7 | Dockerized build/test execution | N/A (container design missing) | `Dockerfile` and optional compose files expected | Container run (missing) | Not Implemented |
| C.1 | Minimum array size is 2 | D2, D3 | `Src/twosum.cpp` (implicit via loops; no explicit validation) | TP-UT (planned) | Partially Implemented |
| C.2 | Integer inputs only | D1, D2, D3 | Function signatures with `vector<int>` and `int` | Compile-time typing | Implemented |
| C.3 | At most one valid solution per test case | D2, D3 | Returns first matching pair in both algorithms | TP-UT (planned) | Implemented / Not Fully Verified |
| C.4 | Target is valid integer | D1, D2, D3 | `int target` in signatures | Compile-time typing | Implemented |

## 5. Backward Traceability (Code -> Requirements)

| Code Artifact | Primary Requirements Covered |
|---|---|
| `Src/main.cpp` | FR1.1, FR2.1, FR2.3, NFR.5 |
| `Src/twosum.cpp::twoSumArray` | FR1.1, FR1.2, FR1.3, FR1.4, NFR.1, NFR.3, C.1, C.3 |
| `Src/twosum.cpp::twoSumHashMap` | FR2.1, FR2.2, FR2.3, FR2.4, NFR.2, NFR.4, C.1, C.3 |

## 6. Verification Coverage Summary

| Verification Area | Current State |
|---|---|
| Unit tests | Defined in `Docs/04_test_plan.md`; no test source files exist in `tests/` |
| Integration tests | Planned in `Docs/04_test_plan.md`; not implemented |
| Acceptance tests | Defined in `Docs/05_acceptance_tests.md`; execution evidence mostly pending |
| CI checks | Not configured (`.github/workflows/` not present) |
| Docker verification | Not configured (`Dockerfile` not present) |
| Manual execution | Demonstrated through `main.cpp` with sample input |

## 7. Gap Analysis and Actions

### Open Gaps
1. No implemented automated tests to verify FR/NFR coverage.
2. Acceptance scenarios are documented, but most are not yet executed with recorded evidence.
3. No CI workflow for build and tests.
4. No Docker artifacts for reproducible build/test.
5. No explicit input validation for array size constraints.

### Recommended Next Actions
1. Add unit tests for all SRS test categories (positive, negative, zero, duplicates, small input sizes, not-found case).
2. Execute and record results for all acceptance scenarios defined in `Docs/05_acceptance_tests.md`.
3. Add GitHub Actions workflow to compile and run tests on push/pull request.
4. Add Dockerfile to build and execute tests in a container.
5. Optionally add explicit precondition checks (`nums.size() >= 2`) and define behavior on invalid input.

## 8. Traceability Status (Overall)
- Functional implementation status: **Core algorithms implemented**.
- Verification status: **Insufficient automated evidence**.
- Deployment/automation status: **Planned but not yet implemented**.
