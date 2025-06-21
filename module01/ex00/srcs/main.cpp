#include "Zombie.hpp"

int main() {
    std::cout << "Creating a zombie on the stack" << std::endl;
    Zombie stackZombie("StackZombie");
    stackZombie.announce();

    std::cout << "\nCreating a zombie on the heap" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    std::cout << "\nCalling randomChump:" << std::endl;
    randomChump("RandomChump");

    delete heapZombie;
    return 0;
}