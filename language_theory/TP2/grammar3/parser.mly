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

s: u A	{  print_string "S -> U a \n" }
| B u C { print_string "S -> b U c \n"}
| v C { print_string "S -> V c\n"}
| B v A { print_string "S -> b V a\n"}
;

u: D { print_string "U -> d\n"}
;

v: D { print_string "V -> d\n"}
;
%%
