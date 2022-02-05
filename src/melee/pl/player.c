#include "melee/pl/player.h"

#define NON_MATCHING 1

extern StaticPlayer player_slots[6];  // used to be [4] but I think should be 6?  ///lbl_80453080

struct Unk_Struct_w_Array {
    char some_str[8+4];  //"PdPm.dat"
    char another_str[16+4]; 
    S8Vec vec_arr[30];  ///lbl_803BCDE0
};

extern struct Unk_Struct {  //lbl_803BCDC0
    char some_str[8+4];  //"PdPm.dat"
    char another_str[16+4]; 
    //S8Vec vec_arr[30];  ///lbl_803BCDE0
} lbl_803BCDC0;

extern S8Vec lbl_803BCDE0[]; ///lbl_803BCDE0

extern char* lbl_803BCE44; //"cant get player struct! %d\n"  /// likely apart of lbl_803BCDC0 struct
extern char* lbl_803BCE60; //"player.c"

extern char* lbl_804D3940; //"0"


extern void ftData_SetScale();
extern void func_SetEntityFacingDirection();
extern void func_80087140();
extern void func_80086664();
extern void func_800D4F24();
extern void func_80390228();
extern s32 func_8008701C(HSD_GObj*);
extern s32 func_800873CC();
extern s32 func_8016C5C0(s32);
extern void func_802F6E1C(s32);
extern void func_800D4FF4(HSD_GObj*);
extern f32 func_800869F8(HSD_GObj*);
extern void func_80087BEC(HSD_GObj*, s8);
extern void func_80087BC0(HSD_GObj*, s8);


void inline Player_CheckSlot(s32 slot)
{
    if (slot < 0 || 6 <= slot) {
        OSReport("cant get player struct! %d\n", slot);
        __assert(__FILE__, 102, "0");
    }
}

// Matches when everything is moved over
#ifdef NON_MATCHING
StaticPlayer* Player_GetPtrForSlot(s32 slot)
{
    Player_CheckSlot(slot);
    return &player_slots[slot];
}
#else
asm StaticPlayer* Player_GetPtrForSlot(s32 slot)
{
    nofralloc
/* 80031724 0002E304  7C 08 02 A6 */	mflr r0
/* 80031728 0002E308  90 01 00 04 */	stw r0, 4(r1)
/* 8003172C 0002E30C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031730 0002E310  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031734 0002E314  7C 7F 1B 79 */	or. r31, r3, r3
/* 80031738 0002E318  41 80 00 0C */	blt lbl_80031744
/* 8003173C 0002E31C  2C 1F 00 06 */	cmpwi r31, 6
/* 80031740 0002E320  41 80 00 2C */	blt lbl_8003176C
lbl_80031744:
/* 80031744 0002E324  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 80031748 0002E328  4C C6 31 82 */	crclr 6
/* 8003174C 0002E32C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 80031750 0002E330  38 9F 00 00 */	addi r4, r31, 0
/* 80031754 0002E334  48 31 3F 55 */	bl OSReport
/* 80031758 0002E338  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 8003175C 0002E33C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031760 0002E340  38 80 00 66 */	li r4, 0x66
/* 80031764 0002E344  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031768 0002E348  48 35 6A B9 */	bl __assert
lbl_8003176C:
/* 8003176C 0002E34C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
/* 80031770 0002E350  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031774 0002E354  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031778 0002E358  38 03 30 80 */	addi r0, r3, player_slots@l
/* 8003177C 0002E35C  7C 60 22 14 */	add r3, r0, r4
/* 80031780 0002E360  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031784 0002E364  38 21 00 18 */	addi r1, r1, 0x18
/* 80031788 0002E368  7C 08 03 A6 */	mtlr r0
/* 8003178C 0002E36C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031790(s32 slot) {

    StaticPlayer* player;
    int i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        for (i = 0; i < 2; i++) {  
            /// transformed will either be [1,0] (normal) or [0,1] (transformed)
            /// checks to see if the player is in a transformed state, and calls
            /// the function only once depending on the state
            if ((player->player_entity[player->transformed[i]])) {
                func_800867E8(player->player_entity[player->transformed[i]]);
            }
        }
    }
}
#else
asm void Player_80031790(s32 slot)
{
    nofralloc
/* 80031790 0002E370  7C 08 02 A6 */	mflr r0
/* 80031794 0002E374  90 01 00 04 */	stw r0, 4(r1)
/* 80031798 0002E378  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8003179C 0002E37C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800317A0 0002E380  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800317A4 0002E384  7C 7E 1B 79 */	or. r30, r3, r3
/* 800317A8 0002E388  41 80 00 0C */	blt lbl_800317B4
/* 800317AC 0002E38C  2C 1E 00 06 */	cmpwi r30, 6
/* 800317B0 0002E390  41 80 00 2C */	blt lbl_800317DC
lbl_800317B4:
/* 800317B4 0002E394  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 800317B8 0002E398  4C C6 31 82 */	crclr 6
/* 800317BC 0002E39C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 800317C0 0002E3A0  38 9E 00 00 */	addi r4, r30, 0
/* 800317C4 0002E3A4  48 31 3E E5 */	bl OSReport
/* 800317C8 0002E3A8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 800317CC 0002E3AC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 800317D0 0002E3B0  38 80 00 66 */	li r4, 0x66
/* 800317D4 0002E3B4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 800317D8 0002E3B8  48 35 6A 49 */	bl __assert
lbl_800317DC:
/* 800317DC 0002E3BC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 800317E0 0002E3C0  3C 60 80 45 */	lis r3, player_slots@ha
/* 800317E4 0002E3C4  38 03 30 80 */	addi r0, r3, player_slots@l
/* 800317E8 0002E3C8  7F E0 22 14 */	add r31, r0, r4
/* 800317EC 0002E3CC  80 1F 00 08 */	lwz r0, 8(r31)
/* 800317F0 0002E3D0  2C 00 00 00 */	cmpwi r0, 0
/* 800317F4 0002E3D4  41 82 00 0C */	beq lbl_80031800
/* 800317F8 0002E3D8  2C 00 00 01 */	cmpwi r0, 1
/* 800317FC 0002E3DC  40 82 00 34 */	bne lbl_80031830
lbl_80031800:
/* 80031800 0002E3E0  3B C0 00 00 */	li r30, 0
lbl_80031804:
/* 80031804 0002E3E4  38 1E 00 0C */	addi r0, r30, 0xc
/* 80031808 0002E3E8  7C 1F 00 AE */	lbzx r0, r31, r0
/* 8003180C 0002E3EC  54 03 10 3A */	slwi r3, r0, 2
/* 80031810 0002E3F0  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031814 0002E3F4  7C 7F 00 2E */	lwzx r3, r31, r0
/* 80031818 0002E3F8  28 03 00 00 */	cmplwi r3, 0
/* 8003181C 0002E3FC  41 82 00 08 */	beq lbl_80031824
/* 80031820 0002E400  48 05 4F C9 */	bl func_800867E8
lbl_80031824:
/* 80031824 0002E404  3B DE 00 01 */	addi r30, r30, 1
/* 80031828 0002E408  2C 1E 00 02 */	cmpwi r30, 2
/* 8003182C 0002E40C  41 80 FF D8 */	blt lbl_80031804
lbl_80031830:
/* 80031830 0002E410  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031834 0002E414  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031838 0002E418  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8003183C 0002E41C  38 21 00 18 */	addi r1, r1, 0x18
/* 80031840 0002E420  7C 08 03 A6 */	mtlr r0
/* 80031844 0002E424  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031848(s32 slot) {
    StaticPlayer* player;
    int i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        for (i = 0; i < 2; i++) {  
            /// transformed will either be [1,0] (normal) or [0,1] (transformed)
            /// checks to see if the player is in a transformed state, and calls
            /// the function only once depending on the state
            if ((player->player_entity[player->transformed[i]])) {
                func_8008688C(player->player_entity[player->transformed[i]]);
            }
        }
    }
}
#else
asm void Player_80031848(s32 slot)
{
    nofralloc
/* 80031848 0002E428  7C 08 02 A6 */	mflr r0
/* 8003184C 0002E42C  90 01 00 04 */	stw r0, 4(r1)
/* 80031850 0002E430  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031854 0002E434  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031858 0002E438  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8003185C 0002E43C  7C 7E 1B 79 */	or. r30, r3, r3
/* 80031860 0002E440  41 80 00 0C */	blt lbl_8003186C
/* 80031864 0002E444  2C 1E 00 06 */	cmpwi r30, 6
/* 80031868 0002E448  41 80 00 2C */	blt lbl_80031894
lbl_8003186C:
/* 8003186C 0002E44C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 80031870 0002E450  4C C6 31 82 */	crclr 6
/* 80031874 0002E454  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 80031878 0002E458  38 9E 00 00 */	addi r4, r30, 0
/* 8003187C 0002E45C  48 31 3E 2D */	bl OSReport
/* 80031880 0002E460  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031884 0002E464  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031888 0002E468  38 80 00 66 */	li r4, 0x66
/* 8003188C 0002E46C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031890 0002E470  48 35 69 91 */	bl __assert
lbl_80031894:
/* 80031894 0002E474  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 80031898 0002E478  3C 60 80 45 */	lis r3, player_slots@ha
/* 8003189C 0002E47C  38 03 30 80 */	addi r0, r3, player_slots@l
/* 800318A0 0002E480  7F E0 22 14 */	add r31, r0, r4
/* 800318A4 0002E484  80 1F 00 08 */	lwz r0, 8(r31)
/* 800318A8 0002E488  2C 00 00 00 */	cmpwi r0, 0
/* 800318AC 0002E48C  41 82 00 0C */	beq lbl_800318B8
/* 800318B0 0002E490  2C 00 00 01 */	cmpwi r0, 1
/* 800318B4 0002E494  40 82 00 34 */	bne lbl_800318E8
lbl_800318B8:
/* 800318B8 0002E498  3B C0 00 00 */	li r30, 0
lbl_800318BC:
/* 800318BC 0002E49C  38 1E 00 0C */	addi r0, r30, 0xc
/* 800318C0 0002E4A0  7C 1F 00 AE */	lbzx r0, r31, r0
/* 800318C4 0002E4A4  54 03 10 3A */	slwi r3, r0, 2
/* 800318C8 0002E4A8  38 03 00 B0 */	addi r0, r3, 0xb0
/* 800318CC 0002E4AC  7C 7F 00 2E */	lwzx r3, r31, r0
/* 800318D0 0002E4B0  28 03 00 00 */	cmplwi r3, 0
/* 800318D4 0002E4B4  41 82 00 08 */	beq lbl_800318DC
/* 800318D8 0002E4B8  48 05 4F B5 */	bl func_8008688C
lbl_800318DC:
/* 800318DC 0002E4BC  3B DE 00 01 */	addi r30, r30, 1
/* 800318E0 0002E4C0  2C 1E 00 02 */	cmpwi r30, 2
/* 800318E4 0002E4C4  41 80 FF D8 */	blt lbl_800318BC
lbl_800318E8:
/* 800318E8 0002E4C8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800318EC 0002E4CC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800318F0 0002E4D0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800318F4 0002E4D4  38 21 00 18 */	addi r1, r1, 0x18
/* 800318F8 0002E4D8  7C 08 03 A6 */	mtlr r0
/* 800318FC 0002E4DC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void inline func_8008688C_wrapper(StaticPlayer* player)
{
    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        s32 i;
        for (i = 0; i < 2; i++) {  
            if ((player->player_entity[player->transformed[i]])) {
                func_8008688C(player->player_entity[player->transformed[i]]);
            }
        }
    }
}

void Player_80031900() {
    s32 slot;
    for (slot = 0; slot < 6; slot++) {
        StaticPlayer* player = &player_slots[slot];
        Player_CheckSlot(slot);
        func_8008688C_wrapper(player);
    }
}
#else
asm void Player_80031900(s32 slot) 
{
    nofralloc
/* 80031900 0002E4E0  7C 08 02 A6 */	mflr r0
/* 80031904 0002E4E4  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031908 0002E4E8  90 01 00 04 */	stw r0, 4(r1)
/* 8003190C 0002E4EC  3C 80 80 3C */	lis r4, lbl_803BCE44@ha
/* 80031910 0002E4F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80031914 0002E4F4  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 80031918 0002E4F8  3B 83 30 80 */	addi r28, r3, player_slots@l
/* 8003191C 0002E4FC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031920 0002E500  3B C4 CE 44 */	addi r30, r4, lbl_803BCE44@l
/* 80031924 0002E504  3B E3 CE 60 */	addi r31, r3, lbl_803BCE60@l
/* 80031928 0002E508  3B 60 00 00 */	li r27, 0
lbl_8003192C:
/* 8003192C 0002E50C  2C 1B 00 00 */	cmpwi r27, 0
/* 80031930 0002E510  41 80 00 0C */	blt lbl_8003193C
/* 80031934 0002E514  2C 1B 00 06 */	cmpwi r27, 6
/* 80031938 0002E518  41 80 00 24 */	blt lbl_8003195C
lbl_8003193C:
/* 8003193C 0002E51C  38 7E 00 00 */	addi r3, r30, 0
/* 80031940 0002E520  4C C6 31 82 */	crclr 6
/* 80031944 0002E524  38 9B 00 00 */	addi r4, r27, 0
/* 80031948 0002E528  48 31 3D 61 */	bl OSReport
/* 8003194C 0002E52C  38 7F 00 00 */	addi r3, r31, 0
/* 80031950 0002E530  38 80 00 66 */	li r4, 0x66
/* 80031954 0002E534  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031958 0002E538  48 35 68 C9 */	bl __assert
lbl_8003195C:
/* 8003195C 0002E53C  80 1C 00 08 */	lwz r0, 8(r28)
/* 80031960 0002E540  2C 00 00 00 */	cmpwi r0, 0
/* 80031964 0002E544  41 82 00 0C */	beq lbl_80031970
/* 80031968 0002E548  2C 00 00 01 */	cmpwi r0, 1
/* 8003196C 0002E54C  40 82 00 34 */	bne lbl_800319A0
lbl_80031970:
/* 80031970 0002E550  3B A0 00 00 */	li r29, 0
lbl_80031974:
/* 80031974 0002E554  38 1D 00 0C */	addi r0, r29, 0xc
/* 80031978 0002E558  7C 1C 00 AE */	lbzx r0, r28, r0
/* 8003197C 0002E55C  54 03 10 3A */	slwi r3, r0, 2
/* 80031980 0002E560  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031984 0002E564  7C 7C 00 2E */	lwzx r3, r28, r0
/* 80031988 0002E568  28 03 00 00 */	cmplwi r3, 0
/* 8003198C 0002E56C  41 82 00 08 */	beq lbl_80031994
/* 80031990 0002E570  48 05 4E FD */	bl func_8008688C
lbl_80031994:
/* 80031994 0002E574  3B BD 00 01 */	addi r29, r29, 1
/* 80031998 0002E578  2C 1D 00 02 */	cmpwi r29, 2
/* 8003199C 0002E57C  41 80 FF D8 */	blt lbl_80031974
lbl_800319A0:
/* 800319A0 0002E580  3B 7B 00 01 */	addi r27, r27, 1
/* 800319A4 0002E584  2C 1B 00 06 */	cmpwi r27, 6
/* 800319A8 0002E588  3B 9C 0E 90 */	addi r28, r28, 0xe90
/* 800319AC 0002E58C  41 80 FF 80 */	blt lbl_8003192C
/* 800319B0 0002E590  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 800319B4 0002E594  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800319B8 0002E598  38 21 00 20 */	addi r1, r1, 0x20
/* 800319BC 0002E59C  7C 08 03 A6 */	mtlr r0
/* 800319C0 0002E5A0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
BOOL Player_800319C4(s32 slot, BOOL arg1) {

    s32 unused;

    s32 i;
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = (&player_slots[slot]);


    if (arg1) {
        for (i = 0; i < 2; i++) {
            if (!player->player_entity[player->transformed[i]]) {
                return FALSE;
            }
        }
        return TRUE;
    }

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            return FALSE;
        } 
    }
    
    return TRUE;

}
#else
asm BOOL Player_800319C4(s32 slot, BOOL arg1)
{
    nofralloc
/* 800319C4 0002E5A4  7C 08 02 A6 */	mflr r0
/* 800319C8 0002E5A8  90 01 00 04 */	stw r0, 4(r1)
/* 800319CC 0002E5AC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800319D0 0002E5B0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800319D4 0002E5B4  3B E4 00 00 */	addi r31, r4, 0
/* 800319D8 0002E5B8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800319DC 0002E5BC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800319E0 0002E5C0  41 80 00 0C */	blt lbl_800319EC
/* 800319E4 0002E5C4  2C 1E 00 06 */	cmpwi r30, 6
/* 800319E8 0002E5C8  41 80 00 2C */	blt lbl_80031A14
lbl_800319EC:
/* 800319EC 0002E5CC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 800319F0 0002E5D0  4C C6 31 82 */	crclr 6
/* 800319F4 0002E5D4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 800319F8 0002E5D8  38 9E 00 00 */	addi r4, r30, 0
/* 800319FC 0002E5DC  48 31 3C AD */	bl OSReport
/* 80031A00 0002E5E0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031A04 0002E5E4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031A08 0002E5E8  38 80 00 66 */	li r4, 0x66
/* 80031A0C 0002E5EC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031A10 0002E5F0  48 35 68 11 */	bl __assert
lbl_80031A14:
/* 80031A14 0002E5F4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 80031A18 0002E5F8  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031A1C 0002E5FC  38 03 30 80 */	addi r0, r3, player_slots@l
/* 80031A20 0002E600  2C 1F 00 00 */	cmpwi r31, 0
/* 80031A24 0002E604  7C 80 22 14 */	add r4, r0, r4
/* 80031A28 0002E608  41 82 00 4C */	beq lbl_80031A74
/* 80031A2C 0002E60C  88 04 00 0C */	lbz r0, 0xc(r4)
/* 80031A30 0002E610  54 03 10 3A */	slwi r3, r0, 2
/* 80031A34 0002E614  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A38 0002E618  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A3C 0002E61C  28 00 00 00 */	cmplwi r0, 0
/* 80031A40 0002E620  40 82 00 0C */	bne lbl_80031A4C
/* 80031A44 0002E624  38 60 00 00 */	li r3, 0
/* 80031A48 0002E628  48 00 00 70 */	b lbl_80031AB8
lbl_80031A4C:
/* 80031A4C 0002E62C  88 04 00 0D */	lbz r0, 0xd(r4)
/* 80031A50 0002E630  54 03 10 3A */	slwi r3, r0, 2
/* 80031A54 0002E634  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A58 0002E638  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A5C 0002E63C  28 00 00 00 */	cmplwi r0, 0
/* 80031A60 0002E640  40 82 00 0C */	bne lbl_80031A6C
/* 80031A64 0002E644  38 60 00 00 */	li r3, 0
/* 80031A68 0002E648  48 00 00 50 */	b lbl_80031AB8
lbl_80031A6C:
/* 80031A6C 0002E64C  38 60 00 01 */	li r3, 1
/* 80031A70 0002E650  48 00 00 48 */	b lbl_80031AB8
lbl_80031A74:
/* 80031A74 0002E654  88 04 00 0C */	lbz r0, 0xc(r4)
/* 80031A78 0002E658  54 03 10 3A */	slwi r3, r0, 2
/* 80031A7C 0002E65C  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A80 0002E660  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A84 0002E664  28 00 00 00 */	cmplwi r0, 0
/* 80031A88 0002E668  41 82 00 0C */	beq lbl_80031A94
/* 80031A8C 0002E66C  38 60 00 00 */	li r3, 0
/* 80031A90 0002E670  48 00 00 28 */	b lbl_80031AB8
lbl_80031A94:
/* 80031A94 0002E674  88 04 00 0D */	lbz r0, 0xd(r4)
/* 80031A98 0002E678  54 03 10 3A */	slwi r3, r0, 2
/* 80031A9C 0002E67C  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031AA0 0002E680  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031AA4 0002E684  28 00 00 00 */	cmplwi r0, 0
/* 80031AA8 0002E688  41 82 00 0C */	beq lbl_80031AB4
/* 80031AAC 0002E68C  38 60 00 00 */	li r3, 0
/* 80031AB0 0002E690  48 00 00 08 */	b lbl_80031AB8
lbl_80031AB4:
/* 80031AB4 0002E694  38 60 00 01 */	li r3, 1
lbl_80031AB8:
/* 80031AB8 0002E698  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80031ABC 0002E69C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80031AC0 0002E6A0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80031AC4 0002E6A4  38 21 00 20 */	addi r1, r1, 0x20
/* 80031AC8 0002E6A8  7C 08 03 A6 */	mtlr r0
/* 80031ACC 0002E6AC  4E 80 00 20 */	blr 
}
#endif

