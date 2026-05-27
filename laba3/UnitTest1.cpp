#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "C:\Users\vyach\source\repos\asdasd\asdasd\asdasd.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
    TEST_CLASS(QuickSortTests)
    {
    public:
        TEST_METHOD(TestQuickSort_RegularArray)
        {
            std::vector<int> arr = {64,34,25,12,22,11,90};
            std::vector<int> expected = {11,12,22,25,34,64,90};
            if (!arr.empty()) {
                quickSort(arr, 0, (int)arr.size() - 1);
            }
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(TestQuickSort_AlreadySorted)
        {
            std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
            std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10};
            if (!arr.empty()) {
                quickSort(arr, 0, (int)arr.size() - 1);
            }
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(TestQuickSort_ReverseSorted)
        {
            std::vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
            std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10};
            if (!arr.empty()) {
                quickSort(arr, 0, (int)arr.size() - 1);
            }
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(TestQuickSort_AllEqual)
        {
            std::vector<int> arr = {5,5,5,5,5,5};
            std::vector<int> expected = {5,5,5,5,5,5};
            if (!arr.empty()) {
                quickSort(arr, 0, (int)arr.size() - 1);
            }
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(TestQuickSort_SingleElement)
        {
            std::vector<int> arr = {42};
            std::vector<int> expected = {42};
            if (!arr.empty()) {
                quickSort(arr, 0, 0);
            }
            Assert::AreEqual(expected[0], arr[0]);
        }
        TEST_METHOD(TestQuickSort_EmptyArray)
        {
            std::vector<int> arr = {};
            Assert::AreEqual((size_t)0, arr.size());
        }
        TEST_METHOD(TestQuickSort_TwoElements)
        {
            std::vector<int> arr = {2,1};
            std::vector<int> expected = {1,2};
            if (!arr.empty()) {
                quickSort(arr, 0, (int)arr.size() - 1);
            }
            Assert::AreEqual(expected[0], arr[0]);
            Assert::AreEqual(expected[1], arr[1]);
        }
    };
    TEST_CLASS(InsertionSortTests)
    {
    public:
        TEST_METHOD(TestInsertionSort_RegularArray)
        {
            std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
            std::vector<int> expected = { 11, 12, 22, 25, 34, 64, 90 };
            insertionSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestInsertionSort_AlreadySorted)
        {
            std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            insertionSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestInsertionSort_ReverseSorted)
        {
            std::vector<int> arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            insertionSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestInsertionSort_AllEqual)
        {
            std::vector<int> arr = { 5, 5, 5, 5, 5, 5 };
            std::vector<int> expected = { 5, 5, 5, 5, 5, 5 };
            insertionSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestInsertionSort_SingleElement)
        {
            std::vector<int> arr = { 42 };
            std::vector<int> expected = { 42 };
            insertionSort(arr);
            Assert::AreEqual(expected[0], arr[0]);
        }

        TEST_METHOD(TestInsertionSort_EmptyArray)
        {
            std::vector<int> arr = {};
            std::vector<int> expected = {};
            insertionSort(arr);
            Assert::AreEqual(expected.size(), arr.size());
        }

        TEST_METHOD(TestInsertionSort_TwoElements)
        {
            std::vector<int> arr = { 2, 1 };
            std::vector<int> expected = { 1, 2 };
            insertionSort(arr);
            Assert::AreEqual(expected[0], arr[0]);
            Assert::AreEqual(expected[1], arr[1]);
        }
    };
    TEST_CLASS(BubbleSortTests)
    {
    public:
        TEST_METHOD(TestBubbleSort_RegularArray)
        {
            std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
            std::vector<int> expected = { 11, 12, 22, 25, 34, 64, 90 };
            bubbleSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestBubbleSort_AlreadySorted)
        {
            std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            bubbleSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestBubbleSort_ReverseSorted)
        {
            std::vector<int> arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            bubbleSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestBubbleSort_AllEqual)
        {
            std::vector<int> arr = { 5, 5, 5, 5, 5, 5 };
            std::vector<int> expected = { 5, 5, 5, 5, 5, 5 };
            bubbleSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(TestBubbleSort_SingleElement)
        {
            std::vector<int> arr = { 42 };
            std::vector<int> expected = { 42 };
            bubbleSort(arr);
            Assert::AreEqual(expected[0], arr[0]);
        }

        TEST_METHOD(TestBubbleSort_TwoElements)
        {
            std::vector<int> arr = { 2, 1 };
            std::vector<int> expected = { 1, 2 };
            bubbleSort(arr);
            Assert::AreEqual(expected[0], arr[0]);
            Assert::AreEqual(expected[1], arr[1]);
        }
        TEST_METHOD(TestBubbleSort_WithDuplicates)
        {
            std::vector<int> arr = { 5, 2, 8, 2, 9, 1, 5, 5 };
            std::vector<int> expected = { 1, 2, 2, 5, 5, 5, 8, 9 };
            bubbleSort(arr);
            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
    };
}