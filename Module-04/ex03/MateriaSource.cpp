#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (copy._templates[i])
            _templates[i] = copy._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    std::cout << "Copy assignment called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_templates[i])
                delete _templates[i];
            if (copy._templates[i])
                _templates[i] = copy._templates[i]->clone();
            else
                _templates[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "Destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (_templates[i])
            delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_templates[i])
        {
            _templates[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return (_templates[i]->clone());
    }
    return (NULL);
}