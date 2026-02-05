#include "../include/Base.h"

int main() {
    Base* something = generate();
    identify(something);
    identify(*something);
    delete (something);
}
