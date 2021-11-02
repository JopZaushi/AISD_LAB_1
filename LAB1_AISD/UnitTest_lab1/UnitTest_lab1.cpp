#include "pch.h"
#include "CppUnitTest.h"
#include "..\LAB1_AISD\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab1
{
	TEST_CLASS(UnitTestlab1)
	{
	public:
		
		TEST_METHOD(Constructor_List)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
		}
		TEST_METHOD(Constructor_with_value_List)
		{
			List List_one(3);
			Assert::IsTrue(List_one.get_size() == 1);
		}
		TEST_METHOD(Destructor_List)
		{
			List List_one;
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.~List();
			Assert::IsTrue(List_one.get_size() == 0);
		}
		TEST_METHOD(Push_back)
		{
			List List_one;
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			List_one.pop_front();
			Assert::IsTrue(List_one.get_size() == 1);
			int element = List_one.at(0);
			Assert::IsTrue(element == 3);
		}
		TEST_METHOD(Push_front)
		{
			List List_one;
			List_one.push_front(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_front(3);
			Assert::IsTrue(List_one.get_size() == 2);
			List_one.pop_front();
			Assert::IsTrue(List_one.get_size() == 1);
			int element = List_one.at(0);
			Assert::IsTrue(element == 2);
		}
		TEST_METHOD(Pop_back)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
			try {
				List_one.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			try {
				List_one.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			Assert::IsTrue(List_one.get_size() == 1);
			int element = List_one.at(0);
			Assert::IsTrue(element == 2);
		}
		TEST_METHOD(Pop_front)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
			try {
				List_one.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			try {
				List_one.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			Assert::IsTrue(List_one.get_size() == 1);
			int element = List_one.at(0);
			Assert::IsTrue(element == 3);
		}
		TEST_METHOD(Insert)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);

			try {
				List_one.insert(8, 5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(4);
			Assert::IsTrue(List_one.get_size() == 2);
			try {
				List_one.insert(8, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			List_one.insert(3,1);
			Assert::IsTrue(List_one.get_size() == 3);
			int element = List_one.at(1);
			Assert::IsTrue(element == 3);
		}
		TEST_METHOD(At)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
			try {
				List_one.at(2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			List_one.pop_front();
			Assert::IsTrue(List_one.get_size() == 1);
			try {
				List_one.at(6);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			int element = List_one.at(0);
			Assert::IsTrue(element == 3);
		}
		TEST_METHOD(Remove)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(4);
			Assert::IsTrue(List_one.get_size() == 2);
			List_one.insert(3, 1);
			Assert::IsTrue(List_one.get_size() == 3);
			try {
				List_one.remove(-1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			try {
				List_one.remove(8);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			List_one.remove(1);
			Assert::IsTrue(List_one.get_size() == 2);
			int element1 = List_one.at(0);
			int element2 = List_one.at(1);
			Assert::IsTrue(element1 == 2);
			Assert::IsTrue(element2 == 4);
		}
		TEST_METHOD(Clear)
		{
			List List_one;
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			List_one.pop_front();
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(2);
			List_one.push_back(2);
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 4);
			List_one.clear();
			Assert::IsTrue(List_one.get_size() == 0);
		}
		TEST_METHOD(Set)
		{
			List List_one;
			Assert::IsTrue(List_one.get_size() == 0);
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			try {
				List_one.set(4,6);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			try {
				List_one.set(-1,4);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			List_one.set(1, 5);
			Assert::IsTrue(List_one.get_size() == 2);
			int element = List_one.at(1);
			Assert::IsTrue(element == 5);
		}
		TEST_METHOD(Emty)
		{
			List List_one;
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(3);
			Assert::IsTrue(List_one.get_size() == 2);
			Assert::IsTrue(List_one.isEmpty() == false);
			List_one.clear();
			Assert::IsTrue(List_one.isEmpty() == true);
		}
		TEST_METHOD(Push_front_list)
		{
			List List_one;
			List List_two;
			List_one.push_back(1);
			Assert::IsTrue(List_one.get_size() == 1);
			List_one.push_back(2);
			Assert::IsTrue(List_one.get_size() == 2);
			List_two.push_back(3);
			Assert::IsTrue(List_two.get_size() == 1);
			List_two.push_front(List_one);
			Assert::IsTrue(List_two.get_size() == 3);
			int element1 = List_two.at(0);
			int element2 = List_two.at(1);
			int element3 = List_two.at(2);
			Assert::IsTrue(element1 == 3);
			Assert::IsTrue(element2 == 1);
			Assert::IsTrue(element3 == 2);
		}
	};
}
