////////////////////////////////
// func36598()
V0 = w[8004fc34]; // 80036f84
800365A8	jalr   v0 ra
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
// func36b80
80036B80	lui    v1, $8006
80036B84	lw     v1, $8a30(v1)
80036B88	nop
80036B8C	lhu    v0, $0000(v1)
80036B90	nop
80036B94	or     v0, v0, a0
80036B98	jr     ra 
80036B9C	sh     v0, $0000(v1)
////////////////////////////////



////////////////////////////////
// func36ba0
80036BA0	lui    v0, $8006
80036BA4	lw     v0, $8a30(v0)
80036BA8	nop
80036BAC	lhu    v1, $0000(v0)
80036BB0	nor    a0, zero, a0
80036BB4	and    v1, v1, a0
80036BB8	jr     ra 
80036BBC	sh     v1, $0000(v0)
////////////////////////////////



////////////////////////////////
// func36bc0
80036BC0	lui    v0, $8006
80036BC4	lw     v0, $8a30(v0)
80036BC8	nop
80036BCC	lh     v0, $0000(v0)
80036BD0	jr     ra 
80036BD4	nop
////////////////////////////////



////////////////////////////////
// func36bd8
80036BD8	lui    v1, $8006
80036BDC	lw     v1, $8a30(v1)
80036BE0	nop
80036BE4	lhu    v0, $002e(v1)
80036BE8	nop
80036BEC	or     v0, v0, a0
80036BF0	jr     ra 
80036BF4	sh     v0, $002e(v1)
////////////////////////////////



////////////////////////////////
// func36bf8
80036BF8	lui    v0, $8006
80036BFC	lw     v0, $8a30(v0)
80036C00	nop
80036C04	lhu    v1, $002e(v0)
80036C08	nor    a0, zero, a0
80036C0C	and    v1, v1, a0
80036C10	jr     ra 
80036C14	sh     v1, $002e(v0)
////////////////////////////////



////////////////////////////////
// func36c18
80036C18	lui    v0, $8006
80036C1C	lw     v0, $8a30(v0)
80036C20	nop
80036C24	lh     v0, $002e(v0)
80036C28	jr     ra 
80036C2C	nop
////////////////////////////////



////////////////////////////////
// func36c30
80036C30	lui    v0, $8006
80036C34	lw     v0, $8a30(v0)
80036C38	jr     ra 
80036C3C	sh     a0, $0014(v0)
////////////////////////////////



////////////////////////////////
// func36c40
80036C40	lui    v0, $8006
80036C44	lw     v0, $8a30(v0)
80036C48	jr     ra 
80036C4C	sh     a0, $0016(v0)
////////////////////////////////



////////////////////////////////
// func36c50
80036C50	lui    v0, $8006
80036C54	lw     v0, $8a30(v0)
80036C58	jr     ra 
80036C5C	sh     a0, $0030(v0)
////////////////////////////////



////////////////////////////////
// func36c60
80036C60	lui    v0, $8006
80036C64	lw     v0, $8a30(v0)
80036C68	jr     ra 
80036C6C	sh     a0, $0032(v0)
////////////////////////////////



////////////////////////////////
// func36c70
80036C70	lui    v0, $8006
80036C74	lw     v0, $8a30(v0)
80036C78	nop
80036C7C	sb     a0, $0018(v0)
80036C80	lui    v0, $8006
80036C84	lw     v0, $8a30(v0)
80036C88	nop
80036C8C	sb     a1, $0019(v0)
80036C90	lui    v0, $8006
80036C94	lw     v0, $8a30(v0)
80036C98	slti   a0, a0, $0080
80036C9C	bne    a0, zero, L36cbc [$80036cbc]
80036CA0	sb     a2, $001a(v0)
80036CA4	slti   v0, a1, $0080
80036CA8	bne    v0, zero, L36cbc [$80036cbc]
80036CAC	nop
80036CB0	slti   v0, a2, $0080
80036CB4	beq    v0, zero, L36cd4 [$80036cd4]
80036CB8	nop

