#include "../Graphs/graph.h"

int main(int argc, char * argv[])
{
    algorithms::graphs::Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    // print the adjacency list representation of the above graph
    gh.printGraph();
    return 0;
}