/*
 * TecManager.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "TecManager.h"
#include "DataSet.h"

TecManager::TecManager(string strName, float fSalary)
    : TecPartTime(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_TEC)
	  , Employee(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_TEC)
{
	// TODO Auto-generated constructor stub
	m_fSalary = fSalary;
}

TecManager::~TecManager()
{
	// TODO Auto-generated destructor stub
}

void TecManager::info()
{
	Employee::info();
	cout << "--工资:" << m_fSalary << endl;
}

void TecManager::setSalary()
{

}

void TecManager::addTecPartTime(uint uiId)
{
//	DataSet::getInstance().addTecPartTime(getId());
	string strName;
	cout << "请输入兼职技术人员的名字:";
	cin >> strName;
	if (0 == uiId)
	{
		uiId = getId();
	}
	TecPartTime *pTecPT = new TecPartTime(strName);
	pTecPT->setLeader(uiId);
	DataSet::getInstance().getTecPartMap().insert(
			PAIR_TECPART(pTecPT->getId(), pTecPT));
	cout << DataSet::getInstance().getTecPartMap().size() << endl;
}
void TecManager::delTecPartTimeById(uint uiId)
{
	if (0 == uiId)
	{
		cout << "请输入要删除的员工编号:";
		cin >> uiId;
	}
	MAP_TECPART::iterator iter;
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	iter = refMap.find(uiId);
	if (iter != refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "删除编号为:" << uiId << "的员工成功...\n";
	}
	else
	{
		cout << "没有编号为:" << uiId << "的员工...\n";
	}
}
void TecManager::modifyTecPartTime(uint uiId)
{

}
TecPartTime* TecManager::findTecPartTime(uint uiId)
{
	if (0 == uiId)
	{
		cout << "请输入要查找的兼职技术人员编号:";
		cin >> uiId;
	}
	TecPartTime* pTecPT = NULL;
	MAP_TECPART::iterator iter;
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	iter = refMap.find(uiId);
	if (iter != refMap.end())
	{
		pTecPT = iter->second;
	}
	return pTecPT;
}
void TecManager::displayTecPartTimeInfo()
{
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	cout << refMap.size() << endl;
	MAP_TECPART::iterator iter;
	iter = refMap.begin();
	for (; iter != refMap.end(); iter++)
	{
		iter->second->info();
	}
}

void TecManager::work()
{
	//增加对本身的操作即对下属的增删改查显示
}
