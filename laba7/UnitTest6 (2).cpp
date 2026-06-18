#include "pch.h"
#include "CppUnitTest.h"
#include "../dz/6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		TEST_METHOD(Test1)
		{
			int exp = 1024;
			int act = solve(2, 10);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test2)
		{
			int exp = 1024;
			int act = solve(2, 11);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test3)
		{
			int exp = 25;
			int act = solve(5, 2);
			Assert::AreEqual(exp, act);
		}
	};
}