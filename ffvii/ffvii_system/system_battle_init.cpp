////////////////////////////////
// func14578()

A3 = A2;
A2 = A1;
A1 = w[80048d84 + A0 * 8 + 4];
A0 = w[80048d84 + A0 * 8 + 0];
func33e34();
////////////////////////////////



////////////////////////////////
// func145bc
loop145cc:	; 800145CC
    func34b44;

    if (V0 == 0)
    {
        return;
    }

    800145DC	beq    s0, zero, loop145cc [$800145cc]
    800145E0	nop
    800145E4	jalr   s0 ra
    800145E8	nop
800145EC	j      loop145cc [$800145cc]
////////////////////////////////



////////////////////////////////
// func34b44
if( w[80071a60] >= 15 )
{
    L34b60:	; 80034B60
    80034B60	j      L34b60 [$80034b60]
    80034B64	nop
}

V0 = w[80071a60];
V0 = w[8004a634 + V0 * 4];

20440380 0
7C440380 1
C0440380 2
BC450380 3
00460380 4
F8460380 5
54470380 6
28440380 7
44570380 8
30540380 9
20440380 a
B4470380 b
F8470380 c
F4480380 d
74490380 e
20440380 f
44440380 10
30440380 11
20440380 12
584A0380 13
904A0380 14

80034B90	jalr   v0 ra

V0 = w[80071a60];
////////////////////////////////