%token A
%token B
%token C
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ () }
;

s: A u	{  print_string "S -> a U\n" }
| u B { print_string "S -> u B \n"}
| A B { print_string "S -> a b\n"}
;

u: C u { print_string "U -> c U\n"}
| {print_string "U -> Lambda\n"}
;
%%
