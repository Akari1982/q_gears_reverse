////////////////////////////////
// func36298()

[8004f8a0] = w(A0);
////////////////////////////////



////////////////////////////////
// func19d00()

A0 = a;
A1 = 0;
80019D0C	jal    func322bc [$800322bc]
////////////////////////////////



////////////////////////////////
// func195f4
800195F4	beq    a0, a1, L19604 [$80019604]

loop195f8:	; 800195F8
A0 = A0 + 0004;
800195FC	bne    a0, a1, loop195f8 [$800195f8]
[A0 + 0000] = w(0);

L19604:	; 80019604
////////////////////////////////



////////////////////////////////
// system_extract_archive()

comp_position = A0;
decomp_length = w[comp_position];
comp_position = comp_position + 4;
T7 = A1 + decomp_length;

T6 = A1;
T8 = bu[comp_position];

L32cec:	; 80032CEC
    if( A1 == T7 )
    {
        return T6;
    }

    comp_position = comp_position + 1;
    T1 = T8 & 0001;
    T9 = 0008;

    loop32cfc:	; 80032CFC
        T0 = bu[A0];

        T8 = T8 >> 01;
        80032D04	addiu  t9, t9, $ffff (=-$1)
        comp_position = comp_position + 1;
        80032D08	bne    t1, zero, L32d28 [$80032d28]

        [A1 + 0000] = b(T0);
        A1 = A1 + 0001;
        T1 = T8 & 0001;
    80032D18	bne    t9, zero, loop32cfc [$80032cfc]

    T8 = bu[comp_position];
    80032D20	j      L32cec [$80032cec]

    L32d28:	; 80032D28
    T4 = bu[comp_position];
    comp_position = comp_position + 1;

    T1 = T4 & 000f;
    T1 = T1 << 08;
    T0 = T0 | T1;
    T1 = A1 - T0;
    T3 = T4 >> 04;
    T3 = T3 + 0003;
    T3 = T3 + T1;

    loop32d4c:	; 80032D4C
        T0 = b[T1];
        [A1] = b(T0);
        T1 = T1 + 1;
        A1 = A1 + 1;
    80032D58	bne    t1, t3, loop32d4c [$80032d4c]

    80032D60	bne    t9, zero, loop32cfc [$80032cfc]
    T1 = T8 & 0001;
    T8 = bu[comp_position];
80032D68	j      L32cec [$80032cec]
////////////////////////////////



////////////////////////////////
// func32cac()

src = A0;

A0 = w[A0];
A1 = A1;
80032CB8	jal    func319ec [$800319ec]

if( V0 == 0 )
{
    return 0;
}

A0 = src;
A1 = V0;
system_extract_archive();

return V0;
////////////////////////////////



////////////////////////////////
// func3337c()

S0 = A0;
if( S0 == 0 )
{
    A0 = 0020;
    80033390	jal    func322dc [$800322dc]

    return;
}

A0 = S0;
800333A0	jal    func31ec8 [$80031ec8]

[80058a08] = w(S0);
[800589f8] = w(S0);
[800589e8] = w(hu[S0 + 0004]);
[800589ec] = w(hu[S0 + 0006]);
[800589f0] = w(hu[S0 + 0008]);
[800589f4] = w(hu[S0 + 000a]);
[800589f8] = w(S0 + hu[S0 + 0002]);
[80058a00] = w(hu[S0 + 000c]);
////////////////////////////////



////////////////////////////////
// func1b500()
if( w[8004ea10] != 0 )
{
    func1b47c();

    func1b43c();
}

[8004e9e0] = w(-1);
[8004e9dc] = w(-1);
[8004ea10] = w(0);
////////////////////////////////



////////////////////////////////
// func1b43c()

if( w[8004ea04] == 1 )
{
    A0 = w[80061c1c];
    func381b8();

    [8004ea04] = w(0);
}
////////////////////////////////



////////////////////////////////
// func1b47c()
if( w[8004ea00] == 1 )
{
    A0 = w[80061bb8];
    func39af4();

    if( w[8004e9ec] == 0 )
    {
        A0 = w[80061bb8];
        8001B4C0	jal    func3987c [$8003987c]
    }
    else
    {
        [8004e9a0] = w(w[80061bb8]);
    }

    [8004ea00] = w(0);
    [8004e9ec] = w(0);
}
////////////////////////////////



////////////////////////////////
// func19dcc()
S2 = A0; // file?
S3 = A1;
S1 = 0;

if( ( w[80010000] + 1 ) >= 2 )
{
    A0 = 80018198; // filename "c:\lserrmem.txt"
    func32c28(); // write debug file

    80019E14	j      L19e50 [$80019e50]
}

A0 = SP + 0110;
A1 = 00ff;
A2 = 0;
A3 = 0;
V0 = 0280;
[SP + 0114] = h(V0);
V0 = 01e0;
[SP + 0110] = h(0);
[SP + 0112] = h(0);
80019E40	jal    system_clear_image [$800445dc]
[SP + 0116] = h(V0);

L19e48:	; 80019E48
80019E48	j      L19e48 [$80019e48]
80019E4C	nop

