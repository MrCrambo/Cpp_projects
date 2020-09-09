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
        adjMatrix = new int*[verticesCount];

        for (int i = 0; i < verticesCount; i++)
        {
            adjMatrix[i] = new int[verticesCount];

            used.push_back(false);
            color.push_back(0);

            breadth.push_back(-1);
            path.push_back(-1);

            for (int j = 0; j < verticesCount; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int i, int j, int w = 1)
    {
        if (i >= verticesCount ||
            j >= verticesCount ||
            i < 0 || j < 0)
        {
            exit(-1);
        }
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    void removeEdge(int i, int j)
    {
        if (i >= verticesCount ||
            j >= verticesCount ||
            i < 0 || j < 0)
        {
            exit(-1);
        }
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }

    int dfs(int v)
    {
        if (v >= verticesCount)
            exit(-1);

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

    /*
    **  Breadth First Search
    **
    */
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
                    path[i] = u;
                }
        }
        
        return breadth;
    }

    /*
    ** Will not correctly search in case of having weights
    */
    std::vector<int> getPath(int from, int to)
    {
        std::vector<int> p;
        std::vector<int> b = bfs(from);
        while (to != -1)
        {
            p.push_back(to);
            to = path[to];
        }
        return p;
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
    int** adjMatrix;
    int verticesCount;

// for dfs
private:
    std::vector<bool> used;
    std::vector<int> color; // 0 - not entered; 1 - entered; 2 - left

private:
    std::vector<int> breadth;
    std::vector<int> path;
};

} } // algoruthms::graphs
