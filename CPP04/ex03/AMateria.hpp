#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
// #include "Character.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        //TBD
        virtual AMateria* clone() const = 0;
        //TBD
        // virtual void use(ICharacter& target);
        //TBD
        ~AMateria();
};




#endif