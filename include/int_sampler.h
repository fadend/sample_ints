#ifndef COM_REVFAD_SAMPLE_INTS_INT_SAMPLER_H_
#define COM_REVFAD_SAMPLE_INTS_INT_SAMPLER_H_

#include <algorithm>
#include <cstdint>
#include <ctime>
#include <random>
#include <unordered_set>

namespace revfad {

template <typename T> class IntSampler {
  using Rng = typename std::conditional<sizeof(T) >= sizeof(int64_t),
                                        std::mt19937_64, std::mt19937_64>::type;

public:
  IntSampler(T max_value, int seed = 0)
      : max_value_(std::max<T>(0, max_value)),
        generator_(
            static_cast<typename Rng::result_type>(IntSampler::get_seed(seed))),
        distribution_(0, max_value_) {}
  // Tests whether any unique values remain to be sampled.
  bool has_next() const {
    // Note: unordered_set.size is O(1) --
    // https://en.cppreference.com/w/cpp/container/unordered_set/size.html.
    return already_sampled_.size() < max_value_ + 1;
  }
  // Once the underlying values have been exhausted, will return 0 for all
  // subsequent calls.
  T next() {
    if (!has_next()) {
      return 0;
    }
    // Note: the following has bad behavior when there are few fresh numbers
    // left to be sampled.
    // TODO: switch to a different strategy when we are seeing lots of rejected
    // samples.
    while (true) {
      T next = distribution_(generator_);
      if (already_sampled_.count(next) > 0) {
        continue;
      }
      already_sampled_.insert(next);
      return next;
    }
  }

private:
  T max_value_;
  Rng generator_;
  std::uniform_int_distribution<T> distribution_;
  std::unordered_set<T> already_sampled_;

  static int get_seed(int seed) {
    if (seed == 0) {
      // Following "Professional C++":
      std::random_device seeder;
      seed = seeder.entropy() ? seeder() : time(nullptr);
    }
    return seed;
  }
};

} // namespace revfad

#endif // COM_REVFAD_SAMPLE_INTS_INT_SAMPLER_H_