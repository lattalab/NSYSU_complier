%{
#include <stdio.h>
#include <math.h>
unsigned int lineCount=1,charCount=1;
int op = 0, idx=0, idx2=0;
char buf[1024];
struct symtab{
	char *name;
};
struct symtab symtable[100];
struct errtab{
	char* name;
	char* info;
};
struct errtab Isymtable[100];

# define MIN(a,b) ((a) < (b) ? (a) : (b))
%}

space [ ]
eol \r\n|\n

reservedWord [Aa][Bb][Ss][Oo][Ll][Uu][Tt][Ee]|[Aa][Nn][Dd]|[Bb][Ee][Gg][Ii][Nn]|[Bb][Rr][Ee][Aa][Kk]|[Cc][Aa][Ss][Ee]|[Cc][Oo][Nn][Ss][Tt]|[Cc][Oo][Nn][Tt][Ii][Nn][Uu][Ee]|[Dd][Oo]|[Ee][Ll][Ss][Ee]|[Ee][Nn][Dd]|[Ff][Oo][Rr]|[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]|[Ii][Ff]|[Mm][Oo][Dd]|[Nn][Ii][Ll]|[Nn][Oo][Tt]|[Oo][Bb][Jj][Ee][Cc][Tt]|[Oo][Ff]|[Oo][Rr]|[Pp][Rr][Oo][Gg][Rr][Aa][Mm]|[Tt][Hh][Ee][Nn]|[Tt][Oo]|[Vv][Aa][Rr]|[Ww][Hh][Ii][Ll][Ee]|[Aa][Rr][Rr][Aa][Yy]|[Ii][Nn][Tt][Ee][Gg][Ee][Rr]|[Dd][Oo][Uu][Bb][Ll][Ee]|[Ww][Rr][Ii][Tt][Ee]|[Ww][Rr][Ii][Tt][Ee][Ll][Nn]|[Ss][Tt][Rr][Ii][Nn][Gg]|[Ff][Ll][Oo][Aa][Tt]|[Rr][Ee][Aa][Dd]
digit [0-9]

id [a-zA-Z_][a-zA-Z0-9_]{0,14}
symbol ";"|":"|"("|")"|":="|">"|"<"|"="|"=="|"<="|">="|"["|"]"|"+"|"-"|"*"|"/"|"."
integer [+-]?[0-9][0-9]*
fraction [0-9]+
float ({integer}[Ff]?|({integer}"."{fraction}[Ff]?))([Ee]{integer})?
hexvalue [+-]?[$][0-9a-fA-F]+
octal [+-]?[&][0-7]+
	/* contains many characters except for newline, two consective ' can be reduced to one ' */
	/* note that if a string contains a string, it will be error. */
string ([']([^'\n\r\n]|[']['][^'\n\r\n]*)*['])
	/* Inside a (* *) are all comments. */
	/* advance note: there are some other comment like: // {} */
comment (([(][*])|[{])([^*]|{eol}|([*]+([^*)]|{eol})))*(([*]+[)])|[}]) 

