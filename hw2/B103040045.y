%{
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

// create symbol table
struct symtab{
	char name[40];
	char type[20];
	char undefinedFlag;  // if assert 1, meaning correctly defined
};
struct symtab symtable[100];
int idx = 0;
int idlistCounter = 0;

char flag = 1;
extern unsigned line_num;
extern int yylex();
extern void yyerror(const char *error);
static char check(const char *id);

%}

%define parse.error verbose	// know more information

%union {
	char *str;
}
%type <str> arraytype standtype type factor varid term simpexp
%token <str> DOUBLE ID INTEGER REAL SINGLE STR STRING INT REAL_NUM
%token <str>ABSOLUTE AND ARRAY BEG BREAK CASE CONST CONTINUE DO ELSE END FOR FUNCTION IF MOD NIL NOT OBJECT OF OR PROGRAM READ READLN THEN TO VAR WHILE WRITE WRITELN LT EQUAL GT ASSIGN LE GE NE LP RP
%token <str> XID XREAL

%%
//程式整體架構
prog 	 : PROGRAM progname ';' VAR declist ';' BEG stmtlist ';' END '.' 
	 | PROGRAM progname {	
		//處理結構中VAR前缺乏;的情況
		char temp[60];
        strcpy(temp, "syntax error, \";\" expected but \"VAR\" found");
        yyerror(temp);
	 } VAR declist ';' BEG stmtlist ';' END '.'
	 | PROGRAM progname ';' VAR declist {
		//處理結構中BEGIN前缺乏;的情況
		char temp[60];
        strcpy(temp, "syntax error, \";\" expected but \"BEGIN\" found");
        yyerror(temp);
	 } BEG stmtlist ';' END '.'
	 | PROGRAM progname ';' VAR declist ';' BEG END '.' {
		// no expression here
		char temp[60];
        strcpy(temp, "Note: expected any expressions inside BEGIN-END, but notany");
        yyerror(temp);
	 } 
	 | PROGRAM progname ';' VAR declist ';' BEG stmtlist ';' END {	
		//處理結構中END後缺乏.的情況
		char temp[60];
        strcpy(temp, "syntax error, \".\" expected but \"end of file\" found");
        yyerror(temp);
	 }
	 | PROGRAM progname ';' VAR declist ';' BEG stmtlist ';' END ';'{	
		//處理結構中END後不是.卻是;的情況
		char temp[60];
        strcpy(temp, "Syntax error, \".\" expected but \";\" found");
        yyerror(temp);
	 }
 	 | error {yyerrok;} // error recovery
	 ;
progname : ID
	 | XID {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
	 ;
declist	 : dec
	 | declist ';' dec
	 ;
dec : idlist ':' type {
        for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, $3);
			symtable[idx-1-i].undefinedFlag = 0;
		}
		idlistCounter = 0;
    }
    | idlist ASSIGN type {
		for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, $3);
			symtable[idx-1-i].undefinedFlag = 1;
		}
		idlistCounter = 0;

		/* if assignment symbol misuse , report error */
            char temp[60];
            strcpy(temp, "syntax error, \":\" expected but \":=\" found");
            yyerror(temp);
        }
	| idlist EQUAL type {
		for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, $3);
			symtable[idx-1-i].undefinedFlag = 1;
		}
		idlistCounter = 0;
		
		/* if assignment symbol misuse , report error */
            char temp[60];
            strcpy(temp, "syntax error, \"=\" expected but \":=\" found");
            yyerror(temp);
        }
    ;
type : standtype {$$ = $1;}
	 | arraytype {$$ = $1;}
	 ;
standtype: INTEGER {$$ = $1;}
	 | REAL {$$ = $1;}
	 | DOUBLE {$$ = $1;}
	 | STRING {$$ = $1;} 
	 ; 
arraytype: ARRAY '[' INT '.' '.' INT ']' OF standtype {$$ = $9;}
	 ;
