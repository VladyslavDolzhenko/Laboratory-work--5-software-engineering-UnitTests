#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Projects\Laboratory work  №2(software engineering)\Laboratory work  №2(software engineering)\Laboratory work  №2(software engineering).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2UnitTests
{
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get0and1and3and1_exceptionThrown)
		{
			int n = 0;
			double a = 1;
			double b = 3;
			double h = 1;

			try {
				checkValidParams(n, a, b, h);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:
		TEST_METHOD(checkValidParams_get1and4and3and1_exceptionThrown)
		{
			int n = 1;
			double a = 4;
			double b = 3;
			double h = 1;

			try {
				checkValidParams(n, a, b, h);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	
	public:
		TEST_METHOD(checkValidParams_get1and5and9and2_exceptionThrown)
		{
			int n = 1;
			double a = 5;
			double b = 9;
			double h = -2;

			try {
				checkValidParams(n, a, b, h);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
			
	public:
		TEST_METHOD(checkValidParams_get8and3and15and2_exceptionThrown)
		{
			int n = 8;
			double a = 3;
			double b = 15;
			double h = 2;

			try {
				checkValidParams(n, a, b, h);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:
		TEST_METHOD(checkValidParams_get0and6and3and0_exceptionThrown)
		{
			int n = 0;
			double a = 6;
			double b = 3;
			double h = 0;

			try {
				checkValidParams(n, a, b, h);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkValidInput_Tests)
	{
	public:
		TEST_METHOD(checkValidInput_exceptionThrown)
		{
			try {
				checkValidInput();
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_get3and9and1and5_truereturned)
		{
			double a = 3;
			double b = 9;
			double h = 1;
			int n = 5;
			int expected = true;

			int actual = calculate(a, b, h, n);

			Assert::AreEqual(expected, actual);
		}

	public:
		TEST_METHOD(calculate_get3and9and1and1_exceptionThrown)
		{
			double a = -3;
			double b = 9;
			double h = 1;
			int n = 1;

			try {
				calculate(a, b, h, n);
				Assert::Fail();
			}
			catch (...) 
			{
				Assert::IsTrue(true);
			}
		}
	};
}