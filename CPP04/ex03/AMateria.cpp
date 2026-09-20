#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "none";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

std::string const & AMateria::getType() const
{
    return this->type;
}
AMateria::~AMateria()
{
}