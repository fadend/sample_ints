#include "int_sampler.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: sample_ints [max_value] [count]\n";
    return 1;
  }
  const long max_value = std::stol(argv[1]);
  const int count = std::stoi(argv[2]);
  revfad::IntSampler<long> sampler(max_value);
  for (int i = 0; i < count && sampler.has_next(); ++i) {
    std::cout << sampler.next() << '\n';
  }
}