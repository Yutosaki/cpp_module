#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# define ZOMBIE_HORDE_SIZE 5

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    ~Zombie();
    void announce();
    void setName(std::string newName);
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP