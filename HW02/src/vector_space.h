#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H

double *add(double u[], int dim_u, double v[], int dim_v) {
    if (dim_u != dim_v || dim_u <= 0 || dim_v <= 0) {
        throw std::string("undefined.");
    }

    double *r = new double[dim_u];
    for (int i = 0; i < dim_u; i++) {
        r[i] = u[i] + v[i];
    }

    return r;
}

double *scale(double u[], int dim, double s) {
    if (dim <= 0) {
        throw std::string("undefined.");
    }

    double *r = new double[dim];
    for (int i = 0; i < dim; i++) {
        r[i] = u[i] * s;
    }

    return r;
}

#endif