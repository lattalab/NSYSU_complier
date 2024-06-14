%{
// Definition
# include "y.tab.h"
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
unsigned line_num = 0; // line number
extern char flag;	// print token?
char noLineflag = 0;	// need to print line?
%}
%x NUM
LINE ^[^\n]*$
EOL \r\n|\n
/* ?i : case-insensitive */
RESERVE (?i:absolute|and|array|begin|break|case|const|continue|do|double|else|end|for|function|if|integer|mod|nil|not|object|of|or|program|read|readln|real|single|string|then|to|var|while|write|writeln)
SYM ";"|":"|"("|")"|":="|">"|"<"|"="|"=="|"<="|">="|"["|"]"|"+"|"-"|"*"|"/"|"."|","
COMMENT \(\*([^\*]|\*+[^\)\*])*\*+\)
ID [A-Z_a-z][0-9A-Z_a-z]{0,14}
Integer ([+-]?[0-9]+)|([+-]?[$][0-9a-fA-F]+)|([+-]?[&][0-7]+)
REAL [+-]?([0-9]+[Ff]?|([0-9]+"."[0-9]+[Ff]?))([Ee][+-]?[0-9]+)?
STR '([^[:^print:]']|'')*'
SPACE [ ]
/* blank line */
BL ^[[:space:]]*$
xid [A-Z_a-z][0-9A-Z_a-z]{15,}
xfloat [+-]?([+-]?[0-9]+"."|"."[0-9]+)[Ff]?([Ee][+-]?[+-]?[0-9]+)?
DEFAULT .
%%
	/* Rules */

	/* "<*>" denoted any stage, BEGIN(0) back to start stage */
