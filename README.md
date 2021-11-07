# Matrix Multiplication algorithm
This repo is an implementation of five matrix multiplication algorithms mentioned in  
*[Parallelizing a Level 3 BLAS Library for LAN-Connected Workstations](https://ir.nctu.edu.tw/handle/11536/149370)*, including:
1. Loop-i-j-k
2. Loop-reordering
3. Matrix-column
4. Block algorithm without submatrices copy
5. Block algorithm with submatrices copy

## Usage

### clone this repo and compile
```sh
git clone https://github.com/9501sam/matrix-multiplication-algorithm
cd matrix-multiplication-algorithm
make
```

### run the program
```
./mm -1         # run Loop-i-j-k
./mm -2         # run Loop-reordering
./mm -3         # run Matrix-column
./mm -4         # run Block algorithm without  submatrices copy
./mm -5         # run Block algorithm with submatrices copy
./mm -2 -3 -5   # run algo 2, 3, 5
./mm -a         # run all algorithms above
make run        # compile the code and run all algorithms above
make run-perf   # compile the code and measure performance using perf
```

## Result
### Acer Aspire A315-51 V1.08 (2018 laptop)
```sh
loop_ijk: 11.70 sec
loop_reorder: 9.59 sec
matrix_col: 5.51 sec
block: 6.58 sec
block_copy: 5.62 sec
```

### Asus Eee PC 1018P (very old laptop)
```sh
loop_ijk: 259.06 sec
loop_reorder: 195.04 sec
matrix_col: 111.18 sec
block: 149.44 sec
block_copy: 113.29 sec
```

### Raspberry Pi 4 Model B with 4G RAM
```sh
loop_ijk: 93.10 sec
loop_reorder: 42.63 sec
matrix_col: 31.45 sec
block: 50.21 sec
block_copy: 33.24 sec
```

## Todo List
- [ ] improve block algorithm
- [ ] find better submatrix size for every machine
