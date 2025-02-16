#include <iostream>
#include <optional>

struct Point {
    double x, y;
    
    Point(double x_, double y_) : x(x_), y(y_) {}
};

class Line {
private:
    double a, b, c; // ax + by + c = 0

public:
    Line(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    Line(const Point& p1, const Point& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a * p1.x + b * p1.y);
    }

    std::optional<Point> intersection(const Line& other) const {
        double det = a * other.b - other.a * b;
        if (det == 0) {
            return std::nullopt;
        }
        double x = (other.b * (-c) - b * (-other.c)) / det;
        double y = (a * (-other.c) - other.a * (-c)) / det;
        return Point(x, y);
    }

    Line perpendicularAt(const Point& p) const {
        return Line(-b, a, b * p.x - a * p.y);
    }

    void print() const {
        std::cout << a << "x + " << b << "y + " << c << " = 0" << std::endl;
    }
};


int main() {
    Point p1(0, 0), p2(4, 4);
    Line line1(p1, p2);
    
    Point p3(0, 4), p4(4, 0);
    Line line2(p3, p4);

    std::cout << "Line 1: ";
    line1.print();
    std::cout << "Line 2: ";
    line2.print();

    auto inter = line1.intersection(line2);
    if (inter) {
        std::cout << "Intersection: (" << inter->x << ", " << inter->y << ")\n";
    } else {
        std::cout << "No intersection (parallel lines).\n";
    }

    Line perp = line1.perpendicularAt(Point(2, 2));
    std::cout << "Perpendicular to Line 1 through (2,2): ";
    perp.print();

    return 0;
}