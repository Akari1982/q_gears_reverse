////////////////////////////////
// field_init_debug_with_default()

A0 = 5; // id
A1 = 6c; // x
A2 = 0; // y
A3 = 6c; // width
A4 = 52; // height
field_init_debug_by_id();

A0 = 800e4254;
A1 = 800a12a8; // "Authr:"
field_copy_string();

A0 = 800e4254;
A1 = w[8009c6dc] + 10;
field_concat_string();

A0 = 5;
A1 = 800e4254;
field_add_string_to_debug_by_id();

A0 = 800e4254;
A1 = 800a12b0; // "Event:"
field_copy_string();

A0 = 800e4254;
A1 = w[8009c6dc] + 18;
field_concat_string();

A0 = 5;
A1 = 800e4254;
field_add_string_to_debug_by_id();

A0 = 5;
A1 = 800a12b8; // "  Go"
field_add_string_to_debug_by_id();

A0 = 5;
A1 = 800a12c0; // "  Stop"
field_add_string_to_debug_by_id();

A0 = 5;
A1 = 800a12c8; // "  Step"
field_add_string_to_debug_by_id();

A0 = 5; // id
A1 = 5; // sub id
A2 = 800a12d0; // "  Actor OFF"
field_copy_into_debug_by_id();

A0 = 5;
A1 = 6; // sub id
A2 = 800a12dc; // "  Info  OFF"
field_copy_into_debug_by_id();

A0 = 5;
funcda2cc();

A0 = 4;
A1 = 6c;
A2 = 52;
A3 = 6c;
A4 = 52;
field_init_debug_by_id();

A0 = 4;
A1 = 800e0628; // "Actor:"
field_add_string_to_debug_by_id();

A0 = 4;
funcda2cc();

A0 = 3;
A1 = 6c;
A2 = a4;
A3 = 6c;
V0 = 5c;
A4 = V0;
field_init_debug_by_id();

A0 = 3;
A1 = 800e0630; // "Word:"
field_add_string_to_debug_by_id();

A0 = 3;
funcda2cc();

A0 = 1;
A1 = 0;
A2 = 0;
A3 = 6c;
A4 = ca;
field_init_debug_by_id();

A0 = 1;
A1 = 800e0628; // "Actor:"
field_add_string_to_debug_by_id();

A0 = 1;
funcda2cc();

[80099ffc] = b(3);
[8007ebcc] = b(4);
[8007ebdc] = b(8);
[80071e24] = b(0);
[8009d820] = b(0);
[80070788] = b(0);
[80071c08] = b(5);

A0 = 5;
A1 = 4;
funcda1d4();
////////////////////////////////



////////////////////////////////
// funcd8194

T0 = A0;
T1 = A1;
T2 = A2;
A1 = A3;
A0 = 0;
A3 = A3 << 10;
A3 = A3 >> 10;
V0 = A0 << 10;

loopd81c0:	; 800D81C0
S0 = V0 >> 10;
V1 = S0 << 01;
V1 = V1 + S0;
V0 = V1 << 06;
V0 = V0 - V1;
V0 = V0 << 01;
800D81D8	lui    at, $800e
AT = AT + 08c0;
AT = AT + V0;
V0 = bu[AT + 0000];
800D81E8	nop
800D81EC	beq    v0, zero, Ld8228 [$800d8228]
V0 = A0 + 0001;
[SP + 0010] = w(A3);
A0 = S0;
A1 = T0 << 10;
A1 = A1 >> 10;
A2 = T1 << 10;
A2 = A2 >> 10;
A3 = T2 << 10;
800D8210	jal    funcd8334 [$800d8334]
A3 = A3 >> 10;
800D8218	jal    funcd84cc [$800d84cc]
A0 = S0;
800D8220	j      Ld8278 [$800d8278]
V0 = S0;

Ld8228:	; 800D8228
A0 = V0;
V0 = V0 << 10;
V0 = V0 >> 10;
V0 = V0 < 0006;
800D8238	bne    v0, zero, loopd81c0 [$800d81c0]
V0 = A0 << 10;
V0 = A1 << 10;
V0 = V0 >> 10;
[SP + 0010] = w(V0);
A0 = 0;
A1 = T0 << 10;
A1 = A1 >> 10;
A2 = T1 << 10;
A2 = A2 >> 10;
A3 = T2 << 10;
800D8264	jal    funcd8334 [$800d8334]
A3 = A3 >> 10;
800D826C	jal    funcd84cc [$800d84cc]
A0 = 0;
V0 = 0;

Ld8278:	; 800D8278
////////////////////////////////



////////////////////////////////
// field_init_debug_by_id()

id = A0;

A0 = id;
A1 = A1;
A2 = A2;
A3 = A3;
A4 = A4;
funcd8334();

if( bu[800e0848 + id * 17a + 78] != 2 )
{
    A0 = id;
    funcd84cc();
}
else
{
    [800e0848 + id * 17a + 78] = b(0);
    [8009d824] = b(1);
}
////////////////////////////////



////////////////////////////////
// funcd8334()

[800e0748 + A0 * 17a + 0] = h(A1);
[800e0748 + A0 * 17a + 2] = h(A2);
[800e0748 + A0 * 17a + 4] = h(A3);
[800e0748 + A0 * 17a + 6] = h(A4);
[8009d824] = b(1);
////////////////////////////////



////////////////////////////////
// funcd83a8()

V0 = 0001;
V1 = A0 << 01;
V1 = V1 + A0;
[8009d824] = b(V0);
V0 = V1 << 06;
V0 = V0 - V1;
V0 = V0 << 01;
800D83D0	lui    at, $800e
AT = AT + 0748;
AT = AT + V0;
V1 = hu[AT + 0000];
800D83E0	lui    at, $800e
AT = AT + 074a;
AT = AT + V0;
A0 = hu[AT + 0000];
V1 = V1 + A1;
A0 = A0 + A2;
800D83F8	lui    at, $800e
AT = AT + 0748;
AT = AT + V0;
[AT + 0000] = h(V1);
800D8408	lui    at, $800e
AT = AT + 074a;
AT = AT + V0;
[AT + 0000] = h(A0);
////////////////////////////////



////////////////////////////////
// funcd8420
800D8420

V0 = 0001;
A0 = A0 << 10;
A0 = A0 >> 10;
V1 = A0 << 01;
V1 = V1 + A0;
[8009d824] = b(V0);
V0 = V1 << 06;
V0 = V0 - V1;
V0 = V0 << 01;
800D8448	lui    at, $800e
AT = AT + 074c;
AT = AT + V0;
V1 = hu[AT + 0000];
800D8458	lui    at, $800e
AT = AT + 074e;
AT = AT + V0;
A0 = hu[AT + 0000];
V1 = V1 + A1;
A0 = A0 + A2;
800D8470	lui    at, $800e
AT = AT + 074c;
AT = AT + V0;
[AT + 0000] = h(V1);
800D8480	lui    at, $800e
AT = AT + 074e;
AT = AT + V0;
[AT + 0000] = h(A0);
800D8490	jr     ra 
800D8494	nop
////////////////////////////////



