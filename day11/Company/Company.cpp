/*
 * Company.cpp
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#include "Company.h"

Company::Company()
{
	// TODO Auto-generated constructor stub
	init();
}

Company::~Company()
{
	// TODO Auto-generated destructor stub
	m_file.writeDataToFile();
}

void Company::init()
{
	m_file.getDataFromFile();

	//若系统最开始运行，没有任何用户
	//则添加一个默认的老板
	cout << DataSet::getInstance().getBossMap().size() << endl;
	if (DataSet::getInstance().getBossMap().empty())
	{
		Boss *pBoss = new Boss;
		DataSet::getInstance().getBossMap().insert(
				PAIR_BOSS(pBoss->getId(), pBoss));
		cout << pBoss->getId() << ' ' << pBoss->getPWd() << endl;
	}
}

short Company::loginFace()
{
	cout << " 888 <-- ^_^ --> 666\n";
	cout << "1,兼职技术人员登录\n";
	cout << "2,技术经理登录\n";
	cout << "3,兼职销售人员登录\n";
	cout << "4,销售经理登录\n";
	cout << "5,老板登录\n";
	cout << "0,退出系统\n";
	cout << "请输入登入选项：";
	short num = -1;
	cin >> num;
	return num;
}
void Company::work()
{
	short num = -1;
	uint uiId = 0;
	string strPwd = "";
	while (1)
	{
		num = loginFace();

		cout << "请输入员工编号:";
		cin >> uiId;

		cout << "请输入密码:";
		cin >> strPwd;

		switch (num)
		{
		case 1: //兼职技术人员登录
		{
			TecPartTime *pTecPT = loginCompare<TecPartTime *>(uiId, strPwd, DataSet::getInstance().getTecPartMap());
			if (NULL != pTecPT)
			{
				pTecPT->work();
			}
			else
			{
				cout << "登入失败...\n";
			}
			break;
		}
		case 2: //技术经理登录
		{
			TecManager *pTecMa = loginCompare<TecManager *>(uiId, strPwd, DataSet::getInstance().getTecManagerMap());
			if (NULL != pTecMa)
			{
				pTecMa->work();
			}
			else
			{
				cout << "登入失败...\n";
			}
			break;
		}
		case 3: //兼职销售人员登录
		{
			SalePartTime *pSalePT = loginCompare<SalePartTime *>(uiId, strPwd, DataSet::getInstance().getSalePartMap());
			if (NULL != pSalePT)
			{
				pSalePT->work();
			}
			else
			{
				cout << "登入失败...\n";
			}
			break;
		}
		case 4: //销售经理登录
		{
			SaleManager *pSaleMa = loginCompare<SaleManager *>(uiId, strPwd, DataSet::getInstance().getSaleManagerMap());
			if (NULL != pSaleMa)
			{
				pSaleMa->work();
			}
			else
			{
				cout << "登入失败...\n";
			}
			break;
		}
		case 5: //老板登录
		{
			Boss *pBoss = loginCompare<Boss *>(uiId, strPwd, DataSet::getInstance().getBossMap());
			if (NULL != pBoss)
			{
				pBoss->work();
			}
			else
			{
				cout << "登入失败...\n";
			}
			break;
		}
		case 0: //退出系统
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
}
