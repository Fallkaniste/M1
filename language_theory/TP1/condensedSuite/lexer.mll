(** lexer.mll *)
{
(*** OCAML PART for tool functions ***)
(* convert char in int *)
let digit_of_char c = (int_of_char c - int_of_char '0')
(* calcul de la valeur et ajout dans une chaine *)
let calcul_to_string b s e c =
  let valeur = b + s*e in 
  let rec aux n = 
    if (n == 1) then string_of_int valeur
    else (string_of_int valeur)^" "^(aux (n-1))
  in aux c
}

(*** ANALYSER PART ***)
(** Lexical Unit(s) **)
let integer = ['0' - '9']

(** Rules **)
rule l0 = parse
		| integer as i     { (*A1*) print_string ("A1 reads "^(Char.escaped i)^"\n"); let vi = (digit_of_char i) in l1 vi lexbuf}
		| _                {failwith "error_l0" } (** to exit properly, or add another rule *)
and
l1  v = parse
		| integer as i       { (*A2*) print_string ("A2 reads "^(Char.escaped i)^"\n"); let vi = (digit_of_char i) in l1 (v*10+vi) lexbuf}
		| '\n'       	     { (*A3*) print_string ("A3 reads eol"^"\n"); v}
		| eof	             { (*A3*) print_string ("A3 reads eof"^"\n"); v}
		|'$'	             { (*A4*) print_string ("A4 reads $"^"\n");l2 v lexbuf }
		| _                {failwith "error_l1" }
and
l2 b = parse
		| '-'		      { l3 b 1 lexbuf}
		| '+'		      { l4 b 1 lexbuf}
		| '0'	              { l5 b 1 lexbuf}
		| _                   {failwith "error_l2"}
and
l3 b count = parse
      	| integer as i     {l6 b count (digit_of_char i) (-1) lexbuf}
      	| '-'	           {l3 b (count+1) lexbuf}
      	| _                {failwith "error_l3" }
and
l4 b count = parse
      	| integer as i     {l6 b count (digit_of_char i) 1 lexbuf}
      	| '+'	           {l4 b (count+1) lexbuf}
      	| _                {failwith "error_l4" }

and
l5 b count = parse
      	| 'b' 		   {(calcul_to_string b 1 0 count);(*A3*) print_string ("L5 PRINT LINE"^"\n") ;l7 b lexbuf}
      	| '0'	           {l5 b (count+1) lexbuf}
      	| _                {failwith "error_l5" }
and
l6 b count nb sign = parse
	| integer as i     {let vi = (digit_of_char i) in l6 b (count) (nb*10+vi) sign lexbuf}
      	| 'b' 		   {calcul_to_string b sign nb count; (*A3*) print_string ("L6 PRINT LINE"^"\n"); l7 b lexbuf}
      	| _                {failwith "error_l6" }

and
l7 b = parse
		| '-'		      { l3 b 1 lexbuf}
		| '+'		      { l4 b 1 lexbuf}
		| '0'	              { l5 b 1 lexbuf}
		| '\n'		 { print_string (" EOF"^"\n"); b}
		| eof	              { print_string (" EOF"^"\n"); b}
		| _                   {failwith "error_l7"}