////////////////////////////////
// funcd8498
800D8498
A0 = A0 << 10;
A0 = A0 >> 10;
V1 = A0 << 01;
V1 = V1 + A0;
V0 = V1 << 06;
V0 = V0 - V1;
V0 = V0 << 01;
800D84B4	lui    at, $800e
AT = AT + 08c0;
AT = AT + V0;
V0 = bu[AT + 0000];
800D84C4	jr     ra 
V0 = V0 < 0001;
800D84C8
////////////////////////////////



////////////////////////////////
// funcd84cc()

for( int i = 0; i < 18; ++i )
{
    [800e0748 + A0 * 17a + i * e + 10] = b(0);
    [800e0748 + A0 * 17a + 160 + i] = b(0);
}

[800e0748 + A0 * 17a + 8] = b(7);
[800e0748 + A0 * 17a + 9] = b(f);
[800e0748 + A0 * 17a + a] = b(1f);
[800e0748 + A0 * 17a + c] = h(0);
[800e0748 + A0 * 17a + e] = h(0);
[800e0748 + A0 * 17a + 78] = b(0);
[8009d824] = b(1);
////////////////////////////////



////////////////////////////////
// funcd85c0
800D85C0
V0 = hu[800e1024];
[800e41b8] = h(0);
[800e41c0] = h(0);
[800e41bc] = h(0);
[800e41c4] = h(0);
V0 = V0 ^ 0001;
[800e1024] = h(V0);
800D85F4	jr     ra 
800D85F8	nop
////////////////////////////////



////////////////////////////////
// funcd85fc()

V0 = bu[8009d824];

S2 = A0;
if( V0 != 0 )
{
    800D8620	jal    funcd85c0 [$800d85c0]
    S0 = 0;
    V0 = h[800e1024];
    A1 = 0007;
    A0 = V0 << 03;
    A0 = A0 - V0;
    A0 = A0 << 02;
    V0 = 800e41c8;
    A0 = A0 + V0;
    800D864C	jal    $8004418c

    S1 = 0;
    loopd8654:	; 800D8654
        if( bu[800e08c0 + S1] == 0 )
        {
            A0 = S0;
            funcd8710();
        }

        S1 = S1 + 17a;
        S0 = S0 + 1;
        V0 = S0 < 6;
    800D8684	bne    v0, zero, loopd8654 [$800d8654]

    [8009d824] = b(0);
}

A3 = 00ffffff;
A1 = 800e41e0;
V0 = h[800e1024];
800D86AC	lui    t0, $ff00
A0 = V0 << 03;
A0 = A0 - V0;
A0 = A0 << 02;
A2 = A0 + A1;
800D86C0	addiu  a1, a1, $ffe8 (=-$18)
A0 = A0 + A1;
V1 = w[A2 + 0000];
V0 = w[S2 + 0000];
V1 = V1 & T0;
V0 = V0 & A3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = w[S2 + 0000];
A0 = A0 & A3;
V0 = V0 & T0;
[S2] = w(V0 | A0);
////////////////////////////////



////////////////////////////////
// funcd8710()

V0 = h[800e41bc];
S5 = A0;
V0 = V0 < 0018;
800D873C	beq    v0, zero, Ld9bdc [$800d9bdc]

A1 = A0;
A0 = A0 * 17a;
S1 = 0;
V1 = h[800e0748 + A0 + 2];
S0 = A0;
V0 = V1 + 0002;
S2 = V0;
A2 = V0;
S3 = 800e0758 + S0;
V1 = V1 << 10;
V0 = h[800e0748 + S0 + 6];
V1 = V1 >> 10;
V1 = V1 + V0;
800D87B0	addiu  v1, v1, $fff8 (=-$8)
V1 = A2 < V1;
800D87B8	beq    v1, zero, Ld8840 [$800d8840]
S4 = A1;
A1 = S1 << 10;

loopd87c4:	; 800D87C4
S1 = S1 + 0001;
A3 = h[800e0748 + S0];
A1 = A1 >> 10;
[SP + 10] = w(A2);
A2 = A1 << 03;
A2 = A2 - A1;
A2 = A2 << 01;
A0 = S4;
A2 = S3 + A2;
A3 = A3 + 0002;
funcd9c04();

V1 = S2 + 000a;
S2 = V1;
V1 = V1 << 10;
800D8808	lui    at, $800e
AT = AT + 074a;
AT = AT + S0;
V0 = h[AT + 0000];
800D8818	lui    at, $800e
AT = AT + 074e;
AT = AT + S0;
A0 = h[AT + 0000];
A2 = V1 >> 10;
V0 = V0 + A0;
800D8830	addiu  v0, v0, $fff8 (=-$8)
V0 = A2 < V0;
800D8838	bne    v0, zero, loopd87c4 [$800d87c4]
A1 = S1 << 10;

