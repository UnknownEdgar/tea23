#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar1;
int globalVar2 = 0;
int globalVar3 = 100;
static int globalVar4;
static int globalVar5 = 0;
static int globalVar6 = 100;
// const int globalVar7;
const int globalVar8 = 0;
const int globalVar9 = 100;

int main(int argc, char **argv) {

    int localVar1 = 2;
    static int localVar2 = 2;
    const int localVar3 = 2;

    fmt::println("Hello, {}!\n", tea::PROJECT_NAME);
    
    fmt::println("Der Wert von globalVar1: {}, die Adresse von globalVar1: {}", globalVar1, fmt::ptr(&globalVar1));
    fmt::println("Der Wert von globalVar2: {}, die Adresse von globalVar2: {}", globalVar2, fmt::ptr(&globalVar2));
    fmt::println("Der Wert von globalVar3: {}, die Adresse von globalVar3: {}", globalVar3, fmt::ptr(&globalVar3));
    fmt::println("Der Wert von static globalVar4: {}, die Adresse von globalVar4: {}", globalVar4, fmt::ptr(&globalVar4));
    fmt::println("Der Wert von static globalVar5: {}, die Adresse von globalVar5: {}", globalVar5, fmt::ptr(&globalVar5));
    fmt::println("Der Wert von static globalVar6: {}, die Adresse von globalVar6: {}", globalVar6, fmt::ptr(&globalVar6));
    // fmt::println("Der Wert von const globalVar7: {}, die Adresse von globalVar7: {}", globalVar7, fmt::ptr(&globalVar7));
    fmt::println("Der Wert von const globalVar8: {}, die Adresse von globalVar8: {}", globalVar8, fmt::ptr(&globalVar8));
    fmt::println("Der Wert von const globalVar9: {}, die Adresse von globalVar9: {}", globalVar9, fmt::ptr(&globalVar9));
    fmt::println("Der Wert von localVar1: {}, die Adresse von localVar1: {}", localVar1, fmt::ptr(&localVar1));
    fmt::println("Der Wert von static localVar2: {}, die Adresse von localVar2: {}", localVar2, fmt::ptr(&localVar2));
    fmt::println("Der Wert von const localVar3: {}, die Adresse von localVar3: {}", localVar3, fmt::ptr(&localVar3));

    return 0; /* exit gracefully*/
}
