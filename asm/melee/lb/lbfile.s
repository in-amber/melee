.include "macros.inc"

.section .text  # 0x8001615C - 0x80016A50

.global func_800161C4
func_800161C4:
/* 800161C4 00012DA4  7C 08 02 A6 */	mflr r0
/* 800161C8 00012DA8  3D 20 80 01 */	lis r9, lbFile_8001615C@ha
/* 800161CC 00012DAC  90 01 00 04 */	stw r0, 4(r1)
/* 800161D0 00012DB0  38 00 00 00 */	li r0, 0
/* 800161D4 00012DB4  39 29 61 5C */	addi r9, r9, lbFile_8001615C@l
/* 800161D8 00012DB8  94 21 FF F8 */	stwu r1, -8(r1)
/* 800161DC 00012DBC  39 40 00 00 */	li r10, 0
/* 800161E0 00012DC0  90 0D AD 28 */	stw r0, cancel@sda21(r13)
/* 800161E4 00012DC4  48 37 94 F1 */	bl HSD_DevComRequest
lbl_800161E8:
/* 800161E8 00012DC8  4B FF FF B9 */	bl lbFile_800161A0
/* 800161EC 00012DCC  2C 03 00 00 */	cmpwi r3, 0
/* 800161F0 00012DD0  41 82 FF F8 */	beq lbl_800161E8
/* 800161F4 00012DD4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800161F8 00012DD8  38 21 00 08 */	addi r1, r1, 8
/* 800161FC 00012DDC  7C 08 03 A6 */	mtlr r0
/* 80016200 00012DE0  4E 80 00 20 */	blr 

.global func_80016204
func_80016204:
/* 80016204 00012DE4  7C 08 02 A6 */	mflr r0
/* 80016208 00012DE8  3C 80 80 43 */	lis r4, lbl_80432058@ha
/* 8001620C 00012DEC  90 01 00 04 */	stw r0, 4(r1)
/* 80016210 00012DF0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80016214 00012DF4  BF 41 00 10 */	stmw r26, 0x10(r1)
/* 80016218 00012DF8  3B 43 00 00 */	addi r26, r3, 0
/* 8001621C 00012DFC  3B A4 20 58 */	addi r29, r4, lbl_80432058@l
/* 80016220 00012E00  3C 80 80 3C */	lis r4, lbl_803BA520@ha
/* 80016224 00012E04  3C 60 80 3C */	lis r3, lbl_803BA508@ha
/* 80016228 00012E08  3B 9A 00 00 */	addi r28, r26, 0
/* 8001622C 00012E0C  3B C4 A5 20 */	addi r30, r4, lbl_803BA520@l
/* 80016230 00012E10  3B E3 A5 08 */	addi r31, r3, lbl_803BA508@l
/* 80016234 00012E14  3B 60 00 00 */	li r27, 0
/* 80016238 00012E18  48 00 00 40 */	b lbl_80016278
lbl_8001623C:
/* 8001623C 00012E1C  2C 1B 00 1C */	cmpwi r27, 0x1c
/* 80016240 00012E20  40 81 00 24 */	ble lbl_80016264
/* 80016244 00012E24  38 7E 00 00 */	addi r3, r30, 0
/* 80016248 00012E28  4C C6 31 82 */	crclr 6
/* 8001624C 00012E2C  38 9A 00 00 */	addi r4, r26, 0
/* 80016250 00012E30  48 32 F4 59 */	bl OSReport
/* 80016254 00012E34  38 7F 00 00 */	addi r3, r31, 0
/* 80016258 00012E38  38 80 00 99 */	li r4, 0x99
/* 8001625C 00012E3C  38 AD 81 08 */	addi r5, r13, lbl_804D37A8@sda21
/* 80016260 00012E40  48 37 1F C1 */	bl __assert
lbl_80016264:
/* 80016264 00012E44  88 7C 00 00 */	lbz r3, 0(r28)
/* 80016268 00012E48  7F 60 DB 78 */	mr r0, r27
/* 8001626C 00012E4C  3B 7B 00 01 */	addi r27, r27, 1
/* 80016270 00012E50  7C 7D 01 AE */	stbx r3, r29, r0
/* 80016274 00012E54  3B 9C 00 01 */	addi r28, r28, 1
lbl_80016278:
/* 80016278 00012E58  88 7C 00 00 */	lbz r3, 0(r28)
/* 8001627C 00012E5C  7C 60 07 75 */	extsb. r0, r3
/* 80016280 00012E60  41 82 00 10 */	beq lbl_80016290
/* 80016284 00012E64  7C 60 07 74 */	extsb r0, r3
/* 80016288 00012E68  2C 00 00 2E */	cmpwi r0, 0x2e
/* 8001628C 00012E6C  40 82 FF B0 */	bne lbl_8001623C
lbl_80016290:
/* 80016290 00012E70  7C 60 07 75 */	extsb. r0, r3
/* 80016294 00012E74  41 82 00 20 */	beq lbl_800162B4
/* 80016298 00012E78  88 1C 00 01 */	lbz r0, 1(r28)
/* 8001629C 00012E7C  7C 00 07 75 */	extsb. r0, r0
/* 800162A0 00012E80  41 82 00 14 */	beq lbl_800162B4
/* 800162A4 00012E84  38 7D 00 00 */	addi r3, r29, 0
/* 800162A8 00012E88  38 9A 00 00 */	addi r4, r26, 0
/* 800162AC 00012E8C  48 30 F7 A5 */	bl strcpy
/* 800162B0 00012E90  48 00 00 84 */	b lbl_80016334
lbl_800162B4:
/* 800162B4 00012E94  7C 60 07 74 */	extsb r0, r3
/* 800162B8 00012E98  2C 00 00 2E */	cmpwi r0, 0x2e
/* 800162BC 00012E9C  40 82 00 40 */	bne lbl_800162FC
/* 800162C0 00012EA0  38 1B 00 00 */	addi r0, r27, 0
/* 800162C4 00012EA4  38 60 00 2E */	li r3, 0x2e
/* 800162C8 00012EA8  7C 7D 01 AE */	stbx r3, r29, r0
/* 800162CC 00012EAC  3B 7B 00 01 */	addi r27, r27, 1
/* 800162D0 00012EB0  4B FF 4B 05 */	bl lbLang_IsSettingUS
/* 800162D4 00012EB4  2C 03 00 00 */	cmpwi r3, 0
/* 800162D8 00012EB8  41 82 00 14 */	beq lbl_800162EC
/* 800162DC 00012EBC  7C 7D DA 14 */	add r3, r29, r27
/* 800162E0 00012EC0  38 8D 81 10 */	addi r4, r13, lbl_804D37B0@sda21
/* 800162E4 00012EC4  48 30 F7 6D */	bl strcpy
/* 800162E8 00012EC8  48 00 00 4C */	b lbl_80016334
lbl_800162EC:
/* 800162EC 00012ECC  7C 7D DA 14 */	add r3, r29, r27
/* 800162F0 00012ED0  38 8D 81 14 */	addi r4, r13, lbl_804D37B4@sda21
/* 800162F4 00012ED4  48 30 F7 5D */	bl strcpy
/* 800162F8 00012ED8  48 00 00 3C */	b lbl_80016334
lbl_800162FC:
/* 800162FC 00012EDC  38 1B 00 00 */	addi r0, r27, 0
/* 80016300 00012EE0  38 60 00 2E */	li r3, 0x2e
/* 80016304 00012EE4  7C 7D 01 AE */	stbx r3, r29, r0
/* 80016308 00012EE8  3B 7B 00 01 */	addi r27, r27, 1
/* 8001630C 00012EEC  4B FF 4B 85 */	bl lbLang_IsSavedLanguageUS
/* 80016310 00012EF0  2C 03 00 00 */	cmpwi r3, 0
/* 80016314 00012EF4  41 82 00 14 */	beq lbl_80016328
/* 80016318 00012EF8  7C 7D DA 14 */	add r3, r29, r27
/* 8001631C 00012EFC  38 8D 81 10 */	addi r4, r13, lbl_804D37B0@sda21
/* 80016320 00012F00  48 30 F7 31 */	bl strcpy
/* 80016324 00012F04  48 00 00 10 */	b lbl_80016334
lbl_80016328:
/* 80016328 00012F08  7C 7D DA 14 */	add r3, r29, r27
/* 8001632C 00012F0C  38 8D 81 14 */	addi r4, r13, lbl_804D37B4@sda21
/* 80016330 00012F10  48 30 F7 21 */	bl strcpy
lbl_80016334:
/* 80016334 00012F14  7F A3 EB 78 */	mr r3, r29
/* 80016338 00012F18  BB 41 00 10 */	lmw r26, 0x10(r1)
/* 8001633C 00012F1C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80016340 00012F20  38 21 00 28 */	addi r1, r1, 0x28
/* 80016344 00012F24  7C 08 03 A6 */	mtlr r0
/* 80016348 00012F28  4E 80 00 20 */	blr 

.global func_8001634C
func_8001634C:
/* 8001634C 00012F2C  7C 08 02 A6 */	mflr r0
/* 80016350 00012F30  90 01 00 04 */	stw r0, 4(r1)
/* 80016354 00012F34  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80016358 00012F38  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 8001635C 00012F3C  7C 7F 1B 78 */	mr r31, r3
/* 80016360 00012F40  93 C1 00 48 */	stw r30, 0x48(r1)
/* 80016364 00012F44  48 33 10 01 */	bl OSDisableInterrupts
/* 80016368 00012F48  3B C3 00 00 */	addi r30, r3, 0
/* 8001636C 00012F4C  38 7F 00 00 */	addi r3, r31, 0
/* 80016370 00012F50  38 81 00 0C */	addi r4, r1, 0xc
/* 80016374 00012F54  48 32 18 ED */	bl DVDFastOpen
/* 80016378 00012F58  2C 03 00 00 */	cmpwi r3, 0
/* 8001637C 00012F5C  40 82 00 2C */	bne lbl_800163A8
/* 80016380 00012F60  3C 60 80 3C */	lis r3, lbl_803BA540@ha
/* 80016384 00012F64  4C C6 31 82 */	crclr 6
/* 80016388 00012F68  38 63 A5 40 */	addi r3, r3, lbl_803BA540@l
/* 8001638C 00012F6C  38 9F 00 00 */	addi r4, r31, 0
/* 80016390 00012F70  48 32 F3 19 */	bl OSReport
/* 80016394 00012F74  3C 60 80 3C */	lis r3, lbl_803BA508@ha
/* 80016398 00012F78  38 63 A5 08 */	addi r3, r3, lbl_803BA508@l
/* 8001639C 00012F7C  38 80 00 D8 */	li r4, 0xd8
/* 800163A0 00012F80  38 AD 81 18 */	addi r5, r13, lbl_804D37B8@sda21
/* 800163A4 00012F84  48 37 1E 7D */	bl __assert
lbl_800163A8:
/* 800163A8 00012F88  83 E1 00 40 */	lwz r31, 0x40(r1)
/* 800163AC 00012F8C  38 61 00 0C */	addi r3, r1, 0xc
/* 800163B0 00012F90  48 32 19 25 */	bl func_80337CD4
/* 800163B4 00012F94  7F C3 F3 78 */	mr r3, r30
/* 800163B8 00012F98  48 33 0F D5 */	bl OSRestoreInterrupts
/* 800163BC 00012F9C  7F E3 FB 78 */	mr r3, r31
/* 800163C0 00012FA0  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800163C4 00012FA4  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800163C8 00012FA8  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 800163CC 00012FAC  38 21 00 50 */	addi r1, r1, 0x50
/* 800163D0 00012FB0  7C 08 03 A6 */	mtlr r0
/* 800163D4 00012FB4  4E 80 00 20 */	blr 