L19e50:	; 80019E50
80019E50	jal    func320d8 [$800320d8]
S0 = 00f0;
A0 = SP + 0030;
A1 = 0;
A2 = 0;
A3 = 0180;
80019E68	jal    func437a0 [$800437a0]
[SP + 0010] = w(S0);
A0 = SP + 00e8;
A1 = 0;
A2 = 00f0;
A3 = 0180;
80019E80	jal    func43858 [$80043858]
[SP + 0010] = w(S0);
A0 = SP + 008c;
A1 = 0;
A2 = 00f0;
A3 = 0180;
80019E98	jal    func437a0 [$800437a0]
[SP + 0010] = w(S0);
A0 = SP + 00fc;
A1 = 0;
A2 = 0;
A3 = 0180;
80019EB0	jal    func43858 [$80043858]
[SP + 0010] = w(S0);
A0 = 0;
system_psyq_draw_sync_callback();

80019EC0	jal    func36298 [$80036298]
A0 = 0;
A0 = 0010;
A1 = 0010;
A2 = 0120;
A3 = 00f0;
V0 = 01f4;
V1 = 03c0;
[SP + 0010] = w(V0);
V0 = 0100;
[SP + 001c] = w(V0);
V0 = 01ff;
[SP + 0014] = w(0);
[SP + 0018] = w(V1);
[SP + 0020] = w(V1);
[SP + 0024] = w(V0);
80019F00	jal    func37390 [$80037390]
[SP + 0028] = w(0);
V1 = w[8004e964];
V0 = 0001;
[SP + 00a4] = b(V0);
[SP + 0048] = b(V0);
[SP + 0049] = b(0);
[SP + 004a] = b(0);
[SP + 004b] = b(0);
[SP + 00a5] = b(0);
[SP + 00a6] = b(0);
[SP + 00a7] = b(0);
V1 = V1 + 0001;
[8004e964] = w(V1);
80019F40	jal    system_psyq_set_disp_mask [$800443ac]
A0 = 0001;

L19f48:	; 80019F48
S0 = S1 & 0001;
80019F4C	bne    s0, zero, L19f58 [$80019f58]
A0 = SP + 0030;
A0 = SP + 008c;

L19f58:	; 80019F58
80019F58	jal    func44abc [$80044abc]
80019F5C	nop
80019F60	bne    s0, zero, L19f6c [$80019f6c]
A0 = SP + 00e8;
A0 = SP + 00fc;

L19f6c:	; 80019F6C
80019F6C	jal    func44d14 [$80044d14]
80019F70	nop
80019F74	jal    func371cc [$800371cc]
A0 = 0;

A0 = 800181a8;
A1 = S2;
80019F84	jal    func36eb4 [$80036eb4]

80019F8C	lui    a0, $8002
80019F90	addiu  a0, a0, $81bc (=-$7e44)
80019F94	jal    func36eb4 [$80036eb4]
A1 = S3;
A1 = w[8004e964];
80019FA4	lui    a0, $8002
80019FA8	addiu  a0, a0, $81c8 (=-$7e38)
80019FAC	jal    func36eb4 [$80036eb4]
80019FB0	nop
80019FB4	lui    a0, $8002
80019FB8	addiu  a0, a0, $81d4 (=-$7e2c)
80019FBC	jal    func36eb4 [$80036eb4]
A1 = S1;
80019FC4	lui    a0, $8002
80019FC8	addiu  a0, a0, $81e0 (=-$7e20)
80019FCC	jal    func36eb4 [$80036eb4]
80019FD0	nop
80019FD4	lui    a0, $8002
80019FD8	addiu  a0, a0, $8200 (=-$7e00)
80019FDC	jal    func36eb4 [$80036eb4]
80019FE0	nop
V0 = S2 & 0080;
80019FE8	beq    v0, zero, L1a048 [$8001a048]
V0 = S2 << 02;
80019FF0	lui    at, $8005
AT = AT + V0;
A1 = w[AT + e768];
80019FFC	lui    a0, $8002
8001A000	addiu  a0, a0, $8204 (=-$7dfc)
8001A004	jal    func36eb4 [$80036eb4]
8001A008	nop
V0 = 0082;
8001A010	bne    s2, v0, L1a048 [$8001a048]
A0 = SP + 0120;
8001A018	jal    func319d4 [$800319d4]
A1 = SP + 0124;
A1 = w[SP + 0120];
8001A024	lui    a0, $8002
8001A028	addiu  a0, a0, $8208 (=-$7df8)
8001A02C	jal    func36eb4 [$80036eb4]
8001A030	nop
A1 = w[SP + 0124];
8001A038	lui    a0, $8002
8001A03C	addiu  a0, a0, $821c (=-$7de4)
8001A040	jal    func36eb4 [$80036eb4]
A2 = A1;

L1a048:	; 8001A048
8001A048	jal    system_psyq_wait_frames [$8004b3f4]
A0 = 0;
8001A050	j      L19f48 [$80019f48]
S1 = S1 + 0001;
////////////////////////////////



////////////////////////////////
// func19d24()
if( hu[80058c0c] == 090c ) // pressed buttons start select L1 R1
{
    func19d54();
}
////////////////////////////////



////////////////////////////////
// func19d54()
80019D5C	jal    func4038c [$8004038c]
80019D60	nop
80019D64	jal    system_psyq_reset_graph [$80043f88]
A0 = 0;
80019D6C	jal    func281e4 [$800281e4]
80019D70	nop
80019D74	jal    func37c68 [$80037c68]
80019D78	nop
80019D7C	jal    func4d13c [$8004d13c]
80019D80	nop
80019D84	jal    func36298 [$80036298]
A0 = 0;

A0 = 0;
system_psyq_draw_sync_callback();

