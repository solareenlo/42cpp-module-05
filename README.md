# 42cpp-module-05

### ex00
- [std::exception](https://cpprefjp.github.io/reference/exception/exception.html)
  - `exception` クラスは，標準ライブラリが提供する全ての例外クラスの基底クラス．
- class の入れ子
- [Static constant string (class member)](https://stackoverflow.com/questions/1563897/static-constant-string-class-member)
  - Before C++17
    ```c++
    // *.hpp
    class A {
    private:
      static const string RECTANGLE;
    };
    // *.cpp
    const string A::RECTANGLE = "rectangle";
    ```
  - After C++17
    ```c++
    // *.hpp
    class A {
    private:
      inline static const string RECTANGLE = "rectangle";
    };
    ```
