//Search BOOL CInstanceBase::IsGameMaster() and add after if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR))		return true;
#ifdef GM_NEW_AFFECTS
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_HA))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TECH))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_GA))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_GM))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TGM))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TUT))
		return true;
#endif

//Example:
BOOL CInstanceBase::IsGameMaster()
{
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR))
		return true;
#ifdef GM_NEW_AFFECTS
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_HA))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TECH))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_GA))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_GM))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TGM))
		return true;
	if (m_kAffectFlagContainer.IsSet(AFFECT_YMIR_TUT))
		return true;
#endif
	return false;
}