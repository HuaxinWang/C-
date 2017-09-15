/*
 * Boss.cpp
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#include "Boss.h"
#include "DataSet.h"

Boss::Boss(string strName) :
		Employee(strName, ENUM_EMPLOYEE_LEVEL_BOSS), TecManager(strName), SaleManager(
				strName)
{
	// TODO Auto-generated constructor stub

}

Boss::~Boss()
{
	// TODO Auto-generated destructor stub
}

void Boss::info()
{
	Employee::info();
}

void Boss::addTecManager()
{
	string strName;
	cout << "请输入技术经理的名字:";
	cin >> strName;
	TecManager *pTecMa = new TecManager(strName);
	DataSet::getInstance().getTecManagerMap().insert(
			PAIR_TECMA(pTecMa->getId(), pTecMa));
}
void Boss::delTecManager(uint uiId)
{
	if (0 == uiId)
	{
		cout << "请输入要删除的技术经理的id:";
		cin >> uiId;
	}
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	MAP_TECMA::iterator iter = refMap.find(uiId);
	if (iter != refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "删除编号为:" << uiId << "的技术经理成功" << endl;
	}
	else
	{
		cout << "没有编号为:" << uiId << "的技术经理" << endl;
	}
}
void Boss::modifyTecManager(uint uiId)
{
}
TecManager* Boss::findTecManager(uint uiId)
{
	if (0 == uiId)
	{
		cout << "请输入要查找的技术经理编号:";
		cin >> uiId;
	}
	TecManager* pTecMa = NULL;
	MAP_TECMA::iterator iter;
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	iter = refMap.find(uiId);
	if (iter != refMap.end())
	{
		pTecMa = iter->second;
	}
	return pTecMa;
}
void Boss::displayTecManager()
{
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	MAP_TECMA::iterator iter = refMap.begin();
	for (; iter != refMap.end(); iter++)
	{
		iter->second->info();
	}
}

short Boss::bossFace()
{
	//大家加上对技术的删改查，对销售的增删改查显示
	cout << " 888<-- ^_^ -->888\n";
	cout << "1,增加技术经理\n";
	cout << "2,显示技术经理\n";
	cout << "3,增加兼职技术人员\n";
	cout << "4,显示兼职技术人员\n";
	cout << "0,返回\n";
    cout << "请输入选项:";
    short num = 0;
    cin >> num;
    return num;
}

void Boss::work()
{
	cout << "欢迎" << getName() << "登入" << endl;
	short num = 0;
	while (1)
	{
		num = bossFace();
		switch (num)
		{
		case 1: //增加技术经理
			addTecManager();
			break;
		case 2: //显示技术经理
			displayTecManager();
			break;
		case 3: //增加兼职技术人员
			break;
		case 4: //显示兼职技术人员
			break;
		case 0: //返回
			return;
		default:
			break;
		}
	}

}
