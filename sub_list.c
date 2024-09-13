#include"apc.h"

/**
 * steps followed
 * 1. check if number of nodes is more or less or equal in op1 and op2
 * 2. if op1 has more than op2 do normal subtraction 
 * 3. if op1 has same as op2 check first node of op1 is greater than first node of op2 
 *	3.1 if op1 is greater do normal subtraction
 *	3.2 if op1 and op2 is same traverse next and do step 3 until node reach null
 * 	    if until node read null value is same store 0 in result
 *	3.3 if op1 is small than op2 then do the normal subtraction and add - in result first node
 * 4. if op1 have less node than op2 then do normal subtraction and store - in the result
 **/

/*function definition for subtraction*/
Status subtraction ( OP_var op1, OP_var op2)
{
    OP_var res;
    init_operator(&res);

    Cmpr large_op = compare_operator( op1.head ,op2.head);

    /*when op1 is greater or equal to op2, flag sent as 0*/
    if(large_op == OP1_GREATER || large_op == EQUAL )
    {
	if(subtract_list(op1, op2 ,0, &res)==e_failure)
	{
	    printf("\nERROR : failed to perform subtraction\n");
	    return e_failure;
	}
	if(op1.sign_flag)
	    res.o_sign = op1.o_sign;
    }
    else if(large_op == OP2_GREATER ) // when op2 > op1
    {
	if(subtract_list(op2, op1 ,1 , &res)==e_failure)
	{
	    printf("\nERROR : failed to perform subtraction\n");
	    return e_failure;
	}

	if(op2.sign_flag)
	    res.o_sign = op2.o_sign;
    }

    /*display the result*/
    printf("\nResult List : ");
    display(res);

    return e_success;
}

/*fucntion to subtract the data in the list */
Status subtract_list( OP_var op1, OP_var op2, int flag, OP_var * res)
{
    int  borrow = 0 , data = 0, num1 , num2 ; 

    while(op1.tail || op2.tail)
    {
	num1 = (op1.tail) ? (op1.tail)->data : 0;
	num2 = (op2.tail) ? (op2.tail)->data : 0;

	/*check if there is borrow*/
	if(borrow)
	{
	    num1 -= borrow;
	    (op1.tail)->data = num1;
	    borrow=0;
	}

	/*getting the result and storing it in a result list*/
	if(num1 >= num2)
	{
	    data = num1 - num2;
	    // printf("%d \n", data);
	}
	else if (num1 < num2)
	{
	    data = (num1 + DIGIT) - num2;
	    borrow = 1;
	}

	/*store the result data*/
	if(insert_at_first(res, data )==e_failure)
	{
	    printf("\nERROR : when perfoming insert in subtraction\n");
	    return e_failure;
	}

	op1.tail = (op1.tail) ? (op1.tail)->prev : NULL;
	op2.tail = (op2.tail) ? (op2.tail)->prev : NULL;
    }

    /*remove leading zeros*/
    while( (res->head != res->tail) && ((res->head)->data==0))
    {
	res->head= (res->head)->next;
    }

    /*if flag present to add - sign at the begining*/
    if(flag)
    {
	res->o_sign = -1;
    }

    return e_success;

}


