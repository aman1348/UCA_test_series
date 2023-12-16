// leetcode problem no: 20
// problem name: Valid Parentheses
// problem link: https://leetcode.com/problems/valid-parentheses/description/

// solution :

typedef struct {
    char val;
    struct node* next;
}
node;

void stack_push(node** top, char val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->next = *top;
    *top = newNode;
}

int stack_isEmpty(node* top) {
    return top==NULL;
}

char stack_pop(node** top) {
    if(*top==NULL) return '\0';

    node* popNode = *top;
    *top = (*top)->next;
    char val = popNode->val;
    free(popNode);
    return val;
}
void freeStackMemory(node** stack) {
    while(stack_pop(stack)!='\0');
}

char getOppositeBracket(char ch) {
    if(ch=='(') return ')';

    else if(ch=='{') return '}';

    else if(ch=='[') return ']';

    else return '1';
}

bool isValid(char* s) {
    node* stack = NULL;
    int i = 0;
    while(s[i]!='\0') {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            stack_push(&stack, s[i]);
        }
        else {
            char ch = stack_pop(&stack);
            // if(ch=='\0') return false;
            if(getOppositeBracket(ch)!=s[i]) return false;
        }

        i++;
    }
    bool ans = stack_isEmpty(stack);    

    freeStackMemory(&stack);
    return ans;
}