////////////////////////////////
// func6fb78()

[SP + 30] = b(b[8006f184 + 0]);
[SP + 31] = b(b[8006f184 + 1]);
[SP + 32] = b(b[8006f184 + 2]);

A0 = 0;
func288a4();

movie_clear_work_area_sync();

[80076530] = w(0);
[80076548] = w(1);

for( int i = 0; i < 10; ++i )
{
    [800765c8 + i * 4] = w(0);
}

A0 = 800767b4;
A1 = 0;
A2 = 0;
A3 = 280;
A4 = f0;
system_graphic_create_draw_env_struct()

A0 = 800767b4 + 5c;
A1 = 0;
A2 = f0;
A3 = 280;
A4 = f0;
system_graphic_create_display_env_struct();

A0 = 800767b4 + 138;
A1 = 0;
A2 = f0;
A3 = 280;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 194;
A1 = 0;
A2 = 0;
A3 = 280;
A4 = f0;
system_graphic_create_display_env_struct();

[800767cc] = b(1);
[80076904] = b(1);

A0 = c;
A1 = 3;
system_filesystem_set_dir();

while( true )
{
    V1 = 800767b4;

    if( w[800767b0] == V1 )
    {
        V1 = V1 + 138;
    }

    [800767b0] = w(V1);

    [80076adc] = w(1 - w[80076adc]);

    A0 = V1 + 70;
    A1 = 20;
    system_clear_otagr();

    func70954();

    A0 = 0;
    A1 = 0;
    A2 = SP + 50;
    func73e3c(); // update buttons

    func7045c();

    if( w[8007654c] != 0 )
    {
        A0 = 8006f188; // "Random Mode\n"
        system_print();
    }

    if( w[80076548] == 0 )
    {
        A0 = 8006f198; // "Stream Pause\n"
        system_print();
    }

    A0 = 8006f1a8; // "Read %3d Error %3d VSync %8d EC %2d ST %2d "
    A1 = w[800764d8];
    A2 = w[800764dc];
    A3 = w[800764ec];
    A4 = w[80059b6c];
    A5 = w[8004f4c0];
    system_print();

    if( w[800764f4] == 0 )
    {
        A0 = 8006f1d4; // "Waiting\n"
        system_print();
    }
    else if( w[800764f4] == 1 )
    {
        A0 = 8006f1e0; // "Reading\n"
        system_print();
    }
    else if( w[800764f4] == 2 )
    {
        A0 = 8006f1ec; // "Verifing\n"
        system_print();
    }

    A0 = 8006f1f8; // "C1 %3d C2 %3d C3 %3d C4 %3d C5 %3d C6 %3d C7 %3d C8 %3d C9 %3d\n"
    A1 = w[80059b18];
    A2 = w[80059b1c];
    A3 = w[80059b20];
    A4 = w[80059b24];
    A5 = w[80059b28];
    A6 = w[80059b2c];
    A7 = w[80059b34];
    A8 = w[80059b38];
    A9 = w[80059b44];
    system_print();

    system_cdrom_data_sync();
    S0 = V0;

    func284cc();

    A0 = 8006f238; // "RestFile %7d RestSize %7d N1 %4d N2 %4d N3 %4d R%3d D%3d\n"
    A1 = S0;
    A2 = V0;
    A3 = w[8004f488];
    A4 = w[8004f48c];
    A5 = w[8004f490];
    A6 = hu[8004f4ca];
    A7 = hu[8004f4cc];
    system_print();

    A0 = 8006f274; // "ErrorAddress %8x ErrorSize %8x N%3d N%3d N%3d\n"
    A1 = w[800764f8];
    A2 = w[800764fc];
    A3 = w[80076500];
    A4 = w[80076504];
    A5 = w[80076508];
    system_print();

    A0 = 8006f2a4; // "FrdPtr1 %8x FrdPtr2 %8x Buf1 %8x Buf2 %8x\n"
    A1 = w[8007650c];
    A2 = w[80076510];
    A3 = w[80076518];
    A4 = w[8007651c];
    system_print();

    if( ( w[800764d8] >= b ) || ( w[80076524] > 0 ) )
    {
        A0 = 8006f2d0; // "S %8x Adrs %8x Write %8x Rest %8x\n"
        A1 = w[80076528];
        A2 = w[8007652c];
        A3 = w[80076514];
        A4 = w[80076524];
        system_print();

        for( int i = 0; i < 7; ++i )
        {
            A0 = 8006f2f4; // "%08x "
            V0 = w[80076528];
            A1 = w[V0 + i * 4 + 0];
            system_print();
        }

        A0 = 8006f2fc; // "\n"
        system_print();

        for( int i = 0; i < 7; ++i )
        {
            A0 = 8006f2f4; // "%08x "
            V0 = w[80076528];
            A1 = w[V0 + i * 4 + 1c];
            system_print();
        }

        A0 = 8006f2fc; // "\n"
        system_print();

        for( int i = 0; i < 7; ++i )
        {
            A0 = 8006f2f4; // "%08x "
            V0 = w[80076528];
            A1 = w[V0 + 38 + i * 4];
            system_print();
        }

        A0 = 8006f2fc; // "\n"
        system_print();

        for( int i = 0; i < 7; ++i )
        {
            A0 = 8006f2f4; // "%08x "
            V0 = w[80076528];
            A1 = w[V0 + i * 4 + 54];
            system_print();
        }

        A0 = 8006f2fc; // "\n"
        system_print();

        V1 = w[8007650c];
        if( V1 != 0 )
        {
            A0 = 8006f300; // "%08x %08x %08x %08x %08x\n"
            A1 = w[V1 + 4];
            A2 = w[V1 + c];
            A3 = w[V1 + 14];
            A4 = w[V1 + 1c];
            system_print();
        }
    }

    [80076538] = w(0);

    A0 = 8006f31c; // "Cancel%8d\n"
    A1 = w[80076534];
    system_print();

    S1 = 800765cc;
    for( int i = 0; i < d; ++i )
    {
        A0 = 8006f328; // "CT%1x   %8d"
        A1 = i;
        A2 = w[S1];
        system_print();

        [80076538] = w(w[80076538] + w[S1]);

        if( w[80076540] == i )
        {
            A0 = 8006f334; // " NOW"
            system_print();
        }

        if( w[8007653c] == i )
        {
            A0 = 8006f33c; // " BEFORE"
            system_print();
        }

        A0 = 8006f2fc; // "\n"
        system_print();

        S1 = S1 + 4;
    }

    A0 = 8006f344; // "\nTOTAL %8d : Time %3d:%02d:%02d\n"

    T0 = w[80076558];
    A2 = T0 % 91a2b3c5;
    V1 = T0 % 88888889;
    A1 = w[80076538];

    A2 = A2 + T0;
    A2 = A2 >> b;
    V0 = T0 >> 1f;
    A2 = A2 - V0;

    A3 = A2 << 04;
    A3 = A3 - A2;
    A3 = A3 << 02;
    V1 = V1 + T0;
    V1 = V1 >> 05;
    V1 = V1 - V0;
    A3 = V1 - A3;

    V0 = V1 << 04;
    V0 = V0 - V1;
    V0 = V0 << 2;
    A4 = T0 - V0;
    system_print();

    A0 = 8006f368; // "\nPUSH START BUTTON TO MENU."
    system_print();

    if( w[80076a24] > 0 )
    {
        A0 = 1;
        A1 = 0;
        A2 = 6;
        A3 = 808d;
        system_memory_full_dump();
    }

    A0 = w[800767b0] + 70;
    system_print_render_strings();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + f0;
    A2 = 8;
    A3 = c;
    A4 = 270;
    A5 = d8;
    func72628();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + 114;
    A2 = 7;
    A3 = b;
    A4 = 272;
    A5 = da;
    func72b48()

    A0 = 0;
    system_draw_sync();

    A0 = 0;
    system_psyq_wait_frames();

    A0 = w[800767b0];
    system_psyq_put_draw_env();

    A0 = w[800767b0] + 5c;
    system_psyq_put_disp_env();

    A0 = w[800767b0] + ec;
    system_psyq_draw_otag();

    if( ( w[80076a44] & 0800 ) == 0 )
    {
        if( w[80076a3c] & 0800 )
        {
            if( w[800764d8] == 0 )
            {
                [80076a24] = w(0);

                A0 = 0;
                func2a2a8();

                A0 = 0;
                system_cdrom_action_sync();

                A0 = w[80076530];
                if( A0 != 0 )
                {
                    system_memory_mark_removed_alloc();
                }

                A0 = w[80076528];
                [80076530] = w(0);

                if( A0 != 0 )
                {
                    system_memory_mark_removed_alloc();
                }

                [80076528] = w(0);
                movie_clear_work_area_sync();

                A0 = 800767b4;
                A1 = 0;
                A2 = 0;
                A3 = 140;
                A4 = f0;
                system_graphic_create_draw_env_struct();

                A0 = 800767b4 + 5c;
                A1 = 0;
                A2 = f0;
                A3 = 140;
                A4 = f0;
                system_graphic_create_display_env_struct();

                A0 = 800767b4 + 138;
                A1 = 0;
                A2 = f0;
                A3 = 140;
                A4 = f0;
                system_graphic_create_draw_env_struct();

                A0 = 800767b4 + 194;
                A1 = 0;
                A2 = 0;
                A3 = 140;
                A4 = f0;
                system_graphic_create_display_env_struct();

                [80076818] = h(0);
                [8007681a] = h(a);
                [8007681c] = h(100);
                [8007681e] = h(d8);
                [80076950] = h(0);
                [80076952] = h(a);
                [80076954] = h(100);
                [80076956] = h(d8);
                [800767cc] = b(1);
                [80076904] = b(1);
                return;
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// func7045c()

if( ( ( w[80076a44] & 0020 ) == 0 ) && ( w[80076a3c] & 0020 ) )
{
    A0 = 1;
    func712c4();
}

if( ( ( w[80076a44] & 0010 ) == 0 ) && ( w[80076a3c] & 0010 ) )
{
    A0 = 2;
    func712c4();
}

if( ( ( w[80076a44] & 0080 ) == 0 ) && ( w[80076a3c] & 0080 ) )
{
    A0 = 3;
    func712c4();
}

if( ( ( w[80076a44] & 0040 ) == 0 ) && ( w[80076a3c] & 0040 ) )
{
    [80076534] = w(w[80076534] + 1);

    A0 = 0;
    func2a2a8();
}

if( ( ( w[80076a44] & 1000 ) == 0 ) && ( w[80076a3c] & 1000 ) )
{
    A0 = 7;
    func712c4();
}

if( ( ( w[80076a44] & 4000 ) == 0 ) && ( w[80076a3c] & 4000 ) )
{
    A0 = 9;
    func712c4();
}

if( ( ( w[80076a44] & 0008 ) == 0 ) && ( w[80076a3c] & 0008 ) )
{
    [80076548] = w(1 - w[80076548]);
}

if( ( ( w[80076a44] & 0004 ) == 0 ) && ( w[80076a3c] & 0004 ) )
{
    if( w[800764d8] < b )
    {
        func71230();
    }
}

if( w[80076548] == 1 )
{
    func28924();
    [8007652c] = w(V0);

    if( V0 != 0 )
    {
        if( w[80076524] >= 801 )
        {
            for( int i = 0; i < 200; ++i )
            {
                V1 = w[8007652c];
                A2 = w[80076514];
                [80076514] = w(A2 + 4);
                [A2 + 0] = w(w[V1 + i * 4]);
            }
        }
        else
        {
            for( int i = 0; i < w[80076524] / 4; ++i )
            {
                V1 = w[8007652c];
                A2 = w[80076514];
                [80076514] = w(A2 + 4);
                [A2 + 0] = w(w[V1 + i * 4]);
            }
        }

        [80076524] = w(w[80076524] - 800);

        if( w[80076524] <= 0 )
        {
            if( w[800764d8] == c )
            {
                [80076544] = w(w[80076544] + 1);

                V0 = w[80076544];
                A0 = w[8007650c];
                A1 = hu[A0 + V0 * 8 + 0];

                if( A1 != 0 )
                {
                    A0 = A1;
                    system_get_aligned_filesize_by_dir_file_id();
                    [80076524] = w(V0);
                }

                V0 = w[80076544];
                V1 = w[8007650c];
                [80076514] = w(w[V1 + V0 * 8 + 4]);
            }
        }

        A0 = w[8007652c];
        func2926c();
    }
}

if( w[80076548] == 2 )
{
    A0 = 8007660c;
    A1 = 80076610;
    func28d40();

    if( V0 == 0 )
    {
        A0 = w[80076610];
        func292c4();
    }
}

if( ( ( w[80076a44] & 2000 ) == 0 ) && ( w[80076a3c] & 2000 ) )
{
    A0 = b;
    func712c4();
}

if( ( ( w[80076a44] & 8000 ) == 0 ) && ( w[80076a3c] & 8000 ) )
{
    A0 = d;
    func712c4();
}

if( w[8007654c] != 0 )
{
    func74180();

    S0 = V0 & ff;
    if( S0 == 0 )
    {
        if( w[800764d8] < b )
        {
            func71230();
        }
    }

    if( ( S0 - 1 ) < c )
    {
        A0 = S0;
        func712c4();
    }
}

if( ( ( w[80076a44] & 0100 ) == 0 ) && ( w[80076a3c] & 0100 ) )
{
    [8007654c] = w(1 - w[8007654c]);
}
////////////////////////////////



////////////////////////////////
// func70954

V0 = w[800764f4];
80070970	beq    v0, zero, L71210 [$80071210]

system_cdrom_data_sync();

80070980	bne    v0, zero, L70dc0 [$80070dc0]
V0 = 0001;
V1 = w[800764f4];
80070990	nop
80070994	bne    v1, v0, L70dc0 [$80070dc0]
V1 = 0002;
V0 = w[800764d8];
[800764f4] = w(V1);
800709AC	addiu  v1, v0, $ffff (=-$1)
V0 = V1 < 000c;
800709B4	beq    v0, zero, L70dc0 [$80070dc0]
V0 = V1 << 02;
800709BC	lui    at, $8007
AT = AT + V0;
V0 = w[AT + f384];
800709C8	nop
800709CC	jr     v0 
800709D0	nop

A0 = 2000;
V0 = 2000;
[80076520] = w(V0);
800709E4	jal    $system_memory_allocate
A1 = 0;
A1 = 0;
800709F0	addiu  a0, zero, $ffff (=-$1)
V1 = V0;
[8007651c] = w(V1);

L70a00:	; 80070A00
V0 = w[80076520];
80070A08	nop
80070A0C	bgez   v0, L70a18 [$80070a18]
80070A10	nop
V0 = V0 + 0003;

L70a18:	; 80070A18
V0 = V0 >> 02;
V0 = A1 < V0;
80070A20	beq    v0, zero, L70bc0 [$80070bc0]
A1 = A1 + 0001;
[V1 + 0000] = w(A0);
80070A2C	j      L70a00 [$80070a00]
V1 = V1 + 0004;
80070A34	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 0007;
A0 = V0;
[80076520] = w(A0);
80070A48	jal    $system_memory_allocate
A1 = 0;
A1 = 0;
80070A54	addiu  a0, zero, $ffff (=-$1)
V1 = V0;
[8007651c] = w(V1);

L70a64:	; 80070A64
V0 = w[80076520];
80070A6C	nop
80070A70	bgez   v0, L70a7c [$80070a7c]
80070A74	nop
V0 = V0 + 0003;

L70a7c:	; 80070A7C
V0 = V0 >> 02;
V0 = A1 < V0;
80070A84	beq    v0, zero, L70a98 [$80070a98]
A1 = A1 + 0001;
[V1 + 0000] = w(A0);
80070A90	j      L70a64 [$80070a64]
V1 = V1 + 0004;

L70a98:	; 80070A98
80070A98	j      L70dac [$80070dac]
A0 = 0007;
A0 = 0002;
80070AA4	jal    $func2a38c
A1 = 0;
[80076510] = w(V0);
80070AB4	beq    v0, zero, L70d2c [$80070d2c]
80070AB8	nop
S1 = hu[V0 + 0000];
80070AC0	nop
80070AC4	blez   s1, L70b50 [$80070b50]
80070AC8	addiu  s3, zero, $ffff (=-$1)
S0 = 0;

loop70ad0:	; 80070AD0
V0 = w[80076510];
80070AD8	nop
V0 = S0 + V0;
S2 = w[V0 + 0004];
80070AE4	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = S1;
A1 = 0;
[80076520] = w(V0);
V1 = S2;

L70afc:	; 80070AFC
V0 = w[80076520];
80070B04	nop
80070B08	bgez   v0, L70b14 [$80070b14]
80070B0C	nop
V0 = V0 + 0003;

L70b14:	; 80070B14
V0 = V0 >> 02;
V0 = A1 < V0;
80070B1C	beq    v0, zero, L70b30 [$80070b30]
A1 = A1 + 0001;
[V1 + 0000] = w(S3);
80070B28	j      L70afc [$80070afc]
V1 = V1 + 0004;

L70b30:	; 80070B30
V0 = w[80076510];
S0 = S0 + 0008;
V0 = S0 + V0;
S1 = hu[V0 + 0000];
80070B44	nop
80070B48	bgtz   s1, loop70ad0 [$80070ad0]
80070B4C	nop

L70b50:	; 80070B50
A0 = w[80076510];
80070B58	j      L70d1c [$80070d1c]
A1 = 0;
A0 = 2000;
V0 = 2000;
[80076520] = w(V0);
80070B70	jal    $system_memory_allocate
A1 = 0;
A1 = 0;
80070B7C	addiu  a0, zero, $ffff (=-$1)
V1 = V0;
[8007651c] = w(V1);

L70b8c:	; 80070B8C
V0 = w[80076520];
80070B94	nop
80070B98	bgez   v0, L70ba4 [$80070ba4]
80070B9C	nop
V0 = V0 + 0003;

L70ba4:	; 80070BA4
V0 = V0 >> 02;
V0 = A1 < V0;
80070BAC	beq    v0, zero, L70bc0 [$80070bc0]
A1 = A1 + 0001;
[V1 + 0000] = w(A0);
80070BB8	j      L70b8c [$80070b8c]
V1 = V1 + 0004;

L70bc0:	; 80070BC0
A0 = 0040;
A1 = w[8007651c];
A2 = w[80076520];
A3 = 0;
80070BD8	jal    $func2935c
[SP + 0010] = w(0);
80070BE0	j      L70dc0 [$80070dc0]
80070BE4	nop
80070BE8	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 0007;
A0 = V0;
[80076520] = w(A0);
80070BFC	jal    $system_memory_allocate
A1 = 0;
A1 = 0;
80070C08	addiu  a0, zero, $ffff (=-$1)
V1 = V0;
[8007651c] = w(V1);

L70c18:	; 80070C18
V0 = w[80076520];
80070C20	nop
80070C24	bgez   v0, L70c30 [$80070c30]
80070C28	nop
V0 = V0 + 0003;

L70c30:	; 80070C30
V0 = V0 >> 02;
V0 = A1 < V0;
80070C38	beq    v0, zero, L70c4c [$80070c4c]
A1 = A1 + 0001;
[V1 + 0000] = w(A0);
80070C44	j      L70c18 [$80070c18]
V1 = V1 + 0004;

L70c4c:	; 80070C4C
A0 = 0007;
A1 = w[8007651c];
80070C58	j      L70db8 [$80070db8]
A2 = 0001;
A0 = 0002;
80070C64	jal    $func2a38c
A1 = 0;
[80076510] = w(V0);
80070C74	beq    v0, zero, L70d2c [$80070d2c]
80070C78	nop
S1 = hu[V0 + 0000];
80070C80	nop
80070C84	blez   s1, L70d10 [$80070d10]
80070C88	addiu  s3, zero, $ffff (=-$1)
S0 = 0;

loop70c90:	; 80070C90
V0 = w[80076510];
80070C98	nop
V0 = S0 + V0;
S2 = w[V0 + 0004];
80070CA4	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = S1;
A1 = 0;
[80076520] = w(V0);
V1 = S2;

L70cbc:	; 80070CBC
V0 = w[80076520];
80070CC4	nop
80070CC8	bgez   v0, L70cd4 [$80070cd4]
80070CCC	nop
V0 = V0 + 0003;

L70cd4:	; 80070CD4
V0 = V0 >> 02;
V0 = A1 < V0;
80070CDC	beq    v0, zero, L70cf0 [$80070cf0]
A1 = A1 + 0001;
[V1 + 0000] = w(S3);
80070CE8	j      L70cbc [$80070cbc]
V1 = V1 + 0004;

L70cf0:	; 80070CF0
V0 = w[80076510];
S0 = S0 + 0008;
V0 = S0 + V0;
S1 = hu[V0 + 0000];
80070D04	nop
80070D08	bgtz   s1, loop70c90 [$80070c90]
80070D0C	nop

L70d10:	; 80070D10
A0 = w[80076510];
A1 = 0001;

L70d1c:	; 80070D1C
80070D1C	jal    $func2990c
A2 = 0;
80070D24	j      L70dc0 [$80070dc0]
80070D28	nop

L70d2c:	; 80070D2C
[800764f4] = w(0);
[800764d8] = w(0);
80070D3C	j      L70dc0 [$80070dc0]
80070D40	nop
80070D44	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 0006;
A0 = V0;
[80076520] = w(A0);
80070D58	jal    $system_memory_allocate
A1 = 0;
A1 = 0;
80070D64	addiu  a0, zero, $ffff (=-$1)
V1 = V0;
[8007651c] = w(V1);

L70d74:	; 80070D74
V0 = w[80076520];
80070D7C	nop
80070D80	bgez   v0, L70d8c [$80070d8c]
80070D84	nop
V0 = V0 + 0003;

L70d8c:	; 80070D8C
V0 = V0 >> 02;
V0 = A1 < V0;
80070D94	beq    v0, zero, L70da8 [$80070da8]
A1 = A1 + 0001;
[V1 + 0000] = w(A0);
80070DA0	j      L70d74 [$80070d74]
V1 = V1 + 0004;

L70da8:	; 80070DA8
A0 = 0006;

L70dac:	; 80070DAC
A1 = w[8007651c];
A2 = 0;

L70db8:	; 80070DB8
A3 = 0;
func293e8();

L70dc0:	; 80070DC0
system_cdrom_data_sync();

80070DC8	bne    v0, zero, L71210 [$80071210]
V0 = 0002;
V1 = w[800764f4];
80070DD8	nop
80070DDC	bne    v1, v0, L71210 [$80071210]
80070DE0	nop
V0 = w[800764d8];
[800764f4] = w(0);
80070DF4	addiu  v1, v0, $ffff (=-$1)
V0 = V1 < 000c;
80070DFC	beq    v0, zero, L71208 [$80071208]
V0 = V1 << 02;
80070E04	lui    at, $8007
AT = AT + V0;
V0 = w[AT + f3b4];
80070E10	nop
80070E14	jr     v0 
80070E18	nop

A1 = 0;
T3 = 2000;
T0 = w[8004f488];
T1 = w[8004f48c];
T2 = w[8004f490];
A3 = w[8007651c];
A2 = w[80076518];

loop70e4c:	; 80070E4C
80070E4C	nop
V1 = w[A2 + 0000];
V0 = w[A3 + 0000];
80070E58	nop
80070E5C	beq    v1, v0, L70ea8 [$80070ea8]
A0 = A1 << 02;
V0 = w[800764dc];
80070E6C	nop
80070E70	bne    v0, zero, L711c0 [$800711c0]
80070E74	nop
[800764f8] = w(A0);
[800764fc] = w(T3);
[80076500] = w(T0);
[80076504] = w(T1);
[80076508] = w(T2);
80070EA0	j      L711c8 [$800711c8]
V0 = V0 + 0001;

L70ea8:	; 80070EA8
A3 = A3 + 0004;
A1 = A1 + 0001;
V0 = A1 < 0800;
80070EB4	bne    v0, zero, loop70e4c [$80070e4c]
A2 = A2 + 0004;
80070EBC	j      L711e0 [$800711e0]

A0 = 7;
system_get_aligned_filesize_by_dir_file_id();

[80076520] = w(V0);
A1 = 0;

L70ed8:	; 80070ED8
V0 = w[80076520];
80070EE0	nop
80070EE4	bgez   v0, L70ef0 [$80070ef0]
80070EE8	nop
V0 = V0 + 0003;

L70ef0:	; 80070EF0
V0 = V0 >> 02;
V0 = A1 < V0;
80070EF8	beq    v0, zero, L711e0 [$800711e0]
A2 = A1 << 02;
V0 = w[80076518];
V1 = w[8007651c];
V0 = A2 + V0;
V1 = A2 + V1;
A0 = w[V0 + 0000];
V0 = w[V1 + 0000];
80070F20	nop
80070F24	beq    a0, v0, L70f48 [$80070f48]
80070F28	nop
V0 = w[800764dc];
80070F34	nop
80070F38	bne    v0, zero, L711c8 [$800711c8]
V0 = V0 + 0001;
80070F40	j      L71170 [$80071170]
A0 = 0007;

L70f48:	; 80070F48
80070F48	j      L70ed8 [$80070ed8]
A1 = A1 + 0001;
V0 = w[8007650c];
80070F58	nop
S1 = hu[V0 + 0000];
80070F60	nop
80070F64	blez   s1, L7108c [$8007108c]
S3 = 0;

loop70f6c:	; 80070F6C
V0 = w[80076510];
V1 = w[8007650c];
V0 = S3 + V0;
V1 = S3 + V1;
S2 = w[V0 + 0004];
S0 = w[V1 + 0004];
A0 = S1;
system_get_aligned_filesize_by_dir_file_id();

A1 = 0;
[80076520] = w(V0);
A0 = S2;

L70fa4:	; 80070FA4
V0 = w[80076520];
80070FAC	nop
80070FB0	bgez   v0, L70fbc [$80070fbc]
80070FB4	nop
V0 = V0 + 0003;

L70fbc:	; 80070FBC
V0 = V0 >> 02;
V0 = A1 < V0;
80070FC4	beq    v0, zero, L7106c [$8007106c]
80070FC8	nop
V1 = w[S0 + 0000];
V0 = w[A0 + 0000];
80070FD4	nop
80070FD8	beq    v1, v0, L7105c [$8007105c]
A2 = A1 << 02;
V0 = w[800764dc];
80070FE8	nop
80070FEC	bne    v0, zero, L7104c [$8007104c]
V0 = V0 + 0001;
[800764f8] = w(A2);
A0 = S1;
system_get_aligned_filesize_by_dir_file_id();

V1 = w[8004f488];
A0 = w[8004f48c];
A1 = w[8004f490];
[800764fc] = w(V0);
[80076500] = w(V1);
[80076504] = w(A0);
[80076508] = w(A1);
V0 = w[800764dc];
80071044	nop
V0 = V0 + 0001;

L7104c:	; 8007104C
[800764dc] = w(V0);
80071054	j      L7106c [$8007106c]
80071058	nop

L7105c:	; 8007105C
A0 = A0 + 0004;
S0 = S0 + 0004;
80071064	j      L70fa4 [$80070fa4]
A1 = A1 + 0001;

L7106c:	; 8007106C
V0 = w[8007650c];
S3 = S3 + 0008;
V0 = S3 + V0;
S1 = hu[V0 + 0000];
80071080	nop
80071084	bgtz   s1, loop70f6c [$80070f6c]
80071088	nop

L7108c:	; 8007108C
A0 = w[8007650c];
80071094	jal    $8002a334
80071098	nop
A0 = w[80076510];
800710A4	jal    $8002a334
800710A8	nop
A0 = w[8007650c];
800710B4	jal    $system_memory_mark_removed_alloc
800710B8	nop
A0 = w[80076510];
800710C4	j      L711f8 [$800711f8]
800710C8	nop
V0 = w[80076524];
800710D4	nop
800710D8	blez   v0, L710f0 [$800710f0]
V0 = 0002;
[800764f4] = w(V0);
800710E8	j      L71200 [$80071200]
800710EC	nop

L710f0:	; 800710F0
A0 = 0006;
system_get_aligned_filesize_by_dir_file_id();

[80076520] = w(V0);
A1 = 0;

L71104:	; 80071104
V0 = w[80076520];
8007110C	nop
80071110	bgez   v0, L7111c [$8007111c]
80071114	nop
V0 = V0 + 0003;

L7111c:	; 8007111C
V0 = V0 >> 02;
V0 = A1 < V0;
80071124	beq    v0, zero, L711e0 [$800711e0]
A2 = A1 << 02;
V0 = w[80076518];
V1 = w[8007651c];
V0 = A2 + V0;
V1 = A2 + V1;
A0 = w[V0 + 0000];
V0 = w[V1 + 0000];
8007114C	nop
80071150	beq    a0, v0, L711d8 [$800711d8]
80071154	nop
V0 = w[800764dc];
80071160	nop
80071164	bne    v0, zero, L711c8 [$800711c8]
V0 = V0 + 0001;
A0 = 0006;

L71170:	; 80071170
[800764f8] = w(A2);
system_get_aligned_filesize_by_dir_file_id();

V1 = w[8004f488];
A0 = w[8004f48c];
A1 = w[8004f490];
[800764fc] = w(V0);
[80076500] = w(V1);
[80076504] = w(A0);
[80076508] = w(A1);
V0 = w[800764dc];

L711c0:	; 800711C0
V0 = V0 + 1;

L711c8:	; 800711C8
[800764dc] = w(V0);
800711D0	j      L711e0 [$800711e0]
800711D4	nop

L711d8:	; 800711D8
800711D8	j      L71104 [$80071104]
A1 = A1 + 0001;

L711e0:	; 800711E0
A0 = w[80076518];
system_memory_mark_removed_alloc();

A0 = w[8007651c];

L711f8:	; 800711F8
system_memory_mark_removed_alloc();

L71200:	; 80071200
[800764f4] = w(0);

L71208:	; 80071208
[800764d8] = w(0);

L71210:	; 80071210
////////////////////////////////



////////////////////////////////
// func71230

if( w[80076530] == 0 )
{
    A0 = 2000;
    A1 = 0;
    system_memory_allocate();
    [80076530] = w(V0);
}

A1 = w[80076530];
if( A1 != 0 )
{
    A0 = 40;
    A2 = 2000;
    A3 = 0;
    A4 = 0;
    func2935c();
}

V1 = w[800765cc];
V1 = V1 + 0001;
[800765cc] = w(V1);

if( w[800764dc] == 0 )
{
    V0 = w[80076540];
    [80076540] = w(0);
    [8007653c] = w(V0);
}
////////////////////////////////



////////////////////////////////
// func712c4()

S0 = A0;

if( ( w[800764d8] != 0 ) || ( w[800764f4] != 0 ) )
{
    return;
}

A0 = c;
A1 = 3;
system_filesystem_set_dir();

A0 = S0 - 1;
[800764f4] = w(1);
[800764d8] = w(S0);

switch( A0 )
{
    case 0:
    {
        [800765d0] = w(w[800765d0] + 1);

        [80076520] = w(2000);

        A0 = 2000;
        A1 = 0;
        system_memory_allocate();
        [80076518] = w(V0);

        for( int i = 0; i < ( w[80076520] / 4 ); ++i )
        {
            [V0 + i * 4] = w(0);
        }

        A0 = 40;
        A1 = w[80076518];
        A2 = w[80076520];
        A3 = 0;
        A4 = 0;
        func2935c()
    }
    break;

    case 1:
    {
        [800765d4] = w(w[800765d4] + 1);

        A0 = 7;
        system_get_aligned_filesize_by_dir_file_id();
        [80076520] = w(V0);

        A0 = V0;
        A1 = 0;
        system_memory_allocate();
        [80076518] = w(V0);

        for( int i = 0; i < ( w[80076520] / 4 ); ++i )
        {
            [V0 + i * 4] = w(0);
        }

        A0 = 7; // dir file id
        A1 = w[80076518]; // allocated memory
        A2 = 0;
        A3 = 0;
        func293e8(); // load file
    }
    break;

    case 2:
    {
        [800765d8] = w(w[800765d8] + 1);

        A0 = 2;
        A1 = 0;
        func2a38c();
        [8007650c] = w(V0);

        if( V0 == 0 )
        {
            [800764f4] = w(0);
            [800764d8] = w(0);
        }
        else
        {
            S0 = hu[V0];

            S1 = 0;
            while( S0 > 0 )
            {
                A0 = S0;
                system_get_aligned_filesize_by_dir_file_id();
                [80076520] = w(V0);

                V0 = w[8007650c];
                S0 = w[V0 + S1 + 4];

                for( int i = 0; i < ( w[80076520] / 4 ); ++i )
                {
                    [S0 + i * 4] = w(0);
                }

                V0 = w[8007650c];
                S1 = S1 + 8;
                S0 = hu[V0 + S1 + 0];
            }

            A0 = w[8007650c];
            A1 = 0;
            A2 = 0;
            func2990c();
        }
    }
    break;

    case 3:
    {
        [800765dc] = w(w[800765dc] + 1);

        [80076520] = w(2000);

        A0 = 2000;
        A1 = 0;
        system_memory_allocate();
        [80076518] = w(V0);

        for( int i = 0; i < ( w[80076520] / 4 ); ++i )
        {
            [V0 + i * 4] = w(0);
        }

        A0 = 40;
        A1 = w[80076518];
        A2 = w[80076520];
        A3 = 0;
        A4 = 0;
        func2935c();
    }
    break;

    case 4:
    {
        [800765e0] = w(w[800765e0] + 1);

        A0 = 7;
        system_get_aligned_filesize_by_dir_file_id();
        [80076520] = w(V0);

        A0 = V0;
        A1 = 0;
        system_memory_allocate();
        [80076518] = w(V0);

        for( int i = 0; i < ( w[80076520] / 4 ); ++i )
        {
            [V0 + i * 4] = w(0);
        }

        A0 = 7;
        A1 = w[80076518];
        A2 = 1;
        A3 = 0;
        func293e8();
    }
    break;

    case 5:
    {
        [800765e4] = w(w[800765e4] + 1);

        A0 = 2;
        A1 = 0;
        func2a38c();
        [8007650c] = w(V0);

        if( V0 == 0 )
        {
            [800764f4] = w(0);
            [800764d8] = w(0);
        }
        else
        {
            S0 = hu[V0 + 0];
            S1 = 0;

            while( S0 > 0 )
            {
                A0 = S0;
                system_get_aligned_filesize_by_dir_file_id();
                [80076520] = w(V0);

                V0 = w[8007650c];
                S0 = w[V0 + S1 + 4];

                for( int i = 0; i < ( w[80076520] / 4 ); ++i )
                {
                    [S0 + i * 4] = w(0);
                }

                V0 = w[8007650c];
                S1 = S1 + 8;
                S0 = hu[V0 + S1 + 0];
            }

            A0 = w[8007650c];
            A1 = 1;
            A2 = 0;
            func2990c();
        }
    }
    break;

    case 6:
    {
        [800765e8] = w(w[800765e8] + 1);

        if( w[80076528] == 0 )
        {
            A0 = 4;
            A1 = 0;
            func2a070();
            [80076528] = w(V0);
        }

        A0 = 1;
        A1 = w[80076528];
        A2 = 0;
        A3 = 0;
        A4 = 1;
        A5 = 0;
        A6 = 0;
        A7 = 0;
        A8 = 0;
        A9 = 0;
        func29cc0();
    }
    break;

    case 7:
    {
        [800765ec] = w(w[800765ec] + 1);

        if( w[80076528] == 0 )
        {
            A0 = 4;
            A1 = 0;
            func2a070();
            [80076528] = w(V0);
        }

        A0 = 1;
        A1 = w[80076528];
        A2 = 1;
        A3 = 0;
        A4 = 1;
        A5 = 0;
        A6 = 0;
        A7 = 0;
        A8 = 0;
        A9 = 0;
        func29cc0();
    }
    break;

    case a:
    {
        if( w[80076548] == 2 )
        {
            [80076548] = w(1);
        }

        [800765f8] = w(w[800765f8] + 1);

        if( w[80076528] == 0 )
        {
            A0 = 4;
            A1 = 0;
            func2a070();
            [80076528] = w(V0);
        }

        A0 = 6;
        system_get_aligned_filesize_by_dir_file_id();
        [80076520] = w(V0);
        [80076524] = w(V0);

        A0 = V0;
        A1 = 0;
        system_memory_allocate();
        [80076514] = w(V0);
        [80076518] = w(V0);

        for( int i = 0; i < ( w[80076520] / 4 ); ++i )
        {
            [V0 + i * 4] = w(0);
        }

        A0 = 6;
        A1 = w[80076528];
        A2 = 1;
        A3 = 100;
        func293e8();
    }
    break;

    case b:
    {
        if( w[80076548] == 2 )
        {
            [80076548] = w(1);
        }

        [800765fc] = w(w[800765fc] + 1);

        if( w[80076528] == 0 )
        {
            A0 = 4;
            A1 = 0;
            func2a070();

            [80076528] = w(V0);
        }

        A0 = 2;
        A1 = 0;
        func2a38c();
        [8007650c] = w(V0);

        if( V0 == 0 )
        {
            [800764f4] = w(0);
            [800764d8] = w(0);
        }
        else
        {
            S0 = hu[V0 + 0];
            A0 = S0;
            system_get_aligned_filesize_by_dir_file_id();
            [80076524] = w(V0);

            V1 = w[8007650c];
            [80076544] = w(0);
            [80076514] = w(w[V1 + 4]);

            S1 = 0;

            while( S0 > 0 )
            {
                A0 = S0;
                system_get_aligned_filesize_by_dir_file_id();
                [80076520] = w(V0);

                V0 = w[8007650c];
                S0 = w[V0 + S1 + 4];

                for( int i = 0; i < ( w[80076520] / 4 ); ++i )
                {
                    [S0 + i * 4] = w(0);
                }

                V0 = w[8007650c];
                S1 = S1 + 8;
                S0 = hu[S1 + V0 + 0];
            }

            A0 = w[80076528];
            func288a4();

            A0 = w[8007650c];
            A1 = 1;
            A2 = 100;
            func2990c();
        }
    }
    break;

    case c:
    {
        [80076600] = w(w[80076600] + 1);

        [80076548] = w(2);

        if( w[80076528] != 0 )
        {
            system_memory_mark_removed_alloc();
        }

        A0 = 40;
        A1 = 0;
        func2a070();
        [80076528] = w(V0);

        A0 = 18;
        A1 = 0;
        system_filesystem_set_dir();

        A0 = 3;
        A2 = 0;
        A1 = w[80076528];
        A3 = 200;
        func293e8();
    }
    break;
}

if( w[800764dc] == 0 )
{
    [8007653c] = w(w[80076540]);
    [80076540] = w(w[800764d8]);
}
////////////////////////////////



////////////////////////////////
// func71ab8()

[8007655c] = w(w[8007655c] + 1);
[800764ec] = w(w[800764ec] + 1);

if( w[8007655c] >= 3c )
{
    [8007655c] = w(0);
    [80076558] = w(w[80076558] + 1);
}
////////////////////////////////



////////////////////////////////
// func71b10()

S3 = 0;
S1 = 0;
S4 = 0001;
S2 = 80076614;
V0 = 0001;
[SP + 0038] = w(S0);
[SP + 002c] = w(0);
[SP + 0030] = w(V0);

L71b4c:	; 80071B4C
    V0 = w[800767b0];
    V1 = 800767b4;
    80071B5C	bne    v0, v1, L71b6c [$80071b6c]
    A0 = V1 + 0070;
    V1 = V1 + 0138;
    A0 = V1 + 0070;

    L71b6c:	; 80071B6C
    V0 = w[80076adc];
    [800767b0] = w(V1);
    V0 = S4 - V0;
    [80076adc] = w(V0);

    A1 = 20;
    system_clear_otagr();

    system_filesystem_get_disc_number();

    A0 = 8006f418; // "\n[ DISC CHANGE TEST NOW DISC %2d ]\n\n"
    A1 = V0;
    system_print();

    A0 = 0;
    A1 = 0;
    A2 = SP + 28;
    func73e3c(); // update buttons

    A0 = 8006f440; // "  STATUS "
    system_print();

    V1 = w[SP + 002c];
    80071BCC	nop
    80071BD0	bne    v1, s4, L71be8 [$80071be8]
    V0 = 0002;
    A0 = 8006f44c;
    80071BE0	j      L71c30 [$80071c30]
    80071BE4	nop

    L71be8:	; 80071BE8
    80071BE8	bne    v1, v0, L71c00 [$80071c00]
    V0 = 0003;
    A0 = 8006f470;
    80071BF8	j      L71c30 [$80071c30]
    80071BFC	nop

    L71c00:	; 80071C00
    80071C00	bne    v1, v0, L71c18 [$80071c18]
    V0 = 0004;
    A0 = 8006f488;
    80071C10	j      L71c30 [$80071c30]
    80071C14	nop

    L71c18:	; 80071C18
    A0 = 8006f4b0; // "[ NOP ]\n"
    80071C20	bne    v1, v0, L71c30 [$80071c30]
    80071C24	nop
    A0 = 8006f49c; // "[ RETRY SET DISC ]\n"

    L71c30:	; 80071C30
    80071C30	jal    $system_print
    S0 = 0;
    A0 = 8006f2fc; // "\n"
    80071C40	jal    $system_print
    80071C44	nop
    V0 = S0 < S1;

    loop71c4c:	; 80071C4C
    80071C4C	beq    v0, zero, L71d4c [$80071d4c]
    V0 = S0 < 0009;
    80071C54	beq    v0, zero, L71d60 [$80071d60]
    V0 = S0 << 02;
    80071C5C	lui    at, $8007
    AT = AT + V0;
    V0 = w[AT + f644];
    80071C68	nop
    80071C6C	jr     v0 
    80071C70	nop

    A0 = 8006f4bc; // "  1 : NORMAL SPEED\n"
    80071C7C	jal    $system_print
    S0 = S0 + 0001;
    80071C84	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f4d0; // "  2 : CD STOPED\n"
    80071C94	jal    $system_print
    S0 = S0 + 0001;
    80071C9C	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f4e4; // "  3 : CD OPENED\n"
    80071CAC	jal    $system_print
    S0 = S0 + 0001;
    80071CB4	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f4f8; // "  4 : CD CLOSED\n"
    80071CC4	jal    $system_print
    S0 = S0 + 0001;
    80071CCC	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f50c; // "  5 : SPINDLE OK\n"
    80071CDC	jal    $system_print
    S0 = S0 + 0001;
    80071CE4	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f520; // "  6 : TOC OK\n"
    80071CF4	jal    $system_print
    S0 = S0 + 0001;
    80071CFC	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f530; // "  7 : SET LOCATION OK\n"
    80071D0C	jal    $system_print
    S0 = S0 + 0001;
    80071D14	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    A0 = 8006f548; // "  8 : PLAY STATION DISC OK\n"
    80071D24	jal    $system_print
    S0 = S0 + 0001;
    80071D2C	j      L71d68 [$80071d68]
    V0 = S0 < 0009;
    system_filesystem_get_disc_number();

    A0 = 8006f564; // "  9 : XENOGEARS %2d DISC OK\n"
    A1 = V0;
    80071D44	j      L71d58 [$80071d58]

    L71d4c:	; 80071D4C
    A0 = 8006f584; // " %2d :\n"
    A1 = S0 + 1;

    L71d58:	; 80071D58
    system_print();

    L71d60:	; 80071D60
    S0 = S0 + 0001;
    V0 = S0 < 0009;

    L71d68:	; 80071D68
    80071D68	bne    v0, zero, loop71c4c [$80071c4c]
    V0 = S0 < S1;
    V0 = w[SP + 0030];
    80071D74	nop
    80071D78	beq    v0, zero, L71d98 [$80071d98]
    A1 = S1;
    A0 = 8006f58c; // "\n MODE %1d : NO ERROR  COUNT %6d\n"
    A2 = S3;
    system_print();

    80071D90	j      L71dac [$80071dac]
    80071D94	nop

    L71d98:	; 80071D98
    A0 = 8006f5b0; // "\n MODE %1d : %2d ERROR COUNT %6d\n"
    A2 = 0;
    A3 = S3;
    system_print();

    L71dac:	; 80071DAC
    A1 = bu[S2 + 0000];
    A2 = bu[S2 + 0001];
    A3 = bu[S2 + 0002];
    V0 = bu[S2 + 0003];
    V1 = bu[S2 + 0004];
    T0 = bu[S2 + 0005];
    T1 = bu[S2 + 0006];
    T2 = bu[S2 + 0007];

    A0 = 8006f5d4; // " RESULT %02x %02x %02x %02x %02x %02x %02x %02x\n"
    [SP + 0010] = w(V0);
    [SP + 0014] = w(V1);
    [SP + 0018] = w(T0);
    [SP + 001c] = w(T1);
    [SP + 0020] = w(T2);
    system_print()


    A0 = 8006f608; // "\n\n PUSH START TO TEST.\n"
    system_print();

    A0 = 8006f620; // " PUSH CIRCLE BUTTON TO MENU.\n"
    system_print();

    if( S1 > 0 )
    {
        system_filesystem_get_disc_number();

        A0 = 3 - V0;
        A1 = S1;
        A2 = SP + 2c;
        A3 = SP + 30;
        func72098();

        S1 = V0;
    }

    V0 = w[80076a3c] & 0040;
    80071E48	beq    v0, zero, L71e78 [$80071e78]

    V0 = w[80076a44] & 0040;
    80071E60	bne    v0, zero, L71e78 [$80071e78]
    80071E64	addiu  v0, s1, $ffff (=-$1)
    V0 = V0 < 0007;
    80071E6C	beq    v0, zero, L71e78 [$80071e78]
    80071E70	nop
    S1 = S1 + 0001;

    L71e78:	; 80071E78
    V0 = w[80076a3c];
    80071E80	nop
    V0 = V0 & 0800;
    80071E88	beq    v0, zero, L71ed4 [$80071ed4]
    80071E8C	nop
    V0 = w[80076a44];
    80071E98	nop
    V0 = V0 & 0800;
    80071EA0	bne    v0, zero, L71ed4 [$80071ed4]
    80071EA4	nop
    80071EA8	beq    s1, zero, L71ec8 [$80071ec8]
    V0 = 0009;
    80071EB0	beq    s1, v0, L71ec8 [$80071ec8]
    80071EB4	nop
    V0 = w[SP + 002c];
    80071EBC	nop
    80071EC0	beq    v0, zero, L71ed4 [$80071ed4]
    80071EC4	nop

    L71ec8:	; 80071EC8
    [SP + 002c] = w(0);
    80071ECC	jal    func71fcc [$80071fcc]
    S1 = 0002;

    L71ed4:	; 80071ED4
    V0 = w[80076a24];
    80071EDC	nop
    80071EE0	blez   v0, L71ef0 [$80071ef0]
    80071EE4	nop
    [80076a24] = w(0);

    L71ef0:	; 80071EF0
    A0 = w[800767b0] + 70;
    system_print_render_strings()

    A2 = 0008;
    A3 = 0014;
    A1 = w[800767b0];
    V0 = 0130;
    [SP + 0010] = w(V0);
    V0 = 00c0;
    [SP + 0014] = w(V0);
    A0 = A1 + 0070;
    A1 = A1 + 00f0;
    func72628();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + 114;
    A2 = 7;
    A3 = 13;
    A4 = 132;
    A5 = c2;
    func72b48();

    A0 = 0;
    system_draw_sync();

    A0 = 0;
    system_psyq_wait_frames();

    A0 = w[800767b0];
    system_psyq_put_draw_env();

    A0 = w[800767b0] + 5c;
    system_psyq_put_disp_env();

    A0 = w[800767b0] + ec;
    system_psyq_draw_otag();

    V1 = w[SP + 0028];
    S3 = S3 + 0001;
80071FA0	bne    v1, 2, L71b4c [$80071b4c]
////////////////////////////////



////////////////////////////////
// func71fcc();

system_cdrom_get_cdrom_hdd_mode();

if( V0 == 0 )
{
    A0 = 0;
    func2a2a8();

    A0 = 0;
    system_cdrom_action_sync();

    A0 = 0;
    system_cdrom_command_cdl_set_mode();

    A0 = 0;
    system_cdrom_action_sync();

    A0 = 3;
    system_psyq_wait_frames();

    loop72010:	; 80072010
        A0 = 8;
        A1 = 0;
        A2 = 80076614;
        func410c0();
    80072020	beq    v0, zero, loop72010 [$80072010]
}
////////////////////////////////



////////////////////////////////
// func72038()

S0 = A1;
S2 = A2;

A0 = A0;
A1 = 0;
A2 = 0;
system_devkit_pc_open();
S1 = V0;

A0 = S1;
A1 = S0;
A2 = S2;
system_devkit_pc_read_all();

A0 = S1;
system_devkit_pc_close();
////////////////////////////////



////////////////////////////////
// func72098()

S0 = A0;
S1 = A1;
S3 = A2;
S4 = A3;

[SP + 18] = w(w[8006f668 + 0]); // 8006f668-8006F180
[SP + 1c] = w(w[8006f668 + 4]);
[SP + 20] = w(w[8006f668 + 8]);
[SP + 24] = w(w[8006f668 + c]);

A0 = 0;
A1 = SP + 28;
system_psyq_cd_int_to_pos();

if( w[S3] != 0 )
{
    return S1;
}

S2 = 1;

system_cdrom_get_cdrom_hdd_mode();

if( V0 != 0 )
{
    if( S1 < 9 )
    {
        if( S0 == S2 )
        {
            A0 = 8006f678;
            A1 = w[8004f494];
            A2 = 8000;
            func72038();

            A0 = 8006f68c;
            A1 = w[8004f498];
            A2 = 007a;
            func72038();

            A0 = 8006f6a0;
        }
        else
        {
            A0 = 8006f6b4;
            A1 = w[8004f494];
            A2 = 8000;
            func72038();

            A0 = 8006f6c8;
            A1 = w[8004f498];
            A2 = 007a;
            func72038();

            A0 = 8006f6dc;
        }

        A1 = w[8004f4ec];
        A2 = 40000;
        func72038();

        [S4] = w(S2);

        return 9;
    }
}

V1 = S1 - 1;
switch( V1 )
{
    case 0:
    {
        A0 = 8;
        A1 = 0;
        A2 = 80076614;
        func410c0();
        S2 = V0;

        if( S2 != 0 )
        {
            S1 = S1 + 1;
        }
    }
    break;

    case 1:
    {
        A0 = 1;
        A1 = 0;
        A2 = 80076614;
        func410c0();

        if( bu[80076614] & 10 )
        {
            S1 = S1 + 1;
        }
    }
    break;

    case 2:
    {
        A0 = 1;
        A1 = 0;
        A2 = 80076614;
        func410c0();

        if( ( bu[80076614] & 10 ) == 0 )
        {
            S1 = S1 + 1;
        }
    }
    break;

    case 3:
    {
        A0 = 1;
        A1 = 0;
        A2 = 80076614;
        func410c0();
        S2 = V0;

        if( bu[80076614] & 02 )
        {
            if( S2 != 0 )
            {
                S1 = S1 + 1;
            }
        }
    }
    break;

    case 4:
    {
        A0 = 13;
        A1 = 0;
        A2 = 80076614;
        func410c0();
        S2 = V0;

        if( S2 != 0 )
        {
            S1 = S1 + 1;
        }
    }
    break;

    case 5:
    {
        A0 = 2;
        A1 = SP + 28;
        A2 = 80076614;
        func410c0();
        S2 = V0;

        if( S2 != 0 )
        {
            S1 = S1 + 1;
        }
    }
    break;

    case 6:
    {
        A0 = 15;
        A1 = 0;
        A2 = 80076614;
        func410c0();
        S2 = V0;

        if( ( ( bu[80076614] & 01 ) == 0 ) || ( ( bu[80076615] & 40 ) == 0 ) )
        {
            if( S2 == 0 )
            {
                S1 = 5;
            }
            else
            {
                S1 = S1 + 1;
            }
        }
        else
        {
            if( S2 != 0 )
            {
                S1 = S1 + 1;
            }
            else
            {
                [S3] = w(1);
                S1 = 5;
            }
        }
    }
    break;

    case 7:
    {
        A0 = a0;
        system_cdrom_command_cdl_set_mode();

        A0 = 0;
        system_cdrom_action_sync();

        A0 = 3;
        system_psyq_wait_frames();

        A0 = 17;
        A1 = SP + 18;
        A2 = 10;
        A3 = 0;
        A4 = 0;
        func2935c();

        A0 = 0;
        system_cdrom_action_sync()

        if( w[SP + 1c] != 4e45585f )
        {
            [S3] = w(2);
        }
        else if( bu[SP + 1b] != ( S0 + 30 ) )
        {
            [S3] = w(3);
        }
        else
        {
            S1 = S1 + 1;

            A0 = 18;
            A1 = w[8004f494];
            A2 = 8000;
            A3 = 0;
            A4 = 0;
            func2935c();

            A0 = 0;
            system_cdrom_action_sync();

            A0 = 28;
            A1 = w[8004f498];
            A2 = 7a;
            A3 = 0;
            A4 = 0;
            func2935c();

            A0 = 0;
            system_cdrom_action_sync();

            [S3] = w(0);
    }
    break;
}

[S4] = w(S2);

return S1;
////////////////////////////////



////////////////////////////////
// func72414

S7 = w[SP + 0048];
S3 = A0;
S4 = A1;
S6 = A2;
S5 = A3;
S1 = 0008;
8007244C	lui    s2, $5555
FP = w[SP + 004c];
S2 = S2 | 5556;
S0 = 0;

loop72468:	; 80072468
80072468	jal    func74180 [$80074180]
8007246C	nop
V0 = V0 & 00ff;
80072474	bgez   v0, L72480 [$80072480]
80072478	nop
V0 = V0 + 001f;

L72480:	; 80072480
V0 = V0 >> 05;
V0 = V0 + 0008;
[8007661c + S0] = b(V0);
[8007661d + S0] = b(S1);
800724A0	jal    func74180 [$80074180]

V0 = V0 & 00ff;
800724AC	mult   v0, s2
V0 = V0 >> 1f;
800724B4	mfhi   v1
V1 = V1 - V0;
V1 = V1 + 0010;
[8007661e + S0] = b(V1);
800724CC	jal    func74180 [$80074180]

V0 = V0 & 00ff;
800724D8	bgez   v0, L724e4 [$800724e4]

V0 = V0 + 001f;

L724e4:	; 800724E4
V0 = V0 >> 05;
V0 = V0 + 0008;
[8007662c + S0] = b(V0);
[8007662d + S0] = b(S1);
80072504	jal    func74180 [$80074180]

V0 = V0 & 00ff;
80072510	mult   v0, s2
V0 = V0 >> 1f;
80072518	mfhi   v1
V1 = V1 - V0;
V1 = V1 + 0010;
[8007662e + S0] = b(V1);
S0 = S0 + 0004;
V0 = S0 < 0010;
80072538	bne    v0, zero, loop72468 [$80072468]

S1 = 0;
S2 = 8007664c;
S0 = 8007663c;

loop72554:	; 80072554
80072554	jal    func74180 [$80074180]
[S0 + 0000] = w(0);
V0 = V0 & 00ff;
V0 = V0 + 0020;
[S2 + 0000] = w(V0);
S2 = S2 + 0004;
S1 = S1 + 0001;
V0 = S1 < 0004;
80072574	bne    v0, zero, loop72554 [$80072554]
S0 = S0 + 0004;
8007257C	jal    $80043b3c
A0 = S3;
A0 = S3;
80072588	jal    $80043a74
A1 = 0;
A0 = S4;
S2 = S6 + S7;
S1 = S6;
S0 = S5 + FP;
[S3 + 0008] = h(S6);
[S3 + 000a] = h(S5);
[S3 + 0010] = h(S2);
[S3 + 0012] = h(S5);
[S3 + 0018] = h(S1);
[S3 + 001a] = h(S0);
[S3 + 0020] = h(S2);
800725BC	jal    $80043b3c
[S3 + 0022] = h(S0);
A0 = S4;
800725C8	jal    $80043a74
A1 = 0;
V0 = S5;
[S4 + 0008] = h(S1);
[S4 + 000a] = h(V0);
[S4 + 0010] = h(S2);
[S4 + 0012] = h(V0);
[S4 + 0018] = h(S1);
[S4 + 001a] = h(S0);
[S4 + 0020] = h(S2);
[S4 + 0022] = h(S0);
////////////////////////////////



////////////////////////////////
// func72628()

S0 = A1;
S2 = 0;
S5 = 8007661e;
S4 = 8007662e;
80072654	addiu  t0, s5, $ffff (=-$1)
8007265C	addiu  fp, s4, $ffff (=-$1)
S3 = 8007663c;
80072670	addiu  s7, s5, $fffe (=-$2)
80072678	addiu  s6, s4, $fffe (=-$2)
[SP + 0010] = w(A0);
[SP + 0018] = w(T0);
[SP + 0020] = w(0);
[S0 + 0008] = h(A2);
[S0 + 000a] = h(A3);
[S0 + 0012] = h(A3);
[S0 + 0018] = h(A2);
V0 = w[SP + 0060];
V1 = w[SP + 0064];
A2 = A2 + V0;
A3 = A3 + V1;
[S0 + 0010] = h(A2);
[S0 + 001a] = h(A3);
[S0 + 0020] = h(A2);
[S0 + 0022] = h(A3);

L726c0:	; 800726C0
V1 = w[S3 + 0000];
800726C4	nop
V1 = V1 + 0001;
[S3 + 0000] = w(V1);
T0 = w[SP + 0020];
V0 = 8007664c;
S1 = T0 + V0;
V0 = w[S1 + 0000];
800726E4	nop
V0 = V0 < V1;
800726EC	beq    v0, zero, L7277c [$8007277c]
800726F0	nop
800726F4	jal    func74180 [$80074180]
[S3 + 0000] = w(0);
V0 = V0 & 00ff;
V0 = V0 + 0020;
[S1 + 0000] = w(V0);
V0 = bu[S6 + 0000];
8007270C	nop
[S7 + 0000] = b(V0);
V0 = bu[FP + 0000];
T0 = w[SP + 0018];
8007271C	nop
[T0 + 0000] = b(V0);
V0 = bu[S4 + 0000];
80072728	jal    func74180 [$80074180]
[S5 + 0000] = b(V0);
V0 = V0 & 00ff;
80072734	bgez   v0, L72740 [$80072740]
80072738	nop
V0 = V0 + 001f;

L72740:	; 80072740
V0 = V0 >> 05;
V0 = V0 + 0008;
[S6 + 0000] = b(V0);
V0 = 0008;
80072750	jal    func74180 [$80074180]
[FP + 0000] = b(V0);
V1 = 55555556;
V0 = V0 & 00ff;
80072764	mult   v0, v1
V0 = V0 >> 1f;
8007276C	mfhi   v1
V1 = V1 - V0;
V1 = V1 + 0010;
[S4 + 0000] = b(V1);

L7277c:	; 8007277C
V0 = bu[S6 + 0000];
V1 = bu[S7 + 0000];
A3 = w[S3 + 0000];
V0 = V0 - V1;
8007278C	mult   v0, a3
T0 = w[SP + 0020];
80072794	mflo   a2
80072798	lui    at, $8007
AT = AT + T0;
A0 = w[AT + 664c];
800727A4	nop
800727A8	div    a2, a0
800727D0	mflo   a2
T0 = w[SP + 0018];
800727D8	nop
V1 = bu[T0 + 0000];
V0 = bu[FP + 0000];
800727E4	nop
V0 = V0 - V1;
800727EC	mult   v0, a3
800727F0	mflo   a1
800727F4	nop
800727F8	nop
800727FC	div    a1, a0
80072824	mflo   a1
V1 = bu[S5 + 0000];
V0 = bu[S4 + 0000];
80072830	nop
V0 = V0 - V1;
80072838	mult   v0, a3
8007283C	mflo   v1
80072840	nop
80072844	nop
80072848	div    v1, a0
80072870	mflo   v1
V0 = bu[S7 + 0000];
A2 = V0 + A2;
V0 = bu[T0 + 0000];
A0 = bu[S5 + 0000];
A1 = V0 + A1;
V0 = 0001;
80072890	beq    s2, v0, L728e0 [$800728e0]
A0 = A0 + V1;
V0 = S2 < 0002;
8007289C	beq    v0, zero, L728b4 [$800728b4]
800728A0	nop
800728A4	beq    s2, zero, L728d0 [$800728d0]
800728A8	nop
800728AC	j      L72910 [$80072910]
S5 = S5 + 0004;

L728b4:	; 800728B4
V0 = 0002;
800728B8	beq    s2, v0, L728f0 [$800728f0]
V0 = 0003;
800728C0	beq    s2, v0, L72900 [$80072900]
800728C4	nop
800728C8	j      L72910 [$80072910]
S5 = S5 + 0004;

L728d0:	; 800728D0
[S0 + 0004] = b(A2);
[S0 + 0005] = b(A1);
800728D8	j      L7290c [$8007290c]
[S0 + 0006] = b(A0);

L728e0:	; 800728E0
[S0 + 000c] = b(A2);
[S0 + 000d] = b(A1);
800728E8	j      L7290c [$8007290c]
[S0 + 000e] = b(A0);

L728f0:	; 800728F0
[S0 + 0014] = b(A2);
[S0 + 0015] = b(A1);
800728F8	j      L7290c [$8007290c]
[S0 + 0016] = b(A0);

L72900:	; 80072900
[S0 + 001c] = b(A2);
[S0 + 001d] = b(A1);
[S0 + 001e] = b(A0);

L7290c:	; 8007290C
S5 = S5 + 0004;

L72910:	; 80072910
S4 = S4 + 4;
FP = FP + 4;
S3 = S3 + 4;
S7 = S7 + 4;
S6 = S6 + 4;
T0 = w[SP + 0018];
S2 = S2 + 0001;
T0 = T0 + 0004;
[SP + 0018] = w(T0);
T0 = w[SP + 0020];
V0 = S2 < 0004;
T0 = T0 + 0004;
[SP + 0020] = w(T0);
80072940	bne    v0, zero, L726c0 [$800726c0]

T0 = w[SP + 10];
[S0 + 0] = w((w[S0 + 0] & ff000000) | (w[T0 + 0] & 00ffffff));
[T0 + 0] = w((w[T0 + 0] & ff000000) | (S0 & 00ffffff));
////////////////////////////////



////////////////////////////////
// func729b8()

S3 = A0;
S4 = A1;
S6 = A2;
S5 = A3;
S7 = A4;
FP = A5;

for( int i = 0; i < 10; ++i )
{
    [8007665c + i] = b(ff);
    [8007665d + i] = b(ff);

    func74180();
    V0 = V0 & 003f;

    [8007665e + i] = b(V0 - 42);
    [8007666c + i] = b(ff);
    [8007666d + i] = b(ff);

    func74180();
    V0 = V0 & 003f;

    [8007666e + i] = b(V0 - 42);
}

for( int i = 0; i < 4; ++i )
{
    [8007667c + i * 4] = w(0);

    func74180()
    V0 = V0 & ff;

    [8007668c + i * 4] = w(V0 + 20);
}

A0 = S3;
func43b3c();

[S3 + 8] = h(S6);
[S3 + a] = h(S5);
[S3 + 10] = h(S6 + S7);
[S3 + 12] = h(S5);
[S3 + 18] = h(S6);
[S3 + 1a] = h(S5 + FP);
[S3 + 20] = h(S6 + S7);
[S3 + 22] = h(S5 + FP);

A0 = S4;
func43b3c();

[S4 + 8] = h(S6);
[S4 + a] = h(S5);
[S4 + 10] = h(S6 + S7);
[S4 + 12] = h(S5);
[S4 + 18] = h(S6);
[S4 + 1a] = h(S5 + FP);
[S4 + 20] = h(S6 + S7);
[S4 + 22] = h(S5 + FP);
////////////////////////////////



////////////////////////////////
// func72b48()

S0 = A1;
S5 = 8007665e;
S4 = 8007666e;
T0 = S5 - 1;
FP = S4 - 1;
S7 = S5 - 2;
S6 = S4 - 2;

[SP + 10] = w(A0);

[S0 + 8] = h(A2);
[S0 + a] = h(A3);
[S0 + 12] = h(A3);
[S0 + 18] = h(A2);
[S0 + 10] = h(A2 + A4);
[S0 + 1a] = h(A3 + A5);
[S0 + 20] = h(A2 + A4);
[S0 + 22] = h(A3 + A5);

for( int i = 0; i < 4; ++i )
{
    S1 = 8007667c + i * 4;
    S2 = 8007668c + i * 4;

    [S1] = w(w[S1] + 1);

    if( w[S2] < w[S1] )
    {
        [S1] = w(0);
        [SP + 18] = w(T0);
        func74180();

        [S2] = w((V0 & ff) + 20);
        [S7] = b( bu[S6]);
        T0 = w[SP + 18];
        [T0] = b(bu[FP]);
        [S5] = b(bu[S4]);
        [S6] = b(ff);
        [FP] = b(ff);
        func74180();

        [S4] = b((V0 & 003f) - 42);
        T0 = w[SP + 18];
    }

    A2 = bu[S7] + (((bu[S6] - bu[S7]) * w[S1]) / w[S2]);
    A1 = bu[T0] + (((bu[FP] - bu[T0]) * w[S1]) / w[S2]);
    A0 = bu[S5] + (((bu[S4] - bu[S5]) * w[S1]) / w[S2]);

    if( i == 0 )
    {
        [S0 + 4] = b(A2);
        [S0 + 5] = b(A1);
        [S0 + 6] = b(A0);
    }
    if( i == 1 )
    {
        [S0 + c] = b(A2);
        [S0 + d] = b(A1);
        [S0 + e] = b(A0);
    }
    else if( i == 2 )
    {
        [S0 + 14] = b(A2);
        [S0 + 15] = b(A1);
        [S0 + 16] = b(A0);
    }
    else if( i == 3 )
    {
        [S0 + 1c] = b(A2);
        [S0 + 1d] = b(A1);
        [S0 + 1e] = b(A0);
    }

    S5 = S5 + 4;
    S4 = S4 + 4;
    T0 = T0 + 4;
    FP = FP + 4;
    S7 = S7 + 4;
    S6 = S6 + 4;
}

T1 = w[SP + 10];
[S0 + 0] = w((w[S0 + 0] & ff000000) | (w[T1 + 0] & 00ffffff));
[T1 + 0] = w((w[T1 + 0] & ff000000) | (S0 & 00ffffff));
////////////////////////////////



////////////////////////////////
// movie_main()

A1 = 8006f714; // "trouble"
[SP + 30] = w(w[A1 + 0]);
[SP + 34] = w(w[A1 + 4]);

A0 = 4; // MASA Masaki Kobayashi (Gear Motion/Movie Programming)
A1 = 0;
system_memory_set_alloc_user();

A0 = 18; // set start file 13
A1 = 0;
system_filesystem_set_dir();

A0 = 0;
A1 = 0;
system_sound_set_cd_volume_increase();

A0 = 0;
system_draw_sync();

A0 = 0;
system_psyq_wait_frames();

A0 = 0;
system_psyq_set_disp_mask();

A0 = 4;
A1 = 1;
system_memory_allocate();
S0 = V0;

V1 = ffe2cff8;
A0 = (S0 & 00ffffff) + V1; // 
A1 = 1;
system_memory_allocate();
S4 = V0; // 801d3000

A0 = S0;
system_memory_mark_removed_alloc();

A0 = 1; // local file id
A1 = S4; // memory
A2 = 0;
A3 = 0;
func293e8(); // load file "0\0019"

A0 = 0;
system_cdrom_action_sync();

A0 = 140;
A1 = 100;
A2 = 80;
A3 = 10;
A4 = 20;
A5 = 800;
A6 = 3;
func1d3538();

system_cdrom_get_cdrom_hdd_mode();

[80076ae0] = w(V0);
[80076a30] = w(-1);
[80076a2c] = w(c80);
[80076a24] = w(0);
[80076a40] = w(0);
[80076ae4] = w(1);
[80076ad8] = w(1);
[800767ac] = w(0);
[80076a34] = w(1);
[80076a28] = w(1);
[80076ad4] = w(2);
[80076acc] = w(0);
[80076a38] = w(0);
[80076ac8] = w(0);

A0 = 800767b4;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 5c;
A1 = 0;
A2 = f0;
A3 = 140;
A4 = f0;
system_graphic_create_display_env_struct();

A0 = 800767b4 + 138;
A1 = 0;
A2 = f0;
A3 = 140;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 194;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = f0;
system_graphic_create_display_env_struct();

[800767ca] = b(1);
[800767cc] = b(1);
[80076902] = b(1);
[80076904] = b(1);
[800767cd] = b(0);
[800767ce] = b(0);
[800767cf] = b(0);
[80076820] = b(0);
[80076905] = b(0);
[80076906] = b(0);
[80076907] = b(0);
[80076958] = b(0);
[80076818] = h(0);
[8007681a] = h(a);
[8007681c] = h(100);
[8007681e] = h(d8);
[80076950] = h(0);
[80076952] = h(a);
[80076954] = h(100);
[80076956] = h(d8);
[800767b0] = w(800767b4);
[80076adc] = w(0);

A0 = 800767b4;
system_psyq_put_draw_env();

A0 = w[800767b0] + 5c;
system_psyq_put_disp_env();

if( w[80076ae0] != 0 )
{
    A0 = 2;
    system_psyq_wait_frames();

    A0 = 0;
    system_controller_get_pressed_button_mask();
    [80076a3c] = w(V0);
}
else
{
    [80076a3c] = w(0);
}

if( bu[8004f4e8] != ff )
{
    if( ( w[80076a3c] & 0100 ) == 0 ) // select
    {
        [80076ad0] = w(0);
        [80076a28] = w(1);
        [80076a34] = w(1);

        [800767ac] = w(bu[8004f4e9]);

        V1 = bu[8004f4e8];
        [80076ad8] = w(V1 & 007f);

        if( V1 & 0080 )
        {
            [80076a2c] = w(hu[80061ba4]);
        }
        else
        {
            [80076a2c] = w(e9);
        }

        A0 = bu[8004f4eb];
        func75a4c();

        8007321C	jal    $801d43b0

        A0 = S4;
        system_memory_mark_removed_alloc();

        A0 = bu[8004f4ea];
        func199f0();

        A0 = 0;
        func19b50();
    }
}

A0 = 800768a4;
A1 = 800768a4 + 138;
A2 = 0;
A3 = 0;
A4 = 0;
A5 = 0;
func72414();

A0 = 800768a4 + 24;
A1 = 800768a4 + 15c;
A2 = 0;
A3 = 0;
A4 = 0;
A5 = 0;
func729b8();

A0 = 10;    // start x
A1 = 10;    // start y
A2 = 280;   // area width
A3 = f0;    // area height
A4 = 400;   // max letters
A5 = 0;     // flags
A6 = 280;   // texpage x
A7 = 0;     // texpage y
A8 = 280;   // clut x
A9 = 100;   // clut y
A10 = 0;    // file
system_print_init(); // LsFONT

[80076ad0] = w(1);

A0 = 1;
system_psyq_set_disp_mask();

L732dc:	; 800732DC
    V1 = 800767b4;

    if( w[800767b0] == V1 )
    {
        V1 = V1 + 138;
    }

    [800767b0] = w(V1);

    [80076adc] = w(1 - w[80076adc]);

    A0 = V1 + 70;
    A1 = 20;
    system_clear_otagr();

    system_filesystem_get_disc_number();

    if( w[80076ae0] == 0 )
    {
        A0 = 8006f71c; // "  [ MOVIE CD-ROM MODE1 DISK %1d ]  \n\n"
        A1 = V0;
        system_print();
    }
    else if( w[80076ae0] == -1 )
    {
        A0 = 8006f744; // "  [ MOVIE CD-ROM MODE2 DISK %1d ]  \n\n"
        A1 = V0;
        system_print();
    }
    else
    {
        A0 = 8006f76c; // "  [ MOVIE PC HDD MODE  DISK %1d ]  \n\n"
        A1 = V0;
        system_print();
    }

    A0 = 8006f794; // "    ERROR %2d Sect %2d:%2d FM%3d\n"
    A1 = w[80059b6c];
    A2 = w[80059b38];
    A3 = w[80059b44];
    A4 = h[80059b48];
    system_print();

    A0 = 8006f7b8; // "    LesMem%2d NoMem%2d Skp%3d\n"
    A1 = w[80059b2c];
    A2 = w[80059b34];
    A3 = w[801e89d4];
    A4 = hu[80061ba4];
    system_print();

    A0 = 0;
    A1 = d;
    A2 = SP + 38;
    func73e3c(); // update buttons
    S0 = V0;

    S1 = 1;

    if( w[80076a3c] & 0010 ) // triangle
    {
        S1 = 20;
    }
    if( w[80076a3c] & 0080 ) // square
    {
        S1 = S1 << 7;
    }

    if( w[800767a8] == 0 )
    {
        if( S0 != 0 )
        {
            [80076ad8] = w(w[80076ad8] + S0);

            if( w[80076ad8] < 0 )
            {
                [80076ad8] = w(2);
            }

            if( w[80076ad8] >= 3 )
            {
                [80076ad8] = w(0);
            }

            [80076a34] = w(1);
            [80076a38] = w(0);
            [80076acc] = w(0);
            [80076ad4] = w(2);
        }
    }

    if( w[800767a8] == 1 )
    {
        if( S0 != 0 )
        {
            [800767ac] = w(w[800767ac] + S0);

            if( w[800767ac] < 0 )
            {
                [800767ac] = w(3f);
            }

            if( w[800767ac] >= 40 )
            {
                [800767ac] = w(0);
            }

            [80076a34] = w(1);
            [80076a38] = w(0);
            [80076acc] = w(0);
            [80076ad4] = w(2);
        }
    }

    if( w[800767a8] == 2 )
    {
        if( S0 != 0 )
        {
            [80076a34] = w(w[80076a34] + S0 * S1);

            if( w[80076a34] <= 0 )
            {
                [80076a34] = w(1);
            }

            if( w[80076a34] >= 2000 )
            {
                [80076a34] = w(1fff);
            }

            if( w[80076a2c] < w[80076a34] )
            {
                [80076a34] = w(w[80076a2c]);
            }

            [80076ad4] = w(1);
        }

        if( w[SP + 38] == 2 )
        {
            if( w[80076ad4] == 1 )
            {
                A0 = w[80076a34];
                func74234();

                A0 = w[80076a34];
                V1 = w[80076a2c];
                [80076a38] = w(V0);

                if( A0 >= V1 )
                {
                    [80076a2c] = w(A0);
                    [80076acc] = w(0);
                }

                [80076ad4] = w(2);
            }
        }
    }

    if( w[800767a8] == 3 )
    {
        if( S0 != 0 )
        {
            [80076a2c] = w(w[80076a2c] + S0 * S1);

            if( w[80076a2c] <= 0 )
            {
                [80076a2c] = w(1);
            }

            if( w[80076a2c] >= 2000 )
            {
                [80076a2c] = w(1fff);
            }

            if( w[80076a2c] < w[80076a34] )
            {
                [80076a2c] = w(w[80076a34]);
            }

            [80076acc] = w(0);
        }

        if( w[SP + 38] == 2 )
        {
            if( w[80076acc] == 0 )
            {
                func7482c();

                if( V0 >= 0 )
                {
                    [80076a2c] = w(V0);
                    [80076acc] = w(1);

                    if( w[80076a34] >= V0 )
                    {
                        [80076a34] = w(V0);
                        [80076ad4] = w(1);
                    }
                }
                else
                {
                    [80076acc] = w(2);
                }
            }
        }
    }

    if( w[800767a8] == 4 )
    {
        if( S0 != 0 )
        {
            [80076a28] = w(w[80076a28] + S0);

            if( w[80076a28] < 0 )
            {
                [80076a28] = w(7);
            }
            if( w[80076a28] >= 8 )
            {
                [80076a28] = w(0);
            }
        }
    }

    if( w[800767a8] == 5 )
    {
        if( S0 != 0 )
        {
            [80076ae4] = w(1 - w[80076ae4]);
        }
    }

    if( w[800767a8] == 6 )
    {
        if( S0 != 0 )
        {
            [80076a30] = w((w[80076a30] + S0 * S1) & 00ff);
        }

        if( w[SP + 38] == 2 )
        {
            [80076a30] = w(-1);
        }
    }

    if( w[800767a8] == 7 )
    {
        if( S0 != 0 )
        {
            [80076ac8] = w(1 - w[80076ac8]);
        }
    }

    for( int i = 0; i < e; ++i )
    {
        if( w[800767a8] == i )
        {
            A0 = 8006f7d8; // "  >"
            system_print();
        }
        else
        {
            A0 = 8006f7dc; // "   "
            system_print();
        }

        switch( i )
        {
            case 0:
            {
                A0 = 8006f7e0; // " MOVIE TYPE   "
                system_print();

                if( w[80076ad8] == 0 )
                {
                    A0 = 8006f7f0; // "PICTURE ONLY\n"
                    system_print();
                }
                else if( w[80076ad8] == 1 )
                {
                    A0 = 8006f800; // "PICTURE+ADPCM\n"
                    system_print();
                }
                else if( w[80076ad8] == 2 )
                {
                    A0 = 8006f810; // "ADPCM ONLY\n"
                    system_print();
                }
            }
            break;

            case 1:
            {
                A0 = 8006f81c; // " MOVIE NUMBER %4d\n\n"
                A1 = w[800767ac];
                system_print();
            }
            break;

            case 2:
            {
                A0 = 8006f830; // " START FRAME  %4d "
                A1 = w[80076a34];
                system_print();

                if( w[80076ad4] == 1 )
                {
                    A0 = 8006f844; // "SET"
                    system_print();
                }
                else if( w[80076ad4] == 2 )
                {
                    if( w[80076a38] < 0 )
                    {
                        A0 = 8006f848; // "EOF"
                        system_print();
                    }
                    else
                    {
                        A0 = 8006f84c; // "+%4dSECT"
                        A1 = w[80076a38];
                        system_print();
                    }
                }

                A0 = 8006f858; // "\n"
                system_print();
            }
            break;

            case 3:
            {
                A0 = 8006f85c; // " END   FRAME  %4d "
                A1 = w[80076a2c];
                system_print();

                if( w[80076acc] == 0 )
                {
                    A0 = 8006f844; // "SET"
                    system_print();
                }
                else if( w[80076acc] == 2 )
                {
                    A0 = 8006f870; // "???"
                    system_print();
                }

                A0 = 8006f858; // "\n"
                system_print();
            }
            break;

            case 4:
            {
                A0 = 8006f874; // " MOVIE CHANNEL %3d\n"
                A1 = w[80076a28];
                system_print();
            }
            break;

            case 5:
            {
                A0 = 8006f888; // " SCREEN MODE  "
                system_print();

                if( w[80076ae4] != 0 )
                {
                    A0 = 8006f898; // "24 BIT COLOR"
                    system_print();
                }
                else
                {
                    A0 = 8006f8a8; // "16 BIT COLOR"
                    system_print();
                }

                A0 = 8006f858; // "\n"
                system_print();
            }
            break;

            case 6:
            {
                A0 = 8006f8b8; // " SCREEN DRAW  "
                system_print();

                if( w[80076a30] < 0 )
                {
                    A0 = 8006f8c8; // "ALL"
                    system_print();
                }
                else
                {
                    A0 = 8006f8cc; // "%3d"
                    A1 = w[80076a30];
                    system_print();
                }

                A0 = 8006f858; // "\n"
                system_print();
            }
            break;

            case 7:
            {
                A0 = 8006f8d0; // " REWIND       "
                system_print();

                if( w[80076ac8] != 0 )
                {
                    A0 = 8006f8e0; // "ON"
                    system_print();
                }
                else
                {
                    A0 = 8006f8e4; // "OFF"
                    system_print();
                }

                A0 = 8006f8e8; // "\n\n"
                system_print();
            }
            break;

            case 8:
            {
                A0 = 8006f8ec; // " MOVIE START.\n\n"
                system_print();
            }
            break;

            case 9:
            {
                A0 = 8006f8fc; // " CD-ROM MONITOR.\n\n"
                system_print();
            }
            break;

            case a:
            {
                A0 = 8006f910; // " CD-ROM CHECK.\n"
                system_print();
            }
            break;

            case b:
            {
                A0 = 8006f920; // " FAT CHECK.\n\n"
                system_print();
            }
            break;

            case c:
            {
                A0 = 8006f930; // " [DISC CHANGE.]\n"
                system_print();
            }
            break;

            case d:
            {
                A0 = 8006f944; // " [RETURN TO KERNEL.]\n"
                system_print();
            }
            break;
        }
    }

    if( w[80076a24] > 0 )
    {
        A0 = 1;
        A2 = 6;
        A1 = 0;
        A3 = 808d;
        system_memory_full_dump();
    }

    A0 = w[800767b0] + 70;
    system_print_render_strings();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + f0;
    A2 = 14;
    A3 = c;
    A4 = 11c;
    A5 = c6;
    func72628();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + 114;
    A2 = 13;
    A3 = b;
    A4 = 11e;
    A5 = c8;
    func72b48();

    A0 = 0;
    system_draw_sync();

    A0 = 0;
    system_psyq_wait_frames();

    A0 = w[800767b0];
    system_psyq_put_draw_env();

    A0 = w[800767b0];
    A0 = A0 + 005c;
    system_psyq_put_disp_env();

    A0 = w[800767b0];
    A0 = A0 + 00ec;
    system_psyq_draw_otag();

    S0 = w[800767a8];

    if( ( S0 < 2 ) || ( (S0 - 4) < 2 ) || ( (S0 - 7) < 2 ) )
    {
        if( w[SP + 38] == 2 )
        {
            [80059b2c] = w(0);
            [80059b34] = w(0);
            [80059b38] = w(0);
            [80059b44] = w(0);

            func758ec();

            [80076a3c] = w(-1);
        }
    }

    if( ( w[800767a8] == 9 ) && ( w[SP + 38] == 2 ) )
    {
        func74bc4();
    }

    if( ( w[800767a8] == a ) && ( w[SP + 38] == 2 ) )
    {
        func6fb78();
    }

    if( ( w[800767a8] == d ) && ( w[SP + 38] == 2 ) )
    {
        func7541c();
    }

    if( ( w[800767a8] == c ) && ( w[SP + 38] == 2 ) )
    {
        func71b10();
    }

    if( ( w[800767a8] == d ) && ( w[SP + 38] == 2 ) )
    {
        A0 = S4;
        system_memory_mark_removed_alloc();

        A0 = 0;
        func19b50();
    }

    [800767a8] = w(S0);

    func19d24(); // reset check
80073E10	j      L732dc [$800732dc]
////////////////////////////////



////////////////////////////////
// func73e3c()

S2 = A0;
S1 = A1;
S0 = A2;

[80076a44] = w(w[80076a3c]); // prev buttons

A0 = 0;
system_controller_get_pressed_button_mask();
[80076a3c] = w(V0);

if( ( w[80076a44] == V0 ) && ( w[80076a44] != 0 ) )
{
    [8007657c] = w(w[8007657c] + 1);

    if( w[80076580] < w[8007657c] )
    {
        [80076a44] = w(0);
        [80076580] = w(1);
        [8007657c] = w(0);
    }
}
else
{
    [80076580] = w(10);
    [8007657c] = w(0);

}

if( ( w[80076a44] & 1000 ) == 0 ) // up
{
    if( w[80076a3c] & 1000 )
    {
        [800767a8] = w(w[800767a8] - 1);
        if( w[800767a8] < S2 )
        {
            [800767a8] = w(S1);
        }
    }
}

if( ( w[80076a44] & 4000 ) == 0 ) // down
{
    if( w[80076a3c] & 4000 )
    {
        [800767a8] = w(w[800767a8] + 1);
        if( S1 < w[800767a8] )
        {
            [800767a8] = w(S2);
        }
    }
}

[S0] = w(0);

if( ( w[80076a44] & 0010 ) == 0 )
{
    if( w[80076a3c] & 0010 ) // triangle
    {
        [S0] = w(1);
    }
}

if( ( w[80076a44] & 0020 ) == 0 )
{
    if( w[80076a3c] & 0020 ) // circle
    {
        [S0] = w(2);
    }
}

if( ( w[80076a44] & 0040 ) == 0 )
{
    if( w[80076a3c] & 0040 ) // cross
    {
        [S0] = w(3);
    }
}

if( ( w[80076a44] & 0080 ) == 0 )
{
    if( w[80076a3c] & 0080 ) // square
    {
        [S0] = w(4);
    }
}

if( ( w[80076a44] & 0100 ) == 0 )
{
    if( w[80076a3c] & 0100 ) // select
    {
        [80076a40] = w(1 - w[80076a40]);
    }
}

if( ( w[80076a44] & 0800 ) == 0 )
{
    if( w[80076a3c] & 0800 ) // start
    {
        [80076a24] = w(1 - w[80076a24]);
    }
}

if( ( w[80076a44] & 2000 ) == 0 )
{
    if( w[80076a3c] & 2000 ) // right
    {
        return 1;
    }
}

if( ( w[80076a44] & 8000 ) == 0 )
{
    if( w[80076a3c] & 8000 ) // left
    {
        return -1;
    }
}

return 0;
////////////////////////////////



////////////////////////////////
// func74180()

[80076584] = w(w[80076584] * 3 + 1);
[80076588] = w(w[80076588] * 7 + 3);

[80076584] = w((w[80076584] ^ w[80076588]) + 1);

if( w[80076584] < 0 )
{
    [80076584] = w(0 - w[80076584]);
}

return w[80076584];
////////////////////////////////



////////////////////////////////
// movie_clear_work_area_sync()

[SP + 10] = h(0);
[SP + 12] = h(0);
[SP + 14] = h(280);
[SP + 16] = h(1e0);

A0 = SP + 10;
A1 = 0;
A2 = 0;
A3 = 0;
system_clear_image()

A0 = 0;
system_draw_sync();
////////////////////////////////



////////////////////////////////
// func74234()

V1 = w[80076ad8];
S3 = A0;
S6 = 0;
8007426C	bne    v1, zero, L742c4 [$800742c4]

A0 = 18;
A1 = 0;
system_filesystem_set_dir();

A0 = 2;
system_cdrom_get_number_of_files_in_dir();

V0 = V0 << 10;
A0 = w[800767ac];
V0 = V0 >> 10;
V0 = A0 < V0;
8007429C	beq    v0, zero, L747f8 [$800747f8]
S5 = A0 + 0003;
A0 = S5;
system_filesystem_get_debug_filename();

S0 = V0;
S7 = 0800;
T0 = 0020;
[SP + 1018] = w(T0);
800742BC	j      L74330 [$80074330]
[SP + 1020] = w(0);

L742c4:	; 800742C4
V0 = 0001;
800742C8	beq    v1, v0, L742e0 [$800742e0]
V0 = 0002;
800742D0	bne    v1, v0, L74334 [$80074334]
V0 = S3 < 0002;
800742D8	j      L747f8 [$800747f8]
800742DC	addiu  v0, zero, $ffff (=-$1)

L742e0:	; 800742E0
A0 = 0018;
800742E4	jal    $system_filesystem_set_dir
A1 = 0001;
800742EC	jal    $system_cdrom_get_number_of_files_in_dir
A0 = 0001;
V0 = V0 << 10;
A0 = w[800767ac];
V0 = V0 >> 10;
V0 = A0 < V0;
80074308	beq    v0, zero, L747f8 [$800747f8]
S5 = A0 + 0002;
80074310	jal    $system_filesystem_get_debug_filename
A0 = S5;
S0 = V0;
S7 = 0920;
T0 = 0028;
[SP + 1018] = w(T0);
T0 = 0008;
[SP + 1020] = w(T0);

L74330:	; 80074330
V0 = S3 < 0002;

L74334:	; 80074334
80074334	bne    v0, zero, L747f8 [$800747f8]
V0 = 0;
system_cdrom_get_cdrom_hdd_mode();

80074344	beq    v0, zero, L74594 [$80074594]
A1 = 0;
A0 = S0;
A2 = 0;
system_devkit_pc_open();

S4 = V0;
A0 = S4;
A1 = 0;
A2 = 0002;
system_devkit_pc_seek();

A0 = S4;
A1 = 0;
A2 = 0;
system_devkit_pc_seek();

A0 = S4;
A1 = SP + 18;
A2 = w[SP + 1018];
system_devkit_pc_read_all();

T0 = w[SP + 1020];
S2 = SP + 0018;
S1 = S2 + T0;
FP = hu[S1 + 0006];
8007439C	addiu  v0, s3, $ffff (=-$1)
800743A0	mult   v0, fp
800743A4	mflo   v1
800743A8	bgez   v0, L743b4 [$800743b4]
A0 = S4;
V0 = S3 + 0002;

L743b4:	; 800743B4
V0 = V0 >> 02;
S0 = V1 - V0;
A1 = S0 * S7;
A2 = 0;
system_devkit_pc_seek();

A0 = S4;
A1 = S2;
A2 = w[SP + 1018];
system_devkit_pc_read_all();

V1 = w[S1 + 0008];
800743E0	nop
800743E4	bne    v1, s3, L743f4 [$800743f4]
A0 = V0;
800743EC	bne    a0, zero, L744a4 [$800744a4]
800743F0	nop

L743f4:	; 800743F4
V0 = w[S1 + 0008];
800743F8	nop
V0 = V0 < S3;
80074400	beq    v0, zero, L7441c [$8007441c]
V0 = S6 < S0;
80074408	beq    v0, zero, L7441c [$8007441c]
8007440C	nop
80074410	beq    a0, zero, L74420 [$80074420]
80074414	addiu  v0, s3, $ffff (=-$1)
S6 = S0;

L7441c:	; 8007441C
8007441C	addiu  v0, s3, $ffff (=-$1)

L74420:	; 80074420
80074420	mult   v0, fp
80074424	mflo   v1
80074428	bgez   v0, L74434 [$80074434]
A0 = S4;
V0 = S3 + 0002;

L74434:	; 80074434
V0 = V0 >> 02;
S0 = V1 - V0;
V0 = 92492493;
80074444	mult   s0, v0
V1 = S0 >> 1f;
8007444C	mfhi   v0
V0 = V0 + S0;
V0 = V0 >> 02;
V0 = V0 - V1;
S0 = S0 + V0;
A1 = S0 * S7;
A2 = 0;
system_devkit_pc_seek();

A0 = S4;
A1 = SP + 18;
A2 = w[SP + 1018];
system_devkit_pc_read_all();

T0 = w[SP + 1020];
V1 = SP + 0018;
S1 = V1 + T0;
V1 = w[S1 + 0008];
80074490	nop
80074494	bne    v1, s3, L744c0 [$800744c0]
A0 = V0;
8007449C	beq    a0, zero, L744c0 [$800744c0]
800744A0	nop

L744a4:	; 800744A4
V0 = hu[S1 + 0004];
800744A8	nop
800744AC	beq    v0, zero, L74584 [$80074584]
800744B0	nop
S0 = S0 - V0;
800744B8	j      L74504 [$80074504]
800744BC	addiu  s2, s0, $fffe (=-$2)

L744c0:	; 800744C0
V0 = w[S1 + 0008];
800744C4	nop
V0 = V0 < S3;
800744CC	beq    v0, zero, L744ec [$800744ec]
800744D0	addiu  v1, fp, $ffff (=-$1)
V0 = S6 < S0;
800744D8	beq    v0, zero, L744ec [$800744ec]
800744DC	nop
800744E0	beq    a0, zero, L744f0 [$800744f0]
800744E4	addiu  v0, s3, $ffff (=-$1)
S6 = S0;

L744ec:	; 800744EC
800744EC	addiu  v0, s3, $ffff (=-$1)

L744f0:	; 800744F0
800744F0	mult   v1, v0
800744F4	mflo   s2
800744F8	blez   s6, L74504 [$80074504]
800744FC	nop
S2 = S6;

L74504:	; 80074504
T0 = w[SP + 1020];
V0 = SP + 0018;
S1 = V0 + T0;

loop74510:	; 80074510
S0 = S2;
80074514	mult   s2, s7
A0 = S4;
8007451C	mflo   a1
80074520	jal    $system_devkit_pc_seek
A2 = 0;
A0 = S4;
A2 = w[SP + 1018];
80074530	jal    $system_devkit_pc_read_all
A1 = SP + 0018;
A0 = V0;
V1 = hu[S1 + 0000];
V0 = 0160;
80074544	bne    v1, v0, L74560 [$80074560]
S2 = S0 + 0001;
V0 = hu[S1 + 0006];
V1 = hu[S1 + 0004];
80074554	nop
V0 = V0 - V1;
S2 = S0 + V0;

L74560:	; 80074560
V0 = w[S1 + 0008];
80074564	nop
80074568	beq    v0, s3, L74578 [$80074578]
8007456C	nop
80074570	bgtz   a0, loop74510 [$80074510]
80074574	nop

L74578:	; 80074578
80074578	bne    a0, zero, L74584 [$80074584]
8007457C	nop
80074580	addiu  s0, zero, $ffff (=-$1)

L74584:	; 80074584
80074584	jal    $system_devkit_pc_close
A0 = S4;
8007458C	j      L747f8 [$800747f8]
V0 = S0;

L74594:	; 80074594
80074594	jal    $system_filesystem_get_sector_by_dir_file_id
A0 = S5;
A0 = V0;
A1 = SP + 0018;
A2 = 0800;
A3 = 0;
800745AC	jal    $func2935c
[SP + 0010] = w(0);
800745B4	jal    $system_cdrom_action_sync
A0 = 0;
FP = hu[SP + 001e];
800745C0	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = S5;
V0 = V0 + S7;
800745CC	addiu  v0, v0, $ffff (=-$1)
800745D0	div    v0, s7
800745D4	bne    s7, zero, L745e0 [$800745e0]
800745D8	nop
800745DC	break   $01c00

L745e0:	; 800745E0
800745E0	addiu  at, zero, $ffff (=-$1)
800745E4	bne    s7, at, L745f8 [$800745f8]
800745E8	lui    at, $8000
800745EC	bne    v0, at, L745f8 [$800745f8]
800745F0	nop
800745F4	break   $01800

L745f8:	; 800745F8
800745F8	mflo   s4
800745FC	addiu  v0, s3, $ffff (=-$1)
80074600	nop
80074604	mult   v0, fp
80074608	mflo   v1
8007460C	bgez   v0, L74618 [$80074618]
S1 = SP + 0018;
V0 = S3 + 0002;

L74618:	; 80074618
V0 = V0 >> 02;
S0 = V1 - V0;
80074620	jal    $system_filesystem_get_sector_by_dir_file_id
A0 = S5;
A0 = V0 + S0;
A1 = S1;
A2 = 0800;
A3 = 0;
80074638	jal    $func2935c
[SP + 0010] = w(0);
80074640	jal    $system_cdrom_action_sync
A0 = 0;
V0 = w[SP + 0020];
8007464C	nop
80074650	bne    v0, s3, L7466c [$8007466c]
V0 = S0 < S4;
80074658	beq    v0, zero, L7466c [$8007466c]
8007465C	nop
V0 = hu[SP + 001c];
80074664	j      L7471c [$8007471c]
80074668	nop

L7466c:	; 8007466C
V0 = w[S1 + 0008];
80074670	nop
V0 = V0 < S3;
80074678	beq    v0, zero, L74694 [$80074694]
V0 = S6 < S0;
80074680	beq    v0, zero, L74694 [$80074694]
V0 = S0 < S4;
80074688	beq    v0, zero, L74698 [$80074698]
8007468C	addiu  v0, s3, $ffff (=-$1)
S6 = S0;

L74694:	; 80074694
80074694	addiu  v0, s3, $ffff (=-$1)

L74698:	; 80074698
80074698	mult   v0, fp
8007469C	mflo   v1
800746A0	bgez   v0, L746ac [$800746ac]
A0 = S5;
V0 = S3 + 0002;

L746ac:	; 800746AC
V0 = V0 >> 02;
S0 = V1 - V0;
V0 = 92492493;
800746BC	mult   s0, v0
V1 = S0 >> 1f;
800746C4	mfhi   v0
V0 = V0 + S0;
V0 = V0 >> 02;
V0 = V0 - V1;
800746D4	jal    $system_filesystem_get_sector_by_dir_file_id
S0 = S0 + V0;
A0 = V0 + S0;
A1 = SP + 0018;
A2 = 0800;
A3 = 0;
800746EC	jal    $func2935c
[SP + 0010] = w(0);
800746F4	jal    $system_cdrom_action_sync
A0 = 0;
V0 = w[S1 + 0008];
80074700	nop
80074704	bne    v0, s3, L74740 [$80074740]
V0 = V0 < S3;
V0 = S0 < S4;
80074710	beq    v0, zero, L74734 [$80074734]
80074714	nop
V0 = hu[S1 + 0004];

L7471c:	; 8007471C
8007471C	nop
80074720	beq    v0, zero, L747e4 [$800747e4]
80074724	nop
S0 = S0 - V0;
8007472C	j      L74778 [$80074778]
80074730	addiu  s2, s0, $fffe (=-$2)

L74734:	; 80074734
V0 = w[S1 + 0008];
80074738	nop
V0 = V0 < S3;

L74740:	; 80074740
80074740	beq    v0, zero, L74760 [$80074760]
80074744	addiu  v1, fp, $ffff (=-$1)
V0 = S6 < S0;
8007474C	beq    v0, zero, L74760 [$80074760]
V0 = S0 < S4;
80074754	beq    v0, zero, L74764 [$80074764]
80074758	addiu  v0, s3, $ffff (=-$1)
S6 = S0;

L74760:	; 80074760
80074760	addiu  v0, s3, $ffff (=-$1)

L74764:	; 80074764
80074764	mult   v1, v0
80074768	mflo   s2
8007476C	blez   s6, L7477c [$8007477c]
S1 = SP + 0018;
S2 = S6;

L74778:	; 80074778
S1 = SP + 0018;

L7477c:	; 8007477C
S0 = S2;
80074780	jal    $system_filesystem_get_sector_by_dir_file_id
A0 = S5;
A0 = V0 + S0;
A1 = SP + 0018;
A2 = 0800;
A3 = 0;
80074798	jal    $func2935c
[SP + 0010] = w(0);
800747A0	jal    $system_cdrom_action_sync
A0 = 0;
V1 = hu[SP + 0018];
V0 = 0160;
800747B0	bne    v1, v0, L747cc [$800747cc]
S2 = S0 + 0001;
V0 = hu[SP + 001e];
V1 = hu[SP + 001c];
800747C0	nop
V0 = V0 - V1;
S2 = S0 + V0;

L747cc:	; 800747CC
V0 = w[S1 + 0008];
800747D0	nop
800747D4	beq    v0, s3, L747e4 [$800747e4]
V0 = S2 < S4;
800747DC	bne    v0, zero, L7477c [$8007477c]
800747E0	nop

L747e4:	; 800747E4
V0 = S2 < S4;
800747E8	bne    v0, zero, L747f8 [$800747f8]
V0 = S0;
800747F0	addiu  s0, zero, $ffff (=-$1)
V0 = S0;

L747f8:	; 800747F8
////////////////////////////////



////////////////////////////////
// func7482c

V1 = w[80076ad8];
8007483C	addiu  s4, zero, $ffff (=-$1)
80074854	bne    v1, zero, L748a8 [$800748a8]

A0 = 18;
A1 = 0;
system_filesystem_set_dir();

A0 = 2;
80074868	jal    $system_cdrom_get_number_of_files_in_dir

V0 = V0 << 10;
A0 = w[800767ac];
V0 = V0 >> 10;
V0 = A0 < V0;
80074884	beq    v0, zero, L74a20 [$80074a20]
S1 = A0 + 0003;
A0 = S1;
8007488C	jal    $system_filesystem_get_debug_filename

S0 = V0;
S2 = 0800;
S3 = 0020;
800748A0	j      L7490c [$8007490c]
S5 = 0;

L748a8:	; 800748A8
V0 = 0001;
800748AC	beq    v1, v0, L748c4 [$800748c4]
V0 = 0002;
800748B4	bne    v1, v0, L7490c [$8007490c]
800748B8	addiu  v0, zero, $ffff (=-$1)
800748BC	j      L74a20 [$80074a20]
800748C0	nop

L748c4:	; 800748C4
A0 = 18;
A1 = 1;
system_filesystem_set_dir();

800748D0	jal    $system_cdrom_get_number_of_files_in_dir
A0 = 0001;
V0 = V0 << 10;
A0 = w[800767ac];
V0 = V0 >> 10;
V0 = A0 < V0;
800748EC	beq    v0, zero, L74a20 [$80074a20]
S1 = A0 + 0002;
A0 = S1;
800748F4	jal    $system_filesystem_get_debug_filename

S0 = V0;
S2 = 0920;
S3 = 0028;
S5 = 0008;

L7490c:	; 8007490C
system_cdrom_get_cdrom_hdd_mode();

80074914	beq    v0, zero, L7499c [$8007499c]
A0 = S0;
A1 = 0;
A2 = 0;
system_devkit_pc_open();

S1 = V0;
A0 = S1;
A1 = 0;
A2 = 2;
80074934	jal    $system_devkit_pc_seek

S0 = V0;
A0 = S1;
A1 = 0;
A2 = 0;
80074948	jal    $system_devkit_pc_seek

A0 = S1;
A1 = S0 - S2;
A2 = 0;
80074958	jal    $system_devkit_pc_seek

A0 = S1;
A1 = SP + 0018;
A2 = S3;
system_devkit_pc_read_all();

V0 = SP + 0018;
A0 = V0 + S5;
V1 = hu[A0 + 0000];
V0 = 0160;
80074980	bne    v1, v0, L7498c [$8007498c]
80074984	nop
S4 = w[A0 + 0008];

L7498c:	; 8007498C
A0 = S1;
system_devkit_pc_close();

80074994	j      L74a20 [$80074a20]
V0 = S4;

L7499c:	; 8007499C
A0 = S1;
system_get_aligned_filesize_by_dir_file_id();

V0 = V0 + S2;
800749A8	addiu  v0, v0, $ffff (=-$1)
800749AC	div    v0, s2
800749D4	mflo   s0

A0 = S1;
800749D8	jal    $system_filesystem_get_sector_by_dir_file_id

A1 = SP + 18;
A2 = 0800;
A3 = 0;
[SP + 0010] = w(0);
V0 = V0 + S0;
800749F8	addiu  a0, v0, $ffff (=-$1)
800749F4	jal    $func2935c

A0 = 0;
system_cdrom_action_sync();

V1 = hu[SP + 0018];
V0 = 0160;
80074A0C	bne    v1, v0, L74a20 [$80074a20]
V0 = S4;
S4 = w[SP + 0020];
80074A18	nop
V0 = S4;

L74a20:	; 80074A20
////////////////////////////////



////////////////////////////////
// func74a48()

A0 = 8006f994; // "c:\work\cdrom\sound\wave\main_se.wd"
A1 = 0;
func28380();
S0 = V0;

A0 = S0;
A1 = 0;
system_sound_load_snd_file();

loop74a74:	; 80074A74
    A0 = 0;
    func3bca4();

    V0 = V0 << 10;
80074A80	bne    v0, zero, loop74a74 [$80074a74]

A0 = S0;
system_memory_mark_removed_alloc();

A0 = 8006f9b8; // "c:\work\cdrom\sound\wave\bat_se.wd"
A1 = 0;
func28380();
S0 = V0;

A0 = S0;
A1 = 0;
system_sound_load_snd_file()

loop74ab0:	; 80074AB0
    A0 = 0;
    func3bca4();

    V0 = V0 << 10;
80074ABC	bne    v0, zero, loop74ab0 [$80074ab0]

A0 = S0;
system_memory_mark_removed_alloc();

A0 = 8006f9dc; // "c:\work\cdrom\sound\wave\gear_se.wd"
A1 = 0;
func28380();
S0 = V0;

A0 = S0;
A1 = 0;
system_sound_load_snd_file();

loop74aec:	; 80074AEC
    A0 = 0;
    func3bca4();

    V0 = V0 << 10;
80074AF8	bne    v0, zero, loop74aec [$80074aec]

A0 = S0;
system_memory_mark_removed_alloc();
////////////////////////////////



////////////////////////////////
// func74b1c()

A0 = 8006fa00; // "c:\work\cdrom\sound\wave\battle2.wd"
A1 = 0;
func28380();
S0 = V0;

A0 = S0;
A1 = 0;
system_sound_load_snd_file();


loop74b48:	; 80074B48
    A0 = 0;
    func3bca4();

    V0 = V0 << 10;
80074B54	bne    v0, zero, loop74b48 [$80074b48]

A0 = S0;
system_memory_mark_removed_alloc();

A0 = 8006fa24; // "c:\work\cdrom\sound\music\battle2.smd"
A1 = 0;
func28380();

A0 = V0;
func396f8();
[8007669c] = w(V0);
////////////////////////////////



////////////////////////////////
// func74b98

A0 = w[8007669c];
A1 = 7f;
A2 = 0;
func39928();
////////////////////////////////



////////////////////////////////
// func74bc4()

movie_clear_work_area_sync();

A0 = 800;
A1 = 0;
system_memory_allocate();
S4 = V0;

if( S4 == 0 )
{
    return;
}

A1 = 0;
A0 = 800767b4;
A2 = 0;
A3 = 280;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 5c;
A1 = 0;
A2 = f0;
A3 = 280;
A4 = f0;
system_graphic_create_display_env_struct();

A0 = 800767b4 + 138;
A1 = 0;
A2 = f0;
A3 = 280;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 194;
A1 = 0;
A2 = 0;
A3 = 280;
A4 = f0;
system_graphic_create_display_env_struct();

[800767cc] = b(1);
[80076904] = b(1);
[80076818] = h(0);
[8007681a] = h(a);
[8007681c] = h(100);
[8007681e] = h(d8);
[80076950] = h(0);
[80076952] = h(a);
[80076954] = h(100);
[80076956] = h(d8);

A0 = w[8007658c]; // file sector
A1 = S4; // memory
A2 = 800; // size
A3 = 0;
A4 = 0; // flags
func2935c(); // load file

A0 = 0;
system_cdrom_action_sync();

L74ce8:	; 80074CE8
    V1 = 800767b4;

    if( w[800767b0] == V1 )
    {
        V1 = V1 + 138;
    }

    [800767b0] = w(V1);
    [80076adc] = w(1 - w[80076adc]);

    A0 = V1 + 70;
    A1 = 20;
    system_clear_otagr();

    A0 = 8006fa4c; // "\n[ MONITOR ]\n"
    system_print();

    A0 = 0;
    A1 = 0;
    A2 = SP + 20;
    func73e3c(); // update buttons

    A1 = w[8007658c];

    if( ( ( w[80076a44] & 1000 ) == 0 ) && ( w[80076a3c] & 1000 ) ) // up
    {
        if( w[80076590] > 0 )
        {
            [80076590] = w(w[80076590] - 1);
        }
    }
    if( ( ( w[80076a44] & 4000 ) == 0 ) && ( w[80076a3c] & 4000 ) ) // down
    {
        if( w[80076590] < 74 )
        {
            [80076590] = w(w[80076590] + 1);
        }
    }
    if( ( ( w[80076a44] & 0010 ) == 0 ) && ( w[80076a3c] & 0010 ) ) // triangle
    {
        [80076590] = w(w[80076590] - с);
        if( w[80076590] < 0 )
        {
            [80076590] = w(0);
        }
    }
    if( ( ( w[80076a44] & 0040 ) == 0 ) && ( w[80076a3c] & 0040 ) ) // cross
    {
        [80076590] = w(w[80076590] + c);
        if( w[80076590] >= 74 )
        {
            [80076590] = w(74);
        }
    }

    if( ( ( w[80076a44] & 8000 ) == 0 ) && ( w[80076a3c] & 8000 ) ) // left
    {
        if( w[8007658c] > 0 )
        {
            [8007658c] = w(w[8007658c] - 1);
        }
    }
    if( ( ( w[80076a44] & 2000 ) == 0 ) && ( w[80076a3c] & 2000 ) ) // right
    {
        [8007658c] = w(w[8007658c] + 1);
    }
    if( ( ( w[80076a44] & 0004 ) == 0 ) && ( w[80076a3c] & 0004 ) ) // l1
    {
        [8007658c] = w(w[8007658c] - 4b);
        if( w[8007658c] < 0 )
        {
            [8007658c] = w(0);
        }
    }
    if( ( ( w[80076a44] & 0008 ) == 0 ) && ( w[80076a3c] & 0008 ) ) // r1
    {
        [8007658c] = w(w[8007658c] + 4b);
    }
    if( ( ( w[80076a44] & 0001 ) == 0 ) && ( w[80076a3c] & 0001 ) ) // l2
    {
        [8007658c] = w(w[8007658c] - 1194);
        if( w[8007658c] < 0 )
        {
            [8007658c] = w(0);
        }
    }
    if( ( ( w[80076a44] & 0002 ) == 0 ) && ( w[80076a3c] & 0002 ) ) // r2
    {
        [8007658c] = w(w[8007658c] + 1194);
    }

    if( A1 != w[8007658c] )
    {
        A0 = w[8007658c];
        A1 = S4;
        A2 = 800;
        A3 = 0;
        A4 = 0;
        func2935c();

        A0 = 0;
        system_cdrom_action_sync();
    }

    A0 = w[8007658c];
    A1 = SP + 18;
    system_psyq_cd_int_to_pos();

    A0 = 8006fa5c; // "ABSPOS %8d POS %04x\nMINUTE %02x SECOND %02x SECTOR %02x"
    A1 = w[8007658c];
    A2 = w[80076590] << 4;
    A3 = bu[SP + 18];
    A4 = bu[SP + 19];
    A5 = bu[SP + 1a];
    system_print();

    S2 = S4 + (w[80076590] << 4);
    S1 = S2;

    for( int i = 0; i < c; ++i )
    {
        A0 = 8006fa98; // "%03x:"
        A1 = (w[80076590] + i) << 04;
        system_print();

        for( int j = 0; j < f; ++j )
        {
            A0 = 8006faa0; // "%02x "
            A1 = bu[S1];
            system_print();

            S1 = S1 + 1;
        }

        A0 = 8006faa8; // "%02x"
        A1 = bu[S1];
        system_print();

        A0 = 8006fab0; // ":"
        system_print();

        S1 = S1 + 1;

        for( int j = 0; j < 10; ++j )
        {
            A1 = bu[S2 + 0];

            V0 = A1 - 20;

            if( V0 < 5e )
            {
                A0 = 8006fab4; // "%c"
            }
            else
            {
                A0 = 8006fab8; // " "
            }
            system_print();

            S2 = S2 + 1;
        }

        A0 = 8006fabc; // "\n"
        system_print();
    }

    A0 = 8006fac0; // "\nPUSH CIRCLE BUTTON TO MENU."
    system_print();

    if( w[80076a24] > 0 )
    {
        A0 = 1;
        A2 = 6;
        A1 = 0;
        A3 = 808d;
        system_memory_full_dump();
    }

    A0 = w[800767b0] + 70;
    system_print_render_strings();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + f0;
    A2 = 8;
    A3 = 14;
    A4 = 270;
    A5 = a0;
    func72628();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + 114;
    A2 = 7;
    A3 = 13;
    A4 = 272;
    A5 = a2;
    func72b48()

    A0 = 0;
    system_draw_sync();

    A0 = 0;
    system_psyq_wait_frames();

    A0 = w[800767b0];
    system_psyq_put_draw_env();

    A0 = w[800767b0] + 5c;
    system_psyq_put_disp_env();

    A0 = w[800767b0] + ec;
    system_psyq_draw_otag();

    if( w[SP + 20] == 2 )
    {
        break;
    }

    A0 = w[800767a8];
    [800767a8] = w(A0);
800752D8	j      L74ce8 [$80074ce8]

A0 = S4;
system_memory_mark_removed_alloc();

movie_clear_work_area_sync();

A0 = 800767b4;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 5c;
A1 = 0;
A2 = f0;
A3 = 140;
A4 = f0;
system_graphic_create_display_env_struct()

A0 = 800767b4 + 138;
A1 = 0;
A2 = f0;
A3 = 140;
A4 = f0;
system_graphic_create_draw_env_struct();

A0 = 800767b4 + 194;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = f0;
system_graphic_create_display_env_struct();

[800767cc] = b(1);
[80076904] = b(1);
[80076818] = h(0);
[8007681a] = h(a);
[8007681c] = h(100);
[8007681e] = h(d8);
[80076950] = h(0);
[80076952] = h(a);
[80076954] = h(100);
[80076956] = h(d8);
////////////////////////////////



////////////////////////////////
// func753dc()

V0 = w[8004f494];
return w[V0 + A0 * 7 + 3];
////////////////////////////////



////////////////////////////////
// func7541c()

movie_clear_work_area_sync();

S1 = 0;

A0 = SP + 18;
A1 = SP + 1c;
system_filesystem_get_current_dir();


A0 = 0;
A1 = 0;
system_filesystem_set_dir();

S2 = 0;
S3 = 0;
S6 = 1249;
S4 = 1;
S5 = 5c;

L75474:	; 80075474
    V0 = w[800767b0];
    V1 = 800767b4;
    A0 = V1 + 70;
    if( V0 == V1 )
    {
        V1 = V1 + 138;
        A0 = V1 + 70;
    }

    V0 = w[80076adc];
    [800767b0] = w(V1);
    V0 = S4 - V0;
    [80076adc] = w(V0);
    A1 = 0020;
    system_clear_otagr();

    A0 = 8006fae0; // "\n[ FAT CHECK MODE "
    system_print()

    if( S2 != 0 )
    {
        A0 = 8006faf4; // "HEX ]\n"
    }
    else
    {
        A0 = 8006fafc; // "DEC ]\n"
    }
    system_print();

    A0 = 0;
    A1 = 0;
    A2 = SP + 20;
    func73e3c(); // update buttons

    if( ( w[80076a44] & 1000 == 0 ) && ( w[80076a3c] & 1000 ) )
    {
        if( S1 > 0 )
        {
            S1 = S1 - 1;
        }
    }

    if( ( w[80076a44] & 0010 == 0 ) && ( w[80076a3c] & 0010 ) )
    {
        S1 = S1 - 14;
        if( S1 < 0 )
        {
            S1 = 0;
        }
    }

    if( ( w[80076a44] & 4000 == 0 ) && ( w[80076a3c] & 4000 ) )
    {
        V0 = S6 - 14;
        if( S1 < V0 )
        {
            S1 = S1 + 1;
        }
    }

    if( ( w[80076a44] & 0040 == 0 ) && ( w[80076a3c] & 0040 ) )
    {
        V1 = S6 - 14;
        S1 = S1 + 14;
        if( V1 < S1 )
        {
            S1 = V1;
        }
    }

    if( ( w[80076a44] & 0008 == 0 ) && ( w[80076a3c] & 0008 ) )
    {
        S2 = S4 - S2;
    }

    S0 = S1;

    if( ( w[80076a44] & 0004 == 0 ) && ( w[80076a3c] & 0004 ) )
    {
        S3 = S4 - S3;
    }


    L75660:	; 80075660
        A0 = S0;
        func753dc();

        if( V0 == 0 )
        {
            A1 = S0;
            if( S2 != 0 )
            {
                A0 = 8006fb04; // "No %4x NullFile\n"
            }
            else
            {
                A0 = 8006fb18; // "No %4d NullFile\n"
            }
        }
        else
        {
            if( S2 != 0 )
            {
                A0 = S0 + 1;
                system_filesystem_get_sector_by_dir_file_id();

                A0 = 8006fb2c; // "No %4x Sect%6x "
                A1 = S0;
                A2 = V0;
                system_print();
            }
            else
            {
                A0 = S0 + 1;
                system_filesystem_get_sector_by_dir_file_id();

                A0 = 8006fb3c; // "No %4d Sect%6d "
                A1 = S0;
                A2 = V0;
                system_print();
            }

            if( S3 == 0 )
            {
                if( S2 != 0 )
                {
                    A0 = S0;
                    func753dc();

                    A0 = 8006fb58; // "Size%9x\n"
                    A1 = V0;
                }
                else
                {
                    A0 = S0;
                    func753dc();

                    A0 = 8006fb64; // "Size%9d\n"
                    A1 = V0;
                }
            }
            else
            {
                A0 = S0;
                func753dc();

                if( V0 < 0 )
                {
                    A0 = S0;
                    func753dc();

                    A0 = 8006fb4c; // "[P%3d]\n"
                    A1 = 0 - V0;
                }
                else
                {
                    A0 = S0 + 1;
                    system_filesystem_get_debug_filename();

                    A1 = V0;
                    if( A1 != 0 )
                    {
                        V0 = bu[A1 + 0000];
                        if( V0 != 0 )
                        {
                            V1 = A1;
                            V0 = bu[V1 + 0000];

                            loop7572c:	; 8007572C
                                if( V0 == S5 )
                                {
                                    A1 = V1 + 1;
                                }

                                V1 = V1 + 1;
                                V0 = bu[V1 + 0];
                            80075748	bne    v0, zero, loop7572c [$8007572c]
                        }

                        A0 = 8006fb54; // "%s\n"
                    }
                    else
                    {
                        A0 = 8006fabc; // "\n"
                    }
                }
            }
        }

        S0 = S0 + 1;
        system_print();

        V0 = S0 < (S1 + 14);
    800757BC	bne    v0, zero, L75660 [$80075660]

    A0 = 8006fac0; // "\nPUSH CIRCLE BUTTON TO MENU."
    system_print();

    if( w[80076a24] > 0 )
    {
        A0 = 1;
        A1 = 0;
        A2 = 6;
        A3 = 808d;
        system_memory_full_dump();
    }

    A0 = w[800767b0] + 70;
    system_print_render_strings();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + f0;
    A2 = 8;
    A3 = 14;
    A4 = 130;
    A5 = c0;
    func72628();

    A0 = w[800767b0] + 70;
    A1 = w[800767b0] + 114;
    A2 = 7;
    A3 = 13;
    A4 = 132;
    A5 = c2;
    func72b48();

    A0 = 0;
    system_draw_sync();

    A0 = 0;
    system_psyq_wait_frames();

    A0 = w[800767b0];
    system_psyq_put_draw_env();

    A0 = w[800767b0];
    A0 = A0 + 005c;
    system_psyq_put_disp_env();

    A0 = w[800767b0];
    A0 = A0 + 00ec;
    system_psyq_draw_otag();

    V1 = w[SP + 20];
800758A8	bne    v1, 2, L75474 [$80075474]

A0 = w[SP + 18];
A1 = w[SP + 1c];
system_filesystem_set_dir();
////////////////////////////////



////////////////////////////////
// func758ec

A1 = 8006fb70;
80075900	lwl    v0, $0003(a1)
80075904	lwr    v0, $0000(a1)
80075908	lwl    v1, $0007(a1)
8007590C	lwr    v1, $0004(a1)
80075910	swl    v0, $002b(sp)
80075914	swr    v0, $0028(sp)
80075918	swl    v1, $002f(sp)
8007591C	swr    v1, $002c(sp)
V1 = w[80076ad8];
80075928	addiu  v0, zero, $ffff (=-$1)
[800766b8] = w(0);
[80076a3c] = w(V0);
8007593C	bne    v1, zero, L75958 [$80075958]
V0 = 0001;
A0 = 0018;
80075948	jal    $system_filesystem_set_dir
A1 = 0;
80075950	j      L75970 [$80075970]
A0 = 0002;

L75958:	; 80075958
80075958	bne    v1, v0, L759a4 [$800759a4]
V0 = 0002;
A0 = 0018;
80075964	jal    $system_filesystem_set_dir
A1 = 0001;
A0 = 0001;

L75970:	; 80075970
80075970	jal    $system_cdrom_get_number_of_files_in_dir
80075974	nop
V0 = V0 << 10;
V1 = w[800767ac];
V0 = V0 >> 10;
V1 = V1 < V0;
8007598C	beq    v1, zero, L75a38 [$80075a38]
80075990	nop
80075994	jal    $system_psyq_set_disp_mask
A0 = 0;
8007599C	j      L759ac [$800759ac]
800759A0	nop

L759a4:	; 800759A4
800759A4	beq    v1, v0, L75a38 [$80075a38]
800759A8	nop

L759ac:	; 800759AC
V0 = w[80076ae4];
S0 = 800767cc;
[S0 + 0000] = b(0);
800759C0	beq    v0, zero, L759dc [$800759dc]
[S0 + 0138] = b(0);
V0 = 0001;
[80076821] = b(V0);
[80076959] = b(V0);

L759dc:	; 800759DC
800759DC	jal    func75b18 [$80075b18]
800759E0	nop
800759E4	jal    $system_psyq_wait_frames
A0 = 0;
A0 = SP + 0028;
A1 = 0;
A2 = 0;
800759F8	jal    $system_clear_image
A3 = 0;
80075A00	jal    $system_draw_sync
A0 = 0;
80075A08	jal    $system_psyq_wait_frames
A0 = 0;
V1 = w[80076ae4];
V0 = 0001;
[S0 + 0000] = b(V0);
80075A20	beq    v1, zero, L75a38 [$80075a38]
[S0 + 0138] = b(V0);
[80076821] = b(0);
[80076959] = b(0);

L75a38:	; 80075A38
////////////////////////////////



////////////////////////////////
// func75a4c

A0 = A0 & 00ff;
V1 = w[80076ad8];
80075A5C	addiu  v0, zero, $ffff (=-$1)
[800766b8] = w(A0);
[80076a3c] = w(V0);
80075A74	bne    v1, zero, L75a90 [$80075a90]
V0 = 0001;
A0 = 0018;
80075A80	jal    $system_filesystem_set_dir
A1 = 0;
80075A88	j      L75aa8 [$80075aa8]
A0 = 0002;

L75a90:	; 80075A90
80075A90	bne    v1, v0, L75ad4 [$80075ad4]
V0 = 0002;
A0 = 0018;
80075A9C	jal    $system_filesystem_set_dir
A1 = 0001;
A0 = 0001;

L75aa8:	; 80075AA8
80075AA8	jal    $system_cdrom_get_number_of_files_in_dir
80075AAC	nop
V0 = V0 << 10;
V1 = w[800767ac];
V0 = V0 >> 10;
V1 = V1 < V0;
80075AC4	beq    v1, zero, L75b08 [$80075b08]
80075AC8	nop
80075ACC	j      L75ae0 [$80075ae0]
V0 = 0001;

L75ad4:	; 80075AD4
80075AD4	beq    v1, v0, L75b08 [$80075b08]
80075AD8	nop
V0 = 0001;

L75ae0:	; 80075AE0
[800767cc] = b(0);
[80076904] = b(0);
[80076821] = b(V0);
[80076959] = b(V0);
80075B00	jal    func75b18 [$80075b18]
80075B04	nop

L75b08:	; 80075B08
////////////////////////////////



////////////////////////////////
// func75b18

V0 = w[80076ad8];
A2 = 8006fb70;
80075B54	lwl    v1, $0003(a2)
80075B58	lwr    v1, $0000(a2)
80075B5C	lwl    a0, $0007(a2)
80075B60	lwr    a0, $0004(a2)
80075B64	swl    v1, $00cb(sp)
80075B68	swr    v1, $00c8(sp)
80075B6C	swl    a0, $00cf(sp)
80075B70	swr    a0, $00cc(sp)
[800766a4] = w(0);
[800766b0] = w(0);
80075B84	bne    v0, zero, L75ba0 [$80075ba0]
S1 = 0001;
V0 = w[800767ac];
S1 = 0;
80075B98	j      L75bb0 [$80075bb0]
S0 = V0 + 0003;

L75ba0:	; 80075BA0
V0 = w[800767ac];
S0 = V0 + 0002;

L75bb0:	; 80075BB0
A0 = S0;
system_get_filesize_by_dir_file_id();

V1 = 0018;
80075BBC	bne    v0, v1, L75bdc [$80075bdc]

A0 = 1;
system_psyq_set_disp_mask();

[8004f4ea] = b(0);
80075BD4	j      L75f34 [$80075f34]
80075BD8	nop

L75bdc:	; 80075BDC
A0 = 0;
system_psyq_wait_frames();

A0 = SP + c8;
A1 = 0;
A2 = 0;
A3 = 0;
system_clear_image();

A0 = 0;
system_draw_sync();

A0 = 0;
system_psyq_wait_frames();

[800766a8] = w(0);
[800766ac] = w(0);
80075C18	jal    $801d43b0

V1 = w[80076a30];
80075C28	nop
80075C2C	blez   v1, L75c54 [$80075c54]
V0 = 00f0;
V0 = V0 - V1;
V1 = V0 >> 1f;
V0 = V0 + V1;
V0 = V0 >> 01;
[800766b4] = w(V0);
80075C4C	j      L75c60 [$80075c60]
A0 = 0140;

L75c54:	; 80075C54
[800766b4] = w(0);
A0 = 0140;

L75c60:	; 80075C60
A1 = 00f0;
A2 = 0080;
A3 = 0010;
V1 = hu[80076ae4];
V0 = 0020;
[SP + 0010] = w(V0);
V0 = 0800;
[SP + 0014] = w(V0);
[SP + 0018] = w(V1);
80075C84	jal    $801d3538

V0 = w[80076ac8];
[801d68b4] = w(0);
80075C9C	beq    v0, zero, L75cbc [$80075cbc]
V0 = 0001;
A0 = S0;
T0 = 800766b4;
[SP + 0014] = w(S1);
80075CB4	j      L75cd0 [$80075cd0]
[SP + 0018] = w(V0);

L75cbc:	; 80075CBC
A0 = S0;
T0 = 800766b4;
[SP + 0014] = w(S1);
[SP + 0018] = w(0);

L75cd0:	; 80075CD0
[SP + 001c] = w(0);
[SP + 0024] = w(0);
V1 = hu[T0 + 0000];
A1 = w[80076a38];
A2 = hu[80076a34];
A3 = hu[80076a2c];
V0 = 80075f68;
[SP + 0030] = w(V0);
V0 = hu[80076a28];
T0 = hu[T0 + 0000];
V1 = V1 + 00f0;
[SP + 0010] = w(V0);
V0 = h[80076a30];
V1 = V1 & ffff;
[SP + 0020] = w(T0);
[SP + 0028] = w(V1);
[SP + 002c] = w(V0);
80075D28	jal    $801d37cc

S5 = 001e;
S7 = 66666667;
V0 = w[800766a8];
S0 = 800767b4;
A0 = V0 << 02;
A0 = A0 + V0;
A0 = A0 << 03;
A0 = A0 - V0;
A0 = A0 << 03;
A0 = A0 + S0;
system_psyq_put_draw_env();

S0 = S0 + 005c;
V0 = w[800766a8];
FP = S0;
A0 = V0 << 02;
A0 = A0 + V0;
A0 = A0 << 03;
A0 = A0 - V0;
A0 = A0 << 03;
A0 = A0 + FP;
system_psyq_put_disp_env();

A0 = 1;
system_psyq_set_disp_mask();


loop75d9c:	; 80075D9C
V0 = w[800766b0];
80075DA4	nop
80075DA8	bne    v0, zero, L75e48 [$80075e48]
80075DAC	mult   s5, s7
V1 = S5 >> 1f;
80075DB4	mfhi   v0
V0 = V0 >> 02;
V0 = V0 - V1;
80075DC0	blez   v0, L75e2c [$80075e2c]
S4 = 0;
S6 = V0;
S2 = 80076a4c;
S1 = 80076a48;
S0 = 0001;

loop75de0:	; 80075DE0
A0 = 1;
system_psyq_wait_frames();

S3 = V0;
80075DE8	jal    $801d3f7c

A0 = 1;
system_psyq_wait_frames();

V1 = V0;
V0 = S0 < 0020;
80075E00	beq    v0, zero, L75e10 [$80075e10]
S0 = S0 + 0002;
[S1 + 0000] = w(S3);
[S2 + 0000] = w(V1);

L75e10:	; 80075E10
S2 = S2 + 0008;
S4 = S4 + 0001;
V0 = S4 < S6;
80075E1C	bne    v0, zero, loop75de0 [$80075de0]
S1 = S1 + 0008;
80075E24	mult   s5, s7
V1 = S5 >> 1f;

L75e2c:	; 80075E2C
80075E2C	mfhi   v0
V0 = V0 >> 02;
V0 = V0 - V1;
V1 = V0 << 02;
V1 = V1 + V0;
V1 = V1 << 01;
S5 = S5 - V1;

L75e48:	; 80075E48
S5 = S5 + 001e;
func76034();

func19d24();

A0 = 0;
system_psyq_wait_frames();

V0 = w[800766ac];
80075E68	nop
A0 = V0 << 02;
A0 = A0 + V0;
A0 = A0 << 03;
A0 = A0 - V0;
A0 = A0 << 03;
A0 = A0 + FP;
system_psyq_put_disp_env();

V0 = w[800766a8];
V1 = w[800766a4];
[800766ac] = w(V0);
V0 = 0001;
80075EA4	beq    v1, v0, L75ec4 [$80075ec4]
V0 = V1 < 0002;
80075EAC	bne    v0, zero, loop75d9c [$80075d9c]
80075EB0	addiu  v0, v1, $ffff (=-$1)
[800766a4] = w(V0);
80075EBC	j      loop75d9c [$80075d9c]
80075EC0	nop

L75ec4:	; 80075EC4
80075EC4	jal    $801d4318
80075EC8	nop
V0 = w[800766ac];
80075ED4	nop
80075ED8	bne    v0, zero, L75f34 [$80075f34]
V0 = 0;
A0 = 0;
system_draw_sync();

A0 = 0;
system_psyq_wait_frames();

[SP + 2d0] = h(0);
[SP + 2d2] = h(f0);
[SP + 2d4] = h(1e0);
[SP + 2d6] = h(f0);

A0 = SP + 2d0;
A1 = 0;
A2 = 0;
system_move_image();

A0 = 0;
system_draw_sync();

A0 = 0;
system_psyq_wait_frames();

A0 = FP + 0138;
system_psyq_put_disp_env();

V0 = 0;

L75f34:	; 80075F34
////////////////////////////////



////////////////////////////////
// func75f68

V0 = A0 & ffff;
[800766a0] = w(V0);
V0 = w[801d68b4];
A1 = 0001;
80075F80	bne    v0, a1, L75fbc [$80075fbc]
V0 = A2 & ffff;
V1 = w[800766b4];
80075F90	nop
80075F94	beq    v0, v1, L75fac [$80075fac]
80075F98	nop
[800766a8] = w(0);
80075FA4	j      L75ff8 [$80075ff8]
80075FA8	nop

L75fac:	; 80075FAC
[800766a8] = w(A1);
80075FB4	j      L75ff8 [$80075ff8]
80075FB8	nop

L75fbc:	; 80075FBC
V1 = w[800766b4];
80075FC4	nop
80075FC8	beq    v0, v1, L75fe8 [$80075fe8]
80075FCC	nop
[800766a8] = w(0);
[800766ac] = w(0);
80075FE0	j      L75ff8 [$80075ff8]
80075FE4	nop

L75fe8:	; 80075FE8
[800766a8] = w(A1);
[800766ac] = w(A1);

L75ff8:	; 80075FF8
V1 = w[80076a2c];
V0 = A0 & ffff;
V0 = V0 < V1;
80076008	bne    v0, zero, L7602c [$8007602c]
8007600C	nop
V0 = w[80076ac8];
80076018	nop
8007601C	bne    v0, zero, L7602c [$8007602c]
V0 = 0001;
[800766a4] = w(V0);

L7602c:	; 8007602C
////////////////////////////////



////////////////////////////////
// func76034()

[80076a44] = w(w[80076a3c]);

A0 = 0;
system_controller_get_pressed_button_mask();
[80076a3c] = w(V0);

if( ( w[80076a44] == w[80076a3c] ) && ( w[80076a44] != 0 ) )
{
    [80076594] = w(w[80076594] + 1);

    if( w[80076598] < w[80076594] )
    {
        [80076a44] = w(0);

        [80076598] = w(1);
        [80076594] = w(0);
    }
}
else
{
    [80076598] = w(5a);
    [80076594] = w(0);

}

if( ( ( w[80076a44] & 0020 ) == 0 ) && ( w[80076a3c] & 0020 ) )
{
    if( w[800766b8] == 0 )
    {
        A0 = 0;
        A1 = a;
        system_sound_set_cd_volume_increase();

        [800766a4] = w(5);
    }
}

if( ( ( w[80076a44] & 0800 ) == 0 ) && ( w[80076a3c] & 0800 ) )
{
    if( w[800766b8] == 0 )
    {
        A0 = 0;
        A1 = a;
        system_sound_set_cd_volume_increase();

        [800766a4] = w(5);
    }
}
////////////////////////////////



////////////////////////////////
// func76180

A0 = 200;
system_gte_set_projection_plane_distance();

A0 = a0;
A1 = 78;
system_gte_set_screen_offset();

A0 = 80076700;
[80076748] = h(1000);
[80076750] = h(1000);
[80076758] = h(1000);
[80076788] = h(1000);
[80076790] = h(1000);
[80076798] = h(1000);
[80076720] = h(093d);
800761E4	addiu  v0, zero, $f6c3 (=-$93d)
[80076722] = h(V0);
[80076724] = h(V0);
[8007674a] = h(0);
[8007674c] = h(0);
[8007674e] = h(0);
[80076752] = h(0);
[80076754] = h(0);
[80076756] = h(0);
[8007678a] = h(0);
[8007678c] = h(0);
[8007678e] = h(0);
[80076792] = h(0);
[80076794] = h(0);
[80076796] = h(0);
[80076726] = h(0);
[80076728] = h(0);
[8007672a] = h(0);
[8007672c] = h(0);
[8007672e] = h(0);
[80076730] = h(0);
[A0 + 0000] = h(0969);
[80076702] = h(0);
[80076704] = h(0);
[80076706] = h(0969);
[80076708] = h(0);
[8007670a] = h(0);
[8007670c] = h(0969);
[8007670e] = h(0);
[80076710] = h(0);

func49e04();

A0 = 60;
A1 = 60;
A2 = 60;
func49f94();
////////////////////////////////



////////////////////////////////
// func762f8()

func76334();

A0 = 800766e0;
system_gte_set_rotation_matrix();

A0 = 800766e0;
system_gte_set_translation_vector();
////////////////////////////////



////////////////////////////////
// func76334()

S1 = w[800766d4] - w[800766c4];
S4 = S1 * S1;

S0 = w[800766cc] - w[800766bc];
S3 = S0 * S0;

A0 = S4 + S3;
system_square_root();

S2 = w[800766d0] - w[800766c0];

A0 = S2;
A1 = V0;
system_get_rotation_based_on_vector_x_y();
[80076740] = h(V0);

A0 = S0;
A1 = S1;
system_get_rotation_based_on_vector_x_y();
[80076742] = h(0 - V0);

A0 = 80076740;
A1 = 80076768; // res
system_calculate_rotation_matrix();

A0 = w[800766dc];
A1 = 80076768;
80076404	jal    $8004b034

A0 = 80076788;
A1 = 80076768; // res
system_gte_matrix_multiplication_to_A1();

[8007677c] = w(0);
[80076780] = w(0);

A0 = S4 + S3 + S2 * S2;
system_square_root();
[80076784] = w(V0);

[8007675c] = w(w[800765bc] - w[800766cc]);
[80076760] = w(w[800765c0] - w[800766d0]);
[80076764] = w(w[800765c4] - w[800766d4]);

A0 = 80076768;
A1 = 8007675c - 14;
A2 = 800766e0; // res
system_gte_matrix_mult_and_trans();
////////////////////////////////
