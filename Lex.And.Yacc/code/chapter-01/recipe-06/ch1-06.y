%{
#include <stdio.h>
/* we found the following required for some yacc implementations. */
/* #define YYSTYPE int */

extern int yylex (void);
void yyerror(char *s);

%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%

sentence: simple_sentence   { printf("Parsed a simple sentence.\n"); }
	| compound_sentence { printf("Parsed a compound sentence.\n"); }
	; 

simple_sentence: subject verb object
	|	subject verb object prep_phrase
	;

compound_sentence: simple_sentence CONJUNCTION simple_sentence
	|	compound_sentence CONJUNCTION simple_sentence
	;

subject:	NOUN
	|	PRONOUN
	|	ADJECTIVE subject
	;

verb:		VERB
	|	ADVERB VERB
	|	verb VERB
	;
	
object:		NOUN
	|	ADJECTIVE object
	;

prep_phrase:	PREPOSITION NOUN
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
