#include <gtest/gtest.h>
#include "./ut_polynomial.h"
#include "./ut_term.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
