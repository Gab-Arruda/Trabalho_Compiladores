#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_COPY 4
#define TAC_JFALSE 5
#define TAC_LABEL 6
#define TAC_MULT 7
#define TAC_DIV 8
#define TAC_LESS 9
#define TAC_GREATER 10
#define TAC_OR 11
#define TAC_AND 12
#define TAC_NOT 13
#define TAC_LE 14
#define TAC_GE 15
#define TAC_EQ 16
#define TAC_DIF 17
#define TAC_ASSIGN_ARRAY 18 


typedef struct tac_node {
    int type;
    HASH_NODE * res;
    HASH_NODE * op1;
    HASH_NODE * op2;
    struct tac_node* prev;
    struct tac_node* next;
} TAC;

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tacPrint(TAC* tac);
void tacPrintBackwards(TAC* tac);
TAC* tacJoin(TAC* l1, TAC* l2);

// CODE GENERATION

TAC* generateCode(AST *node);

#endif