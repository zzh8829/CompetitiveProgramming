class Point2D {
  int x, y;
  Point2D(int x, int y): x(x), y(y){}
  double dist2D(Point2D p) {
    return sqrt((p.x - x)*(p.x - x) +(p.y - y) * (p.y - y))
  }

  void printDistance(double d) {
    cout << "2D distance = " << ceil(d) << endl;
  }
}
