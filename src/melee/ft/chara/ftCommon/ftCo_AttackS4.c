#include <platform.h>
#include "ft/forward.h"
#include "ftCommon/forward.h"

#include "ftCo_AttackS4.h"

#include "ftCo_08A6.h"
#include "ftCo_Attack1.h"
#include "ftCo_AttackHi3.h"
#include "ftCo_AttackLw3.h"
#include "ftCo_AttackS3.h"

#include "ef/eflib.h"
#include "ft/fighter.h"
#include "ft/ft_081B.h"
#include "ft/ft_0877.h"
#include "ft/ft_08A4.h"
#include "ft/ftcommon.h"
#include "ft/ftdata.h"
#include "ftGameWatch/ftGw_AttackS4.h"
#include "ftNess/ftNs_AttackS4.h"
#include "ftPeach/ftPe_AttackS4.h"

#include <common_structs.h>
#include <placeholder.h>

typedef enum cmd_var_idx {
    cmd_unk0_bool,
} cmd_var_idx;

/* 08C22C */ static bool checkItemThrow(ftCo_GObj* gobj, float stick_x_sign);
/* 08C348 */ static void decideFighter(ftCo_GObj* gobj, float stick_x_sign,
                                       float stick_angle);
/* 08C3E0 */ static void doEnter(ftCo_GObj* gobj, float stick_angle);

static bool checkLStick(Fighter* fp)
{
    if (fp->input.x668 & HSD_Pad_A &&
        ABS(fp->input.lstick.x) >= p_ftCommonData->x3C &&
        fp->x670_timer_lstick_tilt_x < p_ftCommonData->x40)
    {
        return true;
    }
    return false;
}

bool ftCo_AttackS4_CheckInput(ftCo_GObj* gobj)
{
    float stick_x_sign, stick_angle;
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    if (checkLStick(fp)) {
        stick_x_sign = fp->input.lstick.x >= 0 ? (float) +1 : -1;
        stick_angle = ftCo_GetLStickAngle(fp);
    } else if (ft_800DF1C8(fp)) {
        stick_x_sign = fp->input.cstick.x >= 0 ? (float) +1 : -1;
        stick_angle = ftCo_GetCStickAngle(fp);
    } else {
        return false;
    }
    if (checkItemThrow(gobj, stick_x_sign)) {
        return true;
    }
    decideFighter(gobj, stick_x_sign, stick_angle);
    return true;
}

static bool checkFacingDir(Fighter* fp)
{
    if (fp->input.x668 & HSD_Pad_A &&
        fp->input.lstick.x * fp->facing_dir >= p_ftCommonData->x3C)
    {
        return true;
    } else {
        return false;
    }
}

/// @todo Can maybe be combined with #ftCo_AttackS4_CheckInput
bool ftCo_AttackS4_8008C114(ftCo_GObj* gobj)
{
    float stick_x_sign, stick_angle;
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    if (checkFacingDir(fp)) {
        stick_x_sign = fp->facing_dir;
        stick_angle = ftCo_GetLStickAngle(fp);
    } else if (ft_800DF1C8(fp)) {
        stick_x_sign = fp->input.cstick.x >= 0 ? (float) +1 : -1;
        stick_angle = ftCo_GetCStickAngle(fp);
    } else {
        return false;
    }
    if (checkItemThrow(gobj, stick_x_sign)) {
        return true;
    }
    decideFighter(gobj, stick_x_sign, stick_angle);
    return true;
}

static bool checkItemThrow(ftCo_GObj* gobj, float stick_x_sign)
{
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    if (fp->item_gobj != NULL) {
        if (fp->input.held_inputs & HSD_Pad_LR ||
            it_8026B30C(fp->item_gobj) == 0 ||
            (it_8026B30C(fp->item_gobj) == 3 && it_8026B594(fp->item_gobj)) ||
            ft_800DF21C(fp))
        {
            ft_800957F4(gobj, stick_x_sign * fp->facing_dir >= 0
                                  ? ftCo_MS_LightThrowF4
                                  : ftCo_MS_LightThrowB4);
            return true;
        }
        switch (it_8026B30C(fp->item_gobj)) {
        case 2:
            fp->facing_dir = stick_x_sign;
            ftCo_Attack_800CCF58(gobj, 2);
            return true;
        case 3:
            fp->facing_dir = stick_x_sign;
            ftCo_Attack_800CDD14(gobj);
            return true;
        }
    }
    return false;
}

