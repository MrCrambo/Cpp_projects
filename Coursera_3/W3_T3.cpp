#include "test_runner.h"

#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList(){
        while(head){
            PopFront();
        }
    }

    void PushFront(const T& value){
        Node* new_node = new Node{value};
        new_node->next = head;
        head = new_node;
    }

    void InsertAfter(Node* node, const T& value){
        if(node == nullptr){
            PushFront(value);
            return;
        }
        Node* new_node = new Node{value};
        new_node->next = node->next;
        node->next = new_node;
    }

    void RemoveAfter(Node* node){
        if(node == nullptr){
            PopFront();
            return;
        }
        
        if(node->next){
            Node* deleted_node = node->next;
            node->next = deleted_node->next;
            delete deleted_node;
        }
    }

    void PopFront(){
        if(head){
            Node* new_head = head->next;
            delete head;
            head = new_head;
        }
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};