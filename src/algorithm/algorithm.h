#pragma once

#include <vector>

class Algorithm {
public:
    virtual std::vector<int> findShortestPath(const std::vector<std::vector<double>> &graph, const int source, const int target) = 0;
};