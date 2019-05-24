////////////////////////////////
// run_script()
exec_num = A0;

[800af594] = w(0);
[800af150] = w(exec_num);

if( exec_num <= 0 )
{
    return;
}

S0 = 0;
loopa1488:	; 800A1488
    // do not execute too much opcodes
    if( S0 >= 401 )
    {
        if( w[800c1b60] == 0 )
        {
            A0 = 8006f414; // "EVENTLOOP ERROR ACT=%d"
            A1 = w[800af1f0]; // current entity id
            system_print_alias();
        }
        return;
    }

    date_138 = w[800af54c];
    V1 = hu[date_138 + cc];
    V0 = w[800ad0d8];
    V0 = bu[V0 + V1];
    V0 = w[800ad778 + V0 * 4];
    jalr   v0 ra

00110A80 00
04140A80 01
60110A80 02
1C100A80 04
840D0A80 05
C00C0A80 06
08E10980 07
F8E20980 08
30E60980 09
10490980 0a
B40B0A80 0b
480E0A80 0d
D8190980 0e
B8190980 0f
10 D481098010820980D427098050250A801C3209804032098048FE0980ACDE0980CCDD09804CDA0980B8D90980ECD8098058D80980D8D7098098D7098030D70980
9CD60980 20
24D60980 21
A0D40980 22
D0D50980 23
7CD30980 24
24D40980 25
C4D20980 26
58D10980 28
54D00980 29
ACCF0980 2a
D4CF0980 2b
04970980 2c
F8950980 2d
98950980 2e
CC940980 2f
30 1C950980745709809C570980C4570980E857098034CF0980F0CE0980ACCE098020CE098094CD0980D4CB098098C90980D0C8098034C9098048CB0980BCCA0980
40 30CA098060C80980F0C7098028C7098058770980386E0980DC1D098074240980A43209801C330980548F0980047A0980C46F0980286F09804479098048780980
50 786D09807C6C0980D07609800C760980946B0980706A0980E8250980E8870980EC3E09805CEA09802048098058480980B8F70980489709808097098040A30980
60 A4F3088000F40880D8F4088064F508803CF6088098F6088070F70880D0A1098008A2098050A2098088A2098030A1098080A10980809C09803C9D09807C980980
70 B89709803C2B0980F8EC0880486208803CEC088040ED08803C3009806C300980786909803868098080680980D05F0980EC640980E4650980DC660980D4480980
80 381C09809C1C0980382C09803C1D0980185C0980885C0980F85C0980645D0980BC5D09801C540980D451098094580980F0580980E0590980F85409808C550980
F0550980 90
845A0980 91
400F0A80 92
F4080A80 93
A83B0980 94
243C0980 95
603C0980 96
089C0980 97
6CF10880 99
20F20880 9a
14F30880 9b
20990980 9d
74AF0980 9e
E0AF0980 9f
50B00980 a0
449C0980 a1
609B0980 a2
FCF70880 a3
089B0980 a5
E4690980 a6
80C70980 a8
C0A20980 aa
D4F80880 ab
90F90880 ac
EC000980 ad
70010980 ae
F4010980 af
8C020980 b0
24030980 b1
B49B0980 b2
F0680980 b3
38690980 b4
80AC0980 b6
B0A30980 b7
E0A30980 b8
085B0980 b9
7C5B0980 ba
C85B0980 bb
CC020A80 bc
30400980 bd
A0400980 be
10410980 bf
80410980 c0
F0410980 c1
60420980 c2
C8680980 c3
04340980 c4
94350980 c5
2C140A80 c6
084D0980 c9
F89D0980 ca
944E0980 cb
F44A0980 cc
00D00980 cd
28D00980 ce
D8C30980 cf
70C40980 d0
00C50980 d1
FC1B0980 d5
741B0980 d6
903C0980 d7
E43C0980 d8
383D0980 d9
BC170980 da
58150980 db
18160980 dc
D4130980 dd
68CC0980 de
F8CC0980 df
e0 6C14098090110980245709804C570980A8100980180F0980DC0F09804C1009802C37098080390980D023098094060980EC080980980B0980F40C09800CF00880
C0030980 f0
1CA80880 f1
E0EE0880 f2
44040980 f3
70B40980 f4
70DB0880 f8
38D40880 f9
843D0980 fa
54CD0880 fb
50250A80 fd
CC5F0880 fe
50250A80 ff

    // if ??? set exec opcodes number to maximum
    if( w[800af4c0] == 0 )
    {
        [800af150] = w(ffff);
    }

    if( ( w[800acff4] != 0 ) && ( w[800ad0d8] == 0 || w[800ad0bc] == 0 || w[800ad0c4] == 0 ) )
    {
        return;
    }

    if( ( w[800af594] == 1 ) && ( w[800af4c0] == 1 ) )
    {
        return;
    }

    S0 = S0 + 1;
    V0 = S0 < exec_num;
800A15A0	bne    v0, zero, loopa1488 [$800a1488]
////////////////////////////////



////////////////////////////////
// call_run_script_8()
// called in move routine
// run 8 opcodes for non-party entities

if( w[800ad04c] == 1 )
{
    number_of_entity = 1;
}
else
{
    number_of_entity = w[800ad0d4]; // number of entity
}

[800ad040] = w(0);
[800c373c] = w(0); // maybe number of inited windows.

if( number_of_entity <= 0 )
{
    return;
}

entity_id = 0;
La1624:	; 800A1624
    struct_5c_p = w[800aefe4];

    if( hu[struct_5c_p + entity_id * 5c + 58] & 0f00 )
    {
        struct_138 = w[struct_5c_p + entity_id * 5c + 4c];
        // we dont move if this bit is set
        if( ( w[struct_138 + 4] & 00100000 ) == 0 )
        {
            if( w[800acff4] != 0 )
            {
                if( ( w[800ad0b8] == 0 ) || ( w[800ad0bc] == 0 ) || ( w[800ad0c4] == 0 ))
                {
                    return;
                }
            }

            [struct_138 + 0] = w(w[struct_138 + 0] & feffffff);
            [800afb8c] = w(struct_5c_p + entity_id * 5c);
            [800af1f0] = w(entity_id);
            [800af54c] = w(struct_138);

            if( bu[800b16a0] != 0 )
            {
                party_id = 0;
                loopa16fc:	; 800A16FC
                    if( w[80059ad4 + party_id * 4] != ff )
                    {
                        // if this entity is in party - skip it
                        800A170C	beq    v0, entity_id, La1808 [$800a1808]
                    }
                    party_id = party_id + 1;
                    V0 = party_id < 3;
                800A171C	bne    v0, zero, loopa16fc [$800a16fc]
            }

            top_priority = f;

            script_slot_id = 0;
            loopa1728:	; 800A1728
                priority = (w[struct_138 + 8c + script_slot_id * 8 + 4] >> 12) & f;
                if( top_priority >= priority )
                {
                    top_priority = priority;
                    [struct_138 + ce] = b(script_slot_id);
                }
                script_slot_id = script_slot_id + 1;
                V0 = script_slot_id < 8;
            800A1764	bne    v0, zero, loopa1728 [$800a1728]

            // if there is no script in slots add script 1 to first slot
            if( top_priority == f )
            {
                A0 = entity_id;
                A1 = 1;
                get_script_offset();

                [struct_138 + 8c + 0] = h(V0);
                [struct_138 + ce] = b(0);
                [struct_138 + 8c + 4] = w((w[struct_138 + 8c + 4] & ffc3ffff) | 001c0000); // run script with priority 7
            }

            [800af4c0] = w(1); // execute once and finish at stop

            V0 = bu[struct_138 + ce]; // current script slot
            [struct_138 + cc] = h(hu[struct_138 + 8c + V0 * 8 + 0]);

            if( ( w[struct_138 + 0] & 00000001 ) == 0 )
            {
                // execute 8 opcodes
                A0 = 8;
                run_script();
            }

            // update script pointer in slot
            V1 = bu[struct_138 + ce]; // current script slot
            [struct_138 + 8c + V1 * 8 + 0] = h(hu[struct_138 + cc]);
        }
    }

    entity_id = entity_id + 1;
    V0 = entity_id < number_of_entity;
800A1810	bne    v0, zero, La1624 [$800a1624]
////////////////////////////////



////////////////////////////////
// funca183c
// call script_for_entity 0
script_id = A0;



struct_5c_p = w[800aefe4];
struct_138 = w[struct_5c_p + 4c];



A0 = 138;
A1 = 1;
system_memory_allocate();
S0 = V0;



// copy data from first entity to temp
A3 = 0;
loopa1890:	; 800A1890
    [S0 + A3] = w(w[struct_138 + A3]);
    A3 = A3 + 4;
800A18B4	bne    a3, 138, loopa1890 [$800a1890]



// set up scripts to entity 0
A2 = 0;
loopa18f4:	; 800A18F4
    [struct_138 + A2 * 8 + 8c] = h(ffff); // requested script
    [struct_138 + A2 * 8 + 8e] = b(0); // wait
    [struct_138 + A2 * 8 + 8f] = b(ff); // script id
    [struct_138 + A2 * 8 + 90] = w((w[struct_138 + A2 * 8 + 90] & fffcffff) | 003c0000); // lowest priority
    [struct_138 + A2 * 8 + 90] = w(w[struct_138 + A2 * 8 + 90] & ffbfffff); // script state?
    [struct_138 + A2 * 8 + 90] = h(ffff); // number of steps
    [struct_138 + A2 * 8 + 90] = w(w[struct_138 + A2 * 8 + 90] & fe7fffff); // argument read type
    A2 = A2 + 1;
    V0 = A2 < 8;
800A1960	bne    v0, zero, loopa18f4 [$800a18f4]



// start script
[800af1f0] = w(0); // current entity id for script call
[800af4c0] = w(0); // wait state for return
[800af54c] = struct_138;
[800afb8c] = w(struct_5c_p);



[800acff4] = w(0);

A0 = 0;
A1 = script_id;
get_script_offset();
[struct_138 + cc] = h(V0);

A0 = ffff;
run_script();

[800acff4] = w(1);



