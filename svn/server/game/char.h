//Search BYTE			gm_level; before it add:
#ifdef GM_NEW_AFFECTS
#ifdef GM_AFFECTS_PER_LEVEL
	char			gm_prefix[8];
#endif
#endif

//Search void			SetGMLevel(); and after it add:
#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
			const char*		GetGMPrefix() const;
			void			RefreshGMAffect();
	#endif
#endif