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
loop_ijk: 11.92 sec
loop_reorder: 9.73 sec
matrix_col: 5.54 sec
block: 5.29 sec
block_copy: 5.12 sec
```
```
sudo perf stat -d -d -d ./mm -1
------------------------------
loop_ijk: 11.90 sec

 Performance counter stats for './mm -1':

         11,923.03 msec task-clock                #    0.998 CPUs utilized          
               459      context-switches          #    0.038 K/sec                  
                53      cpu-migrations            #    0.004 K/sec                  
               465      page-faults               #    0.039 K/sec                  
    32,033,713,210      cycles                    #    2.687 GHz                      (30.75%)
    77,846,561,112      instructions              #    2.43  insn per cycle           (38.49%)
     3,392,703,830      branches                  #  284.550 M/sec                    (38.53%)
         2,593,415      branch-misses             #    0.08% of all branches          (38.53%)
    16,898,083,719      L1-dcache-loads           # 1417.264 M/sec                    (38.56%)
     3,798,727,752      L1-dcache-load-misses     #   22.48% of all L1-dcache accesses  (38.58%)
       454,994,275      LLC-loads                 #   38.161 M/sec                    (30.77%)
       213,338,077      LLC-load-misses           #   46.89% of all LL-cache accesses  (30.74%)
   <not supported>      L1-icache-loads                                             
         4,334,258      L1-icache-load-misses                                         (30.70%)
    16,921,322,113      dTLB-loads                # 1419.213 M/sec                    (30.67%)
            27,709      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.70%)
            68,764      iTLB-loads                #    0.006 M/sec                    (30.74%)
             8,081      iTLB-load-misses          #   11.75% of all iTLB cache accesses  (30.74%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

      11.945033578 seconds time elapsed

      11.883791000 seconds user
       0.039945000 seconds sys


sudo perf stat -d -d -d ./mm -2
------------------------------
loop_reorder: 9.73 sec

 Performance counter stats for './mm -2':

          9,753.71 msec task-clock                #    0.998 CPUs utilized          
               389      context-switches          #    0.040 K/sec                  
                35      cpu-migrations            #    0.004 K/sec                  
               974      page-faults               #    0.100 K/sec                  
    26,223,443,672      cycles                    #    2.689 GHz                      (30.70%)
   104,743,102,783      instructions              #    3.99  insn per cycle           (38.40%)
     3,392,116,354      branches                  #  347.777 M/sec                    (38.41%)
         2,599,338      branch-misses             #    0.08% of all branches          (38.45%)
    20,283,437,097      L1-dcache-loads           # 2079.562 M/sec                    (38.49%)
       441,984,607      L1-dcache-load-misses     #    2.18% of all L1-dcache accesses  (38.48%)
         1,019,639      LLC-loads                 #    0.105 M/sec                    (30.83%)
           286,433      LLC-load-misses           #   28.09% of all LL-cache accesses  (30.82%)
   <not supported>      L1-icache-loads                                             
         3,884,347      L1-icache-load-misses                                         (30.82%)
    20,337,151,088      dTLB-loads                # 2085.069 M/sec                    (30.82%)
            26,781      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.76%)
            67,346      iTLB-loads                #    0.007 M/sec                    (30.73%)
             9,524      iTLB-load-misses          #   14.14% of all iTLB cache accesses  (30.69%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       9.771906008 seconds time elapsed

       9.730777000 seconds user
       0.023967000 seconds sys


sudo perf stat -d -d -d ./mm -3
------------------------------
matrix_col: 5.61 sec

 Performance counter stats for './mm -3':

          5,631.79 msec task-clock                #    0.998 CPUs utilized          
               316      context-switches          #    0.056 K/sec                  
                36      cpu-migrations            #    0.006 K/sec                  
               976      page-faults               #    0.173 K/sec                  
    15,138,716,399      cycles                    #    2.688 GHz                      (30.74%)
    60,946,283,267      instructions              #    4.03  insn per cycle           (38.47%)
     3,391,915,325      branches                  #  602.280 M/sec                    (38.54%)
         2,492,708      branch-misses             #    0.07% of all branches          (38.61%)
    16,869,795,946      L1-dcache-loads           # 2995.457 M/sec                    (38.68%)
       438,578,188      L1-dcache-load-misses     #    2.60% of all L1-dcache accesses  (38.56%)
         3,655,927      LLC-loads                 #    0.649 M/sec                    (30.77%)
         2,366,685      LLC-load-misses           #   64.74% of all LL-cache accesses  (30.70%)
   <not supported>      L1-icache-loads                                             
         1,692,864      L1-icache-load-misses                                         (30.69%)
    16,998,850,783      dTLB-loads                # 3018.372 M/sec                    (30.69%)
            28,810      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.69%)
            22,587      iTLB-loads                #    0.004 M/sec                    (30.69%)
             7,046      iTLB-load-misses          #   31.19% of all iTLB cache accesses  (30.63%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       5.643440787 seconds time elapsed

       5.624506000 seconds user
       0.007983000 seconds sys