Ld8840:	; 800D8840
V0 = S5 << 10;
T5 = V0 >> 10;
V1 = T5 << 01;
V1 = V1 + T5;
V0 = V1 << 06;
V0 = V0 - V1;
T7 = V0 << 01;
800D885C	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
800D886C	nop
800D8870	beq    v0, zero, Ld8f2c [$800d8f2c]
800D8878	lui    t2, $800e
T2 = T2 + 3b28;
V0 = h[800e1024];
V1 = h[800e41bc];
A0 = V0 << 03;
A0 = A0 + V0;
A0 = A0 << 06;
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
A0 = A0 + V0;
800D88AC	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V0 = hu[AT + 0000];
A0 = A0 + T2;
V0 = V0 + 0002;
[A0 + 0008] = h(V0);
800D88C8	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
T3 = T3 | ffff;
800D88DC	addiu  v0, v0, $ffff (=-$1)
V1 = V0 << 02;
V1 = V1 + V0;
800D88E8	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = V1 << 01;
V0 = V0 + V1;
V0 = V0 + 000a;
[A0 + 000a] = h(V0);
800D8908	lui    at, $800e
AT = AT + 074c;
AT = AT + T7;
V0 = hu[AT + 0000];
800D8918	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V1 = hu[AT + 0000];
800D8928	addiu  v0, v0, $fffe (=-$2)
V1 = V1 + V0;
[A0 + 000c] = h(V1);
800D8934	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
800D8944	lui    t6, $800e
T6 = T6 + 41c8;
800D894C	addiu  v0, v0, $ffff (=-$1)
V1 = V0 << 02;
V1 = V1 + V0;
800D8958	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = V1 << 01;
V0 = V0 + V1;
V0 = V0 + 000a;
[A0 + 000e] = h(V0);
800D8978	lui    at, $800e
AT = AT + 074c;
AT = AT + T7;
V0 = hu[AT + 0000];
800D8988	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V1 = hu[AT + 0000];
800D8998	addiu  v0, v0, $fffe (=-$2)
V1 = V1 + V0;
[A0 + 0010] = h(V1);
800D89A4	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
T5 = T5 << 02;
800D89B8	addiu  v0, v0, $ffff (=-$1)
V1 = V0 << 02;
V1 = V1 + V0;
800D89C4	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = V1 << 01;
V0 = V0 + V1;
[A0 + 0012] = h(V0);
800D89E0	lui    at, $800e
AT = AT + 0750;
AT = AT + T7;
V0 = bu[AT + 0000];
800D89F0	lui    t4, $ff00
V0 = V0 | 003f;
[A0 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D8A28	lui    at, $800e
AT = AT + 0751;
AT = AT + T7;
V0 = bu[AT + 0000];
V1 = V1 + T2;
V0 = V0 >> 01;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D8A70	lui    at, $800e
AT = AT + 0752;
AT = AT + T7;
V0 = bu[AT + 0000];
V1 = V1 + T2;
[V1 + 0006] = b(V0);
V0 = h[800e1024];
T0 = h[800e41bc];
A1 = V0 << 03;
A2 = A1 + V0;
A2 = A2 << 06;
A0 = T0 << 01;
A0 = A0 + T0;
A0 = A0 << 03;
A3 = A2 + A0;
A3 = A3 + T2;
A1 = A1 - V0;
A1 = A1 << 02;
A1 = A1 + T5;
A1 = A1 + T6;
A0 = A0 + T2;
A0 = A2 + A0;
A0 = A0 & T3;
T0 = T0 + 0001;
V1 = w[A3 + 0000];
V0 = w[A1 + 0000];
V1 = V1 & T4;
V0 = V0 & T3;
V1 = V1 | V0;
[A3 + 0000] = w(V1);
V1 = T0 << 10;
V0 = w[A1 + 0000];
V1 = V1 >> 10;
V0 = V0 & T4;
V0 = V0 | A0;
[A1 + 0000] = w(V0);
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
A2 = A2 + V0;
800D8B18	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V0 = hu[AT + 0000];
A2 = A2 + T2;
V0 = V0 + 0002;
[A2 + 0008] = h(V0);
800D8B34	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
800D8B44	nop
800D8B48	addiu  v0, v0, $ffff (=-$1)
V1 = V0 << 02;
V1 = V1 + V0;
800D8B54	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = V1 << 01;
V0 = V0 + V1;
V0 = V0 + 000a;
[A2 + 000a] = h(V0);
800D8B74	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V0 = hu[AT + 0000];
800D8B84	nop
V0 = V0 + 0002;
[A2 + 000c] = h(V0);
800D8B90	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V0 = h[AT + 0000];
800D8BA0	nop
800D8BA4	addiu  v0, v0, $ffff (=-$1)
V1 = V0 << 02;
V1 = V1 + V0;
800D8BB0	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = V1 << 01;
V0 = V0 + V1;
[A2 + 000e] = h(V0);
800D8BCC	lui    at, $800e
AT = AT + 074c;
AT = AT + T7;
V0 = hu[AT + 0000];
800D8BDC	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V1 = hu[AT + 0000];
800D8BEC	addiu  v0, v0, $fffe (=-$2)
V1 = V1 + V0;
[A2 + 0010] = h(V1);
800D8BF8	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V1 = h[AT + 0000];
[800e41bc] = h(T0);
800D8C10	addiu  v1, v1, $ffff (=-$1)
V0 = V1 << 02;
V0 = V0 + V1;
800D8C1C	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V1 = hu[AT + 0000];
V0 = V0 << 01;
V1 = V1 + V0;
[A2 + 0012] = h(V1);
800D8C38	lui    at, $800e
AT = AT + 0750;
AT = AT + T7;
V0 = bu[AT + 0000];
800D8C48	nop
V0 = V0 << 02;
V0 = V0 | 007f;
[A2 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D8C84	lui    at, $800e
AT = AT + 0751;
AT = AT + T7;
V0 = bu[AT + 0000];
V1 = V1 + T2;
V0 = V0 | 003f;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D8CCC	lui    at, $800e
AT = AT + 0752;
AT = AT + T7;
V0 = bu[AT + 0000];
V1 = V1 + T2;
V0 = V0 << 01;
V0 = V0 | 003f;
[V1 + 0006] = b(V0);
T0 = h[800e1024];
T1 = h[800e41bc];
A0 = T0 << 03;
A2 = A0 + T0;
A2 = A2 << 06;
A1 = T1 << 01;
A1 = A1 + T1;
A1 = A1 << 03;
A3 = A2 + A1;
A3 = A3 + T2;
A0 = A0 - T0;
A0 = A0 << 02;
A0 = A0 + T5;
A0 = A0 + T6;
A1 = A1 + T2;
A2 = A2 + A1;
A2 = A2 & T3;
V1 = w[A3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T4;
V0 = V0 & T3;
V1 = V1 | V0;
[A3 + 0000] = w(V1);
V0 = w[A0 + 0000];
800D8D54	lui    t2, $800e
T2 = T2 + 3fa8;
V0 = V0 & T4;
V0 = V0 | A2;
[A0 + 0000] = w(V0);
A0 = T0 << 01;
A0 = A0 + T0;
V0 = h[800e41c0];
A0 = A0 << 06;
V0 = V0 << 04;
A0 = A0 + V0;
800D8D84	lui    at, $800e
AT = AT + 0748;
AT = AT + T7;
V0 = hu[AT + 0000];
A0 = A0 + T2;
V0 = V0 + 0002;
[A0 + 0008] = h(V0);
800D8DA0	lui    at, $800e
AT = AT + 0756;
AT = AT + T7;
V1 = h[AT + 0000];
T1 = T1 + 0001;
[800e41bc] = h(T1);
800D8DBC	addiu  v1, v1, $ffff (=-$1)
V0 = V1 << 02;
V0 = V0 + V1;
800D8DC8	lui    at, $800e
AT = AT + 074a;
AT = AT + T7;
V1 = hu[AT + 0000];
V0 = V0 << 01;
V1 = V1 + V0;
[A0 + 000a] = h(V1);
800D8DE4	lui    at, $800e
AT = AT + 074c;
AT = AT + T7;
V0 = hu[AT + 0000];
V1 = 000a;
[A0 + 000e] = h(V1);
800D8DFC	addiu  v0, v0, $fffc (=-$4)
[A0 + 000c] = h(V0);
800D8E04	lui    at, $800e
AT = AT + 0750;
AT = AT + T7;
V0 = bu[AT + 0000];
800D8E14	nop
V0 = V0 << 01;
V0 = V0 | 007f;
[A0 + 0004] = b(V0);
V1 = h[800e1024];
800D8E2C	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D8E4C	lui    at, $800e
AT = AT + 0751;
AT = AT + T7;
V1 = bu[AT + 0000];
V0 = V0 + T2;
V1 = V1 >> 01;
[V0 + 0005] = b(V1);
V1 = h[800e1024];
800D8E70	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D8E90	lui    at, $800e
AT = AT + 0752;
AT = AT + T7;
V1 = bu[AT + 0000];
V0 = V0 + T2;
V1 = V1 | 003f;
[V0 + 0006] = b(V1);
V0 = h[800e1024];
T0 = h[800e41c0];
A1 = V0 << 01;
A1 = A1 + V0;
A1 = A1 << 06;
A3 = T0 << 04;
A2 = A1 + A3;
A2 = A2 + T2;
A0 = V0 << 03;
A0 = A0 - V0;
A0 = A0 << 02;
A0 = A0 + T5;
A0 = A0 + T6;
T0 = T0 + 0001;
A3 = A3 + T2;
A1 = A1 + A3;
V1 = w[A2 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T4;
V0 = V0 & T3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = w[A0 + 0000];
A1 = A1 & T3;
[800e41c0] = h(T0);
V0 = V0 & T4;
V0 = V0 | A1;
800D8F24	j      Ld91f0 [$800d91f0]
[A0 + 0000] = w(V0);

Ld8f2c:	; 800D8F2C
800D8F2C	lui    at, $800e
AT = AT + 0754;
AT = AT + T7;
V0 = h[AT + 0000];
800D8F3C	nop
800D8F40	beq    v0, zero, Ld8f50 [$800d8f50]
V1 = V0;
800D8F48	j      Ld8f84 [$800d8f84]
800D8F4C	addiu  s1, v1, $ffff (=-$1)

Ld8f50:	; 800D8F50
800D8F54	lui    at, $800e
AT = AT + 074e;
AT = AT + T7;
V1 = h[AT + 0000];
V0 = V0 | 6667;
V1 = V1 + 0002;
800D8F6C	mult   v1, v0
V1 = V1 >> 1f;
800D8F74	mfhi   v0
V0 = V0 >> 02;
V0 = V0 - V1;
800D8F80	addiu  s1, v0, $ffff (=-$1)

Ld8f84:	; 800D8F84
800D8F84	lui    t3, $800e
T3 = T3 + 3b28;
T0 = S5 << 10;
T0 = T0 >> 10;
V0 = h[800e1024];
V1 = h[800e41bc];
A0 = V0 << 03;
A0 = A0 + V0;
A0 = A0 << 06;
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
A0 = A0 + V0;
V0 = T0 << 01;
V0 = V0 + T0;
A2 = V0 << 06;
A2 = A2 - V0;
A2 = A2 << 01;
800D8FD4	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V0 = hu[AT + 0000];
A0 = A0 + T3;
V0 = V0 + 0002;
[A0 + 0008] = h(V0);
V0 = S1 << 10;
V0 = V0 >> 10;
A1 = V0 << 02;
A1 = A1 + V0;
800D9000	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
A1 = A1 << 01;
V0 = V0 + A1;
V0 = V0 + 000a;
[A0 + 000a] = h(V0);
800D9020	lui    at, $800e
AT = AT + 074c;
AT = AT + A2;
V0 = hu[AT + 0000];
800D9030	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V1 = hu[AT + 0000];
800D9040	addiu  v0, v0, $fffe (=-$2)
V1 = V1 + V0;
[A0 + 000c] = h(V1);
800D904C	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
800D905C	lui    t2, $00ff
V0 = V0 + A1;
V0 = V0 + 000a;
[A0 + 000e] = h(V0);
800D906C	lui    at, $800e
AT = AT + 074c;
AT = AT + A2;
V0 = hu[AT + 0000];
800D907C	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V1 = hu[AT + 0000];
800D908C	addiu  v0, v0, $fffe (=-$2)
V1 = V1 + V0;
[A0 + 0010] = h(V1);
800D9098	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
T2 = T2 | ffff;
V0 = V0 + A1;
[A0 + 0012] = h(V0);
800D90B4	lui    at, $800e
AT = AT + 0750;
AT = AT + A2;
V0 = bu[AT + 0000];
800D90C4	lui    a3, $800e
A3 = A3 + 41c8;
V0 = V0 >> 01;
V0 = V0 | 003f;
[A0 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9104	lui    at, $800e
AT = AT + 0751;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + T3;
V0 = V0 << 02;
V0 = V0 | 007f;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9150	lui    at, $800e
AT = AT + 0752;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + T3;
V0 = V0 | 003f;
[V1 + 0006] = b(V0);
V1 = h[800e1024];
T1 = h[800e41bc];
V0 = V1 << 03;
A1 = V0 + V1;
A1 = A1 << 06;
A0 = T1 << 01;
A0 = A0 + T1;
A0 = A0 << 03;
A2 = A1 + A0;
A2 = A2 + T3;
V0 = V0 - V1;
T0 = T0 + V0;
T0 = T0 << 02;
T0 = T0 + A3;
800D91AC	lui    a3, $ff00
T1 = T1 + 0001;
A0 = A0 + T3;
A1 = A1 + A0;
V1 = w[A2 + 0000];
V0 = w[T0 + 0000];
V1 = V1 & A3;
V0 = V0 & T2;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = w[T0 + 0000];
A1 = A1 & T2;
V0 = V0 & A3;
V0 = V0 | A1;
[T0 + 0000] = w(V0);
[800e41bc] = h(T1);

Ld91f0:	; 800D91F0
800D91F0	lui    a3, $800e
A3 = A3 + 3b28;
A1 = S5 << 10;
A1 = A1 >> 10;
V0 = h[800e1024];
V1 = h[800e41bc];
A0 = V0 << 03;
A0 = A0 + V0;
A0 = A0 << 06;
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
A0 = A0 + V0;
V1 = A1 << 01;
V1 = V1 + A1;
V0 = V1 << 06;
V0 = V0 - V1;
A2 = V0 << 01;
800D9240	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V0 = hu[AT + 0000];
A0 = A0 + A3;
[A0 + 0008] = h(V0);
800D9258	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
800D9268	lui    at, $800e
AT = AT + 074e;
AT = AT + A2;
V1 = hu[AT + 0000];
800D9278	nop
V0 = V0 + V1;
[A0 + 000a] = h(V0);
800D9284	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V0 = hu[AT + 0000];
800D9294	lui    at, $800e
AT = AT + 074c;
AT = AT + A2;
V1 = hu[AT + 0000];
800D92A4	nop
V0 = V0 + V1;
[A0 + 000c] = h(V0);
800D92B0	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
800D92C0	lui    at, $800e
AT = AT + 074e;
AT = AT + A2;
V1 = hu[AT + 0000];
800D92D0	nop
V0 = V0 + V1;
[A0 + 000e] = h(V0);
800D92DC	lui    at, $800e
AT = AT + 0748;
AT = AT + A2;
V0 = hu[AT + 0000];
800D92EC	lui    at, $800e
AT = AT + 074c;
AT = AT + A2;
V1 = hu[AT + 0000];
800D92FC	nop
V0 = V0 + V1;
[A0 + 0010] = h(V0);
800D9308	lui    at, $800e
AT = AT + 074a;
AT = AT + A2;
V0 = hu[AT + 0000];
V1 = bu[80071c08];
800D9320	nop
800D9324	bne    a1, v1, Ld93d8 [$800d93d8]
[A0 + 0012] = h(V0);
800D932C	lui    at, $800e
AT = AT + 0750;
AT = AT + A2;
V0 = bu[AT + 0000];
800D933C	nop
V0 = V0 >> 01;
[A0 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9374	lui    at, $800e
AT = AT + 0751;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + A3;
V0 = V0 >> 01;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D93BC	lui    at, $800e
AT = AT + 0752;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + A3;
800D93D0	j      Ld9474 [$800d9474]
V0 = V0 >> 01;

Ld93d8:	; 800D93D8
800D93D8	lui    at, $800e
AT = AT + 0750;
AT = AT + A2;
V0 = bu[AT + 0000];
800D93E8	nop
[A0 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D941C	lui    at, $800e
AT = AT + 0751;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + A3;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9460	lui    at, $800e
AT = AT + 0752;
AT = AT + A2;
V0 = bu[AT + 0000];
V1 = V1 + A3;

Ld9474:	; 800D9474
[V1 + 0006] = b(V0);
800D9478	lui    t2, $00ff
T2 = T2 | ffff;
800D9480	lui    t4, $800e
T4 = T4 + 3b28;
T1 = S5 << 10;
T1 = T1 >> 10;
800D9490	lui    v1, $800e
V1 = V1 + 41c8;
V0 = h[800e1024];
T3 = h[800e41bc];
A1 = V0 << 03;
A3 = A1 + V0;
A3 = A3 << 06;
A0 = T3 << 01;
A0 = A0 + T3;
A0 = A0 << 03;
A2 = A3 + A0;
A2 = A2 + T4;
A1 = A1 - V0;
A1 = T1 + A1;
A1 = A1 << 02;
A1 = A1 + V1;
A0 = A0 + T4;
A0 = A3 + A0;
A0 = A0 & T2;
T3 = T3 + 0001;
V1 = w[A2 + 0000];
V0 = w[A1 + 0000];
V1 = V1 & T0;
V0 = V0 & T2;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V1 = T3 << 10;
V0 = w[A1 + 0000];
V1 = V1 >> 10;
V0 = V0 & T0;
V0 = V0 | A0;
[A1 + 0000] = w(V0);
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
A3 = A3 + V0;
V1 = T1 << 01;
V1 = V1 + T1;
V0 = V1 << 06;
V0 = V0 - V1;
A1 = V0 << 01;
800D9540	lui    at, $800e
AT = AT + 0748;
AT = AT + A1;
V0 = hu[AT + 0000];
A3 = A3 + T4;
[A3 + 0008] = h(V0);
800D9558	lui    at, $800e
AT = AT + 074a;
AT = AT + A1;
V0 = hu[AT + 0000];
800D9568	lui    at, $800e
AT = AT + 074e;
AT = AT + A1;
V1 = hu[AT + 0000];
800D9578	nop
V0 = V0 + V1;
[A3 + 000a] = h(V0);
800D9584	lui    at, $800e
AT = AT + 0748;
AT = AT + A1;
V0 = hu[AT + 0000];
800D9594	nop
[A3 + 000c] = h(V0);
800D959C	lui    at, $800e
AT = AT + 074a;
AT = AT + A1;
V0 = hu[AT + 0000];
800D95AC	nop
[A3 + 000e] = h(V0);
800D95B4	lui    at, $800e
AT = AT + 0748;
AT = AT + A1;
V0 = hu[AT + 0000];
800D95C4	lui    at, $800e
AT = AT + 074c;
AT = AT + A1;
V1 = hu[AT + 0000];
800D95D4	nop
V0 = V0 + V1;
[A3 + 0010] = h(V0);
800D95E0	lui    at, $800e
AT = AT + 074a;
AT = AT + A1;
V0 = hu[AT + 0000];
V1 = bu[80071c08];
[800e41bc] = h(T3);
800D9600	bne    t1, v1, Ld96c0 [$800d96c0]
[A3 + 0012] = h(V0);
800D9608	lui    at, $800e
AT = AT + 0750;
AT = AT + A1;
V0 = bu[AT + 0000];
800D9618	nop
V0 = V0 << 02;
V0 = V0 | 007f;
[A3 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9654	lui    at, $800e
AT = AT + 0751;
AT = AT + A1;
V0 = bu[AT + 0000];
V1 = V1 + T4;
V0 = V0 << 02;
V0 = V0 | 007f;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D96A0	lui    at, $800e
AT = AT + 0752;
AT = AT + A1;
V0 = bu[AT + 0000];
V1 = V1 + T4;
V0 = V0 << 02;
800D96B8	j      Ld9774 [$800d9774]
V0 = V0 | 007f;

Ld96c0:	; 800D96C0
800D96C0	lui    at, $800e
AT = AT + 0750;
AT = AT + A1;
V0 = bu[AT + 0000];
800D96D0	nop
V0 = V0 << 01;
V0 = V0 | 003f;
[A3 + 0004] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D970C	lui    at, $800e
AT = AT + 0751;
AT = AT + A1;
V0 = bu[AT + 0000];
V1 = V1 + T4;
V0 = V0 << 01;
V0 = V0 | 003f;
[V1 + 0005] = b(V0);
V0 = h[800e1024];
A0 = h[800e41bc];
V1 = V0 << 03;
V1 = V1 + V0;
V1 = V1 << 06;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V1 = V1 + V0;
800D9758	lui    at, $800e
AT = AT + 0752;
AT = AT + A1;
V0 = bu[AT + 0000];
V1 = V1 + T4;
V0 = V0 << 01;
V0 = V0 | 003f;

Ld9774:	; 800D9774
[V1 + 0006] = b(V0);
800D9778	lui    t3, $00ff
T3 = T3 | ffff;
800D9780	lui    t5, $800e
T5 = T5 + 3b28;
T2 = S5 << 10;
T2 = T2 >> 10;
800D9790	lui    v0, $800e
V0 = V0 + 41c8;
T1 = h[800e1024];
T4 = h[800e41bc];
A0 = T1 << 03;
A2 = A0 + T1;
A2 = A2 << 06;
A1 = T4 << 01;
A1 = A1 + T4;
A1 = A1 << 03;
A3 = A2 + A1;
A3 = A3 + T5;
A0 = A0 - T1;
A0 = T2 + A0;
A0 = A0 << 02;
A0 = A0 + V0;
A1 = A1 + T5;
A2 = A2 + A1;
A2 = A2 & T3;
V1 = w[A3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T0;
V0 = V0 & T3;
V1 = V1 | V0;
[A3 + 0000] = w(V1);
V1 = T2 << 01;
V0 = w[A0 + 0000];
V1 = V1 + T2;
V0 = V0 & T0;
V0 = V0 | A2;
800D9814	lui    a2, $800e
A2 = A2 + 3fa8;
[A0 + 0000] = w(V0);
A0 = T1 << 01;
A0 = A0 + T1;
V0 = h[800e41c0];
A0 = A0 << 06;
V0 = V0 << 04;
A0 = A0 + V0;
V0 = V1 << 06;
V0 = V0 - V1;
A1 = V0 << 01;
800D9848	lui    at, $800e
AT = AT + 0748;
AT = AT + A1;
V0 = hu[AT + 0000];
V1 = bu[80071c08];
A0 = A0 + A2;
[A0 + 0008] = h(V0);
800D9868	lui    at, $800e
AT = AT + 074a;
AT = AT + A1;
V0 = hu[AT + 0000];
800D9878	nop
[A0 + 000a] = h(V0);
800D9880	lui    at, $800e
AT = AT + 074c;
AT = AT + A1;
V0 = hu[AT + 0000];
800D9890	nop
[A0 + 000c] = h(V0);
800D9898	lui    at, $800e
AT = AT + 074e;
AT = AT + A1;
V0 = hu[AT + 0000];
T4 = T4 + 0001;
[800e41bc] = h(T4);
800D98B4	bne    t2, v1, Ld9960 [$800d9960]
[A0 + 000e] = h(V0);
800D98BC	lui    at, $800e
AT = AT + 0750;
AT = AT + A1;
V0 = bu[AT + 0000];
800D98CC	nop
V0 = V0 << 01;
[A0 + 0004] = b(V0);
V1 = h[800e1024];
800D98E0	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D9900	lui    at, $800e
AT = AT + 0751;
AT = AT + A1;
V1 = bu[AT + 0000];
V0 = V0 + A2;
V1 = V1 << 01;
[V0 + 0005] = b(V1);
V1 = h[800e1024];
800D9924	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D9944	lui    at, $800e
AT = AT + 0752;
AT = AT + A1;
V1 = bu[AT + 0000];
V0 = V0 + A2;
800D9958	j      Ld99f4 [$800d99f4]
V1 = V1 << 01;

Ld9960:	; 800D9960
800D9960	lui    at, $800e
AT = AT + 0750;
AT = AT + A1;
V0 = bu[AT + 0000];
800D9970	nop
[A0 + 0004] = b(V0);
V1 = h[800e1024];
800D9980	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D99A0	lui    at, $800e
AT = AT + 0751;
AT = AT + A1;
V1 = bu[AT + 0000];
V0 = V0 + A2;
[V0 + 0005] = b(V1);
V1 = h[800e1024];
800D99C0	nop
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
800D99E0	lui    at, $800e
AT = AT + 0752;
AT = AT + A1;
V1 = bu[AT + 0000];
V0 = V0 + A2;

Ld99f4:	; 800D99F4
[V0 + 0006] = b(V1);
V1 = h[800e4210];
V0 = 0002;
800D9A04	beq    v1, v0, Ld9a64 [$800d9a64]
V0 = V1 < 0003;
800D9A0C	beq    v0, zero, Ld9b38 [$800d9b38]
V0 = 0001;
800D9A14	bne    v1, v0, Ld9b3c [$800d9b3c]
800D9A1C	lui    t3, $800e
T3 = T3 + 3fa8;
V1 = h[800e1024];
T2 = T2 | ffff;
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
V0 = V0 + T3;
V1 = bu[V0 + 0007];
800D9A54	lui    t1, $800e
T1 = T1 + 41c8;
800D9A5C	j      Ld9aac [$800d9aac]
V1 = V1 | 0002;

Ld9a64:	; 800D9A64
800D9A64	lui    t3, $800e
T3 = T3 + 3fa8;
V1 = h[800e1024];
T2 = T2 | ffff;
V0 = V1 << 01;
V0 = V0 + V1;
V1 = h[800e41c0];
V0 = V0 << 06;
V1 = V1 << 04;
V0 = V0 + V1;
V0 = V0 + T3;
V1 = bu[V0 + 0007];
800D9AA0	lui    t1, $800e
T1 = T1 + 41c8;
V1 = V1 & 00fd;

Ld9aac:	; 800D9AAC
[V0 + 0007] = b(V1);
V0 = S5 << 10;
V0 = V0 >> 0e;
V1 = h[800e1024];
T0 = h[800e41c0];
A1 = V1 << 01;
A1 = A1 + V1;
A1 = A1 << 06;
A3 = T0 << 04;
A2 = A1 + A3;
A2 = A2 + T3;
A0 = V1 << 03;
A0 = A0 - V1;
A0 = A0 << 02;
A0 = A0 + V0;
A0 = A0 + T1;
800D9AF4	lui    t1, $ff00
T0 = T0 + 0001;
A3 = A3 + T3;
A1 = A1 + A3;
V1 = w[A2 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T1;
V0 = V0 & T2;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = w[A0 + 0000];
A1 = A1 & T2;
[800e41c0] = h(T0);
V0 = V0 & T1;
V0 = V0 | A1;
[A0 + 0000] = w(V0);

Ld9b38:	; 800D9B38
800D9B38	lui    t2, $00ff

Ld9b3c:	; 800D9B3C
T2 = T2 | ffff;
800D9B40	lui    t3, $800e
T3 = T3 + 4128;
V0 = S5 << 10;
800D9B4C	lui    t1, $800e
T1 = T1 + 41c8;
V0 = V0 >> 0e;
V1 = h[800e1024];
T0 = h[800e41c4];
A0 = V1 << 03;
A2 = A0 + V1;
A2 = A2 << 03;
A1 = T0 << 01;
A1 = A1 + T0;
A1 = A1 << 02;
A3 = A2 + A1;
A3 = A3 + T3;
A0 = A0 - V1;
A0 = A0 << 02;
A0 = A0 + V0;
A0 = A0 + T1;
800D9B98	lui    t1, $ff00
T0 = T0 + 0001;
A1 = A1 + T3;
A2 = A2 + A1;
V1 = w[A3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T1;
V0 = V0 & T2;
V1 = V1 | V0;
[A3 + 0000] = w(V1);
V0 = w[A0 + 0000];
A2 = A2 & T2;
[800e41c4] = h(T0);
V0 = V0 & T1;
V0 = V0 | A2;
[A0 + 0000] = w(V0);

Ld9bdc:	; 800D9BDC
////////////////////////////////



////////////////////////////////
// funcd9c04()

T2 = A2;
V0 = bu[T2];
T9 = A4;
T3 = A3;
800D9C14	beq    v0, zero, Ld9ef4 [$800d9ef4]

V1 = A0 << 01;
V1 = V1 + A0;
V0 = V1 << 06;
V0 = V0 - V1;
T5 = V0 << 01;
T6 = 800e1028;
V0 = A1 << 10;
T8 = V0 >> 10;
T7 = A0 << 02;
T4 = 00ffffff;

Ld9c54:	; 800D9C54
    V0 = h[800e0748 + T5 + 0];
    V1 = h[800e0748 + T5 + 4];
    V0 = V0 + V1;
    800D9C7C	addiu  v0, v0, $fff8 (=-$8)
    V0 = V0 < T3;
    800D9C84	bne    v0, zero, Ld9ef4 [$800d9ef4]
    800D9C88	nop
    V0 = h[800e41b8];
    800D9C94	nop
    V0 = V0 < 0158;
    800D9C9C	beq    v0, zero, Ld9ef4 [$800d9ef4]
    800D9CA0	nop
    V0 = bu[T2 + 0000];
    800D9CA8	nop
    800D9CAC	addiu  v1, v0, $ffe0 (=-$20)
    V0 = V1 < 0020;
    800D9CB4	beq    v0, zero, Ld9d38 [$800d9d38]

    V0 = w[800a12e8 + V1 * 4];
    800D9CD0	jr     v0 

    800D9CD8	j      Ld9d78 [$800d9d78]
    A0 = 003f;
    800D9CE0	j      Ld9d78 [$800d9d78]
    A0 = 00d5;
    800D9CE8	j      Ld9d78 [$800d9d78]
    A0 = 00b2;
    800D9CF0	j      Ld9d78 [$800d9d78]
    A0 = 00b3;
    800D9CF8	j      Ld9d78 [$800d9d78]
    A0 = 00d4;
    800D9D00	j      Ld9d78 [$800d9d78]
    A0 = 00d0;
    800D9D08	j      Ld9d78 [$800d9d78]
    A0 = 00cf;
    800D9D10	j      Ld9d78 [$800d9d78]
    A0 = 00ae;
    800D9D18	j      Ld9d78 [$800d9d78]
    A0 = 00af;
    800D9D20	j      Ld9d78 [$800d9d78]
    A0 = 00da;
    800D9D28	j      Ld9d78 [$800d9d78]
    A0 = 00d6;
    800D9D30	j      Ld9d78 [$800d9d78]
    A0 = 00d9;

    Ld9d38:	; 800D9D38
    V1 = bu[T2 + 0000];
    V0 = V1 < 003a;
    800D9D44	beq    v0, zero, Ld9d58 [$800d9d58]
    V0 = V1 < 0061;
    V0 = bu[T2 + 0000];
    A0 = V0 + 0003;
    800D9D50	j      Ld9d78 [$800d9d78]

    Ld9d58:	; 800D9D58
    800D9D58	bne    v0, zero, Ld9d6c [$800d9d6c]

    V0 = bu[T2 + 0000];
    A0 = V0 + 0053;
    800D9D64	j      Ld9d78 [$800d9d78]

    Ld9d6c:	; 800D9D6C
    V0 = bu[T2 + 0000];
    A0 = V0 + 0073;

    Ld9d78:	; 800D9D78
    V1 = h[800e1024];
    T2 = T2 + 0001;
    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 02;
    V0 = V0 - V1;
    V0 = V0 << 02;
    V0 = V0 - V1;
    V1 = h[800e41b8];
    V0 = V0 << 07;
    V1 = V1 << 04;
    V0 = V0 + V1;
    V0 = V0 + T6;
    V1 = A0 & 000f;
    V1 = V1 << 03;
    800D9DBC	addiu  v1, v1, $ff80 (=-$80)
    [V0 + 000c] = b(V1);
    V1 = h[800e1024];
    A3 = ff000000;

    V0 = V1 << 01;
    V0 = V0 + V1;
    V0 = V0 << 02;
    V0 = V0 - V1;
    V0 = V0 << 02;
    V0 = V0 - V1;

    V1 = h[800e41b8];
    V0 = V0 << 07;
    V1 = V1 << 04;
    V0 = V0 + V1;
    V0 = V0 + T6;
    V1 = A0 >> 01;
    V1 = V1 & 0078;
    800D9E08	addiu  v1, v1, $ff80 (=-$80)
    [V0 + 000d] = b(V1);
    V0 = 800e08a8 + T5 + T8;
    V1 = h[800e1024];
    T1 = h[800e41b8];

    A1 = V1 << 01;
    A1 = A1 + V1;
    A1 = A1 << 02;
    A1 = A1 - V1;
    A1 = A1 << 02;
    A1 = A1 - V1;
    A1 = A1 << 07;

    T0 = T1 << 04;
    A0 = A1 + T0;
    A2 = A0 + T6;
    T1 = T1 + 0001;
    [A2 + 0008] = h(T3);
    [A2 + 000a] = h(T9);
    V0 = bu[V0];
    T0 = T0 + T6;
    V0 = V0 << 01;
    V0 = hu[800e4200 + V0];
    A1 = A1 + T0;
    [800e1036 + A0] = h(V0);

    A0 = V1 << 03;
    A0 = A0 - V1;
    A0 = A0 << 02;

    A0 = 800e41c8 + A0 + T7;
    [A2] = w((w[A2] & A3) | (w[A0] & T4));
    [800e41b8] = h(T1);
    [A0] = w((w[A0] & A3) | (A1 & T4));
    T3 = T3 + 0008;
800D9EEC	bne    bu[T2], zero, Ld9c54 [$800d9c54]

Ld9ef4:	; 800D9EF4
////////////////////////////////



////////////////////////////////
// field_add_string_to_debug_by_id()

id = A0;
src = A1;

A0 = 800e0758 + id * 17a + h[800e0748 + id * 17a + c] * e;
A1 = src;
field_copy_string();

[800e0748 + id * 17a + c] = h(hu[800e0748 + id * 17a + c] + 1);

if( ( ( h[800e0748 + id * 17a + 6] - 8 ) / a ) < h[800e0748 + id * 17a + c] )
{
    [800e0748 + id * 17a + c] = h(0);
}

[8009d824] = b(1);

return 1;
////////////////////////////////



////////////////////////////////
// funcd9ffc()
// not used

id1 = A0;
S1 = A2;

A0 = 800e0758 + id1 * 17a + h[800e0754 + id1 * 17a] * e;
A1 = A1;
field_copy_string();

V0 = h[800e0754 + id1 * 17a];
[800e0758 + id1 * 17a + 150 + V0] = b(S1);

[800e0748 + id1 * 17a + c] = h(hu[800e0754 + id1 * 17a] + 1);

V1 = h[800e074e + id1 * 17a] - 8;
if( ( V1 / a ) < h[800e0754 + id1 * 17a] )
{
    [800e0754 + id1 * 17a] = h(0);
}

[8009d824] = b(1);

return 1;
////////////////////////////////



////////////////////////////////
// field_copy_into_debug_by_id()

A0 = 800e0758 + A0 * 17a + A1 * e;
A1 = A2;
field_copy_string();

[8009d824] = b(1);

return 1;
////////////////////////////////



////////////////////////////////
// funcda194()

[800e0748 + A0 * 17a + 160 + A1] = b(A2);
return 1;
////////////////////////////////



////////////////////////////////
// funcda1d4()

[800e0748 + A0 * 17a + e] = b(A1);
[8009d824] = b(1);
////////////////////////////////



////////////////////////////////
// funcda214()

if( bu[800e0748 + A0 * 17a + 78] == 0 )
{
    [800e0748 + A0 * 17a + 8] = b(A1);
    [800e0748 + A0 * 17a + 9] = b(A2);
    [800e0748 + A0 * 17a + a] = b(A3);
    [8009d824] = b(1);
}
////////////////////////////////



////////////////////////////////
// funcda28c

A0 = A0 << 10;
A0 = A0 >> 10;
V0 = A0 << 01;
V0 = V0 + A0;
V1 = V0 << 06;
V1 = V1 - V0;
V1 = V1 << 01;
V0 = 0001;
800DA2AC	lui    at, $800e
AT = AT + 08c0;
AT = AT + V1;
[AT + 0000] = b(V0);
[8009d824] = b(V0);
////////////////////////////////



////////////////////////////////
// funcda2cc()

[800e0748 + A0 * 17a + 78] = b(2);
[8009d824] = b(1);
////////////////////////////////



////////////////////////////////
// funcda310()

[800e4210] = h((hu[800e4210] + 1) & 3);
////////////////////////////////



////////////////////////////////
// field_copy_string()

dst = A0;
src = A1;

while( bu[src] != 0 )
{
    [dst] = b(bu[src]);
    dst = dst + 1;
    src = src + 1;
}
[dst] = b(0);
////////////////////////////////



////////////////////////////////
// field_concat_string()

dst = A0;
src = A1;

while( bu[dst] != 0 )
{
    dst = dst + 1;
}

while( bu[src] != 0 )
{
    [dst] = b(bu[src]);
    dst = dst + 1;
    src = src + 1;
}
[dst] = b(0);
////////////////////////////////



////////////////////////////////
// funcda3c4
800DA3C4

V0 = bu[A0 + 0000];
800DA3C8	nop
800DA3CC	beq    v0, zero, Lda3e8 [$800da3e8]
V1 = 0;

loopda3d4:	; 800DA3D4
A0 = A0 + 0001;
V0 = bu[A0 + 0000];
800DA3DC	nop
800DA3E0	bne    v0, zero, loopda3d4 [$800da3d4]
V1 = V1 + 0001;

Lda3e8:	; 800DA3E8
return V1;
////////////////////////////////



////////////////////////////////
// funcda3f0

800DA3F4	beq    a2, zero, Lda418 [$800da418]
800DA3F8	addiu  v1, a2, $ffff (=-$1)
800DA3FC	addiu  a2, zero, $ffff (=-$1)

loopda400:	; 800DA400
V0 = bu[A1 + 0000];
A1 = A1 + 0001;
800DA408	addiu  v1, v1, $ffff (=-$1)
[A0 + 0000] = b(V0);
800DA410	bne    v1, a2, loopda400 [$800da400]
A0 = A0 + 0001;

Lda418:	; 800DA418
////////////////////////////////



////////////////////////////////
// field_int_to_string()

[A1 + 0] = b(bu[800e0208 + (A0 & f)]);
[A1 + 1] = b(0);
////////////////////////////////



////////////////////////////////
// field_int2_to_string()

[A1 + 0] = b(bu[800e0208 + ((A0 & f0) >> 4)]);
[A1 + 1] = b(bu[800e0208 + (A0 & f)]);
[A1 + 2] = b(0);
////////////////////////////////



////////////////////////////////
// funcda480
800DA480
V0 = A0 & f000;
V0 = V0 >> 0c;
[A1 + 0004] = b(0);
800DA48C	lui    at, $800e
AT = AT + 0208;
AT = AT + V0;
V0 = bu[AT + 0000];
800DA49C	nop
[A1 + 0000] = b(V0);
V0 = A0 & 0f00;
V0 = V0 >> 08;
800DA4AC	lui    at, $800e
AT = AT + 0208;
AT = AT + V0;
V0 = bu[AT + 0000];
800DA4BC	nop
[A1 + 0001] = b(V0);
V0 = A0 & 00f0;
V0 = V0 >> 04;
800DA4CC	lui    at, $800e
AT = AT + 0208;
AT = AT + V0;
V0 = bu[AT + 0000];
A0 = A0 & 000f;
[A1 + 0002] = b(V0);
800DA4E4	lui    at, $800e
AT = AT + 0208;
AT = AT + A0;
V0 = bu[AT + 0000];
800DA4F4	jr     ra 
[A1 + 0003] = b(V0);
800DA4F8
////////////////////////////////



////////////////////////////////
// funcda4fc
800DA4FС
T1 = 0;
V1 = 2710;
T0 = 0;
800DA508	lui    t2, $6666
T2 = T2 | 6667;
A3 = A1;

loopda514:	; 800DA514
800DA514	div    a0, v1
800DA53C	mflo   a2
800DA540	bne    t1, zero, Lda550 [$800da550]
800DA544	nop
800DA548	beq    a2, zero, Lda574 [$800da574]
800DA54C	mult   a2, v1

Lda550:	; 800DA550
T1 = 0001;
800DA554	lui    at, $800e
AT = AT + 0208;
AT = AT + A2;
V0 = bu[AT + 0000];
T0 = T0 + 0001;
[A3 + 0000] = b(V0);
A3 = A3 + 0001;
800DA570	mult   a2, v1

Lda574:	; 800DA574
800DA574	mflo   v0
800DA578	mult   v1, t2
A0 = A0 - V0;
V1 = V1 >> 1f;
800DA584	mfhi   v0
V0 = V0 >> 02;
V1 = V0 - V1;
V0 = V1 < 0002;
800DA594	beq    v0, zero, loopda514 [$800da514]
V0 = A1 + T0;
800DA59C	lui    at, $800e
AT = AT + 0208;
AT = AT + A0;
V1 = bu[AT + 0000];
[V0 + 0001] = b(0);
[V0 + 0000] = b(V1);
////////////////////////////////
