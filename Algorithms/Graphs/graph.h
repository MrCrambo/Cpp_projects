#include <list>
#include <vector>
#include <iostream>

namespace algorithms { namespace graphs {

struct Node
{
    int dest;
    struct Node* next;
};

struct AdjList
{
    struct Node *head;
};

class AdjListGraph {
public:
    AdjListGraph(int verticesCount)
    {
        this->verticesCount = verticesCount;
        array = new AdjList [verticesCount];
        for (int i = 0; i < verticesCount; ++i)
            array[i].head = NULL;
    }

    Node* newNode(int dest)
    {
        Node* newNode = new Node;
        newNode->dest = dest;
        newNode->next = NULL;
        return newNode;
    }

    void addEdge(int src, int dest)
    {
        Node* n = newNode(dest);
        n->next = array[src].head;
        array[src].head = n;

        n = newNode(src);
        n->next = array[dest].head;
        array[dest].head = n;
    }

    void printGraph()
    {
        int v;
        for (v = 0; v < verticesCount; ++v)
        {
            Node* pCrawl = array[v].head;
            std::cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
            while (pCrawl)
            {
                std::cout<<" -> "<<pCrawl->dest;
                pCrawl = pCrawl->next;
            }
            std::cout<<std::endl;
        }
    }
    
private:
    int verticesCount;
    struct AdjList* array;
};

class AdjMatrixGraph {
public:
    AdjMatrixGraph(int verticesCount)
    {
        this->verticesCount = verticesCount;
        adjMatrix = new bool*[verticesCount];

        for (int i = 0; i < verticesCount; i++)
        {
            adjMatrix[i] = new bool[verticesCount];

            used.push_back(false);
            color.push_back(0);
            breadth.push_back(-1);

            for (int j = 0; j < verticesCount; j++)
                adjMatrix[i][j] = false;
        }
    }

    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    int dfs(int v)
    {
        used[v] = true;
        color[v] = 1;
        for (int i = 0; i < verticesCount; i++)
        {
            if (adjMatrix[v][i] && !used[i] && color[i] == 0)
                dfs(i);

            // cycle check if color[i] is 1
        }
        color[v] = 2;
        return v;
    }

    std::vector<int> bfs(int v)
    {
        if (v >= verticesCount)
            exit(-1);
        std::vector<int> visited;
        breadth[v] = 0;
        visited.push_back(v);
        while (!visited.empty())
        {
            int u = visited.back();
            visited.pop_back();
            for (size_t i = 0; i < verticesCount; i++)
                if (adjMatrix[u][i] && breadth[i] == -1)
                {
                    breadth[i] = breadth[u] + 1;
                    visited.push_back(i);
                }
        }
        
        return breadth;
    }

    void toString()
    {
        for (int i = 0; i < verticesCount; i++)
        {
            std::cout << i << " : ";
            for (int j = 0; j < verticesCount; j++)
                std::cout << adjMatrix[i][j] << " ";
            std::cout << "\n";
        }
    }

    ~AdjMatrixGraph()
    {
        for (int i = 0; i < verticesCount; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
private:
    bool** adjMatrix;
    int verticesCount;

// for dfs
private:
    std::vector<bool> used;
    std::vector<int> color; // 0 - not entered; 1 - entered; 2 - left

private:
    std::vector<int> breadth;
};

} } // algoruthms::graphs
