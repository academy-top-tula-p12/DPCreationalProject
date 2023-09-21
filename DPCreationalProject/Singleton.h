#pragma once
#include <iostream>
#include <mutex>

std::mutex m;

class Singleton
{
private:
	static Singleton* instance;
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton&) = delete;
public:
	static Singleton* GetInstance()
	{
		if (!instance)
			instance = new Singleton();
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;


class OperationSystem
{
	static OperationSystem* instance;
	std::string title;
	OperationSystem(std::string title) : title{ title } {};
public:
	std::string Title(){ return title; }

	static OperationSystem* GetSystem(std::string title)
	{
		std::lock_guard<std::mutex> l(m);
		if (!instance)
			instance = new OperationSystem(title);
		return instance;
	}
};
OperationSystem* OperationSystem::instance = nullptr;


class Computer
{
	OperationSystem* system;
public:
	OperationSystem*& System() { return system; }

	void Lounch(std::string title)
	{
		system = OperationSystem::GetSystem(title);
	}
};

