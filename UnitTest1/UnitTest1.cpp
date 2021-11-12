#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int A[5] = { 1,2,3,4,5 };
			int S = Sum(A, 5, 0, 0);
			Assert::AreEqual(S, 14);


		}
	};
}
