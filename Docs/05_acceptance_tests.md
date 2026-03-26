# Acceptance Tests

## 1. Purpose
This document defines acceptance-level scenarios to confirm the project satisfies its intended use and core requirements for the Two Sum implementations.

## 2. Acceptance Criteria
- The program correctly identifies two indices whose values sum to the target.
- Both approaches are available in source code: brute force array and hash map.
- The same array element is not reused as both indices.
- The system returns an empty result when no valid pair exists.
- Documentation remains aligned with implementation and test expectations.

## 3. Test Scenarios

| AT ID | Requirement Links | Scenario | Input | Expected Result | Execution Method | Status |
|---|---|---|---|---|---|---|
| AT-001 | FR1.2, FR1.3, FR2.3 | Standard positive-number case | nums=[2,7,11,15], target=9 | Valid indices for 2+7 (for example [0,1]) | Manual run | Pass (hash map path in `main.cpp`) |
| AT-002 | FR2.4, C.3 | Duplicate values are handled correctly | nums=[3,3], target=6 | Returns two different indices [0,1] | Planned unit/acceptance run | Planned |
| AT-003 | FR1.3, FR2.3 | No-solution behavior | nums=[1,2,3], target=10 | Empty result is returned; user-facing message indicates no solution | Planned run | Planned |
| AT-004 | FR1.4, C.1 | Minimum allowed input size | nums=[1,2], target=3 | Returns valid indices [0,1] | Planned run | Planned |
| AT-005 | FR2.2, NFR.2 | Hash map approach performs single-pass lookup pattern | Large dataset, valid target | Correct result and expected O(n)-style behavior by design review/perf check | Planned benchmark review | Planned |
| AT-006 | NFR.5 | C++ STL-based implementation exists | Source inspection | `vector<int>` and `unordered_map` usage present | Documentation/code review | Pass |

## 4. Acceptance Procedure
1. Build project source files.
2. Execute the default program path in `Src/main.cpp`.
3. Execute additional scenario inputs through temporary driver edits or automated tests once added.
4. Record result per AT ID as Pass/Fail/Blocked.
5. Any failed acceptance test must reference a defect item before final sign-off.

## 5. Final Sign-off Checklist
- [ ] All acceptance scenarios executed
- [ ] All mandatory scenarios passed (AT-001 through AT-004)
- [ ] Any failures documented and resolved
- [ ] Traceability matrix updated to reflect final evidence