// restore data from temp to first entity
A3 = 0;
loopa1890:	; 800A1890
    [struct_138 + A3] = w(w[S0 + A3]);
    A3 = A3 + 4;
800A18B4	bne    a3, 138, loopa1890 [$800a1890]



A0 = S0;
system_memory_mark_removed_alloc();
////////////////////////////////



////////////////////////////////
// funca1a18
800A1A18	addiu  sp, sp, $ffe8 (=-$18)
V0 = 0001;
[SP + 0010] = w(RA);
[800ad064] = w(V0);
800A1A2C	jal    funca183c [$800a183c]
A0 = 0003;
800A1A34	jal    funcac2fc [$800ac2fc]
800A1A38	nop
[800ad064] = w(0);
RA = w[SP + 0010];
SP = SP + 0018;
800A1A4C	jr     ra 
800A1A50	nop
////////////////////////////////



////////////////////////////////
// funca1a54
V0 = w[8004e9b0];
800A1A5C	addiu  sp, sp, $ffc0 (=-$40)
[SP + 003c] = w(RA);
[SP + 0038] = w(S2);
[SP + 0034] = w(S1);
800A1A6C	beq    v0, zero, La1c88 [$800a1c88]
[SP + 0030] = w(S0);
800A1A74	jal    funca183c [$800a183c]
A0 = 0002;
800A1A7C	jal    funcacd70 [$800acd70]
S1 = 0;
V1 = 800b1738;
V0 = w[V1 + 0000];
800A1A90	nop
800A1A94	blez   v0, La1ac8 [$800a1ac8]
A0 = S1 & ffff;
800A1A9C	addiu  s2, v1, $ff80 (=-$80)
S0 = S2;

loopa1aa4:	; 800A1AA4
A2 = h[S0 + 0000];
S0 = S0 + 0002;
800A1AAC	jal    $801e8330
A1 = 0;
V0 = w[S2 + 0080];
S1 = S1 + 0001;
V0 = S1 < V0;
800A1AC0	bne    v0, zero, loopa1aa4 [$800a1aa4]
A0 = S1 & ffff;

La1ac8:	; 800A1AC8
V1 = w[800b1740];
800A1AD0	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800A1AF8	nop
S1 = bu[V1 + 0074];
V0 = 00ff;
800A1B04	beq    s1, v0, La1b1c [$800a1b1c]
800A1B08	nop
V0 = w[V1 + 0024];
800A1B10	nop
800A1B14	addiu  v0, v0, $fff8 (=-$8)
[V1 + 0024] = w(V0);

La1b1c:	; 800A1B1C
V0 = w[800aefe0];
800A1B24	nop
800A1B28	blez   v0, La1c88 [$800a1c88]
S1 = 0;
A2 = 800b16a6;
A1 = 0;

loopa1b3c:	; 800A1B3C
V0 = w[800ad0d4];
800A1B44	nop
V0 = S1 < V0;
800A1B4C	beq    v0, zero, La1b88 [$800a1b88]
800A1B50	nop
V0 = w[800aefe4];
800A1B5C	nop
V0 = A1 + V0;
V0 = w[V0 + 004c];
800A1B68	nop
V0 = w[V0 + 012c];
800A1B70	nop
V0 = V0 & 0003;
800A1B78	beq    v0, zero, La1bfc [$800a1bfc]
800A1B7C	nop
800A1B80	j      La1c70 [$800a1c70]
800A1B84	nop

La1b88:	; 800A1B88
V0 = bu[A2 + 0000];
800A1B8C	nop
V0 = V0 & 007f;
800A1B94	bne    v0, zero, La1bfc [$800a1bfc]
800A1B98	nop
A0 = w[800aefe4];
V1 = w[A2 + ffea];
A0 = A1 + A0;
V0 = w[A0 + 0020];
800A1BB0	nop
V0 = V0 + V1;
[A0 + 0020] = w(V0);
A0 = w[800aefe4];
V1 = w[A2 + ffee];
A0 = A1 + A0;
V0 = w[A0 + 0024];
800A1BD0	nop
V0 = V0 + V1;
[A0 + 0024] = w(V0);
A0 = w[800aefe4];
V1 = w[A2 + fff2];
A0 = A1 + A0;
V0 = w[A0 + 0028];
800A1BF0	nop
V0 = V0 + V1;
[A0 + 0028] = w(V0);

La1bfc:	; 800A1BFC
V0 = bu[A2 + 0000];
V1 = 0001;
V0 = V0 & 007f;
800A1C08	bne    v0, v1, La1c70 [$800a1c70]
800A1C0C	nop
A0 = w[800aefe4];
V1 = w[A2 + ffea];
A0 = A1 + A0;
V0 = w[A0 + 0020];
800A1C24	nop
V0 = V0 + V1;
[A0 + 0020] = w(V0);
A0 = w[800aefe4];
V1 = w[A2 + ffee];
A0 = A1 + A0;
V0 = w[A0 + 0024];
800A1C44	nop
V0 = V0 + V1;
[A0 + 0024] = w(V0);
A0 = w[800aefe4];
V1 = w[A2 + fff2];
A0 = A1 + A0;
V0 = w[A0 + 0028];
800A1C64	nop
V0 = V0 + V1;
[A0 + 0028] = w(V0);

La1c70:	; 800A1C70
V0 = w[800aefe0];
S1 = S1 + 0001;
V0 = S1 < V0;
800A1C80	bne    v0, zero, loopa1b3c [$800a1b3c]
A1 = A1 + 005c;

La1c88:	; 800A1C88
RA = w[SP + 003c];
S2 = w[SP + 0038];
S1 = w[SP + 0034];
S0 = w[SP + 0030];
SP = SP + 0040;
800A1C9C	jr     ra 
800A1CA0	nop
////////////////////////////////



////////////////////////////////
// funca1ca4
V0 = w[8004e9b0];
800A1CAC	addiu  sp, sp, $ffc8 (=-$38)
[SP + 0034] = w(RA);
[SP + 0030] = w(S2);
[SP + 002c] = w(S1);
800A1CBC	beq    v0, zero, La1e48 [$800a1e48]
[SP + 0028] = w(S0);
V0 = w[800ad0d4];
800A1CCC	nop
800A1CD0	blez   v0, La1d78 [$800a1d78]
S0 = 0;
S1 = 0;

loopa1cdc:	; 800A1CDC
A0 = 0004;
800A1CE0	jal    $80028280
A1 = 0;
V0 = w[800aefe4];
800A1CF0	nop
V0 = S1 + V0;
A1 = w[V0 + 004c];
800A1CFC	nop
V1 = h[A1 + 0124];
800A1D04	addiu  v0, zero, $ffff (=-$1)
800A1D08	beq    v1, v0, La1d58 [$800a1d58]
800A1D0C	nop
A0 = h[A1 + 0124];
[800af54c] = w(A1);
800A1D1C	jal    $800286fc
800A1D20	nop
A0 = V0 + 0008;
800A1D28	jal    $800319ec
A1 = 0;
A1 = V0;
V1 = w[800af54c];
A2 = 0;
A0 = h[V1 + 0124];
A3 = 0080;
800A1D48	jal    $800293e8
[V1 + 0120] = w(A1);
800A1D50	jal    $80028870
A0 = 0;

La1d58:	; 800A1D58
V0 = w[800ad0d4];
S0 = S0 + 0001;
V0 = S0 < V0;
800A1D68	bne    v0, zero, loopa1cdc [$800a1cdc]
S1 = S1 + 005c;
V0 = w[800ad0d4];

La1d78:	; 800A1D78
800A1D78	nop
800A1D7C	blez   v0, La1ddc [$800a1ddc]
S0 = 0;
800A1D84	addiu  s2, zero, $ffff (=-$1)
S1 = 0;

loopa1d8c:	; 800A1D8C
V0 = w[800aefe4];
800A1D94	nop
V1 = S1 + V0;
A1 = w[V1 + 004c];
800A1DA0	nop
V0 = h[A1 + 0124];
800A1DA8	nop
800A1DAC	beq    v0, s2, La1dc4 [$800a1dc4]
800A1DB0	nop
A0 = w[V1 + 0004];
A1 = w[A1 + 0120];
800A1DBC	jal    $80021a38
800A1DC0	nop

La1dc4:	; 800A1DC4
V0 = w[800ad0d4];
S0 = S0 + 0001;
V0 = S0 < V0;
800A1DD4	bne    v0, zero, loopa1d8c [$800a1d8c]
S1 = S1 + 005c;

La1ddc:	; 800A1DDC
800A1DDC	jal    funca321c [$800a321c]
800A1DE0	nop
V0 = h[800b154c];
800A1DEC	nop
800A1DF0	beq    v0, zero, La1e04 [$800a1e04]
A0 = 0010;
800A1DF8	jal    funca3d24 [$800a3d24]
A0 = 0001;
A0 = 0010;

La1e04:	; 800A1E04
800A1E04	jal    put_bytes_to_800C2F3C [$800a2604]
A1 = 0;
800A1E0C	jal    funca2644 [$800a2644]
S0 = 0;
V0 = w[800ad0d4];
800A1E1C	nop
800A1E20	blez   v0, La1e48 [$800a1e48]
800A1E24	nop

loopa1e28:	; 800A1E28
800A1E28	jal    func718e4 [$800718e4]
A0 = S0;
V0 = w[800ad0d4];
S0 = S0 + 0001;
V0 = S0 < V0;
800A1E40	bne    v0, zero, loopa1e28 [$800a1e28]
800A1E44	nop

La1e48:	; 800A1E48
RA = w[SP + 0034];
S2 = w[SP + 0030];
S1 = w[SP + 002c];
S0 = w[SP + 0028];
SP = SP + 0038;
800A1E5C	jr     ra 
800A1E60	nop
////////////////////////////////



