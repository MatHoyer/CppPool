#include "AMateria.hpp"

int main() {
  // Test default constructors
  IMateriaSource* src = new MateriaSource();
  ICharacter* me = new Character("me");
  ICharacter* bob = new Character("bob");

  // Test learning and creating materia
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  AMateria* tmpIce = src->createMateria("ice");
  AMateria* tmpCure = src->createMateria("cure");

  // Test equipping and using materia
  me->equip(tmpIce);
  me->use(0, *bob);

  me->equip(tmpCure);
  me->use(1, *bob);

  // Test Character copy constructor
  ICharacter* copyOfMe = new Character(*static_cast<Character*>(me));
  copyOfMe->use(0, *bob);
  copyOfMe->use(1, *bob);

  // Test Character assignment operator
  ICharacter* assignee = new Character("assignee");
  *static_cast<Character*>(assignee) = *static_cast<Character*>(me);
  assignee->use(0, *bob);
  assignee->use(1, *bob);

  // Test MateriaSource copy constructor
  IMateriaSource* copyOfSrc =
      new MateriaSource(*static_cast<MateriaSource*>(src));
  AMateria* copiedTmpIce = copyOfSrc->createMateria("ice");
  me->equip(copiedTmpIce);

  // Test MateriaSource assignment operator
  IMateriaSource* assigneeSrc = new MateriaSource();
  *static_cast<MateriaSource*>(assigneeSrc) = *static_cast<MateriaSource*>(src);
  AMateria* assignedTmpCure = assigneeSrc->createMateria("cure");
  me->equip(assignedTmpCure);

  // Cleanup and test destructor
  delete assigneeSrc;
  delete copyOfSrc;
  delete assignee;
  delete copyOfMe;
  delete bob;
  delete me;
  delete src;

  return 0;
}