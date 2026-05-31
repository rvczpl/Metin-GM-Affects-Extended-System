#Search chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+0, "Bip01", localeInfo.FN_GM_MARK) after it add:;

	if app.GM_NEW_AFFECTS:
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_HA, "Bip01", localeInfo.FN_HA_MARK)
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_TECH, "Bip01", localeInfo.FN_TECH_MARK)		
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_GA, "Bip01", localeInfo.FN_GA_MARK)
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_GM, "Bip01", localeInfo.FN_GM_MARK)
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_TGM, "Bip01", localeInfo.FN_TGM_MARK)
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT+chr.AFFECT_YMIR_TUT, "Bip01", localeInfo.FN_TUT_MARK)