////////////////////////////////
// funca1e64()
V0 = w[8004e9b0];
if (V0 != 0)
{
    800A1E84	jal    funca2a04 [$800a2a04]
    S1 = 0;
    V0 = w[800ad0d4];
    800A1E94	nop
    800A1E98	blez   v0, La2154 [$800a2154]
    800A1E9C	nop
    S0 = 0;

    La1ea4:	; 800A1EA4
    V0 = w[800aefe4];
    800A1EAC	nop
    V0 = S0 + V0;
    V1 = w[V0 + 004c];
    800A1EB8	nop
    A2 = bu[V1 + 0126];
    800A1EC0	nop
    V0 = A2 & 0080;
    800A1EC8	bne    v0, zero, La1f4c [$800a1f4c]
    V0 = A2 & 007f;
    A1 = bu[V1 + 0127];
    A3 = w[V1 + 0130];
    V0 = w[V1 + 0134];
    V1 = w[800aefe4];
    V0 = V0 & 000f;
    V1 = S0 + V1;
    [SP + 0010] = w(V0);
    V0 = w[V1 + 004c];
    800A1EF4	nop
    V1 = bu[V0 + 0126];
    V0 = w[800aefe4];
    800A1F04	nop
    V0 = S0 + V0;
    [SP + 0014] = w(V1);
    V0 = w[V0 + 004c];
    A0 = S1;
    V0 = w[V0 + 0134];
    A3 = A3 >> 1c;
    V0 = V0 >> 04;
    V0 = V0 & 0001;
    [SP + 0018] = w(V0);
    V0 = A2 << 02;
    800A1F30	lui    at, $8006
    AT = AT + V0;
    A2 = w[AT + 9aa4];
    800A1F3C	jal    func76150 [$80076150]
    A3 = A3 & 0003;
    800A1F44	j      La213c [$800a213c]
    800A1F48	nop

    La1f4c:	; 800A1F4C
    V0 = V0 << 02;
    A2 = w[800aeff0];
    A1 = bu[V1 + 0127];
    A3 = w[V1 + 0130];
    V0 = V0 + A2;
    T0 = w[V0 + 0004];
    V0 = w[V1 + 0134];
    V1 = w[800aefe4];
    V0 = V0 & 000f;
    V1 = S0 + V1;
    [SP + 0010] = w(V0);
    V0 = w[V1 + 004c];
    800A1F84	nop
    V0 = bu[V0 + 0126];
    A0 = S1;
    [SP + 0014] = w(V0);
    V0 = w[800aefe4];
    A3 = A3 >> 1c;
    V0 = S0 + V0;
    V0 = w[V0 + 004c];
    A3 = A3 & 0003;
    V0 = w[V0 + 0134];
    A2 = T0 + A2;
    V0 = V0 >> 04;
    V0 = V0 & 0001;
    800A1FBC	jal    func76150 [$80076150]
    [SP + 0018] = w(V0);
    V0 = w[800aefe4];
    800A1FCC	nop
    A0 = S0 + V0;
    V0 = w[A0 + 004c];
    800A1FD8	nop
    V0 = hu[V0 + 012e];
    800A1FE0	nop
    V1 = V0 & 0003;
    V0 = 0001;
    800A1FEC	beq    v1, v0, La2004 [$800a2004]
    V0 = 0002;
    800A1FF4	beq    v1, v0, La2074 [$800a2074]
    A1 = 0003;
    800A1FFC	j      La213c [$800a213c]
    800A2000	nop

    La2004:	; 800A2004
    A1 = 0002;
    A0 = w[A0 + 0004];
    800A200C	jal    func22eb8 [$80022eb8]
    A2 = 0;
    V0 = w[800aefe4];
    800A201C	nop
    V0 = S0 + V0;
    V1 = w[V0 + 004c];
    A0 = w[V0 + 0004];
    V0 = w[V1 + 012c];
    V1 = w[A0 + 007c];
    V0 = V0 >> 12;
    V1 = w[V1 + 0018];
    V0 = V0 & 03ff;
    [V1 + 0004] = h(V0);
    V0 = w[800aefe4];
    800A204C	nop
    V0 = S0 + V0;
    V1 = w[V0 + 0004];
    V0 = w[V0 + 004c];
    V1 = w[V1 + 007c];
    V0 = w[V0 + 0130];
    V1 = w[V1 + 0018];
    V0 = V0 & 01ff;
    800A206C	j      La213c [$800a213c]
    [V1 + 0006] = h(V0);

    La2074:	; 800A2074
    A0 = w[A0 + 0004];
    800A2078	jal    func22eb8 [$80022eb8]
    A2 = 0;
    V0 = w[800aefe4];
    800A2088	nop
    V0 = S0 + V0;
    V1 = w[V0 + 004c];
    A0 = w[V0 + 0004];
    V0 = w[V1 + 012c];
    V1 = w[A0 + 007c];
    V0 = V0 >> 12;
    V1 = w[V1 + 0018];
    V0 = V0 & 03ff;
    [V1 + 0004] = h(V0);
    V0 = w[800aefe4];
    800A20B8	nop
    V0 = S0 + V0;
    V1 = w[V0 + 0004];
    V0 = w[V0 + 004c];
    V1 = w[V1 + 007c];
    V0 = w[V0 + 0130];
    V1 = w[V1 + 0018];
    V0 = V0 & 01ff;
    [V1 + 0006] = h(V0);
    V0 = w[800aefe4];
    800A20E4	nop
    V0 = S0 + V0;
    V1 = w[V0 + 004c];
    A0 = w[V0 + 0004];
    V0 = w[V1 + 0130];
    V1 = w[A0 + 007c];
    V0 = V0 >> 09;
    V1 = w[V1 + 0018];
    V0 = V0 & 03ff;
    [V1 + 0008] = h(V0);
    V0 = w[800aefe4];
    800A2114	nop
    V0 = S0 + V0;
    V1 = w[V0 + 004c];
    A0 = w[V0 + 0004];
    V0 = w[V1 + 0130];
    V1 = w[A0 + 007c];
    V0 = V0 >> 13;
    V1 = w[V1 + 0018];
    V0 = V0 & 01ff;
    [V1 + 000a] = h(V0);

    La213c:	; 800A213C
    V0 = w[800ad0d4];
    S1 = S1 + 0001;
    V0 = S1 < V0;
    800A214C	bne    v0, zero, La1ea4 [$800a1ea4]
    S0 = S0 + 005c;

    La2154:	; 800A2154
    V0 = w[800b173c];
    800A215C	nop
    800A2160	beq    v0, zero, La2534 [$800a2534]
    S1 = 0;
    A2 = 8006f020;
    A3 = 80059ad4;

    La2178:	; 800A2178
    A0 = w[A3 + 0000];
    V0 = 00ff;
    800A2180	beq    a0, v0, La2354 [$800a2354]
    800A2184	nop
    V0 = w[80059a38];
    800A2190	nop
    V0 = V0 + S1;
    V0 = bu[V0 + 22b1];
    800A219C	nop
    800A21A0	beq    v0, zero, La22d4 [$800a22d4]
    V1 = A0 << 01;
    V1 = V1 + A0;
    V1 = V1 << 03;
    V1 = V1 - A0;
    V1 = V1 << 02;
    A1 = w[800aefe4];
    A0 = w[A2 + 0000];
    V1 = V1 + A1;
    V0 = A0 << 01;
    V0 = V0 + A0;
    V0 = V0 << 03;
    V0 = V0 - A0;
    V0 = V0 << 02;
    V0 = V0 + A1;
    V0 = w[V0 + 0004];
    A0 = w[V1 + 0004];
    [V1 + 0004] = w(V0);
    V1 = w[A2 + 0000];
    800A21F0	nop
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = V0 - V1;
    V1 = w[800aefe4];
    V0 = V0 << 02;
    V0 = V0 + V1;
    [V0 + 0004] = w(A0);
    V1 = w[A2 + 0000];
    800A221C	nop
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = V0 - V1;
    V1 = w[800aefe4];
    V0 = V0 << 02;
    V0 = V0 + V1;
    V1 = w[V0 + 004c];
    800A2244	nop
    V0 = w[V1 + 0000];
    800A224C	nop
    V0 = V0 | 0200;
    [V1 + 0000] = w(V0);
    V1 = w[A2 + 0000];
    800A225C	nop
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = V0 - V1;
    V1 = w[800aefe4];
    V0 = V0 << 02;
    V0 = V0 + V1;
    A0 = w[V0 + 004c];
    800A2284	nop
    V0 = w[A0 + 0000];
    800A228C	addiu  v1, zero, $faff (=-$501)
    V0 = V0 & V1;
    [A0 + 0000] = w(V0);
    V0 = w[A2 + 0000];
    800A229C	nop
    V1 = V0 << 01;
    V1 = V1 + V0;
    V1 = V1 << 03;
    V1 = V1 - V0;
    V0 = w[800aefe4];
    V1 = V1 << 02;
    V1 = V1 + V0;
    V0 = hu[V1 + 0058];
    800A22C4	nop
    V0 = V0 | 0020;
    800A22CC	j      La2354 [$800a2354]
    [V1 + 0058] = h(V0);

    La22d4:	; 800A22D4
    V1 = w[A2 + 0000];
    800A22D8	nop
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = V0 - V1;
    V1 = w[800aefe4];
    V0 = V0 << 02;
    V0 = V0 + V1;
    V1 = w[V0 + 004c];
    800A2300	nop
    V0 = w[V1 + 0000];
    800A2308	nop
    V0 = V0 | 0400;
    [V1 + 0000] = w(V0);
    V1 = w[A2 + 0000];
    800A2318	nop
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = V0 - V1;
    V1 = w[800aefe4];
    V0 = V0 << 02;
    V0 = V0 + V1;
    A0 = w[V0 + 004c];
    800A2340	nop
    V0 = w[A0 + 0000];
    800A2348	addiu  v1, zero, $fcff (=-$301)
    V0 = V0 & V1;
    [A0 + 0000] = w(V0);

    La2354:	; 800A2354
    A2 = A2 + 0004;
    S1 = S1 + 0001;
    V0 = S1 < 0003;
    800A2360	bne    v0, zero, La2178 [$800a2178]
    A3 = A3 + 0004;
}
else
{
    A0 = 0010;
    800A2374	jal    put_bytes_to_800C2F3C [$800a2604]
    A1 = 0;
    800A237C	jal    funca2644 [$800a2644]
    S1 = 0;

    if ( w[800ad0d4] > 0)
    {
        S2 = 800aefe4;
        S0 = 0;

        loopa23a4:	; 800A23A4
            V0 = w[S2 + 0000];
            A0 = S1;
            V0 = V0 + S0;
            V1 = w[V0 + 004c];
            [800af1f0] = w(S1);
            [800afb8c] = w(V0);
            [800af54c] = w(V1);
            800A23CC	jal    get_script_offset [$800a2620]
            A1 = 0002;
            A0 = w[800af54c];
            V1 = w[800ad0d8];
            [A0 + 00cc] = h(V0);
            V0 = V0 & ffff;
            V1 = V1 + V0;
            V0 = bu[V1 + 0000];
            800A23F4	nop
            if (V0 == 0)
            {
                800A23FC	lui    v1, $0400
                V0 = w[A0 + 0004];
                800A2404	nop
                V0 = V0 | V1;
                [A0 + 0004] = w(V0);
            }

            [800af1f0] = w(S1);
            [800afb8c] = w(V0);

            V0 = w[S2 + 0];
            [800af54c] = w(w[S0 + V0 + 4c]);

            A0 = S1;
            A1 = 0;
            get_script_offset;

            A0 = w[800af54c];
            [A0 + cc] = h(V0);

            S0 = S0 + 5c;

            S1 = S1 + 1;
            V1 = S1 < w[800ad0d4];
        800A245C	bne    v1, zero, loopa23a4 [$800a23a4]
    }

    if (w[800ad0d4] > 0)
    {
        S1 = 0;
        S2 = 800aefe4;
        S0 = 0;

        loopa2484:	; 800A2484
            V0 = w[S2 + 0000];
            800A2488	nop
            V0 = V0 + S0;
            V1 = w[V0 + 004c];
            [800af1f0] = w(S1);
            [800af148] = w(0);
            [800af4c0] = w(0);
            [800afb8c] = w(V0);
            [800af54c] = w(V1);

            A0 = ffff;
            run_script();

            V0 = w[800af148];
            800A24CC	nop
            800A24D0	bne    v0, zero, La251c [$800a251c]

            A0 = S1;
            A1 = 0;
            A2 = w[S2 + 000c];
            A3 = 0;
            V1 = w[A2 + 0004];
            V0 = 0080;
            [SP + 0010] = w(0);
            [SP + 0014] = w(V0);
            [SP + 0018] = w(0);
            800A24F8	jal    func76150 [$80076150]
            A2 = V1 + A2;
            V1 = w[800af54c];
            800A2508	nop
            V0 = w[V1 + 0004];
            800A2510	nop
            V0 = V0 | 0800;
            [V1 + 0004] = w(V0);

            La251c:	; 800A251C
            S0 = S0 + 5c;
            S1 = S1 + 1;
            V0 = S1 < w[800ad0d4];
        800A252C	bne    v0, zero, loopa2484 [$800a2484]
    }
}