80019D94	jal    func4b678 [$8004b678]
A0 = 0;
80019D9C	jal    func40d4c [$80040d4c]
80019DA0	nop
80019DA4	jal    func4076c [$8004076c]
80019DA8	nop
80019DAC	jal    func4036c [$8004036c]
80019DB0	nop
80019DB4	jal    func195b8 [$800195b8]
////////////////////////////////



////////////////////////////////
// func2dbf4()

S1 = 0;
S7 = A2;
S6 = A3;
FP = w[A0 + 0000];
V1 = w[SP + 0058];
S5 = hu[SP + 005c];
S4 = hu[SP + 0060];
V0 = FP << 02;
V0 = V0 + 0004;
8002DC44	blez   fp, L2ddb8 [$8002ddb8]
S0 = A0 + V0;
V0 = A1 << 10;
S3 = V0 >> 10;
V0 = V1 << 10;
S2 = V0 >> 10;

loop2dc5c:	; 8002DC5C
V1 = w[S0 + 0000];
V0 = 1100;
8002DC64	bne    v1, v0, L2dccc [$8002dccc]
S0 = S0 + 0004;
V0 = 0001;
8002DC70	beq    s3, v0, L2dc8c [$8002dc8c]
8002DC74	nop
V0 = 0002;
8002DC7C	beq    s3, v0, L2dca8 [$8002dca8]
8002DC80	nop
8002DC84	j      L2dd3c [$8002dd3c]
8002DC88	nop

L2dc8c:	; 8002DC8C
V0 = hu[S0 + 0004];
8002DC90	nop
V0 = S7 + V0;
[SP + 0010] = h(V0);
V0 = hu[S0 + 0006];
8002DCA0	j      L2dd60 [$8002dd60]
V0 = S6 + V0;

L2dca8:	; 8002DCA8
V0 = hu[S0 + 0000];
V1 = hu[S0 + 0004];
V0 = S7 + V0;
V1 = V1 + V0;
[SP + 0010] = h(V1);
V0 = hu[S0 + 0002];
V1 = hu[S0 + 0006];
8002DCC4	j      L2dd30 [$8002dd30]
V0 = S6 + V0;

L2dccc:	; 8002DCCC
V0 = 1101;
8002DCD0	bne    v1, v0, L2ddbc [$8002ddbc]
V0 = 0001;
8002DCD8	beq    s2, v0, L2dcf4 [$8002dcf4]
8002DCDC	nop
V0 = 0002;
8002DCE4	beq    s2, v0, L2dd10 [$8002dd10]
8002DCE8	nop
8002DCEC	j      L2dd3c [$8002dd3c]
8002DCF0	nop

L2dcf4:	; 8002DCF4
V0 = hu[S0 + 0004];
8002DCF8	nop
V0 = S5 + V0;
[SP + 0010] = h(V0);
V0 = hu[S0 + 0006];
8002DD08	j      L2dd60 [$8002dd60]
V0 = S4 + V0;

L2dd10:	; 8002DD10
V0 = hu[S0 + 0000];
V1 = hu[S0 + 0004];
V0 = S5 + V0;
V1 = V1 + V0;
[SP + 0010] = h(V1);
V0 = hu[S0 + 0002];
V1 = hu[S0 + 0006];
V0 = S4 + V0;

L2dd30:	; 8002DD30
V1 = V1 + V0;
8002DD34	j      L2dd64 [$8002dd64]
[SP + 0012] = h(V1);

L2dd3c:	; 8002DD3C
V0 = hu[S0 + 0000];
V1 = hu[S0 + 0004];
8002DD44	nop
V0 = V0 + V1;
[SP + 0010] = h(V0);
V0 = hu[S0 + 0002];
V1 = hu[S0 + 0006];
8002DD58	nop
V0 = V0 + V1;

L2dd60:	; 8002DD60
[SP + 0012] = h(V0);

