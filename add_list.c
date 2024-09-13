#include"apc.h"

/**
 * steps followed
 * 1. convert from string to integer
 * 2. add two node if carry store it in carry flg else carry is 0
 * 3. conevrt the ditgit into 4 char string and store it in the result node
 */

/*function definition of addition*/
Status addition ( OP_var op1 , OP_var  op2 )
{
    OP_var res;
    init_operator(&res);

    /*function call to add two list*/
    if(add_list ( op1, op2, &res ) == e_failure)
    {
	printf("\nERROR : Failed to add the list\n");
    }

    /*display the result list*/
    res.o_sign = op1.o_sign;
    printf("\nResult is : ");
    display(res);
}

/*function definition of add_list*/
Status add_list (OP_var op1 , OP_var  op2, OP_var * res )
{
    int carry=0,sum=0,num1,num2;

    /*traverse and add nodes*/
    while (op2.tail || op1.tail || carry )
    {
	/*add two int value of the string*/
	num1 = (op1.tail) ? (op1.tail)->data : 0 ;
	num2 = (op2.tail) ? (op2.tail)->data : 0 ;


	sum = carry + num1 + num2 ;
	carry = sum / DIGIT ;

	/*insert the data to the result list*/
	if(insert_at_first(res,sum % DIGIT)==e_failure)
	{
	    printf("ERROR : failed to insert the node to result list\n");
	    return e_failure;
	}

	/*travese to the previous node*/
	op2.tail = (op2.tail) ? (op2.tail)->prev : NULL;
	op1.tail = (op1.tail) ? (op1.tail)->prev : NULL;
    }

    return e_success;
}

