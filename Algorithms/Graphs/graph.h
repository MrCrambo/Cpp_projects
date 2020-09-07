#include <list>
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
};

} } // algoruthms::graphs
