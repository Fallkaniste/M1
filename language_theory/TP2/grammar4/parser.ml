type token =
  | A
  | EOF

open Parsing;;
let _ = parse_error;;
let yytransl_const = [|
  257 (* A *);
    0 (* EOF *);
    0|]

let yytransl_block = [|
    0|]

let yylhs = "\255\255\
\001\000\002\000\004\000\005\000\003\000\003\000\000\000"

let yylen = "\002\000\
\002\000\001\000\000\000\000\000\003\000\001\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\006\000\007\000\000\000\002\000\004\000\001\000\
\000\000\005\000"

let yydgoto = "\002\000\
\004\000\005\000\006\000\007\000\009\000"

let yysindex = "\255\255\
\000\255\000\000\000\000\000\000\002\000\000\000\000\000\000\000\
\000\255\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000"

let yygindex = "\000\000\
\000\000\000\000\250\255\000\000\000\000"

let yytablesize = 3
let yytable = "\001\000\
\003\000\008\000\010\000"

let yycheck = "\001\000\
\001\001\000\000\009\000"

let yynames_const = "\
  A\000\
  EOF\000\
  "

let yynames_block = "\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 's) in
    Obj.repr(
# 8 "parser.mly"
          ( () )
# 62 "parser.ml"
               : unit))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : 'u) in
    Obj.repr(
# 11 "parser.mly"
     ( print_string "S -> U \n" )
# 69 "parser.ml"
               : 's))
; (fun __caml_parser_env ->
    Obj.repr(
# 14 "parser.mly"
   ( print_string "U -> lambda\n")
# 75 "parser.ml"
               : 'v))
; (fun __caml_parser_env ->
    Obj.repr(
# 17 "parser.mly"
   ( print_string "W -> lambda\n")
# 81 "parser.ml"
               : 'w))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'v) in
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'w) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'u) in
    Obj.repr(
# 20 "parser.mly"
       ( print_string "U -> V W U\n")
# 90 "parser.ml"
               : 'u))
; (fun __caml_parser_env ->
    Obj.repr(
# 21 "parser.mly"
    (print_string"U -> a\n")
# 96 "parser.ml"
               : 'u))
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
