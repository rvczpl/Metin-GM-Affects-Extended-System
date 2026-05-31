//Add below to the end of file before }:
#ifdef GM_NEW_AFFECTS
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_HA", CInstanceBase::AFFECT_YMIR_HA);
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_TECH", CInstanceBase::AFFECT_YMIR_TECH);
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_GA", CInstanceBase::AFFECT_YMIR_GA);
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_GM", CInstanceBase::AFFECT_YMIR_GM);
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_TGM", CInstanceBase::AFFECT_YMIR_TGM);
	PyModule_AddIntConstant(poModule, "AFFECT_YMIR_TUT", CInstanceBase::AFFECT_YMIR_TUT);
#endif