#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue<int> h;
    int j[] = {1,2,3,4,5,6,6,7,8,45};
    for(int i = 0 ; i != 10 ; ++i){
        h.enqueue(j[i]);
    }
    h.printQueue();
    h.dequeue();
    h.printQueue();
}