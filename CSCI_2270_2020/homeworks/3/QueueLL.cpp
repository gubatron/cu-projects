#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while (!isEmpty())
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    auto *nn = new Node();
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function,
    // handle the case when enqueuing in an empty queue

    if (isEmpty()) // if empty
    { 
        queueFront = nn; 
        queueEnd = nn;
        return;
    } // if not empty
    queueEnd->next = nn;
    queueEnd = nn;
    return;
}

//TODO
void QueueLL::dequeue()
{
    if (!isEmpty())
    {
        // TODO Complete this function, 
        // handle the case when your queue becomes
        // empty after dequeuing

        auto *to_delete = queueFront; // store front in to_delete
        queueFront = queueFront->next; // move actual front to node before it
        if (queueFront == nullptr) // if the front is empty, it means the end is empty
        {
            queueEnd = nullptr; // equate them both to NULL
        }
        delete(to_delete); // deleate head 
        return;
    }
    else
    {
        cout << "queue is empty. can not deque" << endl;
        return;
    }
}

int QueueLL::peek()
{
    if (!isEmpty())
        return queueFront->key;
    else
    {
        cout << " queue is empty. can not peek" << endl;
        return -1;
    }
    //return 0;
}
