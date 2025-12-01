// init.c 

static Object SpawnObject(string type, vector position, vector orientation, float scale = 1.0)
{
    Object obj;
    if (type.Contains(".p3d")) {
        obj = GetGame().CreateStaticObjectUsingP3D(type, position, orientation, scale, false);
    } else {        
        obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOPERSISTENCY_CHAR);
    }

    if (!obj) {
        Error("Failed to create object " + type);
        return null;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.SetScale(scale);
    obj.Update();
	obj.SetAffectPathgraph(true, false);
	if (obj.CanAffectPathgraph()) {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    } 

    return obj;
}

void main()
{
	
	// -- Wczytaj Loot
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	int year, month, day, hour, minute;
	int reset_month = 7, reset_day = 17;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
	
	// -- Wczytaj obiekty

// Kayetan Colin_MCREJ
SpawnObject("StaticObj_Wall_PipeFenceWall_8", "7690.096191 280.877716 2352.544434", "35.999985 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_PipeFence_8", "7693.743652 280.383209 2359.401123", "45.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7482.718262 287.741669 2490.014648", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7486.495117 287.040009 2491.435303", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_Railing_1_Pole", "7696.264648 280.453308 2354.750977", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7490.601563 287.039978 2492.675781", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7495.334961 287.040039 2493.966553", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_Railing_1_Pole", "7693.861816 280.524597 2351.597168", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7559.682129 286.998535 2518.048828", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_FueldStation_Shed", "7700.567871 283.213379 2353.504395", "125.999908 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7554.110840 287.040009 2519.193604", "-0.000120 0.000000 0.000000", 1);
SpawnObject("dz/structures/military/improvised/roadblock_cncblocks_long.p3d", "8102.794922 268.137268 1754.955566", "-0.314159 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7549.401367 287.039978 2520.527832", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7800.395020 352.978790 1157.975586", "-135.000092 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7545.829590 287.040009 2520.882080", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7797.775879 352.777222 1158.447144", "-143.999939 0.000000 -0.000000", 1);
SpawnObject("dz/structures/signs/billboards/bilboard_notacola.p3d", "7699.781250 282.796692 2359.981689", "2.042035 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7543.545410 287.040009 2521.191162", "-0.000120 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7795.311523 352.661560 1160.200806", "-124.466820 0.000000 -0.000000", 0.999984);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7789.665039 280.690063 2271.214600", "143.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7793.520020 352.623566 1162.201050", "-116.999962 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7785.741699 280.690033 2278.442139", "134.999908 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Long", "7872.194336 275.485291 1914.018311", "-9.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7792.171875 352.128235 1164.880371", "-124.466820 0.000000 -0.000000", 0.999984);
SpawnObject("StaticObj_Roadblock_Wood_Long", "7875.917969 275.456055 1914.370972", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7791.248535 352.259277 1167.354370", "-124.466820 0.000000 -0.000000", 0.999984);
SpawnObject("StaticObj_Roadblock_Wood_Small", "8108.911621 268.827271 1762.100098", "135.000000 0.000000 -0.000000", 1);
SpawnObject("dz/structures/military/improvised/roadblock_cncblocks_long.p3d", "6909.460449 442.954559 919.784241", "1.413716 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Long", "7881.107422 275.318329 1914.119141", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_CncBlocks_Long", "6560.870605 387.689240 1458.427490", "-144.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_CncBlocks_Long", "6564.170898 387.553101 1462.477295", "-135.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "8109.940430 269.214569 1766.694214", "135.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7382.778320 358.099274 1962.888184", "-108.000015 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7395.791992 356.505310 1968.547974", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7434.448242 352.321472 1994.060669", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7418.499023 352.537292 1979.681519", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "8110.403320 269.520477 1770.675049", "135.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7428.974121 352.246887 1986.551880", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("dz/structures/military/improvised/roadblock_cncblocks_long.p3d", "6904.371094 442.838898 918.887390", "1.413717 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7432.431152 352.024994 1989.285034", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "7434.401855 352.175110 1992.186890", "-108.000046 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_Wood_Small", "8108.425293 268.654358 1755.049683", "135.000000 0.000000 -0.000000", 1);	

	// OFFROAD FUN
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6965.759766 400.531036 1742.112183", "74.502174 -15.000000 0.000001", 0.999944);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6966.587891 400.540283 1739.277954", "74.502174 -15.000000 0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6978.726563 395.788910 1745.689209", "74.502182 -19.999998 -0.000001", 0.999944);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6979.554688 395.798157 1742.854980", "74.502182 -19.999996 0.000002", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6991.289551 390.330780 1748.828613", "74.502174 -24.999992 -0.000000", 0.999944);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6992.117676 390.340027 1745.994385", "74.502174 -24.999996 -0.000000", 0.999969);
//SpawnObject("StaticObj_Panels_Concrete", "7221.509766 302.411499 2271.659912", "12.999999 0.000000 90.000000", 1.3);
//SpawnObject("StaticObj_Panels_Concrete", "7215.376465 304.497162 2254.390381", "18.999998 0.000000 90.000000", 1.3);
//SpawnObject("StaticObj_Panels_Concrete", "7225.930664 300.313324 2294.166260", "12.999999 0.000000 90.000000", 1.3);
//SpawnObject("dz/structures/industrial/misc/misc_concretepipe.p3d", "7210.177734 302.898041 2250.784424", "-0.000002 1.570796 -0.000002", 1.4);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7004.629883 385.005035 1749.482178", "74.502182 -19.999996 -0.000002", 0.999969);
//SpawnObject("dz/structures/industrial/misc/misc_concretepanels.p3d", "7196.837891 303.003082 2255.387695", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/structures/industrial/misc/misc_concretepanels.p3d", "7197.295898 302.970398 2259.645264", "-2.232916 0.000000 -0.000000", 0.999985);
//SpawnObject("dz/structures/military/misc/misc_concreteblock2.p3d", "7212.534180 301.994415 2252.855713", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/structures/military/misc/misc_concreteblock2_stripes.p3d", "7199.603516 302.386780 2262.914551", "1.752059 0.000000 -0.000000", 0.999986);
//SpawnObject("StaticObj_Panels_Concrete_Legacy", "7208.279785 302.967987 2259.709961", "31.898996 -4.399998 -0.000001", 0.999979);
//SpawnObject("Land_Construction_Crane", "7183.265625 322.843292 2230.389893", "0.000002 -0.000000 -0.000001", 1);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7191.399902 303.890015 2235.159912", "-141.906937 5.610000 0.000002", 0.999971);
//SpawnObject("StaticObj_Target_Concrete1", "7191.417480 324.607758 2230.344727", "179.999893 -0.000005 179.999893", 1);
//SpawnObject("StaticObj_Rail_ConcreteRamp", "7452.390137 356.228302 1988.724609", "21.999996 0.000000 -44.000000", 1.65);
//SpawnObject("StaticObj_Panels_Concrete", "7197.600098 303.908997 2231.610107", "37.999996 0.000000 90.000000", 1.6);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7003.801758 384.995789 1752.316406", "74.502182 -19.999998 -0.000001", 0.999943);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7182.580078 305.115997 2223.840088", "-141.906906 4.210001 0.000001", 0.999971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7173.830078 305.389008 2212.679932", "-141.906998 -1.789998 0.000001", 0.999971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7189.051270 303.897980 2236.949463", "-141.906937 5.610000 0.000002", 0.999971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7180.231445 305.123962 2225.629639", "-141.906906 4.210001 0.000001", 0.999971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7171.481445 305.396973 2214.469482", "-141.906998 -1.789997 0.000001", 0.99997);
//SpawnObject("dz/rocks/rock_wallh3.p3d", "6603.451172 334.877960 2042.159912", "-0.671395 0.000000 0.000000", 0.99998);
//SpawnObject("dz/rocks/rock_bright_spike1.p3d", "6629.080078 330.220062 2021.793823", "0.092325 0.000000 -0.000000", 0.999982);
//SpawnObject("dz/rocks/rock_bright_monolith2.p3d", "6678.103027 329.516724 2077.637451", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_bright_wallh3.p3d", "6758.491211 322.763977 2071.045166", "-3.043008 0.000000 -0.000000", 0.999976);
//SpawnObject("dz/rocks/rock_monolith1.p3d", "6762.030273 312.581940 2058.906738", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_wallv.p3d", "6656.971680 336.367065 2114.197754", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_bright_apart2.p3d", "6721.045410 322.479797 2049.443359", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_bright_spike1.p3d", "6715.472656 321.436401 2094.495850", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_bright_apart1.p3d", "6684.991211 322.644287 2035.902222", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/rocks/rock_apart2.p3d", "6657.313477 327.386658 2026.808716", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/plants_bliss/tree/t_acer_2s_summer.p3d", "6701.319824 352.889221 2054.922852", "0.000000 -0.000000 -0.000000", 3.65);
//SpawnObject("StaticObj_Wreck_Train_742_Red", "6390.844727 337.253906 1899.464844", "13.358417 0.000000 -0.000000", 1.59997);
//SpawnObject("Land_Wreck_hb02_aban1_red_DE", "6410.583496 335.411560 1898.521484", "41.616867 0.000000 -0.000000", 0.999985);
//SpawnObject("dz/structures/wrecks/vehicles/wreck_hb02_aban2_red.p3d", "6416.709961 333.970886 1901.431030", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/structures/wrecks/vehicles/wreck_lada_red.p3d", "6408.385742 333.142029 1891.233032", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7025.213379 311.571716 2154.762207", "-104.544624 -4.999996 -0.000001", 0.99997);
//SpawnObject("dz/structures_sakhal/walls/wall_tin8_lowred_8.p3d", "6394.893555 335.839172 1911.659668", "-0.708469 0.000000 0.000000", 0.999976);
//SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "6438.241211 342.457367 1911.959595", "0.000000 -0.000000 -0.000000", 2.5);
//SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "6450.599121 344.397003 1927.430786", "1.935994 0.000000 -0.000000", 2.49994);
//SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "6421.041992 322.395050 1884.307983", "0.000000 -0.000000 -0.000000", 2.5);
//SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "6430.049805 340.083527 1902.792114", "0.000000 -0.000000 -0.000000", 2.5);
//SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "6416.232422 329.044037 1887.307739", "0.000000 -0.000000 -0.000000", 2.5);
//SpawnObject("dz/plants_bliss/tree/t_piceaabies_2fb_summer.p3d", "6384.155762 335.877319 1776.000000", "0.000000 -0.000000 -0.000000", 1.9);
//SpawnObject("dz/plants_bliss/tree/t_piceaabies_2fb_summer.p3d", "6375.108398 333.163666 1764.667847", "0.000000 -0.000000 -0.000000", 1.9);
//SpawnObject("StaticObj_Bridge_Wood2", "6580.012695 392.919403 1476.453491", "57.804989 -36.999954 0.000003", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6562.026855 411.881165 1464.791382", "57.804989 -45.999966 0.000002", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6596.898438 383.348572 1486.968262", "57.804989 -18.999985 -0.000006", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6614.686523 379.376923 1497.867432", "57.804989 -5.200002 -0.000002", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6882.905762 406.300598 1664.508667", "64.805008 4.999999 -0.000001", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6896.462402 400.026184 1709.388672", "-122.577995 -1.770000 0.000000", 1.44994);
//SpawnObject("StaticObj_Bridge_Wood2", "6904.276855 405.663055 1674.870361", "64.805000 -7.999996 -0.000000", 1.04997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6913.364746 405.251068 1721.424561", "59.253822 1.400000 -0.000000", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6925.720215 405.420258 1728.823486", "59.253822 0.000000 -0.000000", 0.999939);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7454.899902 329.338654 2300.679443", "-0.639619 5.399902 -0.024736", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6914.909180 405.256012 1718.908081", "59.253822 1.400000 0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6927.264648 405.425232 1726.307007", "59.253834 -0.000001 -0.000000", 0.999971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6939.537109 405.382233 1731.824219", "74.502159 0.000002 -0.000000", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6938.696289 402.952332 1688.988037", "-115.460999 15.400002 -0.000002", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6926.115234 406.160400 1682.969727", "-115.460999 9.999996 0.000000", 0.999951);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6924.808594 406.123383 1685.617798", "-115.460999 9.999996 0.000003", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6912.078613 407.476166 1679.562866", "-115.460999 0.000000 0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6950.779785 398.484741 1694.907104", "-115.460999 20.399992 -0.000000", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6949.473633 398.489685 1697.555176", "-115.460999 20.399992 0.000005", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6952.310059 404.018951 1738.485962", "74.502174 -9.999996 -0.000001", 0.999944);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6953.138184 404.028198 1735.651733", "74.502174 -9.999996 -0.000000", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7024.642090 311.570618 2156.984375", "-104.544624 -4.999996 -0.000002", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7013.435059 310.549835 2153.980957", "-104.544983 -4.999996 -0.000001", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7023.862793 311.582581 2159.832275", "-104.544624 -4.999996 -0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7012.655273 310.561890 2156.828613", "-104.544983 -4.999997 -0.000000", 0.999932);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7027.659668 311.555176 2146.515381", "-104.544624 -4.999991 -0.000002", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7016.452637 310.534393 2143.511963", "-104.544983 -4.999996 -0.000001", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7026.880371 311.567139 2149.363281", "-104.544624 -4.999991 -0.000001", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7015.672852 310.546448 2146.359619", "-104.544983 -4.999998 -0.000001", 0.999933);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7025.992676 311.559753 2151.914307", "-104.544624 -4.999997 -0.000002", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7014.785645 310.538971 2148.910889", "-104.544983 -4.999996 -0.000001", 0.99997);
//SpawnObject("StaticObj_Wall_VilVar2_Red_4_D", "6402.214355 336.531799 1917.510742", "-45.998131 0.000000 0.000000", 0.999989);
//SpawnObject("StaticObj_Bridge_Wood2", "7455.997559 326.041168 2334.171875", "179.633972 3.000000 0.000001", 1.04997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7014.005859 310.551025 2151.758545", "-104.544983 -4.999998 -0.000001", 0.999933);
//SpawnObject("StaticObj_Bridge_Wood2", "7455.842773 323.849915 2354.456055", "179.633972 7.999995 0.000001", 1.04997);
//SpawnObject("StaticObj_Bridge_Wood2", "7455.499023 318.752441 2374.751709", "179.633972 13.999993 0.000001", 1.04997);
//SpawnObject("StaticObj_Panels_Concrete", "6458.250000 337.622253 1961.724731", "37.999996 0.000000 90.000000", 1.6);
//SpawnObject("StaticObj_Panels_Concrete", "6466.189941 336.706268 1947.959961", "49.000000 0.000000 90.000000", 1.6);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7453.992676 315.432251 2396.729248", "-0.642006 -15.600088 -0.025665", 0.999968);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7456.944336 315.441925 2396.802246", "-0.642004 -15.600097 -0.025661", 0.999969);
//SpawnObject("dz/structures/industrial/farms/barn_wood2.p3d", "6026.490723 400.663849 1271.123657", "-1.061671 0.000000 0.000000", 0.999984);
//SpawnObject("StaticObj_Bridge_Wood2", "7456.080078 326.873993 2315.750000", "179.633972 -1.999999 0.000001", 1.04997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6938.708984 405.372986 1734.658447", "74.502159 0.000000 -0.000000", 0.999944);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7454.145508 308.367126 2416.632324", "-0.642005 -15.600081 -0.025665", 0.999968);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7457.097168 308.376801 2416.705322", "-0.642004 -15.600097 -0.025661", 0.999969);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7457.851563 329.348328 2300.752197", "-0.639619 5.399899 -0.024734", 0.999969);
//SpawnObject("StaticObj_Misc_Pipes", "6024.680664 400.486938 1284.239868", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6913.384766 407.471222 1676.914795", "-115.460999 0.000000 0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "6937.390137 402.957275 1691.636108", "-115.460999 15.400002 0.000001", 0.99997);
//SpawnObject("StaticObj_Bridge_Wood2", "6508.609863 428.957458 1433.516113", "-123.194984 -19.999989 -0.000003", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6486.948730 420.299377 1419.444580", "-123.195007 -16.999989 0.000002", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6469.049805 414.441010 1408.699951", "-123.194969 -14.999991 0.000000", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "6454.744141 411.160858 1400.189941", "-123.194984 -5.399999 -0.000006", 1.39997);
//SpawnObject("dz/structures/industrial/farms/barn_wood2.p3d", "6042.546387 401.228424 1266.277466", "1.522017 0.000000 -0.000000", 0.999973);
//SpawnObject("StaticObj_Bridge_Wood2", "6442.877930 410.388184 1392.506592", "-123.194969 -0.400000 -0.000004", 1.39997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7059.164551 313.273132 2162.322998", "76.515495 -15.000000 -0.000000", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7078.371582 310.079620 2167.249512", "76.515495 -4.999998 0.000000", 0.849971);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7070.180176 310.828674 2165.059814", "76.515495 -9.999999 0.000002", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7059.892578 313.278107 2159.461426", "76.515495 -15.000000 0.000001", 0.99997);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7080.117188 309.795807 2164.576416", "76.515495 -4.999998 -0.000000", 0.999914);
//SpawnObject("StaticObj_Rail_Crossing_Block_25", "7070.908691 310.833649 2162.198486", "76.515495 -9.999998 0.000003", 0.999969);
//SpawnObject("StaticObj_Bridge_Wood2", "7241.276367 377.729645 1878.887573", "-123.194984 -22.399988 -0.000001", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7288.586914 372.658844 1908.254272", "57.804989 -12.999989 0.000010", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7311.241211 368.180511 1922.484131", "57.804989 -5.599987 -0.000002", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7222.686035 369.956818 1866.436035", "-123.194984 -16.999992 -0.000003", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7204.787109 364.098450 1855.691406", "-123.194969 -14.999991 -0.000004", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7190.481445 360.818298 1847.181396", "-123.194969 -5.399999 -0.000004", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7178.615234 360.045624 1839.498047", "-123.194969 -0.400000 -0.000004", 1.39997);
//SpawnObject("StaticObj_Bridge_Wood2", "7331.582520 366.762329 1934.970947", "-123.194984 -0.000003 -0.000000", 1.3);
//SpawnObject("StaticObj_Bridge_Wood2", "7364.531250 354.591309 1956.296631", "-123.194984 9.999999 0.000005", 1.8);
//SpawnObject("dz/structures/industrial/farms/barn_brick2.p3d", "6024.310547 397.803253 1283.350952", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("Land_Barn_Brick1", "6030.763672 394.245331 1299.873535", "34.795631 0.000000 -0.000000", 0.999941);
//SpawnObject("dz/structures/industrial/smokestacks/smokestack_brick.p3d", "6028.313477 392.195892 1278.331177", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("dz/structures/industrial/misc/misc_concretepanels.p3d", "6028.229492 397.746674 1289.963257", "0.000000 -0.000000 -0.000000", 1);
//SpawnObject("StaticObj_Rail_ConcreteRamp", "7426.931641 359.932953 1955.333862", "49.000000 0.000000 -43.999992", 1.65);
//SpawnObject("StaticObj_Rail_ConcreteRamp", "7480.997559 344.440521 2103.316895", "3.000000 0.000002 -43.999996", 1.65);
//SpawnObject("StaticObj_Rail_ConcreteRamp", "7472.232910 349.576111 2046.118408", "12.999999 0.000000 -43.999996", 1.65);
//SpawnObject("dz/structures/ruins/ruin_houseblock_corner_total.p3d", "6366.944824 334.544800 1832.028564", "-1.354700 0.000000 0.000000", 0.999993);
//SpawnObject("dz/structures/ruins/ruin_house_total.p3d", "6386.337402 332.853119 1870.087891", "-1.982077 0.000000 -0.000000", 0.999988);
//SpawnObject("StaticObj_Roadblock_CncBlocks_Long", "6306.458008 429.312134 1303.329956", "-96.854683 0.000000 -0.000000", 0.999991);
//SpawnObject("StaticObj_Roadblock_CncBlocks_Long", "6314.870605 429.206024 1304.776855", "-102.868767 0.000000 -0.000000", 0.999977);
//SpawnObject("dz/structures/industrial/mines/mine_building.p3d", "6337.314941 425.342560 1301.975098", "-2.076449 0.000000 -0.000000", 0.999982);
//SpawnObject("StaticObj_Bridge_Wood2", "7456.790039 325.385681 2284.443359", "179.633972 -1.999998 0.000001", 1.04997);
//SpawnObject("StaticObj_Bridge_Wood2", "7456.919922 325.214996 2263.649902", "179.633972 1.000000 0.000001", 1.04997);



	// FACTORIA:
	
		// HQ_Armory
		
		SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7315.170898 286.529938 2618.985596", "-2.199116 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Misc_Gunrack", "7314.320313 287.755035 2619.401611", "47.999928 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Wall_BackAlley_01_l_gap_F", "7315.805176 288.241333 2618.754395", "136.999496 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7317.384277 288.231964 2619.287109", "42.999920 0.000000 -0.000000", 1.135);
		SpawnObject("StaticObj_Furniture_flag_chernarus_wall", "7316.140137 289.489014 2619.179932", "136.999191 0.000000 -0.000000", 1.405);
		SpawnObject("dz/structures/furniture/eletrical_appliances/tv_a/tv_a.p3d", "7317.348145 288.432861 2619.999756", "1.946773 0.000000 -0.000000", 0.999993);
		SpawnObject("StaticObj_Furniture_pultskasou", "7316.052734 287.822266 2619.593262", "-40.999939 0.000000 0.000000", 1);
		SpawnObject("StaticObj_ammoboxes_single", "7316.044922 288.387756 2619.593994", "-40.999939 0.000000 0.000000", 1);
		SpawnObject("StaticObj_ammoboxes_stacked", "7311.642090 288.141876 2622.936035", "46.999928 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_box_c", "7316.840820 289.528687 2616.344238", "44.999992 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_closed_v2", "7316.880859 287.354797 2616.437012", "-135.000000 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_shelf_1side", "7314.096191 287.354736 2621.969971", "-135.000092 0.000000 -0.000000", 1.205);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v3", "7317.162109 287.345337 2616.147949", "-135.000092 0.000000 -0.000000", 1);
		SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7315.769043 286.061951 2618.725342", "-0.734784 0.000000 1.570796", 0.865);
		SpawnObject("StaticObj_Furniture_metalcrate", "7314.238281 288.022186 2621.723389", "44.999985 -0.000000 -0.000000", 0.6);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v1", "7317.427246 287.354797 2615.876953", "-135.000000 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_metalcrate", "7313.940430 287.589935 2621.474121", "44.999985 -0.000000 -0.000000", 0.6);
		SpawnObject("StaticObj_Billboard_Service", "7317.859863 289.067993 2620.320068", "46.799992 0.000000 0.000000", 0.375);
		SpawnObject("StaticObj_Furniture_metalcrate", "7314.782227 288.444275 2622.364258", "44.999985 -0.000000 -0.000000", 0.6);
		SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7315.061035 285.705963 2618.335693", "-0.741765 0.000000 0.000000", 1);
		SpawnObject("Flaming_Candle_WithLight", "7316.389160 288.240234 2620.293945", "0.000000 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_closed_v3", "7317.711914 287.354828 2615.596191", "-135.000031 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_open_v1", "7317.992188 287.354828 2615.302734", "-134.999863 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v2", "7318.285156 287.354828 2615.026367", "-135.000092 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_office_chair", "7318.768555 287.750854 2618.843262", "-41.399963 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_closed_v1", "7316.583984 287.354797 2616.715576", "-135.000092 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_carpet_big", "7316.677734 287.358002 2618.562744", "48.799988 0.000000 -0.000000", 0.745);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v1", "7316.019043 287.354797 2617.397705", "-135.000031 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_wall_board", "7315.350098 287.511993 2618.919922", "53.599991 0.000000 0.000000", 0.77);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v2", "7315.735352 287.354797 2617.685547", "-135.000000 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_locker_closed_blue_v3", "7315.453613 287.354767 2617.970703", "-135.000092 0.000000 -0.000000", 1);
		SpawnObject("dz/structures/furniture/chairs/ch_mod_h/ch_mod_h.p3d", "7315.572754 287.354767 2621.412842", "0.000005 -0.000000 -0.000000", 1);
		SpawnObject("dz/structures/furniture/school_equipment/vaulting_box_large.p3d", "7317.516602 287.346039 2619.481201", "2.356193 0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_radio_b", "7316.645020 288.240234 2619.994629", "-110.617210 0.000000 -0.000000", 0.99998);
		SpawnObject("StaticObj_Furniture_office_chair", "7318.374512 287.750854 2618.490723", "-43.199963 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Furniture_metalcrate", "7313.755371 288.022186 2621.338867", "44.999989 -0.000000 -0.000000", 0.6);
	
		// HQ_Roof_Guard
		
		SpawnObject("StaticObj_Misc_Antenna", "7313.287109 297.405670 2623.927979", "53.999973 0.000000 -0.000000", 1);
		SpawnObject("BookCandide", "7319.193848 294.071564 2617.349609", "0.000000 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Roadblock_Pillbox", "7317.208984 295.036774 2619.315186", "-133.635742 -0.000001 0.000001", 1);
		SpawnObject("Land_Mil_Fortified_Nest_Small", "7318.711426 295.273773 2617.754639", "-43.526279 0.000000 0.000000", 0.99998);
		SpawnObject("Flaming_Candle_WithLight", "7316.822266 293.985657 2619.691895", "0.000000 -0.000000 -0.000000", 1);		
		
		
		// Car_Mechanic
		
		SpawnObject("Land_RoadCone", "7316.784180 287.038849 2610.402344", "0.000000 -0.000000 -0.000000", 1);
		SpawnObject("dz/structures/specific/fuelstation/fuelstation_feed_nofuel.p3d", "7316.054199 287.040009 2610.972412", "0.785398 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7299.268066 287.039978 2599.838623", "-1.610748 0.000000 0.000000", 0.139999);
		SpawnObject("StaticObj_Furniture_patient_monitor", "7303.877930 287.084564 2609.935791", "0.000000 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Misc_TirePile", "7312.792480 291.270416 2613.145264", "-179.999893 0.000000 -0.000000", 1);
		SpawnObject("Land_Misc_Toilet_Mobile", "7312.453613 288.260834 2614.971924", "-41.999840 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Misc_TirePile_Large", "7309.944824 291.255249 2613.414795", "-35.999802 0.000000 0.000000", 1);
		SpawnObject("StaticObj_EngineCrane_01_F", "7305.018066 288.102966 2610.394775", "137.402451 0.000000 -0.000000", 0.999989);
		SpawnObject("StaticObj_ToolTrolley_02_F", "7303.572754 287.564117 2614.294678", "-88.048111 0.000000 0.000000", 0.999992);
		SpawnObject("StaticObj_Misc_TirePile", "7301.042969 295.571625 2604.410156", "0.000000 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Misc_TirePile_Group", "7307.334473 295.145050 2611.724609", "-11.348612 0.000000 0.000000", 0.999976);
		SpawnObject("StaticObj_Misc_TirePile_Large", "7298.942871 287.312317 2603.092285", "-35.999802 0.000000 0.000000", 1);
		SpawnObject("StaticObj_Decal_Runway_Num2", "7307.512207 287.040009 2607.757080", "-41.329998 0.000000 0.000000", 0.0999992);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7309.961914 287.040009 2604.160156", "138.599701 0.000000 -0.000000", 0.14);
		SpawnObject("StaticObj_Furniture_Workbench", "7305.426758 287.084564 2614.763672", "-42.820904 0.000000 0.000000", 0.999984);
		SpawnObject("Industrial_Fluoresent_Light", "7304.390137 289.716003 2614.840088", "137.988998 0.000000 90.000000", 0.999985);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7316.223145 287.040009 2609.722656", "138.307983 0.000000 -0.000000", 0.139997);
		SpawnObject("StaticObj_Furniture_Workbench", "7305.479980 286.984985 2617.750000", "49.862873 0.000000 -0.000000", 0.999976);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7313.082520 287.040009 2606.937988", "138.599701 0.000000 -0.000000", 0.14);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7306.854492 287.040009 2601.373291", "138.599701 0.000000 -0.000000", 0.14);
		SpawnObject("Land_RoadCone", "7299.433105 287.083435 2611.657471", "143.184738 0.000000 -0.000000", 0.999992);
		SpawnObject("Land_RoadCone", "7303.597168 287.083435 2606.994385", "53.999981 -0.000000 -0.000000", 0.999999);
		SpawnObject("Land_RoadCone", "7301.277344 287.083435 2605.111572", "35.999977 -0.000000 -0.000000", 0.999999);
		SpawnObject("dz/structures/furniture/various/rack_dz.p3d", "7308.681641 287.084564 2615.709229", "0.785398 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_office_table_a", "7309.764160 287.084564 2614.075439", "44.999992 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Furniture_ch_office_B", "7309.208496 287.084564 2614.726563", "-11.943913 0.000000 0.000000", 0.999979);
		SpawnObject("StaticObj_Decal_Runway_Num1", "7303.838867 287.040009 2604.381104", "-42.999985 0.000000 0.000000", 0.1);
		SpawnObject("StaticObj_ToolTrolley_02_F", "7307.580566 287.564056 2612.572510", "131.942657 0.000000 -0.000000", 0.999972);
		SpawnObject("StaticObj_Furniture_Vise", "7307.058594 287.897583 2613.363037", "-38.317039 0.000000 0.000000", 0.999984);
		SpawnObject("Land_Wreck_sed02_aban1_red_DE", "7302.810059 287.946014 2612.949951", "-45.000000 -24.699986 -0.000000", 1);
		SpawnObject("dz/structures/furniture/various/metal_cutting_saw.p3d", "7304.713867 287.760834 2616.953613", "2.349148 0.000000 -0.000000", 0.999946);
		SpawnObject("dz/structures/furniture/various/grinder.p3d", "7306.003906 287.860443 2614.348145", "-2.305167 0.000000 -0.000000", 0.999961);
		SpawnObject("dz/structures/furniture/various/drill.p3d", "7304.662598 287.860413 2615.515869", "2.311212 0.000000 -0.000000", 0.999985);
		SpawnObject("StaticObj_Decal_oilstain1", "7306.952148 287.040009 2608.406494", "-139.029388 0.000000 -0.000000", 0.999987);
		SpawnObject("StaticObj_Decal_Runway_Num3", "7311.077148 287.040009 2611.096924", "-42.107601 0.000000 0.000000", 0.0999994);
		SpawnObject("StaticObj_ToolTrolley_02_F", "7308.740723 287.519562 2609.781738", "-126.099892 0.000000 -0.000000", 0.999987);
		SpawnObject("Land_RoadCone", "7301.292480 287.038879 2602.867920", "0.000000 -0.000000 -0.000000", 1);
		SpawnObject("StaticObj_Decal_Runway_Line_1x30", "7303.280762 287.039948 2599.966553", "-1.610748 0.000000 0.000000", 0.139999);
		SpawnObject("StaticObj_Roadblock_CncBlock", "7316.311035 287.383240 2611.837646", "-44.200005 0.000000 0.000000", 1);

		// HALA TARGOWA
		
