////////////////////////////////
// func6f47c()
S0 = A0; // pointer to field +154

S1 = 800aee64;

A0 = S1;
A1 = S1 - 110;
A2 = S1 - 100;
A3 = S1 - f0;
8006F4A8	jal    func72de0 [$80072de0]

S2 = S1 + d4;

A0 = S1 + c4; // rot data
A1 = S1 + d4;
system_calculate_rotation_matrix();

A0 = S1;
A1 = S1 + d4;
8006F4C4	jal    system_gte_matrix_multiplication_to_A1 [$80049a84]

V0 = h[S0];
S0 = S0 + 2;
[S1 + 138] = w(V0);
A0 = 0;
A1 = S1 + 0138;

V0 = h[S0 + 0000];
S0 = S0 + 0002;
[800aefa0] = w(V0);
V0 = h[S0 + 0000];
S0 = S0 + 0004;
[800aefa4] = w(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefa8] = h(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefaa] = h(V0);
V0 = hu[S0 + 0000];
8006F52C	nop
V0 = V0 << 03;
[800aefac] = h(V0);
8006F53C	jal    func30840 [$80030840]
S0 = S0 + 0004;
V0 = h[S0 + 0000];
S0 = S0 + 0002;
A0 = 0001;
A1 = S1 + 014c;
[S1 + 014c] = w(V0);
V0 = h[S0 + 0000];
S0 = S0 + 0002;
[800aefb4] = w(V0);
V0 = h[S0 + 0000];
S0 = S0 + 0004;
[800aefb8] = w(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefbc] = h(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefbe] = h(V0);
V0 = hu[S0 + 0000];
8006F5A4	nop
V0 = V0 << 03;
[800aefc0] = h(V0);
8006F5B4	jal    func30840 [$80030840]
S0 = S0 + 0004;
V0 = h[S0 + 0000];
S0 = S0 + 0002;
A0 = 0002;
A1 = S1 + 0160;
[S1 + 0160] = w(V0);
V0 = h[S0 + 0000];
S0 = S0 + 0002;
[800aefc8] = w(V0);
V0 = h[S0 + 0000];
S0 = S0 + 0004;
[800aefcc] = w(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefd0] = h(V0);
V0 = hu[S0 + 0000];
S0 = S0 + 0002;
V0 = V0 << 03;
[800aefd2] = h(V0);
V0 = hu[S0 + 0000];
8006F61C	nop
V0 = V0 << 03;
[800aefd4] = h(V0);
V0 = w[S1 + 0138];
V1 = w[S1 + 013c];

L6f634:	; 8006F634
A2 = w[S1 + 0140];
A3 = w[S1 + 0144];
[S1 + 014c] = w(V0);
[S1 + 0150] = w(V1);
[S1 + 0154] = w(A2);
[S1 + 0158] = w(A3);
V0 = w[S1 + 0148];
8006F650	nop
[S1 + 015c] = w(V0);
V0 = w[S1 + 0138];
V1 = w[S1 + 013c];
A2 = w[S1 + 0140];

L6f664:	; 8006F664
A3 = w[S1 + 0144];
[S1 + 0160] = w(V0);
[S1 + 0164] = w(V1);
[S1 + 0168] = w(A2);
[S1 + 016c] = w(A3);
V0 = w[S1 + 0148];
8006F67C	nop
[S1 + 0170] = w(V0);
S0 = S0 + 0004;
8006F684	jal    func30840 [$80030840]

V0 = hu[S0 + 0000];
8006F690	nop
V0 = V0 << 04;
[800aefd8] = h(V0);
V0 = hu[S0 + 0002];
8006F6A4	nop
V0 = V0 << 04;
[800aefda] = h(V0);
V0 = hu[S0 + 0004];
8006F6B8	nop
V0 = V0 << 04;
[800aefdc] = h(V0);

A0 = S1;
system_gte_set_rotation_matrix();

A0 = S1;
system_gte_set_translation_vector();

A0 = S1 + cc;
A1 = S1 + e8;
A2 = SP + 10;
8006F6E0	jal    system_gte_rotate_translate_vector [$8004a584]

A0 = S2; // original light matrix without rotation.
system_gte_calculate_and_set_lighting_matrix();

A0 = S2;
system_gte_set_rotation_matrix();

A0 = S2;
system_gte_set_translation_vector();
////////////////////////////////



////////////////////////////////
// func6f71c
A0 = A1;
A1 = A2;
system_extract_archive;
////////////////////////////////



////////////////////////////////
// func6f740()

A0 = 1; // cancels the current drawing and flushes the command buffer.
system_psyq_reset_graph();

func1c768(); // clear GP + 418 and GP + 420

S1 = 0;
loop6f768:	; 8006F768
    func24e3c(); // load defined set of images to vram

    A0 = 0; // wait for termination
    system_draw_sync();

    S1 = S1 + 1;

    A0 = (w[800acfe0] + S1) & 1;
    func24ed4(); // clear some set of images and set to load next

    func24e3c(); // load defined set of images to vram

    A0 = 0; // wait for termination
    system_draw_sync();

    func24db0(); // free memory of GP + 340 and reset render sprites list pointer

    V0 = S1 < 2;
8006F7B0	bne    v0, zero, loop6f768 [$8006f768]

struct_5c_p = w[800aefe4];
number_of_entity = w[800aefe0];
if( number_of_entity > 0 )
{
    S1 = 0;
    loop6f7d0:	; 8006F7D0
        A0 = S1;
        func7fe50(); // clear sprite and script entity allocated data

        // clear model data
        if( ( hu[struct_5c_p + S1 * 5c + 58] & 0040 ) == 0 )
        {
            model_struct = w[struct_5c_p + S1 * 5c + 0];

            if( hu[struct_5c_p + S1 * 5c + 58] & 2000 )
            {
                A0 = w[model_struct + 14];
                func304e0(); // clear additional +8 and +c in parts data and restore original pointers.
            }

            A0 = w[model_struct + 4];
            func2c9cc();

            A0 = w[model_struct + 8];
            system_memory_mark_removed_alloc(); // clear packets

            A0 = model_struct;
            system_memory_mark_removed_alloc();
        }

        S1 = S1 + 1;
        V0 = S1 < number_of_entity;
    8006F858	bne    v0, zero, loop6f7d0 [$8006f7d0]
}

clear_distortion_buffers();

A0 = w[800aefe4]; // allocated entity data
system_memory_mark_removed_alloc();

A0 = w[800ad0cc]; // field triggers
system_memory_mark_removed_alloc();

A0 = w[800ad0c8]; // field dialog
system_memory_mark_removed_alloc();

A0 = w[800ad0d0]; // field script
system_memory_mark_removed_alloc();

A0 = w[800aefec]; // field walkmesh
system_memory_mark_removed_alloc();

A0 = w[800aefe8]; // field model
system_memory_mark_removed_alloc();

A0 = w[800aeff0]; // field sprite
system_memory_mark_removed_alloc();

if( h[800af586] != 0 )
{
    A0 = w[800af550];
    system_cdrom_memory_mark_removed_alloc();
}



A0 = 800af37c;
V0 = h[A0];
if( V0 > 0 )
{
    S1 = 0;
    S3 = A0 + 0004;
    S0 = S3;
    S2 = A0 + 0084;

    loop6f920:	; 8006F920
        A0 = w[S0 + 0000];
        8006F924	jal    func27e1c [$80027e1c]
        S1 = S1 + 0001;

        A0 = w[S2];
        system_memory_mark_removed_alloc();

        S2 = S2 + 0004;

        A0 = w[S0];
        system_memory_mark_removed_alloc();

        S0 = S0 + 0004;
        V0 = h[S3 + fffc];
        8006F948	nop
        V0 = S1 < V0;
    8006F950	bne    v0, zero, loop6f920 [$8006f920]
}

system_print_clear_memory();

[800af37c] = h(0);

if( w[800b1738] != 0 )
{
    8006F97C	jal    func1e7fd4 [$801e7fd4]

    A0 = w[800acff8];
    system_memory_mark_removed_alloc();

    field_flush_sync();
}
[800b1738] = w(0);

A0 = 3;
system_memory_mark_removed_alloc_by_type();

funca788c();
////////////////////////////////



////////////////////////////////
// field_load_tim_into_vram()

image_x = A1;
image_y = A2;
clut_x = A3;
clut_y = A4;
clut_width = A5;
clut_height = A6;

A0 = A0;
system_set_texture_address();

A0 = SP + 10;
system_read_tim();

if( V0 != 0 )
{
    clut_sizes = w[SP + 14];
    clut_data = w[SP + 18];

    if( clut_data != 0 )
    {
        if( ( (clut_y << 10) >> 10 ) != -1 )
        {
            [clut_sizes + 0] = h(clut_x);
            [clut_sizes + 2] = h(clut_y);
        }

        if( ( clut_width << 10 ) != 0 )
        {
            [clut_sizes + 4] = h(clut_width);
        }

        if( ( clut_height << 10 ) != 0 )
        {
            [clut_sizes + 6] = h(clut_height);
        }

        A0 = clut_sizes;
        A1 = clut_data;
        system_load_image(); // transfer data from pointer to a frame buffer to given rect
    }

    image_sizes = w[SP + 1c];
    image_data = w[SP + 20];

    if( image_data != 0 )
    {
        [image_sizes + 0] = h(image_x);
    }
    [image_sizes + 2] = h(image_y);

    A0 = image_sizes;
    A1 = image_data;
    system_load_image(); // transfer data from pointer to a frame buffer to given rect
}
////////////////////////////////



////////////////////////////////
// func6fb18
V0 = w[800ad038];
8006FB20	addiu  sp, sp, $ffd0 (=-$30)
8006FB24	bne    v0, zero, L6fb88 [$8006fb88]
[SP + 0028] = w(RA);
A0 = 0004;
V0 = 0001;
[800ad038] = w(V0);
8006FB3C	jal    $8002a070
A1 = 0001;
A1 = V0;
A2 = 0;
A0 = w[8004e9f0];
A3 = 0;
[800ad0ec] = w(A1);
[SP + 0010] = w(0);
[SP + 0014] = w(0);
[SP + 0018] = w(0);
[SP + 001c] = w(0);
[SP + 0020] = w(0);
[SP + 0024] = w(0);
A0 = A0 & 0fff;
A0 = A0 << 01;
8006FB80	jal    $80029cc0
A0 = A0 + 00b9;

L6fb88:	; 8006FB88
RA = w[SP + 0028];
SP = SP + 0030;
8006FB90	jr     ra 
8006FB94	nop
////////////////////////////////



////////////////////////////////
// func6fb98()

V1 = w[800ad038];
if( V1 == 1 )
{
    A0 = 0;
    system_cdrom_action_sync();

    A0 = 0;
    system_draw_sync();

    A0 = w[800ad0ec];
    system_memory_mark_removed_alloc();

    [800ad038] = w(0);
}

8006FBD8	jal    func78270 [$80078270]
////////////////////////////////



////////////////////////////////
// func6fbf0
V0 = h[A1 + 0000];
8006FBF4	nop
V0 = V0 << 10;
[A0 + 0000] = w(V0);
V0 = h[A1 + 0002];
8006FC04	nop
V0 = V0 << 10;
[A0 + 0004] = w(V0);
V0 = h[A1 + 0004];
8006FC14	nop
V0 = V0 << 10;
8006FC1C	jr     ra 
[A0 + 0008] = w(V0);
////////////////////////////////



////////////////////////////////
// func6fc24()
S0 = A0;

[SP + 10] = h(0);
[SP + 12] = h(0);
[SP + 14] = h(0);

A0 = SP + 10;
A1 = S0;
system_calculate_rotation_matrix();

[S0 + 14] = w(0);
[S0 + 18] = w(0);
[S0 + 1c] = w(0);
////////////////////////////////



////////////////////////////////
// func6fc6c()

if( w[800c1b60] == 0 )
{
    func281274();
}

A0 = 0;
A1 = 0;
A2 = 140;
A3 = e0;
func715f4();

func35c84(); // reset system buttons

[800acfd8] = h(ffff);

[800af370] = h(0); // current button mask c1
[800af374] = h(0); // current button mask c2
[800c1b68] = h(0); // pressed button mask c1
[800c2dcc] = h(0); // pressed button mask c2
[800c2dd4] = h(0); // repeated button mask c1
[800c2ddc] = h(0); // repeated button mask c2

[800b181a] = h(3); // default animation id
[800b181e] = h(40);
[800b1820] = h(ff);
[800b182a] = b(5);

[800c2f0c] = h(ff);

[800c2f34] = w(0);
[800c2f30] = w(0);
[800b1690] = w(0);
[800b1694] = w(0);
[800b1698] = w(0);
[800b1738] = w(0);
[800b168c] = w(0);
[800b16a5] = b(0);
[800b16a4] = b(0);

// distortion
[800b154c] = h(0);
[800b1554] = w(0);
[800b1558] = w(0);
[800b155c] = w(0);
[800b1560] = w(0);
[800b1564] = w(0);
[800b1568] = w(0);
[800b1584] = h(0);
[800b1586] = h(0);

[800b173c] = w(0);
[800b16a2] = b(0);
[800b1684] = h(0);
[800b1686] = h(0);
[800b1682] = h(0);
[800b16a1] = b(0);
[800b1673] = b(0);
[800b1672] = b(0);
[800b1671] = b(0);
[800b1670] = b(0);
[800b16a0] = b(0);
[800b16a3] = b(0);
[800b16a6] = b(0);
[800ad04c] = w(0);
[800ad024] = w(0);
[800ad068] = w(0);
[800acffc] = w(0);
[800ad070] = w(0);
[800ad06c] = w(0);
[800ad048] = w(0);
[800ad004] = w(0);
[800ad040] = w(0);
[800ad060] = w(0);
[800ad080] = w(0);
[800af538] = w(0);
[800acff0] = w(0);
[800ad028] = w(0);
[800af358] = w(0);
[800af1d8] = w(0);
[800af79c] = b(0);
[800ad0ac] = w(0);
[800ad0a8] = w(0);
[800b17b4] = h(0);
[800b1810] = h(0);
[800b0978] = w(0);
[800b1840] = h(0);
[800ad010] = w(0);
[800ad014] = w(0);

