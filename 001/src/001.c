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
    FILE *inFile, *outFile;
    float a, b, *k, *l, res, *result;
    int size;
    char c, r, ch;
    char inname[55], outname[55];
    r='y';
    while (r == 'y') {
        inFile = NULL;
           while(inFile == NULL){
           printf("name of the input file(less than 55 characters): ");
           scanf("%s", inname);
           inFile = fopen(inname, "r");
           if (inFile == NULL){
               printf("This file does not exist.\n");
           } else {
               printf("name of the output file(less than 55 characters): ");
               scanf("%s", outname);
               outFile = fopen(outname, "w");
           }
           }
           while(feof(inFile) == 0){               //work for end of file
           fscanf(inFile, " %c", &ch);
           fscanf(inFile, " %c", &c);
        switch (c) {
        case 's':
        fscanf(inFile, "%f", &a);
        if (ch == '!') {
             if (a>0) {
                res=1;
                for (int i=1; i<a+1; i++) { //n! = 1*2*3...*n
                    res=res*i;
                }
            }
        }
        else {
        fscanf(inFile, "%f", &b);
        switch (ch) {
        case '+':
            res=a+b;
            break;
        case '-':
            res=a-b;
            break;
        case '/':
            res=a/b;
            break;
        case '*':
            res=a*b;
            break;
        case '^':                                         // operation a^b
                res = 1;
                for (int i = 0; i<b; i++) {
                    res = res * a;
                }
             break;}}
        fprintf(outFile, "%f %c ", a, ch);
        fprintf(outFile, "%f = ", b);
        fprintf(outFile, "%f\n", res);
        if(feof(inFile) != 0){
                printf("For restart enter y, for exit enter something different: ");
                scanf(" %c", &r);
                printf("\n");
            }
        break;
        case 'v':
            fscanf(inFile, "%i", &size);
                   k = malloc(size*sizeof(int));
                   l = malloc(size*sizeof(int));
                   fprintf(outFile, "(");
                   for (int i = 0; i<size; i++){                   // first vector
                       fscanf(inFile, " %f", &k[i]);
                           fprintf(outFile, "%f ", k[i]);
                   }
                   fprintf(outFile, ") %c ",ch);
                   if (ch != 's'){                                 //to not scan second vector for scaling
                       fprintf(outFile, "(");
                       for (int i = 0; i<size; i++){               // second vector
                           fscanf(inFile, " %f", &l[i]);
                               fprintf(outFile, "%f ", l[i]);
                       }
                       fprintf(outFile, ") = (");
                       if (ch == '+'){
                           for (int i = 0; i<size; i++){
                                   fprintf(outFile, "%f ", k[i] + l[i]);
                           }
                           fprintf(outFile, ")\n");
                       } else if (ch == '-'){
                           for (int i = 0; i<size; i++){
                                   fprintf(outFile, "%f ", k[i] - l[i]);
                           }
                           fprintf(outFile, ")\n");
                       }
                   } else if (ch == 's'){
                       fscanf(inFile, " %f", &a);              //scalar
                       fprintf(outFile, "%f = (", a);
                       for (int i = 0; i<size; i++){
                               fprintf(outFile, "%f ", k[i] * a);
                       }
                       fprintf(outFile, ")\n");
                   } else fprintf(outFile, "Wrong operation!");
                   free(k);                           //freeing up memory
                   free(l);
                   if(feof(inFile) != 0){
                       printf("For restart enter y, for exit enter something different: ");
                       scanf(" %c", &r);
                       printf("\n");
                   }
            break;
        }
           }
        fclose(inFile);
        fclose(outFile);
            return 0;
    }
}
