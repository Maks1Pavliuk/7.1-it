#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1/Source.cpp" // Update with your source file path

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int rowCount = 8, colCount = 6, Low = -26, High = 23;
			int** Q = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Q[i] = new int[colCount];

			Create(Q, rowCount, colCount, Low, High);

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					Assert::IsTrue(Q[i][j] >= Low && Q[i][j] <= High);

			for (int i = 0; i < rowCount; i++) delete[] Q[i];
			delete[] Q;
		}

		TEST_METHOD(TestCalc)
		{
			const int rowCount = 2, colCount = 2;
			int** Q = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Q[i] = new int[colCount];
			Q[0][0] = 1; Q[0][1] = -3; Q[1][0] = 4; Q[1][1] = 5;

			int S = 0, k = 0;
			Calc(Q, rowCount, colCount, S, k);

			Assert::AreEqual(6, S);
			Assert::AreEqual(2, k);
			Assert::AreEqual(0, Q[0][0]);
			Assert::AreEqual(0, Q[1][1]);

			for (int i = 0; i < rowCount; i++) delete[] Q[i];
			delete[] Q;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 3, colCount = 3;
			int** Q = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Q[i] = new int[colCount];
			Q[0][0] = 3; Q[0][1] = 1; Q[0][2] = 2;
			Q[1][0] = 5; Q[1][1] = 4; Q[1][2] = 6;
			Q[2][0] = 8; Q[2][1] = 7; Q[2][2] = 9;

			Sort(Q, rowCount, colCount);

			Assert::AreEqual(1, Q[0][0]);
			Assert::AreEqual(2, Q[0][1]);
			Assert::AreEqual(3, Q[0][2]);

			for (int i = 0; i < rowCount; i++) delete[] Q[i];
			delete[] Q;
		}
	};
}
