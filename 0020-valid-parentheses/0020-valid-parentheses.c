bool isValid(char* s) {
    int n = strlen(s);
    char* stack = malloc(n*sizeof(char));
    int top = -1;int i=0;

    while(i<n){
        char c= s[i];
        
        if( c == '(' || c == '{' || c == '[' ){
            stack[++top] = c;
        }
        else{
            char topmost = stack[top--];
            if(c == ']' && topmost != '[' ||
                c == '}' && topmost != '{' ||
                c == ')'&& topmost != '(' ){
                    return false;
            }
        }
        i++;
    }
    return (top==-1);
}