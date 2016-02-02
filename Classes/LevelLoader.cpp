#include "LevelLoader.h"

////////////////////////////////////////////////////////////
LevelLoader::LevelLoader(std::string const & filename) 
{
	loadJSONData(filename);
	m_document.Parse<0>(m_JSONData.c_str());	
	loadGameData();
}

////////////////////////////////////////////////////////////
void LevelLoader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();

	auto fileUtils = cocos2d::FileUtils::getInstance();
	// Loads all the data in the file into a std::string.
	m_JSONData = fileUtils->getStringFromFile(filename);
}


////////////////////////////////////////////////////////////
void LevelLoader::loadGameData()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	Value::ConstMemberIterator it1 = m_document["global_settings"].MemberonBegin();
	// Get value of "chest_texture_file" 
	ptr->m_chestTextureFile = it1->value.GetString();
	it1++;
	// Get value of "background_texture_file" 
	ptr->m_backgroundTextureFile = it1->value.GetString();
	it1++;
	// Get value of "circle_pad_outline_texture_file"
	ptr->m_circlePadOutlineTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_up_one_texture_file"
	ptr->m_zombieUpOneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_up_two_texture_file"
	ptr->m_zombieUpTwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_up_three_texture_file"
	ptr->m_zombieUpThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_up_four_texture_file"
	ptr->m_zombieUpFourTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_right_one_texture_file"
	ptr->m_zombieRightOneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_right_two_texture_file"
	ptr->m_zombieRightTwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_right_three_texture_file"
	ptr->m_zombieRightThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_right_four_texture_file"
	ptr->m_zombieRightFourTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_down_one_texture_file"
	ptr->m_zombieDownOneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_down_two_texture_file"
	ptr->m_zombieDownTwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_down_three_texture_file"
	ptr->m_zombieDownThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_down_four_texture_file"
	ptr->m_zombieDownFourTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_left_one_texture_file"
	ptr->m_zombieLeftOneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_left_two_texture_file"
	ptr->m_zombieLeftTwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_left_three_texture_file"
	ptr->m_zombieLeftThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "zombie_left_four_texture_file"
	ptr->m_zombieLeftFourTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player_one_texture_file"
	ptr->m_playerOneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player_two_texture_file"
	ptr->m_playerTwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player_three_texture_file"
	ptr->m_playerThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player_four_texture_file"
	ptr->m_playerFourTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player2_one_texture_file"
	ptr->m_player2_OneTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player2_two_texture_file"
	ptr->m_player2_TwoTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player2_three_texture_file"
	ptr->m_player2_ThreeTextureFile = it1->value.GetString();
	it1++;
	// Get value of "player2_four_texture_file"
	ptr->m_player2_FourTextureFile = it1->value.GetString();
	it1++;
}
