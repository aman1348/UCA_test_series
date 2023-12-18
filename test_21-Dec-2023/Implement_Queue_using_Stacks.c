// leetcode problem no: 232
// problem name:  Implement Queue using Stacks
// problem link: https://leetcode.com/problems/implement-queue-using-stacks/description/

// solution :

typedef struct
{
    int stack1[100];
    int top1;
    int stack2[100];
    int top2;

} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->top1 = 0;
    q->top2 = 0;

    return q;
}

void myQueuePush(MyQueue *obj, int x)
{
    (obj->stack1)[(obj->top1)++] = x;
}

int myQueuePop(MyQueue *obj)
{
    if ((obj->top2) == 0)
    {
        for (int i = obj->top1 - 1; i >= 0; i--)
        {
            (obj->stack2)[(obj->top2)++] = (obj->stack1)[i];
            (obj->top1)--;
        }
    }
    return (obj->stack2)[--(obj->top2)];
}

int myQueuePeek(MyQueue *obj)
{
    if ((obj->top2) == 0)
    {
        for (int i = obj->top1 - 1; i >= 0; i--)
        {
            (obj->stack2)[(obj->top2)++] = (obj->stack1)[i];
            (obj->top1)--;
        }
    }
    return (obj->stack2)[(obj->top2) - 1];
}

bool myQueueEmpty(MyQueue *obj)
{
    return (obj->top1) == 0 && (obj->top2) == 0;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/