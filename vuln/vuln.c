#include<stdio.h>
#include <unistd.h>
void vuln(){
    int a[10];
    char s[10];
    printf("Enter your name: ");
    gets(s);
    printf("Have a nice day, %s\n!!", s);
}
int win(){
    execve("/bin/sh", NULL, NULL);
    return 0;
}
int main(){
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);
    vuln();
    return 0;
}

// gcc -fno-stack-protector -z execstack -no-pie -o vuln vuln.c
