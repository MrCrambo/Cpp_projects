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

class Graph
{
public:
    Graph(int count)
    {
        this->verticesCount = count;
        array = new AdjList [count];
        for (int i = 0; i < count; ++i)
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

} } // algoruthms::graphs