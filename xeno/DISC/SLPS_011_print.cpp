////////////////////////////////
// system_print_add_letter_to_render()

V0 = w[8004fc34]; // system_print_add_letter_to_render_inner()
800365A8	jalr   v0 ra
////////////////////////////////



////////////////////////////////
// system_print_inner()

string = A1;

letter = bu[string];
S3 = A2;
S5 = 0;
if( letter == 0 )
{
    return 0;
}

S7 = 2d;
S6 = 2b;

L36608:	; 80036608
    if( letter == 25 ) // "%"
    {
        A1 = 80059868;
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
        string = string + 1;
        A0 = bu[string];
        if( A0 == S7 )
        {
            [SP + 110] = w(w[SP + 110] | 00000001);
            80036664	j      L36644 [$80036644]
        }
        if( A0 == S6 )
        {
            [SP + 110] = w(w[SP + 110] | 00000002);
            80036680	j      L36644 [$80036644]
        }
        if( A0 == A1 )
        {
            [SP + 111] = b(A0);
            80036690	j      L36644 [$80036644]
        }

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
        string = string + 0001;
        A0 = bu[string + 0000];
        800366EC	j      L36728 [$80036728]
        V0 = 002e;

        loop366f4:	; 800366F4
        V0 = w[SP + 0114];
        string = string + 0001;
        V1 = V0 << 02;
        V1 = V1 + V0;
        V1 = V1 << 01;
        80036708	addiu  v1, v1, $ffd0 (=-$30)
        V1 = V1 + A0;
        A0 = bu[string + 0000];
        [SP + 0114] = w(V1);
        80036718	addiu  v0, a0, $ffd0 (=-$30)

        L3671c:	; 8003671C
        V0 = V0 < 000a;
        80036720	bne    v0, zero, loop366f4 [$800366f4]
        V0 = 002e;

        L36728:	; 80036728
        if( A0 == V0 )
        {
            string = string + 0001;
            A0 = bu[string + 0000];

            8003673C	bne    a0, 2a, L36784 [$80036784]

            S3 = S3 + 4;
            string = string + 1;
            A0 = bu[string + 0];
            [SP + 118] = w(w[S3 - 4]);
            80036754	j      L36790 [$80036790]


            loop3675c:	; 8003675C
                V0 = w[SP + 0118];
                string = string + 1;
                V1 = V0 << 02;
                V1 = V1 + V0;
                V1 = V1 << 01;
                V1 = V1 + A0 - 30;
                A0 = bu[string + 0];
                [SP + 0118] = w(V1);

                L36784:	; 80036784
                V0 = A0 - 30;
                V0 = V0 < a;
            80036788	bne    v0, zero, loop3675c [$8003675c]

            L36790:	; 80036790
            if( w[SP + 118] >= 0 )
            {
                [SP + 110] = w(w[SP + 110] | 00000008);
            }
        }

        L367b0:	; 800367B0
        V1 = w[SP + 110];
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

        V0 = w[80018bec + V1 * 4];
        800367F0	jr     v0 
        800367F4	nop

        case a:
        {
            S3 = S3 + 4;
            A0 = w[S3 - 4];
            V0 = 2;
            80036800	j      L36854 [$80036854]
        }
        break;

    80036808 c 11
        S3 = S3 + 4;
        A0 = w[S3 - 4];
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

    80036848 1d
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

        A0 = A0 / w[SP + 11c];
        800368DC	nop
        800368E0	bne    a0, zero, loop368b0 [$800368b0]
        S1 = S1 + 0001;

        L368e8:	; 800368E8
        V0 = w[SP + 0118];
        800368EC	nop
        V0 = S1 < V0;
        if( V0 != 0 )
        {
            V1 = 0030;
            80036900	addiu  s0, s0, $ffff (=-$1)

            loop36904:	; 80036904
                [S0 + 0000] = b(V1);
                V0 = w[SP + 0118];
                S1 = S1 + 0001;
                V0 = S1 < V0;
                80036918	addiu  s0, s0, $ffff (=-$1)
            80036914	bne    v0, zero, loop36904 [$80036904]

            S0 = S0 + 0001;
        }

        if( bu[SP + 111] != 0 )
        {
            S0 = S0 - 1;
            [S0 + 0] = b(V0);
            S1 = S1 + 1;
        }
        80036938	j      L36a98 [$80036a98]


    80036940 18
        V1 = w[SP + 0110];
        V0 = 0008;
        [SP + 0118] = w(V0);
        V1 = V1 | 0008;

    80036954 0
        [SP + 110] = w(V1);
        A1 = 80018bc4;
        8003695C	j      L36970 [$80036970]
        S3 = S3 + 0004;

    80036964 20
        A1 = 80018bd8;
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

    80036A0C b
        80036A0C	addiu  s0, s0, $ffff (=-$1)
        S3 = S3 + 0004;
        V0 = w[S3 + fffc];
        S1 = 0001;
        80036A1C	j      L36a98 [$80036a98]
        [S0 + 0000] = b(V0);

    80036A24 1b
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

    80036A6C 16
        S3 = S3 + 0004;
        S0 = w[S3 + fffc];
        80036A74	j      L36b38 [$80036b38]
        [S0 + 0000] = w(S5);

    80036A7C 1 2 3 4 5 6 7 8 9 d e f 10 12 13 14 15 17 19 1a 1c 1e 1f
        L36a7c:	; 80036A7C
        if( A0 != 25 ) // "%"
        {
            return S5;
        }
    }

    S5 = S5 + 1;

    A0 = letter;
    system_print_add_letter_to_render();

    80036A90	j      L36b3c [$80036b3c]
    string = string + 1;

    L36a98:	; 80036A98
    if( S1 < w[SP + 114] )
    {
        if( ( w[SP + 110] & 0001 ) == 0 )
        {
            loop36ac0:	; 80036AC0
                A0 = 20;
                system_print_add_letter_to_render();

                S5 = S5 + 1;
                [SP + 114] = w(w[SP + 114] - 1);
                V0 = S1 < w[SP + 114];
            80036ADC	bne    v0, zero, loop36ac0 [$80036ac0]
        }
    }

    if( S1 > 0 )
    {
        S2 = S1 + S0;

        loop36af0:	; 80036AF0
            A0 = bu[S0];
            system_print_add_letter_to_render();

            S0 = S0 + 1;
            V0 = S0 < S2;
        80036B00	bne    v0, zero, loop36af0 [$80036af0]
    }

    S5 = S5 + S1;
    if( S1 < w[SP + 114] )
    {
        loop36b1c:	; 80036B1C
            A0 = 20;
            system_print_add_letter_to_render();

            S5 = S5 + 1;
            S1 = S1 + 1;
            V0 = S1 < w[SP + 114];
        80036B30	bne    v0, zero, loop36b1c [$80036b1c]
    }

    L36b38:	; 80036B38
    string = string + 1;

    L36b3c:	; 80036B3C
    A0 = bu[string + 0];
