#include <iostream>
#include <vector>

//#include "ClassicSolution.h"
//#include "FactoryMethod.h"
#include "AbstarctFactory.h"

/* Classic object function factory
Unit* CreateUnit(UnitType type)
{
    Unit* unit;
	switch (type)
	{
	case Infantry:
		unit = new InfantryUnit();
		break;
	case Archer:
		unit = new ArcherUnit();
		break;
	case Cavalry:
		unit = new CavalryUnit();
		break;
	default:
		unit = nullptr;
	}

	return unit;
}
*/

/*
void FactoryMethodExample()
{
	std::vector<Factory*> factories;
	factories.push_back(new InfantryFactory());
	factories.push_back(new ArcherFactory());
	factories.push_back(new CavalryFactory());
	factories.push_back(new SpearmanFactory());

	int size{ 10 };
	std::vector<Unit*> army;
	for (int i = 0; i < size; i++)
		army.push_back(factories[rand() % factories.size()]->Create());

	for (auto item : army)
		item->Info();
}
*/

void AbstarctFactoryExample()
{
	class Army
	{
	public:
		std::vector<InfantryUnit*> Infantries;
		std::vector<ArcherUnit*> Archers;
		std::vector<CavalryUnit*> Cavalries;
		std::vector<OriginUnit*> Origins;
		int Size;

		ArmyFactory* Factory = nullptr;

		Army(ArmyFactory* factory, int size = 5) : Size{ size }, Factory{ factory }
		{
			for (int i = 0; i < Size; i++)
				Infantries.push_back(Factory->InfantryCreate());
			for (int i = 0; i < Size; i++)
				Archers.push_back(Factory->ArcherCreate());
			for (int i = 0; i < Size; i++)
				Cavalries.push_back(Factory->CavalryCreate());
			for (int i = 0; i < Size; i++)
				Origins.push_back(Factory->OriginCreate());
		}

		std::string Info()
		{
			std::string result = "";
			for (auto infatry : Infantries)
				result += infatry->Info() + "\n";
			for (auto archer : Archers)
				result += archer->Info() + "\n";
			for (auto cavalry : Cavalries)
				result += cavalry->Info() + "\n";
			for (auto origin : Origins)
				result += origin->Info() + "\n";
			return result;
		}

		~Army()
		{
			for (auto infatry : Infantries)
				delete infatry;
			for (auto archer : Archers)
				delete archer;
			for (auto cavalry : Cavalries)
				delete cavalry;
			for (auto origin : Origins)
				delete origin;
		}
	};
	
	Army* romeArmy = new Army(new RomeArmyFactory());
	Army* carthagenArmy = new Army(new CarthagenArmyFactory());

	std::cout << romeArmy->Info() << "\n";
	std::cout << carthagenArmy->Info() << "\n";
}



int main()
{
	srand(time(nullptr));
	
	
}