L36cbc:	; 80036CBC
80036CBC	lui    v1, $8006
80036CC0	lw     v1, $8a30(v1)
80036CC4	nop
80036CC8	lbu    v0, $001b(v1)
80036CCC	j      L36cec [$80036cec]
80036CD0	andi   v0, v0, $00fe

L36cd4:	; 80036CD4
80036CD4	lui    v1, $8006
80036CD8	lw     v1, $8a30(v1)
80036CDC	nop
80036CE0	lbu    v0, $001b(v1)
80036CE4	nop
80036CE8	ori    v0, v0, $0001

L36cec:	; 80036CEC
80036CEC	jr     ra 
80036CF0	sb     v0, $001b(v1)
////////////////////////////////



////////////////////////////////
// func36cf4
80036CF4	addiu  sp, sp, $ffe8 (=-$18)
80036CF8	sw     ra, $0010(sp)
80036CFC	lui    a2, $8005
80036D00	addiu  a2, a2, $fc38 (=-$3c8)
80036D04	addu   a3, zero, zero

loop36d08:	; 80036D08
80036D08	sh     a1, $0000(a2)
80036D0C	addiu  a2, a2, $0002
80036D10	sh     a0, $0000(a2)
80036D14	addiu  a3, a3, $0001
80036D18	slti   v0, a3, $0008
80036D1C	bne    v0, zero, loop36d08 [$80036d08]
80036D20	addiu  a2, a2, $0002
80036D24	slti   v0, a3, $000c
80036D28	beq    v0, zero, L36d90 [$80036d90]
80036D2C	slti   v0, a3, $000e

loop36d30:	; 80036D30
80036D30	sh     a1, $0000(a2)
80036D34	addiu  a2, a2, $0002
80036D38	sh     a1, $0000(a2)
80036D3C	addiu  a2, a2, $0002
80036D40	sh     a0, $0000(a2)
80036D44	addiu  a2, a2, $0002
80036D48	sh     a0, $0000(a2)
80036D4C	addiu  a3, a3, $0001
80036D50	slti   v0, a3, $000c
80036D54	bne    v0, zero, loop36d30 [$80036d30]
80036D58	addiu  a2, a2, $0002
80036D5C	j      L36d90 [$80036d90]
80036D60	slti   v0, a3, $000e

loop36d64:	; 80036D64
80036D64	sh     a1, $0000(a2)
80036D68	addiu  v1, v1, $ffff (=-$1)
80036D6C	bgez   v1, loop36d64 [$80036d64]
80036D70	addiu  a2, a2, $0002
80036D74	ori    v1, zero, $0003

loop36d78:	; 80036D78
80036D78	sh     a0, $0000(a2)
80036D7C	addiu  v1, v1, $ffff (=-$1)
80036D80	bgez   v1, loop36d78 [$80036d78]
80036D84	addiu  a2, a2, $0002
80036D88	addiu  a3, a3, $0001
80036D8C	slti   v0, a3, $000e

L36d90:	; 80036D90
80036D90	bne    v0, zero, loop36d64 [$80036d64]
80036D94	ori    v1, zero, $0003
80036D98	ori    v1, zero, $0007

loop36d9c:	; 80036D9C
80036D9C	sh     a1, $0000(a2)
80036DA0	addiu  v1, v1, $ffff (=-$1)
80036DA4	bgez   v1, loop36d9c [$80036d9c]
80036DA8	addiu  a2, a2, $0002
80036DAC	ori    v1, zero, $0008

loop36db0:	; 80036DB0
80036DB0	sh     a0, $0000(a2)
80036DB4	addiu  v1, v1, $0001
80036DB8	slti   v0, v1, $0010
80036DBC	bne    v0, zero, loop36db0 [$80036db0]
80036DC0	addiu  a2, a2, $0002
80036DC4	lui    a0, $8006
80036DC8	addiu  a0, a0, $8a34 (=-$75cc)
80036DCC	lui    a1, $8005
80036DD0	addiu  a1, a1, $fc38 (=-$3c8)
80036DD4	jal    system_load_image [$8004470c]
80036DD8	nop
80036DDC	lw     ra, $0010(sp)
80036DE0	addiu  sp, sp, $0018
80036DE4	jr     ra 
80036DE8	nop
////////////////////////////////



