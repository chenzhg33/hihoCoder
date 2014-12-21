#include <iostream>
#include <utility>
using namespace std;
struct Point {
	int x, y;
	bool operator==(Point p) {
		return x == p.x && y == p.y;
	}
	Point() {}
	Point(int x1, int y1) : x(x1), y(y1) {}
};
struct Segment {
	Point p1, p2;
} seg[4];
int cross(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

bool is_Rec() {
	int i, j;
	for (i = 0; i < 4; ++i) {
		if (seg[i].p1 == seg[i].p2)
			return false;
	}
	Point b = seg[0].p1;
	Point four[4];
	four[0] = b;
	for (i = 1; i < 4; ++i) {
		for (j = i; j < 4; ++j) {
			if (seg[j].p1 == b) {
				b = seg[j].p2;
				four[i] = b;
				swap(seg[j], seg[i]);
				break;
			} else if (seg[j].p2 == b) {
				b = seg[j].p1;
				four[i] = b;
				swap(seg[j], seg[i]);
				break;
			}
		}
		if (j == 4) return false;
	}
	if (!(b == seg[0].p2)) return false;
	for (int i = 0; i < 4; ++i) {
		Point a(four[i].x - four[(i+1)%4].x, four[i].y - four[(i+1)%4].y);
		Point b(four[(i+2)%4].x - four[(i+1)%4].x, four[(i+2)%4].y - four[(i+1)%4].y);
		if (cross(a, b) != 0) return false;
		//cout << four[i].x << ',' << four[i].y << endl;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 4; ++i) {
			cin >> seg[i].p1.x >> seg[i].p1.y;
			cin >> seg[i].p2.x >> seg[i].p2.y;
		}
		if(is_Rec())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}