SpawnObject("land_treehouse_platform_no_rails2", "7323.689941 288.440002 2568.760010", "115.120003 0.000000 90.000000", 0.999993);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7321.930176 288.614990 2569.290039", "-166.999939 1.999999 0.000000", 0.999988);
SpawnObject("treehouse/models/treehouse_long_rail.p3d", "7328.430176 289.993011 2568.010010", "3.141591 0.087266 0.000000", 1);
SpawnObject("treehouse/models/treehouse_long_rail.p3d", "7333.399902 289.963989 2568.370117", "3.019420 0.087266 0.002967", 1);
SpawnObject("treehouse/models/treehouse_long_rail.p3d", "7323.830078 289.950012 2568.659912", "-2.844885 0.174533 -0.000000", 0.9);
SpawnObject("StaticObj_Furniture_workbench_DZ", "7297.649414 287.727356 2573.373779", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7301.324219 288.681854 2579.421387", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7301.288574 288.878723 2578.386963", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_GarbCont_Corner", "7300.620117 287.839996 2574.492188", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_GarbCont_Corner", "7300.628906 289.439606 2574.507324", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_shelf", "7300.220703 287.189972 2570.318115", "79.999931 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_shelf_DZ", "7307.719238 287.140015 2575.186279", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_shelf_DZ", "7308.734863 287.149994 2575.194580", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_shelfs_small", "7294.652832 287.289948 2578.161621", "23.999960 0.000000 90.000000", 1);
SpawnObject("StaticObj_Furniture_shelfs_small", "7309.728027 287.139984 2575.182373", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_shelfs_small_broken", "7296.103027 287.040009 2579.772461", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_case_d", "7305.350586 287.253693 2575.120117", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_case_d", "7304.602539 287.239960 2575.117676", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_case_d", "7306.093262 287.239960 2575.131836", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_case_d", "7306.838867 287.239960 2575.129883", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_box_c_multi", "7298.118652 287.040009 2570.976074", "-149.999054 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_bucket", "7321.355957 287.239960 2570.287842", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_box_c", "7296.857910 287.602264 2572.344238", "-107.999420 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_flowers_01", "7296.725586 288.201935 2573.342773", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_flowers_02", "7296.937988 287.249695 2578.761719", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_pokladna", "7297.111816 288.415894 2573.666748", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lekarnicka", "7301.550293 288.501312 2578.185303", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_radio_b", "7320.071289 288.189941 2575.681152", "-129.999466 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_tv_a", "7317.446777 288.408905 2576.578613", "-92.999504 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_vending_machine", "7300.544922 288.281433 2574.410156", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_cashier", "7298.649902 288.202179 2573.534424", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_icebox", "7316.523926 287.812225 2578.090088", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_pultskasou", "7319.899902 287.872253 2575.040039", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_pult", "7303.330078 287.739990 2575.271484", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_scale", "7307.131836 288.420013 2579.935547", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_hospital_transport_bed", "7322.508789 287.040009 2575.989502", "-31.999971 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_case_sink_a", "7301.979980 287.289948 2573.586914", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_fridge", "7302.201172 287.239960 2575.356689", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_fridge", "7301.605957 287.239960 2575.364014", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_anatomy_poster_1", "7319.353027 289.289459 2575.849365", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_anatomy_poster_2", "7318.461914 289.259735 2575.846436", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_bench", "7319.899902 287.339935 2573.362793", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_table", "7303.189941 287.598633 2573.353516", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_CncBlock", "7308.128418 287.383270 2581.208496", "93.999985 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_CncBlock", "7305.861328 287.660095 2581.471680", "-77.999748 -19.999947 -2.999956", 1);
SpawnObject("StaticObj_Rubble_Bricks2", "7307.914063 286.125000 2581.291260", "-10.999997 0.000000 0.000000", 1);
SpawnObject("StaticObj_Rubble_Metal3", "7309.138184 286.788605 2583.525635", "70.999893 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Pallets2", "7316.205078 288.360748 2581.434326", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Pallets3", "7316.164063 287.220184 2581.599121", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7336.100098 288.389008 2584.280029", "90.000000 0.000000 -0.000000", 1.4);
SpawnObject("treehouse/models/treehouse_long_rail.p3d", "7336.080078 290.839996 2582.520020", "1.570796 0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_bodybag2_c", "7335.072266 287.186523 2570.063232", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_bodybag1_orange", "7333.156250 287.196228 2569.782227", "158.636154 0.000000 -0.000000", 0.999989);
SpawnObject("AP_static_gore_bodybag2_d", "7334.773438 287.145752 2572.208008", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_corpse2", "7334.833496 287.163818 2572.273193", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_deadbody5", "7319.236328 287.643005 2578.233398", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_deadbody4", "7317.997070 287.446411 2577.033936", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("AP_static_gore_deadbody3", "7318.255859 287.382538 2578.282471", "130.366180 0.000000 -0.000000", 0.999983);
SpawnObject("AP_static_gore_deadbody_leg2", "7318.758789 288.050781 2579.388184", "-109.304039 0.000000 -0.000000", 0.999989);
SpawnObject("AP_static_gore_sleepbag1_orange", "7319.807129 287.361664 2578.838135", "-169.847076 0.000000 -0.000000", 0.999988);
SpawnObject("AP_static_gore_bodybag2_d", "7318.187012 287.380829 2577.283936", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Industrial_Fluoresent_Light", "7321.740234 291.085999 2572.610107", "0.000000 0.000000 -90.000000", 0.999996);
SpawnObject("Industrial_Fluoresent_Light", "7296.970215 289.986328 2575.050049", "-180.000000 90.000000 89.999992", 0.499996);
SpawnObject("Industrial_Fluoresent_Light", "7313.339844 289.365997 2571.229980", "0.000000 0.000000 -90.000000", 0.999996);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7336.015625 288.884918 2581.856445", "-90.854767 0.000000 -0.000000", 1.14999);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7336.025879 288.928101 2583.029785", "-90.854767 0.000000 -0.000000", 1.14999);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7335.855469 289.133820 2580.765869", "-80.385521 0.000000 0.000000", 1.39999);
SpawnObject("StaticObj_Misc_CinderBlocks", "7310.478027 287.892242 2581.337646", "-12.999968 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_SilageWall_Pole", "7324.959961 287.950012 2569.459961", "25.549274 0.000000 -0.000000", 0.999982);
SpawnObject("StaticObj_Wall_SilageWall_Pole", "7328.500000 288.000000 2569.070068", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_SilageWall_Pole", "7332.259766 287.950012 2569.419922", "-12.374393 0.000000 0.000000", 0.999996);
SpawnObject("StaticObj_Furniture_hospital_bench", "7323.411621 287.040009 2580.604980", "-35.163979 0.000000 0.000000", 0.99997);
SpawnObject("StaticObj_Garbage_Bin", "7327.559082 287.605804 2581.040771", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/structures/furniture/chairs/ch_mod_c/ch_mod_c.p3d", "7322.312500 287.040009 2577.443604", "-1.388231 0.000000 0.000000", 0.999992);
SpawnObject("StaticObj_Slum_Roof2", "7315.120117 288.281006 2581.949951", "-179.999924 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_shelfs_small_crushed", "7334.901367 287.040009 2580.063232", "-100.999565 0.000000 -0.000000", 1);
SpawnObject("StaticObj_chair_crushed", "7333.875977 287.040039 2580.270752", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_chair_leisure_crushed", "7335.340332 287.040009 2579.799805", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_tv_a", "7313.567383 288.704651 2573.012207", "-92.999504 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7299.547852 290.431427 2574.400146", "90.000008 84.000076 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7299.625000 290.580994 2575.489502", "-89.999954 89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7299.606445 290.631378 2577.620117", "-89.999954 -89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7299.570801 290.581390 2576.570068", "-89.999435 89.944038 -0.000104", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7299.619629 290.631378 2578.694092", "-89.999954 89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7299.689453 290.688568 2579.691650", "-89.999954 89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7297.323730 290.581848 2575.651611", "179.999893 89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_IndCnc_Pole", "7297.008789 288.939270 2578.167969", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_IndCnc_Pole", "7296.830078 288.868988 2575.050049", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7297.461914 290.627014 2578.485840", "179.999893 -89.944038 179.999893", 1);
SpawnObject("StaticObj_Furniture_shelf", "7304.360840 287.189972 2579.464111", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_shelf", "7302.663086 287.189972 2579.459961", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_Cnc_5", "7305.789063 287.740143 2574.404541", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_carpet_big", "7299.189941 287.260010 2578.066895", "-11.999992 0.000000 0.000000", 1);
SpawnObject("Land_Wall_BackAlley_01_l_gate_F", "7311.799805 288.897888 2574.508057", "0.000000 0.000000 0.000000", 1);
SpawnObject("Land_Wall_BackAlley_01_l_gate_F", "7325.653320 288.684967 2581.429932", "0.000000 0.000000 0.000000", 1);
SpawnObject("Land_Wall_Gate_Camp", "7330.986328 288.570770 2581.420410", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7335.599609 288.681854 2580.202393", "72.999756 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7335.091797 288.689056 2581.021729", "-139.000565 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7327.750000 288.689056 2581.424805", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7334.222168 288.681854 2581.360352", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7323.662598 288.689056 2581.327881", "-16.999990 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7322.913574 288.681854 2580.937744", "-31.999971 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7322.097656 288.681854 2580.328857", "134.999222 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7313.750000 288.689056 2574.639893", "-17.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_rack_DZ", "7313.562500 287.240021 2572.836182", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_hospital_bench", "7319.228027 287.239960 2569.964600", "-175.999710 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_hospital_bench", "7320.598145 287.239960 2569.925537", "176.000107 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_medical_table", "7317.155762 287.239960 2571.318359", "41.999939 0.000000 0.000000", 1);
SpawnObject("Land_Wreck_S1023_Medic_Beige", "7331.419922 286.858490 2571.149902", "-162.530960 0.000000 -0.000000", 0.999985);
SpawnObject("StaticObj_Furniture_hospital_transport_bed", "7316.281738 287.239960 2571.170654", "151.999054 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_wall_hanger", "7319.846680 289.039978 2569.580078", "0.000000 0.000000 0.000000", 1);
SpawnObject("Land_BusStation_wall_bench", "7312.809082 288.005890 2571.103760", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_beaker", "7320.133789 288.249847 2573.827148", "-25.141848 0.000000 0.000000", 0.999999);
SpawnObject("StaticObj_Furniture_lab_bunsen", "7319.946777 288.189941 2574.062500", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_cylinder_beaker", "7320.033691 288.379425 2573.663818", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_dropper", "7324.146973 287.084930 2572.737793", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_erlenmeyer_flask", "7319.853516 288.249756 2573.938721", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_microscope", "7319.724121 288.189941 2573.608398", "11.763053 0.000000 -0.000000", 0.999991);
SpawnObject("StaticObj_Furniture_lab_teacher_bench", "7313.689453 287.252594 2570.911865", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lab_volume_beaker", "7320.164551 288.262207 2573.711426", "78.163345 0.000000 -0.000000", 0.999998);
SpawnObject("StaticObj_WhiteBoard_Laboratory", "7317.506836 288.210449 2575.424316", "18.999981 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7313.188965 287.839264 2573.019287", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7313.137695 287.839264 2573.980957", "-89.999985 0.000000 0.000000", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7310.775391 288.167938 2577.453613", "6.999998 0.000000 0.000000", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7311.128418 287.538147 2577.440186", "-173.999954 0.000000 -0.000000", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7310.299316 287.538147 2577.492432", "-0.999999 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_5x", "7310.434082 288.001984 2570.531250", "5.999996 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_shelfs_small_crushed", "7309.077637 287.252106 2570.116943", "-100.999565 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7298.391113 289.693726 2573.919922", "0.000000 0.000000 -89.999985", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7299.744629 290.659637 2576.633057", "-149.999954 89.944038 179.999893", 1);
SpawnObject("StaticObj_Furniture_box_c", "7297.811035 288.489655 2573.350098", "-51.999901 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7313.169922 289.988739 2571.234131", "-90.000000 0.000000 90.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7313.124512 290.044769 2572.778564", "-87.999992 0.000000 90.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7313.729980 290.644379 2573.160889", "7.000976 89.944038 -0.000105", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7319.831543 290.489044 2575.340576", "179.999893 -64.999741 90.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7313.679688 290.588623 2571.346436", "179.999893 89.944038 179.999893", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7316.777832 290.631378 2575.111084", "0.999997 68.999962 103.999573", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7315.398438 290.830994 2573.512939", "-69.000244 77.999855 -41.000183", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7315.539063 290.943481 2571.074463", "-96.999916 81.999916 179.999893", 1);
SpawnObject("StaticObj_Slum_Roof3", "7318.589844 288.913483 2572.675781", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7314.645996 290.839020 2572.179688", "118.999527 -81.999794 0.000015", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7314.673828 288.881805 2574.971436", "-22.999943 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7316.558105 288.731842 2575.715332", "-21.999964 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7301.304688 288.831818 2577.795898", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7301.309570 288.831818 2576.729248", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7315.573730 288.789032 2575.327148", "156.999435 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7301.253418 288.839020 2575.760742", "-87.999641 0.000000 0.000000", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7318.733398 287.338196 2581.770996", "22.999987 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_5x", "7322.484863 288.001984 2582.553711", "-90.999680 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_3x", "7303.544434 287.747894 2581.426270", "4.999990 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_carpet_big", "7303.401367 290.239014 2580.629883", "-12.999652 89.960434 166.999664", 0.999999);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7308.955566 289.238922 2581.016113", "0.000000 11.999985 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7301.944824 286.462006 2580.959961", "0.000000 9.999996 0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_gap_F", "7303.635742 288.576355 2581.535645", "-1.999998 28.999968 -0.000000", 1);
SpawnObject("StaticObj_Furniture_vending_machine", "7320.968262 288.281433 2575.353516", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Sign_Build_BlueCross", "7320.532227 289.411987 2581.479980", "-88.999359 0.000000 -19.999954", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7314.580078 287.338196 2581.514648", "16.999990 0.000000 0.000000", 1);
SpawnObject("Land_Roadblock_WoodenCrate", "7313.503906 287.660004 2581.167725", "-80.999733 -28.999971 -0.000000", 1);
SpawnObject("StaticObj_Roadblock_CncBlock", "7305.861328 287.660095 2581.471680", "-77.999748 -19.999943 -2.999956", 1);
SpawnObject("StaticObj_Slum_Roof4", "7323.279785 288.484009 2576.250000", "90.000000 0.000000 -0.000000", 0.7);
SpawnObject("dz/structures/furniture/decoration/lekarnicka/lekarnicka.p3d", "7322.930176 286.709991 2577.669922", "-2.495820 -1.569883 -1.570796", 1);
SpawnObject("StaticObj_Furniture_hospital_bench", "7322.362793 287.040009 2579.464600", "-63.254356 0.000000 0.000000", 0.999963);
SpawnObject("StaticObj_Furniture_lab_cylinder_beaker", "7319.979492 288.379425 2573.786865", "-70.932037 0.000000 0.000000", 0.999993);
SpawnObject("StaticObj_Furniture_lab_beaker", "7320.205566 288.249847 2574.149658", "-36.478348 0.000000 0.000000", 0.999997);
SpawnObject("StaticObj_Furniture_lab_beaker", "7319.968750 288.306549 2574.367920", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_hospital_transport_bed", "7333.330078 287.368988 2570.959961", "144.998932 0.000000 -90.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_gap_F", "7334.870117 289.341003 2571.030029", "90.000000 -17.799982 0.000000", 1.5);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7335.310059 288.489014 2573.870117", "-90.000000 10.199991 -0.000000", 1);
SpawnObject("land_treehouse_platform_no_rails2", "7331.479980 288.480011 2568.179932", "174.999908 89.947655 179.999908", 1);
SpawnObject("land_treehouse_platform_no_rails2", "7334.370117 288.463013 2568.530029", "169.800003 89.951538 -179.999924", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7329.439941 288.273987 2567.929932", "-2.475960 0.000000 0.000000", 0.999994);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7328.470215 288.299011 2567.959961", "-0.624394 1.999999 0.000000", 0.999988);
SpawnObject("land_treehouse_platform_no_rails2", "7326.470215 288.451996 2567.909912", "3.000000 89.923386 -179.999924", 1);

		// STRAZNIK KONTENER
		
SpawnObject("StaticObj_Wall_Wood2_5_D", "7327.649902 287.009003 2591.399902", "28.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Wall_Wood2_5_pole", "7329.799805 287.692993 2590.189941", "-157.603867 0.000000 -0.000000", 0.999995);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7336.017578 288.443024 2589.283936", "-89.999985 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Chair_Plastic", "7330.540039 287.419006 2592.169922", "79.973106 -0.010000 0.000000", 0.799996);
SpawnObject("StaticObj_Furniture_box_c", "7336.439941 288.049988 2598.340088", "-7.599993 0.000000 0.020000", 1);
SpawnObject("StaticObj_Furniture_box_c", "7335.438965 289.938843 2592.777100", "-99.004120 0.000000 -0.000000", 0.989996);
SpawnObject("treehouse/models/treehouse_long_rail.p3d", "7338.799805 289.440247 2597.959961", "-0.010472 0.010472 -0.006981", 1.2);
SpawnObject("Land_Misc_Well_Pump_Yellow", "7334.839844 287.756012 2598.850098", "-153.429993 0.000000 -0.000000", 1);
SpawnObject("land_treehouse_stairs_curved_short", "7331.970215 288.779999 2592.379883", "-37.999996 0.000000 0.000000", 0.8);
SpawnObject("Land_Misc_FireBarrel_Yellow", "7332.600098 288.264008 2597.250000", "-48.447544 0.000000 0.000000", 0.999995);
SpawnObject("dz/structures/furniture/chairs/ch_mod_h/ch_mod_h.p3d", "7334.870117 287.161011 2595.050049", "-1.239707 0.000000 0.000000", 1);
SpawnObject("dz/structures/furniture/tables/conference_table_a/conference_table_a.p3d", "7335.259766 287.181671 2595.179932", "-1.570796 0.000000 -0.000000", 1);
SpawnObject("dz/structures/furniture/decoration/wallboards/picture_b_02/picture_b_02.p3d", "7335.709961 287.161011 2597.520020", "-1.574287 -0.000175 -0.034383", 1);
SpawnObject("StaticObj_Furniture_flowers_02", "7333.422363 289.602020 2592.789063", "-23.000000 0.000000 0.000000", 0.957);
SpawnObject("StaticObj_Wall_Wood2_5_pole", "7332.660156 288.170990 2591.219971", "0.000000 -0.000000 -0.000000", 1.5);
SpawnObject("StaticObj_flowerpot", "7333.620117 289.562012 2593.189941", "0.000000 -10.959996 -0.000000", 0.9);
SpawnObject("StaticObj_flowerpot", "7333.160156 287.149994 2592.830078", "132.999969 76.659866 0.000004", 0.9);
SpawnObject("StaticObj_Furniture_almara", "7335.259766 287.161011 2593.729980", "90.000000 0.000000 -0.000000", 1);
SpawnObject("dz/structures/furniture/decoration/wallboards/picture_d_02/picture_d_02.p3d", "7334.259766 287.674011 2598.159912", "3.141591 0.000000 0.040143", 1);
SpawnObject("StaticObj_Furniture_radio_b", "7335.288574 287.878815 2595.539307", "-139.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_flowers_01", "7333.479980 289.601990 2593.429932", "0.000000 -0.000000 -0.000000", 1.07);
SpawnObject("treehouse/models/treehouse_platform_no_rails.p3d", "7333.290039 289.739990 2593.070068", "1.595056 -1.221730 -0.000000", 0.3);
SpawnObject("StaticObj_Furniture_lekarnicka", "7335.950195 288.661987 2592.350098", "90.000000 0.000000 -0.000000", 1);
SpawnObject("Land_Misc_DogHouse", "7344.626465 288.109100 2600.122070", "-63.430496 0.000000 0.000000", 0.999936);
SpawnObject("StaticObj_Slum_Roof3", "7328.660645 288.259064 2594.698242", "161.009109 0.000000 -0.000000", 0.599988);
SpawnObject("treehouse/models/stairs01_short.p3d", "7331.069824 286.880005 2594.489990", "-0.191114 0.000000 0.000000", 0.8);
SpawnObject("StaticObj_Misc_Bench2", "7332.845215 287.517914 2595.440186", "-83.029610 0.000000 0.000000", 0.999979);
SpawnObject("StaticObj_Misc_WoodTable_Indoor", "7327.906250 287.418243 2593.972656", "-138.434219 0.000000 -0.000000", 0.999972);
SpawnObject("Land_Misc_Table_Market_Spawn", "7328.737305 287.515869 2596.734131", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7332.450195 288.079987 2590.810059", "-167.125000 6.999984 179.989975", 1.39999);
SpawnObject("treehouse/models/treehouse_platform2.p3d", "7335.029785 287.040009 2599.850098", "-2.007129 0.000000 1.570796", 1);
SpawnObject("dz/structures/roads/panels/panel_concrete_2.p3d", "7338.783691 288.009308 2597.971924", "-1.588249 0.000000 1.570796", 1);
SpawnObject("StaticObj_Furniture_shelfs_small", "7334.765137 287.040009 2600.196289", "-117.150070 0.000000 -0.000000", 0.999993);
SpawnObject("StaticObj_Furniture_shelfs_small", "7330.210449 287.040009 2596.635254", "-0.878570 0.000000 0.000000", 0.999995);
SpawnObject("StaticObj_Furniture_table_DZ", "7331.569824 287.165985 2592.659912", "158.014648 0.000000 -0.000000", 0.999988);
SpawnObject("StaticObj_flowerpot", "7331.580078 287.616180 2592.919434", "0.000000 0.000000 -0.000005", 0.9);
SpawnObject("StaticObj_flowerpot", "7331.447754 287.616180 2592.632813", "0.000000 0.000000 -0.000005", 0.6);
SpawnObject("land_treehouse_platform_no_rails", "7337.020020 287.739990 2598.870117", "-54.999996 0.000000 73.999992", 0.85);
SpawnObject("StaticObj_Furniture_box_c", "7331.950195 287.339996 2591.659912", "151.999985 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_box_c", "7336.426270 287.246918 2599.012695", "47.399990 0.000000 0.000000", 1);
SpawnObject("StaticObj_flowerpot", "7331.799805 287.735992 2592.300049", "-175.999969 76.659904 -0.000004", 0.9);
SpawnObject("StaticObj_flowerpot", "7331.330078 287.765991 2592.780029", "78.000000 76.659904 -0.000014", 1.1);
SpawnObject("StaticObj_Furniture_box_c", "7336.189941 287.339996 2599.459961", "64.400002 5.999996 -61.000000", 1);
SpawnObject("StaticObj_Furniture_flowers_01", "7332.305664 287.040009 2592.965576", "0.000000 -0.000000 -0.000000", 1.07);
SpawnObject("StaticObj_Furniture_box_c", "7336.450195 287.747009 2598.610107", "57.899990 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_WoodPile_Forest1", "7337.503906 287.791534 2589.645264", "-1.600000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_WoodBlock", "7336.115234 287.384216 2600.739014", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/structures/residential/misc/misc_woodreserve.p3d", "7340.057617 287.039825 2600.092773", "1.494818 0.000000 0.000000", 0.999991);
SpawnObject("treehouse/models/treehouse_platform_no_rails2.p3d", "7340.040039 288.040009 2598.209961", "-1.623680 0.000000 1.570796", 1);
SpawnObject("StaticObj_Wall_Wood2_5_nolc", "7326.439941 286.949005 2594.760010", "115.045990 0.000000 -0.000000", 0.999989);
SpawnObject("StaticObj_Wall_Wood2_5_pole", "7325.390137 287.816010 2592.570068", "-157.603867 0.000000 -0.000000", 0.999996);
SpawnObject("StaticObj_Furniture_metalcrate", "7321.104980 287.040009 2600.202637", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_3x", "7320.916504 287.747894 2599.008301", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_5x", "7320.638184 288.001953 2597.177002", "-92.727112 0.000000 -0.000000", 0.999976);
SpawnObject("AP_static_gore_bone_pile2b", "7345.559570 287.106873 2599.091553", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("treehouse/models/treehouse_platform_no_rails2.p3d", "7335.680176 288.287994 2598.770020", "-0.095993 0.000000 1.570796", 0.9);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7335.700195 290.114014 2598.000000", "-96.000008 0.000000 90.000000", 1);
SpawnObject("dz/structures/furniture/folding_beds/foldingbed_open.p3d", "7335.169922 287.161011 2597.060059", "-0.086743 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_carpet_big", "7334.649902 287.170990 2596.629883", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_table_drawer", "7334.080078 287.173004 2597.669922", "174.979950 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Pillow_Old", "7344.720215 287.088013 2599.709961", "102.823936 0.000000 -0.000000", 2);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7332.450195 288.079987 2590.810059", "-167.125000 6.999982 179.989975", 1.39999);
SpawnObject("StaticObj_Furniture_box_c", "7335.555176 289.854523 2591.703125", "85.999977 0.000000 0.000000", 1);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7335.830078 288.343994 2595.164063", "1.522568 0.000000 -1.570796", 0.999961);
SpawnObject("land_treehouse_platform_no_rails", "7336.520020 287.117004 2599.870117", "136.189941 0.000000 108.999985", 0.85);
SpawnObject("StaticObj_Furniture_box_c", "7335.185547 287.346039 2589.175293", "85.999977 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_box_c", "7335.812500 287.156769 2589.070557", "85.999977 0.000000 0.000000", 0.6);
SpawnObject("StaticObj_Wall_Wood2_5_pole", "7334.741699 287.425842 2588.690186", "68.952591 -9.999998 6.000000", 0.99998);
SpawnObject("StaticObj_Wall_BackAlley_01_l_gap_F", "7336.043945 288.509796 2591.248779", "90.739639 0.000000 -0.000000", 0.999941);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7336.108887 285.936493 2592.355713", "1.609834 0.000000 -1.570796", 0.999961);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7334.331055 290.024658 2591.242188", "179.999969 0.000000 90.000000", 0.9);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7336.107910 286.897644 2592.289795", "1.609834 0.000000 -1.570796", 0.999961);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7334.280762 287.876953 2591.665527", "0.000000 -1.570106 -1.570796", 0.999961);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7335.285645 287.939301 2593.246094", "-1.531758 -1.570308 -1.570796", 0.999961);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7334.525391 288.368927 2598.906738", "2.447597 0.000000 -1.570796", 0.699961);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7335.728027 288.391785 2589.921143", "-91.125000 6.999979 179.989975", 1.39999);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7335.326172 289.602814 2598.002197", "173.000000 89.965729 -0.000000", 1);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7333.606445 288.439697 2596.424316", "1.609834 0.000000 -1.570796", 0.999961);
SpawnObject("StaticObj_Wall_BackAlley_01_l_1m_F", "7334.252930 289.611145 2597.533936", "178.999969 89.960434 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_02_l_1m_F", "7332.994141 288.564606 2590.463379", "178.412994 20.229998 179.999985", 0.849979);
SpawnObject("StaticObj_chair", "7335.397949 289.567047 2596.001709", "87.866432 0.000000 -0.000000", 0.999957);
SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2sb_trail_r_summer.p3d", "7337.947754 293.351074 2595.067139", "0.000000 -0.000000 -0.000000", 1.8);
SpawnObject("StaticObj_Furniture_box_c", "7332.114258 287.320801 2590.331055", "85.999977 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_flowers_02", "7332.082031 287.623901 2590.200684", "-103.099495 0.000000 -0.000000", 0.956982);
SpawnObject("dz/structures_bliss/residential/slums/slum_roof3.p3d", "7334.775391 290.036407 2596.740234", "1.564673 0.000000 -0.000000", 0.549994);
SpawnObject("Flaming_Candle_WithLight", "7335.318848 287.931366 2595.306641", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_BackAlley_01_l_gap_F", "7336.006836 288.488861 2594.494873", "90.739639 0.000000 -0.000000", 0.999941);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7336.071777 285.915558 2595.601807", "1.609834 0.000000 -1.570796", 0.999961);
SpawnObject("dz/structures_bliss/walls/wall_backalley_02_l_1m_f.p3d", "7336.070801 286.876709 2595.535889", "1.609834 0.000000 -1.570796", 0.999961);
SpawnObject("StaticObj_Furniture_kitchen_table_a", "7334.078125 289.540009 2595.887695", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/structures/residential/misc/misc_tree_pavement2.p3d", "7326.234375 286.852386 2592.861084", "-2.698065 0.000000 -0.000000", 0.999986);
SpawnObject("Flaming_Candle_WithLight", "7333.976563 290.356262 2595.912598", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_sorbus_2s_summer.p3d", "7326.505859 283.442413 2593.199463", "0.000000 -0.000000 -0.000000", 0.45);
SpawnObject("dz/plants_bliss/clutter/c_grassflowersyellowtall_summer.p3d", "7326.269531 287.117065 2592.853516", "2.419026 0.000000 -0.000000", 0.5);

		// BRAMA A
		
SpawnObject("StaticObj_Wall_Barricade1_10", "7396.592773 287.040009 2600.362305", "139.999329 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Garbage_Bin", "7374.843750 287.655731 2623.429688", "31.999971 0.000000 0.000000", 1);
SpawnObject("StaticObj_Garbage_Container", "7374.707520 287.681580 2626.673828", "-3.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Garbage_Container_Paper", "7374.884277 287.731567 2624.734375", "5.999996 0.000000 0.000000", 1);
SpawnObject("StaticObj_Garbage_Pile3", "7373.358398 287.309204 2628.817383", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Garbage_Pile4", "7369.983887 287.040009 2628.725586", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Slum_Roof1", "7375.103027 288.456024 2625.401123", "-90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_bed_large_metal_broken", "7388.694824 287.040009 2614.485352", "10.999997 0.000000 0.000000", 1);
SpawnObject("StaticObj_bed_large_metal", "7390.008301 288.559998 2613.278809", "64.999420 55.999947 -170.000427", 1);
SpawnObject("StaticObj_bed_large_metal_crushed", "7390.524902 287.040009 2613.219971", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_metalcrate", "7389.737305 287.439911 2612.880371", "178.000381 0.000000 90.000000", 1);
SpawnObject("StaticObj_Misc_NoticeBoard2", "7373.964355 287.861694 2619.357910", "-89.999680 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Barricade", "7395.716797 287.657135 2608.328125", "47.999844 0.000000 0.000000", 1);
SpawnObject("Land_Misc_FireBarrel_Blue", "7394.719727 288.274078 2605.788330", "162.152786 0.000000 -0.000000", 0.999991);
SpawnObject("StaticObj_Furniture_wall_board_03", "7373.904297 288.089752 2619.350098", "90.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_ConcretePanels", "7388.033691 287.749969 2611.736084", "6.999998 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_ConcreteBlock2", "7379.369629 287.425690 2625.857178", "58.999805 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_ConcreteBlock2", "7376.640137 287.425690 2628.639893", "32.999969 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Hedgehog_Concrete", "7375.156738 287.590576 2629.902100", "0.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Hedgehog_Concrete", "7380.583008 287.590576 2624.770996", "109.999870 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_Hedgehog_Concrete", "7378.143066 287.590576 2627.392578", "90.000000 0.000000 -0.000000", 1);
SpawnObject("land_treehouse_platform_no_rails", "7393.220215 287.660004 2598.879883", "32.999996 -2.999999 90.000000", 1);
SpawnObject("land_treehouse_long_rail", "7392.330078 287.419006 2598.820068", "151.000000 -31.999990 87.000000", 0.8);
SpawnObject("Land_Mil_GuardTower", "7393.259766 289.406006 2604.729980", "-82.954422 0.000000 0.000000", 0.999893);
SpawnObject("StaticObj_Slum_Roof6", "7396.350098 289.072998 2604.350098", "0.000000 -0.000000 -0.000000", 0.7);
SpawnObject("StaticObj_Furniture_foldingbed_matress", "7396.540527 286.894287 2604.028564", "-62.361694 0.000000 0.000000", 0.999989);
SpawnObject("dz/structures/furniture/beds/pillow_flannel.p3d", "7397.241211 287.275879 2603.885742", "-0.000000 0.000000 0.000000", 0.999999);
SpawnObject("dz/structures/furniture/beds/pillow_old.p3d", "7397.304688 287.245667 2604.156494", "0.174533 -0.401426 0.069813", 1.2);
SpawnObject("dz/structures/furniture/chairs/ch_mod_c/ch_mod_c.p3d", "7395.278320 287.040009 2605.312744", "1.104941 0.000000 -0.000000", 0.999977);
SpawnObject("dz/structures_bliss/ruins/proxy/table_crushed.p3d", "7394.041992 287.040009 2602.863037", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("treehouse/models/treehouse_platform_no_rails2.p3d", "7396.867188 287.040009 2603.727295", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_Hedgehog_Concrete", "7388.430176 287.590576 2614.279053", "-117.606873 0.000000 -0.000000", 0.999955);
SpawnObject("dz/structures/furniture/school_equipment/flag_chernarus_pole.p3d", "7399.700195 294.033997 2606.310059", "-0.663225 0.000000 0.000000", 1);
SpawnObject("land_treehouse_long_rail", "7400.069824 290.109985 2603.479980", "-82.000000 -13.999997 90.000000", 1.29999);
SpawnObject("land_treehouse_platform3", "7399.790039 288.329987 2602.199951", "141.623917 -58.999985 0.000003", 0.999994);
SpawnObject("dz/structures_bliss/industrial/misc/misc_cinderblocks.p3d", "7401.611816 287.039978 2603.287842", "0.669494 0.000000 -0.000000", 0.999944);
SpawnObject("StaticObj_Misc_WoodenCrate_3x", "7398.188477 288.138367 2605.544189", "136.149872 0.000000 -0.000000", 0.869969);
SpawnObject("StaticObj_Misc_WoodenCrate", "7399.220215 288.054993 2604.979980", "0.000000 7.999994 -12.999993", 1);
SpawnObject("land_treehouse_platform_no_rails", "7399.290039 287.720001 2606.040039", "-33.999981 -88.019592 87.999969", 0.9);
SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2sb_summer.p3d", "7378.219727 287.040039 2602.583008", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_pyruscommunis_3s_summer.p3d", "7371.605469 287.040039 2605.046875", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_fagussylvatica_2s_summer.p3d", "7388.704102 287.039978 2599.705811", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_malusdomestica_3s_summer.p3d", "7367.931152 292.929260 2632.474121", "0.000000 -0.000000 -0.000000", 2);
SpawnObject("dz/plants/tree/t_fagussylvatica_1s.p3d", "7371.711426 287.040039 2631.394287", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Flaming_Candle_WithLight", "7397.636719 287.962585 2605.055908", "0.000000 -0.000000 -0.000000", 1);

		// MOST
		
SpawnObject("land_treehouse_platform2", "7341.020020 285.770996 2644.649902", "-10.000000 0.000000 -30.999996", 1);
SpawnObject("StaticObj_Bridge_Wood_50", "7346.669922 284.354004 2648.120117", "90.061752 0.000000 -0.000000", 0.999983);
SpawnObject("treehouse/models/treehouse_platform3.p3d", "7344.876465 286.937683 2638.000244", "0.000000 -0.000000 -0.000000", 0.8);
SpawnObject("treehouse/models/treehouse_platform2.p3d", "7346.770020 286.813995 2657.709961", "0.000000 0.174533 0.000000", 1);
SpawnObject("land_treehouse_platform_no_rails", "7339.740234 284.028992 2649.270020", "91.549194 -13.000000 -0.000000", 0.999939);
SpawnObject("treehouse/models/treehouse_platform2.p3d", "7346.799805 286.859009 2639.699951", "0.000000 -0.174533 -0.000000", 1);

		// CMENTARZ
		
SpawnObject("dz/structures/walls/wall_stoned.p3d", "7306.232422 287.021057 2647.708496", "0.000000 -0.000000 -0.000000", 0.25);
SpawnObject("dz/structures/walls/wall_stoned.p3d", "7306.514648 287.014740 2651.006592", "0.000000 -0.000000 -0.000000", 0.25);
SpawnObject("dz/structures/walls/wall_stoned.p3d", "7306.306641 287.014740 2652.984375", "0.000000 -0.000000 -0.000000", 0.25);
SpawnObject("dz/structures/walls/wall_stoned.p3d", "7306.019531 287.017670 2649.580322", "0.000000 -0.000000 -0.000000", 0.15);
SpawnObject("dz/rocks/stone5.p3d", "7306.678711 286.868286 2646.463135", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Flaming_Candle_NoLight", "7306.638672 287.453339 2646.334473", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Flaming_Candle_NoLight", "7306.544922 287.375214 2646.215088", "0.000000 -0.000000 -0.000000", 0.75);
SpawnObject("StaticObj_Cemetery_Tombstone3", "7303.512695 287.605164 2651.503906", "86.296600 2.999997 -2.999998", 0.99998);
SpawnObject("StaticObj_Cemetery_Tombstone10", "7303.441895 287.480957 2649.804932", "79.876991 -3.000000 3.999999", 0.699982);
SpawnObject("dz/structures/specific/cemeteries/cemetery_tombstone11.p3d", "7303.583496 287.083923 2647.964844", "1.283772 -0.017453 -0.069813", 0.90149);
SpawnObject("dz/structures/specific/cemeteries/cemetery_tombstone3.p3d", "7303.329102 286.980652 2653.759277", "1.708040 -0.104720 -0.000000", 0.89999);
SpawnObject("StaticObj_Wall_Wood1D_5", "7304.832520 287.020386 2645.657471", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_Wood1D_5", "7307.331543 287.020386 2648.177002", "-90.133636 0.000000 -0.000000", 0.999915);
SpawnObject("StaticObj_Wall_Wood1D_5_2", "7307.533691 287.021240 2654.026123", "-84.927124 0.000000 0.000000", 1);
SpawnObject("dz/structures/walls/wall_gate_wood3.p3d", "7307.288086 286.959473 2651.153564", "-1.559538 0.000000 0.000000", 0.999962);
SpawnObject("dz/plants/tree/d_fagussylvatica_stump.p3d", "7309.200684 287.142090 2647.218994", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_pyruscommunis_2s_summer.p3d", "7304.856934 287.039948 2656.119385", "0.157080 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_pyruscommunis_2s_summer.p3d", "7308.691406 287.040009 2643.943848", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/plants_bliss/tree/t_betulapendulae_2s_summer.p3d", "7307.471680 287.040009 2635.742920", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_picture_e", "7303.669922 287.285004 2651.500000", "87.566986 -60.279976 -1.900000", 0.999985);
SpawnObject("Flaming_Candle_WithLight", "7306.546875 287.467621 2646.299805", "71.999977 0.000000 -0.000000", 1.35);

		// ULICE
		
SpawnObject("StaticObj_Road_Sidewalk4_Narrow_8m", "7338.056152 286.895050 2620.662109", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Land_BusStation_building", "7354.700195 287.652008 2622.070068", "90.000008 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_RoadBarrier_2", "7371.100098 291.419006 2614.050049", "90.000008 0.000000 -0.000000", 1);
SpawnObject("StaticObj_BusStation_roof_big", "7358.169922 289.273987 2619.840088", "-0.109137 0.000000 0.000000", 0.999935);
SpawnObject("StaticObj_Garbage_Bin2", "7362.706055 287.720825 2620.669678", "1.209966 0.000000 -0.000000", 0.99999);
SpawnObject("StaticObj_Road_Sidewalk4_Narrow_8m", "7352.973633 286.895020 2619.977051", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_Narrow_8m", "7359.490234 286.894989 2619.979980", "0.000000 0.000000 -0.250000", 1);
SpawnObject("dz/structures/military/misc/misc_concreteblock2.p3d", "7335.673828 287.140015 2609.645264", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7356.330566 286.893921 2604.583008", "90.000008 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7360.250000 286.894012 2604.570068", "0.000000 -0.000000 -0.000000", 1.05);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7366.353516 286.895020 2604.559082", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/structures/military/misc/misc_concreteblock1.p3d", "7338.343750 287.137756 2604.418945", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("dz/structures/military/misc/misc_concreteblock1.p3d", "7338.109375 287.140015 2607.757813", "-0.157080 0.000000 0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7336.040039 286.885010 2607.719971", "179.386719 0.000000 -0.000000", 0.999969);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7336.557617 286.893860 2604.097900", "-92.530518 0.000000 -0.000000", 0.999977);
SpawnObject("StaticObj_Decal_Crosswalk_East", "7326.948242 287.040009 2609.092285", "145.691513 0.000000 -0.000000", 0.999936);
SpawnObject("StaticObj_Decal_Crosswalk", "7366.810059 287.040009 2614.370117", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7366.250000 286.895050 2608.452637", "-179.999893 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7358.899902 286.868011 2621.879883", "179.635406 0.000000 -0.000000", 1.04995);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7332.290527 286.894958 2606.236084", "145.932755 0.000000 -0.000000", 0.999974);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7356.735840 286.895020 2608.043457", "90.000008 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7360.329102 286.893921 2608.439697", "179.999878 0.000000 -0.000000", 1);
SpawnObject("dz/structures/military/misc/misc_concreteblock2_stripes.p3d", "7325.796875 287.146667 2617.072021", "0.968160 0.000000 -0.000000", 0.999838);
SpawnObject("dz/structures/military/misc/misc_concreteblock2_stripes.p3d", "7332.036133 287.160217 2608.002930", "-0.581495 0.000000 0.000000", 0.999929);
SpawnObject("StaticObj_Wall_IndVar1_5_2", "7333.369141 287.784393 2621.758545", "0.206343 0.000000 -0.000000", 0.999952);
SpawnObject("Land_Garage_Small", "7323.516602 288.351746 2622.764160", "-42.317863 0.000000 0.000000", 0.999978);
SpawnObject("dz/structures/walls/wall_gate_feng_open.p3d", "7323.476074 287.040039 2618.850586", "-0.722566 0.000000 0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7330.442871 286.915253 2604.956543", "145.932755 0.000000 -0.000000", 0.999974);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7366.397461 286.895020 2600.574707", "0.000000 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7332.456543 286.895020 2601.601074", "-34.094593 0.000000 0.000000", 0.999934);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7362.740234 286.873993 2600.760010", "0.000000 -0.000000 -0.000000", 1.1);
SpawnObject("StaticObj_Wall_PipeFenceWall_8", "7358.200195 289.109985 2623.989990", "-0.400000 0.000000 0.000000", 1);
SpawnObject("dz/structures_bliss/walls/wall_pipefence_8.p3d", "7337.903809 287.139832 2619.715576", "-3.141191 0.000000 -0.000000", 0.999837);
SpawnObject("dz/structures/residential/misc/misc_table_camp.p3d", "7321.972168 287.149963 2610.884277", "-0.511725 0.000000 0.000000", 0.999961);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7324.939941 286.894989 2614.719971", "-124.174980 0.000000 -0.000000", 0.999968);
SpawnObject("StaticObj_Road_Sidewalk4_4m", "7323.779785 286.855011 2616.399902", "-124.313988 0.000000 -0.000000", 1.19996);
SpawnObject("StaticObj_Wall_IndVar1_5_2", "7339.087402 287.784363 2621.740967", "179.910294 0.000000 -0.000000", 0.999916);
SpawnObject("Land_Wall_Gate_FenR_Big_R", "7327.649414 287.888672 2622.099609", "-140.373993 0.000000 -0.000000", 0.999977);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7333.488770 287.015045 2620.844727", "-0.390627 0.000000 0.000000", 0.499934);
SpawnObject("StaticObj_Wall_IndVar1_Pole", "7335.950195 287.881989 2621.810059", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7328.640137 286.885010 2599.510010", "-34.838581 0.000000 0.000000", 0.999939);
SpawnObject("StaticObj_Road_Sidewalk4_Corner", "7327.219727 286.859375 2602.033203", "56.124435 0.000000 -0.000000", 1.09992);
SpawnObject("StaticObj_Misc_ConcretePanels", "7349.609863 287.730011 2625.379883", "3.000000 0.000000 0.000000", 1);
SpawnObject("StaticObj_Road_Sidewalk4_8m", "7322.000000 286.904999 2612.209961", "-34.809765 0.000000 0.000000", 0.9999);
SpawnObject("Industrial_Fluoresent_Light", "7358.160156 291.303986 2619.959961", "0.000000 0.000000 0.000000", 0.999986);
SpawnObject("StaticObj_Furniture_Light_BathRoom", "7289.436035 286.954529 2578.708740", "0.000000 -0.000000 -0.000000", 1);

		// FLORA WEWNĘTRZNA
		
SpawnObject("dz/plants_bliss/tree/t_juglansregia_3s_summer.p3d", "7314.333496 289.961823 2594.816162", "0.000000 -0.000000 -0.000000", 1.35);
SpawnObject("dz/plants_bliss/tree/t_fagussylvaticae_2s_summer.p3d", "7334.668945 292.839783 2627.876465", "2.094395 0.000000 -0.000000", 1.6);

		// FLORA ZEWNĘTRZNA
		
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7210.303711 295.569733 2568.222900", "-0.072099 -0.069093 0.013565", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7197.891113 297.902954 2554.913574", "0.530198 -0.004655 0.048081", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7203.217773 296.695526 2568.244873", "1.530384 -0.012066 -0.037151", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7201.493652 297.129150 2556.876465", "2.010726 -0.068859 -0.053719", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7206.954102 296.175049 2565.759766", "1.658284 0.033994 0.063464", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7200.644531 297.289551 2556.875977", "-0.387917 -0.068816 0.025446", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7200.085449 297.246155 2559.829590", "-2.764126 0.034130 0.023204", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7198.501953 297.199432 2564.375488", "-1.464038 -0.032800 -0.026690", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7214.001953 298.254700 2521.893311", "-0.338445 -0.057285 0.068211", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7226.454590 293.580414 2524.459473", "-1.510825 0.025301 -0.054822", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7214.652344 296.366638 2536.421631", "1.451765 -0.061836 0.030862", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7213.872559 296.646515 2535.805176", "2.250610 0.025450 -0.060822", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7213.486328 299.700867 2516.019043", "1.434699 0.052543 -0.009479", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7222.141602 294.646973 2527.420410", "1.223195 -0.029771 0.036371", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7213.196289 298.844666 2520.362061", "1.111595 0.067951 -0.023098", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7216.227539 296.112488 2533.874023", "0.546689 -0.042320 0.016795", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7212.191895 298.750488 2482.942871", "0.767589 -0.012564 0.022621", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7218.441406 295.041718 2491.172119", "1.711400 0.064026 0.035903", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7223.515625 293.398651 2491.124268", "-1.501238 -0.035903 0.002307", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7223.743652 293.113678 2493.461670", "-0.144774 -0.027423 -0.042260", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7219.974121 296.702454 2477.613037", "-1.862501 -0.052730 0.050071", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7230.076172 291.360382 2490.117188", "0.281302 0.048098 0.026975", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7223.865234 295.003418 2477.993896", "2.989052 0.017682 -0.002090", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7214.554688 297.029205 2491.440918", "0.116203 -0.054524 -0.043159", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7228.888184 292.972595 2522.810791", "-1.246206 -0.061342 -0.066651", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7226.009766 294.919952 2514.063232", "2.319833 -0.032281 -0.009049", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7234.040527 290.988678 2513.469238", "-2.145338 0.034535 0.049526", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7221.840820 294.734039 2526.279541", "-2.821460 0.047561 -0.030308", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7226.226074 292.861023 2529.931641", "0.779478 -0.009922 0.033431", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7220.594727 297.310242 2511.900635", "0.685135 0.007983 -0.017507", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7230.869629 292.013214 2524.024658", "2.968918 0.026362 0.029080", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7228.823730 292.193359 2530.912598", "0.776218 0.011835 0.068790", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7264.352539 292.179016 2485.249756", "-1.958953 -0.046922 -0.041106", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7258.877930 288.062195 2499.994385", "-1.987332 -0.065394 -0.068049", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7244.648926 291.140656 2484.555176", "-2.917912 -0.065897 0.064930", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7255.867188 289.203857 2482.856445", "-2.258281 -0.065714 -0.037032", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7252.590332 289.182739 2500.865967", "0.727512 -0.017345 0.031718", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7245.450684 291.045837 2484.973633", "1.311402 0.019689 0.037952", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7253.285645 290.060883 2478.529297", "2.090113 0.003752 -0.008499", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7247.307129 290.795654 2486.020508", "-1.717919 0.053429 -0.002529", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7257.175781 291.401337 2442.792725", "-2.815324 0.045179 0.021398", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7255.392090 292.059357 2440.363770", "2.424147 -0.028215 0.016514", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7266.308594 290.687897 2436.214844", "-2.338241 0.038549 0.001762", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7250.077637 292.993805 2440.203857", "2.736896 -0.007625 0.040973", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7261.564941 289.877502 2443.756836", "-3.102187 -0.000087 -0.066332", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7258.915039 291.481506 2437.663574", "2.077841 -0.017358 -0.046977", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7253.502930 292.087402 2443.404541", "0.453497 -0.053114 -0.004459", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7255.184082 291.230988 2452.391357", "0.442567 0.051967 -0.064960", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7262.560059 291.395416 2475.907715", "-2.668632 0.013821 0.059919", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7266.945313 293.593994 2463.326172", "1.795387 0.033406 0.027542", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7261.793457 291.261841 2479.481201", "1.650997 0.055832 0.009696", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7262.596191 292.197235 2470.270508", "-2.092414 -0.007476 0.056684", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7264.270508 291.625916 2460.628418", "0.745537 0.068535 -0.006530", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7267.795898 293.589630 2470.402588", "-2.267484 0.009338 0.044242", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7266.262695 292.642120 2478.431152", "1.363367 0.060204 0.008235", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7256.661133 290.153351 2465.128418", "-0.000959 0.068262 0.058811", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7283.559082 292.810089 2508.785400", "-1.152246 0.037577 0.048665", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7298.398926 289.983856 2521.700439", "0.377179 0.036018 -0.035753", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7302.764648 292.139832 2514.499756", "-0.222243 0.065978 -0.005597", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7299.104980 290.290131 2519.977539", "-3.072656 -0.040611 0.054797", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7294.102051 289.162262 2524.076416", "-1.809001 -0.029021 -0.002959", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7294.971191 293.807495 2511.264893", "-1.128852 -0.006594 0.008465", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7295.851074 295.969086 2506.485596", "-2.139585 -0.023336 0.051972", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7298.145508 294.120331 2509.687744", "0.513516 0.015935 0.021487", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7287.359863 297.162811 2486.298828", "2.264033 -0.024985 0.013037", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7283.743164 295.464874 2487.757324", "1.677075 -0.033964 0.016830", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7277.203125 295.033600 2482.490479", "1.910439 -0.006658 -0.064418", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7295.778809 301.527161 2488.147461", "-0.890886 0.002512 0.029098", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7275.280762 291.322693 2493.391846", "-2.543800 -0.020844 -0.034181", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7279.830566 293.883362 2487.868896", "2.817625 -0.046155 0.064781", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7279.968750 291.929932 2498.663574", "-1.679568 -0.045375 0.041634", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7287.650879 297.129150 2489.000244", "2.397685 0.046867 0.006266", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7308.029785 287.539154 2534.418701", "-0.131160 -0.046820 -0.058662", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7307.010742 286.512512 2541.043213", "-0.834319 -0.003760 0.040155", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7315.239258 310.959473 2480.795410", "-2.801709 -0.053787 -0.009053", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7316.255859 304.670166 2492.585938", "-0.286288 0.043441 -0.030265", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7320.553711 311.644440 2483.520996", "-0.948604 0.048665 -0.033295", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7327.686523 311.733978 2485.781006", "-0.394437 0.014179 0.045865", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7315.277832 300.718689 2499.632568", "1.417825 -0.049159 -0.005904", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7327.337402 309.785706 2488.279541", "-2.546677 0.009709 0.032941", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7311.752930 305.946259 2488.905029", "-0.065388 -0.017038 -0.057912", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7318.025879 299.973358 2502.562012", "1.490116 -0.060681 -0.054298", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7295.391602 288.392487 2531.127686", "1.767583 0.035370 0.046355", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7299.470703 286.326050 2536.650879", "-2.043516 -0.014396 0.014729", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7302.660645 289.994720 2525.259277", "0.098561 -0.052116 -0.005768", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7349.613281 285.938904 2537.802979", "2.898162 0.026277 0.068714", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7345.967773 289.835266 2525.329346", "1.379858 0.036171 0.014622", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7340.532715 288.165619 2531.419434", "-2.374675 0.023515 0.002103", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7347.584961 286.293915 2539.688477", "1.379474 -0.056531 0.026575", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7345.971680 286.050964 2538.740479", "1.232591 0.062041 -0.063656", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7347.676758 286.957489 2533.348633", "2.636035 -0.042601 0.054946", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7336.410645 288.956421 2529.976318", "-2.407272 -0.017822 0.005729", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7335.864746 285.984955 2538.250244", "-2.037955 0.020430 0.067269", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7312.502441 285.771301 2539.916748", "-0.672096 -0.002018 -0.047915", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7326.588867 289.628754 2528.951660", "-2.589055 -0.026920 -0.044715", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7317.664063 288.873444 2531.665039", "-2.343611 0.042388 -0.044399", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7311.917480 290.963226 2520.699219", "-1.749942 0.037224 -0.068339", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7324.842773 286.731598 2535.776367", "1.201335 -0.029660 -0.036435", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7309.629395 290.055420 2527.120361", "-0.885517 -0.059518 -0.039299", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7321.343750 285.734711 2538.188232", "0.442759 -0.015432 -0.034433", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7320.354980 289.670502 2528.484619", "-1.017827 0.017166 0.056130", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7366.046387 286.181885 2535.662109", "0.539019 -0.012040 -0.002930", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7367.543945 286.456848 2533.794189", "2.207082 0.041340 0.015692", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7357.187012 289.454834 2525.465820", "-1.245439 -0.049108 0.053885", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7374.056152 288.706940 2525.433105", "-0.363948 -0.053565 0.053241", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7354.676270 286.847076 2533.252930", "1.497786 -0.057716 -0.058074", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7364.119141 290.851440 2523.054688", "-0.801146 0.059211 0.023605", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7369.668457 293.017426 2519.819336", "0.757043 0.046841 0.057255", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7369.436035 293.790375 2519.056152", "2.241406 -0.019834 -0.039733", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7401.608398 286.306610 2532.175049", "-1.671131 -0.055666 -0.050118", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7399.101563 290.223694 2517.818115", "-1.479186 0.036861 -0.030026", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7386.457031 286.219940 2530.689209", "1.396157 -0.044881 -0.042154", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7395.960449 289.061066 2520.707520", "-2.929033 0.024845 -0.063941", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7399.444824 287.233398 2523.998535", "0.087823 -0.061930 -0.039265", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7392.745605 286.536133 2534.570557", "-0.331733 -0.024564 -0.054622", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7393.825195 286.198700 2530.093506", "-1.289350 -0.057950 0.060694", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7393.337402 287.534027 2524.398438", "-2.971795 0.005814 0.034769", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7240.823730 297.620789 2637.646240", "-1.832396 -0.009270 -0.055879", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7248.513184 293.220886 2625.193115", "0.005561 0.006189 -0.040113", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7254.663574 300.456940 2661.678467", "-0.359154 -0.019016 0.049381", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7266.904785 296.376587 2667.064453", "2.215519 -0.008320 -0.018704", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7247.731934 301.741547 2669.177979", "2.317341 0.068066 -0.038689", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7242.028809 297.189636 2639.056396", "1.869212 -0.022246 0.021743", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7230.140137 302.277710 2634.543213", "0.534225 0.005567 0.056987", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7254.388672 300.635010 2662.633789", "2.611682 -0.064776 -0.053736", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7380.730957 288.187500 2525.851563", "1.666721 -0.025744 -0.004101", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7382.350586 286.431702 2530.691162", "-0.118696 0.033614 0.043245", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7377.413086 285.861725 2537.108643", "-1.065574 -0.022927 -0.062458", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7373.269531 286.064270 2535.554443", "-1.679952 -0.014899 -0.046129", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7372.008789 286.561615 2532.242432", "-2.841594 0.001276 0.048260", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7380.667969 290.592651 2520.949219", "0.601914 0.003339 0.021853", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7384.106934 290.105530 2521.313232", "1.894141 -0.057336 -0.018202", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7371.000000 285.972809 2537.916748", "2.912926 0.050246 -0.018197", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7270.945313 287.372009 2605.322510", "-1.169888 0.003496 -0.001272", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7250.748047 300.896759 2660.123047", "1.276503 -0.064320 0.069592", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7257.709473 290.152832 2605.384033", "-1.273626 0.061159 0.067286", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7284.678223 288.741028 2642.759033", "-0.761453 0.009027 0.046956", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7274.304688 295.000793 2661.572510", "-1.758379 0.058397 -0.053706", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7239.175293 297.847504 2625.577393", "0.746305 -0.063149 -0.021214", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7269.864746 291.378235 2641.637695", "-2.780809 0.009995 -0.002793", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7232.704590 300.983673 2629.384521", "-0.068648 -0.024841 0.061402", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7282.524902 288.701935 2640.386719", "-2.545910 0.012496 0.052607", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7294.640137 288.020142 2651.553955", "1.380625 -0.058410 0.059782", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7294.746582 287.909393 2650.160156", "-2.847154 0.027568 0.006066", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7296.933594 287.101013 2638.368652", "2.866330 -0.032212 0.042882", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7299.162109 287.177582 2649.645020", "1.830095 0.050872 -0.038391", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7284.427246 287.920349 2638.380859", "2.674001 -0.057967 0.045013", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7287.289551 288.072632 2641.834473", "2.851374 -0.000807 0.051098", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7281.079590 292.365875 2655.387939", "0.053307 -0.046411 -0.040181", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7264.104004 288.128387 2601.368652", "-0.822814 -0.032225 0.017567", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7259.619629 293.103455 2633.391846", "0.776601 -0.037351 -0.059424", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7233.385742 300.064240 2621.289063", "1.715043 0.065710 0.062318", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7240.045898 296.322205 2614.875977", "-0.043720 -0.042738 0.055210", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7272.127441 290.325623 2637.187744", "1.521180 0.054571 -0.018606", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7265.319824 289.750488 2616.039063", "2.939963 0.028838 -0.005623", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7237.503906 297.481323 2616.271729", "-0.380056 0.062429 0.058159", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7243.094238 296.857697 2638.968262", "1.284557 -0.040748 -0.036968", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7225.569824 299.648865 2607.002930", "1.597690 0.051665 -0.056028", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7237.818848 295.376587 2607.451904", "1.264230 0.032468 0.015134", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7226.862793 300.366364 2610.159180", "3.016281 0.042784 0.068075", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7247.666992 293.753967 2614.908936", "-1.734026 -0.053352 -0.016757", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7234.342773 298.510742 2614.267822", "-2.043517 -0.001012 -0.048000", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7211.412598 295.346039 2593.595703", "0.483794 0.052014 0.064828", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7213.070801 305.508972 2612.077637", "-1.896633 -0.034066 0.056591", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7260.525879 289.608917 2606.425049", "2.969110 -0.032715 0.046713", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7226.477051 309.415405 2667.453125", "0.332117 -0.050778 -0.029149", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7255.297852 294.156219 2638.851074", "-2.921172 -0.047110 0.021892", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7244.847168 301.870544 2668.322021", "-0.410736 -0.067005 0.056459", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7263.740723 292.833527 2645.743896", "-0.934222 -0.036128 -0.008303", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7272.982910 292.117340 2649.126709", "-1.064999 0.020537 -0.009641", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7263.541992 289.891388 2615.841797", "2.599410 -0.042567 -0.033908", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7222.743652 304.652710 2625.250977", "1.975636 -0.006726 -0.056050", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7244.540039 301.414093 2662.052246", "-1.765474 0.026579 0.019518", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7278.413574 289.215302 2639.572021", "0.579287 -0.048805 0.055819", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7280.780273 288.207977 2635.640137", "2.095290 -0.051597 -0.011929", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7268.715332 290.480255 2620.895264", "0.804406 0.060963 0.016497", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7275.786133 288.533417 2617.367188", "0.784847 0.004455 0.054558", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7268.642090 291.335724 2633.278320", "2.878411 -0.062893 -0.038050", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7273.645020 289.397675 2620.738037", "1.573912 -0.030572 0.038199", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7274.898926 289.079498 2620.402588", "-1.616098 -0.029409 0.067614", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7280.863770 287.751373 2627.305176", "0.297793 -0.049210 -0.012539", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7250.328125 295.474182 2643.948975", "1.929807 -0.054162 0.043147", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7274.046387 289.549652 2622.879883", "1.678034 -0.044071 0.018274", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7237.074219 298.964264 2628.399902", "-3.044469 0.026549 -0.016715", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7235.875977 299.636108 2628.008301", "-3.036607 -0.021018 0.007992", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7270.745117 290.682434 2632.529297", "1.656941 -0.010868 0.023413", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7244.045410 295.830536 2634.285889", "-0.881107 0.064440 -0.005337", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7278.252930 288.599976 2625.609863", "1.418017 0.026988 -0.028301", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7242.651855 295.914490 2625.335449", "-0.428186 0.002755 0.017848", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7257.917480 290.653259 2614.168213", "0.549182 0.023609 0.067291", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7252.764160 291.984955 2611.116455", "-2.087044 0.069459 -0.053054", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7247.439453 293.881165 2628.259033", "2.854249 -0.061521 -0.052027", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7244.629395 294.966187 2624.521973", "3.018774 0.042537 -0.069477", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7238.909668 297.537781 2619.914307", "1.582158 0.054814 -0.036337", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7251.440918 292.437012 2621.971436", "-1.475350 0.018632 -0.068974", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7244.796875 294.888428 2624.570801", "-2.178703 0.007689 -0.008277", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7240.573242 296.985382 2623.232422", "2.853099 0.013122 -0.058402", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7274.593750 292.651764 2651.938232", "-2.776206 0.063984 -0.067934", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7268.242676 291.507874 2639.584717", "-1.633356 0.046279 0.026221", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7257.947266 299.696838 2671.488525", "0.588683 0.059595 0.015138", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7264.832520 299.374481 2683.876465", "-0.899131 -0.062752 0.041596", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7297.355469 288.047516 2664.169922", "1.226455 -0.020873 0.052990", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7258.400879 299.822906 2674.224609", "-0.374686 -0.055734 0.030968", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7293.805176 287.447113 2642.789063", "2.849647 -0.054089 -0.040769", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7310.490234 287.040009 2658.958496", "-2.427599 0.037539 -0.051550", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7293.910156 289.817566 2670.366211", "0.507955 -0.032106 -0.028356", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7290.474121 292.398041 2687.187744", "-0.610926 0.030708 -0.063059", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7270.070801 298.840057 2700.899658", "0.925594 -0.014993 -0.030201", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7286.499512 294.300415 2676.364746", "0.811309 -0.029903 -0.043892", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7269.546875 296.727509 2670.493408", "-0.268263 0.019361 -0.022621", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7265.677734 299.842316 2705.631836", "-1.126552 -0.059224 -0.029051", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7284.354980 291.007507 2652.967529", "-0.640648 0.052739 0.035945", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7310.100586 287.974060 2690.508301", "-0.672096 -0.017533 -0.011205", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7290.000000 291.777435 2739.701660", "-1.506607 0.001280 -0.020085", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7287.261230 291.650421 2741.510742", "0.116970 0.023413 0.044353", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7290.253906 292.522705 2750.748779", "0.923484 0.034718 -0.064282", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7281.943848 293.842896 2730.736572", "-2.601902 0.019190 0.034215", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7279.263184 293.923218 2743.237793", "-1.873623 0.009304 -0.036299", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7290.678223 292.841644 2728.839600", "-1.804016 -0.022510 0.034322", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7296.012695 292.159821 2736.962891", "-1.635465 -0.045512 0.049679", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7285.499512 292.577545 2749.491699", "-0.117928 -0.044280 -0.053386", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7280.580078 291.822510 2653.033691", "2.120410 -0.023950 -0.014639", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7241.035156 306.348358 2680.581299", "-3.134977 -0.066055 -0.065203", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7275.294922 297.374207 2694.436279", "0.883792 0.064849 -0.059015", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7234.755371 306.707214 2666.918945", "-2.646773 -0.007941 0.043726", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7242.451660 303.902100 2672.377197", "-1.207471 0.053067 0.042699", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7261.184570 299.709045 2676.854492", "-0.133653 -0.022041 -0.028527", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7263.374512 293.246063 2648.746826", "0.087248 0.028859 0.030389", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7240.910645 301.582062 2654.971680", "2.171991 -0.007515 -0.021589", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7271.565918 297.620453 2745.872559", "3.087613 0.004447 -0.038996", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7279.533203 293.942902 2743.639648", "2.757031 0.056386 -0.052739", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7268.053711 299.435883 2748.998047", "-1.734985 -0.018845 -0.059382", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7275.475586 296.735107 2752.475342", "1.462312 0.001515 0.004199", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7278.131836 295.094666 2749.186768", "-1.228947 0.028394 0.037053", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7271.365234 298.131500 2752.094727", "2.061733 0.038877 0.036478", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7269.349121 298.092346 2740.692139", "2.930567 0.052747 0.028774", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7275.416992 295.748169 2745.152100", "0.014765 -0.013156 -0.052406", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7242.830566 301.414124 2655.938232", "1.034893 0.062978 -0.068948", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7272.263184 294.642944 2659.971680", "-1.588294 -0.024649 -0.056459", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7267.170898 297.659180 2673.337646", "-3.017624 0.024321 -0.037709", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7231.485840 308.776855 2681.645020", "-0.585807 0.019557 0.037390", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7239.995605 305.832581 2675.620850", "2.388481 -0.022254 0.034249", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7258.818848 297.477234 2658.156982", "-0.231063 0.051124 -0.012402", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7223.066406 306.408539 2652.424072", "2.258855 0.054592 -0.015807", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7255.719238 303.182495 2688.428223", "-1.841983 -0.012291 -0.006803", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7286.274414 294.456360 2696.521240", "0.006903 -0.063029 0.024491", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7285.557617 294.252686 2701.529785", "1.096254 -0.041608 -0.046445", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7285.402344 294.545593 2699.546631", "-0.095110 0.067866 0.037364", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7294.150391 291.872192 2703.560547", "2.355116 0.019433 0.008559", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7281.027832 296.957642 2688.580566", "0.635663 0.011550 -0.040419", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7296.617188 289.350281 2688.509277", "0.910062 -0.043257 0.020315", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7286.878906 294.314209 2689.057861", "-1.594813 0.025399 -0.016616", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7293.242188 291.725677 2695.403564", "0.409010 -0.049641 -0.005891", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7242.710938 298.553314 2648.291016", "2.538624 -0.007204 -0.066898", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7226.748535 303.752991 2632.557861", "1.329618 0.028275 -0.017776", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7210.132324 310.000183 2635.024170", "0.061169 -0.024721 0.032988", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7252.842773 294.012970 2633.354248", "2.315422 0.064614 -0.061018", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7224.533691 305.878876 2651.514404", "-0.860205 -0.016088 0.013864", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7211.140625 310.405334 2637.274658", "-0.593094 0.065045 -0.017464", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7225.133789 306.402405 2653.949219", "-1.870746 0.045456 0.044152", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7236.788574 301.182068 2649.584473", "2.107562 0.011196 -0.002180", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7253.710449 303.719971 2693.632813", "-0.610734 -0.057822 0.020328", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7239.500000 306.075348 2710.875732", "1.584267 0.026681 -0.011051", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7242.729492 305.485779 2708.066895", "-1.758762 -0.044945 0.064704", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7254.992676 303.703522 2698.516113", "2.536130 0.038408 -0.065603", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7252.172852 304.380096 2699.574707", "-1.081489 0.007204 -0.002955", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7248.615723 304.936584 2696.095703", "-1.986374 -0.041353 0.057571", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7246.161621 304.532013 2711.153809", "-1.934217 -0.004928 -0.007233", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7235.899414 308.270416 2700.797607", "-2.569879 -0.050403 0.015849", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7179.721680 314.784973 2630.100342", "-2.602860 -0.050911 0.051545", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7221.084473 309.413116 2660.700928", "2.765468 0.003939 0.047774", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7181.667969 318.836304 2651.522217", "2.459621 -0.020251 -0.005000", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7234.274902 300.281555 2628.835693", "-0.411311 -0.018219 0.036128", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7233.216309 300.678497 2625.831055", "3.060577 0.025395 -0.027065", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7221.951660 306.391144 2640.444824", "0.609201 0.019114 0.014899", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7195.524902 319.490845 2671.966064", "1.721179 -0.025348 0.009645", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7198.589844 315.345337 2653.482910", "-0.333651 0.024883 -0.052572", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7261.017090 300.824219 2713.794434", "2.543225 0.019003 -0.015756", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7264.696289 300.540771 2692.710449", "-1.887046 -0.038647 0.062629", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7269.689453 298.622223 2696.409668", "-0.689353 -0.000083 -0.008456", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7265.708008 299.861847 2701.774170", "-0.428761 0.042725 -0.039836", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7258.661621 302.029633 2701.380859", "-1.262696 0.007042 -0.062002", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7259.028809 301.443359 2704.687012", "2.590973 -0.009939 0.000526", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7267.954102 299.326721 2703.870850", "-1.958186 -0.031612 -0.025872", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7260.498535 300.968109 2710.475830", "-1.788101 0.003671 -0.063779", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7253.927246 302.976196 2705.737061", "1.845435 0.018372 0.059940", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7266.374512 298.246765 2679.071045", "2.075155 0.036013 -0.058581", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7276.312988 296.936279 2704.675537", "-1.862501 -0.050156 0.040070", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7295.812988 289.496674 2680.577148", "1.989058 0.038856 0.060507", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7278.730957 296.099060 2706.627197", "2.246391 0.061108 -0.038868", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7284.656738 295.090576 2677.601563", "-1.722904 0.052785 -0.069323", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7251.734375 304.365417 2700.501465", "-2.623570 -0.042171 -0.036704", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7250.412109 304.258057 2683.815918", "0.165291 0.043036 0.009671", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7259.397461 302.317780 2738.114746", "0.496641 0.036827 -0.043462", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7265.875488 299.719147 2742.329590", "1.846202 0.040279 0.002461", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7266.344727 299.785583 2745.165771", "0.112943 -0.056105 -0.045073", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7264.899414 299.826324 2735.264404", "0.151677 -0.016911 -0.056165", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7256.940430 303.431152 2739.957275", "1.955118 -0.033103 -0.000620", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7254.495605 304.526581 2741.226074", "-0.303162 0.039951 0.000194", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7261.743164 301.570282 2742.776123", "-2.732678 0.065590 -0.011916", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7260.065430 302.367859 2743.546387", "2.604587 0.003859 0.011486", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7283.911133 288.292938 2526.997070", "-2.890874 0.055679 -0.054908", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7284.491699 289.668884 2523.020264", "2.520215 -0.054984 0.031352", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7291.995605 294.430420 2510.610840", "-2.375249 0.021470 -0.043317", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7295.931641 291.864960 2514.808105", "0.130968 -0.046317 -0.017354", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7297.384277 291.028198 2516.423340", "-1.507757 -0.018133 0.000058", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7280.421387 288.017456 2526.765625", "0.919650 0.023818 -0.023204", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7295.538574 290.532928 2518.318848", "-2.781767 -0.014712 0.004157", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7285.347168 289.001740 2525.685791", "3.086464 0.017967 -0.058214", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7301.360840 287.159790 2535.087402", "-1.366243 0.001745 -0.047898", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7290.426270 286.304169 2539.552002", "-2.137667 -0.052768 -0.002333", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7281.369141 287.065857 2529.303955", "0.242185 0.021282 -0.014503", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7282.761230 286.241943 2535.682861", "-2.654443 0.048916 -0.001813", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7288.100586 289.179596 2525.589844", "-1.372571 0.006803 -0.039900", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7291.944336 286.549713 2535.783203", "-1.141700 -0.039465 -0.034825", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7284.936035 286.653412 2532.965576", "-0.254265 0.019356 -0.006142", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7289.536621 286.788666 2542.512695", "-2.214752 0.029076 -0.003458", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7240.564941 307.803284 2774.576416", "-3.100844 -0.063238 0.034607", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7252.761230 304.838776 2736.702637", "2.585412 0.017452 0.017277", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7235.244629 311.319550 2750.045898", "2.478604 -0.014004 0.033764", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7264.168457 298.503296 2781.817383", "-3.047920 -0.048886 0.055159", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7264.693848 299.716614 2732.036377", "-1.764707 -0.053250 -0.054729", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7242.539063 307.760010 2762.185059", "-3.041017 0.067887 0.030580", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7246.061035 306.870331 2750.983154", "-1.395198 -0.004532 0.012112", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7233.906250 311.677368 2750.487305", "-2.096056 0.004920 -0.010787", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7236.124512 310.622650 2757.082520", "-2.882246 0.041020 0.027696", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7280.294434 294.924347 2784.462402", "-2.304684 0.003543 -0.023848", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7273.022949 297.792145 2754.517334", "2.420695 0.063511 -0.006100", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7261.473145 298.607574 2788.559326", "-2.940539 0.044702 -0.063992", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7286.495117 292.940125 2751.318359", "1.821466 -0.064512 0.018990", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7260.069336 302.581665 2753.189453", "-2.244282 0.048661 0.062088", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7276.477539 296.047821 2781.992432", "1.582158 -0.057997 -0.067099", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7280.228027 295.350128 2779.102539", "-0.059060 0.009334 -0.059352", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7269.756348 296.446686 2787.598633", "-1.381008 -0.015010 -0.015986", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7273.374512 296.953796 2747.544434", "2.046968 0.002738 -0.026537", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7263.078125 299.257416 2778.567383", "2.338817 -0.060775 0.048000", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7274.696289 297.929657 2768.362061", "1.708714 0.022629 -0.068386", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7247.935059 307.026550 2741.105957", "2.601711 -0.005525 -0.012087", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7242.932617 307.751282 2760.566406", "1.631630 -0.067286 0.007608", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7273.075195 298.131439 2760.576172", "0.011889 -0.024832 0.038118", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7241.287109 306.841553 2781.779297", "-0.935756 0.060451 0.043786", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7187.944824 324.909698 2774.289795", "-1.663653 -0.068168 0.051656", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7210.701660 316.355469 2793.696289", "-0.680916 -0.048750 -0.053612", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7191.158203 324.993164 2755.859131", "-1.909672 0.069170 -0.010868", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7207.924316 317.837036 2781.511230", "2.552622 0.032012 -0.018781", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7202.133301 318.842529 2788.328857", "-2.290303 0.013216 0.066119", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7180.315918 324.808838 2789.713867", "0.178331 0.050902 0.042750", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7208.810547 319.571655 2763.875244", "0.388493 -0.008307 -0.047110", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7209.516602 317.679535 2779.944824", "-0.184659 -0.059305 -0.012070", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7171.143555 329.652130 2755.475342", "0.971423 -0.032085 -0.025041", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7212.583984 319.525360 2758.181396", "0.133844 0.003224 -0.033917", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7191.400391 324.272369 2771.803955", "-2.227600 0.020089 0.041050", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7164.934082 331.153534 2747.519531", "2.463456 0.018871 0.018236", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7184.303223 324.849426 2735.772461", "-2.553580 -0.038775 -0.010770", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7180.034180 328.000031 2754.064941", "-1.625685 -0.030823 0.000850", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7169.013184 329.569183 2741.002930", "1.894524 -0.016859 -0.035954", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7177.999512 327.511719 2772.748535", "0.989640 -0.004093 0.068978", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7229.829102 309.328857 2724.173340", "1.413606 0.019318 0.003317", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7228.208984 311.514984 2786.032959", "0.102780 0.065543 0.008324", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7200.269531 322.723450 2752.706543", "-0.731923 -0.042946 0.026093", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7245.928223 307.803131 2743.192871", "-1.306608 0.038225 -0.011661", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7240.177246 309.467590 2749.103516", "1.532301 0.027380 -0.022944", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7206.279297 318.519653 2775.598877", "0.685710 0.064534 0.013442", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7241.936523 307.094788 2776.281738", "-2.617818 0.031254 0.003901", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7233.742676 309.335083 2727.894531", "1.692032 -0.064806 -0.017247", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7238.639160 309.929443 2751.030273", "-1.479761 -0.006513 0.035489", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7241.700684 306.834198 2778.108887", "2.158377 0.026153 -0.052053", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7275.519043 297.648132 2761.177734", "-2.377743 -0.014558 -0.001736", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7221.232910 316.011230 2735.373291", "-0.267879 0.064142 -0.024841", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7262.554688 301.752045 2746.442871", "0.704502 0.024632 0.068394", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7236.982910 307.536804 2725.488281", "2.673043 -0.036934 -0.027355", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7256.415039 302.298950 2729.022949", "0.727321 0.043705 -0.036393", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7266.592773 298.987274 2774.153564", "-1.844476 0.041327 0.036793", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7247.056641 306.057343 2759.981934", "-1.376406 0.066281 -0.010506", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7258.242676 302.731476 2736.970215", "-0.163374 -0.026238 0.001489", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7263.233887 298.684753 2782.272949", "1.164135 -0.001153 -0.069340", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7254.831543 303.140961 2731.782227", "1.202294 -0.052270 -0.035890", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7284.448242 295.774872 2759.423340", "-1.762214 0.013719 -0.017222", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7243.028320 307.743469 2735.204590", "-1.677650 -0.040321 0.059399", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7273.492676 296.949921 2777.861328", "2.143420 -0.006590 0.066336", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7232.479004 312.060730 2755.929688", "2.102768 -0.015019 0.068867", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7221.196777 312.670471 2691.700684", "1.179284 0.011720 -0.036209", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7241.100586 305.708038 2714.334717", "-2.241789 0.069200 0.009189", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7251.490234 303.182129 2710.291016", "-1.612646 -0.005610 0.055679", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7238.106934 306.330597 2710.112793", "-1.685320 -0.019706 0.035349", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7238.869141 307.307831 2689.233398", "-2.713310 -0.062552 -0.022876", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7252.138184 303.619568 2682.195313", "-3.078027 -0.051699 0.040019", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7204.143555 318.206146 2684.015869", "-1.129044 -0.028982 0.005367", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7209.859863 314.462311 2668.264648", "-2.523667 0.049483 0.043125", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7271.389160 288.504639 2613.243164", "1.580240 -0.068765 0.029570", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7258.020508 293.941498 2644.436768", "1.803058 -0.010740 0.062833", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7248.218262 296.587280 2646.952393", "1.884745 0.000398 0.004216", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7269.903809 288.879547 2614.451660", "-1.506798 0.049892 0.008708", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7242.343262 296.108490 2627.846680", "-2.830280 0.067751 -0.053544", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7239.085938 296.398712 2612.827637", "1.259437 0.008213 -0.018517", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7276.601074 288.152008 2615.272217", "1.628178 -0.023174 0.050787", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7234.951660 300.208740 2641.315186", "-1.420510 0.025893 0.059075", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7301.166016 287.040009 2633.737061", "-3.045044 -0.067827 0.024197", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7285.763672 287.131592 2620.448486", "0.280919 -0.057579 -0.051831", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7289.752441 286.812592 2621.562988", "0.875354 0.018146 -0.026728", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7246.356934 298.916534 2652.817139", "1.520413 0.009309 0.024359", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7291.902832 286.904236 2626.302490", "1.952817 0.056190 0.010570", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7271.029785 296.831329 2671.622314", "-0.522912 -0.010024 -0.051980", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7287.097656 287.505859 2638.829834", "-0.211120 0.007429 0.030180", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7275.603027 289.352692 2636.131592", "0.310832 -0.033231 -0.052278", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7218.731934 307.312317 2635.870361", "1.312361 -0.067734 0.010395", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7223.197754 300.452515 2606.616211", "-2.019739 0.048098 -0.045929", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7239.622070 287.667297 2583.480957", "-2.457704 -0.003518 0.061730", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7217.954590 305.840454 2624.458984", "0.935757 -0.037969 0.015705", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7224.705078 292.413757 2583.916260", "0.053883 0.051584 -0.041442", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7204.542969 297.778717 2594.532959", "2.805927 0.019851 0.059458", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7251.115234 292.467865 2611.440918", "2.411683 0.059740 -0.041617", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7242.439941 287.135010 2582.827637", "-2.249842 0.004408 0.042985", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7230.399414 289.169281 2569.684082", "-0.924827 -0.046837 0.005733", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7222.208496 292.362457 2585.941162", "-1.123867 0.033508 0.013450", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7239.958984 292.199310 2597.818848", "0.611693 -0.056233 0.043833", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7192.061523 305.670746 2608.055664", "-2.948784 -0.069050 0.061086", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7221.700195 292.779694 2562.483398", "2.424338 0.015590 0.028152", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7233.353516 299.139343 2615.250244", "0.021476 -0.005516 0.038123", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7224.453613 294.991638 2598.195801", "0.533842 0.019373 -0.025522", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7201.285645 296.959167 2564.515625", "-2.493562 -0.063549 -0.043334", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7227.795898 292.064819 2540.172119", "0.112751 0.004941 0.034867", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7229.761719 291.127106 2546.646729", "2.215710 0.054490 0.002559", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7224.688477 293.204620 2533.329590", "-1.790402 0.068526 -0.043458", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7232.142578 291.315063 2534.809570", "-1.758762 -0.000552 -0.031837", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7223.756836 292.550690 2549.073730", "-2.516572 0.047438 -0.058593", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7225.976563 292.105225 2545.360840", "-2.830472 -0.043701 0.049781", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7222.373535 294.314392 2528.812500", "-1.862885 0.002342 0.003816", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7224.879395 292.768250 2539.370850", "-1.698743 0.045848 -0.058265", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7235.276855 290.901062 2536.520508", "-3.103721 0.014784 -0.029051", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7223.733887 293.498718 2532.263428", "0.065196 -0.053293 -0.002998", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7237.642090 290.256348 2539.266357", "-2.704106 -0.057733 0.008669", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7244.711914 289.128296 2528.521484", "-2.289920 0.059267 0.068731", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7223.820801 293.686249 2529.740234", "0.993666 0.024649 0.063119", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7234.945313 290.957947 2532.928467", "-2.676687 -0.062441 -0.034535", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7248.006836 287.896698 2542.434570", "-0.507380 -0.057358 -0.020550", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7223.518066 292.993439 2543.219727", "0.427802 -0.009411 0.000471", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7290.493164 287.609772 2531.394287", "-1.483980 0.047063 -0.040505", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7309.960449 288.433655 2532.495850", "-1.181393 -0.021346 0.002367", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7206.229980 301.609741 2508.778076", "2.776974 -0.019582 0.018820", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7204.131348 301.885986 2502.212646", "2.771029 -0.041080 0.044809", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7211.313965 298.503815 2495.467285", "1.516578 0.031505 -0.017111", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7218.997559 296.253662 2483.517334", "-2.582535 0.038992 -0.009577", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7208.150391 300.924683 2510.961670", "-2.296056 0.019118 -0.069259", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7216.215332 296.989044 2502.032959", "0.787148 -0.013267 0.032553", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7207.213379 299.933136 2487.045410", "1.387911 0.010698 -0.038902", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7218.178223 295.373138 2490.079102", "-0.405558 0.028999 -0.068646", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7232.165527 292.553467 2469.957764", "-1.591937 0.030320 0.028697", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7227.467285 293.646576 2469.053223", "1.156082 -0.029144 0.028369", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7215.932617 296.617706 2488.489014", "-2.988285 0.057238 0.060268", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7210.976563 301.376831 2467.910400", "0.129625 -0.064614 -0.023673", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7217.072266 298.068146 2473.917725", "-0.156854 0.015922 0.004792", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7207.261230 300.255402 2480.271729", "0.349375 -0.054652 0.030768", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7219.455566 297.391479 2459.395996", "1.494334 0.026873 -0.058504", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7211.959961 298.103607 2488.843262", "2.329420 0.005746 0.058879", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7210.270996 300.230652 2508.917480", "-2.064993 0.005993 0.050813", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7218.010742 295.973999 2501.045654", "0.448703 0.003914 0.058512", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7217.646484 297.112335 2504.968506", "1.602292 0.060004 -0.063144", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7234.043457 290.880035 2501.701660", "-2.545910 0.005618 -0.049845", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7226.847168 294.387909 2506.096436", "-0.127516 -0.037978 0.068957", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7219.230957 296.190308 2503.458252", "2.002289 -0.010314 0.044770", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7215.162598 298.910675 2516.919189", "-2.074389 0.034283 -0.009066", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7216.670410 298.791534 2511.959473", "-0.035858 0.029775 -0.066238", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7202.161621 304.754242 2434.251221", "0.885901 0.011460 -0.039589", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7225.737793 294.791809 2447.898682", "1.903153 -0.001323 0.026208", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7226.354980 295.046051 2445.083740", "2.306218 0.027325 0.053497", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7205.232910 302.706451 2446.462646", "-1.371996 -0.059233 0.000028", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7202.194336 303.543427 2440.684326", "1.848695 -0.036904 -0.044506", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7221.012695 296.592346 2442.273438", "1.685705 0.008064 -0.019352", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7218.881348 298.192810 2437.620605", "-2.359526 -0.017098 0.033623", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7221.400391 297.431641 2447.457031", "2.558182 -0.030061 -0.016378", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7254.157715 289.500275 2486.944092", "2.403054 0.002435 -0.062169", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7262.578613 286.948364 2508.982666", "-2.443898 0.016412 -0.046585", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7267.327148 287.475189 2508.567871", "-1.307758 -0.028399 -0.019663", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7245.682617 289.992096 2503.570068", "-2.003056 -0.031548 0.001391", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7250.197266 290.213684 2498.677734", "1.455984 0.042605 0.001847", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7257.632813 289.409393 2493.345947", "0.311791 -0.026571 -0.014746", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7262.948730 287.526611 2504.056396", "-0.148033 0.017631 0.006735", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7258.730957 289.992615 2487.607178", "-1.279762 0.054562 -0.055572", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7252.845215 288.573853 2515.218994", "-0.283411 -0.030653 0.026264", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7253.061523 288.425507 2508.258057", "-2.322517 0.023724 -0.046530", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7262.811035 287.076294 2527.159668", "-1.116580 0.038766 0.043628", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7270.025391 286.777435 2525.739502", "2.540158 -0.056386 0.042976", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7279.104004 290.975616 2504.868408", "-0.018025 -0.069613 -0.026528", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7278.665039 290.412598 2513.177002", "-2.822419 -0.068867 0.026464", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7272.886230 289.513885 2500.463867", "0.323872 0.019787 0.054856", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7258.492676 287.596252 2517.651855", "2.223764 0.063643 0.060221", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7280.571289 289.898132 2520.723633", "-2.900845 -0.034867 -0.025139", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7287.422363 289.412292 2525.190674", "-0.628568 -0.044071 -0.035481", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7283.335449 292.239349 2512.669189", "-2.573140 0.039772 0.047297", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7271.422852 286.001617 2533.025146", "1.859241 -0.017831 -0.069813", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7269.458984 286.806946 2524.634277", "1.097597 -0.003424 -0.051418", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7277.488770 286.014832 2536.544678", "0.503736 -0.047007 -0.050186", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7290.339844 288.753357 2526.285156", "2.565277 0.000266 -0.060532", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7278.037598 286.057587 2535.592529", "-2.700655 -0.050753 -0.022787", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7298.317871 293.316681 2510.718018", "1.853297 0.022527 -0.048315", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7309.301758 292.775696 2515.260986", "0.361839 -0.007455 -0.032089", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7298.098633 300.084412 2497.975586", "1.198075 0.065586 -0.034880", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7288.682617 296.007935 2502.181885", "0.813610 0.064227 0.041962", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7304.390625 297.348389 2502.596191", "-2.347445 0.044774 0.032238", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7295.367676 298.009644 2503.063232", "2.384646 0.033836 0.015952", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7302.676758 291.112610 2517.942383", "1.802866 0.061568 -0.059744", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7300.290527 290.476624 2519.744629", "2.044858 -0.066839 0.025774", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7324.873535 292.501770 2518.632080", "0.620514 -0.022795 -0.048673", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7319.928711 292.786682 2517.041992", "1.027990 0.053348 -0.041033", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7311.708008 290.591339 2523.040283", "2.833348 -0.066153 -0.029251", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7317.300293 293.764038 2514.628662", "-1.746107 0.068271 -0.037151", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7320.855957 301.209839 2500.616699", "1.840258 0.063089 -0.055210", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7308.804688 294.238586 2511.283691", "2.393850 -0.067623 -0.022557", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7315.229980 290.575073 2523.424072", "0.495107 -0.030384 -0.000935", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7331.627930 290.729309 2524.100586", "-0.308340 -0.061171 0.017788", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7334.895996 300.392944 2505.673096", "0.813801 0.022642 0.069332", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7331.275879 299.507935 2507.600586", "1.153972 -0.034066 0.032281", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7336.017578 294.223114 2517.066895", "-2.923664 -0.023592 0.004493", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7328.966797 299.013367 2508.092529", "-2.427023 0.065978 -0.068837", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7337.478027 296.089142 2514.030518", "1.841600 0.009436 0.067384", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7338.125977 291.161652 2523.416016", "0.683026 -0.050655 0.001255", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7314.462891 297.116852 2507.379150", "0.678232 0.040982 -0.001592", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7328.744141 297.178680 2511.884766", "2.023382 -0.024943 0.060012", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7336.048340 300.284119 2505.934570", "-1.323099 0.032651 0.042273", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7341.098145 306.727478 2494.402588", "1.855215 0.062463 0.024568", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7326.437500 297.040344 2511.692627", "-0.695682 0.025386 0.035677", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7320.397461 301.217041 2500.458496", "-0.822622 -0.004216 -0.046607", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7313.761719 302.879028 2494.113770", "0.590984 -0.030150 -0.022672", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7334.403320 311.864807 2486.676270", "2.386372 -0.020422 0.007668", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7339.245605 310.416107 2488.701172", "0.110066 0.014784 0.018802", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7327.112793 299.370026 2507.196045", "2.630857 0.032366 0.031488", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7335.230957 289.563751 2528.331543", "-1.440259 0.001238 0.012850", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7336.401367 291.515198 2522.397949", "-0.053499 0.017673 0.006125", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7333.873047 298.372955 2509.628662", "-1.320990 -0.040637 0.018768", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7338.008789 297.906677 2510.624268", "-0.203259 0.029771 0.056194", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7344.086426 291.825256 2521.217529", "-1.152438 -0.034450 -0.064065", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7351.805664 297.639069 2510.989258", "2.823761 0.014511 -0.015849", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7356.259766 295.491058 2515.815674", "1.617249 0.046014 -0.065590", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7354.061035 295.571289 2514.630615", "3.093367 0.005333 -0.061623", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7344.489746 297.166046 2512.647949", "0.752249 -0.037117 -0.056561", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7332.177734 291.971161 2521.246094", "-2.297205 -0.024981 0.036022", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7335.934082 291.636444 2522.362061", "0.838538 -0.059556 -0.042814", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7347.245605 286.897644 2542.955078", "-0.075551 0.005393 0.038911", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7346.775391 286.410858 2540.233398", "-0.791174 -0.003778 0.054337", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7345.501465 286.593262 2541.530762", "-2.970452 -0.058606 0.025531", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7342.089355 293.345459 2518.474121", "0.760686 0.052376 0.001515", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7341.410645 290.335999 2524.520020", "1.703346 0.023856 0.063174", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7350.933594 289.247742 2526.564941", "2.457704 0.000309 0.036938", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7347.185547 286.074860 2536.779785", "-0.376796 -0.041319 -0.035954", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7352.369629 286.042908 2538.336670", "-1.770651 0.032029 -0.022194", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7367.521484 294.237244 2518.285156", "-1.072285 -0.036337 -0.047847", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7350.964355 286.302246 2539.541016", "-0.804981 -0.064559 -0.001229", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7358.626953 296.458893 2513.528320", "-3.107747 0.051230 0.061849", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7354.144043 290.504547 2524.075928", "-2.249075 -0.022514 0.018981", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7369.761719 291.982330 2521.150635", "1.651764 -0.002440 0.008972", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7325.881348 285.950012 2541.746582", "-2.841594 0.063809 -0.042998", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7330.424316 286.717468 2536.241455", "2.703148 0.032933 -0.010578", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7313.211426 286.461060 2536.193604", "0.920225 0.066046 -0.065948", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7332.251465 287.225494 2534.634033", "-2.562784 0.059066 -0.011916", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7312.089844 290.472351 2523.811768", "1.106225 0.059399 0.051273", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7334.817871 286.309814 2536.695068", "0.664617 0.006901 -0.055368", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7319.916504 289.585022 2528.912842", "1.867486 0.050740 -0.004302", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7323.720703 285.868988 2537.456543", "-0.563947 0.045985 0.035481", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7385.404785 290.160706 2520.998291", "-1.044673 0.018998 0.023013", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7374.066406 286.430847 2532.253418", "2.817050 0.010391 0.031556", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7384.587402 293.240326 2514.625732", "2.410149 0.040172 0.052577", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7383.592285 286.195618 2537.174072", "1.382926 0.048959 -0.007941", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7387.672852 285.951080 2531.253174", "1.478419 0.051972 -0.031480", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7378.845215 286.557434 2531.131836", "0.400381 0.002128 0.025565", 1);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7400.220215 290.086517 2517.569824", "-0.112176 -0.050135 -0.068283", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7395.071777 286.600220 2535.074219", "-1.133455 -0.058866 0.044911", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7393.269531 303.030060 2488.821533", "-1.155122 0.037526 -0.032247", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7385.663086 299.493011 2499.907227", "-0.982352 0.016416 0.056041", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7379.855957 300.430939 2499.117920", "-0.395012 -0.061414 -0.069468", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7385.902344 292.263702 2516.796387", "-0.097603 -0.000130 -0.046705", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7389.869141 299.263306 2499.528564", "-0.390985 0.037645 0.043330", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7388.893066 292.050751 2516.452393", "1.402484 0.057162 0.052342", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7385.722656 299.820587 2499.166260", "-1.403635 -0.062441 -0.051413", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7383.519531 295.317017 2509.943604", "-1.865569 -0.006905 -0.051703", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7376.953125 304.180634 2492.442383", "-0.106231 0.044966 -0.015070", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7357.335938 297.577362 2509.629883", "-0.591176 0.011558 0.005814", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7369.825684 297.308807 2508.996094", "3.060960 0.008614 0.011333", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7361.972656 304.865417 2494.786865", "2.294713 -0.058359 0.045541", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7372.917480 299.420746 2502.655762", "-1.130003 0.023298 0.016429", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7353.912109 306.161438 2494.755371", "3.020692 0.058351 0.025902", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7373.176758 299.249786 2503.371338", "0.984462 -0.067082 0.019062", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7368.068848 295.839569 2514.082520", "-1.285707 0.051371 0.009492", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7348.167480 304.920715 2496.703125", "-2.807270 -0.025923 0.028995", 1);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7343.480469 316.946991 2477.426758", "-2.367196 -0.060098 -0.023579", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7340.348633 315.925598 2481.219238", "-2.271511 -0.028147 -0.037513", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7341.002930 306.549316 2494.645996", "-0.755509 0.005197 0.022655", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7355.646484 302.064423 2499.267822", "-3.101228 -0.026281 -0.064960", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7345.202637 316.052307 2480.284424", "-1.387911 -0.004276 0.058713", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7336.716309 313.373779 2484.736084", "-0.583506 0.018939 0.025233", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7338.019043 315.996124 2481.000488", "-3.006502 0.041425 0.030764", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7332.232422 317.550842 2475.275391", "2.143037 0.011303 0.061619", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7340.036133 308.766541 2491.575684", "-0.504312 -0.033678 0.036836", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7324.457520 315.556213 2477.548828", "0.808816 -0.024359 -0.041199", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7330.258789 317.120514 2475.577881", "1.409388 -0.041340 -0.010855", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7321.043945 307.589172 2489.803711", "3.039675 0.052815 -0.067930", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7333.121094 306.821228 2494.570801", "-1.628562 -0.029443 0.046470", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7342.654785 306.928314 2494.213867", "-2.856167 0.049257 -0.009462", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7330.033691 305.467468 2496.058594", "-0.318694 -0.055065 -0.051929", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7302.398438 286.073059 2538.827881", "-2.033929 0.021483 0.045120", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7242.192871 287.105682 2564.554688", "-0.818020 0.013480 -0.002618", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7236.479492 287.549500 2563.058838", "-2.357033 -0.020669 -0.019544", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7236.154297 287.584686 2563.416992", "1.794621 0.017976 -0.058001", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7243.833008 287.087372 2564.215820", "-2.467291 -0.057682 0.055504", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7244.541992 287.429993 2559.091797", "1.476310 0.047779 -0.028054", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7239.035645 287.975220 2558.004395", "-2.526735 0.039439 -0.056075", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7235.230957 287.740662 2564.080322", "-0.445251 0.001268 0.012441", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7243.810547 287.148346 2561.773926", "2.578125 0.056318 0.048878", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7240.930664 290.986847 2595.019531", "-1.854447 -0.049483 -0.034437", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7238.596191 292.975891 2599.839355", "1.103733 -0.040914 0.066979", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7245.137207 291.534729 2598.166992", "-2.759715 -0.060767 0.045235", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7230.571777 290.712067 2592.069580", "0.792709 0.065854 0.052555", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7246.111328 292.330658 2602.312500", "1.868062 0.045661 0.057379", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7246.484863 290.083588 2593.767822", "-2.020506 -0.053203 0.008529", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7250.761230 290.861847 2599.019287", "1.238536 -0.001319 0.016821", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7236.400879 292.651886 2598.116699", "2.348979 0.060183 -0.004336", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7262.735352 287.140503 2590.316650", "-1.892415 -0.015854 -0.009061", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7244.771484 291.259705 2597.521484", "2.104494 -0.002755 0.005768", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7254.476074 290.626770 2602.124023", "2.724241 -0.012914 0.015334", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7249.952148 291.067902 2599.212158", "-1.585609 0.003143 0.033193", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7257.281738 289.886078 2602.057861", "-2.478989 0.010983 -0.006978", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7264.308594 287.231140 2593.026123", "-0.046021 -0.002469 -0.008678", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7257.010254 287.959167 2589.971924", "-1.512359 0.023967 -0.010928", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7250.237305 291.226135 2600.412354", "-0.302971 -0.052969 -0.050280", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7254.849121 291.086945 2606.816406", "1.374488 0.011201 0.055023", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7277.100586 287.020111 2605.388184", "0.543238 -0.060145 0.052078", 0.999991);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7262.304199 289.241791 2609.739014", "-0.351484 0.043300 -0.061781", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7274.230469 287.731140 2610.317383", "-2.954920 -0.013361 -0.042738", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7258.606445 290.426331 2611.311523", "-0.703160 -0.047531 -0.064972", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7266.300293 288.684143 2611.532715", "-2.952428 0.015270 0.039137", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7260.429199 289.853851 2613.837646", "1.372188 -0.047842 -0.049492", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_3f.p3d", "7264.786621 288.565887 2606.635986", "2.370264 0.048448 -0.062714", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7241.510742 287.443146 2578.403809", "-1.387144 -0.006100 0.041063", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7228.097656 291.221008 2589.878662", "2.110630 0.016808 -0.068897", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3s.p3d", "7239.967773 287.597443 2583.605713", "-0.948796 0.008367 -0.058137", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7228.492188 291.438721 2575.070313", "-0.954357 0.015611 -0.036670", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7233.498047 289.366302 2586.067383", "-0.572193 -0.055888 -0.021751", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7240.311523 287.387665 2581.683594", "-2.841977 0.021074 0.069182", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7241.455566 288.496399 2589.716064", "1.512168 -0.050663 0.024189", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7245.844727 287.017181 2583.783203", "-2.709284 -0.036103 -0.062688", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7253.962402 288.083771 2588.825195", "-1.675158 -0.049743 -0.023805", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7246.930176 288.001648 2588.626953", "1.051384 0.062105 0.043168", 0.999993);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7259.199707 287.307373 2583.807861", "-0.704118 -0.052253 -0.062250", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7250.893066 290.610596 2598.032959", "-0.510064 -0.048733 -0.060519", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7249.513672 290.254852 2595.268311", "2.301233 0.050497 0.047766", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7259.689453 287.791046 2590.743652", "-2.839293 -0.057336 0.004238", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7246.040039 288.424255 2589.458740", "-1.585226 -0.014742 -0.039077", 0.99999);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7239.644043 287.773224 2585.240723", "-2.559525 0.059902 -0.021027", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7214.672363 292.990173 2582.082031", "-1.376215 -0.059936 -0.018410", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7205.166992 294.564362 2577.908936", "1.583500 -0.041050 -0.001012", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7197.859375 295.628174 2575.657959", "1.504114 -0.047659 -0.043121", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7212.679199 295.161743 2567.127441", "-0.834511 0.028066 0.029754", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7204.861328 296.525513 2565.995117", "-2.136325 0.003995 -0.047067", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7208.983887 295.801270 2568.523438", "-0.589067 -0.045963 0.037577", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7209.312012 295.742096 2566.121826", "0.919841 0.003594 -0.030870", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7207.014648 295.936401 2569.459473", "-1.342274 -0.066979 -0.003121", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7204.115234 297.070770 2552.809326", "-0.165484 0.066886 -0.038293", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7199.045898 297.167877 2565.573242", "2.197685 0.038417 0.000765", 0.999992);
SpawnObject("dz/plants/tree/t_piceaabies_3d.p3d", "7209.094238 295.872894 2563.984131", "-0.439115 -0.006113 -0.033201", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1f.p3d", "7208.539063 295.908539 2564.344482", "-2.679562 -0.037577 0.002065", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7195.466797 298.276459 2556.533936", "1.048508 0.048703 0.039597", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7204.184570 296.579407 2563.095947", "0.023969 -0.005009 0.000104", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1sb.p3d", "7195.220215 298.630127 2553.120850", "-1.327126 0.017268 -0.063494", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_2s.p3d", "7195.597168 297.275024 2569.359619", "1.670364 -0.016719 -0.013506", 0.999994);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7180.176270 303.479492 2552.477051", "-1.533452 -0.001298 0.046398", 0.999999);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7191.283691 298.418335 2562.965576", "0.285904 0.064320 -0.036495", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7183.586426 300.407349 2560.237793", "2.989819 -0.030470 -0.014580", 0.999996);
SpawnObject("dz/plants/tree/t_piceaabies_2d.p3d", "7184.282227 299.416992 2563.852539", "-1.017827 0.018423 -0.053403", 0.999997);
SpawnObject("dz/plants/tree/t_piceaabies_2fb.p3d", "7197.850098 298.334442 2551.322266", "2.774480 0.036005 -0.050702", 0.999998);
SpawnObject("dz/plants/tree/t_piceaabies_2f.p3d", "7188.153809 302.195129 2544.491211", "-2.296438 -0.011648 0.039090", 0.999995);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7181.914063 302.129242 2556.419678", "2.811296 -0.008086 0.037386", 1);
SpawnObject("dz/plants/tree/t_piceaabies_1s.p3d", "7178.060059 303.917175 2552.347900", "2.282250 -0.008878 -0.050041", 0.999998);


		// -- Dynamic_custom_events (spawn_randomly) ------------------------------------------------------

		// Losujemy liczbę od 1 do 10
		
		int choice = Math.RandomInt(1, 11); // Math.RandomInt(a,b) -> [a, b-1]
		
		switch ( choice )
		{
			case 1:
			{
				// przykład: spawn kilku obiektów / event 1
				
				break;
			}
			case 2:
			{
				// event 2
				
				break;
			}
			case 3:
			{
				// event 3
				
				break;
			}
			case 4:
			{
				// event 4
			
				break;
			}
			case 5:
			{
				// event 5
				
				break;
			}
			case 6:
			{
				// event 6
				
				break;
			}
			case 7:
			{
				// event 7
				
				break;
			}
			case 8:
			{
				// event 8
				
				break;
			}
			case 9:
			{
				// event 9
			
				break;
			}
			case 10:
			{
				// event 10
		
				break;
			}
			default:
			{
				// safety
				break;
			}
		}

}

enum Identity
{
    ANY = 0,
    NAME = 1,
    STEAMID = 2,
    PID = 3
}	

class CustomMission: MissionServer
{
// SteamIDs of all admin players stored here
	
	// --- Stacje / przystanki (pola klasy) ---
private const vector STOP_TOPOLIN = "1383.1 178.2 7666.1".ToVector();
private const vector STOP_GRABIN  = "10614.3 182.04 11075.9".ToVector();
private const vector STOP_FACTORIA = "7345.88 0 2615.05".ToVector();

// Jeśli Factorii ma alternatywne 'triggery' - traktujemy Topolin i Grabin jako stacje Factorii
private ref array<vector> FACTORIA_ALTERNATE_TRIGGERS;
	
	private ref TStringArray m_admins;
	
	// Players that have God Mode enabled, listed here
	private ref TIntArray m_gods;
	
	// Keep track of internal call queue limit to prevent overloads
	private int m_calls;
	
	// Limit the number of function calls
	// TODO: figure out proper limit when the performance starts to degrade
	// TODO make constant
	private int CALLS_LIMIT;
	
	override void OnInit()
	{
		
		
		super.OnInit();
		
		// Initialize needed class members here
		m_calls = 0;
		CALLS_LIMIT = 50;

		m_admins = new TStringArray;
		m_gods = new TIntArray;
		
		LoadAdmins();
		    // Inicjalizacja alternatywnych triggerów factorii
    FACTORIA_ALTERNATE_TRIGGERS = new array<vector>;
    FACTORIA_ALTERNATE_TRIGGERS.Insert(STOP_TOPOLIN);
    FACTORIA_ALTERNATE_TRIGGERS.Insert(STOP_GRABIN);
	}
	
	void LoadAdmins()
	{
		string path = "$profile:admins.txt";
		
		FileHandle file = OpenFile(path, FileMode.READ);
		
		// If file doesnt exist, create it
		if ( file == 0 ) {
			file = OpenFile(path, FileMode.WRITE);
			
			FPrintln(file, "// This file contains SteamID64 of all server admins. Add them below.");
			FPrintln(file, "// Line starting with // means a comment line.");
			
			CloseFile(file);
			return;
		}
		
		string line;
		
		while ( FGets( file, line ) > 0 )
		{
			if (line.Length() < 2) continue;
			if (line.Get(0) + line.Get(1) == "//") continue;
			
			m_admins.Insert(line);
		}
		
		CloseFile(file);
	}
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

bool Command(PlayerBase player, string command)
	{
		const string helpMsg = "Available commands: /help /car /warp /kill /give /gear /ammo /say /info /heal /god /suicide /here /there";

		// Split command message into args
		TStringArray args = new TStringArray;
		MySplit(command, " ", args);
		

		string arg;
		PlayerBase target;
		int dist;
		
		switch (args[0])
		{
			case "/car":
				if ( args.Count() != 2 ) {
					SendPlayerMessage(player, "Syntax: /car [TYPE] - Spawn a vehicle");
					SpawnCar(player, "help");
					return false;
				}
				SpawnCar(player, args[1]);
				break;
				
		case "/topolin":
{
    // Z Factorii -> Topolin (target = STOP_TOPOLIN)
    //TryTeleportNetwork(player, "factoria", 1383.1 178.2 7666.1, 5.0, 8, 14, 16, 20, "Teleportacja do Topolina.");
    break;
}

case "/grabin":
{
    // Z Factorii -> Grabin (target = STOP_GRABIN)
    //TryTeleportNetwork(player, "factoria", 7345.88 0 2615.05, 5.0, 8, 14, 16, 20, "Teleportacja do Grabina.");
    break;
}

case "/factoria":
{
    // Z Topolin/Grabin -> Factorii (target = STOP_FACTORIA)
    //TryTeleportNetwork(player, "town", 7345.88 0 2615.05, 5.0, 8, 14, 16, 20, "Teleportacja do Factorii.");
    break;
}

				
			case "/warp":
				if ( args.Count() < 3 ) {
				SendPlayerMessage(player, "Syntax: /warp [X] [Z] - Teleport to [X, Z]");
					return false;
				}
				string pos = args[1] + " " + "0" + " " + args[2];
				SafeSetPos(player, pos);
				SendPlayerMessage(player, "Teleported to: " + pos);
				break;
				
			case "/heal":
				if ( args.Count() != 1 ) {
					SendPlayerMessage(player, "Syntax: /heal - Set all health statuses to max");
					return false;
				}
				RestoreHealth(player);
				break;
				
			case "/gear":
				if ( args.Count() != 2 ) {
					SendPlayerMessage(player, "Syntax: /gear [TYPE] - Spawn item loadout to self");
					SpawnGear(player, "help");
					return false;
				}
				if (SpawnGear(player, args[1])) {
					SendPlayerMessage(player, "Gear spawned.");
				}
				break;
				
			case "/ammo":
				// Args count: 2 <= x <= 3
				if ( args.Count() < 2 || args.Count() > 3 ) {
					SendPlayerMessage(player, "Syntax: /ammo [FOR_WEAPON] (AMOUNT) - Spawn mags and ammo for weapon");
					SpawnAmmo(player, "help");
					return false;
				}
				if ( args.Count() == 3 && SpawnAmmo(player, args[1], args[2].ToInt()) ) {
					SendPlayerMessage(player, "Ammo spawned.");
				}
				else if ( args.Count() == 2 && SpawnAmmo(player, args[1]) ) {
					SendPlayerMessage(player, "Ammo spawned.");
				}
				break;
				
			case "/info":
				if ( args.Count() < 1 || args.Count() > 2 ) {
					SendPlayerMessage(player, "Syntax: /info (0/1) - Get information about players on the server or set continuous info on/off");
					return false;
				}
				if (args.Count() == 2) {
					arg = args[1];
					arg.ToLower();
					
					if (arg.ToInt() == 1) {
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.PlayerInfo, 20000, true, player);
						SendPlayerMessage(player, "Continuous info mode enabled.");
						break;
					}
					else if (arg.ToInt() == 0) {
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.PlayerInfo);
						SendPlayerMessage(player, "Continuous info mode disabled.");
					}
				}
				else {
					PlayerInfo(player);
				}
				break;
				
			case "/say":
				if ( args.Count() < 2 ) {
					SendPlayerMessage(player, "Syntax: /say [MESSAGE] - Global announcement to all players");
					return false;
				}
				
				// Form the message string from the command text and send to all players
				string msg = command.Substring( 5, command.Length() - 5 );
				
				SendGlobalMessage(msg);
				break;
				
			case "/spawn":
				return false;
				
			case "/god":
				if ( args.Count() != 2 ) {
					SendPlayerMessage(player, "Syntax: /god [0-1] - Enable or disable semi god mode (BEWARE: huge damage in short timespan can still kill you!)");
					return false;
				}
				
				int setGod = args[1].ToInt();
				int pId = player.GetID();

				// Add player to gods, call godmode function every 1 sec
				if (setGod == 1) {
					
					if ( m_gods.Find(pId) != -1 ) {
						SendPlayerMessage(player, "You are already god.");
						return false;
					}

					// Here we only need to add the new call to queue
					// However make sure we are within safe limits
					// TODO: Figure out more robust system to ensure performance does not degrade over time
					if (m_calls < CALLS_LIMIT) {
						m_gods.Insert( pId );
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.GodMode, 1000, true, player);
						m_calls += 1;
						SendPlayerMessage(player, "God mode enabled.");
					} else {
						SendPlayerMessage(player, "ERROR: Call queue limit reached. Please try again later.");
					}
				}
				// Do vice versa except for other gods
				else if (setGod == 0) {
					// Remove player id from gods list if found
					int godIdx = m_gods.Find( pId );

					if (godIdx == -1) {
						SendPlayerMessage(player, "God mode not currently enabled for player.");
						return false;
					}
					else {
						m_gods.Remove(godIdx);
					}
					
					// The problem is we cant remove the interval function call for a specific player
					// We also dont want to check for all god players in a single fucntion call => too slow
					// Thus we need to re-queue the function call for each god player separately (serverside)
					// Remove godmode function from call queue but add again for remaining gods
					RefreshGodQueue();
					
					SendPlayerMessage(player, "Godmode disabled.");
				}
				else {
					SendPlayerMessage(player, "ERROR: Invalid argument given. Argument should be: 0-1");
					return false;
				}
				break;
				
			case "/give":
				if ( args.Count() < 2 || args.Count() > 3 ) {
					SendPlayerMessage(player, "Syntax: /give [ITEM_NAME] (AMOUNT) - Spawn item on ground, default amount is 1");
					return false;
				}
				
				EntityAI item = player.SpawnEntityOnGroundPos(args[1], player.GetPosition());
				
				if (!item) {
					SendPlayerMessage(player, "ERROR: Could not create item.");
					return false;
				}
				if ( args.Count() == 3 ) {
					
					int itemCount = args[2].ToInt();
					
					if (itemCount <= 0) {
						SendPlayerMessage(player, "ERROR: Invalid count.");
						return false;
					}
					
					// Spawn the rest of the items if count was specified and valid
					for (int i = 0; i < itemCount - 1; i++) {
						player.SpawnEntityOnGroundPos(args[1], player.GetPosition());
					}
				}
				SendPlayerMessage(player, "Item(s) spawned.");
				break;
				
			case "/here":
				if ( args.Count() < 2 ) {
					SendPlayerMessage(player, "Syntax: /here '[PLAYER IDENTITY]' (DISTANCE) - Moves a player to self, remember to use single quotes around identity");
					return false;
				}
				
				PrepareTeleport(command, args, target, dist);
				
				if (!target) {
					SendPlayerMessage(player, "Could not found target player.");
					return false;
				}				
				if (dist < 1) {
					SendPlayerMessage(player, "Invalid distance.");
					return false;
				}
				TeleportPlayer(target, player, dist);					
				break;
				
			case "/there":
				if ( args.Count() < 2 ) {
					SendPlayerMessage(player, "Syntax: /there '[PLAYER IDENTITY]' (DISTANCE) - Moves self to a player");
					return false;
				}
				
				PrepareTeleport(command, args, target, dist);
				
				if (!target) {
					SendPlayerMessage(player, "Could not found target player.");
					return false;
				}				
				if (dist < 1) {
					SendPlayerMessage(player, "Invalid distance.");
					return false;
				}
				TeleportPlayer(player, target, dist);					
				break;

			case "/suicide":
				if ( args.Count() != 1 ) {
					SendPlayerMessage(player, "Syntax: /suicide - Commit a suicide");
					return false;
				}
				
				// Use SteamID here for sake of certainty
				if (!KillPlayer( player.GetIdentity().GetPlainId() )) {
					SendPlayerMessage(player, "Could not commit suicide.");
				}
				break;

			case "/kill":
				if ( args.Count() < 2 ) {
					SendPlayerMessage(player, "Syntax: /kill '[PLAYER IDENTITY]' - Kills a player by given identity, use single quotes around");
					return false;
				}
				
				arg = MyTrim(command, "'");
				
				if (!KillPlayer(arg)) {
					SendPlayerMessage(player, "Error: Could not kill player.");
				}	
				break;

			case "/help":
				SendPlayerMessage(player, helpMsg);
				return false;

			default:
				SendPlayerMessage(player, "Unknown command!");
				SendPlayerMessage(player, helpMsg);
				return false;
		}
		
		return true;
	}
	
	void PrepareTeleport(string cmd, TStringArray args, out PlayerBase target, out int distance)
	{
		// Parse target player name: "...stuff 'input' stuff..." -> "input"
		string name = MyTrim(cmd, "'");
		
		distance = args[args.Count() - 1].ToInt();
		target = GetPlayer(name, Identity.ANY);
	}
	
	bool SpawnAmmo(PlayerBase player, string type, int amount = 1)
	{
		type.ToLower();
		
		const string helpMsg = "Available ammo types: svd, m4, akm, fx45";

		vector pos = player.GetPosition();
		pos[0] = pos[0] + 1;
		pos[1] = pos[1] + 1;
		pos[2] = pos[2] + 1;
		
		string mag;
		string ammo;
		
		switch (type)
		{
			case "svd":
				mag = "Mag_SVD_10Rnd";
				ammo = "AmmoBox_762x54Tracer_20Rnd";
				break;
			
			case "m4":
				mag = "Mag_STANAG_30Rnd";
				ammo = "AmmoBox_556x45Tracer_20Rnd";
				break;
				
			case "akm":
				mag = "Mag_AKM_30Rnd";
				ammo = "AmmoBox_762x39Tracer_20Rnd";
				break;
			
			case "fx45":
				mag = "Mag_FNX45_15Rnd";
				ammo = "AmmoBox_45ACP_25rnd";
				break;

			case "help":
				SendPlayerMessage(player, helpMsg);
				return false;
			
			default:
				SendPlayerMessage(player, "Invalid ammo type.");
				SendPlayerMessage(player, helpMsg);
				return false;
		}
		
		for (int i = 0; i < amount; i++)
		{
			player.SpawnEntityOnGroundPos(mag, pos);
			player.SpawnEntityOnGroundPos(ammo, pos);
		}
		
		return true;
	}

	// Just keep track of the active calls, no boundary checks here
	void RefreshGodQueue()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.GodMode);
		m_calls = 0;

		foreach (int pId : m_gods)
		{
			PlayerBase godPlayer = GetPlayer(pId.ToString(), Identity.PID);
			if (!godPlayer) {
				m_gods.Remove( pId );
				continue;
			}
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.GodMode, 1000, true, godPlayer);
			m_calls += 1;
		}
	}

	void GodMode(PlayerBase player)
	{
//		// if we only had the PID
//		PlayerBase player = GetPlayer(pId.ToString(), Identity.PID);

		// If invalid player
		if (!player) {
			// Make sure this function call gets removed from the queue
			// So the function call queue does not get overloaded
			// Refresh call takes care of removing invalid PIDs
			RefreshGodQueue();
			return;
		}
		
		int pId = player.GetID();
		
		// If player is not god, do nothing
		if (m_gods.Find( pId ) == -1) {
			// Refresh at this point to get the pid removed from the list
			RefreshGodQueue();
			return;
		}

		// If player already dead, make sure godmode gets disabled
		if (player.GetHealth("", "") <= 0.0) {
			// We have just checked pid is in the list, so manually remove the pid and refresh
			m_gods.Remove( pId );
			RefreshGodQueue();
			return;
		}
		
		// Set all health statuses to maximum
		RestoreHealth(player);
	}
	
	void RestoreHealth(PlayerBase player)
	{
		if (!player) return;
		
		player.SetHealth("GlobalHealth", "Blood", player.GetMaxHealth("GlobalHealth", "Blood"));
		player.SetHealth("GlobalHealth", "Health", player.GetMaxHealth("GlobalHealth", "Health"));
		player.SetHealth("GlobalHealth", "Shock", player.GetMaxHealth("GlobalHealth", "Shock"));
	}
	
	bool SpawnCar(PlayerBase player, string type)
	{
		type.ToLower();
		
		const string helpMsg = "Available types: offroad, olga, olgablack, sarka, gunter, humvee";
		
		// Set car pos near player
		vector pos = player.GetPosition();
		pos[0] = pos[0] + 3;
		pos[1] = pos[1] + 3;
		pos[2] = pos[2] + 3;

		Car car;
		
		switch (type)
		{
			case "offroad":
				// Spawn and build the car
				car = GetGame().CreateObject("OffroadHatchback", pos);
				car.GetInventory().CreateAttachment("HatchbackTrunk");
				car.GetInventory().CreateAttachment("HatchbackHood");
				car.GetInventory().CreateAttachment("HatchbackDoors_CoDriver");
				car.GetInventory().CreateAttachment("HatchbackDoors_Driver");
				car.GetInventory().CreateAttachment("HatchbackWheel");
				car.GetInventory().CreateAttachment("HatchbackWheel");
				car.GetInventory().CreateAttachment("HatchbackWheel");
				car.GetInventory().CreateAttachment("HatchbackWheel");
				
				SendPlayerMessage(player, "OffroadHatchback spawned.");
				break;
			
			case "olga":
				// Spawn and build the car
				car = GetGame().CreateObject("CivilianSedan", pos);
				car.GetInventory().CreateAttachment("CivSedanHood");
				car.GetInventory().CreateAttachment("CivSedanTrunk");
				car.GetInventory().CreateAttachment("CivSedanDoors_Driver");
				car.GetInventory().CreateAttachment("CivSedanDoors_CoDriver");
				car.GetInventory().CreateAttachment("CivSedanDoors_BackLeft");
				car.GetInventory().CreateAttachment("CivSedanDoors_BackRight");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				
				SendPlayerMessage(player, "CivSedan spawned.");
				break;
				
			case "olgablack":
				// Spawn and build the car
				car = GetGame().CreateObject("CivilianSedan_Black", pos);
				car.GetInventory().CreateAttachment("CivSedanHood_Black");
				car.GetInventory().CreateAttachment("CivSedanTrunk_Black");
				car.GetInventory().CreateAttachment("CivSedanDoors_Driver_Black");
				car.GetInventory().CreateAttachment("CivSedanDoors_CoDriver_Black");
				car.GetInventory().CreateAttachment("CivSedanDoors_BackLeft_Black");
				car.GetInventory().CreateAttachment("CivSedanDoors_BackRight_Black");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				car.GetInventory().CreateAttachment("CivSedanWheel");
				
				SendPlayerMessage(player, "CivSedan_Black spawned.");
				break;
				
			case "sarka":
				// Spawn and build the car
				car = GetGame().CreateObject("Sedan_02", pos);
				car.GetInventory().CreateAttachment("Sedan_02_Hood");
				car.GetInventory().CreateAttachment("Sedan_02_Trunk");
				car.GetInventory().CreateAttachment("Sedan_02_Door_1_1");
				car.GetInventory().CreateAttachment("Sedan_02_Door_1_2");
				car.GetInventory().CreateAttachment("Sedan_02_Door_2_1");
				car.GetInventory().CreateAttachment("Sedan_02_Door_2_2");
				car.GetInventory().CreateAttachment("Sedan_02_Wheel");
				car.GetInventory().CreateAttachment("Sedan_02_Wheel");
				car.GetInventory().CreateAttachment("Sedan_02_Wheel");
				car.GetInventory().CreateAttachment("Sedan_02_Wheel");
				
				SendPlayerMessage(player, "Sedan_02 spawned.");
				break;

			case "gunter":
				// Spawn and build the car
				car = GetGame().CreateObject("Hatchback_02", pos);
				car.GetInventory().CreateAttachment("Hatchback_02_Hood");
				car.GetInventory().CreateAttachment("Hatchback_02_Trunk");
				car.GetInventory().CreateAttachment("Hatchback_02_Door_1_1");
				car.GetInventory().CreateAttachment("Hatchback_02_Door_1_2");
				car.GetInventory().CreateAttachment("Hatchback_02_Door_2_1");
				car.GetInventory().CreateAttachment("Hatchback_02_Door_2_2");
				car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
				car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
				car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
				car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
				car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
				
				SendPlayerMessage(player, "Hatchback_02 spawned.");
				break;
				
				// hummer
				
			case "humvee":
			car = GetGame().CreateObject("Offroad_02", pos);
			car.GetInventory().CreateAttachment("Offroad_02_Hood");
				car.GetInventory().CreateAttachment("Offroad_02_Trunk");
				car.GetInventory().CreateAttachment("Offroad_02_Door_1_1");
				car.GetInventory().CreateAttachment("Offroad_02_Door_1_2");
				car.GetInventory().CreateAttachment("Offroad_02_Door_2_1");
				car.GetInventory().CreateAttachment("Offroad_02_Door_2_2");
				car.GetInventory().CreateAttachment("Offroad_02_Wheel");
				car.GetInventory().CreateAttachment("Offroad_02_Wheel");
				car.GetInventory().CreateAttachment("Offroad_02_Wheel");
				car.GetInventory().CreateAttachment("Offroad_02_Wheel");
				car.GetInventory().CreateAttachment("Offroad_02_Wheel");
				car.GetInventory().CreateAttachment("GlowPlug");
				SendPlayerMessage(player, "Offroad_02 spawned.");
				break;
			
			case "help":
				SendPlayerMessage(player, helpMsg);
				return false;
				
			default:
				SendPlayerMessage(player, "ERROR: Car type invalid.");
				SendPlayerMessage(player, helpMsg);
				return false;
		}
		
		// A car was spawned, so we do some common car configuration

		// Do general car building matching all car types
		car.GetInventory().CreateAttachment("CarRadiator");
		car.GetInventory().CreateAttachment("CarBattery");
		car.GetInventory().CreateAttachment("SparkPlug");
		car.GetInventory().CreateAttachment("HeadlightH7");
		car.GetInventory().CreateAttachment("HeadlightH7");
		
		// Fill all the fluids
		car.Fill(CarFluid.FUEL, car.GetFluidCapacity(CarFluid.FUEL));
		car.Fill(CarFluid.OIL, car.GetFluidCapacity(CarFluid.OIL));
		car.Fill(CarFluid.BRAKE, car.GetFluidCapacity(CarFluid.BRAKE));
		car.Fill(CarFluid.COOLANT, car.GetFluidCapacity(CarFluid.COOLANT));
		
		// Set neutral gear
		car.GetController().ShiftTo(CarGear.NEUTRAL);
		
		return true;
	}
	
	void SafeSetPos(PlayerBase player, string pos)
	{
		// Safe conversion
		vector p = pos.ToVector();
		
		// Check that position is a valid coordinate
		// 0 0 0 wont be accepted even though valid
		if (p) {
			// Get safe surface value for Y coordinate in that position
			p[1] = GetGame().SurfaceY(p[0], p[2]);
			player.SetPosition(p);
			return;
		}
		
		SendPlayerMessage(player, "Invalid coordinates.");
	}
	
// Główna funkcja: targetPos jest VECTOR, a nie string
void TryTeleportNetwork(PlayerBase player, string requiredSourceType, vector targetPos, float maxRadius, int startHour1Inclusive, int endHour1Exclusive, int startHour2Inclusive, int endHour2Exclusive, string successMsg)
{
    if (!player) return;

    // pobierz czas serwera
    int y, mo, d, hour, minute;
    GetGame().GetWorld().GetDate(y, mo, d, hour, minute);

    if (!IsTimeAllowed(hour, minute, startHour1Inclusive, endHour1Exclusive, startHour2Inclusive, endHour2Exclusive))
    {
        SendPlayerMessage(player, "Nie możesz się teleportować teraz. Dozwolone godziny: " + startHour1Inclusive.ToString() + ":00 - " + (endHour1Exclusive - 1).ToString() + ":59 oraz " + startHour2Inclusive.ToString() + ":00 - " + (endHour2Exclusive - 1).ToString() + ":59.");
        return;
    }

    // sprawdź czy gracz jest przy właściwym przystanku
 //   bool sourceOk = false;
 //   vector plPos = player.GetPosition();

 //   if (requiredSourceType == "factoria" || requiredSourceType == "factoría")
 //   {
     //   if (IsNear(plPos, STOP_FACTORIA, maxRadius)) sourceOk = true;
     //   else
     //   {
     //       for (int i = 0; i < FACTORIA_ALTERNATE_TRIGGERS.Count(); i++)
      //      {
      //          if (IsNear(plPos, FACTORIA_ALTERNATE_TRIGGERS.Get(i), maxRadius))
      //          {
      //              sourceOk = true;
      //              break;
      //          }
      //      }
      //  }
   // }
   // else if (requiredSourceType == "town")
   // {
    //    if (IsNear(plPos, STOP_TOPOLIN, maxRadius)) sourceOk = true;
    //    else if (IsNear(plPos, STOP_GRABIN, maxRadius)) sourceOk = true;
    //}
    //else
    //{
     //   SendPlayerMessage(player, "Błąd konfiguracyjny komendy.");
    //    return;
    //}

    //if (!sourceOk)
    //{
    //    SendPlayerMessage(player, "Nie jesteś przy właściwym przystanku, teleport niedostępny.");
    //    return;
    //}

    // teleportuj bezpiecznie (SafeSetPos oczekuje stringa - przekonwertujemy)
    SafeSetPos(player, targetPos.ToString());
    SendPlayerMessage(player, successMsg);
}

// IsTimeAllowed: obsługuje dwa interwały [start1, end1) oraz [start2, end2)
bool IsTimeAllowed(int hour, int minute, int start1, int end1, int start2, int end2)
{
    // pierwszy interwał
    if (hour >= start1 && hour < end1) return true;
    // drugi interwał
    if (hour >= start2 && hour < end2) return true;
    return false;
}

// IsNear: liczy dystans po XZ (ignoruje Y). true jeśli <= maxRadius.
bool IsNear(vector posA, vector posB, float maxRadius)
{
    vector d = posA - posB;
    float dx = d[0];
    float dz = d[2];
    float dist = Math.Sqrt(dx*dx + dz*dz);
    return dist <= maxRadius;
}
	
	void PlayerInfo(PlayerBase player)
	{
		if (!player) {
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.PlayerInfo);
			return;
		}
		
		// Clear chat history first
		for (int x = 0; x < 15; x++) {
			SendPlayerMessage(player, " ");
		}
		
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );

		// Send player count
		SendPlayerMessage(player, "Players on server: " + players.Count());
		
		// Maximum amount of single line entries that fit in the chat history: 12
		int max = 10;
		
		if ( players.Count() < max )
			max = players.Count();
		
		PlayerBase p;

		for ( int i = 0; i < max; ++i )
		{
			//if (i > 0)
			//	SendPlayerMessage(player, "*");
			
			Class.CastTo(p, players.Get(i));
			
			string info = "Player {" + string.ToString(i, false, false, false) + "}";
			info = info + "  " + "Name: " + p.GetIdentity().GetName();
			info = info + "  " + "Pos: " + p.GetPosition().ToString();
			info = info	+ "  " + "Health: " + p.GetHealth("GlobalHealth", "Health");
			info = info + "  " + "Blood: " + p.GetHealth("GlobalHealth", "Blood");
			info = info + "  " + "Shock: " + p.GetHealth("GlobalHealth", "Shock");
			info = info + "  " + "PlayerID: " + p.GetID();
			info = info + "  " + "SteamID64: " + p.GetIdentity().GetPlainId();

			SendPlayerMessage(player, info);
		}
		
		SendPlayerMessage(player, " ");
	}

	bool SpawnGear(PlayerBase player, string type) 
	{
		type.ToLower();
		
		const string helpMsg = "Available types: mil, ghillie, medic, nv, svd, m4, akm, fx45";

		vector pos = player.GetPosition();
		pos[0] = pos[0] + 1;
		pos[1] = pos[1] + 1;
		pos[2] = pos[2] + 1;
		
		// DONT spawn a mag as attachment, is buggy ingame, spawn mags in ground instead
		EntityAI item;
		EntityAI subItem;

		switch (type)
		{
			case "mil":
				// Head
				item = player.SpawnEntityOnGroundPos("Mich2001Helmet", pos);
				
				//subItem = item.GetInventory().CreateAttachment("NVGoggles");
				//subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				//player.SpawnEntityOnGroundPos("GP5GasMask", pos);
				
				// Vest
				item = player.SpawnEntityOnGroundPos("SmershVest", pos);
				item.GetInventory().CreateAttachment("SmershBag");
				
				// Body
				player.SpawnEntityOnGroundPos("TTsKOJacket_Camo", pos);
				player.SpawnEntityOnGroundPos("TTSKOPants", pos);
				player.SpawnEntityOnGroundPos("OMNOGloves_Gray", pos);
				
				// Waist
				item = player.SpawnEntityOnGroundPos("MilitaryBelt", pos);
				item.GetInventory().CreateAttachment("Canteen");
				item.GetInventory().CreateAttachment("PlateCarrierHolster");
				
				subItem = item.GetInventory().CreateAttachment("NylonKnifeSheath");
				subItem.GetInventory().CreateAttachment("CombatKnife");
				
				// Legs
				item = player.SpawnEntityOnGroundPos("MilitaryBoots_Black", pos);
				item.GetInventory().CreateAttachment("CombatKnife");
				
				// Back
				//player.SpawnEntityOnGroundPos("AliceBag_Camo", pos);

				break;

			case "ghillie":
				player.SpawnEntityOnGroundPos("GhillieAtt_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieAtt_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieBushrag_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieHood_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieSuit_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieTop_Woodland", pos);
				
				break;
				
			case "svd":
				item = player.SpawnEntityOnGroundPos("SVD", pos);
				
				item.GetInventory().CreateAttachment("AK_Suppressor");
				
				subItem = item.GetInventory().CreateAttachment("PSO1Optic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				item = player.SpawnEntityOnGroundPos("KazuarOptic", pos);
				item.GetInventory().CreateAttachment("Battery9V");				
				
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				
				break;
			
			case "m4":
				item = player.SpawnEntityOnGroundPos("M4A1", pos);
				
				item.GetInventory().CreateAttachment("M4_Suppressor");
				item.GetInventory().CreateAttachment("M4_OEBttstck");
				item.GetInventory().CreateAttachment("M4_RISHndgrd");
				
				subItem = item.GetInventory().CreateAttachment("ReflexOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
		
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				
				player.SpawnEntityOnGroundPos("ACOGOptic", pos);
				
				break;
				
			case "akm":
				item = player.SpawnEntityOnGroundPos("AKM", pos);
				
				item.GetInventory().CreateAttachment("AK_Suppressor");
				item.GetInventory().CreateAttachment("AK_WoodBttstck");
				item.GetInventory().CreateAttachment("AK_RailHndgrd");
				
				subItem = item.GetInventory().CreateAttachment("KobraOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				item = player.SpawnEntityOnGroundPos("PSO1Optic", pos);
				item.GetInventory().CreateAttachment("Battery9V");

				player.SpawnEntityOnGroundPos("Mag_AKM_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_Drum75Rnd", pos);

				break;
			
			case "fx45":
				item = player.SpawnEntityOnGroundPos("FNX45", pos);
				
				item.GetInventory().CreateAttachment("PistolSuppressor");
				
				subItem = item.GetInventory().CreateAttachment("FNP45_MRDSOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("TLRLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				
				break;
			
			case "nv":
				item = player.SpawnEntityOnGroundPos("NVGHeadstrap", pos);
				
				subItem = item.GetInventory().CreateAttachment("NVGoggles");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				break;
				
			case "medic":
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("SalineBagIV", pos);
				player.SpawnEntityOnGroundPos("Morphine", pos);
				player.SpawnEntityOnGroundPos("Epinephrine", pos);
				
				break;
				
			case "mosin":
				break;
				
			case "sks":
				break;
				
			case "help":
				SendPlayerMessage(player, helpMsg);
				return false;
			
			default:
				SendPlayerMessage(player, "Invalid gear type.");
				SendPlayerMessage(player, helpMsg);
				return false;
		}
		
		return true;
	}

	void TeleportPlayer(PlayerBase from, PlayerBase to, int distance)
	{
		if (!from) return;
		if (!to) return;
		
		vector toPos = to.GetPosition();

		float pos_x = toPos[0] + distance;
		float pos_z = toPos[2] + distance;
		float pos_y = GetGame().SurfaceY(pos_x, pos_z);
		
		vector pos = Vector(pos_x, pos_y, pos_z);
		
		from.SetPosition(pos);
	}
	
	bool KillPlayer(string tag)
	{
		PlayerBase p = GetPlayer(tag, Identity.ANY);
		
		if (!p) return false;
		
		p.SetHealth("", "", -1);
		
		return true;
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		switch(eventTypeId)
		{
			// Handle user command
			case ChatMessageEventTypeID:

				ChatMessageEventParams chatParams;
				Class.CastTo(chatParams, params);
				
				// Remove those stupid ' ' => Substring: x, false, false, quotes = false
				
				// Check that input was a command (contains forward slash)
				string cmd = string.ToString(chatParams.param3, false, false, false);

				// command format: /abc def ghi
				// if not command, is normal chat message
				if ( cmd.Get(0) != "/" ) break;
				
				// Get sender player name as string
				string senderName = string.ToString(chatParams.param2, false, false, false);
				
				// Get sender player object
				PlayerBase sender = GetPlayer(senderName, Identity.NAME);
				
				// If fails to get the message sender, stop
				if (!sender) {
					return;
				}
				
				// Check that player has sufficient privileges to execute commands
				//if ( !IsAdmin(sender) ) {
				//	SendPlayerMessage(sender, "Sorry, you are not an admin!");
				//	return;
				//}

				// Execute specified command
				Command(sender, cmd);
				
				// Return after execution instead of breaking to prevent normal event handling
				return;
		}
		
		// Unless chat command was executed, operate normally
		// Call super class event handler to handle other events
		super.OnEvent(eventTypeId, params);
	}
	
	bool IsAdmin(PlayerBase player)
	{
		return m_admins.Find( player.GetIdentity().GetPlainId() ) != -1;
	}

	PlayerBase GetPlayer(string tag, Identity type)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		
		PlayerBase p;
		
		bool nameMatch;
		bool steamIdMatch;
		bool pidMatch;
		
		for ( int i = 0; i < players.Count(); ++i )
		{
			Class.CastTo(p, players.Get(i));
			
			// Store matches from different checks
			nameMatch = p.GetIdentity().GetName() == tag;
			steamIdMatch = p.GetIdentity().GetPlainId() == tag;
			pidMatch = p.GetID() == tag.ToInt();
			
			if ( type == Identity.ANY ) {
				if ( nameMatch || steamIdMatch || pidMatch )
					return p;
			}
			
			else if ( type == Identity.NAME ) {
				if ( nameMatch )
					return p;
			}
			
			else if ( type == Identity.STEAMID ) {
				if ( steamIdMatch )
					return p;
			}

			else if ( type == Identity.PID ) {
				if ( pidMatch )
					return p;
			}
		}
		
		// Player with given parameter not found
		return NULL;
	}
	
	void SendGlobalMessage(string message)	
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		
		for ( int i = 0; i < players.Count(); ++i )
		{
			Man player = players.Get(i);
			if ( player )
				SendPlayerMessage(player, message);
		}
	}
	
	void SendPlayerMessage(PlayerBase player, string message)	
	{
		Param1<string> Msgparam;
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
	}
	
	string MyTrim(string text, string c)
	{
		if (text.Length() < 3) return "";
		
		int count = 0;
		
		int start = 0;
		int end = 0;

		for (int i = 0; i < text.Length(); i++)
		{
			if (text.Get(i) == c) {
				count++;
				start = i + 1;
				break;
			}
		}

		for (int j = text.Length() - 1; j >= 0; j--)
		{
			if (text.Get(j) == c) {
				count++;
				end = j - 1;
				break;
			}
		}
		
		// Return substring only if trimmed by c from both sides.
		if (count == 2) return text.Substring(start, end - start + 1);
		
		return "";
	}
	
	void MySplit(string text, string delim, out TStringArray list)
	{
		string temp = text + delim;
		string word = "";
		
		for (int i = 0; i < temp.Length(); i++ )
		{
			string x = temp.Get(i);
			
			if ( x != delim ) {
				word = word + x;
			}
			else {
				list.Insert(word);
				word = "";
			}
		}
	}
	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}	

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		EntityAI item;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			player.SetQuickBarEntityShortcut(itemEnt, 2);

			itemEnt = itemClothing.GetInventory().CreateInInventory( "BoneKnife" );
			player.SetQuickBarEntityShortcut(itemEnt, 1);
			
			
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}

