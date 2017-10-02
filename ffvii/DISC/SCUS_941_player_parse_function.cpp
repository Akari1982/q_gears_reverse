////////////////////////////////
// system_add_status_protect()

party_id = A0;
status_protect_mask = A1;

[8009d84c + party_id * 440 + 48] = w(w[8009d84c + party_id * 440 + 48] | status_protect_mask);
////////////////////////////////



////////////////////////////////
// system_add_status_protect_bit()

party_id = A0
protect_status_id = A1;

if( A1 < 41 )
{
    [8009d84c + party_id * 440 + 48] = w(w[8009d84c + party_id * 440 + 48] | (1 << protect_status_id));
}
////////////////////////////////



////////////////////////////////
// system_add_elemental_defense()

party_id = A0;
type = A1;
element_mask = A2;

if( type == 0 )
{
    [8009d84c + party_id * 440 + 42] = h(hu[8009d84c + party_id * 440 + 42] | element_mask);
}
else if( type == 1 )
{
    [8009d84c + party_id * 440 + 40] = h(hu[8009d84c + party_id * 440 + 40] | element_mask);
}
else if( type == 2 )
{
    [8009d84c + party_id * 440 + 3e] = h(hu[8009d84c + party_id * 440 + 3e] | element_mask);
}
////////////////////////////////



////////////////////////////////
// system_add_stats()

party_id = A0;
stat_id = A1;
amount = A2;

switch( stat_id )
{
    case 0: [8009d84c + A0 * 440 + 2] = b(bu[8009d84c + party_id * 440 + 2] + amount); break;
    case 1: [8009d84c + A0 * 440 + 3] = b(bu[8009d84c + party_id * 440 + 3] + amount); break;
    case 2: [8009d84c + A0 * 440 + 4] = b(bu[8009d84c + party_id * 440 + 4] + amount); break;
    case 3: [8009d84c + A0 * 440 + 5] = b(bu[8009d84c + party_id * 440 + 5] + amount); break;
    case 4: [8009d84c + A0 * 440 + 6] = b(bu[8009d84c + party_id * 440 + 6] + amount); break;
    case 5: [8009d84c + A0 * 440 + 7] = b(bu[8009d84c + party_id * 440 + 7] + amount); break;
}
////////////////////////////////



////////////////////////////////
// system_add_status_attack_bit()

party_id = A0;
attack_status_id = A1;

if( attack_status_mask < 41 )
{
    [8009d84c + party_id * 440 + 44] = w(w[8009d84c + party_id * 440 + 44] | (1 << attack_status_id));
}
////////////////////////////////



////////////////////////////////
// system_add_attack_type()

party_id = A0;
attack_element_mask = A1;

[8009d84c + party_id * 440 + 3c] = h(hu[8009d84c + party_id * 440 + 3c] | attack_element_mask);
////////////////////////////////



////////////////////////////////
// system_add_materia_equip_stat_bonus()

materia_id = A0;

