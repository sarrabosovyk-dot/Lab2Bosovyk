#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, d;
    cout << "Enter a, b, c, d: ";
    cin >> a >> b >> c >> d;

    if (!cin || !isfinite(a) || !isfinite(b) ||
        !isfinite(c) || !isfinite(d)) {
        cout << "It is impossible to calculate z.\n";
        return 1;
    }

    double argX = fabs(cos(a * a * (c + 1))
                       + sin(M_PI * d + a));

    double x = sqrt(argX);

    double sinB = sin(b);
    if (fabs(cos(b)) < 1e-12) {
        cout << "It is impossible to calculate z: tg(b) is undefined.\n";
        return 0;
    }

    double sinED = sin(exp(d));
    if (fabs(sinED) < 1e-12) {
        cout << "It is impossible to calculate z: ctg(e^d) is undefined.\n";
        return 0;
    }

    double y = tan(b) - c * sqrt(16 + cos(exp(d)) / sinED);

    double z;
    if (y > 0) {
        double denominator = 1 + sin(x) * sin(x);
        z = (x * x - 1) / denominator;
    } else {
        double numeratorArg = fabs(y * y * y - x * x * x * x + 1);
        z = sqrt(numeratorArg) / (1 - y);
    }

    if (!isfinite(x) || !isfinite(y) || !isfinite(z)) {
        cout << "It is impossible to calculate z.\n";
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << '\n';

    return 0;
}