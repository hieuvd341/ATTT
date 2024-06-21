#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check_pass(char *password){
    int auth_flag = 0;
    char buff[8];
    strcpy(buff, password);
    if(strcmp(buff, "vdh") == 0){
        auth_flag = 1;
    }
    else if(strcmp(buff, "knc") == 0){
        auth_flag = 1;
    }
    else if(strcmp(buff, "ltva") == 0){
        auth_flag = 1;
    }
    return auth_flag;
}
int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <password>\n", argv[0]);
        exit(0);
    }
    if(check_pass(argv[1])){
        printf("Access granted\n");
    }
    else{
        printf("Access denied\n");
    }
    return 0;
}


// gcc -fno-stack-protector -z execstack -o example-1 example-1.c 
