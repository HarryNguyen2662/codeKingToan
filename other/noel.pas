const fi='';
      fo='';

var f,g:text;
    n,m,i,j,t:longint;
    s,k:string;
    a,e:array[0..61]of string;
    b,c,d,kq,u,v:array[0..61]of int64;
    dem:int64;

function xl(x:string):longint;
var l:longint;
    y:string;
begin
    y:=''; xl:=0;
    for l:=length(x) downto 1 do
    begin
        y:=x[l]+y;
        if y=a[length(y)] then xl:=length(y);
    end;
end;

function kt(x:string):boolean;
begin
    if pos(s,x)=0 then kt:=false else kt:=true;
end;


procedure pt(x:string);
var l,r,dd:longint;
begin
    for l:=length(k)+1 to length(S)-1 do
        if (pos(k,e[l])=1)or(k='') then
            begin
                dd:=0;
                for r:=1 to m do
                    if pos(e[u[r]],e[l])=1 then dd:=1;
                if dd=0 then begin inc(m); u[m]:=l; v[m]:=xl(e[l]); end;
            end;
end;



begin
assign(f,fi);reset(f);
assign(g,fo);rewrite(g);
readln(F,n);
readln(f,s);

a[0]:='';
for i:=1 to length(s) do a[i]:=a[i-1]+s[i];
e[0]:='';
for i:=1 to length(S) do e[i]:=s[length(s)-i+1]+e[i-1];

for i:=0 to 61 do d[i]:=0;

k:='';
for i:=length(s) downto 1 do
begin
    b:=d; c:=d; u:=d; v:=d;

    m:=0;
    pt(k);

    m:=1;
    b[xl(k)]:=1;

    for j:=length(k)+1 to n do
    begin
        for t:=0 to length(s)-1 do
            if b[t]>0 then
                begin inc(c[xl(a[t]+'0')],b[t]); inc(c[xl(a[t]+'1')],b[t]); end;
        if j=u[m] then begin dec(c[v[m]]); inc(m); end;
        b:=c; c:=d;
    end;

    for j:=0 to length(s)-1 do
        if kt(a[j]+k)=false then inc(kq[length(K)],b[j]);

    k:=s[i]+k;
end;
dem:=1;
for i:=1 to n do dem:=dem*2;

for i:=0 to length(s) do dem:=dem-kq[i];
writeln(g,dem);
close(f);
close(g);
end.