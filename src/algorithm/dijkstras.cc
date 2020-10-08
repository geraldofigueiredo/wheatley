#include "dijkstras.h"

std::vector<int> Dijkstras::findShortestPath(const std::vector<std::vector<double>> &graph, const int source, const int target) {
    std::vector<int> sequence;
    sequence.resize(graph.size());

    std::vector<double> route;
    route.resize(graph.size());

    std::vector<bool> sptSet;
    sptSet.resize(graph.size());
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < route.size(); i++) 
        route[i] = __DBL_MAX__, sptSet[i] = false, sequence[i] = -1;

    // Distance of source vertex from itself is always 0 
    route[source] = 0;
  
    // Find shortest path for all vertices 
    int u, count = 0;
    do {
        count++;
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        u = minDistance(route, sptSet);
        sequence.push_back(u);
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < graph.size(); v++) 
            if (!sptSet[v] && graph[u][v] && route[u] != __DBL_MAX__ && route[u] + graph[u][v] < route[v]) {
                sequence[v] = u;
                route[v] = route[u] + graph[u][v];
            }
    }while(u != target && count < graph.size());
  
    
    std::vector<int> output;
    std::cout << "Rota gerada: ";
    getPath(sequence, target, output);
    if (output.size() > 1) {
        output.insert(output.begin(), 0);
    }
    std::cout << std::endl;
    return output;
}

int Dijkstras::minDistance(std::vector<double> route, std::vector<bool> sptSet){
    // Initialize min value
    double min = __DBL_MAX__;
    int min_index;

    for (int v = 0; v < route.size(); v++)
        if (sptSet[v] == false && route[v] <= min)
            min = route[v], min_index = v;
  
    return min_index; 
}

void Dijkstras::getPath(const std::vector<int> &parent, const int j, std::vector<int> &outputRoute) {
    // Base Case : If j is source
    if (parent[j] == -1)
        return;

    getPath(parent, parent[j], outputRoute);

    std::cout << j << " ";
    outputRoute.push_back(j);
}