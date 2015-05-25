#include "global.h"
#include "FontCharmaps.h"

#include <map>

const wchar_t FontCharmaps::M_SKIP = 0xFEFF;

static std::map<RString,const wchar_t*> charmaps;

using namespace FontCharmaps;

/* Map ranges of Unicode characters.  This is for font mapping; don't try
 * to use it for actual conversion (if that's wanted, use iconv).
 *
 * Use M_SKIP to indicate that a glyph should be skipped, not mapped.  Do
 * this to skip control codes, for example, while keeping glyphs aligned. */

/*
 * ASCII:
 *
 (empty)
 (empty)
 !"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_
`abcdefghijklmno
pqrstuvwxyz{|}~
 */
static const wchar_t map_ascii[] = {
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, M_SKIP,
	0
};

/*
 * ISO-8859-1 (Latin1): West Europe, US, others:
 *
 (empty)
 (empty)
 ¡¢£¤¥¦§¨©ª«¬-®¯
°±²³´µ¶·¸¹º»¼½¾¿
ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏ
ÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß
àáâãäåæçèéêëìíîï
ðñòóôõö÷øùúûüýþÿ
 *
 * Non-breaking space and soft hyphen are not used.
 */
static const wchar_t map_iso_8859_1[] = {
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7, 0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
	0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7, 0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
	0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7, 0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
	0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7, 0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
	0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
	0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7, 0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff,
	0
};

/*
 * Windows codepage 1252; latin1 plus other stuff (including angled quotes):
 *
€ ‚ƒ„…†‡ˆ‰Š‹Œ Ž
 ‘’“”•–—˜™š›œ žŸ
 ¡¢£¤¥¦§¨©ª«¬-®¯
°±²³´µ¶·¸¹º»¼½¾¿
ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏ
ÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß
àáâãäåæçèéêëìíîï
ðñòóôõö÷øùúûüýþÿ
 *
 * Non-breaking space and soft hyphen are not used.
 */
static const wchar_t map_cp1252[] = {
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, M_SKIP,
	0x20AC, M_SKIP, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021, 0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, M_SKIP, 0x017D, M_SKIP,
	M_SKIP, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x017E, M_SKIP, 0x0178,
	0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
	0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
	0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
	0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
	0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
	0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
	0
};

/*
 * ISO-8859-2: Czech: (cs), Hungarian (hu), Polish (pl), Romanian (ro), Croatian (hr),
 * Slovak (sk), Slovenian (sl), Sorbian.
 *
 Ą˘Ł¤ĽŚ§¨ŠŞŤŹ­ŽŻ
°ą˛ł´ľśˇ¸šşťź˝žż
ŔÁÂĂÄĹĆÇČÉĘËĚÍÎĎ
ĐŃŇÓÔŐÖ×ŘŮÚŰÜÝŢß
ŕáâăäĺćçčéęëěíîď
đńňóôőö÷řůúűüýţ˙
 */

static const wchar_t map_iso_8859_2[] = {
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP, M_SKIP,
	0x00A0, 0x0104, 0x02D8, 0x0141, 0x00A4, 0x013D, 0x015A, 0x00A7, 0x00A8, 0x0160, 0x015E, 0x0164, 0x0179, 0x00AD, 0x017D, 0x017B,
	0x00B0, 0x0105, 0x02DB, 0x0142, 0x00B4, 0x013E, 0x015B, 0x02C7, 0x00B8, 0x0161, 0x015F, 0x0165, 0x017A, 0x02DD, 0x017E, 0x017C,
	0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7, 0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
	0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7, 0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
	0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7, 0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
	0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7, 0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9,
	0
};

/*
 * Unicode range 30: CJK Symbols and Punctuation, Hiragana, Katakana:

　、。〃〄々〆〇〈〉《》「」『』
【】〒〓〔〕〖〗〘〙〚〛〜〝〞〟
〠
〰〱〲〳〴〵〶〷
　ぁあぃいぅうぇえぉおかがきぎく
ぐけげこごさざしじすずせぜそぞた
だちぢっつづてでとどなにぬねのは
ばぱひびぴふぶぷへべぺほぼぽまみ
むめもゃやゅゆょよらりるれろゎわ
ゐゑをんゔ　　　　　　゛゜ゝゞ　
　ァアィイゥウェエォオカガキギク
グケゲコゴサザシジスズセゼソゾタ
ダチヂッツヅテデトドナニヌネノハ
バパヒビピフブプヘベペホボポマミ
ムメモャヤュユョヨラリルレロヮワ
ヰヱヲンヴヵヶヷヸヹヺ・ーヽヾ　

 */
