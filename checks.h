#ifndef CHECKS_H
#define CHECKS_H

#include <vector>

extern void checkTypes(double F, double k, const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
extern void checkSizes(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
extern void checkSimulation(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
extern void setZero();

#endif