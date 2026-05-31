//1. Search: AFFECT_NUM = 64, and before it add:
#ifdef GM_NEW_AFFECTS
			AFFECT_YMIR_HA = 49,
			AFFECT_YMIR_TECH = 50,
			AFFECT_YMIR_GA = 51,
			AFFECT_YMIR_GM = 52,
			AFFECT_YMIR_TGM = 53,
			AFFECT_YMIR_TUT = 54,
#endif

//IMPORTANT: Effects can be problematic with same ids with serversource.If you have problem change ids in client side in -1 (serverside AFFECT_YMIR_HA = 50, in client side 49). 

