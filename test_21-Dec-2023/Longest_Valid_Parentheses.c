// leetcode problem no: 32
// problem name: Longest Valid Parentheses
// problem link: https://leetcode.com/problems/longest-valid-parentheses/description/

// solution:

typedef struct
{
    int val;
    struct node *next;
} node;

void stack_push(node **top, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = *top;
    *top = newNode;
}

int stack_isEmpty(node *top)
{
    return top == NULL;
}

int stack_pop(node **top)
{
    if (*top == NULL)
        return -1;

    node *popNode = *top;
    *top = (*top)->next;
    int val = popNode->val;
    free(popNode);
    return val;
}

void freeStackMemory(node **stack)
{
    while (stack_pop(stack) != -1)
        ;
}

int longestValidParentheses(char *s)
{
    node *stack = NULL;
    int n = 0;
    for (; s[n] != '\0'; n++);

    int *dp = (int *)calloc(n, sizeof(int));

    int maxlength = 0;

    for (int i = 0; i < n; i++)
    {
        int len = 0;
        if (s[i] == '(')
        {
            stack_push(&stack, i);
        }
        else
        {
            if (!stack_isEmpty(stack))
            {
                int index = stack_pop(&stack);
                len = i - index + 1;

                if (index > 0)
                {
                    len += dp[index - 1];
                }
            }
        }
        dp[i] = len;
        if (maxlength < len)
        {
            maxlength = len;
        }
    }

    freeStackMemory(&stack);
    free(dp);
    return maxlength;
}