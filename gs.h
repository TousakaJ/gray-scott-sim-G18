#ifndef GS_H
#define GS_H

#include <vector>
#include <string>

// Define simulation parameters
extern const int width;
extern const int height;
extern double Du;
extern double Dv;
extern double F;
extern double k;
extern double threshold;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;

// Initialize grid and constants
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

// Function declarations
void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif