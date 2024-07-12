%{
/*
 * A lexer for the basic grammar to use for recognizing english sentences.
 */
#include <stdio.h>

extern int yylex (void);
void yyerror(char *s);

%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence: subject VERB object	{ printf("Sentence is valid.\n"); }
	;

subject:	NOUN
	|	PRONOUN
	;

object:		NOUN
	;
%%

extern FILE *yyin;

int main()
{
    yyin = stdin;
	while(!feof(yyin)) {
		yyparse();
	}

    return 0;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}
