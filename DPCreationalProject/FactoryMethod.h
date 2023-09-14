#pragma once
#include <iostream>

class Unit
{
public:
	virtual void Info() = 0;
	virtual ~Unit() {}
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


class Factory
{
public:
	virtual Unit* Create() = 0;
	virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
public:
	Unit* Create() override
	{
		return new InfantryUnit();
	}
};

class ArcherFactory : public Factory
{
public:
	Unit* Create() override
	{
		return new ArcherUnit();
	}
};

class CavalryFactory : public Factory
{
public:
	Unit* Create() override
	{
		return new CavalryUnit();
	}
};


class SpearmanUnit : public Unit
{
public:
	void Info() override
	{
		std::cout << "Spearman\n";
	}
};

class SpearmanFactory : public Factory
{
public:
	Unit* Create() override
	{
		return new SpearmanUnit();
	}
};

