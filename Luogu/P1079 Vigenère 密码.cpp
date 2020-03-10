#include<iostream>
#include<string>
using namespace std;
char A = 'a', B = 'b', C = 'c', D = 'd',E = 'e', F = 'f', G = 'g', H = 'h',  I= 'i', J = 'j', K = 'k', L = 'l', M = 'm', N = 'n', O = 'o', P = 'p', Q = 'q', R = 'r', S = 's', T = 't', U = 'u', V = 'v', W = 'w', X = 'x', Y = 'y', Z = 'z';
char map[27][27] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 { ' ',A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z },
					 { ' ',B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A },
					 { ' ',C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B },
					 { ' ',D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C },
					 { ' ',E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D },
					 { ' ',F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E },
					 { ' ',G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F },
					 { ' ',H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G },
					 { ' ',I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H },
					 { ' ',J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I },
					 { ' ',K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J },
					 { ' ',L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K },
					 { ' ',M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L },
					 { ' ',N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M },
					 { ' ',O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N },
					 { ' ',P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O },
					 { ' ',Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P },
					 { ' ',R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q },
					 { ' ',S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R },
					 { ' ',T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S },
					 { ' ',U,V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T },
					 { ' ',V,W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U },
					 { ' ',W,X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V },
					 { ' ',X,Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W },
					 { ' ',Y,Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X },
					 { ' ',Z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y }, };
string ans;
int main()
{
	string t;
	string num1, num2;
	cin >> num1 >> num2;
	t = num1;
	num1 = num2;
	num2 = t;
	string x1, x2;
	x1 = num1;
	x2 = num2;
	for (int i = 0; i < x1.length(); i++)
		if (x1[i] >= 'A'&&x1[i] <= 'Z')
			x1[i] = char(x1[i] + 32);
	for (int i = 0; i < x2.length(); i++)
		if (x2[i] >= 'A'&&x2[i] <= 'Z')
			x2[i] = char(x2[i] + 32);
	for (int i = 0; i < num1.length(); i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (map[int(x2[i%x2.length()] - 96)][j] ==x1[i])
				ans += map[1][j];
		}
	}	
	for (int i = 0; i < ans.length(); i++)
	{
		if (islower(num1[i]))
			cout << ans[i];
		else
			cout << char(ans[i] - 32);
	}
	return 0;
}