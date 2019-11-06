%{
(** Parser *)


(** Subset of rules in order to generate quads
<statlist>   ::= <stat> | <stat> ; <statlist> 
<stat>	     ::= ...| <forstat> | <affectstat>
<affectstat> ::= ident := <exp>

*)
     open Lang

%}
%token <string> INTCONST
%token <string> IDENTIFIER
%token PLUS MINUS
%token TIMES 
%token ENDINSTR 
%token AFFECT 
%token EOF
%left  PLUS MINUS
%left  TIMES 

%type <string> term ident
%type <string*(Lang.quad list)> expr 
%type <Lang.quad list> statlist
%start statlist

%%

statlist: EOF                               { []}
    | stat                                  { $1 }
    | stat ENDINSTR statlist                { $1@$3 }

;

stat:  affectstat                           { $1 }
;

affectstat:  ident AFFECT expr            { let (ident, exp) = ($1, (fst $3)) in (snd $3)@[((currentquad ()),":=",exp,"nil",ident)]}
;

  
expr: 
    | ident                                { ($1,[])}
    | term                                 { ($1,[])}
    | expr PLUS expr                       { let (e1,e2) = (fst $1,fst $3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd $1)@(snd $3)))@[(currentquad ()),"+",e1,e2,res])}
    | expr TIMES expr                      { let (e1,e2) = (fst $1,fst $3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd $1)@(snd $3)))@[(currentquad ()),"*",e1,e2,res])}
;

ident: IDENTIFIER                           { $1 }
;

term: INTCONST                             { $1 }   
;
