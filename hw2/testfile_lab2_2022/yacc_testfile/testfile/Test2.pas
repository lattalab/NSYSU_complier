(*
self-created testfile, not provided by TA
*)
program IfElseExample;
var
  x, y: integer;
  u : real;
begin
  x := 10;
  y := 20;
  
  if (x < y) then
    writeln('x is less than y'); 
	
  if (x > y) 
    writeln('x > y'); 
	
  if x < y) then  
    writeln('x is less than y'); (*Error when lacking ')' *)
	
  if (x < y then  
    writeln('x is less than y'); (*Error when lacking ')' *)
    x:= 1 + 1.23;
    x:= 1 - 1.23;
    x:= 1 * 1.23;
    x:= 1 / 1.23;
    
    y:= 1*u;
    y:= 1+u;
    y:= 1-u;
    y:= 1/u;
    
end.