La2534:	; 800A2534
////////////////////////////////



////////////////////////////////
// funca2550
V1 = w[800af54c];
800A2558	nop
V0 = hu[V1 + 00cc];
800A2560	nop
V0 = V0 + 0001;
800A2568	jr     ra 
[V1 + 00cc] = h(V0);
////////////////////////////////



////////////////////////////////
// get_bytes_sign()
// [00000000][00xxxxx0] => x     (sign_mask)
// [xxxxxxxx][xx000000] => x * 4 (sign_data id)
script_file = w[800ad0d0];
sign_data = w[script_file + (A0 >> 6) * 4];
sign_mask = 1 << ((A0 >> 1) & 1f);

return 0 - (0 < (sign_data & sign_mask)); // 0 - signed, -1 unsigned
////////////////////////////////



////////////////////////////////
// get_bytes_from_800C2F3C()
// [xxxxxxxx][xxxxxxx0] => x (offset to read)
// [xxxxxxxx][xx000000] => x * 4 (offset to sign)
slot = A0 / 2;

script_file = w[800ad0d0];
sign_data = w[script_file + (slot >> 5) * 4]; // sign block
sign_bit = 1 << (slot & 1f);

if( sign_data & sign_bit ) // if bit in sign block is set
{
    return hu[800c2f3c + slot * 2];
}
else
{
    return h[800c2f3c + slot * 2];
}
////////////////////////////////



////////////////////////////////
// put_bytes_to_800C2F3C()
[800c2f3c + ((A0 >> 1) << 1)] = h(A1);
////////////////////////////////



////////////////////////////////
// get_script_offset()
V0 = w[800ad0d0];
return hu[V0 + 84 + A0 * 40 + A1 * 2];
////////////////////////////////



////////////////////////////////
// funca2644()
A0 = 3e;
A1 = w[80061c20];
put_bytes_to_800C2F3C();

A0 = 40;
A1 = w[80061c24];
put_bytes_to_800C2F3C();

A0 = 42;
A1 = w[80061c28];
put_bytes_to_800C2F3C();
////////////////////////////////



////////////////////////////////
// funca268c()
V0 = w[80059a38];
[V0 + 231a] = h(w[8004e9f0]);
[V0 + 231c] = h(hu[V0 + 1938] << 9);
[V0 + 2320] = h(hu[V0 + 1932]);
[V0 + 2322] = h(w[8004e9c8]);

A0 = 44;
A1 = hu[80058ab8];
put_bytes_to_800C2F3C();

A0 = 46;
A1 = bu[80058b6c];
put_bytes_to_800C2F3C();

func96a20();
A0 = 6; // direction of pc entity during spawn.
A1 = V0;
put_bytes_to_800C2F3C();

func99ae8();
A0 = 8; // direction of camera.
A1 = V0;
put_bytes_to_800C2F3C();

A0 = 24;
A1 = h[800aeed0];
put_bytes_to_800C2F3C();

A0 = 3c;
A1 = w[8004e9f0]; // field id to load
put_bytes_to_800C2F3C();

funca2644();

A1 = 0;
V1 = w[80059a38];
loopa274c:	; 800A274C
    [V1 + 1930 + A1 * 2] = h(hu[800c2f3c + A1 * 2]);
    A1 = A1 + 1;
    V0 = A1 < 200;
800A2760	bne    v0, zero, loopa274c [$800a274c]
////////////////////////////////



////////////////////////////////
// funca2778
800A2778	addiu  sp, sp, $ffe0 (=-$20)
V1 = bu[800af79c];
V0 = 0001;
[SP + 0018] = w(RA);
[SP + 0014] = w(S1);
800A2790	beq    v1, v0, La29ec [$800a29ec]
[SP + 0010] = w(S0);
S0 = 0;
V0 = hu[800af140];
V1 = hu[800af370];
A0 = 80061c20;
V0 = V0 | V1;
[800af140] = h(V0);

loopa27c0:	; 800A27C0
V0 = w[80059a38];
V1 = w[A0 + 0000];
V0 = V0 + S0;
S0 = S0 + 0001;
[V0 + 1d34] = b(V1);
V0 = S0 < 0003;
800A27DC	bne    v0, zero, loopa27c0 [$800a27c0]
A0 = A0 + 0004;
800A27E4	jal    funca268c [$800a268c]
S0 = 0;
V0 = w[8004e9bc];
S1 = 0001;
[8004e998] = w(0);
V0 = V0 + 0001;
[8004e9bc] = w(V0);

loopa280c:	; 800A280C
V0 = w[80059a38];
800A2814	nop
V0 = V0 + S0;
V0 = bu[V0 + 22b1];
800A2820	nop
800A2824	bne    v0, s1, La2834 [$800a2834]
800A2828	nop
800A282C	jal    func9f474 [$8009f474]
A0 = S0;

La2834:	; 800A2834
S0 = S0 + 0001;
V0 = S0 < 0003;
800A283C	bne    v0, zero, loopa280c [$800a280c]
800A2840	nop
V0 = w[8004e9bc];
800A284C	nop
V0 = V0 < 001f;
800A2854	bne    v0, zero, La28fc [$800a28fc]
800A2858	nop
V0 = w[8004e9cc];
[8004e9bc] = w(0);
V0 = V0 & 0080;
800A2870	bne    v0, zero, La2900 [$800a2900]
A0 = 000c;
800A2878	jal    get_bytes_from_800C2F3C [$800a25a8]
A0 = 000a;
A1 = V0 & 00ff;
V0 = V0 >> 08;
V1 = w[8004e9cc];
800A2890	nop
V1 = V1 & 0004;
800A2898	bne    v1, zero, La28c8 [$800a28c8]
A2 = V0 & 00ff;
V0 = ff3b;
800A28A4	beq    a1, v0, La28e8 [$800a28e8]
800A28A8	nop
A1 = A1 + 0001;
V0 = A1 < 003d;
800A28B4	bne    v0, zero, La28e8 [$800a28e8]
800A28B8	nop
A1 = 0;
800A28C0	j      La28e8 [$800a28e8]
A2 = A2 + 0001;

La28c8:	; 800A28C8
800A28C8	bne    a1, zero, La28e4 [$800a28e4]
800A28CC	nop
800A28D0	beq    a2, zero, La28e8 [$800a28e8]
800A28D4	nop
A1 = 003b;
800A28DC	j      La28e8 [$800a28e8]
800A28E0	addiu  a2, a2, $ffff (=-$1)

La28e4:	; 800A28E4
800A28E4	addiu  a1, a1, $ffff (=-$1)

La28e8:	; 800A28E8
A0 = 000a;
V0 = A2 << 08;
A1 = A1 & 00ff;
800A28F4	jal    put_bytes_to_800C2F3C [$800a2604]
A1 = V0 | A1;

La28fc:	; 800A28FC
A0 = 000c;

La2900:	; 800A2900
A1 = bu[80058abc];
V0 = bu[80058ab4];
A1 = A1 << 08;
800A2914	jal    put_bytes_to_800C2F3C [$800a2604]
A1 = V0 | A1;
A1 = bu[80058b20];
800A2924	jal    put_bytes_to_800C2F3C [$800a2604]
A0 = 000e;
V1 = w[800b1740];
800A2934	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V0 = w[V0 + 004c];
800A295C	nop
A1 = h[V0 + 0022];
800A2964	jal    put_bytes_to_800C2F3C [$800a2604]
A0 = 001e;
V1 = w[800b1740];
800A2974	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V0 = w[V0 + 004c];
800A299C	nop
A1 = h[V0 + 002a];
800A29A4	jal    put_bytes_to_800C2F3C [$800a2604]
A0 = 0020;
V1 = w[800b1740];
800A29B4	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V0 = w[V0 + 004c];
800A29DC	nop
A1 = h[V0 + 0026];
800A29E4	jal    put_bytes_to_800C2F3C [$800a2604]
A0 = 0022;

