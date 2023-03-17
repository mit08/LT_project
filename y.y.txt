%{
/* Definition section */
#include<stdio.h>
#include<stdlib.h>
%}

%token dg k k1 op op1 eol

/* Rule Section */
%%
S: A  {printf("\nThis sentence is valid.\n"); return 0;};
 |B	{printf("\nThis sentence is valid.\n"); return 0;};
 |C	{printf("\nThis sentence is valid.\n"); return 0;};
;
A: k k1 op dg eol
;
B: k k1 dg eol
;
C: k k1 op1 eol
;
%%
void yyerror()
{
printf("Error: Invalid sentence");
exit(1);
}
//driver code
void main()
{
printf("Enter sentence: ");
yyparse();
}