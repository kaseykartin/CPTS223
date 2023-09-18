#include "testQueue.h"
//Having everything within a single file, not splitting function definitions into a .cpp is poor
//coding structure. 
//
//I personally would create a queue using linked nodes to store information instead of an array, 
//would require less data members
//
//the destructor deletes the array made by the queue but none of the other data members
//
//peek() should have some sort of exit statement when viewing an empty list, rather than returning 
//a meaningless value
//
//this program could definitely use more commenting, its pretty bare minimum as it came
int main()
{

   bool isFull = isFullTest();

   bool isEmpty = isEmptyTest();

   int peek = peekTest1();
   peek = peekTest2();

   int size = sizeTest();

   queue q = dequeueTest1();
   dequeueTest2();

   queue q2 = enqueueTest1();
   enqueueTest2();


    return 0;
}