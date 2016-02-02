#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <memory>
////////////////////////////////////////////////////////////
/// \brief A class that stores gameplay data
/// 
////////////////////////////////////////////////////////////


class GameData {
private:
	//Constructor
	GameData();

	static std::weak_ptr<GameData> m_instance;

	friend std::weak_ptr < GameData >;
	friend std::shared_ptr < GameData >;
public:
	//Get instance of singleton
	static std::shared_ptr<GameData> sharedGameData();

	std::string m_chestTextureFile;
	std::string m_backgroundTextureFile;
	std::string m_circlePadOutlineTextureFile;
	std::string m_zombieUpOneTextureFile;
	std::string m_zombieUpTwoTextureFile;
	std::string m_zombieUpThreeTextureFile;
	std::string m_zombieUpFourTextureFile;
	std::string m_zombieRightOneTextureFile;
	std::string m_zombieRightTwoTextureFile;
	std::string m_zombieRightThreeTextureFile;
	std::string m_zombieRightFourTextureFile;
	std::string m_zombieDownOneTextureFile;
	std::string m_zombieDownTwoTextureFile;
	std::string m_zombieDownThreeTextureFile;
	std::string m_zombieDownFourTextureFile;
	std::string m_zombieLeftOneTextureFile;
	std::string m_zombieLeftTwoTextureFile;
	std::string m_zombieLeftThreeTextureFile;
	std::string m_zombieLeftFourTextureFile;
	std::string m_playerOneTextureFile;
	std::string m_playerTwoTextureFile;
	std::string m_playerThreeTextureFile;
	std::string m_playerFourTextureFile;
	std::string m_player2_OneTextureFile;
	std::string m_player2_TwoTextureFile;
	std::string m_player2_ThreeTextureFile;
	std::string m_player2_FourTextureFile;

	int m_selectedPlayer;
};

#endif