.global func_800163D8
func_800163D8:
/* 800163D8 00012FB8  7C 08 02 A6 */	mflr r0
/* 800163DC 00012FBC  3C 80 80 3C */	lis r4, lbl_803BA508@ha
/* 800163E0 00012FC0  90 01 00 04 */	stw r0, 4(r1)
/* 800163E4 00012FC4  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 800163E8 00012FC8  93 E1 00 54 */	stw r31, 0x54(r1)
/* 800163EC 00012FCC  3B E4 A5 08 */	addi r31, r4, lbl_803BA508@l
/* 800163F0 00012FD0  93 C1 00 50 */	stw r30, 0x50(r1)
/* 800163F4 00012FD4  93 A1 00 4C */	stw r29, 0x4c(r1)
/* 800163F8 00012FD8  4B FF FE 0D */	bl func_80016204
/* 800163FC 00012FDC  7C 7E 1B 78 */	mr r30, r3
/* 80016400 00012FE0  48 32 15 6D */	bl DVDConvertPathToEntrynum
/* 80016404 00012FE4  3B A3 00 00 */	addi r29, r3, 0
/* 80016408 00012FE8  2C 1D FF FF */	cmpwi r29, -1
/* 8001640C 00012FEC  40 82 00 28 */	bne lbl_80016434
/* 80016410 00012FF0  38 9E 00 00 */	addi r4, r30, 0
/* 80016414 00012FF4  4C C6 31 82 */	crclr 6
/* 80016418 00012FF8  38 BD 00 00 */	addi r5, r29, 0
/* 8001641C 00012FFC  38 7F 00 50 */	addi r3, r31, 0x50
/* 80016420 00013000  48 32 F2 89 */	bl OSReport
/* 80016424 00013004  38 7F 00 00 */	addi r3, r31, 0
/* 80016428 00013008  38 BF 00 6C */	addi r5, r31, 0x6c
/* 8001642C 0001300C  38 80 00 EE */	li r4, 0xee
/* 80016430 00013010  48 37 1D F1 */	bl __assert
lbl_80016434:
/* 80016434 00013014  48 33 0F 31 */	bl OSDisableInterrupts
/* 80016438 00013018  3B C3 00 00 */	addi r30, r3, 0
/* 8001643C 0001301C  38 7D 00 00 */	addi r3, r29, 0
/* 80016440 00013020  38 81 00 0C */	addi r4, r1, 0xc
/* 80016444 00013024  48 32 18 1D */	bl DVDFastOpen
/* 80016448 00013028  2C 03 00 00 */	cmpwi r3, 0
/* 8001644C 0001302C  40 82 00 24 */	bne lbl_80016470
/* 80016450 00013030  38 9D 00 00 */	addi r4, r29, 0
/* 80016454 00013034  4C C6 31 82 */	crclr 6
/* 80016458 00013038  38 7F 00 38 */	addi r3, r31, 0x38
/* 8001645C 0001303C  48 32 F2 4D */	bl OSReport
/* 80016460 00013040  38 7F 00 00 */	addi r3, r31, 0
/* 80016464 00013044  38 80 00 D8 */	li r4, 0xd8
/* 80016468 00013048  38 AD 81 18 */	addi r5, r13, lbl_804D37B8@sda21
/* 8001646C 0001304C  48 37 1D B5 */	bl __assert
lbl_80016470:
/* 80016470 00013050  83 E1 00 40 */	lwz r31, 0x40(r1)
/* 80016474 00013054  38 61 00 0C */	addi r3, r1, 0xc
/* 80016478 00013058  48 32 18 5D */	bl func_80337CD4
/* 8001647C 0001305C  7F C3 F3 78 */	mr r3, r30
/* 80016480 00013060  48 33 0F 0D */	bl OSRestoreInterrupts
/* 80016484 00013064  7F E3 FB 78 */	mr r3, r31
/* 80016488 00013068  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 8001648C 0001306C  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 80016490 00013070  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 80016494 00013074  83 A1 00 4C */	lwz r29, 0x4c(r1)
/* 80016498 00013078  38 21 00 58 */	addi r1, r1, 0x58
/* 8001649C 0001307C  7C 08 03 A6 */	mtlr r0
/* 800164A0 00013080  4E 80 00 20 */	blr 

