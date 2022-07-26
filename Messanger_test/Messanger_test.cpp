#include "pch.h"
#include "CppUnitTest.h"
#include"..\SFML Network\User.h"
#include"..\SFML Network\User.cpp"
#include"..\SFML Network\Client.h"
#include"..\SFML Network\Client.cpp"
#include"..\SFML Network\Server.h"
#include"..\SFML Network\Server.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messangertest
{
	TEST_CLASS(Messangertest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			User usr;
			std::string name = "name";
			usr.set_name(name);
			Assert::IsTrue(usr.get_name()==name);
		}
	};
}
