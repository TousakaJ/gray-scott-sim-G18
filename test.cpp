#define UNIT_TESTING
#include "acutest.h"
#include "gs.cpp"

void test_type_match() {
    TEST_CHECK(typeid(F) == typeid(double));
    TEST_CHECK(typeid(k) == typeid(double));
    TEST_CHECK(typeid(u[0][0]) == typeid(double));
    TEST_CHECK(typeid(v[0][0]) == typeid(double));
}

void test_vector_sizes() {
    TEST_CHECK(u.size() == v.size());
    for (size_t i = 0; i < u.size(); ++i) {
        TEST_CHECK(u[i].size() == v[i].size());
    }
}

void test_simulation_correctness() {

    F = 0.0;
    k = 0.0;

    for (auto &row : u) {
        std::fill(row.begin(), row.end(), 0.0);
    }
    for (auto &row : v) {
        std::fill(row.begin(), row.end(), 0.0);
    }
    
    simulateStep();

    // Check for the expected outcome here
    // For instance, if u and v are expected to remain 0, you can check for that
    for (const auto &row : u) {
        for (double val : row) {
            TEST_CHECK(val == 0.0);
        }
    }
    for (const auto &row : v) {
        for (double val : row) {
            TEST_CHECK(val == 0.0);
        }
    }
}

// Define the test suite
TEST_LIST = {
   { "test_type_match", test_type_match },
   { "test_vector_sizes", test_vector_sizes },
   { "test_simulation_correctness", test_simulation_correctness },
   { NULL, NULL } // Terminate the test list
};
