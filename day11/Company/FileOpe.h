/*
 * FileOpe.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef FILEOPE_H_
#define FILEOPE_H_

#include <iostream>
#include <fstream>
#include <map>

#include "Employee.h"
#include "TecPartTime.h"
#include "TecManager.h"
#include "SalePartTime.h"
#include "SaleManager.h"
#include "Boss.h"

using namespace std;

#define TEC_PARTTIME_FILE   "./tec_parttime.info"
#define TEC_MANAGER_FILE    "./tec_manager.info"

#define SALE_PARTTIME_FILE  "./sale_parttime.info"
#define SALE_MANAGER_FILE   "./sale_manager.info"

#define BOSS_FILE           "./boss.info"

class FileOpe
{
public:
	FileOpe();
	virtual ~FileOpe();

	bool openFileForWrite(string strFile);
	void closeWriteFile();

	bool openFileForRead(string strFile);
	void closeReadFile();

	/***************************************/

	void writeEmployeeToFile(const Employee &ref);

	void writeTecPartTimeToFile(const TecPartTime &ref);
	void writeTecManagerToFile(const TecManager &ref);

	void writeSalePartTimeToFile(const SalePartTime &ref);
	void writeSaleManagerToFile(const SaleManager &ref);

	void writeBossToFile(const Boss &ref);

	/*****************************************/

	void readEmployeeFromFile(Employee &ref);

	void readTecPartTimeFromFile(TecPartTime &ref);

	void readTecManagerFromFile(TecManager &ref);

	void readSalePartTimeFromFile(SalePartTime &ref);
	void readSaleManagerFromFile(SaleManager &ref);

	void readBossFromFile(Boss &ref);

	/*********************************************/

	void writeDataToFile();

//	template<typename T, typename M>
//	void readDataFromFile(string strFile, map<uint, T* > & contianer, M fun);

	void getDataFromFile();

private:
	ofstream m_outFile;
	ifstream m_inFile;
};

//template<typename T, typename M>
//void FileOpe::readDataFromFile(string strFile, map<uint, T* > &contianer, M fun)
//{
//	openFileForRead(strFile);
//	T *pData = NULL;
//	while (1)
//	{
//		pData = new T;
//		fun(*pData);
//		if (m_inFile.eof())
//		{
//			delete pData;
//			break;
//		}
//		contianer.insert(pair<uint, T *>(pData->getId(), pData));
//	}
//}

#endif /* FILEOPE_H_ */
