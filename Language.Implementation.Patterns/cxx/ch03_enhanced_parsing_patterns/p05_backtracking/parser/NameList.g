list     : '[' elements ']' ; // match bracketed list
elements : element (',' element)* ; // match comma-separated list
element  : NAME '=' NAME // match assignment such as a=b
         | NAME
         | list
         ;
