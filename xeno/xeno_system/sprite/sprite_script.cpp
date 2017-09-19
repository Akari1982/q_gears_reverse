////////////////////////////////
// func23090()
struct_164 = A0;

if( ( w[80058810 + 28] + 1 ) != 0 )
{
    S0 = 0;
    loop230b8:	; 800230B8
        if( h[struct_164 + 9e] != 0 ) // wait
        {
            [struct_164 + 9e] = h(h[struct_164 + 9e] - 1);
            if( h[struct_164 + 9e] == 0 )
            {
                A0 = struct_164;
                func246ac(); // call script
            }
        }
        V0 = w[80058810 + 28] + 1;
        S0 = S0 + 1;
    800230F4	bne    s0, v0, loop230b8 [$800230b8]
}
////////////////////////////////



////////////////////////////////
// func246ac()
struct_164 = A0;

if( bu[80058810 + 3d] != 0 )
{
    funcc08f0(); // battle sprite animation script
    return;
}

L246e4:	; 800246E4
if( h[struct_164 + 9e] != 0 )
{
    return;
}

script_ptr = w[struct_164 + 64];

opcode = bu[script_ptr];
if( opcode >= 80 )
{
    if( opcode == 80 )
    {
        A1 = b[struct_164 + b0]; // default animation id
        if( A1 >= 0 )
        {
            A0 = struct_164;
            func243e4(); // play animation
        }
        [struct_164 + a8] = w(w[struct_164 + a8] & cfffffff);
        return;
    }
    else if( opcode == 81 )
    {
        if( b[struct_164 + af] == 3f ) // play default animation
        {
            [struct_164 + a8] = w(w[struct_164 + a8] & cfffffff);

            if( w[struct_164 + 68] != 0 )
            {
                A0 = struct_164;
                80024AB4	jalr   w[struct_164 + 68] ra
            }
            else
            {
                A1 = b[struct_164 + b0]; // default animation id
                if( A1 >= 0 )
                {
                    A0 = struct_164;
                    func243e4(); // play animation
                }
                [struct_164 + a8] = w(w[struct_164 + a8] & cfffffff);
            }
        }
        else
        {
            [struct_164 + 9e] = h(0); // wait 0

            if( w[struct_164 + 68] != 0 )
            {
                A0 = struct_164;
                80024B98	jalr   w[struct_164 + 68] ra
            }
            [struct_164 + a8] = w((w[struct_164 + a8] & cfffffff) | 10000000);
        }
        return;
    }
    else if( opcode == 82 )
    {
        if( w[struct_164 + 68] != 0 )
        {
            A0 = struct_164;
            80024B48	jalr   w[struct_164 + 68] ra
        }

        S0 = w[struct_164 + 10];

        A0 = struct_164;
        A1 = b[struct_164 + af];
        func243e4(); // play animation

        [struct_164 + 10] = w(S0);
        [struct_164 + 9e] = h(0);

        A0 = struct_164;
        func246ac(); // call this script function again

        return;
    }
    else if( opcode == 85 )
    {
        A0 = struct_164;
        func21ac4(); // pop script pos 3 bytes from stack +8e

        [struct_164 + 64] = w((w[struct_164 + 64] & ff000000) | V0);
        800249D0	j      L246e4 [$800246e4]
    }
    else if( opcode == 86 )
    {
        if( w[struct_164 + 10] >= 0 )
        {
            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
            80024CF0	j      L246e4 [$800246e4]
        }

        [struct_164 + 9e] = h(1);
        return;
    }
    else if( opcode == 87 )
    {
        if( h[struct_164 + 6] >= h[struct_164 + 84] )
        {
            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
            80024CF0	j      L246e4 [$800246e4]
        }

        [struct_164 + 9e] = h(1);
        return;
    }
    else if( opcode == 8e )
    {
        [struct_164 + 64] = w(0);
        return;
    }
    else if( opcode == 98 )
    {
        A0 = w[struct_164 + 70];
        if( A0 != 0 )
        {
            [struct_164 + 9e] = h(1);

            if( b[A0 + af] == b[struct_164 + 8d] )
            {
                if( ( w[A0 + a8] & 30000000 ) == 20000000 )
                {
                    return;
                }
            }
        }

        [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
        80024CF0	j      L246e4 [$800246e4]
    }
    else if( opcode == a7 )
    {
        [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);

        if( bu[script_ptr + 1] & 80 )
        {
            [80058ac4] = w((bu[script_ptr + 1] & 7f) + 1);
            [struct_164 + 9e] = h(h[struct_164 + 9e] + 1);
        }
        else
        {
            V1 = ((bu[script_ptr + 1] + 2) * ((w[struct_164 + ac] >> 9) & fff)) >> 8;
            if( V1 == 0 )
            {
                V1 = 1;
            }
            [struct_164 + 9e] = h(h[struct_164 + 9e] + V1);
        }
        return;
    }
    else if( opcode == be )
    {
        A3 = h[script_ptr + 1];

        frame_id = A3 & 01ff;

        wait = ((((A3 >> b) & f) + 1) * ((w[struct_164 + ac] >> 9) & fff)) >> 8;
        if( wait == 0 )
        {
            wait = 1;
        }

        if( ( w[struct_164 + 3c] & 00000003 ) != 00000001 )
        {
            [struct_164 + 34] = h(frame_id);
        }
        else
        {
            if( ( A3 & 8000 ) && ( frame_id != 0 ) )
            {
                V0 = w[struct_164 + 60] + frame_id;
                frame_id = bu[V0 - 1];
            }

            // invert offset y
            [struct_164 + ac] = w((w[struct_164 + ac] & ffffffdf) | ((A3 >> 4) & 20));

            // invert tile x and width
            V0 = (w[struct_164 + ac] >> 5) & 1;
            V1 = (w[struct_164 + ac] >> 4) & 1;
            [struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | ((V0 XOR V1) << 3));

            // invert tile y and height
            if( ( A3 >> a ) & 1 )
            {
                [struct_164 + 3c] = w(w[struct_164 + 3c] | 00000010);
            }
            else
            {
                [struct_164 + 3c] = w(w[struct_164 + 3c] & ffffffef);
            }

            A0 = struct_164;
            A1 = frame_id;
            system_set_sprite_frame();
        }

        [struct_164 + 9e] = h(hu[struct_164 + 9e] + wait);
        [struct_164 + 64] = w(w[struct_164 + 64] + 3);
        return;
    }
    else if( opcode == c8 )
    {
        A0 = struct_164;
        A1 = script_ptr + 2;
        func1fa1c();

        A0 = struct_164;
        A1 = bu[script_ptr + 1]; // opcode
        A2 = V0; // script pointer
        func1fa5c(); // parse opcode

        [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
        80024CF0	j      L246e4 [$800246e4]
    }
    else if( opcode == d4 )
    {
        [struct_164 + 64] = w(w[struct_164 + 64] + h[script_ptr + 1]);

        if( w[struct_164 + 68] != 0 )
        {
            A0 = struct_164;
            80024A50	jalr   w[struct_164 + 68] ra
        }
        80024A58	j      L246e4 [$800246e4]
    }
    else if( opcode == e1 )
    {
        [struct_164 + 64] = w(w[struct_164 + 64] + h[script_ptr + 1]);
        80024A20	j      L246e4 [$800246e4]
    }
    else if( opcode == e2 )
    {
        A0 = struct_164;
        A1 = w[struct_164 + 64] + 3;
        func21b58(); // push script pos 3 bytes to stack +8e

        [struct_164 + 64] = w(w[struct_164 + 64] + h[script_ptr + 1]);
        800249B0	j      L246e4 [$800246e4]

    }
    else if( opcode == e4 )
    {
        A0 = struct_164;
        func21a68(); // pop value 1 byte from stack +8e

        if( V0 == 0 )
        {
            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
        }
        else
        {
            A0 = struct_164;
            A1 = V0 - 1;
            func21b00(); // push to stack +8e

            [struct_164 + 64] = w(w[struct_164 + 64] + h[script_ptr + 1]);
        }
        80024C00	j      L246e4 [$800246e4]
    }
    else if( opcode == fa )
    {
        A0 = struct_164;
        A1 = script_ptr + 1;
        func1fa1c();

        if( bu[V0] == 0 )
        {
            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
        }
        else
        {
            [struct_164 + 64] = w(w[struct_164 + 64] + h[script_ptr + 1]);
        }
        80024A20	j      L246e4 [$800246e4]
    }
    else
    // 83 84 88 89 8a 8b 8c 8d 8f 90 91 92 93 94 95 96 97 99 9a 9b 9c 9d 9e 9f a0 a1 a2 a3
    // a4 a5 a6 a8 a9 aa ab ac ad ae af b0 b1 b2 b3 b4 b5 b6 b7 b8 b9 ba bb bc bd bf c0 c1
    // c2 c3 c4 c5 c6 c7 c9 ca cb cc cd ce cf d0 d1 d2 d3 d5 d6 d7 d8 d9 da db dc dd de df
    // e0 e3 e5 e6 e7 e8 e9 ea eb ec ed ee f0 f1 f2 f3 f4 f5 f6 f7 f8 f9 fb fc fd fe ff
    {
        A0 = struct_164;
        A1 = opcode;
        A2 = script_ptr + 1;
        func1fa5c(); // parse opcode

        [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]);
        80024CF0	j      L246e4 [$800246e4]
    }
}

[struct_164 + 64] = w(script_ptr + 1);

if( opcode < 10 )
{
    A0 = struct_164;
    A1 = hu[struct_164 + 34] + 1;
    system_set_sprite_frame();
}
else if( opcode < 20 )
{
    anim_frame_id = (w[struct_164 + a8] >> b) & 3f;
    [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | (((anim_frame_id + 1) & 3f) << b));

    A0 = struct_164;
    system_set_rotated_sprite_frame();
}
else if( opcode < 30 )
{
    A0 = struct_164;
    A1 = hu[struct_164 + 34] - 1;
    system_set_sprite_frame();
}

if( opcode < 40 )
{
    S3 = (opcode & f) + 1;
}
S3 = (S3 * ((w[struct_164 + ac] >> 9) & fff)) >> 8;
if( S3 == 0 )
{
    S3 = 1;
}
[struct_164 + 9e] = h(hu[struct_164 + 9e] + S3);

// increment unknown clamp 0x3f
V0 = (((w[struct_164 + a8] >> 16) & 3f) + 1) & 3f; // 0x0fc00000
if( V0 != 0 )
{
    [struct_164 + a8] = w((w[struct_164 + a8] & f03fffff) | (V0 << 16));
}
////////////////////////////////



////////////////////////////////
// func1fa5c
struct_164 = S3 = A0;
pointer = S1 = A2; // script pointer
A1 = A1 - 8a; // opcode

if( A1 < 73 )
{
    switch( A1 )
    {
        case 8a:
        {
            [struct_164 + c] = w(0);
            [struct_164 + 14] = w(0);
            [struct_164 + 18] = w(0);
            return;
        }

        case 8c:
        {
            S0 = w[struct_164 + 74];
            A0 = (h[S0 + a] << 10) | h[S0 + 2];
            A1 = (h[struct_164 + a] << 10) | h[struct_164 + 2];
            func22fa0(); // get rotation based on two positions x and y
            rotation = V0;

            A0 = struct_164;
            A1 = rotation;
            func21e40(); // set anim move based on rotation

            A0 = struct_164;
            A1 = rotation;
            func22218(); // apply new dir and anim

            return;
        }

        case 8d:
        {
            V0 = w[struct_164 + 24];
            A0 = h[V0 + 4];
            A1 = h[V0 + 6];
            system_set_default_tex_page_settings();

            return;
        }

        case 90:
        {
            if( w[struct_164 + 44] == w[struct_164 + 48] )
            {
                A0 = struct_164;
                A1 = w[struct_164 + 4c]; // sprite_pack
                func22124();

                [struct_164 + b0] = w(w[struct_164 + b0] | 00000400);
            }
            else
            {
                A0 = struct_164;
                A1 = w[struct_164 + 48]; // sprite_pack
                func22124();

                [struct_164 + b0] = w(w[struct_164 + b0] & fffffbff);
            }
            return;
        }

        case 91:
        {
            [struct_164 + 2b] = b(bu[struct_164 + 2b] & fe);
            A0 = struct_164;
            func1f524();

            return;
        }

        case 92:
        {
            [struct_164 + 2b] = b(bu[struct_164 + 2b] | 01);
            A0 = struct_164;
            func1f524();

            return;
        }

        case 93:
        {
            struct_164_2 = w[struct_164 + 70];
            if( struct_164_2 != 0 )
            {
                if( w[struct_164 + 3c] & 00000003 )
                {
                    struct_110 = w[struct_164 + 24];
                    sprite_file_1 = w[struct_110 + 0];
                    if( ( hu[sprite_file_1 + 0] >> f ) == 0 )
                    {
                        [struct_164 + 40] = w((w[struct_164 + 40] & fffe1fff) | 0001c000);
                    }

                    struct_b4 = w[struct_164 + 20];
                    if( struct_b4 != 0 )
                    {
                        struct_b4_2 = w[struct_164_2 + 20];
                        struct_124_2 = w[struct_b4_2 + 34];
                        if( struct_124_2 != 0 )
                        {
                            A0 = struct_164;
                            func1d364();

                            struct_124 = w[struct_b4 + 34];

                            T0 = 0;
                            loop20d20:	; 80020D20
                                [struct_124 + T0 * 8 + 0] = w(w[struct_124_2 + T0 * 8 + 0]);
                                [struct_124 + T0 * 8 + 4] = w(w[struct_124_2 + T0 * 8 + 4]);
                                T0 = T0 + 1;
                            80020D5C	bne    t0, 8, loop20d20 [$80020d20]

                            [struct_b4 + 3c] = b(b[struct_b4_2 + 3c]);
                            [struct_b4 + 3d] = b(b[struct_b4_2 + 3d]);
                        }
                    }

                    A0 = struct_164;
                    A1 = hu[struct_164 + 34]; // frame id
                    system_set_sprite_frame();
                }
            }
            return;
        }

        case 94:
        {
            if( ( w[struct_164 + 3c] & 00000003 ) == 2 )
            {
                S0 = w[struct_164 + 70];
                struct_b4 = w[struct_164 + 20];
                [struct_b4 + 2] = h(hu[S0 + 32]); // rotation y
                [struct_164 + 3c] = w(w[struct_164 + 3c] | 10000000);
            }
            return;
        }

        case 96:
        {
            A0 = w[struct_164 + 6c]; // pointer to self
            func1cd00();

            return;
        }

        case a0: // set move speed
        {
            [struct_164 + 18] = w((((b[pointer] << 4) * (w[80058838] + 1) * h[struct_164 + 82]) >> c) << 8);

            A0 = struct_164;
            func22800();

            return;
        }

        case a7: // wait
        {
            if( bu[pointer] & 80 )
            {
                [80058ac4] = w((bu[pointer] & 7f) + 1);
            }
            else
            {
                V1 = ((bu[pointer] + 1) * ((w[struct_164 + ac] >> 9) & fff)) >> 8;
                if( V1 == 0 )
                {
                    V1 = 1;
                }
                [struct_164 + 9e] = h(h[struct_164 + 9e] + V1);
            }
            return;
        }

        case b3: // set direction frame id
        {
            [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | ((b[pointer] & 3f) << b));
            return;
        }

        case b4: // push value to stack
        {
            V0 = bu[struct_164 + 8c] - 1;
            [struct_164 + 8c] = b(V0);
            [struct_164 + 8e + V0] = b(bu[pointer]);
            return;
        }

        case b5: // set scale
        {
            if( w[struct_164 + 3c] & 00000003 )
            {
                A0 = struct_164;
                A1 = bu[pointer] << 8;
                func21e60();
            }
            return;
        }

        case c6:
        {
            if( w[struct_164 + a8] & 00000001 )
            {
                V1 = w[struct_164 + 7c];
                [V1 + c] = h(bu[pointer]);
            }
            return;
        }

        case fc:
        {
            A0 = 2000;
            A1 = 0;
            system_memory_allocate();
            S0 = V0;

            V0 = S0 + 1f00;
            T0 = V0;
            [T0] = w(SP);
            T0 = T0 - 4;
            SP = T0;
            8001FCFC	lb     v0, $0002(s1)
            8001FD00	lbu    v1, $0001(s1)
            8001FD04	sll    v0, v0, $10
            8001FD08	sll    v1, v1, $08
            8001FD0C	addu   v0, v0, v1
            8001FD10	lbu    v1, $0000(s1)

            A0 = w[S3 + 24];
            8001FD18	addu   v0, v0, v1
            8001FD1C	lh     v1, $0004(a0)
            8001FD20	lh     a0, $0006(a0)
            8001FD24	addu   v0, v0, s1
            8001FD28	sw     v0, $0170(gp)
            8001FD2C	sh     v1, $0174(gp)
            8001FD30	sh     a0, $0178(gp)
            func1f9a8();

            SP = SP + 4;
            SP = w[SP];

            A0 = S0;
            system_memory_free();

            return;
        }

F4170280 // A1
74FD0180 // A2
EC150280 // A3
F80B0280 // A4
CC160280 // A5
24170280 // A6
B4150280 // A8
EC140280 // A9
40150280 // AA
7C150280 // AB
9C140280 // AC
CC120280 // AD
38130280 // AE
D0130280 // AF
70FB0180 // B0
78130280 // B6
A4130280 // b7
F8120280 // b8
64FB0180 // b9
940D0280 // ba
700C0280 // bb
64010280 // bc
6C120280 // bd
54FD0180 // bf
C4FF0180 // c0
60000280 // c1
14140280 // c4
20FB0180 // c5
ECFA0180 // c9
A0FB0180 // cc
80FD0180 // cd
34FE0180 // ce
FCFE0180 // cf
C40B0280 // d0
0C0A0280 // d1
440A0280 // d2
C40B0280 // d3
440A0280 // d5
AC0A0280 // d6
D00A0280 // d7
F80A0280 // d8
200B0280 // d9
440B0280 // da
680B0280 // db
900B0280 // dc
C40B0280 // dd
C40B0280 // de
100C0280 // df
A4120280 // e0
7C0A0280 // e5
280C0280 // e6
9C110280 // e7
D0110280 // e9
04120280 // ea
38120280 // eb
8C180280 // ed
A8180280 // ee
E8180280 // ef
A80D0280 // f1
240E0280 // f2
980F0280 // f5
38100280 // f6
D4100280 // f7


    8001FAEC	lw     v0, $00a8(s3)
    8001FAF0	nop
    8001FAF4	andi   v0, v0, $0001
    8001FAF8	beq    v0, zero, L21900 [$80021900]
    8001FAFC	nop
    8001FB00	lbu    v0, $0001(s1)
    8001FB04	lbu    v1, $0000(s1)
    8001FB08	lw     a0, $007c(s3)
    8001FB0C	sll    v0, v0, $18
    8001FB10	sra    v0, v0, $10
    8001FB14	or     v1, v1, v0
    8001FB18	j      L21900 [$80021900]
    8001FB1C	sh     v1, $000c(a0)
    8001FB20	lui    v0, $8006
    8001FB24	lw     v0, $8838(v0)
    8001FB28	lbu    s0, $0000(s1)
    8001FB2C	addiu  v0, v0, $0001
    8001FB30	div    s0, v0
    8001FB34	mflo   s0
    8001FB38	addiu  v0, zero, $ffff (=-$1)
    8001FB3C	addiu  s0, s0, $ffff (=-$1)
    8001FB40	beq    s0, v0, L21900 [$80021900]
    8001FB44	addiu  s1, zero, $ffff (=-$1)

    L1fb48:	; 8001FB48
    8001FB48	jal    func22b64 [$80022b64]
    8001FB4C	addu   a0, s3, zero
    8001FB50	addiu  s0, s0, $ffff (=-$1)
    8001FB54	beq    s0, s1, L21900 [$80021900]
    8001FB58	nop
    8001FB5C	j      L1fb48 [$8001fb48]
    8001FB60	nop
    8001FB64	lw     v0, $0050(s3)
    8001FB68	j      L1fb78 [$8001fb78]
    8001FB6C	nop
    8001FB70	lui    v0, $8006
    8001FB74	lw     v0, $883c(v0)

    L1fb78:	; 8001FB78
    8001FB78	nop
    8001FB7C	beq    v0, zero, L21900 [$80021900]
    8001FB80	nop
    8001FB84	lhu    a0, $0014(v0)
    8001FB88	lbu    v0, $0000(s1)
    8001FB8C	sll    a0, a0, $10
    8001FB90	jal    func39d08 [$80039d08]
    8001FB94	or     a0, v0, a0
    8001FB98	j      L21900 [$80021900]
    8001FB9C	nop
    8001FBA0	lbu    v0, $0001(s1)
    8001FBA4	lbu    v1, $0000(s1)
    8001FBA8	lw     a0, $0064(s3)
    8001FBAC	sll    v0, v0, $18
    8001FBB0	sra    v0, v0, $10
    8001FBB4	or     v1, v1, v0
    8001FBB8	addu   v1, v1, a0
    8001FBBC	j      L21900 [$80021900]
    8001FBC0	sw     v1, $0088(s3)

    8001FD54	lbu    v0, $0000(s1)
    8001FD58	j      L21900 [$80021900]
    8001FD5C	sh     v0, $0036(s3)

    8001FD74	lbu    v0, $0000(s1)
    8001FD78	j      L21900 [$80021900]
    8001FD7C	sb     v0, $003d(s3)
    8001FD80	lw     a0, $0020(s3)
    8001FD84	nop
    8001FD88	beq    a0, zero, L21900 [$80021900]
    8001FD8C	nop
    8001FD90	lbu    v1, $0001(s1)
    8001FD94	lbu    v0, $0000(s1)
    8001FD98	sll    v1, v1, $18
    8001FD9C	sra    v1, v1, $10
    8001FDA0	or     v0, v0, v1
    8001FDA4	andi   v1, v0, $01ff
    8001FDA8	sll    a1, v1, $03
    8001FDAC	andi   v0, v0, $ffff
    8001FDB0	srl    v1, v0, $09
    8001FDB4	srl    v0, v0, $0c
    8001FDB8	andi   v0, v0, $0001
    8001FDBC	bne    v0, zero, L1fe08 [$8001fe08]
    8001FDC0	andi   v1, v1, $0007
    8001FDC4	beq    v1, zero, L1fdf4 [$8001fdf4]
    8001FDC8	nop
    8001FDCC	lw     v0, $0034(a0)
    8001FDD0	nop
    8001FDD4	beq    v0, zero, L21900 [$80021900]
    8001FDD8	sll    v1, v1, $03
    8001FDDC	addu   v1, v1, v0
    8001FDE0	lhu    v0, $0002(v1)
    8001FDE4	nop
    8001FDE8	addu   v0, v0, a1
    8001FDEC	j      L21900 [$80021900]
    8001FDF0	sh     v0, $0002(v1)

    L1fdf4:	; 8001FDF4
    8001FDF4	lhu    v0, $0000(a0)
    8001FDF8	nop
    8001FDFC	addu   v0, v0, a1
    8001FE00	j      L21400 [$80021400]
    8001FE04	sh     v0, $0000(a0)

    L1fe08:	; 8001FE08
    8001FE08	beq    v1, zero, L1fe2c [$8001fe2c]
    8001FE0C	nop
    8001FE10	lw     a0, $0034(a0)
    8001FE14	nop
    8001FE18	beq    a0, zero, L21900 [$80021900]
    8001FE1C	sll    v0, v1, $03
    8001FE20	addu   v0, v0, a0
    8001FE24	j      L21900 [$80021900]
    8001FE28	sh     a1, $0002(v0)

    L1fe2c:	; 8001FE2C
    8001FE2C	j      L21400 [$80021400]
    8001FE30	sh     a1, $0000(a0)
    8001FE34	lbu    v0, $0001(s1)
    8001FE38	lbu    v1, $0000(s1)
    8001FE3C	lw     a0, $0020(s3)
    8001FE40	sll    v0, v0, $18
    8001FE44	sra    v0, v0, $10
    8001FE48	or     v0, v1, v0
    8001FE4C	beq    a0, zero, L21900 [$80021900]
    8001FE50	addu   v1, v0, zero
    8001FE54	andi   v0, v0, $01ff
    8001FE58	sll    a1, v0, $03
    8001FE5C	andi   a2, v1, $ffff
    8001FE60	srl    v1, a2, $09
    8001FE64	lw     v0, $00ac(s3)
    8001FE68	nop
    8001FE6C	andi   v0, v0, $0010
    8001FE70	beq    v0, zero, L1fe7c [$8001fe7c]
    8001FE74	andi   v1, v1, $0007
    8001FE78	subu   a1, zero, a1

    L1fe7c:	; 8001FE7C
    8001FE7C	srl    v0, a2, $0c
    8001FE80	andi   v0, v0, $0001
    8001FE84	bne    v0, zero, L1fed0 [$8001fed0]
    8001FE88	nop
    8001FE8C	beq    v1, zero, L1febc [$8001febc]
    8001FE90	nop
    8001FE94	lw     v0, $0034(a0)
    8001FE98	nop
    8001FE9C	beq    v0, zero, L21900 [$80021900]
    8001FEA0	sll    v1, v1, $03
    8001FEA4	addu   v1, v1, v0
    8001FEA8	lhu    v0, $0004(v1)
    8001FEAC	nop
    8001FEB0	addu   v0, v0, a1
    8001FEB4	j      L21900 [$80021900]
    8001FEB8	sh     v0, $0004(v1)

    L1febc:	; 8001FEBC
    8001FEBC	lhu    v0, $0002(a0)
    8001FEC0	nop
    8001FEC4	addu   v0, v0, a1
    8001FEC8	j      L21400 [$80021400]
    8001FECC	sh     v0, $0002(a0)

    L1fed0:	; 8001FED0
    8001FED0	beq    v1, zero, L1fef4 [$8001fef4]
    8001FED4	nop
    8001FED8	lw     a0, $0034(a0)
    8001FEDC	nop
    8001FEE0	beq    a0, zero, L21900 [$80021900]
    8001FEE4	sll    v0, v1, $03
    8001FEE8	addu   v0, v0, a0
    8001FEEC	j      L21900 [$80021900]
    8001FEF0	sh     a1, $0004(v0)

    L1fef4:	; 8001FEF4
    8001FEF4	j      L21400 [$80021400]
    8001FEF8	sh     a1, $0002(a0)
    8001FEFC	lbu    v0, $0001(s1)
    8001FF00	lbu    v1, $0000(s1)
    8001FF04	lw     a0, $0020(s3)
    8001FF08	sll    v0, v0, $18
    8001FF0C	sra    v0, v0, $10
    8001FF10	or     v0, v1, v0
    8001FF14	beq    a0, zero, L21900 [$80021900]
    8001FF18	addu   v1, v0, zero
    8001FF1C	andi   v0, v0, $01ff
    8001FF20	sll    a1, v0, $03
    8001FF24	andi   a2, v1, $ffff
    8001FF28	srl    v1, a2, $09
    8001FF2C	lw     v0, $00ac(s3)
    8001FF30	nop
    8001FF34	andi   v0, v0, $0010
    8001FF38	beq    v0, zero, L1ff44 [$8001ff44]
    8001FF3C	andi   v1, v1, $0007
    8001FF40	subu   a1, zero, a1

    L1ff44:	; 8001FF44
    8001FF44	srl    v0, a2, $0c
    8001FF48	andi   v0, v0, $0001
    8001FF4C	bne    v0, zero, L1ff98 [$8001ff98]
    8001FF50	nop
    8001FF54	beq    v1, zero, L1ff84 [$8001ff84]
    8001FF58	nop
    8001FF5C	lw     v0, $0034(a0)
    8001FF60	nop
    8001FF64	beq    v0, zero, L21900 [$80021900]
    8001FF68	sll    v1, v1, $03
    8001FF6C	addu   v1, v1, v0
    8001FF70	lhu    v0, $0006(v1)
    8001FF74	nop
    8001FF78	addu   v0, v0, a1
    8001FF7C	j      L21900 [$80021900]
    8001FF80	sh     v0, $0006(v1)

    L1ff84:	; 8001FF84
    8001FF84	lhu    v0, $0004(a0)
    8001FF88	nop
    8001FF8C	addu   v0, v0, a1
    8001FF90	j      L21400 [$80021400]
    8001FF94	sh     v0, $0004(a0)

    L1ff98:	; 8001FF98
    8001FF98	beq    v1, zero, L1ffbc [$8001ffbc]
    8001FF9C	nop
    8001FFA0	lw     a0, $0034(a0)
    8001FFA4	nop
    8001FFA8	beq    a0, zero, L21900 [$80021900]
    8001FFAC	sll    v0, v1, $03
    8001FFB0	addu   v0, v0, a0
    8001FFB4	j      L21900 [$80021900]
    8001FFB8	sh     a1, $0006(v0)

    L1ffbc:	; 8001FFBC
    8001FFBC	j      L21400 [$80021400]
    8001FFC0	sh     a1, $0004(a0)
    8001FFC4	jal    system_get_random_2_bytes [$8003f8b0]
    8001FFC8	nop
    8001FFCC	lbu    v1, $0000(s1)
    8001FFD0	andi   s1, v0, $00ff
    8001FFD4	mult   s1, v1
    8001FFD8	mflo   s1
    8001FFDC	lh     v0, $002c(s3)
    8001FFE0	sra    s1, s1, $08
    8001FFE4	mult   s1, v0
    8001FFE8	mflo   v0
    8001FFEC	bgez   v0, L1fff8 [$8001fff8]
    8001FFF0	nop
    8001FFF4	addiu  v0, v0, $0fff

    L1fff8:	; 8001FFF8
    8001FFF8	jal    system_get_random_2_bytes [$8003f8b0]
    8001FFFC	sra    s1, v0, $0c
    80020000	addu   s0, v0, zero
    80020004	jal    system_cos [$8003f774]
    80020008	addu   a0, s0, zero
    8002000C	addu   a0, s3, zero
    80020010	jal    func22b34 [$80022b34]
    80020014	addu   a1, v0, zero
    80020018	mult   v0, s1
    8002001C	addu   a0, s0, zero
    80020020	lw     v1, $0000(s3)
    80020024	mflo   v0
    80020028	sll    v0, v0, $04
    8002002C	addu   v0, v0, v1
    80020030	jal    system_sin [$8003f758]
    80020034	sw     v0, $0000(s3)
    80020038	addu   a0, s3, zero
    8002003C	jal    func22b34 [$80022b34]
    80020040	addu   a1, v0, zero
    80020044	mult   v0, s1
    80020048	lw     v1, $0008(s3)
    8002004C	mflo   v0
    80020050	sll    v0, v0, $04
    80020054	subu   v1, v1, v0
    80020058	j      L21900 [$80021900]
    8002005C	sw     v1, $0008(s3)
    80020060	jal    system_get_random_2_bytes [$8003f8b0]
    80020064	nop
    80020068	lbu    v1, $0000(s1)
    8002006C	andi   a0, v0, $00ff
    80020070	mult   a0, v1
    80020074	mflo   a0
    80020078	lh     v0, $002c(s3)
    8002007C	sra    a0, a0, $08
    80020080	mult   a0, v0
    80020084	mflo   a1
    80020088	bgez   a1, L20094 [$80020094]
    8002008C	addu   a0, s3, zero
    80020090	addiu  a1, a1, $0fff

    L20094:	; 80020094
    80020094	jal    func22b34 [$80022b34]
    80020098	sra    a1, a1, $0c
    8002009C	addiu  a0, sp, $0018
    800200A0	sll    v0, v0, $10
    800200A4	sra    a1, v0, $10
    800200A8	addu   a2, zero, zero
    800200AC	jal    func2194c [$8002194c]
    800200B0	addu   a3, zero, zero
    800200B4	jal    system_get_random_2_bytes [$8003f8b0]
    800200B8	nop
    800200BC	sll    s0, v0, $10
    800200C0	jal    system_get_random_2_bytes [$8003f8b0]
    800200C4	sra    s0, s0, $10
    800200C8	addiu  s2, sp, $0030
    800200CC	addu   a0, s2, zero
    800200D0	addu   a1, s0, zero
    800200D4	sll    v0, v0, $10
    800200D8	sra    a2, v0, $10
    800200DC	jal    func2194c [$8002194c]
    800200E0	addu   a3, zero, zero
    800200E4	addiu  s1, sp, $0020
    800200E8	lh     a1, $0002(s3)
    800200EC	lh     a2, $0006(s3)
    800200F0	lh     a3, $000a(s3)
    800200F4	jal    func2195c [$8002195c]
    800200F8	addu   a0, s1, zero
    800200FC	addiu  s0, sp, $0038
    80020100	addu   a0, s0, zero
    80020104	jal    func49c44 [$80049c44]
    80020108	addu   a1, s1, zero
    8002010C	jal    system_gte_set_translation_vector [$80049e34]
    80020110	addu   a0, s0, zero
    80020114	addu   a0, s2, zero
    80020118	jal    system_calculate_rotation_matrix [$8003f5e0]
    8002011C	addu   a1, s0, zero
    80020120	jal    system_gte_set_rotation_matrix [$80049da4]
    80020124	addu   a0, s0, zero
    80020128	addiu  a0, sp, $0018
    8002012C	addu   a1, a0, zero
    80020130	jal    func4a3f4 [$8004a3f4]
    80020134	addiu  a2, sp, $0068
    80020138	lh     v0, $0018(sp)
    8002013C	nop
    80020140	sll    v0, v0, $10
    80020144	sw     v0, $0000(s3)
    80020148	lh     v0, $001a(sp)
    8002014C	nop
    80020150	sll    v0, v0, $10
    80020154	sw     v0, $0004(s3)
    80020158	lh     v0, $001c(sp)
    8002015C	j      L218fc [$800218fc]
    80020160	sll    v0, v0, $10
    80020164	lbu    s2, $0000(s1)
    80020168	nop
    8002016C	andi   v0, s2, $0080
    80020170	beq    v0, zero, L20930 [$80020930]
    80020174	andi   a0, s2, $003f
    80020178	lbu    v0, $003f(s3)
    8002017C	nop
    80020180	andi   s1, v0, $0001
    80020184	sltiu  v0, a0, $0027
    80020188	beq    v0, zero, L2087c [$8002087c]
    8002018C	sll    v0, a0, $02
    80020190	lui    at, $8002
    80020194	addu   at, at, v0
    80020198	lw     v0, $8578(at)
    8002019C	nop
    800201A0	jr     v0 
    800201A4	nop

    800201A8	lw     v1, $00ac(s3)
    800201AC	nop
    800201B0	andi   v1, v1, $000f
    800201B4	sll    v0, v1, $03
    800201B8	subu   v0, v0, v1
    800201BC	sll    v0, v0, $02
    800201C0	lui    at, $800c
    800201C4	addu   at, at, v0
    800201C8	lhu    v0, $35de(at)
    800201CC	nop
    800201D0	sh     v0, $0018(sp)
    800201D4	lw     v1, $00ac(s3)
    800201D8	nop
    800201DC	andi   v1, v1, $000f
    800201E0	sll    v0, v1, $03
    800201E4	subu   v0, v0, v1
    800201E8	sll    v0, v0, $02
    800201EC	lui    at, $800c
    800201F0	addu   at, at, v0
    800201F4	lhu    v0, $35e0(at)
    800201F8	sh     zero, $001a(sp)
    800201FC	j      L2087c [$8002087c]
    80020200	sh     v0, $001c(sp)
    80020204	lw     v0, $006c(s3)
    80020208	nop
    8002020C	lw     v1, $0014(v0)
    80020210	lui    a0, $4000
    80020214	or     v1, v1, a0
    80020218	j      L2027c [$8002027c]
    8002021C	sw     v1, $0014(v0)
    80020220	lw     a0, $006c(s3)
    80020224	lui    v1, $bfff
    80020228	lw     v0, $0014(a0)
    8002022C	ori    v1, v1, $ffff
    80020230	and    v0, v0, v1
    80020234	j      L2027c [$8002027c]
    80020238	sw     v0, $0014(a0)
    8002023C	addiu  a0, sp, $0020
    80020240	jal    func49f64 [$80049f64]
    80020244	addiu  a1, sp, $0024
    80020248	lw     v1, $0020(sp)
    8002024C	ori    v0, zero, $00a0
    80020250	subu   v0, v0, v1
    80020254	lw     v1, $0024(sp)
    80020258	sll    v0, v0, $01
    8002025C	sh     v0, $0018(sp)
    80020260	ori    v0, zero, $0070
    80020264	subu   v0, v0, v1
    80020268	sll    v0, v0, $01
    8002026C	sh     v0, $001a(sp)
    80020270	lh     v0, $000a(s3)
    80020274	j      L202c8 [$800202c8]
    80020278	addu   s1, zero, zero

    L2027c:	; 8002027C
    8002027C	lh     v0, $0002(s3)
    80020280	nop
    80020284	sh     v0, $0018(sp)
    80020288	lh     v0, $0006(s3)
    8002028C	nop
    80020290	sh     v0, $001a(sp)
    80020294	lh     v0, $000a(s3)
    80020298	j      L202c8 [$800202c8]
    8002029C	addu   s1, zero, zero
    800202A0	lw     s0, $0070(s3)
    800202A4	nop
    800202A8	lh     v0, $0002(s0)
    800202AC	nop
    800202B0	sh     v0, $0018(sp)
    800202B4	lh     v0, $0006(s0)
    800202B8	nop
    800202BC	sh     v0, $001a(sp)
    800202C0	lh     v0, $000a(s0)
    800202C4	addu   s1, zero, zero

    L202c8:	; 800202C8
    800202C8	j      L2087c [$8002087c]
    800202CC	sh     v0, $001c(sp)
    800202D0	lui    s0, $800c
    800202D4	lw     s0, $353c(s0)
    800202D8	j      L20314 [$80020314]
    800202DC	nop
    800202E0	lui    s0, $800c
    800202E4	lw     s0, $353c(s0)
    800202E8	j      L2034c [$8002034c]
    800202EC	nop
    800202F0	lui    s0, $800c
    800202F4	lw     s0, $353c(s0)
    800202F8	j      L2039c [$8002039c]
    800202FC	nop
    80020300	lui    s0, $800c
    80020304	lw     s0, $353c(s0)
    80020308	j      L203dc [$800203dc]
    8002030C	nop
    80020310	lw     s0, $0074(s3)

    L20314:	; 80020314
    80020314	nop
    80020318	lh     v0, $0002(s0)
    8002031C	nop
    80020320	sh     v0, $0018(sp)
    80020324	lh     v1, $0006(s0)
    80020328	nop
    8002032C	sh     v1, $001a(sp)
    80020330	lh     v0, $000a(s0)
    80020334	nop
    80020338	sh     v0, $001c(sp)
    8002033C	lhu    v0, $0036(s0)
    80020340	j      L203d0 [$800203d0]
    80020344	subu   v1, v1, v0
    80020348	lw     s0, $0074(s3)

    L2034c:	; 8002034C
    8002034C	nop
    80020350	lh     v0, $0002(s0)
    80020354	nop
    80020358	sh     v0, $0018(sp)
    8002035C	lh     a0, $0006(s0)
    80020360	nop
    80020364	sh     a0, $001a(sp)
    80020368	lh     v0, $000a(s0)
    8002036C	nop
    80020370	sh     v0, $001c(sp)
    80020374	lhu    v0, $0036(s0)
    80020378	lhu    v1, $0038(s0)
    8002037C	nop
    80020380	subu   v0, v0, v1
    80020384	srl    v1, v0, $1f
    80020388	addu   v0, v0, v1
    8002038C	lhu    v1, $0036(s0)
    80020390	j      L20410 [$80020410]
    80020394	sra    v0, v0, $01
    80020398	lw     s0, $0074(s3)

    L2039c:	; 8002039C
    8002039C	nop
    800203A0	lh     v0, $0002(s0)
    800203A4	nop
    800203A8	sh     v0, $0018(sp)
    800203AC	lh     v1, $0006(s0)
    800203B0	nop
    800203B4	sh     v1, $001a(sp)
    800203B8	lh     v0, $000a(s0)
    800203BC	nop
    800203C0	sh     v0, $001c(sp)
    800203C4	lhu    v0, $0038(s0)
    800203C8	nop
    800203CC	subu   v1, v1, v0

    L203d0:	; 800203D0
    800203D0	j      L2087c [$8002087c]
    800203D4	sh     v1, $001a(sp)
    800203D8	lw     s0, $0074(s3)

    L203dc:	; 800203DC
    800203DC	nop
    800203E0	lh     v0, $0002(s0)
    800203E4	nop
    800203E8	sh     v0, $0018(sp)
    800203EC	lh     a0, $0006(s0)
    800203F0	nop
    800203F4	sh     a0, $001a(sp)
    800203F8	lh     v0, $000a(s0)
    800203FC	nop
    80020400	sh     v0, $001c(sp)
    80020404	lhu    v0, $0038(s0)
    80020408	lhu    v1, $0038(s0)
    8002040C	sra    v0, v0, $01

    L20410:	; 80020410
    80020410	subu   v1, v1, v0
    80020414	subu   a0, a0, v1
    80020418	j      L2087c [$8002087c]
    8002041C	sh     a0, $001a(sp)
    80020420	lui    v0, $8007
    80020424	lh     v0, $f02e(v0)
    80020428	lui    v1, $8007
    8002042C	lh     v1, $f032(v1)
    80020430	lui    a0, $8007
    80020434	lh     a0, $f036(a0)
    80020438	sh     v0, $0018(sp)
    8002043C	j      L20878 [$80020878]
    80020440	sh     v1, $001a(sp)
    80020444	lui    v0, $8007
    80020448	lh     v0, $f03e(v0)
    8002044C	lui    v1, $8007
    80020450	lh     v1, $f042(v1)
    80020454	lui    a0, $8007
    80020458	lh     a0, $f046(a0)
    8002045C	sh     v0, $0018(sp)
    80020460	j      L20878 [$80020878]
    80020464	sh     v1, $001a(sp)
    80020468	lui    s0, $800c
    8002046C	lw     s0, $353c(s0)
    80020470	j      L20598 [$80020598]
    80020474	nop
    80020478	j      L204a8 [$800204a8]
    8002047C	ori    a0, zero, $000b
    80020480	j      L204a8 [$800204a8]
    80020484	ori    a0, zero, $000c
    80020488	j      L204a8 [$800204a8]
    8002048C	ori    a0, zero, $000d
    80020490	lw     s0, $0070(s3)
    80020494	nop
    80020498	beq    s0, zero, L20880 [$80020880]
    8002049C	andi   v0, s1, $00ff
    800204A0	j      L204ac [$800204ac]
    800204A4	nop

    L204a8:	; 800204A8
    800204A8	lw     s0, $0074(s3)

    L204ac:	; 800204AC
    800204AC	nop
    800204B0	lw     a1, $0020(s0)
    800204B4	nop
    800204B8	beq    a1, zero, L2087c [$8002087c]
    800204BC	ori    v1, zero, $0001
    800204C0	lw     v0, $003c(s0)
    800204C4	nop
    800204C8	andi   v0, v0, $0003
    800204CC	bne    v0, v1, L2087c [$8002087c]
    800204D0	nop
    800204D4	lw     v1, $0034(a1)
    800204D8	nop
    800204DC	beq    v1, zero, L204fc [$800204fc]
    800204E0	addiu  v0, a0, $fff6 (=-$a)
    800204E4	sll    v0, v0, $03
    800204E8	addu   v0, v0, v1
    800204EC	lb     v1, $0000(v0)
    800204F0	lb     t0, $0001(v0)
    800204F4	j      L20504 [$80020504]
    800204F8	nop

    L204fc:	; 800204FC
    800204FC	addu   v1, zero, zero
    80020500	addu   t0, zero, zero

    L20504:	; 80020504
    80020504	lw     v0, $00ac(s0)
    80020508	nop
    8002050C	andi   v0, v0, $0010
    80020510	beq    v0, zero, L2051c [$8002051c]
    80020514	nop
    80020518	subu   v1, zero, v1

    L2051c:	; 8002051C
    8002051C	lh     v0, $002c(s0)
    80020520	nop
    80020524	mult   v1, v0
    80020528	mflo   a1
    8002052C	nop
    80020530	bgez   a1, L2053c [$8002053c]
    80020534	mult   t0, v0
    80020538	addiu  a1, a1, $0fff

    L2053c:	; 8002053C
    8002053C	mflo   a2
    80020540	bgez   a2, L2054c [$8002054c]
    80020544	sra    v1, a1, $0c
    80020548	addiu  a2, a2, $0fff

    L2054c:	; 8002054C
    8002054C	sra    t0, a2, $0c
    80020550	addiu  a0, sp, $0018
    80020554	lh     a1, $0002(s0)
    80020558	lh     a3, $000a(s0)
    8002055C	lh     a2, $0006(s0)
    80020560	addu   a1, v1, a1
    80020564	sll    a1, a1, $10
    80020568	sra    a1, a1, $10
    8002056C	addu   a2, t0, a2
    80020570	sll    a2, a2, $10
    80020574	jal    func2194c [$8002194c]
    80020578	sra    a2, a2, $10
    8002057C	j      L20880 [$80020880]
    80020580	andi   v0, s1, $00ff
    80020584	lui    s0, $800c
    80020588	lw     s0, $353c(s0)
    8002058C	j      L204ac [$800204ac]
    80020590	addiu  a0, a0, $fff2 (=-$e)
    80020594	lw     s0, $0074(s3)

    L20598:	; 80020598
    80020598	nop
    8002059C	lh     v0, $0002(s0)
    800205A0	nop
    800205A4	sh     v0, $0018(sp)
    800205A8	lh     v0, $0006(s0)
    800205AC	nop
    800205B0	sh     v0, $001a(sp)
    800205B4	lh     v0, $000a(s0)
    800205B8	j      L2087c [$8002087c]
    800205BC	sh     v0, $001c(sp)
    800205C0	addiu  a0, sp, $0020
    800205C4	addu   a1, zero, zero
    800205C8	addu   a2, zero, zero
    800205CC	jal    func2195c [$8002195c]
    800205D0	addu   a3, zero, zero
    800205D4	lui    v0, $800d
    800205D8	addiu  v0, v0, $2d5c
    800205DC	lw     s0, $0000(v0)
    800205E0	nop
    800205E4	beq    s0, zero, L2063c [$8002063c]
    800205E8	addu   a1, zero, zero
    800205EC	addu   a0, v0, zero

    loop205f0:	; 800205F0
    800205F0	lw     v0, $0020(sp)
    800205F4	lw     v1, $0000(s0)
    800205F8	nop
    800205FC	addu   v0, v0, v1
    80020600	sw     v0, $0020(sp)
    80020604	lw     v0, $0024(sp)
    80020608	lw     v1, $0004(s0)
    8002060C	nop
    80020610	addu   v0, v0, v1
    80020614	sw     v0, $0024(sp)
    80020618	lw     v0, $0028(sp)
    8002061C	lw     v1, $0008(s0)
    80020620	addiu  a0, a0, $0004
    80020624	addu   v0, v0, v1
    80020628	sw     v0, $0028(sp)
    8002062C	lw     s0, $0000(a0)
    80020630	nop
    80020634	bne    s0, zero, loop205f0 [$800205f0]
    80020638	addiu  a1, a1, $0001

    L2063c:	; 8002063C
    8002063C	lw     v0, $0020(sp)
    80020640	nop
    80020644	div    v0, a1
    80020648	mflo   v0
    8002064C	lw     v1, $0024(sp)
    80020650	nop
    80020654	div    v1, a1
    80020658	mflo   v1
    8002065C	lw     a0, $0028(sp)
    80020660	nop
    80020664	div    a0, a1
    80020668	mflo   a0
    8002066C	j      L2085c [$8002085c]
    80020670	sw     v0, $0020(sp)
    80020674	lui    s0, $800c
    80020678	lw     s0, $353c(s0)
    8002067C	nop
    80020680	lw     v1, $0000(s0)
    80020684	nop
    80020688	sw     v1, $0020(sp)
    8002068C	lw     a0, $0004(s0)
    80020690	nop
    80020694	sw     a0, $0024(sp)
    80020698	lw     a1, $0008(s0)
    8002069C	nop
    800206A0	sw     a1, $0028(sp)
    800206A4	lw     v0, $0000(s3)
    800206A8	nop
    800206AC	addu   v1, v1, v0
    800206B0	sw     v1, $0020(sp)
    800206B4	lw     v0, $0004(s3)
    800206B8	nop
    800206BC	addu   a0, a0, v0
    800206C0	srl    v0, v1, $1f
    800206C4	addu   v1, v1, v0
    800206C8	sw     a0, $0024(sp)
    800206CC	lw     a2, $0008(s3)
    800206D0	sra    v0, v1, $01
    800206D4	sw     v0, $0020(sp)
    800206D8	srl    v0, a0, $1f
    800206DC	addu   a0, a0, v0
    800206E0	sra    v0, a0, $01
    800206E4	sra    v1, v1, $11
    800206E8	sra    a0, a0, $11
    800206EC	sw     v0, $0024(sp)
    800206F0	sh     v1, $0018(sp)
    800206F4	sh     a0, $001a(sp)
    800206F8	addu   a1, a1, a2
    800206FC	srl    v0, a1, $1f
    80020700	sw     a1, $0028(sp)
    80020704	addu   a1, a1, v0
    80020708	sra    v0, a1, $01
    8002070C	sra    a1, a1, $11
    80020710	sw     v0, $0028(sp)
    80020714	j      L2087c [$8002087c]
    80020718	sh     a1, $001c(sp)
    8002071C	addiu  a0, sp, $0020
    80020720	addu   a1, zero, zero
    80020724	addu   a2, zero, zero
    80020728	jal    func2195c [$8002195c]
    8002072C	addu   a3, zero, zero
    80020730	lui    v0, $800d
    80020734	addiu  v0, v0, $2d5c
    80020738	lw     s0, $0000(v0)
    8002073C	nop
    80020740	beq    s0, zero, L20798 [$80020798]
    80020744	addu   a2, zero, zero
    80020748	addu   a0, v0, zero

    loop2074c:	; 8002074C
    8002074C	lw     v0, $0020(sp)
    80020750	lw     v1, $0000(s0)
    80020754	nop
    80020758	addu   v0, v0, v1
    8002075C	sw     v0, $0020(sp)
    80020760	lw     v0, $0024(sp)
    80020764	lw     v1, $0004(s0)
    80020768	nop
    8002076C	addu   v0, v0, v1
    80020770	sw     v0, $0024(sp)
    80020774	lw     v0, $0028(sp)
    80020778	lw     v1, $0008(s0)
    8002077C	addiu  a0, a0, $0004
    80020780	addu   v0, v0, v1
    80020784	sw     v0, $0028(sp)
    80020788	lw     s0, $0000(a0)
    8002078C	nop
    80020790	bne    s0, zero, loop2074c [$8002074c]
    80020794	addiu  a2, a2, $0001

    L20798:	; 80020798
    80020798	lw     v0, $0020(sp)
    8002079C	lw     v1, $0000(s3)
    800207A0	addiu  a2, a2, $0001
    800207A4	addu   v0, v0, v1
    800207A8	div    v0, a2
    800207AC	mflo   a1
    800207B0	sw     v0, $0020(sp)
    800207B4	lw     v0, $0024(sp)
    800207B8	lw     v1, $0004(s3)
    800207BC	nop
    800207C0	addu   v0, v0, v1
    800207C4	div    v0, a2
    800207C8	mflo   a0
    800207CC	sw     v0, $0024(sp)
    800207D0	lw     v0, $0028(sp)
    800207D4	lw     v1, $0008(s3)
    800207D8	nop
    800207DC	addu   v0, v0, v1
    800207E0	div    v0, a2
    800207E4	mflo   v1
    800207E8	sw     v0, $0028(sp)
    800207EC	sw     a1, $0020(sp)
    800207F0	sra    a1, a1, $10
    800207F4	sh     a1, $0018(sp)
    800207F8	sw     a0, $0024(sp)
    800207FC	sra    a0, a0, $10
    80020800	sh     a0, $001a(sp)
    80020804	sw     v1, $0028(sp)
    80020808	sra    v1, v1, $10
    8002080C	j      L2087c [$8002087c]
    80020810	sh     v1, $001c(sp)
    80020814	addiu  a0, sp, $0020
    80020818	addu   a1, zero, zero
    8002081C	addu   a2, zero, zero
    80020820	jal    func2195c [$8002195c]
    80020824	addu   a3, zero, zero
    80020828	lw     v0, $0020(sp)
    8002082C	nop
    80020830	div    v0, s0
    80020834	mflo   v0
    80020838	lw     v1, $0024(sp)
    8002083C	nop
    80020840	div    v1, s0
    80020844	mflo   v1
    80020848	lw     a0, $0028(sp)
    8002084C	nop
    80020850	div    a0, s0
    80020854	mflo   a0
    80020858	sw     v0, $0020(sp)

    L2085c:	; 8002085C
    8002085C	sra    v0, v0, $10
    80020860	sh     v0, $0018(sp)
    80020864	sw     v1, $0024(sp)
    80020868	sra    v1, v1, $10
    8002086C	sh     v1, $001a(sp)
    80020870	sw     a0, $0028(sp)
    80020874	sra    a0, a0, $10

    L20878:	; 80020878
    80020878	sh     a0, $001c(sp)

    L2087c:	; 8002087C
    8002087C	andi   v0, s1, $00ff

    L20880:	; 80020880
    80020880	beq    v0, zero, L208d4 [$800208d4]
    80020884	addiu  a1, sp, $0018
    80020888	lui    a0, $8005
    8002088C	addiu  a0, a0, $f25c (=-$da4)
    80020890	jal    func49be4 [$80049be4]
    80020894	addu   a2, a1, zero
    80020898	lhu    v0, $0018(sp)
    8002089C	lui    v1, $8005
    800208A0	lhu    v1, $f270(v1)
    800208A4	lui    a0, $8005
    800208A8	lhu    a0, $f274(a0)
    800208AC	lui    a1, $8005
    800208B0	lhu    a1, $f278(a1)
    800208B4	addu   v0, v0, v1
    800208B8	sh     v0, $0018(sp)
    800208BC	lhu    v0, $001a(sp)
    800208C0	lhu    v1, $001c(sp)
    800208C4	addu   v0, v0, a0
    800208C8	addu   v1, v1, a1
    800208CC	sh     v0, $001a(sp)
    800208D0	sh     v1, $001c(sp)

    L208d4:	; 800208D4
    800208D4	andi   v0, s2, $0040
    800208D8	beq    v0, zero, L20904 [$80020904]
    800208DC	nop
    800208E0	lhu    v0, $0018(sp)
    800208E4	nop
    800208E8	sh     v0, $00a0(s3)
    800208EC	lhu    v0, $001a(sp)
    800208F0	nop
    800208F4	sh     v0, $00a2(s3)
    800208F8	lhu    v0, $001c(sp)
    800208FC	j      L21900 [$80021900]
    80020900	sh     v0, $00a4(s3)

    L20904:	; 80020904
    80020904	lh     v0, $0018(sp)
    80020908	nop
    8002090C	sll    v0, v0, $10
    80020910	sw     v0, $0000(s3)
    80020914	lh     v0, $001a(sp)
    80020918	nop
    8002091C	sll    v0, v0, $10
    80020920	sw     v0, $0004(s3)
    80020924	lh     v0, $001c(sp)
    80020928	j      L218fc [$800218fc]
    8002092C	sll    v0, v0, $10

    L20930:	; 80020930
    80020930	lw     s0, $0070(s3)
    80020934	nop
    80020938	beq    s0, zero, L21900 [$80021900]
    8002093C	nop
    80020940	lw     a0, $0020(s0)
    80020944	nop
    80020948	beq    a0, zero, L21900 [$80021900]
    8002094C	ori    v1, zero, $0001
    80020950	lw     v0, $003c(s0)
    80020954	nop
    80020958	andi   v0, v0, $0003
    8002095C	bne    v0, v1, L21900 [$80021900]
    80020960	nop
    80020964	lw     v1, $0034(a0)
    80020968	nop
    8002096C	beq    v1, zero, L20988 [$80020988]
    80020970	sll    v0, s2, $03
    80020974	addu   v0, v0, v1
    80020978	lb     a1, $0001(v0)
    8002097C	lb     v1, $0000(v0)
    80020980	j      L20990 [$80020990]
    80020984	nop

    L20988:	; 80020988
    80020988	addu   v1, zero, zero
    8002098C	addu   a1, zero, zero

    L20990:	; 80020990
    80020990	lw     v0, $003c(s0)
    80020994	nop
    80020998	andi   v0, v0, $0008
    8002099C	beq    v0, zero, L209a8 [$800209a8]
    800209A0	nop
    800209A4	subu   v1, zero, v1

    L209a8:	; 800209A8
    800209A8	lh     a0, $002c(s0)
    800209AC	nop
    800209B0	mult   a1, a0
    800209B4	mflo   v0
    800209B8	nop
    800209BC	bgez   v0, L209c8 [$800209c8]
    800209C0	mult   v1, a0
    800209C4	addiu  v0, v0, $0fff

    L209c8:	; 800209C8
    800209C8	sra    v0, v0, $0c
    800209CC	mflo   v1
    800209D0	bgez   v1, L209dc [$800209dc]
    800209D4	sll    a1, v0, $10
    800209D8	addiu  v1, v1, $0fff

    L209dc:	; 800209DC
    800209DC	lw     v0, $0008(s0)
    800209E0	sra    v1, v1, $0c
    800209E4	sw     v0, $0008(s3)
    800209E8	lw     v0, $0000(s0)
    800209EC	sll    v1, v1, $10
    800209F0	addu   v0, v1, v0
    800209F4	sw     v0, $0000(s3)
    800209F8	lw     v0, $0004(s0)
    800209FC	nop
    80020A00	addu   v0, a1, v0
    80020A04	j      L21900 [$80021900]
    80020A08	sw     v0, $0004(s3)
    80020A0C	addu   a0, s3, zero
    80020A10	jal    func1fa1c [$8001fa1c]
    80020A14	addu   a1, s1, zero
    80020A18	addu   a0, s3, zero
    80020A1C	addiu  a1, s1, $0001
    80020A20	jal    func1fa1c [$8001fa1c]
    80020A24	addu   s0, v0, zero
    80020A28	lbu    v1, $0000(s0)
    80020A2C	lbu    v0, $0000(v0)
    80020A30	nop
    80020A34	mult   v1, v0
    80020A38	mflo   v0
    80020A3C	j      L21900 [$80021900]
    80020A40	sb     v0, $0000(s0)
    80020A44	addu   a0, s3, zero
    80020A48	jal    func1fa1c [$8001fa1c]
    80020A4C	addu   a1, s1, zero
    80020A50	addu   a0, s3, zero
    80020A54	addiu  a1, s1, $0001
    80020A58	jal    func1fa1c [$8001fa1c]
    80020A5C	addu   s0, v0, zero
    80020A60	lbu    v1, $0000(s0)
    80020A64	lbu    v0, $0000(v0)
    80020A68	nop
    80020A6C	divu   v1, v0
    80020A70	mflo   v1
    80020A74	j      L21900 [$80021900]
    80020A78	sb     v1, $0000(s0)
    80020A7C	addu   a0, s3, zero
    80020A80	jal    func1fa1c [$8001fa1c]
    80020A84	addu   a1, s1, zero
    80020A88	jal    system_get_random_2_bytes [$8003f8b0]
    80020A8C	addu   s0, v0, zero
    80020A90	lbu    v1, $0001(s1)
    80020A94	andi   v0, v0, $00ff
    80020A98	mult   v0, v1
    80020A9C	mflo   v0
    80020AA0	sra    v0, v0, $08
    80020AA4	j      L21900 [$80021900]
    80020AA8	sb     v0, $0000(s0)
    80020AAC	addu   a0, s3, zero
    80020AB0	jal    func1fa1c [$8001fa1c]
    80020AB4	addu   a1, s1, zero
    80020AB8	lbu    v1, $0000(v0)
    80020ABC	lbu    a0, $0001(s1)
    80020AC0	nop
    80020AC4	addu   v1, v1, a0
    80020AC8	j      L21900 [$80021900]
    80020ACC	sb     v1, $0000(v0)
    80020AD0	addu   a0, s3, zero
    80020AD4	jal    func1fa1c [$8001fa1c]
    80020AD8	addu   a1, s1, zero
    80020ADC	lbu    a0, $0000(v0)
    80020AE0	lb     v1, $0001(s1)
    80020AE4	nop
    80020AE8	mult   a0, v1
    80020AEC	mflo   v1
    80020AF0	j      L21900 [$80021900]
    80020AF4	sb     v1, $0000(v0)
    80020AF8	addu   a0, s3, zero
    80020AFC	jal    func1fa1c [$8001fa1c]
    80020B00	addu   a1, s1, zero
    80020B04	lbu    v1, $0000(v0)
    80020B08	lb     a0, $0001(s1)
    80020B0C	nop
    80020B10	div    v1, a0
    80020B14	mflo   v1
    80020B18	j      L21900 [$80021900]
    80020B1C	sb     v1, $0000(v0)
    80020B20	addu   a0, s3, zero
    80020B24	jal    func1fa1c [$8001fa1c]
    80020B28	addu   a1, s1, zero
    80020B2C	lbu    v1, $0000(v0)
    80020B30	lb     a0, $0001(s1)
    80020B34	nop
    80020B38	sllv   v1, a0, v1
    80020B3C	j      L21900 [$80021900]
    80020B40	sb     v1, $0000(v0)
    80020B44	addu   a0, s3, zero
    80020B48	jal    func1fa1c [$8001fa1c]
    80020B4C	addu   a1, s1, zero
    80020B50	lb     v1, $0000(v0)
    80020B54	lb     a0, $0001(s1)
    80020B58	nop
    80020B5C	srav   v1, a0, v1
    80020B60	j      L21900 [$80021900]
    80020B64	sb     v1, $0000(v0)
    80020B68	addu   a0, s3, zero
    80020B6C	jal    func1fa1c [$8001fa1c]
    80020B70	addu   a1, s1, zero
    80020B74	lbu    v1, $0001(v0)
    80020B78	lbu    a0, $0000(v0)
    80020B7C	lb     a1, $0001(s1)
    80020B80	sll    v1, v1, $08
    80020B84	or     v1, v1, a0
    80020B88	j      L20bb4 [$80020bb4]
    80020B8C	sllv   v1, a1, v1
    80020B90	addu   a0, s3, zero
    80020B94	jal    func1fa1c [$8001fa1c]
    80020B98	addu   a1, s1, zero
    80020B9C	lbu    v1, $0001(v0)
    80020BA0	lbu    a0, $0000(v0)
    80020BA4	lb     a1, $0001(s1)
    80020BA8	sll    v1, v1, $08
    80020BAC	or     v1, v1, a0
    80020BB0	srav   v1, a1, v1

    L20bb4:	; 80020BB4
    80020BB4	sb     v1, $0000(v0)
    80020BB8	sra    v1, v1, $08
    80020BBC	j      L21900 [$80021900]
    80020BC0	sb     v1, $0001(v0)
    80020BC4	addu   a0, s3, zero
    80020BC8	jal    func1fa1c [$8001fa1c]
    80020BCC	addu   a1, s1, zero
    80020BD0	addu   a0, s3, zero
    80020BD4	addiu  a1, s1, $0001
    80020BD8	jal    func1fa1c [$8001fa1c]
    80020BDC	addu   s0, v0, zero
    80020BE0	lbu    v1, $0000(s0)
    80020BE4	lbu    v0, $0000(v0)
    80020BE8	nop
    80020BEC	addu   v1, v1, v0
    80020BF0	j      L21900 [$80021900]
    80020BF4	sb     v1, $0000(s0)
    80020BF8	lw     a0, $0074(s3)
    80020BFC	lb     a1, $0000(s1)
    80020C00	jal    func243e4 [$800243e4]
    80020C04	nop
    80020C08	j      L21900 [$80021900]
    80020C0C	nop
    80020C10	addu   a0, s3, zero
    80020C14	jal    func1fa1c [$8001fa1c]
    80020C18	addu   a1, s1, zero
    80020C1C	lbu    v1, $0001(s1)
    80020C20	j      L21900 [$80021900]
    80020C24	sb     v1, $0000(v0)
    80020C28	addu   a0, s3, zero
    80020C2C	jal    func1fa1c [$8001fa1c]
    80020C30	addu   a1, s1, zero
    80020C34	lbu    v1, $0001(s1)
    80020C38	sb     zero, $0001(v0)
    80020C3C	j      L21900 [$80021900]
    80020C40	sb     v1, $0000(v0)

    80020C70	lbu    v0, $0000(s1)
    80020C74	lhu    v1, $0030(s3)
    80020C78	sll    v0, v0, $18
    80020C7C	sra    v0, v0, $18
    80020C80	addu   v0, v0, v1
    80020C84	j      L21900 [$80021900]
    80020C88	sh     v0, $0030(s3)

    80020D94	lbu    a1, $0000(s1)
    80020D98	jal    func23114 [$80023114]
    80020D9C	addu   a0, s3, zero
    80020DA0	j      L21900 [$80021900]
    80020DA4	nop
    80020DA8	lbu    v0, $0000(s1)
    80020DAC	lw     a0, $0020(s3)
    80020DB0	sb     v0, $0028(s3)
    80020DB4	lbu    v0, $0001(s1)
    80020DB8	nop
    80020DBC	sb     v0, $0029(s3)
    80020DC0	lw     v0, $003c(s3)
    80020DC4	lbu    v1, $0002(s1)
    80020DC8	andi   v0, v0, $0003
    80020DCC	sb     v1, $002a(s3)
    80020DD0	ori    v1, zero, $0002
    80020DD4	bne    v0, v1, L20e00 [$80020e00]
    80020DD8	nop
    80020DDC	lbu    v0, $0000(s1)
    80020DE0	nop
    80020DE4	sh     v0, $0038(a0)
    80020DE8	lbu    v0, $0001(s1)
    80020DEC	nop
    80020DF0	sh     v0, $003a(a0)
    80020DF4	lbu    v0, $0002(s1)
    80020DF8	nop
    80020DFC	sh     v0, $003c(a0)

    L20e00:	; 80020E00
    80020E00	lw     v0, $003c(s3)
    80020E04	ori    v1, zero, $0001
    80020E08	andi   v0, v0, $0003
    80020E0C	bne    v0, v1, L21900 [$80021900]
    80020E10	nop
    80020E14	jal    func1f524 [$8001f524]
    80020E18	addu   a0, s3, zero
    80020E1C	j      L21900 [$80021900]
    80020E20	nop
    80020E24	lbu    a0, $0028(s3)
    80020E28	lb     a1, $0000(s1)
    80020E2C	lw     s0, $0020(s3)
    80020E30	jal    func21920 [$80021920]
    80020E34	nop

    L20e38:	; 80020E38
    80020E38	lbu    a0, $0029(s3)
    80020E3C	sb     v0, $0028(s3)
    80020E40	lb     a1, $0001(s1)
    80020E44	jal    func21920 [$80021920]
    80020E48	nop
    80020E4C	lbu    a0, $002a(s3)
    80020E50	sb     v0, $0029(s3)
    80020E54	lb     a1, $0002(s1)
    80020E58	jal    func21920 [$80021920]
    80020E5C	nop
    80020E60	lw     v1, $003c(s3)
    80020E64	sb     v0, $002a(s3)
    80020E68	ori    v0, zero, $0002
    80020E6C	andi   v1, v1, $0003
    80020E70	bne    v1, v0, L20ec0 [$80020ec0]
    80020E74	nop
    80020E78	lbu    v0, $0000(s1)
    80020E7C	lhu    v1, $0038(s0)
    80020E80	sll    v0, v0, $18
    80020E84	sra    v0, v0, $18
    80020E88	addu   v0, v0, v1
    80020E8C	sh     v0, $0038(s0)
    80020E90	lbu    v0, $0001(s1)
    80020E94	lhu    v1, $003a(s0)
    80020E98	sll    v0, v0, $18
    80020E9C	sra    v0, v0, $18
    80020EA0	addu   v0, v0, v1
    80020EA4	sh     v0, $003a(s0)
    80020EA8	lbu    v0, $0002(s1)
    80020EAC	lhu    v1, $003c(s0)
    80020EB0	sll    v0, v0, $18
    80020EB4	sra    v0, v0, $18
    80020EB8	addu   v0, v0, v1
    80020EBC	sh     v0, $003c(s0)

    L20ec0:	; 80020EC0
    80020EC0	lw     v0, $003c(s3)
    80020EC4	ori    v1, zero, $0001
    80020EC8	andi   v0, v0, $0003
    80020ECC	bne    v0, v1, L20ee0 [$80020ee0]
    80020ED0	lui    v1, $0001
    80020ED4	jal    func1f524 [$8001f524]
    80020ED8	addu   a0, s3, zero
    80020EDC	lui    v1, $0001

    L20ee0:	; 80020EE0
    80020EE0	lw     a0, $0040(s3)
    80020EE4	ori    v1, v1, $e000
    80020EE8	and    v0, a0, v1
    80020EEC	bne    v0, v1, L21900 [$80021900]
    80020EF0	nop
    80020EF4	lw     v1, $0020(s3)
    80020EF8	nop
    80020EFC	lw     v0, $0034(v1)
    80020F00	nop
    80020F04	beq    v0, zero, L21900 [$80021900]
    80020F08	andi   v0, a0, $0002
    80020F0C	bne    v0, zero, L21900 [$80021900]
    80020F10	nop
    80020F14	lh     v0, $003a(s0)
    80020F18	lh     a3, $0038(s0)
    80020F1C	sw     v0, $0010(sp)
    80020F20	lh     v0, $003c(s0)
    80020F24	nop
    80020F28	sw     v0, $0014(sp)
    80020F2C	lw     a0, $0034(v1)
    80020F30	lw     a1, $002c(v1)
    80020F34	lw     a2, $0030(v1)
    80020F38	jal    funcb1fa8 [$800b1fa8]
    80020F3C	nop
    80020F40	j      L21900 [$80021900]
    80020F44	nop

    80020F98	ori    a0, zero, $0005
    80020F9C	jal    func322bc [$800322bc]
    80020FA0	addu   a1, zero, zero
    80020FA4	lb     a0, $0002(s1)
    80020FA8	lbu    v0, $0001(s1)
    80020FAC	lbu    v1, $0000(s1)
    80020FB0	sll    a0, a0, $10
    80020FB4	sll    v0, v0, $08
    80020FB8	addu   a0, a0, v0
    80020FBC	addu   a0, a0, v1
    80020FC0	addu   a0, a0, s1
    80020FC4	jal    func2c3ac [$8002c3ac]
    80020FC8	addu   s0, a0, zero
    80020FCC	lw     v0, $0020(s3)
    80020FD0	nop
    80020FD4	lw     a0, $002c(v0)
    80020FD8	nop
    if( A0 != 0 )
    {
        system_memory_free();
    }

    80020FEC	lw     a2, $0020(s3)
    80020FF0	addu   a0, s0, zero
    80020FF4	addiu  a1, a2, $002c
    80020FF8	jal    system_allocate_memory_for_packets [$8002c964]
    80020FFC	addiu  a2, a2, $0030
    80021000	lw     v0, $0020(s3)
    80021004	addu   a0, s0, zero
    80021008	lw     a1, $002c(v0)
    8002100C	jal    system_fill_packets_drafts_for_model_part [$8002c6dc]
    80021010	addu   a2, zero, zero
    80021014	lw     v0, $0020(s3)
    80021018	lw     a2, $0034(s0)
    8002101C	lw     a0, $0030(v0)
    80021020	lw     a1, $002c(v0)
    80021024	jal    system_memcpy [$8003f810]
    80021028	nop
    8002102C	lw     v0, $0020(s3)
    80021030	j      L21900 [$80021900]
    80021034	sw     s0, $0034(v0)
    80021038	ori    a0, zero, $0005
    8002103C	jal    func322bc [$800322bc]
    80021040	addu   a1, zero, zero
    80021044	lb     v0, $0002(s1)
    80021048	lbu    v1, $0001(s1)
    8002104C	lbu    a0, $0000(s1)
    80021050	sll    v0, v0, $10
    80021054	sll    v1, v1, $08
    80021058	addu   v0, v0, v1
    8002105C	addu   v0, v0, a0
    80021060	addu   s0, v0, s1
    80021064	jal    func2c1f8 [$8002c1f8]
    80021068	addu   a0, s0, zero
    8002106C	lw     v0, $0020(s3)
    80021070	nop
    80021074	lw     a0, $002c(v0)
    80021078	nop
    80021080	addiu  s1, s0, $0010
    if( A0 != 0 )
    {
        system_memory_free();
    }

    8002108C	lw     a2, $0020(s3)
    80021090	addu   a0, s1, zero
    80021094	addiu  a1, a2, $002c
    80021098	jal    system_allocate_memory_for_packets [$8002c964]
    8002109C	addiu  a2, a2, $0030
    800210A0	lw     v0, $0020(s3)
    800210A4	addu   a0, s1, zero
    800210A8	lw     a1, $002c(v0)
    800210AC	jal    system_fill_packets_drafts_for_model_part [$8002c6dc]
    800210B0	addu   a2, zero, zero
    800210B4	lw     v0, $0020(s3)
    800210B8	lw     a2, $0044(s0)
    800210BC	lw     a0, $0030(v0)
    800210C0	lw     a1, $002c(v0)
    800210C4	jal    system_memcpy [$8003f810]
    800210C8	nop
    800210CC	j      L21168 [$80021168]
    800210D0	nop
    800210D4	lb     v0, $0002(s1)
    800210D8	lbu    v1, $0001(s1)
    800210DC	lbu    a0, $0000(s1)
    800210E0	sll    v0, v0, $10
    800210E4	sll    v1, v1, $08
    800210E8	addu   v0, v0, v1
    800210EC	addu   v0, v0, a0
    800210F0	addu   s0, v0, s1
    800210F4	jal    func2c1f8 [$8002c1f8]
    800210F8	addu   a0, s0, zero
    800210FC	lw     v0, $0020(s3)
    80021100	nop
    80021104	lw     a0, $002c(v0)
    80021108	nop
    80021110	addiu  s1, s0, $0010
    if( A0 != 0 )
    {
        system_memory_free();
    }

    8002111C	lw     a2, $0020(s3)
    80021120	addu   a0, s1, zero
    80021124	addiu  a1, a2, $002c
    80021128	jal    system_allocate_memory_for_packets [$8002c964]
    8002112C	addiu  a2, a2, $0030
    80021130	lw     v0, $0020(s3)
    80021134	addu   a0, s1, zero
    80021138	lw     a1, $002c(v0)
    8002113C	jal    system_fill_packets_drafts_for_model_part [$8002c6dc]
    80021140	addu   a2, zero, zero
    80021144	lw     v0, $0020(s3)
    80021148	lw     a2, $0044(s0)
    8002114C	lw     a0, $0030(v0)
    80021150	lw     a1, $002c(v0)
    80021154	jal    system_memcpy [$8003f810]
    80021158	nop
    8002115C	lw     v0, $0010(s2)
    80021160	nop
    80021164	sw     zero, $0004(v0)

    L21168:	; 80021168
    80021168	lw     v0, $0020(s3)
    8002116C	j      L21900 [$80021900]
    80021170	sw     s1, $0034(v0)

    8002119C	addu   a0, s3, zero
    800211A0	lbu    v0, $0001(s1)
    800211A4	lbu    a1, $0000(s1)
    800211A8	sll    v0, v0, $18
    800211AC	sra    v0, v0, $10
    800211B0	or     a1, a1, v0
    800211B4	sll    a1, a1, $11
    800211B8	lh     v0, $002c(a0)
    800211BC	sra    a1, a1, $10
    800211C0	jal    func21e60 [$80021e60]
    800211C4	addu   a1, v0, a1
    800211C8	j      L21900 [$80021900]
    800211CC	nop
    800211D0	lbu    v0, $0001(s1)
    800211D4	lbu    v1, $0000(s1)
    800211D8	lw     a0, $0020(s3)
    800211DC	sll    v0, v0, $18
    800211E0	sra    v0, v0, $10
    800211E4	or     v1, v1, v0
    800211E8	beq    a0, zero, L21900 [$80021900]
    800211EC	sll    v1, v1, $01
    800211F0	lhu    v0, $0006(a0)
    800211F4	nop
    800211F8	addu   v0, v1, v0
    800211FC	j      L21400 [$80021400]
    80021200	sh     v0, $0006(a0)
    80021204	lbu    v0, $0001(s1)
    80021208	lbu    v1, $0000(s1)
    8002120C	lw     a0, $0020(s3)
    80021210	sll    v0, v0, $18
    80021214	sra    v0, v0, $10
    80021218	or     v1, v1, v0
    8002121C	beq    a0, zero, L21900 [$80021900]
    80021220	sll    v1, v1, $01
    80021224	lhu    v0, $0008(a0)
    80021228	nop
    8002122C	addu   v0, v1, v0
    80021230	j      L21400 [$80021400]
    80021234	sh     v0, $0008(a0)
    80021238	lbu    v0, $0001(s1)
    8002123C	lbu    v1, $0000(s1)
    80021240	lw     a0, $0020(s3)
    80021244	sll    v0, v0, $18
    80021248	sra    v0, v0, $10
    8002124C	or     v1, v1, v0
    80021250	beq    a0, zero, L21900 [$80021900]
    80021254	sll    v1, v1, $01
    80021258	lhu    v0, $000a(a0)
    8002125C	nop
    80021260	addu   v0, v1, v0
    80021264	j      L21400 [$80021400]
    80021268	sh     v0, $000a(a0)
    8002126C	addu   a0, s3, zero
    80021270	lbu    v0, $0000(s1)
    80021274	lui    v1, $8007
    80021278	lw     v1, $b4b0(v1)
    8002127C	lui    a1, $8007
    80021280	lw     a1, $b4b0(a1)
    80021284	sll    v0, v0, $01
    80021288	addu   v0, v0, v1
    8002128C	lhu    v0, $0002(v0)
    80021290	lw     a2, $0024(a0)
    80021294	jal    func239f4 [$800239f4]
    80021298	addu   a1, v0, a1
    8002129C	j      L21900 [$80021900]
    800212A0	nop
    800212A4	addu   a0, s3, zero
    800212A8	lw     a2, $0024(a0)
    800212AC	lb     a1, $0001(s1)
    800212B0	lbu    v0, $0000(s1)
    800212B4	sll    a1, a1, $08
    800212B8	addu   a1, a1, v0
    800212BC	jal    func239f4 [$800239f4]
    800212C0	addu   a1, s1, a1
    800212C4	j      L21900 [$80021900]
    800212C8	nop
    800212CC	addiu  a0, zero, $f801 (=-$7ff)
    800212D0	lw     v1, $00a8(s3)
    800212D4	lbu    v0, $0000(s1)
    800212D8	and    v1, v1, a0
    800212E0	sll    v0, v0, $01
            [struct_164 + a8] = w(V1 | V0);
            return;


    800212F8	lb     v1, $0000(s1)
    800212FC	lbu    v0, $008c(s3)
    80021300	nop
    80021304	subu   v0, v0, v1
    80021308	j      L21900 [$80021900]
    8002130C	sb     v0, $008c(s3)

    80021338	lb     v1, $0000(s1)
    8002133C	lw     v0, $00ac(s3)
    80021340	nop
    80021344	andi   v0, v0, $0010
    80021348	beq    v0, zero, L21354 [$80021354]
    8002134C	sll    v1, v1, $04
    80021350	subu   v1, zero, v1

    L21354:	; 80021354
    80021354	lw     a0, $0020(s3)
    80021358	nop
    8002135C	beq    a0, zero, L21900 [$80021900]
    80021360	nop
    80021364	lhu    v0, $0004(a0)
    80021368	nop
    8002136C	addu   v0, v0, v1
    80021370	j      L21400 [$80021400]
    80021374	sh     v0, $0004(a0)
    80021378	lw     a0, $0020(s3)
    8002137C	nop
    80021380	beq    a0, zero, L21900 [$80021900]
    80021384	nop
    80021388	lbu    v0, $0000(s1)
    8002138C	lhu    v1, $0000(a0)
    80021390	sll    v0, v0, $18
    80021394	sra    v0, v0, $14
    80021398	addu   v1, v1, v0
    8002139C	j      L21400 [$80021400]
    800213A0	sh     v1, $0000(a0)
    800213A4	lw     a0, $0020(s3)
    800213A8	nop
    800213AC	beq    a0, zero, L21900 [$80021900]
    800213B0	nop
    800213B4	lbu    v0, $0000(s1)
    800213B8	lhu    v1, $0002(a0)
    800213BC	sll    v0, v0, $18
    800213C0	sra    v0, v0, $14
    800213C4	addu   v1, v1, v0
    800213C8	j      L21400 [$80021400]
    800213CC	sh     v1, $0002(a0)
    800213D0	lb     v1, $0000(s1)
    800213D4	lw     v0, $00ac(s3)
    800213D8	nop
    800213DC	andi   v0, v0, $0010
    800213E0	beq    v0, zero, L213ec [$800213ec]
    800213E4	sll    v1, v1, $04
    800213E8	subu   v1, zero, v1

    L213ec:	; 800213EC
    800213EC	lw     v0, $0020(s3)
    800213F0	nop
    800213F4	beq    v0, zero, L21900 [$80021900]
    800213F8	nop
    800213FC	sh     v1, $0004(v0)

    L21400:	; 80021400
    [S3 + 3c] = w(w[S3 + 3c] | 10000000);

    8002140C	j      L21900 [$80021900]

    80021414	jal    system_get_random_2_bytes [$8003f8b0]
    80021418	nop
    8002141C	lbu    v1, $0000(s1)
    80021420	andi   v0, v0, $00ff
    80021424	mult   v0, v1
    80021428	mflo   a3
    8002142C	bgez   a3, L21438 [$80021438]
    80021430	srl    v0, v1, $01
    80021434	addiu  a3, a3, $00ff

    L21438:	; 80021438
    80021438	sra    a3, a3, $08
    8002143C	subu   a3, a3, v0
    80021440	addiu  a0, sp, $0018
    80021444	addu   a1, zero, zero
    80021448	addu   a2, zero, zero
    8002144C	sll    a3, a3, $14
    80021450	jal    func2194c [$8002194c]
    80021454	sra    a3, a3, $10
    80021458	addiu  a0, sp, $0018
    8002145C	addiu  s0, sp, $0038
    80021460	jal    system_calculate_rotation_matrix [$8003f5e0]
    80021464	addu   a1, s0, zero
    80021468	addu   a0, s0, zero
    8002146C	addiu  a1, s3, $000c
    80021470	jal    system_gte_apply_matrix_lv [$80049324]
    80021474	addiu  a2, sp, $0020
    80021478	lw     v0, $0020(sp)
    8002147C	nop
    80021480	sw     v0, $000c(s3)
    80021484	lw     v0, $0024(sp)
    80021488	nop
    8002148C	sw     v0, $0010(s3)
    80021490	lw     v0, $0028(sp)
    80021494	j      L21900 [$80021900]
    80021498	sw     v0, $0014(s3)
    8002149C	jal    system_get_random_2_bytes [$8003f8b0]
    800214A0	nop
    800214A4	lbu    v1, $0000(s1)
    800214A8	andi   v0, v0, $00ff
    800214AC	mult   v0, v1
    800214B0	mflo   v0
    800214B4	bgez   v0, L214c0 [$800214c0]
    800214B8	srl    v1, v1, $01
    800214BC	addiu  v0, v0, $00ff

    L214c0:	; 800214C0
    800214C0	sra    v0, v0, $08
    800214C4	subu   v0, v0, v1
    800214C8	sll    v0, v0, $04
    800214CC	lhu    a1, $0032(s3)
    800214D0	addu   a0, s3, zero
    800214D4	addu   a1, a1, v0
    800214D8	sll    a1, a1, $10
    800214DC	jal    func21e40 [$80021e40]
    800214E0	sra    a1, a1, $10
    800214E4	j      L21900 [$80021900]
    800214E8	nop
    800214EC	lb     v1, $0000(s1)
    800214F0	lh     v0, $002c(s3)
    800214F4	nop
    800214F8	mult   v1, v0
    800214FC	mflo   a1
    80021500	bgez   a1, L2150c [$8002150c]
    80021504	addu   a0, s3, zero
    80021508	addiu  a1, a1, $0fff

    L2150c:	; 8002150C
    8002150C	jal    func22b34 [$80022b34]
    80021510	sra    a1, a1, $0c
    80021514	lw     v1, $00ac(s3)
    80021518	nop
    8002151C	andi   v1, v1, $0010
    80021520	beq    v1, zero, L2152c [$8002152c]
    80021524	sll    a0, v0, $10
    80021528	subu   a0, zero, a0

    L2152c:	; 8002152C
    8002152C	lw     v0, $0000(s3)
    80021530	nop
    80021534	addu   v0, a0, v0
    80021538	j      L21900 [$80021900]
    8002153C	sw     v0, $0000(s3)
    80021540	lb     v1, $0000(s1)
    80021544	lh     v0, $002c(s3)
    80021548	nop
    8002154C	mult   v1, v0
    80021550	mflo   a1
    80021554	bgez   a1, L21560 [$80021560]
    80021558	addu   a0, s3, zero
    8002155C	addiu  a1, a1, $0fff

    L21560:	; 80021560
    80021560	jal    func22b34 [$80022b34]
    80021564	sra    a1, a1, $0c
    80021568	lw     v1, $0004(s3)
    8002156C	sll    v0, v0, $10
    80021570	addu   v0, v0, v1
    80021574	j      L21900 [$80021900]
    80021578	sw     v0, $0004(s3)
    8002157C	lb     v1, $0000(s1)
    80021580	lh     v0, $002c(s3)
    80021584	nop
    80021588	mult   v1, v0
    8002158C	mflo   a1
    80021590	bgez   a1, L2159c [$8002159c]
    80021594	addu   a0, s3, zero
    80021598	addiu  a1, a1, $0fff

    L2159c:	; 8002159C
    8002159C	jal    func22b34 [$80022b34]
    800215A0	sra    a1, a1, $0c
    800215A4	lw     v1, $0008(s3)
    800215A8	sll    v0, v0, $10
    800215AC	j      L218fc [$800218fc]
    800215B0	addu   v0, v0, v1
    800215B4	addu   a0, s3, zero
    800215B8	lbu    v1, $0000(s1)
    800215BC	lhu    v0, $0032(a0)
    800215C0	sll    v1, v1, $18
    800215C4	sra    v1, v1, $14
    800215C8	addu   v0, v0, v1
    800215CC	jal    func22800 [$80022800]
    800215D0	sh     v0, $0032(a0)
    800215D4	j      L21900 [$80021900]
    800215D8	nop

    800215EC	lw     v0, $00a8(s3)
    800215F0	nop
    800215F4	andi   v0, v0, $0001
    800215F8	beq    v0, zero, L21620 [$80021620]
    800215FC	nop
    80021600	lw     v0, $007c(s3)
    80021604	nop
    80021608	lw     v0, $0004(v0)
    8002160C	nop
    80021610	beq    v0, zero, L21620 [$80021620]
    80021614	nop
    80021618	j      L21900 [$80021900]
    8002161C	sw     v0, $001c(s3)

    L21620:	; 80021620
    80021620	lb     v0, $0000(s1)
    80021624	lh     v1, $0082(s3)
    80021628	sll    v0, v0, $06
    8002162C	mult   v0, v1
    80021630	mflo   a0
    80021634	bgez   a0, L21640 [$80021640]
    80021638	lui    v0, $0001
    8002163C	addiu  a0, a0, $0fff

    L21640:	; 80021640
    80021640	lw     v1, $00ac(s3)
    80021644	nop
    80021648	srl    v1, v1, $09
    8002164C	andi   v1, v1, $0fff
    80021650	div    v0, v1
    80021654	mflo   v0
    80021658	nop
    8002165C	nop
    80021660	mult   v0, v0
    80021664	sra    v0, a0, $0c
    80021668	sll    v1, v0, $05
    8002166C	mflo   v0
    80021670	bgez   v0, L2167c [$8002167c]
    80021674	sw     v1, $001c(s3)
    80021678	addiu  v0, v0, $00ff

    L2167c:	; 8002167C
    8002167C	sra    v0, v0, $08
    80021680	mult   v0, v1
    80021684	mflo   v0
    80021688	addu   a0, v0, zero
    8002168C	bgez   a0, L21698 [$80021698]
    80021690	sw     v0, $001c(s3)
    80021694	addiu  a0, a0, $00ff

    L21698:	; 80021698
    80021698	lui    v0, $8006
    8002169C	lw     v0, $8838(v0)
    800216A0	nop
    800216A4	addiu  v0, v0, $0001
    800216A8	mult   v0, v0
    800216AC	mflo   v1
    800216B0	sra    v0, a0, $08
    800216B4	nop
    800216B8	mult   v1, v0
    800216BC	sw     v0, $001c(s3)
    800216C0	mflo   v0
    800216C4	j      L21900 [$80021900]
    800216C8	sw     v0, $001c(s3)
    800216CC	lb     v1, $0000(s1)
    800216D0	lui    v0, $8006
    800216D4	lw     v0, $8838(v0)
    800216D8	sll    v1, v1, $04
    800216DC	addiu  v0, v0, $0001
    800216E0	mult   v1, v0
    800216E4	mflo   v1
    800216E8	lh     v0, $0082(s3)
    800216EC	nop
    800216F0	mult   v1, v0
    800216F4	mflo   v0
    800216F8	bgez   v0, L21704 [$80021704]
    800216FC	addu   a0, s3, zero
    80021700	addiu  v0, v0, $0fff

    L21704:	; 80021704
    80021704	sra    v0, v0, $0c
    80021708	lw     v1, $0018(a0)
    8002170C	sll    v0, v0, $08
    80021710	addu   v0, v0, v1
    80021714	jal    func22800 [$80022800]
    80021718	sw     v0, $0018(a0)
    8002171C	j      L21900 [$80021900]
    80021720	nop
    80021724	lw     v0, $00a8(s3)
    80021728	nop
    8002172C	andi   v0, v0, $0001
    80021730	bne    v0, zero, L21900 [$80021900]
    80021734	nop
    80021738	lb     v1, $0000(s1)
    8002173C	lui    v0, $8006
    80021740	lw     v0, $8838(v0)
    80021744	sll    v1, v1, $04
    80021748	addiu  v0, v0, $0001
    8002174C	mult   v1, v0
    80021750	mflo   v1
    80021754	lh     v0, $0082(s3)
    80021758	nop
    8002175C	mult   v1, v0
    80021760	mflo   v1
    80021764	bgez   v1, L21770 [$80021770]
    80021768	nop
    8002176C	addiu  v1, v1, $0fff

    L21770:	; 80021770
    80021770	sra    v1, v1, $0c
    80021774	lw     v0, $00ac(s3)
    80021778	sll    v1, v1, $10
    8002177C	srl    v0, v0, $09
    80021780	andi   v0, v0, $0fff
    80021784	div    v1, v0
    80021788	mflo   v1
    8002178C	lw     v0, $0010(s3)
    80021790	nop
    80021794	addu   v1, v1, v0
    80021798	j      L21900 [$80021900]
    8002179C	sw     v1, $0010(s3)

    800217F4	lw     v0, $00a8(s3)
    800217F8	nop
    800217FC	andi   v0, v0, $0001
    80021800	beq    v0, zero, L21820 [$80021820]
    80021804	nop
    80021808	lw     v0, $007c(s3)
    8002180C	nop
    80021810	lw     v0, $0000(v0)
    80021814	nop
    80021818	bne    v0, zero, L21860 [$80021860]
    8002181C	nop

    L21820:	; 80021820
    80021820	lb     v1, $0000(s1)
    80021824	lui    v0, $8006
    80021828	lw     v0, $8838(v0)
    8002182C	sll    v1, v1, $04
    80021830	addiu  v0, v0, $0001
    80021834	mult   v1, v0
    80021838	mflo   v1
    8002183C	lh     v0, $0082(s3)
    80021840	nop
    80021844	mult   v1, v0
    80021848	mflo   v0
    8002184C	bgez   v0, L21858 [$80021858]
    80021850	nop
    80021854	addiu  v0, v0, $0fff

    L21858:	; 80021858
    80021858	sra    v0, v0, $0c
    8002185C	sll    v0, v0, $08

    L21860:	; 80021860
    80021860	sw     v0, $0010(s3)
    80021864	lw     v0, $0010(s3)
    80021868	lw     v1, $00ac(s3)
    8002186C	sll    v0, v0, $08
    80021870	srl    v1, v1, $09
    80021874	andi   v1, v1, $0fff
    80021878	div    v0, v1
    8002187C	mflo   v1
    80021880	sw     v0, $0010(s3)
    80021884	j      L21900 [$80021900]
    80021888	sw     v1, $0010(s3)
    8002188C	lb     v1, $0001(s1)
    80021890	lbu    v0, $0000(s1)
    80021894	sll    v1, v1, $08
    80021898	or     v0, v0, v1
    8002189C	sll    v0, v0, $10
    800218A0	j      L21900 [$80021900]
    800218A4	sw     v0, $0000(s3)
    800218A8	lb     v0, $0001(s1)
    800218AC	lbu    v1, $0000(s1)
    800218B0	lh     a0, $002c(s3)
    800218B4	sll    v0, v0, $08
    800218B8	or     v1, v1, v0
    800218BC	mult   v1, a0
    800218C0	lh     v1, $0084(s3)
    800218C4	mflo   v0
    800218C8	bgez   v0, L218d4 [$800218d4]
    800218CC	nop
    800218D0	addiu  v0, v0, $0fff

    L218d4:	; 800218D4
    800218D4	sra    v0, v0, $0c
    800218D8	addu   v0, v1, v0
    800218DC	sll    v0, v0, $10
    800218E0	j      L21900 [$80021900]
    800218E4	sw     v0, $0004(s3)
    800218E8	lb     v1, $0001(s1)
    800218EC	lbu    v0, $0000(s1)
    800218F0	sll    v1, v1, $08
    800218F4	or     v0, v0, v1
    800218F8	sll    v0, v0, $10

    L218fc:	; 800218FC
    800218FC	sw     v0, $0008(s3)

        default: // 8b 8e 8f 95 97 98 99 9a 9b 9c 9d 9e 9f b1 b2 be c2 c3 c7 c8 ca cb d4 e1 e2 e3 e4 e8 ec ee f3 f4 f8 f9 fa fb fd fe ff
        {
            return;
        }
}

L21900:	; 80021900
return;
////////////////////////////////