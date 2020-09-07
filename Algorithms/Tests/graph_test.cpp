#include "../Graphs/graph.h"

int main(int argc, char * argv[])
{
    algorithms::graphs::AdjMatrixGraph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    // gh.addEdge(1, 2);
    // gh.addEdge(1, 3);
    // gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    gh.toString();

    std::cout<< "Dfs from 0 is: " << gh.dfs(0) << std::endl << std::endl;
    // std::cout<< "Dfs from 1 is: " << gh.dfs(1) << std::endl << std::endl;
    // std::cout<< "Dfs from 2 is: " << gh.dfs(2) << std::endl << std::endl;
    // std::cout<< "Dfs from 3 is: " << gh.dfs(3) << std::endl << std::endl;
    // std::cout<< "Dfs from 4 is: " << gh.dfs(4) << std::endl << std::endl;

    return 0;
}