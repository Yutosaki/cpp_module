#include <exception>
#include <iostream>

#include "Array.h"

int main() {
    {
        std::cout << "=== test: index out of range ===\n";
        Array<int> a;
        try {
            std::cout << a[0] << '\n';
        } catch (const std::exception& e) {
            std::cerr << "caught: " << e.what() << '\n';
        }
    }

    {
        std::cout << "\n=== test: copy constructor & independence ===\n";
        Array<int> a(5, 4);
        Array<int> b = a;
        // ディープコピーのテスト
        std::cout << "init  a[0]=" << a[0] << ", b[0]=" << b[0] << '\n';
        a[0] = 3;
        b[0] = 2;
        std::cout << "after a[0]=" << a[0] << ", b[0]=" << b[0] << "\n";

        // 代入演算子テスト
        Array<int> c(5, 6);
        std::cout << "init  c[0]=" << c[0] << '\n';
        c = a;
        std::cout << "after c=a  c[0]=" << c[0] << " (a[0]=" << a[0] << ")\n";
        // ディープコピーテスト
        a[0] = 4;
        c[0] = 1;
        std::cout << "after c=a  c[0]=" << c[0] << " (a[0]=" << a[0] << ")\n";
    }

    {
        std::cout << "\n=== test: size ===\n";
        Array<int> a(5);
        std::cout << "size(a)= " << a.size() << '\n';
    }

    {
        std::cout << "\n=== test: subscript operator (rw/ro) ===\n";
        Array<int> a(5);
        const Array<int> b(5, 3);
        a[0] = 1;
        std::cout << "a[0]=" << a[0] << "  b[0]=" << b[0] << '\n';
    }
    return 0;
}
