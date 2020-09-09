#include "../Graphs/graph.h"

int main(int argc, char * argv[])
{
    algorithms::graphs::AdjMatrixGraph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    gh.toString();

    std::cout<< "Dfs from 0 is: " << gh.dfs(0) << std::endl;

    auto path = gh.getPath(0, 3);
    for (const auto& i: path)
        std::cout << i << " -> ";

    return 0;
}