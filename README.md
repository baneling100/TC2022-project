# Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications in CPM 2001
Paper authors: Toru Kasai, Gunho Lee, Hiroki Arimura, Setsuo Arikawa, and Kunsoo Park, reproduced by Seunghyeon Nam and Woohyeon Baek

## Overview
This program implements Kasai's linear-time LCP construction algorithm with ...

## Preparing for dataset
We use "Harry Potter Books Corpora (Part 1-7)" (7001402 bytes = 6.68MiB) to compare computation time on English texts. The dataset is already in the repository so **you don't have to download it manually**, but you can download it via kaggle API described below if you want.
```
$ pip install kaggle  # download kaggle API
# login to kaggle and download your "kaggle.json" to ~/.kaggle/
$ kaggle datasets download -d balabaskar/harry-potter-books-corpora-part-1-7  # download dataset
```

You may also use the provided script to create larger input data.
```
$ python3 pattern-gen.py
>> Enter max pattern length (default: 1000) >>
>> Enter number of patterns (default: 1000) >>
$ python3 text-gen.py
>> Enter number of repetitions for input generation (default: 5000) >>
```
The generated input will be written to `input.txt`.

## How to compile and run
Just execute Makefile, then you can get some computation time results.
```
$ make
$ make run
```

## Results: TODO