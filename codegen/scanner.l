%option noyywrap
%{
#include "parser.tab.h"
// #include "token.h"
%}
delim [ \t\n\r]
ws    {delim}+
letter [A-Za-z]
digit [0-9]
id    ({letter}|_)({letter}|{digit}|_)*
number {digit}+
string \"([^\"\n]|\\\")*\"
in_line_comment  \/\/.*$
c_comment    \/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/
%%
{c_comment}	{}
{in_line_comment} {}
while		{return TOKEN_WHILE;}	
<<EOF>> 	{yyterminate();}
{ws}		/*eat up white space */
string		{return TOKEN_STRING;}
{string} 	{return TOKEN_STRING_LITERAL;}
{number} 	{return TOKEN_INT_LITERAL;}
integer		{return TOKEN_INT;}
\'(((\\)?[^\\])|(\\\\))\'	{edit_string(yytext); return TOKEN_CHAR_LITERAL;}
char		{return TOKEN_CHAR;}
array		{return TOKEN_ARRAY;}
boolean		{return TOKEN_BOOLEAN;}
if 			{return TOKEN_IF;}
else		{return TOKEN_ELSE;}
false		{return TOKEN_FALSE;}
for		{return TOKEN_FOR;}
function	{return TOKEN_FUNCTION;}
print		{return TOKEN_PRINT;}
return		{return TOKEN_RETURN;}
true		{return TOKEN_TRUE;}
void		{return TOKEN_VOID;}
"+"		{return TOKEN_ADD;}
"-"		{return TOKEN_SUB;}
"*"		{return TOKEN_MULT;}
"/"		{return TOKEN_DIV;}
"^"		{return TOKEN_EXP;}
"++"		{return TOKEN_INCREMENT;}
"--"		{return TOKEN_DECREMENT;}
">"		{return TOKEN_GT;}
">="		{return TOKEN_GE;}
"=="		{return TOKEN_EQ;}
"<="		{return TOKEN_LE;}
"<"		{return TOKEN_LT;}
"&&"		{return TOKEN_AND;}
"||"		{return TOKEN_OR;}
"!="		{return TOKEN_NE;}
"="		{return TOKEN_ASSGN;}
";"		{return TOKEN_SEMICOLON;}
":"		{return TOKEN_COLON;}
"("		{return TOKEN_LPAREN;}
")"		{return TOKEN_RPAREN;}
"["		{return TOKEN_LBRACE;}
"]"		{return TOKEN_RBRACE;}
"{"		{return TOKEN_LCURLBRACE;}
"}"		{return TOKEN_RCURLBRACE;}
","		{return TOKEN_COMMA;}
"%"		{return TOKEN_MOD;}
{id}		{return TOKEN_IDENT;}
"!"		{return TOKEN_NOT;}
.		{return NOT_TOKEN;}
%%
