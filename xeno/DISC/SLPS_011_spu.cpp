////////////////////////////////
// func4c3f0()

A0 = 0;
func4c410();
////////////////////////////////



////////////////////////////////
// func4c410()

S0 = A0;

8004C41C	jal    func4b5e8 [$8004b5e8]

A0 = S0;
8004C424	jal    func4c584 [$8004c584]

A0 = c000;
8004C42C	bne    s0, zero, L4c450 [$8004c450]

V1 = 0017;
8004C438	lui    v0, $8006
8004C43C	addiu  v0, v0, $809e (=-$7f62)

loop4c440:	; 8004C440
[V0 + 0000] = h(A0);
8004C444	addiu  v1, v1, $ffff (=-$1)
8004C448	bgez   v1, loop4c440 [$8004c440]
8004C44C	addiu  v0, v0, $fffe (=-$2)

L4c450:	; 8004C450
8004C450	jal    func4c508 [$8004c508]

[80058048] = w(0);
[8005804c] = w(0);
[80058058] = w(0);
[8005805c] = h(0);
[8005805e] = h(0);
[80058060] = w(0);
[80058064] = w(0);
[80058050] = w(w[80058510]);

A0 = d1;
A1 = w[80058510];
A2 = 0;
8004C4A4	jal    func4ced0 [$8004ced0]

[80058504] = w(0);
[80058508] = w(0);
[8005850c] = w(0);
[80058044] = w(0);
[800584c4] = w(0);
[80058040] = w(0);
[8005806c] = w(0);
[80058068] = w(0);
[800584a0] = w(0);
////////////////////////////////



////////////////////////////////
// func4c584()

S0 = A0;
A0 = w[800584b8];
V0 = w[A0 + 0000];
8004C5A4	lui    v1, $000b
V0 = V0 | V1;
[A0 + 0000] = w(V0);
V0 = w[800584a8];
[800584c4] = w(0);
[800584c8] = w(0);
[800584c0] = h(0);
[V0 + 0180] = h(0);
[V0 + 0182] = h(0);
[V0 + 01aa] = h(0);

func4d0b0();

V0 = w[800584a8];
8004C5EC	nop
[V0 + 0180] = h(0);
[V0 + 0182] = h(0);
V0 = hu[V0 + 01ae];
8004C5FC	nop
V0 = V0 & 07ff;
8004C604	beq    v0, zero, L4c65c [$8004c65c]
V1 = 0;
V1 = V1 + 0001;

loop4c610:	; 8004C610
V0 = V1 < 0f01;
8004C614	bne    v0, zero, L4c63c [$8004c63c]
8004C618	nop
8004C61C	lui    a0, $8002
8004C620	addiu  a0, a0, $9500 (=-$6b00)
8004C624	lui    a1, $8002
8004C628	addiu  a1, a1, $9510 (=-$6af0)
8004C62C	jal    func199e8 [$800199e8]
8004C630	nop
8004C634	j      L4c660 [$8004c660]
A0 = 0;

L4c63c:	; 8004C63C
V0 = w[800584a8];
8004C644	nop
V0 = hu[V0 + 01ae];
8004C64C	nop
V0 = V0 & 07ff;
8004C654	bne    v0, zero, loop4c610 [$8004c610]
V1 = V1 + 0001;

L4c65c:	; 8004C65C
A0 = 0;

L4c660:	; 8004C660
A1 = 80059b58;
[800584cc] = w(2);
[800584d0] = w(3);
[800584d4] = w(8);
[800584d8] = w(7);

V0 = w[800584a8];
[V0 + 1ac] = h(0004);
[V0 + 184] = h(0);
[V0 + 186] = h(0);
[V0 + 18c] = h(ffff);
[V0 + 18e] = h(ffff);
[V0 + 198] = h(0);
[V0 + 19a] = h(0);

loop4c6c4:	; 8004C6C4
    [A1 + 0000] = h(0);
    A0 = A0 + 0001;
    V0 = A0 < 000a;
    A1 = A1 + 0002;
8004C6D0	bne    v0, zero, loop4c6c4 [$8004c6c4]

8004C6D8	bne    s0, zero, L4c7d4 [$8004c7d4]
V0 = 0;

A0 = 800584e8;

[800584c0] = h(0200);

V0 = w[800584a8];
[V0 + 190] = h(0);
[V0 + 192] = h(0);
[V0 + 194] = h(0);
[V0 + 196] = h(0);
[V0 + 1b0] = h(0);
[V0 + 1b2] = h(0);
[V0 + 1b4] = h(0);
[V0 + 1b6] = h(0);

A1 = 10;
8004C71C	jal    func4c818 [$8004c818]

V1 = w[800584a8];
for( int i = 0; i < 18; ++i )
{
    [V1 + 0] = h(0);
    [V1 + 2] = h(0);
    [V1 + 4] = h(3fff);
    [V1 + 6] = h(0200);
    [V1 + 8] = h(0);
    [V1 + a] = h(0);
    V1 = V1 + 10;
}

V0 = w[800584a8];
[V0 + 188] = h(ffff);
[V0 + 18a] = h(00ff);

func4d0b0();
func4d0b0();
func4d0b0();
func4d0b0();

V0 = w[800584a8];
[V0 + 18c] = h(ffff);
[V0 + 18e] = h(00ff);

func4d0b0();
func4d0b0();
func4d0b0();
func4d0b0();

V0 = 0;

L4c7d4:	; 8004C7D4
A0 = w[800584a8];
[800584dc] = w(1);
[A0 + 1aa] = h(c000);
[800584e0] = w(0);
[800584e4] = w(0);
////////////////////////////////



////////////////////////////////
// func4d0b0()

[SP + 4] = w(d);
[SP + 0] = w(0);
8004D0C0	j      L4d0f8 [$8004d0f8]

loop4d0c8:	; 8004D0C8
    [SP + 4] = w(w[SP + 4] * d);
    [SP + 0] = w(w[SP + 0] + 1);

    L4d0f8:	; 8004D0F8
    V0 = w[SP + 0] < 3c;
8004D104	bne    v0, zero, loop4d0c8 [$8004d0c8]
////////////////////////////////
