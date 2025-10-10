#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} in version {} !\n", tea::PROJECT_NAME, tea::PROJECT_VER);
    for(int num = 0; num < argc; num++){
        fmt::println("argc[{}]: {} (Adresse: {})", num, argv[num], fmt::ptr(argv[num]));
    };

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
