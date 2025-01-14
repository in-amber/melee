// #include <platform.h>

// #include "it_266F.h"

// #include "it/types.h"
// #include "items/itbat.h"
// #include "items/itbombhei.h"
// #include "items/itbox.h"
// #include "items/itcapsule.h"
// #include "items/itdkinoko.h"
// #include "items/itdosei.h"
// #include "items/itegg.h"
// #include "items/itevyoshiegg.h"
// #include "items/itfflower.h"
// #include "items/itfflowerflame.h"
// #include "items/itflipper.h"
// #include "items/itfoods.h"
// #include "items/itfreeze.h"
// #include "items/itgshell.h"
// #include "items/ithammer.h"
// #include "items/ithammerhead.h"
// #include "items/itharisen.h"
// #include "items/itheart.h"
// #include "items/itkinoko.h"
// #include "items/itkusudama.h"
// #include "items/itlgun.h"
// #include "items/itlgunbeam.h"
// #include "items/itlgunray.h"
// #include "items/itlipstick.h"
// #include "items/itlipstickspore.h"
// #include "items/itmball.h"
// #include "items/itmetalb.h"
// #include "items/itmsbomb.h"
// #include "items/itparasol.h"
// #include "items/itrabbitc.h"
// #include "items/itrshell.h"
// #include "items/itscball.h"
// #include "items/itspycloak.h"
// #include "items/itsscope.h"
// #include "items/itsscopebeam.h"
// #include "items/itstar.h"
// #include "items/itstarrod.h"
// #include "items/itstarrodstar.h"
// #include "items/itsword.h"
// #include "items/ittaru.h"
// #include "items/ittarucann.h"
// #include "items/ittomato.h"
// #include "items/itwstar.h"

// struct sdata_ItemGXLink it_803F1418[] = {
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_80284E10, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC, it_8026EECC,
//     it_8026EECC, it_8026EECC, it_8026EECC,
// };