.global func_800164A4
func_800164A4:
/* 800164A4 00013084  7C 08 02 A6 */	mflr r0
/* 800164A8 00013088  90 01 00 04 */	stw r0, 4(r1)
/* 800164AC 0001308C  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 800164B0 00013090  BF 01 00 60 */	stmw r24, 0x60(r1)
/* 800164B4 00013094  3B 03 00 00 */	addi r24, r3, 0
/* 800164B8 00013098  3B 24 00 00 */	addi r25, r4, 0
/* 800164BC 0001309C  3B 45 00 00 */	addi r26, r5, 0
/* 800164C0 000130A0  3B 66 00 00 */	addi r27, r6, 0
/* 800164C4 000130A4  3B 87 00 00 */	addi r28, r7, 0
/* 800164C8 000130A8  3B A8 00 00 */	addi r29, r8, 0
/* 800164CC 000130AC  48 33 0E 99 */	bl OSDisableInterrupts
/* 800164D0 000130B0  3B E3 00 00 */	addi r31, r3, 0
/* 800164D4 000130B4  38 78 00 00 */	addi r3, r24, 0
/* 800164D8 000130B8  38 81 00 20 */	addi r4, r1, 0x20
/* 800164DC 000130BC  48 32 17 85 */	bl DVDFastOpen
/* 800164E0 000130C0  2C 03 00 00 */	cmpwi r3, 0
/* 800164E4 000130C4  40 82 00 2C */	bne lbl_80016510
/* 800164E8 000130C8  3C 60 80 3C */	lis r3, lbl_803BA540@ha
/* 800164EC 000130CC  4C C6 31 82 */	crclr 6
/* 800164F0 000130D0  38 63 A5 40 */	addi r3, r3, lbl_803BA540@l
/* 800164F4 000130D4  38 98 00 00 */	addi r4, r24, 0
/* 800164F8 000130D8  48 32 F1 B1 */	bl OSReport
/* 800164FC 000130DC  3C 60 80 3C */	lis r3, lbl_803BA508@ha
/* 80016500 000130E0  38 63 A5 08 */	addi r3, r3, lbl_803BA508@l
/* 80016504 000130E4  38 80 00 D8 */	li r4, 0xd8
/* 80016508 000130E8  38 AD 81 18 */	addi r5, r13, lbl_804D37B8@sda21
/* 8001650C 000130EC  48 37 1D 15 */	bl __assert
lbl_80016510:
/* 80016510 000130F0  83 C1 00 54 */	lwz r30, 0x54(r1)
/* 80016514 000130F4  38 61 00 20 */	addi r3, r1, 0x20
/* 80016518 000130F8  48 32 17 BD */	bl func_80337CD4
/* 8001651C 000130FC  7F E3 FB 78 */	mr r3, r31
/* 80016520 00013100  48 33 0E 6D */	bl OSRestoreInterrupts
/* 80016524 00013104  3C 00 80 00 */	lis r0, 0x8000
/* 80016528 00013108  93 DA 00 00 */	stw r30, 0(r26)
/* 8001652C 0001310C  7C 19 00 40 */	cmplw r25, r0
/* 80016530 00013110  41 80 00 0C */	blt lbl_8001653C
/* 80016534 00013114  38 00 00 21 */	li r0, 0x21
/* 80016538 00013118  48 00 00 08 */	b lbl_80016540
lbl_8001653C:
/* 8001653C 0001311C  38 00 00 23 */	li r0, 0x23
lbl_80016540:
/* 80016540 00013120  80 9A 00 00 */	lwz r4, 0(r26)
/* 80016544 00013124  7C 07 03 78 */	mr r7, r0
/* 80016548 00013128  38 78 00 00 */	addi r3, r24, 0
/* 8001654C 0001312C  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016550 00013130  38 B9 00 00 */	addi r5, r25, 0
/* 80016554 00013134  39 1B 00 00 */	addi r8, r27, 0
/* 80016558 00013138  39 3C 00 00 */	addi r9, r28, 0
/* 8001655C 0001313C  39 5D 00 00 */	addi r10, r29, 0
/* 80016560 00013140  54 06 00 34 */	rlwinm r6, r0, 0, 0, 0x1a
/* 80016564 00013144  38 80 00 00 */	li r4, 0
/* 80016568 00013148  48 37 91 6D */	bl HSD_DevComRequest
/* 8001656C 0001314C  BB 01 00 60 */	lmw r24, 0x60(r1)
/* 80016570 00013150  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80016574 00013154  38 21 00 80 */	addi r1, r1, 0x80
/* 80016578 00013158  7C 08 03 A6 */	mtlr r0
/* 8001657C 0001315C  4E 80 00 20 */	blr 

.global func_80016580
func_80016580:
/* 80016580 00013160  7C 08 02 A6 */	mflr r0
/* 80016584 00013164  3D 00 80 3C */	lis r8, lbl_803BA508@ha
/* 80016588 00013168  90 01 00 04 */	stw r0, 4(r1)
/* 8001658C 0001316C  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 80016590 00013170  BF 21 00 64 */	stmw r25, 0x64(r1)
/* 80016594 00013174  3B 88 A5 08 */	addi r28, r8, lbl_803BA508@l
/* 80016598 00013178  3B A4 00 00 */	addi r29, r4, 0
/* 8001659C 0001317C  3B 25 00 00 */	addi r25, r5, 0
/* 800165A0 00013180  3B C6 00 00 */	addi r30, r6, 0
/* 800165A4 00013184  3B E7 00 00 */	addi r31, r7, 0
/* 800165A8 00013188  4B FF FC 5D */	bl func_80016204
/* 800165AC 0001318C  7C 7B 1B 78 */	mr r27, r3
/* 800165B0 00013190  48 32 13 BD */	bl DVDConvertPathToEntrynum
/* 800165B4 00013194  3B 43 00 00 */	addi r26, r3, 0
/* 800165B8 00013198  2C 1A FF FF */	cmpwi r26, -1
/* 800165BC 0001319C  40 82 00 28 */	bne lbl_800165E4
/* 800165C0 000131A0  38 9B 00 00 */	addi r4, r27, 0
/* 800165C4 000131A4  4C C6 31 82 */	crclr 6
/* 800165C8 000131A8  38 BA 00 00 */	addi r5, r26, 0
/* 800165CC 000131AC  38 7C 00 50 */	addi r3, r28, 0x50
/* 800165D0 000131B0  48 32 F0 D9 */	bl OSReport
/* 800165D4 000131B4  38 7C 00 00 */	addi r3, r28, 0
/* 800165D8 000131B8  38 BC 00 6C */	addi r5, r28, 0x6c
/* 800165DC 000131BC  38 80 01 1A */	li r4, 0x11a
/* 800165E0 000131C0  48 37 1C 41 */	bl __assert
lbl_800165E4:
/* 800165E4 000131C4  48 33 0D 81 */	bl OSDisableInterrupts
/* 800165E8 000131C8  3B 63 00 00 */	addi r27, r3, 0
/* 800165EC 000131CC  38 7A 00 00 */	addi r3, r26, 0
/* 800165F0 000131D0  38 81 00 1C */	addi r4, r1, 0x1c
/* 800165F4 000131D4  48 32 16 6D */	bl DVDFastOpen
/* 800165F8 000131D8  2C 03 00 00 */	cmpwi r3, 0
/* 800165FC 000131DC  40 82 00 24 */	bne lbl_80016620
/* 80016600 000131E0  38 9A 00 00 */	addi r4, r26, 0
/* 80016604 000131E4  4C C6 31 82 */	crclr 6
/* 80016608 000131E8  38 7C 00 38 */	addi r3, r28, 0x38
/* 8001660C 000131EC  48 32 F0 9D */	bl OSReport
/* 80016610 000131F0  38 7C 00 00 */	addi r3, r28, 0
/* 80016614 000131F4  38 80 00 D8 */	li r4, 0xd8
/* 80016618 000131F8  38 AD 81 18 */	addi r5, r13, lbl_804D37B8@sda21
/* 8001661C 000131FC  48 37 1C 05 */	bl __assert
lbl_80016620:
/* 80016620 00013200  83 81 00 50 */	lwz r28, 0x50(r1)
/* 80016624 00013204  38 61 00 1C */	addi r3, r1, 0x1c
/* 80016628 00013208  48 32 16 AD */	bl func_80337CD4
/* 8001662C 0001320C  7F 63 DB 78 */	mr r3, r27
/* 80016630 00013210  48 33 0D 5D */	bl OSRestoreInterrupts
/* 80016634 00013214  3C 00 80 00 */	lis r0, 0x8000
/* 80016638 00013218  93 99 00 00 */	stw r28, 0(r25)
/* 8001663C 0001321C  7C 1D 00 40 */	cmplw r29, r0
/* 80016640 00013220  41 80 00 0C */	blt lbl_8001664C
/* 80016644 00013224  38 E0 00 21 */	li r7, 0x21
/* 80016648 00013228  48 00 00 08 */	b lbl_80016650
lbl_8001664C:
/* 8001664C 0001322C  38 E0 00 23 */	li r7, 0x23
lbl_80016650:
/* 80016650 00013230  80 99 00 00 */	lwz r4, 0(r25)
/* 80016654 00013234  38 7A 00 00 */	addi r3, r26, 0
/* 80016658 00013238  38 BD 00 00 */	addi r5, r29, 0
/* 8001665C 0001323C  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016660 00013240  39 3E 00 00 */	addi r9, r30, 0
/* 80016664 00013244  39 5F 00 00 */	addi r10, r31, 0
/* 80016668 00013248  54 06 00 34 */	rlwinm r6, r0, 0, 0, 0x1a
/* 8001666C 0001324C  38 80 00 00 */	li r4, 0
/* 80016670 00013250  39 00 00 01 */	li r8, 1
/* 80016674 00013254  48 37 90 61 */	bl HSD_DevComRequest
/* 80016678 00013258  BB 21 00 64 */	lmw r25, 0x64(r1)
/* 8001667C 0001325C  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80016680 00013260  38 21 00 80 */	addi r1, r1, 0x80
/* 80016684 00013264  7C 08 03 A6 */	mtlr r0
/* 80016688 00013268  4E 80 00 20 */	blr 

