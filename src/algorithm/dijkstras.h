#pragma once

#include <iostream>

#include "algorithm.h"

class Dijkstras: public Algorithm {
private:
    int minDistance(std::vector<double> route, std::vector<bool> sptSet);
    void getPath(const std::vector<int> &parent, const int j, std::vector<int> &outputRoute);
public:
    std::vector<int> findShortestPath(const std::vector<std::vector<double>> &graph, const int source, const int target);
};