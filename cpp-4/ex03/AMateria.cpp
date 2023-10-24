#include "AMateria.hpp"
#include <iterator>
#include <string>

// ---------------------Materia---------------------
// ---------------------AMateria---------------------
AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "[AMateria] default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	this->_type = other.getType();
	std::cout << "[AMateria] copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria& other) {
	this->_type = other.getType();
	std::cout << "[AMateria] assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] destructor called" << std::endl;
}

std::string const & AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "[Amateria] Materia not set yet" << std::endl;
}

// ---------------------Ice---------------------
Ice::Ice() : AMateria("ice") {
	std::cout << "[Ice] default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "[Ice] copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice& other) {
	this->_type = other.getType();
	std::cout << "[Ice] assignment operator called" << std::endl;
	return *this;
}

AMateria* Ice::clone() const {
	std::cout << "[Ice] clone() called" << std::endl;
	return new Ice(*this);
}

Ice::~Ice() {
	std::cout << "[Ice] destructor called" << std::endl;
}

void Ice::use(ICharacter& target) {
	std::cout << "[Ice] * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// ---------------------Cure---------------------
Cure::Cure() : AMateria("cure") {
	std::cout << "[Cure] default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "[Cure] copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure& other) {
	this->_type = other.getType();
	std::cout << "[Cure] assignment operator called" << std::endl;
	return *this;
}

AMateria* Cure::clone() const {
	std::cout << "[Cure] clone() called" << std::endl;
	return new Cure(*this);
}

Cure::~Cure() {
	std::cout << "[Cure] destructor called" << std::endl;
}

void Cure::use(ICharacter& target) {
	std::cout << "[Cure] * heals " << target.getName() << "'s wounds *" << std::endl;
}

// ---------------------MateriaSource---------------------
MateriaSource::MateriaSource() {
	this->index = 0;
	for (int i = 0; i < 4; i++)
		this->know[i] = NULL;
	std::cout << "[MateriaSource] default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	this->index = other.index;
	for (int i = 0; i < 4; i++) {
		if (other.know[i])
			this->know[i] = other.know[i]->clone();
		else
			this->know[i] = NULL;
	}
	std::cout << "[MateriaSource] copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other) {
	this->index = other.index;
	for (int i = 0; i < 4; i++) {
		if (this->know[i])
			delete this->know[i];
		this->know[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (other.know[i])
			this->know[i] = other.know[i]->clone();
	}
	std::cout << "[MateriaSource] assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->know[i]) {
			delete this->know[i];
			this->know[i] = NULL;
		}
	}
	std::cout << "[MateriaSource] destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* newM) {
	if (newM == NULL) {
		std::cout << "[MateriaSource] ERROR: Can not learn a NULL AMateria" << std::endl;
		return ;
	}
	delete this->know[this->index];
	this->know[this->index] = newM;
	if (this->index == 3)
		this->index = 0;
	else
		++index;
	std::cout << "[MateriaSource] AMateria learned" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->know[i]->getType().compare(type) == 0) {
			std::cout << "[MateriaSource] AMateria created" << std::endl;
			return this->know[i]->clone();
		}
	}
	std::cout << "[MateriaSource] ERROR: No AMateria learned for this type" << std::endl;
	return NULL;
}

// ---------------------Character---------------------
Character::Character(std::string name) : _name(name) {
	this->index = 0;
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	std::cout << "[Character] default constructor called" << std::endl;
}

Character::Character(const Character& other) {
	this->_name = other.getName();
	this->index = other.index;
	for (int i = 0; i < 4; i++) {
		if (other.inv[i])
			this->inv[i] = other.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
	std::cout << "[Character] copy constructor called" << std::endl;
}

Character &Character::operator=(const Character& other) {
	this->_name = other.getName();
	this->index = other.index;
	for (int i = 0; i < 4; i++) {
		if (this->inv[i]) {
			delete this->inv[i];
			this->inv[i] = NULL;
		}
		if (other.inv[i])
			this->inv[i] = other.inv[i]->clone();
	}
	std::cout << "[Character] assignment operator called" << std::endl;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inv[i]) {
			delete this->inv[i];
			this->inv[i] = NULL;
		}
	}
	std::cout << "[Character] destructor called" << std::endl;
}

std::string const & Character::getName() const { return this->_name; }

void	Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "[Character] ERROR: Can not equip NULL AMateria" << std::endl;
		return ;
	}
	if (this->inv[this->index])
		delete this->inv[this->index];
	this->inv[this->index] = m;
	if (this->index == 3)
		this->index = 0;
	else
		++this->index;
	std::cout << "[Character] AMateria equiped" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "[Character] ERROR: Bad index in Character::unequip" << std::endl;
		return ;
	}
	if (this->inv[idx])
		delete this->inv[idx];
	this->inv[idx] = NULL;
	std::cout << "[Character] AMateria unequiped" << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "[Character] ERROR: Bad index in Character::use" << std::endl;
		return ;
	}
	if (this->inv[idx] == NULL) {
		std::cout << "[Character] ERROR: Can not use a NULL AMateria" << std::endl;
		return ;
	}
	this->inv[idx]->use(target);
}