La29ec:	; 800A29EC
RA = w[SP + 0018];
S1 = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0020;
800A29FC	jr     ra 
800A2A00	nop
////////////////////////////////



////////////////////////////////
// funca2a04
800A2A04	addiu  sp, sp, $ffd0 (=-$30)
A3 = 800af550;
A0 = 80059b74;
V0 = A0 + 0004;
A2 = V0;
V0 = A2 | A3;
[SP + 0028] = w(RA);
[SP + 0024] = w(S1);
[SP + 0020] = w(S0);
V1 = bu[A0 + 0000];
V0 = V0 & 0003;
[800af124] = w(A0);
[800af124] = w(A2);
[800aefe0] = w(V1);
800A2A50	beq    v0, zero, La2aac [$800a2aac]
T0 = A0 + 0034;

loopa2a58:	; 800A2A58
800A2A58	lwl    v0, $0003(a2)
800A2A5C	lwr    v0, $0000(a2)
800A2A60	lwl    v1, $0007(a2)
800A2A64	lwr    v1, $0004(a2)
800A2A68	lwl    a0, $000b(a2)
800A2A6C	lwr    a0, $0008(a2)
800A2A70	lwl    a1, $000f(a2)
800A2A74	lwr    a1, $000c(a2)
800A2A78	swl    v0, $0003(a3)
800A2A7C	swr    v0, $0000(a3)
800A2A80	swl    v1, $0007(a3)
800A2A84	swr    v1, $0004(a3)
800A2A88	swl    a0, $000b(a3)
800A2A8C	swr    a0, $0008(a3)
800A2A90	swl    a1, $000f(a3)
800A2A94	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2A9C	bne    a2, t0, loopa2a58 [$800a2a58]
A3 = A3 + 0010;
800A2AA4	j      La2ad8 [$800a2ad8]
800A2AA8	nop

La2aac:	; 800A2AAC
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2AD0	bne    a2, t0, La2aac [$800a2aac]
A3 = A3 + 0010;

La2ad8:	; 800A2AD8
800A2AD8	lwl    v0, $0003(a2)
800A2ADC	lwr    v0, $0000(a2)
800A2AE0	lwl    v1, $0007(a2)
800A2AE4	lwr    v1, $0004(a2)
800A2AE8	swl    v0, $0003(a3)
800A2AEC	swr    v0, $0000(a3)
800A2AF0	swl    v1, $0007(a3)
800A2AF4	swr    v1, $0004(a3)
V1 = w[800af124];
A3 = 800aef28;
V0 = V1 + 0038;
A2 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
[800af124] = w(A2);
800A2B20	beq    v0, zero, La2b7c [$800a2b7c]
T0 = V1 + 00a8;

loopa2b28:	; 800A2B28
800A2B28	lwl    v0, $0003(a2)
800A2B2C	lwr    v0, $0000(a2)
800A2B30	lwl    v1, $0007(a2)
800A2B34	lwr    v1, $0004(a2)
800A2B38	lwl    a0, $000b(a2)
800A2B3C	lwr    a0, $0008(a2)
800A2B40	lwl    a1, $000f(a2)
800A2B44	lwr    a1, $000c(a2)
800A2B48	swl    v0, $0003(a3)
800A2B4C	swr    v0, $0000(a3)
800A2B50	swl    v1, $0007(a3)
800A2B54	swr    v1, $0004(a3)
800A2B58	swl    a0, $000b(a3)
800A2B5C	swr    a0, $0008(a3)
800A2B60	swl    a1, $000f(a3)
800A2B64	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2B6C	bne    a2, t0, loopa2b28 [$800a2b28]
A3 = A3 + 0010;
800A2B74	j      La2ba8 [$800a2ba8]
800A2B78	nop

La2b7c:	; 800A2B7C
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2BA0	bne    a2, t0, La2b7c [$800a2b7c]
A3 = A3 + 0010;

La2ba8:	; 800A2BA8
800A2BA8	lwl    v0, $0003(a2)
800A2BAC	lwr    v0, $0000(a2)
800A2BB0	nop
800A2BB4	swl    v0, $0003(a3)
800A2BB8	swr    v0, $0000(a3)
V1 = w[800af124];
A3 = w[800aeff4];
V0 = V1 + 0074;
A2 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
[800af124] = w(A2);
800A2BE4	beq    v0, zero, La2c40 [$800a2c40]
T0 = V1 + 0474;

loopa2bec:	; 800A2BEC
800A2BEC	lwl    v0, $0003(a2)
800A2BF0	lwr    v0, $0000(a2)
800A2BF4	lwl    v1, $0007(a2)
800A2BF8	lwr    v1, $0004(a2)
800A2BFC	lwl    a0, $000b(a2)
800A2C00	lwr    a0, $0008(a2)
800A2C04	lwl    a1, $000f(a2)
800A2C08	lwr    a1, $000c(a2)
800A2C0C	swl    v0, $0003(a3)
800A2C10	swr    v0, $0000(a3)
800A2C14	swl    v1, $0007(a3)
800A2C18	swr    v1, $0004(a3)
800A2C1C	swl    a0, $000b(a3)
800A2C20	swr    a0, $0008(a3)
800A2C24	swl    a1, $000f(a3)
800A2C28	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2C30	bne    a2, t0, loopa2bec [$800a2bec]
A3 = A3 + 0010;
800A2C38	j      La2c6c [$800a2c6c]
800A2C3C	nop

La2c40:	; 800A2C40
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2C64	bne    a2, t0, La2c40 [$800a2c40]
A3 = A3 + 0010;

La2c6c:	; 800A2C6C
V1 = w[800af124];
A3 = 800b154c;
V0 = V1 + 0400;
A2 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
[800af124] = w(A2);
800A2C94	beq    v0, zero, La2cf0 [$800a2cf0]
T0 = V1 + 06e0;

loopa2c9c:	; 800A2C9C
800A2C9C	lwl    v0, $0003(a2)
800A2CA0	lwr    v0, $0000(a2)
800A2CA4	lwl    v1, $0007(a2)
800A2CA8	lwr    v1, $0004(a2)
800A2CAC	lwl    a0, $000b(a2)
800A2CB0	lwr    a0, $0008(a2)
800A2CB4	lwl    a1, $000f(a2)
800A2CB8	lwr    a1, $000c(a2)
800A2CBC	swl    v0, $0003(a3)
800A2CC0	swr    v0, $0000(a3)
800A2CC4	swl    v1, $0007(a3)
800A2CC8	swr    v1, $0004(a3)
800A2CCC	swl    a0, $000b(a3)
800A2CD0	swr    a0, $0008(a3)
800A2CD4	swl    a1, $000f(a3)
800A2CD8	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2CE0	bne    a2, t0, loopa2c9c [$800a2c9c]
A3 = A3 + 0010;
800A2CE8	j      La2d1c [$800a2d1c]
800A2CEC	nop

La2cf0:	; 800A2CF0
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2D14	bne    a2, t0, La2cf0 [$800a2cf0]
A3 = A3 + 0010;

La2d1c:	; 800A2D1C
800A2D1C	lwl    v0, $0003(a2)
800A2D20	lwr    v0, $0000(a2)
800A2D24	nop
800A2D28	swl    v0, $0003(a3)
800A2D2C	swr    v0, $0000(a3)
V1 = w[800af124];
A3 = 800aed54;
V0 = V1 + 02e4;
A2 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
[800af124] = w(A2);
800A2D58	beq    v0, zero, La2db4 [$800a2db4]
T0 = V1 + 04a4;

loopa2d60:	; 800A2D60
800A2D60	lwl    v0, $0003(a2)
800A2D64	lwr    v0, $0000(a2)
800A2D68	lwl    v1, $0007(a2)
800A2D6C	lwr    v1, $0004(a2)
800A2D70	lwl    a0, $000b(a2)
800A2D74	lwr    a0, $0008(a2)
800A2D78	lwl    a1, $000f(a2)
800A2D7C	lwr    a1, $000c(a2)
800A2D80	swl    v0, $0003(a3)
800A2D84	swr    v0, $0000(a3)
800A2D88	swl    v1, $0007(a3)
800A2D8C	swr    v1, $0004(a3)
800A2D90	swl    a0, $000b(a3)
800A2D94	swr    a0, $0008(a3)
800A2D98	swl    a1, $000f(a3)
800A2D9C	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2DA4	bne    a2, t0, loopa2d60 [$800a2d60]
A3 = A3 + 0010;
800A2DAC	j      La2de0 [$800a2de0]
800A2DB0	nop

La2db4:	; 800A2DB4
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2DD8	bne    a2, t0, La2db4 [$800a2db4]
A3 = A3 + 0010;

La2de0:	; 800A2DE0
800A2DE0	lwl    v0, $0003(a2)
800A2DE4	lwr    v0, $0000(a2)
800A2DE8	lwl    v1, $0007(a2)
800A2DEC	lwr    v1, $0004(a2)
800A2DF0	swl    v0, $0003(a3)
800A2DF4	swr    v0, $0000(a3)
800A2DF8	swl    v1, $0007(a3)
800A2DFC	swr    v1, $0004(a3)
V0 = w[800af124];
V1 = w[800ad0d4];
V0 = V0 + 01c8;
[800af124] = w(V0);
800A2E1C	blez   v1, La314c [$800a314c]
S1 = 0;
S0 = 0;