A0 = SP + 20;
A1 = 800af5bc;
S0 = 800b182a;
V0 = 0020;
[800af1e8] = w(V0);
V0 = 0002;
[800af51c] = w(V0);
V0 = 03ff;
[800b1680] = h(V0);
[800ad0f0] = w(4);
[800ad01c] = w(0);
[800acfda] = h(0);
[800b1812] = h(0);
[800b1818] = h(0);
[800b1816] = h(0);
[800b181c] = h(0);
[800b1822] = h(0);
[800b1829] = b(0);
[800acfdc] = b(0);
[800acfdd] = b(0);
[800b182b] = b(0);
[800b1828] = b(0);
[800ad08c] = w(0);
[800b1824] = w(0);
[800ad02c] = h(0);
[800b182c] = b(0);
[800ad05c] = w(0);
[800ad054] = w(0);
[800ad064] = w(0);
[800ad03c] = w(ff);
[SP + 0020] = h(0);
[SP + 0022] = h(0);
[SP + 0024] = h(0);
system_calculate_rotation_matrix();

8006FFD4	addiu  v0, zero, $ffff (=-$1)
A1 = 0002;
8006FFDC	addiu  s0, s0, $ff90 (=-$70)

loop6ffe0:	; 8006FFE0
[S0 + 0000] = h(V0);
8006FFE4	addiu  a1, a1, $ffff (=-$1)
8006FFE8	bgez   a1, loop6ffe0 [$8006ffe0]
8006FFEC	addiu  s0, s0, $fffe (=-$2)
A3 = 001d;
A1 = 000f;
8006FFF8	lui    v1, $800b
V1 = V1 + 16a8;
A2 = V1 + 00ba;
A0 = 1000;
V0 = 0001;
[800ad0e0] = h(V0);
V0 = 0720;
[800aee0e] = h(A0);
[V1 + 0000] = h(V0);
V0 = 0100;
[800b1678] = h(V0);
[800b1676] = h(V0);
[800b1674] = h(V0);
V0 = 0200;
[800b167e] = h(V0);
[800b167c] = h(V0);
[800b167a] = h(V0);
V0 = 0080;
[800b1688] = h(V0);
V0 = 00ff;
[800ad09c] = w(V0);
80070074	addiu  v0, zero, $ffff (=-$1)
[800b1660] = h(A0);
[800b1658] = h(0);
[800b165a] = h(0);
[800b165c] = h(0);
[800ad044] = w(V0);

loop700a0:	; 800700A0
[A2 + 0000] = h(A3);
800700A4	addiu  a1, a1, $ffff (=-$1)
800700A8	bgez   a1, loop700a0 [$800700a0]
800700AC	addiu  a2, a2, $fffe (=-$2)
V1 = w[8004e9b0];
V0 = 001d;
[800b1764] = h(V0);
800700C4	addiu  v0, zero, $ffff (=-$1)
[800ad0c4] = w(V0);
V0 = 0002;
[800b16ac] = w(V0);
V0 = ffff;
[800b164e] = h(V0);
V0 = 0080;
[800b1666] = b(V0);
[800b1665] = b(V0);
[800b1664] = b(V0);
V0 = 00ff;
[800b166a] = b(V0);
[800b1669] = b(V0);
[800b1668] = b(V0);
V0 = 15e0;
[800b166c] = h(V0);
V0 = 300c;
[800b166e] = h(V0);
V0 = 0008;
[800acfe0] = w(0);
[800ad0e4] = w(0);
[800af37c] = h(0);
[800b1740] = w(0);
[800b164c] = h(0);
[800b1648] = h(0);
[800b164a] = h(0);
[800b1654] = w(0);
[800b1650] = w(0);
[800b1662] = h(0);
[800b16aa] = h(V0);
80070194	bne    v1, zero, L701cc [$800701cc]
A1 = 0;
A0 = 8006f020;
V1 = 80059ad4;

loop701b0:	; 800701B0
    [V1 + 0000] = w(ff);
    [A0 + 0000] = w(ff);
    A0 = A0 + 0004;
    V1 = V1 + 0004;
    A1 = A1 + 0001;
    V0 = A1 < 0003;
800701C4	bne    v0, zero, loop701b0 [$800701b0]


L701cc:	; 800701CC
V1 = ffff;
A1 = 001f;
V0 = 800b17b2;

loop701dc:	; 800701DC
[V0 + 0000] = h(V1);
800701E0	addiu  a1, a1, $ffff (=-$1)
800701E4	bgez   a1, loop701dc [$800701dc]
800701E8	addiu  v0, v0, $fffe (=-$2)
A1 = 0;
800701F0	lui    v0, $800c
V0 = V0 + 2f3c;
A2 = V0 + 0400;
V1 = V0;
A0 = w[80059a38];
V0 = 0002;
[800b1770] = w(0);
[800b176c] = w(0);
[8004f7a4] = w(V0);

loop70224:	; 80070224
V0 = hu[A0 + 1930];
A0 = A0 + 0002;
A1 = A1 + 0001;
[V1 + 0000] = h(V0);
[A2 + 0000] = h(0);
A2 = A2 + 0002;
V0 = A1 < 0200;
80070240	bne    v0, zero, loop70224 [$80070224]
V1 = V1 + 0002;
A0 = 200;
system_gte_set_projection_plane_distance();

S0 = 800aee64;
80070258	jal    func6fc24 [$8006fc24]
A0 = S0;
A0 = 800aed30;
80070268	jal    func6fc24 [$8006fc24]
S1 = S0 + 00d4;
80070270	jal    func6fc24 [$8006fc24]
A0 = S1;
80070278	jal    func6fc24 [$8006fc24]
A0 = S0 + 0114;
A0 = S0 + 00c4;
V0 = 3000;
[S0 + 00c4] = h(0);
[800aef2a] = h(0);
[800aef2c] = h(0);
[800aef30] = h(0);
[800aef32] = h(0);
[800aef34] = h(0);
[800aef98] = w(V0);
A1 = S1;
system_calculate_rotation_matrix();

[800c3740] = w(800b1970);

func71bdc(); // init camera

func70314();

func85ac8();

field_particle_clear_arrays();

funcab1f0();
////////////////////////////////



////////////////////////////////
// func70314()

for( int i = 0; i < 3; ++i )
{
    [800afb78 + i * 6] = h(00ff);
    [800afb7a + i * 6] = h(00ff);
}
[800acfe4] = w(0);
////////////////////////////////



////////////////////////////////
// func70358()

A1 = 8006f184;
[SP + 38] = w(w[A1 + 0]);
[SP + 3c] = w(w[A1 + 4]);
[SP + 40] = w(w[A1 + 8]);
[SP + 44] = w(w[A1 + c]);

func6fc6c(); // init values

// copy first 0x100 byte of field file
A2 = w[80059b70]; // field file
A3 = 800b144c;
T0 = A2 + 100;
loop703cc:	; 800703CC
    [A3 + 0] = w(w[A2 + 0]);
    [A3 + 4] = w(w[A2 + 4]);
    [A3 + 8] = w(w[A2 + 8]);
    [A3 + c] = w(w[A2 + c]);
    A2 = A2 + 10;
    A3 = A3 + 10;
80070410	bne    a2, t0, loop703cc [$800703cc]

for( int i = 0; i < 4; ++i )
{
    for( int j = 0; j < 4; ++j )
    {
        A0 = 800afb90 + (i * 4 + j) * 70;
        A1 = j;
        A2 = i;
        A3 = 0;
        func79e08();
    }
}

A0 = 800b0290 + 0;
A1 = 4;
A2 = 4;
A3 = 1;
func79e08();

A0 = 800b0290 + 70;
A1 = 5;
A2 = 5;
A3 = 1;
func79e08();

A0 = 800b0290 + e0;
A1 = 6;
A2 = 6;
A3 = 1;
func79e08();

A0 = 800b0290 + 150;
A1 = 7;
A2 = 7;
A3 = 1;
func79e08();

A0 = 800b0290 + 1c0;
A1 = 8;
A2 = 8;
A3 = 1;
func79e08();

func79bd8();

// additional textures extraction (part 0 of field file)
V0 = w[80059b70];
A0 = w[V0 + 10c] + 10;
A1 = 1;
system_memory_allocate();
S2 = V0;

V0 = w[80059b70];
A0 = V0 + w[V0 + 130];
A1 = S2;
system_extract_archive();

S3 = w[S2 + 0];
if( S3 > 0 )
{
    S4 = 0;
    loop7056c:	; 8007056C
        A0 = S2 + w[S2 + 4 + S4 * 4];
        func76888(); // load tim by tim file pointer

        S4 = S4 + 1;
        V0 = S4 < S3;
    80070580	bne    v0, zero, loop7056c [$8007056c]
}

// sprite texture extraction (part 4 of field file)
V0 = w[80059b70];
A0 = w[V0 + 11c] + 10;
A1 = 0;
system_memory_allocate();
S4 = V0;

V0 = w[80059b70];
A0 = V0 + w[V0 + 140];
A1 = S4;
system_extract_archive();

number_of_textures = w[S4];
if( number_of_textures > 0 )
{
    S0 = 0;
    func705e0:	; 800705E0
        if( h[800b144c + S0 * 8 + 6] == 0 )
        {
            A0 = S4 + w[S4 + 4 + S0 * 4]; // texture pack pointer
            A1 = hu[800b144c + S0 * 8 + 0]; // x offset in vram to load to
            A2 = hu[800b144c + S0 * 8 + 2]; // y pos in vram to load to
            func228fc();
        }
        S0 = S0 + 1;
        V0 = S0 < number_of_textures;
    80070620	bne    v0, zero, func705e0 [$800705e0]
}

A0 = 0; // wait for termination
system_draw_sync();

A0 = S2;
system_memory_mark_removed_alloc();

A0 = S4;
system_memory_mark_removed_alloc();

// 3d model extraction (part 2 of field file)
V0 = w[80059b70];
A0 = w[V0 + 114] + 10;
A1 = 0;
system_memory_allocate();
[800aefe8] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 138];
A1 = V0;
system_extract_archive();

S2 = w[800aefe8];
number_of_models = w[S2];
if( number_of_models > 0 )
{
    S4 = 0;
    loop706a8:	; 800706A8
        A0 = S2 + w[S2 + 4 + S4 * 4];
        func2c1f8(); // sets global offsets for model file and return number of parts

        S4 = S4 + 1;
        V0 = S4 < number_of_models;
    800706D4	bne    v0, zero, loop706a8 [$800706a8]
}

A1 = w[80059b70];
A0 = A1 + w[A1 + 148];
A1 = 80064f6c; // where
system_extract_archive();

// script extraction (part 5 of field file)
V0 = w[80059b70];
A0 = w[V0 + 120] + 10;
A1 = 0;
system_memory_allocate();
[800ad0d0] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 144];
A1 = V0;
system_extract_archive();

V0 = w[800ad0d0];
V1 = w[V0 + 80];
[800ad0d4] = w(V1); // number of entities
[800ad0d8] = w(V0 + 84 + V1 * 40); // pointer to script data

// triggers extraction (part 8 of field file)
A0 = w[80059b70];
A0 = w[A0 + 12c] + 10;
A1 = 0;
system_memory_allocate();
[800ad0cc] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 150];
A1 = V0;
system_extract_archive();

// dialogs extraction (part 7 of field file)
V0 = w[80059b70];
A0 = w[V0 + 128] + 10;
A1 = 0;
system_memory_allocate();
[800ad0c8] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 14c];
A1 = V0;
system_extract_archive();

// walkmesh extraction (part 1 of field file)
V0 = w[80059b70];
A0 = w[V0 + 110] + 10;
A1 = 0;
system_memory_allocate();
[800aefec] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 134];
A1 = V0;
system_extract_archive();

V0 = w[800aefec];
[800af028] = h(w[V0]); // block count

S2 = w[800aefec] + 4;

S4 = 0;
loop70860:	; 80070860
    [800af018 + S4 * 4] = w(w[S2] / e); // number of triangles
    S2 = S2 + 4;
    S4 = S4 + 1;
    V0 = S4 < 4;
80070888	bne    v0, zero, loop70860 [$80070860]

[800aeff4] = w(w[800aefec] + w[S2]); // material data
S2 = S2 + 4;

blocks = h[800af028];
if( blocks > 0 )
{
    S4 = 0;
    loop708cc:	; 800708CC
        [800aeff8 + S4 * 4] = w(w[800aefec] + w[S2 + 0]); // block_start
        [800af008 + S4 * 4] = w(w[800aefec] + w[S2 + 4]; // block_vertex
        S2 = S2 + 8;
        S4 = S4 + 1;
        V0 = S4 < blocks;
    80070908	bne    v0, zero, loop708cc [$800708cc]
}

[800af1e4] = w((w[800aeff8] - w[800aeff4]) / 4); // number of materials

// sprite data extraction (part 3 of field file)
V1 = w[80059b70];
A0 = w[V1 + 118] + 10;
A1 = 0;
system_memory_allocate();
[800aeff0] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 13c];
A1 = V0;
system_extract_archive();

[800aeeb0] = h(1);
[800aeeb2] = h(1);
[800aeeb4] = h(1);
[800aeeb6] = h(1);

A0 = w[80059b70] + 154;
func6f47c();

// set up entities
V0 = w[80059b70];
number_of_entities = hu[V0 + 18c];
[800aefe0] = w(number_of_entities);

A0 = number_of_entities * 5c;
A1 = 0;
system_memory_allocate();
[800aefe4] = w(V0);

