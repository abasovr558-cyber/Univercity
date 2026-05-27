#include "pch.h"
#include "CppUnitTest.h"
#include "../qweqweqweqwe/qweqweqweqwe.cpp"
#include <stack>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(StackIsEmptyTests)
    {
    public:

        TEST_METHOD(EmptyStackReturnsTrue)
        {
            std::stack<int> emptyStack;
            bool result = isEmpty(emptyStack);
            Assert::IsTrue(result);
        }

        TEST_METHOD(StackWithOneElement)
        {
            std::stack<int> stack;
            stack.push(42);
            bool result = isEmpty(stack);
            Assert::IsFalse(result);
        }

        TEST_METHOD(StackWithMultipleElements)
        {
            std::stack<int> stack;
            for (int i = 0; i < 100; ++i) {
                stack.push(i);
            }
            bool result = isEmpty(stack);
            Assert::IsFalse(result);
        }

        TEST_METHOD(StackAfterPushAndPop)
        {
            std::stack<int> stack;
            stack.push(10);
            stack.push(20);
            stack.pop();
            stack.pop();
            bool result = isEmpty(stack);
            Assert::IsTrue(result);
        }
    };
}