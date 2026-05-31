//1. Search void CInstanceBase::UpdateTextTailLevel(DWORD level), inside it after char szText[256]; add:
#ifdef GM_NEW_AFFECTS
	if (IsGameMaster())
	{
		if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_HA))
			sprintf(szText, "[HA]");
		else if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_GA))
			sprintf(szText, "[GA]");
		else if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TECH))
			sprintf(szText, "[TECH]");
		else if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TGM))
			sprintf(szText, "[TGM]");
		else if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TUT))
			sprintf(szText, "[TUT]");
		else
			sprintf(szText, "[GM]");
	}
	else
#endif

//2. Search void CInstanceBase::SetAffectFlagContainer(const CAffectFlagContainer& c_rkAffectFlagContainer)after __SetNormalAffectFlagContainer(c_rkAffectFlagContainer); add:

#ifdef GM_NEW_AFFECTS
		if (m_isTextTail && m_dwLevel)
			UpdateTextTailLevel(m_dwLevel);
#endif

//3. Search void CInstanceBase::__SetAffect(UINT eAffect, bool isVisible) and add in switch (eAffect) and after case AFFECT_YMIR:
#ifdef GM_NEW_AFFECTS
		case AFFECT_YMIR_HA:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TECH:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_GA:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_GM:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TGM:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TUT:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;
#endif


//example:
void CInstanceBase::__SetAffect(UINT eAffect, bool isVisible)
{
	switch (eAffect)
	{
		case AFFECT_YMIR:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

#ifdef GM_NEW_AFFECTS
		case AFFECT_YMIR_HA:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TECH:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_GA:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_GM:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TGM:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;

		case AFFECT_YMIR_TUT:
#ifdef ENABLE_CANSEEHIDDENTHING_FOR_GM
			if (IsAffect(AFFECT_INVISIBILITY) && !__MainCanSeeHiddenThing())
				return;
#else
			if (IsAffect(AFFECT_INVISIBILITY))
				return;
#endif
			break;
#endif