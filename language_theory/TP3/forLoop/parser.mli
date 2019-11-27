type token =
  | INTCONST of (string)
  | IDENTIFIER of (string)
  | PLUS
  | MINUS
  | TIMES
  | ENDINSTR
  | AFFECT
  | EOF
  | DO
  | ENDLOOP
  | FOR
  | STEP
  | UNTIL

val statlist :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Lang.quad list