if( number_of_entities > 0 )
{
    struct_5c = w[800aefe4];

    // init entity struct with zeroes
    S4 = 0;
    loop709f0:	; 800709F0
        [struct_5c + S4] = w(0);
        S4 = S4 + 4;
        V0 = S4 < number_of_entities * 5c;
    800709FC	bne    v0, zero, loop709f0 [$800709f0]

    init_data = w[80059b70] + 190;
    entity_id = 0;
    L70a1c:	; 80070A1C
        [struct_5c + entity_id * 5c + 58] = h(hu[init_data + entity_id * 10 + 0]); // flags
        [struct_5c + entity_id * 5c + 50] = h(hu[init_data + entity_id * 10 + 2]); // x rot
        [struct_5c + entity_id * 5c + 52] = h(hu[init_data + entity_id * 10 + 4]); // y rot
        [struct_5c + entity_id * 5c + 54] = h(hu[init_data + entity_id * 10 + 6]); // z rot
        [struct_5c + entity_id * 5c + 20] = w(hu[init_data + entity_id * 10 + 8]); // x
        [struct_5c + entity_id * 5c + 40] = w(hu[init_data + entity_id * 10 + 8]); // x
        [struct_5c + entity_id * 5c + 24] = w(hu[init_data + entity_id * 10 + a]); // y
        [struct_5c + entity_id * 5c + 44] = w(hu[init_data + entity_id * 10 + a]); // y
        [struct_5c + entity_id * 5c + 28] = w(hu[init_data + entity_id * 10 + c]); // z
        [struct_5c + entity_id * 5c + 48] = w(hu[init_data + entity_id * 10 + c]); // z

        if( ( hu[struct_5c + entity_id * 5c + 58] & 0040 ) == 0 )
        {
            A0 = 24;
            A1 = 0;
            system_memory_allocate();
            S0 = V0;

            [struct_5c + entity_id * 5c + 0] = w(S0);

            models = w[800aefe8];
            model_id = hu[init_data + entity_id * 10 + e];
            [S0 + 4] = w(models + w[models + 4 + model_id * 4] + 10);

            A0 = w[S0 + 4];
            A1 = S0 + 8;
            A2 = S0 + c;
            system_allocate_memory_for_packets(); // allocate place for both packets buffers

            A0 = w[S0 + 4]; // data
            A1 = w[S0 + 8]; // memory for packets
            A2 = ( hu[struct_5c + entity_id * 5c + 58] & 000c ) >> 2; // lighting flags
            system_fill_packets_drafts_for_model_part(); // fill 1st buffer

            A0 = w[S0 + c]; // to
            A1 = w[S0 + 8]; // from
            V0 = w[S0 + 4];
            A2 = w[V0 + 34]; // size
            system_memcpy(); // copy from 1st buffer to second

            if( hu[struct_5c + entity_id * 5c + 58] & 2000 )
            {
                A0 = 3; // KAZM
                A1 = 0;
                system_memory_set_alloc_user();

                A0 = w[S0 + 4];
                A1 = 0;
                func301d8(); // init +1c in model data
                [S0 + 14] = w(V0);

                A0 = 8; // YOSI
                A1 = 0;
                system_memory_set_alloc_user();
            }

            A0 = w[S0 + 4];
            func2c454();
        }
        else
        {
            [struct_5c + entity_id * 5c + 50] = h(0);
            [struct_5c + entity_id * 5c + 52] = h(0);
            [struct_5c + entity_id * 5c + 54] = h(0);
            [struct_5c + entity_id * 5c + 58] = h(hu[struct_5c + entity_id * 5c + 58] | 0020);
        }

        A0 = entity_id;
        func80558();

        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entities;
    80070C28	bne    v0, zero, L70a1c [$80070a1c]
}

if( w[800c1b60] == 0 ) // DEBUG
{
    func2812bc(); // create debug lines packets
}

func7d4e0();

func710f4(); // create some packets

A0 = w[80059b70];
system_memory_mark_removable();

A0 = w[80059b70];
system_memory_mark_removed_alloc();

A0 = 5; // MIYA
A1 = 0;
system_memory_set_alloc_user();

A0 = 3c00;
A1 = 0;
func24d5c(); // init for sprites

func1c7d0(); // sprites init all

A0 = 8; // YOSI
A1 = 0;
system_memory_set_alloc_user();

S0 = 800b1710;

A0 = S0;
A1 = 800;
A2 = 0;
A3 = 0;
A4 = 800;
A5 = 0;
A6 = 0;
A7 = 800;
A8 = 0;
A9 = 0;
func76ed4(); // set data in A0

A0 = S0 - 20;
A1 = 1f8;
A2 = fffff03f;
A3 = fffffe08;
A4 = 0;
A5 = 0;
A6 = 0;
A7 = 0;
A8 = 0;
A9 = 0;
func76ed4(); // set data in A0

S2 = 800af558;

[800a1732] = b(1e);
[800a1731] = b(1e);
[800a1730] = b(1e);

[S2] = h(140);

[800af562] = h(0);
[800af57d] = b(0);
[800af57c] = b(0);
[800af57a] = b(0);
[800af579] = b(0);
[800af578] = b(0);
[800af576] = b(0);
[800af575] = b(0);

[S2 + 1c] = b(0);
[S2 + c] = w(0);

[800af56c] = w(1000);

[800af584] = h(0);
[800af582] = h(0);
[800af580] = h(0);

[800af560] = h(0);
[800af55e] = h(0);
[800af55c] = h(0);
[800af55a] = h(0);
[800af556] = h(0);
[800af554] = h(0);

[800af586] = h(0);
[800af568] = w(0);
[800af57e] = b(20);

[800afcff4] = w(0);
S1 = S2 + c;

funca1e64(); // we run script from here

[800acff4] = w(1);

A0 = S0 - b8;
A1 = 800af104;
system_calculate_rotation_matrix();

[800af120] = w(0);
[800af11c] = w(0);
[800af118] = w(0);

S0 = S2 + 1c;

if( h[800af586] != 0 )
{
    A0 = h[800af554];
    A1 = h[800af556];
    A2 = h[S2];
    A3 = h[800af55a];
    A4 = h[800af55c];
    A5 = h[800af55e];
    A6 = h[800af560];
    A7 = h[800af562];
    A8 = S1;
    A9 = S0;
    A10 = h[800af580];
    A11 = h[800af582];
    A12 = h[800af584];

    80070EB8	jal    func26eac [$80026eac]

    [800af550] = w(V0);
}

A0 = 8; // YOSI
A1 = 0;
system_memory_set_alloc_user();

V1 = hu[800b1812];

V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;

V1 = w[800aefe4];

V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 0020];

A1 = 800aed94;

V1 = V1 << 10;
[A1 + 0000] = w(V1);
V1 = w[V0 + 0024];
80070F18	nop
V1 = V1 << 10;

[800aed98] = w(V1);

V0 = w[V0 + 0028];

V1 = w[800aefe0];

V0 = V0 << 10;

[800aed9c] = w(V0);

if( V1 > 0 )
{
    S4 = 0;
    S1 = A1 + 250;
    S0 = 0;

    loop70f50:	; 80070F50
        A1 = S0 + w[S1];

        A0 = A1 + 50;
        A1 = A1 + c;
        system_calculate_rotation_matrix();

        V0 = S0 + w[800aefe4];

        S4 = S4 + 1;

        V1 = w[V0 + c];
        A0 = w[V0 + 10];
        A1 = w[V0 + 14];
        A2 = w[V0 + 18];

        [V0 + 2c] = w(V1);
        [V0 + 30] = w(A0);
        [V0 + 34] = w(A1);
        [V0 + 38] = w(A2);

        V1 = w[V0 + 1c];
        A0 = w[V0 + 20];
        A1 = w[V0 + 24];
        A2 = w[V0 + 28];

        [V0 + 3c] = w(V1);
        [V0 + 40] = w(A0);
        [V0 + 44] = w(A1);
        [V0 + 48] = w(A2);

        S0 = S0 + 5c;
        V0 = S4 < w[S1 - 4];
    80070FC4	bne    v0, zero, loop70f50 [$80070f50]
}

80070FCC	jal    func772f0 [$800772f0]

funca1ca4();

[8004e9d8] = w(-1);
[8004e9d4] = w(-1);

func734c8();

80070FF8	jal    func768f8 [$800768f8]

if( h[800af586] == 0 )
{
    80071014	jal    func73d2c [$80073d2c]

    [800ad024] = w(V0);
}
else
{
    [800ad024] = w(1);
}

if( w[800ad0d4] > 0 )
{
    S4 = 0;
    S0 = 0;

    loop7103c:	; 8007103C
        A0 = w[800aefe4] + S0;

        if( hu[A0 + 58] & 0040 )
        {
            A2 = w[A0 + 4c];
            if( (w[A2 + 4] & 01000000) == 0 )
            {
                A0 = w[A0 + 4];
                A1 = ((hu[800aee62] + hu[A2 + 108]) << 10) >> 10;
                80071094	jal    func22218 [$80022218]
            }
            else
            {
                A0 = w[A0 + 4];
                A1 = h[A2 + 108];
                800710AC	jal    func21e40 [$80021e40]
            }
        }

        S4 = S4 + 1;
        S0 = S0 + 5c;
        V0 = S4 < w[800ad0d4];
    800710C4	bne    v0, zero, loop7103c [$8007103c]
}
////////////////////////////////



////////////////////////////////
// func710f4()

A0 = 0;
func7cf50();

A0 = 1;
func7cf50();
////////////////////////////////



////////////////////////////////
// func7111c
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 02;
V0 = V0 - A0;
A0 = V0 << 03;
80071130	lui    at, $800b
AT = AT + A0;
V0 = h[AT + 15ea];
8007113C	nop
80071140	beq    v0, zero, L7133c [$8007133c]
80071144	nop
80071148	lui    at, $800b
AT = AT + A0;
V0 = h[AT + 15ec];
80071154	nop
80071158	bgtz   v0, L711d8 [$800711d8]
V0 = 0001;
V1 = h[800ad0e0];
80071168	lui    at, $800b
AT = AT + A0;
[AT + 15ec] = h(0);
80071174	beq    v1, v0, L7133c [$8007133c]
80071178	nop
8007117C	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d0];
80071188	nop
8007118C	bne    v0, zero, L7133c [$8007133c]
80071190	nop
80071194	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d4];
800711A0	nop
800711A4	bne    v0, zero, L7133c [$8007133c]
800711A8	nop
800711AC	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d8];
800711B8	nop
800711BC	bne    v0, zero, L7133c [$8007133c]
800711C0	nop
800711C4	lui    at, $800b
AT = AT + A0;
[AT + 15ea] = h(0);
800711D0	j      L7133c [$8007133c]
800711D4	nop

L711d8:	; 800711D8
800711D8	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d0];
800711E4	lui    at, $800b
AT = AT + A0;
V1 = w[AT + 15dc];
800711F0	nop
V0 = V0 + V1;
800711F8	lui    at, $800b
AT = AT + A0;
[AT + 15d0] = w(V0);
V0 = V0 >> 08;
V0 = V0 < 0100;
8007120C	bne    v0, zero, L71220 [$80071220]
V0 = ff00;
80071214	lui    at, $800b
AT = AT + A0;
[AT + 15d0] = w(V0);

L71220:	; 80071220
80071220	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d0];
8007122C	nop
80071230	bgez   v0, L71244 [$80071244]
80071234	nop
80071238	lui    at, $800b
AT = AT + A0;
[AT + 15d0] = w(0);

L71244:	; 80071244
80071244	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d4];
80071250	lui    at, $800b
AT = AT + A0;
V1 = w[AT + 15e0];
8007125C	nop
V0 = V0 + V1;
80071264	lui    at, $800b
AT = AT + A0;
[AT + 15d4] = w(V0);
V0 = V0 >> 08;
V0 = V0 < 0100;
80071278	bne    v0, zero, L7128c [$8007128c]
V0 = ff00;
80071280	lui    at, $800b
AT = AT + A0;
[AT + 15d4] = w(V0);

L7128c:	; 8007128C
8007128C	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d4];
80071298	nop
8007129C	bgez   v0, L712b0 [$800712b0]
800712A0	nop
800712A4	lui    at, $800b
AT = AT + A0;
[AT + 15d4] = w(0);

L712b0:	; 800712B0
800712B0	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d8];
800712BC	lui    at, $800b
AT = AT + A0;
V1 = w[AT + 15e4];
800712C8	nop
V0 = V0 + V1;
800712D0	lui    at, $800b
AT = AT + A0;
[AT + 15d8] = w(V0);
V0 = V0 >> 08;
V0 = V0 < 0100;
800712E4	bne    v0, zero, L712f8 [$800712f8]
V0 = ff00;
800712EC	lui    at, $800b
AT = AT + A0;
[AT + 15d8] = w(V0);

L712f8:	; 800712F8
800712F8	lui    at, $800b
AT = AT + A0;
V0 = w[AT + 15d8];
80071304	nop
80071308	bgez   v0, L7131c [$8007131c]
8007130C	nop
80071310	lui    at, $800b
AT = AT + A0;
[AT + 15d8] = w(0);

L7131c:	; 8007131C
8007131C	lui    at, $800b
AT = AT + A0;
V0 = hu[AT + 15ec];
80071328	nop
8007132C	addiu  v0, v0, $ffff (=-$1)
80071330	lui    at, $800b
AT = AT + A0;
[AT + 15ec] = h(V0);

L7133c:	; 8007133C
8007133C	jr     ra 
80071340	nop
////////////////////////////////



////////////////////////////////
// func71344
80071344	addiu  sp, sp, $ffe8 (=-$18)
[SP + 0010] = w(S0);
S0 = A0;
V1 = w[800ad0dc];
V0 = 0002;
8007135C	bne    v1, v0, L71374 [$80071374]
[SP + 0014] = w(RA);
80071364	jal    func7111c [$8007111c]
A0 = 0;
8007136C	jal    func7111c [$8007111c]
A0 = 0001;

L71374:	; 80071374
A1 = w[800acfe0];
8007137C	jal    func7d058 [$8007d058]
A0 = S0;
RA = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0018;
80071390	jr     ra 
80071394	nop
////////////////////////////////



////////////////////////////////
// func71398()

[800b15ec + A0 * 58] = h(A1);
[800b15ea + A0 * 58] = h(1);
[800b15e8 + A0 * 58] = h(A5);
[800b15dc + A0 * 58] = w(((A2 << 8) - w[800b15d0 + id * 58]) / A1);
[800b15e0 + A0 * 58] = w(((A3 << 8) - w[800b15d4 + id * 58]) / A1);
[800b15e4 + A0 * 58] = w(((A4 << 8) - w[800b15d8 + id * 58]) / A1);
////////////////////////////////



////////////////////////////////
// func7145c
V1 = h[800ad0e0];
V0 = 0001;
80071468	beq    v1, v0, L714e0 [$800714e0]
A1 = 0001;
V1 = w[800ad0dc];
V0 = 0002;
[800ad0e0] = h(A1);
80071484	bne    v1, v0, L714e0 [$800714e0]
V1 = ff00;
8007148C	div    v1, a0
80071490	mflo   v1
V0 = 0002;
[800b15d8] = w(0);
[800b15d4] = w(0);
[800b15d0] = w(0);
[800b15ec] = h(A0);
[800b15ea] = h(A1);
[800b15e8] = h(V0);
[800b15e4] = w(V1);
[800b15e0] = w(V1);
[800b15dc] = w(V1);

L714e0:	; 800714E0
800714E0	jr     ra 
800714E4	nop
////////////////////////////////



