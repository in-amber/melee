#ifndef _lbarchive_h_
#define _lbarchive_h_

#include <dolphin/types.h>

#include <sysdolphin/baselib/archive.h>

void lbArchive_InitializeDAT(HSD_Archive* archive, u8* data, u32 length);
void func_80016EFC();
void func_80016BE0();

void func_80016C64(char*, void**, char*, s32, ...);
void* func_80016DBC(void*, ...);
s32 func_800171CC(void*, ...);
void func_80016AF0(void);

#endif
