int math(const char exp[])
{
    int a=exp[0]-48;
    int b=exp[2]-48;
    switch(exp[1]){
        case '+': return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
    return 0;
}
