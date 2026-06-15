#define UNIT_TEST_MODE
#include "pch.h"
#include "CppUnitTest.h"
#include "../qweqweqwe/qweqweqwe.cpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(IntegralTests)
    {
    public:

        TEST_METHOD(TestSimpsonWithN4)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.79113;
            double result = simpson_rule(diff, a, b, 4);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN8)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.78514;
            double result = simpson_rule(diff, a, b, 8);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN16)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.77908;
            double result = simpson_rule(diff, a, b, 16);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN64)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.77925;
            double result = simpson_rule(diff, a, b, 64);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN256)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.77926;
            double result = simpson_rule(diff, a, b, 256);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN1024)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.77926;
            double result = simpson_rule(diff, a, b, 1024);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }

        TEST_METHOD(TestSimpsonWithN8192)
        {
            double a = 2.0;
            double b = 4.0;
            double expected = 2.77926;
            double result = simpson_rule(diff, a, b, 8192);
            double tolerance = 0.0001;

            Assert::AreEqual(expected, result, tolerance);
        }
    };
}