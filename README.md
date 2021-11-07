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
loop_ijk: 11.56 sec

 Performance counter stats for './mm -1':

         11,590.61 msec task-clock                #    1.000 CPUs utilized          
                34      context-switches          #    0.003 K/sec                  
                 4      cpu-migrations            #    0.000 K/sec                  
               976      page-faults               #    0.084 K/sec                  
    31,152,716,414      cycles                    #    2.688 GHz                      (30.74%)
    77,755,770,065      instructions              #    2.50  insn per cycle           (38.44%)
     3,390,837,874      branches                  #  292.550 M/sec                    (38.44%)
         2,401,946      branch-misses             #    0.07% of all branches          (38.44%)
    16,917,136,204      L1-dcache-loads           # 1459.555 M/sec                    (38.45%)
     3,804,252,039      L1-dcache-load-misses     #   22.49% of all L1-dcache accesses  (38.48%)
       439,970,634      LLC-loads                 #   37.959 M/sec                    (30.78%)
       211,767,259      LLC-load-misses           #   48.13% of all LL-cache accesses  (30.78%)
   <not supported>      L1-icache-loads                                             
         1,840,894      L1-icache-load-misses                                         (30.78%)
    16,920,052,072      dTLB-loads                # 1459.807 M/sec                    (30.78%)
             3,749      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.78%)
            11,377      iTLB-loads                #    0.982 K/sec                    (30.78%)
             4,065      iTLB-load-misses          #   35.73% of all iTLB cache accesses  (30.77%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

      11.592541936 seconds time elapsed

      11.579212000 seconds user
       0.011999000 seconds sys


sudo perf stat -d -d -d ./mm -2
------------------------------
loop_reorder: 9.56 sec

 Performance counter stats for './mm -2':

          9,585.78 msec task-clock                #    1.000 CPUs utilized          
                25      context-switches          #    0.003 K/sec                  
                 8      cpu-migrations            #    0.001 K/sec                  
               463      page-faults               #    0.048 K/sec                  
    25,782,974,839      cycles                    #    2.690 GHz                      (30.71%)
   104,880,391,514      instructions              #    4.07  insn per cycle           (38.43%)
     3,391,286,923      branches                  #  353.783 M/sec                    (38.47%)
         2,370,004      branch-misses             #    0.07% of all branches          (38.52%)
    20,287,956,825      L1-dcache-loads           # 2116.465 M/sec                    (38.56%)
       433,292,348      L1-dcache-load-misses     #    2.14% of all L1-dcache accesses  (38.58%)
           631,080      LLC-loads                 #    0.066 M/sec                    (30.82%)
           108,145      LLC-load-misses           #   17.14% of all LL-cache accesses  (30.78%)
   <not supported>      L1-icache-loads                                             
         1,063,090      L1-icache-load-misses                                         (30.73%)
    20,299,282,092      dTLB-loads                # 2117.646 M/sec                    (30.71%)
             2,575      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.71%)
             9,551      iTLB-loads                #    0.996 K/sec                    (30.71%)
             3,598      iTLB-load-misses          #   37.67% of all iTLB cache accesses  (30.71%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       9.587286183 seconds time elapsed

       9.586373000 seconds user
       0.000000000 seconds sys


sudo perf stat -d -d -d ./mm -3
------------------------------
matrix_col: 5.49 sec

 Performance counter stats for './mm -3':

          5,513.95 msec task-clock                #    1.000 CPUs utilized          
                20      context-switches          #    0.004 K/sec                  
                 4      cpu-migrations            #    0.001 K/sec                  
               466      page-faults               #    0.085 K/sec                  
    14,828,139,094      cycles                    #    2.689 GHz                      (30.80%)
    60,973,775,765      instructions              #    4.11  insn per cycle           (38.49%)
     3,391,267,846      branches                  #  615.035 M/sec                    (38.49%)
         2,334,215      branch-misses             #    0.07% of all branches          (38.49%)
    16,878,823,576      L1-dcache-loads           # 3061.115 M/sec                    (38.49%)
       433,309,958      L1-dcache-load-misses     #    2.57% of all L1-dcache accesses  (38.44%)
         3,365,777      LLC-loads                 #    0.610 M/sec                    (30.76%)
         2,152,179      LLC-load-misses           #   63.94% of all LL-cache accesses  (30.75%)
   <not supported>      L1-icache-loads                                             
           548,083      L1-icache-load-misses                                         (30.75%)
    16,960,694,896      dTLB-loads                # 3075.963 M/sec                    (30.75%)
             2,318      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.75%)
             3,567      iTLB-loads                #    0.647 K/sec                    (30.75%)
             1,856      iTLB-load-misses          #   52.03% of all iTLB cache accesses  (30.75%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       5.515083820 seconds time elapsed

       5.506528000 seconds user
       0.007997000 seconds sys


