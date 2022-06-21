/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static CommandFixture sc;

TEST(TestGameCalcDirSound, Basic1)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_EIGHT);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic2)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_RIGHT, &pos_b, &pos_a),
        TILE_TWO);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic3)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_DOWN, &pos_b, &pos_a),
        TILE_FOUR);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic4)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_LEFT, &pos_b, &pos_a),
        TILE_SIX);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic5)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 5};
    pos_t pos_b = {8, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic6)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 6};
    pos_t pos_b = {8, 5};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic7)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 6};
    pos_t pos_b = {8, 5};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_DOWN, &pos_b, &pos_a),
        TILE_SEVEN);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic8)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {5, 8};
    pos_t pos_b = {6, 3};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_FIVE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, Basic9)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {6, 3};
    pos_t pos_b = {5, 8};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_ONE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, SameAxe1)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {7, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_FIVE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, SameAxe2)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {7, 6};
    pos_t pos_b = {7, 9};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_ONE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, SameAxe3)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {6, 7};
    pos_t pos_b = {9, 7};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_SEVEN);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestGameCalcDirSound, SameAxe4)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {9, 7};
    pos_t pos_b = {6, 7};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 3;
    core->game->map->height = 3;
}

TEST(TestCommandBroadCast, Basic)
{
    char *msg = strdup("MESSAGE");

    sc.startTest();
    broadcast_e(sc.getCore(), sc.getClient(), msg);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ok\n");
    EXPECT_EQ(sc.getResOtherCli(), "message 4, MESSAGE\n");

    free(msg);
}

TEST(TestTakeCast, Basic)
{
    char *param = strdup(" food");

    GET_CELL(sc.getCore()->game->map, sc.getClient()->trantorian->pos.x, sc.getClient()->trantorian->pos.y)->food = 1;

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ok\n");

    free(param);
}

TEST(TestTakeCast, Error1)
{
    char *param = strdup("");

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ko\n");

    free(param);
}

TEST(TestTakeCast, Error2)
{
    char *param = strdup(" food");

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ko\n");

    free(param);
}

TEST(TestSetCast, Basic)
{
    char *param = strdup(" food");

    GET_CELL(sc.getCore()->game->map, sc.getClient()->trantorian->pos.x, sc.getClient()->trantorian->pos.y)->food = 1;

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ok\n");

    free(param);
}

TEST(TestSetCast, Error1)
{
    char *param = strdup("");

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ko\n");

    free(param);
}

TEST(TestSetCast, Error2)
{
    char *param = strdup(" food");

    sc.startTest();
    take_e(sc.getCore(), sc.getClient(), param);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ko\n");

    free(param);
}

TEST(TestCommandLook, Basic)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_UP;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player , , , ]\n");
}

TEST(TestCommandLook, WithMapElem1)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_UP;

    GET_CELL(sc.getCore()->game->map, 0, 0)->food = 1;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player food , , , ]\n");

    GET_CELL(sc.getCore()->game->map, 0, 0)->food = 0;
}

TEST(TestCommandLook, WithMapElem2)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_UP;

    GET_CELL(sc.getCore()->game->map, 0, 1)->food = 1;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player , , food , ]\n");
}

TEST(TestCommandLook, WithMapElem3)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_RIGHT;

    GET_CELL(sc.getCore()->game->map, 1, 0)->food = 1;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player , , food , ]\n");
}

TEST(TestCommandLook, WithMapElem4)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_DOWN;

    GET_CELL(sc.getCore()->game->map, 0, 2)->food = 1;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player , , food , player ]\n"); // self
}

TEST(TestCommandLook, WithMapElem5)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_LEFT;

    GET_CELL(sc.getCore()->game->map, 2, 0)->food = 1;

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "[player , player , food , ]\n"); // other player
}

TEST(TestCommandLook, WithMapElems)
{
    POS_X(sc.getClient()) = 0;
    POS_Y(sc.getClient()) = 0;

    sc.getClient()->trantorian->level = 1;
    sc.getClient()->trantorian->direction = DIR_UP;

    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);
    game_dispatch_ressources(sc.getCore()->game->map);

    sc.startTest();
    look_e(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    EXPECT_TRUE(sc.getRes() != "[player , , , ]\n");
}
