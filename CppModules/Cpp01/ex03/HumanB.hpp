#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        HumanB(std::string name);
        HumanB(const HumanB&);
        virtual ~HumanB();
        HumanB &operator=(const HumanB& op);

        void        attack();
        void        setWeapon(Weapon& weapon);
    private:
        std::string _name;
		Weapon *_weapon;
};

#endif
