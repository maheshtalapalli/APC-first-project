#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DIGIT 10000

/*creating enum*/
typedef enum status
{
    e_failure,
    e_success
} Status;
/*compare two oparand */
typedef enum compare
{
    OP1_GREATER,
    OP2_GREATER,
    EQUAL
}Cmpr;

/*creating structures*/
typedef struct node
{
    struct node * prev;
    unsigned int data;
    struct node * next;
} Dlist;

typedef struct list_status
{
    struct node * head;
    struct node * tail;
    int o_sign;
    int sign_flag;
} OP_var;

/*function prototype*/
void init_operator( OP_var *  );

Status create_list( OP_var *, char *  );

Status insert_at_first( OP_var *, int  );

void display ( OP_var );

Status addition ( OP_var , OP_var );

Status add_list ( OP_var , OP_var , OP_var *);

Status subtraction(OP_var  ,OP_var );

Status subtract_list( OP_var , OP_var , int , OP_var * );

Status multiplication(OP_var , OP_var );

Status division(OP_var  ,OP_var );

int node_count(Dlist * );

Cmpr compare_operator ( Dlist * , Dlist *);

void freeList ( OP_var * );
int new(int num);


#endif
