# Known Issues and Limitations

## 1. Purpose
This document tracks current known issues, limitations, and technical risks for CS351 Project 0.

## 2. Open Issues

| ID | Area | Issue | Impact | Workaround | Planned Fix |
|---|---|---|---|---|---|
| KI-001 | Testing | No executable automated tests exist in `tests/`. | Verification is mostly manual; regression risk is higher. | Manually run scenarios by editing input values in `Src/main.cpp`. | Add C++ test harness and test cases covering UT-001 through UT-008. |
| KI-002 | Input handling | `main.cpp` uses hardcoded sample input instead of runtime user input or test-driver input. | Limited runtime flexibility and reduced demo coverage without code edits. | Change values directly in `Src/main.cpp` before rebuild/run. | Add CLI argument/input mode and/or separate test driver. |
| KI-003 | Validation | No explicit precondition checks for minimum input size (`nums.size() >= 2`). | Behavior is safe (returns empty) but not explicitly validated/documented at runtime. | Provide valid input arrays in current usage. | Add explicit guard checks and messages for invalid input size. |
| KI-004 | CI/CD | No GitHub Actions workflow is present. | Build/test quality is not automatically enforced on push/PR. | Manual local build and run. | Add `.github/workflows` pipeline for compile and test. |
| KI-005 | Containerization | No Dockerfile/container setup exists. | Reproducible environment requirement is not yet fulfilled. | Use local toolchain installation. | Add Dockerfile and container test command. |
| KI-006 | Algorithm contract | Project assumptions state one valid solution per case; behavior for multiple valid pairs is "first found" pair. | Output may vary by algorithm/input order when multiple pairs exist. | Use test cases with exactly one valid solution. | Document behavior clearly and add dedicated multi-solution test note. |

## 3. Resolved Issues
- None recorded yet.

## 4. Risk Notes
- Very large integer values may risk overflow in `nums[i] + nums[j]` or complement computation.
- Performance comparison claims are currently design-based and not benchmark-backed in this repository.

## 5. Tracking and Update Policy
1. Add a new KI entry for each confirmed defect or limitation.
2. Link KI entries to related requirement IDs (FR/NFR/C) when applicable.
3. Move fixed items to the "Resolved Issues" section with date and commit reference.