80036B44	bne    a0, zero, L36608 [$80036608]

return S5;
////////////////////////////////



////////////////////////////////
// func36b80

V1 = w[80058a30];
[V1 + 0] = h(hu[V1 + 0] | A0);
////////////////////////////////



////////////////////////////////
// func36ba0

V0 = w[80058a30];
[V0 + 0] = h(hu[V0 + 0] & (0 NOR A0));
////////////////////////////////



////////////////////////////////
// func36bc0

V0 = w[80058a30];
return h[V0 + 0];
////////////////////////////////



////////////////////////////////
// func36bd8

V1 = w[80058a30];
[V1 + 2e] = h(hu[V1 + 2e] | A0);
////////////////////////////////



////////////////////////////////
// func36bf8

V1 = w[80058a30];
[V1 + 2e] = h(hu[V1 + 2e] | (0 NOR A0));
////////////////////////////////



////////////////////////////////
// func36c18

V0 = w[80058a30];
return h[V0 + 2e];
////////////////////////////////



////////////////////////////////
// system_print_set_default_letter_width()

V0 = w[80058a30];
[V0 + 14] = h(A0);
////////////////////////////////



////////////////////////////////
// system_print_set_default_letter_height()

V0 = w[80058a30];
[V0 + 16] = h(A0);
////////////////////////////////



