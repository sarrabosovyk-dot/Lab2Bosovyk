
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool inD(double x, double y) {
    bool leftCircle =
        (x + 2) * (x + 2) + (y - 1) * (y - 1) <= 1;

    bool rightCircle =
        (x - 3) * (x - 3) + y * y <= 2.25;

    bool r1 = x >= 0 && x <= 2 && y >= 1 && y <= 2;
    bool r2 = x >= 4 && x <= 5 && y >= 1 && y <= 2;
    bool r3 = x >= 4 && x <= 5 && y >= -2 && y <= -1;
    bool r4 = x >= 1 && x <= 2 && y >= -2 && y <= -1;
    bool r5 = x >= -3 && x <= -2 && y >= -2 && y <= -1;
    bool r6 = x >= -2 && x <= -1 && y >= -1 && y <= 0;

    return leftCircle || rightCircle ||
           r1 || r2 || r3 || r4 || r5 || r6;
}

int main() {
    double x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;

    if (!cin || !isfinite(x) || !isfinite(y)) {
        cout << "Invalid input.\n";
        return 1;
    }

    bool inside = inD(x, y);
    double u;

    if (inside) {
        u = y * y * x - sin(x);
    } else {
        double angle = sin(y - x) - 0.1;
        double rootArg = cos(x * y + 1);

        if (fabs(sin(angle)) < 1e-12 || rootArg < 0) {
            cout << "NO: x=" << x << " y=" << y
                 << ". Cannot calculate u.\n";
            return 0;
        }

        u = cos(angle) / sin(angle) - sqrt(rootArg);
    }

    if (!isfinite(u)) {
        cout << "Cannot calculate u.\n";
        return 0;
    }

    cout << (inside ? "YES: " : "NO: ")
         << fixed << setprecision(5)
         << "x=" << x << " y=" << y << " u=" << u << '\n';

    return 0;
}