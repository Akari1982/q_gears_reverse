////////////////////////////////
// funcae954()

unit_id = A0;
battle_speed = 0;
S3 = 0;
S1 = w[800f83e0 + unit_id * 68 + 0]; // current status
if (S1 < 0) // if imprisoned
{
    V1 = hu[800f7dc6];
    if (V1 == 1)
    {
        S1 = S1 | 02000000;
    }
    else if (V1 == 3)
    {
        S1 = S1 | 00000400;
    }
}

// if not stopped or dead
if ((S1 & 00000401) == 0)
{
    S3 = 22;
    battle_speed = hu[800f7da6]; // calculated battle speed

    if ((S1 & 00000200) == 0) // if not slowed
    {
        battle_speed = battle_speed << 1;
        S3 = 44;
        if (S1 & 00000100) // if haste
        {
            battle_speed = battle_speed << 1;
            S3 = 88;
        }
    }
}



// for players
if (unit_id < 3)
{
    A0 = unit_id;
    A1 = bu[800f83e0 + unit_id * 68 + 14]; // dexterity
    A2 = 5;
    funcb1218;

    unit_dexterity = V0 + 32;
}
// for enemy
else
{
    unit_dexterity = bu[800f83e0 + unit_id * 68 + 14]; // dexterity
}

party_dexterity = hu[800f7da8]; // party dexterity
V1 = battle_speed * unit_dexterity / party_dexterity;

// if paralized, petrified or sleep
if (S1 & 02004004)
{
    V1 = 0;
}

[800f5bb8 + unit_id * 44 + 0] = h[battle_speed];
[800f5bb8 + unit_id * 44 + 2] = h[V1];
[800f5bb8 + unit_id * 44 + a] = h[S3];
////////////////////////////////



////////////////////////////////
// funca3278()

[800f3944] = w(0);
[800f3948] = w(0);
[80163798] = b(ff);
////////////////////////////////



////////////////////////////////
// funca283c()

A1 = 0;
A0 = 0;

for(int i = 0; i < 6d; ++i )
{
    if( i == A1 )
    {
        [800f38ac + A0] = w(i);
        A0 = A0 + 4;
    }

    // 1F 0E 09 1F 00 0C 09 1F 01 0C 09 1F 02 0D 09 1F
    // 1E 09 1F 0A 16 09 1F 1D 09 1F 19 09 1F 0E 1C 09
    // 1F 0E 1B 09 1F 1A 09 1F 17 1F 03 0C 09 1F 1F 1F
    // 1F 0E 09 1F 04 0B 0F 1F 05 1F 06 0C 09 1F 00 0C
    // 09 1F 01 0C 09 1F 02 0D 09 1F 0E 09 1F 12 0E 09
    // 1F 0E 18 09 1F 10 0E 09 1F 1F 1F 1F 1F 07 0C 09
    // 1F 08 1F 11 1F 13 09 1F 14 1F 15 0F 1F
    if( bu[800a0098 + i] == 1f )
    {
        A1 = i + 1;
    }
}
////////////////////////////////



////////////////////////////////
// funcad480()

A1 = 0;
A2 = 0;
A0 = 0;

for( int i = 0; i < 1e; ++i )
{
    if( A1 < 10 )
    {
        if( i == A2 )
        {
            [800f495c + A0] = w(i);
            A0 = A0 + 4;
            A1 = A1 + 1;
        }

        // 08 00 02 08 01 08 03 08 04 08 05 08 00 02 08 01
        // 08 07 08 06 08 00 02 08 00 08 08 08 08 08
        if( bu[800e7bcc + i] == 8 )
        {
            A2 = i + 1;
        }
    }
}
////////////////////////////////



////////////////////////////////
// funca71f4()

for( int i = 0; i < 3; ++i )
{
    for( int j = 0; j < 80; ++j )
    {
        [800f4308 + i * 200 + j * 4] = b(ff);
    }

    [800f4908 + i * 4] = w(0);
    [800f4914 + i * 4] = w(0);
}
////////////////////////////////



////////////////////////////////
// funcdcf94()

if( A0 == -1 )
{
    [800f1e4f] = b(0);
}
else
{
    [800f1e4f] = b(1);
    [800f1e50] = h(A0);
}
////////////////////////////////



////////////////////////////////
// funca55bc()

for( int i = 0; i < 10; ++i )
{
    [800f3a40 + i * 4 + 0] = h(ffff);
    [800f3a40 + i * 4 + 2] = h(ffff);
}
////////////////////////////////



////////////////////////////////
// funca4ba4()

party_id = A0;

// copy usual attack command
[800f39f0 + party_id * 6 + 0] = w(w[8009d84c + party_id * 440 + 4c + 0]);
[800f39f0 + party_id * 6 + 4] = b(b[8009d84c + party_id * 440 + 4c + 4]);
[800f39f0 + party_id * 6 + 5] = b(b[8009d84c + party_id * 440 + 4c + 5]);

[800f3a04 + party_id * 6 + 0] = b(1);
[800f3a04 + party_id * 6 + 4] = b(b[800f39f0 + party_id * 6 + 4]);
[800f3a04 + party_id * 6 + 5] = b(b[800f39f0 + party_id * 6 + 5]);

if( bu[800f5bb8 + party_id * 44 + 29] & 2 ) // if long ranged
{
    [800f3a04 + party_id * 6 + 1] = b(0);
}
else
{
    [800f3a04 + party_id * 6 + 1] = b(7);
}

[800f3a04 + party_id * 6 + 2] = b(bu[800f5efc + party_id * 18 + 0]);
////////////////////////////////



////////////////////////////////
// funca4e80()

party_id = A0;

if( bu[800f5e60 + party_id * 34 + 5] != ff ) // limit level
{
    [80163762] = h(hu[80163762] | (1 << party_id));

    [800f5bb8 + party_id * 44 + 8] = h(hu[800f5bb8 + party_id * 44 + 8] | 0001);
    [800f5bb8 + party_id * 44 + e] = b(bu[800f5bb8 + party_id * 44 + e] | 01);
}
////////////////////////////////



////////////////////////////////
// funcb108c()

A0 = party_id = A0;
A1 = 5;
A2 = 0;
A3 = 0;
funca31a0();
////////////////////////////////



////////////////////////////////
// funca31a0()

S0 = A0;
S1 = A1;
S2 = A2;
S3 = A3;

funca2f4c();

[V0 + 0] = b(S0);
[V0 + 1] = b(S1);
[V0 + 5] = b(S2);
[V0 + 6] = h(S3);
[V0 + 8] = h(-1);
[V0 + a] = h(-1);
////////////////////////////////



////////////////////////////////
// funca2f4c()

V1 = w[800f3944];
[80163798 + V1 * c + 2] = b(0);
[80163798 + V1 * c + 3] = b(0);
[80163798 + V1 * c + a] = h(w[800f3948]);

if( V1 < 40 )
{
    [800f3944] = w(w[800f3944] + 1);
}
else
{
    A0 = 0028; // error code
    func155a4();
}

return 80163798 + V1 * c;
////////////////////////////////
