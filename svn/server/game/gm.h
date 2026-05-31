//1. Search extern BYTE gm_get_level(const char * name, const char * host = NULL, const char * account = NULL); after it add:
#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
		extern const char* gm_get_prefix(const char* name, const char* host = NULL, const char* account = NULL);
	#endif
#endif