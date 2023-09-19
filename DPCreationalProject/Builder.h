#pragma once
#include <iostream>
#include <vector>

class IBuilder;
class InfantryBuilder;

class Unit 
{
protected:
	int attack;
	int defense;
public:
	int& Attack() { return attack; }
	int& Defense() { return defense; }

	Unit(int attack, int defense) 
		: attack{ attack }, defense{ defense } {};

	static IBuilder* GetBuilder() {};
};

class Infantry : public Unit
{
	std::string weapon;
	std::string armor;
	std::vector<std::string> addons;
public:
	Infantry() : Unit(10, 10)
	{
		weapon = "";
		armor = "";
	}

	std::string& Weapon() { return weapon; }
	std::string& Armor() { return armor; }
	std::vector<std::string>& Addons() { return addons; }

	std::string ToString()
	{
		std::string str_result = "Infantry:\n";
		str_result += "\tweapon: " + this->weapon + "\n";
		str_result += "\tarmor: " + this->armor + "\n";
		str_result += "\taddons:\n";
		for(auto addon : addons)
			str_result += "\t\t" + addon + "\n";

		return str_result;
	}

	static InfantryBuilder* GetBuilder();
};

class IBuilder
{
public:
	virtual IBuilder* SetNew() = 0;

	virtual IBuilder* SetWeapon(std::string weapon) = 0;
	virtual IBuilder* SetArmor(std::string armor) = 0;
	virtual IBuilder* SetAddon(std::string addon) = 0;

	virtual Unit* GetUnit() = 0;
};

class InfantryBuilder : public IBuilder
{
	Infantry* unit;
public:
	InfantryBuilder() : unit{ new Infantry() } {}

	InfantryBuilder* SetNew() override
	{
		unit = new Infantry();
		return this;
	}

	InfantryBuilder* SetWeapon(std::string weapon) override
	{
		unit->Weapon() = weapon;
		return this;
	}

	InfantryBuilder* SetArmor(std::string armor) override
	{
		unit->Armor() = armor;
		return this;
	}

	InfantryBuilder* SetAddon(std::string addon) override
	{
		unit->Addons().push_back(addon);
		return this;
	}

	Infantry* GetUnit() override
	{
		return unit;
	}
};

InfantryBuilder* Infantry::GetBuilder()
{
	return new InfantryBuilder();
};

