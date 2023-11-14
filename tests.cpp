#define BOOST_TEST_MODULE Tests
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include <boost/type_index.hpp>
#include <type_traits>
#include "gs.h"
#include "tests.h"

BOOST_AUTO_TEST_CASE(testGrayScottDiffusionZeroCase) {
    //Simulates the case when u=0 and v=0 to check for the correct result
    // Your checks go here
    init();
    setZero();
    simulateStep();
    for (const auto& row : u) {
        for (const auto& element : row) {
            BOOST_CHECK_CLOSE(element, 0, 1e-9);
        }
    }
    for (const auto& row : v) {
        for (const auto& element : row) {
            BOOST_CHECK_CLOSE(element, 0, 1e-9);;
        }
    }
    // Count elements above threshold
    double result = countElementsAboveThreshold(threshold);

    // Verify the result
    BOOST_CHECK_CLOSE(result, 0, 1e-9);
}

BOOST_AUTO_TEST_CASE(testInitialization) {
    // This tests that the initialization function has the correct types of variables and sizes of u and v 
    // Set simulation parameters for the test
    Du = 0.1;
    Dv = 0.05;
    F = 0.03;
    k = 0.0648;
    threshold = 0.1;

    // Initialize and run the simulation
    init();
    BOOST_CHECK(typeid(F) == typeid(u[0][0]));
    BOOST_CHECK(typeid(k) == typeid(u[0][0]));
    BOOST_CHECK(typeid(F) == typeid(v[0][0]));
    BOOST_CHECK(typeid(k) == typeid(v[0][0]));
    BOOST_CHECK(u.size() == v.size());
    BOOST_CHECK(u[0].size() == v[0].size());
}

BOOST_AUTO_TEST_CASE(testSimulation) {
    // This tests that the simulationstep function maintains the correct types of variables and sizes of u and v 
    // Set simulation parameters for the test
    Du = 0.1;
    Dv = 0.05;
    F = 0.03;
    k = 0.0648;
    threshold = 0.1;

    // Initialize and run the simulation
    init();
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }
    BOOST_CHECK(typeid(F) == typeid(u[0][0]));
    BOOST_CHECK(typeid(k) == typeid(u[0][0]));
    BOOST_CHECK(typeid(F) == typeid(v[0][0]));
    BOOST_CHECK(typeid(k) == typeid(v[0][0]));
    BOOST_CHECK(u.size() == v.size());
    BOOST_CHECK(u[0].size() == v[0].size());

    // Verify the simulation results or other conditions
    // ...

    // You can use BOOST_CHECK or BOOST_REQUIRE macros to add more specific checks
}

BOOST_AUTO_TEST_CASE(testCountElementsAboveThreshold) {
    //Tests that the CountElementsAboveThreshold gives the correct result under an example input
    // Initialize grid and constants
    const int testWidth = 3;
    const int testHeight = 3;
    std::vector<std::vector<double>> testU(testWidth, std::vector<double>(testHeight, 1.0));
    std::vector<std::vector<double>> testV(testWidth, std::vector<double>(testHeight, 0.0));

    // Set simulation parameters for the test
    Du = 0.1;
    Dv = 0.05;
    F = 0.03;
    k = 0.0648;
    threshold = 0.1;
    init();
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    // Count elements above threshold
    double result = countElementsAboveThreshold(threshold);

    // Verify the result
    BOOST_CHECK_CLOSE(result, 0, 1e-9);
}
// /* Expected value */ was here