////////////////////////////////
// system_print_set_current_letter_x

V0 = w[80058a30];
[V0 + 30] = h(A0);
////////////////////////////////



////////////////////////////////
// system_print_set_current_letter_y

V0 = w[80058a30];
[V0 + 32] = h(A0);
////////////////////////////////



////////////////////////////////
// func36c70

V0 = w[80058a30];
[V0 + 18] = b(A0); // r
[V0 + 19] = b(A1); // g
[V0 + 1a] = b(A2); // b

A0 = A0 < 0080;
80036C9C	bne    a0, zero, L36cbc [$80036cbc]

V0 = A1 < 0080;
80036CA8	bne    v0, zero, L36cbc [$80036cbc]
80036CAC	nop
V0 = A2 < 0080;
80036CB4	beq    v0, zero, L36cd4 [$80036cd4]
80036CB8	nop

L36cbc:	; 80036CBC
V1 = w[80058a30];
V0 = bu[V1 + 1b] & 00fe;
80036CCC	j      L36cec [$80036cec]

L36cd4:	; 80036CD4
V1 = w[80058a30];
V0 = bu[V1 + 1b] | 0001;

L36cec:	; 80036CEC
[V1 + 1b] = b(V0);
////////////////////////////////



////////////////////////////////
// func36cf4

A2 = 8004fc38;
A3 = 0;

loop36d08:	; 80036D08
[A2 + 0000] = h(A1);
A2 = A2 + 0002;
[A2 + 0000] = h(A0);
A3 = A3 + 0001;
V0 = A3 < 0008;
80036D1C	bne    v0, zero, loop36d08 [$80036d08]
A2 = A2 + 0002;
V0 = A3 < 000c;
80036D28	beq    v0, zero, L36d90 [$80036d90]
V0 = A3 < 000e;

loop36d30:	; 80036D30
[A2 + 0000] = h(A1);
A2 = A2 + 0002;
[A2 + 0000] = h(A1);
A2 = A2 + 0002;
[A2 + 0000] = h(A0);
A2 = A2 + 0002;
[A2 + 0000] = h(A0);
A3 = A3 + 0001;
V0 = A3 < 000c;
80036D54	bne    v0, zero, loop36d30 [$80036d30]
A2 = A2 + 0002;
80036D5C	j      L36d90 [$80036d90]
V0 = A3 < 000e;

loop36d64:	; 80036D64
[A2 + 0000] = h(A1);
80036D68	addiu  v1, v1, $ffff (=-$1)
80036D6C	bgez   v1, loop36d64 [$80036d64]
A2 = A2 + 0002;
V1 = 0003;

loop36d78:	; 80036D78
[A2 + 0000] = h(A0);
80036D7C	addiu  v1, v1, $ffff (=-$1)
80036D80	bgez   v1, loop36d78 [$80036d78]
A2 = A2 + 0002;
A3 = A3 + 0001;
V0 = A3 < 000e;

L36d90:	; 80036D90
80036D90	bne    v0, zero, loop36d64 [$80036d64]
V1 = 0003;
V1 = 0007;

loop36d9c:	; 80036D9C
[A2 + 0000] = h(A1);
80036DA0	addiu  v1, v1, $ffff (=-$1)
80036DA4	bgez   v1, loop36d9c [$80036d9c]
A2 = A2 + 0002;
V1 = 0008;

loop36db0:	; 80036DB0
[A2 + 0000] = h(A0);
V1 = V1 + 0001;
V0 = V1 < 0010;
80036DBC	bne    v0, zero, loop36db0 [$80036db0]
A2 = A2 + 0002;
A0 = 80058a34;
A1 = 8004fc38;
system_load_image();
////////////////////////////////



////////////////////////////////
// system_print_get_default_letter_width()

V0 = w[80058a30];
return h[V0 + 14];
////////////////////////////////



////////////////////////////////
// system_print_get_default_letter_height()

V0 = w[80058a30];
return h[V0 + 16];
////////////////////////////////



