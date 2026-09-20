# ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        /* data */
    public:
        Cure();
        AMateria *clone() const;
        // void use(ICharacter& target);
        ~Cure();
};




#endif