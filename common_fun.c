#include"apc.h"


/*function definition of insert at first*/
Status insert_at_first(OP_var * op, int data)
{
    // printf(" data %d \n ",data);
    /*create new node and check for the memeory allocation*/

    Dlist * new_node = (Dlist *) malloc(sizeof(Dlist));
    if(new_node == NULL)
    {
	printf("\nERROR : Memory allocation failed\n");
	return e_failure;
    }
    /*update the data to new node*/
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    /*list is empty*/
    if(op->head == NULL)
    {
	op->head = new_node;
	op->tail = new_node;
	return e_success;
    }

    /*insert at first when list is not empty*/
    new_node->next = op->head;
    (op->head)->prev = new_node;
    op->head = new_node;

    return e_success;

}

/*function definition of the display*/
void display(OP_var op)
{
    /*when list is empty*/
    if(op.head==NULL)
    {
	printf("\nERROR : List is empty\n");
	return ;
    }

    /*to remove the preceeding zero*/
    while(op.head && (op.head)->data==0)
	op.head = (op.head)->next;

    /*display the data when the list is not empty*/
    Dlist * temp = op.head;
    while(temp)
    {
	if( (temp != op.head) && (temp->data < 1000))
	    if(temp->data < 100)
		if(temp->data < 10)

		    printf("000%d",temp->data);
		else
		    printf("00%d",temp->data);
	    else
		printf("0%d",temp->data);
	else if(temp == op.head)
	    printf("%d",(temp->data)*(op.o_sign));
	else
	    printf("%d",temp->data);

	temp=temp->next;
    }
    /*display zero when the list is empty*/
    if(op.head==NULL)
	printf("0");
    printf("\n");
}

/*function to find the node count*/
int node_count(Dlist * head)
{
    int count = 0 ;
    /*traver the list*/
    while(head)
    {
	head=head->next;
	count++;
    }

    return count ;
}


/*function definition to compare the two list*/
Cmpr compare_operator ( Dlist * op1_head , Dlist * op2_head)
{
    /*check the node count of operator 1 and 2*/
    int op1_count = node_count(op1_head);
    int op2_count = node_count(op2_head);

    /*depending on the node count return*/
    if(op1_count > op2_count)
    {
	return OP1_GREATER;
    }
    else if (op1_count < op2_count)
    {
	return OP2_GREATER;
    }
    else
    {
	/*if node counts are same then compare the data and return the greatest value*/
	Dlist * temp_op1 = op1_head;
	Dlist * temp_op2 = op2_head;

	while(op1_head)
	{
	    if(op1_head->data < op2_head->data)
	    {
		return OP2_GREATER;
	    }
	    else if(op1_head->data > op2_head->data)
	    {
		return OP1_GREATER;
	    }

	    op1_head=op1_head->next;
	    op2_head=op2_head->next;
	}
    }

    return EQUAL;
}



void freeList ( OP_var * op)
{
    /*check if list is empty*/
    if(op->head==NULL)
    {
	//	printf("List empty\n");
	return ;
    }

    Dlist * temp = op->head;

    /*traverse the list and delete one by one node*/
    while(op->head!=NULL)
    {
	op->head=(op->head)->next;
	free(temp);
	temp=op->head;
    }
    op->tail=NULL;
    return ;
}

/*initialise the structure*/
void init_operator(OP_var * op)
{
    op->head = NULL;
    op->tail = NULL;
    op->o_sign = 1;
    op->sign_flag = 0;
}
