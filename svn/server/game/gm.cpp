//1. Search BYTE gm_new_get_level( const char * name, const char * host, const char* account), after this function add:
#ifdef GM_NEW_AFFECTS
#ifdef GM_AFFECTS_PER_LEVEL
const char* gm_get_prefix(const char* name, const char* host, const char* account)
{
	if (gm_new_get_level(name, host, account) <= GM_PLAYER)
		return "GM";

	std::map<std::string, tGM>::iterator it = g_map_GM.find(name);
	if (g_map_GM.end() == it)
		return "GM";

	return it->second.Info.m_szPrefix[0] ? it->second.Info.m_szPrefix : "GM";
}
#endif
#endif

