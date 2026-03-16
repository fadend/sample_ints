#include "../include/int_sampler.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace revfad {
namespace {

using ::testing::AllOf;
using ::testing::Ge;
using ::testing::Le;

TEST(IntSamplerTests, AllValuesInRange) {
  IntSampler<int> sampler(1000, 1);
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(1000)));
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(1000)));
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(1000)));
}

TEST(IntSamplerTests, SmallRange) {
  IntSampler<long> sampler(2, 1);
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(2)));
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(2)));
  ASSERT_TRUE(sampler.has_next());
  ASSERT_THAT(sampler.next(), AllOf(Ge(0), Le(2)));
  ASSERT_FALSE(sampler.has_next());
  ASSERT_EQ(sampler.next(), 0);
}

TEST(IntSamplerTests, NegativeMax) {
  // max_value gets clipped to 0.
  IntSampler<long> sampler(-1, 1);
  ASSERT_TRUE(sampler.has_next());
  ASSERT_EQ(sampler.next(), 0);
  ASSERT_FALSE(sampler.has_next());
}

TEST(IntSamplerTests, NoSeed) {
  // max_value gets clipped to 0.
  IntSampler<long> sampler(0, 1);
  ASSERT_TRUE(sampler.has_next());
  ASSERT_EQ(sampler.next(), 0);
  ASSERT_FALSE(sampler.has_next());
}

} // namespace
} // namespace revfad