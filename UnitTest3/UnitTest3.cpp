#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = P0(2, 3);
			Assert::AreEqual(t, 0);
		}
	};
}