.global func_8001668C
func_8001668C:
/* 8001668C 0001326C  7C 08 02 A6 */	mflr r0
/* 80016690 00013270  3C C0 80 3C */	lis r6, lbl_803BA508@ha
/* 80016694 00013274  90 01 00 04 */	stw r0, 4(r1)
/* 80016698 00013278  38 00 00 00 */	li r0, 0
/* 8001669C 0001327C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800166A0 00013280  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 800166A4 00013284  3B E6 A5 08 */	addi r31, r6, lbl_803BA508@l
/* 800166A8 00013288  3B 64 00 00 */	addi r27, r4, 0
/* 800166AC 0001328C  3B 85 00 00 */	addi r28, r5, 0
/* 800166B0 00013290  90 0D AD 28 */	stw r0, cancel@sda21(r13)
/* 800166B4 00013294  4B FF FB 51 */	bl func_80016204
/* 800166B8 00013298  7C 7E 1B 78 */	mr r30, r3
/* 800166BC 0001329C  48 32 12 B1 */	bl DVDConvertPathToEntrynum
/* 800166C0 000132A0  3B A3 00 00 */	addi r29, r3, 0
/* 800166C4 000132A4  2C 1D FF FF */	cmpwi r29, -1
/* 800166C8 000132A8  40 82 00 28 */	bne lbl_800166F0
/* 800166CC 000132AC  38 9E 00 00 */	addi r4, r30, 0
/* 800166D0 000132B0  4C C6 31 82 */	crclr 6
/* 800166D4 000132B4  38 BD 00 00 */	addi r5, r29, 0
/* 800166D8 000132B8  38 7F 00 50 */	addi r3, r31, 0x50
/* 800166DC 000132BC  48 32 EF CD */	bl OSReport
/* 800166E0 000132C0  38 7F 00 00 */	addi r3, r31, 0
/* 800166E4 000132C4  38 BF 00 6C */	addi r5, r31, 0x6c
/* 800166E8 000132C8  38 80 01 1A */	li r4, 0x11a
/* 800166EC 000132CC  48 37 1B 35 */	bl __assert
lbl_800166F0:
/* 800166F0 000132D0  7F A3 EB 78 */	mr r3, r29
/* 800166F4 000132D4  4B FF FC 59 */	bl func_8001634C
/* 800166F8 000132D8  3C 00 80 00 */	lis r0, 0x8000
/* 800166FC 000132DC  90 7C 00 00 */	stw r3, 0(r28)
/* 80016700 000132E0  7C 1B 00 40 */	cmplw r27, r0
/* 80016704 000132E4  41 80 00 0C */	blt lbl_80016710
/* 80016708 000132E8  38 E0 00 21 */	li r7, 0x21
/* 8001670C 000132EC  48 00 00 08 */	b lbl_80016714
lbl_80016710:
/* 80016710 000132F0  38 E0 00 23 */	li r7, 0x23
lbl_80016714:
/* 80016714 000132F4  80 9C 00 00 */	lwz r4, 0(r28)
/* 80016718 000132F8  3C 60 80 01 */	lis r3, lbFile_8001615C@ha
/* 8001671C 000132FC  39 23 61 5C */	addi r9, r3, lbFile_8001615C@l
/* 80016720 00013300  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016724 00013304  38 7D 00 00 */	addi r3, r29, 0
/* 80016728 00013308  38 BB 00 00 */	addi r5, r27, 0
/* 8001672C 0001330C  54 06 00 34 */	rlwinm r6, r0, 0, 0, 0x1a
/* 80016730 00013310  38 80 00 00 */	li r4, 0
/* 80016734 00013314  39 00 00 01 */	li r8, 1
/* 80016738 00013318  39 40 00 00 */	li r10, 0
/* 8001673C 0001331C  48 37 8F 99 */	bl HSD_DevComRequest
lbl_80016740:
/* 80016740 00013320  4B FF FA 61 */	bl lbFile_800161A0
/* 80016744 00013324  2C 03 00 00 */	cmpwi r3, 0
/* 80016748 00013328  41 82 FF F8 */	beq lbl_80016740
/* 8001674C 0001332C  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 80016750 00013330  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80016754 00013334  38 21 00 30 */	addi r1, r1, 0x30
/* 80016758 00013338  7C 08 03 A6 */	mtlr r0
/* 8001675C 0001333C  4E 80 00 20 */	blr 

