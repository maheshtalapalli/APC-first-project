#include"apc.h"
#include <unistd.h>

/**
 * steps followed
 * 1. compare two list 
 *	1.1 op1 is greater than or op2 
 *		subtract op1 by op2 until op1 is less than op2
 *		increement the count 
 *	1.2 op2 is greater than op1 print 0 
 **/
Status division(OP_var op1, OP_var op2)
{

    OP_var res , div;
    init_operator(&res);
    init_operator(&div);
    int quotient = 0;

    /*considering the sign*/
    res.o_sign = op1.o_sign * op2.o_sign;

    /*comparing the operators*/
    Cmpr large_op = compare_operator( op1.head ,op2.head);

    /*check if the denominator is zero*/
    if((op2.head)->data == 0)
    {
	printf("\nERROR : denominator in the division cannot be 0\n");
	return e_failure;
    }

    while(large_op != OP2_GREATER)
    { 
	quotient++;
	/*subtract op1 by op2 and store it in div*/
	if(subtract_list(op1, op2 ,0,&div)==e_failure)
	{
	    printf("\nERROR : failed to perform subtraction\n");
	    return e_failure;
	}

	/*compare div and op2*/
	large_op = compare_operator( div.head ,op2.head);

	if(large_op == OP2_GREATER) break;

	//freeList( &op1);

	/*copy div to op1 for next operation*/
	op1 = div;

	/*reset the values of div*/
	init_operator(&div);
    }

    /*display the result*/
    printf("\nResult List : %d\n",quotient * res.o_sign);

    return e_success;

}