idlist	 : ID {

	idlistCounter ++;
	//宣告id，建立table以儲存id與其type對照，並比對是否重複
	/* Store in symbol table */
	/* First, check if there repeat ID encounter */
	int store = 1;
	for (int i=0;i<idx;i++)
	{
		int res = strcmp(symtable[i].name, $1);
		if (res == 0) // repetitive ID
		{
			char temp[60];
        	strcpy(temp, "Error: Duplicate identifier ");
			strcat(temp , symtable[i].name);
        	yyerror(temp);
			store = 0;
		}
	}
	if (store)
	{
		strcpy(symtable[idx].name, $1);
		idx +=1;
	}
}
	 | idlist ',' ID {
	
	idlistCounter++;
	/* Store in symbol table */
	/* First, check if there repeat ID encounter */
	int store = 1;
	for (int i=0;i<idx;i++)
	{
		int res = strcmp(symtable[i].name, $3);
		if (res == 0) // repetitive ID
		{
			char temp[60];
        	strcpy(temp, "Error: Duplicate identifier ");
			strcat(temp , symtable[i].name);
        	yyerror(temp);
			store = 0;
		}
	}

	if (store)
	{
		strcpy(symtable[idx].name, $3);
		idx +=1;
	}
}
	 | XID {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
	 | idlist ',' XID {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
	 ;
stmtlist : stmt
	 | stmtlist ';' stmt
	 ;
stmt	 : assign
	 | read
	 | write
	 | for
	 | ifstmt
assign	 : varid ASSIGN simpexp {

		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $1)==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $3)==0)
			{
				chsimp=i;
				break;
			}
		}

		// Test if identifier has been defined?
		if (chvar!=-1 && symtable[chvar].undefinedFlag){
			char temp[60];
			strcpy(temp, "Error, identifier not found \"");
			strcat(temp, symtable[chvar].name);
			strcat(temp, "\".");
			yyerror(temp);
		}

		if(chvar!=-1 && chsimp!=-1 && (strcmp(symtable[chvar].type, symtable[chsimp].type)!=0)){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[60];
	        	strcpy(temp, "error, incompatible types: got \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" expected \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            	}
		if(chvar!=-1 && chsimp==-1 && (strcmp(symtable[chvar].type, $3)!=0)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[60];
				strcpy(temp, "error, incompatible types: got \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" expected \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);
        }
	 }
	 | varid EQUAL simpexp {
		//若符號錯誤，需輸出錯誤訊息
		char temp [50];
		strcpy(temp,"Illegal expression, Use \":=\" to replace the =");
		yyerror(temp);
	 }
	 | varid ':' simpexp {
		//若符號錯誤，需輸出錯誤訊息
		char temp [50];
		strcpy(temp,"Illegal expression, Use \":=\" to replace the :");
		yyerror(temp);
	 }
	 ;
exp	 : simpexp
	 | exp relop simpexp
	 ;
relop	 : LT
	 | EQUAL
	 | GT
	 | LE
	 | GE
	 | NE
	 | MOD
	 ;
simpexp	 : term {$$ = $1;}
	 | simpexp '+' term {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $1)==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $3)==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
        }
		if(chvar==-1 && chsimp!=-1 && strcmp($1, symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $1);
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, $3)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" + \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        }
		if (chvar==-1 && chsimp==-1 && strcmp($1, $3)) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, $1);
				strcat(temp, "\" + \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
	 }
	 | simpexp '-' term {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)	//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $1)==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)	//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $3)==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
        }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, $3)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" + \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        }
		if (chvar==-1 && chsimp==-1 && strcmp($1, $3)) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, $1);
				strcat(temp, "\" - \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp($1, symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $1);
	        	strcat(temp, "\" - \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" - \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp($3, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" - \"String\"");
				yyerror(temp);
			}
		}
	 }
	 ;