void decideFighter(HSD_GObj* gobj, float stick_x_sign, float stick_angle)
{
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    fp->facing_dir = stick_x_sign;
    switch (fp->kind) {
    case FTKIND_NESS:
        ftNs_AttackS4_Enter(gobj);
        return;
    case FTKIND_PEACH:
        ftPe_AttackS4_Enter(gobj);
        return;
    case FTKIND_GAMEWATCH:
        ftGw_AttackS4_Enter(gobj);
        return;
    case FTKIND_PIKACHU:
    case FTKIND_PICHU:
        doEnter(gobj, stick_angle);
        fp->cb.x21D4_callback_EnterHitlag = efLib_PauseAll;
        fp->cb.x21D8_callback_ExitHitlag = efLib_ResumeAll;
        return;
    default:
        doEnter(gobj, stick_angle);
        return;
    }
}

static void doEnter(ftCo_GObj* gobj, float stick_angle)
{
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    FtMotionId msid;
    if (stick_angle > p_ftCommonData->xB8 &&
        ftData_80085FD4(fp, ftCo_MS_AttackS4S)->x8 != NULL)
    {
        msid = ftCo_MS_AttackS4Hi;
    } else if (stick_angle > p_ftCommonData->xBC &&
               ftData_80085FD4(fp, ftCo_MS_AttackS4LwS)->x8 != NULL)
    {
        msid = ftCo_MS_AttackS4HiS;
    } else if (stick_angle < p_ftCommonData->xC4 &&
               ftData_80085FD4(fp, ftCo_MS_AttackLw4)->x8 != NULL)
    {
        msid = ftCo_MS_AttackS4Lw;
    } else if (stick_angle < p_ftCommonData->xC0 &&
               ftData_80085FD4(fp, ftCo_MS_AttackHi4)->x8 != NULL)
    {
        msid = ftCo_MS_AttackS4LwS;
    } else {
        msid = ftCo_MS_AttackS4S;
    }
    fp->allow_interrupt = false;
    fp->cmd_vars[cmd_unk0_bool] = false;
    fp->throw_flags.flags = 0;
    Fighter_ChangeMotionState(gobj, msid, Ft_MF_None, NULL, 0, 1, 0);
    ftAnim_8006EBA4(gobj);
}

void ftCo_AttackS4_Anim(ftCo_GObj* gobj)
{
    if (!ftAnim_IsFramesRemaining(gobj)) {
        ft_8008A2BC(gobj);
    }
}

void ftCo_AttackS4_IASA(HSD_GObj* gobj)
{
    ftCo_Fighter* fp = GET_FIGHTER(gobj);
    if (fp->allow_interrupt) {
        GUARD(ft_80096540(gobj))
        GUARD(ftCo_Attack100_CheckInput(gobj))
        GUARD(ft_800D6824(gobj))
        GUARD(ft_800D68C0(gobj))
        GUARD(ftCo_Catch_CheckInput(gobj))
    }
    GUARD(ftCo_800CECE8(gobj))
    if (fp->allow_interrupt) {
        GUARD(ftCo_AttackS4_CheckInput(gobj))
        GUARD(ftCo_AttackHi4_CheckInput(gobj))
        GUARD(ftCo_AttackLw4_CheckInput(gobj))
        GUARD(ftCo_AttackS3_CheckInput(gobj))
        GUARD(ftCo_AttackHi3_CheckInput(gobj))
        GUARD(ftCo_AttackLw3_CheckInput(gobj))
        GUARD(ftCo_Attack1_CheckInput(gobj))
        GUARD(ft_80091A4C(gobj))
        GUARD(ft_800DE9D8(gobj))
        GUARD(ftCo_Jump_CheckInput(gobj))
        GUARD(ftCo_Dash_CheckInput(gobj))
        GUARD(ft_800D5FB0(gobj))
        GUARD(ftCo_Turn_CheckInput(gobj))
        GUARD(ftCo_Walk_CheckInput(gobj))
    }
}

void ftCo_AttackS4_Phys(ftCo_GObj* gobj)
{
    ft_80084FA8(gobj);
}

void ftCo_AttackS4_Coll(ftCo_GObj* gobj)
{
    ft_80084104(gobj);
}
