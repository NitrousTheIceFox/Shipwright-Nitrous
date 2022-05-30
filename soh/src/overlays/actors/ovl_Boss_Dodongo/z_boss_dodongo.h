#ifndef Z_BOSS_DODONGO_H
#define Z_BOSS_DODONGO_H

#include "ultra64.h"
#include "global.h"

struct BossDodongo;

typedef void (*BossDodongoActionFunc)(struct BossDodongo*, GlobalContext*);

typedef struct {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ Color_RGB8 color;
    /* 0x2A */ s16 alpha;
    /* 0x2C */ f32 unk_2C;
} BossDodongoEffect; // Size = 0x30

typedef struct BossDodongo {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ BossDodongoActionFunc actionFunc;
    /* 0x0194 */ s16 health;
    /* 0x0196 */ s16 unk_196;
    /* 0x0198 */ s16 unk_198;
    /* 0x019A */ s16 unk_19A;
    /* 0x019C */ s16 csState;
    /* 0x019E */ s16 unk_19E;
    /* 0x01A0 */ s16 unk_1A0;
    /* 0x01A2 */ s16 unk_1A2;
    /* 0x01A4 */ s16 unk_1A4;
    /* 0x01A6 */ s16 unk_1A6;
    /* 0x01A8 */ s16 numWallCollisions;
    /* 0x01AA */ s16 unk_1AA;
    /* 0x01AC */ s16 unk_1AC;
    /* 0x01AE */ s16 unk_1AE;
    /* 0x01B0 */ s16 unk_1B0;
    /* 0x01B2 */ char unk_1B2[0x2];
    /* 0x01B4 */ s16 cutsceneCamera;
    /* 0x01B6 */ s16 unk_1B6;
    /* 0x01B8 */ s16 playerYawInRange;
    /* 0x01BA */ s16 playerPosInRange;
    /* 0x01BC */ s16 unk_1BC;
    /* 0x01BE */ s16 unk_1BE;
    /* 0x01C0 */ s16 unk_1C0;
    /* 0x01C2 */ s16 unk_1C2;
    /* 0x01C4 */ s16 unk_1C4; // Some kind of angle
    /* 0x01C6 */ s16 unk_1C6;
    /* 0x01C8 */ s16 unk_1C8;
    /* 0x01CA */ char unk_1CA[0x2];
    /* 0x01CC */ s16 unk_1CC;
    /* 0x01CE */ char unk_1CE[0xC];
    /* 0x01DA */ s16 unk_1DA;
    /* 0x01DC */ s16 unk_1DC;
    /* 0x01DE */ s16 unk_1DE;
    /* 0x01E0 */ s16 unk_1E0;
    /* 0x01E2 */ u8 unk_1E2;
    /* 0x01E3 */ s8 unk_1E3;
    /* 0x01E4 */ f32 unk_1E4;
    /* 0x01E8 */ f32 unk_1E8;
    /* 0x01EC */ f32 unk_1EC;
    /* 0x01F0 */ char unk_1F0[0x8];
    /* 0x01F8 */ f32 unk_1F8;
    /* 0x01FC */ f32 unk_1FC;
    /* 0x0200 */ f32 unk_200;
    /* 0x0204 */ f32 unk_204;
    /* 0x0208 */ f32 unk_208;
    /* 0x020C */ f32 unk_20C;
    /* 0x0210 */ f32 colorFilterR;
    /* 0x0214 */ f32 colorFilterG;
    /* 0x0214 */ f32 colorFilterB;
    /* 0x021C */ f32 colorFilterMin;
    /* 0x0220 */ f32 colorFilterMax;
    /* 0x0224 */ f32 unk_224;
    /* 0x0228 */ f32 unk_228;
    /* 0x022C */ f32 unk_22C;
    /* 0x0230 */ f32 unk_230;
    /* 0x0234 */ f32 unk_234;
    /* 0x0238 */ f32 unk_238;
    /* 0x023C */ f32 unk_23C;
    /* 0x0240 */ f32 unk_240;
    /* 0x0244 */ f32 unk_244;
    /* 0x0248 */ char unk_248[0x14];
    /* 0x025C */ f32 unk_25C[50];
    /* 0x0324 */ f32 unk_324[50];
    /* 0x03EC */ Vec3f vec;
    /* 0x03F8 */ Vec3f firePos;
    /* 0x0404 */ Vec3f unk_404;
    /* 0x0410 */ Vec3f unk_410;
    /* 0x041C */ Vec3f mouthPos;
    /* 0x0428 */ Vec3f cameraEye;
    /* 0x0434 */ Vec3f cameraAt;
    /* 0x0440 */ ColliderJntSph collider;
    /* 0x0460 */ ColliderJntSphElement items[19];
    /* 0x0920 */ BossDodongoEffect effects[80];

    s16 canEatPlayer;
    s16 bitingPlayer; // used for sounds and damage.
    s16 playerBelly;  // also used for sound and damage.
    s16 hasPlayer;
    s16 grabTimer;
    f32 swallowOffset;
    s16 ocTimer;    // Button Mash? CORRECTION: Time before collision / hitbox can be made again.
    s16 MunchTimer; // for munching sound.

    u8 eatenShield;
    /* 0x0373 */ u8 eatenTunic;

    s16 LinkNotBomb; // Used as a variable for checking if Link was eaten and not the bomb.

    s16 frameCount;    // used for sound loop rate.
    s16 LinkSwallowed; // Is Link in Dodongo's Belly?
    s16 invincibilityTimer;
    s16 swallowTimer; // Time Player has left before Link is swallowed.
    s16 spittingout;  // is King Dodongo going to spit Link out? (finished bunching or keeping link in his belly?)
    s16 grab;         // is King Dodongo holding Link?
    s16 stoploop;     // stop the looping in AteExplosive.
    s16 stoppingloop; // used to make the loop go one last time to set stop loop, to also execute the inhale without it
                      // doing the biting effect..

} BossDodongo; // size = 0x1820

#endif