////////////////////////////////
// func36dec
80036DEC	lui    v0, $8006
80036DF0	lw     v0, $8a30(v0)
80036DF4	nop
80036DF8	lh     v0, $0014(v0)
80036DFC	jr     ra 
80036E00	nop
////////////////////////////////



////////////////////////////////
// func36e04
80036E04	lui    v0, $8006
80036E08	lw     v0, $8a30(v0)
80036E0C	nop
80036E10	lh     v0, $0016(v0)
80036E14	jr     ra 
80036E18	nop
////////////////////////////////



////////////////////////////////
// func36e1c
80036E1C	lui    v0, $8006
80036E20	lw     v0, $8a30(v0)
80036E24	nop
80036E28	lh     v0, $0030(v0)
80036E2C	jr     ra 
80036E30	nop
////////////////////////////////



////////////////////////////////
// func36e34
80036E34	lui    v0, $8006
80036E38	lw     v0, $8a30(v0)
80036E3C	nop
80036E40	lh     v0, $0032(v0)
80036E44	jr     ra 
80036E48	nop
////////////////////////////////



////////////////////////////////
// func36e4c
80036E4C	lui    v0, $8006
80036E50	lw     v0, $8a30(v0)
80036E54	nop
80036E58	lh     v0, $0034(v0)
80036E5C	jr     ra 
80036E60	nop
////////////////////////////////



////////////////////////////////
// func36e64
80036E64	lui    v0, $8006
80036E68	lw     v0, $8a30(v0)
80036E6C	nop
80036E70	lhu    v1, $0030(v0)
80036E74	lhu    a0, $0032(v0)
80036E78	lhu    a1, $0036(v0)
80036E7C	sh     v1, $00cc(v0)
80036E80	sh     a0, $00ce(v0)
80036E84	jr     ra 
80036E88	sh     a1, $00d0(v0)
////////////////////////////////



////////////////////////////////
// func36e8c
80036E8C	lui    v0, $8006
80036E90	lw     v0, $8a30(v0)
80036E94	nop
80036E98	lhu    v1, $00cc(v0)
80036E9C	lhu    a0, $00ce(v0)
80036EA0	lhu    a1, $00d0(v0)
80036EA4	sh     v1, $0030(v0)
80036EA8	sh     a0, $0032(v0)
80036EAC	jr     ra 
80036EB0	sh     a1, $0036(v0)
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
// func36f00
80036F00	lui    a2, $8006
80036F04	lw     a2, $8a30(a2)
80036F08	nop
80036F0C	beq    a2, zero, L36f2c [$80036f2c]
80036F10	nop
80036F14	lhu    v0, $000c(a2)
80036F18	lhu    v1, $000e(a2)
80036F1C	addu   v0, v0, a0
80036F20	addu   v1, v1, a1
80036F24	sh     v0, $0030(a2)
80036F28	sh     v1, $0032(a2)

L36f2c:	; 80036F2C
80036F2C	jr     ra 
80036F30	nop
////////////////////////////////



////////////////////////////////
// func36f34
80036F34	lui    a2, $8006
80036F38	lw     a2, $8a30(a2)
80036F3C	nop
80036F40	beq    a2, zero, L36f7c [$80036f7c]
80036F44	nop
80036F48	bgez   a0, L36f54 [$80036f54]
80036F4C	nop
80036F50	addu   a0, zero, zero

L36f54:	; 80036F54
80036F54	bgez   a1, L36f60 [$80036f60]
80036F58	nop
80036F5C	addu   a1, zero, zero

L36f60:	; 80036F60
80036F60	lhu    v0, $000c(a2)
80036F64	lhu    v1, $000e(a2)
80036F68	addu   v0, v0, a0
80036F6C	addu   v1, v1, a1
80036F70	sh     v0, $0030(a2)
80036F74	sh     v0, $0036(a2)
80036F78	sh     v1, $0032(a2)