not_id [a-zA-Z_][a-zA-Z0-9_]{15,}|([0-9]|[#\^])+[a-zA-Z0-9_]*
xfloat ([+-]?({integer}"."|"."{fraction})[Ff]?([Ee][+-]?{integer})?)
	/* lack of ' at the begining or ending. */
	/* Cannot use " as quoting symbol to string. */
xstring ['][^';\n\r\n ]*[^;\n\r\n ]|[^';\n\r\n ]*[']|["][^';\n\r\n ]*[^;\n\r\n ]|[^';\n\r\n ]*["]|["]([^'\n\r\n]|["]["][^'\n\r\n]*)*["]
	/* contain the situataion with only one side "(* or *) with all consideration. "*/
xcomment  [(][*]([^* \n\r\n;]|[*]+[^*) \n\r\n;])*([*]+[^ \n\r\n);]|[^ \n\r\n;])|([^(* \n\r\n;]|([^(* \n\r\n;][*]+))*[*]+[)]
/*undefined_symbols*/
else .

%%
{space} {charCount++; op=0;}	/* just ignore space character */
{eol} {lineCount++; charCount=1; op=0;}
{reservedWord} {
    printf("Line: %d,1st char: %d, \"%s\" is an \"reserved word\".\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;
}
{id} {
    printf("Line: %d,1st char: %d, \"%s\" is an \"ID\".\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;

	/* Store in symbol table */
	int store = 1;
	for (int i=0;i<idx;i++)
	{
		int res = strcmp(symtable[i].name, yytext);
		if (res == 0) // repetitive ID
			store = 0;
	}

	if (store)
	{
		symtable[idx].name = (char *)malloc(strlen(yytext) + 1);
    	strcpy(symtable[idx].name, yytext);
		idx +=1;
	}
}
{symbol} {
    printf("Line: %d,1st char: %d, \"%s\" is a \"symbol\".\n", lineCount, charCount, yytext);
    charCount+=yyleng;
	op=0;
}
{integer} {
	/* see if the + or - is in the middle of two number to check operator or sign? */
    if (!op)
	{
		printf("Line: %d,1st char: %d, \"%s\" is a \"integer\".\n", lineCount, charCount, yytext); 
    	
	}
	else
	{
		if(yytext[0]=='+')
			printf("Line: %d, 1st char: %d, \"+\" is an \"symbol\".\n", lineCount, charCount);
		if(yytext[0]=='-')
			printf("Line: %d, 1st char: %d, \"-\" is an \"symbol\".\n", lineCount, charCount);
		yytext=yytext+1;
		printf("Line: %d, 1st char: %d, \"%s\" is a \"integer\".\n", lineCount, charCount+1, yytext);
	}
    charCount+=yyleng;
	op=1;
}
{float} {
	/* see if the + or - is in the middle of two number to check operator or sign? */
	if (!op)
	{
		printf("Line: %d,1st char: %d, \"%s\" is a \"float\".\n", lineCount, charCount, yytext); 
    	
	}
	else
	{
		if(yytext[0]=='+')
			printf("Line: %d, 1st char: %d, \"+\" is an \"symbol\".\n", lineCount, charCount);
		if(yytext[0]=='-')
			printf("Line: %d, 1st char: %d, \"-\" is an \"symbol\".\n", lineCount, charCount);
		yytext=yytext+1;
		printf("Line: %d, 1st char: %d, \"%s\" is a \"float\".\n", lineCount, charCount+1, yytext);
	}
    charCount+=yyleng;
	op=1;
}
{hexvalue} {
    printf("Line: %d,1st char: %d, \"%s\" is a \"hexvalue(Data Type: integer)\".\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;
}
{octal} {
    printf("Line: %d,1st char: %d, \"%s\" is a \"octal(Data Type: integer)\".\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;
}
{string} {
	/* string size is limited to 30 */
    if(yyleng<=32)
	{
		int temp=0,num=0;
		memset(buf,0,sizeof(buf));
		buf[temp++]=yytext[0];
		for(int i=1;i<yyleng-1;i++)
		{
			if(yytext[i]==39 && yytext[i+1]==39 && i!=yyleng-2) // change '' to '
			{
				num+=2;
				// Check if other character before double ''
				// if yes, then change to single '
				// otherwise, stay original
				if (i-1 >=1 && yytext[i-1])
					buf[temp++]=yytext[i++];
				else
				{
					buf[temp++] = yytext[i];
					buf[temp++] = yytext[i++];
				}
			}
			else if(yytext[i]==39)
			{
				num++;
				buf[temp++]=yytext[i];
			}
			else 
				buf[temp++]=yytext[i];
		}
		buf[temp]=yytext[yyleng-1];
		if(num%2==0)    // ' must be paired
			printf("Line: %d,1st char: %d, \"%s\" is a \"string\".\n", lineCount, charCount, buf);
		else 
			printf("Line: %d,1st char: %d, \"%s\" is an invalid \"string\".\n", lineCount, charCount, yytext);
	}
	else 
		printf("\033[0;33;1mLine: %d,1st char: %d, \"%s\" is an invalid \"string\".\033[0m\n", lineCount, charCount, yytext);
	
    charCount+=yyleng;
	op=0;
}
{comment} {
	printf("Line: %d,1st char: %d, \"%s\" is a \"comment\".\n", lineCount, charCount, yytext);
	for(int i=0;i<yyleng;i++)
	{
		if(yytext[i]==10) // new line character
		{
			lineCount++;
			charCount=1;
		}
		else 
			charCount++;
	}
	op=0;
}
{not_id} {
    printf("\033[0;33;1mLine: %d,1st char: %d, \"%s\" is an invalid \"ID\".\033[0m\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;

	/* store to Error list */
	int store = 1;
	for (int i=0;i<idx2;i++)
	{
		int res = strcmp(Isymtable[i].name, yytext);
		if (res == 0) // repetitive ID
			store = 0;
	}

	if (store)
	{
		if ((yytext[0] >= 'A' && yytext[0] <= 'Z') || (yytext[0] >= 'a' && yytext[0] <= 'z') || (yytext[0] == '_'))
		{
			Isymtable[idx2].info = (char *)malloc(strlen("Cannot be longer than \"15\" characters") + 1);
			strcpy(Isymtable[idx2].info, "Cannot be longer than \"15\" characters");
		}
		else
		{
			Isymtable[idx2].info = (char *)malloc(strlen("Didn't start with \"alphabetic or underline\".") + 1);
			strcpy(Isymtable[idx2].info, "Didn't start with \"alphabetic or underline\".");
		}
		Isymtable[idx2].name = (char *)malloc(strlen(yytext) + 1);
    	strcpy(Isymtable[idx2].name, yytext);
		idx2 +=1;
	}
}
{xfloat} {
    printf("\033[0;33;1mLine: %d,1st char: %d, \"%s\" is an invalid \"float\".\033[0m\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;
}
{xstring} {
    printf("\033[0;33;1mLine: %d,1st char: %d, \"%s\" is an invalid \"string\".\033[0m\n", lineCount, charCount, yytext); 
    charCount+=yyleng;
	op=0;
}
{xcomment} {
	printf("\033[0;33;1mLine: %d,1st char: %d, \"%s\" is an invalid \"comment\".\033[0m\n", lineCount, charCount, yytext);
	for (int i=0;i<yyleng;i++)
	{
		if(yytext[i]==10)   // new line character
		{
			lineCount++;
			charCount=1;
		}
		else 
			charCount++;
	}
	op=0;
}
{else} {
	printf("Line: %d,1st char: %d, \"%s\" is a \"unknown\".\n", lineCount, charCount, yytext);
    charCount+=yyleng;
	op=0;
}

%%

int main()
{
	yylex();
	printf("The symbol table contains:\n");
	for (int i=0;i<MIN(idx, 100);i++)
	{
		printf("%s\n", symtable[i].name);
		free(symtable[i].name);
	}
	if (idx2 != 0) // only print info when Invalid_ID occured
	{
		printf("The symbol table for \"Invalid_ID\"(List of invalid identifiers) contains:\n");
		for (int i=0;i<MIN(idx2, 100);i++)
		{
			printf("%s\t%s\n", Isymtable[i].name,Isymtable[i].info);
			free(Isymtable[i].name);
			free(Isymtable[i].info);
		}
	}
	return 0;
}