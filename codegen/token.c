#include "token.h"
#include<stdio.h>
#include<string.h>

const char * token_string(token_t t){
	switch(t){
		case TOKEN_WHILE:
			return "WHILE";
			break;
		case TOKEN_IDENT:
			return "IDENTIFIER";
			break;
		case TOKEN_STRING:
			return "STRING";
			break;
		case TOKEN_STRING_LITERAL:
			return "STRING_LITERAL";
			break;
		case TOKEN_INT_LITERAL:
			return "INTEGER_LITERAL";
			break;
		case TOKEN_INT:
			return "INTEGER";
			break;
		case TOKEN_CHAR_LITERAL:
			return "CHARACTER_LITERAL";
			break;
		case TOKEN_CHAR:
			return "CHARACTER";
			break;
		case TOKEN_ARRAY:
			return "ARRAY";
			break;
		case TOKEN_BOOLEAN:
			return "BOOLEAN";
			break;
		case TOKEN_ELSE:
			return "ELSE";
			break;
		case TOKEN_FALSE:
			return "FALSE";
			break;
		case TOKEN_FOR:
			return "FOR";
			break;
		case TOKEN_FUNCTION:
			return "FUNCTION";
			break;
		case TOKEN_PRINT:
			return "PRINT";
			break;
		case TOKEN_RETURN:
			return "RETURN";
			break;
		case TOKEN_TRUE:
			return "TRUE";
			break;
		case TOKEN_VOID:
			return "VOID";
			break;
		case TOKEN_ADD:
			return "ADD";
			break;
		case TOKEN_SUB:
			return "SUBTRACT";
			break;
		case TOKEN_MULT:
			return "MULTIPLY";
			break;
		case TOKEN_DIV:
			return "DIVIDE";
			break;
		case TOKEN_EXP:
			return "EXPONENTIATION";
			break;
		case TOKEN_INCREMENT:
			return "INCREMENT";
			break;
		case TOKEN_DECREMENT:
			return "DECREMENT";
			break;
		case TOKEN_GT:
			return "GT";
			break;
		case TOKEN_GE:
			return "GE";
			break;
		case TOKEN_EQ:
			return "EQ";
			break;
		case TOKEN_LE:
			return "LE";
			break;
		case TOKEN_LT:
			return "LT";
			break;
		case TOKEN_AND:
			return "AND";
			break;
		case TOKEN_OR:
			return "OR";
			break;
		case TOKEN_NE:
			return "NOT_EQUAL";
			break;
		case TOKEN_ASSGN:
			return "ASSIGNMENT";
			break;
		case TOKEN_SEMICOLON:
			return "SEMICOLON";
			break;
		case TOKEN_COLON:
			return "COLON";
			break;
		case TOKEN_LPAREN:
			return "LEFT_PARENTHESES";
			break;
		case TOKEN_RPAREN:
			return "RIGHT_PARENTHESES";
			break;
		case TOKEN_LBRACE:
			return "LEFT_BRACE";
			break;
		case TOKEN_RBRACE:
			return "RIGHT_BRACE";
			break;
		case TOKEN_LCURLBRACE:
			return "LEFT_CURL_BRACE";
			break;
		case TOKEN_RCURLBRACE:
			return "RIGHT_CURL_BRACE";
			break;
		case TOKEN_MOD:
			return "MODULUS";
			break;
		case TOKEN_COMMA:
			return "COMMA";
			break;
		case TOKEN_IF:
			return "IF";
			break;
		default:
			return "nothing";
			break;
	}
}

void edit_string(char * word){
	int i, j, k;
	for(i=1;i<strlen(word);i++){
		word[i-1] = word[i];
	}	
	word[i-2] = '\0';

	for(i = 0; i < strlen(word); i++){
		if(word[i]=='\\'){
			if(word[i+1]=='n'){
				word[i] = '\n';
			} else if(word[i+1]=='0'){
				word[i] = '\0';	
				if(word[0] == '\0'){
					return;
				}
			} else{
				word[i] = word[i+1];
			}
			for(j = i+1; j < strlen(word)-1; j++){
				word[j] = word[j+1];
			}
			if(strlen(word) != 0){
				word[j] = '\0';
			}
		}
        }
	//printf("%s\n", word);
}