sudo perf stat -d -d -d ./mm -4
------------------------------
block: 5.35 sec

 Performance counter stats for './mm -4':

          5,374.38 msec task-clock                #    0.998 CPUs utilized          
               303      context-switches          #    0.056 K/sec                  
                36      cpu-migrations            #    0.007 K/sec                  
               463      page-faults               #    0.086 K/sec                  
    14,446,391,591      cycles                    #    2.688 GHz                      (30.78%)
    48,102,503,230      instructions              #    3.33  insn per cycle           (38.51%)
     3,435,783,743      branches                  #  639.289 M/sec                    (38.58%)
        11,555,171      branch-misses             #    0.34% of all branches          (38.66%)
    10,254,443,604      L1-dcache-loads           # 1908.023 M/sec                    (38.64%)
       481,851,131      L1-dcache-load-misses     #    4.70% of all L1-dcache accesses  (38.54%)
        38,560,493      LLC-loads                 #    7.175 M/sec                    (30.82%)
         2,289,631      LLC-load-misses           #    5.94% of all LL-cache accesses  (30.74%)
   <not supported>      L1-icache-loads                                             
         2,329,454      L1-icache-load-misses                                         (30.69%)
    10,218,048,525      dTLB-loads                # 1901.251 M/sec                    (30.67%)
            25,970      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.60%)
            31,810      iTLB-loads                #    0.006 M/sec                    (30.60%)
             5,897      iTLB-load-misses          #   18.54% of all iTLB cache accesses  (30.68%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       5.386557574 seconds time elapsed

       5.351435000 seconds user
       0.023961000 seconds sys


sudo perf stat -d -d -d ./mm -5
------------------------------
block_copy: 5.16 sec

 Performance counter stats for './mm -5':

          5,189.10 msec task-clock                #    0.998 CPUs utilized          
               287      context-switches          #    0.055 K/sec                  
                41      cpu-migrations            #    0.008 K/sec                  
               816      page-faults               #    0.157 K/sec                  
    13,951,821,534      cycles                    #    2.689 GHz                      (30.72%)
    44,787,935,664      instructions              #    3.21  insn per cycle           (38.39%)
     3,439,329,851      branches                  #  662.799 M/sec                    (38.39%)
        11,542,510      branch-misses             #    0.34% of all branches          (38.39%)
    13,681,270,173      L1-dcache-loads           # 2636.539 M/sec                    (38.42%)
       450,778,742      L1-dcache-load-misses     #    3.29% of all L1-dcache accesses  (38.44%)
        23,560,106      LLC-loads                 #    4.540 M/sec                    (30.76%)
         1,240,657      LLC-load-misses           #    5.27% of all LL-cache accesses  (30.77%)
   <not supported>      L1-icache-loads                                             
         1,638,579      L1-icache-load-misses                                         (30.84%)
    13,749,814,281      dTLB-loads                # 2649.748 M/sec                    (30.84%)
            55,038      dTLB-load-misses          #    0.00% of all dTLB cache accesses  (30.85%)
            28,689      iTLB-loads                #    0.006 M/sec                    (30.84%)
             8,361      iTLB-load-misses          #   29.14% of all iTLB cache accesses  (30.75%)
   <not supported>      L1-dcache-prefetches                                        
   <not supported>      L1-dcache-prefetch-misses                                   

       5.201901057 seconds time elapsed

       5.182092000 seconds user
       0.007984000 seconds sys

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
- [X] improve block algorithm
- [ ] find better submatrix size for each machine