static const wchar_t map_basic_japanese[] =
{
	0x3000,0x3001,0x3002,0x3003,0x3004,0x3005,0x3006,0x3007,0x3008,0x3009,0x300a,0x300b,0x300c,0x300d,0x300e,0x300f,
	0x3010,0x3011,0x3012,0x3013,0x3014,0x3015,0x3016,0x3017,0x3018,0x3019,0x301a,0x301b,0x301c,0x301d,0x301e,0x301f,
	0x3020,0x3021,0x3022,0x3023,0x3024,0x3025,0x3026,0x3027,0x3028,0x3029,0x302a,0x302b,0x302c,0x302d,0x302e,0x302f,
	0x3030,0x3031,0x3032,0x3033,0x3034,0x3035,0x3036,0x3037,0x3038,0x3039,0x303a,0x303b,0x303c,0x303d,0x303e,0x303f,
	0x3040,0x3041,0x3042,0x3043,0x3044,0x3045,0x3046,0x3047,0x3048,0x3049,0x304a,0x304b,0x304c,0x304d,0x304e,0x304f,
	0x3050,0x3051,0x3052,0x3053,0x3054,0x3055,0x3056,0x3057,0x3058,0x3059,0x305a,0x305b,0x305c,0x305d,0x305e,0x305f,
	0x3060,0x3061,0x3062,0x3063,0x3064,0x3065,0x3066,0x3067,0x3068,0x3069,0x306a,0x306b,0x306c,0x306d,0x306e,0x306f,
	0x3070,0x3071,0x3072,0x3073,0x3074,0x3075,0x3076,0x3077,0x3078,0x3079,0x307a,0x307b,0x307c,0x307d,0x307e,0x307f,
	0x3080,0x3081,0x3082,0x3083,0x3084,0x3085,0x3086,0x3087,0x3088,0x3089,0x308a,0x308b,0x308c,0x308d,0x308e,0x308f,
	0x3090,0x3091,0x3092,0x3093,0x3094,0x3095,0x3096,0x3097,0x3098,0x3099,0x309a,0x309b,0x309c,0x309d,0x309e,0x309f,
	0x30a0,0x30a1,0x30a2,0x30a3,0x30a4,0x30a5,0x30a6,0x30a7,0x30a8,0x30a9,0x30aa,0x30ab,0x30ac,0x30ad,0x30ae,0x30af,
	0x30b0,0x30b1,0x30b2,0x30b3,0x30b4,0x30b5,0x30b6,0x30b7,0x30b8,0x30b9,0x30ba,0x30bb,0x30bc,0x30bd,0x30be,0x30bf,
	0x30c0,0x30c1,0x30c2,0x30c3,0x30c4,0x30c5,0x30c6,0x30c7,0x30c8,0x30c9,0x30ca,0x30cb,0x30cc,0x30cd,0x30ce,0x30cf,
	0x30d0,0x30d1,0x30d2,0x30d3,0x30d4,0x30d5,0x30d6,0x30d7,0x30d8,0x30d9,0x30da,0x30db,0x30dc,0x30dd,0x30de,0x30df,
	0x30e0,0x30e1,0x30e2,0x30e3,0x30e4,0x30e5,0x30e6,0x30e7,0x30e8,0x30e9,0x30ea,0x30eb,0x30ec,0x30ed,0x30ee,0x30ef,
	0x30f0,0x30f1,0x30f2,0x30f3,0x30f4,0x30f5,0x30f6,0x30f7,0x30f8,0x30f9,0x30fa,0x30fb,0x30fc,0x30fd,0x30fe,0x30ff,
	0
};

