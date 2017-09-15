/*
 * FileOpe.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "FileOpe.h"

#include "DataSet.h"

FileOpe::FileOpe()
{
	// TODO Auto-generated constructor stub

}

FileOpe::~FileOpe()
{
	// TODO Auto-generated destructor stub
}

bool FileOpe::openFileForWrite(string strFile)
{
	bool bOk = false;
	if (m_outFile.is_open())
	{
		bOk = true;
	}
	else
	{
		m_outFile.open(strFile.c_str());
		bOk = m_outFile.is_open();
	}
	return bOk;
}

void FileOpe::closeWriteFile()
{
	if (m_outFile.is_open())
	{
		m_outFile.close();
	}
}

bool FileOpe::openFileForRead(string strFile)
{
	m_inFile.open(strFile.c_str());
	bool bOk = m_inFile.is_open();
	return bOk;
}

void FileOpe::closeReadFile()
{
	if (m_inFile.is_open())
	{
		m_inFile.close();
	}
}

void FileOpe::writeEmployeeToFile(const Employee &ref)
{
	m_outFile << ref.getId() << ' ' << ref.getName() << ' ' << ref.getLevel()
			<< ' ' << ref.getPWd() << ' ' << ref.getNote() << endl;
}

void FileOpe::writeTecPartTimeToFile(const TecPartTime &ref)
{
	writeEmployeeToFile(ref);
	m_outFile << ref.getPerHourPay() << ' ' << ref.getWorkHour() << ' '
			<< ref.getLeader() << endl;
}
void FileOpe::writeTecManagerToFile(const TecManager &ref)
{
	writeEmployeeToFile(ref);
	m_outFile << ref.getSalary() << endl;
}

void FileOpe::writeSalePartTimeToFile(const SalePartTime &ref)
{

}
void FileOpe::writeSaleManagerToFile(const SaleManager &ref)
{

}

void FileOpe::writeBossToFile(const Boss &ref)
{
	writeEmployeeToFile(ref);
}

void FileOpe::readEmployeeFromFile(Employee &ref)
{
	m_inFile >> ref.getId() >> ref.getName() >> ref.getLevel() >> ref.getPWd()
			>> ref.getNote();
}

void FileOpe::readTecPartTimeFromFile(TecPartTime &ref)
{
	readEmployeeFromFile(ref);
	m_inFile >> ref.getPerHourPay() >> ref.getWorkHour() >> ref.getLeader();
}
void FileOpe::readTecManagerFromFile(TecManager &ref)
{
	readEmployeeFromFile(ref);
	m_inFile >> ref.getSalary();
}

void FileOpe::readSalePartTimeFromFile(SalePartTime &ref)
{

}
void FileOpe::readSaleManagerFromFile(SaleManager &ref)
{

}

void FileOpe::readBossFromFile(Boss &ref)
{
	readEmployeeFromFile(ref);
}

void FileOpe::writeDataToFile()
{
	//往文件中写入兼职技术人员的信息
	MAP_TECPART &tecPart = DataSet::getInstance().getTecPartMap();
	openFileForWrite(TEC_PARTTIME_FILE);
	MAP_TECPART::iterator iterTecPart = tecPart.begin();
	for (; iterTecPart != tecPart.end(); iterTecPart++)
	{
		writeTecPartTimeToFile(*(iterTecPart->second));
	}
	closeWriteFile();

	//往文件中写入技术经理的信息
	MAP_TECMA &tecMa = DataSet::getInstance().getTecManagerMap();
	openFileForWrite(TEC_MANAGER_FILE);
	MAP_TECMA::iterator iterTecMa = tecMa.begin();
	for (; iterTecMa != tecMa.end(); iterTecMa++)
	{
		writeTecManagerToFile(*(iterTecMa->second));
	}
	closeWriteFile();

	//往文件中写入读兼职销售人员的信息
//	MAP_SALEPART &salePart = DataSet::getInstance().getSalePartMap();
	//往文件中写入读取销售经理的信息
//	MAP_SALEMA &saleMa = DataSet::getInstance().getSaleManagerMap();

	//往文件中写入读取老板的信息
	MAP_BOSS &boss = DataSet::getInstance().getBossMap();
	openFileForWrite(BOSS_FILE);
	MAP_BOSS::iterator iterBoss = boss.begin();
	for (; iterBoss != boss.end(); iterBoss++)
	{
		writeBossToFile(*(iterBoss->second));
	}
	closeWriteFile();
}
void FileOpe::getDataFromFile()
{
	//读取兼职技术人员的信息
	MAP_TECPART &tecPart = DataSet::getInstance().getTecPartMap();
	openFileForRead(TEC_PARTTIME_FILE);
	TecPartTime *pTecPT = NULL;
	while (1)
	{
		pTecPT = new TecPartTime;
		readTecPartTimeFromFile(*pTecPT);
		if (m_inFile.eof())
		{
			delete pTecPT;
			Employee::m_suiId--;
			break;
		}
		tecPart.insert(PAIR_TECPART(pTecPT->getId(), pTecPT));
		if (Employee::m_suiId < pTecPT->getId())
		{
			Employee::m_suiId = pTecPT->getId()+1;
		}
	}
	closeReadFile();

	//读取技术经理的信息
	MAP_TECMA &tecMa = DataSet::getInstance().getTecManagerMap();
	openFileForRead(TEC_MANAGER_FILE);
	TecManager *pTecMa = NULL;
	while (1)
	{
		pTecMa = new TecManager;
		readTecManagerFromFile(*pTecMa);
		if (m_inFile.eof())
		{
			delete pTecMa;
			Employee::m_suiId--;
			break;
		}
		tecMa.insert(PAIR_TECMA(pTecMa->getId(), pTecMa));
		if (Employee::m_suiId < pTecMa->getId())
		{
			Employee::m_suiId = pTecMa->getId()+1;
		}
	}
	closeReadFile();

	//从文件中读兼职销售人员的信息
//	MAP_SALEPART &salePart = DataSet::getInstance().getSalePartMap();
	//从文件中读取销售经理的信息
//	MAP_SALEMA &saleMa = DataSet::getInstance().getSaleManagerMap();

	//从文件中读取老板的信息
	MAP_BOSS &boss = DataSet::getInstance().getBossMap();
	openFileForRead(BOSS_FILE);
	Boss *pBoss = NULL;
	while (1)
	{
		pBoss = new Boss;
		readBossFromFile(*pBoss);
		if (m_inFile.eof())
		{
			delete pBoss;
			Employee::m_suiId--;
			break;
		}
		boss.insert(PAIR_BOSS(pBoss->getId(), pBoss));
		if (Employee::m_suiId < pBoss->getId())
		{
			Employee::m_suiId = pBoss->getId()+1;
		}
	}
	closeReadFile();
}

