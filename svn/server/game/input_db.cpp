//1. Search: LPCHARACTER pChar = CHARACTER_MANAGER::instance().FindPC(rAdminInfo.m_szName ); inside if statement and after pChar->SetGMLevel() add:

#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
				pChar->RefreshGMAffect();
				pChar->UpdatePacket();
	#endif
#endif

//example
		LPCHARACTER pChar = CHARACTER_MANAGER::instance().FindPC(rAdminInfo.m_szName );
		if (pChar )
		{
			pChar->SetGMLevel();

#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
				pChar->RefreshGMAffect();
				pChar->UpdatePacket();
	#endif
#endif
		}