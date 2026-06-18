#include "pch.h"
#include "CppUnitTest.h"
#include "../dz/9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		TEST_METHOD(Test1)
		{
			int exp = 15;
			int act = solve(5, 15, { 3, 8, 1, 2, 5 });
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test2)
		{
			int exp = 17;
			int act = solve(4, 19, { 10, 10, 7, 7 });
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test3)
		{
			int exp = 6;
			int act = solve(3, 6, { 1, 2, 3 });
			Assert::AreEqual(exp, act);
		}
	};
}