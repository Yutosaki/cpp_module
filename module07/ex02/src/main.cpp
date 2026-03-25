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
    {
        std::cout << "\n=== extra test: advanced out of range ===\n";
        Array<int> a(5);  // インデックスは 0, 1, 2, 3, 4 が有効

        // 1. 境界値テスト（最大インデックスの直後）
        try {
            std::cout << "accessing a[5] (size is 5)... ";
            std::cout << a[5] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "caught: " << e.what() << '\n';
        }

        // 2. 非常に大きなインデックス
        try {
            std::cout << "accessing a[9999]... ";
            std::cout << a[9999] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "caught: " << e.what() << '\n';
        }

        // 3. constオブジェクトでの範囲外アクセス
        // (const版のoperator[]が正しく例外を投げるかの確認)
        const Array<int> const_a(3, 10);
        try {
            std::cout << "accessing const_a[3] (size is 3)... ";
            std::cout << const_a[3] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "caught: " << e.what() << '\n';
        }

        // 4. size_tのラップアラウンド（負の数をキャストした場合のシミュレーション）
        // size_tに -1 を渡すと非常に大きな数になりますが、i >= size_ で防げるはずです。
        try {
            std::cout << "accessing a[(size_t)-1]... ";
            std::cout << a[static_cast<size_t>(-1)] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "caught: " << e.what() << '\n';
        }
    }
    return 0;
}