La2e28:	; 800A2E28
V0 = w[800aefe4];
V1 = w[800af124];
V0 = V0 + S0;
800A2E3C	lwl    a0, $0003(v1)
800A2E40	lwr    a0, $0000(v1)
800A2E44	lwl    a1, $0007(v1)
800A2E48	lwr    a1, $0004(v1)
800A2E4C	swl    a0, $0053(v0)
800A2E50	swr    a0, $0050(v0)
800A2E54	swl    a1, $0057(v0)
800A2E58	swr    a1, $0054(v0)
V1 = w[800af124];
800A2E64	nop
V0 = V1 + 0008;
[800af124] = w(V0);
800A2E74	lwl    v0, $000b(v1)
800A2E78	lwr    v0, $0008(v1)
800A2E7C	nop
800A2E80	swl    v0, $0013(sp)
800A2E84	swr    v0, $0010(sp)
V0 = w[800aefe4];
V1 = w[SP + 0010];
A0 = w[800af124];
V0 = S0 + V0;
[V0 + 0058] = h(V1);
V0 = w[800aefe4];
V1 = A0 + 0034;
V0 = S0 + V0;
V0 = w[V0 + 004c];
A2 = V1;
[800af124] = w(A2);
A3 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
T1 = w[A3 + 0118];
800A2ED4	beq    v0, zero, La2f30 [$800a2f30]
T0 = A0 + 0164;

loopa2edc:	; 800A2EDC
800A2EDC	lwl    v0, $0003(a2)
800A2EE0	lwr    v0, $0000(a2)
800A2EE4	lwl    v1, $0007(a2)
800A2EE8	lwr    v1, $0004(a2)
800A2EEC	lwl    a0, $000b(a2)
800A2EF0	lwr    a0, $0008(a2)
800A2EF4	lwl    a1, $000f(a2)
800A2EF8	lwr    a1, $000c(a2)
800A2EFC	swl    v0, $0003(a3)
800A2F00	swr    v0, $0000(a3)
800A2F04	swl    v1, $0007(a3)
800A2F08	swr    v1, $0004(a3)
800A2F0C	swl    a0, $000b(a3)
800A2F10	swr    a0, $0008(a3)
800A2F14	swl    a1, $000f(a3)
800A2F18	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A2F20	bne    a2, t0, loopa2edc [$800a2edc]
A3 = A3 + 0010;
800A2F28	j      La2f5c [$800a2f5c]
800A2F2C	nop

La2f30:	; 800A2F30
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A2F54	bne    a2, t0, La2f30 [$800a2f30]
A3 = A3 + 0010;

La2f5c:	; 800A2F5C
800A2F5C	lwl    v0, $0003(a2)
800A2F60	lwr    v0, $0000(a2)
800A2F64	lwl    v1, $0007(a2)
800A2F68	lwr    v1, $0004(a2)
800A2F6C	swl    v0, $0003(a3)
800A2F70	swr    v0, $0000(a3)
800A2F74	swl    v1, $0007(a3)
800A2F78	swr    v1, $0004(a3)
V0 = w[800aefe4];
800A2F84	nop
V0 = S0 + V0;
V0 = w[V0 + 004c];
800A2F90	nop
[V0 + 0118] = w(T1);
V0 = w[800aefe4];
800A2FA0	nop
V0 = S0 + V0;
V1 = w[V0 + 004c];
V0 = w[800af124];
V1 = w[V1 + 0134];
V0 = V0 + 0138;
[800af124] = w(V0);
V1 = V1 & 0080;
800A2FC8	beq    v1, zero, La3064 [$800a3064]
A0 = 000c;
800A2FD0	jal    $800319ec
A1 = 0;
V1 = w[800aefe4];
800A2FE0	nop
V1 = S0 + V1;
V1 = w[V1 + 004c];
800A2FEC	nop
[V1 + 0110] = w(V0);
V0 = w[800aefe4];
800A2FFC	nop
V0 = S0 + V0;
V0 = w[V0 + 004c];
800A3008	nop
V1 = w[V0 + 0110];
V0 = w[800af124];
800A3018	nop
800A301C	lwl    a0, $0003(v0)
800A3020	lwr    a0, $0000(v0)
800A3024	lwl    a1, $0007(v0)
800A3028	lwr    a1, $0004(v0)
800A302C	lwl    a2, $000b(v0)
800A3030	lwr    a2, $0008(v0)
800A3034	swl    a0, $0003(v1)
800A3038	swr    a0, $0000(v1)
800A303C	swl    a1, $0007(v1)
800A3040	swr    a1, $0004(v1)
800A3044	swl    a2, $000b(v1)
800A3048	swr    a2, $0008(v1)
V0 = w[800af124];
800A3054	nop
V0 = V0 + 000c;
[800af124] = w(V0);

La3064:	; 800A3064
V0 = w[800aefe4];
800A306C	nop
V0 = S0 + V0;
V0 = w[V0 + 004c];
800A3078	nop
V0 = w[V0 + 012c];
800A3080	nop
V0 = V0 & 1000;
800A3088	beq    v0, zero, La3134 [$800a3134]
A0 = 0010;
800A3090	jal    $800319ec
A1 = 0;
V1 = w[800aefe4];
800A30A0	nop
V1 = S0 + V1;
V1 = w[V1 + 004c];
800A30AC	nop
[V1 + 0114] = w(V0);
V0 = w[800aefe4];
800A30BC	nop
V0 = S0 + V0;
V0 = w[V0 + 004c];
800A30C8	nop
V1 = w[V0 + 0114];
V0 = w[800af124];
800A30D8	nop
800A30DC	lwl    a0, $0003(v0)
800A30E0	lwr    a0, $0000(v0)
800A30E4	lwl    a1, $0007(v0)
800A30E8	lwr    a1, $0004(v0)
800A30EC	lwl    a2, $000b(v0)
800A30F0	lwr    a2, $0008(v0)
800A30F4	lwl    a3, $000f(v0)
800A30F8	lwr    a3, $000c(v0)
800A30FC	swl    a0, $0003(v1)
800A3100	swr    a0, $0000(v1)
800A3104	swl    a1, $0007(v1)
800A3108	swr    a1, $0004(v1)
800A310C	swl    a2, $000b(v1)
800A3110	swr    a2, $0008(v1)
800A3114	swl    a3, $000f(v1)
800A3118	swr    a3, $000c(v1)
V0 = w[800af124];
800A3124	nop
V0 = V0 + 0010;
[800af124] = w(V0);

La3134:	; 800A3134
V0 = w[800ad0d4];
S1 = S1 + 0001;
V0 = S1 < V0;
800A3144	bne    v0, zero, La2e28 [$800a2e28]
S0 = S0 + 005c;

La314c:	; 800A314C
A2 = w[800af124];
A3 = 800c2f3c;
V0 = A2 | A3;
V0 = V0 & 0003;
800A3164	beq    v0, zero, La31c0 [$800a31c0]
T0 = A2 + 0800;

loopa316c:	; 800A316C
800A316C	lwl    v0, $0003(a2)
800A3170	lwr    v0, $0000(a2)
800A3174	lwl    v1, $0007(a2)
800A3178	lwr    v1, $0004(a2)
800A317C	lwl    a0, $000b(a2)
800A3180	lwr    a0, $0008(a2)
800A3184	lwl    a1, $000f(a2)
800A3188	lwr    a1, $000c(a2)
800A318C	swl    v0, $0003(a3)
800A3190	swr    v0, $0000(a3)
800A3194	swl    v1, $0007(a3)
800A3198	swr    v1, $0004(a3)
800A319C	swl    a0, $000b(a3)
800A31A0	swr    a0, $0008(a3)
800A31A4	swl    a1, $000f(a3)
800A31A8	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A31B0	bne    a2, t0, loopa316c [$800a316c]
A3 = A3 + 0010;
800A31B8	j      La31ec [$800a31ec]
800A31BC	nop

La31c0:	; 800A31C0
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A31E4	bne    a2, t0, La31c0 [$800a31c0]
A3 = A3 + 0010;

La31ec:	; 800A31EC
V0 = w[800af124];
800A31F4	nop
V0 = V0 + 0800;
[800af124] = w(V0);
RA = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0030;
800A3214	jr     ra 
800A3218	nop
////////////////////////////////



////////////////////////////////
// funca321c
800A321C	addiu  sp, sp, $ffd0 (=-$30)
A0 = 800aefe0;
800A3228	addiu  a3, a0, $ff48 (=-$b8)
A1 = 80059b74;
V0 = A1 + 003c;
A2 = V0;
V0 = A2 | A3;
[SP + 0028] = w(RA);
[SP + 0024] = w(S1);
[SP + 0020] = w(S0);
V1 = bu[A1 + 0000];
V0 = V0 & 0003;
[800af124] = w(A1);
[800af124] = w(A2);
800A3264	beq    v0, zero, La32c4 [$800a32c4]
[A0 + 0000] = w(V1);
T0 = A1 + 00ac;

loopa3270:	; 800A3270
800A3270	lwl    v0, $0003(a2)
800A3274	lwr    v0, $0000(a2)
800A3278	lwl    v1, $0007(a2)
800A327C	lwr    v1, $0004(a2)
800A3280	lwl    a0, $000b(a2)
800A3284	lwr    a0, $0008(a2)
800A3288	lwl    a1, $000f(a2)
800A328C	lwr    a1, $000c(a2)
800A3290	swl    v0, $0003(a3)
800A3294	swr    v0, $0000(a3)
800A3298	swl    v1, $0007(a3)
800A329C	swr    v1, $0004(a3)
800A32A0	swl    a0, $000b(a3)
800A32A4	swr    a0, $0008(a3)
800A32A8	swl    a1, $000f(a3)
800A32AC	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A32B4	bne    a2, t0, loopa3270 [$800a3270]
A3 = A3 + 0010;
800A32BC	j      La32f4 [$800a32f4]
800A32C0	nop

La32c4:	; 800A32C4
T0 = A1 + 00ac;

loopa32c8:	; 800A32C8
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A32EC	bne    a2, t0, loopa32c8 [$800a32c8]
A3 = A3 + 0010;

La32f4:	; 800A32F4
800A32F4	lwl    v0, $0003(a2)
800A32F8	lwr    v0, $0000(a2)
800A32FC	nop
800A3300	swl    v0, $0003(a3)
800A3304	swr    v0, $0000(a3)
V0 = w[800af124];
V1 = w[800ad0d4];
V0 = V0 + 0920;
[800af124] = w(V0);
800A3324	blez   v1, La3444 [$800a3444]
S1 = 0;
S0 = 0;

