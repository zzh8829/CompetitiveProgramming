program problemWombats;
uses math;

const	inf =	round(1.0e+15);

type	tRec =	record
					a: array[ 1..12, 1..12 ] of int64;
					n, cnt: longInt;
					f: array[ 1..800000, 1..12 ] of longInt;
					dp: array[ 1..800000 ] of int64;
				end;
				
var	forSearch: array[ 1..12 ] of longInt;

function find( const g: tRec ): longInt;
var	l, r, c, i: longInt;
begin
	l := 1;
	r := g.cnt;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		i := 1;
		while ( i <= g.n ) and ( forSearch[i] = g.f[c][i] ) do
			inc( i );
		
		if ( i <= g.n ) and ( g.f[c][i] < forSearch[i] ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

procedure generateStates( var g: tRec );
var	i, j: longInt;
begin
	with g do
	begin
		cnt := 1;
		for i := 1 to n do
			f[1][i] := 0;
		
		while ( true ) do
		begin
			i := n;
			while ( i > 1 ) and ( f[cnt][i] = min( f[cnt][i - 1], n - i + 1 ) ) do
				dec( i );
			
			if ( i = 1 ) and ( f[cnt][i] = n ) then
				break;
			
			inc( cnt );
			for j := 1 to i - 1 do
				f[cnt][j] := f[cnt - 1][j];
			
			f[cnt][i] := f[cnt - 1][i] + 1;
			
			for j := i + 1 to n do
				f[cnt][j] := 0;
		end;
		
		for i := 1 to cnt do
			dp[i] := -inf;
	end;
end;

procedure processTransition( var g2, g: tRec );
var	i, j: longInt;
begin
	with g do
	begin
		for i := 1 to cnt do
		begin
			for j := 1 to n - 1 do
				forSearch[j] := min( f[i][j], n - j );
			
			j := find( g2 );
			
			g2.dp[j] := max( g2.dp[j], dp[i] );
		end;
	end;
end;

procedure calculateDP( var g: tRec );
var	i, j, k: longInt;
begin
	with g do
	begin
		for i := cnt downto 1 do
		begin
			for j := 1 to n do
				forSearch[j] := f[i][j];
			
			if ( n <> 12 ) then
			begin
				for j := 1 to n do
					if ( f[i][j] > 0 ) and ( ( j = n ) or ( f[i][j + 1] < f[i][j] ) ) then
					begin
						dec( forSearch[j] );
						
						k := find( g );
						
						dp[k] := max( dp[k], dp[i] );
						
						inc( forSearch[j] );
					end;
			end;
			
			for j := 1 to n do
				for k := 1 to f[i][j] do
					inc( dp[i], a[j + k - 1][j] );
		end;
	end;
end;

var	f: array[ 0..1 ] of tRec;
	n, i, j, k: longInt;
	a: array[ 1..12, 1..12, 1..12 ] of longInt;
	ans: int64;

begin
	readln( n );
	for i := 1 to n do
		for j := 1 to i do
			for k := 1 to i + 1 - j do
				read( a[i][j][k] );
	
	f[n mod 2].n := n;
	for i := 1 to n do
		for j := 1 to i do
			f[n mod 2].a[i][j] := a[i][i + 1 - j][j];
			
	generateStates( f[n mod 2] );
	for i := 1 to f[n mod 2].cnt do
		f[n mod 2].dp[i] := 0;

	calculateDP( f[n mod 2] );
	
	for k := n - 1 downto 1 do
	begin
		f[k mod 2].n := k;
		for i := 1 to k do
			for j := 1 to i do
				f[k mod 2].a[i][j] := a[ i + (n - k) ][i + 1 - j][j];
		
		f[k mod 2].cnt := 0;
		
		generateStates( f[k mod 2] );
		processTransition( f[k mod 2], f[ (k + 1) mod 2 ] );
		calculateDP( f[k mod 2] );
	end;
	
	ans := 0;
	for i := 1 to f[1].cnt do
		ans := max( ans, f[1].dp[i] );
{		
	for i := 1 to n do
	begin
		writeln( 'Layer #', i, ': ' );
		
		for j := 1 to i do
		begin
			for k := 1 to j do
				write( f[i].a[j][k], ' ' );
			writeln();
		end;
		
		for j := 1 to f[i].cnt do
		begin
			write( j:3, ' ' );
			for k := 1 to i do
				write( f[i].f[j][k], ' ' );
			
			writeln( f[i].dp[j] );
		end;
	end;
}	
	writeln( ans );
end.
