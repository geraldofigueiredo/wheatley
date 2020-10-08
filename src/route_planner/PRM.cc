#include "PRM.h"

void PRM::generateRoute(const Image &image, const Image::Position& start, const Image::Position& end) {
    unsigned int numNodes = 0;
    std::vector<int> route;
    Image imageWithNodes = Image(image);

    do {
        numNodes += 10;
        std::cout << "número de nós utilizados: " << numNodes << " - ";

        Image copyImage = Image(image);

        copyImage.setStartLocation(start);
        copyImage.setEndLocation(end);
        
        this->resetNodeGrid(start, end);
        this->resetDistanceMatrix(numNodes);
        
        auto imageWithNodes = generateNodeGrid(copyImage, numNodes);

        image_op::writeImage("../resources/1-nodes.png", imageWithNodes);
        image_op::writeImage("../resources/2-nodesConnection.png", connectNodes(imageWithNodes));

        route = shortestPathAlgo->findShortestPath(this->distanceMatrix, 0, 1);
    }while(route.size() == 0 || numNodes == 1000);

    image_op::writeImage("../resources/3-route.png", drawRoute(imageWithNodes, route));
}

Image PRM::generateNodeGrid(Image image, const unsigned int numNodes) {
    const auto [width, height] = image.getDimension();
    Point::Component x;
    Point::Component y;
    
    for (size_t i = 0; i < numNodes; i++) {
        do {
            x = rand() % width;
            y = rand() % height;
        } while(image.isOccupied({x,y}));

        nodeGrid.push_back({x,y});
        image.setPixel({x,y}, Color::BLUE());
    }
    return image;
}

Image PRM::connectNodes(Image image) {
    for (size_t i = 0; i < nodeGrid.size(); i++) {
        for (size_t j = 0; j < nodeGrid.size(); j++) {
            if (i == j) {
                this->distanceMatrix[i][j] = 0;
                continue;
            }
            std::vector<Image::Position> points = image.getPathBetweenPoints(nodeGrid[i], nodeGrid[j]);
            image.drawLine(points);

            if (points.size() > 0) {
                setDistanceBetweenPoints(i, j);
            }
        }
    }
    return image;
}

Image PRM::drawRoute(Image image, const std::vector<int> &sequence) {
    for (size_t i = 0; i < sequence.size()-1; i++) {
        int start = sequence[i];
        int end = sequence[i+1];
        const auto points = image.getPathBetweenPoints(this->nodeGrid[start], this->nodeGrid[end]);
        image.drawLine(points);
    }
    return image;
}
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(std::vector<double> route, std::vector<bool> sptSet) {
    // Initialize min value
    double min = __DBL_MAX__;
    int min_index;

    for (int v = 0; v < route.size(); v++)
        if (sptSet[v] == false && route[v] <= min)
            min = route[v], min_index = v;
  
    return min_index; 
} 

void printPath(const std::vector<int> &parent, const int j, std::vector<int> &outputRoute) {
    // Base Case : If j is source 
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j], outputRoute);

    printf("%d ", j);
    outputRoute.push_back(j);
} 

// A utility function to print the constructed distance array 
void printSolution(const std::vector<double> &route, const std::vector<int> &parent, std::vector<int> &outputRoute) {
    int src = 0; 
    printf("Vertex\t Distance\tPath"); 
    for (int i = 1; i < route.size(); i++) 
    { 
        printf("\n%d -> %d \t\t %f\t\t%d ", 
                      src, i, route[i], src);
        printPath(parent, i, outputRoute);
    } 
}
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
std::vector<int> dijkstra(const std::vector<std::vector<double>> &graph, const int source, const int target) {
    std::vector<int> sequence;
    sequence.resize(graph.size());

    std::vector<double> route;
    route.resize(graph.size());
    // int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 

    std::vector<bool> sptSet;
    sptSet.resize(graph.size());
    // bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < route.size(); i++) 
        route[i] = __DBL_MAX__, sptSet[i] = false, sequence[i] = -1;

    route[source] = 0;
  
    // Distance of source vertex from itself is always 0 
    // dist[src] = 0; 
    int u, count = 0;
    // Find shortest path for all vertices 
    do {
        count++;
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        u = minDistance(route, sptSet);
        sequence.push_back(u);
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < graph.size(); v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && route[u] != __DBL_MAX__ && route[u] + graph[u][v] < route[v]) {
                sequence[v] = u;
                route[v] = route[u] + graph[u][v];
            }
    }while(u != target && count < graph.size());
  
    // print the constructed distance array
    std::vector<int> output;
    // printSolution(route, sequence, output);
    printPath(sequence, target, output);
    if (output.size() > 1) {
        output.insert(output.begin(), 0);
    }
    return output;
}