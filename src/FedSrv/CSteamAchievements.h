#pragma once

// Note, even if you remove a value from this list, you must NEVER remove it from m_Achievements
// or the Enum to string assignments will not line up, and you will be handing out wrong achievements!
enum EAchievements
{
	BETA_ACHIEVEMENT_1_0 = 0,
	FIRST_MINER_KILL_1_1 = 1,
	FIRST_CON_KILL_1_2 = 2,
	FIRST_FORCE_EJECT_1_3 = 3,
	FIRST_BASE_KILL_1_4 = 4,
	FIRST_BASE_CAP_1_5 = 5

	// Don't forget to update g_nMaximumSteamAchievementCount!
};

const int g_nMaximumSteamAchievementCount = 6; // Always keep this in sync with the number of achievments in EAchievements!

// BT - STEAM

class CSteamAchievements
{
private:
	CSteamID m_steamID;
	bool m_gotResponse;
	bool m_gotSuccessfulResponse;
	bool m_gotStatsStoredResponse;
	bool m_gotSuccessfulStatsStoredResponse;

	CCallResult< CSteamAchievements, GSStatsStored_t > m_UserStatsStoredCallResult;


	const char * m_Achievements[g_nMaximumSteamAchievementCount] =
	{
		// Never remove an item from this list! (see note above).
		"BETA_ACHIEVEMENT_1_0",
		"FIRST_MINER_KILL_1_1",
		"FIRST_CON_KILL_1_2",
		"FIRST_FORCE_EJECT_1_3",
		"FIRST_BASE_KILL_1_4",
		"FIRST_BASE_CAP_1_5"
	};

	bool SetAchievement(CSteamID &steamID, EAchievements achievement);

	// Steam Callbacks
	STEAM_GAMESERVER_CALLBACK(CSteamAchievements, OnUserStatsReceived, GSStatsReceived_t);




public:
	CSteamAchievements();

	bool RemoveAchievement(char *szSteamID, EAchievements achievement);

	void AwardBetaParticipation(CSteamID &steamID);

	void AwardKillAchievement(CSteamID &steamID, PilotType pt);
	
	// Steam Call Results
	void OnUserStatsStored(GSStatsStored_t *pCallback, bool bIOFailure);

};


