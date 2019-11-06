type token =
  | A
  | B
  | C
  | D
  | EOF

open Parsing;;
let _ = parse_error;;
let yytransl_const = [|
  257 (* A *);
  258 (* B *);
  259 (* C *);
  260 (* D *);
    0 (* EOF *);
    0|]

let yytransl_block = [|
    0|]

let yylhs = "\255\255\
\001\000\002\000\002\000\002\000\002\000\003\000\004\000\000\000"

let yylen = "\002\000\
\002\000\002\000\003\000\002\000\003\000\001\000\001\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\000\000\006\000\008\000\000\000\000\000\000\000\
\000\000\000\000\001\000\002\000\004\000\003\000\005\000"

let yydgoto = "\002\000\
\005\000\006\000\007\000\008\000"

let yysindex = "\002\000\
\254\254\000\000\253\254\000\000\000\000\004\000\004\255\003\255\
\005\255\006\255\000\000\000\000\000\000\000\000\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

let yygindex = "\000\000\
\000\000\000\000\006\000\007\000"

let yytablesize = 10
let yytable = "\003\000\
\004\000\004\000\001\000\011\000\012\000\013\000\015\000\014\000\
\009\000\010\000"

let yycheck = "\002\001\
\004\001\004\001\001\000\000\000\001\001\003\001\001\001\003\001\
\003\000\003\000"

let yynames_const = "\
  A\000\
  B\000\
  C\000\
  D\000\
  EOF\000\
  "

let yynames_block = "\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 's) in
    Obj.repr(
# 11 "parser.mly"
          ( () )
# 73 "parser.ml"
               : unit))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 'u) in
    Obj.repr(
# 14 "parser.mly"
       (  print_string "S -> U a \n" )
# 80 "parser.ml"
               : 's))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'u) in
    Obj.repr(
# 15 "parser.mly"
        ( print_string "S -> b U c \n")
# 87 "parser.ml"
               : 's))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 'v) in
    Obj.repr(
# 16 "parser.mly"
      ( print_string "S -> V c\n")
# 94 "parser.ml"
               : 's))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'v) in
    Obj.repr(
# 17 "parser.mly"
        ( print_string "S -> b V a\n")
# 101 "parser.ml"
               : 's))
; (fun __caml_parser_env ->
    Obj.repr(
# 20 "parser.mly"
     ( print_string "U -> d\n")
# 107 "parser.ml"
               : 'u))
; (fun __caml_parser_env ->
    Obj.repr(
# 23 "parser.mly"
     ( print_string "V -> d\n")
# 113 "parser.ml"
               : 'v))
(* Entry sp *)
; (fun __caml_parser_env -> raise (Parsing.YYexit (Parsing.peek_val __caml_parser_env 0)))
|]
let yytables =
  { Parsing.actions=yyact;
    Parsing.transl_const=yytransl_const;
    Parsing.transl_block=yytransl_block;
    Parsing.lhs=yylhs;
    Parsing.len=yylen;
    Parsing.defred=yydefred;
    Parsing.dgoto=yydgoto;
    Parsing.sindex=yysindex;
    Parsing.rindex=yyrindex;
    Parsing.gindex=yygindex;
    Parsing.tablesize=yytablesize;
    Parsing.table=yytable;
    Parsing.check=yycheck;
    Parsing.error_function=parse_error;
    Parsing.names_const=yynames_const;
    Parsing.names_block=yynames_block }
let sp (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (Parsing.yyparse yytables 1 lexfun lexbuf : unit)
;;