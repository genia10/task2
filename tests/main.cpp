#include "ce_test.h"
#include "y_test.h"
#include "showwordbeginnings_test.h"
#include "m_test.h"
#include "save_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
