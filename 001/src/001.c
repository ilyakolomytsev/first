/*
 ============================================================================
 Name        : 001.c
 Author      : ilya
 Version     :
 Copyright   : mya
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float a, b, res ;
    char c, r;
    r='y';
    while (r == 'y') //
    {
        printf("Write first number: ");
        scanf(" %f", &a);
        printf("Write operation (+-/*^!): ");
        scanf(" %c", &c);
        if (c == '!') {
             if (a>0) {
                res=1;
                for (int i=1; i<a+1; i++) { //n! = 1*2*3...*n
                    res=res*i;
                }
                printf ("Result %2f (operation %c)", res, c);
            }
        }
        else {
        printf ("Write second number: ");
        scanf(" %f", &b);
        switch (c) {
        case '+':
            printf("Result %f (operation %c)", a + b, c);
            break;
        case '-':
            printf("Result %f (operation %c)", a - b, c);
            break;
        case '/':
            printf("Result %f (operation %c)", a / b, c);
            break;
        case '*':
            printf("Result %f (operation %c)", a * b, c);
            break;
        case '^':                                         // operation a^b
        {
                res = 1;
                for (int i = 0; i<b; i++) {
                    res = res * a;
                }
                printf("Result %f ^ %f = %f", a, b, res);
             break;
        }
        }
        }
            printf("Continue? (y/n)");
            scanf(" %c", &r);

    }

        return 0;
}

