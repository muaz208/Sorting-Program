#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    
 
	void TestQ3_readandSort1(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
	void TestQ3_readandSort3(CuTest *tc) {

		char inputFile[] =  "wordlist2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words(actualList,size);

		char *expectedList[]={"brysontiller","lilbaby","nafesmallz","nav","playboicarti","swaelee"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
   
	void TestQ3_readandSort2(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort2_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}

	void TestQ3_readandSort4(CuTest *tc) {

		char inputFile[] =  "wordlist2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort2_words(actualList,size);

		char *expectedList[]={"brysontiller","lilbaby","nafesmallz","nav","playboicarti","swaelee"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}

	void TestQ3_readandSortSamePrefix(CuTest *tc) {

		char inputFile[] =  "wordlist3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words(actualList,size);

		char *expectedList[]={"lilbaby","lildurk","lilkeed","lilmosey","liluzivert","lilwayne"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
	void TestQ3_readandSortSamePrefix2(CuTest *tc) {

		char inputFile[] =  "wordlist3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort2_words(actualList,size);

		char *expectedList[]={"lilbaby","lildurk","lilkeed","lilmosey","liluzivert","lilwayne"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
 

    
  
//===========================================================
	CuSuite* Lab3GetSuite() {


		SUITE_ADD_TEST(suite, TestQ3_readandSort1);
		SUITE_ADD_TEST(suite, TestQ3_readandSort2);
		SUITE_ADD_TEST(suite, TestQ3_readandSort3);
		SUITE_ADD_TEST(suite, TestQ3_readandSort4);
		SUITE_ADD_TEST(suite, TestQ3_readandSortSamePrefix);
		SUITE_ADD_TEST(suite, TestQ3_readandSortSamePrefix2);
        
       

		return suite;
	}
    
