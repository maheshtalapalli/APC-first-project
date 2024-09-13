#include"apc.h"
/*
Name: Talapalli Mahesh
Date: 24-07-2024
Description: Arbitrary Precision Calculator
 */

int main(int argc , char * argv[]) 
{
    /*check if CLA is passed right*/
    if(argc < 3)
    {
	printf("ERROR : Pass the CLA as operand operator operand\n");
	return e_failure;	
    }
    /*check for the operator*/
    if(strlen(argv[2]) > 1)
    {
	printf("ERROR : Pass the Operator either + - / x\n");
	return e_failure;	
    }

    OP_var op1,op2;
    init_operator(&op1);
    init_operator(&op2);


    /*create the operand 1 list and operand 2 list*/
    if(create_list(&op1,argv[1])==e_failure)
    {
	printf("ERROR : Creating operator 1 list failed\n");
	return e_failure;	
    }

    if(create_list(&op2,argv[3])==e_failure)
    {
	printf("ERROR : Creating operator 2 list failed\n");
	return e_failure;	
    }

    /*display the created list
    printf("\nOperand 1 is : ");
    display(op1);
    printf("\nOparand 2 is : ");
    display(op2);
*/
    switch (argv[2][0])
    {
	case '+' :
	    {
		/*addition operation*/
		Status add_status;

		if(op1.o_sign * op2.o_sign == 1) 
		    add_status = addition(op1,op2);
		else 
		    add_status = subtraction(op1,op2); 

		if(add_status == e_failure)
		{
		    printf("\nERROR : failed to do addition\n");
		    return e_failure;
		}
		break;
	    }
	case '-' :
	    /*substraction operation*/
	    {
		Status sub_status;

		if(op1.o_sign * op2.o_sign == -1) 
		    sub_status = addition(op1,op2);
		else 
		    sub_status = subtraction(op1,op2); 

		if(sub_status == e_failure)
		{
		    printf("\nERROR : failed to do subtraction\n");
		    return e_failure;
		}
		break;
	    }
	case 'x' :
	    /*multiplication operation*/
	    if(multiplication(op1,op2)==e_failure)
	    {
		printf("\nERROR : failed to do multiplication\n");
		return e_failure;
	    }
	    break;
	case '/' :
	    /*division operation*/
	    if(division(op1,op2)==e_failure)
	    {
		printf("\nERROR : failed to do division\n");
		return e_failure;
	    }
	    break; 
	default :
	    printf("ERROR : Pass the Operator either + - / x\n");
    }

    return 0;
}

