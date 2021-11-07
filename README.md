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
```
------------------------------
loop_ijk: 11.62 sec

 Performance counter stats for './mm -1':

         11,647.36 msec task-clock                #    0.997 CPUs utilized          
               756      context-switches          #    0.065 K/sec                  
                15      cpu-migrations            #    0.001 K/sec                  
               464      page-faults               #    0.040 K/sec                  
    31,302,781,226      cycles                    #    2.688 GHz                      (49.88%)
    77,808,594,515      instructions              #    2.49  insn per cycle           (62.41%)
     3,393,438,035      branches                  #  291.348 M/sec                    (62.46%)
         2,438,603      branch-misses             #    0.07% of all branches          (62.59%)
    16,910,901,083      L1-dcache-loads           # 1451.909 M/sec                    (62.62%)
     3,805,134,863      L1-dcache-load-misses     #   22.50% of all L1-dcache accesses  (62.60%)
       447,265,869      LLC-loads                 #   38.401 M/sec                    (49.97%)
       212,809,427      LLC-load-misses           #   47.58% of all LL-cache accesses  (49.87%)

      11.684338879 seconds time elapsed

      11.640324000 seconds user
       0.007989000 seconds sys


sudo perf stat -d ./mm -2
------------------------------
loop_reorder: 9.56 sec

 Performance counter stats for './mm -2':

          9,584.28 msec task-clock                #    1.000 CPUs utilized          
                39      context-switches          #    0.004 K/sec                  
                 8      cpu-migrations            #    0.001 K/sec                  
               463      page-faults               #    0.048 K/sec                  
    25,781,170,217      cycles                    #    2.690 GHz                      (49.95%)
   104,791,039,414      instructions              #    4.06  insn per cycle           (62.46%)
     3,392,447,212      branches                  #  353.960 M/sec                    (62.50%)
         2,367,146      branch-misses             #    0.07% of all branches          (62.55%)
    20,291,035,716      L1-dcache-loads           # 2117.117 M/sec                    (62.57%)
       431,383,595      L1-dcache-load-misses     #    2.13% of all L1-dcache accesses  (62.53%)
           603,779      LLC-loads                 #    0.063 M/sec                    (49.97%)
           102,750      LLC-load-misses           #   17.02% of all LL-cache accesses  (49.93%)

       9.585923394 seconds time elapsed

       9.576834000 seconds user
       0.007997000 seconds sys


sudo perf stat -d ./mm -3
------------------------------
matrix_col: 5.51 sec

 Performance counter stats for './mm -3':

          5,539.77 msec task-clock                #    0.999 CPUs utilized          
                91      context-switches          #    0.016 K/sec                  
                 3      cpu-migrations            #    0.001 K/sec                  
               465      page-faults               #    0.084 K/sec                  
    14,899,494,833      cycles                    #    2.690 GHz                      (50.02%)
    60,939,574,517      instructions              #    4.09  insn per cycle           (62.55%)
     3,393,209,545      branches                  #  612.518 M/sec                    (62.55%)
         2,339,239      branch-misses             #    0.07% of all branches          (62.54%)
    16,918,707,613      L1-dcache-loads           # 3054.047 M/sec                    (62.54%)
       434,032,157      L1-dcache-load-misses     #    2.57% of all L1-dcache accesses  (62.46%)
         3,428,307      LLC-loads                 #    0.619 M/sec                    (49.94%)
         1,995,136      LLC-load-misses           #   58.20% of all LL-cache accesses  (49.94%)

       5.543379570 seconds time elapsed

       5.540462000 seconds user
       0.000000000 seconds sys


sudo perf stat -d ./mm -4
------------------------------
block: 6.54 sec

 Performance counter stats for './mm -4':

          6,567.75 msec task-clock                #    1.000 CPUs utilized          
                13      context-switches          #    0.002 K/sec                  
                 2      cpu-migrations            #    0.000 K/sec                  
               463      page-faults               #    0.070 K/sec                  
    17,664,732,174      cycles                    #    2.690 GHz                      (49.99%)
    71,426,687,409      instructions              #    4.04  insn per cycle           (62.54%)
     3,418,872,456      branches                  #  520.554 M/sec                    (62.55%)
         9,186,259      branch-misses             #    0.27% of all branches          (62.55%)
    13,586,302,278      L1-dcache-loads           # 2068.638 M/sec                    (62.55%)
       468,997,638      L1-dcache-load-misses     #    3.45% of all L1-dcache accesses  (62.49%)
        29,472,820      LLC-loads                 #    4.488 M/sec                    (49.94%)
         1,760,656      LLC-load-misses           #    5.97% of all LL-cache accesses  (49.94%)

       6.568902200 seconds time elapsed

       6.564230000 seconds user
       0.004000000 seconds sys


sudo perf stat -d ./mm -5
------------------------------
block_copy: 5.60 sec

 Performance counter stats for './mm -5':

          5,622.13 msec task-clock                #    1.000 CPUs utilized          
                15      context-switches          #    0.003 K/sec                  
                 1      cpu-migrations            #    0.000 K/sec                  
             1,527      page-faults               #    0.272 K/sec                  
    15,123,971,232      cycles                    #    2.690 GHz                      (49.92%)
    61,498,226,136      instructions              #    4.07  insn per cycle           (62.44%)
     3,432,788,592      branches                  #  610.585 M/sec                    (62.44%)
         9,178,835      branch-misses             #    0.27% of all branches          (62.51%)
    20,444,343,000      L1-dcache-loads           # 3636.405 M/sec                    (62.58%)
       445,204,281      L1-dcache-load-misses     #    2.18% of all L1-dcache accesses  (62.60%)
        18,173,297      LLC-loads                 #    3.232 M/sec                    (50.02%)
         1,107,575      LLC-load-misses           #    6.09% of all LL-cache accesses  (49.94%)

       5.623169529 seconds time elapsed

       5.610683000 seconds user
       0.011997000 seconds sys

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
