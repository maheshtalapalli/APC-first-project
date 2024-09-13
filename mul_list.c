#include"apc.h"

/**
 * steps followed
 * 1. tail node of op2 is multiplied with all the nodes of op1 from tail node to head node 
 * 2. op2 node is traversed to previous untill op2 prev reaches null
 * 3. the multiplied result is sent to the addition function
 **/

/*function definiton of the multiplication function*/
Status multiplication(OP_var op1, OP_var op2)
{

    OP_var res , r1 , r2;
    init_operator(&res);
    init_operator(&r1);
    init_operator(&r2);

    int data=0,carry=0,num1,num2,count=1;

    /*to traverse the op2 to multiply with all nodes in op1*/
    while(op2.tail  || carry)
    {
	num2 = (op2.tail) ? (op2.tail)->data:0;
	Dlist * temp_tail = op1.tail;

	while(temp_tail || carry)
	{
	    data = 0;
	    num1 = (temp_tail) ? temp_tail->data:0;

	    data = num1 * num2 + carry;
	    carry = data/DIGIT;

	    /*inserting the result into a list*/
	    if(insert_at_first(&r1, data%DIGIT)==e_failure)
	    {
		printf("\nERROR : failed to insert when doing multiplication\n");
		return e_failure;
	    }

	    temp_tail = (temp_tail) ? temp_tail->prev : NULL;
	}

	op2.tail = (op2.tail) ? (op2.tail)->prev : NULL;

	/*adding the result*/
	add_list(r1,r2,&res);

	/*to store the result from addition in r2 and reset r1 and res*/
	if(op2.tail!=NULL)
	{
	    freeList(&r2);
	    r2 = res;

	    init_operator(&res);
	    init_operator(&r1);

	    /*insert extra zeros at the end of r1 for next iteration*/
	    int i=0;
	    while(i++<count)
		insert_at_first(&r1, 0);
	    count++;
	}
    }

    /*display the result with the sign*/
    res.o_sign = op1.o_sign * op2.o_sign;
    printf("\nResult is : ");
    display (res);

    return e_success;
}