////////////////////////////////
// system_print_get_current_letter_x()

V0 = w[80058a30];
return h[V0 + 30];
////////////////////////////////



////////////////////////////////
// system_print_get_current_letter_y

V0 = w[80058a30];
return h[V0 + 32];
////////////////////////////////



////////////////////////////////
// func36e4c

V0 = w[80058a30];
return h[V0 + 34];
///////////////////////////////



////////////////////////////////
// func36e64

V0 = w[80058a30];
[V0 + cc] = h(hu[V0 + 30]);
[V0 + ce] = h(hu[V0 + 32]);
[V0 + d0] = h(hu[V0 + 36]);
////////////////////////////////



////////////////////////////////
// func36e8c

V0 = w[80058a30];
[V0 + 30] = h(hu[V0 + cc]);
[V0 + 32] = h(hu[V0 + ce]);
[V0 + 36] = h(hu[V0 + d0]);
////////////////////////////////



////////////////////////////////
// system_print()

string = A0;

[SP + 18] = w(string);
[SP + 1c] = w(A1); // arg1
[SP + 20] = w(A2); // arg2
[SP + 24] = w(A3); // arg3

if( w[80058a30] != 0 )
{
    A0 = 0;
    A1 = string;
    A2 = SP + 1c; // args
    system_print_inner();
}
////////////////////////////////



////////////////////////////////
// func36f00

A2 = w[80058a30];
if( A2 != 0 )
{
    [A2 + 30] = h(hu[A2 + c] + A0);
    [A2 + 32] = h(hu[A2 + e] + A1);
}
////////////////////////////////



////////////////////////////////
// func36f34

A2 = w[80058a30];
80036F3C	nop
80036F40	beq    a2, zero, L36f7c [$80036f7c]
80036F44	nop
80036F48	bgez   a0, L36f54 [$80036f54]
80036F4C	nop
A0 = 0;

L36f54:	; 80036F54
80036F54	bgez   a1, L36f60 [$80036f60]
80036F58	nop
A1 = 0;

L36f60:	; 80036F60
[A2 + 30] = h(hu[A2 + c] + A0);
[A2 + 36] = h(hu[A2 + c] + A0);
[A2 + 32] = h(hu[A2 + e] + A1);

L36f7c:	; 80036F7C
////////////////////////////////



////////////////////////////////
// system_print_add_letter_to_render_inner()

A2 = w[80058a30];

letter = A0;

