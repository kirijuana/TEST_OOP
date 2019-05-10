#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(RectanglePerimeter)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//RectangleInput.txt");

			shape * test = new rectangle;
			test->InData(ReadFile);
			double expected = test->Perimeter();
			double actual = 10;

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(CirclePerimeter)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//CircleInput.txt");

			shape * test = new circle;
			test->InData(ReadFile);
			float expected = test->Perimeter();
			float actual = 43.981;

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TrianglePerimeter)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//TriangleInput.txt");

			shape * test = new triangle;
			test->InData(ReadFile);
			float expected = test->Perimeter();
			float actual = 18;

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(OutRectangle)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InRectangle.txt");
			shape* expected;
			expected = new rectangle;
			expected->InData(ReadFile);
			ReadFile.close();
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutRectangle.txt");
			expected->Out(WriteFile);
			WriteFile.close();
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutRectangle.txt");
			string expectedStr;
			getline(ReadFile1, expectedStr, '\0');

			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InRectangle.txt");
			string actualStr;
			getline(ReadFile2, actualStr, '\0');
			ReadFile2.close();
			Assert::AreEqual(expectedStr, actualStr);
		}
		TEST_METHOD(OutCircle)
		{		
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InCircle.txt");
			shape* expected;
			expected = new circle;	
			expected->InData(ReadFile);
			ReadFile.close();
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutCircle.txt");
			expected->Out(WriteFile);
			WriteFile.close();
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutCircle.txt");
			string expectedStr;
			getline(ReadFile1, expectedStr, '\0');
			
			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InCircle.txt");
			string actualStr;
			getline(ReadFile2, actualStr, '\0');
			ReadFile2.close();
			Assert::AreEqual(expectedStr, actualStr);
		}
		TEST_METHOD(OutTriangle)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InTriangle.txt");
			shape* expected;
			expected = new triangle;
			expected->InData(ReadFile);
			ReadFile.close();
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutTriangle.txt");
			expected->Out(WriteFile);
			WriteFile.close();
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutTriangle.txt");
			string expectedStr;
			getline(ReadFile1, expectedStr, '\0');

			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//InTriangle.txt");
			string actualStr;
			getline(ReadFile2, actualStr, '\0');
			ReadFile2.close();
			Assert::AreEqual(expectedStr, actualStr);
		}
		TEST_METHOD(InRectangle)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//expectRectangle.txt");
		
			int expected = 7;
			shape *actual = new rectangle;
			actual->InData(ReadFile);
			rectangle *temp;
			temp = (rectangle*)actual;
			Assert::AreEqual(expected, int(temp->x));
		}
		TEST_METHOD(InCircle)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//expectCircle.txt");

			int expected = 5;
			shape *actual = new circle;
			actual->InData(ReadFile);
			circle *temp;
			temp = (circle*)actual;
			Assert::AreEqual(expected, int(temp->x));
		}
		TEST_METHOD(InTriangle)
		{
			ifstream ReadFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//expectCircle.txt");

			int expected = 5;
			shape *actual = new triangle;
			actual->InData(ReadFile);
			triangle *temp;
			temp = (triangle*)actual;
			Assert::AreEqual(expected, int(temp->a));
		}
		TEST_METHOD(OutContainer)
		{
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutContainer.txt");
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//Input.txt");
			container c;
			c.In(ReadFile1);
		    c.Out(WriteFile);
			WriteFile.close();
		
			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutList.txt");
			ifstream ReadFile3("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutContainer.txt");
			string expected;
			getline(ReadFile2, expected, '\0');
			string actual;
			getline(ReadFile3, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SortContainer)
		{
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutSort.txt");
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//Input.txt");
			container c;
			c.In(ReadFile1);
			c.Sorting();
			c.Out(WriteFile);
			WriteFile.close();

			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//expecSorting.txt");
			ifstream ReadFile3("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//OutSort.txt");
			string expected;
			getline(ReadFile2, expected, '\0');
			string actual;
			getline(ReadFile3, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OutOnlyRectangle)
		{
			ofstream WriteFile("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//FilterOut.txt");
			ifstream ReadFile1("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//Input.txt");
			container c;		
			c.In(ReadFile1);
			c.FiltredOut(WriteFile);		
			WriteFile.close();
			ReadFile1.close();
			ifstream ReadFile2("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//expecFilterOut.txt");
			ifstream ReadFile3("C://Users//kirijuana//source//repos//TEST_OOP//UnitTest1//FilterOut.txt");
			string expected;
			getline(ReadFile2, expected, '\0');
			string actual;
			getline(ReadFile3, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
	};
}