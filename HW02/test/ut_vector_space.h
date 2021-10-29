#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

// ADD
// TA
TEST(VectorTest, add_TA) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};

  double * result = add(u, 3, v, 3);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}

// add two vectors properly
TEST(Vector, Add4Dim) {
    double u[4] = {8.8, 9.9, 10.10, 11.11};
    double v[4] = {1.2, 0.1, -0.10, -1.11};
    double * result = add(u, 4, v, 4);
    EXPECT_NEAR(10.0, result[0], DELTA);
    EXPECT_NEAR(10.0, result[1], DELTA);
    EXPECT_NEAR(10.0, result[2], DELTA);
    EXPECT_NEAR(10.0, result[3], DELTA);
    delete [] result;
}

TEST(Vector, Add2Dim) {
    double u[2] = {1, 15};
    double v[2] = {11, 25};
    double * result = add(u, 2, v, 2);
    EXPECT_NEAR(12.0, result[0], DELTA);
    EXPECT_NEAR(40.0, result[1], DELTA);
    delete [] result;
}

// throw exception if vectors are in different dimension
TEST(VectorTest, AddDiffDim) {
    double u[3] = {2, 5, 10};
    double v[2] = {8, 0.8};
    ASSERT_THROW(add(u, 3, v, 2), std::string);
}

// throw exception if vector has 0 or negative dimension
TEST(VectorTest, AddNonPosDim) {
    double u[] = {};
    double v[] = {};
    ASSERT_THROW(add(u, 0, v, 0), std::string);
}

// SCALE
// TA
TEST(VectorTest, scale_TA) {
  double u[3] = {1.5, 2.5, 3.5};

  double * result = scale(u, 3, 1.2);

  EXPECT_NEAR(1.8, result[0], DELTA);
  EXPECT_NEAR(3.0, result[1], DELTA);
  EXPECT_NEAR(4.2, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}

// scale the vector properly
TEST(Vector, Scale4Dim) {
    double u[4] = {1, 10, 100, 1000};
    double * result = scale(u, 4, 2.5);
    EXPECT_NEAR(2.5, result[0], DELTA);
    EXPECT_NEAR(25.0, result[1], DELTA);
    EXPECT_NEAR(250.0, result[2], DELTA);
    EXPECT_NEAR(2500.0, result[3], DELTA);
    delete [] result;
}

TEST(Vector, Scale2Dim) {
    double u[2] = {11, 25};
    double * result = scale(u, 2, 1.15);
    EXPECT_NEAR(12.65, result[0], DELTA);
    EXPECT_NEAR(28.75, result[1], DELTA);
    delete [] result;
}

// throw exception if vector has 0 or negative dimension
TEST(VectorTest, ScaleNonPosDim) {
    double u[] = {};
    ASSERT_THROW(scale(u, 0, 1.2), std::string);
}

