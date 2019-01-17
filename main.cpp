#include <iostream>
using namespace std;


struct A {

    virtual ~A() {
        log ("A", "~A");
    }

    void f() {
        log("A", "f");
    }

    virtual void g() = 0;

    static void log(const string s1, const string s2) {
        cout << s1 << ":" << s2 << "\n";
    }
};
struct B : A{
        ~B() {
            log ("B", "~B");
        }
        void f () {
            log ("B", "f");
        }
        void g () {
            log ("B", "g");
        }
};

struct C : B {
        virtual ~C() {
            log ("C", "~C");
        }
        virtual void f () {
            log ("C", "f");
        }
        virtual void g () {
            log ("C", "g");
        }
};

int main() {

    A::log ("Log", "Test");         // Log: Test
    B b;                            //
    A* ab = &b;                     //
    B* bc = new C ();

    cout << "ab->f(): ";  ab->f();  // ab->f(): A:f
    cout << "ab->g(): ";  ab->g();  // ab->g(): B:g
    cout << "bc->f(): ";  bc->f();  // bc->f(): B:f
    cout << "bc->g(): ";  bc->g();  // bc->g(): C:g

    cout << "Ende\n";               // Ende
    return 0;                       // B :~B A:~A
}
/*
 * Log::Test
 * ab->f(: A::f
 */