#include <iostream>
#include <stdexcept>

using namespace std;

/*

Adds to end, pops first element i.e. from front.

*/

class Queue
{
private:
    int front;
    int end;
    int currSize;
    int capacity;
    int *que;

public:
    Queue(int capacity) : capacity(capacity), currSize(0), front(0), end(-1)
    {
        this->que = new int(this->capacity);
    }
    void enqueue1(int num)
    {
        if (this->currSize >= this->capacity)
        {
            throw std::runtime_error("Queue size full");
        }
        this->end++;
        this->que[this->end] = num;
        this->currSize++;
        return;
    }

    /* First round of deque implementation where we have only end and front defaults to zero.
    Everytime when an element is popped, all the other element are moved to left position and currSize is reduced by 1*/
    int deque1()
    {
        if (currSize == 0)
        {
            string errMsg = "Queue is empty";
            throw std::runtime_error(errMsg);
        }
        int poppedElement = this->que[0];

        // Expensive copy of order N
        for (int i = 1; i <= this->currSize; i++)
        {
            this->que[i - 1] = this->que[i];
        }
        this->end--;
        this->currSize--;

        return poppedElement;
    }

    void enqueue(int num)
    {
        if (this->currSize >= this->capacity)
        {
            throw std::runtime_error("Queue size full");
        }

        /* More intitutive way to set end
        if(this->end >= (this->capacity -1))
        {
            this->end = 0;
        }
        else
        {
            this->end++;
        }
        */

        // Better approach to adjust end;
        this->end++;
        this->end = this->end % this->capacity;

        this->que[this->end] = num;
        this->currSize++;
        return;
    }

    int deque()
    {
        if (currSize == 0)
        {
            string errMsg = "Queue is empty";
            throw std::runtime_error(errMsg);
        }
        int poppedElement = this->que[this->front];

        /* More intitutive approach to adjust front
        if(this->front >= (this->capacity -1))
        {
                this->front = 0;
        }
        else
        {
                this->front++;
        }
        */

        // Better approach to adjust front
        this->front++;
        this->front = this->front % this->capacity;

        this->currSize--;

        return poppedElement;
    }

    void display()
    {

        for (int i = 0; i < this->currSize; i++)
        {
            cout << this->que[i] << endl;
        }
    }
};

int main()
{

    int capacity = 5;
    Queue *q1 = new Queue(capacity);

    q1->enqueue(2);
    q1->enqueue(6);
    q1->enqueue(1);
    q1->enqueue(9);
    q1->enqueue(0);
    // q1->enqueue(5);

    q1->display();

    cout << "Deque all elements" << endl;

    for (int j = 0; j < capacity; j++)
    {
        cout << q1->deque() << endl;
    }

    cout << "Enque  elements" << endl;
    q1->enqueue(5);
    q1->display();

    return 0;
}