////////////////////////////////
// func714e8
V0 = h[800ad0e0];
800714F0	nop
800714F4	beq    v0, zero, L71570 [$80071570]
V0 = 0002;
V1 = w[800ad0dc];
[800ad0e0] = h(0);
8007150C	bne    v1, v0, L71570 [$80071570]
80071510	lui    v1, $ffff
80071514	div    v1, a0
80071518	mflo   v1
V0 = ff00;
[800b15d8] = w(V0);
[800b15d4] = w(V0);
[800b15d0] = w(V0);
V0 = 0001;
[800b15ea] = h(V0);
V0 = 0002;
[800b15ec] = h(A0);
[800b15e8] = h(V0);
[800b15e4] = w(V1);
[800b15e0] = w(V1);
[800b15dc] = w(V1);

L71570:	; 80071570
80071570	jr     ra 
80071574	nop
////////////////////////////////



////////////////////////////////
// field_init_controllers_and_mouse()

A0 = 80061c8c; // system buffer for controller 1
A1 = A0 + 22; // system buffer for controller 2
field_set_controllers_system_buttons_buffer();

A0 = 3; // horizontal
A1 = 4; // vertical
field_set_mouse_speed();

A0 = 0;
A1 = 140;
A2 = 0;
A3 = e0;
field_set_mouse_area();

A0 = 0; // controller
A1 = 50;
A2 = 64;
field_set_mouse_position();

A0 = 1; // controller
A1 = fa;
A2 = 64;
field_set_mouse_position();

A0 = 0;
A1 = 12c;
A2 = a;
A3 = dc;
field_set_mouse_area();
////////////////////////////////



////////////////////////////////
// func715f4()

[800b1970] = h(A0);
[800b1972] = h(A1);
[800b1974] = h(A2);
[800b1976] = h(A3);

[800b9a64] = h(A0);
[800b9a66] = h(A1 + 100);
[800b9a68] = h(A2);
[800b9a6a] = h(A3);
////////////////////////////////



////////////////////////////////
// func71640()

[80058838] = w(1);

A0 = 0;
system_draw_sync();

A0 = 0;
system_psyq_wait_frames();

system_gte_init();

A0 = 00a0;
A1 = 0070;
system_gte_set_screen_offset();

A0 = 800b1970;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = e0;
system_graphic_create_draw_env_struct();

S2 = 800b9a64;
A0 = S2;
A1 = 0;
A2 = 100;
A3 = 140;
A4 = e0;
system_graphic_create_draw_env_struct();

A0 = 800b1970 + 5c;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = e0;
system_graphic_create_draw_env_struct();

A0 = 800b9ac0;
A1 = 0;
A2 = 100;
A3 = 140;
A4 = e0;
system_graphic_create_draw_env_struct();

A0 = 800b1970 + b8;
A1 = 0;
A2 = 100;
A3 = 140;
A4 = e0;
system_graphic_create_display_env_struct();

A0 = 800b9b1c;
A1 = 0;
A2 = 0;
A3 = 140;
A4 = e0;
system_graphic_create_display_env_struct();

A0 = 0;
A1 = 0;
A2 = 140;
A3 = e0;
func715f4();

func86360();

[800b1989] = b(0);
[800b198a] = b(0);
[800b198b] = b(0);
[800b9a7d] = b(0);
[800b9a7e] = b(0);
[800b9a7f] = b(0);
[800b1986] = b(1);
[800b9a7a] = b(1);

A0 = 0;
system_psyq_wait_frames();

A0 = 800b9b1c;
system_psyq_put_disp_env();

A0 = S2;
system_psyq_put_draw_env();

A0 = 140;
A1 = f0;
func2de00();
////////////////////////////////



////////////////////////////////
// func717d0
[A0 + 001c] = w(0);
[A0 + 0018] = w(0);
800717D8	jr     ra 
[A0 + 0014] = w(0);
////////////////////////////////



////////////////////////////////
// func717e0
800717E0	addiu  sp, sp, $ff80 (=-$80)
[SP + 006c] = w(S1);
S1 = 800aeea4;
A0 = S1;
[SP + 0068] = w(S0);
800717F8	addiu  s0, s1, $ffe0 (=-$20)
A1 = S0;
[SP + 0078] = w(RA);
[SP + 0074] = w(S3);
[SP + 0070] = w(S2);
system_calculate_rotation_matrix();

80071810	jal    func717d0 [$800717d0]
A0 = S0;
A0 = S0;
8007181C	addiu  s2, s1, $ffc0 (=-$40)
A1 = S2;
S0 = SP + 0040;
80071828	jal    $800491c4
A2 = S0;
A0 = S2;
80071834	jal    func736c8 [$800736c8]
A1 = S0;
S3 = S1 + 0084;
A0 = S3;
S0 = S1 + 00d4;
A1 = S0;
system_calculate_rotation_matrix();

80071850	jal    func717d0 [$800717d0]
A0 = S0;
A0 = S3;
S0 = S1 + 0094;
A1 = S0;
system_calculate_rotation_matrix();

A0 = S2;
8007186C	jal    $80049a84
A1 = S0;
80071874	jal    $80049da4
A0 = S2;
8007187C	jal    $80049e34
A0 = S2;
A0 = S1 + 008c;
A1 = S1 + 00a8;
8007188C	jal    $8004a584
A2 = SP + 0060;
A0 = S0;
V0 = w[800aef98];
A1 = SP + 0010;
[SP + 0010] = w(V0);
[SP + 0014] = w(V0);
800718AC	jal    $80049c74
[SP + 0018] = w(V0);
800718B4	jal    $80049da4
A0 = S0;
800718BC	jal    $80049e34
A0 = S0;
RA = w[SP + 0078];
S3 = w[SP + 0074];
S2 = w[SP + 0070];
S1 = w[SP + 006c];
S0 = w[SP + 0068];
SP = SP + 0080;
800718DC	jr     ra 
800718E0	nop
////////////////////////////////



////////////////////////////////
// func718e4()

entity_id = A0;

V1 = w[800aefe4];
V0 = w[V1 + entity_id * 5c + 4c];
[SP + 10] = w(h[V0 + f4]); // speed x
[SP + 14] = w(h[V0 + f6]); // speed y
[SP + 18] = w(h[V0 + f8]); // speed z

A1 = w[800aefe4];
A0 = A1 + entity_id * 5c + 50; // x rotation
A1 = A1 + entity_id * 5c + c; // place for matrix
system_calculate_rotation_matrix();

A0 = w[800aefe4] + entity_id * 5c + c; // matrix
A1 = SP + 10; // speed vector
system_gte_multiply_matrix_by_vector();
////////////////////////////////



////////////////////////////////
// func71984

8007198C	jal    func717e0 [$800717e0]

S0 = 800aef38;
8007199C	jal    $80049da4
A0 = S0;
800719A4	jal    $80049e34
A0 = S0;
V0 = w[800c1b60];
if( V0 == 0 )
{
    func2815c8(); // update debug line packets
}
////////////////////////////////



////////////////////////////////
// func719dc()
disable = A0;
rot = A1;

A2 = 0;
loop719e4:	; 800719E4
    if( ( bu[800ad0f4 + (rot & 7)] & disable ) == 0 )
    {
        return A2;
    }

    rot = rot + 1;
    A2 = A2 + 1;
    V0 = V1 < 8;
80071A14	bne    v0, zero, loop719e4 [$800719e4]

return 0;
////////////////////////////////



////////////////////////////////
// func71a28()
disable = A0;
rot = A1;

A2 = 0;
loop71a30:	; 80071A30
    if( ( bu[800ad0f4 + (rot & 7)] & disable ) == 0 )
    {
        return A2;
    }

    rot = rot - 1;
    A2 = A2 + 1;
    V0 = V1 < 8;
80071A60	bne    v0, zero, loop71a30 [$80071a30]

return 0;
////////////////////////////////



////////////////////////////////
// func71a74()
intersect_line = A0;
change_line = A1;
ret_addr = A2;

[SP + 30] = w(h[intersect_line + 4] - h[intersect_line + 0]);
[SP + 34] = w(0);
[SP + 38] = w(h[intersect_line + 6] - h[intersect_line + 2]);
A0 = SP + 30;
A1 = SP + 10;
system_gte_normalize_word_vector_T0_T1_T2_to_word();

[SP + 30] = w(h[change_line + 4] - h[change_line + 0]);
[SP + 34] = w(0);
[SP + 38] = w(h[change_line + 6] - h[change_line + 2]);
A0 = SP + 30;
A1 = SP + 20;
system_gte_normalize_word_vector_T0_T1_T2_to_word();

A0 = ( ( w[SP + 20] * w[SP + 18] ) - ( w[SP + 28] * w[SP + 10] ) ) >> c;

if( A0 == 0 )
{
    A0 = 0;
}
else
{
    A0 = (((h[change_line + 2] - h[intersect_line + 2]) * w[SP + 10]) - ((h[change_line + 0] - h[intersect_line + 0]) * w[SP + 18])) / A0;
}

[ret_addr + 0] = h(hu[change_line + 0] + ((A0 * w[SP + 20]) >> c));
[ret_addr + 2] = h(hu[change_line + 2] + ((A0 * w[SP + 28]) >> c));
////////////////////////////////



////////////////////////////////
// func71bdc()
// init camera

[800aee58] = w(8);
[800aee5c] = w(8);
[800aee60] = h(0);
[800aee62] = h(0);
[800aeea4] = h(0);
[800aeea6] = h(0);
[800aeea8] = h(0);
[800aeeac] = w(00000000);

// initial cam rotation
[800aeeb8] = h(0);
[800aeeba] = h(0800);
[800aeebc] = h(0);

// set up default rotation on start
[800aeec0] = w(00400000);
[800aeec4] = w(08000000);
[800aeec8] = b(0);
[800aeec9] = b(0);
[800aeeca] = h(0);
[800aeee0] = w(00000800);

// shake not working
[800aeefc] = h(0);
[800aef00] = h(0);
[800aef04] = w(0);
[800aef08] = w(0);
[800aef0c] = w(0);
[800aef10] = w(0);
[800aef14] = w(0);
[800aef18] = w(0);

A0 = 800aee84;
func6fc24(); // nullify rot translation matrix

[800aed54] = w(0);
[800aed58] = w(0);
[800aed5c] = w(0);
[800aed64] = w(0);
[800aed68] = w(0);
[800aed6c] = w(0);
[800aed74] = w(0);
[800aed78] = w(10000000);
[800aed7c] = w(0);
[800aed84] = w(0);
[800aed88] = w(0);
[800aed8c] = w(0);
[800aed94] = w(0);
[800aed98] = w(0);
[800aed9c] = w(0);
[800aeda4] = w(0);
[800aeda8] = w(10000000);
[800aedac] = w(0);
[800aedb4] = w(0);
[800aedb8] = w(0);
[800aedbc] = w(0);

[800aee08] = h(0);
[800aee10] = h(0);
[800aee12] = h(0);
[800aee34] = h(0);
[800aeecc] = w(200);
[800aeed0] = h(1e);
[800aeed2] = h(1000);
[800aeed4] = h(0);
[800aeee4] = h(0);
[800aeef0] = h(0);
////////////////////////////////



////////////////////////////////
// func71d78()

// ??? and not all camera direction locked
if( ( ( bu[800aeec8] & ff ) != ff ) && ( bu[800aeec9] != ff ) )
{
    if( h[800aeeca] == 0 )
    {
        V0 = (hu[800aeeba] & fff) >> 9;
        if( bu[800ad0f4 + V0] & bu[800aeec8] )
        {
            if( ( w[800aeec0] != ffc00000 ) && ( w[800aeec0] != 00400000 ) )
            {
                [800aeec0] = w(00400000);
                [800aeee0] = w(w[800aeee0] + 200);
            }
            [800aeeca] = h(8);
        }

        // if current cam direction disallowed
        A1 = (hu[800aeeba] & fff) >> 9;
        if( bu[800ad0f4 + A1] & bu[800aeec9] )
        {
            A0 = bu[800aeec9];
            A1 = (hu[800aeeba] & fff) >> 9;
            func719dc();
            S0 = V0;

            A0 = bu[800aeec9];
            A1 = (hu[800aeeba] & fff) >> 9;
            func71a28();

            if( V0 < S0 ) // closest allowed rotation
            {
                [800aeec0] = w(ffc00000);
                [800aeee0] = w(w[800aeee0] - 200);
                [800aeeca] = h(8);
            }
            else
            {
                [800aeec0] = w(00400000);
                [800aeee0] = w(w[800aeee0] + 200);
                [800aeeca] = h(8);
            }
        }
    }

    // L1 currently pressed and ???
    if( ( hu[800af370] & 0004 ) && ( ( w[800aeeac] & 80000000 ) == 0 ) && ( h[800aeeca] == 0 ) )
    {
        V0 = ((h[800aeeba] - 200) & fff) >> 9;
        if( ( bu[800ad0f4 + V0] & bu[800aeec9] ) == 0 )
        {
            [800aeec0] = w(ffc00000);
            [800aeeca] = h(8);
            [800aeee0] = w(w[800aeee0] - 200);
        }
    }

    // R1 currently pressed and ???
    if( ( hu[800af370] & 0008 ) && ( ( w[800aeeac] & 00008000 ) == 0 ) && ( h[800aeeca] == 0 ) )
    {
        V0 = ((h[800aeeba] + 200) & fff) >> 9;
        if( ( bu[800ad0f4 + V0] & bu[800aeec9] ) == 0 )
        {
            [800aeec0] = w(00400000);
            [800aeeca] = h(8);
            [800aeee0] = w(w[800aeee0] + 200);
        }
    }
}

// perform one rotation step
if( h[800aeeca] != 0 )
{
    [800aeec4] = w(w[800aeec4] + w[800aeec0]);
    [800aeeba] = h(w[800aeec4] >> 10);
    [800aeeca] = h(hu[800aeeca] - 1);
}

if( hu[800aeeca] == 0 )
{
    [800aeeba] = h(w[800aeee0]);
}

if( w[800c1b60] == 0 )
{
    func284ef8();
}
////////////////////////////////



////////////////////////////////
// func720c8()
S0 = A0; // vector with +20 current position
S2 = A1; // current y pos [][]

[SP + 38] = w(w[S0 + 0]); // current x
[SP + 3c] = w(0);
[SP + 40] = w(w[S0 + 8]); // current z

A0 = SP + 38; // current x z and y = 0
A1 = SP + 10; // intersect line
A2 = SP + 28; // ret position curr and fin ( x z x z )
func7c394();

