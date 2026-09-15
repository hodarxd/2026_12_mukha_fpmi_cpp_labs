#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double k;
    double x;
    double i = 0.0;
    
    std::cout << "Enter accuracy: ";
    std::cin >> k;
    std::cout << std::endl;
    std::cout << "Enter argument: ";
    std::cin >> x;

    double res = x;
    double step = x;

    double eps = std::pow(10, -k);

    while (std::fabs(step) > eps) {
        step = step * (x * x) / ((2.0 * i + 2.0) * (2.0 * i + 3.0));
        res += step;
        ++i;
    }

    std::cout << std::setprecision(k);
    std::cout << "sh(x) " << res << std::endl;
    std::cout << "cmathsh(x) " << std::sinh(x);

    return 0;
}