L36f7c:	; 80036F7C
80036F7C	jr     ra 
80036F80	nop
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
// func37174
80037174	lui    v1, $8006
80037178	lw     v1, $8a30(v1)
8003717C	nop
80037180	lhu    v0, $002e(v1)
80037184	lhu    a1, $000e(v1)
80037188	lbu    a0, $001b(v1)
8003718C	andi   v0, v0, $0001
80037190	sll    v0, v0, $02
80037194	addu   v0, v0, v1
80037198	lw     a2, $0004(v0)
8003719C	lhu    v0, $000c(v1)
800371A0	andi   a0, a0, $00fe
800371A4	sh     zero, $0034(v1)
800371A8	sh     a1, $0032(v1)
800371AC	sh     a1, $00ce(v1)
800371B0	sb     a0, $001b(v1)
800371B4	sh     v0, $0030(v1)
800371B8	sh     v0, $00cc(v1)
800371BC	sh     v0, $0036(v1)
800371C0	sh     v0, $00d0(v1)
800371C4	jr     ra 
800371C8	sw     a2, $0038(v1)
////////////////////////////////



////////////////////////////////
// func371cc
800371CC	addiu  sp, sp, $ffd0 (=-$30)
800371D0	sw     s2, $0018(sp)
800371D4	lui    s2, $8006
800371D8	lw     s2, $8a30(s2)
800371DC	sw     s3, $001c(sp)
800371E0	addu   s3, a0, zero
800371E4	sw     ra, $0028(sp)
800371E8	sw     s5, $0024(sp)
800371EC	sw     s4, $0020(sp)
800371F0	sw     s1, $0014(sp)
800371F4	beq    s2, zero, L372fc [$800372fc]
800371F8	sw     s0, $0010(sp)
800371FC	lhu    v0, $0000(s2)
80037200	nop
80037204	andi   v0, v0, $0001
80037208	beq    v0, zero, L37220 [$80037220]
8003720C	addu   s5, zero, zero
80037210	lhu    v0, $002e(s2)
80037214	addu   s4, zero, zero
80037218	j      L37240 [$80037240]
8003721C	andi   v0, v0, $fffe

L37220:	; 80037220
80037220	lhu    v1, $002e(s2)
80037224	nop
80037228	andi   v0, v1, $0001
8003722C	beq    v0, zero, L3723c [$8003723c]
80037230	addu   s4, v0, zero
80037234	j      L37240 [$80037240]
80037238	andi   v0, v1, $fffe

L3723c:	; 8003723C
8003723C	ori    v0, v1, $0001

L37240:	; 80037240
80037240	beq    s3, zero, L37254 [$80037254]
80037244	sh     v0, $002e(s2)
80037248	addiu  v0, zero, $ffff (=-$1)
8003724C	bne    s3, v0, L37278 [$80037278]
80037250	sll    v0, s4, $02

L37254:	; 80037254
80037254	jal    system_draw_sync [$80044448]
80037258	addu   a0, zero, zero
8003725C	sll    v0, s4, $02
80037260	addiu  v0, v0, $00c4
80037264	addu   s3, s2, v0
80037268	ori    s5, zero, $0001
8003726C	jal    func43a5c [$80043a5c]
80037270	addu   a0, s3, zero
80037274	sll    v0, s4, $02

L37278:	; 80037278
80037278	addu   v0, v0, s2
8003727C	lh     s0, $0034(s2)
80037280	lw     s1, $0004(v0)
80037284	beq    s0, zero, L372a8 [$800372a8]
80037288	addu   a0, s3, zero

loop3728c:	; 8003728C
8003728C	addu   a1, s1, zero
80037290	addiu  s1, s1, $0010
80037294	jal    func315f0 [$800315f0]
80037298	addu   a0, s3, zero
8003729C	addiu  s0, s0, $ffff (=-$1)
800372A0	bne    s0, zero, loop3728c [$8003728c]
800372A4	addu   a0, s3, zero

L372a8:	; 800372A8
800372A8	addu   s0, s4, zero
800372AC	sll    a1, s0, $03
800372B0	addiu  a1, a1, $001c
800372B4	jal    func439c0 [$800439c0]
800372B8	addu   a1, s2, a1
800372BC	lhu    v0, $0000(s2)
800372C0	nop
800372C4	andi   v0, v0, $0010
800372C8	beq    v0, zero, L372e0 [$800372e0]
800372CC	addu   a0, s3, zero
800372D0	sll    a1, s0, $04
800372D4	addiu  a1, a1, $0044
800372D8	jal    func31614 [$80031614]
800372DC	addu   a1, s2, a1

