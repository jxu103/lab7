#include "iterator.h"
#include "composite.h"
#include "gtest/gtest.h"
#include <iostream>


using namespace std;

TEST(Runfile,Final) {
	Op* op1 = new Op(1);
	Op* op3 = new Op(3);
	Add* add1 = new Add(op1,op3);
	add1->evaluate();
	



	//return 0;	
}


int main(int argc, char **argv)	{
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
