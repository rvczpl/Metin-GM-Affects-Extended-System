//1. Search bool CClientManager::__GetAdminInfo(const char *szIP, std::vector<tAdminInfo> & rAdminVec) and change query like this:
"SELECT mID,mAccount,mName,mContactIP,mServerIP,mAuthority,prefix FROM gmlist WHERE mServerIP='ALL' or mServerIP='%s'",

//example:

bool CClientManager::__GetAdminInfo(const char *szIP, std::vector<tAdminInfo> & rAdminVec)
{
	char szQuery[512];

#ifdef GM_NEW_AFFECTS
#ifdef GM_AFFECTS_PER_LEVEL

	snprintf(szQuery, sizeof(szQuery),
		"SELECT mID,mAccount,mName,mContactIP,mServerIP,mAuthority,prefix FROM gmlist WHERE mServerIP='ALL' or mServerIP='%s'",
		szIP ? szIP : "ALL");
#else
	snprintf(szQuery, sizeof(szQuery),
		"SELECT mID,mAccount,mName,mContactIP,mServerIP,mAuthority FROM gmlist WHERE mServerIP='ALL' or mServerIP='%s'",
		szIP ? szIP : "ALL");
#endif
#endif

//2. Search strlcpy(Info.m_szServerIP, row[idx++], sizeof(Info.m_szServerIP)); after std::string stAuth = row[idx++]; add:
#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
			strlcpy(Info.m_szPrefix, row[idx] && *row[idx] ? row[idx] : "GM", sizeof(Info.m_szPrefix));
			idx++;
	#endif
#endif