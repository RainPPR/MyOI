program A;

var
    n, x, i: Integer;
    vis: array[1 .. 1010] of Integer;

begin
    ReadLn(n);
    for i := 1 to n do begin
        Read(x);
        if vis[x] <> 0 then begin
            WriteLn('1 1');
            WriteLn(vis[x]);
            WriteLn(i);
            Exit;
        end;
        vis[x] := i;
    end;
    WriteLn('-1');
end.