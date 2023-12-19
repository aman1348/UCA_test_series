// leetcode problen no: 622
// problem name: Design Circular Queue
// problem link: https://leetcode.com/problems/design-circular-queue/description/

// solution:

typedef struct
{
    int *q;
    int size;
    int front;
    int rear;

} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->size = k;
    queue->q = (int *)malloc(sizeof(int) * k);
    queue->front = -1;
    queue->rear = 0;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{

    if (obj->front == obj->rear)
        return false;

    (obj->q)[obj->rear] = value;
    obj->rear = ((obj->rear) + 1) % (obj->size);
    if (obj->front == -1)
    {
        obj->front = 0;
    }

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (obj->front == -1)
        return false;

    (obj->front) = ((obj->front) + 1) % obj->size;
    if (obj->front == obj->rear)
    {
        obj->rear = 0;
        obj->front = -1;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (obj->front == -1)
        return -1;
    return (obj->q)[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (obj->front == -1)
        return -1;
    if (obj->rear == 0)
        return (obj->q)[(obj->size) - 1];
    return (obj->q)[(obj->rear) - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (obj->front == -1)
        return true;

    return false;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if (obj->front == obj->rear)
        return true;

    return false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->q);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/