<*>{LINE} {
	++line_num;
	if(noLineflag)
		noLineflag = 0;
	else
		printf("Line %u: ", line_num);
	flag = 1;
	REJECT; // consider other cases
}
<*>{RESERVE} {
	if(flag)
		ECHO;
	int i=0;
	// change to lower case to find which case
	for(i=0;i<strlen(yytext);i++)
		yytext[i]=tolower(yytext[i]);
	noLineflag = 0;
	BEGIN(0);

	if(strcmp(yytext,"absolute") == 0)
		return ABSOLUTE;
	else if(strcmp(yytext,"and") == 0)
		return AND;
	else if(strcmp(yytext,"array") == 0){
		yylval.str = strdup(yytext);
		return ARRAY;}
	else if(strcmp(yytext,"begin") == 0)
		return BEG;
	else if(strcmp(yytext,"break") == 0)
		return BREAK;
	else if(strcmp(yytext,"case") == 0)
		return CASE;
	else if(strcmp(yytext,"const") == 0)
		return CONST;
	else if(strcmp(yytext,"continue") == 0)
		return CONTINUE;
	else if(strcmp(yytext,"do") == 0)
		return DO;
	else if(strcmp(yytext,"double") == 0){
		yylval.str = strdup(yytext);
		return DOUBLE;}
	else if(strcmp(yytext,"else") == 0)
		return ELSE;
	else if(strcmp(yytext,"end") == 0)
		return END;
	else if(strcmp(yytext,"for") == 0)
		return FOR;
	else if(strcmp(yytext,"function") == 0)
		return FUNCTION;
	else if(strcmp(yytext,"if") == 0)
		return IF;
	else if(strcmp(yytext,"integer") == 0){
		yylval.str = strdup(yytext);
		return INTEGER;}
	else if(strcmp(yytext,"mod") == 0)
		return MOD;
	else if(strcmp(yytext,"nil") == 0)
		return NIL;
	else if(strcmp(yytext,"not") == 0)
		return NOT;
	else if(strcmp(yytext,"object") == 0)
		return OBJECT;
	else if(strcmp(yytext,"of") == 0)
		return OF;
	else if(strcmp(yytext,"or") == 0)
		return OR;
	else if(strcmp(yytext,"program") == 0)
		return PROGRAM;
	else if(strcmp(yytext,"read") == 0)
		return READ;
	else if(strcmp(yytext,"readln") == 0)
		return READLN;
	else if(strcmp(yytext,"real") == 0){
		yylval.str = strdup(yytext);
		return REAL;}
	else if(strcmp(yytext,"single") == 0)
		return SINGLE;
	else if(strcmp(yytext,"string") == 0){
		yylval.str = strdup(yytext);
		return STRING;}
	else if(strcmp(yytext,"then") == 0)
		return THEN;
	else if(strcmp(yytext,"to") == 0)
		return TO;
	else if(strcmp(yytext,"var") == 0)
		return VAR;
	else if(strcmp(yytext,"while") == 0)
		return WHILE;
	else if(strcmp(yytext,"write") == 0) {
		yylval.str = strdup(yytext);
		return WRITE;}
	else if(strcmp(yytext,"writeln") == 0) {
		yylval.str = strdup(yytext);
		return WRITELN;}
}
<*>{SYM} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(0);

	if(strcmp(yytext,"(") == 0)
		return LP;
	else if(strcmp(yytext,")") == 0)
		return RP;
	else if(strcmp(yytext,",") == 0)
		return ',';
	else if(strcmp(yytext,":") == 0)
		return ':';
	else if(strcmp(yytext,";") == 0)
		return ';';
	else if(strcmp(yytext,"=") == 0)
		return EQUAL;
	else if(strcmp(yytext,"[") == 0)
		return '[';
	else if(strcmp(yytext,"]") == 0)
		return ']';
	else if(strcmp(yytext,":=") == 0)
		return ASSIGN;
	else if(strcmp(yytext,"+") == 0)
		return '+';
	else if(strcmp(yytext,"-") == 0)	
		return '-';
	else if(strcmp(yytext,"*") == 0)
		return '*';
	else if(strcmp(yytext,"/") == 0)
		return '/';
	else if(strcmp(yytext,".") == 0)
		return '.';
	else if(strcmp(yytext,"<") == 0)
		return LT;
	else if(strcmp(yytext,">") == 0)
		return GT;
	else if(strcmp(yytext,">=") == 0)
		return GE;
	else if(strcmp(yytext,"<=") == 0)
		return LE;
	else if(strcmp(yytext,"<>") == 0)
		return NE;
}
<*>{ID} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(NUM);
	yylval.str = strdup(yytext);
	return ID;
}
<INITIAL>{Integer} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(NUM);
	return (INT);
}
<INITIAL>{REAL} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(NUM);
	return (REAL_NUM);
}
<*>{STR} {
	noLineflag = 0;
	
	int temp =0;
	char buf[60];
	for(int i=0; i<yyleng; i++) {
		// check if there is context before or after double ''
		if(yytext[i]==39 && yytext[i+1]==39 && ((i>1 && yytext[i]) || yytext[i+2])){
			buf[temp++] = yytext[i++];
		}
		else{
			buf[temp++] = yytext[i];
		}
	}
	buf[temp] = '\0';
	BEGIN(NUM);
	yylval.str = strdup(buf);
	printf("%s", yylval.str);
	return STR;
}
<*>{COMMENT} {
	// adapt the line number when comment at first line
	if (line_num ==0)	line_num += 1;
	char *head = yytext - 1, *tail = yytext;
	while(*++tail)
		if(*tail == '\n') {
			++line_num;
			head = tail;
		}
	noLineflag = 1;
	BEGIN(0);
}
<*>{BL} {
	if(flag)
		printf("\rLine %u: ", line_num + 1);
	noLineflag = 1;
	BEGIN(0);
}
<*>{EOL} {
	if(flag)
		if(noLineflag)
			printf("\rLine %u: ", line_num + 1);
		else
			ECHO;
	BEGIN(0);
}
<*>{SPACE} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(0);
}
<*>{xid} {
	BEGIN(0);
	noLineflag = 0;
	yylval.str = strdup(yytext);
	return XID;
}
<*>{xfloat} {
	BEGIN(0);
	noLineflag = 0;
	yylval.str = strdup(yytext);
	return XREAL;
}
<*>{DEFAULT} {
	if(flag)
		ECHO;
	noLineflag = 0;
	BEGIN(0);
}
%%

int yywrap(void){
	return 1;
}
