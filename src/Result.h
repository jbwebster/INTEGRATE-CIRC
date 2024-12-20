/*
 * Result.h
 *
 *  Created on: Sep 26, 2013
 *      Author: jinzhang
 */

#ifndef RESULT_H_
#define RESULT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include "sam.h"
#include <fstream>


using namespace std;


#include "MyTypes.h"
#include "Reference.h"
#include "Gene.h"
#include "FocalRegionHandler.h"
#include "BreakPoint.h"
#include "Util.h"
#include "Updator.h"

class Result {
private:
	vector<result_t> results;
	int indi;

public:

	
    vector<break_point_record_t> bkvec;
    
    
    Result();
	virtual ~Result();
    
    int getResultSize();
	

	int addResult(result_t result);
	int searchResult(int geneId1,int geneId2,result_t & result);
	result_t * getOneResult(int index);
	int	printOneResult(int index, ofstream & outFile, Reference & ref, int isRunningNormal);
	int printAllResult(char * file, Reference & ref,int isRunningNormal, char* dir);
	int getTiers(double pn);
	int printSummary(char * filename, Gene & g, int isRunningNormal, int largeNum, char* dir);
	int checkALLPrime(Gene & g);
	
	void checkMultiJunction(int index, Gene & g); //New
	vector<int> getAllSprnas(result_t * prt, vector<split_rna_t> & sts); //New


	int getSize();

	int getIndi() const {
		return indi;
	}

	void setIndi(int indi) {
		this->indi = indi;
	}

	int removeMultiple(Gene & g, int largeNum);
	int combineRecord(Gene & g);


	int printExons(char * file, Gene & g, Reference & ref, int isRunningNormal, char * bkfile, char * bkfileBEDPE, char * bkfileVCF, char * refname, char * sample_name, char* dir);
	
	//copy and modified from printExons from 0.1.c and rm //bk and change
        int getAllJunctionsStep1(Gene& g, Reference & ref);
        int getAllJunctionsStep2(char * filename, Gene& g, Reference & ref);
        int getAllJunctionsStep3(char * filename, Gene& g, Reference & ref);
        int getAllJunctionsStep4(Gene& g, Reference & ref);
        int getAllJunctionsStep5(Gene& g, Reference & ref);
        int getAllJunctionsStep6(char * file, Gene& g, Reference & ref, char* dir);
	
		int printFcirc(char* file, Gene& g, Reference & ref, char* dir);

	std::string createFilename(char* dir, char* file);
};




#endif /* RESULT_H_ */