if( V0 == -1 ) // we found triangle
{
    // copy intersect line in format x z x z
    [SP + 20] = h(hu[SP + 10]);
    [SP + 22] = h(hu[SP + 14]);
    [SP + 24] = h(hu[SP + 18]);
    [SP + 26] = h(hu[SP + 1c]);

    A0 = SP + 20; // intersect line
    A1 = SP + 28; // change in pos if we outside bound
    A2 = SP + 30; // ret new pos
    func71a74();

    [800aed94] = w(h[SP + 30] << 10);
    [800aed9c] = w(h[SP + 32] << 10);

    if( bu[800b16a1] == 0 )
    {
        if( w[800ad080] == 0 )
        {
            [800aed98] = w(S2 << 10);
            [800ad080] = w(1);
        }
    }
    else
    {
        [800aed98] = w(ffe00000 + w[S0 + 4]);
    }
}
else
{
    // if we don't found triangle - use data from entity
    [800aed94] = w(w[S0 + 0]); // x
    [800aed98] = w(ffe00000 + w[S0 + 4]); // y
    [800aed9c] = w(w[S0 + 8]); // z

    [800ad080] = w(0);
}



[800aed84] = w(w[800aed94]);

A0 = ((h[800aeed0] * 3b) / 8) + c00;
system_cos();
[800aed88] = w(w[800aed98] + ((((0 - ((V0 * w[800aeecc]) << 5)) >> 10) * h[800aeed2]) << 4));

A0 = ((h[800aeed0] * 3b) / 8) + c00;
system_sin();
[800aed8c] = w(w[800aed9c] + (((((V0 * w[800aeecc]) << 5) >> 10) * h[800aeed2]) << 4));



A0 = 800aed84;
A1 = 800aed94;
func72d14(); // calculate cam pos with rotation (maybe look at point)



if( w[800aeeac] & 00000001 )
{
    if( h[800aeef0] != 0 )
    {
        [800aeef4] = w(w[800aeef4] + w[800aeef8]);
        [800aeed2] = h(w[800aeef4] >> 10);
    }

    [800aeef0] = h(h[800aeef0] - 1);
    if( h[800aeef0] == 0 )
    {
        [800aeeac] = w(w[800aeeac] & 0000fffe);
    }
}



if( w[800aeeac] & 00000008 )
{
    [800aeed8] = w(w[800aeed8] + w[800aeedc]);
    [800aeed0] = h(w[800aeed8] >> 10);

    [800aeed4] = h(hu[800aeed4]) - 1;
    if( hu[800aeed4] == 0 )
    {
        [800aeeac] = w(w[800aeeac] & 0000fff7)
    }
}
////////////////////////////////



////////////////////////////////
// func72404()
if( w[800aeeac] & 00000010 )
{
    if( h[800aeee4] != 0 )
    {
        [800aeee8] = w(w[800aeee8] + w[800aeeec]);
        [800aeecc] = w(w[800aeee8] >> 10);
    }
    [800aeee4] = h(h[800aeee4] - 1);
    if( h[800aeee4] < 0 )
    {
        [800aeeac] = w(w[800aeeac] & 0000ffef);
        [800aeee4] = h(0);
    }
}

if( w[800b16ac] != 0 )
{
    [800aee58] = w(1);
    [800aee5c] = w(1);
    [800b16ac] = w(w[800b16ac] - 1);
}

if( ( w[800aed54] >> 10 ) != ( w[800aed84] >> 10 ) )
{
    V1 = w[800aed84] - w[800aed54];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee5c] * w[800aee5c] ) )
    {
        [800aed54] = w(w[800aed54] + (V1 / w[800aee5c]));
    }
}

if( ( w[800aed58] >> 10 ) != ( w[800aed88] >> 10 ) )
{
    V1 = w[800aed88] - w[800aed58];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee5c] * w[800aee5c] ) )
    {
        [800aed58] = w(w[800aed58] + (V1 / w[800aee5c]));
    }
}

if( ( w[800aed5c] >> 10 ) != ( w[800aed8c] >> 10 ) )
{
    V1 = w[800aed8c] - w[800aed5c];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee5c] * w[800aee5c] ) )
    {
        [800aed5c] = w(w[800aed5c] + (V1 / w[800aee5c]));
    }
}

if( ( w[800aed64] >> 10 ) != ( w[800aed94] >> 10 ) )
{
    V1 = w[800aed94] - w[800aed64];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee58] * w[800aee58] ) )
    {
        [800aed64] = w(w[800aed64] + (V1 / w[800aee58]));
    }
}

if( ( w[800aed68] >> 10 ) != ( w[800aed98] >> 10 ) )
{
    V1 = w[800aed98] - w[800aed68];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee58] * w[800aee58] ) )
    {
        [800aed68] = w(w[800aed68] + (V1 / w[800aee58]))
    }
}

if( ( w[800aed6c] >> 10 ) != ( w[800aed9c] >> 10 ) )
{
    V1 = w[800aed9c] - w[800aed6c];
    V0 = V1 >> 10;
    if( ( V0 * V0 ) >= ( w[800aee58] * w[800aee58] ) )
    {
        [800aed6c] = w(w[800aed6c] + (V1 / w[800aee58]));
    }
}

[800aedb4] = w(0);
[800aedb8] = w(0);
[800aedbc] = w(0);

if( h[800aeefc] != 0 )
{
    if( h[800aeefe] != 0 )
    {
        [800aef04] = w(w[800aef04] + w[800aef10]);
        [800aef08] = w(w[800aef08] + w[800aef14]);
        [800aef0c] = w(w[800aef0c] + w[800aef18]);
    }
    else if( h[800aef00] != 0 )
    {
        [800aeefc] = h(0);
        [800aef00] = h(0);
        [800aef04] = w(0);
        [800aef08] = w(0);
        [800aef0c] = w(0);
    }

    system_get_random_2_bytes();
    [800aedb4] = w(h[800aef06] * V0);

    system_get_random_2_bytes();
    [800aedb8] = w(h[800aef0a] * V0);

    system_get_random_2_bytes();
    [800aedbc] = w(h[800aef0e] * V0);

    if( w[800aedb4] < 0 )
    {
        [800aedb4] = w(0);
        [800aed04] = w(0);
    }

    if( w[800aedb8] < 0 )
    {
        [800aedb8] = w(0);
        [800aed08] = w(0);
    }

    if( w[800aedbc] < 0 )
    {
        [800aedbc] = w(0);
        [800aed0c] = w(0);
    }

    if( h[800aeefe] > 0 )
    {
        [800aeefe] = h(h[800aeefe] - 1);
    }
}
////////////////////////////////



////////////////////////////////
// func728c0()
if( h[800aee08] == 0 )
{
    [800ad088] = w(0);

    if( ( w[800ad084] & 3 ) == 0 )
    {
        if( w[800aee58] >= 9 )
        {
            [800aee58] = w(w[800aee58] - 2);
        }
        else
        {
            [800aee58] = w(8);
        }

        if( w[800aee5c] >= 9 )
        {
            [800aee5c] = w(w[800aee5c] - 2);
        }
        else
        {
            [800aee5c] = w(8);
        }
    }

    [800ad084] = w(w[800ad084] + 1);
}
else if( h[800aee08] == 1 )
{
    [800ad084] = w(0);
    [800ad088] = w(0);

    if( hu[800aee10] & 0001 )
    {
        if( h[800aee12] != 0 )
        {
            [800aee14] = w(w[800aee14] + w[800aee24]);
            [800aee18] = w(w[800aee18] + w[800aee28]);
            [800aee1c] = w(w[800aee1c] + w[800aee2c]);
        }

        [800aee12] = h(h[800aee12] - 1);

        if( h[800aee12] == 0 )
        {
            [800aee10] = h(hu[800aee10] & fffe);
        }

        [800aed94] = w(w[800aee14]);
        [800aed98] = w(w[800aee18]);
        [800aed9c] = w(w[800aee1c]);
    }

    if( hu[800aee10] & 0002 )
    {
        if( h[800aee34] != 0 )
        {
            [800aee38] = w(w[800aee38] + w[800aee48]);
            [800aee3c] = w(w[800aee3c] + w[800aee4c]);
            [800aee40] = w(w[800aee40] + w[800aee50]);
        }

        [800aee34] = h(h[800aee34] - 1);

        if( h[800aee34] == 0 )
        {
            [800aee10] = h(hu[800aee10] & fffd);
        }

        [800aed84] = w(w[800aee38]);
        [800aed88] = w(w[800aee3c]);
        [800aed8c] = w(w[800aee40]);
    }
}
else if( h[800aee08] == 2 )
{
    [800ad088] = w(w[800ad088] + 1);
    [800ad084] = w(0);

    if( w[800ad088] >= 41 )
    {
        [800aee08] = h(0);
    }
}



if( ( h[800aee08] == 0 ) || ( h[800aee08] == 2 ) )
{
    func71d78(); // set camera rotation based on buttons and step rotation

    pc_entity_id = hu[800b1812];
    struct_5c_p = w[800aefe4];
    struct_138 = w[struct_5c_p + pc_entity_id * 5c + 4c];

    [SP + 18] = w(w[struct_138 + 20]);
    [SP + 1c] = w(w[struct_138 + 24]);
    [SP + 20] = w(w[struct_138 + 28]);

    A0 = SP + 18;
    A1 = h[struct_138 + 72]; // current y pos
    func720c8();

    if( ( w[800aeeac] & 00004000 ) == 0 )
    {
        A0 = h[800aed86];
        A1 = h[800aed8e];
        A2 = h[800af028] - 1; // camera walkmesh id
        A3 = SP + 38; // ret normal
        A4 = SP + 28; // ret position
        func7a7d8(); // get triangle in which camera resides

        if( h[SP + 3a] < h[800aed8a] )
        {
            [800aed88] = w(h[SP + 3a] << 10);
        }
    }

    if( h[800aee08] == 2 )
    {
        A0 = h[800aed96] - h[800aed66];
        A1 = h[800aed9e] - h[800aed6e];
        length_of_vector_by_x_y();
        S0 = V0;

        A0 = h[800aed86] - h[800aed56];
        A1 = h[800aed8e] - h[800aed5e];
        length_of_vector_by_x_y();

        if( ( S0 & 0080 ) && ( V0 & 0080 ) )
        {
            [800aee08] = h(0);
        }
    }
}



func72404(); // update cam move and shake

[800aeeba] = h(hu[800aeeba] & fff);
////////////////////////////////



////////////////////////////////
// func72d14()
S1 = A0;
cam_pos = A1;

system_gte_push_matrix();

A0 = 800aeeb8; // rot angles vector
A1 = SP + 10;
system_calculate_rotation_matrix();

[SP + 30] = w(w[cam_pos + 0] - w[S1 + 0]);
[SP + 34] = w(w[cam_pos + 4] - w[S1 + 4]);
[SP + 38] = w(w[cam_pos + 8] - w[S1 + 8]);

A0 = SP + 10;
A1 = SP + 30;
A2 = SP + 40;
system_gte_apply_matrix_lv();

[S1 + 0] = w(w[cam_pos + 0] + w[SP + 40]);
[S1 + 8] = w(w[cam_pos + 8] + w[SP + 48]);

system_gte_pop_matrix();
////////////////////////////////



////////////////////////////////
// func72dc4()

[A0 + 0] = w(h[A0 + 2]);
[A0 + 4] = w(h[A0 + 6]);
[A0 + 8] = w(h[A0 + a]);
////////////////////////////////



////////////////////////////////
// func72de0
80072DE0	addiu  sp, sp, $ff90 (=-$70)
[SP + 0068] = w(S4);
S4 = A1;
[SP + 006c] = w(RA);
[SP + 0064] = w(S3);
[SP + 0060] = w(S2);
[SP + 005c] = w(S1);
[SP + 0058] = w(S0);
V0 = w[A2 + 0000];
V1 = w[S4 + 0000];
S1 = A0;
V0 = V0 - V1;
V0 = V0 >> 10;
[SP + 0010] = w(V0);
V0 = w[A2 + 0004];
V1 = w[S4 + 0004];
A0 = SP + 0010;
V0 = V0 - V1;
V0 = V0 >> 10;
[SP + 0014] = w(V0);
V0 = w[A2 + 0008];
V1 = w[S4 + 0008];
S2 = SP + 0020;
V0 = V0 - V1;
V0 = V0 >> 10;
[SP + 0018] = w(V0);
A2 = w[A3 + 0000];
A1 = S2;
[SP + 0040] = w(A2);
V0 = w[A3 + 0004];
A2 = A2 >> 10;
[SP + 0044] = w(V0);
V1 = w[A3 + 0008];
V0 = V0 >> 10;
[SP + 0040] = w(A2);
[SP + 0044] = w(V0);
[SP + 0048] = w(V1);
V1 = V1 >> 10;
80072E78	jal    $80048c24
[SP + 0048] = w(V1);
S3 = SP + 0040;
A0 = S3;
A1 = S2;
80072E8C	jal    $8004a328
A2 = SP + 0010;
A0 = SP + 0010;
S0 = SP + 0030;
80072E9C	jal    $80048c24
A1 = S0;
A0 = S2;
A1 = S0;
80072EAC	jal    $8004a328
A2 = SP + 0010;
A0 = SP + 0010;
80072EB8	jal    $80048c24
A1 = S3;
V0 = w[SP + 0030];
80072EC4	nop
[S1 + 0000] = h(V0);
V0 = w[SP + 0034];
80072ED0	nop
[S1 + 0002] = h(V0);
V0 = w[SP + 0038];
80072EDC	nop
[S1 + 0004] = h(V0);
V0 = w[SP + 0040];
80072EE8	nop
[S1 + 0006] = h(V0);
V0 = w[SP + 0044];
80072EF4	nop
[S1 + 0008] = h(V0);
V0 = w[SP + 0048];
80072F00	nop
[S1 + 000a] = h(V0);
V0 = w[SP + 0020];
80072F0C	nop
[S1 + 000c] = h(V0);
V0 = w[SP + 0024];
80072F18	nop
[S1 + 000e] = h(V0);
V0 = w[SP + 0028];
80072F24	nop
[S1 + 0010] = h(V0);
V1 = h[S4 + 0002];
A0 = S1;
V0 = V1 << 01;
V0 = V0 + V1;
[SP + 0050] = h(V0);
V1 = h[S4 + 0006];
A1 = SP + 0050;
V0 = V1 << 01;
V0 = V0 + V1;
[SP + 0052] = h(V0);
V1 = h[S4 + 000a];
A2 = SP + 0010;
V0 = V1 << 01;
V0 = V0 + V1;
80072F64	jal    $80049b94
[SP + 0054] = h(V0);
V0 = w[SP + 0010];
80072F70	nop
V0 = 0 - V0;
[S1 + 0014] = w(V0);
V0 = w[SP + 0014];
80072F80	nop
V0 = 0 - V0;
[S1 + 0018] = w(V0);
V0 = w[SP + 0018];
80072F90	nop
V0 = 0 - V0;
[S1 + 001c] = w(V0);
RA = w[SP + 006c];
S4 = w[SP + 0068];
S3 = w[SP + 0064];
S2 = w[SP + 0060];
S1 = w[SP + 005c];
S0 = w[SP + 0058];
SP = SP + 0070;
80072FB8	jr     ra 
80072FBC	nop
////////////////////////////////



