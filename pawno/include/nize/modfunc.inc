#include <a_samp>

new spoiler[20][0] = {1000, 1001, 1002, 1003, 1014, 1015, 1016, 1023, 1058, 1060, 1049, 1050, 1138, 1139, 1146, 1147, 1158, 1162, 1163, 1164};
new nitro[3][0] = {1008, 1009, 1010};
new front_bumper[23][0] = {1117, 1152, 1153, 1155, 1157, 1160, 1165, 1167, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1179, 1181, 1182, 1185, 1188, 1189, 1192, 1193};
new rear_bumper[22][0] = {1140, 1141, 1148, 1149, 1150, 1151, 1154, 1156, 1159, 1161, 1166, 1168, 1176, 1177, 1178, 1180, 1183, 1184, 1186, 1187, 1190, 1191};
new exhaust[28][0] = {1018, 1019, 1020, 1021, 1022, 1028, 1029, 1037, 1043, 1044, 1045, 1046, 1059, 1064, 1065, 1066, 1089, 1092, 1104, 1105, 1113, 1114, 1126, 1127, 1129, 1132, 1135, 1136};
new bventr[2][0] = {1042, 1044};
new bventl[2][0] = {1043, 1045};
new bscoop[4][0] = {1004, 1005, 1011, 1012};
new rscoop[13][0] = {1006, 1032, 1033, 1035, 1038, 1053, 1054, 1055, 1061, 1067, 1068, 1088, 1091};
new left_sideskirt[21][0] = {1007, 1026, 1031, 1036, 1039, 1042, 1047, 1048, 1056, 1057, 1069, 1070, 1090, 1093, 1106, 1108, 1118, 1119, 1133, 1122, 1134};
new right_sideskirt[21][0] = {1017, 1027, 1030, 1040, 1041, 1051, 1052, 1062, 1063, 1071, 1072, 1094, 1095, 1099, 1101, 1102, 1107, 1120, 1121, 1124, 1137};
new hydraulics[1][0] = {1087};
new bass[1][0] = {1086};
new rbbars[2][0] = {1109, 1110};
new fbbars[2][0] = {1115, 1116};
new wheels[17][0] = {1025, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1096, 1097, 1098};
new lights[2][0] = {1013, 1024};

stock InitComponents(componentid)
{
	new
		i = 0;

	for(i = 0; i < 20; i ++) { if(spoiler[i][0] == componentid) { return 1; } }
	for(i = 0; i < 3; i ++) { if(nitro[i][0] == componentid) { return 2; } }
	for(i = 0; i < 23; i ++) { if(front_bumper[i][0] == componentid) { return 3; } }
	for(i = 0; i < 22; i ++) { if(rear_bumper[i][0] == componentid) { return 4; } }
	for(i = 0; i < 28; i ++) { if(exhaust[i][0] == componentid) { return 5; } }
	for(i = 0; i < 2; i ++) { if(bventr[i][0] == componentid) { return 6; } }
	for(i = 0; i < 2; i ++) { if(bventl[i][0] == componentid) { return 7; } }
	for(i = 0; i < 4; i ++) { if(bscoop[i][0] == componentid) { return 8; } }
	for(i = 0; i < 13; i ++) { if(rscoop[i][0] == componentid) { return 9; } }
	for(i = 0; i < 21; i ++) { if(left_sideskirt[i][0] == componentid) { return 10; } }
	for(i = 0; i < 21; i ++) { if(right_sideskirt[i][0] == componentid) { return 11; } }
	if(hydraulics[0][0] == componentid) { return 12; }
	if(bass[0][0] == componentid) { return 13; }
	for(i = 0; i < 2; i ++) { if(rbbars[i][0] == componentid) { return 14; } }
	for(i = 0; i < 2; i ++) { if(fbbars[i][0] == componentid) { return 15; } }
	for(i = 0; i < 17; i ++) { if(wheels[i][0] == componentid) { return 16; } }
	for(i = 0; i < 2; i ++) { if(lights[i][0] == componentid) { return 17; } }
	return 0;
}