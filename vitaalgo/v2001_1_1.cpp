#include <cstdio>

typedef long long ll;

int main() {
	int N;
	scanf("%d", &N);
	
	for (int qn = 0; qn < N; qn++) {
		ll hx, hy, nx, ny, tx, ty, ccw;
		scanf("%lld %lld %lld %lld %lld %lld", &hx, &hy, &nx, &ny, &tx, &ty);
		
		ccw = (nx - hx) * (ty - hy) - (tx - hx) * (ny - hy);
		if (ccw == 0)
			printf("3\n");
		else if (ccw > 0)
			printf("1\n");
		else
			printf("2\n");
	}
	
	return 0;
}