sudo perf stat -d -d -d ./mm -4
------------------------------
block: 6.54 sec

 Performance counter stats for './mm -4':

          6,569.65 msec task-clock                #    1.000 CPUs utilized          
                17      context-switches          #    0.003 K/sec                  
                 3      cpu-migrations            #    0.000 K/sec                  
               464      page-faults               #    0.071 K/sec                  
    17,666,974,371      cycles                    #    2.689 GHz                      (30.69%)
    71,621,014,817      instructions              #    4.05  insn per cycle           (38.42%)
     3,426,262,519      branches                  #  521.529 M/sec                    (38.48%)
         9,224,418      branch-misses             #    0.27% of all branches          (38.54%)
    13,608,666,014      L1-dcache-loads           # 2071.444 M/sec                    (38.60%)
       470,070,921      L1-dcache-load-misses     #    3.45% of all L1-dcache accesses  (38.63%)
        29,286,930      LLC-loads                 #    4.458 M/sec                    (30.84%)
         1,785,194      LLC-load-misses           #    6.10% of all LL-cache accesses  (30.77%)
   <not supported>      L1-icache-loads                                             
           740,213      L1-icache-load-misses                                         (30.71%)
    13,551,506,696      dTLB-loads                # 2062.744 M/sec                    (30.68%)
             4,862      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.68%)
             5,511      iTLB-loads                #    0.839 K/sec                    (30.68%)
             2,907      iTLB-load-misses          #   52.75% of all iTLB cache accesses  (30.68%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       6.570854326 seconds time elapsed

       6.570250000 seconds user
       0.000000000 seconds sys


sudo perf stat -d -d -d ./mm -5
------------------------------
block_copy: 5.60 sec

 Performance counter stats for './mm -5':

          5,622.22 msec task-clock                #    1.000 CPUs utilized          
                23      context-switches          #    0.004 K/sec                  
                 8      cpu-migrations            #    0.001 K/sec                  
             1,524      page-faults               #    0.271 K/sec                  
    15,122,357,041      cycles                    #    2.690 GHz                      (30.74%)
    61,614,557,589      instructions              #    4.07  insn per cycle           (38.49%)
     3,433,388,386      branches                  #  610.682 M/sec                    (38.54%)
         9,174,149      branch-misses             #    0.27% of all branches          (38.54%)
    20,405,670,462      L1-dcache-loads           # 3629.468 M/sec                    (38.54%)
       445,925,952      L1-dcache-load-misses     #    2.19% of all L1-dcache accesses  (38.53%)
        19,924,235      LLC-loads                 #    3.544 M/sec                    (30.73%)
         1,069,603      LLC-load-misses           #    5.37% of all LL-cache accesses  (30.73%)
   <not supported>      L1-icache-loads                                             
           615,868      L1-icache-load-misses                                         (30.73%)
    20,440,169,432      dTLB-loads                # 3635.604 M/sec                    (30.73%)
            18,519      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.73%)
             7,552      iTLB-loads                #    0.001 M/sec                    (30.73%)
             2,456      iTLB-load-misses          #   32.52% of all iTLB cache accesses  (30.73%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       5.623555081 seconds time elapsed

       5.618834000 seconds user
       0.003999000 seconds sys


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
