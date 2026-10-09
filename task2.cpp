#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double h;
    cout << "Enter h; ";
    cin >> h;

    if (!cin || !isfinite(h)) {
        cout << "The task cannot be solved for this h.\n";
        return 1;
    }
    double cos1 = cos(h + 2);
    double cos2 = cos(h + 4);

    double a = exp(h) + sqrt(
        1 + h * h * cos1 * cos1 / 2.0
          + pow(h, 4) * pow(cos2, 4) / 24.0
    );

    if (!isfinite(a) || a <= 0) {
        cout << "The task cannot be solved: invalid a.\n";
        return 0;

    }
    double lnA = log(a);
    double cotH = cos(h) / sin(h);
    double b = lnA = sqrt(4 + cotH * cotH + lnA * lnA);

    // log(cosh(t)) у стабільній формі, щоб уникнути переповнення під час обчислення cosh(t).
    auto logCosh = [](double t) {
        double v = fabs(t);
        return v + log1p(exp(-2 * v)) - log(2);
    };

    double t = b * h;
    double logChBH = logCosh(t);

    // c = кубічний корінь з дробу + ln^4(cosh(a+b))
    double logFirst = (2 * log(a) + 4 * log(fabs(h))
                      + 2 * logCosh(t) - log(6.0)) / 3.0;
                    
    double first = 0;
    if (h != 0) {
        first = exp(logFirst);

    }

    double logTerm = logCosh(a + b);
    double second = pow(logTerm, 4);
    double c = first + second;
    
     if (!isfinite(a) || !isfinite(b) || !isfinite(c)) {
        cout << "The task cannot be solved: overflow.\n";
        return 0;
    }

    double d = b * b - 4 * a * c;

    cout << setprecision(10);
    cout << "a = " << a << "\nb = " << b << "\nc = " << c << '\n';

    if (!isfinite(d)) {
        cout << "The task cannot be solved: overflow in discriminant.\n";
    } else if (d < 0) {
        cout << "No real roots. D = " << d << '\n';
    } else if (fabs(d) < 1e-12) {
        cout << "One real root: x = " << -b / (2 * a) << '\n';
    } else {
        double rootD = sqrt(d);
        cout << "Two real roots:\n";
        cout << "x1 = " << (-b + rootD) / (2 * a) << '\n';
        cout << "x2 = " << (-b - rootD) / (2 * a) << '\n';
    }

    return 0;
}