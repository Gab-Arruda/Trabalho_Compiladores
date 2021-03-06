/*Gabriel Arruda dos Santos 00290400*/
#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char *yytext;

#define HASH_SIZE 997

#define SYMBOL_VARIABLE 6
#define SYMBOL_LABEL 9

typedef struct hash_node
{
    int type;
    char *text;
    struct hash_node *next;      
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE* hashFind(char *text);
HASH_NODE* hashInsert(char *text, int type);
void hashPrint(void);
HASH_NODE* makeTemp(void);
HASH_NODE* makeLabel(void);

#endif