/* Korean Jamo */
static const wchar_t map_korean_jamo[] =
{
	0x1100,0x1110,0x1120,0x1130,0x1140,0x1150,0x1160,0x1170,0x1180,0x1190,0x11a0,0x11b0,0x11c0,0x11d0,0x11e0,0x11f0,
	0x1101,0x1111,0x1121,0x1131,0x1141,0x1151,0x1161,0x1171,0x1181,0x1191,0x11a1,0x11b1,0x11c1,0x11d1,0x11e1,0x11f1,
	0x1102,0x1112,0x1122,0x1132,0x1142,0x1152,0x1162,0x1172,0x1182,0x1192,0x11a2,0x11b2,0x11c2,0x11d2,0x11e2,0x11f2,
	0x1103,0x1113,0x1123,0x1133,0x1143,0x1153,0x1163,0x1173,0x1183,0x1193,0x11a3,0x11b3,0x11c3,0x11d3,0x11e3,0x11f3,
	0x1104,0x1114,0x1124,0x1134,0x1144,0x1154,0x1164,0x1174,0x1184,0x1194,0x11a4,0x11b4,0x11c4,0x11d4,0x11e4,0x11f4,
	0x1105,0x1115,0x1125,0x1135,0x1145,0x1155,0x1165,0x1175,0x1185,0x1195,0x11a5,0x11b5,0x11c5,0x11d5,0x11e5,0x11f5,
	0x1106,0x1116,0x1126,0x1136,0x1146,0x1156,0x1166,0x1176,0x1186,0x1196,0x11a6,0x11b6,0x11c6,0x11d6,0x11e6,0x11f6,
	0x1107,0x1117,0x1127,0x1137,0x1147,0x1157,0x1167,0x1177,0x1187,0x1197,0x11a7,0x11b7,0x11c7,0x11d7,0x11e7,0x11f7,
	0x1108,0x1118,0x1128,0x1138,0x1148,0x1158,0x1168,0x1178,0x1188,0x1198,0x11a8,0x11b8,0x11c8,0x11d8,0x11e8,0x11f8,
	0x1109,0x1119,0x1129,0x1139,0x1149,0x1159,0x1169,0x1179,0x1189,0x1199,0x11a9,0x11b9,0x11c9,0x11d9,0x11e9,0x11f9,
	0x110a,0x111a,0x112a,0x113a,0x114a,0x115a,0x116a,0x117a,0x118a,0x119a,0x11aa,0x11ba,0x11ca,0x11da,0x11ea,0x11fa,
	0x110b,0x111b,0x112b,0x113b,0x114b,0x115b,0x116b,0x117b,0x118b,0x119b,0x11ab,0x11bb,0x11cb,0x11db,0x11eb,0x11fb,
	0x110c,0x111c,0x112c,0x113c,0x114c,0x115c,0x116c,0x117c,0x118c,0x119c,0x11ac,0x11bc,0x11cc,0x11dc,0x11ec,0x11fc,
	0x110d,0x111d,0x112d,0x113d,0x114d,0x115d,0x116d,0x117d,0x118d,0x119d,0x11ad,0x11bd,0x11cd,0x11dd,0x11ed,0x11fd,
	0x110e,0x111e,0x112e,0x113e,0x114e,0x115e,0x116e,0x117e,0x118e,0x119e,0x11ae,0x11be,0x11ce,0x11de,0x11ee,0x11fe,
	0x110f,0x111f,0x112f,0x113f,0x114f,0x115f,0x116f,0x117f,0x118f,0x119f,0x11af,0x11bf,0x11cf,0x11df,0x11ef,0x11ff,
	0
};

/* 5x3 Numbers. "01234 56789 %. :x" */
static const wchar_t map_numbers[] = {
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034,
	0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
	0x0025, 0x002E, 0x0020, 0x003A, 0x0078,
	0
};


static void Init()
{
	if(!charmaps.empty())
		return;

	charmaps["ascii"] = map_ascii;
	charmaps["basic-japanese"] = map_basic_japanese;
	charmaps["iso-8859-1"] = map_iso_8859_1;
	charmaps["cp1252"] = map_cp1252;
	charmaps["iso-8859-2"] = map_iso_8859_2;
	charmaps["korean-jamo"] = map_korean_jamo;
	charmaps["numbers"] = map_numbers;
}

const wchar_t *FontCharmaps::get_char_map(RString name)
{
	Init();

	name.MakeLower();

	auto i = charmaps.find(name);
	if(i == charmaps.end())
		return NULL;

	return i->second;
}

/*
 * (c) 2003 Glenn Maynard
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
