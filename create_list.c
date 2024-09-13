#include"apc.h"


/*function definition for creating the list*/
//Status create_list( Dlist ** head , Dlist ** tail , char * oprnd ) 
Status create_list( OP_var * op, char * oprnd ) 
    //r_val * create_list( char * oprnd ) 
{
    int len ,value;
    char buffer[100];

    /*check if sign is passed with the operator or not*/
   if(!isdigit(oprnd[0]))
    {
	if(oprnd[0] =='-')
	    op->o_sign = -1;
	else if(oprnd[0] == '+')
	    op->o_sign = 1;

	int i=0;
	/*left shift the string*/
	while(oprnd[i]!='\0')
	{
	    oprnd[i]=oprnd[i+1];
	    i++;
	}
	op->sign_flag = 1;
    }
    

    /*store 4 digit in 1 node*/ 
    while((len = strlen(oprnd))>=4)
    {
	strcpy(buffer,oprnd+len-4);
	value = atoi(buffer);

	if(insert_at_first( op , value) == e_failure)
	    return e_failure;

	oprnd[len-4]='\0';
    }

    /*copy the remaining char to node*/
    if(len>0)
    {
	strcpy(buffer,oprnd);
	value = atoi(buffer);

	if(insert_at_first( op , value) == e_failure)
	    return e_failure;
    }

    return e_success;
}
