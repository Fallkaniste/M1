type token =
  | INTCONST of (string)
  | IDENTIFIER of (string)
  | PLUS
  | MINUS
  | TIMES
  | ENDINSTR
  | AFFECT
  | EOF

val statlist :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Lang.quad list