// // Common items
// struct ItemLogicTable it_803F14C4[ARRAY_SIZE(it_803F1418)] = {
//     {
//         // Capsule
//         it_803F5468,
//         it_8027CF00,
//         NULL,
//         it_8027D1D4,
//         it_8027D208,
//         it_8027D230,
//         it_8027D338,
//         it_8027D414,
//         it_8027D450,
//         it_8027D4F4,
//         it_8027D4B8,
//         NULL,
//         it_8027D614,
//         it_8027D530,
//         it_8027D650,
//     },
//     {
//         // Box
//         it_803F5850,
//         it_802861CC,
//         it_80286208,
//         it_80286780,
//         it_80286964,
//         it_802867B4,
//         it_80286CB4,
//         it_80286F04,
//         it_80286FC8,
//         it_80286E70,
//         it_80286D48,
//         NULL,
//         NULL,
//         it_80286DDC,
//         it_80287084,
//     },
//     {
//         // Taru
//         it_803F58E0,
//         it_80287458,
//         NULL,
//         it_80287E68,
//         it_80287EA8,
//         it_80287EC8,
//         it_80288818,
//         it_80288A98,
//         NULL,
//         it_802889F8,
//         it_802888B8,
//         NULL,
//         NULL,
//         it_80288958,
//         it_80288C68,
//     },
//     {
//         // Egg
//         it_803F5988,
//         it_80288D98,
//         NULL,
//         it_80288F88,
//         it_80288FBC,
//         it_80288FDC,
//         it_80289218,
//         it_802895A8,
//         it_80289644,
//         it_8028950C,
//         it_802893D4,
//         NULL,
//         NULL,
//         it_80289470,
//         it_802896AC,
//     },
//     {
//         // Kusudama
//         it_803F59F8,
//         it_80289784,
//         NULL,
//         it_8028A93C,
//         it_8028AB28,
//         it_8028A970,
//         it_8028AEA4,
//         it_8028AFC4,
//         NULL,
//         it_8028AF8C,
//         it_8028AF1C,
//         NULL,
//         NULL,
//         it_8028AF54,
//         it_8028B06C,
//     },
//     {
//         // TaruCann
//         it_803F63C0,
//         it_80296120,
//         it_802960E0,
//         it_8029683C,
//         it_802968D8,
//         it_80296930,
//         it_8029789C,
//         NULL,
//         NULL,
//         it_802978B4,
//         it_802978A4,
//         NULL,
//         NULL,
//         it_802978AC,
//         it_802978BC,
//     },
//     {
//         // BombHei
//         it_803F54D8,
//         it_8027D76C,
//         NULL,
//         it_8027E0B4,
//         it_8027E648,
//         it_80280380,
//         it_80280DF0,
//         it_80280E30,
//         it_80280E9C,
//         it_802810A4,
//         it_80281070,
//         NULL,
//         it_80281104,
//         it_802810C4,
//         it_80281144,
//     },
//     {
//         // Dosei
//         it_803F55D0,
//         it_80281164,
//         NULL,
//         it_8028218C,
//         it_802826F8,
//         it_802829FC,
//         it_802839BC,
//         it_80283588,
//         it_80282B14,
//         it_80283A3C,
//         it_80283A5C,
//         NULL,
//         it_80283AA4,
//         it_80283A80,
//         it_80283AC4,
//     },
//     {
//         // Heart
//         it_803F56C8,
//         it_80283BEC,
//         it_80283C48,
//         it_80283F28,
//         it_8028402C,
//         NULL,
//         NULL,
//         NULL,
//         it_8028412C,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80284194,
//     },
//     {
//         // Tomato
//         it_803F5740,
//         it_802842A4,
//         it_80284324,
//         it_802844E4,
//         it_8028454C,
//         NULL,
//         NULL,
//         NULL,
//         it_802845BC,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80284624,
//     },
//     {
//         // Star
//         it_803F57A0,
//         it_80284644,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_8028482C,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80284834,
//     },
//     {
//         // Bat
//         it_803F57B0,
//         it_80284910,
//         NULL,
//         it_80284AAC,
//         it_80284B30,
//         it_80284BA0,
//         it_80284C78,
//         NULL,
//         it_80284C10,
//         it_80284CAC,
//         it_80284CCC,
//         NULL,
//         it_80284D14,
//         it_80284CF0,
//         it_80284D34,
//     },
//     {
//         // Sword
//         it_803F5800,
//         it_80285338,
//         NULL,
//         it_80285804,
//         it_80285B00,
//         it_80285C78,
//         it_80285FAC,
//         NULL,
//         it_80285DF0,
//         it_80285FE0,
//         it_80286000,
//         NULL,
//         itSword_BounceOffShield,
//         it_80286024,
//         it_80286068,
//     },
//     {
//         // Parasol
//         it_803F5AB0,
//         it_8028B0B8,
//         NULL,
//         it_8028B5E8,
//         it_8028B3C0,
//         it_8028B3E0,
//         it_8028B4D4,
//         NULL,
//         it_8028B580,
//         it_8028B540,
//         it_8028B4F8,
//         NULL,
//         it_8028B560,
//         it_8028B51C,
//         it_8028B8B8,
//     },
//     {
//         // G Shell
//         it_803F5BA8,
//         it_8028BDAC,
//         NULL,
//         it_8028C148,
//         it_8028C300,
//         it_8028C1AC,
//         it_8028CCA8,
//         it_8028CCCC,
//         it_8028CB24,
//         it_8028CD04,
//         it_8028CD3C,
//         NULL,
//         it_8028CF2C,
//         it_8028CE1C,
//         it_8028CFC0,
//     },
//     {
//         // R Shell
//         it_803F5C48,
//         it_8028D59C,
//         NULL,
//         it_8028D898,
//         it_8028D9F4,
//         it_8028D8E0,
//         it_8028E540,
//         it_8028E584,
//         it_8028E3CC,
//         it_8028E5C8,
//         it_8028E600,
//         NULL,
//         it_8028E684,
//         it_8028E624,
//         it_8028E718,
//     },
//     {
//         // L Gun
//         it_803F5CC8,
//         it_8028E738,
//         NULL,
//         it_8028E904,
//         it_8028E9B8,
//         it_8028E9E0,
//         it_8028EA54,
//         NULL,
//         it_8028EB00,
//         it_8028EAC0,
//         it_8028EA78,
//         NULL,
//         it_8028EAE0,
//         it_8028EA9C,
//         it_8028EB68,
//     },
//     {
//         // Freeze
//         it_803F5D28,
//         it_8028ED50,
//         it_8028ED10,
//         it_8028F2B4,
//         it_8028F318,
//         it_8028F340,
//         it_8028F3CC,
//         it_8028F42C,
//         NULL,
//         it_8028F3EC,
//         it_8028F3D4,
//         it_8028F3E4,
//         it_8028F40C,
//         it_8028F3DC,
//         it_8028F8C4,
//     },
//     {
//         // Foods
//         it_803F5DB0,
//         it_8028FBE4,
//         NULL,
//         it_8028FD7C,
//         it_8028FDE4,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_8028FE70,
//     },
//     {
//         // MSBomb
//         it_803F5E00,
//         it_8028FED4,
//         NULL,
//         it_802900CC,
//         it_802900F4,
//         it_80290114,
//         it_802906E4,
//         it_80290738,
//         it_80290794,
//         it_80290830,
//         it_802907F0,
//         NULL,
//         it_802908A4,
//         it_80290850,
//         it_80290918,
//     },
//     {
//         // Flipper
//         it_803F5EA8,
//         it_80290A20,
//         NULL,
//         it_80290F8C,
//         it_80290FC0,
//         it_80290FE0,
//         it_802915E8,
//         it_802919B8,
//         it_80291B58,
//         it_80291978,
//         it_802917C8,
//         NULL,
//         it_80291998,
//         it_802918A0,
//         it_80291BC0,
//     },
//     {
//         // S_Scope
//         it_803F5F40,
//         it_80291C98,
//         NULL,
//         it_8029215C,
//         it_80292190,
//         it_802921B8,
//         it_8029222C,
//         NULL,
//         it_802922D8,
//         it_80292298,
//         it_80292250,
//         NULL,
//         it_802922B8,
//         it_80292274,
//         it_80292340,
//     },
//     {
//         // StarRod
//         it_803F5F90,
//         it_80292360,
//         NULL,
//         it_80292514,
//         it_80292548,
//         it_802925B4,
//         it_8029266C,
//         NULL,
//         it_802926A8,
//         it_8029274C,
//         it_80292710,
//         NULL,
//         it_802927A8,
//         it_8029276C,
//         it_802927C8,
//     },
//     {
//         // LipStick
//         it_803F6310,
//         it_8029570C,
//         NULL,
//         it_802958C8,
//         it_80295908,
//         it_80295974,
//         it_80295ACC,
//         NULL,
//         it_80295B08,
//         it_80295BAC,
//         it_80295B70,
//         NULL,
//         it_80295C08,
//         it_80295BCC,
//         it_80295C28,
//     },
//     {
//         // Harisen
//         it_803F5FF0,
//         it_8029285C,
//         NULL,
//         it_80292A5C,
//         it_80292A90,
//         it_80292B2C,
//         it_80292BCC,
//         NULL,
//         it_80292C08,
//         it_80292CAC,
//         it_80292C70,
//         NULL,
//         it_80292D08,
//         it_80292CCC,
//         it_80292D28,
//     },
//     {
//         // F Flower
//         it_803F6090,
//         it_80292E04,
//         NULL,
//         it_80293284,
//         it_802933C4,
//         it_802933EC,
//         it_80293488,
//         NULL,
//         it_80293534,
//         it_802934F4,
//         it_802934AC,
//         NULL,
//         it_80293514,
//         it_802934D0,
//         it_80293640,
//     },
//     {
//         // Kinoko
//         it_803F6110,
//         it_8029367C,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_802939E0,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_802939E8,
//     },
//     {
//         // DKinoko
//         it_803F6130,
//         it_80293A08,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80293D6C,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80293D74,
//     },
//     {
//         // Hammer
//         it_803F6150,
//         it_80293F58,
//         NULL,
//         it_802940FC,
//         it_802941F8,
//         NULL,
//         NULL,
//         NULL,
//         it_802942B0,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80294344,
//     },
//     {
//         // WStar
//         it_803F61B0,
//         it_8029451C,
//         NULL,
//         it_80294728,
//         it_80294790,
//         NULL,
//         NULL,
//         NULL,
//         it_80294A28,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80294A90,
//     },
//     {
//         // ScBall
//         it_803F6220,
//         it_80294AB0,
//         NULL,
//         it_80294BE4,
//         it_80294C14,
//         it_80294C3C,
//         it_80294D4C,
//         NULL,
//         it_80294CE4,
//         it_80294D5C,
//         it_80294D54,
//         NULL,
//         it_80294DA0,
//         it_80294D7C,
//         it_80294A90,
//     },
//     {
//         // RabbitC
//         it_803F6270,
//         it_80295118,
//         NULL,
//         it_8029524C,
//         it_80295298,
//         NULL,
//         NULL,
//         NULL,
//         it_80295340,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_802953A8,
//     },
//     {
//         // MetalB
//         it_803F62C0,
//         it_802953C8,
//         NULL,
//         it_80295524,
//         it_80295554,
//         NULL,
//         NULL,
//         it_802955E0,
//         it_80295684,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_802956EC,
//     },
//     {
//         // Spycloak
//         it_803F6370,
//         it_80295C48,
//         NULL,
//         it_80295D90,
//         it_80295DC0,
//         NULL,
//         NULL,
//         NULL,
//         it_80295E4C,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80295EB4,
//     },
//     {
//         // M Ball
//         it_803F6488,
//         it_80297904,
//         it_802978DC,
//         it_80297ABC,
//         it_80297AF0,
//         it_80297B18,
//         it_80297BB8,
//         NULL,
//         it_80297BF8,
//         it_802980A0,
//         it_80298060,
//         NULL,
//         it_80298114,
//         it_802980D4,
//         it_80298148,
//     },
//     {
//         // L Gun Ray
//         it_803F64F8,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80298634,
//         NULL,
//         NULL,
//         it_80298654,
//         it_8029863C,
//         it_8029864C,
//         it_80298828,
//         it_80298644,
//         it_802988C4,
//     },
//     {
//         // Star Rod Star
//         it_803F6530,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80298BE4,
//         NULL,
//         NULL,
//         it_80298C04,
//         it_80298BEC,
//         it_80298BFC,
//         it_80298CE8,
//         it_80298BF4,
//         it_80298DCC,
//     },
//     {
//         // LipStick Spore
//         it_803F6680,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_8029A600,
//         NULL,
//         NULL,
//         it_8029A620,
//         it_8029A608,
//         it_8029A618,
//         it_8029A704,
//         it_8029A610,
//         it_8029A728,
//     },
//     {
//         // S Scope Beam
//         it_803F6568,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80299360,
//         NULL,
//         NULL,
//         it_802993A0,
//         it_80299368,
//         it_80299378,
//         it_80299380,
//         it_80299370,
//         it_802993C0,
//     },
//     {
//         // L Gun Beam
//         it_803F6630,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_80299B6C,
//         NULL,
//         NULL,
//         it_80299B74,
//         it_80299C08,
//         it_80299C10,
//         it_80299C18,
//         it_80299C20,
//         it_80299C28,
//     },
//     {
//         // Hammer Head
//         it_803F6640,
//         it_80299D4C,
//         NULL,
//         it_80299DD0,
//         it_80299E28,
//         it_80299E48,
//         it_8029A0B0,
//         it_8029A0EC,
//         NULL,
//         it_8029A0C8,
//         it_8029A0B8,
//         NULL,
//         NULL,
//         it_8029A0C0,
//         it_8029A0F4,
//     },
//     {
//         // F Flower Flame
//         it_803F66C8,
//         it_8029A9FC,
//         NULL,
//         it_8029AD1C,
//         it_8029AD94,
//         NULL,
//         NULL,
//         NULL,
//         it_8029AF34,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         it_8029B0A8,
//     },
//     {
//         // EvYoshiEgg
//         it_803F6728,
//         it_8029B1AC,
//         it_8029B188,
//         it_8029B2F4,
//         it_8029B328,
//         it_8029B348,
//         it_8029B46C,
//         it_8029B56C,
//         it_8029B670,
//         it_8029B52C,
//         it_8029B4AC,
//         NULL,
//         NULL,
//         it_8029B4EC,
//         it_8029B6D8,
//     },
// };