////////////////////////////////
// func72fc0()
V0 = A0 - A1;
V0 = V0 & 0fff;
V0 = V0 < 0800;
80072FCC	beq    v0, zero, L72ff4 [$80072ff4]
80072FD0	nop
A0 = A0 - A2;
V0 = A0 - A1;
V0 = V0 & 0fff;
V0 = V0 < 0800;
80072FE4	bne    v0, zero, L73010 [$80073010]
80072FE8	nop
80072FEC	j      L73010 [$80073010]
A0 = A1;

L72ff4:	; 80072FF4
A0 = A0 + A2;
V0 = A0 - A1;
V0 = V0 & 0fff;
V0 = V0 < 0800;
80073004	beq    v0, zero, L73010 [$80073010]
80073008	nop
A0 = A1;

L73010:	; 80073010
80073010	jr     ra 
V0 = A0 & 0fff;
////////////////////////////////



////////////////////////////////
// func73018()
if( w[800ad0f0] == 0 )
{
    A0 = A0;
    A1 = A1;
    func72fc0();
    return V0;
}
else
{
    return A1 & fff;
}
////////////////////////////////



////////////////////////////////
// func73050()

func80720(); // move routine



A0 = 800b1658;
A1 = 800af104;
system_calculate_rotation_matrix();

[800af120] = w(0);
[800af11c] = w(0);
[800af118] = w(0);

A0 = w[800aed6c] - w[800aed5c];
A1 = w[800aed64] - w[800aed54];
system_get_rotation_based_on_vector_x_y();
[800aee62] = h(V0 - 400);

A0 = w[800aed9c] - w[800aed8c];
A1 = w[800aed94] - w[800aed84];
system_get_rotation_based_on_vector_x_y();
[800aee60] = h(V0 - 400);

A0 = (w[800aed64] - w[800aed54]) >> 10;
A1 = (w[800aed6c] - w[800aed5c]) >> 10;
length_of_vector_by_x_y();

A0 = V0;
A1 = (w[800aed68] - w[800aed58]) >> 10;
system_get_rotation_based_on_vector_x_y();
[800af588] = w(V0);



T1 = 1f8003fc;
T0 = 1f8003fc;
[1f8003fc] = w(SP);
T0 = 1f8003fc - 4;
SP = T0;



func728c0(); // camera update



SP = SP + 4;


SP = w[SP];
V0 = w[800aed54];
V1 = w[800aed58];
A1 = w[800aed5c];
A3 = w[800aedb4];
T0 = w[800aedb8];
A2 = w[800aedbc];
V0 = w[SP + 10];
V0 = V0 + A3;

[SP + 0010] = w(V0);
V0 = w[800aed64];
[SP + 0014] = w(V1);
V1 = V1 + T0;
[SP + 0014] = w(V1);
V1 = w[800aed68];
[SP + 0018] = w(A1);
S0 = 800aed6c;
A0 = w[S0 + 0000];
[SP + 0020] = w(V0);
V0 = V0 + A3;
[SP + 0020] = w(V0);
V0 = w[800ad0f0];
A1 = A1 + A2;
[SP + 0018] = w(A1);
[SP + 0024] = w(V1);
V1 = V1 + T0;
[SP + 0028] = w(A0);
A0 = A0 + A2;
[SP + 0024] = w(V1);
80073210	beq    v0, zero, L7327c [$8007327c]
[SP + 0028] = w(A0);
A0 = S0 + 00f8;
A1 = SP + 0010;
A2 = SP + 0020;
80073224	jal    func72de0 [$80072de0]
A3 = S0 + 0008;
A1 = 800aed30;
V0 = w[S0 + 00f8];
V1 = w[S0 + 00fc];
A0 = w[S0 + 0100];
[A1 + 0000] = w(V0);
[A1 + 0004] = w(V1);
[A1 + 0008] = w(A0);
V0 = w[S0 + 0104];
V1 = w[S0 + 0108];
A0 = w[S0 + 010c];
[A1 + 000c] = w(V0);
[A1 + 0010] = w(V1);
[A1 + 0014] = w(A0);
V0 = w[S0 + 0110];
V1 = w[S0 + 0114];
[A1 + 0018] = w(V0);
[A1 + 001c] = w(V1);
80073274	j      L732d8 [$800732d8]
80073278	lui    t1, $1f80

L7327c:	; 8007327C
A0 = 800aed30;
V0 = w[A0 + 0000];
V1 = w[A0 + 0004];
A1 = w[A0 + 0008];
A2 = w[A0 + 000c];
[S0 + 00f8] = w(V0);
[S0 + 00fc] = w(V1);
[S0 + 0100] = w(A1);
[S0 + 0104] = w(A2);
V0 = w[A0 + 0010];
V1 = w[A0 + 0014];
A1 = w[A0 + 0018];
A2 = w[A0 + 001c];
[S0 + 0108] = w(V0);
[S0 + 010c] = w(V1);
[S0 + 0110] = w(A1);
[S0 + 0114] = w(A2);
A1 = SP + 0010;
A2 = SP + 0020;
A3 = S0 + 0008;
800732CC	jal    func72de0 [$80072de0]

800732D4	lui    t1, $1f80

L732d8:	; 800732D8
T1 = T1 | 03fc;
T0 = T1;
[T0 + 0000] = w(SP);
800732E4	addiu  t0, t0, $fffc (=-$4)
SP = T0;
800732EC	jal    func71984 [$80071984]
S2 = 0;
SP = SP + 0004;
SP = w[SP + 0000];
V0 = w[800ad0d4];
80073304	nop

if( V0 > 0 )
{
    S1 = 0;

    loop73314:	; 80073314
        V0 = w[800aefe4];
        8007331C	nop
        A0 = S1 + V0;
        V1 = hu[A0 + 0058];
        80073328	nop
        V0 = V1 & 0f40;
        80073330	beq    v0, zero, L73470 [$80073470]
        V0 = V1 & 0020;
        80073338	bne    v0, zero, L73470 [$80073470]
        8007333C	lui    v0, $0010
        S0 = w[A0 + 004c];
        80073344	nop
        A0 = w[S0 + 0004];
        8007334C	nop
        V0 = A0 & V0;
        80073354	bne    v0, zero, L73470 [$80073470]
        V1 = A0 & 0600;
        V0 = 0200;
        80073360	beq    v1, v0, L73470 [$80073470]
        80073364	nop
        V1 = w[S0 + 0000];
        8007336C	nop
        V0 = V1 & 8000;
        80073374	bne    v0, zero, L733e8 [$800733e8]
        80073378	lui    v0, $0020
        A1 = w[S0 + 0014];
        80073380	nop
        V0 = A1 & V0;
        80073388	beq    v0, zero, L73398 [$80073398]
        V0 = V1 & 1800;
        80073390	beq    v0, zero, L733c8 [$800733c8]
        A2 = 0200;

        L73398:	; 80073398
        V0 = A0 & 2000;
        8007339C	bne    v0, zero, L733b0 [$800733b0]
        800733A0	nop
        A2 = h[S0 + 011e];
        800733A8	j      L733b8 [$800733b8]
        800733AC	nop

        L733b0:	; 800733B0
        A2 = h[800b1688];

        L733b8:	; 800733B8
        A0 = h[S0 + 0108];
        A1 = h[S0 + 0106];
        800733C0	j      L733dc [$800733dc]
        800733C4	nop

        L733c8:	; 800733C8
        A1 = A1 >> 0b;
        800733CC	addiu  a1, a1, $fffe (=-$2)
        A1 = A1 & 0007;
        A1 = A1 << 09;
        A0 = h[S0 + 0108];

        L733dc:	; 800733DC
        func73018();

        [S0 + 0108] = h(V0);

        L733e8:	; 800733E8
        V0 = bu[800acfdd];
        800733F0	nop
        800733F4	bne    v0, zero, L73470 [$80073470]
        800733F8	lui    v1, $0100
        V0 = w[S0 + 0004];
        80073400	nop
        V0 = V0 & V1;
        80073408	bne    v0, zero, L7344c [$8007344c]
        8007340C	nop
        V0 = w[800aefe4];
        80073418	nop
        V0 = S1 + V0;
        V1 = w[V0 + 004c];
        A1 = hu[800aee62];
        V1 = hu[V1 + 0108];
        A0 = w[V0 + 0004];
        A1 = A1 + V1;
        A1 = A1 << 10;
        A1 = A1 >> 10;
        func22218(); // apply new dir and anim

        80073444	j      L73470 [$80073470]
        80073448	nop

        L7344c:	; 8007344C
        V0 = w[800aefe4];
        80073454	nop
        V0 = S1 + V0;
        V1 = w[V0 + 004c];
        A0 = w[V0 + 0004];
        A1 = h[V1 + 0108];
        func21e40(); // set anim move based on rotation

        L73470:	; 80073470
        V0 = w[800ad0d4];
        S2 = S2 + 0001;
        S1 = S1 + 005c;
        V0 = S2 < V0;
    80073480	bne    v0, zero, loop73314 [$80073314]
}



if( w[800c1b60] == 0 )
{
    A0 = 8006f194; // "MATRIX    "
    field_debug_add_timer();
}
////////////////////////////////



////////////////////////////////
// func734c8()

