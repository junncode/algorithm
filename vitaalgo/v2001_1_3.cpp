#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

struct Point {
	int x, y;
};
vector<Point> seq;
typedef long long ll;

int ccw(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

ll dist(Point p1, Point p2) {
	ll d1 = (p1.x - p2.x);
	ll d2 = (p1.y - p2.y);
	return d1 * d1 + d2 * d2;
}

bool cmp(const Point& u, const Point& v) {
	int temp = ccw(seq[0], u, v);
	if (temp == 0) {
		return dist(seq[0], u) <= dist(seq[0], v);
	}
	else {
		return temp > 0;
	}
}

int main() {
	int n; cin >> n;
	seq.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> seq[i].x >> seq[i].y;
	}

	for (int i = 1; i < n; i++) 
		if (seq[i].y < seq[0].y || (seq[i].y == seq[0].y && seq[i].x < seq[0].x)) 
			swap(seq[0], seq[i]);

	sort(seq.begin() + 1, seq.end(), cmp);

	vector<Point> s;
	for (int i = 0; i < n; i++) {
		while (s.size() >= 2 && ccw(s[s.size() - 2], s[s.size() - 1], seq[i]) <= 0)
			s.pop_back();
		s.push_back(seq[i]);
	}
	cout << s.size();
}