.global func_80016760
func_80016760:
/* 80016760 00013340  7C 08 02 A6 */	mflr r0
/* 80016764 00013344  3C C0 80 3C */	lis r6, lbl_803BA508@ha
/* 80016768 00013348  90 01 00 04 */	stw r0, 4(r1)
/* 8001676C 0001334C  38 00 00 00 */	li r0, 0
/* 80016770 00013350  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80016774 00013354  BF 41 00 18 */	stmw r26, 0x18(r1)
/* 80016778 00013358  3B 43 00 00 */	addi r26, r3, 0
/* 8001677C 0001335C  3B E6 A5 08 */	addi r31, r6, lbl_803BA508@l
/* 80016780 00013360  3B 84 00 00 */	addi r28, r4, 0
/* 80016784 00013364  3B 65 00 00 */	addi r27, r5, 0
/* 80016788 00013368  90 0D AD 28 */	stw r0, cancel@sda21(r13)
/* 8001678C 0001336C  4B FF FA 79 */	bl func_80016204
/* 80016790 00013370  7C 7E 1B 78 */	mr r30, r3
/* 80016794 00013374  48 32 11 D9 */	bl DVDConvertPathToEntrynum
/* 80016798 00013378  3B A3 00 00 */	addi r29, r3, 0
/* 8001679C 0001337C  2C 1D FF FF */	cmpwi r29, -1
/* 800167A0 00013380  40 82 00 28 */	bne lbl_800167C8
/* 800167A4 00013384  38 9E 00 00 */	addi r4, r30, 0
/* 800167A8 00013388  4C C6 31 82 */	crclr 6
/* 800167AC 0001338C  38 BD 00 00 */	addi r5, r29, 0
/* 800167B0 00013390  38 7F 00 50 */	addi r3, r31, 0x50
/* 800167B4 00013394  48 32 EE F5 */	bl OSReport
/* 800167B8 00013398  38 7F 00 00 */	addi r3, r31, 0
/* 800167BC 0001339C  38 BF 00 6C */	addi r5, r31, 0x6c
/* 800167C0 000133A0  38 80 00 EE */	li r4, 0xee
/* 800167C4 000133A4  48 37 1A 5D */	bl __assert
lbl_800167C8:
/* 800167C8 000133A8  7F A3 EB 78 */	mr r3, r29
/* 800167CC 000133AC  4B FF FB 81 */	bl func_8001634C
/* 800167D0 000133B0  90 7B 00 00 */	stw r3, 0(r27)
/* 800167D4 000133B4  38 60 00 00 */	li r3, 0
/* 800167D8 000133B8  80 9B 00 00 */	lwz r4, 0(r27)
/* 800167DC 000133BC  38 04 00 1F */	addi r0, r4, 0x1f
/* 800167E0 000133C0  54 04 00 34 */	rlwinm r4, r0, 0, 0, 0x1a
/* 800167E4 000133C4  4B FF F3 ED */	bl func_80015BD0
/* 800167E8 000133C8  90 7C 00 00 */	stw r3, 0(r28)
/* 800167EC 000133CC  7F 43 D3 78 */	mr r3, r26
/* 800167F0 000133D0  83 DC 00 00 */	lwz r30, 0(r28)
/* 800167F4 000133D4  4B FF FA 11 */	bl func_80016204
/* 800167F8 000133D8  7C 7D 1B 78 */	mr r29, r3
/* 800167FC 000133DC  48 32 11 71 */	bl DVDConvertPathToEntrynum
/* 80016800 000133E0  3B 83 00 00 */	addi r28, r3, 0
/* 80016804 000133E4  2C 1C FF FF */	cmpwi r28, -1
/* 80016808 000133E8  40 82 00 28 */	bne lbl_80016830
/* 8001680C 000133EC  38 9D 00 00 */	addi r4, r29, 0
/* 80016810 000133F0  4C C6 31 82 */	crclr 6
/* 80016814 000133F4  38 BC 00 00 */	addi r5, r28, 0
/* 80016818 000133F8  38 7F 00 50 */	addi r3, r31, 0x50
/* 8001681C 000133FC  48 32 EE 8D */	bl OSReport
/* 80016820 00013400  38 7F 00 00 */	addi r3, r31, 0
/* 80016824 00013404  38 BF 00 6C */	addi r5, r31, 0x6c
/* 80016828 00013408  38 80 01 1A */	li r4, 0x11a
/* 8001682C 0001340C  48 37 19 F5 */	bl __assert
lbl_80016830:
/* 80016830 00013410  7F 83 E3 78 */	mr r3, r28
/* 80016834 00013414  4B FF FB 19 */	bl func_8001634C
/* 80016838 00013418  3C 00 80 00 */	lis r0, 0x8000
/* 8001683C 0001341C  90 7B 00 00 */	stw r3, 0(r27)
/* 80016840 00013420  7C 1E 00 40 */	cmplw r30, r0
/* 80016844 00013424  41 80 00 0C */	blt lbl_80016850
/* 80016848 00013428  38 E0 00 21 */	li r7, 0x21
/* 8001684C 0001342C  48 00 00 08 */	b lbl_80016854
lbl_80016850:
/* 80016850 00013430  38 E0 00 23 */	li r7, 0x23
lbl_80016854:
/* 80016854 00013434  80 9B 00 00 */	lwz r4, 0(r27)
/* 80016858 00013438  3C 60 80 01 */	lis r3, lbFile_8001615C@ha
/* 8001685C 0001343C  39 23 61 5C */	addi r9, r3, lbFile_8001615C@l
/* 80016860 00013440  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016864 00013444  38 7C 00 00 */	addi r3, r28, 0
/* 80016868 00013448  38 BE 00 00 */	addi r5, r30, 0
/* 8001686C 0001344C  54 06 00 34 */	rlwinm r6, r0, 0, 0, 0x1a
/* 80016870 00013450  38 80 00 00 */	li r4, 0
/* 80016874 00013454  39 00 00 01 */	li r8, 1
/* 80016878 00013458  39 40 00 00 */	li r10, 0
/* 8001687C 0001345C  48 37 8E 59 */	bl HSD_DevComRequest
lbl_80016880:
/* 80016880 00013460  4B FF F9 21 */	bl lbFile_800161A0
/* 80016884 00013464  2C 03 00 00 */	cmpwi r3, 0
/* 80016888 00013468  41 82 FF F8 */	beq lbl_80016880
/* 8001688C 0001346C  BB 41 00 18 */	lmw r26, 0x18(r1)
/* 80016890 00013470  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80016894 00013474  38 21 00 30 */	addi r1, r1, 0x30
/* 80016898 00013478  7C 08 03 A6 */	mtlr r0
/* 8001689C 0001347C  4E 80 00 20 */	blr 

