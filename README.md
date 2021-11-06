# Matrix Multiplication algorithm
This repo impliments five matrix multiplication algorithms mentioned in 
[Parallelizing a Level 3 BLAS Library for LAN-Connected Workstations](https://ir.nctu.edu.tw/handle/11536/149370),
including:

1. Loop-i-j-k
2. Loop-reordering
3. Matrix-column
4. Block algorithm without submatrices copy
5. Block algorithm with submatrices copy

## Usage

```sh
git clone https://github.com/9501sam/matrix-multiplication-algorithm
cd matrix-multiplication-algorithm
make run
```

## Result
### Aspire A315-51 V1.08:
```sh
loop_ijk: 18.69 sec
loop_reorder: 12.26 sec
matrix_col: 11.50 sec
block: 11.88 sec
block_copy: 11.66 sec
```

