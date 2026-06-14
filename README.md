# LU-DecompEngine

A matrix computation architecture written in C99 to perform **LU (Lower Upper) Decomposition** from scratch. This tool allows small edge compute layers to perform matrix inversions, linear regressions, and system state predictions efficiently without loading heavy dependencies.

## 🧮 Mathematical Strategy
* **Algorithmic Model:** Factoring an $N \times N$ matrix $A$ such that $A = L \times U$.
* **Memory Management:** Rows are flattened into a continuous 1D block to avoid multi-pointer system fragmentation.
* **Time Complexity:** $O(N^3)$ processing bounds.
