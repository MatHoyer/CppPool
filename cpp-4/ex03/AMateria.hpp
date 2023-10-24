#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

// ---------------------Materia---------------------
class AMateria {
	protected:
		std::string _type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria &operator=(const AMateria& other);
		virtual ~AMateria();
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		Ice &operator=(const Ice& other);
		~Ice();

		void use(ICharacter& target);
		AMateria* clone() const;
};

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure &operator=(const Cure& other);
		~Cure();

		void use(ICharacter& target);
		AMateria* clone() const;
	
};

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource &operator=(const MateriaSource& other);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		int index;
		AMateria *know[4];
};

// ---------------------Character---------------------
class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	public:
		Character(std::string name);
		Character(const Character& other);
		Character &operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		int index;
		AMateria *inv[4];

};

#endif