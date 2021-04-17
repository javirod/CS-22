#ifndef queueADT_H
#define queueADT_H

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0; //Function to return the first element of the queue.
	virtual Type back() const = 0; //Function to return the last element of the queue.
	virtual void addQueue(const Type& queueElement) = 0; //Function to add queueElement to the queue.
	virtual void deleteQueue() = 0; //Function to remove the first element of the queue.
};

#endif