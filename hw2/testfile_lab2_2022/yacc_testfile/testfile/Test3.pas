(*
self-created testfile, not provided by TA
*)
program MultiLineCommetExample;
var
  a, b, sum: integer;
  f : real;
  str : string;
  ThisIsAVeryLongIdentifier: integer;
  AnotherExampleOfLongId, IdentifierWithMoreThan15Characters: real;
begin
  a := 5;
  b := 10;
  (* This is a multi-line comment.
     It spans multiple lines and provides detailed information
     about the following code block. The variables a and b are
     initialized with values 5 and 10 respectively. The sum of
     these two variables is then calculated and printed. *)
  sum := a + b;
  f := 00123.123 + 12f + 12.00F + 111E-10 + 1.;
  a := &42 + $A2;
  writeln('The sum of ', a, ' and ', b, ' is ', sum);
  
  ThisIsAVeryLongIdentifier := 100;
end.
