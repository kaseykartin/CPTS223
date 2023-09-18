#include "testQueue.h"
/* Test ID : Full queue check - EQC
Unit : queue::isFull()
Description : test to determine if queue::isFull() returns 1 if a queue object is full
Test steps :
1. Construct an empty queue object
2. Invoke queue::enqueue() to fill queue object to capacity
3. Invoke queue::isFull()
4. Return result
Test data : size = 1
Precondition : queue object is empty
Postcondition : queue object is Full
Expected result : queue is full; 1 is returned
Actual result : queue is full; 1 is returned
Status : passed
*/
bool isFullTest()
{
	queue q(1);

	q.enqueue(5);

	return q.isFull();

}

/* Test ID : Empty queue check - EQC
Unit : queue::isEmpty()
Description : test to determine if queue::isEmpty() returns 1 if a queue object is empty
Test steps :
1. Construct an empty queue object
2. Invoke queue::isEmpty on empty queue object
3. Return result
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is empty
Expected result : queue is empty; 1 is returned
Actual result : queue is empty; 1 is returned
Status : passed
*/
bool isEmptyTest()
{
	queue q(0);

	return q.isEmpty();

}

/* Test ID : peekTest()
Unit : queue::peek()
Description : test to determine if queue::peek() returns the first item in a queue
Test steps :
1. Create an empty queue
2. Populate that queue with multiple items
3. Invoke queue::peek() on that queue
4. Return results
Test data : Queue populated with 1, 2, 3 in that order
Precondition : Queue is populated
Postcondition : Queue is populated
Expected result : Queue returns a 1
Actual result : Queue returns a 3
Status : Failed
*/
int peekTest1()
{
	queue q(5);

	q.enqueue(1);
	q.enqueue(2);	
	q.enqueue(3);

	return q.peek();
}


/* Test ID : peekTest2()
Unit : queue::peek()
Description : test to determine if queue::peek() can tell the queue is empty
Test steps :
1. Create an empty queue
2. Invoke queue::peek() on that queue
3. Return results
Test data : queue is empty
Precondition : Queue is empty
Postcondition : error message is displayed
Expected result : Queue returns an error message
Actual result : error message doesnt display, false value returned
Status : Failed
*/
int peekTest2()
{
	queue q(5);
	return q.peek();
}


/* Test ID : sizeTest()
Unit : queue::size()
Description : A unit test to determine if queue::size() works properly
Test steps :
1. Create a queue of size 3
2. Return queue::size()
Test data : size = 3
Precondition : A queue is made
Postcondition : size() returns the correct number
Expected result : 3 is returned
Actual result : 1 is returned
Status : Failed
*/
int sizeTest()
{
	queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	return q.size();
}


/* Test ID : dequeueTest1()
Unit : queue::dequeue()
Description : Test to determine if dequeue works properly
Test steps :
1. Create a queue
2. Populate that queue
3. Invoke dequeue, return result
Test data : Queue is populated with 1, 2, 3 in that order, then dequeued once to rid the 1
Precondition : Queue is populated
Postcondition : Queue has been dequeued once
Expected result : a queue of 2, 3 is returned
Actual result : a queue of 1, 2 was returned
Status : Failed
*/
queue dequeueTest1()
{
	queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();

	return q;
}


/* Test ID : dequeueTest2()
Unit : queue::dequeue()
Description : Test to determine if dequeue works properly
Test steps :
1. Create a queue
2. Invoke dequeue, return result
Test data : queue is empty
Precondition : Queue is empty
Postcondition : an error message is displayed
Expected result : an error message is displayed
Actual result : No error message + false value "removed"
Status : Failed
*/
void dequeueTest2()
{
	queue q(5);
	q.dequeue();
}


/* Test ID : enqueueTest1()
Unit : queue::enqueue()
Description : testing to see if enqueue properly populates a queue
Test steps :
1. Create a queue
2. Populate that queue
3. Return the queue
Test data : a queue of 1, 2, 3
Precondition : queue is populated
Postcondition : correct queue is returned
Expected result : queue of 1, 2, 3 returned
Actual result : queue of 0, 1, 2 returned
Status : failed
*/
queue enqueueTest1()
{
	queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	return q;
}


/* Test ID :
Unit : euqueueTest2()
Description : testing to see if enqueue reacts properly attempting to enqueue a full queue
Test steps :
1. Create a queue of size two
2. Attempt to invoke enqueue three times
Test data : size = 2
Precondition : queue is empty
Postcondition : error message is displayed
Expected result : error message is displayed
Actual result : error message displayed twice
Status : Failed
*/
void enqueueTest2()
{
	queue q(2);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
}

