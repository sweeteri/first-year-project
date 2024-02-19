#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "menu_items.hpp"

TEST(TrueParent, Artists){
  const KPetrova::MenuItem* actual_parent = KPetrova::ARTISTS_AIVAZONSKIY.parent;
  const KPetrova::MenuItem* expected_parent = &KPetrova::STUDY_ARTISTS;
  ASSERT_EQ(actual_parent, expected_parent)
  << "Родителем художника не является " << actual_parent->title;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
