#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#define maxn 1005
#define re register
using namespace std;
namespace fastIO {
#define BUF_SIZE 100000
#define OUT_SIZE 100000
#define ll long long
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if (p1 == pend) {
			p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if (pend == p1) { IOerror = 1; return -1; }
		}
		return *p1++;
	}
	inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
	inline void read(int &x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0'&&ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (sign)x = -x;
	}
	inline void read(ll &x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0'&&ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (sign)x = -x;
	}
	inline void read(double &x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0'&&ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (ch == '.') {
			double tmp = 1; ch = nc();
			for (; ch >= '0'&&ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
		}
		if (sign)x = -x;
	}
	inline void read(char *s) {
		char ch = nc();
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		for (; !blank(ch) && !IOerror; ch = nc())*s++ = ch;
		*s = 0;
	}
	inline void read(char &c) {
		for (c = nc(); blank(c); c = nc());
		if (IOerror) { c = -1; return; }
	}
	inline void read1(int &x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch<'0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0'&&ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (bo)x = -x;
	}
	inline void read1(ll &x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch<'0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0'&&ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (bo)x = -x;
	}
	inline void read1(double &x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch<'0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0'&&ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (ch == '.') {
			double tmp = 1;
			for (ch = getchar(); ch >= '0'&&ch <= '9'; tmp /= 10.0, x += tmp * (ch - '0'), ch = getchar());
		}
		if (bo)x = -x;
	}
	inline void read1(char *s) {
		char ch = getchar();
		for (; blank(ch); ch = getchar());
		for (; !blank(ch); ch = getchar())*s++ = ch;
		*s = 0;
	}
	inline void read1(char &c) { for (c = getchar(); blank(c); c = getchar()); }
	struct Ostream_fwrite {
		char *buf, *p1, *pend;
		Ostream_fwrite() { buf = new char[BUF_SIZE]; p1 = buf; pend = buf + BUF_SIZE; }
		void out(char ch) {
			if (p1 == pend) {
				fwrite(buf, 1, BUF_SIZE, stdout); p1 = buf;
			}
			*p1++ = ch;
		}
		void print(int x) {
			static char s[15], *s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1);
		}
		void println(int x) {
			static char s[15], *s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1); out('\n');
		}
		void print(ll x) {
			static char s[25], *s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1);
		}
		void println(ll x) {
			static char s[25], *s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1); out('\n');
		}
		void print(double x, int y) {
			static ll mul[] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL };
			if (x < -1e-12)out('-'), x = -x; x *= mul[y];
			ll x1 = (ll)floor(x); if (x - floor(x) >= 0.5)++x1;
			ll x2 = x1 / mul[y], x3 = x1 - x2 * mul[y]; print(x2);
			if (y > 0) { out('.'); for (size_t i = 1; i < y&&x3*mul[i] < mul[y]; out('0'), ++i); print(x3); }
		}
		void println(double x, int y) { print(x, y); out('\n'); }
		void print(char *s) { while (*s)out(*s++); }
		void println(char *s) { while (*s)out(*s++); out('\n'); }
		void flush() { if (p1 != buf) { fwrite(buf, 1, p1 - buf, stdout); p1 = buf; } }
		~Ostream_fwrite() { flush(); }
	}Ostream;
	inline void print(int x) { Ostream.print(x); }
	inline void println(int x) { Ostream.println(x); }
	inline void print(char x) { Ostream.out(x); }
	inline void println(char x) { Ostream.out(x); Ostream.out('\n'); }
	inline void print(ll x) { Ostream.print(x); }
	inline void println(ll x) { Ostream.println(x); }
	inline void print(double x, int y) { Ostream.print(x, y); }
	inline void println(double x, int y) { Ostream.println(x, y); }
	inline void print(char *s) { Ostream.print(s); }
	inline void println(char *s) { Ostream.println(s); }
	inline void println() { Ostream.out('\n'); }
	inline void flush() { Ostream.flush(); }
	char Out[OUT_SIZE], *o = Out;
	inline void print1(int x) {
		static char buf[15];
		char *p1 = buf; if (!x)*p1++ = '0'; if (x < 0)*o++ = '-', x = -x;
		while (x)*p1++ = x % 10 + '0', x /= 10;
		while (p1-- != buf)*o++ = *p1;
	}
	inline void println1(int x) { print1(x); *o++ = '\n'; }
	inline void print1(ll x) {
		static char buf[25];
		char *p1 = buf; if (!x)*p1++ = '0'; if (x < 0)*o++ = '-', x = -x;
		while (x)*p1++ = x % 10 + '0', x /= 10;
		while (p1-- != buf)*o++ = *p1;
	}
	inline void println1(ll x) { print1(x); *o++ = '\n'; }
	inline void print1(char c) { *o++ = c; }
	inline void println1(char c) { *o++ = c; *o++ = '\n'; }
	inline void print1(char *s) { while (*s)*o++ = *s++; }
	inline void println1(char *s) { print1(s); *o++ = '\n'; }
	inline void println1() { *o++ = '\n'; }
	inline void flush1() { if (o != Out) { if (*(o - 1) == '\n')*--o = 0; puts(Out); } }
	struct puts_write {
		~puts_write() { flush1(); }
	}_puts;
#undef ll
#undef OUT_SIZE
#undef BUF_SIZE
}; using namespace fastIO;
int n, a[maxn];
int k;
stack<int> s;
bool flag;
int main()
{
	while (1)
	{
		read(n);
		if (n == 0)
			return 0;
		while (1)
		{
			int i = 1;
			k = 1;
			flag = true;
			read(a[1]);
			if (a[1] == 0)
				break;
			for (int i = 2; i <= n; i++)
				read(a[i]);
			for (k; k <= n; k++)
			{
				if (a[k] == i)
				{
					i++;
					continue;
				}
				if (a[k] > i)
				{
					while (a[k] > i)
						s.push(i), i++;
					i++;
				}
				else
				{
					if (s.top() == a[k])
						s.pop();
					else
					{
						flag = false;
						printf("No\n");
						break;
					}
				}
			}
			if (flag)
				printf("Yes\n");
		}
		printf("\n");
	}
	return 0;
}