term	 : factor
	 | factor '*' factor {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $1)==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)	//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $3)==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, $3)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $3);
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar==-1 && chsimp==-1 && strcmp($1, $3)) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, $1);
				strcat(temp, "\" * \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp($1, symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $1);
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
			if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" * \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp($3, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" * \"String\"");
				yyerror(temp);
			}
		}
	 }
	 | factor '/' factor {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $1)==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, $3)==0)
			{
				chsimp=i;
				break;
			}
		}

		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, $3)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $3);
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar==-1 && chsimp==-1 && strcmp($1, $3)) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, $1);
				strcat(temp, "\" / \"");
				strcat(temp, $3);
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp($1, symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, $1);
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" / \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp($3, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" / \"String\"");
				yyerror(temp);
			}
		}
	 }
	 ;
factor	 : varid {$$ = $1;}
	 | INT {$$ = "integer";}
	 | REAL_NUM {$$ = "real";}
	 | LP simpexp RP {$$ = $2;}
	 | STR {$$ = "string";}
	 | XREAL {$$ = "real"; yyerror("syntax error: Invalid REAL number used, please check again.");}
	 ;
read	 : readfunc
	 | readfunc LP RP
	 | readfunc LP readlist RP
	 ;
readfunc: READ
	| READLN
readlist 	: varid
	 | readlist ',' varid
	 ;

write	 : writefunc
	 | writefunc LP RP
	 | writefunc LP writelist RP
	 ;
writefunc: WRITE
	 | WRITELN
	 ;
writelist: term
	 | writelist ',' term
	 ;
for	 : FOR idxexp DO body
	 | FOR idxexp body {
		// lack of DO keywords
		char temp[60];
		strcpy(temp, "Syntax error, \"DO\" expected, please add DO keywords.");
		yyerror(temp);
	 }
	 ;
idxexp	 : varid ASSIGN simpexp TO exp
	 ;
varid	 : ID {
	//變數，如果不存在則編寫錯誤訊息
		if(!check($1))
		{
			char temp[46];
            strcpy(temp, "error, identifier not found \"");
        	strcat(temp, $1);
            strcat(temp, "\"");
            yyerror(temp);
		}
	 }
	 | ID '[' simpexp ']' {
		//陣列，如果不存在則編寫錯誤訊息
		if(!check($1))
		{
			char temp[46];
            strcpy(temp, "error, identifier not found \"");
            strcat(temp, $1);
            strcat(temp, "\"");
            yyerror(temp);
		}
	 }
	 | XID{
		char temp[54];
        strcpy(temp, "syntax error, identifier's name is too long. ");
        yyerror(temp);
	 }
	 ;
ifstmt	:IF exp RP THEN body{
		//缺少左括號的情況，編寫錯誤訊息, but shift/reduce occured
				char temp[100];
            	strcpy(temp, "syntax error, \"THEN\" expected but \")\" found");
            	yyerror(temp);
	 }
	 | IF LP exp RP THEN body 
	 | IF LP exp RP body{
		//缺少THEN的情況，編寫錯誤訊息
				char temp[60];
            	strcpy(temp, "syntax error, \"THEN\" expected but \"identifier \" found");
            	yyerror(temp);
	 } 
	 | IF LP exp THEN body {//缺少右括號的情況，編寫錯誤訊息
				char temp[100];
            	strcpy(temp, "syntax error, \")\" expected but \"THEN\" found");
            	yyerror(temp);
	 }
	 ;
body	 : stmt
	 | BEG stmtlist ';' END
	;
%%

int main() {
	yyparse();
	return 0;
}
// print Error message
void yyerror(const char *error) {
	printf("\rLine %u: %s\n", line_num, error);
	flag =0;
}
static char check(const char *id) { // 如果id存在回傳1，反之回傳0
	for(int i = 0; i <idx; ++i)
		if(!strcmp(symtable[i].name, id))
			return 1;
	return 0;
}