loopa3330:	; 800A3330
V0 = w[800aefe4];
A1 = w[800af124];
V0 = S0 + V0;
A0 = w[V0 + 004c];
V0 = A1 + 000c;
[800af124] = w(V0);
V1 = h[A0 + 0124];
800A3358	addiu  v0, zero, $ffff (=-$1)
800A335C	beq    v1, v0, La3378 [$800a3378]
V0 = 00ff;
V1 = h[A0 + 00ea];
800A3368	nop
800A336C	beq    v1, v0, La3378 [$800a3378]
A0 = V1;
[A1 + 0020] = h(A0);

La3378:	; 800A3378
V0 = w[800aefe4];
800A3380	nop
A0 = S0 + V0;
V0 = w[A0 + 004c];
800A338C	nop
V0 = w[V0 + 0004];
800A3394	lui    v1, $0100
V0 = V0 & V1;
800A339C	bne    v0, zero, La33b8 [$800a33b8]
800A33A0	nop
A0 = w[A0 + 0004];
A1 = w[800af124];
800A33B0	jal    $80021bb0
800A33B4	nop

La33b8:	; 800A33B8
V0 = w[800aefe4];
800A33C0	nop
A1 = S0 + V0;
V0 = w[A1 + 004c];
A0 = w[800af124];
V1 = w[V0 + 0134];
V0 = A0 + 0168;
[800af124] = w(V0);
V1 = V1 & 0080;
800A33E8	beq    v1, zero, La33f8 [$800a33f8]
V0 = A0 + 0174;
[800af124] = w(V0);

La33f8:	; 800A33F8
V0 = w[A1 + 004c];
800A33FC	nop
V0 = w[V0 + 012c];
800A3404	nop
V0 = V0 & 1000;
800A340C	beq    v0, zero, La342c [$800a342c]
800A3410	nop
V0 = w[800af124];
800A341C	nop
V0 = V0 + 0010;
[800af124] = w(V0);

La342c:	; 800A342C
V0 = w[800ad0d4];
S1 = S1 + 0001;
V0 = S1 < V0;
800A343C	bne    v0, zero, loopa3330 [$800a3330]
S0 = S0 + 005c;

La3444:	; 800A3444
RA = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0030;
800A3454	jr     ra 
800A3458	nop
////////////////////////////////



////////////////////////////////
// funca345c
800A345C	addiu  sp, sp, $ffd0 (=-$30)
V1 = 80059b74;
V0 = V1 + 0004;
A3 = V0;
A2 = 800af550;
V0 = A2 | A3;
A0 = w[800aefe0];
V0 = V0 & 0003;
[SP + 0028] = w(RA);
[SP + 0024] = w(S1);
[SP + 0020] = w(S0);
[800af124] = w(V1);
[800af124] = w(A3);
800A34A4	beq    v0, zero, La3504 [$800a3504]
[V1 + 0000] = b(A0);
T0 = A2 + 0030;

loopa34b0:	; 800A34B0
800A34B0	lwl    v0, $0003(a2)
800A34B4	lwr    v0, $0000(a2)
800A34B8	lwl    v1, $0007(a2)
800A34BC	lwr    v1, $0004(a2)
800A34C0	lwl    a0, $000b(a2)
800A34C4	lwr    a0, $0008(a2)
800A34C8	lwl    a1, $000f(a2)
800A34CC	lwr    a1, $000c(a2)
800A34D0	swl    v0, $0003(a3)
800A34D4	swr    v0, $0000(a3)
800A34D8	swl    v1, $0007(a3)
800A34DC	swr    v1, $0004(a3)
800A34E0	swl    a0, $000b(a3)
800A34E4	swr    a0, $0008(a3)
800A34E8	swl    a1, $000f(a3)
800A34EC	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A34F4	bne    a2, t0, loopa34b0 [$800a34b0]
A3 = A3 + 0010;
800A34FC	j      La3534 [$800a3534]
800A3500	nop

La3504:	; 800A3504
T0 = A2 + 0030;

loopa3508:	; 800A3508
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A352C	bne    a2, t0, loopa3508 [$800a3508]
A3 = A3 + 0010;

La3534:	; 800A3534
800A3534	lwl    v0, $0003(a2)
800A3538	lwr    v0, $0000(a2)
800A353C	lwl    v1, $0007(a2)
800A3540	lwr    v1, $0004(a2)
800A3544	swl    v0, $0003(a3)
800A3548	swr    v0, $0000(a3)
800A354C	swl    v1, $0007(a3)
800A3550	swr    v1, $0004(a3)
V0 = w[800af124];
A2 = 800aef28;
V0 = V0 + 0038;
A3 = V0;
V0 = A3 | A2;
V0 = V0 & 0003;
[800af124] = w(A3);
800A357C	beq    v0, zero, La35d8 [$800a35d8]
T0 = A2 + 0070;

loopa3584:	; 800A3584
800A3584	lwl    v0, $0003(a2)
800A3588	lwr    v0, $0000(a2)
800A358C	lwl    v1, $0007(a2)
800A3590	lwr    v1, $0004(a2)
800A3594	lwl    a0, $000b(a2)
800A3598	lwr    a0, $0008(a2)
800A359C	lwl    a1, $000f(a2)
800A35A0	lwr    a1, $000c(a2)
800A35A4	swl    v0, $0003(a3)
800A35A8	swr    v0, $0000(a3)
800A35AC	swl    v1, $0007(a3)
800A35B0	swr    v1, $0004(a3)
800A35B4	swl    a0, $000b(a3)
800A35B8	swr    a0, $0008(a3)
800A35BC	swl    a1, $000f(a3)
800A35C0	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A35C8	bne    a2, t0, loopa3584 [$800a3584]
A3 = A3 + 0010;
800A35D0	j      La3604 [$800a3604]
800A35D4	nop

La35d8:	; 800A35D8
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A35FC	bne    a2, t0, La35d8 [$800a35d8]
A3 = A3 + 0010;

La3604:	; 800A3604
800A3604	lwl    v0, $0003(a2)
800A3608	lwr    v0, $0000(a2)
800A360C	nop
800A3610	swl    v0, $0003(a3)
800A3614	swr    v0, $0000(a3)
V0 = w[800af124];
A2 = w[800aeff4];
V0 = V0 + 0074;
A3 = V0;
V0 = A2 | A3;
V0 = V0 & 0003;
[800af124] = w(A3);
800A3640	beq    v0, zero, La369c [$800a369c]
T0 = A2 + 0400;

loopa3648:	; 800A3648
800A3648	lwl    v0, $0003(a2)
800A364C	lwr    v0, $0000(a2)
800A3650	lwl    v1, $0007(a2)
800A3654	lwr    v1, $0004(a2)
800A3658	lwl    a0, $000b(a2)
800A365C	lwr    a0, $0008(a2)
800A3660	lwl    a1, $000f(a2)
800A3664	lwr    a1, $000c(a2)
800A3668	swl    v0, $0003(a3)
800A366C	swr    v0, $0000(a3)
800A3670	swl    v1, $0007(a3)
800A3674	swr    v1, $0004(a3)
800A3678	swl    a0, $000b(a3)
800A367C	swr    a0, $0008(a3)
800A3680	swl    a1, $000f(a3)
800A3684	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A368C	bne    a2, t0, loopa3648 [$800a3648]
A3 = A3 + 0010;
800A3694	j      La36c8 [$800a36c8]
800A3698	nop

La369c:	; 800A369C
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A36C0	bne    a2, t0, La369c [$800a369c]
A3 = A3 + 0010;

La36c8:	; 800A36C8
V0 = w[800af124];
A2 = 800b154c;
V0 = V0 + 0400;
A3 = V0;
V0 = A3 | A2;
V0 = V0 & 0003;
[800af124] = w(A3);
800A36F0	beq    v0, zero, La374c [$800a374c]
T0 = A2 + 02e0;

loopa36f8:	; 800A36F8
800A36F8	lwl    v0, $0003(a2)
800A36FC	lwr    v0, $0000(a2)
800A3700	lwl    v1, $0007(a2)
800A3704	lwr    v1, $0004(a2)
800A3708	lwl    a0, $000b(a2)
800A370C	lwr    a0, $0008(a2)
800A3710	lwl    a1, $000f(a2)
800A3714	lwr    a1, $000c(a2)
800A3718	swl    v0, $0003(a3)
800A371C	swr    v0, $0000(a3)
800A3720	swl    v1, $0007(a3)
800A3724	swr    v1, $0004(a3)
800A3728	swl    a0, $000b(a3)
800A372C	swr    a0, $0008(a3)
800A3730	swl    a1, $000f(a3)
800A3734	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A373C	bne    a2, t0, loopa36f8 [$800a36f8]
A3 = A3 + 0010;
800A3744	j      La3778 [$800a3778]
800A3748	nop

La374c:	; 800A374C
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A3770	bne    a2, t0, La374c [$800a374c]
A3 = A3 + 0010;

La3778:	; 800A3778
800A3778	lwl    v0, $0003(a2)
800A377C	lwr    v0, $0000(a2)
800A3780	nop
800A3784	swl    v0, $0003(a3)
800A3788	swr    v0, $0000(a3)
V0 = w[800af124];
A2 = 800aed54;
V0 = V0 + 02e4;
A3 = V0;
V0 = A3 | A2;
V0 = V0 & 0003;
[800af124] = w(A3);
800A37B4	beq    v0, zero, La3810 [$800a3810]
T0 = A2 + 01c0;

loopa37bc:	; 800A37BC
800A37BC	lwl    v0, $0003(a2)
800A37C0	lwr    v0, $0000(a2)
800A37C4	lwl    v1, $0007(a2)
800A37C8	lwr    v1, $0004(a2)
800A37CC	lwl    a0, $000b(a2)
800A37D0	lwr    a0, $0008(a2)
800A37D4	lwl    a1, $000f(a2)
800A37D8	lwr    a1, $000c(a2)
800A37DC	swl    v0, $0003(a3)
800A37E0	swr    v0, $0000(a3)
800A37E4	swl    v1, $0007(a3)
800A37E8	swr    v1, $0004(a3)
800A37EC	swl    a0, $000b(a3)
800A37F0	swr    a0, $0008(a3)
800A37F4	swl    a1, $000f(a3)
800A37F8	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A3800	bne    a2, t0, loopa37bc [$800a37bc]
A3 = A3 + 0010;
800A3808	j      La383c [$800a383c]
800A380C	nop