asm void Player_80031AD0(s32 slot) /// https://decomp.me/scratch/tfUzD
{
    nofralloc
/* 80031AD0 0002E6B0  7C 08 02 A6 */	mflr r0
/* 80031AD4 0002E6B4  90 01 00 04 */	stw r0, 4(r1)
/* 80031AD8 0002E6B8  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 80031ADC 0002E6BC  BF 61 00 34 */	stmw r27, 0x34(r1)
/* 80031AE0 0002E6C0  7C 7C 1B 79 */	or. r28, r3, r3
/* 80031AE4 0002E6C4  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
/* 80031AE8 0002E6C8  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
/* 80031AEC 0002E6CC  41 80 00 0C */	blt lbl_80031AF8
/* 80031AF0 0002E6D0  2C 1C 00 06 */	cmpwi r28, 6
/* 80031AF4 0002E6D4  41 80 00 24 */	blt lbl_80031B18
lbl_80031AF8:
/* 80031AF8 0002E6D8  38 9C 00 00 */	addi r4, r28, 0
/* 80031AFC 0002E6DC  4C C6 31 82 */	crclr 6
/* 80031B00 0002E6E0  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031B04 0002E6E4  48 31 3B A5 */	bl OSReport
/* 80031B08 0002E6E8  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031B0C 0002E6EC  38 80 00 66 */	li r4, 0x66
/* 80031B10 0002E6F0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031B14 0002E6F4  48 35 67 0D */	bl __assert
lbl_80031B18:
/* 80031B18 0002E6F8  1C 9C 0E 90 */	mulli r4, r28, 0xe90
/* 80031B1C 0002E6FC  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031B20 0002E700  38 03 30 80 */	addi r0, r3, player_slots@l
/* 80031B24 0002E704  7F C0 22 14 */	add r30, r0, r4
/* 80031B28 0002E708  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031B2C 0002E70C  3B BF 00 21 */	addi r29, r31, 0x21
/* 80031B30 0002E710  1C 00 00 03 */	mulli r0, r0, 3
/* 80031B34 0002E714  7C 1D 00 AE */	lbzx r0, r29, r0
/* 80031B38 0002E718  7C 00 07 74 */	extsb r0, r0
/* 80031B3C 0002E71C  2C 00 FF FF */	cmpwi r0, -1
/* 80031B40 0002E720  41 82 00 14 */	beq lbl_80031B54
/* 80031B44 0002E724  88 1E 00 AC */	lbz r0, 0xac(r30)
/* 80031B48 0002E728  38 60 00 01 */	li r3, 1
/* 80031B4C 0002E72C  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 80031B50 0002E730  98 1E 00 AC */	stb r0, 0xac(r30)
lbl_80031B54:
/* 80031B54 0002E734  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031B58 0002E738  2C 1C 00 00 */	cmpwi r28, 0
/* 80031B5C 0002E73C  1C 00 00 03 */	mulli r0, r0, 3
/* 80031B60 0002E740  7C 7F 02 14 */	add r3, r31, r0
/* 80031B64 0002E744  8B 63 00 20 */	lbz r27, 0x20(r3)
/* 80031B68 0002E748  7F 7B 07 74 */	extsb r27, r27
/* 80031B6C 0002E74C  41 80 00 0C */	blt lbl_80031B78
/* 80031B70 0002E750  2C 1C 00 06 */	cmpwi r28, 6
/* 80031B74 0002E754  41 80 00 24 */	blt lbl_80031B98
lbl_80031B78:
/* 80031B78 0002E758  38 9C 00 00 */	addi r4, r28, 0
/* 80031B7C 0002E75C  4C C6 31 82 */	crclr 6
/* 80031B80 0002E760  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031B84 0002E764  48 31 3B 25 */	bl OSReport
/* 80031B88 0002E768  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031B8C 0002E76C  38 80 00 66 */	li r4, 0x66
/* 80031B90 0002E770  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031B94 0002E774  48 35 66 8D */	bl __assert
lbl_80031B98:
/* 80031B98 0002E778  93 61 00 24 */	stw r27, 0x24(r1)
/* 80031B9C 0002E77C  38 A0 00 00 */	li r5, 0
/* 80031BA0 0002E780  38 00 FF FF */	li r0, -1
/* 80031BA4 0002E784  9B 81 00 28 */	stb r28, 0x28(r1)
/* 80031BA8 0002E788  38 61 00 24 */	addi r3, r1, 0x24
/* 80031BAC 0002E78C  88 81 00 2A */	lbz r4, 0x2a(r1)
/* 80031BB0 0002E790  50 A4 3E 30 */	rlwimi r4, r5, 7, 0x18, 0x18
/* 80031BB4 0002E794  98 81 00 2A */	stb r4, 0x2a(r1)
/* 80031BB8 0002E798  88 81 00 2A */	lbz r4, 0x2a(r1)
/* 80031BBC 0002E79C  50 A4 36 72 */	rlwimi r4, r5, 6, 0x19, 0x19
/* 80031BC0 0002E7A0  98 81 00 2A */	stb r4, 0x2a(r1)
/* 80031BC4 0002E7A4  98 01 00 29 */	stb r0, 0x29(r1)
/* 80031BC8 0002E7A8  48 03 72 D1 */	bl func_80068E98
/* 80031BCC 0002E7AC  90 7E 00 B0 */	stw r3, 0xb0(r30)
/* 80031BD0 0002E7B0  38 00 00 02 */	li r0, 2
/* 80031BD4 0002E7B4  90 1E 00 00 */	stw r0, 0(r30)
/* 80031BD8 0002E7B8  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031BDC 0002E7BC  1C 00 00 03 */	mulli r0, r0, 3
/* 80031BE0 0002E7C0  7C 7D 00 AE */	lbzx r3, r29, r0
/* 80031BE4 0002E7C4  7C 7D 07 74 */	extsb r29, r3
/* 80031BE8 0002E7C8  2C 1D FF FF */	cmpwi r29, -1
/* 80031BEC 0002E7CC  41 82 00 8C */	beq lbl_80031C78
/* 80031BF0 0002E7D0  7C 7F 02 14 */	add r3, r31, r0
/* 80031BF4 0002E7D4  8B 63 00 22 */	lbz r27, 0x22(r3)
/* 80031BF8 0002E7D8  2C 1C 00 00 */	cmpwi r28, 0
/* 80031BFC 0002E7DC  7F 7B 07 74 */	extsb r27, r27
/* 80031C00 0002E7E0  41 80 00 0C */	blt lbl_80031C0C
/* 80031C04 0002E7E4  2C 1C 00 06 */	cmpwi r28, 6
/* 80031C08 0002E7E8  41 80 00 24 */	blt lbl_80031C2C
lbl_80031C0C:
/* 80031C0C 0002E7EC  38 9C 00 00 */	addi r4, r28, 0
/* 80031C10 0002E7F0  4C C6 31 82 */	crclr 6
/* 80031C14 0002E7F4  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031C18 0002E7F8  48 31 3A 91 */	bl OSReport
/* 80031C1C 0002E7FC  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031C20 0002E800  38 80 00 66 */	li r4, 0x66
/* 80031C24 0002E804  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031C28 0002E808  48 35 65 F9 */	bl __assert
lbl_80031C2C:
/* 80031C2C 0002E80C  93 A1 00 18 */	stw r29, 0x18(r1)
/* 80031C30 0002E810  38 80 00 01 */	li r4, 1
/* 80031C34 0002E814  38 00 FF FF */	li r0, -1
/* 80031C38 0002E818  9B 81 00 1C */	stb r28, 0x1c(r1)
/* 80031C3C 0002E81C  88 61 00 1E */	lbz r3, 0x1e(r1)
/* 80031C40 0002E820  50 83 3E 30 */	rlwimi r3, r4, 7, 0x18, 0x18
/* 80031C44 0002E824  98 61 00 1E */	stb r3, 0x1e(r1)
/* 80031C48 0002E828  38 61 00 18 */	addi r3, r1, 0x18
/* 80031C4C 0002E82C  88 81 00 1E */	lbz r4, 0x1e(r1)
/* 80031C50 0002E830  53 64 36 72 */	rlwimi r4, r27, 6, 0x19, 0x19
/* 80031C54 0002E834  98 81 00 1E */	stb r4, 0x1e(r1)
/* 80031C58 0002E838  98 01 00 1D */	stb r0, 0x1d(r1)
/* 80031C5C 0002E83C  48 03 72 3D */	bl func_80068E98
/* 80031C60 0002E840  90 7E 00 B4 */	stw r3, 0xb4(r30)
/* 80031C64 0002E844  80 1E 00 00 */	lwz r0, 0(r30)
/* 80031C68 0002E848  2C 00 00 01 */	cmpwi r0, 1
/* 80031C6C 0002E84C  41 82 00 0C */	beq lbl_80031C78
/* 80031C70 0002E850  38 00 00 02 */	li r0, 2
/* 80031C74 0002E854  90 1E 00 00 */	stw r0, 0(r30)
lbl_80031C78:
/* 80031C78 0002E858  80 1E 00 00 */	lwz r0, 0(r30)
/* 80031C7C 0002E85C  2C 00 00 02 */	cmpwi r0, 2
/* 80031C80 0002E860  40 82 00 1C */	bne lbl_80031C9C
/* 80031C84 0002E864  81 9E 00 B8 */	lwz r12, 0xb8(r30)
/* 80031C88 0002E868  28 0C 00 00 */	cmplwi r12, 0
/* 80031C8C 0002E86C  41 82 00 10 */	beq lbl_80031C9C
/* 80031C90 0002E870  7D 88 03 A6 */	mtlr r12
/* 80031C94 0002E874  38 7C 00 00 */	addi r3, r28, 0
/* 80031C98 0002E878  4E 80 00 21 */	blrl 
lbl_80031C9C:
/* 80031C9C 0002E87C  BB 61 00 34 */	lmw r27, 0x34(r1)
/* 80031CA0 0002E880  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80031CA4 0002E884  38 21 00 48 */	addi r1, r1, 0x48
/* 80031CA8 0002E888  7C 08 03 A6 */	mtlr r0
/* 80031CAC 0002E88C  4E 80 00 20 */	blr 
}

#ifdef NON_MATCHING
void Player_80031CB0(s32 id, s32 slot) {
    if (lbl_803BCDE0[id].x != -1) {
        func_800855C8(lbl_803BCDE0[id].x, slot);
    }
    if (lbl_803BCDE0[id].y != -1) {
        func_800855C8(lbl_803BCDE0[id].y, slot);
    }
}
#else
asm void Player_80031CB0(s32 id, s32 slot)
{
    nofralloc
/* 80031CB0 0002E890  7C 08 02 A6 */	mflr r0
/* 80031CB4 0002E894  90 01 00 04 */	stw r0, 4(r1)
/* 80031CB8 0002E898  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031CBC 0002E89C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031CC0 0002E8A0  1F E3 00 03 */	mulli r31, r3, 3
/* 80031CC4 0002E8A4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80031CC8 0002E8A8  3C 60 80 3C */	lis r3, lbl_803BCDE0
/* 80031CCC 0002E8AC  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0
/* 80031CD0 0002E8B0  7C 60 FA 14 */	add r3, r0, r31
/* 80031CD4 0002E8B4  88 03 00 00 */	lbz r0, 0(r3)
/* 80031CD8 0002E8B8  3B C4 00 00 */	addi r30, r4, 0
/* 80031CDC 0002E8BC  7C 03 07 74 */	extsb r3, r0
/* 80031CE0 0002E8C0  2C 03 FF FF */	cmpwi r3, -1
/* 80031CE4 0002E8C4  41 82 00 0C */	beq lbl_80031CF0
/* 80031CE8 0002E8C8  7F C4 F3 78 */	mr r4, r30
/* 80031CEC 0002E8CC  48 05 38 DD */	bl func_800855C8
lbl_80031CF0:
/* 80031CF0 0002E8D0  3C 60 80 3C */	lis r3, lbl_803BCDE0
/* 80031CF4 0002E8D4  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0
/* 80031CF8 0002E8D8  7C 60 FA 14 */	add r3, r0, r31
/* 80031CFC 0002E8DC  88 03 00 01 */	lbz r0, 1(r3)
/* 80031D00 0002E8E0  7C 03 07 74 */	extsb r3, r0
/* 80031D04 0002E8E4  2C 03 FF FF */	cmpwi r3, -1
/* 80031D08 0002E8E8  41 82 00 0C */	beq lbl_80031D14
/* 80031D0C 0002E8EC  7F C4 F3 78 */	mr r4, r30
/* 80031D10 0002E8F0  48 05 38 B9 */	bl func_800855C8
lbl_80031D14:
/* 80031D14 0002E8F4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031D18 0002E8F8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031D1C 0002E8FC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80031D20 0002E900  38 21 00 18 */	addi r1, r1, 0x18
/* 80031D24 0002E904  7C 08 03 A6 */	mtlr r0
/* 80031D28 0002E908  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_80031D2C(s32 id, s32 slot) {   ///https://decomp.me/scratch/50Zi6
    if (lbl_803BCDE0[id].x != -1) {
        func_8008578C(lbl_803BCDE0[id].x, slot);
    }
    if (lbl_803BCDE0[id].y != -1) {
        func_8008578C(lbl_803BCDE0[id].y, slot);
    }
}
#else
asm void Player_80031D2C(s32 id, s32 slot)
{
    nofralloc
/* 80031D2C 0002E90C  7C 08 02 A6 */	mflr r0
/* 80031D30 0002E910  90 01 00 04 */	stw r0, 4(r1)
/* 80031D34 0002E914  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031D38 0002E918  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031D3C 0002E91C  1F E3 00 03 */	mulli r31, r3, 3
/* 80031D40 0002E920  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80031D44 0002E924  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
/* 80031D48 0002E928  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
/* 80031D4C 0002E92C  7C 60 FA 14 */	add r3, r0, r31
/* 80031D50 0002E930  88 03 00 00 */	lbz r0, 0(r3)
/* 80031D54 0002E934  3B C4 00 00 */	addi r30, r4, 0
/* 80031D58 0002E938  7C 03 07 74 */	extsb r3, r0
/* 80031D5C 0002E93C  2C 03 FF FF */	cmpwi r3, -1
/* 80031D60 0002E940  41 82 00 0C */	beq lbl_80031D6C
/* 80031D64 0002E944  7F C4 F3 78 */	mr r4, r30
/* 80031D68 0002E948  48 05 3A 25 */	bl func_8008578C
lbl_80031D6C:
/* 80031D6C 0002E94C  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
/* 80031D70 0002E950  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
/* 80031D74 0002E954  7C 60 FA 14 */	add r3, r0, r31
/* 80031D78 0002E958  88 03 00 01 */	lbz r0, 1(r3)
/* 80031D7C 0002E95C  7C 03 07 74 */	extsb r3, r0
/* 80031D80 0002E960  2C 03 FF FF */	cmpwi r3, -1
/* 80031D84 0002E964  41 82 00 0C */	beq lbl_80031D90
/* 80031D88 0002E968  7F C4 F3 78 */	mr r4, r30
/* 80031D8C 0002E96C  48 05 3A 01 */	bl func_8008578C
lbl_80031D90:
/* 80031D90 0002E970  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031D94 0002E974  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031D98 0002E978  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80031D9C 0002E97C  38 21 00 18 */	addi r1, r1, 0x18
/* 80031DA0 0002E980  7C 08 03 A6 */	mtlr r0
/* 80031DA4 0002E984  4E 80 00 20 */	blr 
}
#endif

void Player_80031DA8(s32 param_1, s32 param_2)
{
    func_800EED50(param_1, param_2);
}

#ifdef NON_MATCHING
inline checkNegOne(s8* num) { return *num != -1; }

