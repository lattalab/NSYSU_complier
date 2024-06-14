(*
self-created testfile, not provided by TA
*)
program ForLoop;
var
  i: integer;
  (* Error becase of lacking "DO" *)
begin
  for i := 1 to 10  
    writeln('Value of i: ', i);
    writeln
end.