L2dd64:	; 8002DD64
S0 = S0 + 0008;
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
A0 = SP + 0010;
[SP + 0014] = h(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
A1 = S0;
8002DD84	jal    system_load_image [$8004470c]
[SP + 0016] = h(V0);
V1 = h[SP + 0014];
V0 = h[SP + 0016];
8002DD94	nop
8002DD98	mult   v1, v0
8002DD9C	mflo   t0
V0 = T0 << 01;
S0 = S0 + V0;
S1 = S1 + 0001;
V0 = S1 < FP;
8002DDB0	bne    v0, zero, loop2dc5c [$8002dc5c]
8002DDB4	nop

L2ddb8:	; 8002DDB8
V0 = 0;

L2ddbc:	; 8002DDBC
////////////////////////////////



////////////////////////////////
// func288a4()
V0 = w[8004f4d4];
[8004f4d4] = w(A0);
return V0;
////////////////////////////////



////////////////////////////////
// func36eb4()
[SP + 18] = w(A0);
[SP + 1c] = w(A1);
[SP + 20] = w(A2);
[SP + 24] = w(A3);

if( w[80058a30] != 0 )
{
    A0 = 0;
    A1 = A0;
    A2 = SP + 1c;
    80036EE8	jal    func365c0 [$800365c0]
}
////////////////////////////////



////////////////////////////////
// func365c0()
S4 = A1;

A0 = bu[S4];
S3 = A2;
S5 = 0;
if( A0 == 0 )
{
    return 0;
}

S7 = 2d;
S6 = 2b;

L36608:	; 80036608
    V0 = 25;
    80036608	bne    a0, v0, L36a88 [$80036a88]
    8003660C	nop
    80036610	lui    a1, $8006
    80036614	addiu  a1, a1, $9868 (=-$6798)
    V0 = w[A1 + 0000];
    V1 = w[A1 + 0004];
    A0 = w[A1 + 0008];
    [SP + 0110] = w(V0);
    [SP + 0114] = w(V1);
    [SP + 0118] = w(A0);
    V0 = w[A1 + 000c];
    80036634	nop
    [SP + 011c] = w(V0);
    A1 = 0020;
    V1 = 0030;

    L36644:	; 80036644
    S4 = S4 + 1;
    A0 = bu[S4];
    80036650	bne    a0, s7, L3666c [$8003666c]
    80036654	nop
    V0 = w[SP + 0110];
    8003665C	nop
    V0 = V0 | 0001;
    80036664	j      L36644 [$80036644]
    [SP + 0110] = w(V0);

    L3666c:	; 8003666C
    8003666C	bne    a0, s6, L36688 [$80036688]
    80036670	nop
    V0 = w[SP + 0110];
    80036678	nop
    V0 = V0 | 0002;
    80036680	j      L36644 [$80036644]
    [SP + 0110] = w(V0);

    L36688:	; 80036688
    80036688	bne    a0, a1, L36698 [$80036698]
    8003668C	nop
    80036690	j      L36644 [$80036644]
    [SP + 0111] = b(A0);

    L36698:	; 80036698
    80036698	bne    a0, v1, L366b4 [$800366b4]
    V0 = 002a;
    V0 = w[SP + 0110];
    800366A4	nop
    V0 = V0 | 0004;
    800366AC	j      L36644 [$80036644]
    [SP + 0110] = w(V0);

    L366b4:	; 800366B4
    800366B4	bne    a0, v0, L3671c [$8003671c]
    800366B8	addiu  v0, a0, $ffd0 (=-$30)
    S3 = S3 + 0004;
    V0 = w[S3 + fffc];
    800366C4	nop
    800366C8	bgez   v0, L366e4 [$800366e4]
    [SP + 0114] = w(V0);
    V1 = w[SP + 0110];
    V0 = 0 - V0;
    [SP + 0114] = w(V0);
    V1 = V1 | 0001;
    [SP + 0110] = w(V1);

    L366e4:	; 800366E4
    S4 = S4 + 0001;
    A0 = bu[S4 + 0000];
    800366EC	j      L36728 [$80036728]
    V0 = 002e;

    loop366f4:	; 800366F4
    V0 = w[SP + 0114];
    S4 = S4 + 0001;
    V1 = V0 << 02;
    V1 = V1 + V0;
    V1 = V1 << 01;
    80036708	addiu  v1, v1, $ffd0 (=-$30)
    V1 = V1 + A0;
    A0 = bu[S4 + 0000];
    [SP + 0114] = w(V1);
    80036718	addiu  v0, a0, $ffd0 (=-$30)

    L3671c:	; 8003671C
    V0 = V0 < 000a;
    80036720	bne    v0, zero, loop366f4 [$800366f4]
    V0 = 002e;

    L36728:	; 80036728
    80036728	bne    a0, v0, L367b0 [$800367b0]
    V0 = 002a;
    S4 = S4 + 0001;
    A0 = bu[S4 + 0000];
    80036738	nop
    8003673C	bne    a0, v0, L36784 [$80036784]
    80036740	addiu  v0, a0, $ffd0 (=-$30)
    S3 = S3 + 0004;
    S4 = S4 + 0001;
    V0 = w[S3 + fffc];
    A0 = bu[S4 + 0000];
    80036754	j      L36790 [$80036790]
    [SP + 0118] = w(V0);

    loop3675c:	; 8003675C
    V0 = w[SP + 0118];
    S4 = S4 + 0001;
    V1 = V0 << 02;
    V1 = V1 + V0;
    V1 = V1 << 01;
    80036770	addiu  v1, v1, $ffd0 (=-$30)
    V1 = V1 + A0;
    A0 = bu[S4 + 0000];
    [SP + 0118] = w(V1);
    80036780	addiu  v0, a0, $ffd0 (=-$30)

    L36784:	; 80036784
    V0 = V0 < 000a;
    80036788	bne    v0, zero, loop3675c [$8003675c]
    8003678C	nop

    L36790:	; 80036790
    V0 = w[SP + 0118];
    80036794	nop
    80036798	bltz   v0, L367b0 [$800367b0]
    8003679C	nop
    V0 = w[SP + 0110];
    800367A4	nop
    V0 = V0 | 0008;
    [SP + 0110] = w(V0);

    L367b0:	; 800367B0
    V1 = w[SP + 0110];
    800367B4	nop
    V0 = V1 & 0001;
    800367BC	beq    v0, zero, L367d0 [$800367d0]
    S0 = SP + 0110;
    800367C4	addiu  v0, zero, $fffb (=-$5)
    V0 = V1 & V0;
    [SP + 0110] = w(V0);

    L367d0:	; 800367D0
    800367D0	addiu  v1, a0, $ffa8 (=-$58)
    V0 = V1 < 0021;
    800367D8	beq    v0, zero, L36a7c [$80036a7c]
    V0 = V1 << 02;
    800367E0	lui    at, $8002
    AT = AT + V0;
    V0 = w[AT + 8bec];
    800367EC	nop
    800367F0	jr     v0 
    800367F4	nop

    S3 = S3 + 0004;
    A0 = w[S3 + fffc];
    80036800	j      L36854 [$80036854]
    V0 = 0002;
    S3 = S3 + 0004;
    A0 = w[S3 + fffc];
    80036810	nop
    80036814	bgez   a0, L36828 [$80036828]
    80036818	nop
    A0 = 0 - A0;
    80036820	j      L36840 [$80036840]
    [SP + 0111] = b(S7);

    L36828:	; 80036828
    V0 = w[SP + 0110];
    8003682C	nop
    V0 = V0 & 0002;
    80036834	beq    v0, zero, L36858 [$80036858]
    V0 = 000a;
    [SP + 0111] = b(S6);

    L36840:	; 80036840
    80036840	j      L36858 [$80036858]
    V0 = 000a;
    S3 = S3 + 0004;
    A0 = w[S3 + fffc];
    V0 = 000a;

    L36854:	; 80036854
    [SP + 0111] = b(0);

    L36858:	; 80036858
    [SP + 011c] = w(V0);
    V1 = w[SP + 0110];
    80036860	nop
    V0 = V1 & 0008;
    80036868	bne    v0, zero, L368a8 [$800368a8]
    V0 = V1 & 0004;
    80036870	beq    v0, zero, L36894 [$80036894]
    80036874	nop
    V1 = w[SP + 0114];
    V0 = bu[SP + 0111];
    80036880	nop
    80036884	beq    v0, zero, L36894 [$80036894]
    [SP + 0118] = w(V1);
    8003688C	addiu  v0, v1, $ffff (=-$1)
    [SP + 0118] = w(V0);

    L36894:	; 80036894
    V0 = w[SP + 0118];
    80036898	nop
    8003689C	bgtz   v0, L368a8 [$800368a8]
    V0 = 0001;
    [SP + 0118] = w(V0);

    L368a8:	; 800368A8
    800368A8	beq    a0, zero, L368e8 [$800368e8]
    S1 = 0;

    loop368b0:	; 800368B0
    V0 = w[SP + 011c];
    800368B4	nop
    800368B8	divu   a0, v0
    800368BC	mfhi   v1
    800368C0	addiu  s0, s0, $ffff (=-$1)
    V1 = V1 + 0030;
    [S0 + 0000] = b(V1);
    V0 = w[SP + 011c];
    800368D0	nop
    800368D4	divu   a0, v0
    800368D8	mflo   a0
    800368DC	nop
    800368E0	bne    a0, zero, loop368b0 [$800368b0]
    S1 = S1 + 0001;

    L368e8:	; 800368E8
    V0 = w[SP + 0118];
    800368EC	nop
    V0 = S1 < V0;
    800368F4	beq    v0, zero, L36920 [$80036920]
    800368F8	nop
    V1 = 0030;
    80036900	addiu  s0, s0, $ffff (=-$1)

    loop36904:	; 80036904
    [S0 + 0000] = b(V1);
    V0 = w[SP + 0118];
    S1 = S1 + 0001;
    V0 = S1 < V0;
    80036914	bne    v0, zero, loop36904 [$80036904]
    80036918	addiu  s0, s0, $ffff (=-$1)
    S0 = S0 + 0001;

    L36920:	; 80036920
    V0 = bu[SP + 0111];
    80036924	nop
    80036928	beq    v0, zero, L36a98 [$80036a98]
    8003692C	nop
    80036930	addiu  s0, s0, $ffff (=-$1)
    [S0 + 0000] = b(V0);
    80036938	j      L36a98 [$80036a98]
    S1 = S1 + 0001;
    V1 = w[SP + 0110];
    V0 = 0008;
    [SP + 0118] = w(V0);
    V1 = V1 | 0008;
    [SP + 0110] = w(V1);
    80036954	lui    a1, $8002
    80036958	addiu  a1, a1, $8bc4 (=-$743c)
    8003695C	j      L36970 [$80036970]
    S3 = S3 + 0004;
    80036964	lui    a1, $8002
    80036968	addiu  a1, a1, $8bd8 (=-$7428)
    S3 = S3 + 0004;

    L36970:	; 80036970
    V1 = w[SP + 0110];
    A0 = w[S3 + fffc];
    V0 = V1 & 0008;
    8003697C	bne    v0, zero, L369ac [$800369ac]
    V0 = V1 & 0004;
    80036984	beq    v0, zero, L36998 [$80036998]
    80036988	nop
    V0 = w[SP + 0114];
    80036990	nop
    [SP + 0118] = w(V0);

    L36998:	; 80036998
    V0 = w[SP + 0118];
    8003699C	nop
    800369A0	bgtz   v0, L369ac [$800369ac]
    V0 = 0001;
    [SP + 0118] = w(V0);

    L369ac:	; 800369AC
    800369AC	beq    a0, zero, L369d4 [$800369d4]
    S1 = 0;

    loop369b4:	; 800369B4
    800369B4	addiu  s0, s0, $ffff (=-$1)
    V0 = A0 & 000f;
    A0 = A0 >> 04;
    V0 = A1 + V0;
    V0 = bu[V0 + 0000];
    S1 = S1 + 0001;
    800369CC	bne    a0, zero, loop369b4 [$800369b4]
    [S0 + 0000] = b(V0);

    L369d4:	; 800369D4
    V0 = w[SP + 0118];
    800369D8	nop
    V0 = S1 < V0;
    800369E0	beq    v0, zero, L36a98 [$80036a98]
    V1 = 0030;
    800369E8	addiu  s0, s0, $ffff (=-$1)

    loop369ec:	; 800369EC
    [S0 + 0000] = b(V1);
    V0 = w[SP + 0118];
    S1 = S1 + 0001;
    V0 = S1 < V0;
    800369FC	bne    v0, zero, loop369ec [$800369ec]
    80036A00	addiu  s0, s0, $ffff (=-$1)
    80036A04	j      L36a98 [$80036a98]
    S0 = S0 + 0001;
    80036A0C	addiu  s0, s0, $ffff (=-$1)
    S3 = S3 + 0004;
    V0 = w[S3 + fffc];
    S1 = 0001;
    80036A1C	j      L36a98 [$80036a98]
    [S0 + 0000] = b(V0);
    S3 = S3 + 0004;
    V0 = w[SP + 0110];
    S0 = w[S3 + fffc];
    V0 = V0 & 0008;
    80036A34	bne    v0, zero, L36a4c [$80036a4c]
    A0 = S0;
    80036A3C	jal    func3fa40 [$8003fa40]
    A0 = S0;
    80036A44	j      L36a98 [$80036a98]
    S1 = V0;

    L36a4c:	; 80036A4C
    A2 = w[SP + 0118];
    80036A50	jal    func3f7c0 [$8003f7c0]
    A1 = 0;
    80036A58	bne    v0, zero, L36a98 [$80036a98]
    S1 = V0 - S0;
    S1 = w[SP + 0118];
    80036A64	j      L36a98 [$80036a98]
    80036A68	nop
    S3 = S3 + 0004;
    S0 = w[S3 + fffc];
    80036A74	j      L36b38 [$80036b38]
    [S0 + 0000] = w(S5);

    L36a7c:	; 80036A7C
    V0 = 0025;
    80036A80	bne    a0, v0, L36b50 [$80036b50]

    L36a88:	; 80036A88
    S5 = S5 + 1;

    func36598();

    80036A90	j      L36b3c [$80036b3c]
    S4 = S4 + 0001;

    L36a98:	; 80036A98
    V0 = w[SP + 0114];
    80036A9C	nop
    V0 = S1 < V0;
    80036AA4	beq    v0, zero, L36ae4 [$80036ae4]
    80036AA8	nop
    V0 = w[SP + 0110];
    80036AB0	nop
    V0 = V0 & 0001;
    80036AB8	bne    v0, zero, L36ae4 [$80036ae4]
    80036ABC	nop

    loop36ac0:	; 80036AC0
    A0 = 20;
    func36598();

    V0 = w[SP + 0114];
    80036ACC	nop
    80036AD0	addiu  v0, v0, $ffff (=-$1)
    [SP + 0114] = w(V0);
    V0 = S1 < V0;
    80036ADC	bne    v0, zero, loop36ac0 [$80036ac0]
    S5 = S5 + 0001;

    L36ae4:	; 80036AE4
    80036AE4	blez   s1, L36b08 [$80036b08]
    80036AE8	nop
    S2 = S1 + S0;

    loop36af0:	; 80036AF0
        A0 = bu[S0];
        func36598();

        S0 = S0 + 0001;
        V0 = S0 < S2;
    80036B00	bne    v0, zero, loop36af0 [$80036af0]

    L36b08:	; 80036B08
    V0 = w[SP + 0114];
    80036B0C	nop
    V0 = S1 < V0;
    S5 = S5 + S1;
    if( V0 != 0 )
    {
        loop36b1c:	; 80036B1C
            A0 = 20;
            func36598(); // call func from 8004fc34

            V0 = w[SP + 0114];
            S5 = S5 + 0001;
            S1 = S1 + 0001;
            V0 = S1 < V0;
        80036B30	bne    v0, zero, loop36b1c [$80036b1c]
    }

    L36b38:	; 80036B38
    S4 = S4 + 0001;

    L36b3c:	; 80036B3C
    A0 = bu[S4 + 0000];
80036B44	bne    a0, zero, L36608 [$80036608]

L36b50:	; 80036B50
return S5;
////////////////////////////////



////////////////////////////////
// func36598()
V0 = w[8004fc34]; // 80036f84
800365A8	jalr   v0 ra
////////////////////////////////



////////////////////////////////
// func36f84()
A2 = w[80058a30];
A3 = A0;
80036F90	beq    a2, zero, L3716c [$8003716c]

V1 = h[A2 + 0032];
A1 = h[A2 + 0016];
V0 = h[A2 + 000e];
A0 = h[A2 + 0012];
V1 = V1 + A1;
V0 = V0 + A0;
V0 = V0 < V1;
80036FB4	bne    v0, zero, L3716c [$8003716c]
80036FB8	nop
V1 = h[A2 + 0034];
V0 = h[A2 + 002c];
80036FC4	nop
V0 = V0 < V1;
80036FCC	bne    v0, zero, L3716c [$8003716c]
V0 = A3 < 0020;
80036FD4	beq    v0, zero, L37000 [$80037000]
V0 = 000a;
80036FDC	bne    a3, v0, L3716c [$8003716c]
80036FE0	nop
V1 = hu[A2 + 0032];
A0 = hu[A2 + 0016];
V0 = hu[A2 + 0036];
V1 = V1 + A0;
[A2 + 0030] = h(V0);
80036FF8	j      L3716c [$8003716c]
[A2 + 0032] = h(V1);

L37000:	; 80037000
V0 = hu[A2 + 002e];
80037004	nop
V0 = V0 & 0004;
8003700C	beq    v0, zero, L37020 [$80037020]
V0 = A3 < 0060;
80037014	bne    v0, zero, L37020 [$80037020]
80037018	nop
8003701C	addiu  a3, a3, $ffe0 (=-$20)

L37020:	; 80037020
V0 = hu[A2 + 002e];
80037024	nop
V0 = V0 & 0008;
8003702C	beq    v0, zero, L37044 [$80037044]
80037030	addiu  a3, a3, $ffe0 (=-$20)
V0 = A2 + A3;
A1 = bu[V0 + 0064];
8003703C	j      L37048 [$80037048]
80037040	nop

L37044:	; 80037044
A1 = h[A2 + 0014];

L37048:	; 80037048
V0 = h[A2 + 0030];
V1 = h[A2 + 000c];
A0 = h[A2 + 0010];
V0 = V0 + A1;
V1 = V1 + A0;
V0 = V0 < V1;
80037060	bne    v0, zero, L37094 [$80037094]
80037064	nop
V0 = hu[A2 + 0000];
8003706C	nop
V0 = V0 & 0008;
80037074	bne    v0, zero, L3716c [$8003716c]
80037078	nop
V1 = hu[A2 + 0032];
A0 = hu[A2 + 0016];
V0 = hu[A2 + 0036];
V1 = V1 + A0;
[A2 + 0030] = h(V0);
[A2 + 0032] = h(V1);

L37094:	; 80037094
80037094	beq    a3, zero, L3715c [$8003715c]
80037098	nop
V1 = w[A2 + 0038];
V0 = w[A2 + 0018];
800370A4	nop
[V1 + 0004] = w(V0);
V1 = h[A2 + 0032];
V0 = h[A2 + 0030];
A0 = w[A2 + 0038];
V1 = V1 << 10;
V0 = V0 | V1;
[A0 + 0008] = w(V0);
V0 = hu[A2 + 002e];
800370C8	nop
V0 = V0 & 0002;
800370D0	beq    v0, zero, L37104 [$80037104]
V0 = A3 & 0018;
V0 = V0 >> 02;
V0 = V0 + A2;
A0 = A3 & 0007;
V1 = w[A2 + 0038];
V0 = hu[V0 + 003c];
A0 = A0 << 04;
[V1 + 000e] = h(V0);
V0 = A3 & 0060;
V1 = bu[A2 + 00d2];
800370FC	j      L37130 [$80037130]
V0 = V0 >> 01;

L37104:	; 80037104
V0 = A3 & 0030;
V0 = V0 >> 03;
V0 = V0 + A2;
A0 = A3 & 000f;
V1 = w[A2 + 0038];
V0 = hu[V0 + 003c];
A0 = A0 << 03;
[V1 + 000e] = h(V0);
V0 = A3 & 00c0;
V1 = bu[A2 + 00d2];
V0 = V0 >> 03;

L37130:	; 80037130
V1 = V1 + V0;
V1 = V1 << 08;
V0 = w[A2 + 0038];
A0 = A0 | V1;
[V0 + 000c] = h(A0);
V1 = hu[A2 + 0034];
V0 = w[A2 + 0038];
V1 = V1 + 0001;
V0 = V0 + 0010;
[A2 + 0038] = w(V0);
[A2 + 0034] = h(V1);

L3715c:	; 8003715C
V0 = hu[A2 + 0030];
80037160	nop
V0 = V0 + A1;
[A2 + 0030] = h(V0);

L3716c:	; 8003716C
////////////////////////////////



////////////////////////////////
// system_set_pack_global_pointers
number_of_files = w[A0];
if (number_of_files != 0)
{
    A1 = 1;
    loop33268:	; 80033268
        [A0 + A1 * 4] = w(A0 + w[A0 + A1 * 4]); // set global offset
        A1 = A1 + 1;
        V0 = A1 < number_of_files;
    80033284	beq    v0, zero, loop33268 [$80033268]
}

return number_of_files;
////////////////////////////////



////////////////////////////////
// system_side_of_vector
8004A5B4	mtc2   a0,l33
8004A5B8	mtc2   a2,gbk
8004A5BC	mtc2   a1,rbk
8004A5C8	gte_func26zero,r11r12
8004A5CC	mfc2   v0,ofx
8004A5D0	jr     ra 
////////////////////////////////



////////////////////////////////
// system_cos()
return h[80051a92 + (A0 & 0fff) * 4];
////////////////////////////////



////////////////////////////////
// system_sin
return h[80051a90 + (A0 & 0fff) * 4];
////////////////////////////////



////////////////////////////////
// system_get_rotation_based_on_vector_x_y
//A0 - Y
//A1 - X
//V0 - rotation for entity

A2 = 0;
A3 = 0;

if (A1 == 0 && A0 == 0)
{
    return 0;
}

if (A1 < 0)
{
    A2 = 1;
    A1 = -A1;
}

if (A0 < 0)
{
    A3 = 1;
    A0 = -A0;
}



if (A0 >= A1)
{
    if (A0 & 7fe00000)
    {
        V0 = A1 >> 10;
        A0 = A0 / V0;
    }
    else
    {
        V0 = A0 << 10;
        A0 = V0 / A1;
    }

    V1 = h[800566d0 + A0 * 2];
}
else
{
    if (A1 & 7fe00000)
    {
        V0 = A0 >> 10;
        A0 = A1 / V0;
    }
    else
    {
        V0 = A1 << 10;
        A0 = V0 / A0;
    }

    V1 = 0400 - h[800566d0 + A0 * 2];
}

if (A2 != 0)
{
    V1 = 0800 - V1;
}

if (A3 != 0)
{
    V1 = -V1;
}

V0 = V1;
////////////////////////////////



////////////////////////////////
// system_get_random_value_from_to

if (A0 == FF)
{
    return FF;
}
if (A1 == 0)
{
    return 0;
}

if (A0 == A1)
{
    return A0;
}

S0 = A1 - A0;
if (S0 < FF)
{
    system_get_random_2_bytes;
    V0 = V0 & FF;

    V1 = S0 + 1;
    V1 = V0 MOD V1; 1F MOD 3 = 1
    V1 = A0 + V1;
    V0 = V1;
}
else
{
    system_get_random_2_bytes;
    V0 = V0 & FF;
}

return V0;
////////////////////////////////



////////////////////////////////
// system_get_random_2_bytes
V0 = w[80059898];
V0 = V0 * 41C64E6D + 3039;
[80059898] = w(V0);
V0 = V0 >> 10;
return V0 & 7FFF;
////////////////////////////////



////////////////////////////////
// func33560
V0 = hu[A0 + 0]
return bu[A0 + V0 * 2 + A1 * 2 + 6];
////////////////////////////////



////////////////////////////////
// func33584
V0 = hu[A0 + 0]
return bu[A0 + V0 * 2 + A1 * 2 + 6 + 1];
////////////////////////////////



////////////////////////////////
// func495f4()
[A0 + 0] = h((h[A0 + 0] * w[A1 + 0]) >> c);
[A0 + 2] = h((h[A0 + 2] * w[A1 + 0]) >> c);
[A0 + 4] = h((h[A0 + 4] * w[A1 + 0]) >> c);
[A0 + 6] = h((h[A0 + 6] * w[A1 + 4]) >> c);
[A0 + 8] = h((h[A0 + 8] * w[A1 + 4]) >> c);
[A0 + a] = h((h[A0 + a] * w[A1 + 4]) >> c);
[A0 + c] = h((h[A0 + c] * w[A1 + 8]) >> c);
[A0 + e] = h((h[A0 + e] * w[A1 + 8]) >> c);
[A0 + 10] = h((h[A0 + 10] * w[A1 + 8]) >> c);

return A0;
////////////////////////////////



////////////////////////////////
// func49c74()
[A0 + 0] = h((h[A0 + 0] * w[A1 + 0]) >> c);
[A0 + 2] = h((h[A0 + 2] * w[A1 + 4]) >> c);
[A0 + 4] = h((h[A0 + 4] * w[A1 + 8]) >> c);
[A0 + 6] = h((h[A0 + 6] * w[A1 + 0]) >> c);
[A0 + 8] = h((h[A0 + 8] * w[A1 + 4]) >> c);
[A0 + a] = h((h[A0 + a] * w[A1 + 8]) >> c);
[A0 + c] = h((h[A0 + c] * w[A1 + 0]) >> c);
[A0 + e] = h((h[A0 + e] * w[A1 + 4]) >> c);
[A0 + 10] = h((h[A0 + 10] * w[A1 + 8]) >> c);

return A0;
////////////////////////////////



////////////////////////////////
// system_get_root_counter_value()

A0 = A0 & ffff;

if( A0 < 3 )
{
    V0 = w[80055aa0]; // 1f801100
    return hu[V0 + A0 * 10]; // current root counter X value
}

return 0;
////////////////////////////////



////////////////////////////////
// system_root_counter_setup()

T0 = A0 & ffff;

if( T0 >= 3 )
{
    return 0;
}

root = w[80055aa0]; // 1f801100

// 6 IRQ Once/Repeat Mode    (0=One-shot, 1=Repeatedly)
// 3 Reset counter to 0000h  (0=After Counter=FFFFh, 1=After Counter=Target)
counter_mode = 0048;

[root + T0 * 10 + 4] = h(0); // Timer 0..2 Counter Mode
[root + T0 * 10 + 8] = h(A1); // Timer 0..2 Counter Target Value

if( T0 < 2 )
{
    if( A2 & 0010 )
    {
        counter_mode = 0049;
    }

    if( ( A2 & 0001 ) == 0 )
    {
        counter_mode = counter_mode | 0100;
    }
}
else if( T0 == 2 )
{
    if( ( A2 & 0001 ) == 0 )
    {
        // 10 Interrupt Request       (0=Yes, 1=No) (Set after Writing)    (W=1) (R)
        counter_mode = 0248;
    }
}

if( A2 & 1000 )
{
    // 4 IRQ when Counter=Target (0=Disable, 1=Enable)
    counter_mode = counter_mode | 0010;
}

[root + T0 * 10 + 4] = h(counter_mode); // Timer 0..2 Counter Mode

return 1;
////////////////////////////////



////////////////////////////////
// system_root_counter_enable()

A0 = A0 & ffff;

A1 = w[80055a9c]; // 1f801070
[A1 + 4] = w(w[A1 + 4] | w[80055aa4 + A0 * 4]); // I_MASK - Interrupt mask register

return A0 < 3;
////////////////////////////////
