#pragma once
#include <iostream>
#include <map>

/*
class Product
{
	int value;
public:
	Product(){}
	Product(int value) : value{ value } {};

	Product(const Product& product){}
};
*/

class IPrototype
{
public:
	virtual IPrototype* Clone() = 0;
};

enum UnitType
{
	Infantry,
	Archer,
	Cavalry
};

class Unit : public IPrototype
{
protected:
	std::string name;
public:
	std::string& Name() { return name; }
	Unit(std::string name) : name{ name } {}
	virtual std::string ToString()
	{
		return "Unit: " + name;
	}
	virtual ~Unit() {}
};

class IFactory
{
public:
	virtual Unit* CreateUnit() = 0;
};

// Infantry
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") {}
	IPrototype* Clone() override
	{
		return new InfantryUnit(*this);
	}
};

class InfantryFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

// Archer
class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") {}
	IPrototype* Clone() override
	{
		return new ArcherUnit(*this);
	}
};

class ArcherFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

// Cavalry
class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") {}
	IPrototype* Clone() override
	{
		return new CavalryUnit(*this);
	}
};

class CavalryFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};


class StroreClones
{
	std::map<UnitType, IPrototype*> clones;
public:
	IPrototype* GetClone(UnitType type)
	{
		auto it = clones.find(type);
		if (it != clones.end())
			return it->second->Clone();

		IFactory* factory = nullptr;
		
		switch (type)
		{
		case Infantry:
			factory = new InfantryFactory();
			break;
		case Archer:
			factory = new ArcherFactory();
			break;
		case Cavalry:
			factory = new CavalryFactory();
			break;
		default:
			break;
		}

		if (!factory) return nullptr;

		auto clone = (IPrototype*)factory->CreateUnit();
		auto clonePair = std::make_pair(type, clone);
		clones.insert(clonePair);
	}
};