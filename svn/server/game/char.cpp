//1. Search void CHARACTER::SetEmpire(BYTE bEmpire) and after this add

#ifdef GM_NEW_AFFECTS
#ifdef GM_AFFECTS_PER_LEVEL
void CHARACTER::RefreshGMAffect()
{
	m_afAffectFlag.Reset(AFFECT_YMIR_HA);
	m_afAffectFlag.Reset(AFFECT_YMIR_TECH);
	m_afAffectFlag.Reset(AFFECT_YMIR_GA);
	m_afAffectFlag.Reset(AFFECT_YMIR_GM);
	m_afAffectFlag.Reset(AFFECT_YMIR_TGM);
	m_afAffectFlag.Reset(AFFECT_YMIR_TUT);

	if (GetGMLevel() <= GM_PLAYER)
		return;

	const char* p = GetGMPrefix();

	if (!strcasecmp(p, "HA"))
		m_afAffectFlag.Set(AFFECT_YMIR_HA);
	else if (!strcasecmp(p, "TECH"))
		m_afAffectFlag.Set(AFFECT_YMIR_TECH);
	else if (!strcasecmp(p, "GA"))
		m_afAffectFlag.Set(AFFECT_YMIR_GA);
	else if (!strcasecmp(p, "TGM"))
		m_afAffectFlag.Set(AFFECT_YMIR_TGM);
	else if (!strcasecmp(p, "TUT"))
		m_afAffectFlag.Set(AFFECT_YMIR_TUT);
	else
		m_afAffectFlag.Set(AFFECT_YMIR_GM);

	m_bPKMode = PK_MODE_PROTECT;
}
#endif
#endif

//2. Search void CHARACTER::SetPlayerProto(const TPlayerTable * t), in this void search if (GetGMLevel() > GM_LOW_WIZARD) or if (GetGMLevel() > GM_PLAYER) and replace whole if statement like this:

#ifndef ENABLE_GM_FLAG_IF_TEST_SERVER
	if (!test_server)
#endif
	{

#ifdef GM_NEW_AFFECTS
	#ifdef GM_AFFECTS_PER_LEVEL
		RefreshGMAffect();
	#else
		if (GetGMLevel() == GM_IMPLEMENTOR)
		{
			m_afAffectFlag.Set(AFFECT_YMIR_HA);
			m_bPKMode = PK_MODE_PROTECT;
		}
		else if (GetGMLevel() == GM_HIGH_WIZARD)
		{
			m_afAffectFlag.Set(AFFECT_YMIR_GA);
			m_bPKMode = PK_MODE_PROTECT;
		}
		else if (GetGMLevel() == GM_GOD)
		{
			m_afAffectFlag.Set(AFFECT_YMIR_GM);
			m_bPKMode = PK_MODE_PROTECT;
		}
		else if (GetGMLevel() == GM_LOW_WIZARD)
		{
			m_afAffectFlag.Set(AFFECT_YMIR_TUT);
			m_bPKMode = PK_MODE_PROTECT;
		}
	#endif
#else
#ifdef ENABLE_GM_FLAG_FOR_LOW_WIZARD
		if (GetGMLevel() > GM_PLAYER)
		{
			m_afAffectFlag.Set(AFF_YMIR);
			m_bPKMode = PK_MODE_PROTECT;
		}
#else
		if (GetGMLevel() > GM_LOW_WIZARD)
		{
			m_afAffectFlag.Set(AFF_YMIR);
			m_bPKMode = PK_MODE_PROTECT;
		}
#endif
#endif
	}
	
//3. Search void CHARACTER::SetGMLevel() and replace whole function with:
#ifdef GM_NEW_AFFECTS
#ifdef  GM_AFFECTS_PER_LEVEL

void CHARACTER::SetGMLevel()
{
	if (GetDesc())
	{
		m_pointsInstant.gm_level = gm_get_level(GetName(), GetDesc()->GetHostName(), GetDesc()->GetAccountTable().login);
		strlcpy(m_pointsInstant.gm_prefix, gm_get_prefix(GetName(), GetDesc()->GetHostName(), GetDesc()->GetAccountTable().login), sizeof(m_pointsInstant.gm_prefix));
	}
	else
	{
		m_pointsInstant.gm_level = GM_PLAYER;
		strlcpy(m_pointsInstant.gm_prefix, "GM", sizeof(m_pointsInstant.gm_prefix));
	}
}

const char* CHARACTER::GetGMPrefix() const
{
	return m_pointsInstant.gm_prefix[0] ? m_pointsInstant.gm_prefix : "GM";
}

#else
void CHARACTER::SetGMLevel()
{
	if (GetDesc())
	{
	    m_pointsInstant.gm_level =  gm_get_level(GetName(), GetDesc()->GetHostName(), GetDesc()->GetAccountTable().login);
	}
	else
	{
	    m_pointsInstant.gm_level = GM_PLAYER;
	}
}
#endif
#endif	