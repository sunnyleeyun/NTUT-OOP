#include "../src/dot.h"

// 2-dimensional vector dot 2-dimensional vector
TEST(Vector, Dot2Dim2DimType1) {
    double u[2] = {1, 2}, v[2] = {3, 4};
    int dim_u = 2, dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(11.0, result, 0.001);
}

TEST(Vector, Dot2Dim2DimType2) {
    double u[2] = {-4, -9}, v[2] = {-1, 2};
    int dim_u = 2, dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(-14.0, result, 0.001);
}

// 3-dimensional vector dot 3-dimensional vector
TEST(Vector, Dot3Dim3DimType1) {
    double u[3] = {9, 2, 7}, v[3] = {4, 8, 10};
    int dim_u = 3, dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(122.0, result, 0.001);
}

TEST(Vector, Dot3Dim3DimType2) {
    double u[3] = {1, 2, 3}, v[3] = {4, -5, 6};
    int dim_u = 3, dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(12.0, result, 0.001);
}

// 3-dimensional vector dot 4-dimensional vector
TEST(Vector, DotDifDimType1Exception) {
    double u[3] = {9, 2, 7}, v[4] = {4, 8, 10, 12};
    int dim_u = 3, dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Vector, DotDifDimType2Exception) {
    double u[4] = {1, 2, 3, -8}, v[3] = {4, -5, 6};
    int dim_u = 4, dim_v = 3;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

// pass -1 as dimension parameter (dim_u, dim_v)
TEST(Vector, DotNegDimType1Exception) {
    double u[1] = {1}, v[2] = {3, 4};
    int dim_u = -1, dim_v = 2;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Vector, DotNegDimType2Exception) {
    double u[2] = {-4, -9}, v[1] = {2};
    int dim_u = 2, dim_v = -1;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}