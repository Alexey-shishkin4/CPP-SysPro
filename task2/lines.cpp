#include <iostream>
#include <optional>
#include <cmath>


struct Point {
    double x, y;

    Point(double x_, double y_) : x(x_), y(y_) {}
};


bool equals(double a, double b, double tolerance = 1e-9) {
    return std::fabs(a - b) < tolerance;
}


class Line {
private:
    double a, b, c; // ax + by + c = 0

    bool isValid() const {
        return !(std::isnan(a) || std::isnan(b) || std::isnan(c));
    }

public:
    Line(const Point& p1, const Point& p2) {
        if (equals(p1.x, p2.x) && equals(p1.y, p2.y)) {
            a = b = c = std::nan("1");
        }
        else {
            a = p2.y - p1.y;
            b = p1.x - p2.x;
            c = -(a * p1.x + b * p1.y);
        }
    }

    std::optional<Point> intersection(const Line& other) const {
        if (!isValid()) {
            return std::nullopt;
        }

        double det = a * other.b - other.a * b;
        if (equals(det, 0)) {
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
        if (isValid()) {
            std::cout << a << "x + " << b << "y + " << c << " = 0" << std::endl;
        }
        else {
            std::cout << "Invalid line!" << std::endl;
        }
    }

    bool operator==(const Line& other) const {
        return equals(a, other.a) && equals(b, other.b) && equals(c, other.c);
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
    }
    else {
        std::cout << "No intersection (parallel lines).\n";
    }

    Line perp = line1.perpendicularAt(Point(2, 2));
    std::cout << "Perpendicular to Line 1 through (2,2): ";
    perp.print();

    Line invalidLine(Point(1, 1), Point(1, 1));
    std::cout << "Invalid line: ";
    invalidLine.print();

    return 0;
}