equip_eff_id = bu[800730d0 + materia_id * 14 + 8];
if( equip_eff_id != ff )
{
    if( bu[GP + 2dc] == 0 ) // battle
    {
        [800694fc] = h(hu[800694fc] + hu[80049060 + equip_eff_id * 10 + 0]); // strength modifier
        [800694fe] = h(hu[800694fe] + hu[80049060 + equip_eff_id * 10 + 2]); // vitality modifier
        [80069500] = h(hu[80069500] + hu[80049060 + equip_eff_id * 10 + 4]); // magic modifier
        [80069502] = h(hu[80069502] + hu[80049060 + equip_eff_id * 10 + 6]); // spirit modifier
        [80069504] = h(hu[80069504] + hu[80049060 + equip_eff_id * 10 + 8]); // luck modifier
        [80069506] = h(hu[80069506] + hu[80049060 + equip_eff_id * 10 + a]); // dexterity modifier
        [800694f4] = h(hu[800694f4] + hu[80049060 + equip_eff_id * 10 + c]); // max hp modifier
        [800694f6] = h(hu[800694f6] + hu[80049060 + equip_eff_id * 10 + e]); // max mp modifier
    }
    else // menu
    {
        V0 = w[GP + 238];
        [V0 + 0a] = h(hu[80049060 + equip_eff_id * 10 + 0]);
        [V0 + 0c] = h(hu[80049060 + equip_eff_id * 10 + 2]);
        [V0 + 0e] = h(hu[80049060 + equip_eff_id * 10 + 4]);
        [V0 + 10] = h(hu[80049060 + equip_eff_id * 10 + 6]);
        [V0 + 12] = h(hu[80049060 + equip_eff_id * 10 + 8]);
        [V0 + 14] = h(hu[80049060 + equip_eff_id * 10 + a]);
        [V0 + 16] = h(hu[80049060 + equip_eff_id * 10 + c]);
        [V0 + 18] = h(hu[80049060 + equip_eff_id * 10 + e]);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X0()

materia_param = A0;
materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( materia_param == 0 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_00();
}
if( materia_param == 2 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_20();
}
if( materia_param == 3 )
{
    A0 = stars;
    A1 = materia_id;
    system_add_materia_30();
}
if( materia_param == 4 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_40();
}
////////////////////////////////



////////////////////////////////
// system_add_materia_00()

materia_id = A0;
materia_exp = A1;

if( bu[GP + 2dc] == 0 ) // battle
{
    unit_structure = w[GP + 11c];

    V1 = bu[800730d0 + materia_id * 14 + e];
    if( V1 == c ) // underwater
    {
        [unit_structure + 23] = b(bu[unit_structure + 23] | 1);
    }
    else if( V1 == 62 ) // hp<->mp
    {
        [unit_structure + 23] = b(bu[unit_structure + 23] | 8);
    }
}
else // menu
{
    V1 = bu[800730d0 + materia_id * 14 + e];
    if (V1 == c || V1 == 62)
    {
        [GP + 2b8] = b(11);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_materia_20()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( materia_id == d ) // counter attack
{
    A0 = stars;
    A1 = d;
    system_add_materia_counter_attack();
}
else
{
    if( bu[GP + 2dc] == 0 ) // battle
    {
        modifier = bu[800730d0 + materia_id * 14 + e];
        [800694e4 + modifier * 2] = h(hu[800694e4 + modifier * 2] + bu[800730d0 + materia_id * 14 + e + stars]);
    }
    else // menu
    {
        A0 = w[GP + 238];
        [A0 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
        [A0 + 1b] = b(bu[800730d0 + materia_id * 14 + e + stars]);

        [GP + 2b8] = b(4);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_materia_counter_attack()

number_of_star = A0;
materia_id = A1;

if( bu[GP + 2dc] == 0 ) // battle
{
    A0 = w[GP + 13c];
    if( A0 != 8 )
    {
        unit_structure = w[GP + 11c];
        [unit_structure + A0 * 3 + 24] = b(9);
        [unit_structure + A0 * 3 + 25] = b(9);
        [unit_structure + A0 * 3 + 26] = b(bu[800730d0 + materia_id * 14 + e + number_of_star]); // counter_value
        [GP + 13c] = w(w[GP + 13c] + 1);
    }
}
else // menu
{
    [GP + 2b8] = b(12);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_30()

stars = A0;
materia_id = A1;

if( materia_id == b )
{
    system_add_materia_long_range();
}
////////////////////////////////



////////////////////////////////
// system_add_materia_long_range()

if( bu[GP + 2dc] == 0 ) // battle
{
    unit_structure = bu[GP + 11c];
    [unit_structure + 23] = b(bu[unit_structure + 23] | 4);
}
else // menu
{
    [GP + 2b8] = b(12);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_40()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( stars > 0 )
{
    for( int i = stars; i >= 0; --i )
    {
        mod_value = bu[800730d0 + materia_id * 14 + e + i];
        if( mod_value != ff )
        {
            break;
        }
    }
}

if( bu[GP + 2dc] == 0 ) // battle
{
    modifier = bu[800730d0 + materia_id * 14 + e];
    [800694e4 + modifier * 2] = h(hu[800694e4 + modifier * 2] + mod_value);
}
else // menu
{
    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [V1 + 1b] = b(mod_value);
    [GP + 2b8] = b(d);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X1()

materia_param = A0;
materia_id = A1;
materia_exp = A2;

if( materia_param == 2 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_21();

}
else if( materia_param == 4 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_41();
}
////////////////////////////////



////////////////////////////////
// system_add_materia_21()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( stars > 0 )
{
    for( int i = stars; i >= 0; --i )
    {
        mod_value = bu[800730d0 + materia_id * 14 + e + i];
        if( mod_value != ff )
        {
            break;
        }
    }
}

if( bu[GP + 2dc] == 0 ) // battle
{
    type = bu[800730d0 + materia_id * 14 + e];
    [GP + 128 + type * 2] = h(hu[GP + 128 + type * 2] + mod_value);

    if( materia_id == a ) // preemptive
    {
        if( h[GP + 12e] >= 56 )
        {
            [GP + 12e] = h(55);
        }
        if( stars == 5 )
        {
            [GP + 118] = b(1);
        }
    }
}
else // menu
{
    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [V1 + 1b] = (stars);
    [GP + 2b8] = b(a);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_41()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( stars > 0 )
{
    for( int i = stars; i >= 0; --i )
    {
        mod_value = bu[800730d0 + materia_id * 14 + e + i];
        if( mod_value != ff )
        {
            break;
        }
    }
}

if( bu[GP + 2dc] == 0 ) // battle
{
    if( materia_id == 7 )
    {
        [GP + 130] = h(hu[GP + 130] + mod_value);
    }
    else
    {
        type = bu[800730d0 + materia_id * 14 + e];
        [GP + 128 + type * 2] = h(hu[GP + 128 + type * 2] + mod_value);
    }
}
else
{
    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [V1 + 1b] = b(S2);
    [GP + 2b8] = b(9);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X2()

materia_param = A0;
materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( materia_param == 1 )
{
    A0 = stars;
    A1 = materia_id;
    system_add_materia_12();
}

return;
////////////////////////////////



////////////////////////////////
// system_add_materia_12()

number_of_star = A0;
materia_id = A1;

if( bu[GP + 2dc] == 0 ) // battle
{
    A2 = number_of_star - 1;
    for( ; A2 > 0; --A2 )
    {
        if( bu[800730d0 + materia_id * 14 + e + A2] != ff )
        {
            break;
        }
    }
    [80069508 + 0] = b(bu[800730d0 + materia_id * 14 + e + A2]);
}
else // menu
{
    A3 = w[GP + 238];

    for( int i = 0; i < 5; ++i )
    {
        A3 = w[GP + 238];
        [A3 + 1b] = b(0);
        [A3 + 1a] = b(bu[800730d0 + materia_id * 14 + e + i]);
    }

    V0 = bu[A3 + 1];
    if( V0 == number_of_star )
    {
        V0 = number_of_star - 2;
    }
    else
    {
        V0 = number_of_star - 1;
    }

    [A3 + V0 * 2 + 1b] = b(1);
    [GP + 2b8] = b(13);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X3()

materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( bu[GP + 2dc] == 0 ) // battle
{
    V1 = bu[800730d0 + materia_id * 14 + e];
    if( V1 == 15 ) // w-magic
    {
        [GP + 148] = b(2);

        A0 = 2;
        system_search_existed_command();

        if( V0 == -1 )
        {
            A0 = 2;
            system_add_command_to_temp();
            [80069508 + V0 * 3 + 1] = b(stars);
        }
        else
        {
            [80069508 + V0 * 3 + 0] = b(2);
            [80069508 + V0 * 3 + 1] = b(stars);
        }
    }
    else if( V1 == 16 ) // w-summon
    {
        [GP + 14c] = b(2);

        A0 = 3;
        system_search_existed_command();

        if( V0 == -1 )
        {
            A0 = 3;
            system_add_command_to_temp();
            [80069508 + V0 * 3 + 1] = b(stars);
        }
        else
        {
            [80069508 + V1 * 3 + 0] = b(3)
            [80069508 + V1 * 3 + 1] = b(stars);
        }
    }
    else if( V1 == 17 ) // w-item
    {
        A0 = 4;
        system_search_existed_command();

        [80069508 + V0 * 3] = b(17);
        [80069509 + V0 * 3] = b(stars);
    }
}
else // menu
{
    [GP + 2b8] = b(e);

    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [V1 + 1b] = b(stars);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X4()
// mega all

if( bu[GP + 2dc] != 0 ) // menu
{
    [GP + 2b8] = b(b);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X5()

materia_param = A0;
materia_id = A1;
materia_exp = A2;

if( materia_param == 2 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_25();
}
else if( materia_param == 3 )
{
    A0 = materia_id;
    A1 = materia_exp;
    system_add_materia_35();
}
////////////////////////////////



////////////////////////////////
// system_add_materia_25()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( bu[GP + 2dc] != 0 ) // menu
{
    A0 = w[GP + 238];
    [A0 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [A0 + 1b] = b(stars * a);

    switch( bu[800730d0 + materia_id * 14 + e] )
    {
        case 54 55:                      [GP + 2b8] = b(0f); break;
        case 56 58 59 5a 5c 5d 5e 5f 64: [GP + 2b8] = b(10); break;
    }
}
////////////////////////////////



////////////////////////////////
// system_add_materia_35()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( bu[GP + 2dc] != 0 ) // menu
{
    A0 = w[GP + 238];

    [A0 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [A0 + 1b] = b(stars);

    V1 = bu[800730d0 + materia_id * 14 + e];
    if( V1 == 51 ) // all
    {
        [GP + 2b8] = b(f);
    }
    else if( V1 == 57 ) // final attack
    {
        [GP + 2b8] = b(10);
    }
    else if( V1 == 63 ) // quadra magic
    {
        [GP + 2b8] = b(f);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X6()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( bu[GP + 2dc] == 0 )
{
    A0 = stars - 1;
    for( ; A0 >= 0; --A0 )
    {
        if( bu[800730d0 + materia_id * 14 + e + A0] != ff )
        {
            break;
        }
    }

    A0 = bu[800730d0 + materia_id * 14 + e + A0];
    system_add_command_to_temp();
}
else // menu
{
    A3 = w[GP + 238];

    for( int i = 0; i < 5; ++i )
    {
        [A3 + 1a + i * 2] = b(bu[800730d0 + materia_id * 14 + e + i]);
        [A3 + 1b + i * 2] = b(0);
    }

    if( bu[A3 + 1] == stars )
    {
        V0 = stars - 2;
    }
    else
    {
        V0 = stars - 1;
    }

    [A3 + V0 * 2 + 1b] = b(1);

    [GP + 2b8] = b(3);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X7()

materia_exp = A2;

if( bu[GP + 2dc] == 0 )
{
    S1 = materia_exp & 00ffffff;
    for( int i = 0; i < 18; ++i )
    {
        if( S1 & 1 )
        {
            A0 = i; // attack_id
            A1 = i + 48; // record id
            A2 = i + 48; // kernel data id
            system_add_magic_summon_skill_to_unit_structure();
        }
        S1 = S1 >> 1;
    }

    A0 = d;
    system_add_command_to_temp();
}
else // menu
{
    [GP + 2b8] = b(8);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X8()

if( bu[GP + 2dc] == 0 )
{
    A0 = 5;
    system_add_command_to_temp();

    A0 = 6;
    system_add_command_to_temp();

    A0 = 7;
    system_add_command_to_temp();

    A0 = 9;
    system_add_command_to_temp();

    A0 = a;
    system_add_command_to_temp();

    A0 = b;
    system_add_command_to_temp();

    A0 = c;
    system_add_command_to_temp();
}
else // menu
{
    [GP + 2b8] = b(5);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_X9()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

if( bu[GP + 2dc] == 0 ) // battle
{
    S0 = stars - 1;
    for( ; S0 >= 0; --S0 )
    {
        magic_id = bu[800730d0 + materia_id * 14 + 0e + S0];

        if( magic_id != ff )
        {
            A0 = magic_id;
            system_add_magic_to_temp();
        }
    }

    A0 = 2;
    system_add_command_to_temp();

    if( bu[GP + 148] == 0 )
    {
        [GP + 148] = b(1);
    }
}
else // menu
{
    S0 = 0;
    A2 = w[GP + 238];

    loop1b6a0:	; 8001B6A0
        [A2 + 1b + S0 * 2] = b(0);
        [A2 + 1a + S0 * 2] = b(bu[800730d0 + materia_id * 14 + e + S0]);

        S0 = S0 + 1;
        V0 = S0 < 5;
    8001B6B8	bne    v0, zero, loop1b6a0 [$8001b6a0]

    if (stars > 0) // if we have at least 1 star
    {
        S0 = 0;

        loop1b6d0:	; 8001B6D0
            [A2 + 1b + S0 * 2] = b(1);
            S0 = S0 + 1;
            V0 = S0 < stars;
        8001B6DC	bne    v0, zero, loop1b6d0 [$8001b6d0]
    }

    [GP + 2b8] = b(1);
}

return;
////////////////////////////////



////////////////////////////////
// system_add_materia_Xa()

if( bu[GP + 2dc] == 0 ) // battle
{
    for( int i = 0; i < 38; ++i )
    {
        A0 = i;
        system_add_magic_to_temp();
    }

    A0 = 2;
    system_add_command_to_temp();

    if( bu[GP + 148] == 0 )
    {
        [GP + 148] = b(1);
    }
}
else // menu
{
    [GP + 2b8] = b(6);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_Xb()

materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars();
stars = V0;

summon_id = bu[800730d0 + materia_id * 14 + e];

if( bu[GP + 2dc] == 0 )
{
    if( bu[800694b4 + summon_id - 38] != ff )
    {
        [800694b4 + summon_id - 38] = b(bu[800694b4 + summon_id - 38] + stars);
    }

    A0 = summon_id - 38; // attack id
    A1 = summon_id; // record id
    A2 = summon_id; // kernel data id
    system_add_magic_summon_skill_to_unit_structure();

    A0 = 3;
    system_add_command_to_temp();

    if( bu[GP + 14c] == 0 )
    {
        [GP + 14c] = b(1);
    }
}
else
{
    V0 = w[GP + 238];
    [V0 + 1a] = b(summon_id - 38);
    [V0 + 1b] = b(stars);
    [GP + 2b8] = b(2);
}
////////////////////////////////



////////////////////////////////
// system_add_materia_Xc()

if( bu[GP + 2dc] == 0 )
{
    for( int i = 0; i < 10; ++i )
    {
        [800694b4 + i] = b(ff);
    }

    for( int i = 38; i < 48; ++i )
    {
        A0 = i - 38;
        A1 = i;
        A2 = i;
        system_add_magic_summon_skill_to_unit_structure();
    }

    A0 = 3;
    system_add_command_to_temp();

    if( bu[GP + 14c] == 0 )
    {
        [GP + 14c] = b(1);
    }
}
else
{
    [GP + 2b8] = b(7);
}
////////////////////////////////



////////////////////////////////
// system_get_materia_activated_stars()

materia_id = A0;
materia_exp = A1;
stars = 1;

// search how much stars activated in this materia
// start search from max level
// needed exp stored divided by 100 so we need multiply
for( int i = 3; i >= 0; --i )
{
    need_exp = hu[800730d0 + materia_id * 14 + i * 2 + 0];
    if( need_exp != ffff && materia_exp >= need_exp * 64 )
    {
        stars = i + 2;
        break;
    }
}

[GP + 278] = w(1); // how much stars this materia has
for( int i = 0; i < 4; ++i )
{
    if( hu[800730d0 + materia_id * 14 + i * 2 + 0] != ffff )
    {
        [GP + 278] = w(w[GP + 278] + 1);
    }
}

// for menu
if( bu[GP + 2dc] != 0 )
{
    V1 = hu[800730d0 + (stars - 1) * 2 + materia_id * 14 + 0];
    if( V1 == ffff || stars == w[GP + 278] )
    {
        [GP + 1cc] = w(0); // AP to next level
    }
    else
    {
        [GP + 1cc] = w(V1 * 64 - materia_exp); // AP to next level
    }

    V0 = w[GP + 238];
    [V0 + 0] = b(stars);
    [V0 + 1] = b(bu[GP + 278]);
    [V0 + 4] = w(w[GP + 1cc]);
}

return stars;
////////////////////////////////



////////////////////////////////
// system_add_magic_to_temp()

magic_id = A0;

for( int i = 0; i < 38; ++ i )
{
    if( bu[80069554 + i * 5 + 0] == magic_id )
    {
        return;
    }
}

V1 = bu[GP + 124];
[80069554 + V1 * 5] = b(magic_id);

[GP + 124] = b(bu[GP + 124] + 1);
////////////////////////////////



////////////////////////////////
// system_add_magic_summon_skill_to_unit_structure()

attack_id = A0;
record_id = A1;
kernel_data_id = A2;

unit_structure = w[GP + 11c];
[unit_structure + 108 + record_id * 8 + 0] = b(attack_id);
[unit_structure + 108 + record_id * 8 + 1] = b(bu[800708c4 + kernel_data_id * 1c + 4]); // magic cost
[unit_structure + 108 + record_id * 8 + 5] = b(bu[800708c4 + kernel_data_id * 1c + c]); // animation id?
////////////////////////////////



////////////////////////////////
// system_add_command_to_temp()

command_id = A0;

for( int i = 0; i < 10; ++i )
{
    if( bu[80069508 + i * 3] == command_id )
    {
        return i;
    }
}

V1 = bu[GP + 120];
[80069508 + V1 * 3] = b(command_id);

[GP + 120] = b(bu[GP + 120] + 1);

return bu[GP + 120] - 1;
////////////////////////////////



////////////////////////////////
// system_search_existed_command()

command_id = A0;

for( int i = 0; i < 10; ++i )
{
    if( bu[80069508 + i * 3 + 0] == command_id )
    {
        return i;
    }
}

return -1;
////////////////////////////////



////////////////////////////////
// system_add_pair_materia_with_slot_check()

left_slot = A0;
right_slot = A1;
materia1_data = A2;
materia2_data = A3;
S3 = A4;
S4 = A5;
S1 = A6;

if( ( left_slot == 2 && right_slot == 3 ) || ( left_slot == 6 && right_slot == 7 ) ) // if linked
{
    A0 = materia1_data;
    A1 = materia2_data;
    A2 = S3;
    A3 = S4;
    A4 = S1;
    system_add_pair_materia_unordered();
}
////////////////////////////////



////////////////////////////////
// system_add_pair_materia_unordered()

materia1_data = A0
materia2_data = A1;
unk1 = A2;
unk2 = A3;
unk3 = A4;

materia1_id = materia1_data & 000000ff;
materia2_id = materia2_data & 000000ff;
materia1_type = bu[800730d0 + materia1_id * 14 + d] & 0f;
materia2_type = bu[800730d0 + materia2_id * 14 + d] & 0f;

if( materia1_id != ff && materia2_id != ff )
{
    if( materia1_type != 5 )
    {
        if( materia2_type == 5 )
        {
            A0 = materia2_data;
            A1 = materia1_data;
            A2 = unk1;
            A3 = unk3;
            system_add_pair_materia_ordered();
        }
    }
    else
    {
        if( materia2_type != 5 )
        {
            A0 = materia1_data;
            A1 = materia2_data;
            A2 = unk2;
            A3 = unk3;
            system_add_pair_materia_ordered();
        }
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_materia_ordered()

materia_5type_data = A0;
materia_pair_data = A1;
S3 = A3;


materia_5type_id = materia_5type_data & 000000ff;
materia_5type_exp = materia_5type_data >> 8;


A0 = materia_5type_id;
A1 = materia_5type_exp;
system_get_materia_activated_stars();
number_of_5type_stars = V0;

for( int i = 0; i < 5; ++i )
{
    [GP + 110 + i] = b(bu[800730d0 + materia_5type_id * 14 + f + i]);
}

switch( bu[800730d0 + materia_5type_id * 14 + e] )
{
    case 51: // all
    {
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_all();
    }
    break;

    case 54: // counter
    {
        [GP + 140] = w(8);
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_counter();
    }
    break;

    case 55: // magic counter
    {
        [GP + 140] = w(7);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_magic_counter;
    }
    break;

    case 56: // sneak attack
    {
        [GP + 140] = w(4);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_sneak_final_attack;
    }
    break;

    case 57: // final attack
    {
        [GP + 140] = w(1);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_sneak_final_attack;
    }
    break;

    case 58: // mp turbo
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        system_add_pair_with_mp_turbo;
    }
    break;

    case 59: // mp absorb
    {
        [GP + 134] = b(1);
        A0 = materia_pair_data;
        system_add_pair_flag_to_command_magic_summon();
    }
    break;

    case 5a: // hp absorb
    {
        [GP + 134] = b(2);
        A0 = materia_pair_data;
        system_add_pair_flag_to_command_magic_summon();
    }
    break;

    case 5c: // added cut
    {
        [GP + 134] = b(10);
        A0 = materia_pair_data;
        system_add_pair_flag_to_command_magic_summon();
    }
    break;

    case 5d: // steal as well
    {
        [GP + 134] = b(8);
        A0 = materia_pair_data;
        system_add_pair_flag_to_command_magic_summon();
    }
    break;

    case 5e: // elemental
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        A2 = S3 & ff;
        system_add_pair_with_elemental;
    }
    break;

    case 5f: // added effect
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        A2 = S3 & ff;
        system_add_pair_with_added_effect;
    }
    break;

    case 63: // quadra magic
    {
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_quadra_magic;
    }
    break;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_all()

number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = materia_pair_data & 000000ff
materia_pair_exp = materia_pair_data >> 8;
materia_pair_type = bu[800730d0 + materia_pair_id * 14 + d] & 0f;

if( materia_pair_type == 9 )
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_magic_with_all();
}
if( materia_pair_type == a )
{
    A0 = number_of_5type_stars;
    system_add_pair_master_magic_with_all();
}
////////////////////////////////



////////////////////////////////
// system_add_pair_magic_with_all()

number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars();
stars = V0;

for( int i = stars; i > 0; --i )
{
    A0 = bu[800730d0 + materia_pair_id * 14 + d + i];
    system_search_existed_magic();
    data_id = V0;

    if( data_id != -1 )
    {
        [80069554 + data_id * 5 + 1] = b(bu[80069554 + data_id * 5 + 1] + number_of_5type_stars);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_master_magic_with_all()

number_of_5type_stars = A0;

for( int i = 0; i < 38; ++i )
{
    A0 = i;
    system_search_existed_magic();
    data_id = V0;

    if( data_id != -1 )
    {
        [80069555 + data_id * 5] = b(bu[80069555 + data_id * 5] + number_of_5type_stars);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_counter()

number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = materia_pair_data & 000000ff
materia_pair_exp = materia_pair_data >> 8;
materia_pair_type = bu[800730d0 + materia_pair_id * 14 + 0d] & 0f;

[GP + 144] = h(0);

if( materia_pair_type == 6 ) // command
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_command_with_counter();
}
if( materia_pair_type == 8 ) // master command
{
    A0 = number_of_5type_stars;
    A1 = fd;
    system_add_pair_master_materia_with_counter();
}
////////////////////////////////



////////////////////////////////
// system_add_pair_command_with_counter()

number_of_5type_stars = A0;
materia_pair_id = A1;

unit_structure = w[GP + 11c];

A0 = bu[800730d0 + materia_pair_id * 14 + e];
if( A0 == 5 || A0 == 6 || A0 == 8 || A0 == 9 || A0 == a || A0 == b || A0 == c )
{
    A0 = A0;
    system_search_existed_command();

    if( V0 != -1 )
    {
        counter_slot = w[GP + 13c];
        if( counter_slot != 8 )
        {
            [unit_structure + 24 + counter_slot * 3 + 0] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + 24 + counter_slot * 3 + 1] = b(bu[800730d0 + materia_pair_id * 14 + e]);
            [unit_structure + 24 + counter_slot * 3 + 2] = b(bu[GP + 10f + number_of_5type_stars]);
            [GP + 13c] = w(counter_slot + 1);
        }
    }
}

A0 = bu[800730d0 + materia_pair_id * 14 + f]
if( A0 == 7 || A0 == 11 )
{
    A0 = A0;
    system_search_existed_command();

    if( V0 != -1 )
    {
        counter_slot = w[GP + 13c];
        if( counter_slot != 8 )
        {
            [unit_structure + 24 + counter_slot * 3 + 0] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + 24 + counter_slot * 3 + 1] = b(bu[800730d0 + materia_pair_id * 14 + f]);
            [unit_structure + 24 + counter_slot * 3 + 2] = b(bu[GP + 10f + number_of_5type_stars]);
            [GP + 13c] = w(counter_slot + 1);
        }
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_master_materia_with_counter()

number_of_5type_stars = A0;

counter_slot = w[GP + 13c];
if( counter_slot != 0 )
{
    unit_structure = w[GP + 11c];
    [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
    [unit_structure + counter_slot * 3 + 25] = b(A1);
    [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

    [GP + 13c] = w(counter_slot + 1);
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_magic_counter()

materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;

[GP + 144] = h(0);

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V1 = V0 & 0f;

if( V1 == 9 )
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_magic_with_magic_counter;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    A1 = fe;
    system_add_pair_master_materia_with_counter;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_summon_with_magic_counter;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    A1 = ff;
    system_add_pair_master_materia_with_counter;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_magic_with_magic_counter
number_of_5type_stars = A0;
materia_pair_id = A1;

A0 = materia_pair_id;
A1 = A2;
system_get_materia_activated_stars;
A0 = V0;

if (A0 > 0)
{
    loop18878:	; 80018878
        V1 = bu[800730d0 + materia_pair_id * 14 + d + A0];

        if (V1 != ff)
        {
            counter_slot = w[GP + 13c];
            if (counter_slot == 8)
            {
                return;
            }

            unit_structure = w[GP + 11c];
            [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + counter_slot * 3 + 25] = b(V1);
            [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

            [GP + 13c] = w(counter_slot + 1);
            return;
        }

        A0 = A0 - 1;
    80018914	bgtz   a0, loop18878 [$80018878]
}
////////////////////////////////



////////////////////////////////
// system_add_pair_summon_with_magic_counter
number_of_5type_stars = A0;
materia_pair_id = A1;

counter_slot = w[GP + 13c];
if (counter_slot != 8)
{
    unit_structure = w[GP + 11c];
    [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
    [unit_structure + counter_slot * 3 + 25] = b(bu[800730d0 + materia_pair_id * 14 + e]);
    [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

    [GP + 13c] = w(counter_slot + 1);
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_sneak_final_attack
materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V0 = V0 & 0f;
switch (V1)
{
    case 6:
    {
        [GP + 144] = h(1);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_command_with_counter;
    }
    break;

    case 8:
    {
        [GP + 144] = h(1);
        A0 = number_of_5type_stars;
        A1 = fd;
        system_add_pair_master_materia_with_counter;
    }
    break;

    case 9:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_magic_with_magic_counter;
    }
    break;

    case a:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = fe;
        system_add_pair_master_materia_with_counter;
    }
    break;

    case b:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_summon_with_magic_counter;
    }
    break;

    case c:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = ff;
        system_add_pair_master_materia_with_counter;
    }
    break;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_mp_turbo
number_of_5type_stars = A0;
materia_pair_data = A1;

materia_pair_id = materia_pair_data & ff;
materia_pair_exp = materia_pair_data >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V1 = V0 & 0f;
if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_magic_with_mp_turbo;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_magic_with_mp_turbo;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_summon_with_mp_turbo;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_summon_with_mp_turbo;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_magic_with_mp_turbo
number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars;
S0 = V0;

if (S0 > 0)
{
    loop18bf8:	; 80018BF8
        A0 = bu[800730d0 + materia_pair_id * 14 + d + S0];
        system_search_existed_magic;
        magic_slot = V0;

        if (magic_slot != -1)
        {
            A1 = bu[80069554 + magic_slot * 5 + 4];
            V1 = A1 >> 5;
            A0 = V1 + number_of_5type_stars;
            if (A0 >= 6)
            {
                A0 = 5;
            }
            V0 = A0 & 7;
            V0 = V0 << 5;

            V1 = A1 & 1f;
            V1 = V1 | V0;
            [80069554 + magic_slot * 5 + 4] = b(V1);
        }

        S0 = S0 - 1;
    80018C70	bgtz   s0, loop18bf8 [$80018bf8]
}
////////////////////////////////



////////////////////////////////
// system_add_pair_master_magic_with_mp_turbo
number_of_5type_stars = A0;

S0 = 0;
loop18b2c:	; 80018B2C
    A0 = S0;
    system_search_existed_magic;
    magic_slot = V0;

    if (magic_slot != -1)
    {
        A1 = bu[80069554 + magic_slot * 5 + 4];
        V1 = A1 >> 5;
        A0 = V1 + number_of_5type_stars;
        if (A0 >= 6)
        {
            A0 = 5;
        }
        V0 = A0 & 7;
        V0 = V0 << 5;

        V1 = A1 & 1f;
        V1 = V1 | V0;
        [80069554 + magic_slot * 5 + 4] = b(V1);
    }

    S0 = S0 + 1;
    V0 = S0 < 38;
80018B98	bne    v0, zero, loop18b2c [$80018b2c]
////////////////////////////////



////////////////////////////////
// system_add_pair_master_summon_with_mp_turbo
number_of_5type_stars = A0;

T0 = 0;
loop18abc:	; 80018ABC
    unit_structure = w[GP + 11c];
    A1 = bu[unit_structure + 108 + 38 * 8 + T0 * 8 + 7];
    V0 = A1 >> 5;
    V1 = V0 + number_of_5type_stars;

    if (V1 >= 6)
    {
        V1 = 5;
    }

    V0 = A1 & 1f;
    V1 = V1 & 7;
    V1 = V1 << 5;
    V0 = V0 | V1;
    [unit_structure + 108 + 38 * 8 + T0 * 8 + 7] = b(V0);

    T0 = T0 + 1;
    V0 = T0 < 10;
80018B04	bne    v0, zero, loop18abc [$80018abc]
////////////////////////////////



////////////////////////////////
// system_add_pair_summon_with_mp_turbo
// there is bug here. Bost will get first 4 initializing magic as well. but maybe this data is rewritten.
number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars;
A2 = V0;
if (A2 > 0)
{
    loop18a48:	; 80018A48
        V0 = bu[800730d0 + materia_pair_id * 14 + d + A2];

        V1 = w[GP + 11c];
        A3 = V1 + V0 * 8;
        V1 = bu[A3 + 108 + 7];
        V0 = V1 >> 5;
        A1 = V0 + number_of_5type_stars;
        if (A1 >= 6)
        {
            A1 = 5;
        }

        V0 = A1 & 7;
        V0 = V0 << 5;
        V1 = V1 | V0;
        [A3 + 10f] = b(V1);

        A2 = A2 - 1;
    80018A90	bgtz   a2, loop18a48 [$80018a48]
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_command_magic_summon()

materia_pair_data = A0;
materia_pair_id = materia_pair_data & ff;
materia_pair_exp = materia_pair_data >> 8;

switch( bu[800730d0 + materia_pair_id * 14 + d] & 0f )
{
    case 6:
    {
        A0 = materia_pair_data;
        system_add_pair_flag_to_active_command();
    }
    break;

    case 8:
    {
        system_add_pair_flag_to_all_active_commands();
    }
    break;

    case 9:
    {
        A0 = materia_pair_data;
        A1 = materia_pair_exp;
        system_add_pair_flag_to_magic();
    }
    break;

    case a:
    {
        system_add_pair_flag_to_all_magics();
    }
    break;

    case b:
    {
        A0 = materia_pair_data;
        A1 = materia_pair_exp;
        system_add_pair_flag_to_summon();
    }
    break;

    case c:
    {
        system_add_pair_flag_to_all_summons();
    }
    break;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_active_command()

materia_pair_id = A0;

A0 = bu[800730d0 + materia_pair_id * 14 + e];
system_search_existed_command();
if( V0 != -1 )
{
    [80069508 + V0 * 3 + 2] = b(bu[80069508 + V0 * 3 + 2] | bu[GP + 134]);
}

A0 = bu[800730d0 + materia_pair_id * 14 + f];
if (A0 == 7 || A0 == 11)
{
    system_search_existed_command();
    if( V0 != -1 )
    {
        [80069508 + V0 * 3 + 2] = b(bu[80069508 + V0 * 3 + 2] | bu[GP + 134]);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_all_active_commands()

for( int i = 0; i < 10; ++i )
{
    A0 = bu[80069508 + i * 3 + 0];
    system_search_existed_command();
    if( V0 != -1 )
    {
        [80069508 + V0 * 3 + 2] = b(bu[80069508 + V0 * 3 + 2] | bu[GP + 134]);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_magic()

materia_pair_data = A0;
materia_pair_exp = A1;

A0 = materia_pair_data & ff; // id
A1 = materia_pair_exp;
system_get_materia_activated_stars();
stars = V0;

for( int i = stars; i > 0; --i )
{
    A0 = bu[800730dd + S1 * 14 + i];
    system_search_existed_magic();
    if( V0 != -1 )
    {
        [80069554 + V0 * 5 + 4] = b(bu[80069554 + V0 * 5 + 4] | bu[GP + 134]);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_all_magics()

for( int i = 0; i < 38; ++i )
{
    A0 = i;
    system_search_existed_magic();
    if( V0 != -1 )
    {
        [80069554 + V0 * 5 + 4] = b(bu[80069554 + V0 * 5 + 4] | bu[GP + 134]);
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_summon()

materia_pair_data = A0;
materia_pair_exp = A1;

A0 = materia_pair_data & ff; // id
A1 = materia_pair_exp;
system_get_materia_activated_stars();
stars = V0;

for( int i = stars; i > 0; --i )
{
    V0 = bu[800730d0 + S0 * 14 + d + i];
    unit_structure = w[GP + 11c];
    [unit_structure + 10f + V0 * 8] = b(bu[unit_structure + 10f + V0 * 8] | bu[GP + 134]);
}
////////////////////////////////



////////////////////////////////
// system_add_pair_flag_to_all_summons()

for( int i = 0; i < 10; ++i )
{
    unit_structure = w[GP + 11c];
    [unit_structure + 108 + 1c0 + i * 8 + 7] = b(bu[unit_structure + 108 + 1c0 + i * 8 + 7] | bu[GP + 134]);
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_quadra_magic
number_of_5type_stars = A1;
A1 = A2 & ff;
V0 = bu[800730d0 + A1 * 14 + d];
A2 = A2 >> 8;
V1 = V0 & 0f;
if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = A1;
    A2 = A2;
    system_add_pair_magic_with_quadra_magic;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_magic_with_quadra_magic;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    system_add_pair_summon_with_quadra_magic;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_summon_with_quadra_magic;
}
////////////////////////////////



////////////////////////////////
// system_add_pair_magic_with_quadra_magic
S2 = A0;
S1 = A1 & ff;
A0 = S1;
A1 = A2;
system_get_materia_activated_stars;
S0 = V0;
if (S0 > 0)
{
    loop192a0:	; 800192A0
        A0 = bu[800730d0 + S1 * 14 + d + S0];
        system_search_existed_magic;
        magic_slot = V0;

        if (magic_slot != -1)
        {
            V1 = bu[80069554 + magic_slot * 5 + 2];
            V1 = bu[80069554 + magic_slot * 5 + 3];
            V1 = V1 + 1;
            A0 = A0 + S2;
            [80069554 + magic_slot * 5 + 2] = b(V1);
            [80069554 + magic_slot * 5 + 3] = b(A0);
        }

        S0 = S0 - 1;
    80019310	bgtz   s0, loop192a0 [$800192a0]
}
L19318:	; 80019318
////////////////////////////////



////////////////////////////////
// system_add_pair_master_magic_with_quadra_magic
A2 = 0;
loop19348:	; 80019348
    [80069554 + A2 * 5 + 2] = b(bu[80069554 + A2 * 5 + 2] + 1);
    [80069554 + A2 * 5 + 3] = b(bu[80069554 + A2 * 5 + 2] + A0);
    A2 = A2 + 1;
    V0 = A2 < 38;
8001936C	bne    v0, zero, loop19348 [$80019348]
////////////////////////////////



////////////////////////////////
// system_add_pair_summon_with_quadra_magic
A1 = A1 & ff;
V1 = bu[800730de + A1 * 14];
V1 = V1 - 38;
[800694c4 + V1] = b(bu[800694c4 + V1] + 1);
[800694d4 + V1] = b(bu[800694d4 + V1] + A0);
////////////////////////////////



////////////////////////////////
// system_add_pair_master_summon_with_quadra_magic
V1 = 800694d4;
A1 = 800694c4;
A2 = V1 + 10;

loop19408:	; 80019408
    [A1] = b(bu[A1] + 1);
    [V1] = b(bu[V1] + A0);

    V1 = V1 + 1;
    A1 = A1 + 1;
    V0 = V1 < A2;
80019430	bne    v0, zero, loop19408 [$80019408]
////////////////////////////////



////////////////////////////////
// system_add_pair_with_elemental
number_of_5type_stars = A0;
materia_pair_data = A1;
equipment_type = A2; // 0 - weapon, 1 - armor

materia_pair_id = materia_pair_data & ff;
V1 = bu[800730d0 + materia_pair_id * 14 + c];
if (V1 < 20)
{
    A1 = hu[800491b0 + V1 * 2];
    A0 = A0 & ff;
    V0 = A2 & ff;
    if (V0 == 0)
    {
        V1 = w[GP + 11c];
        V0 = hu[V1 + 3c];
        V0 = A1 | V0;
        [V1 + 3c] = h[V0];
    }
    else
    {
        if (A0 == 1)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 3e];
            V0 = A1 | V0;
            [V1 + 3e] = h[V0];
        }
        else if (A0 == 2)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 40];
            V0 = A1 | V0;
            [V1 + 40] = h[V0];
        }
        else if (A0 >= 3)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 42];
            V0 = A1 | V0;
            [V1 + 42] = h[V0];
        }
    }
}
////////////////////////////////



////////////////////////////////
// system_add_pair_with_added_effect
A1 = A1 & ff;
V0 = A1 * 14;
A2 = A2 & ff;
V1 = bu[800730d0 + V0 + a];
A0 = bu[800730d0 + V0 + 9];
V0 = bu[800730d0 + V0 + b];
V1 = V1 << 8;
A0 = A0 + V1;
V0 = V0 << 10;
A0 = A0 + V0;
if (A2 == 0)
{
    V1 = w[GP + 11c];
    V0 = w[V1 + 44];
    V0 = A1 | V0;
    [V1 + 44] = w[V0];
}
else
{
    V1 = w[GP + 11c];
    V0 = w[V1 + 48];
    V0 = A1 | V0;
    [V1 + 48] = w[V0];
}
////////////////////////////////



////////////////////////////////
// system_get_armor_address_by_id
// A0 - armor id

return 80071e44 + A0 * 24;
////////////////////////////////



////////////////////////////////
// system_get_accessory_address_by_id
// A0 - accessory id

return 80071c24 + A0 * 10;
////////////////////////////////



////////////////////////////////
// system_get_limit_id
if (A0 < 9)
{
    V1 = bu[80082268 + A0 * 38 + 0c + A1] - 80;
}
else
{
    V1 = 7f;
}

return V1;
////////////////////////////////



////////////////////////////////
// system_calculate_total_lure_gil_preemptive_value
S2 = 0;
S1 = 0;

[GP + 1d4] = b(10);
[GP + 1d5] = b(10);
[GP + 1d6] = b(0);
[GP + 1d7] = b(10);

// remove underwater timer
[8009d302] = b(bu[8009d302] & 7f);



S0 = 0;
loop176d8:	; 800176D8
    V1 = bu[8009cbdc + S0];
    if (V1 != ff)
    {
        A0 = S0;
        system_get_party_player_structure_address_by_party_id;
        [GP + 11c] = w(V0);

        [GP + 1d4] = b(bu[GP + 1d4] + bu[V0 + 43c]);
        [GP + 1d6] = b(bu[GP + 1d6] + bu[V0 + 43e]);
        [GP + 1d7] = b(bu[GP + 1d7] + bu[V0 + 43f]);

        S2 = S2 + bu[V0 + 43d]; // encounter value (enemy lure/away)
        S1 = S1 + bu[V0 + 437]; // number of stars equipped enemy away materia has

        // if underwater materia equipped add timer to battle ui
        V0 = bu[V0 + 23];
        if (V0 & 01)
        {
            V0 = bu[8009d302];
            V0 = V0 | 80;
            [8009d302] = b(V0);
        }
    }

    S0 = S0 + 1;
    V0 = S0 < 3;
80017784	bne    v0, zero, loop176d8 [$800176d8]



V0 = bu[GP + 1d4];
if (V0 >= 21)
{
    [GP + 1d4] = b(20);
}




if (S2 + 10 >= S1)
{
    [GP + 1d5] = b(S2 - S1 + 10);
}
else
{
    [GP + 1d5] = b(2);
}

V0 = bu[GP + 1d5];
if (V0 >= 21)
{
    [GP + 1d5] = b(20);
}




V0 = bu[GP + 1d6];
if (V0 >= 21)
{
    [GP + 1d6] = b(20);
}



V0 = bu[GP + 1d7];
if (V0 >= 56)
{
    [GP + 1d7] = b(55);
}

// if mastered pre emptive
V0 = bu[GP + 118];
if (V0 != 0)
{
    V0 = bu[GP + 1d7];
    V0 = V0 | 80;
    [GP + 1d7] = b(V0);
}
////////////////////////////////



////////////////////////////////
// system_get_party_player_structure_address_by_party_id
// A0 - party id
V1 = bu[8009cbdc + A0];
if (V1 != ff)
{
    return 8009d84c + A0 * 440;
}
////////////////////////////////



////////////////////////////////
// system_get_armor_address_equipped_by_party_id()

party_id = 0;

char_id = bu[8009c6e4 + 4f8 + party_id];

if( char_id != ff )
{
    save_id = w[800491d0 + char_id * 4];

    return 80071e4d + bu[8009c738 + save_id * 84 + 1d] * 24;
}
////////////////////////////////



////////////////////////////////
// system_get_player_base_attack_defense()

party_id = A0;
type = A1;

char_id = bu[8009c6e4 + 4f8 + party_id];
save_id = w[800491d0 + char_id * 4];

if( type == 0 )
{
    V1 = bu[8009c738 + save_id * 84 + 1c]; // weapon
    A2 = bu[800738a0 + V1 * 2c + 4]; // weapon attack
    return A2;
}
if( type == 1 )
{
    V1 = bu[8009c738 + save_id * 84 + 1d]; // armor
    A2 = bu[80071e44 + V1 * 24 + 2]; // defense
    return A2;
}
if( type == 2 )
{
    return 0;
}
if( type == 3 )
{
    return 0;
}

// undefined
return A2;
////////////////////////////////



////////////////////////////////
// system_copy_temp_magic_to_unit_structure
S0 = 0;
S1 = 0;

loop1bc30:	; 8001BC30
    A0 = bu[80069554 + S0];
    A1 = S1 & ff;
    A2 = A0;
    system_add_magic_summon_skill_to_unit_structure;

    unit_structure = w[GP + 11c];
    [unit_structure + 108 + S1 * 8 + 2] = b(bu[80069554 + S0 + 1]);
    [unit_structure + 108 + S1 * 8 + 3] = b(bu[80069554 + S0 + 2]);
    [unit_structure + 108 + S1 * 8 + 4] = b(bu[80069554 + S0 + 3]);
    [unit_structure + 108 + S1 * 8 + 7] = b(bu[80069554 + S0 + 4]);

    S1 = S1 + 1;
    S0 = S0 + 5;
    V0 = S1 < 38;
8001BCC8	bne    v0, zero, loop1bc30 [$8001bc30]
////////////////////////////////



////////////////////////////////
// system_copy_and_sort_command
[GP + 138] = w(0);
[GP + 13c] = w(0);

system_remove_steal_if_mug;

S1 = 0;
loop1b974:	; 8001B974
    V1 = bu[80069508 + S1];
    if (V1 != ff)
    {
        // replace magic with w-magic
        if (V1 == 2)
        {
            V0 = bu[GP + 148];
            if (V0 == 2)
            {
                [80069508 + S1] = b(15);
            }
        }

        // replace summon with w-summon
        if (V1 == 3)
        {
            V0 = bu[GP + 14c];
            if (V0 == 2)
            {
                [80069508 + S1] = b(16);
            }
        }

        A0 = bu[80069508 + S1];
        system_get_command_order;

        A0 = bu[80069508 + S1];
        A1 = V0 & ff;
        system_copy_command_to_unit_structure;

        V0 = w[GP + 138];
        V0 = V0 + 1;
        [GP + 138] = w(V0);
    }

    S1 = S1 + 3;
    V0 = S1 < 30;
8001BA0C	bne    v0, zero, loop1b974 [$8001b974]

V1 = [GP + 138];
A0 = w[GP + 11c];
V0 = V1 / 4;
[A0 + 21] = b(V0);
////////////////////////////////



////////////////////////////////
// system_remove_steal_if_mug
A0 = 0;
A1 = 0;

loop1b8b8:	; 8001B8B8
    V0 = bu[80069508 + A0 * 3 + 0];
    if (V0 == 11) // mug
    {
        A1 = 1;
        break;
    }

    A0 = A0 + 1;
    V1 = V1 + 3;
    V0 = A0 < 10;
8001B8E0	bne    v0, zero, loop1b8b8 [$8001b8b8]

A0 = 0;
loop1b8fc:	; 8001B8FC
    if (A1 == 1)
    {
        V0 = bu[80069508 + A0 * 3];
        if (V0 == 5)
        {
            [80069508 + A0 * 3] = b(ff);
        }
    }

    A0 = A0 + 1;
    V0 = A0 < 10;
8001B934	bne    v0, zero, loop1b8fc [$8001b8fc]
////////////////////////////////



////////////////////////////////
// system_get_command_order
if (A0 == 18 || A0 == 19 || A0 == 1a || A0 == 1b || A0 == 1)
{
    return 0;
}
if (A0 == 2 || A0 == 15)
{
    return 1;
}
if (A0 == 3 || A0 == 16)
{
    return 2;
}
if (A0 == 4 || A0 == 17)
{
    return 3;
}

// if there is no magic
V0 = bu[GP + 148];
if (V0 == 0)
{
    [GP + 148] = b(1);
    return 1;
}

// if there is no summon
V0 = bu[GP + 14c];
if (V0 == 0)
{
    [GP + 14c] = b(1);
    return 2;
}

// order for all others
V1 = 4;
loop1bb08:	; 8001BB08
    V0 = w[GP + 11c];
    V0 = bu[V0 + 4c + V1 * 6];
    if (V0 == ff)
    {
        return V1;
    }

    V1 = V1 + 1;
    V0 = V1 < 10;
8001BB20	bne    v0, zero, loop1bb08 [$8001bb08]
////////////////////////////////



////////////////////////////////
// system_copy_command_to_unit_structure
command_id = A0;
command_slot = A1;

unit_structure = w[GP + 11c];

[unit_structure + command_slot * 6 + 4c + 0] = b(command_id);
[unit_structure + command_slot * 6 + 4c + 1] = b(bu[800707c4 + command_id * 8 + 0]); // default 
[unit_structure + command_slot * 6 + 4c + 2] = b(bu[800707c4 + command_id * 8 + 1]); // default target type
[unit_structure + command_slot * 6 + 4c + 3] = b(0);

A3 = 0;
loop1bba8:	; 8001BBA8
    V0 = bu[80069508 + A1];
    if (command_id == V0)
    {
        [unit_structure + command_slot * 6 + 4c + 4] = b(bu[80069508 + A3 * 3 + 1]);
        [unit_structure + command_slot * 6 + 4c + 5] = b(bu[80069508 + A3 * 3 + 2]);

        return;
    }

    A3 = A3 + 1;
    V0 = A3 < 10;
8001BC08	bne    v0, zero, loop1bba8 [$8001bba8]
////////////////////////////////



////////////////////////////////
// system_copy_summon_to_unit_structure
A1 = 0;
unit_structure = w[GP + 11c];

loop1b578:	; 8001B578
    [unit_structure + 108 + 38 * 8 + A1 * 8 + 2] = b(bu[800694b4 + A1]);
    [unit_structure + 108 + 38 * 8 + A1 * 8 + 3] = b(bu[800694c4 + A1]);
    [unit_structure + 108 + 38 * 8 + A1 * 8 + 4] = b(bu[800694d4 + A1]);

    A1 = A1 + 1;
    V0 = A1 < 10;
8001B5D4	bne    v0, zero, loop1b578 [$8001b578]
////////////////////////////////



////////////////////////////////
// system_copy_boosted_stat_to_unit_structure
materia boost no greater than 0x64 (from plus type materia)
A1 = 0;
loop1af1c:	; 8001AF1C
    V0 = h[800694e4 + A1 * 2];
    if (V0 >= 65)
    {
        [800694e4 + A1 * 2] = h(64);
    }

    A1 = A1 + 1;
    V0 = A1 < b;
8001AF38	bne    v0, zero, loop1af1c [$8001af1c]

// limit exp to 0x20
V0 = h[800694f8];
if (V0 >= 21)
{
    [800694f8] = h(20);
}

// limit materia equip modifiers to 0xff if greater than zero
A1 = 0;
loop1af6c:	; 8001AF6C
    V0 = h[800694fc + A1 * 2];
    V1 = V0;
    V0 = V0 & 8000;
    if (V0 == 0)
    {
        [800694fc + A1 * 2] = h(V1 & ff);
    }

    A1 = A1 + 1;
    V0 = A1 < 6;
8001AF90	bne    v0, zero, loop1af6c [$8001af6c]



// calculate final strength
strength = h[8006953c]; // unit strength
boost = h[800694e4]; // materia boost %
equip = hu[800694fc]; // materia equip
strength = strength + strength * 100 / boost + equip;
if (strength >= 100)
{
    strength = ff;
}
if (strength < 0)
{
    strength = 0;
}
[8006953c] = h(strength); // set new unit strength



// calculate final vitality
vitality = h[8006953e];
boost = h[800694e6];
equip = hu[800694fe];
vitality = vitality + vitality * 100 / boost + equip;
if (vitality >= 100)
{
    vitality = ff;
}
if (vitality < 0)
{
    vitality = 0;
}
[8006953e] = h(vitality);



// calculate final magic
magic = h[80069540];
boost = h[800694e8];
equip = hu[80069500];
magic = magic + magic * 100 / boost + equip;
if (magic >= 100)
{
    magic = ff;
}
if (magic < 0)
{
    magic = 0;
}
[80069540] = h(magic);



// calculate final spirit
spirit = h[80069542];
boost = h[800694ea];
equip = hu[80069502];
spirit = spirit + spirit * 100 / boost + equip;
if (spirit >= 100)
{
    spirit = ff;
}
if (spirit < 0)
{
    spirit = 0;
}
[80069542] = h(spirit);



// calculate final dexterity
dexterity = h[80069544];
boost = h[800694ec];
equip = hu[80069504];
dexterity = dexterity + dexterity * 100 / boost + equip;
if (dexterity >= 100)
{
    dexterity = ff;
}
if (dexterity < 0)
{
    dexterity = 0;
}
[80069544] = h(dexterity);



// calculate final luck
luck = h[80069546];
boost = h[800694ee];
equip = hu[80069506];
luck = luck + luck * 100 / boost + equip;
if (luck >= 100)
{
    luck = ff;
}
if (luck < 0)
{
    luck = 0;
}
[80069546] = h(luck);



// calculate final hp
hp = h[80069550];
boost = h[800694f4];
hp = hp + hp * 100 / boost;
if (hp >= 2710) // 10000
{
    hp = 270f; // 9999
}
if (hp < 0)
{
    hp = 0;
}
[80069550] = h(hp);



// calculate final attack
attack = h[80069548];
boost = h[800694f0];
attack = attack + attack * 100 / boost;
[80069548] = h(attack);



// calculate final defense
defense = h[8006954a];
boost = h[800694f2];
defense = defense + defense * 100 / boost;
[8006954a] = h(defense);



// calculate final mp
mp = h[80069552];
boost = h[800694f6];
mp = mp + mp * 100 / boost;
if (mp >= 3e8) // 1000
{
    hp = 3e7; // 999
}
if (mp < 0)
{
    mp = 0;
}
[80069552] = h(mp);



unit_structure = w[GP + 11c];
[unit_structure + 00] = b(bu[800694f8]); // exp modifier
[unit_structure + 01] = b(bu[800694fa]); // cover modifier

[unit_structure + 02] = b(bu[8006953c]); // set strength
[unit_structure + 03] = b(bu[8006953e]); // set vitality
[unit_structure + 04] = b(bu[80069540]); // set magic
[unit_structure + 05] = b(bu[80069542]); // set spirit
[unit_structure + 06] = b(bu[80069544]); // set dexterity
[unit_structure + 07] = b(bu[80069546]); // set luck

[unit_structure + 0c] = h(hu[8006954c]);
[unit_structure + 0e] = h(hu[8006954e]);

[unit_structure + 12] = b(bu[80069550]); // set hp
[unit_structure + 16] = b(bu[80069552]); // set mp
////////////////////////////////



////////////////////////////////
// func1ae08
V0 = h[GP + 128];
if (V0 >= 21)
{
    [GP + 128] = h(20);
}

V0 = h[GP + 12c];
if (V0 >= 21)
{
    [GP + 12c] = h(20);
}

V0 = h[GP + 12a];
if (V0 >= 100)
{
    [GP + 12a] = h(ff);
}

V0 = h[GP + 130];
if (V0 >= 100)
{
    [GP + 130] = h(ff);
}

unit_structure = w[GP + 11c];

[unit_structure + 437] = b(bu[unit_structure + 437] + bu[GP + 130]);
[unit_structure + 43c] = b(bu[unit_structure + 43c] + bu[GP + 128]);
[unit_structure + 43d] = b(bu[unit_structure + 43d] + bu[GP + 12a]);
[unit_structure + 43e] = b(bu[unit_structure + 43e] + bu[GP + 12c]);
[unit_structure + 43f] = b(bu[unit_structure + 43f] + bu[GP + 12e]);
////////////////////////////////



////////////////////////////////
// system_parse_megaall_materia
materia_data = A0;
A2 = A0 & ff;
V0 = bu[800730d0 + A2 * 14 + d];
V0 = V0 & 0f;
if (V0 == 4)
{
    A0 = A2;
    A1 = A0 >> 8;
    system_get_materia_activated_stars;
    A1 = V0;

    // add all to all magic
    A0 = 0;
    loop196dc:	; 800196DC
        V0 = w[GP + 11c];
        V1 = A0 * 8;
        V1 = V0 + V1;
        [V1 + 108] = b(V0);
        if (V0 != ff)
        {
            [V1 + 10a] = b(bu[V1 + 10a] + A1);
        }

        A0 = A0 + 1;
        V0 = A0 < 38;
    8001970C	bne    v0, zero, loop196dc [$800196dc]



    A3 = ff;
    A2 = 800101e8;
    A0 = 0;

    loop19720:	; 80019720
        V0 = w[GP + 11c];
        V0 = V0 + A0;
        V0 = bu[V0 + 4c];

        if (V0 != ff)
        {
            switch (V1)
            {
                case 5 6 9 a b 11:
                {
                    V1 = w[GP + 11c];
                    [V1 + A0 + 4c + 4] = b(V0 + A1);

                }
            }
        }

        A0 = A0 + 6;
        V0 = A0 < 60;
    80019780	bne    v0, zero, loop19720 [$80019720]



    // if first command not flash - replace it with slash all.
    V0 = w[GP + 11c];
    V1 = bu[V0 + 4c];
    if (V1 != 1a)
    {
        A0 = 18;
        A1 = 0;
        system_copy_command_to_unit_structure;
    }
}
////////////////////////////////



////////////////////////////////
// system_sort_magic_in_unit_structure
party_id = A0;
T1 = SP + 98;
V0 = hu[8009d7be];
V0 = V0 >> a;
T3 = V0 & 7; // magic order
A3 = SP;

T2 = 0;
loop1c12c:	; 8001C12C
    [SP + d0 + T2 * 8] = w(w[8009d84c + party_id * 440 + 108 + T2 * 8 + 0]);
    [SP + d4 + T2 * 8] = w(w[8009d84c + party_id * 440 + 108 + T2 * 8 + 4]);

    V0 = bu[8009d84c + party_id * 440 + 108 + T2 * 8];
    if (V0 != ff)
    {
        [SP + 98 + V0] = b(T2);
    }


    [8009d84c + party_id * 440 + 108 + T2 * 8] = b(ff);

    T2 = T2 + 1;
    V0 = T2 < 38;
8001C170	bne    v0, zero, loop1c12c [$8001c12c]



// clear with ff
T2 = 0;
loop1c184:	; 8001C184
    V1 = 17;
    loop1c18c:	; 8001C18C
        [SP + T2 * 18 + V1] = b(ff);
        V1 = V1 - 1;
    8001C194	bgez   v1, loop1c18c [$8001c18c]

    T2 = T2 + 1;
    V0 = T2 < 4;
8001C1A4	bne    v0, zero, loop1c184 [$8001c184]



// create order list
T2 = 0;
loop1c1c0:	; 8001C1C0
    A0 = bu[80082268 + f5c + T2];
00 01 02 08 03 04 05 06 07 0-8 restorative
43 44 40 41 42 45 49 4A 4B 51 46 47 48 4C 4D 4E 4F 50 9-1a independent
20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 1b-2c attack elemental
60 61 62 63 64 65 66 68 67 2d-35
    V0 = A0 >> 5;
    V1 = bu[8001029c + T3 * 4 + V0];
00010203
00020103
02000103
01000203
01020003
02010003
    A0 = A0 & 1f;
    [SP + V1 * 18 + A0] = b(T2);
    T2 = T2 + 1;
    V0 = T2 < 36;
8001C200	bne    v0, zero, loop1c1c0 [$8001c1c0]



// clear 38 slots in 60
T2 = 37;
V0 = SP + 97;
loop1c210:	; 8001C210
    [V0] = b(ff);
    V0 = V0 - 1;
    T2 = T2 - 1;
8001C218	bgez   t2, loop1c210 [$8001c210]



// copy magic id to 0x60 ordered by id
T2 = 0;
loop1c230:	; 8001C230
    V1 = bu[SP + d0 + T2 * 8];
    if (V1 != ff)
    {
        [SP + 60 + V1] = b(V1);
    }

    T2 = T2 + 1;
    V0 = T2 < 38;
8001C250	bne    v0, zero, loop1c230 [$8001c230]



T2 = 0;
loop1c268:	; 8001C268
    V1 = SP + T2 * 18;
    loop1c270:	; 8001C270
        V0 = bu[V1];
        if (V0 != ff)
        {
            [V1] = b(bu[SP + 60 + V0]);
        }

        V1 = V1 + 1;
        V0 = V1 < SP + T2 * 18 + 18;
    8001C294	bne    v0, zero, loop1c270 [$8001c270]

    T2 = T2 + 1;
    V0 = T2 < 4;
8001C2A4	bne    v0, zero, loop1c268 [$8001c268]



T3 = 0;
order_group = 0;
loop1c2c0:	; 8001C2C0
    T0 = 0;
    loop1c2c8:	; 8001C2C8
        V0 = bu[SP + order_group * 18 + T0 + 0];
        A0 = bu[SP + order_group * 18 + T0 + 1];
        V1 = bu[SP + order_group * 18 + T0 + 2];
        V0 = V0 & A0;
        V1 = V1 & V0;
        if (V1 != ff)
        {
            T1 = 8009d84c + party_id * 440 + 108 + T3 * 8
            A3 = SP + order_group * 18 + T0;
            T4 = SP + order_group * 18 + T0 + 3;

            loop1c2f0:	; 8001C2F0
                V0 = bu[A3];
                if (V0 != ff)
                {
                    V0 = bu[SP + 98 + V0];
                    [T1 + 0] = w(w[SP + V0 * 8 + 0]);
                    [T1 + 4] = w(w[SP + V0 * 8 + 4]);
                }

                T1 = T1 + 8;
                A3 = A3 + 1;
                T3 = T3 + 1;
                V0 = A3 < T4;
            8001C33C	bne    v0, zero, loop1c2f0 [$8001c2f0]
        }

        T0 = T0 + 3;
        V0 = T0 < 18;
    8001C34C	bne    v0, zero, loop1c2c8 [$8001c2c8]

    order_group = order_group + 1;
    V0 = order_group < 4;
8001C35C	bne    v0, zero, loop1c2c0 [$8001c2c0]



T2 = 0;
loop1c378:	; 8001C378
    V1 = bu[8009d84c + party_id * 440 + 108 + T2 * 8];
    if (V1 != ff)
    {
        if (T2 >= 38)
        {
            V1 = V1 + 38;
        }

        if (V1 == 19 || V1 == 47)
        {
            [8009d84c + party_id * 440 + 108 + T2 * 8 + 4] = b(0);
        }
    }

    T2 = T2 + 1;
    V0 = T2 < 48;
8001C3B0	bne    v0, zero, loop1c378 [$8001c378]
////////////////////////////////



////////////////////////////////
// system_search_existed_magic()

magic_id = A0;

for( int i = 0; i < 38; ++i )
{
    if( bu[80069554 + i * 5 + 0] == magic_id )
    {
        return i;
    }
}

return -1;
////////////////////////////////