L372e0:	; 800372E0
800372E0	jal    func37174 [$80037174]
800372E4	nop
800372E8	addu   v0, s5, zero
800372EC	beq    v0, zero, L372fc [$800372fc]
800372F0	nop
800372F4	jal    system_psyq_draw_otag [$80044a48]
800372F8	addu   a0, s3, zero

L372fc:	; 800372FC
800372FC	lw     ra, $0028(sp)
80037300	lw     s5, $0024(sp)
80037304	lw     s4, $0020(sp)
80037308	lw     s3, $001c(sp)
8003730C	lw     s2, $0018(sp)
80037310	lw     s1, $0014(sp)
80037314	lw     s0, $0010(sp)
80037318	addiu  sp, sp, $0030
8003731C	jr     ra 
80037320	nop
////////////////////////////////



////////////////////////////////
// func37324()

[80058a3c] = w(A0);
////////////////////////////////



////////////////////////////////
// func37334()
A0 = w[80058a30];
if( A0 != 0 )
{
    [80058954] = w(80036eb4);
    if( w[80058a3c] == 0 )
    {
        system_memory_free();
    }
    [80058a30] = w(0);
}
[80058a3c] = w(0);
////////////////////////////////



////////////////////////////////
// func37390
80037390	addiu  sp, sp, $ffb0 (=-$50)
80037394	sw     s1, $002c(sp)
80037398	lw     s1, $0078(sp)
8003739C	sw     s3, $0034(sp)
800373A0	lw     s3, $0060(sp)
800373A4	sw     s2, $0030(sp)
800373A8	lw     s2, $0064(sp)
800373AC	sw     s6, $0040(sp)
800373B0	lw     s6, $006c(sp)
800373B4	sw     s5, $003c(sp)
800373B8	lw     s5, $0070(sp)
800373BC	lui    v0, $8006
800373C0	lw     v0, $8a3c(v0)
800373C4	sw     s4, $0038(sp)
800373C8	lw     s4, $0074(sp)
800373CC	sw     fp, $0048(sp)
800373D0	addu   fp, a0, zero
800373D4	sw     s7, $0044(sp)
800373D8	addu   s7, a1, zero
800373DC	sw     ra, $004c(sp)
800373E0	sw     s0, $0028(sp)
800373E4	sw     a2, $0018(sp)
800373E8	bne    v0, zero, L37424 [$80037424]
800373EC	sw     a3, $0020(sp)
800373F0	jal    func322dc [$800322dc]
800373F4	ori    a0, zero, $0032
800373F8	andi   v0, s2, $0001
800373FC	bne    v0, zero, L37410 [$80037410]
80037400	sll    a0, s3, $04
80037404	sll    v0, s3, $05
80037408	j      L37414 [$80037414]
8003740C	addiu  a0, v0, $00d4

L37410:	; 80037410
80037410	addiu  a0, a0, $00d4

L37414:	; 80037414
80037414	srl    a1, s2, $02
80037418	xori   a1, a1, $0001
8003741C	jal    system_memory_allocate [$800319ec]
80037420	andi   a1, a1, $0001

L37424:	; 80037424
80037424	addu   a1, v0, zero
80037428	addu   s0, a1, zero
8003742C	addiu  v1, s0, $00d4
80037430	andi   v0, s2, $0001
80037434	beq    v0, zero, L37444 [$80037444]
80037438	sw     v1, $0004(s0)
8003743C	j      L37450 [$80037450]
80037440	sw     v1, $0008(s0)

L37444:	; 80037444
80037444	sll    v0, s3, $04
80037448	addu   v0, v1, v0
8003744C	sw     v0, $0008(s0)

L37450:	; 80037450
80037450	bne    s1, zero, L37464 [$80037464]
80037454	addu   a0, s1, zero
80037458	lui    s1, $8005
8003745C	addiu  s1, s1, $f8e0 (=-$720)
80037460	addu   a0, s1, zero

