#pragma once
#include <iostream>

// base class product
class Unit
{
public:
	virtual std::string Info() = 0;
	virtual ~Unit() {}
};

// classes products

class InfantryUnit : public Unit
{
public:
	std::string Info() override
	{
		return "Infantry";
	}
};

class ArcherUnit : public Unit
{
public:
	std::string Info() override
	{
		return"Archer";
	}
};

class CavalryUnit : public Unit
{
public:
	std::string Info() override
	{
		return "Cavalry";
	}
};

class OriginUnit : public Unit
{
public:
	std::string Info() override
	{
		return "";
	}
};


// concrete products
// rome units
class RomeInfantryUnit : public InfantryUnit
{
public:
	std::string Info() override
	{
		return "Rome " + InfantryUnit::Info();
	}
};

class RomeArcherUnit : public ArcherUnit
{
public:
	std::string Info() override
	{
		return "Rome " + ArcherUnit::Info();
	}
};

class RomeCavalryUnit : public CavalryUnit
{
public:
	std::string Info() override
	{
		return "Rome " + CavalryUnit::Info();
	}
};

class RomeOriginUnit : public OriginUnit
{
public:
	std::string Info() override
	{
		return "Rome Chariot";
	}
};

// carthagens units
class CarthagenInfantryUnit : public InfantryUnit
{
public:
	std::string Info() override
	{
		return "Crathagen " + InfantryUnit::Info();
	}
};

class CarthagenArcherUnit : public ArcherUnit
{
public:
	std::string Info() override
	{
		return "Crathagen " + ArcherUnit::Info();
	}
};

class CarthagenCavalryUnit : public CavalryUnit
{
public:
	std::string Info() override
	{
		return "Crathagen " + CavalryUnit::Info();
	}
};

class CarthagenOriginUnit : public OriginUnit
{
public:
	std::string Info() override
	{
		return "Crathagen Elephant";
	}
};


// abstarct factory
class ArmyFactory
{
public:
	virtual InfantryUnit* InfantryCreate() = 0;
	virtual ArcherUnit* ArcherCreate() = 0;
	virtual CavalryUnit* CavalryCreate() = 0;
	virtual OriginUnit* OriginCreate() = 0;

	virtual ~ArmyFactory() {}
};

// rome army factory
class RomeArmyFactory : public ArmyFactory
{
public:
	InfantryUnit* InfantryCreate() override
	{
		return new RomeInfantryUnit();
	}

	ArcherUnit* ArcherCreate() override
	{
		return new RomeArcherUnit();
	}

	CavalryUnit* CavalryCreate() override
	{
		return new RomeCavalryUnit();
	}

	OriginUnit* OriginCreate() override
	{
		return new RomeOriginUnit();
	}
};

// carthagen army factory
class CarthagenArmyFactory : public ArmyFactory
{
public:
	InfantryUnit* InfantryCreate() override
	{
		return new CarthagenInfantryUnit();
	}

	ArcherUnit* ArcherCreate() override
	{
		return new CarthagenArcherUnit();
	}

	CavalryUnit* CavalryCreate() override
	{
		return new CarthagenCavalryUnit();
	}
	OriginUnit* OriginCreate() override
	{
		return new CarthagenOriginUnit();
	}

};