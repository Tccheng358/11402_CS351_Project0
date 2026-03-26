
# Test Plan

## Overview
This document outlines the testing strategy and procedures for CS351 Project 0.

## Testing Scope
- Unit tests for core functionality
- Integration tests for component interactions
- Edge case validation

## Test Environment
- Language: C++20
- Framework: Manual test harness (current), unit test framework planned for automation
- Tools: `g++`/`clang++` compiler, command line execution, optional CI runner

## Test Cases

### Unit Tests
| Test ID | Description | Expected Result | Status |
|---------|-------------|-----------------|--------|
| UT-001 | Basic valid case: nums = [2, 7, 11, 15], target = 9 | Returns indices [0, 1] (or equivalent valid pair order) | Planned |
| UT-002 | Negative numbers: nums = [-3, 4, 3, 90], target = 0 | Returns indices [0, 2] | Planned |
| UT-003 | Duplicate values: nums = [3, 3], target = 6 | Returns indices [0, 1] using two distinct elements | Planned |
| UT-004 | Zero involved: nums = [0, 4, 3, 0], target = 0 | Returns indices [0, 3] (or equivalent valid pair order) | Planned |
| UT-005 | Minimum input size: nums = [1, 2], target = 3 | Returns indices [0, 1] | Planned |
| UT-006 | No solution: nums = [1, 2, 3], target = 10 | Returns empty result | Planned |
| UT-007 | Both algorithms agree on same input set | `twoSumArray` and `twoSumHashMap` return valid index pairs that satisfy sum | Planned |
| UT-008 | Larger input performance sanity check | Hash map version completes with fewer operations than brute force for large n | Planned |

### Integration Tests
| Test ID | Description | Expected Result | Status |
|---------|-------------|-----------------|--------|
| IT-001 | `main.cpp` calls `twoSumHashMap` and prints output format | Program prints valid index pair for sample input | Pass (manual) |
| IT-002 | Swap call to `twoSumArray` in `main.cpp` and execute | Program prints valid index pair for sample input | Planned |
| IT-003 | Build all source files together (`main.cpp`, `twosum.cpp`) | Successful compilation with no linker errors | Pass (manual) |

## Test Execution
- **Schedule**:
	- Milestone 1: Execute manual integration tests
	- Milestone 2: Implement automated unit tests in `tests/`
	- Milestone 3: Run tests in CI and container environment
- **Responsible Party**: Project owner / course team
- **Pass Criteria**:
	- All unit tests pass
	- Integration tests pass on local build
	- Acceptance tests pass against documented requirements
	- No regression in expected algorithm behavior

## Defect Tracking
- Log issues in project repository
- Track severity and resolution status
- Link defect IDs to affected requirement IDs when possible

## Sign-off
- [ ] Test cases implemented in `tests/`
- [ ] Automated test run passing
- [x] Manual smoke test completed
- [x] Documentation reviewed
