%token A
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ () }
;

/* this grammar is ambiguous and can be simplified */
/*
s: u { print_string "S -> U \n" }
;

v: { print_string "U -> lambda\n"}
;

w: { print_string "W -> lambda\n"}
;

u:v w u{ print_string "U -> V W U\n"}
| A {print_string"U -> a\n"}
;
*/

/* we can replace everything above by : */ 
s: A { print_string "S -> a \n" }
;
%%
