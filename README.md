# LeetCode solutions

C++20. One file per problem, named `NNNN-slug.cpp`, containing the `Solution` class exactly as submitted.

Written for interview preparation, with an emphasis on the standard library choices rather than on golfing the line count. Signatures use `const&` where the input is only read, which LeetCode's own templates do not.

## Solved

| # | Problem | Difficulty | Pattern | Time | Space |
|---|---|---|---|---|---|
| [1](0001-two-sum.cpp) | Two Sum | Easy | Hash map complement | `O(n)` | `O(n)` |
| [20](0020-valid-parentheses.cpp) | Valid Parentheses | Easy | Stack | `O(n)` | `O(n)` |
| [49](0049-group-anagrams.cpp) | Group Anagrams | Medium | Canonical form + hash | `O(n k)` | `O(n k)` |
| [121](0121-best-time-to-buy-and-sell-stock.cpp) | Best Time to Buy and Sell Stock | Easy | One pass | `O(n)` | `O(1)` |
| [125](0125-valid-palindrome.cpp) | Valid Palindrome | Easy | Two pointers | `O(n)` | `O(1)` |
| [215](0215-kth-largest-element-in-an-array.cpp) | Kth Largest Element in an Array | Medium | Min-heap of size k | `O(n log k)` | `O(k)` |
| [217](0217-contains-duplicate.cpp) | Contains Duplicate | Easy | Hash set | `O(n)` | `O(n)` |
| [242](0242-valid-anagram.cpp) | Valid Anagram | Easy | Bounded-alphabet counting | `O(n)` | `O(1)` |
| [704](0704-binary-search.cpp) | Binary Search | Easy | Binary search | `O(log n)` | `O(1)` |
| [973](0973-k-closest-points-to-origin.cpp) | K Closest Points to Origin | Medium | Max-heap of size k | `O(n log k)` | `O(k)` |

`n` is the input size; `k` is the parameter named `k` in the problem, or the maximum string length in 49.

## Notes on a few

**215 and 973** both keep a heap of size `k`, in opposite directions. To keep the `k` largest you need a **min**-heap, because `pop` removes the top and the thing you want to discard is the smallest of what you are keeping. To keep the `k` closest, the same logic gives a max-heap.

**973** stores `(distance, index)` rather than the point itself. A comparator runs far more often than there are elements, so computing each squared distance once and storing it beats recomputing it inside a comparator. No `sqrt`, since it is monotonic and never changes the ordering.

**49** builds a per-word key from a 26-slot count array. The separators matter: without them, counts of `1,11` and `11,1` both encode as `111`. The key is write-only, so it never needs to be decoded.

**704** uses `left + (right - left) / 2` rather than `(left + right) / 2`, which can overflow `int` when both are large.
