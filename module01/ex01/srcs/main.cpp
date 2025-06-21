#include "Zombie.hpp"

int main() {
    int N = ZOMBIE_HORDE_SIZE;

    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (horde == NULL) {
        std::cerr << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}