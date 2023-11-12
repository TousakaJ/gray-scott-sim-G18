#ifndef CHECKS_H
#define CHECKS_H

#include <vector>

void checkTypes(double F, double k, const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
void checkSizes(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
void checkSimulation(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v);
void setZero();

#endif