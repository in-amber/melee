#include "itkinoko.h"

#include "it/inlines.h"
#include "it/it_266F.h"
#include "it/it_26B1.h"
#include "it/it_2725.h"
#include "it/item.h"

ItemStateTable it_803F6110[] = {
    { 0, it_80293754, it_8029375C, it_80293798 },
    { 0, it_802938AC, it_802938B4, it_80293964 },
};

HSD_AnimJoint* it_80293660(int idx)
{
    KinokoAnim* attrs = it_804D6D24[It_Kind_Kinoko]->x4_specialAttributes;
    return attrs[idx + 2].joint;
}

void it_8029367C(Item_GObj* gobj)
{
    Item* it;

    it = GET_ITEM(gobj);
    if (it->pos.x > 0.0f) {
        it->facing_dir = -1.0f;
    } else {
        it->facing_dir = 1.0f;
    }
    it->xD5C = 0;
    it->xDD4_itemVar.kinoko.x0 = 0.0f;
    it->xDD4_itemVar.kinoko.x4.x = 0.0f;
    it->xDD4_itemVar.kinoko.x4.y = 1.0f;
    it->xDD4_itemVar.kinoko.x4.z = 0.0f;
    it_8029385C(gobj);
}

void it_802936E4(Item_GObj* gobj)
{
    Item* it = GET_ITEM(gobj);
    PAD_STACK(8);

    it->x40_vel.x = it->xDD4_itemVar.kinoko.x0;
    it->x40_vel.y = it->x40_vel.z = 0.0f;

    it_8026B390(gobj);
    Item_8026AE84(it, 0x107, 0x7F, 0x40);
    Item_80268E5C(gobj, 0, ITEM_UNK_0x1 | ITEM_HIT_PRESERVE);
}

bool it_80293754(Item_GObj* gobj)
{
    return false;
}

void it_8029375C(Item_GObj* gobj)
{
    Item* it = GET_ITEM(gobj);
    KinokoAttrs* attrs = it->xC4_article_data->x4_specialAttributes;
    if (it->ground_or_air != GA_Air) {
        it->xDD4_itemVar.kinoko.x0 = attrs->x0 * it->facing_dir;
        it->x40_vel.x =
            it->xDD4_itemVar.kinoko.x0 * it->xDD4_itemVar.kinoko.x4.y;
    }
}

bool it_80293798(Item_GObj* gobj)
{
    Item* it = GET_ITEM(gobj);
    CollData* cd = &it->x378_itemColl;
    PAD_STACK(16);

    it_8026D78C(gobj, it_80293884);
    if (it->ground_or_air != GA_Air) {
        if ((cd->env_flags & MPCOLL_UNK)) {
            it_80276408(gobj, cd, &it->xDD4_itemVar.kinoko.x4);
        } else {
            it->xDD4_itemVar.kinoko.x4.x = 0.0f;
        }
        if ((cd->env_flags & MPCOLL_RIGHTWALL) ||
            (cd->env_flags & MPCOLL_LEFTWALL))
        {
            it->facing_dir = -it->facing_dir;
            it->xDD4_itemVar.kinoko.x0 = -it->xDD4_itemVar.kinoko.x0;
            it->x40_vel.x =
                it->xDD4_itemVar.kinoko.x0 * it->xDD4_itemVar.kinoko.x4.y;
        }
    }
    return 0;
}

void it_8029385C(Item_GObj* gobj)
{
    Item_80268E5C(gobj, 1, ITEM_ANIM_UPDATE);
}

void it_80293884(Item_GObj* gobj)
{
    Item_80268E5C(gobj, 1, ITEM_UNK_0x1 | ITEM_HIT_PRESERVE);
}

bool it_802938AC(Item_GObj* gobj)
{
    return false;
}

void it_802938B4(Item_GObj* gobj)
{
    f32 vel;
    Item* it = GET_ITEM(gobj);
    ItemAttr* attr = it->xCC_item_attr;
    KinokoAttrs* sa = it->xC4_article_data->x4_specialAttributes;

    it_80272860(gobj, attr->x10_fall_speed, attr->x14_fall_speed_max);

    if (it->x40_vel.x < 0.0f) {
        vel = -it->x40_vel.x;
    } else {
        vel = it->x40_vel.x;
    }

    if (vel < sa->x4) {
        it->x40_vel.x = 0.0f;
        return;
    } else if (it->x40_vel.x > 0.0f) {
        it->x40_vel.x -= sa->x4;
    }
    if (it->x40_vel.x < 0.0f) {
        it->x40_vel.x += sa->x4;
    }
}

bool it_80293964(Item_GObj* gobj)
{
    Item* it = GET_ITEM(gobj);
    CollData* cd = &it->x378_itemColl;

    it_8026E7E0(gobj, it_802936E4);
    if (it->ground_or_air != GA_Air && (cd->env_flags & MPCOLL_UNK)) {
        it_80276408(gobj, cd, &it->xDD4_itemVar.kinoko.x4);
    }
    return false;
}

bool it_802939E0(Item_GObj* gobj)
{
    return true;
}

void it_802939E8(Item_GObj* gobj, HSD_GObj* gobj_2)
{
    it_8026B894(gobj, gobj_2);
}
