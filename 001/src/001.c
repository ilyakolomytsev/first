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
    float a, b, *k, *l, res, *result;
    int size;
    char c, r;
    r='y';
    while (r == 'y') {
        printf("Work with vectors or numbers? (v/n)");
        scanf(" %c", &c);
        switch (c) {
        case 'n':
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
                res = 1;
                for (int i = 0; i<b; i++) {
                    res = res * a;
                }
                printf("Result %f ^ %f = %f", a, b, res);
             break;}}
        break;
        case 'v':
            printf("Write the size of the vectors: ");
            scanf (" %i", &size);
            printf("Write the operation: ");
            scanf (" %c", &c);
            k=malloc(size*sizeof(int));
            l=malloc(size*sizeof(int));
            result=malloc(size*sizeof(int));
            if (c == '+') {
                printf("Write first vector:");
                for (int i=0;i<size;i++) scanf ("%f", &k[i]);
                printf("Write second vector:");
                for (int i=0;i<size;i++) scanf ("%f", &l[i]);
                printf ("Result summ vectors: ");
                for (int i=0;i<size;i++) printf("%f", k[i]+l[i]);
                printf ("\n");  }
            else if ( c == '-' ) {
                 for (int i=0;i<size;i++) scanf ("%f", &k[i]);
                 printf("Write second vector:");
                 for (int i=0;i<size;i++) scanf ("%f", &l[i]);
                 printf ("Result diff vectors: ");
                 for (int i=0;i<size;i++) printf("%f", k[i]-l[i]);
                 printf ("\n");}
            break; }
            free(k);
            free(l);
            free(result);
            printf("Continue? (y/n)");
            scanf(" %c", &r); }
            return 0; }


