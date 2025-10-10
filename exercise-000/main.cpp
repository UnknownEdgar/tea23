#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value){
    value = 99;
    fmt::println("ValueByPara: {}", value);
}

void changeValueByPointer(int* ptr){
    *ptr = 77;
    fmt::println("ValueByPtr: {}", *ptr);
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    /*  Task 0
    fmt::print("Hello, {} in version {} !\n", tea::PROJECT_NAME, tea::PROJECT_VER);
    for(int num = 0; num < argc; num++){
        fmt::println("argc[{}]: {} (Adresse: {})", num, argv[num], fmt::ptr(argv[num]));
    };
    */

    /*  Task 1 
    int x = 10;
    int* p = &x;
    fmt::println("x: {} (Adresse: {})\np: {} (Adresse: {})", x, fmt::ptr(&x), *p, fmt::ptr(p));
    *p = 42;
    fmt::println("x: {} (Adresse: {})\np: {} (Adresse: {})", x, fmt::ptr(&x), *p, fmt::ptr(p));
    */

    /*  Task 2
    double* d = new double(3.1415);
    fmt::println("d: {} (Adresse: {})", *d, fmt::ptr(d));
    delete d;
    */
    
    int y = 5;
    fmt::println("y: {}",y);
    changeValueByParameter(y);
    fmt::println("y: {}",y);
    changeValueByPointer(&y);
    fmt::println("y: {}",y);

    return 0; /* exit gracefully*/
}
