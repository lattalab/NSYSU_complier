(*
self-created testfile, not provided by TA
*)
program StringTest;
var
  a, b, sum: real;
  str : string;
  (*
  Here all these string Test should be reduced
  When there are somthing before or after 2 consective ' 
  we can reduce 2 to 1 ' 
  *)
begin
  str := 'You''ll see';
  writeln(str);
  
  str := '''';
  writeln(str);
  
  str := '''123';
  writeln(str);
  
  str := 'abc''';
  writeln(str);
    
   str := ''';
  writeln(str);
  
  str := 'abcdefghijklmnopqrstuvwxyz12345678910';
  writeln(str);
end.
