# 42cpp-module-05

### ex03
- 同じ base class からできた複数個の derived class に1つのメソッドでアクセスする

### ex02
- 同じ base class からの複数個の derived class

### ex01
- 複数個の exception
  - 上手にエラーハンドリング
- nested classes
  - [その13 内部クラスは外側クラスのメンバにアクセスし放題！](http://marupeke296.com/CPP_No13_SubClass.html)
  - [そろそろ内部クラスに関して一言言っておくか](http://isoparametric.hatenablog.com/entry/20080117/1200575103)
      ```c++
      #include <iostream>

      class Hoge {
       public:
          Hoge() : bar_(*this) {}

       private:
          class Bar {
           public:
              explicit Bar(Hoge& hoge) : hoge_(hoge) {}
              void func() {
                  hoge_.func();
              }
              Hoge& hoge_;
          };
          Bar bar_;
          void func() {
              std::cout << "func" << std::endl;
          }

       public:
          Bar& Bar() { return bar_; }
      };

      int main() {
          Hoge hoge;
          hoge.Bar().func();
          return 0;
      }
      ```
  - [Why would one use nested classes in C++?](https://stackoverflow.com/questions/4571355/why-would-one-use-nested-classes-in-c)
  - [Why is a type qualifier on a return type meaningless?](https://stackoverflow.com/questions/1607188/why-is-a-type-qualifier-on-a-return-type-meaningless)


### ex00
- [std::exception](https://cpprefjp.github.io/reference/exception/exception.html)
  - `exception` クラスは，標準ライブラリが提供する全ての例外クラスの基底クラス．
- nested classes
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
- [Weird error on 'exception specification of overriding function is more lax than base version' in C++](https://stackoverflow.com/questions/59919357/weird-error-on-exception-specification-of-overriding-function-is-more-lax-than)
- [exception specification of overriding function is more lax than base version](https://stackoverflow.com/questions/53829852/exception-specification-of-overriding-function-is-more-lax-than-base-version/53829972)
