#include<stdio.h>
#include<stdlib.h>

void func(){
    printf("Exiting\n");
}
int main(){
    atexit(func);
    exit(10);
}
