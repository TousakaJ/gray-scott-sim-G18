#include "gtest/gtest.h"

extern double Du;                     // Diffusion rate of U
extern double Dv;                     // Diffusion rate of V
extern double F;                      // Feed rate
extern double k;                      // Kill rate
extern double threshold;

extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

extern void init();
extern void writeVTKFile(int iteration);
extern void writeVTKFileU(int iteration);
extern void simulateStep();
extern double countElementsAboveThreshold(double threshold);