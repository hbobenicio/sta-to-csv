#include <gtest/gtest.h>
#include "fields.h"

TEST(FieldsTest, CheckIsDecimal)
{
	FieldInfo nonDecimalFieldInfo("IT-CO-UNIDADE-GESTORA", 'A', "6");
	FieldInfo decimalFieldInfo("VA-TRANSACAO", 'N', "16,2");

	ASSERT_FALSE(nonDecimalFieldInfo.isDecimal());
	ASSERT_TRUE(decimalFieldInfo.isDecimal());
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

