#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10010;
bool isPrime(int n) {
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

bool isFlag1[maxn] = {0};
int main() {
	int MSize, N, p, x, M;
	scanf("%d %d", &MSize, &N);
	while(isPrime(MSize) == false) {
		MSize++;
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &x);
		p = x % MSize;
		if(isFlag1[p] == false) {
			isFlag1[p] = true;
			if(i == 0) printf("%d", p);
			else printf(" %d", p);
		} else {
			int step;
			for(step = 1; step < MSize; step++) {
				M = (x + step * step) % MSize;
				if(isFlag1[M] == false) {
					isFlag1[M] = true;
					if(i == 0) printf("%d", M);
					else printf(" %d", M);
					break;
				}
			}
			if(step >= MSize) {
				if(i != 0) printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}
