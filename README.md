# Output unique random ints

Trying for an answer for "Programming Pearls" 1.6 Problems 4, writing a program
to output random ints (without replacement).

## Build

This is using CMake for driving builds.

```
cmake .
make all
```

## Run

```
./sample_ints 1000000 20     
318138
84762
855258
856497
567931
46295
14591
91373
597581
977856
16761
451594
575484
714118
907344
37665
772289
256536
385728
797620
```

## Run tests

After building:

```
ctest --output-on-failure
```

## Acknowledgments

Code was formatted with clang-format.

The example CMake projects at https://github.com/ttroy50/cmake-examples were
helpful. Thank you!