void Player_80031DC8(void func_arg(s32, s32)) {   ////https://decomp.me/scratch/Iq3tA
    s32 slot;
    for (slot = 0; slot < 6; slot++) {
        Player_CheckSlot(slot);

        if (player_slots[slot].player_state) {
            func_arg(((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].x, 0);
            if (checkNegOne(&((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].y)) {
                func_arg(((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].y, 0);
            }
        }
    }
}
#else
asm void Player_80031DC8()
{
    nofralloc
    /* 80031DC8 0002E9A8  7C 08 02 A6 */	mflr r0
    /* 80031DCC 0002E9AC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80031DD0 0002E9B0  90 01 00 04 */	stw r0, 4(r1)
    /* 80031DD4 0002E9B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80031DD8 0002E9B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80031DDC 0002E9BC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80031DE0 0002E9C0  3B C4 30 80 */	addi r30, r4, player_slots@l
    /* 80031DE4 0002E9C4  3C 80 80 3C */	lis r4, lbl_803BCDC0@ha
    /* 80031DE8 0002E9C8  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80031DEC 0002E9CC  3B E4 CD C0 */	addi r31, r4, lbl_803BCDC0@l
    /* 80031DF0 0002E9D0  3B A0 00 00 */	li r29, 0
    /* 80031DF4 0002E9D4  93 81 00 10 */	stw r28, 0x10(r1)
    /* 80031DF8 0002E9D8  3B 83 00 00 */	addi r28, r3, 0
    lbl_80031DFC:
    /* 80031DFC 0002E9DC  2C 1D 00 00 */	cmpwi r29, 0
    /* 80031E00 0002E9E0  41 80 00 0C */	blt lbl_80031E0C
    /* 80031E04 0002E9E4  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031E08 0002E9E8  41 80 00 24 */	blt lbl_80031E2C
    lbl_80031E0C:
    /* 80031E0C 0002E9EC  38 9D 00 00 */	addi r4, r29, 0
    /* 80031E10 0002E9F0  4C C6 31 82 */	crclr 6
    /* 80031E14 0002E9F4  38 7F 00 84 */	addi r3, r31, 0x84
    /* 80031E18 0002E9F8  48 31 38 91 */	bl OSReport
    /* 80031E1C 0002E9FC  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 80031E20 0002EA00  38 80 00 66 */	li r4, 0x66
    /* 80031E24 0002EA04  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80031E28 0002EA08  48 35 63 F9 */	bl __assert
    lbl_80031E2C:
    /* 80031E2C 0002EA0C  80 1E 00 00 */	lwz r0, 0(r30)
    /* 80031E30 0002EA10  2C 00 00 00 */	cmpwi r0, 0
    /* 80031E34 0002EA14  41 82 00 58 */	beq lbl_80031E8C
    /* 80031E38 0002EA18  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80031E3C 0002EA1C  39 9C 00 00 */	addi r12, r28, 0
    /* 80031E40 0002EA20  7D 88 03 A6 */	mtlr r12
    /* 80031E44 0002EA24  38 80 00 00 */	li r4, 0
    /* 80031E48 0002EA28  1C 00 00 03 */	mulli r0, r0, 3
    /* 80031E4C 0002EA2C  7C 7F 02 14 */	add r3, r31, r0
    /* 80031E50 0002EA30  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 80031E54 0002EA34  7C 63 07 74 */	extsb r3, r3
    /* 80031E58 0002EA38  4E 80 00 21 */	blrl 
    /* 80031E5C 0002EA3C  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80031E60 0002EA40  1C 00 00 03 */	mulli r0, r0, 3
    /* 80031E64 0002EA44  7C 7F 02 14 */	add r3, r31, r0
    /* 80031E68 0002EA48  88 63 00 21 */	lbz r3, 0x21(r3)
    /* 80031E6C 0002EA4C  7C 60 07 74 */	extsb r0, r3
    /* 80031E70 0002EA50  2C 00 FF FF */	cmpwi r0, -1
    /* 80031E74 0002EA54  41 82 00 18 */	beq lbl_80031E8C
    /* 80031E78 0002EA58  39 9C 00 00 */	addi r12, r28, 0
    /* 80031E7C 0002EA5C  7D 88 03 A6 */	mtlr r12
    /* 80031E80 0002EA60  7C 63 07 74 */	extsb r3, r3
    /* 80031E84 0002EA64  38 80 00 00 */	li r4, 0
    /* 80031E88 0002EA68  4E 80 00 21 */	blrl 
    lbl_80031E8C:
    /* 80031E8C 0002EA6C  3B BD 00 01 */	addi r29, r29, 1
    /* 80031E90 0002EA70  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031E94 0002EA74  3B DE 0E 90 */	addi r30, r30, 0xe90
    /* 80031E98 0002EA78  41 80 FF 64 */	blt lbl_80031DFC
    /* 80031E9C 0002EA7C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80031EA0 0002EA80  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80031EA4 0002EA84  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80031EA8 0002EA88  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80031EAC 0002EA8C  83 81 00 10 */	lwz r28, 0x10(r1)
    /* 80031EB0 0002EA90  38 21 00 20 */	addi r1, r1, 0x20
    /* 80031EB4 0002EA94  7C 08 03 A6 */	mtlr r0
    /* 80031EB8 0002EA98  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031EBC(s32 slot) { ///https://decomp.me/scratch/XYDYq

    s32 i;
    Player_CheckSlot(slot);

    for (i = 0; i < 2; i++) {
        StaticPlayer*player = &player_slots[slot];
        if ((player->player_entity[player->transformed[i]])) {
            if (!func_8008701C(player->player_entity[player->transformed[i]])) {
                func_800D4F24(player->player_entity[player->transformed[i]], 1);
            }
            func_80390228(player->player_entity[player->transformed[i]]);
        }
    }

}
#else
asm void Player_80031EBC()
{
    nofralloc
    /* 80031EBC 0002EA9C  7C 08 02 A6 */	mflr r0
    /* 80031EC0 0002EAA0  90 01 00 04 */	stw r0, 4(r1)
    /* 80031EC4 0002EAA4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80031EC8 0002EAA8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80031ECC 0002EAAC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80031ED0 0002EAB0  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80031ED4 0002EAB4  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80031ED8 0002EAB8  41 80 00 0C */	blt lbl_80031EE4
    /* 80031EDC 0002EABC  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031EE0 0002EAC0  41 80 00 2C */	blt lbl_80031F0C
    lbl_80031EE4:
    /* 80031EE4 0002EAC4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80031EE8 0002EAC8  4C C6 31 82 */	crclr 6
    /* 80031EEC 0002EACC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80031EF0 0002EAD0  38 9D 00 00 */	addi r4, r29, 0
    /* 80031EF4 0002EAD4  48 31 37 B5 */	bl OSReport
    /* 80031EF8 0002EAD8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80031EFC 0002EADC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80031F00 0002EAE0  38 80 00 66 */	li r4, 0x66
    /* 80031F04 0002EAE4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80031F08 0002EAE8  48 35 63 19 */	bl __assert
    lbl_80031F0C:
    /* 80031F0C 0002EAEC  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80031F10 0002EAF0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80031F14 0002EAF4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80031F18 0002EAF8  7F E0 22 14 */	add r31, r0, r4
    /* 80031F1C 0002EAFC  3B A0 00 00 */	li r29, 0
    lbl_80031F20:
    /* 80031F20 0002EB00  38 9D 00 0C */	addi r4, r29, 0xc
    /* 80031F24 0002EB04  7C 1F 20 AE */	lbzx r0, r31, r4
    /* 80031F28 0002EB08  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F2C 0002EB0C  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F30 0002EB10  7C 1F 00 2E */	lwzx r0, r31, r0
    /* 80031F34 0002EB14  28 00 00 00 */	cmplwi r0, 0
    /* 80031F38 0002EB18  41 82 00 50 */	beq lbl_80031F88
    /* 80031F3C 0002EB1C  7F DF 22 14 */	add r30, r31, r4
    /* 80031F40 0002EB20  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F44 0002EB24  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F48 0002EB28  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F4C 0002EB2C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F50 0002EB30  48 05 50 CD */	bl func_8008701C
    /* 80031F54 0002EB34  2C 03 00 00 */	cmpwi r3, 0
    /* 80031F58 0002EB38  40 82 00 1C */	bne lbl_80031F74
    /* 80031F5C 0002EB3C  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F60 0002EB40  38 80 00 01 */	li r4, 1
    /* 80031F64 0002EB44  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F68 0002EB48  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F6C 0002EB4C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F70 0002EB50  48 0A 2F B5 */	bl func_800D4F24
    lbl_80031F74:
    /* 80031F74 0002EB54  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F78 0002EB58  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F7C 0002EB5C  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F80 0002EB60  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F84 0002EB64  48 35 E2 A5 */	bl func_80390228
    lbl_80031F88:
    /* 80031F88 0002EB68  3B BD 00 01 */	addi r29, r29, 1
    /* 80031F8C 0002EB6C  2C 1D 00 02 */	cmpwi r29, 2
    /* 80031F90 0002EB70  41 80 FF 90 */	blt lbl_80031F20
    /* 80031F94 0002EB74  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80031F98 0002EB78  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80031F9C 0002EB7C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80031FA0 0002EB80  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80031FA4 0002EB84  38 21 00 20 */	addi r1, r1, 0x20
    /* 80031FA8 0002EB88  7C 08 03 A6 */	mtlr r0
    /* 80031FAC 0002EB8C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031FB0(s32 slot, s32 entity_index) { //https://decomp.me/scratch/5EHKN

    s32 unused;
    StaticPlayer* player;
    Player_CheckSlot(slot);

    player = &player_slots[slot];
    player->player_entity[player->transformed[entity_index]] = 0;
    if (((player->flags >> 5) & 0x1) == 0 || (Player_800319C4(slot, 0) != 0)) {
        player->player_state = 0;
    }
}
#else
asm void Player_80031FB0()
{
    nofralloc
    /* 80031FB0 0002EB90  7C 08 02 A6 */	mflr r0
    /* 80031FB4 0002EB94  90 01 00 04 */	stw r0, 4(r1)
    /* 80031FB8 0002EB98  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80031FBC 0002EB9C  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80031FC0 0002EBA0  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80031FC4 0002EBA4  3B C4 00 00 */	addi r30, r4, 0
    /* 80031FC8 0002EBA8  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80031FCC 0002EBAC  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80031FD0 0002EBB0  41 80 00 0C */	blt lbl_80031FDC
    /* 80031FD4 0002EBB4  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031FD8 0002EBB8  41 80 00 2C */	blt lbl_80032004
    lbl_80031FDC:
    /* 80031FDC 0002EBBC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80031FE0 0002EBC0  4C C6 31 82 */	crclr 6
    /* 80031FE4 0002EBC4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80031FE8 0002EBC8  38 9D 00 00 */	addi r4, r29, 0
    /* 80031FEC 0002EBCC  48 31 36 BD */	bl OSReport
    /* 80031FF0 0002EBD0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80031FF4 0002EBD4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80031FF8 0002EBD8  38 80 00 66 */	li r4, 0x66
    /* 80031FFC 0002EBDC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032000 0002EBE0  48 35 62 21 */	bl __assert
    lbl_80032004:
    /* 80032004 0002EBE4  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032008 0002EBE8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003200C 0002EBEC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032010 0002EBF0  7F E0 22 14 */	add r31, r0, r4
    /* 80032014 0002EBF4  7C 7F F2 14 */	add r3, r31, r30
    /* 80032018 0002EBF8  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 8003201C 0002EBFC  38 80 00 00 */	li r4, 0
    /* 80032020 0002EC00  54 00 10 3A */	slwi r0, r0, 2
    /* 80032024 0002EC04  7C 7F 02 14 */	add r3, r31, r0
    /* 80032028 0002EC08  90 83 00 B0 */	stw r4, 0xb0(r3)
    /* 8003202C 0002EC0C  88 1F 00 AC */	lbz r0, 0xac(r31)
    /* 80032030 0002EC10  54 00 DF FF */	rlwinm. r0, r0, 0x1b, 0x1f, 0x1f
    /* 80032034 0002EC14  41 82 00 18 */	beq lbl_8003204C
    /* 80032038 0002EC18  38 7D 00 00 */	addi r3, r29, 0
    /* 8003203C 0002EC1C  38 80 00 00 */	li r4, 0
    /* 80032040 0002EC20  4B FF F9 85 */	bl Player_800319C4
    /* 80032044 0002EC24  2C 03 00 00 */	cmpwi r3, 0
    /* 80032048 0002EC28  41 82 00 0C */	beq lbl_80032054
    lbl_8003204C:
    /* 8003204C 0002EC2C  38 00 00 00 */	li r0, 0
    /* 80032050 0002EC30  90 1F 00 00 */	stw r0, 0(r31)
    lbl_80032054:
    /* 80032054 0002EC34  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032058 0002EC38  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 8003205C 0002EC3C  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 80032060 0002EC40  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80032064 0002EC44  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032068 0002EC48  7C 08 03 A6 */	mtlr r0
    /* 8003206C 0002EC4C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032070(s32 slot, BOOL bool_arg) {   ////https://decomp.me/scratch/HuE3T
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    
    if (bool_arg == 0) {
        func_800D4FF4(player->player_entity[player->transformed[0]]);
        if(((player->flags >> 5) & 0x1) 
                && unkStruct->vec_arr[player->player_character].z == 0 
                && func_8008701C(player->player_entity[player->transformed[1]])) 
        {
            func_800D4FF4(player->player_entity[player->transformed[1]]);
        }
        func_802F6E1C(slot);
        return;
    }

    if (func_800873CC(player->player_entity[player->transformed[0]])) {
        func_800D4FF4(player->player_entity[player->transformed[1]]);
    }
}
#else
asm void Player_80032070()
{
    nofralloc
    /* 80032070 0002EC50  7C 08 02 A6 */	mflr r0
    /* 80032074 0002EC54  90 01 00 04 */	stw r0, 4(r1)
    /* 80032078 0002EC58  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003207C 0002EC5C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032080 0002EC60  3B E4 00 00 */	addi r31, r4, 0
    /* 80032084 0002EC64  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032088 0002EC68  7C 7E 1B 79 */	or. r30, r3, r3
    /* 8003208C 0002EC6C  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80032090 0002EC70  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80032094 0002EC74  3B A3 CD C0 */	addi r29, r3, lbl_803BCDC0@l
    /* 80032098 0002EC78  41 80 00 0C */	blt lbl_800320A4
    /* 8003209C 0002EC7C  2C 1E 00 06 */	cmpwi r30, 6
    /* 800320A0 0002EC80  41 80 00 24 */	blt lbl_800320C4
    lbl_800320A4:
    /* 800320A4 0002EC84  38 9E 00 00 */	addi r4, r30, 0
    /* 800320A8 0002EC88  4C C6 31 82 */	crclr 6
    /* 800320AC 0002EC8C  38 7D 00 84 */	addi r3, r29, 0x84
    /* 800320B0 0002EC90  48 31 35 F9 */	bl OSReport
    /* 800320B4 0002EC94  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 800320B8 0002EC98  38 80 00 66 */	li r4, 0x66
    /* 800320BC 0002EC9C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800320C0 0002ECA0  48 35 61 61 */	bl __assert
    lbl_800320C4:
    /* 800320C4 0002ECA4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800320C8 0002ECA8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800320CC 0002ECAC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800320D0 0002ECB0  2C 1F 00 00 */	cmpwi r31, 0
    /* 800320D4 0002ECB4  7F E0 22 14 */	add r31, r0, r4
    /* 800320D8 0002ECB8  40 82 00 78 */	bne lbl_80032150
    /* 800320DC 0002ECBC  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 800320E0 0002ECC0  54 00 10 3A */	slwi r0, r0, 2
    /* 800320E4 0002ECC4  7C 7F 02 14 */	add r3, r31, r0
    /* 800320E8 0002ECC8  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 800320EC 0002ECCC  48 0A 2F 09 */	bl func_800D4FF4
    /* 800320F0 0002ECD0  88 1F 00 AC */	lbz r0, 0xac(r31)
    /* 800320F4 0002ECD4  54 00 DF FF */	rlwinm. r0, r0, 0x1b, 0x1f, 0x1f
    /* 800320F8 0002ECD8  41 82 00 4C */	beq lbl_80032144
    /* 800320FC 0002ECDC  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032100 0002ECE0  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032104 0002ECE4  7C 7D 02 14 */	add r3, r29, r0
    /* 80032108 0002ECE8  88 03 00 22 */	lbz r0, 0x22(r3)
    /* 8003210C 0002ECEC  7C 00 07 75 */	extsb. r0, r0
    /* 80032110 0002ECF0  40 82 00 34 */	bne lbl_80032144
    /* 80032114 0002ECF4  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032118 0002ECF8  54 00 10 3A */	slwi r0, r0, 2
    /* 8003211C 0002ECFC  7C 7F 02 14 */	add r3, r31, r0
    /* 80032120 0002ED00  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032124 0002ED04  48 05 4E F9 */	bl func_8008701C
    /* 80032128 0002ED08  2C 03 00 00 */	cmpwi r3, 0
    /* 8003212C 0002ED0C  41 82 00 18 */	beq lbl_80032144
    /* 80032130 0002ED10  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032134 0002ED14  54 00 10 3A */	slwi r0, r0, 2
    /* 80032138 0002ED18  7C 7F 02 14 */	add r3, r31, r0
    /* 8003213C 0002ED1C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032140 0002ED20  48 0A 2E B5 */	bl func_800D4FF4
    lbl_80032144:
    /* 80032144 0002ED24  7F C3 F3 78 */	mr r3, r30
    /* 80032148 0002ED28  48 2C 4C D5 */	bl func_802F6E1C
    /* 8003214C 0002ED2C  48 00 00 34 */	b lbl_80032180
    lbl_80032150:
    /* 80032150 0002ED30  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032154 0002ED34  54 00 10 3A */	slwi r0, r0, 2
    /* 80032158 0002ED38  7C 7F 02 14 */	add r3, r31, r0
    /* 8003215C 0002ED3C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032160 0002ED40  48 05 52 6D */	bl func_800873CC
    /* 80032164 0002ED44  2C 03 00 00 */	cmpwi r3, 0
    /* 80032168 0002ED48  41 82 00 18 */	beq lbl_80032180
    /* 8003216C 0002ED4C  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032170 0002ED50  54 00 10 3A */	slwi r0, r0, 2
    /* 80032174 0002ED54  7C 7F 02 14 */	add r3, r31, r0
    /* 80032178 0002ED58  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 8003217C 0002ED5C  48 0A 2E 79 */	bl func_800D4FF4
    lbl_80032180:
    /* 80032180 0002ED60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032184 0002ED64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032188 0002ED68  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003218C 0002ED6C  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80032190 0002ED70  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032194 0002ED74  7C 08 03 A6 */	mtlr r0
    /* 80032198 0002ED78  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_8003219C(s32 slot) {   ///https://decomp.me/scratch/q6dzH
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_8008701C(player->player_entity[player->transformed[0]]);
}
#else
asm void Player_8003219C()
{
    nofralloc
    /* 8003219C 0002ED7C  7C 08 02 A6 */	mflr r0
    /* 800321A0 0002ED80  90 01 00 04 */	stw r0, 4(r1)
    /* 800321A4 0002ED84  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800321A8 0002ED88  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800321AC 0002ED8C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800321B0 0002ED90  41 80 00 0C */	blt lbl_800321BC
    /* 800321B4 0002ED94  2C 1F 00 06 */	cmpwi r31, 6
    /* 800321B8 0002ED98  41 80 00 2C */	blt lbl_800321E4
    lbl_800321BC:
    /* 800321BC 0002ED9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800321C0 0002EDA0  4C C6 31 82 */	crclr 6
    /* 800321C4 0002EDA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800321C8 0002EDA8  38 9F 00 00 */	addi r4, r31, 0
    /* 800321CC 0002EDAC  48 31 34 DD */	bl OSReport
    /* 800321D0 0002EDB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800321D4 0002EDB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800321D8 0002EDB8  38 80 00 66 */	li r4, 0x66
    /* 800321DC 0002EDBC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800321E0 0002EDC0  48 35 60 41 */	bl __assert
    lbl_800321E4:
    /* 800321E4 0002EDC4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800321E8 0002EDC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800321EC 0002EDCC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800321F0 0002EDD0  7C 60 22 14 */	add r3, r0, r4
    /* 800321F4 0002EDD4  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800321F8 0002EDD8  54 00 10 3A */	slwi r0, r0, 2
    /* 800321FC 0002EDDC  7C 63 02 14 */	add r3, r3, r0
    /* 80032200 0002EDE0  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032204 0002EDE4  48 05 4E 19 */	bl func_8008701C
    /* 80032208 0002EDE8  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 8003220C 0002EDEC  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032210 0002EDF0  38 21 00 18 */	addi r1, r1, 0x18
    /* 80032214 0002EDF4  7C 08 03 A6 */	mtlr r0
    /* 80032218 0002EDF8  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
BOOL Player_8003221C(s32 slot) {    //// https://decomp.me/scratch/jpxOM

    StaticPlayer* player;

    if (Player_GetPlayerState(slot) == 2) {   ///2 means in-game
        Player_CheckSlot(slot);
        player = &player_slots[slot];

        if (!func_8008701C(player->player_entity[player->transformed[0]])) {
            return 1;
        }

    }

    return 0;
}
#else
asm BOOL Player_8003221C(s32 slot)
{
    nofralloc
    /* 8003221C 0002EDFC  7C 08 02 A6 */	mflr r0
    /* 80032220 0002EE00  90 01 00 04 */	stw r0, 4(r1)
    /* 80032224 0002EE04  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80032228 0002EE08  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 8003222C 0002EE0C  7C 7F 1B 78 */	mr r31, r3
    /* 80032230 0002EE10  48 00 00 91 */	bl Player_GetPlayerState
    /* 80032234 0002EE14  2C 03 00 02 */	cmpwi r3, 2
    /* 80032238 0002EE18  40 82 00 70 */	bne lbl_800322A8
    /* 8003223C 0002EE1C  2C 1F 00 00 */	cmpwi r31, 0
    /* 80032240 0002EE20  41 80 00 0C */	blt lbl_8003224C
    /* 80032244 0002EE24  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032248 0002EE28  41 80 00 2C */	blt lbl_80032274
    lbl_8003224C:
    /* 8003224C 0002EE2C  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 80032250 0002EE30  4C C6 31 82 */	crclr 6
    /* 80032254 0002EE34  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 80032258 0002EE38  38 9F 00 00 */	addi r4, r31, 0
    /* 8003225C 0002EE3C  48 31 34 4D */	bl OSReport
    /* 80032260 0002EE40  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 80032264 0002EE44  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 80032268 0002EE48  38 80 00 66 */	li r4, 0x66
    /* 8003226C 0002EE4C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032270 0002EE50  48 35 5F B1 */	bl __assert
    lbl_80032274:
    /* 80032274 0002EE54  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032278 0002EE58  3C 60 80 45 */	lis r3, player_slots
    /* 8003227C 0002EE5C  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032280 0002EE60  7C 60 22 14 */	add r3, r0, r4
    /* 80032284 0002EE64  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80032288 0002EE68  54 00 10 3A */	slwi r0, r0, 2
    /* 8003228C 0002EE6C  7C 63 02 14 */	add r3, r3, r0
    /* 80032290 0002EE70  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032294 0002EE74  48 05 4D 89 */	bl func_8008701C
    /* 80032298 0002EE78  2C 03 00 00 */	cmpwi r3, 0
    /* 8003229C 0002EE7C  40 82 00 0C */	bne lbl_800322A8
    /* 800322A0 0002EE80  38 60 00 01 */	li r3, 1
    /* 800322A4 0002EE84  48 00 00 08 */	b lbl_800322AC
    lbl_800322A8:
    /* 800322A8 0002EE88  38 60 00 00 */	li r3, 0
    lbl_800322AC:
    /* 800322AC 0002EE8C  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 800322B0 0002EE90  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 800322B4 0002EE94  38 21 00 18 */	addi r1, r1, 0x18
    /* 800322B8 0002EE98  7C 08 03 A6 */	mtlr r0
    /* 800322BC 0002EE9C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s32 Player_GetPlayerState(s32 slot) {  //https://decomp.me/scratch/495kO
    s32 state;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    state = player->player_state;
    return state;
}
#else
asm s32 Player_GetPlayerState(s32 slot)
{
    nofralloc
    /* 800322C0 0002EEA0  7C 08 02 A6 */	mflr r0
    /* 800322C4 0002EEA4  90 01 00 04 */	stw r0, 4(r1)
    /* 800322C8 0002EEA8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800322CC 0002EEAC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800322D0 0002EEB0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800322D4 0002EEB4  41 80 00 0C */	blt lbl_800322E0
    /* 800322D8 0002EEB8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800322DC 0002EEBC  41 80 00 2C */	blt lbl_80032308
    lbl_800322E0:
    /* 800322E0 0002EEC0  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 800322E4 0002EEC4  4C C6 31 82 */	crclr 6
    /* 800322E8 0002EEC8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 800322EC 0002EECC  38 9F 00 00 */	addi r4, r31, 0
    /* 800322F0 0002EED0  48 31 33 B9 */	bl OSReport
    /* 800322F4 0002EED4  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 800322F8 0002EED8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 800322FC 0002EEDC  38 80 00 66 */	li r4, 0x66
    /* 80032300 0002EEE0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032304 0002EEE4  48 35 5F 1D */	bl __assert
    lbl_80032308:
    /* 80032308 0002EEE8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003230C 0002EEEC  3C 60 80 45 */	lis r3, player_slots
    /* 80032310 0002EEF0  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032314 0002EEF4  7C 60 22 14 */	add r3, r0, r4
    /* 80032318 0002EEF8  80 63 00 00 */	lwz r3, 0(r3)
    /* 8003231C 0002EEFC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032320 0002EF00  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032324 0002EF04  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032328 0002EF08  7C 08 03 A6 */	mtlr r0
    /* 8003232C 0002EF0C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetPlayerCharacter(s32 slot) {   ///https://decomp.me/scratch/3aykL
    s32 unused;
    StaticPlayer* player; 
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->player_character;
}
#else
asm s32 Player_GetPlayerCharacter(s32 slot) 
{
    nofralloc
    /* 80032330 0002EF10  7C 08 02 A6 */	mflr r0
    /* 80032334 0002EF14  90 01 00 04 */	stw r0, 4(r1)
    /* 80032338 0002EF18  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003233C 0002EF1C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032340 0002EF20  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032344 0002EF24  41 80 00 0C */	blt lbl_80032350
    /* 80032348 0002EF28  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003234C 0002EF2C  41 80 00 2C */	blt lbl_80032378
    lbl_80032350:
    /* 80032350 0002EF30  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 80032354 0002EF34  4C C6 31 82 */	crclr 6
    /* 80032358 0002EF38  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 8003235C 0002EF3C  38 9F 00 00 */	addi r4, r31, 0
    /* 80032360 0002EF40  48 31 33 49 */	bl OSReport
    /* 80032364 0002EF44  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 80032368 0002EF48  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 8003236C 0002EF4C  38 80 00 66 */	li r4, 0x66
    /* 80032370 0002EF50  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032374 0002EF54  48 35 5E AD */	bl __assert
    lbl_80032378:
    /* 80032378 0002EF58  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003237C 0002EF5C  3C 60 80 45 */	lis r3, player_slots
    /* 80032380 0002EF60  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032384 0002EF64  7C 60 22 14 */	add r3, r0, r4
    /* 80032388 0002EF68  80 63 00 04 */	lwz r3, 4(r3)
    /* 8003238C 0002EF6C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032390 0002EF70  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032394 0002EF74  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032398 0002EF78  7C 08 03 A6 */	mtlr r0
    /* 8003239C 0002EF7C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerCharacter(s32 slot, s32 value) {   ///https://decomp.me/scratch/zABz1
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_character = value;
}
#else
asm void Player_SetPlayerCharacter(s32 slot, s32 value)
{
    nofralloc
    /* 800323A0 0002EF80  7C 08 02 A6 */	mflr r0
    /* 800323A4 0002EF84  90 01 00 04 */	stw r0, 4(r1)
    /* 800323A8 0002EF88  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800323AC 0002EF8C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800323B0 0002EF90  3B E4 00 00 */	addi r31, r4, 0
    /* 800323B4 0002EF94  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800323B8 0002EF98  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800323BC 0002EF9C  41 80 00 0C */	blt lbl_800323C8
    /* 800323C0 0002EFA0  2C 1E 00 06 */	cmpwi r30, 6
    /* 800323C4 0002EFA4  41 80 00 2C */	blt lbl_800323F0
    lbl_800323C8:
    /* 800323C8 0002EFA8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800323CC 0002EFAC  4C C6 31 82 */	crclr 6
    /* 800323D0 0002EFB0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800323D4 0002EFB4  38 9E 00 00 */	addi r4, r30, 0
    /* 800323D8 0002EFB8  48 31 32 D1 */	bl OSReport
    /* 800323DC 0002EFBC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800323E0 0002EFC0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800323E4 0002EFC4  38 80 00 66 */	li r4, 0x66
    /* 800323E8 0002EFC8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800323EC 0002EFCC  48 35 5E 35 */	bl __assert
    lbl_800323F0:
    /* 800323F0 0002EFD0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800323F4 0002EFD4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800323F8 0002EFD8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800323FC 0002EFDC  7C 60 22 14 */	add r3, r0, r4
    /* 80032400 0002EFE0  93 E3 00 04 */	stw r31, 4(r3)
    /* 80032404 0002EFE4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032408 0002EFE8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003240C 0002EFEC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032410 0002EFF0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032414 0002EFF4  7C 08 03 A6 */	mtlr r0
    /* 80032418 0002EFF8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetPlayerSlotType(s32 slot) {   ///https://decomp.me/scratch/1BMYo
    s32 slot_type;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    slot_type = player->slot_type;
    return slot_type;
}
#else
asm s32 Player_GetPlayerSlotType(s32 slot) {
    nofralloc
    /* 8003241C 0002EFFC  7C 08 02 A6 */	mflr r0
    /* 80032420 0002F000  90 01 00 04 */	stw r0, 4(r1)
    /* 80032424 0002F004  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032428 0002F008  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003242C 0002F00C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032430 0002F010  41 80 00 0C */	blt lbl_8003243C
    /* 80032434 0002F014  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032438 0002F018  41 80 00 2C */	blt lbl_80032464
    lbl_8003243C:
    /* 8003243C 0002F01C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032440 0002F020  4C C6 31 82 */	crclr 6
    /* 80032444 0002F024  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032448 0002F028  38 9F 00 00 */	addi r4, r31, 0
    /* 8003244C 0002F02C  48 31 32 5D */	bl OSReport
    /* 80032450 0002F030  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032454 0002F034  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032458 0002F038  38 80 00 66 */	li r4, 0x66
    /* 8003245C 0002F03C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032460 0002F040  48 35 5D C1 */	bl __assert
    lbl_80032464:
    /* 80032464 0002F044  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032468 0002F048  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003246C 0002F04C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032470 0002F050  7C 60 22 14 */	add r3, r0, r4
    /* 80032474 0002F054  80 63 00 08 */	lwz r3, 8(r3)
    /* 80032478 0002F058  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003247C 0002F05C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032480 0002F060  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032484 0002F064  7C 08 03 A6 */	mtlr r0
    /* 80032488 0002F068  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_8003248C(s32 slot, BOOL arg1) {   //https://decomp.me/scratch/3yC1W
    
    s32 slot_type;
    struct Unk_Struct_w_Array* unk_struct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    StaticPlayer* player;
 
    Player_CheckSlot(slot);

    player = &player_slots[slot];

    if (arg1 == 1) {

        if (unk_struct->vec_arr[player->player_character].z == 0) {
            if (player->slot_type == 0 || player->slot_type == 1) {
                return 1;
            }
        }
    }
    slot_type = player->slot_type;

    return slot_type;
}
#else
asm s32 Player_8003248C(s32 slot, BOOL arg1)
{
    nofralloc
    /* 8003248C 0002F06C  7C 08 02 A6 */	mflr r0
    /* 80032490 0002F070  90 01 00 04 */	stw r0, 4(r1)
    /* 80032494 0002F074  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032498 0002F078  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 8003249C 0002F07C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 800324A0 0002F080  3B C4 00 00 */	addi r30, r4, 0
    /* 800324A4 0002F084  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 800324A8 0002F088  7C 7D 1B 79 */	or. r29, r3, r3
    /* 800324AC 0002F08C  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 800324B0 0002F090  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
    /* 800324B4 0002F094  41 80 00 0C */	blt lbl_800324C0
    /* 800324B8 0002F098  2C 1D 00 06 */	cmpwi r29, 6
    /* 800324BC 0002F09C  41 80 00 24 */	blt lbl_800324E0
    lbl_800324C0:
    /* 800324C0 0002F0A0  38 9D 00 00 */	addi r4, r29, 0
    /* 800324C4 0002F0A4  4C C6 31 82 */	crclr 6
    /* 800324C8 0002F0A8  38 7F 00 84 */	addi r3, r31, 0x84
    /* 800324CC 0002F0AC  48 31 31 DD */	bl OSReport
    /* 800324D0 0002F0B0  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 800324D4 0002F0B4  38 80 00 66 */	li r4, 0x66
    /* 800324D8 0002F0B8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800324DC 0002F0BC  48 35 5D 45 */	bl __assert
    lbl_800324E0:
    /* 800324E0 0002F0C0  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 800324E4 0002F0C4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800324E8 0002F0C8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800324EC 0002F0CC  2C 1E 00 01 */	cmpwi r30, 1
    /* 800324F0 0002F0D0  7C 80 22 14 */	add r4, r0, r4
    /* 800324F4 0002F0D4  40 82 00 38 */	bne lbl_8003252C
    /* 800324F8 0002F0D8  80 04 00 04 */	lwz r0, 4(r4)
    /* 800324FC 0002F0DC  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032500 0002F0E0  7C 7F 02 14 */	add r3, r31, r0
    /* 80032504 0002F0E4  88 03 00 22 */	lbz r0, 0x22(r3)
    /* 80032508 0002F0E8  7C 00 07 75 */	extsb. r0, r0
    /* 8003250C 0002F0EC  40 82 00 20 */	bne lbl_8003252C
    /* 80032510 0002F0F0  80 04 00 08 */	lwz r0, 8(r4)
    /* 80032514 0002F0F4  2C 00 00 00 */	cmpwi r0, 0
    /* 80032518 0002F0F8  41 82 00 0C */	beq lbl_80032524
    /* 8003251C 0002F0FC  2C 00 00 01 */	cmpwi r0, 1
    /* 80032520 0002F100  40 82 00 0C */	bne lbl_8003252C
    lbl_80032524:
    /* 80032524 0002F104  38 60 00 01 */	li r3, 1
    /* 80032528 0002F108  48 00 00 08 */	b lbl_80032530
    lbl_8003252C:
    /* 8003252C 0002F10C  80 64 00 08 */	lwz r3, 8(r4)
    lbl_80032530:
    /* 80032530 0002F110  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032534 0002F114  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80032538 0002F118  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 8003253C 0002F11C  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80032540 0002F120  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032544 0002F124  7C 08 03 A6 */	mtlr r0
    /* 80032548 0002F128  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetSlottype(s32 slot, s32 value) {
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->slot_type = value;
}
#else
asm void Player_SetSlottype(s32 slot, s32 value) 
{
    nofralloc
    /* 8003254C 0002F12C  7C 08 02 A6 */	mflr r0
    /* 80032550 0002F130  90 01 00 04 */	stw r0, 4(r1)
    /* 80032554 0002F134  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032558 0002F138  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003255C 0002F13C  3B E4 00 00 */	addi r31, r4, 0
    /* 80032560 0002F140  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032564 0002F144  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032568 0002F148  41 80 00 0C */	blt lbl_80032574
    /* 8003256C 0002F14C  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032570 0002F150  41 80 00 2C */	blt lbl_8003259C
    lbl_80032574:
    /* 80032574 0002F154  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032578 0002F158  4C C6 31 82 */	crclr 6
    /* 8003257C 0002F15C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032580 0002F160  38 9E 00 00 */	addi r4, r30, 0
    /* 80032584 0002F164  48 31 31 25 */	bl OSReport
    /* 80032588 0002F168  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003258C 0002F16C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032590 0002F170  38 80 00 66 */	li r4, 0x66
    /* 80032594 0002F174  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032598 0002F178  48 35 5C 89 */	bl __assert
    lbl_8003259C:
    /* 8003259C 0002F17C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800325A0 0002F180  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800325A4 0002F184  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800325A8 0002F188  7C 60 22 14 */	add r3, r0, r4
    /* 800325AC 0002F18C  93 E3 00 08 */	stw r31, 8(r3)
    /* 800325B0 0002F190  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800325B4 0002F194  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800325B8 0002F198  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800325BC 0002F19C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800325C0 0002F1A0  7C 08 03 A6 */	mtlr r0
    /* 800325C4 0002F1A4  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
s8 Player_800325C8(s32 slot, BOOL b) {
    
    
    if (!b) {
        return lbl_803BCDE0[slot].x;
    }
    else if (b == 1) {
        return lbl_803BCDE0[slot].y;
    }

    return -1;
}
#else
asm s8 Player_800325C8(s32 slot, BOOL b) 
{
    nofralloc
    /* 800325C8 0002F1A8  2C 04 00 00 */	cmpwi r4, 0
    /* 800325CC 0002F1AC  40 82 00 1C */	bne lbl_800325E8
    /* 800325D0 0002F1B0  1C 83 00 03 */	mulli r4, r3, 3
    /* 800325D4 0002F1B4  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
    /* 800325D8 0002F1B8  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
    /* 800325DC 0002F1BC  7C 60 22 14 */	add r3, r0, r4
    /* 800325E0 0002F1C0  88 63 00 00 */	lbz r3, 0(r3)
    /* 800325E4 0002F1C4  4E 80 00 20 */	blr 
    lbl_800325E8:
    /* 800325E8 0002F1C8  2C 04 00 01 */	cmpwi r4, 1
    /* 800325EC 0002F1CC  40 82 00 1C */	bne lbl_80032608
    /* 800325F0 0002F1D0  1C 03 00 03 */	mulli r0, r3, 3
    /* 800325F4 0002F1D4  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
    /* 800325F8 0002F1D8  38 63 CD E0 */	addi r3, r3, lbl_803BCDE0@l
    /* 800325FC 0002F1DC  7C 63 02 14 */	add r3, r3, r0
    /* 80032600 0002F1E0  88 63 00 01 */	lbz r3, 1(r3)
    /* 80032604 0002F1E4  4E 80 00 20 */	blr 
    lbl_80032608:
    /* 80032608 0002F1E8  38 60 FF FF */	li r3, -1
    /* 8003260C 0002F1EC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_80032610(s32 slot, BOOL arg1) {  ////https://decomp.me/scratch/pHTx2

    struct Unk_Struct_w_Array* some_struct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    StaticPlayer* player;
    s32 error_value = -1;


    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if (arg1 == 0) {
        return some_struct->vec_arr[player->player_character].x;
    }
    if (arg1 == 1) {
        return some_struct->vec_arr[player->player_character].y;
    }

    return error_value;
}
#else
asm s8 Player_80032610(s32 slot, BOOL arg1) 
{
    nofralloc
    /* 80032610 0002F1F0  7C 08 02 A6 */	mflr r0
    /* 80032614 0002F1F4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032618 0002F1F8  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 8003261C 0002F1FC  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032620 0002F200  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032624 0002F204  3B C4 00 00 */	addi r30, r4, 0
    /* 80032628 0002F208  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 8003262C 0002F20C  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80032630 0002F210  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80032634 0002F214  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
    /* 80032638 0002F218  41 80 00 0C */	blt lbl_80032644
    /* 8003263C 0002F21C  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032640 0002F220  41 80 00 24 */	blt lbl_80032664
    lbl_80032644:
    /* 80032644 0002F224  38 9D 00 00 */	addi r4, r29, 0
    /* 80032648 0002F228  4C C6 31 82 */	crclr 6
    /* 8003264C 0002F22C  38 7F 00 84 */	addi r3, r31, 0x84
    /* 80032650 0002F230  48 31 30 59 */	bl OSReport
    /* 80032654 0002F234  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 80032658 0002F238  38 80 00 66 */	li r4, 0x66
    /* 8003265C 0002F23C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032660 0002F240  48 35 5B C1 */	bl __assert
    lbl_80032664:
    /* 80032664 0002F244  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032668 0002F248  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003266C 0002F24C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032670 0002F250  2C 1E 00 00 */	cmpwi r30, 0
    /* 80032674 0002F254  7C 60 22 14 */	add r3, r0, r4
    /* 80032678 0002F258  40 82 00 18 */	bne lbl_80032690
    /* 8003267C 0002F25C  80 03 00 04 */	lwz r0, 4(r3)
    /* 80032680 0002F260  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032684 0002F264  7C 7F 02 14 */	add r3, r31, r0
    /* 80032688 0002F268  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 8003268C 0002F26C  48 00 00 24 */	b lbl_800326B0
    lbl_80032690:
    /* 80032690 0002F270  2C 1E 00 01 */	cmpwi r30, 1
    /* 80032694 0002F274  40 82 00 18 */	bne lbl_800326AC
    /* 80032698 0002F278  80 03 00 04 */	lwz r0, 4(r3)
    /* 8003269C 0002F27C  1C 00 00 03 */	mulli r0, r0, 3
    /* 800326A0 0002F280  7C 7F 02 14 */	add r3, r31, r0
    /* 800326A4 0002F284  88 63 00 21 */	lbz r3, 0x21(r3)
    /* 800326A8 0002F288  48 00 00 08 */	b lbl_800326B0
    lbl_800326AC:
    /* 800326AC 0002F28C  38 60 FF FF */	li r3, -1
    lbl_800326B0:
    /* 800326B0 0002F290  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800326B4 0002F294  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800326B8 0002F298  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800326BC 0002F29C  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800326C0 0002F2A0  38 21 00 28 */	addi r1, r1, 0x28
    /* 800326C4 0002F2A4  7C 08 03 A6 */	mtlr r0
    /* 800326C8 0002F2A8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800326CC(s32 slot, Vec* arg_vec) {
    StaticPlayer* player;
    Vec* player_vecs;

    Player_CheckSlot(slot);

    player = &player_slots[slot];
    player_vecs = player->player_poses.byIndex;
    *arg_vec = player_vecs[player->transformed[0]];
}

#else
asm void Player_800326CC(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 800326CC 0002F2AC  7C 08 02 A6 */	mflr r0
    /* 800326D0 0002F2B0  90 01 00 04 */	stw r0, 4(r1)
    /* 800326D4 0002F2B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800326D8 0002F2B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800326DC 0002F2BC  3B E4 00 00 */	addi r31, r4, 0
    /* 800326E0 0002F2C0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800326E4 0002F2C4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800326E8 0002F2C8  41 80 00 0C */	blt lbl_800326F4
    /* 800326EC 0002F2CC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800326F0 0002F2D0  41 80 00 2C */	blt lbl_8003271C
    lbl_800326F4:
    /* 800326F4 0002F2D4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800326F8 0002F2D8  4C C6 31 82 */	crclr 6
    /* 800326FC 0002F2DC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032700 0002F2E0  38 9E 00 00 */	addi r4, r30, 0
    /* 80032704 0002F2E4  48 31 2F A5 */	bl OSReport
    /* 80032708 0002F2E8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003270C 0002F2EC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032710 0002F2F0  38 80 00 66 */	li r4, 0x66
    /* 80032714 0002F2F4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032718 0002F2F8  48 35 5B 09 */	bl __assert
    lbl_8003271C:
    /* 8003271C 0002F2FC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032720 0002F300  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032724 0002F304  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032728 0002F308  7C 60 22 14 */	add r3, r0, r4
    /* 8003272C 0002F30C  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80032730 0002F310  1C 00 00 0C */	mulli r0, r0, 0xc
    /* 80032734 0002F314  7C 83 02 14 */	add r4, r3, r0
    /* 80032738 0002F318  80 64 00 10 */	lwz r3, 0x10(r4)
    /* 8003273C 0002F31C  80 04 00 14 */	lwz r0, 0x14(r4)
    /* 80032740 0002F320  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032744 0002F324  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032748 0002F328  80 04 00 18 */	lwz r0, 0x18(r4)
    /* 8003274C 0002F32C  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032750 0002F330  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032754 0002F334  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032758 0002F338  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003275C 0002F33C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032760 0002F340  7C 08 03 A6 */	mtlr r0
    /* 80032764 0002F344  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032768(s32 slot, Vec* arg_vec) { //https://decomp.me/scratch/Acnkf
    StaticPlayer* player;
    Vec* player_vecs;

    Vec* dst_vec;
    Vec* dst_vec2;

    Player_CheckSlot(slot);

    player = &player_slots[slot];

    player_vecs = player->player_poses.byIndex;
    dst_vec = &player_vecs[player->transformed[0]];
    *dst_vec = *arg_vec;

    player_vecs = player->player_poses.byIndex;
    dst_vec2 = &player_vecs[player->transformed[1]];
    *dst_vec2 = *arg_vec;
}
#else
asm void Player_80032768(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032768 0002F348  7C 08 02 A6 */	mflr r0
    /* 8003276C 0002F34C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032770 0002F350  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032774 0002F354  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032778 0002F358  3B E4 00 00 */	addi r31, r4, 0
    /* 8003277C 0002F35C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032780 0002F360  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032784 0002F364  41 80 00 0C */	blt lbl_80032790
    /* 80032788 0002F368  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003278C 0002F36C  41 80 00 2C */	blt lbl_800327B8
    lbl_80032790:
    /* 80032790 0002F370  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032794 0002F374  4C C6 31 82 */	crclr 6
    /* 80032798 0002F378  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003279C 0002F37C  38 9E 00 00 */	addi r4, r30, 0
    /* 800327A0 0002F380  48 31 2F 09 */	bl OSReport
    /* 800327A4 0002F384  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800327A8 0002F388  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800327AC 0002F38C  38 80 00 66 */	li r4, 0x66
    /* 800327B0 0002F390  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800327B4 0002F394  48 35 5A 6D */	bl __assert
    lbl_800327B8:
    /* 800327B8 0002F398  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 800327BC 0002F39C  80 7F 00 00 */	lwz r3, 0(r31)
    /* 800327C0 0002F3A0  80 1F 00 04 */	lwz r0, 4(r31)
    /* 800327C4 0002F3A4  3C 80 80 45 */	lis r4, player_slots@ha
    /* 800327C8 0002F3A8  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 800327CC 0002F3AC  7C A4 2A 14 */	add r5, r4, r5
    /* 800327D0 0002F3B0  88 85 00 0C */	lbz r4, 0xc(r5)
    /* 800327D4 0002F3B4  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 800327D8 0002F3B8  7C 85 22 14 */	add r4, r5, r4
    /* 800327DC 0002F3BC  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800327E0 0002F3C0  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800327E4 0002F3C4  80 1F 00 08 */	lwz r0, 8(r31)
    /* 800327E8 0002F3C8  90 04 00 18 */	stw r0, 0x18(r4)
    /* 800327EC 0002F3CC  88 05 00 0D */	lbz r0, 0xd(r5)
    /* 800327F0 0002F3D0  80 7F 00 00 */	lwz r3, 0(r31)
    /* 800327F4 0002F3D4  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 800327F8 0002F3D8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 800327FC 0002F3DC  7C 85 22 14 */	add r4, r5, r4
    /* 80032800 0002F3E0  90 64 00 10 */	stw r3, 0x10(r4)
    /* 80032804 0002F3E4  90 04 00 14 */	stw r0, 0x14(r4)
    /* 80032808 0002F3E8  80 1F 00 08 */	lwz r0, 8(r31)
    /* 8003280C 0002F3EC  90 04 00 18 */	stw r0, 0x18(r4)
    /* 80032810 0002F3F0  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032814 0002F3F4  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80032818 0002F3F8  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 8003281C 0002F3FC  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032820 0002F400  7C 08 03 A6 */	mtlr r0
    /* 80032824 0002F404  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032828(s32 slot, s32 index, Vec* arg_vec) {  ///https://decomp.me/scratch/kre07
    StaticPlayer* player;
    Vec* player_vecs;

    Player_CheckSlot(slot);

    player = &player_slots[slot];

    player_vecs = player->player_poses.byIndex;
    player_vecs[player->transformed[index]] = *arg_vec;

}
#else
asm void Player_80032828(s32 slot, s32 index, Vec* arg_vec)
{
    nofralloc
    /* 80032828 0002F408  7C 08 02 A6 */	mflr r0
    /* 8003282C 0002F40C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032830 0002F410  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032834 0002F414  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032838 0002F418  3B E5 00 00 */	addi r31, r5, 0
    /* 8003283C 0002F41C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032840 0002F420  3B C4 00 00 */	addi r30, r4, 0
    /* 80032844 0002F424  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80032848 0002F428  7C 7D 1B 79 */	or. r29, r3, r3
    /* 8003284C 0002F42C  41 80 00 0C */	blt lbl_80032858
    /* 80032850 0002F430  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032854 0002F434  41 80 00 2C */	blt lbl_80032880
    lbl_80032858:
    /* 80032858 0002F438  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003285C 0002F43C  4C C6 31 82 */	crclr 6
    /* 80032860 0002F440  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032864 0002F444  38 9D 00 00 */	addi r4, r29, 0
    /* 80032868 0002F448  48 31 2E 41 */	bl OSReport
    /* 8003286C 0002F44C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032870 0002F450  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032874 0002F454  38 80 00 66 */	li r4, 0x66
    /* 80032878 0002F458  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003287C 0002F45C  48 35 59 A5 */	bl __assert
    lbl_80032880:
    /* 80032880 0002F460  1C BD 0E 90 */	mulli r5, r29, 0xe90
    /* 80032884 0002F464  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032888 0002F468  80 1F 00 04 */	lwz r0, 4(r31)
    /* 8003288C 0002F46C  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032890 0002F470  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032894 0002F474  7C A4 2A 14 */	add r5, r4, r5
    /* 80032898 0002F478  7C 85 F2 14 */	add r4, r5, r30
    /* 8003289C 0002F47C  88 84 00 0C */	lbz r4, 0xc(r4)
    /* 800328A0 0002F480  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 800328A4 0002F484  7C 85 22 14 */	add r4, r5, r4
    /* 800328A8 0002F488  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800328AC 0002F48C  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800328B0 0002F490  80 1F 00 08 */	lwz r0, 8(r31)
    /* 800328B4 0002F494  90 04 00 18 */	stw r0, 0x18(r4)
    /* 800328B8 0002F498  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800328BC 0002F49C  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800328C0 0002F4A0  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800328C4 0002F4A4  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800328C8 0002F4A8  38 21 00 28 */	addi r1, r1, 0x28
    /* 800328CC 0002F4AC  7C 08 03 A6 */	mtlr r0
    /* 800328D0 0002F4B0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800328D4(s32 slot, Vec* arg_vec) {  //https://decomp.me/scratch/dgJM1
    StaticPlayer* player;
    s32 i;
    Vec* player_vecs;
    Vec* player_vecs2;

    Vec* dst_vec;
    Vec* dst_vec2;

    Vec* unused;

    Player_CheckSlot(slot);
    player = &player_slots[slot];
    Player_CheckSlot(slot);

    player_vecs = player->player_poses.byIndex;
    dst_vec = &player_vecs[player->transformed[0]];
    *dst_vec = *arg_vec;

    player_vecs2 = player->player_poses.byIndex;
    dst_vec2 = &player_vecs2[player->transformed[1]];
    *dst_vec2 = *arg_vec;
    

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            func_80087140(player->player_entity[player->transformed[i]]);
        }
    }
}
#else
asm void Player_800328D4(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 800328D4 0002F4B4  7C 08 02 A6 */	mflr r0
    /* 800328D8 0002F4B8  90 01 00 04 */	stw r0, 4(r1)
    /* 800328DC 0002F4BC  94 21 FF C8 */	stwu r1, -0x38(r1)
    /* 800328E0 0002F4C0  93 E1 00 34 */	stw r31, 0x34(r1)
    /* 800328E4 0002F4C4  93 C1 00 30 */	stw r30, 0x30(r1)
    /* 800328E8 0002F4C8  93 A1 00 2C */	stw r29, 0x2c(r1)
    /* 800328EC 0002F4CC  3B A4 00 00 */	addi r29, r4, 0
    /* 800328F0 0002F4D0  93 81 00 28 */	stw r28, 0x28(r1)
    /* 800328F4 0002F4D4  7C 7C 1B 79 */	or. r28, r3, r3
    /* 800328F8 0002F4D8  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 800328FC 0002F4DC  3B C3 CD C0 */	addi r30, r3, lbl_803BCDC0@l
    /* 80032900 0002F4E0  41 80 00 0C */	blt lbl_8003290C
    /* 80032904 0002F4E4  2C 1C 00 06 */	cmpwi r28, 6
    /* 80032908 0002F4E8  41 80 00 24 */	blt lbl_8003292C
    lbl_8003290C:
    /* 8003290C 0002F4EC  38 9C 00 00 */	addi r4, r28, 0
    /* 80032910 0002F4F0  4C C6 31 82 */	crclr 6
    /* 80032914 0002F4F4  38 7E 00 84 */	addi r3, r30, 0x84
    /* 80032918 0002F4F8  48 31 2D 91 */	bl OSReport
    /* 8003291C 0002F4FC  38 7E 00 A0 */	addi r3, r30, 0xa0
    /* 80032920 0002F500  38 80 00 66 */	li r4, 0x66
    /* 80032924 0002F504  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032928 0002F508  48 35 58 F9 */	bl __assert
    lbl_8003292C:
    /* 8003292C 0002F50C  1C 9C 0E 90 */	mulli r4, r28, 0xe90
    /* 80032930 0002F510  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032934 0002F514  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032938 0002F518  2C 1C 00 00 */	cmpwi r28, 0
    /* 8003293C 0002F51C  7F E0 22 14 */	add r31, r0, r4
    /* 80032940 0002F520  41 80 00 0C */	blt lbl_8003294C
    /* 80032944 0002F524  2C 1C 00 06 */	cmpwi r28, 6
    /* 80032948 0002F528  41 80 00 24 */	blt lbl_8003296C
    lbl_8003294C:
    /* 8003294C 0002F52C  38 9C 00 00 */	addi r4, r28, 0
    /* 80032950 0002F530  4C C6 31 82 */	crclr 6
    /* 80032954 0002F534  38 7E 00 84 */	addi r3, r30, 0x84
    /* 80032958 0002F538  48 31 2D 51 */	bl OSReport
    /* 8003295C 0002F53C  38 7E 00 A0 */	addi r3, r30, 0xa0
    /* 80032960 0002F540  38 80 00 66 */	li r4, 0x66
    /* 80032964 0002F544  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032968 0002F548  48 35 58 B9 */	bl __assert
    lbl_8003296C:
    /* 8003296C 0002F54C  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032970 0002F550  3B C0 00 00 */	li r30, 0
    /* 80032974 0002F554  80 7D 00 00 */	lwz r3, 0(r29)
    /* 80032978 0002F558  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 8003297C 0002F55C  80 1D 00 04 */	lwz r0, 4(r29)
    /* 80032980 0002F560  7C 9F 22 14 */	add r4, r31, r4
    /* 80032984 0002F564  90 64 00 10 */	stw r3, 0x10(r4)
    /* 80032988 0002F568  90 04 00 14 */	stw r0, 0x14(r4)
    /* 8003298C 0002F56C  80 1D 00 08 */	lwz r0, 8(r29)
    /* 80032990 0002F570  90 04 00 18 */	stw r0, 0x18(r4)
    /* 80032994 0002F574  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032998 0002F578  80 7D 00 00 */	lwz r3, 0(r29)
    /* 8003299C 0002F57C  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 800329A0 0002F580  80 1D 00 04 */	lwz r0, 4(r29)
    /* 800329A4 0002F584  7C 9F 22 14 */	add r4, r31, r4
    /* 800329A8 0002F588  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800329AC 0002F58C  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800329B0 0002F590  80 1D 00 08 */	lwz r0, 8(r29)
    /* 800329B4 0002F594  90 04 00 18 */	stw r0, 0x18(r4)
    lbl_800329B8:
    /* 800329B8 0002F598  38 1E 00 0C */	addi r0, r30, 0xc
    /* 800329BC 0002F59C  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 800329C0 0002F5A0  54 03 10 3A */	slwi r3, r0, 2
    /* 800329C4 0002F5A4  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 800329C8 0002F5A8  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 800329CC 0002F5AC  28 03 00 00 */	cmplwi r3, 0
    /* 800329D0 0002F5B0  41 82 00 08 */	beq lbl_800329D8
    /* 800329D4 0002F5B4  48 05 47 6D */	bl func_80087140
    lbl_800329D8:
    /* 800329D8 0002F5B8  3B DE 00 01 */	addi r30, r30, 1
    /* 800329DC 0002F5BC  2C 1E 00 02 */	cmpwi r30, 2
    /* 800329E0 0002F5C0  41 80 FF D8 */	blt lbl_800329B8
    /* 800329E4 0002F5C4  80 01 00 3C */	lwz r0, 0x3c(r1)
    /* 800329E8 0002F5C8  83 E1 00 34 */	lwz r31, 0x34(r1)
    /* 800329EC 0002F5CC  83 C1 00 30 */	lwz r30, 0x30(r1)
    /* 800329F0 0002F5D0  83 A1 00 2C */	lwz r29, 0x2c(r1)
    /* 800329F4 0002F5D4  83 81 00 28 */	lwz r28, 0x28(r1)
    /* 800329F8 0002F5D8  38 21 00 38 */	addi r1, r1, 0x38
    /* 800329FC 0002F5DC  7C 08 03 A6 */	mtlr r0
    /* 80032A00 0002F5E0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032A04(s32 slot, Vec* arg_vec) {   ///https://decomp.me/scratch/EhCVP
    StaticPlayer* player;
    s32 i;

    Player_CheckSlot(slot);

    for (i = 0; i < 2; i++) {
        player = &player_slots[slot];

        player->player_poses.byIndex[player->transformed[i]] = *arg_vec;
                
        if (player->player_entity[player->transformed[i]]) {
            func_80086664(player->player_entity[player->transformed[i]], arg_vec);
        }
    }
}
#else
asm void Player_80032A04(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032A04 0002F5E4  7C 08 02 A6 */	mflr r0
    /* 80032A08 0002F5E8  90 01 00 04 */	stw r0, 4(r1)
    /* 80032A0C 0002F5EC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032A10 0002F5F0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032A14 0002F5F4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032A18 0002F5F8  3B C4 00 00 */	addi r30, r4, 0
    /* 80032A1C 0002F5FC  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80032A20 0002F600  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80032A24 0002F604  41 80 00 0C */	blt lbl_80032A30
    /* 80032A28 0002F608  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032A2C 0002F60C  41 80 00 2C */	blt lbl_80032A58
    lbl_80032A30:
    /* 80032A30 0002F610  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032A34 0002F614  4C C6 31 82 */	crclr 6
    /* 80032A38 0002F618  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032A3C 0002F61C  38 9D 00 00 */	addi r4, r29, 0
    /* 80032A40 0002F620  48 31 2C 69 */	bl OSReport
    /* 80032A44 0002F624  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032A48 0002F628  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032A4C 0002F62C  38 80 00 66 */	li r4, 0x66
    /* 80032A50 0002F630  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032A54 0002F634  48 35 57 CD */	bl __assert
    lbl_80032A58:
    /* 80032A58 0002F638  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032A5C 0002F63C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032A60 0002F640  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032A64 0002F644  7F A0 22 14 */	add r29, r0, r4
    /* 80032A68 0002F648  3B E0 00 00 */	li r31, 0
    lbl_80032A6C:
    /* 80032A6C 0002F64C  38 BF 00 0C */	addi r5, r31, 0xc
    /* 80032A70 0002F650  80 7E 00 00 */	lwz r3, 0(r30)
    /* 80032A74 0002F654  7C BD 2A 14 */	add r5, r29, r5
    /* 80032A78 0002F658  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80032A7C 0002F65C  88 85 00 00 */	lbz r4, 0(r5)
    /* 80032A80 0002F660  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 80032A84 0002F664  38 84 00 10 */	addi r4, r4, 0x10
    /* 80032A88 0002F668  7C 9D 22 14 */	add r4, r29, r4
    /* 80032A8C 0002F66C  90 64 00 00 */	stw r3, 0(r4)
    /* 80032A90 0002F670  90 04 00 04 */	stw r0, 4(r4)
    /* 80032A94 0002F674  80 1E 00 08 */	lwz r0, 8(r30)
    /* 80032A98 0002F678  90 04 00 08 */	stw r0, 8(r4)
    /* 80032A9C 0002F67C  88 05 00 00 */	lbz r0, 0(r5)
    /* 80032AA0 0002F680  54 03 10 3A */	slwi r3, r0, 2
    /* 80032AA4 0002F684  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032AA8 0002F688  7C 1D 00 2E */	lwzx r0, r29, r0
    /* 80032AAC 0002F68C  28 00 00 00 */	cmplwi r0, 0
    /* 80032AB0 0002F690  41 82 00 20 */	beq lbl_80032AD0
    /* 80032AB4 0002F694  38 1F 00 0C */	addi r0, r31, 0xc
    /* 80032AB8 0002F698  7C 1D 00 AE */	lbzx r0, r29, r0
    /* 80032ABC 0002F69C  38 9E 00 00 */	addi r4, r30, 0
    /* 80032AC0 0002F6A0  54 03 10 3A */	slwi r3, r0, 2
    /* 80032AC4 0002F6A4  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032AC8 0002F6A8  7C 7D 00 2E */	lwzx r3, r29, r0
    /* 80032ACC 0002F6AC  48 05 3B 99 */	bl func_80086664
    lbl_80032AD0:
    /* 80032AD0 0002F6B0  3B FF 00 01 */	addi r31, r31, 1
    /* 80032AD4 0002F6B4  2C 1F 00 02 */	cmpwi r31, 2
    /* 80032AD8 0002F6B8  41 80 FF 94 */	blt lbl_80032A6C
    /* 80032ADC 0002F6BC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032AE0 0002F6C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032AE4 0002F6C4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032AE8 0002F6C8  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80032AEC 0002F6CC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032AF0 0002F6D0  7C 08 03 A6 */	mtlr r0
    /* 80032AF4 0002F6D4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerAndEntityFacingDirection(s32 slot, f32 direction) {   ///https://decomp.me/scratch/DxWHO
    StaticPlayer* player;
    s32 i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    for (i = 0; i < 2; i++) {
        player->facing_direction = direction;
        if (player->player_entity[player->transformed[i]]) {
            func_SetEntityFacingDirection(direction, player->player_entity[player->transformed[i]]);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityFacingDirection(s32 slot, f32 direction) {
    nofralloc
    /* 80032AF8 0002F6D8  7C 08 02 A6 */	mflr r0
    /* 80032AFC 0002F6DC  90 01 00 04 */	stw r0, 4(r1)
    /* 80032B00 0002F6E0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032B04 0002F6E4  DB E1 00 18 */	stfd f31, 0x18(r1)
    /* 80032B08 0002F6E8  FF E0 08 90 */	fmr f31, f1
    /* 80032B0C 0002F6EC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032B10 0002F6F0  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 80032B14 0002F6F4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032B18 0002F6F8  41 80 00 0C */	blt lbl_80032B24
    /* 80032B1C 0002F6FC  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032B20 0002F700  41 80 00 2C */	blt lbl_80032B4C
    lbl_80032B24:
    /* 80032B24 0002F704  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032B28 0002F708  4C C6 31 82 */	crclr 6
    /* 80032B2C 0002F70C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032B30 0002F710  38 9E 00 00 */	addi r4, r30, 0
    /* 80032B34 0002F714  48 31 2B 75 */	bl OSReport
    /* 80032B38 0002F718  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032B3C 0002F71C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032B40 0002F720  38 80 00 66 */	li r4, 0x66
    /* 80032B44 0002F724  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032B48 0002F728  48 35 56 D9 */	bl __assert
    lbl_80032B4C:
    /* 80032B4C 0002F72C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032B50 0002F730  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032B54 0002F734  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032B58 0002F738  7F E0 22 14 */	add r31, r0, r4
    /* 80032B5C 0002F73C  3B C0 00 00 */	li r30, 0
    lbl_80032B60:
    /* 80032B60 0002F740  D3 FF 00 40 */	stfs f31, 0x40(r31)
    /* 80032B64 0002F744  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80032B68 0002F748  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80032B6C 0002F74C  54 03 10 3A */	slwi r3, r0, 2
    /* 80032B70 0002F750  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032B74 0002F754  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80032B78 0002F758  28 03 00 00 */	cmplwi r3, 0
    /* 80032B7C 0002F75C  41 82 00 0C */	beq lbl_80032B88
    /* 80032B80 0002F760  FC 20 F8 90 */	fmr f1, f31
    /* 80032B84 0002F764  48 08 C0 F1 */	bl func_SetEntityFacingDirection
    lbl_80032B88:
    /* 80032B88 0002F768  3B DE 00 01 */	addi r30, r30, 1
    /* 80032B8C 0002F76C  2C 1E 00 02 */	cmpwi r30, 2
    /* 80032B90 0002F770  41 80 FF D0 */	blt lbl_80032B60
    /* 80032B94 0002F774  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032B98 0002F778  CB E1 00 18 */	lfd f31, 0x18(r1)
    /* 80032B9C 0002F77C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032BA0 0002F780  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80032BA4 0002F784  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032BA8 0002F788  7C 08 03 A6 */	mtlr r0
    /* 80032BAC 0002F78C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_80032BB0(s32 slot) {   ///https://decomp.me/scratch/ETbBe
    StaticPlayer* player;
    f32 temp;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    temp = func_800869F8(player->player_entity[player->transformed[0]]);
    return temp / player->model_scale;

}
#else
asm f32 Player_80032BB0(s32 slot)
{
    nofralloc
    /* 80032BB0 0002F790  7C 08 02 A6 */	mflr r0
    /* 80032BB4 0002F794  90 01 00 04 */	stw r0, 4(r1)
    /* 80032BB8 0002F798  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80032BBC 0002F79C  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032BC0 0002F7A0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032BC4 0002F7A4  41 80 00 0C */	blt lbl_80032BD0
    /* 80032BC8 0002F7A8  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032BCC 0002F7AC  41 80 00 2C */	blt lbl_80032BF8
    lbl_80032BD0:
    /* 80032BD0 0002F7B0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032BD4 0002F7B4  4C C6 31 82 */	crclr 6
    /* 80032BD8 0002F7B8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032BDC 0002F7BC  38 9F 00 00 */	addi r4, r31, 0
    /* 80032BE0 0002F7C0  48 31 2A C9 */	bl OSReport
    /* 80032BE4 0002F7C4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032BE8 0002F7C8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032BEC 0002F7CC  38 80 00 66 */	li r4, 0x66
    /* 80032BF0 0002F7D0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032BF4 0002F7D4  48 35 56 2D */	bl __assert
    lbl_80032BF8:
    /* 80032BF8 0002F7D8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032BFC 0002F7DC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032C00 0002F7E0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032C04 0002F7E4  7F E0 22 14 */	add r31, r0, r4
    /* 80032C08 0002F7E8  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032C0C 0002F7EC  54 00 10 3A */	slwi r0, r0, 2
    /* 80032C10 0002F7F0  7C 7F 02 14 */	add r3, r31, r0
    /* 80032C14 0002F7F4  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032C18 0002F7F8  48 05 3D E1 */	bl func_800869F8
    /* 80032C1C 0002F7FC  C0 1F 00 5C */	lfs f0, 0x5c(r31)
    /* 80032C20 0002F800  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80032C24 0002F804  EC 21 00 24 */	fdivs f1, f1, f0
    /* 80032C28 0002F808  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032C2C 0002F80C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80032C30 0002F810  7C 08 03 A6 */	mtlr r0
    /* 80032C34 0002F814  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetScale(s32 slot, f32 scale) {   ///https://decomp.me/scratch/8OwGv
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->model_scale = scale;
    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            ftData_SetScale(scale, player->player_entity[player->transformed[i]]);
        }
    }

}
#else
asm void Player_SetScale(s32 slot, f32 scale)
{
    nofralloc
    /* 80032C38 0002F818  7C 08 02 A6 */	mflr r0
    /* 80032C3C 0002F81C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032C40 0002F820  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032C44 0002F824  DB E1 00 18 */	stfd f31, 0x18(r1)
    /* 80032C48 0002F828  FF E0 08 90 */	fmr f31, f1
    /* 80032C4C 0002F82C  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032C50 0002F830  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 80032C54 0002F834  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032C58 0002F838  41 80 00 0C */	blt lbl_80032C64
    /* 80032C5C 0002F83C  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032C60 0002F840  41 80 00 2C */	blt lbl_80032C8C
    lbl_80032C64:
    /* 80032C64 0002F844  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032C68 0002F848  4C C6 31 82 */	crclr 6
    /* 80032C6C 0002F84C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032C70 0002F850  38 9E 00 00 */	addi r4, r30, 0
    /* 80032C74 0002F854  48 31 2A 35 */	bl OSReport
    /* 80032C78 0002F858  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032C7C 0002F85C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032C80 0002F860  38 80 00 66 */	li r4, 0x66
    /* 80032C84 0002F864  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032C88 0002F868  48 35 55 99 */	bl __assert
    lbl_80032C8C:
    /* 80032C8C 0002F86C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032C90 0002F870  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032C94 0002F874  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032C98 0002F878  7F E0 22 14 */	add r31, r0, r4
    /* 80032C9C 0002F87C  D3 FF 00 5C */	stfs f31, 0x5c(r31)
    /* 80032CA0 0002F880  3B C0 00 00 */	li r30, 0
    lbl_80032CA4:
    /* 80032CA4 0002F884  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80032CA8 0002F888  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80032CAC 0002F88C  54 03 10 3A */	slwi r3, r0, 2
    /* 80032CB0 0002F890  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032CB4 0002F894  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80032CB8 0002F898  28 03 00 00 */	cmplwi r3, 0
    /* 80032CBC 0002F89C  41 82 00 0C */	beq lbl_80032CC8
    /* 80032CC0 0002F8A0  FC 20 F8 90 */	fmr f1, f31
    /* 80032CC4 0002F8A4  48 05 39 E1 */	bl ftData_SetScale
    lbl_80032CC8:
    /* 80032CC8 0002F8A8  3B DE 00 01 */	addi r30, r30, 1
    /* 80032CCC 0002F8AC  2C 1E 00 02 */	cmpwi r30, 2
    /* 80032CD0 0002F8B0  41 80 FF D4 */	blt lbl_80032CA4
    /* 80032CD4 0002F8B4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032CD8 0002F8B8  CB E1 00 18 */	lfd f31, 0x18(r1)
    /* 80032CDC 0002F8BC  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032CE0 0002F8C0  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80032CE4 0002F8C4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032CE8 0002F8C8  7C 08 03 A6 */	mtlr r0
    /* 80032CEC 0002F8CC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_GetSpawnPlatformPos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/dQVrr
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    *arg_vec = player->player_poses.byVecName.spawn_platform_final_pos;
}
#else
asm void Player_GetSpawnPlatformPos(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 80032CF0 0002F8D0  7C 08 02 A6 */	mflr r0
    /* 80032CF4 0002F8D4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032CF8 0002F8D8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032CFC 0002F8DC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032D00 0002F8E0  3B E4 00 00 */	addi r31, r4, 0
    /* 80032D04 0002F8E4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032D08 0002F8E8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032D0C 0002F8EC  41 80 00 0C */	blt lbl_80032D18
    /* 80032D10 0002F8F0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032D14 0002F8F4  41 80 00 2C */	blt lbl_80032D40
    lbl_80032D18:
    /* 80032D18 0002F8F8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032D1C 0002F8FC  4C C6 31 82 */	crclr 6
    /* 80032D20 0002F900  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032D24 0002F904  38 9E 00 00 */	addi r4, r30, 0
    /* 80032D28 0002F908  48 31 29 81 */	bl OSReport
    /* 80032D2C 0002F90C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032D30 0002F910  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032D34 0002F914  38 80 00 66 */	li r4, 0x66
    /* 80032D38 0002F918  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032D3C 0002F91C  48 35 54 E5 */	bl __assert
    lbl_80032D40:
    /* 80032D40 0002F920  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032D44 0002F924  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032D48 0002F928  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032D4C 0002F92C  7C 80 22 14 */	add r4, r0, r4
    /* 80032D50 0002F930  80 64 00 28 */	lwz r3, 0x28(r4)
    /* 80032D54 0002F934  80 04 00 2C */	lwz r0, 0x2c(r4)
    /* 80032D58 0002F938  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032D5C 0002F93C  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032D60 0002F940  80 04 00 30 */	lwz r0, 0x30(r4)
    /* 80032D64 0002F944  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032D68 0002F948  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032D6C 0002F94C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032D70 0002F950  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032D74 0002F954  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032D78 0002F958  7C 08 03 A6 */	mtlr r0
    /* 80032D7C 0002F95C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetSpawnPlatformPos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/XNLqe
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_poses.byVecName.spawn_platform_final_pos = *arg_vec;
}
#else
asm void Player_SetSpawnPlatformPos(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032D80 0002F960  7C 08 02 A6 */	mflr r0
    /* 80032D84 0002F964  90 01 00 04 */	stw r0, 4(r1)
    /* 80032D88 0002F968  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032D8C 0002F96C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032D90 0002F970  3B E4 00 00 */	addi r31, r4, 0
    /* 80032D94 0002F974  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032D98 0002F978  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032D9C 0002F97C  41 80 00 0C */	blt lbl_80032DA8
    /* 80032DA0 0002F980  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032DA4 0002F984  41 80 00 2C */	blt lbl_80032DD0
    lbl_80032DA8:
    /* 80032DA8 0002F988  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032DAC 0002F98C  4C C6 31 82 */	crclr 6
    /* 80032DB0 0002F990  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032DB4 0002F994  38 9E 00 00 */	addi r4, r30, 0
    /* 80032DB8 0002F998  48 31 28 F1 */	bl OSReport
    /* 80032DBC 0002F99C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032DC0 0002F9A0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032DC4 0002F9A4  38 80 00 66 */	li r4, 0x66
    /* 80032DC8 0002F9A8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032DCC 0002F9AC  48 35 54 55 */	bl __assert
    lbl_80032DD0:
    /* 80032DD0 0002F9B0  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 80032DD4 0002F9B4  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032DD8 0002F9B8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032DDC 0002F9BC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032DE0 0002F9C0  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032DE4 0002F9C4  7C 84 2A 14 */	add r4, r4, r5
    /* 80032DE8 0002F9C8  90 64 00 28 */	stw r3, 0x28(r4)
    /* 80032DEC 0002F9CC  90 04 00 2C */	stw r0, 0x2c(r4)
    /* 80032DF0 0002F9D0  80 1F 00 08 */	lwz r0, 8(r31)
    /* 80032DF4 0002F9D4  90 04 00 30 */	stw r0, 0x30(r4)
    /* 80032DF8 0002F9D8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032DFC 0002F9DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032E00 0002F9E0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032E04 0002F9E4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032E08 0002F9E8  7C 08 03 A6 */	mtlr r0
    /* 80032E0C 0002F9EC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_GetSomePos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/S1eUX
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    *arg_vec = player->player_poses.byVecName.some_other_player_pos;
}
#else
asm void Player_GetSomePos(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 80032E10 0002F9F0  7C 08 02 A6 */	mflr r0
    /* 80032E14 0002F9F4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032E18 0002F9F8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032E1C 0002F9FC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032E20 0002FA00  3B E4 00 00 */	addi r31, r4, 0
    /* 80032E24 0002FA04  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032E28 0002FA08  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032E2C 0002FA0C  41 80 00 0C */	blt lbl_80032E38
    /* 80032E30 0002FA10  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032E34 0002FA14  41 80 00 2C */	blt lbl_80032E60
    lbl_80032E38:
    /* 80032E38 0002FA18  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032E3C 0002FA1C  4C C6 31 82 */	crclr 6
    /* 80032E40 0002FA20  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032E44 0002FA24  38 9E 00 00 */	addi r4, r30, 0
    /* 80032E48 0002FA28  48 31 28 61 */	bl OSReport
    /* 80032E4C 0002FA2C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032E50 0002FA30  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032E54 0002FA34  38 80 00 66 */	li r4, 0x66
    /* 80032E58 0002FA38  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032E5C 0002FA3C  48 35 53 C5 */	bl __assert
    lbl_80032E60:
    /* 80032E60 0002FA40  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032E64 0002FA44  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032E68 0002FA48  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032E6C 0002FA4C  7C 80 22 14 */	add r4, r0, r4
    /* 80032E70 0002FA50  80 64 00 34 */	lwz r3, 0x34(r4)
    /* 80032E74 0002FA54  80 04 00 38 */	lwz r0, 0x38(r4)
    /* 80032E78 0002FA58  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032E7C 0002FA5C  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032E80 0002FA60  80 04 00 3C */	lwz r0, 0x3c(r4)
    /* 80032E84 0002FA64  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032E88 0002FA68  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032E8C 0002FA6C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032E90 0002FA70  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032E94 0002FA74  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032E98 0002FA78  7C 08 03 A6 */	mtlr r0
    /* 80032E9C 0002FA7C  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
void Player_SetSomePos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/p2H7B
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_poses.byVecName.some_other_player_pos = *arg_vec;
}
#else
asm void Player_SetSomePos(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032EA0 0002FA80  7C 08 02 A6 */	mflr r0
    /* 80032EA4 0002FA84  90 01 00 04 */	stw r0, 4(r1)
    /* 80032EA8 0002FA88  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032EAC 0002FA8C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032EB0 0002FA90  3B E4 00 00 */	addi r31, r4, 0
    /* 80032EB4 0002FA94  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032EB8 0002FA98  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032EBC 0002FA9C  41 80 00 0C */	blt lbl_80032EC8
    /* 80032EC0 0002FAA0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032EC4 0002FAA4  41 80 00 2C */	blt lbl_80032EF0
    lbl_80032EC8:
    /* 80032EC8 0002FAA8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032ECC 0002FAAC  4C C6 31 82 */	crclr 6
    /* 80032ED0 0002FAB0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032ED4 0002FAB4  38 9E 00 00 */	addi r4, r30, 0
    /* 80032ED8 0002FAB8  48 31 27 D1 */	bl OSReport
    /* 80032EDC 0002FABC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032EE0 0002FAC0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032EE4 0002FAC4  38 80 00 66 */	li r4, 0x66
    /* 80032EE8 0002FAC8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032EEC 0002FACC  48 35 53 35 */	bl __assert
    lbl_80032EF0:
    /* 80032EF0 0002FAD0  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 80032EF4 0002FAD4  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032EF8 0002FAD8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032EFC 0002FADC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032F00 0002FAE0  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032F04 0002FAE4  7C 84 2A 14 */	add r4, r4, r5
    /* 80032F08 0002FAE8  90 64 00 34 */	stw r3, 0x34(r4)
    /* 80032F0C 0002FAEC  90 04 00 38 */	stw r0, 0x38(r4)
    /* 80032F10 0002FAF0  80 1F 00 08 */	lwz r0, 8(r31)
    /* 80032F14 0002FAF4  90 04 00 3C */	stw r0, 0x3c(r4)
    /* 80032F18 0002FAF8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032F1C 0002FAFC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032F20 0002FB00  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032F24 0002FB04  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032F28 0002FB08  7C 08 03 A6 */	mtlr r0
    /* 80032F2C 0002FB0C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80032F30(s32 slot) { ///https://decomp.me/scratch/CL76t
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    value = player->unk4E;
    return value;
}
#else
asm s32 Player_80032F30(s32 slot)
{
    nofralloc
    /* 80032F30 0002FB10  7C 08 02 A6 */	mflr r0
    /* 80032F34 0002FB14  90 01 00 04 */	stw r0, 4(r1)
    /* 80032F38 0002FB18  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032F3C 0002FB1C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032F40 0002FB20  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032F44 0002FB24  41 80 00 0C */	blt lbl_80032F50
    /* 80032F48 0002FB28  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032F4C 0002FB2C  41 80 00 2C */	blt lbl_80032F78
    lbl_80032F50:
    /* 80032F50 0002FB30  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032F54 0002FB34  4C C6 31 82 */	crclr 6
    /* 80032F58 0002FB38  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032F5C 0002FB3C  38 9F 00 00 */	addi r4, r31, 0
    /* 80032F60 0002FB40  48 31 27 49 */	bl OSReport
    /* 80032F64 0002FB44  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032F68 0002FB48  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032F6C 0002FB4C  38 80 00 66 */	li r4, 0x66
    /* 80032F70 0002FB50  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032F74 0002FB54  48 35 52 AD */	bl __assert
    lbl_80032F78:
    /* 80032F78 0002FB58  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032F7C 0002FB5C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032F80 0002FB60  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032F84 0002FB64  7C 60 22 14 */	add r3, r0, r4
    /* 80032F88 0002FB68  88 63 00 4E */	lbz r3, 0x4e(r3)
    /* 80032F8C 0002FB6C  7C 63 07 74 */	extsb r3, r3
    /* 80032F90 0002FB70  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032F94 0002FB74  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032F98 0002FB78  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032F9C 0002FB7C  7C 08 03 A6 */	mtlr r0
    /* 80032FA0 0002FB80  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_80032FA4(s32 slot, s32 arg) {  ///https://decomp.me/scratch/MHqlV
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk4E = arg;
}
#else
asm void Player_80032FA4(s32 slot, s32 arg) 
{
    nofralloc
    /* 80032FA4 0002FB84  7C 08 02 A6 */	mflr r0
    /* 80032FA8 0002FB88  90 01 00 04 */	stw r0, 4(r1)
    /* 80032FAC 0002FB8C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032FB0 0002FB90  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032FB4 0002FB94  3B E4 00 00 */	addi r31, r4, 0
    /* 80032FB8 0002FB98  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032FBC 0002FB9C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032FC0 0002FBA0  41 80 00 0C */	blt lbl_80032FCC
    /* 80032FC4 0002FBA4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032FC8 0002FBA8  41 80 00 2C */	blt lbl_80032FF4
    lbl_80032FCC:
    /* 80032FCC 0002FBAC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032FD0 0002FBB0  4C C6 31 82 */	crclr 6
    /* 80032FD4 0002FBB4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032FD8 0002FBB8  38 9E 00 00 */	addi r4, r30, 0
    /* 80032FDC 0002FBBC  48 31 26 CD */	bl OSReport
    /* 80032FE0 0002FBC0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032FE4 0002FBC4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032FE8 0002FBC8  38 80 00 66 */	li r4, 0x66
    /* 80032FEC 0002FBCC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032FF0 0002FBD0  48 35 52 31 */	bl __assert
    lbl_80032FF4:
    /* 80032FF4 0002FBD4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032FF8 0002FBD8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032FFC 0002FBDC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033000 0002FBE0  7F E5 07 74 */	extsb r5, r31
    /* 80033004 0002FBE4  7C 60 22 14 */	add r3, r0, r4
    /* 80033008 0002FBE8  98 A3 00 4E */	stb r5, 0x4e(r3)
    /* 8003300C 0002FBEC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033010 0002FBF0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033014 0002FBF4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033018 0002FBF8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003301C 0002FBFC  7C 08 03 A6 */	mtlr r0
    /* 80033020 0002FC00  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
f32 Player_GetFacingDirection(s32 slot) {   ///https://decomp.me/scratch/HNZ62
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->facing_direction;
}
#else
asm f32 Player_GetFacingDirection(s32 slot)
{
    nofralloc
    /* 80033024 0002FC04  7C 08 02 A6 */	mflr r0
    /* 80033028 0002FC08  90 01 00 04 */	stw r0, 4(r1)
    /* 8003302C 0002FC0C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033030 0002FC10  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033034 0002FC14  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033038 0002FC18  41 80 00 0C */	blt lbl_80033044
    /* 8003303C 0002FC1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033040 0002FC20  41 80 00 2C */	blt lbl_8003306C
    lbl_80033044:
    /* 80033044 0002FC24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033048 0002FC28  4C C6 31 82 */	crclr 6
    /* 8003304C 0002FC2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033050 0002FC30  38 9F 00 00 */	addi r4, r31, 0
    /* 80033054 0002FC34  48 31 26 55 */	bl OSReport
    /* 80033058 0002FC38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003305C 0002FC3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033060 0002FC40  38 80 00 66 */	li r4, 0x66
    /* 80033064 0002FC44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033068 0002FC48  48 35 51 B9 */	bl __assert
    lbl_8003306C:
    /* 8003306C 0002FC4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033070 0002FC50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033074 0002FC54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033078 0002FC58  7C 60 22 14 */	add r3, r0, r4
    /* 8003307C 0002FC5C  C0 23 00 40 */	lfs f1, 0x40(r3)
    /* 80033080 0002FC60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033084 0002FC64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033088 0002FC68  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003308C 0002FC6C  7C 08 03 A6 */	mtlr r0
    /* 80033090 0002FC70  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFacingDirection(s32 slot, f32 direction) {  ///https://decomp.me/scratch/A84ci
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->facing_direction = direction;
}
#else
asm void Player_SetFacingDirection(s32 slot, f32 direction)
{
    nofralloc
    /* 80033094 0002FC74  7C 08 02 A6 */	mflr r0
    /* 80033098 0002FC78  90 01 00 04 */	stw r0, 4(r1)
    /* 8003309C 0002FC7C  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 800330A0 0002FC80  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 800330A4 0002FC84  FF E0 08 90 */	fmr f31, f1
    /* 800330A8 0002FC88  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800330AC 0002FC8C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800330B0 0002FC90  41 80 00 0C */	blt lbl_800330BC
    /* 800330B4 0002FC94  2C 1F 00 06 */	cmpwi r31, 6
    /* 800330B8 0002FC98  41 80 00 2C */	blt lbl_800330E4
    lbl_800330BC:
    /* 800330BC 0002FC9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800330C0 0002FCA0  4C C6 31 82 */	crclr 6
    /* 800330C4 0002FCA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800330C8 0002FCA8  38 9F 00 00 */	addi r4, r31, 0
    /* 800330CC 0002FCAC  48 31 25 DD */	bl OSReport
    /* 800330D0 0002FCB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800330D4 0002FCB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800330D8 0002FCB8  38 80 00 66 */	li r4, 0x66
    /* 800330DC 0002FCBC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800330E0 0002FCC0  48 35 51 41 */	bl __assert
    lbl_800330E4:
    /* 800330E4 0002FCC4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800330E8 0002FCC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800330EC 0002FCCC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800330F0 0002FCD0  7C 60 22 14 */	add r3, r0, r4
    /* 800330F4 0002FCD4  D3 E3 00 40 */	stfs f31, 0x40(r3)
    /* 800330F8 0002FCD8  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800330FC 0002FCDC  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033100 0002FCE0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033104 0002FCE4  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033108 0002FCE8  7C 08 03 A6 */	mtlr r0
    /* 8003310C 0002FCEC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFacingDirectionConditional(s32 slot, BOOL b, f32 direction) {  ///https://decomp.me/scratch/S2NKb
    StaticPlayer* player;
    s32 unused;
    if (!b) {
        Player_CheckSlot(slot);
        player = &player_slots[slot];
        player->facing_direction = direction;
    }
}
#else
asm void Player_SetFacingDirectionConditional(s32 slot, BOOL b, f32 direction)
{
    nofralloc
    /* 80033110 0002FCF0  7C 08 02 A6 */	mflr r0
    /* 80033114 0002FCF4  2C 04 00 00 */	cmpwi r4, 0
    /* 80033118 0002FCF8  90 01 00 04 */	stw r0, 4(r1)
    /* 8003311C 0002FCFC  94 21 FF D0 */	stwu r1, -0x30(r1)
    /* 80033120 0002FD00  DB E1 00 28 */	stfd f31, 0x28(r1)
    /* 80033124 0002FD04  FF E0 08 90 */	fmr f31, f1
    /* 80033128 0002FD08  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 8003312C 0002FD0C  3B E3 00 00 */	addi r31, r3, 0
    /* 80033130 0002FD10  40 82 00 50 */	bne lbl_80033180
    /* 80033134 0002FD14  2C 1F 00 00 */	cmpwi r31, 0
    /* 80033138 0002FD18  41 80 00 0C */	blt lbl_80033144
    /* 8003313C 0002FD1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033140 0002FD20  41 80 00 2C */	blt lbl_8003316C
    lbl_80033144:
    /* 80033144 0002FD24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033148 0002FD28  4C C6 31 82 */	crclr 6
    /* 8003314C 0002FD2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033150 0002FD30  38 9F 00 00 */	addi r4, r31, 0
    /* 80033154 0002FD34  48 31 25 55 */	bl OSReport
    /* 80033158 0002FD38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003315C 0002FD3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033160 0002FD40  38 80 00 66 */	li r4, 0x66
    /* 80033164 0002FD44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033168 0002FD48  48 35 50 B9 */	bl __assert
    lbl_8003316C:
    /* 8003316C 0002FD4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033170 0002FD50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033174 0002FD54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033178 0002FD58  7C 60 22 14 */	add r3, r0, r4
    /* 8003317C 0002FD5C  D3 E3 00 40 */	stfs f31, 0x40(r3)
    lbl_80033180:
    /* 80033180 0002FD60  80 01 00 34 */	lwz r0, 0x34(r1)
    /* 80033184 0002FD64  CB E1 00 28 */	lfd f31, 0x28(r1)
    /* 80033188 0002FD68  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 8003318C 0002FD6C  38 21 00 30 */	addi r1, r1, 0x30
    /* 80033190 0002FD70  7C 08 03 A6 */	mtlr r0
    /* 80033194 0002FD74  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetCostumeId(s32 slot) {   ///https://decomp.me/scratch/MFT7R
    s8 costume_id;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    costume_id = player->costume_id;
    return costume_id;
}
#else
asm s8 Player_GetCostumeId(s32 slot)
{
    nofralloc
    /* 80033198 0002FD78  7C 08 02 A6 */	mflr r0
    /* 8003319C 0002FD7C  90 01 00 04 */	stw r0, 4(r1)
    /* 800331A0 0002FD80  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800331A4 0002FD84  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800331A8 0002FD88  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800331AC 0002FD8C  41 80 00 0C */	blt lbl_800331B8
    /* 800331B0 0002FD90  2C 1F 00 06 */	cmpwi r31, 6
    /* 800331B4 0002FD94  41 80 00 2C */	blt lbl_800331E0
    lbl_800331B8:
    /* 800331B8 0002FD98  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800331BC 0002FD9C  4C C6 31 82 */	crclr 6
    /* 800331C0 0002FDA0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800331C4 0002FDA4  38 9F 00 00 */	addi r4, r31, 0
    /* 800331C8 0002FDA8  48 31 24 E1 */	bl OSReport
    /* 800331CC 0002FDAC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800331D0 0002FDB0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800331D4 0002FDB4  38 80 00 66 */	li r4, 0x66
    /* 800331D8 0002FDB8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800331DC 0002FDBC  48 35 50 45 */	bl __assert
    lbl_800331E0:
    /* 800331E0 0002FDC0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800331E4 0002FDC4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800331E8 0002FDC8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800331EC 0002FDCC  7C 60 22 14 */	add r3, r0, r4
    /* 800331F0 0002FDD0  88 63 00 44 */	lbz r3, 0x44(r3)
    /* 800331F4 0002FDD4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800331F8 0002FDD8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800331FC 0002FDDC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033200 0002FDE0  7C 08 03 A6 */	mtlr r0
    /* 80033204 0002FDE4  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
void Player_SetCostumeId(s32 slot, s8 costume_id) {  //https://decomp.me/scratch/u3A1u
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->costume_id = costume_id;
}
#else
asm void Player_SetCostumeId(s32 slot, s8 costume_id)
{
    nofralloc
    /* 80033208 0002FDE8  7C 08 02 A6 */	mflr r0
    /* 8003320C 0002FDEC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033210 0002FDF0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033214 0002FDF4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033218 0002FDF8  3B E4 00 00 */	addi r31, r4, 0
    /* 8003321C 0002FDFC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033220 0002FE00  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033224 0002FE04  41 80 00 0C */	blt lbl_80033230
    /* 80033228 0002FE08  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003322C 0002FE0C  41 80 00 2C */	blt lbl_80033258
    lbl_80033230:
    /* 80033230 0002FE10  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033234 0002FE14  4C C6 31 82 */	crclr 6
    /* 80033238 0002FE18  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003323C 0002FE1C  38 9E 00 00 */	addi r4, r30, 0
    /* 80033240 0002FE20  48 31 24 69 */	bl OSReport
    /* 80033244 0002FE24  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033248 0002FE28  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003324C 0002FE2C  38 80 00 66 */	li r4, 0x66
    /* 80033250 0002FE30  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033254 0002FE34  48 35 4F CD */	bl __assert
    lbl_80033258:
    /* 80033258 0002FE38  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003325C 0002FE3C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033260 0002FE40  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033264 0002FE44  7C 60 22 14 */	add r3, r0, r4
    /* 80033268 0002FE48  9B E3 00 44 */	stb r31, 0x44(r3)
    /* 8003326C 0002FE4C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033270 0002FE50  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033274 0002FE54  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033278 0002FE58  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003327C 0002FE5C  7C 08 03 A6 */	mtlr r0
    /* 80033280 0002FE60  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetControllerIndex(s32 slot) {   ///https://decomp.me/scratch/Y9hg1
    s8 controller_index;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    controller_index = player->controller_index;
    return controller_index;
}
#else
asm s8 Player_GetControllerIndex(s32 slot) 
{
    nofralloc
    /* 80033284 0002FE64  7C 08 02 A6 */	mflr r0
    /* 80033288 0002FE68  90 01 00 04 */	stw r0, 4(r1)
    /* 8003328C 0002FE6C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033290 0002FE70  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033294 0002FE74  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033298 0002FE78  41 80 00 0C */	blt lbl_800332A4
    /* 8003329C 0002FE7C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800332A0 0002FE80  41 80 00 2C */	blt lbl_800332CC
    lbl_800332A4:
    /* 800332A4 0002FE84  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800332A8 0002FE88  4C C6 31 82 */	crclr 6
    /* 800332AC 0002FE8C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800332B0 0002FE90  38 9F 00 00 */	addi r4, r31, 0
    /* 800332B4 0002FE94  48 31 23 F5 */	bl OSReport
    /* 800332B8 0002FE98  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800332BC 0002FE9C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800332C0 0002FEA0  38 80 00 66 */	li r4, 0x66
    /* 800332C4 0002FEA4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800332C8 0002FEA8  48 35 4F 59 */	bl __assert
    lbl_800332CC:
    /* 800332CC 0002FEAC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800332D0 0002FEB0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800332D4 0002FEB4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800332D8 0002FEB8  7C 60 22 14 */	add r3, r0, r4
    /* 800332DC 0002FEBC  88 63 00 46 */	lbz r3, 0x46(r3)
    /* 800332E0 0002FEC0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800332E4 0002FEC4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800332E8 0002FEC8  38 21 00 20 */	addi r1, r1, 0x20
    /* 800332EC 0002FECC  7C 08 03 A6 */	mtlr r0
    /* 800332F0 0002FED0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetControllerIndex(s32 slot, s8 controller_index) {    //https://decomp.me/scratch/mUnD7
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->controller_index = controller_index;
}
#else
asm void Player_SetControllerIndex(s32 slot, s8 controller_index)
{
    nofralloc
    /* 800332F4 0002FED4  7C 08 02 A6 */	mflr r0
    /* 800332F8 0002FED8  90 01 00 04 */	stw r0, 4(r1)
    /* 800332FC 0002FEDC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033300 0002FEE0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033304 0002FEE4  3B E4 00 00 */	addi r31, r4, 0
    /* 80033308 0002FEE8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 8003330C 0002FEEC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033310 0002FEF0  41 80 00 0C */	blt lbl_8003331C
    /* 80033314 0002FEF4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033318 0002FEF8  41 80 00 2C */	blt lbl_80033344
    lbl_8003331C:
    /* 8003331C 0002FEFC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033320 0002FF00  4C C6 31 82 */	crclr 6
    /* 80033324 0002FF04  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033328 0002FF08  38 9E 00 00 */	addi r4, r30, 0
    /* 8003332C 0002FF0C  48 31 23 7D */	bl OSReport
    /* 80033330 0002FF10  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033334 0002FF14  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033338 0002FF18  38 80 00 66 */	li r4, 0x66
    /* 8003333C 0002FF1C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033340 0002FF20  48 35 4E E1 */	bl __assert
    lbl_80033344:
    /* 80033344 0002FF24  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033348 0002FF28  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003334C 0002FF2C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033350 0002FF30  7C 60 22 14 */	add r3, r0, r4
    /* 80033354 0002FF34  9B E3 00 46 */	stb r31, 0x46(r3)
    /* 80033358 0002FF38  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003335C 0002FF3C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033360 0002FF40  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033364 0002FF44  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033368 0002FF48  7C 08 03 A6 */	mtlr r0
    /* 8003336C 0002FF4C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetUnkColor(s32 slot) {  //https://decomp.me/scratch/xd5Nw
    s8 unk_color;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk_color = player->unk_color;
    return unk_color;
}
#else
asm s8 Player_GetUnkColor(s32 slot)
{
    nofralloc
    /* 80033370 0002FF50  7C 08 02 A6 */	mflr r0
    /* 80033374 0002FF54  90 01 00 04 */	stw r0, 4(r1)
    /* 80033378 0002FF58  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003337C 0002FF5C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033380 0002FF60  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033384 0002FF64  41 80 00 0C */	blt lbl_80033390
    /* 80033388 0002FF68  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003338C 0002FF6C  41 80 00 2C */	blt lbl_800333B8
    lbl_80033390:
    /* 80033390 0002FF70  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033394 0002FF74  4C C6 31 82 */	crclr 6
    /* 80033398 0002FF78  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003339C 0002FF7C  38 9F 00 00 */	addi r4, r31, 0
    /* 800333A0 0002FF80  48 31 23 09 */	bl OSReport
    /* 800333A4 0002FF84  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800333A8 0002FF88  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800333AC 0002FF8C  38 80 00 66 */	li r4, 0x66
    /* 800333B0 0002FF90  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800333B4 0002FF94  48 35 4E 6D */	bl __assert
    lbl_800333B8:
    /* 800333B8 0002FF98  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800333BC 0002FF9C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800333C0 0002FFA0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800333C4 0002FFA4  7C 60 22 14 */	add r3, r0, r4
    /* 800333C8 0002FFA8  88 63 00 47 */	lbz r3, 0x47(r3)
    /* 800333CC 0002FFAC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800333D0 0002FFB0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800333D4 0002FFB4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800333D8 0002FFB8  7C 08 03 A6 */	mtlr r0
    /* 800333DC 0002FFBC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetUnkColor(s32 slot, s8 unk_color) {   //https://decomp.me/scratch/sgRAy
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk_color = unk_color;
}
#else
asm void Player_SetUnkColor(s32 slot, s8 unk_color)
{
    nofralloc
    /* 800333E0 0002FFC0  7C 08 02 A6 */	mflr r0
    /* 800333E4 0002FFC4  90 01 00 04 */	stw r0, 4(r1)
    /* 800333E8 0002FFC8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800333EC 0002FFCC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800333F0 0002FFD0  3B E4 00 00 */	addi r31, r4, 0
    /* 800333F4 0002FFD4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800333F8 0002FFD8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800333FC 0002FFDC  41 80 00 0C */	blt lbl_80033408
    /* 80033400 0002FFE0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033404 0002FFE4  41 80 00 2C */	blt lbl_80033430
    lbl_80033408:
    /* 80033408 0002FFE8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003340C 0002FFEC  4C C6 31 82 */	crclr 6
    /* 80033410 0002FFF0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033414 0002FFF4  38 9E 00 00 */	addi r4, r30, 0
    /* 80033418 0002FFF8  48 31 22 91 */	bl OSReport
    /* 8003341C 0002FFFC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033420 00030000  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033424 00030004  38 80 00 66 */	li r4, 0x66
    /* 80033428 00030008  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003342C 0003000C  48 35 4D F5 */	bl __assert
    lbl_80033430:
    /* 80033430 00030010  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033434 00030014  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033438 00030018  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003343C 0003001C  7C 60 22 14 */	add r3, r0, r4
    /* 80033440 00030020  9B E3 00 47 */	stb r31, 0x47(r3)
    /* 80033444 00030024  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033448 00030028  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003344C 0003002C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033450 00030030  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033454 00030034  7C 08 03 A6 */	mtlr r0
    /* 80033458 00030038  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s8 Player_GetPlayerId(s32 slot) {  //https://decomp.me/scratch/XYjDY
    s8 player_id;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player_id = player->player_id;
    return player_id;
}
#else
asm s8 Player_GetPlayerId(s32 slot)
{
    nofralloc
    /* 8003345C 0003003C  7C 08 02 A6 */	mflr r0
    /* 80033460 00030040  90 01 00 04 */	stw r0, 4(r1)
    /* 80033464 00030044  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033468 00030048  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003346C 0003004C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033470 00030050  41 80 00 0C */	blt lbl_8003347C
    /* 80033474 00030054  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033478 00030058  41 80 00 2C */	blt lbl_800334A4
    lbl_8003347C:
    /* 8003347C 0003005C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033480 00030060  4C C6 31 82 */	crclr 6
    /* 80033484 00030064  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033488 00030068  38 9F 00 00 */	addi r4, r31, 0
    /* 8003348C 0003006C  48 31 22 1D */	bl OSReport
    /* 80033490 00030070  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033494 00030074  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033498 00030078  38 80 00 66 */	li r4, 0x66
    /* 8003349C 0003007C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800334A0 00030080  48 35 4D 81 */	bl __assert
    lbl_800334A4:
    /* 800334A4 00030084  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800334A8 00030088  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800334AC 0003008C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800334B0 00030090  7C 60 22 14 */	add r3, r0, r4
    /* 800334B4 00030094  88 63 00 48 */	lbz r3, 0x48(r3)
    /* 800334B8 00030098  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800334BC 0003009C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800334C0 000300A0  38 21 00 20 */	addi r1, r1, 0x20
    /* 800334C4 000300A4  7C 08 03 A6 */	mtlr r0
    /* 800334C8 000300A8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerId(s32 slot, s8 player_id) {  ///https://decomp.me/scratch/uC164
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_id = player_id;
}
#else
asm void Player_SetPlayerId(s32 slot, s8 player_id)
{
    nofralloc
    /* 800334CC 000300AC  7C 08 02 A6 */	mflr r0
    /* 800334D0 000300B0  90 01 00 04 */	stw r0, 4(r1)
    /* 800334D4 000300B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800334D8 000300B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800334DC 000300BC  3B E4 00 00 */	addi r31, r4, 0
    /* 800334E0 000300C0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800334E4 000300C4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800334E8 000300C8  41 80 00 0C */	blt lbl_800334F4
    /* 800334EC 000300CC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800334F0 000300D0  41 80 00 2C */	blt lbl_8003351C
    lbl_800334F4:
    /* 800334F4 000300D4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800334F8 000300D8  4C C6 31 82 */	crclr 6
    /* 800334FC 000300DC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033500 000300E0  38 9E 00 00 */	addi r4, r30, 0
    /* 80033504 000300E4  48 31 21 A5 */	bl OSReport
    /* 80033508 000300E8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003350C 000300EC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033510 000300F0  38 80 00 66 */	li r4, 0x66
    /* 80033514 000300F4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033518 000300F8  48 35 4D 09 */	bl __assert
    lbl_8003351C:
    /* 8003351C 000300FC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033520 00030100  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033524 00030104  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033528 00030108  7C 60 22 14 */	add r3, r0, r4
    /* 8003352C 0003010C  9B E3 00 48 */	stb r31, 0x48(r3)
    /* 80033530 00030110  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033534 00030114  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033538 00030118  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003353C 0003011C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033540 00030120  7C 08 03 A6 */	mtlr r0
    /* 80033544 00030124  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s8 Player_GetCpuLevel(s32 slot) {    ///https://decomp.me/scratch/qHsUw
    s8 cpu_level;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    cpu_level = player->cpu_level;
    return cpu_level;
}
#else
asm s8 Player_GetCpuLevel(s32 slot)
{
    nofralloc
    /* 80033548 00030128  7C 08 02 A6 */	mflr r0
    /* 8003354C 0003012C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033550 00030130  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033554 00030134  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033558 00030138  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003355C 0003013C  41 80 00 0C */	blt lbl_80033568
    /* 80033560 00030140  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033564 00030144  41 80 00 2C */	blt lbl_80033590
    lbl_80033568:
    /* 80033568 00030148  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003356C 0003014C  4C C6 31 82 */	crclr 6
    /* 80033570 00030150  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033574 00030154  38 9F 00 00 */	addi r4, r31, 0
    /* 80033578 00030158  48 31 21 31 */	bl OSReport
    /* 8003357C 0003015C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033580 00030160  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033584 00030164  38 80 00 66 */	li r4, 0x66
    /* 80033588 00030168  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003358C 0003016C  48 35 4C 95 */	bl __assert
    lbl_80033590:
    /* 80033590 00030170  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033594 00030174  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033598 00030178  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003359C 0003017C  7C 60 22 14 */	add r3, r0, r4
    /* 800335A0 00030180  88 63 00 49 */	lbz r3, 0x49(r3)
    /* 800335A4 00030184  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800335A8 00030188  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800335AC 0003018C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800335B0 00030190  7C 08 03 A6 */	mtlr r0
    /* 800335B4 00030194  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetPlayerAndEntityCpuLevel(s32 slot, s8 cpu_level) {   /////https://decomp.me/scratch/yPZB6
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->cpu_level = cpu_level;
    for (i = 0; i < 2; i++){
        if (player->player_entity[player->transformed[i]]) {
            func_80087BEC(player->player_entity[player->transformed[i]], cpu_level);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityCpuLevel(s32 slot, s8 cpu_level)
{
    nofralloc
    /* 800335B8 00030198  7C 08 02 A6 */	mflr r0
    /* 800335BC 0003019C  90 01 00 04 */	stw r0, 4(r1)
    /* 800335C0 000301A0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800335C4 000301A4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800335C8 000301A8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800335CC 000301AC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800335D0 000301B0  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 800335D4 000301B4  3B A4 00 00 */	addi r29, r4, 0
    /* 800335D8 000301B8  41 80 00 0C */	blt lbl_800335E4
    /* 800335DC 000301BC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800335E0 000301C0  41 80 00 2C */	blt lbl_8003360C
    lbl_800335E4:
    /* 800335E4 000301C4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800335E8 000301C8  4C C6 31 82 */	crclr 6
    /* 800335EC 000301CC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800335F0 000301D0  38 9E 00 00 */	addi r4, r30, 0
    /* 800335F4 000301D4  48 31 20 B5 */	bl OSReport
    /* 800335F8 000301D8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800335FC 000301DC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033600 000301E0  38 80 00 66 */	li r4, 0x66
    /* 80033604 000301E4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033608 000301E8  48 35 4C 19 */	bl __assert
    lbl_8003360C:
    /* 8003360C 000301EC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033610 000301F0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033614 000301F4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033618 000301F8  7F E0 22 14 */	add r31, r0, r4
    /* 8003361C 000301FC  9B BF 00 49 */	stb r29, 0x49(r31)
    /* 80033620 00030200  3B C0 00 00 */	li r30, 0
    lbl_80033624:
    /* 80033624 00030204  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80033628 00030208  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 8003362C 0003020C  54 03 10 3A */	slwi r3, r0, 2
    /* 80033630 00030210  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80033634 00030214  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80033638 00030218  28 03 00 00 */	cmplwi r3, 0
    /* 8003363C 0003021C  41 82 00 0C */	beq lbl_80033648
    /* 80033640 00030220  7F A4 EB 78 */	mr r4, r29
    /* 80033644 00030224  48 05 45 A9 */	bl func_80087BEC
    lbl_80033648:
    /* 80033648 00030228  3B DE 00 01 */	addi r30, r30, 1
    /* 8003364C 0003022C  2C 1E 00 02 */	cmpwi r30, 2
    /* 80033650 00030230  41 80 FF D4 */	blt lbl_80033624
    /* 80033654 00030234  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033658 00030238  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003365C 0003023C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033660 00030240  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80033664 00030244  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033668 00030248  7C 08 03 A6 */	mtlr r0
    /* 8003366C 0003024C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetCpuType(s32 slot) {   ///https://decomp.me/scratch/AD23P
    s8 cpu_type;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    cpu_type = player->cpu_type;
    return cpu_type;
}
#else
asm s8 Player_GetCpuType(s32 slot)
{
    nofralloc
    /* 80033670 00030250  7C 08 02 A6 */	mflr r0
    /* 80033674 00030254  90 01 00 04 */	stw r0, 4(r1)
    /* 80033678 00030258  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003367C 0003025C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033680 00030260  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033684 00030264  41 80 00 0C */	blt lbl_80033690
    /* 80033688 00030268  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003368C 0003026C  41 80 00 2C */	blt lbl_800336B8
    lbl_80033690:
    /* 80033690 00030270  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033694 00030274  4C C6 31 82 */	crclr 6
    /* 80033698 00030278  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003369C 0003027C  38 9F 00 00 */	addi r4, r31, 0
    /* 800336A0 00030280  48 31 20 09 */	bl OSReport
    /* 800336A4 00030284  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800336A8 00030288  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800336AC 0003028C  38 80 00 66 */	li r4, 0x66
    /* 800336B0 00030290  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800336B4 00030294  48 35 4B 6D */	bl __assert
    lbl_800336B8:
    /* 800336B8 00030298  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800336BC 0003029C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800336C0 000302A0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800336C4 000302A4  7C 60 22 14 */	add r3, r0, r4
    /* 800336C8 000302A8  88 63 00 4A */	lbz r3, 0x4a(r3)
    /* 800336CC 000302AC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800336D0 000302B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800336D4 000302B4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800336D8 000302B8  7C 08 03 A6 */	mtlr r0
    /* 800336DC 000302BC  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetPlayerAndEntityCpuType(s32 slot, s8 cpu_type) {   ///https://decomp.me/scratch/e0AfS
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->cpu_type = cpu_type;
    for (i = 0; i < 2; i++){
        if (player->player_entity[player->transformed[i]]) {
            func_80087BC0(player->player_entity[player->transformed[i]], cpu_type);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityCpuType(s32 slot, s8 cpu_type)
{
    nofralloc
    /* 800336E0 000302C0  7C 08 02 A6 */	mflr r0
    /* 800336E4 000302C4  90 01 00 04 */	stw r0, 4(r1)
    /* 800336E8 000302C8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800336EC 000302CC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800336F0 000302D0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800336F4 000302D4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800336F8 000302D8  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 800336FC 000302DC  3B A4 00 00 */	addi r29, r4, 0
    /* 80033700 000302E0  41 80 00 0C */	blt lbl_8003370C
    /* 80033704 000302E4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033708 000302E8  41 80 00 2C */	blt lbl_80033734
    lbl_8003370C:
    /* 8003370C 000302EC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033710 000302F0  4C C6 31 82 */	crclr 6
    /* 80033714 000302F4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033718 000302F8  38 9E 00 00 */	addi r4, r30, 0
    /* 8003371C 000302FC  48 31 1F 8D */	bl OSReport
    /* 80033720 00030300  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033724 00030304  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033728 00030308  38 80 00 66 */	li r4, 0x66
    /* 8003372C 0003030C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033730 00030310  48 35 4A F1 */	bl __assert
    lbl_80033734:
    /* 80033734 00030314  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033738 00030318  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003373C 0003031C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033740 00030320  7F E0 22 14 */	add r31, r0, r4
    /* 80033744 00030324  9B BF 00 4A */	stb r29, 0x4a(r31)
    /* 80033748 00030328  3B C0 00 00 */	li r30, 0
    lbl_8003374C:
    /* 8003374C 0003032C  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80033750 00030330  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80033754 00030334  54 03 10 3A */	slwi r3, r0, 2
    /* 80033758 00030338  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 8003375C 0003033C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80033760 00030340  28 03 00 00 */	cmplwi r3, 0
    /* 80033764 00030344  41 82 00 0C */	beq lbl_80033770
    /* 80033768 00030348  7F A4 EB 78 */	mr r4, r29
    /* 8003376C 0003034C  48 05 44 55 */	bl func_80087BC0
    lbl_80033770:
    /* 80033770 00030350  3B DE 00 01 */	addi r30, r30, 1
    /* 80033774 00030354  2C 1E 00 02 */	cmpwi r30, 2
    /* 80033778 00030358  41 80 FF D4 */	blt lbl_8003374C
    /* 8003377C 0003035C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033780 00030360  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033784 00030364  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033788 00030368  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 8003378C 0003036C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033790 00030370  7C 08 03 A6 */	mtlr r0
    /* 80033794 00030374  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetHandicap(s32 slot) {   ///https://decomp.me/scratch/LY1eX
    s8 handicap;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    handicap = player->handicap;
    return handicap;
}
#else
asm s8 Player_GetHandicap(s32 slot)
{
    nofralloc
    /* 80033798 00030378  7C 08 02 A6 */	mflr r0
    /* 8003379C 0003037C  90 01 00 04 */	stw r0, 4(r1)
    /* 800337A0 00030380  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800337A4 00030384  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800337A8 00030388  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800337AC 0003038C  41 80 00 0C */	blt lbl_800337B8
    /* 800337B0 00030390  2C 1F 00 06 */	cmpwi r31, 6
    /* 800337B4 00030394  41 80 00 2C */	blt lbl_800337E0
    lbl_800337B8:
    /* 800337B8 00030398  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800337BC 0003039C  4C C6 31 82 */	crclr 6
    /* 800337C0 000303A0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800337C4 000303A4  38 9F 00 00 */	addi r4, r31, 0
    /* 800337C8 000303A8  48 31 1E E1 */	bl OSReport
    /* 800337CC 000303AC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800337D0 000303B0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800337D4 000303B4  38 80 00 66 */	li r4, 0x66
    /* 800337D8 000303B8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 800337DC 000303BC  48 35 4A 45 */	bl __assert
    lbl_800337E0:
    /* 800337E0 000303C0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800337E4 000303C4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800337E8 000303C8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800337EC 000303CC  7C 60 22 14 */	add r3, r0, r4
    /* 800337F0 000303D0  88 63 00 4B */	lbz r3, 0x4b(r3)
    /* 800337F4 000303D4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800337F8 000303D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800337FC 000303DC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033800 000303E0  7C 08 03 A6 */	mtlr r0
    /* 80033804 000303E4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetHandicap(s32 slot, s8 handicap) {   ///https://decomp.me/scratch/JYc5C
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->handicap = handicap;
}
#else
void Player_SetHandicap(s32 slot, s8 handicap) 
{
    nofralloc
    /* 80033808 000303E8  7C 08 02 A6 */	mflr r0
    /* 8003380C 000303EC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033810 000303F0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033814 000303F4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033818 000303F8  3B E4 00 00 */	addi r31, r4, 0
    /* 8003381C 000303FC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033820 00030400  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033824 00030404  41 80 00 0C */	blt lbl_80033830
    /* 80033828 00030408  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003382C 0003040C  41 80 00 2C */	blt lbl_80033858
    lbl_80033830:
    /* 80033830 00030410  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033834 00030414  4C C6 31 82 */	crclr 6
    /* 80033838 00030418  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003383C 0003041C  38 9E 00 00 */	addi r4, r30, 0
    /* 80033840 00030420  48 31 1E 69 */	bl OSReport
    /* 80033844 00030424  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033848 00030428  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003384C 0003042C  38 80 00 66 */	li r4, 0x66
    /* 80033850 00030430  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033854 00030434  48 35 49 CD */	bl __assert
    lbl_80033858:
    /* 80033858 00030438  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003385C 0003043C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033860 00030440  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033864 00030444  7C 60 22 14 */	add r3, r0, r4
    /* 80033868 00030448  9B E3 00 4B */	stb r31, 0x4b(r3)
    /* 8003386C 0003044C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033870 00030450  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033874 00030454  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033878 00030458  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003387C 0003045C  7C 08 03 A6 */	mtlr r0
    /* 80033880 00030460  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetUnk50(s32 slot) {  ///https://decomp.me/scratch/jSMaA
    f32 unk50;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk50 = player->unk50;
    return unk50;
}
#else
asm f32 Player_GetUnk50(s32 slot) 
{
    nofralloc
    /* 80033884 00030464  7C 08 02 A6 */	mflr r0
    /* 80033888 00030468  90 01 00 04 */	stw r0, 4(r1)
    /* 8003388C 0003046C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033890 00030470  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033894 00030474  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033898 00030478  41 80 00 0C */	blt lbl_800338A4
    /* 8003389C 0003047C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800338A0 00030480  41 80 00 2C */	blt lbl_800338CC
    lbl_800338A4:
    /* 800338A4 00030484  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800338A8 00030488  4C C6 31 82 */	crclr 6
    /* 800338AC 0003048C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800338B0 00030490  38 9F 00 00 */	addi r4, r31, 0
    /* 800338B4 00030494  48 31 1D F5 */	bl OSReport
    /* 800338B8 00030498  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800338BC 0003049C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800338C0 000304A0  38 80 00 66 */	li r4, 0x66
    /* 800338C4 000304A4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 800338C8 000304A8  48 35 49 59 */	bl __assert
    lbl_800338CC:
    /* 800338CC 000304AC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800338D0 000304B0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800338D4 000304B4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800338D8 000304B8  7C 60 22 14 */	add r3, r0, r4
    /* 800338DC 000304BC  C0 23 00 50 */	lfs f1, 0x50(r3)
    /* 800338E0 000304C0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800338E4 000304C4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800338E8 000304C8  38 21 00 20 */	addi r1, r1, 0x20
    /* 800338EC 000304CC  7C 08 03 A6 */	mtlr r0
    /* 800338F0 000304D0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetAttackRatio(s32 slot) {   ///https://decomp.me/scratch/K70PJ
    f32 attack_ratio;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    attack_ratio = player->attack_ratio;
    return attack_ratio;
}
#else
asm f32 Player_GetAttackRatio(s32 slot)
{
    nofralloc
    /* 800338F4 000304D4  7C 08 02 A6 */	mflr r0
    /* 800338F8 000304D8  90 01 00 04 */	stw r0, 4(r1)
    /* 800338FC 000304DC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033900 000304E0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033904 000304E4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033908 000304E8  41 80 00 0C */	blt lbl_80033914
    /* 8003390C 000304EC  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033910 000304F0  41 80 00 2C */	blt lbl_8003393C
    lbl_80033914:
    /* 80033914 000304F4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033918 000304F8  4C C6 31 82 */	crclr 6
    /* 8003391C 000304FC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033920 00030500  38 9F 00 00 */	addi r4, r31, 0
    /* 80033924 00030504  48 31 1D 85 */	bl OSReport
    /* 80033928 00030508  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003392C 0003050C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033930 00030510  38 80 00 66 */	li r4, 0x66
    /* 80033934 00030514  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033938 00030518  48 35 48 E9 */	bl __assert
    lbl_8003393C:
    /* 8003393C 0003051C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033940 00030520  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033944 00030524  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033948 00030528  7C 60 22 14 */	add r3, r0, r4
    /* 8003394C 0003052C  C0 23 00 54 */	lfs f1, 0x54(r3)
    /* 80033950 00030530  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033954 00030534  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033958 00030538  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003395C 0003053C  7C 08 03 A6 */	mtlr r0
    /* 80033960 00030540  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetAttackRatio(s32 slot, f32 attack_ratio) {   ///https://decomp.me/scratch/dJtJs
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->attack_ratio = attack_ratio;
}
#else
asm void Player_SetAttackRatio(s32 slot, f32 attack_ratio)
{
    nofralloc
    /* 80033964 00030544  7C 08 02 A6 */	mflr r0
    /* 80033968 00030548  90 01 00 04 */	stw r0, 4(r1)
    /* 8003396C 0003054C  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033970 00030550  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033974 00030554  FF E0 08 90 */	fmr f31, f1
    /* 80033978 00030558  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003397C 0003055C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033980 00030560  41 80 00 0C */	blt lbl_8003398C
    /* 80033984 00030564  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033988 00030568  41 80 00 2C */	blt lbl_800339B4
    lbl_8003398C:
    /* 8003398C 0003056C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033990 00030570  4C C6 31 82 */	crclr 6
    /* 80033994 00030574  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033998 00030578  38 9F 00 00 */	addi r4, r31, 0
    /* 8003399C 0003057C  48 31 1D 0D */	bl OSReport
    /* 800339A0 00030580  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800339A4 00030584  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800339A8 00030588  38 80 00 66 */	li r4, 0x66
    /* 800339AC 0003058C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 800339B0 00030590  48 35 48 71 */	bl __assert
    lbl_800339B4:
    /* 800339B4 00030594  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800339B8 00030598  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800339BC 0003059C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800339C0 000305A0  7C 60 22 14 */	add r3, r0, r4
    /* 800339C4 000305A4  D3 E3 00 54 */	stfs f31, 0x54(r3)
    /* 800339C8 000305A8  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800339CC 000305AC  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 800339D0 000305B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800339D4 000305B4  38 21 00 28 */	addi r1, r1, 0x28
    /* 800339D8 000305B8  7C 08 03 A6 */	mtlr r0
    /* 800339DC 000305BC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetDefenseRatio(s32 slot) {   ///https://decomp.me/scratch/4sS0R
    f32 defense_ratio;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    defense_ratio = player->defense_ratio;
    return defense_ratio;
}
#else
asm f32 Player_GetDefenseRatio(s32 slot)
{
    nofralloc
    /* 800339E0 000305C0  7C 08 02 A6 */	mflr r0
    /* 800339E4 000305C4  90 01 00 04 */	stw r0, 4(r1)
    /* 800339E8 000305C8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800339EC 000305CC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800339F0 000305D0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800339F4 000305D4  41 80 00 0C */	blt lbl_80033A00
    /* 800339F8 000305D8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800339FC 000305DC  41 80 00 2C */	blt lbl_80033A28
    lbl_80033A00:
    /* 80033A00 000305E0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033A04 000305E4  4C C6 31 82 */	crclr 6
    /* 80033A08 000305E8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033A0C 000305EC  38 9F 00 00 */	addi r4, r31, 0
    /* 80033A10 000305F0  48 31 1C 99 */	bl OSReport
    /* 80033A14 000305F4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033A18 000305F8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033A1C 000305FC  38 80 00 66 */	li r4, 0x66
    /* 80033A20 00030600  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033A24 00030604  48 35 47 FD */	bl __assert
    lbl_80033A28:
    /* 80033A28 00030608  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033A2C 0003060C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033A30 00030610  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033A34 00030614  7C 60 22 14 */	add r3, r0, r4
    /* 80033A38 00030618  C0 23 00 58 */	lfs f1, 0x58(r3)
    /* 80033A3C 0003061C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033A40 00030620  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033A44 00030624  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033A48 00030628  7C 08 03 A6 */	mtlr r0
    /* 80033A4C 0003062C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetDefenseRatio(s32 slot, f32 defense_ratio) {    ///https://decomp.me/scratch/NIFKD
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->defense_ratio = defense_ratio;
}
#else
asm void Player_SetDefenseRatio(s32 slot, f32 defense_ratio)
{
    nofralloc
    /* 80033A50 00030630  7C 08 02 A6 */	mflr r0
    /* 80033A54 00030634  90 01 00 04 */	stw r0, 4(r1)
    /* 80033A58 00030638  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033A5C 0003063C  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033A60 00030640  FF E0 08 90 */	fmr f31, f1
    /* 80033A64 00030644  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033A68 00030648  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033A6C 0003064C  41 80 00 0C */	blt lbl_80033A78
    /* 80033A70 00030650  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033A74 00030654  41 80 00 2C */	blt lbl_80033AA0
    lbl_80033A78:
    /* 80033A78 00030658  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033A7C 0003065C  4C C6 31 82 */	crclr 6
    /* 80033A80 00030660  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033A84 00030664  38 9F 00 00 */	addi r4, r31, 0
    /* 80033A88 00030668  48 31 1C 21 */	bl OSReport
    /* 80033A8C 0003066C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033A90 00030670  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033A94 00030674  38 80 00 66 */	li r4, 0x66
    /* 80033A98 00030678  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033A9C 0003067C  48 35 47 85 */	bl __assert
    lbl_80033AA0:
    /* 80033AA0 00030680  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033AA4 00030684  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033AA8 00030688  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033AAC 0003068C  7C 60 22 14 */	add r3, r0, r4
    /* 80033AB0 00030690  D3 E3 00 58 */	stfs f31, 0x58(r3)
    /* 80033AB4 00030694  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80033AB8 00030698  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033ABC 0003069C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033AC0 000306A0  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033AC4 000306A4  7C 08 03 A6 */	mtlr r0
    /* 80033AC8 000306A8  4E 80 00 20 */	blr
}
#endif

#ifdef NON_MATCHING
f32 Player_GetModelScale(s32 slot) {  ///https://decomp.me/scratch/oXyh9
    f32 model_scale;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    model_scale = player->model_scale;
    return model_scale;
}
#else
asm f32 Player_GetModelScale(s32 slot)
{
    nofralloc
    /* 80033ACC 000306AC  7C 08 02 A6 */	mflr r0
    /* 80033AD0 000306B0  90 01 00 04 */	stw r0, 4(r1)
    /* 80033AD4 000306B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033AD8 000306B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033ADC 000306BC  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033AE0 000306C0  41 80 00 0C */	blt lbl_80033AEC
    /* 80033AE4 000306C4  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033AE8 000306C8  41 80 00 2C */	blt lbl_80033B14
    lbl_80033AEC:
    /* 80033AEC 000306CC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033AF0 000306D0  4C C6 31 82 */	crclr 6
    /* 80033AF4 000306D4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033AF8 000306D8  38 9F 00 00 */	addi r4, r31, 0
    /* 80033AFC 000306DC  48 31 1B AD */	bl OSReport
    /* 80033B00 000306E0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033B04 000306E4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033B08 000306E8  38 80 00 66 */	li r4, 0x66
    /* 80033B0C 000306EC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033B10 000306F0  48 35 47 11 */	bl __assert
    lbl_80033B14:
    /* 80033B14 000306F4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033B18 000306F8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033B1C 000306FC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033B20 00030700  7C 60 22 14 */	add r3, r0, r4
    /* 80033B24 00030704  C0 23 00 5C */	lfs f1, 0x5c(r3)
    /* 80033B28 00030708  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033B2C 0003070C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033B30 00030710  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033B34 00030714  7C 08 03 A6 */	mtlr r0
    /* 80033B38 00030718  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetModelScale(s32 slot, f32 model_scale) {   //https://decomp.me/scratch/lbBPD
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->model_scale = model_scale;
}
#else
asm void Player_SetModelScale(s32 slot, f32 model_scale)
{
    nofralloc
    /* 80033B3C 0003071C  7C 08 02 A6 */	mflr r0
    /* 80033B40 00030720  90 01 00 04 */	stw r0, 4(r1)
    /* 80033B44 00030724  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033B48 00030728  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033B4C 0003072C  FF E0 08 90 */	fmr f31, f1
    /* 80033B50 00030730  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033B54 00030734  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033B58 00030738  41 80 00 0C */	blt lbl_80033B64
    /* 80033B5C 0003073C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033B60 00030740  41 80 00 2C */	blt lbl_80033B8C
    lbl_80033B64:
    /* 80033B64 00030744  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033B68 00030748  4C C6 31 82 */	crclr 6
    /* 80033B6C 0003074C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033B70 00030750  38 9F 00 00 */	addi r4, r31, 0
    /* 80033B74 00030754  48 31 1B 35 */	bl OSReport
    /* 80033B78 00030758  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033B7C 0003075C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033B80 00030760  38 80 00 66 */	li r4, 0x66
    /* 80033B84 00030764  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033B88 00030768  48 35 46 99 */	bl __assert
    lbl_80033B8C:
    /* 80033B8C 0003076C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033B90 00030770  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033B94 00030774  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033B98 00030778  7C 60 22 14 */	add r3, r0, r4
    /* 80033B9C 0003077C  D3 E3 00 5C */	stfs f31, 0x5c(r3)
    /* 80033BA0 00030780  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80033BA4 00030784  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033BA8 00030788  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033BAC 0003078C  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033BB0 00030790  7C 08 03 A6 */	mtlr r0
    /* 80033BB4 00030794  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80033BB8(s32 slot) {  ///https://decomp.me/scratch/MBPYW
    return func_8016C5C0(slot);
}
#else
asm s32 Player_80033BB8(s32 slot)
{
    nofralloc
    /* 80033BB8 00030798  7C 08 02 A6 */	mflr r0
    /* 80033BBC 0003079C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033BC0 000307A0  94 21 FF F8 */	stwu r1, -8(r1)
    /* 80033BC4 000307A4  48 13 89 FD */	bl func_8016C5C0
    /* 80033BC8 000307A8  80 01 00 0C */	lwz r0, 0xc(r1)
    /* 80033BCC 000307AC  38 21 00 08 */	addi r1, r1, 8
    /* 80033BD0 000307B0  7C 08 03 A6 */	mtlr r0
    /* 80033BD4 000307B4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetStocks(s32 slot) {  //https://decomp.me/scratch/FkfgM
    s8 stocks;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stocks = player->stocks;
    return stocks;
}
#else
asm s32 Player_GetStocks(s32 slot)
{
    nofralloc
    /* 80033BD8 000307B8  7C 08 02 A6 */	mflr r0
    /* 80033BDC 000307BC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033BE0 000307C0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033BE4 000307C4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033BE8 000307C8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033BEC 000307CC  41 80 00 0C */	blt lbl_80033BF8
    /* 80033BF0 000307D0  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033BF4 000307D4  41 80 00 2C */	blt lbl_80033C20
    lbl_80033BF8:
    /* 80033BF8 000307D8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033BFC 000307DC  4C C6 31 82 */	crclr 6
    /* 80033C00 000307E0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033C04 000307E4  38 9F 00 00 */	addi r4, r31, 0
    /* 80033C08 000307E8  48 31 1A A1 */	bl OSReport
    /* 80033C0C 000307EC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033C10 000307F0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033C14 000307F4  38 80 00 66 */	li r4, 0x66
    /* 80033C18 000307F8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033C1C 000307FC  48 35 46 05 */	bl __assert
    lbl_80033C20:
    /* 80033C20 00030800  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033C24 00030804  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033C28 00030808  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033C2C 0003080C  7C 60 22 14 */	add r3, r0, r4
    /* 80033C30 00030810  88 63 00 8E */	lbz r3, 0x8e(r3)
    /* 80033C34 00030814  7C 63 07 74 */	extsb r3, r3
    /* 80033C38 00030818  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033C3C 0003081C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033C40 00030820  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033C44 00030824  7C 08 03 A6 */	mtlr r0
    /* 80033C48 00030828  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s32 Player_GetP1Stock() {  //https://decomp.me/scratch/HC5LM
    return player_slots[0].stocks;
}
#else
asm s32 Player_GetP1Stock()
{
    nofralloc
    /* 80033C4C 0003082C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033C50 00030830  38 63 30 80 */	addi r3, r3, player_slots@l
    /* 80033C54 00030834  88 63 00 8E */	lbz r3, 0x8e(r3)
    /* 80033C58 00030838  7C 63 07 74 */	extsb r3, r3
    /* 80033C5C 0003083C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetStocks(s32 slot, s32 stocks) {  //https://decomp.me/scratch/YOxJC
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->stocks = stocks;
}
#else
asm void Player_SetStocks(s32 slot, s32 stocks)
{
    nofralloc
    /* 80033C60 00030840  7C 08 02 A6 */	mflr r0
    /* 80033C64 00030844  90 01 00 04 */	stw r0, 4(r1)
    /* 80033C68 00030848  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033C6C 0003084C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033C70 00030850  3B E4 00 00 */	addi r31, r4, 0
    /* 80033C74 00030854  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033C78 00030858  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033C7C 0003085C  41 80 00 0C */	blt lbl_80033C88
    /* 80033C80 00030860  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033C84 00030864  41 80 00 2C */	blt lbl_80033CB0
    lbl_80033C88:
    /* 80033C88 00030868  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033C8C 0003086C  4C C6 31 82 */	crclr 6
    /* 80033C90 00030870  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033C94 00030874  38 9E 00 00 */	addi r4, r30, 0
    /* 80033C98 00030878  48 31 1A 11 */	bl OSReport
    /* 80033C9C 0003087C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033CA0 00030880  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033CA4 00030884  38 80 00 66 */	li r4, 0x66
    /* 80033CA8 00030888  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033CAC 0003088C  48 35 45 75 */	bl __assert
    lbl_80033CB0:
    /* 80033CB0 00030890  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033CB4 00030894  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033CB8 00030898  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033CBC 0003089C  7F E5 07 74 */	extsb r5, r31
    /* 80033CC0 000308A0  7C 60 22 14 */	add r3, r0, r4
    /* 80033CC4 000308A4  98 A3 00 8E */	stb r5, 0x8e(r3)
    /* 80033CC8 000308A8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033CCC 000308AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033CD0 000308B0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033CD4 000308B4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033CD8 000308B8  7C 08 03 A6 */	mtlr r0
    /* 80033CDC 000308BC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_LoseStock(s32 slot) {   //https://decomp.me/scratch/FyAe7
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    if (player->stocks > 0){
        player->stocks = player->stocks - 1;
    }
}
#else
asm void Player_LoseStock(s32 slot)
{
    nofralloc
    /* 80033CE0 000308C0  7C 08 02 A6 */	mflr r0
    /* 80033CE4 000308C4  90 01 00 04 */	stw r0, 4(r1)
    /* 80033CE8 000308C8  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80033CEC 000308CC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80033CF0 000308D0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033CF4 000308D4  41 80 00 0C */	blt lbl_80033D00
    /* 80033CF8 000308D8  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033CFC 000308DC  41 80 00 2C */	blt lbl_80033D28
    lbl_80033D00:
    /* 80033D00 000308E0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033D04 000308E4  4C C6 31 82 */	crclr 6
    /* 80033D08 000308E8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033D0C 000308EC  38 9F 00 00 */	addi r4, r31, 0
    /* 80033D10 000308F0  48 31 19 99 */	bl OSReport
    /* 80033D14 000308F4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033D18 000308F8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033D1C 000308FC  38 80 00 66 */	li r4, 0x66
    /* 80033D20 00030900  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033D24 00030904  48 35 44 FD */	bl __assert
    lbl_80033D28:
    /* 80033D28 00030908  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033D2C 0003090C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033D30 00030910  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033D34 00030914  7C 80 22 14 */	add r4, r0, r4
    /* 80033D38 00030918  88 64 00 8E */	lbz r3, 0x8e(r4)
    /* 80033D3C 0003091C  7C 60 07 75 */	extsb. r0, r3
    /* 80033D40 00030920  40 81 00 0C */	ble lbl_80033D4C
    /* 80033D44 00030924  38 03 FF FF */	addi r0, r3, -1
    /* 80033D48 00030928  98 04 00 8E */	stb r0, 0x8e(r4)
    lbl_80033D4C:
    /* 80033D4C 0003092C  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80033D50 00030930  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80033D54 00030934  38 21 00 18 */	addi r1, r1, 0x18
    /* 80033D58 00030938  7C 08 03 A6 */	mtlr r0
    /* 80033D5C 0003093C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetCoins(s32 slot) {  //https://decomp.me/scratch/2QPs1
    s32 current_coins;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    current_coins = player->current_coins;
    return current_coins;
}
#else
asm s32 Player_GetCoins(s32 slot)
{
    nofralloc
    /* 80033D60 00030940  7C 08 02 A6 */	mflr r0
    /* 80033D64 00030944  90 01 00 04 */	stw r0, 4(r1)
    /* 80033D68 00030948  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033D6C 0003094C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033D70 00030950  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033D74 00030954  41 80 00 0C */	blt lbl_80033D80
    /* 80033D78 00030958  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033D7C 0003095C  41 80 00 2C */	blt lbl_80033DA8
    lbl_80033D80:
    /* 80033D80 00030960  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033D84 00030964  4C C6 31 82 */	crclr 6
    /* 80033D88 00030968  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033D8C 0003096C  38 9F 00 00 */	addi r4, r31, 0
    /* 80033D90 00030970  48 31 19 19 */	bl OSReport
    /* 80033D94 00030974  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033D98 00030978  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033D9C 0003097C  38 80 00 66 */	li r4, 0x66
    /* 80033DA0 00030980  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033DA4 00030984  48 35 44 7D */	bl __assert
    lbl_80033DA8:
    /* 80033DA8 00030988  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033DAC 0003098C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033DB0 00030990  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033DB4 00030994  7C 60 22 14 */	add r3, r0, r4
    /* 80033DB8 00030998  80 63 00 90 */	lwz r3, 0x90(r3)
    /* 80033DBC 0003099C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033DC0 000309A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033DC4 000309A4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033DC8 000309A8  7C 08 03 A6 */	mtlr r0
    /* 80033DCC 000309AC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetCoins(s32 slot, s32 current_coins) {   ///https://decomp.me/scratch/sFNid
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->current_coins = current_coins;
}
#else
asm void Player_SetCoins(s32 slot, s32 current_coins)
{
    nofralloc
    /* 80033DD0 000309B0  7C 08 02 A6 */	mflr r0
    /* 80033DD4 000309B4  90 01 00 04 */	stw r0, 4(r1)
    /* 80033DD8 000309B8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033DDC 000309BC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033DE0 000309C0  3B E4 00 00 */	addi r31, r4, 0
    /* 80033DE4 000309C4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033DE8 000309C8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033DEC 000309CC  41 80 00 0C */	blt lbl_80033DF8
    /* 80033DF0 000309D0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033DF4 000309D4  41 80 00 2C */	blt lbl_80033E20
    lbl_80033DF8:
    /* 80033DF8 000309D8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033DFC 000309DC  4C C6 31 82 */	crclr 6
    /* 80033E00 000309E0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033E04 000309E4  38 9E 00 00 */	addi r4, r30, 0
    /* 80033E08 000309E8  48 31 18 A1 */	bl OSReport
    /* 80033E0C 000309EC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033E10 000309F0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033E14 000309F4  38 80 00 66 */	li r4, 0x66
    /* 80033E18 000309F8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80033E1C 000309FC  48 35 44 05 */	bl __assert
    lbl_80033E20:
    /* 80033E20 00030A00  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033E24 00030A04  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033E28 00030A08  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033E2C 00030A0C  7C 60 22 14 */	add r3, r0, r4
    /* 80033E30 00030A10  93 E3 00 90 */	stw r31, 0x90(r3)
    /* 80033E34 00030A14  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033E38 00030A18  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033E3C 00030A1C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033E40 00030A20  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033E44 00030A24  7C 08 03 A6 */	mtlr r0
    /* 80033E48 00030A28  4E 80 00 20 */	blr 
}
#endif