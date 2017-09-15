/*
 * Company.h
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#ifndef COMPANY_H_
#define COMPANY_H_

#include "DataSet.h"

class Company
{
public:
	Company();
	virtual ~Company();

	void init();

	short loginFace();
	void work();

	template<typename T>
	T loginCompare(uint uiId, const string &strPwd, map<uint, T>& container);

//	bool tecPartTimeLogin();
//	bool tecManagerLogin();
//
//	bool salePartTimeLogin();
//	bool saleManagerLogin();
//
//	bool bossLogin();

private:
	FileOpe m_file;
};

template<typename T>
T Company::loginCompare(uint uiId, const string &strPwd, map<uint, T>& container)
{
	T reval = NULL;

	typename map<uint, T>::iterator iter = container.find(uiId);
	if (iter != container.end())
	{
		if (iter->second->getPWd() == strPwd)
		{
			reval = iter->second;
		}
	}
	return reval;
}

#endif /* COMPANY_H_ */
