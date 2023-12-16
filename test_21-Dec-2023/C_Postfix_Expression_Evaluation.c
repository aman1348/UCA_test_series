// hackerrank problem no: 8
// problem name: C Postfix Expression Evaluation
// problem link: https://www.hackerrank.com/contests/17cs1102/challenges/8-c-postfix-expression-evaluation/problem

// solution:


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int data[100];
    int top;
}stack;

void push(stack *st, int ele) {
    st->data[(st->top)++] = ele;
}

int pop(stack* st) {
    if((st->top)==0) {
        return -1;
    }
    (st->top)--;

    return st->data[st->top];
}

int operation(char op, int num1, int num2) {
    int ans = 0;
    switch(op) {
        case '+': ans = num1 + num2;
            break;
        case '-': ans = num1 - num2;
            break;
        case '*': ans = num1 * num2;
            break;
        case '/': ans = num1 / num2;
            break;
    }
    return ans;
}

int main() {
    
    int n;
    scanf("%d", &n);
    stack st;
    st.top = 0;

    while(n-- > 0) {
        
        int num = 0;
        char str[10];
        scanf("%s", str);
        while(str[0]!='?') {
            
            if('0'<=str[0] && str[0]<='9') {
                num = 0;
                int j = 0;
                while(str[j]!='\0') {
                    num = 10*num + (str[j]-'0');
                    j++;
                }               
                    push(&st, num);
            }
            else {
                int num2 = pop(&st);
                int num1 = pop(&st);
                push(&st, operation(str[0], num1, num2));
            }
            scanf("%s", str);
        }
        
        printf("%d \n", pop(&st));
        
    }
    return 0;
}

