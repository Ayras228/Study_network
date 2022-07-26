#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messangertest
{
	TEST_CLASS(Messangertest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(1 == 1);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::IsTrue(1 == 2);
		}
	};
}
