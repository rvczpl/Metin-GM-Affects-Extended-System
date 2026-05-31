//Add below to the end of file before }

#ifdef GM_NEW_AFFECTS
	PyModule_AddIntConstant(poModule, "GM_NEW_AFFECTS", 1);
#else
	PyModule_AddIntConstant(poModule, "GM_NEW_AFFECTS", 0);
#endif