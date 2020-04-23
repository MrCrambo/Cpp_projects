#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate(){
        if(free.empty()){
            free.push(new T);
        }
        auto new_object = free.front();
        free.pop();
        allocated.insert(new_object);
        return new_object;
    }

    T* TryAllocate(){
        T* new_object;
        if(free.empty()){
            return nullptr;
        }
        return Allocate();
    }

    void Deallocate(T* object){
        if(allocated.count(object) != 0){
            free.push(object);
            allocated.erase(object);
        }else{
            throw invalid_argument("Object is not find");
        }
    }


    ~ObjectPool(){
        for(auto x : allocated){
            delete x;
        }
        while(!free.empty()){
            T* deleting_object = free.front();
            free.pop();
            delete deleting_object;
        }
    }

private:
    set<T*> allocated;
    queue<T*> free;
};
