#pragma once
#include <iostream>

enum UnitType
{
	Infantry,
	Archer,
	Cavalry
};

class Unit
{
public:
	virtual void Info() = 0;
	virtual ~Unit(){}
};

class InfantryUnit : public Unit
{
public:
	void Info() override
	{
		std::cout << "Infantry\n";
	}
};

class ArcherUnit : public Unit
{
public:
	void Info() override
	{
		std::cout << "Archer\n";
	}
};

class CavalryUnit : public Unit
{
public:
	void Info() override
	{
		std::cout << "Cavalry\n";
	}
};



