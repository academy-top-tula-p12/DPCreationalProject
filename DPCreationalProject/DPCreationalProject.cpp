#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

//#include "ClassicSolution.h"
//#include "FactoryMethod.h"
//#include "AbstarctFactory.h"
//#include "Builder.h"
//#include "Prototype.h"
#include "Singleton.h"

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

/*
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
*/

//
//void BuilderExample()
//{
//	InfantryBuilder* infantryBuilder = Infantry::GetBuilder();
//
//	infantryBuilder->SetAddon("Dagger");
//	infantryBuilder->SetAddon("Flask");
//	infantryBuilder->SetWeapon("Sword");
//	infantryBuilder->SetArmor("Chain mail");
//
//	Infantry* infantry1 = infantryBuilder->GetUnit();
//
//	std::cout << infantry1->ToString() << "\n";
//
	//Infantry* infantry2 = infantryBuilder->SetNew()
	//	->SetArmor("Tunic")
	//	->SetWeapon("Spear")
	//	->SetAddon("Sling")
	//	->GetUnit();
//
//	//Infantry* infantry2 = infantryBuilder->GetUnit();
//
//	std::cout << infantry1->ToString() << "\n";
//	std::cout << infantry2->ToString() << "\n";
//}

//void PrototypeExample()
//{
//	class Army
//	{
//		std::string title;
//		std::vector<InfantryUnit*> infantries;
//		std::vector<ArcherUnit*> archers;
//		std::vector<CavalryUnit*> cavalries;
//	public:
//		Army(std::string title, int iCount, int aCount, int cCount)
//		{
//			IFactory* factory;
//
//			factory = new InfantryFactory();
//			for (int i = 0; i < iCount; i++)
//				infantries.push_back((InfantryUnit*)factory->CreateUnit());
//			delete factory;
//
//			factory = new ArcherFactory();
//			for (int i = 0; i < aCount; i++)
//				archers.push_back((ArcherUnit*)factory->CreateUnit());
//			delete factory;
//
//			factory = new CavalryFactory();
//			for (int i = 0; i < cCount; i++)
//				cavalries.push_back((CavalryUnit*)factory->CreateUnit());
//			delete factory;
//		}
//
//		Army(int iCount, int aCount, int cCount, std::string title)
//		{
//			StroreClones store;
//			for (int i = 0; i < iCount; i++)
//				infantries.push_back((InfantryUnit*)store.GetClone(UnitType::Infantry));
//			for (int i = 0; i < aCount; i++)
//				archers.push_back((ArcherUnit*)store.GetClone(UnitType::Archer));
//			for (int i = 0; i < cCount; i++)
//				cavalries.push_back((CavalryUnit*)store.GetClone(UnitType::Cavalry));
//		}
//
//		~Army()
//		{
//			infantries.clear();
//			archers.clear();
//			cavalries.clear();
//		}
//	};
//
//	const auto start1 = std::chrono::steady_clock::now();
//	Army army1("army1", 1000, 1000, 1000);
//	const auto end1 = std::chrono::steady_clock::now();
//	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << "\n";
//
//	const auto start2 = std::chrono::steady_clock::now();
//	Army army2(1000, 1000, 1000, "army2");
//	const auto end2 = std::chrono::steady_clock::now();
//	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << "\n";
//}


void ComputerLaunch(std::string title)
{
	Computer* computer = new Computer();

	computer->Lounch(title);
	std::cout << computer->System()->Title() << "\n";
}

int main()
{
	srand(time(nullptr));
	
	std::thread th1(ComputerLaunch, "Windows");
	std::thread th2(ComputerLaunch, "Linux");

	th1.join();
	th2.join();

	std::cout << "\n";

	system("pause");
}
