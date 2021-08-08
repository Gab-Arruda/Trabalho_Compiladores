%{
    #include "tokens.h"
    #include "hash.h"
    int running = 1;  
    int lineNumber = 1;  
%}

%x COMMENT

%%

int                     {return KW_INT;}
[0-9]+                  {hashInsert(yytext,LIT_INTEGER); return LIT_INTEGER;}
[-+;{}:]                {return yytext[0];}
[ \t]    
"\n"                    {++lineNumber;}   
"//".*              
"/*"                    {BEGIN(COMMENT);}
.                       {return TOKEN_ERROR;} 

<COMMENT>"*/"           {BEGIN(INITIAL);}
<COMMENT>"\n"           {++lineNumber;}
<COMMENT>.

%%

#include "main.c"
#include "hash.c"

int yywrap()
  {
    running = 0;
    return 1;
  }