if( letter != 0 )
{
    if( ( h[A2 + 32] + h[A2 + 16] ) <= ( h[A2 + e] + h[A2 + 12] ) )
    {
        if( h[A2 + 34] <= h[A2 + 2c] )
        {
            if( letter < 20 ) // control characters
            {
                if( letter == a ) // new line
                {
                    [A2 + 30] = h(hu[A2 + 36]);
                    [A2 + 32] = h(hu[A2 + 32] + hu[A2 + 16]);
                }
            }
            else
            {
                if( hu[A2 + 2e] & 0004 ) // use uppercase characters
                {
                    if( letter >= 60 )
                    {
                        letter = letter - 20;
                    }
                }

                letter = letter - 20;

                if( hu[A2 + 2e] & 0008 )
                {
                    A1 = bu[A2 + 64 + letter]; // width
                }
                else
                {
                    A1 = h[A2 + 14]; // default
                }

                if( ( h[A2 + 30] + A1 ) >= ( h[A2 + c] + h[A2 + 10] ) )
                {
                    if( hu[A2 + 0] & 0008 )
                    {
                        return;
                    }

                    [A2 + 30] = h(hu[A2 + 36]);
                    [A2 + 32] = h(hu[A2 + 32] + hu[A2 + 16]);
                }

                if( letter != 0 ) // if not space
                {
                    packet = w[A2 + 38];
                    [packet + 4] = w(w[A2 + 18]); // colour
                    [packet + 8] = w((h[A2 + 32] << 10) | h[A2 + 30]); // x and y

                    if( hu[A2 + 2e] & 0002 )
                    {
                        [packet + c] = h(((letter & 07) << 4) | ((bu[A2 + d2] + (letter & 60 >> 1)) << 8)); // uv
                        [packet + e] = h(hu[A2 + 3c + ((letter & 18) / 4])); // palette
                    }
                    else
                    {
                        [packet + c] = h(((letter & 0f) << 3) | ((bu[A2 + d2] + ((letter & c0) >> 3)) << 8)); uv
                        [packet + e] = h(hu[A2 + 3c + ((letter & 30) / 8)]); // palette
                    }

                    [A2 + 38] = w(packet + 10);
                    [A2 + 34] = h(hu[A2 + 34] + 1); // increment number of letters
                }

                [A2 + 30] = h(hu[A2 + 30] + A1);
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// func37174

V1 = w[80058a30];
V0 = V1 + (hu[V1 + 2e] & 1) * 4;

[V1 + 1b] = b(bu[V1 + 1b] & fe);
[V1 + 30] = h(hu[V1 + c]);
[V1 + 32] = h(hu[V1 + e]);
[V1 + 36] = h(hu[V1 + c]);
[V1 + 34] = h(0);
[V1 + 38] = w(w[V0 + 4]);
[V1 + cc] = h(hu[V1 + c]);
[V1 + ce] = h(hu[V1 + e]);
[V1 + d0] = h(hu[V1 + c]);
////////////////////////////////



////////////////////////////////
// system_print_render_strings()

S3 = A0;

S2 = w[80058a30];

if( S2 != 0 )
{
    S5 = 0;

    if( hu[S2 + 0] & 0001 )
    {
        S4 = 0;
        [S2 + 2e] = h(hu[S2 + 2e] & fffe);
    }
    else
    {
        S4 = hu[S2 + 2e] & 0001;
        if( S4 != 0 )
        {
            [S2 + 2e] = h(hu[S2 + 2e] & fffe);
        }
        else
        {
            [S2 + 2e] = h(hu[S2 + 2e] | 0001);
        }
    }

    if( ( S3 == 0 ) || ( S3 == -1 ) )
    {
        A0 = 0;
        system_draw_sync();

        S3 = S2 + c4 + S4 * 4;
        S5 = 1;

        A0 = S3;
        func43a5c();
    }

    S0 = h[S2 + 34];
    S1 = w[S2 + S4 * 4 + 4];

    while( S0 != 0 )
    {
        A0 = S3;
        A1 = S1;
        80037294	jal    func315f0 [$800315f0]

        S1 = S1 + 10;
    }

    A0 = S3;
    A1 = S2 + 1c + S4 * 8;
    800372B4	jal    func439c0 [$800439c0]

    if( hu[S2 + 0] & 0010 )
    {
        A0 = S3;
        A1 = S2 + 44 + S4 * 10;
        800372D8	jal    func31614 [$80031614]
    }

    func37174(); // reset current string buffer

    if( S5 != 0 )
    {
        A0 = S3;
        system_psyq_draw_otag();
    }
}
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
    [80058954] = w(80036eb4); // system_print()

    if( w[80058a3c] == 0 )
    {
        system_memory_mark_removed_alloc();
        [80058a30] = w(0);
    }
}
[80058a3c] = w(0);
////////////////////////////////



////////////////////////////////
// func37390()

S1 = A10;
max_letters = A4;
S2 = A5;
texpage_x = A6;
texpage_y = A7;
clut_x = A8;
clut_y = A9;
FP = A0;
S7 = A1;
[SP + 18] = w(A2);
[SP + 20] = w(A3);

mem = w[80058a3c];
if( mem == 0 )
{
    A0 = 32; // LsFONT
    system_memory_set_alloc_contents();

    if( ( S2 & 1 ) == 0 )
    {
        A0 = (max_letters << 5) + d4;
    }
    else
    {
        A0 = (max_letters << 4) + d4;
    }

    A1 = ((S2 >> 2) ^ 1) & 1;
    system_memory_allocate();
    mem = V0;
}

[mem + 4] = w(mem + d4);

if( S2 & 1 )
{
    [mem + 8] = w(mem + d4);
}
else
{
    [mem + 8] = w(mem + d4 + max_letters * 10);
}

if( S1 == 0 )
{
    S1 = 8004f8e0;
}

A0 = S1;
A1 = 0;
func32cac();

S1 = V0;
V0 = bu[S1 + 0000];
A1 = V0 & 0001;
V0 = V0 & 0002;
A0 = V0 & 00ff;
[mem + 14] = h(bu[S1 + 2]);
[mem + 16] = h(bu[S1 + 3]);

if( S2 & 2 )
{
    A0 = 0;
}

[mem + c] = h(FP);
[mem + 30] = h(FP);
[mem + 0] = h(S2);
[mem + e] = h(S7);
[mem + 32] = h(S7);
[mem + 10] = h(hu[SP + 18]);

[mem + 18] = b(ff); // r
[mem + 19] = b(ff); // g
[mem + 1a] = b(ff); // b

[mem + 2c] = h(max_letters);
[mem + 34] = h(0);
[mem + 2e] = h(0);
[mem + 12] = h(hu[SP + 20]);

if( A1 != 0 )
{
    [mem + 1b] = b(7d); // Textured Rectangle, 16x16, opaque, raw-texture
}
else
{
    [mem + 1b] = b(75); // Textured Rectangle, 8x8, opaque, raw-texture
}

[mem + d2] = b(texpage_y);

if( A0 == 0 )
{
    [mem + 2e] = h(hu[mem + 2e] | 0004);
}

if( A1 != 0 )
{
    [mem + 2e] = h(hu[mem + 2e] | 0002);

    V1 = 20;
    if( A0 != 0 )
    {
        V1 = 30;
    }
}
else
{
    V1 = 8;
    if( A0 != 0 )
    {
        V1 = 10;
    }
}

[SP + 10] = h(texpage_x);
[SP + 12] = h(texpage_y);
[SP + 14] = h(20);
[SP + 16] = h(V1);

A1 = S1 + 4;

if( h[mem + 14] == 0 )
{
    [mem + 2e] = h(hu[mem + 2e] | 0008);

    A0 = mem + 64;
    A2 = 60;
    system_memmove();

    A1 = S1 + 64;
}

A0 = SP + 10;
system_load_image();

A0 = 0;
A1 = 0;
A2 = texpage_x;
A3 = texpage_y;
system_graphic_get_texpage_by_param();
[mem + 2] = h(V0);

A0 = clut_x;
A1 = clut_y;
system_graphic_get_clut_by_param();
[mem + 3c] = h(V0);

A0 = clut_x + 10;
A1 = clut_y;
system_graphic_get_clut_by_param();
[mem + 3e] = h(V0);

A0 = clut_x + 20;
A1 = clut_y;
system_graphic_get_clut_by_param();
[mem + 40] = h(V0);

A0 = clut_x + 30;
A1 = clut_y;
system_graphic_get_clut_by_param();
[mem + 42] = h(V0);

[80058a34 + 0] = h(clut_x);
[80058a34 + 2] = h(clut_y);
[80058a34 + 4] = h(40);
[80058a34 + 6] = h(1);

A0 = 7fff;
A1 = 0;
80037638	jal    func36cf4 [$80036cf4]

A0 = mem + 1c;
A1 = 0;
A3 = h[mem + 2];
A2 = 0;
system_graphic_create_texpage_settings_packet();

A0 = mem + 24;
A1 = 0;
A3 = h[mem + 2];
A2 = 0;
system_graphic_create_texpage_settings_packet();

[mem + 47] = b(3);
[mem + 48] = b(0);
[mem + 49] = b(0);
[mem + 4a] = b(0);
[mem + 4b] = b(60);
[mem + 4c] = w((S7 << 10) | FP);
[mem + 50] = w((w[SP + 20] << 10) | w[SP + 18]);
[mem + 4b] = b(bu[mem + 4b] | 0002);

[mem + 54] = w(w[mem + 44]);
[mem + 58] = w(w[mem + 48]);
[mem + 5c] = w(w[mem + 4c]);
[mem + 60] = w(w[mem + 50]);

[80058a30] = w(mem);

func37174();

A0 = S1;
system_memory_mark_removed_alloc();

return mem;
////////////////////////////////