La3810:	; 800A3810
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A3834	bne    a2, t0, La3810 [$800a3810]
A3 = A3 + 0010;

La383c:	; 800A383C
800A383C	lwl    v0, $0003(a2)
800A3840	lwr    v0, $0000(a2)
800A3844	lwl    v1, $0007(a2)
800A3848	lwr    v1, $0004(a2)
800A384C	swl    v0, $0003(a3)
800A3850	swr    v0, $0000(a3)
800A3854	swl    v1, $0007(a3)
800A3858	swr    v1, $0004(a3)
V0 = w[800af124];
V1 = w[800ad0d4];
V0 = V0 + 01c8;
[800af124] = w(V0);
800A3878	blez   v1, La3b2c [$800a3b2c]
S1 = 0;
S0 = 0;

La3884:	; 800A3884
V0 = w[800aefe4];
V1 = w[800af124];
V0 = V0 + S0;
800A3898	lwl    a0, $0053(v0)
800A389C	lwr    a0, $0050(v0)
800A38A0	lwl    a1, $0057(v0)
800A38A4	lwr    a1, $0054(v0)
800A38A8	swl    a0, $0003(v1)
800A38AC	swr    a0, $0000(v1)
800A38B0	swl    a1, $0007(v1)
800A38B4	swr    a1, $0004(v1)
V0 = w[800aefe4];
A0 = w[800af124];
V0 = S0 + V0;
V1 = hu[V0 + 0058];
V0 = A0 + 0008;
[800af124] = w(V0);
[SP + 0010] = w(V1);
800A38E0	lwl    v0, $0013(sp)
800A38E4	lwr    v0, $0010(sp)
800A38E8	nop
800A38EC	swl    v0, $000b(a0)
800A38F0	swr    v0, $0008(a0)
V0 = w[800aefe4];
A1 = w[800af124];
V0 = S0 + V0;
A0 = w[V0 + 0004];
A1 = A1 + 0004;
[800af124] = w(A1);
800A3918	jal    $80021d1c
800A391C	nop
V0 = w[800aefe4];
V1 = w[800af124];
V0 = S0 + V0;
V1 = V1 + 0030;
A2 = w[V0 + 004c];
A3 = V1;
[800af124] = w(A3);
V0 = A2 | A3;
V0 = V0 & 0003;
800A3950	beq    v0, zero, La39ac [$800a39ac]
T0 = A2 + 0130;

loopa3958:	; 800A3958
800A3958	lwl    v0, $0003(a2)
800A395C	lwr    v0, $0000(a2)
800A3960	lwl    v1, $0007(a2)
800A3964	lwr    v1, $0004(a2)
800A3968	lwl    a0, $000b(a2)
800A396C	lwr    a0, $0008(a2)
800A3970	lwl    a1, $000f(a2)
800A3974	lwr    a1, $000c(a2)
800A3978	swl    v0, $0003(a3)
800A397C	swr    v0, $0000(a3)
800A3980	swl    v1, $0007(a3)
800A3984	swr    v1, $0004(a3)
800A3988	swl    a0, $000b(a3)
800A398C	swr    a0, $0008(a3)
800A3990	swl    a1, $000f(a3)
800A3994	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A399C	bne    a2, t0, loopa3958 [$800a3958]
A3 = A3 + 0010;
800A39A4	j      La39d8 [$800a39d8]
800A39A8	nop

La39ac:	; 800A39AC
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A39D0	bne    a2, t0, La39ac [$800a39ac]
A3 = A3 + 0010;

La39d8:	; 800A39D8
800A39D8	lwl    v0, $0003(a2)
800A39DC	lwr    v0, $0000(a2)
800A39E0	lwl    v1, $0007(a2)
800A39E4	lwr    v1, $0004(a2)
800A39E8	swl    v0, $0003(a3)
800A39EC	swr    v0, $0000(a3)
800A39F0	swl    v1, $0007(a3)
800A39F4	swr    v1, $0004(a3)
V0 = w[800aefe4];
800A3A00	nop
V0 = S0 + V0;
A0 = w[V0 + 004c];
A3 = w[800af124];
V1 = w[A0 + 0134];
V0 = A3 + 0138;
[800af124] = w(V0);
V1 = V1 & 0080;
800A3A28	beq    v1, zero, La3a80 [$800a3a80]
800A3A2C	nop
V0 = w[A0 + 0110];
800A3A34	nop
800A3A38	lwl    v1, $0003(v0)
800A3A3C	lwr    v1, $0000(v0)
800A3A40	lwl    a0, $0007(v0)
800A3A44	lwr    a0, $0004(v0)
800A3A48	lwl    a1, $000b(v0)
800A3A4C	lwr    a1, $0008(v0)
800A3A50	swl    v1, $013b(a3)
800A3A54	swr    v1, $0138(a3)
800A3A58	swl    a0, $013f(a3)
800A3A5C	swr    a0, $013c(a3)
800A3A60	swl    a1, $0143(a3)
800A3A64	swr    a1, $0140(a3)
V0 = w[800af124];
800A3A70	nop
V0 = V0 + 000c;
[800af124] = w(V0);

La3a80:	; 800A3A80
V0 = w[800aefe4];
800A3A88	nop
V0 = S0 + V0;
A0 = w[V0 + 004c];
800A3A94	nop
V0 = w[A0 + 012c];
800A3A9C	nop
V0 = V0 & 1000;
800A3AA4	beq    v0, zero, La3b14 [$800a3b14]
800A3AA8	nop
V1 = w[800af124];
V0 = w[A0 + 0114];
800A3AB8	nop
800A3ABC	lwl    a0, $0003(v0)
800A3AC0	lwr    a0, $0000(v0)
800A3AC4	lwl    a1, $0007(v0)
800A3AC8	lwr    a1, $0004(v0)
800A3ACC	lwl    a2, $000b(v0)
800A3AD0	lwr    a2, $0008(v0)
800A3AD4	lwl    a3, $000f(v0)
800A3AD8	lwr    a3, $000c(v0)
800A3ADC	swl    a0, $0003(v1)
800A3AE0	swr    a0, $0000(v1)
800A3AE4	swl    a1, $0007(v1)
800A3AE8	swr    a1, $0004(v1)
800A3AEC	swl    a2, $000b(v1)
800A3AF0	swr    a2, $0008(v1)
800A3AF4	swl    a3, $000f(v1)
800A3AF8	swr    a3, $000c(v1)
V0 = w[800af124];
800A3B04	nop
V0 = V0 + 0010;
[800af124] = w(V0);

La3b14:	; 800A3B14
V0 = w[800ad0d4];
S1 = S1 + 0001;
V0 = S1 < V0;
800A3B24	bne    v0, zero, La3884 [$800a3884]
S0 = S0 + 005c;

La3b2c:	; 800A3B2C
A3 = w[800af124];
A2 = 800c2f3c;
V0 = A3 | A2;
V0 = V0 & 0003;
800A3B44	beq    v0, zero, La3ba0 [$800a3ba0]
T0 = A2 + 0800;

loopa3b4c:	; 800A3B4C
800A3B4C	lwl    v0, $0003(a2)
800A3B50	lwr    v0, $0000(a2)
800A3B54	lwl    v1, $0007(a2)
800A3B58	lwr    v1, $0004(a2)
800A3B5C	lwl    a0, $000b(a2)
800A3B60	lwr    a0, $0008(a2)
800A3B64	lwl    a1, $000f(a2)
800A3B68	lwr    a1, $000c(a2)
800A3B6C	swl    v0, $0003(a3)
800A3B70	swr    v0, $0000(a3)
800A3B74	swl    v1, $0007(a3)
800A3B78	swr    v1, $0004(a3)
800A3B7C	swl    a0, $000b(a3)
800A3B80	swr    a0, $0008(a3)
800A3B84	swl    a1, $000f(a3)
800A3B88	swr    a1, $000c(a3)
A2 = A2 + 0010;
800A3B90	bne    a2, t0, loopa3b4c [$800a3b4c]
A3 = A3 + 0010;
800A3B98	j      La3bcc [$800a3bcc]
800A3B9C	nop

La3ba0:	; 800A3BA0
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A3BC4	bne    a2, t0, La3ba0 [$800a3ba0]
A3 = A3 + 0010;

La3bcc:	; 800A3BCC
S1 = 80059b74;
V0 = w[800af124];
V1 = w[800c1b60];
V0 = V0 + 0800;
[800af124] = w(V0);
800A3BF0	bne    v1, zero, La3c08 [$800a3c08]
A1 = V0 - S1;
A0 = 8006f42c;
800A3C00	jal    $80037870
A2 = A1;

La3c08:	; 800A3C08
RA = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0030;
800A3C18	jr     ra 
800A3C1C	nop
////////////////////////////////



////////////////////////////////
// funca3c20()
A0 = 2c0; // dest x
A1 = 100; // dest y
funca3c44();
////////////////////////////////



////////////////////////////////
// funca3c44()
dest_x = A0;
dest_y = A1;

A0 = 200;
system_gte_set_projection_plane_distance();

[SP + 10] = h(0);
[SP + 12] = h(0);
[SP + 14] = h(140);
[SP + 16] = h(e0);

A0 = SP + 10; // src rect
A1 = dest_x;
A2 = dest_y;
system_move_image()

field_sync();
////////////////////////////////



////////////////////////////////
// funca3cac()
[800b154c] = h(0);
if( w[800acffc] != 0 )
{
    A0 = w[800b1588];
    system_memory_mark_removed_alloc();

    A0 = w[800b15bc];
    system_memory_mark_removed_alloc();

    A0 = w[800b1590];
    system_memory_mark_removed_alloc();

    A0 = w[800b1594];
    system_memory_mark_removed_alloc();

    [800acffc] = w(0);
}
////////////////////////////////