L37464:	; 80037464
80037464	jal    func32cac [$80032cac]
80037468	addu   a1, zero, zero
8003746C	addu   s1, v0, zero
80037470	lbu    v0, $0000(s1)
80037474	lbu    v1, $0002(s1)
80037478	andi   a1, v0, $0001
8003747C	andi   v0, v0, $0002
80037480	andi   a0, v0, $00ff
80037484	sh     v1, $0014(s0)
80037488	lbu    v1, $0003(s1)
8003748C	andi   v0, s2, $0002
80037490	beq    v0, zero, L3749c [$8003749c]
80037494	sh     v1, $0016(s0)
80037498	addu   a0, zero, zero

L3749c:	; 8003749C
8003749C	addu   v0, fp, zero
800374A0	sh     v0, $000c(s0)
800374A4	sh     v0, $0030(s0)
800374A8	addu   v0, s7, zero
800374AC	sh     s2, $0000(s0)
800374B0	sh     v0, $000e(s0)
800374B4	sh     v0, $0032(s0)
800374B8	lhu    t0, $0018(sp)
800374BC	ori    v0, zero, $00ff
800374C0	sh     t0, $0010(s0)
800374C4	lhu    t0, $0020(sp)
800374C8	sb     v0, $001a(s0)
800374CC	sb     v0, $0019(s0)
800374D0	sb     v0, $0018(s0)
800374D4	addu   v0, a1, zero
800374D8	sh     s3, $002c(s0)
800374DC	sh     zero, $0034(s0)
800374E0	sh     zero, $002e(s0)
800374E4	beq    v0, zero, L374f4 [$800374f4]
800374E8	sh     t0, $0012(s0)
800374EC	j      L374f8 [$800374f8]
800374F0	ori    v0, zero, $007d

L374f4:	; 800374F4
800374F4	ori    v0, zero, $0075

L374f8:	; 800374F8
800374F8	sb     v0, $001b(s0)
800374FC	sll    v0, a0, $10
80037500	sra    a0, v0, $10
80037504	bne    a0, zero, L3751c [$8003751c]
80037508	sb     s6, $00d2(s0)
8003750C	lhu    v0, $002e(s0)
80037510	nop
80037514	ori    v0, v0, $0004
80037518	sh     v0, $002e(s0)

L3751c:	; 8003751C
8003751C	addu   v0, a1, zero
80037520	beq    v0, zero, L37544 [$80037544]
80037524	nop
80037528	lhu    v0, $002e(s0)
8003752C	ori    v1, zero, $0020
80037530	ori    v0, v0, $0002
80037534	beq    a0, zero, L37550 [$80037550]
80037538	sh     v0, $002e(s0)
8003753C	j      L37550 [$80037550]
80037540	ori    v1, zero, $0030

L37544:	; 80037544
80037544	beq    a0, zero, L37550 [$80037550]
80037548	ori    v1, zero, $0008
8003754C	ori    v1, zero, $0010

L37550:	; 80037550
80037550	lhu    t0, $0068(sp)
80037554	ori    v0, zero, $0020
80037558	sh     s6, $0012(sp)
8003755C	sh     v0, $0014(sp)
80037560	sh     v1, $0016(sp)
80037564	sh     t0, $0010(sp)
80037568	lh     v0, $0014(s0)
8003756C	nop
80037570	bne    v0, zero, L37594 [$80037594]
80037574	addiu  a1, s1, $0004
80037578	addiu  a0, s0, $0064
8003757C	lhu    v0, $002e(s0)
80037580	ori    a2, zero, $0060
80037584	ori    v0, v0, $0008
80037588	jal    system_memmove [$8003f844]
8003758C	sh     v0, $002e(s0)
80037590	addiu  a1, s1, $0064

