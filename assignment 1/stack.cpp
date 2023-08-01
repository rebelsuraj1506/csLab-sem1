#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100 // maximum size for expression
struct Node{
    int data;
    struct Node *next;
};
struct Node* top=NULL;//initializing top value as NULL
//For Push operation taking num as input and pushing every element which is entered.
void push(int num)
{
    struct Node* newNode= new Node;
    newNode->data = num;
    newNode->next=top;
    top=newNode;
}
//Popping the top element
int pop()
{
    int ret = top->data;
    Node* to_delete = top;
    if(top->next)
    {
    top=top->next;
    free(to_delete);
    }
    else{
        free(to_delete);
    }
    return ret;
}
int tp()
{
    if(top)
    return top->data;
}
//displaying the stack elements after every successful operation.
void display()
{
    struct Node*  ptr;
    if(top==NULL)
    {
        cout<<"Stack is Empty.";
    }
    else{
        ptr=top;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    cout<<endl;
}
/*Evaluating the postfix expression using the exp as expression
and using the push and pop function to evaluate the postfix expression
and returning the output.*/
int evaluatePostfix(char* exp)
{
    int i;
    for (i = 0; exp[i]; ++i) {
        if (exp[i] == ' ')
            continue;
        else if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            push(num);
        }
        else {
            int val1 = tp();
            pop();
            int val2 = tp();
            pop();
            switch (exp[i]) {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case '%':
                push(val2 % val1);
                break;
            }
        }
    }
    return tp();
}
/*Main Function in which we take input and take each character
and call the evaluatePostfix() function to evaluate the
expression and getting the output.*/
int main()
{
    char exp[MAX_SIZE];
    cin.getline(exp,MAX_SIZE-1);
    cout<<evaluatePostfix(exp);
}