.global func_800168A0
func_800168A0:
/* 800168A0 00013480  7C 08 02 A6 */	mflr r0
/* 800168A4 00013484  3C E0 80 3C */	lis r7, lbl_803BA508@ha
/* 800168A8 00013488  90 01 00 04 */	stw r0, 4(r1)
/* 800168AC 0001348C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800168B0 00013490  BF 21 00 24 */	stmw r25, 0x24(r1)
/* 800168B4 00013494  3B 44 00 00 */	addi r26, r4, 0
/* 800168B8 00013498  3B 23 00 00 */	addi r25, r3, 0
/* 800168BC 0001349C  3B C7 A5 08 */	addi r30, r7, lbl_803BA508@l
/* 800168C0 000134A0  3B 65 00 00 */	addi r27, r5, 0
/* 800168C4 000134A4  3B E6 00 00 */	addi r31, r6, 0
/* 800168C8 000134A8  38 7A 00 00 */	addi r3, r26, 0
/* 800168CC 000134AC  48 00 18 D1 */	bl func_8001819C
/* 800168D0 000134B0  28 03 00 00 */	cmplwi r3, 0
/* 800168D4 000134B4  90 7B 00 00 */	stw r3, 0(r27)
/* 800168D8 000134B8  41 82 00 58 */	beq lbl_80016930
/* 800168DC 000134BC  7F 43 D3 78 */	mr r3, r26
/* 800168E0 000134C0  4B FF F9 25 */	bl func_80016204
/* 800168E4 000134C4  7C 7D 1B 78 */	mr r29, r3
/* 800168E8 000134C8  48 32 10 85 */	bl DVDConvertPathToEntrynum
/* 800168EC 000134CC  3B 83 00 00 */	addi r28, r3, 0
/* 800168F0 000134D0  2C 1C FF FF */	cmpwi r28, -1
/* 800168F4 000134D4  40 82 00 28 */	bne lbl_8001691C
/* 800168F8 000134D8  38 9D 00 00 */	addi r4, r29, 0
/* 800168FC 000134DC  4C C6 31 82 */	crclr 6
/* 80016900 000134E0  38 BC 00 00 */	addi r5, r28, 0
/* 80016904 000134E4  38 7E 00 50 */	addi r3, r30, 0x50
/* 80016908 000134E8  48 32 ED A1 */	bl OSReport
/* 8001690C 000134EC  38 7E 00 00 */	addi r3, r30, 0
/* 80016910 000134F0  38 BE 00 6C */	addi r5, r30, 0x6c
/* 80016914 000134F4  38 80 00 EE */	li r4, 0xee
/* 80016918 000134F8  48 37 19 09 */	bl __assert
lbl_8001691C:
/* 8001691C 000134FC  7F 83 E3 78 */	mr r3, r28
/* 80016920 00013500  4B FF FA 2D */	bl func_8001634C
/* 80016924 00013504  90 7F 00 00 */	stw r3, 0(r31)
/* 80016928 00013508  38 60 00 01 */	li r3, 1
/* 8001692C 0001350C  48 00 01 14 */	b lbl_80016A40
lbl_80016930:
/* 80016930 00013510  38 00 00 00 */	li r0, 0
/* 80016934 00013514  90 0D AD 28 */	stw r0, cancel@sda21(r13)
/* 80016938 00013518  7F 43 D3 78 */	mr r3, r26
/* 8001693C 0001351C  4B FF F8 C9 */	bl func_80016204
/* 80016940 00013520  7C 7C 1B 78 */	mr r28, r3
/* 80016944 00013524  48 32 10 29 */	bl DVDConvertPathToEntrynum
/* 80016948 00013528  3B A3 00 00 */	addi r29, r3, 0
/* 8001694C 0001352C  2C 1D FF FF */	cmpwi r29, -1
/* 80016950 00013530  40 82 00 28 */	bne lbl_80016978
/* 80016954 00013534  38 9C 00 00 */	addi r4, r28, 0
/* 80016958 00013538  4C C6 31 82 */	crclr 6
/* 8001695C 0001353C  38 BD 00 00 */	addi r5, r29, 0
/* 80016960 00013540  38 7E 00 50 */	addi r3, r30, 0x50
/* 80016964 00013544  48 32 ED 45 */	bl OSReport
/* 80016968 00013548  38 7E 00 00 */	addi r3, r30, 0
/* 8001696C 0001354C  38 BE 00 6C */	addi r5, r30, 0x6c
/* 80016970 00013550  38 80 00 EE */	li r4, 0xee
/* 80016974 00013554  48 37 18 AD */	bl __assert
lbl_80016978:
/* 80016978 00013558  7F A3 EB 78 */	mr r3, r29
/* 8001697C 0001355C  4B FF F9 D1 */	bl func_8001634C
/* 80016980 00013560  90 7F 00 00 */	stw r3, 0(r31)
/* 80016984 00013564  7F 23 CB 78 */	mr r3, r25
/* 80016988 00013568  80 9F 00 00 */	lwz r4, 0(r31)
/* 8001698C 0001356C  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016990 00013570  54 04 00 34 */	rlwinm r4, r0, 0, 0, 0x1a
/* 80016994 00013574  4B FF F2 3D */	bl func_80015BD0
/* 80016998 00013578  90 7B 00 00 */	stw r3, 0(r27)
/* 8001699C 0001357C  7F 43 D3 78 */	mr r3, r26
/* 800169A0 00013580  83 BB 00 00 */	lwz r29, 0(r27)
/* 800169A4 00013584  4B FF F8 61 */	bl func_80016204
/* 800169A8 00013588  7C 7C 1B 78 */	mr r28, r3
/* 800169AC 0001358C  48 32 0F C1 */	bl DVDConvertPathToEntrynum
/* 800169B0 00013590  3B 63 00 00 */	addi r27, r3, 0
/* 800169B4 00013594  2C 1B FF FF */	cmpwi r27, -1
/* 800169B8 00013598  40 82 00 28 */	bne lbl_800169E0
/* 800169BC 0001359C  38 9C 00 00 */	addi r4, r28, 0
/* 800169C0 000135A0  4C C6 31 82 */	crclr 6
/* 800169C4 000135A4  38 BB 00 00 */	addi r5, r27, 0
/* 800169C8 000135A8  38 7E 00 50 */	addi r3, r30, 0x50
/* 800169CC 000135AC  48 32 EC DD */	bl OSReport
/* 800169D0 000135B0  38 7E 00 00 */	addi r3, r30, 0
/* 800169D4 000135B4  38 BE 00 6C */	addi r5, r30, 0x6c
/* 800169D8 000135B8  38 80 01 1A */	li r4, 0x11a
/* 800169DC 000135BC  48 37 18 45 */	bl __assert
lbl_800169E0:
/* 800169E0 000135C0  7F 63 DB 78 */	mr r3, r27
/* 800169E4 000135C4  4B FF F9 69 */	bl func_8001634C
/* 800169E8 000135C8  3C 00 80 00 */	lis r0, 0x8000
/* 800169EC 000135CC  90 7F 00 00 */	stw r3, 0(r31)
/* 800169F0 000135D0  7C 1D 00 40 */	cmplw r29, r0
/* 800169F4 000135D4  41 80 00 0C */	blt lbl_80016A00
/* 800169F8 000135D8  38 E0 00 21 */	li r7, 0x21
/* 800169FC 000135DC  48 00 00 08 */	b lbl_80016A04
lbl_80016A00:
/* 80016A00 000135E0  38 E0 00 23 */	li r7, 0x23
lbl_80016A04:
/* 80016A04 000135E4  80 9F 00 00 */	lwz r4, 0(r31)
/* 80016A08 000135E8  3C 60 80 01 */	lis r3, lbFile_8001615C@ha
/* 80016A0C 000135EC  39 23 61 5C */	addi r9, r3, lbFile_8001615C@l
/* 80016A10 000135F0  38 04 00 1F */	addi r0, r4, 0x1f
/* 80016A14 000135F4  38 7B 00 00 */	addi r3, r27, 0
/* 80016A18 000135F8  38 BD 00 00 */	addi r5, r29, 0
/* 80016A1C 000135FC  54 06 00 34 */	rlwinm r6, r0, 0, 0, 0x1a
/* 80016A20 00013600  38 80 00 00 */	li r4, 0
/* 80016A24 00013604  39 00 00 01 */	li r8, 1
/* 80016A28 00013608  39 40 00 00 */	li r10, 0
/* 80016A2C 0001360C  48 37 8C A9 */	bl HSD_DevComRequest
lbl_80016A30:
/* 80016A30 00013610  4B FF F7 71 */	bl lbFile_800161A0
/* 80016A34 00013614  2C 03 00 00 */	cmpwi r3, 0
/* 80016A38 00013618  41 82 FF F8 */	beq lbl_80016A30
/* 80016A3C 0001361C  38 60 00 00 */	li r3, 0
lbl_80016A40:
/* 80016A40 00013620  BB 21 00 24 */	lmw r25, 0x24(r1)
/* 80016A44 00013624  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80016A48 00013628  38 21 00 40 */	addi r1, r1, 0x40
/* 80016A4C 0001362C  7C 08 03 A6 */	mtlr r0
/* 80016A50 00013630  4E 80 00 20 */	blr 


.section .data

.global lbl_803BA508
lbl_803BA508:
    .asciz "lbfile.c"
    .balign 4

.global lbl_803BA514
lbl_803BA514:
    .asciz "!cancelflag"
    .balign 4
    
.global lbl_803BA520
lbl_803BA520:
    .asciz "Error : file name too long %s."
    .balign 4

.global lbl_803BA540
lbl_803BA540:
    .asciz "Cannot open file no=%d."
    .balign 4
    .asciz "file isn't exist %s = %d\n"
    .balign 4
    .asciz "entry_num != -1"
    .balign 4
    .4byte NULL


.section .bss, "wa"

.global lbl_80432058
lbl_80432058:
	.skip 0x20


.section .sdata

.global lbl_804D37A8
lbl_804D37A8:
    .asciz "NULL"
    .balign 4
.global lbl_804D37B0
lbl_804D37B0:
    .asciz "usd"
    .balign 4
.global lbl_804D37B4
lbl_804D37B4:
    .asciz "dat"
    .balign 4
.global lbl_804D37B8
lbl_804D37B8:
    .asciz "0"
    .balign 4
    .4byte NULL


.section .sbss

.global cancel
cancel:
	.skip 0x8