for( int i = 0; i < w[800aefe0]; ++i )
{
    S0 = w[800aefe4] + i * 5c;
    flags = hu[S0 + 58];
    model_data = w[S0 + 0];

    if( ( flags & 0040 ) == 0 ) // model or sprite loaded
    {
        A0 = model_data;
        funca9eb4();

        if( h[800b1662] != 0 )
        {
            if( flags & 0010 )
            {
                [model_data + 12] = h(5);
            }
            else
            {
                [model_data + 12] = h(4);
            }
        }
        else
        {
            if( flags & 000c ) // lighting calculated
            {
                [model_data + 12] = h(1);
            }
            else
            {
                if( flags & 4000 )
                {
                    [model_data + 12] = h(3);
                }
                else
                {
                    if( flags & 0010 )
                    {
                        [model_data + 12] = h(2);
                    }
                    else
                    {
                        [model_data + 12] = h(0);
                    }
                }
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// func735e0()

if( w[800c1b60] == 0 )
{
    800735F4	break   $00400
}

V1 = w[800acfe0];
V1 = V1 + 0001;
V0 = V1 >> 1f;
V0 = V1 + V0;
V0 = V0 >> 01;
V0 = V0 << 01;
V1 = V1 - V0;

A0 = 800b1970 + V1 * 80f4;
[800c3740] = w(A0);
[800acfe0] = w(V1);

A0 = A0 + 80d4;
A1 = 8;
system_clear_otagr();
////////////////////////////////



////////////////////////////////
// func73670()

func735e0();

A0 = w[800c3740] + cc;
A1 = 1000;
system_clear_otagr();

if( w[800ad024] != 0 )
{
    A0 = w[800c3740] + 40d0;
    A1 = 1000;
    system_clear_otagr();
}
////////////////////////////////



////////////////////////////////
// func736c8
800736C8	addiu  sp, sp, $ffe0 (=-$20)
[SP + 0010] = w(S0);
S0 = A0;
[SP + 0014] = w(S1);
[SP + 0018] = w(RA);
800736DC	jal    func7372c [$8007372c]
S1 = A1;
A0 = S0;
800736E8	jal    func73708 [$80073708]
A1 = S1;
RA = w[SP + 0018];
S1 = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0020;
80073700	jr     ra 
80073704	nop
////////////////////////////////



////////////////////////////////
// func73708
V0 = w[A1 + 0014];
8007370C	nop
[A0 + 0014] = w(V0);
V0 = w[A1 + 0018];
80073718	nop
[A0 + 0018] = w(V0);
V0 = w[A1 + 001c];
80073724	jr     ra 
[A0 + 001c] = w(V0);
////////////////////////////////



////////////////////////////////
// func7372c()

[A0 + 0] = h(hu[A1 + 0]);
[A0 + 2] = h(hu[A1 + 2]);
[A0 + 4] = h(hu[A1 + 4]);
[A0 + 6] = h(hu[A1 + 6]);
[A0 + 8] = h(hu[A1 + 8]);
[A0 + a] = h(hu[A1 + a]);
[A0 + c] = h(hu[A1 + c]);
[A0 + e] = h(hu[A1 + e]);
[A0 + 10] = h(hu[A1 + 10]);
////////////////////////////////



////////////////////////////////
// func73798
80073798	addiu  sp, sp, $ff08 (=-$f8)
[SP + 00d8] = w(S0);
S0 = 0;
T1 = 800af1f8;
T3 = 800af0dc;
A3 = 0;
T2 = bu[800aeec9];
T0 = 800ad0fc;
[SP + 00f4] = w(RA);
[SP + 00f0] = w(S6);
[SP + 00ec] = w(S5);
[SP + 00e8] = w(S4);
[SP + 00e4] = w(S3);
[SP + 00e0] = w(S2);
[SP + 00dc] = w(S1);

loop737e4:	; 800737E4
V0 = hu[T0 + 0000];
800737E8	nop
V0 = T2 & V0;
800737F0	beq    v0, zero, L73824 [$80073824]
A0 = 0;
V1 = A3;
V0 = V1 + A0;

loop73800:	; 80073800
V0 = V0 << 01;
V0 = V0 + T1;
[V0 + 0000] = h(0);
A0 = A0 + 0001;
V0 = A0 < 0010;
80073814	bne    v0, zero, loop73800 [$80073800]
V0 = V1 + A0;
8007381C	j      L73854 [$80073854]
A3 = A3 + 0010;

L73824:	; 80073824
A2 = A3;
A1 = T3;

loop7382c:	; 8007382C
V0 = hu[A1 + 0000];
V1 = A2 + A0;
A0 = A0 + 0001;
V1 = V1 << 01;
V1 = V1 + T1;
[V1 + 0000] = h(V0);
V0 = A0 < 0010;
80073848	bne    v0, zero, loop7382c [$8007382c]
A1 = A1 + 0002;
A3 = A3 + 0010;

L73854:	; 80073854
S0 = S0 + 0001;
V0 = S0 < 0008;
8007385C	bne    v0, zero, loop737e4 [$800737e4]
T0 = T0 + 0002;
V1 = 800af524;
8007386C	addiu  a0, v1, $fffc (=-$4)
A1 = 800af1f8;
V0 = 0080;
8007387C	jal    $8004470c
[V1 + 0000] = h(V0);
80073884	jal    $80049ff4
A0 = 0080;
A0 = 010a;
80073890	jal    $system_gte_set_screen_offset
A1 = 00a6;
A0 = w[800aed54];
V0 = w[800aed64];
A1 = w[800aed5c];
V1 = w[800aed68];
S0 = 800aed58;
[SP + 00c8] = w(0);
[SP + 00cc] = w(0);
[SP + 00d0] = w(0);
[SP + 00b8] = w(0);
A0 = A0 - V0;
V0 = w[800aed6c];
A0 = A0 >> 10;
A1 = A1 - V0;
V0 = w[S0 + 0000];
A1 = A1 >> 10;
V0 = V0 - V1;
800738F0	jal    length_of_vector_by_x_y [$80099020]
[SP + 00bc] = w(V0);
S1 = SP + 0030;
A0 = S1;
A1 = SP + 00b8;
A2 = SP + 00c8;
A3 = S0 + 001c;
V0 = 0 - V0;
V0 = V0 << 10;
80073914	jal    func72de0 [$80072de0]
[SP + 00c0] = w(V0);
8007391C	jal    func6fc24 [$8006fc24]
A0 = SP + 0010;
A0 = SP + 0010;
V0 = 0080;
8007392C	jal    $80049da4
[SP + 002c] = w(V0);
80073934	jal    $80049e34
A0 = SP + 0010;
A2 = 0040;
V1 = hu[800b1812];
A0 = h[800ad020];
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
V0 = hu[800aee62];
V1 = hu[V1 + 0106];
V0 = V0 + 0400;
V1 = V1 + V0;
A1 = V1 << 10;
[800ad022] = h(V1);
80073994	jal    func73018 [$80073018]
A1 = A1 >> 10;
S0 = SP + 0050;
A0 = S0;
[800ad020] = h(V0);
[SP + 00b0] = h(0);
[SP + 00b2] = h(V0);
800739B4	jal    func717d0 [$800717d0]
[SP + 00b4] = h(0);
A0 = SP + 00b0;
A1 = S0;
system_calculate_rotation_matrix();

A0 = S1;
800739CC	jal    $80049a84
A1 = S0;
A0 = SP + 0010;
A1 = S0;
A2 = SP + 0070;
V0 = 1000;
800739E4	jal    $800491c4
[SP + 006c] = w(V0);
V0 = bu[800b16a5];
800739F4	nop
800739F8	bne    v0, zero, L73a6c [$80073a6c]
S2 = SP + 0050;
V0 = w[800ad0f0];
80073A08	nop
80073A0C	bne    v0, zero, L73a6c [$80073a6c]
80073A10	nop
V0 = w[8004ea1c];
80073A1C	nop
80073A20	bne    v0, zero, L73a6c [$80073a6c]
S0 = 0014;
S2 = 80d4;
S1 = 800b0450;

loop73a34:	; 80073A34
A1 = S1;
A2 = SP + 0070;
S1 = S1 + 0070;
S0 = S0 + 0001;
A0 = w[800c3740];
A3 = w[800acfe0];
80073A54	jal    func7a180 [$8007a180]
A0 = A0 + S2;
V0 = S0 < 0015;
80073A60	bne    v0, zero, loop73a34 [$80073a34]
80073A64	nop
S2 = SP + 0050;

L73a6c:	; 80073A6C
80073A6C	jal    func6fc24 [$8006fc24]
A0 = S2;
A0 = SP + 0030;
80073A78	jal    $80049a84
A1 = S2;
A0 = SP + 0010;
A1 = S2;
S3 = SP + 0070;
A2 = S3;
S1 = 1000;
80073A94	jal    $800491c4
[SP + 006c] = w(S1);
A0 = SP + 0010;
A1 = S2;
S0 = 800aef58;
80073AAC	jal    $800490b4
A2 = S0;
80073AB4	jal    $80049da4
A0 = SP + 0010;
80073ABC	jal    $80049e34
A0 = SP + 0010;
80073AC4	jal    func6fc24 [$8006fc24]
A0 = S2;
80073ACC	addiu  a0, s0, $ff0c (=-$f4)
80073AD0	jal    $80049a84
A1 = S2;
A0 = SP + 0010;
A1 = S2;
A2 = S3;
80073AE4	jal    $800491c4
[SP + 006c] = w(S1);
A0 = SP + 0010;
80073AF0	jal    func736c8 [$800736c8]
A1 = S3;
A0 = SP + 00b0;
A1 = SP + 0090;
V0 = 0400;
[SP + 00b0] = h(V0);
[SP + 00b2] = h(0);
[SP + 00b4] = h(0);
system_calculate_rotation_matrix();

V0 = bu[800b16a5];
80073B1C	nop
80073B20	bne    v0, zero, L73c70 [$80073c70]
80073B24	lui    a3, $00ff
V0 = w[800ad0f0];
80073B30	nop
80073B34	bne    v0, zero, L73c74 [$80073c74]
A3 = A3 | ffff;
V0 = w[8004ea1c];
80073B44	nop
80073B48	bne    v0, zero, L73c70 [$80073c70]
80073B4C	lui    a3, $00ff
S0 = 0010;
S6 = S2;
S4 = S3;
S3 = 0700;
V0 = 800ad0cc;
S2 = V0 + 0042;
S1 = V0 + 0040;

loop73b70:	; 80073B70
80073B70	jal    func6fc24 [$8006fc24]
A0 = S6;
A0 = SP + 0010;
A1 = S6;
A2 = S4;
V0 = h[S1 + 0000];
S1 = S1 + 0004;
S0 = S0 + 0001;
[SP + 0064] = w(V0);
V0 = h[S2 + 0000];
S2 = S2 + 0004;
80073B9C	jal    $800491c4
[SP + 006c] = w(V0);
A0 = S4;
80073BA8	jal    func7372c [$8007372c]
A1 = SP + 0090;
S5 = 800afb90;
A1 = S3 + S5;
A2 = S4;
S3 = S3 + 0070;
A0 = 80d4;
V0 = w[800c3740];
A3 = w[800acfe0];
80073BD8	jal    func7a26c [$8007a26c]
A0 = V0 + A0;
V0 = S0 < 0014;
80073BE4	bne    v0, zero, loop73b70 [$80073b70]
80073BE8	nop
S0 = 0;
S2 = 80d4;
S1 = S5;
A1 = S5;

loop73bfc:	; 80073BFC
A2 = SP + 0010;
S1 = S1 + 0070;
S0 = S0 + 0001;
A0 = w[800c3740];
A3 = w[800acfe0];
80073C18	jal    func7a180 [$8007a180]
A0 = A0 + S2;
V0 = S0 < 0010;
80073C24	bne    v0, zero, loop73bfc [$80073bfc]
A1 = S1;
S0 = 0015;
S2 = 80d4;
S1 = 800b04c0;

loop73c3c:	; 80073C3C
A1 = S1;
A2 = SP + 0010;
S1 = S1 + 0070;
S0 = S0 + 0001;
A0 = w[800c3740];
A3 = w[800acfe0];
80073C5C	jal    func7a180 [$8007a180]
A0 = A0 + S2;
V0 = S0 < 19;
80073C68	bne    v0, zero, loop73c3c [$80073c3c]
80073C6C	lui    a3, $00ff

L73c70:	; 80073C70
A3 = A3 | ffff;

L73c74:	; 80073C74
A0 = 00a0;
A1 = 800b12d4;
80073C80	lui    t0, $ff00
V0 = w[800acfe0];
A2 = w[800c3740];
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 06;
V1 = V1 + A1;
A1 = w[V1 + 0000];
80073CA8	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80d4];
A1 = A1 & T0;
V0 = V0 & A3;
A1 = A1 | V0;
[V1 + 0000] = w(A1);
80073CC4	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80d4];
V1 = V1 & A3;
V0 = V0 & T0;
V0 = V0 | V1;
80073CDC	lui    at, $0001
AT = A2 + AT;
[AT + 80d4] = w(V0);
80073CE8	jal    $system_gte_set_screen_offset
A1 = 0070;
A0 = w[800aeecc];
80073CF8	jal    $80049ff4
80073CFC	nop
RA = w[SP + 00f4];
S6 = w[SP + 00f0];
S5 = w[SP + 00ec];
S4 = w[SP + 00e8];
S3 = w[SP + 00e4];
S2 = w[SP + 00e0];
S1 = w[SP + 00dc];
S0 = w[SP + 00d8];
SP = SP + 00f8;
80073D24	jr     ra 
80073D28	nop
////////////////////////////////



////////////////////////////////
// func73d2c
80073D2C	addiu  sp, sp, $fff8 (=-$8)
V0 = w[800aefe0];
80073D38	nop
80073D3C	blez   v0, L73d80 [$80073d80]
A0 = 0;
A2 = V0;
A1 = w[800aefe4];

loop73d50:	; 80073D50
80073D50	nop
V1 = hu[A1 + 0058];
80073D58	nop
V0 = V1 & 0040;
80073D60	bne    v0, zero, L73d70 [$80073d70]
V0 = V1 & 8000;
80073D68	bne    v0, zero, L73d84 [$80073d84]
V0 = 0001;

L73d70:	; 80073D70
A0 = A0 + 0001;
V0 = A0 < A2;
80073D78	bne    v0, zero, loop73d50 [$80073d50]
A1 = A1 + 005c;

L73d80:	; 80073D80
V0 = 0;

L73d84:	; 80073D84
SP = SP + 0008;
80073D88	jr     ra 
80073D8C	nop
////////////////////////////////



////////////////////////////////
// func73d90()

[800af370] = h(0); // current buttons c1
[800af374] = h(0); // current buttons c2
[800c1b68] = h(0); // pressed buttons c1
[800c2dcc] = h(0); // pressed buttons c2
[800c2dd4] = h(0); // repeated buttons c1
[800c2ddc] = h(0); // repeated buttons c2

// receive all button updates since last update
L73dc8:	; 80073DC8
    func35b88(); // get one button update
    if( V0 == 0 )
    {
        break;
    }
    [800af370] = h(hu[800af370] | (hu[80058с0с] & hu[800b164e]));
    [800af374] = h(hu[800af374] | hu[80058с10]);
    [800c1b68] = h(hu[800c1b68] | (hu[80058b28] & hu[800b164e]));
    [800c2dcc] = h(hu[800c2dcc] | hu[80058b2c]);
    [800c2dd4] = h(hu[800c2dd4] | (hu[80058b40] & hu[800b164e]));
    [800c2ddc] = h(hu[800c2ddc] | hu[80058b44]);
80073E94	j      L73dc8 [$80073dc8]

// filter buttons
[800af370] = h(hu[800af370] & hu[800acfd8]);
[800c2dd4] = h(hu[800c2dd4] & hu[800acfd8]);
[800c1b68] = h(hu[800c1b68] & hu[800acfd8]);

func35c84(); // clear system button masks

A0 = 1;
A1 = 80064ed8; // mouse struct
field_get_mouse_data();

if( w[800ad0f0] != 0 )
{
    [800af370] = h(0);
    [800af374] = h(0);
    [800c1b68] = h(0);
    [800c2dcc] = h(0);
    [800c2dd4] = h(0);
    [800c2ddc] = h(0);
}

// if battle started - disable jumping
if( w[800ad0b4] == 0 )
{
    [800c1b68] = h(hu[800c1b68] & ff7f);
}
////////////////////////////////



////////////////////////////////
// func73f78

S2 = 800b1662;
V0 = h[S2 + 0000];
[80058c14] = w(0);
[80058c5c] = w(0);
80073FC0	beq    v0, zero, L74028 [$80074028]
80073FC4	nop
A0 = bu[800b1664];
A1 = bu[800b1665];
A2 = bu[800b1666];
80073FE0	jal    $8002c4f0
80073FE4	nop
A0 = bu[800b1668];
A1 = bu[800b1669];
A2 = bu[800b166a];
80074000	jal    $80049fb4
80074004	nop
A0 = h[800b166c];
A1 = h[800b166e];
A2 = w[800aeecc];
80074020	jal    $80048958
80074024	nop

L74028:	; 80074028
S0 = 800aef98;
80074030	addiu  a0, s0, $ffc0 (=-$40)
A1 = SP + 0018;
V1 = w[S0 + 0000];
V0 = 0800;
[SP + 0028] = w(V0);
[SP + 002c] = w(V0);
[SP + 0030] = w(V0);
[SP + 0018] = w(V1);
[SP + 001c] = w(V1);
80074054	jal    $80049c74
[SP + 0020] = w(V1);
8007405C	addiu  s1, s0, $ffa0 (=-$60)
A0 = S1;
A1 = 800af104;
8007406C	jal    $800491c4
A2 = SP + 0038;
A0 = h[800b1682];
V0 = w[800b1690];
A1 = h[800b1686];
V1 = w[800b1694];
[8004f7a8] = w(0);
V1 = V1 + A1;
[800b1694] = w(V1);
V1 = h[800b1684];
V0 = V0 + A0;
[800b1690] = w(V0);
V0 = w[800b1698];
A0 = w[800aefe0];
V0 = V0 + V1;
[800b1698] = w(V0);
800740D8	blez   a0, L74844 [$80074844]
S6 = 0;
FP = 0001;
S3 = SP + 0078;
S7 = S0 + 004c;
S5 = S2 + 0044;
S4 = SP + 0058;
S2 = 0;

L740f8:	; 800740F8
V0 = w[800aefe4];
80074100	nop
V0 = S2 + V0;
V1 = w[V0 + 000c];
A0 = w[V0 + 0010];
A1 = w[V0 + 0014];
A2 = w[V0 + 0018];
[V0 + 002c] = w(V1);
[V0 + 0030] = w(A0);
[V0 + 0034] = w(A1);
[V0 + 0038] = w(A2);
V1 = w[V0 + 001c];
A0 = w[V0 + 0020];
A1 = w[V0 + 0024];
A2 = w[V0 + 0028];
[V0 + 003c] = w(V1);
[V0 + 0040] = w(A0);
[V0 + 0044] = w(A1);
[V0 + 0048] = w(A2);
V0 = w[800aefe4];
80074150	nop
V1 = S2 + V0;
V0 = hu[V1 + 0058];
8007415C	nop
V0 = V0 & 0040;
80074164	bne    v0, zero, L7482c [$8007482c]
[SP + 0098] = w(0);
V0 = w[800ad0d4];
80074174	nop
V0 = S6 < V0;
8007417C	beq    v0, zero, L743c0 [$800743c0]
S1 = V1;
A0 = w[S1 + 004c];
80074188	nop
V0 = w[A0 + 012c];
80074190	nop
V1 = V0 & 0003;
V0 = 0002;
8007419C	beq    v1, v0, L741e4 [$800741e4]
V0 = V1 < 0003;
800741A4	beq    v0, zero, L741bc [$800741bc]
800741A8	nop
800741AC	beq    v1, fp, L741d0 [$800741d0]
800741B0	nop
800741B4	j      L7427c [$8007427c]
800741B8	nop

L741bc:	; 800741BC
V0 = 0003;
800741C0	beq    v1, v0, L74200 [$80074200]
800741C4	nop
800741C8	j      L7427c [$8007427c]
800741CC	nop

L741d0:	; 800741D0
V0 = hu[A0 + 0070];
[SP + 0012] = h(0);
[SP + 0014] = h(0);
800741DC	j      L7421c [$8007421c]
[SP + 0010] = h(V0);

L741e4:	; 800741E4
[SP + 0010] = h(0);
V0 = w[S1 + 004c];
800741EC	nop
V0 = hu[V0 + 0070];
[SP + 0014] = h(0);
800741F8	j      L7421c [$8007421c]
[SP + 0012] = h(V0);

L74200:	; 80074200
[SP + 0010] = h(0);
[SP + 0012] = h(0);
V0 = w[S1 + 004c];
8007420C	nop
V0 = hu[V0 + 0070];
80074214	nop
[SP + 0014] = h(V0);

L7421c:	; 8007421C
A0 = SP + 0010;
A1 = S3;
system_calculate_rotation_matrix();

A0 = w[S7 + 0000];
A1 = S3;
A0 = A0 + S2;
80074234	jal    $80049a84
A0 = A0 + 000c;
V0 = w[800aefe4];
80074244	nop
V0 = S2 + V0;
V1 = w[V0 + 0020];
80074250	addiu  a0, s7, $ff54 (=-$ac)
[SP + 008c] = w(V1);
V1 = w[V0 + 0024];
A1 = S3;
[SP + 0090] = w(V1);
V0 = w[V0 + 0028];
A2 = SP + 0058;
8007426C	jal    $800491c4
[SP + 0094] = w(V0);
80074274	j      L74628 [$80074628]
80074278	nop

L7427c:	; 8007427C
V1 = w[S1 + 004c];
80074280	nop
A3 = hu[V1 + 0128];
V0 = ffff;
A2 = A3 & ffff;
80074290	beq    a2, v0, L74304 [$80074304]
A2 = A2 >> 0c;
A0 = w[S7 + 0000];
A3 = A3 & 0fff;
A0 = A0 + S2;
A0 = A0 + 002c;
800742A8	jal    $801e72cc
A1 = A0;
800742B0	addiu  a0, s7, $ff54 (=-$ac)
A1 = w[S7 + 0000];
A2 = S3;
A1 = A1 + S2;
800742C0	jal    $800491c4
A1 = A1 + 002c;
A0 = S3;
A1 = w[S7 + 0000];
A2 = SP + 0058;
A1 = A1 + S2;
800742D8	jal    $800491c4
A1 = A1 + 000c;
A1 = w[S7 + 0000];
800742E4	nop
A1 = A1 + S2;
A0 = A1 + 002c;
A1 = A1 + 000c;
800742F4	jal    $800491c4
A2 = A0;
800742FC	j      L74628 [$80074628]
80074300	nop

L74304:	; 80074304
V1 = bu[V1 + 0075];
V0 = 00ff;
8007430C	beq    v1, v0, L74410 [$80074410]
A2 = S3;
V0 = w[800aefe4];
A0 = 800aef38;
V0 = S2 + V0;
V0 = w[V0 + 004c];
8007432C	nop
V1 = bu[V0 + 0075];
A1 = w[800aefe4];
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V0 = V0 << 02;
A1 = A1 + V0;
80074354	jal    $800491c4
A1 = A1 + 002c;
A0 = S3;
A1 = w[800aefe4];
A2 = SP + 0058;
A1 = A1 + S2;
80074370	jal    $800491c4
A1 = A1 + 000c;
A0 = w[800aefe4];
80074380	nop
A2 = S2 + A0;
V0 = w[A2 + 004c];
A1 = A2 + 000c;
V1 = bu[V0 + 0075];
A2 = A2 + 002c;
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V0 = V0 << 02;
A0 = A0 + V0;
800743B0	jal    $800491c4
A0 = A0 + 002c;
800743B8	j      L74628 [$80074628]
800743BC	nop

L743c0:	; 800743C0
V0 = bu[S5 + 0000];
800743C4	nop
V0 = V0 & 007f;
800743CC	bne    v0, zero, L74410 [$80074410]
800743D0	nop
V1 = h[S5 + ffdc];
V0 = w[S1 + 0020];
800743DC	nop
V0 = V0 + V1;
[S1 + 0020] = w(V0);
V1 = h[S5 + ffe0];
V0 = w[S1 + 0024];
800743F0	nop
V0 = V0 + V1;
[S1 + 0024] = w(V0);
V1 = h[S5 + ffde];
V0 = w[S1 + 0028];
80074404	nop
V0 = V0 + V1;
[S1 + 0028] = w(V0);

L74410:	; 80074410
V0 = bu[S5 + 0000];
80074414	nop
V0 = V0 & 007f;
8007441C	bne    v0, fp, L74460 [$80074460]
80074420	nop
V1 = h[S5 + ffdc];
V0 = w[S1 + 0020];
8007442C	nop
V0 = V0 + V1;
[S1 + 0020] = w(V0);
V1 = h[S5 + ffe0];
V0 = w[S1 + 0024];
80074440	nop
V0 = V0 + V1;
[S1 + 0024] = w(V0);
V1 = h[S5 + ffde];
V0 = w[S1 + 0028];
80074454	nop
V0 = V0 + V1;
[S1 + 0028] = w(V0);

L74460:	; 80074460
V0 = bu[S5 + 0000];
80074464	nop
V0 = V0 & 0080;
8007446C	beq    v0, zero, L7447c [$8007447c]
V1 = SP + 0038;
T0 = 0001;
[SP + 0098] = w(T0);

L7447c:	; 8007447C
T4 = w[V1 + 0000];
T5 = w[V1 + 0004];
R11R12 = T4;
R13R21 = T5;
T4 = w[V1 + 0008];
T5 = w[V1 + 000c];
T6 = w[V1 + 0010];
R22R23 = T4;
R31R32 = T5;
R33 = T6;
V0 = S1 + 000c;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
800744C0	nop
800744C4	nop
800744C8	gte_func18t1,dqb
T4 = IR1;
T5 = IR2;
T6 = IR3;
[S4 + 0000] = h(T4);
[S4 + 0006] = h(T5);
[S4 + 000c] = h(T6);
V0 = S1 + 000e;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
80074500	nop
80074504	nop
80074508	gte_func18t1,dqb
V0 = SP + 005a;
T4 = IR1;
T5 = IR2;
T6 = IR3;
[V0 + 0000] = h(T4);
[V0 + 0006] = h(T5);
[V0 + 000c] = h(T6);
V0 = S1 + 0010;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
80074544	nop
80074548	nop
8007454C	gte_func18t1,dqb
V0 = SP + 005c;
T4 = IR1;
T5 = IR2;
T6 = IR3;
[V0 + 0000] = h(T4);
[V0 + 0006] = h(T5);
[V0 + 000c] = h(T6);
T4 = w[V1 + 0014];
T5 = w[V1 + 0018];
80074574	ctc2   t4,vz2
T6 = w[V1 + 001c];
8007457C	ctc2   t5,rgb
80074580	ctc2   t6,otz
V0 = S1 + 0020;
T5 = hu[V0 + 0004];
T4 = hu[V0 + 0000];
T5 = T5 << 10;
T4 = T4 | T5;
VXY0 = T4;
VZ0 = w[V0 + 0008];
800745A0	nop
800745A4	nop
800745A8	gte_func18t0,r11r12
V0 = SP + 006c;
[V0 + 0000] = w(MAC1);
[V0 + 0004] = w(MAC2);
[V0 + 0008] = w(MAC3);
V0 = w[800aefe4];
800745C4	nop
A1 = S2 + V0;
V0 = hu[A1 + 0058];
800745D0	nop
V0 = V0 & 0003;
800745D8	beq    v0, zero, L74628 [$80074628]
800745DC	nop
800745E0	bne    v0, fp, L74604 [$80074604]
A0 = S4;
A0 = 800aef58;
A1 = A1 + 000c;
800745F4	jal    $800490b4
A2 = S4;
800745FC	j      L74618 [$80074618]
80074600	nop

L74604:	; 80074604
80074604	jal    func7372c [$8007372c]
A1 = A1 + 000c;
A0 = S4;
80074610	jal    $80049c74
A1 = SP + 0018;

L74618:	; 80074618
A0 = 800aee84;
80074620	jal    $80049a84
A1 = SP + 0058;

L74628:	; 80074628
S0 = w[S1 + 0000];
8007462C	nop
V0 = h[S0 + 0012];
80074634	nop
80074638	bne    v0, fp, L746b4 [$800746b4]
8007463C	nop
V0 = w[SP + 0058];
V1 = w[SP + 005c];
A0 = w[SP + 0060];
A1 = w[SP + 0064];
[SP + 0078] = w(V0);
[SP + 007c] = w(V1);
[SP + 0080] = w(A0);
[SP + 0084] = w(A1);
V0 = w[SP + 0068];
V1 = w[SP + 006c];
A0 = w[SP + 0070];
A1 = w[SP + 0074];
[SP + 0088] = w(V0);
[SP + 008c] = w(V1);
[SP + 0090] = w(A0);
[SP + 0094] = w(A1);
A0 = S3;
80074684	jal    $80049c74
A1 = SP + 0028;
8007468C	jal    $80030924
A0 = S3;
A0 = h[800aefd8];
A1 = h[800aefda];
A2 = h[800aefdc];
800746AC	jal    $80030a50
800746B0	nop

L746b4:	; 800746B4
V0 = w[800aefe4];
800746BC	nop
V0 = S2 + V0;
V0 = hu[V0 + 0058];
[8004f7a8] = w(0);
V0 = V0 & 0020;
800746D4	bne    v0, zero, L7482c [$8007482c]
800746D8	nop
V0 = hu[S1 + 0058];
800746E0	nop
V0 = V0 & 2000;
800746E8	beq    v0, zero, L7471c [$8007471c]
800746EC	nop
V0 = w[S0 + 0014];
800746F4	nop
800746F8	beq    v0, zero, L7471c [$8007471c]
800746FC	nop
A0 = w[S0 + 0014];
[800ad030] = w(S6);
[800ad034] = w(0);
80074714	jal    $800303e8
80074718	nop

L7471c:	; 8007471C
T4 = w[S4 + 0000];
T5 = w[S4 + 0004];
R11R12 = T4;
R13R21 = T5;
T4 = w[S4 + 0008];
T5 = w[S4 + 000c];
T6 = w[S4 + 0010];
R22R23 = T4;
R31R32 = T5;
R33 = T6;
T4 = w[S4 + 0014];
T5 = w[S4 + 0018];
8007474C	ctc2   t4,vz2
T6 = w[S4 + 001c];
80074754	ctc2   t5,rgb
80074758	ctc2   t6,otz
8007475C	jal    funca9f4c [$800a9f4c]
A0 = S0;
80074764	beq    v0, zero, L7477c [$8007477c]
80074768	nop
T0 = w[SP + 0098];
80074770	nop
80074774	bne    t0, fp, L7482c [$8007482c]
80074778	nop

L7477c:	; 8007477C
T4 = w[S4 + 0000];
T5 = w[S4 + 0004];
R11R12 = T4;
R13R21 = T5;
T4 = w[S4 + 0008];
T5 = w[S4 + 000c];
T6 = w[S4 + 0010];
R22R23 = T4;
R31R32 = T5;
R33 = T6;
T4 = w[S4 + 0014];
T5 = w[S4 + 0018];
800747AC	ctc2   t4,vz2
T6 = w[S4 + 001c];
800747B4	ctc2   t5,rgb
800747B8	ctc2   t6,otz
V0 = hu[S1 + 0058];
800747C0	nop
V0 = V0 & 8000;
800747C8	bne    v0, zero, L747fc [$800747fc]
800747CC	nop
A0 = w[S0 + 0004];
V0 = w[800acfe0];
A3 = h[S0 + 0012];
A2 = w[800c3740];
V0 = V0 << 02;
V0 = V0 + S0;
A1 = w[V0 + 0008];
800747F4	j      L74824 [$80074824]
A2 = A2 + 00cc;

L747fc:	; 800747FC
A0 = w[S0 + 0004];
V0 = w[800acfe0];
A3 = h[S0 + 0012];
A2 = w[800c3740];
V0 = V0 << 02;
V0 = V0 + S0;
A1 = w[V0 + 0008];
A2 = A2 + 40d0;

L74824:	; 80074824
80074824	jal    $8002c510
80074828	nop

L7482c:	; 8007482C
V0 = w[800aefe0];
S6 = S6 + 0001;
V0 = S6 < V0;
8007483C	bne    v0, zero, L740f8 [$800740f8]
S2 = S2 + 005c;

L74844:	; 80074844
V0 = w[800c1b60];
if( V0 == 0 )
{
    A0 = 8006f1a0; // "MODEL     "
    field_debug_add_timer();
}
////////////////////////////////



////////////////////////////////
// func7489c

V0 = w[8004ea24];
800748AC	bne    v0, zero, L74944 [$80074944]

S0 = 800b1738;
V0 = w[S0 + 0000];
800748C0	nop
800748C4	beq    v0, zero, L74920 [$80074920]
800748C8	nop
800748CC	jal    func861bc [$800861bc]
800748D0	nop
A0 = bu[800b1730];
A1 = bu[800b1731];
A2 = bu[800b1732];
800748EC	jal    $80049f94
800748F0	nop
A0 = 800aef38;
800748FC	addiu  a1, s0, $ffb8 (=-$48)
A2 = w[800c3740];
A3 = w[800acfe0];
V0 = 0001;
[SP + 0010] = w(V0);
80074918	jal    $801e7d14
A2 = A2 + 00cc;

L74920:	; 80074920
if( w[800c1b60] == 0 )
{
    A0 = 8006f1ac; // "GEAR      "
    field_debug_add_timer();
}
////////////////////////////////