L37594:	; 80037594
80037594	jal    system_load_image [$8004470c]
80037598	addiu  a0, sp, $0010
8003759C	addu   a0, zero, zero
800375A0	addu   a1, zero, zero
800375A4	lw     a2, $0068(sp)
800375A8	jal    func43894 [$80043894]
800375AC	addu   a3, s6, zero
800375B0	addu   a0, s5, zero
800375B4	addu   a1, s4, zero
800375B8	sh     v0, $0002(s0)
800375BC	ori    v0, zero, $0040
800375C0	sh     v0, $0014(sp)
800375C4	ori    v0, zero, $0001
800375C8	sh     s5, $0010(sp)
800375CC	sh     s4, $0012(sp)
800375D0	jal    func438d0 [$800438d0]
800375D4	sh     v0, $0016(sp)
800375D8	addiu  a0, s5, $0010
800375DC	addu   a1, s4, zero
800375E0	jal    func438d0 [$800438d0]
800375E4	sh     v0, $003c(s0)
800375E8	addiu  a0, s5, $0020
800375EC	addu   a1, s4, zero
800375F0	jal    func438d0 [$800438d0]
800375F4	sh     v0, $003e(s0)
800375F8	addiu  a0, s5, $0030
800375FC	addu   a1, s4, zero
80037600	jal    func438d0 [$800438d0]
80037604	sh     v0, $0040(s0)
80037608	sh     v0, $0042(s0)
8003760C	lui    a1, $8006
80037610	addiu  a1, a1, $8a34 (=-$75cc)
80037614	lwl    v0, $0013(sp)
80037618	lwr    v0, $0010(sp)
8003761C	lwl    v1, $0017(sp)
80037620	lwr    v1, $0014(sp)
80037624	swl    v0, $0003(a1)
80037628	swr    v0, $0000(a1)
8003762C	swl    v1, $0007(a1)
80037630	swr    v1, $0004(a1)
80037634	ori    a0, zero, $7fff
80037638	jal    func36cf4 [$80036cf4]
8003763C	addu   a1, zero, zero
80037640	addiu  a0, s0, $001c
80037644	addu   a1, zero, zero
80037648	lh     a3, $0002(s0)
8003764C	jal    func43c98 [$80043c98]
80037650	addu   a2, zero, zero
80037654	addiu  a0, s0, $0024
80037658	addu   a1, zero, zero
8003765C	lh     a3, $0002(s0)
80037660	jal    func43c98 [$80043c98]
80037664	addu   a2, zero, zero
80037668	ori    v0, zero, $0003
8003766C	sb     v0, $0047(s0)
80037670	ori    v0, zero, $0060
80037674	sb     v0, $004b(s0)
80037678	sll    v0, s7, $10
8003767C	or     v0, fp, v0
80037680	sb     zero, $0048(s0)
80037684	sb     zero, $0049(s0)
80037688	sb     zero, $004a(s0)
8003768C	sw     v0, $004c(s0)
80037690	lw     t0, $0020(sp)
80037694	lbu    v1, $004b(s0)
80037698	sll    v0, t0, $10
8003769C	lw     t0, $0018(sp)
800376A0	ori    v1, v1, $0002
800376A4	or     v0, t0, v0
800376A8	sw     v0, $0050(s0)
800376AC	sb     v1, $004b(s0)
800376B0	lw     v0, $0044(s0)
800376B4	lw     v1, $0048(s0)
800376B8	lw     a0, $004c(s0)
800376BC	lw     a1, $0050(s0)
800376C0	sw     v0, $0054(s0)
800376C4	sw     v1, $0058(s0)
800376C8	sw     a0, $005c(s0)
800376CC	sw     a1, $0060(s0)
800376D0	lui    at, $8006
800376D4	sw     s0, $8a30(at)
800376D8	jal    func37174 [$80037174]
800376DC	nop
800376E0	jal    system_memory_free [$80031f0c]
800376E4	addu   a0, s1, zero
800376E8	addu   v0, s0, zero
800376EC	lw     ra, $004c(sp)
800376F0	lw     fp, $0048(sp)
800376F4	lw     s7, $0044(sp)
800376F8	lw     s6, $0040(sp)
800376FC	lw     s5, $003c(sp)
80037700	lw     s4, $0038(sp)
80037704	lw     s3, $0034(sp)
80037708	lw     s2, $0030(sp)
8003770C	lw     s1, $002c(sp)
80037710	lw     s0, $0028(sp)
80037714	addiu  sp, sp, $0050
80037718	jr     ra 
8003771C	nop
////////////////////////////////
