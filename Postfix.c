// Infix to Postfix
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int eval(char, int, int);
int pop();
void push(int n);
int s[10],top = -1, i, op1, op2, res;
char a[50],ch,x;
void main(){
    printf("Enter the postfix expression: ");
    gets(a);
    for (i=0; a[i]!='\0'; i++){
        ch = a[i];
        if (ch>='0' && ch<='9'){
            push(ch-'0');
        }
        else{
            op2 = pop();
            op1 = pop();
            res = eval(ch, op1, op2);
        }
    x = pop();
    printf("Evaluated value: %d", res);
    }
}
void push(int n){
    s[++top] = n;
}

int pop(){
    int res;
    res = s[top--];
    return res;
}

int eval(char ch, int op1, int op2){
    switch (ch)
    {
    case '+':
        return (op1+op2);
    case '-':
        return (op1-op2);
    case '/':
        return (op1/op2);
    case '*':
        return (op1*op2);
    default:
        break;
    }
}