#include <gtest/gtest.h>
#include <string>

#include "fields.h"

using namespace std;

TEST(FieldsTest, CheckIsDecimal)
{
	FieldInfo nonDecimalFieldInfo("IT-CO-UNIDADE-GESTORA", 'A', "6");
	FieldInfo decimalFieldInfo("VA-TRANSACAO", 'N', "16,2");

	ASSERT_FALSE(nonDecimalFieldInfo.isDecimal());
	ASSERT_TRUE(decimalFieldInfo.isDecimal());
}

TEST(FieldsTest, CheckDecimalSeparator)
{
	FieldInfo decimalFieldInfo("VA-TRANSACAO", 'N', "16,2");

	ASSERT_EQ(decimalFieldInfo.beforeDecimalSeparator(), "16");
	ASSERT_EQ(decimalFieldInfo.afterDecimalSeparator(), "2");
}

TEST(FieldsTest, CheckReadLength)
{
	FieldInfo nonDecimalFieldInfo("IT-CO-UNIDADE-GESTORA", 'A', "6");
	FieldInfo decimalFieldInfo("VA-TRANSACAO", 'N', "16,2");

	ASSERT_EQ(nonDecimalFieldInfo.readLength(), 6);
	ASSERT_EQ(decimalFieldInfo.readLength(), 18);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
