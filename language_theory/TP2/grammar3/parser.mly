%token A
%token B
%token C
%token D
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ () }
;

/* in this grammar two non terminals are giving the same output and that's a problem */ 
s: u A	{  print_string "S -> U a \n" }
| B u C { print_string "S -> b U c \n"}
| u C { print_string "S -> V c\n"} /* we replace v by u because it creates conflicts */
| B u A { print_string "S -> b V a\n"} /* we replace v by u because it creates conflicts */
;

u: D { print_string "U -> d\n"}
;

/*
v: D { print_string "V -> d\n"} 
;
*/
%%
