// leetcode problem no: 316
// problem name: Remove Duplicate Letters
// problem link: https://leetcode.com/problems/remove-duplicate-letters/description/

// solution:

typedef struct
{
    char st[26];
    int top;
} stack;

void push(stack *s, char ch)
{
    (s->st)[(s->top)++] = ch;
}

char pop(stack *s)
{
    (s->top)--;
    return (s->st)[s->top];
}
char top(stack *s)
{
    if (s->top <= 0)
        return '\0';
    return (s->st)[(s->top) - 1];
}

char *removeDuplicateLetters(char *s)
{
    char *ch = (char *)malloc(sizeof(char) * 27);
    char freq[26];
    stack st;
    st.top = 0;
    bool included[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
        included[i] = false;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']--;
        if (st.top == 0)
        {
            push(&st, s[i]);
            included[s[i] - 'a'] = true;
            continue;
        }

        while (st.top > 0)
        {
            if (top(&st) > s[i] && freq[top(&st) - 'a'] > 0 && !included[s[i] - 'a'])
            {
                included[top(&st) - 'a'] = false;
                pop(&st);
            }
            else
            {
                break;
            }
        }

        if (!included[s[i] - 'a'])
        {
            push(&st, s[i]);
            included[s[i] - 'a'] = true;
        }
    }

    for (int i = st.top - 1; i >= 0; i--)
    {
        ch[i] = st.st[i];
    }
    
    ch[st.top] = '\0';
    return ch;
}