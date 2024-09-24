Program:
%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}
/* Rules Section*/
%%
 /* Rule for counting number of tokens*/
"while"|"if"|"else" {i++;}
"int"|"float" {i++;}
[a-zA-Z_][a-zA-Z0-9_]* {i++;}
"<="|"=="|"="|"++"|"-"|"*"|"+"|"<"|">" {i++;}
[(){}|, ;]    {i++;}
[0-9]*"."[0-9]+ {i++;}
[0-9]+ {i++;}
"\n" {printf("no of tokens : %d\n", i); i = 0;}
%%
int yywrap(void){}
int main()
{
	// The function that starts the analysis
	yylex();
}
