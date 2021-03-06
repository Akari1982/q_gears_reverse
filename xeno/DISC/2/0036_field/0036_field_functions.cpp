////////////////////////////////
// clear_distortion_buffers()

[800b154c] = h(0); // deactivate distortion update

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



////////////////////////////////
// set_distortion()
// called from 0xFE26_ScreenDistortionSetup()
// or from funca1ca4()
// Эффект дисторшна. Используется на первой карте с горением Лахана чтобы показать горячий воздух от пожара

read_script = A0;

[800b154c] = h(1); // activate distortion update

if( w[800acffc] == 0 ) // init buffers
{
    A0 = 180;
    A1 = 0;
    system_memory_allocate();
    [800b1588] = w(V0);

    A0 = 180;
    A1 = 0;
    system_memory_allocate();
    [800b158c] = w(V0);

    A0 = 3840;
    A1 = 0;
    system_memory_allocate();
    [800b1590] = w(V0);

    A0 = 3840;
    A1 = 0;
    system_memory_allocate();
    [800b1594] = w(V0);

    [800acffc] = w(1);

    for( int i = 0; i < 11; ++i )
    {
        for( int j = 0; j < 14; ++j )
        {
            S0 = w[800b1590] + (i * 14 + j) * 28;
            S4 = w[800b1594] + (i * 14 + j) * 28;

            A0 = S0;
            system_graphic_textured_quad_header();

            A0 = S0;
            A1 = 0;
            system_set_draw_packet_transparency();

            [S0 + 4] = b(80); // R
            [S0 + 5] = b(80); // G
            [S0 + 6] = b(80); // B
            [S0 + 8] = h(j * 10); // x0
            [S0 + a] = h(i * 10); // y0
            [S0 + 10] = h(j * 10 + 10); // x1
            [S0 + 12] = h(i * 10); // y1
            [S0 + 18] = h(j * 10); // x2
            [S0 + 1a] = h(i * 10 + 10); // y2
            [S0 + 20] = h(j * 10 + 10); // x3
            [S0 + 22] = h(i * 10 + 10); // y3

            if( i >= e )
            {
                [S0 + c] = b((j * 10) & 3f); // u0
                [S0 + d] = b((j & fc) * 4 + (i - e) * 50); // v0
                [S0 + 14] = b((j * 10) & 3f + 10); // u1
                [S0 + 15] = b((j & fc) * 4 + (i - e) * 50); // v1
                [S0 + 1c] = b((j * 10) & 3f); // u2
                [S0 + 1d] = b((j & fc) * 4 + (i - e) * 50 + 10); // v2
                [S0 + 24] = b((j * 10) & 3f + 10); // u3
                [S0 + 25] = b((j & fc) * 4 + (i - e) * 50 + 10); // v3

                A0 = 2; // 15 bit
                A1 = 0;
                A2 = 3c0; // x base
                A3 = 0; // y base
                system_graphic_get_texpage_by_param();
                [S0 + 16] = h(V0);

                A3 = S4;
                A2 = S0;
                T0 = A2 + 28;
                while( A2 != T0 )
                {
                    [A3] = w(w[A2]);
                    A2 = A2 + 4;
                    A3 = A3 + 4;
                }
            }
            else
            {
                [S0 + c] = b((j * 10) & 3f); // u0
                [S0 + d] = b(i * 10); // v0
                [S0 + 14] = b(((j * 10) & 3f) + 10); // u1
                [S0 + 15] = b(i * 10); // v1
                [S0 + 1c] = b((j * 10) & 3f); // u2
                [S0 + 1d] = b(i * 10 + 10); // v2
                [S0 + 24] = b(((j * 10) & 3f) + 10); // u3
                [S0 + 25] = b(i * 10 + 10); // v3

                A0 = 2; // 15 bit
                A1 = 0; // semi transparency
                A2 = (j * 10) & ffc0; // x base
                A3 = 0; // y base
                system_graphic_get_texpage_by_param();
                [S0 + 16] = h(V0);

                A3 = S4;
                A2 = S0;
                T0 = A2 + 28;
                while( A2 != T0 )
                {
                    [A3] = w(w[A2]);
                    A2 = A2 + 4;
                    A3 = A3 + 4;
                }

                A0 = 2;
                A1 = 0;
                A2 = (j * 10) & ffc0; // x base
                A3 = 100; // y base
                system_graphic_get_texpage_by_param();
                [S4 + 16] = h(V0);
            }
        }
    }

    [SP + 20] = h(0); // src x
    [SP + 22] = h(20); // src y
    [SP + 24] = h(140); // width
    [SP + 26] = h(c0); // height

    A0 = w[800b1588];
    A1 = SP + 20;
    A2 = 0; // dst x
    A3 = 0; // dst y
    system_graphic_create_copy_rectangle_packet();

    [SP + 22] = h(120); // src y

    A0 = w[800b158c];
    A1 = SP + 20;
    A2 = 0;
    A3 = 100;
    system_graphic_create_copy_rectangle_packet();

    for( int i = 0; i < f; ++i )
    {
        [SP + 20] = h(hu[800adff8 + i * 4 + 0]); // src x
        [SP + 22] = h(hu[800adff8 + i * 4 + 2]); // src y
        [SP + 24] = h(40); // width
        [SP + 26] = h(10); // height

        A0 = w[800b1588] + 18 + i * 18;
        A1 = SP + 20;
        A2 = 3c0; // width
        A3 = i * 10; // height
        system_graphic_create_copy_rectangle_packet();

        [SP + 22] = h(hu[800adff8 + i * 4 + 2] + 100); // src y

        A0 = w[800b158c] + 18 + i * 18;
        A1 = SP + 20;
        A2 = 3c0; // width
        A3 = i * 10; // height
        system_graphic_create_copy_rectangle_packet();
    }
}

if( read_script == 0 )
{
    A0 = 1;
    read_two_bytes_with_80();
    S5 = V0;

    A0 = 3;
    read_two_bytes_with_80();
    S4 = V0;

    A0 = 5;
    read_two_bytes_with_80();
    S3 = V0;

    A0 = 7;
    read_two_bytes_with_80();
    S2 = V0;

    A0 = 9;
    read_two_bytes_with_80();
    S1 = V0;

    A0 = b;
    read_two_bytes_with_80();
    S0 = V0;

    A0 = d;
    read_two_bytes_with_80();

    A0 = S5;
    A1 = S4;
    A2 = S3;
    A3 = S2;
    A4 = S1;
    A5 = S0;
    A6 = V0; // steps
    setup_distortion_values();
}

[800b154e] = h(0);
////////////////////////////////



////////////////////////////////
// setup_distortion_values()

steps = A6;
if( steps == 0 )
{
    steps = 1;
}

[800b1550] = h(steps);
[800b156c] = w(((A0 << 10) - w[800b1554]) / steps);
[800b1570] = w(((A1 << 10) - w[800b1558]) / steps);
[800b1574] = w(((A2 << 10) - w[800b155c]) / steps);
[800b1578] = w(((A3 << 10) - w[800b1560]) / steps);
[800b157c] = w(((A4 << 10) - w[800b1564]) / steps);
[800b1580] = w(((A5 << 10) - w[800b1568]) / steps);
////////////////////////////////



////////////////////////////////
// update_distortion()

if( h[800b154c] != 0 ) // render distortion
{
    if( h[800b1550] > 0 ) // unfinished steps
    {
        [800b1550] = h(hu[800b1550] - 1);
        [800b1554] = w(w[800b1554] + w[800b156c]);
        [800b1558] = w(w[800b1558] + w[800b1570]);
        [800b155c] = w(w[800b155c] + w[800b1574]);
        [800b1560] = w(w[800b1560] + w[800b1578]);
        [800b1564] = w(w[800b1564] + w[800b157c]);
        [800b1568] = w(w[800b1568] + w[800b1580]);
    }
    else if( h[800b154e] != 0 ) // stop after finish
    {
        [800b154c] = h(0); // deactivate distortion update
        [800b1554] = w(0);
        [800b1558] = w(0);
        [800b155c] = w(0);
        [800b1560] = w(0);
        [800b1564] = w(0);
        [800b1568] = w(0);
    }

    val1 = w[800b1554] >> 10;
    val2 = w[800b1558] >> 10;
    val3 = w[800b155c] >> 10;
    val4 = w[800b1560] >> 10;
    val5 = w[800b1564] >> 10;
    val6 = w[800b1568] >> 10;

    rb = w[800acfe0]; // render buffer

    [800b1584] = h(h[800b1584] + val5);
    [800b1586] = h(h[800b1586] + val6);

    for( int i = e; i < 11; ++i )
    {
        A0 = h[800b1586] + val6 * 2 + i * val4 * b;
        system_cos();
        S6 = (V0 * val2) >> c;

        for( int j = 0; j < 14; ++j )
        {
            A0 = h[800b1584] + j * val3;
            system_cos();
            S3 = (V0 * val1) >> c;

            V1 = w[800b1590 + rb * 4];
            S0 = V1 + (118 + i * 14 + j) * 28;

            if( j == 0 )
            {
                [V1 + 2bc0 + i * 320 + 18] = h(0);
                [V1 + 2bc0 + i * 320 + 8] = h(0);
            }
            else
            {
                [S0 + fff8] = h(S3 + j * 10);
                [S0 + ffe8] = h(S3 + j * 10);
                [S0 + 0018] = h(S3 + j * 10);
                [S0 + 0008] = h(S3 + j * 10);

                if( j == 13 )
                {
                    [V1 + (118 + i * 14 + j) * 28 + 20] = h(S3 + 140);
                    [V1 + (118 + i * 14 + j) * 28 + 10] = h(S3 + 140);
                }
            }

            [V1 + (118 + i * 14 + j) * 28 + a] = h(S6 + i * 10 - 30);
            [V1 + (118 + i * 14 + j) * 28 + 12] = h(S6 + i * 10 - 30);
            [V1 + (118 + i * 14 + j) * 28 + fd02] = h(S6 + i * 10 - 30);
            [V1 + (118 + i * 14 + j) * 28 + fcfa] = h(S6 + i * 10 - 30);

            if( i == 10 )
            {
                [V1 + (i * 14 + j) * 28 + 1a] = h(e0);
                [V1 + (i * 14 + j) * 28 + 22] = h(e0);
            }

            A3 = w[800c3740];
            [S0 + 0] = w((w[S0 + 0] & ff000000) | (w[A3 + d0] & 00ffffff));
            [A3 + d0] = w((w[A3 + d0] & ff000000) | (S0 & 00ffffff));
        }
    }

    A0 = w[800acfe0];
    A1 = w[800b1588 + A0 * 4];

    [A1 + 0] = w((w[A1 + 0] & ff000000) | (V1 & 00ffffff));
    [A3 + d0] = w((w[A3 + d0] & ff000000) | (w[800b1588 + A0 * 4] & 00ffffff));

    for( int i = 0; i < e; ++i )
    {
        A0 = h[800b1586] + i * val4 * b;
        system_cos();
        S6 = (V0 * val2) >> c;

        for( int j = 0; j < 14; ++j )
        {
            A0 = h[800b1584] + j * val3;
            system_cos();
            S3 = (V0 * val1) >> c;

            S0 = w[800b1590 + rb * 4] + (i * 14 + j) * 28;

            if( i == 0 )
            {
                [S0 + a] = h(20); // y0
                [S0 + 12] = h(20); // y1
            }
            else if( i == d )
            {
                [S0 + a] = h(S6 + f0); // y0
                [S0 + 12] = h(S6 + f0); // y1

                [S0 + fd02] = h(S6 + f0);
                [S0 + fcfa] = h(S6 + f0);

                A0 = h[800b1586] + (i + 1) * val4 * b;
                system_cos();
                S6 = (V0 * val2) >> c;

                [S0 + 1a] = h(S6 + f0); // y2
                [S0 + 22] = h(S6 + f0); // y3
            }
            else
            {
                [S0 + a] = h(S6 + 20 + i * 10); // y0
                [S0 + 12] = h(S6 + 20 + i * 10); // y1

                [S0 + fd02] = h(S6 + 20 + i * 10);
                [S0 + fcfa] = h(S6 + 20 + i * 10);
            }

            if( j == 0 )
            {
                [S0 + 8] = h(0); // x0
                [S0 + 18] = h(0); // x2
            }
            else
            {
                [S0 + 8] = h(S3 + j * 10); // x0
                [S0 + 18] = h(S3 + j * 10); // x2
                [S0 - 8] = h(S3 + j * 10);
                [S0 - 18] = h(S3 + j * 10);

                if( j == 13 )
                {
                    [S0 + 10] = h(140); // x1
                    [S0 + 20] = h(140); // x3
                }
            }

            A2 = w[800c3740];
            [S0 + 0] = w((w[S0 + 0] & ff000000) | (w[A2 + d0] & 00ffffff));
            [A2 + d0] = w((w[A2 + d0] & ff000000) | (S0 & 00ffffff));
        }
    }

    T1 = A2;
    V0 = w[800acfe0];
    T0 = 800b1588 + V0 * 4;

    for( int i = 0; i < f; ++i )
    {
        A0 = w[T0 + 0] + i * 18;
        [A0 + 18] = w((w[A0 + 18] & ff000000) | (w[T1 + d0] & 00ffffff));
        V0 = w[T0 + 0] + 18 + i * 18;
        [T1 + d0] = w((w[T1 + d0] & ff000000) | (V0 & 00ffffff));
    }

    V0 = w[800acfe0];
    A1 = w[800c3740];
    V1 = 800b12ec + V0 * c0;
    [V1 + 0] = w((w[V1 + 0] & ff000000) | (w[A1 + d0] & 00ffffff));
    [A1 + d0] = w((w[A1 + d0] & ff000000) | (V1 & 00ffffff));
}
////////////////////////////////



////////////////////////////////
// funca4a90

[A0 + 14] = w(A1);
[A0 + 18] = w(A2);
[A0 + 1c] = w(A3);
////////////////////////////////



////////////////////////////////
// funca4aa0

A0 = w[800af354];
system_memory_mark_removed_alloc();

A0 = w[800afb70];
system_memory_mark_removed_alloc();
////////////////////////////////



////////////////////////////////
// funca4ad8()

A2 = 0;
A3 = 800b0748;
A1 = 0;

loopa4ae8:	; 800A4AE8
    V1 = w[800acfe0];
    V1 = V1 + 0001;
    V1 = V1 & 0001;
    V0 = V1 << 02;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = A1 + V0;
    V0 = V0 + A3;
    [V0 + 0004] = b(A0);
    V1 = w[800acfe0];
    V1 = V1 + 1;
    V1 = V1 & 1;
    V0 = V1 << 02;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = A1 + V0;
    V0 = V0 + A3;
    [V0 + 0005] = b(A0);
    V1 = w[800acfe0];
    A2 = A2 + 0001;
    V1 = V1 + 0001;
    V1 = V1 & 0001;
    V0 = V1 << 02;
    V0 = V0 + V1;
    V0 = V0 << 03;
    V0 = A1 + V0;
    V0 = V0 + A3;
    [V0 + 0006] = b(A0);
    V0 = A2 < 0005;
    A1 = A1 + 0050;
800A4B70	bne    v0, zero, loopa4ae8 [$800a4ae8]
////////////////////////////////



////////////////////////////////
// funca4b80()

[800b15d8] = w(0000ff00);
[800b15d4] = w(0000ff00);
[800b15d0] = w(0000ff00);
[800b15dc] = w(-10000 / A0);
[800b15e0] = w(-10000 / A0);
[800b15e4] = w(-10000 / A0);
[800b15e8] = h(1);
[800b15ea] = h(1);
[800b15ec] = h(A0 + 1);
////////////////////////////////



////////////////////////////////
// funca4be8()

[800b15d8] = w(0);
[800b15d4] = w(0);
[800b15d0] = w(0);
[800b15dc] = w(10000 / A0);
[800b15e0] = w(10000 / A0);
[800b15e4] = w(10000 / A0);
[800b15e8] = h(1);
[800b15ea] = h(1);
[800b15ec] = h(A0 + 1);
////////////////////////////////



////////////////////////////////
// funca4c4c()

S0 = A2;
A0 = S0 << 7;

[SP + 10] = h(A0);
[SP + 12] = h(1);
[SP + 14] = h(40);
[SP + 16] = h(S0);

A1 = 1;
system_memory_allocate();
S1 = V0;

A0 = SP + 10;
A1 = S1;
system_store_image();

A0 = 0;
system_draw_sync();

S0 = S0 << 5;

for( int i = 0; i < S0; ++i )
{
    [S1 + i * 20 + 0] = w(w[S1 + i * 20 + 0] | 80008000);
    [S1 + i * 20 + 4] = w(w[S1 + i * 20 + 4] | 80008000);
    [S1 + i * 20 + 8] = w(w[S1 + i * 20 + 8] | 80008000);
    [S1 + i * 20 + c] = w(w[S1 + i * 20 + c] | 80008000);
    [S1 + i * 20 + 10] = w(w[S1 + i * 20 + 10] | 80008000);
    [S1 + i * 20 + 14] = w(w[S1 + i * 20 + 14] | 80008000);
    [S1 + i * 20 + 18] = w(w[S1 + i * 20 + 18] | 80008000);
    [S1 + i * 20 + 1c] = w(w[S1 + i * 20 + 1c] | 80008000);
}

A0 = SP + 10;
A1 = S1;
system_load_image();

A0 = 0;
system_draw_sync();

A0 = S1;
system_memory_mark_removed_alloc();
////////////////////////////////



////////////////////////////////
// funca4d5c()

funca5b14(); // create some sprites

for( int i = 0; i < 2; ++i )
{
    func73670(); // clear otagr

    800A4D7C	jal    funca58e0 [$800a58e0]

    funca5dfc(); // draw otag
}

for( int i = 0; i < 5; ++i )
{
    A0 = 2c0 + i * 40;
    A1 = 100;
    A2 = e0;
    funca4c4c();
}

for( int i = 0; i < 2; ++i )
{
    func73670(); // clear otagr

    800A4DC8	jal    funca58e0 [$800a58e0]

    funca5dfc(); // draw otag
}
////////////////////////////////



////////////////////////////////
// funca4dfc

V0 = w[800ad010];
800A4E14	beq    v0, zero, La50fc [$800a50fc]

system_print_clear_memory();

800A4E24	jal    func70314 [$80070314]
800A4E28	nop
field_particle_store_texture();

V1 = w[800ad010];
V0 = 0001;
800A4E40	beq    v1, v0, La4e50 [$800a4e50]
V0 = 0004;
800A4E48	bne    v1, v0, La4e70 [$800a4e70]
800A4E4C	nop

La4e50:	; 800A4E50
800A4E50	jal    funca3c20 [$800a3c20]
800A4E54	nop
800A4E58	jal    $system_draw_sync
A0 = 0;
800A4E60	jal    func73670 [$80073670]
800A4E64	nop
800A4E68	jal    field_sync [$80076c88]
800A4E6C	nop

La4e70:	; 800A4E70
800A4E70	jal    field_sync [$80076c88]
800A4E74	nop

La4e78:	; 800A4E78
V1 = w[800ad010];
V0 = 0003;
800A4E84	beq    v1, v0, La4ff8 [$800a4ff8]
V0 = V1 < 0004;
800A4E8C	beq    v0, zero, La4ea4 [$800a4ea4]
800A4E90	nop
800A4E94	blez   v1, La50e4 [$800a50e4]
A0 = 0001;
800A4E9C	j      La4f54 [$800a4f54]
800A4EA0	nop

La4ea4:	; 800A4EA4
V0 = 0004;
800A4EA8	bne    v1, v0, La50e4 [$800a50e4]
A0 = 0001;
800A4EB0	jal    funca4d5c [$800a4d5c]
A1 = 0001;
800A4EB8	jal    funca6348 [$800a6348]
S0 = 0;
A0 = w[800ad014];
[800ad0e0] = h(1);
800A4ED4	jal    func714e8 [$800714e8]

V0 = w[800ad014];
[800c2f14] = w(0);
800A4EEC	blez   v0, La4f3c [$800a4f3c]
800A4EF0	nop

loopa4ef4:	; 800A4EF4
800A4EF4	jal    func7743c [$8007743c]
S0 = S0 + 0001;
800A4EFC	jal    funca6118 [$800a6118]

800A4F04	jal    func74bdc [$80074bdc]

800A4F0C	jal    func78170 [$80078170]

V0 = w[800c2f14];
V1 = w[800ad014];
V0 = V0 + 0006;
V1 = S0 < V1;
[800c2f14] = w(V0);
800A4F34	bne    v1, zero, loopa4ef4 [$800a4ef4]

La4f3c:	; 800A4F3C
A0 = 0;
system_draw_sync();

800A4F44	jal    funca653c [$800a653c]

800A4F4C	j      La50e4 [$800a50e4]

La4f54:	; 800A4F54
A1 = 0001;
800A4F54	jal    funca4d5c [$800a4d5c]

A0 = w[800ad014];
V0 = 0001;
[800ad0e0] = h(V0);
800A4F70	jal    func714e8 [$800714e8]
800A4F74	lui    s1, $0080
V0 = w[800ad014];
800A4F80	nop
800A4F84	blez   v0, La50e4 [$800a50e4]
S0 = 0;
800A4F8C	lui    s2, $0080

La4f90:	; 800A4F90
800A4F90	jal    func7743c [$8007743c]
800A4F94	nop
800A4F98	jal    funca58e0 [$800a58e0]
800A4F9C	nop
800A4FA0	jal    func74bdc [$80074bdc]
800A4FA4	nop
800A4FA8	jal    func78170 [$80078170]
800A4FAC	nop
800A4FB0	jal    funca4ad8 [$800a4ad8]
A0 = S1 >> 10;
A0 = w[800ad014];
800A4FC0	nop
800A4FC4	div    s2, a0
800A4FC8	mflo   v0
800A4FCC	nop
S1 = S1 - V0;
800A4FD4	bgez   s1, La4fe0 [$800a4fe0]
800A4FD8	nop
S1 = 0;

La4fe0:	; 800A4FE0
S0 = S0 + 0001;
V0 = S0 < A0;
800A4FE8	beq    v0, zero, La50e4 [$800a50e4]
800A4FEC	nop
800A4FF0	j      La4f90 [$800a4f90]
800A4FF4	nop

La4ff8:	; 800A4FF8
A0 = 0001;
800A4FFC	jal    funca5b14 [$800a5b14]
A1 = 0001;
S0 = 0;
S1 = 02c0;

loopa500c:	; 800A500C
A0 = S1;
A1 = 0100;
800A5014	jal    funca4c4c [$800a4c4c]
A2 = 00e0;
S0 = S0 + 0001;
V0 = S0 < 0005;
800A5024	bne    v0, zero, loopa500c [$800a500c]
S1 = S1 + 0040;
A0 = w[800ad014];
800A5034	jal    func7145c [$8007145c]
S1 = 0;
800A503C	jal    funca4ad8 [$800a4ad8]
A0 = 0;
V0 = w[800ad014];
800A504C	nop
800A5050	blez   v0, La50a4 [$800a50a4]
S0 = 0;
800A5058	lui    s2, $0080

loopa505c:	; 800A505C
800A505C	jal    func7743c [$8007743c]
S0 = S0 + 0001;
800A5064	jal    funca58e0 [$800a58e0]
800A5068	nop
800A506C	jal    func74bdc [$80074bdc]
800A5070	nop
800A5074	jal    func78170 [$80078170]
800A5078	nop
800A507C	jal    funca4ad8 [$800a4ad8]
A0 = S1 >> 10;
V0 = w[800ad014];
800A508C	nop
800A5090	div    s2, v0
800A5094	mflo   a0
V0 = S0 < V0;
800A509C	bne    v0, zero, loopa505c [$800a505c]
S1 = S1 + A0;

La50a4:	; 800A50A4
S0 = 0003;

La50a8:	; 800A50A8
V0 = w[800ad010];
800A50B0	nop
800A50B4	bne    v0, s0, La4e78 [$800a4e78]
800A50B8	nop
800A50BC	jal    func7743c [$8007743c]
800A50C0	nop
800A50C4	jal    funca58e0 [$800a58e0]
800A50C8	nop
800A50CC	jal    func74bdc [$80074bdc]
800A50D0	nop
800A50D4	jal    func78170 [$80078170]
800A50D8	nop
800A50DC	j      La50a8 [$800a50a8]
800A50E0	nop

La50e4:	; 800A50E4
[800ad010] = w(0);

field_particle_load_texture();

800A50F4	jal    func76bd4 [$80076bd4]
800A50F8	nop

La50fc:	; 800A50FC
////////////////////////////////



////////////////////////////////
// funca5118()

system_print_clear_memory();

field_particle_clear_all();

func85b04(); // stops first 8 chanels (4 left, 4 right) if requested

func7f5fc(); // close and clean dialogs

if( w[800af51c] != 6 )
{
    field_particle_store_texture();

    if( w[800af51c] != 4 )
    {
        funca3c20(); // copy some image within vram
    }
}

A0 = 0; // wait for termination
system_draw_sync();

func73670(); // clear otagr.

field_sync();

func6f740(); // clear entity, field data and all other allocated memory



// allocate new place for field
A0 = w[80059b50];
A1 = 0;
system_memory_allocate();
S0 = V0;

A0 = S0; // to here
A1 = w[80059b70]; // from here
A2 = w[80059b50]; // this much
system_memcpy();

A0 = w[80059b70];
system_memory_mark_removable();

A0 = w[80059b70];
system_memory_mark_removed_alloc(); // free field file memory



if( w[800af51c] != 6 )
{
    A0 = 1;
    funca858c();
}



A0 = w[80059b50];
A1 = 1;
system_memory_allocate;
[80059b70] = w(V0);

A0 = V0; // to here
A1 = S0; // from here
A2 = w[80059b50]; // this much
system_memcpy; // copy clut/texture data

A0 = w[80059b70];
system_memory_mark_not_removable();

A0 = S0;
system_memory_mark_removed_alloc();



V1 = w[800af51c];
switch( V1 )
{
    case 0:
    {
        A0 = 0;
        A1 = 0;
        funca5b14(); // create some sprites

        A0 = w[800af1e8];
        800A52FC	jal    func7145c [$8007145c]
        S0 = 0;
        V0 = w[800af1e8];
        800A530C	nop
        800A5310	blez   v0, La5360 [$800a5360]
        S1 = 80d4;

        loopa5318:	; 800A5318
            S0 = S0 + 0001;
            func73670(); // clear otagr

            A0 = w[800c3740];
            A1 = w[800acfe0];
            800A5330	jal    func71344 [$80071344]
            A0 = A0 + S1;
            800A5338	jal    funca58e0 [$800a58e0]
            800A533C	nop
            800A5340	jal    funca5dfc [$800a5dfc]
            800A5344	nop
            V0 = w[800af1e8];
            800A5350	nop
            V0 = S0 < V0;
        800A5358	bne    v0, zero, loopa5318 [$800a5318]

        La5360:	; 800A5360
        func73670(); // clear otagr

        800A5368	jal    funca5dfc [$800a5dfc]
        800A536C	nop
        800A5370	jal    func1aed8 [$8001aed8]
        800A5374	nop
        800A5378	jal    func1b23c [$8001b23c]

        S0 = w[800af51c];
        S1 = w[800af1e8];

        func70358(); // parse field here

        800A5398	jal    func6fb18 [$8006fb18]
        800A539C	nop
        800A53A0	jal    func6fb98 [$8006fb98]
        800A53A4	nop
        V1 = w[8004e9ac];
        800A53B0	addiu  v0, zero, $ffff (=-$1)

        [800af51c] = w(S0);
        [800af1e8] = w(S1);

        800A53C4	bne    v1, v0, La53dc [$800a53dc]
        800A53C8	nop
        A0 = w[8004e9c8];
        800A53D4	jal    func85134 [$80085134]
        A1 = 0;

        La53dc:	; 800A53DC
        A0 = w[800af1e8];
        800A53E4	jal    func714e8 [$800714e8]
        800A53E8	nop
        800A53EC	j      La5878 [$800a5878]
    }
    break;

    case 6:
    {
        A0 = w[800af1e8];
        800A5284	jal    func7145c [$8007145c]
        S0 = 0;
        V0 = w[800af1e8];
        800A5294	nop
        800A5298	blez   v0, La5360 [$800a5360]
        S1 = 80d4;

        La52a0:	; 800A52A0
        S0 = S0 + 0001;
        func73670(); // clear otagr

        A0 = w[800c3740];
        A1 = w[800acfe0];
        800A52B8	jal    func71344 [$80071344]
        A0 = A0 + S1;
        800A52C0	jal    funca5dfc [$800a5dfc]
        800A52C4	nop
        V0 = w[800af1e8];
        800A52D0	nop
        V0 = S0 < V0;
        800A52D8	beq    v0, zero, La5360 [$800a5360]
        800A52DC	nop
        800A52E0	j      La52a0 [$800a52a0]
        800A52E4	nop
    }
    break;

    case 1:
    {
        A0 = 0;
        800A53F8	jal    funca5b14 [$800a5b14]
        A1 = 0;
        A0 = w[800af1e8];
        800A5408	jal    funca4be8 [$800a4be8]
        S0 = 0;
        V0 = w[800af1e8];
        800A5418	nop
        800A541C	blez   v0, La546c [$800a546c]
        S1 = 80d4;

        loopa5424:	; 800A5424
        S0 = S0 + 0001;
        func73670(); // clear otagr

        A0 = w[800c3740];
        A1 = w[800acfe0];
        800A543C	jal    func71344 [$80071344]
        A0 = A0 + S1;
        800A5444	jal    funca58e0 [$800a58e0]
        800A5448	nop
        800A544C	jal    funca5dfc [$800a5dfc]
        800A5450	nop
        V0 = w[800af1e8];
        800A545C	nop
        V0 = S0 < V0;
        800A5464	bne    v0, zero, loopa5424 [$800a5424]
        800A5468	nop

        La546c:	; 800A546C
        field_sync();

        800A5474	jal    func1aed8 [$8001aed8]
        800A5478	nop
        800A547C	jal    func1b23c [$8001b23c]
        800A5480	nop
        S0 = w[800af51c];
        S1 = w[800af1e8];
        800A5494	jal    func70358 [$80070358]
        800A5498	nop
        800A549C	jal    func6fb18 [$8006fb18]
        800A54A0	nop
        800A54A4	jal    func6fb98 [$8006fb98]
        800A54A8	nop
        V1 = w[8004e9ac];
        800A54B4	addiu  v0, zero, $ffff (=-$1)
        [800af51c] = w(S0);
        [800af1e8] = w(S1);
        800A54C8	bne    v1, v0, La54e0 [$800a54e0]
        800A54CC	nop
        A0 = w[8004e9c8];
        800A54D8	jal    func85134 [$80085134]
        A1 = 0;

        La54e0:	; 800A54E0
        A0 = w[800af1e8];
        800A54E8	jal    funca4b80 [$800a4b80]
        800A54EC	nop
        800A54F0	j      La5878 [$800a5878]
        800A54F4	nop
    }
    break;

    case 2:
    case 4:
    {
        A0 = 0001;
        800A54FC	jal    funca4d5c [$800a4d5c]
        A1 = 0001;
        800A5504	jal    func1aed8 [$8001aed8]
        800A5508	nop
        800A550C	jal    func1b23c [$8001b23c]
        800A5510	nop
        S0 = w[800af51c];
        S1 = w[800af1e8];
        800A5524	jal    func70358 [$80070358]
        800A5528	nop
        800A552C	jal    func6fb18 [$8006fb18]
        800A5530	nop
        V1 = w[800ad038];
        V0 = 0001;
        800A5540	bne    v1, v0, La55b8 [$800a55b8]
        800A5544	nop

        loopa5548:	; 800A5548
        system_cdrom_data_sync(); // wait for command to finish

        800A5550	beq    v0, zero, La5598 [$800a5598]

        func73670(); // clear otagr

        800A5560	jal    funca58e0 [$800a58e0]
        800A5564	nop
        800A5568	jal    funca5dfc [$800a5dfc]
        800A556C	nop
        V1 = w[800c1b58];
        800A5578	nop
        V0 = V1 < 22c0;
        800A5580	beq    v0, zero, loopa5548 [$800a5548]
        V0 = V1 + 0020;
        [800c1b58] = w(V0);
        800A5590	j      loopa5548 [$800a5548]
        800A5594	nop

        La5598:	; 800A5598
        A0 = w[800ad0ec];
        system_memory_mark_removed_alloc();

        [800ad038] = w(0);
        800A55B0	jal    func78270 [$80078270]
        800A55B4	nop

        La55b8:	; 800A55B8
        V1 = w[8004e9ac];
        V0 = 0001;
        [800af1d8] = w(V0);
        800A55CC	addiu  v0, zero, $ffff (=-$1)
        [800af51c] = w(S0);
        [800af1e8] = w(S1);
        800A55E0	bne    v1, v0, La55f8 [$800a55f8]
        800A55E4	nop
        A0 = w[8004e9c8];
        800A55F0	jal    func85134 [$80085134]
        A1 = 0;

        La55f8:	; 800A55F8
        A0 = w[800af1e8];
        800A5600	jal    func714e8 [$800714e8]
        800A5604	lui    s1, $0080
        V0 = w[800af1e8];
        800A5610	nop
        800A5614	blez   v0, La5878 [$800a5878]
        S0 = 0;
        800A561C	lui    s2, $0080

        La5620:	; 800A5620
        800A5620	jal    func7743c [$8007743c]
        800A5624	nop
        800A5628	jal    funca58e0 [$800a58e0]
        800A562C	nop
        800A5630	jal    func74bdc [$80074bdc]
        800A5634	nop
        800A5638	jal    func78170 [$80078170]
        800A563C	nop
        800A5640	jal    funca4ad8 [$800a4ad8]
        A0 = S1 >> 10;
        A0 = w[800af1e8];
        800A5650	nop
        800A5654	div    s2, a0
        800A5658	mflo   v0
        800A565C	nop
        S1 = S1 - V0;
        800A5664	bgez   s1, La5670 [$800a5670]
        800A5668	nop
        S1 = 0;

        La5670:	; 800A5670
        V1 = w[800c1b58];
        800A5678	nop
        V0 = V1 < 22c0;
        800A5680	beq    v0, zero, La5690 [$800a5690]
        V0 = V1 + 0020;
        [800c1b58] = w(V0);

        La5690:	; 800A5690
        S0 = S0 + 0001;
        V0 = S0 < A0;
        800A5698	beq    v0, zero, La5878 [$800a5878]
        800A569C	nop
        800A56A0	j      La5620 [$800a5620]
        800A56A4	nop
    }
    break;

    case 3:
    {
        A0 = 0;
        800A56AC	jal    funca5b14 [$800a5b14]
        A1 = 0;
        800A56B4	jal    func6fb18 [$8006fb18]

        func73670(); // clear otagr

        800A56C4	jal    funca58e0 [$800a58e0]
        800A56C8	nop
        800A56CC	jal    funca5dfc [$800a5dfc]
        800A56D0	nop
        800A56D4	jal    func1aed8 [$8001aed8]
        800A56D8	nop
        800A56DC	jal    func1b23c [$8001b23c]
        800A56E0	nop
        S0 = w[800af51c];
        S1 = w[800af1e8];
        V0 = 0001;
        [800af1d8] = w(V0);
        800A5700	jal    func70358 [$80070358]
        800A5704	nop
        800A5708	jal    func6fb98 [$8006fb98]
        800A570C	nop
        V1 = w[8004e9ac];
        800A5718	addiu  v0, zero, $ffff (=-$1)
        [800af51c] = w(S0);
        [800af1e8] = w(S1);
        800A572C	bne    v1, v0, La5748 [$800a5748]
        S0 = 0;
        A0 = w[8004e9c8];
        800A573C	jal    func85134 [$80085134]
        A1 = 0;
        S0 = 0;

        La5748:	; 800A5748
        800A5748	jal    func7743c [$8007743c]
        S0 = S0 + 0001;
        800A5750	jal    funca58e0 [$800a58e0]
        800A5754	nop
        800A5758	jal    func74bdc [$80074bdc]
        800A575C	nop
        800A5760	jal    func78170 [$80078170]
        800A5764	nop
        V0 = S0 < 0004;
        800A576C	beq    v0, zero, La5878 [$800a5878]
        800A5770	nop
        800A5774	j      La5748 [$800a5748]
        800A5778	nop
    }
    break;

    case 5:
    {
        A0 = 0;
        800A5780	jal    funca5b14 [$800a5b14]
        A1 = 0;
        800A5788	jal    func6fb18 [$8006fb18]

        func73670(); // clear otagr

        800A5798	jal    funca58e0 [$800a58e0]
        800A579C	nop
        800A57A0	jal    funca5dfc [$800a5dfc]
        800A57A4	nop
        800A57A8	jal    func1aed8 [$8001aed8]
        800A57AC	nop
        800A57B0	jal    func1b23c [$8001b23c]
        800A57B4	nop
        S0 = w[800af51c];
        S1 = w[800af1e8];
        V0 = 0001;
        [800af1d8] = w(V0);
        800A57D4	jal    func70358 [$80070358]
        800A57D8	nop
        800A57DC	jal    func6fb98 [$8006fb98]

        V0 = 02c0;
        [SP + 0010] = h(V0);
        V0 = 0100;
        [SP + 0012] = h(V0);
        V0 = 0140;
        [SP + 0014] = h(V0);
        V0 = 00ff;
        [SP + 0016] = h(V0);
        [800af51c] = w(S0);
        [800af1e8] = w(S1);

        A0 = SP + 10;
        A1 = 140; // dest x
        A2 = ff; // dest y
        system_move_image();

        V1 = w[8004e9ac];
        800A582C	addiu  v0, zero, $ffff (=-$1)
        800A5830	bne    v1, v0, La584c [$800a584c]
        S0 = 0;
        A0 = w[8004e9c8];
        800A5840	jal    func85134 [$80085134]
        A1 = 0;
        S0 = 0;

        La584c:	; 800A584C
        800A584C	jal    func7743c [$8007743c]
        S0 = S0 + 0001;
        800A5854	jal    funca58e0 [$800a58e0]
        800A5858	nop
        800A585C	jal    func74bdc [$80074bdc]
        800A5860	nop
        800A5864	jal    func78170 [$80078170]
        800A5868	nop
        V0 = S0 < 0004;
        800A5870	bne    v0, zero, La584c [$800a584c]
        800A5874	nop

    }
    break;
}

La5878:	; 800A5878
if( w[800af51c] != 6 )
{
    field_particle_load_texture();
}

[800af51c] = w(2);
[800af1e8] = w(20);
[800af1d8] = w(0);

800A58B4	jal    func76bd4 [$80076bd4]

system_memory_clean_removed_alloc();
////////////////////////////////



////////////////////////////////
// funca58e0()

A0 = 800af58c;
A1 = SP + 0028;
system_calculate_rotation_matrix();

[SP + 3c] = w(0);
[SP + 40] = w(0);
[SP + 44] = w(0);
[SP + 48] = w(w[800c1b58]);
[SP + 4c] = w(w[800c1b58]);
[SP + 50] = w(w[800c1b58]);

A0 = SP + 28;
A1 = SP + 48;
system_gte_multiply_matrix_by_vector();

A0 = SP + 28;
system_gte_set_rotation_matrix();

A0 = SP + 28;
system_gte_set_translation_vector();

for( int i = 0; i < 5; ++i )
{
    if( w[800c1b58] != 1000 )
    {
        A0 = 800b08d8 + i * 20 +  0; // xyz0
        A1 = 800b08d8 + i * 20 +  8; // xyz1
        A2 = 800b08d8 + i * 20 + 10; // xyz3
        A3 = 800b08d8 + i * 20 + 18; // xyz2
        A4 = 800b08d8 - 190 + i * 50 + w[800acfe0] * 28 +  8; // xy0
        A5 = 800b08d8 - 190 + i * 50 + w[800acfe0] * 28 + 10; // xy1
        A6 = 800b08d8 - 190 + i * 50 + w[800acfe0] * 28 + 18; // xy3
        A7 = 800b08d8 - 190 + i * 50 + w[800acfe0] * 28 + 20; // xy2
        A8 = SP + 58; // Interpolation value for depth queing. (not used)
        A9 = SP + 5c; // return flags (not used)
        func4a664(); // transform 4 points by rotation matrix
    }

    A2 = w[800acfe0];
    A3 = w[800c3740];
    A0 = A2 * 28;
    A1 = i * 50 + A0;
    A1 = A1 + 800b08d8 - 190;
    A0 = A0 + 800b08d8 - 190;
    A0 = i * 50 + A0;
    A0 = A0 & 00ffffff;
    V1 = w[A1 + 0000];
    V0 = w[000180d4 + A3];
    [A1 + 0000] = w((V1 & ff000000) | (V0 & 00ffffff));
    V1 = A2 << 01;
    V1 = V1 + A2;
    A1 = w[000180d4 + A3];
    V1 = V1 << 02;
    A1 = (A1 & ff000000) | A0;
    [000180d4 + A3] = w(A1);
    [800b08d8 + i * 18 + V1 - 258 + 0000] = w((w[800b08d8 + i * 18 + V1 - 258 + 0000] & ff000000) | (A1 & 00ffffff));
    [000180d4 + A3] = w((w[000180d4 + A3] & ff000000) | ((800b08d8 + i * 18 + V1 - 258) & 00ffffff));
}
////////////////////////////////



////////////////////////////////
// funca5b14()

V1 = 800b0748;
800A5B28	addiu  v1, v1, $ff44 (=-$bc)
S5 = 02c0;
FP = 0040;
800A5B40	addiu  s7, zero, $ffd0 (=-$30)
800A5B48	addiu  s6, zero, $ffb0 (=-$50)
S3 = 800b0748;
V0 = 1000;
[SP + 0018] = w(A0);
[SP + 0020] = w(A1);
[SP + 0028] = w(V1);
[SP + 0030] = w(0);
[SP + 0038] = w(0);
[800c1b58] = w(V0);
[800af58c] = h(0);
[800af58e] = h(0);
[800af590] = h(0);

S4 = 0;
La5ba0:	; 800A5BA0
    A0 = S3;
    V1 = 800b0748;
    S2 = V1 + 0028;
    V1 = w[SP + 0038];
    S0 = S4 << 05;
    S2 = V1 + S2;
    V1 = 800b0748;
    V0 = V1 + 0190;
    S0 = S0 + V0;
    [A0 + 3] = b(9);
    [A0 + 7] = b(2c);

    A0 = 0002;
    A2 = S5;
    A3 = 0100;
    A1 = w[SP + 0020];
    800A5BE0	addiu  v1, zero, $ffc8 (=-$38)
    [S0 + 0002] = h(V1);
    V0 = 0038;
    [S0 + 0012] = h(V0);
    [S0 + 001a] = h(V0);
    V0 = S4 << 06;
    [S0 + 0000] = h(S6);
    [S0 + 0004] = h(0);
    [S0 + 0008] = h(S7);
    [S0 + 000a] = h(V1);
    [S0 + 000c] = h(0);
    [S0 + 0010] = h(S6);
    [S0 + 0014] = h(0);
    [S0 + 0018] = h(S7);
    [S0 + 001c] = h(0);
    V1 = 00df;
    [S3 + 001a] = h(V1);
    [S3 + 0022] = h(V1);
    V1 = 800b0748;
    800A5C30	addiu  s0, v1, $ffb0 (=-$50)
    S1 = S4 << 04;
    S0 = S1 + S0;
    [S3 + 0008] = h(V0);
    [S3 + 000a] = h(0);
    [S3 + 0010] = h(FP);
    [S3 + 0012] = h(0);
    [S3 + 0018] = h(V0);
    [S3 + 0020] = h(FP);
    V1 = 00ff;
    [S0 + 0004] = h(V1);
    [S0 + 0006] = h(V1);
    V1 = 800b0748;
    800A5C68	addiu  v0, v1, $ffb8 (=-$48)
    S1 = S1 + V0;
    [S0 + 0000] = h(0);
    [S0 + 0002] = h(0);
    V1 = 00ff;
    [S1 + 0004] = h(V1);
    [S1 + 0000] = h(0);
    [S1 + 0002] = h(0);
    [S1 + 0006] = h(V1);
    system_graphic_get_texpage_by_param();

    V1 = 800b0748;
    800A5C98	addiu  a0, v1, $ff38 (=-$c8)
    A1 = 0;
    A2 = 0;
    V1 = w[SP + 0030];
    A3 = V0 & ffff;
    [SP + 0010] = w(S0);
    A0 = V1 + A0;
    system_gpu_create_texture_setting_packet();

    A0 = 0002;
    A2 = S5;
    A1 = w[SP + 0020];
    A3 = 0100;
    system_graphic_get_texpage_by_param();

    A1 = 0;
    A2 = 0;
    A0 = w[SP + 0028];
    A3 = V0 & ffff;
    [SP + 0010] = w(S1);
    system_gpu_create_texture_setting_packet();

    A0 = S3;
    A1 = w[SP + 0018];
    V0 = 0080;
    [S3 + 0004] = b(V0);
    [S3 + 0005] = b(V0);
    [S3 + 0006] = b(V0);
    system_set_draw_packet_transparency();

    A0 = 0002;
    A2 = S5;
    A3 = 0100;
    V0 = 0040;
    A1 = w[SP + 0020];
    V1 = 00df;
    [S3 + 001d] = b(V1);
    [S3 + 000c] = b(0);
    [S3 + 000d] = b(0);
    [S3 + 0014] = b(V0);
    [S3 + 0015] = b(0);
    [S3 + 001c] = b(0);
    [S3 + 0024] = b(V0);
    [S3 + 0025] = b(V1);
    system_graphic_get_texpage_by_param();

    A2 = S3;
    A3 = S3 + 0020;
    [S3 + 0016] = h(V0);

    loopa5d48:	; 800A5D48
        V0 = w[A2 + 0000];
        V1 = w[A2 + 0004];
        A0 = w[A2 + 0008];
        A1 = w[A2 + 000c];
        [S2 + 0000] = w(V0);
        [S2 + 0004] = w(V1);
        [S2 + 0008] = w(A0);
        [S2 + 000c] = w(A1);
        S2 = S2 + 0010;
        A2 = A2 + 0010;
    800A5D6C	bne    a2, a3, loopa5d48 [$800a5d48]

    V0 = w[A2 + 0000];
    V1 = w[A2 + 0004];
    [S2 + 0000] = w(V0);
    [S2 + 0004] = w(V1);
    S5 = S5 + 0040;
    FP = FP + 0040;
    S7 = S7 + 0020;
    S6 = S6 + 0020;
    V1 = w[SP + 0028];
    S3 = S3 + 0050;
    V1 = V1 + 0018;
    [SP + 0028] = w(V1);
    V1 = w[SP + 0030];
    V1 = V1 + 0018;
    [SP + 0030] = w(V1);
    V1 = w[SP + 0038];
    V1 = V1 + 0050;
    [SP + 0038] = w(V1);
    S4 = S4 + 1;
    V0 = S4 < 5;
800A5DC0	bne    v0, zero, La5ba0 [$800a5ba0]
////////////////////////////////



////////////////////////////////
// funca5dfc()

A0 = 0;
system_draw_sync();

A0 = 2;
system_psyq_wait_frames();

A0 = w[800c3740];
A1 = 0;
A2 = 0;
A3 = 0;
system_clear_image();

A0 = w[800c3740];
system_psyq_put_draw_env();

A0 = w[800c3740];
A0 = A0 + 00b8;
system_psyq_put_disp_env();

A0 = w[800c3740] + 80f0;
system_psyq_draw_otag();
////////////////////////////////



////////////////////////////////
// funca5e70
800A5E70	addiu  sp, sp, $ffc0 (=-$40)
[SP + 0034] = w(S1);
S1 = A0;
[SP + 0038] = w(S2);
S2 = A2;
[SP + 0030] = w(S0);
S0 = A3;
V1 = 00a0;
A2 = 0070;
V0 = 0001;
[SP + 003c] = w(RA);
800A5E9C	beq    a1, v0, La5f64 [$800a5f64]
[SP + 0018] = w(0);
V0 = A1 < 0002;
800A5EA8	beq    v0, zero, La5ec0 [$800a5ec0]
800A5EAC	nop
800A5EB0	beq    a1, zero, La5edc [$800a5edc]
A0 = SP + 0010;
800A5EB8	j      La60fc [$800a60fc]
800A5EBC	nop

La5ec0:	; 800A5EC0
V0 = 0002;
800A5EC4	beq    a1, v0, La5fec [$800a5fec]
V0 = 0003;
800A5ECC	beq    a1, v0, La6074 [$800a6074]
A0 = SP + 0010;
800A5ED4	j      La60fc [$800a60fc]
800A5ED8	nop

La5edc:	; 800A5EDC
V0 = h[S1 + 0008];
800A5EE0	nop
V0 = V1 - V0;
[SP + 0010] = w(V0);
V0 = h[S1 + 000a];
A1 = SP + 0020;
V0 = A2 - V0;
800A5EF8	jal    $8004a2bc
[SP + 0014] = w(V0);
V0 = w[SP + 0020];
A0 = w[SP + 0024];
800A5F08	jal    $80048af4
A0 = V0 + A0;
V0 = V0 >> 01;
V0 = V0 < S2;
800A5F18	beq    v0, zero, La60fc [$800a60fc]
800A5F1C	nop
V0 = hu[S0 + 0000];
800A5F24	nop
800A5F28	addiu  v0, v0, $fffa (=-$6)
[S0 + 0000] = h(V0);
V0 = V0 << 10;
800A5F34	bgez   v0, La5f40 [$800a5f40]
800A5F38	nop
[S0 + 0000] = h(0);

La5f40:	; 800A5F40
V0 = hu[S0 + 0000];
800A5F44	nop
[S1 + 0004] = b(V0);
V0 = hu[S0 + 0000];
800A5F50	nop
[S1 + 0005] = b(V0);
V0 = hu[S0 + 0000];
800A5F5C	j      La60fc [$800a60fc]
[S1 + 0006] = b(V0);

La5f64:	; 800A5F64
V0 = h[S1 + 0014];
A0 = SP + 0010;
V0 = V1 - V0;
[SP + 0010] = w(V0);
V0 = h[S1 + 0016];
A1 = SP + 0020;
V0 = A2 - V0;
800A5F80	jal    $8004a2bc
[SP + 0014] = w(V0);
V0 = w[SP + 0020];
A0 = w[SP + 0024];
800A5F90	jal    $80048af4
A0 = V0 + A0;
V0 = V0 >> 01;
V0 = V0 < S2;
800A5FA0	beq    v0, zero, La60fc [$800a60fc]
800A5FA4	nop
V0 = hu[S0 + 0000];
800A5FAC	nop
800A5FB0	addiu  v0, v0, $fffa (=-$6)
[S0 + 0000] = h(V0);
V0 = V0 << 10;
800A5FBC	bgez   v0, La5fc8 [$800a5fc8]
800A5FC0	nop
[S0 + 0000] = h(0);

La5fc8:	; 800A5FC8
V0 = hu[S0 + 0000];
800A5FCC	nop
[S1 + 0010] = b(V0);
V0 = hu[S0 + 0000];
800A5FD8	nop
[S1 + 0011] = b(V0);
V0 = hu[S0 + 0000];
800A5FE4	j      La60fc [$800a60fc]
[S1 + 0012] = b(V0);

La5fec:	; 800A5FEC
V0 = h[S1 + 0020];
A0 = SP + 0010;
V0 = V1 - V0;
[SP + 0010] = w(V0);
V0 = h[S1 + 0022];
A1 = SP + 0020;
V0 = A2 - V0;
800A6008	jal    $8004a2bc
[SP + 0014] = w(V0);
V0 = w[SP + 0020];
A0 = w[SP + 0024];
800A6018	jal    $80048af4
A0 = V0 + A0;
V0 = V0 >> 01;
V0 = V0 < S2;
800A6028	beq    v0, zero, La60fc [$800a60fc]
800A602C	nop
V0 = hu[S0 + 0000];
800A6034	nop
800A6038	addiu  v0, v0, $fffa (=-$6)
[S0 + 0000] = h(V0);
V0 = V0 << 10;
800A6044	bgez   v0, La6050 [$800a6050]
800A6048	nop
[S0 + 0000] = h(0);

La6050:	; 800A6050
V0 = hu[S0 + 0000];
800A6054	nop
[S1 + 001c] = b(V0);
V0 = hu[S0 + 0000];
800A6060	nop
[S1 + 001d] = b(V0);
V0 = hu[S0 + 0000];
800A606C	j      La60fc [$800a60fc]
[S1 + 001e] = b(V0);

La6074:	; 800A6074
V0 = h[S1 + 002c];
800A6078	nop
V0 = V1 - V0;
[SP + 0010] = w(V0);
V0 = h[S1 + 002e];
A1 = SP + 0020;
V0 = A2 - V0;
800A6090	jal    $8004a2bc
[SP + 0014] = w(V0);
V0 = w[SP + 0020];
A0 = w[SP + 0024];
800A60A0	jal    $80048af4
A0 = V0 + A0;
V0 = V0 >> 01;
V0 = V0 < S2;
800A60B0	beq    v0, zero, La60fc [$800a60fc]
800A60B4	nop
V0 = hu[S0 + 0000];
800A60BC	nop
800A60C0	addiu  v0, v0, $fffa (=-$6)
[S0 + 0000] = h(V0);
V0 = V0 << 10;
800A60CC	bgez   v0, La60d8 [$800a60d8]
800A60D0	nop
[S0 + 0000] = h(0);

La60d8:	; 800A60D8
V0 = hu[S0 + 0000];
800A60DC	nop
[S1 + 0028] = b(V0);
V0 = hu[S0 + 0000];
800A60E8	nop
[S1 + 0029] = b(V0);
V0 = hu[S0 + 0000];
800A60F4	nop
[S1 + 002a] = b(V0);

La60fc:	; 800A60FC
RA = w[SP + 003c];
S2 = w[SP + 0038];
S1 = w[SP + 0034];
S0 = w[SP + 0030];
SP = SP + 0040;
800A6110	jr     ra 
800A6114	nop
////////////////////////////////
// funca6118
800A6118	addiu  sp, sp, $ffc8 (=-$38)
[SP + 0028] = w(S6);
S6 = 0;
[SP + 0020] = w(S4);
S4 = ffffff;
[SP + 002c] = w(S7);
800A6134	lui    s7, $ff00
[SP + 0024] = w(S5);
S5 = 0;
[SP + 0030] = w(RA);
[SP + 001c] = w(S3);
[SP + 0018] = w(S2);
[SP + 0014] = w(S1);
[SP + 0010] = w(S0);

loopa6154:	; 800A6154
S3 = 0;
A1 = 0;

loopa615c:	; 800A615C
V0 = w[800acfe0];
A2 = w[800c2f14];
V1 = w[800af598];
S0 = V0 << 03;
S0 = S0 - V0;
V0 = S0 << 06;
S0 = S0 + V0;
S0 = S0 << 05;
S0 = V1 + S0;
V0 = S5 + S3;
S2 = V0 << 01;
S1 = S2 + V0;
S1 = S1 << 02;
S1 = S1 + V0;
S1 = S1 << 02;
S0 = S0 + S1;
A0 = S0;
A3 = S2 + 71c0;
800A61B0	jal    funca5e70 [$800a5e70]
A3 = V1 + A3;
A0 = S0;
A1 = 0001;
A3 = S2 + 73f0;
V0 = w[800af598];
A2 = w[800c2f14];
800A61D4	jal    funca5e70 [$800a5e70]
A3 = V0 + A3;
A0 = S0;
A1 = 0002;
A3 = S2 + 7620;
V0 = w[800af598];
A2 = w[800c2f14];
800A61F8	jal    funca5e70 [$800a5e70]
A3 = V0 + A3;
A0 = S0;
A1 = 0003;
S2 = S2 + 7850;
A3 = w[800af598];
A2 = w[800c2f14];
800A621C	jal    funca5e70 [$800a5e70]
A3 = A3 + S2;
S3 = S3 + 0001;
A2 = w[800acfe0];
A3 = w[800c3740];
V0 = A2 << 03;
V0 = V0 - A2;
V1 = V0 << 06;
V0 = V0 + V1;
V1 = w[800af598];
V0 = V0 << 05;
V0 = V0 + V1;
S1 = S1 + V0;
V0 = w[S1 + 0000];
800A6260	lui    at, $0001
AT = A3 + AT;
V1 = w[AT + 80d4];
V0 = V0 & S7;
V1 = V1 & S4;
V0 = V0 | V1;
[S1 + 0000] = w(V0);
S1 = S1 & S4;
800A6280	lui    at, $0001
AT = A3 + AT;
A0 = w[AT + 80d4];
V0 = S3 < 0014;
A0 = A0 & S7;
A0 = A0 | S1;
800A6298	lui    at, $0001
AT = A3 + AT;
[AT + 80d4] = w(A0);
800A62A4	bne    v0, zero, loopa615c [$800a615c]
A1 = 0;
S6 = S6 + 0001;
V0 = S6 < 000e;
800A62B4	bne    v0, zero, loopa6154 [$800a6154]
S5 = S5 + 0014;
A1 = ffffff;
V0 = 800b12f8;
V1 = A2 << 01;
V1 = V1 + A2;
V1 = V1 << 06;
V1 = V1 + V0;
800A62DC	lui    a2, $ff00
V0 = w[V1 + 0000];
A0 = A0 & A1;
V0 = V0 & A2;
V0 = V0 | A0;
[V1 + 0000] = w(V0);
800A62F4	lui    at, $0001
AT = A3 + AT;
V0 = w[AT + 80d4];
V1 = V1 & A1;
V0 = V0 & A2;
V0 = V0 | V1;
800A630C	lui    at, $0001
AT = A3 + AT;
[AT + 80d4] = w(V0);
RA = w[SP + 0030];
S7 = w[SP + 002c];
S6 = w[SP + 0028];
S5 = w[SP + 0024];
S4 = w[SP + 0020];
S3 = w[SP + 001c];
S2 = w[SP + 0018];
S1 = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0038;
800A6340	jr     ra 
800A6344	nop
////////////////////////////////
// funca6348
800A6348	addiu  sp, sp, $ffc8 (=-$38)
A0 = 7a80;
A1 = 0001;
[SP + 0034] = w(RA);
[SP + 0030] = w(FP);
[SP + 002c] = w(S7);
[SP + 0028] = w(S6);
[SP + 0024] = w(S5);
[SP + 0020] = w(S4);
[SP + 001c] = w(S3);
[SP + 0018] = w(S2);
[SP + 0014] = w(S1);
800A6378	jal    $system_memory_allocate
[SP + 0010] = w(S0);
S6 = 0;
S1 = 0080;
S3 = 0010;
S7 = 0;
[800af598] = w(V0);

loopa6398:	; 800A6398
S2 = 0;
S5 = S6 << 04;
S4 = 0010;

loopa63a4:	; 800A63A4
V1 = S7 + S2;
A1 = V1 << 01;
V0 = A1 + V1;
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[800af598];
V0 = V0 << 02;
S0 = V1 + V0;
A0 = S0;
A1 = A1 + V1;
V0 = V0 + 38e0;
FP = V1 + V0;
[A1 + 71c0] = h(S1);
[A1 + 73f0] = h(S1);
[A1 + 7620] = h(S1);
800A63E4	jal    $80043b50
[A1 + 7850] = h(S1);
A2 = S2;
V0 = S2 << 04;
[S0 + 0008] = h(V0);
[S0 + 0020] = h(V0);
V0 = V0 & 003f;
V1 = V0 + 0010;
[S0 + 0004] = b(S1);
[S0 + 0005] = b(S1);
[S0 + 0006] = b(S1);
[S0 + 0010] = b(S1);
[S0 + 0011] = b(S1);
[S0 + 0012] = b(S1);
[S0 + 001c] = b(S1);
[S0 + 001d] = b(S1);
[S0 + 001e] = b(S1);
[S0 + 0028] = b(S1);
[S0 + 0029] = b(S1);
[S0 + 002a] = b(S1);
[S0 + 000a] = h(S5);
[S0 + 0014] = h(S4);
[S0 + 0016] = h(S5);
[S0 + 0022] = h(S3);
[S0 + 002c] = h(S4);
[S0 + 002e] = h(S3);
[S0 + 000c] = b(V0);
[S0 + 000d] = b(S5);
[S0 + 0018] = b(V1);
[S0 + 0019] = b(S5);
[S0 + 0024] = b(V0);
[S0 + 0025] = b(S3);
[S0 + 0030] = b(V1);
800A6468	bgez   s2, La6474 [$800a6474]
[S0 + 0031] = b(S3);
A2 = S2 + 0003;

La6474:	; 800A6474
A0 = 0002;
A1 = 0001;
A2 = A2 >> 02;
A2 = A2 << 06;
A2 = A2 + 02c0;
800A6488	jal    $system_graphic_get_texpage_by_param
A3 = 0100;
[S0 + 001a] = h(V0);
A0 = S0;
800A6498	jal    $system_set_draw_packet_transparency
A1 = 0001;
A3 = FP;
A2 = S0;
T0 = A2 + 0030;

loopa64ac:	; 800A64AC
V0 = w[A2 + 0000];
V1 = w[A2 + 0004];
A0 = w[A2 + 0008];
A1 = w[A2 + 000c];
[A3 + 0000] = w(V0);
[A3 + 0004] = w(V1);
[A3 + 0008] = w(A0);
[A3 + 000c] = w(A1);
A2 = A2 + 0010;
800A64D0	bne    a2, t0, loopa64ac [$800a64ac]
A3 = A3 + 0010;
V0 = w[A2 + 0000];
800A64DC	nop
[A3 + 0000] = w(V0);
S2 = S2 + 0001;
V0 = S2 < 0014;
800A64EC	bne    v0, zero, loopa63a4 [$800a63a4]
S4 = S4 + 0010;
S3 = S3 + 0010;
S6 = S6 + 0001;
V0 = S6 < 000e;
800A6500	bne    v0, zero, loopa6398 [$800a6398]
S7 = S7 + 0014;
RA = w[SP + 0034];
FP = w[SP + 0030];
S7 = w[SP + 002c];
S6 = w[SP + 0028];
S5 = w[SP + 0024];
S4 = w[SP + 0020];
S3 = w[SP + 001c];
S2 = w[SP + 0018];
S1 = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0038;
800A6534	jr     ra 
800A6538	nop
////////////////////////////////
// funca653c
A0 = w[800af598];
800A6544	addiu  sp, sp, $ffe8 (=-$18)
[SP + 0010] = w(RA);
800A654C	jal    $system_memory_mark_removed_alloc
800A6550	nop
RA = w[SP + 0010];
SP = SP + 0018;
800A655C	jr     ra 
800A6560	nop
////////////////////////////////
// funca6564
800A6564	addiu  sp, sp, $ffd8 (=-$28)
A0 = 0004;
[SP + 0020] = w(RA);
800A6570	jal    $system_memory_set_alloc_user
A1 = 0;
V1 = w[800ad04c];
V0 = 0002;
800A6584	bne    v1, v0, La659c [$800a659c]
V0 = 0001;
[801d68b4] = w(V0);
800A6594	j      La65a8 [$800a65a8]
A0 = 0140;

La659c:	; 800A659C
[801d68b4] = w(0);
A0 = 0140;

La65a8:	; 800A65A8
A1 = 00e0;
V0 = 0020;
[SP + 0010] = w(V0);
V0 = 0800;
A2 = 0080;
V1 = hu[800c2f0a];
A3 = 0010;
[SP + 0014] = w(V0);
800A65CC	jal    $801d3538
[SP + 0018] = w(V1);
A0 = 0008;
[800ad044] = w(0);
800A65E0	jal    $system_memory_set_alloc_user
A1 = 0;
RA = w[SP + 0020];
SP = SP + 0028;
800A65F0	jr     ra 
800A65F4	nop
////////////////////////////////
// funca65f8
800A65F8	addiu  sp, sp, $ffe8 (=-$18)
A0 = A0 & ffff;
A2 = A2 & ffff;
[SP + 0010] = w(RA);
[800afb74] = w(A0);
[800af5b8] = w(0);
800A6618	bne    a2, zero, La6630 [$800a6630]
V0 = 0001;
[800ad050] = w(V0);
800A6628	j      La6638 [$800a6638]
800A662C	nop

La6630:	; 800A6630
[800ad050] = w(0);

La6638:	; 800A6638
V0 = w[800ad04c];
800A6640	nop
800A6644	bne    v0, zero, La66e0 [$800a66e0]
800A6648	nop
V0 = w[800af348];
800A6654	nop
800A6658	bne    v0, zero, La66e0 [$800a66e0]
800A665C	nop
800A6660	jal    $system_draw_sync
A0 = 0;
A0 = w[800ad050];
V1 = 800b1970;
V0 = A0 << 07;
V0 = V0 + A0;
V0 = V0 << 04;
V0 = V0 - A0;
V0 = V0 << 02;
V0 = V0 + A0;
V0 = V0 << 02;
V0 = V0 + V1;
V1 = h[800c2f0a];
[800c3740] = w(V0);
V0 = 0001;
800A66AC	bne    v1, v0, La66e0 [$800a66e0]
V0 = A0 & 0001;
V1 = V0 << 07;
V1 = V1 + V0;
V1 = V1 << 04;
V1 = V1 - V0;
V1 = V1 << 02;
V1 = V1 + V0;
V1 = V1 << 02;
V0 = 0001;
800A66D4	lui    at, $800b
AT = AT + V1;
[AT + 1a39] = b(V0);

La66e0:	; 800A66E0
RA = w[SP + 0010];
SP = SP + 0018;
800A66E8	jr     ra 
800A66EC	nop
////////////////////////////////
// funca66f0
800A66F0	addiu  sp, sp, $ffc0 (=-$40)
A0 = 0004;
[SP + 0038] = w(RA);
[800afb74] = w(0);
800A6704	jal    $system_memory_set_alloc_user
A1 = 0;
V0 = w[800ad044];
800A6714	nop
800A6718	bne    v0, zero, La67e8 [$800a67e8]
A0 = 0018;
800A6720	jal    $system_filesystem_set_dir
A1 = 0001;
V1 = h[800c2f0c];
V0 = 00ff;
800A6734	bne    v1, v0, La6754 [$800a6754]
A0 = 0001;
V0 = w[800ad058];
800A6744	nop
V0 = V0 & 0040;
800A674C	beq    v0, zero, La6758 [$800a6758]
800A6750	nop

La6754:	; 800A6754
A0 = 0003;

La6758:	; 800A6758
[SP + 0014] = w(A0);
A0 = h[800c2ef4];
A1 = hu[800c2efe];
A2 = hu[800c2ef8];
V0 = 0001;
[SP + 0010] = w(V0);
V0 = 00e0;
[SP + 002c] = w(V0);
V0 = 800a65f8;
[SP + 0030] = w(V0);
V0 = hu[800c2f0e];
V1 = hu[800c2ef6];
A3 = hu[800c2efa];
T0 = hu[800c2efc];
[SP + 0020] = w(A2);
A2 = hu[800c2f00];
[SP + 0024] = w(A3);
A3 = hu[800c2f02];
A0 = A0 + 0002;
[SP + 0018] = w(V0);
[SP + 001c] = w(V1);
800A67D4	jal    $801d37cc
[SP + 0028] = w(T0);
A0 = 0004;
800A67E0	jal    $system_filesystem_set_dir
A1 = 0;

La67e8:	; 800A67E8
A0 = 0008;
800A67EC	jal    $system_memory_set_alloc_user
A1 = 0;
RA = w[SP + 0038];
SP = SP + 0040;
800A67FC	jr     ra 
800A6800	nop
////////////////////////////////
// funca6804
800A6804	addiu  sp, sp, $ffd8 (=-$28)
[SP + 001c] = w(S1);
S1 = A0;
[SP + 0020] = w(RA);
800A6814	jal    $80019d24
[SP + 0018] = w(S0);
V0 = w[800ad044];
800A6824	nop
800A6828	bne    v0, zero, La6854 [$800a6854]
800A682C	nop
800A6830	blez   s1, La6854 [$800a6854]
S0 = 0;

loopa6838:	; 800A6838
800A6838	jal    $801d3f7c
S0 = S0 + 0001;
800A6840	jal    func84c8c [$80084c8c]
800A6844	nop
V0 = S0 < S1;
800A684C	bne    v0, zero, loopa6838 [$800a6838]
800A6850	nop

La6854:	; 800A6854
RA = w[SP + 0020];
S1 = w[SP + 001c];
S0 = w[SP + 0018];
SP = SP + 0028;
800A6864	jr     ra 
800A6868	nop
////////////////////////////////
// funca686c
800A686C	addiu  sp, sp, $ffe8 (=-$18)
[SP + 0010] = w(RA);

loopa6874:	; 800A6874
800A6874	jal    func7743c [$8007743c]
800A6878	nop
800A687C	jal    func74bdc [$80074bdc]
800A6880	nop
800A6884	jal    $800284dc
800A6888	nop
800A688C	bne    v0, zero, loopa6874 [$800a6874]
800A6890	nop
V0 = w[800acfe0];
800A689C	nop
800A68A0	bne    v0, zero, loopa6874 [$800a6874]
800A68A4	nop
800A68A8	jal    $80041288
A0 = 0;
RA = w[SP + 0010];
SP = SP + 0018;
800A68B8	jr     ra 
800A68BC	nop
////////////////////////////////
// funca68c0
800A68C0	addiu  sp, sp, $ffd0 (=-$30)
V1 = w[800ad04c];
V0 = 0002;
[SP + 0028] = w(RA);
[SP + 0024] = w(S3);
[SP + 0020] = w(S2);
[SP + 001c] = w(S1);
800A68E0	bne    v1, v0, La6918 [$800a6918]
[SP + 0018] = w(S0);
S0 = 80059aa8;
A0 = w[S0 + 0000];
800A68F4	jal    $80031edc
800A68F8	nop
A0 = w[80059aac];
800A6904	jal    $80031edc
800A6908	nop
A0 = w[S0 + 0000];
800A6910	j      La6998 [$800a6998]
800A6914	nop

La6918:	; 800A6918
A0 = SP + 0010;
S1 = 80059aa8;
S3 = 0200;
S2 = 0140;
A1 = w[S1 + 0000];
S0 = 0080;
[SP + 0010] = h(S3);
[SP + 0012] = h(0);
[SP + 0014] = h(S2);
800A6940	jal    $8004470c
[SP + 0016] = h(S0);
800A6948	jal    $system_draw_sync
A0 = 0;
A1 = w[80059aac];
A0 = SP + 0010;
[SP + 0010] = h(S3);
[SP + 0012] = h(S0);
[SP + 0014] = h(S2);
800A6968	jal    $8004470c
[SP + 0016] = h(S0);
800A6970	jal    $system_draw_sync
A0 = 0;
A0 = w[S1 + 0000];
800A697C	jal    $80031edc
800A6980	nop
A0 = w[80059aac];
800A698C	jal    $80031edc
800A6990	nop
A0 = w[S1 + 0000];

La6998:	; 800A6998
800A6998	jal    $system_memory_mark_removed_alloc
800A699C	nop
A0 = w[80059aac];
800A69A8	jal    $system_memory_mark_removed_alloc
800A69AC	nop
RA = w[SP + 0028];
S3 = w[SP + 0024];
S2 = w[SP + 0020];
S1 = w[SP + 001c];
S0 = w[SP + 0018];
SP = SP + 0030;
800A69C8	jr     ra 
800A69CC	nop
////////////////////////////////
// funca69d0
800A69D0	addiu  sp, sp, $ffb0 (=-$50)
V1 = w[800ad04c];
V0 = 0002;
[SP + 004c] = w(RA);
[SP + 0048] = w(S4);
[SP + 0044] = w(S3);
[SP + 0040] = w(S2);
[SP + 003c] = w(S1);
800A69F4	bne    v1, v0, La6b58 [$800a6b58]
[SP + 0038] = w(S0);
A0 = 14000;
800A6A04	jal    $system_memory_allocate
A1 = 0;
A0 = 14000;
A1 = 0;
S0 = 80059aa8;
800A6A20	jal    $system_memory_allocate
[S0 + 0000] = w(V0);
S3 = 0;
A0 = w[S0 + 0000];
[80059aac] = w(V0);
800A6A38	jal    $80031ec8
S1 = 0001;
A0 = w[80059aac];
S2 = 8006f150;
800A6A50	jal    $80031ec8
800A6A54	nop
A0 = 0004;
800A6A5C	jal    $system_filesystem_set_dir
A1 = 0;

loopa6a64:	; 800A6A64
V1 = w[S2 + 0000];
V0 = 00ff;
800A6A6C	beq    v1, v0, La6ab4 [$800a6ab4]
S4 = S1 << 02;
V0 = S3 << 03;
S0 = SP + 0018;
S0 = S0 + V0;
V0 = V1 + 0005;
[S0 + 0000] = h(V0);
A0 = w[S2 + 0000];
S3 = S3 + 0001;
800A6A90	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = A0 + 0005;
A0 = V0;
800A6A9C	jal    $system_memory_allocate
A1 = 0001;
800A6AA4	lui    at, $8006
AT = AT + S4;
[AT + 518c] = w(V0);
[S0 + 0004] = w(V0);

La6ab4:	; 800A6AB4
S1 = S1 + 0001;
V0 = S1 < 0003;
800A6ABC	bne    v0, zero, loopa6a64 [$800a6a64]
S2 = S2 + 0004;
A0 = SP + 0018;
A1 = 0;
V0 = S3 << 03;
V0 = A0 + V0;
A2 = 0;
[V0 + 0004] = w(0);
800A6ADC	jal    $8002990c
[V0 + 0000] = h(0);
800A6AE4	jal    $system_cdrom_action_sync
A0 = 0;
S1 = 0001;
S4 = 00ff;
S0 = 80065190;
S3 = 80059aa8;
S2 = 80061c24;

loopa6b0c:	; 800A6B0C
V0 = w[S2 + 0000];
800A6B10	nop
800A6B14	beq    v0, s4, La6b38 [$800a6b38]
800A6B18	nop
A0 = w[S0 + 0000];
A1 = w[S3 + 0000];
800A6B24	jal    $80032cd8
800A6B28	nop
A0 = w[S0 + 0000];
800A6B30	jal    $system_memory_mark_removed_alloc
800A6B34	nop

La6b38:	; 800A6B38
S0 = S0 + 0004;
S3 = S3 + 0004;
S1 = S1 + 0001;
V0 = S1 < 0003;
800A6B48	bne    v0, zero, loopa6b0c [$800a6b0c]
S2 = S2 + 0004;
800A6B50	j      La6bf8 [$800a6bf8]
800A6B54	nop

La6b58:	; 800A6B58
A0 = 14000;
800A6B60	jal    $system_memory_allocate
A1 = 0;
A0 = 14000;
A1 = 0;
S0 = 80059aa8;
800A6B7C	jal    $system_memory_allocate
[S0 + 0000] = w(V0);
A0 = w[S0 + 0000];
[80059aac] = w(V0);
800A6B90	jal    $80031ec8
S2 = 0200;
A0 = w[80059aac];
800A6BA0	jal    $80031ec8
S1 = 0140;
A0 = SP + 0010;
A1 = w[S0 + 0000];
S0 = 0080;
[SP + 0010] = h(S2);
[SP + 0012] = h(0);
[SP + 0014] = h(S1);
800A6BC0	jal    $80044770
[SP + 0016] = h(S0);
800A6BC8	jal    $system_draw_sync
A0 = 0;
A1 = w[80059aac];
A0 = SP + 0010;
[SP + 0010] = h(S2);
[SP + 0012] = h(S0);
[SP + 0014] = h(S1);
800A6BE8	jal    $80044770
[SP + 0016] = h(S0);
800A6BF0	jal    $system_draw_sync
A0 = 0;

La6bf8:	; 800A6BF8
RA = w[SP + 004c];
S4 = w[SP + 0048];
S3 = w[SP + 0044];
S2 = w[SP + 0040];
S1 = w[SP + 003c];
S0 = w[SP + 0038];
SP = SP + 0050;
800A6C14	jr     ra 
800A6C18	nop
////////////////////////////////
// funca6c1c
A0 = w[800b097c];
800A6C24	nop
V0 = A0 & 0003;
800A6C2C	bne    v0, zero, La6c58 [$800a6c58]
800A6C30	nop
V0 = w[800c2dd8];
800A6C3C	nop
V1 = w[V0 + 0000];
V0 = V0 + 0004;
[800c2dd8] = w(V0);
[800c1b5c] = w(V1);

La6c58:	; 800A6C58
V0 = w[800c1b5c];
V1 = A0 + 0001;
[800b097c] = w(V1);
V1 = V0 & 00ff;
V0 = V0 >> 08;
[800c1b5c] = w(V0);
800A6C7C	beq    v1, zero, La6c94 [$800a6c94]
800A6C80	nop
V1 = V1 >> 03;
800A6C88	bne    v1, zero, La6c94 [$800a6c94]
800A6C8C	nop
V1 = 0001;

La6c94:	; 800A6C94
800A6C94	jr     ra 
V0 = V1;
////////////////////////////////



////////////////////////////////
// funca6c9c

A0 = a800;
A1 = 0;
system_memory_allocate();
S4 = V0;

A0 = 7000;
A1 = 0;
system_memory_allocate();

S5 = V0;
S2 = 0;
S6 = 00e0;
S3 = 0;

loopa6cec:	; 800A6CEC
A0 = SP + 0010;
A1 = S4;
V0 = 0060;
[SP + 0010] = h(S3);
[SP + 0012] = h(0);
[SP + 0014] = h(V0);
800A6D04	jal    $80044770
[SP + 0016] = h(S6);
800A6D0C	jal    $system_draw_sync
A0 = 0;
S1 = 0;
[800c2dd8] = w(S4);
[800c2de0] = w(S5);
[800b097c] = w(0);

loopa6d30:	; 800A6D30
800A6D30	jal    funca6c1c [$800a6c1c]
S1 = S1 + 0001;
800A6D38	jal    funca6c1c [$800a6c1c]
S0 = V0;
V0 = V0 << 05;
800A6D44	jal    funca6c1c [$800a6c1c]
S0 = S0 | V0;
V0 = V0 << 0a;
800A6D50	jal    funca6c1c [$800a6c1c]
S0 = S0 | V0;
V0 = V0 << 10;
800A6D5C	jal    funca6c1c [$800a6c1c]
S0 = S0 | V0;
V0 = V0 << 15;
800A6D68	jal    funca6c1c [$800a6c1c]
S0 = S0 | V0;
V0 = V0 << 1a;
V1 = w[800c2de0];
S0 = S0 | V0;
[V1 + 0000] = w(S0);
V0 = w[800c2de0];
800A6D8C	nop
V0 = V0 + 0004;
[800c2de0] = w(V0);
V0 = S1 < 1c00;
800A6DA0	bne    v0, zero, loopa6d30 [$800a6d30]
A0 = SP + 0010;
A1 = S5;
V0 = S2 << 06;
[SP + 0010] = h(V0);
V0 = 0100;
[SP + 0012] = h(V0);
V0 = 0040;
[SP + 0014] = h(V0);
800A6DC4	jal    $8004470c
[SP + 0016] = h(S6);
800A6DCC	jal    $system_draw_sync
A0 = 0;
S2 = S2 + 0001;
V0 = S2 < 0005;
800A6DDC	bne    v0, zero, loopa6cec [$800a6cec]
S3 = S3 + 0060;
800A6DE4	jal    $system_memory_mark_removed_alloc
A0 = S4;
800A6DEC	jal    $system_memory_mark_removed_alloc
A0 = S5;
////////////////////////////////



////////////////////////////////
// funca6e20
V0 = w[8004e9a4];
800A6E28	addiu  sp, sp, $ffd0 (=-$30)
[SP + 002c] = w(RA);
[SP + 0028] = w(S2);
[SP + 0024] = w(S1);
800A6E38	beq    v0, zero, La7114 [$800a7114]
[SP + 0020] = w(S0);
V1 = w[800afb74];
800A6E48	nop
V0 = V1 < 0687;
800A6E50	bne    v0, zero, La7114 [$800a7114]
800A6E54	nop
V0 = V1 < 18e2;
800A6E5C	beq    v0, zero, La7114 [$800a7114]
A0 = SP + 0018;
A1 = 0;
A2 = 0;
A3 = 0;
V0 = 0001;
[800af348] = w(V0);
V0 = 0500;
S2 = 0200;
[801e89e0] = w(0);
[SP + 0018] = h(0);
[SP + 001a] = h(0);
[SP + 001c] = h(V0);
800A6E98	jal    $800445dc
[SP + 001e] = h(S2);
800A6EA0	jal    $system_draw_sync
A0 = 0;
800A6EA8	jal    $8004b3f4
A0 = 0;
S1 = 800b1970;
A0 = S1;
A1 = 0;
A2 = 0;
A3 = 0280;
S0 = 00e0;
800A6ECC	jal    $800437a0
[SP + 0010] = w(S0);
A0 = 800b9a64;
A1 = 0;
A2 = 0100;
A3 = 0280;
800A6EE8	jal    $800437a0
[SP + 0010] = w(S0);
A0 = S1 + 00b8;
A1 = 0;
A2 = 0100;
A3 = 0280;
800A6F00	jal    $80043858
[SP + 0010] = w(S0);
A0 = 800b9b1c;
A1 = 0;
A2 = 0;
A3 = 0280;
800A6F1C	jal    $80043858
[SP + 0010] = w(S0);
A0 = w[800c3740];
[800b9b2d] = b(0);
[800b1a39] = b(0);
800A6F3C	jal    $system_psyq_put_disp_env
A0 = A0 + 00b8;
A0 = w[800c3740];
800A6F4C	jal    system_psyq_put_draw_env
800A6F50	nop
A0 = SP + 0018;
A1 = 0;
A2 = 0;
A3 = 0;
V0 = 0300;
[SP + 0018] = h(V0);
V0 = 0100;
[SP + 001a] = h(0);
[SP + 001c] = h(S2);
800A6F78	jal    $800445dc
[SP + 001e] = h(V0);
800A6F80	jal    funcac068 [$800ac068]
800A6F84	nop
800A6F88	jal    $8004b3f4
A0 = 0;
800A6F90	jal    $system_draw_sync
A0 = 0;
800A6F98	j      La703c [$800a703c]
800A6F9C	nop

loopa6fa0:	; 800A6FA0
800A6FA0	jal    $80019d24
800A6FA4	nop
800A6FA8	jal    func735e0 [$800735e0]
800A6FAC	nop
V0 = w[800afb74];
800A6FB8	nop
V0 = V0 < 18de;
800A6FC0	beq    v0, zero, La6fd0 [$800a6fd0]
800A6FC4	nop
800A6FC8	jal    funcabe74 [$800abe74]
800A6FCC	nop

La6fd0:	; 800A6FD0
800A6FD0	jal    $system_draw_sync
A0 = 0;
800A6FD8	jal    $8004b3f4
A0 = 0002;
A1 = 0;
A2 = 0;
A0 = w[800c3740];
800A6FF0	jal    $800445dc
A3 = 0;
A0 = w[800c3740];
800A7000	jal    $system_psyq_put_disp_env
A0 = A0 + 00b8;
A0 = w[800c3740];
800A7010	jal    system_psyq_put_draw_env
800A7014	nop
V0 = w[800c3740];
A0 = 80f0;
800A7024	jal    $system_psyq_draw_otag
A0 = V0 + A0;
800A702C	jal    funcac1cc [$800ac1cc]
800A7030	nop
800A7034	jal    funca6804 [$800a6804]
A0 = 0005;

La703c:	; 800A703C
V0 = w[800afb74];
800A7044	nop
V0 = V0 < 18e2;
800A704C	bne    v0, zero, loopa6fa0 [$800a6fa0]
V0 = 0001;
[800af348] = w(0);
[801e89e0] = w(V0);
800A7064	jal    $system_draw_sync
A0 = 0;
800A706C	jal    $8004b3f4
A0 = 0;
S1 = 800b1970;
A0 = S1;
A1 = 0;
A2 = 0;
A3 = 0140;
S0 = 00e0;
800A7090	jal    $800437a0
[SP + 0010] = w(S0);
A0 = 800b9a64;
A1 = 0;
A2 = 0100;
A3 = 0140;
800A70AC	jal    $800437a0
[SP + 0010] = w(S0);
A0 = S1 + 00b8;
A1 = 0;
A2 = 0100;
A3 = 0140;
800A70C4	jal    $80043858
[SP + 0010] = w(S0);
A0 = 800b9b1c;
A1 = 0;
A2 = 0;
A3 = 0140;
800A70E0	jal    $80043858
[SP + 0010] = w(S0);
V0 = 0001;
[800b9b2d] = b(V0);
[800b1a39] = b(V0);
[800b9b2c] = b(0);
[800b1a38] = b(0);
800A710C	jal    funcac188 [$800ac188]
800A7110	nop

La7114:	; 800A7114
RA = w[SP + 002c];
S2 = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0030;
800A7128	jr     ra 
800A712C	nop
////////////////////////////////



////////////////////////////////
// funca7130

[800ad05c] = w(0);
[800af5b8] = w(0);
[800ad050] = w(0);

A0 = a9;
system_get_aligned_filesize_by_dir_file_id();

A0 = V0;
A1 = 0;
system_memory_allocate();

S0 = V0;

A0 = a9;
A1 = S0;
A2 = 0;
A3 = 80;
system_load_file_by_dir_file_id();

[800afb74] = w(0);
[800af348] = w(0);
800A7198	jal    funca686c [$800a686c]

A0 = 0018;
800A71A4	jal    $system_filesystem_set_dir
A1 = 0;
A0 = h[800c2ef4];
800A71B4	jal    $8002a0e0
800A71B8	nop
A0 = 0004;
800A71C0	jal    $system_filesystem_set_dir
A1 = 0;
800A71C8	jal    funca686c [$800a686c]
800A71CC	nop
V0 = w[800b1738];
800A71D8	nop
800A71DC	beq    v0, zero, La720c [$800a720c]
800A71E0	nop
800A71E4	jal    $801e7fd4
800A71E8	nop
800A71EC	jal    field_flush_sync [$80078fb0]
800A71F0	nop
800A71F4	jal    field_sync [$80076c88]
800A71F8	nop
A0 = w[800acff8];
800A7204	jal    $system_memory_mark_removed_alloc
800A7208	nop

La720c:	; 800A720C
field_particle_clear_all();

V1 = w[800ad04c];
V0 = 0002;
800A7220	beq    v1, v0, La727c [$800a727c]
A0 = SP + 0010;
A1 = S0;
V0 = 0140;
[SP + 0010] = h(V0);
V0 = 00c0;
[SP + 0014] = h(V0);
V0 = 0100;
[SP + 0012] = h(0);
800A7244	jal    $8004470c
[SP + 0016] = h(V0);
800A724C	jal    $system_draw_sync
A0 = 0;
800A7254	jal    $system_memory_mark_removed_alloc
A0 = S0;
A0 = 18000;
800A7264	jal    $system_memory_allocate
A1 = 0;
S0 = V0;
A0 = SP + 0010;
800A7274	jal    $80044770
A1 = S0;

La727c:	; 800A727C
V0 = w[8004ea14];
V1 = w[800ad008];
800A728C	bne    v0, zero, La72d8 [$800a72d8]
A0 = 0008;
A0 = ffffff;
V0 = ffe2cff8;
A0 = V1 & A0;
A0 = A0 + V0;
800A72AC	jal    $system_memory_allocate
A1 = 0001;
S2 = V0;
800A72B8	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 00a9;
A0 = S2;
A1 = S0;
800A72C8	jal    $system_memcpy
A2 = V0;
800A72D0	j      La72e4 [$800a72e4]
800A72D4	nop

La72d8:	; 800A72D8
800A72D8	jal    $system_memory_allocate
A1 = 0001;
S2 = V0;

La72e4:	; 800A72E4
800A72E4	jal    $system_memory_mark_removed_alloc
A0 = S0;
800A72EC	jal    func84d9c [$80084d9c]
S0 = 0001;
800A72F4	jal    funcac130 [$800ac130]
800A72F8	nop
[800af5b8] = w(S0);
800A7304	jal    funca68c0 [$800a68c0]
800A7308	nop
800A730C	jal    field_flush_sync [$80078fb0]
800A7310	nop
800A7314	jal    $80031e1c
800A7318	nop
800A731C	jal    funca6564 [$800a6564]
800A7320	nop
800A7324	jal    funca66f0 [$800a66f0]
800A7328	nop
[800ad054] = w(S0);

loopa7334:	; 800A7334
800A7334	jal    $8004b3f4
A0 = 0;
800A733C	jal    funca6804 [$800a6804]
A0 = 0003;
V0 = w[800af5b8];
800A734C	nop
800A7350	bne    v0, zero, loopa7334 [$800a7334]
S0 = 0002;
S1 = 800c2f0e;

La7360:	; 800A7360
V1 = w[800ad04c];
V0 = 0001;
800A736C	beq    v1, v0, La739c [$800a739c]
V0 = V1 < 0002;
800A7374	beq    v0, zero, La738c [$800a738c]
800A7378	nop
800A737C	beq    v1, zero, La73b4 [$800a73b4]
800A7380	nop
800A7384	j      La7450 [$800a7450]
800A7388	nop

La738c:	; 800A738C
800A738C	beq    v1, s0, La7434 [$800a7434]
800A7390	nop
800A7394	j      La7450 [$800a7450]
800A7398	nop

La739c:	; 800A739C
800A739C	jal    func735e0 [$800735e0]
800A73A0	nop
800A73A4	jal    func74fa0 [$80074fa0]
800A73A8	nop
800A73AC	j      La7448 [$800a7448]
A0 = 0006;

La73b4:	; 800A73B4
800A73B4	jal    $system_draw_sync
A0 = 0;
800A73BC	jal    $8004b3f4
A0 = 0;
A0 = w[800c3740];
800A73CC	jal    $system_psyq_put_disp_env
A0 = A0 + 00b8;
A0 = w[800c3740];
800A73DC	jal    system_psyq_put_draw_env
800A73E0	nop
800A73E4	jal    funca6804 [$800a6804]
A0 = 0003;
800A73EC	jal    $system_draw_sync
A0 = 0;
800A73F4	jal    $8004b3f4
A0 = 0;
A0 = w[800c3740];
800A7404	jal    $system_psyq_put_disp_env
A0 = A0 + 00b8;
A0 = w[800c3740];
800A7414	jal    system_psyq_put_draw_env
800A7418	nop
800A741C	jal    funca6804 [$800a6804]
A0 = 0003;
800A7424	jal    funca6e20 [$800a6e20]
800A7428	nop
800A742C	j      La7450 [$800a7450]
800A7430	nop

La7434:	; 800A7434
800A7434	jal    func7743c [$8007743c]
800A7438	nop
800A743C	jal    func74bdc [$80074bdc]
800A7440	nop
A0 = 0009;

La7448:	; 800A7448
800A7448	jal    funca6804 [$800a6804]
800A744C	nop

La7450:	; 800A7450
V0 = w[800c1b60];
800A7458	nop
800A745C	bne    v0, zero, La74d4 [$800a74d4]
800A7460	nop
V0 = w[800ad04c];
800A746C	nop
800A7470	bne    v0, s0, La74ac [$800a74ac]
800A7474	nop
V0 = hu[800c2dd4];
800A7480	nop
V0 = V0 & 0080;
800A7488	bne    v0, zero, La758c [$800a758c]
800A748C	nop
V0 = w[800ad05c];
800A7498	nop
800A749C	bne    v0, zero, La758c [$800a758c]
800A74A0	nop
800A74A4	j      La7538 [$800a7538]
800A74A8	nop

La74ac:	; 800A74AC
800A74AC	jal    func73d90 [$80073d90]
800A74B0	nop
V0 = hu[800c2dd4];
800A74BC	nop
V0 = V0 & 0020;
800A74C4	bne    v0, zero, La758c [$800a758c]
800A74C8	nop
800A74CC	j      La7538 [$800a7538]
800A74D0	nop

La74d4:	; 800A74D4
V0 = w[800ad058];
800A74DC	nop
V0 = V0 & 0080;
800A74E4	beq    v0, zero, La7538 [$800a7538]
800A74E8	nop
800A74EC	jal    func73d90 [$80073d90]
800A74F0	nop
V0 = hu[800c2dd4];
800A74FC	nop
V0 = V0 & 0020;
800A7504	beq    v0, zero, La7538 [$800a7538]
A0 = 0;
800A750C	jal    $80038bc0
A1 = 000a;
S0 = 0;

La7518:	; 800A7518
800A7518	jal    $8004b3f4
A0 = 0;
S0 = S0 + 0001;
V0 = S0 < 0005;
800A7528	beq    v0, zero, La758c [$800a758c]
800A752C	nop
800A7530	j      La7518 [$800a7518]
800A7534	nop

La7538:	; 800A7538
V0 = w[800ad04c];
800A7540	nop
800A7544	bne    v0, s0, La7560 [$800a7560]
800A7548	nop
V0 = w[800ad05c];
800A7554	nop
800A7558	bne    v0, zero, La758c [$800a758c]
800A755C	nop

La7560:	; 800A7560
V0 = h[S1 + 0000];
800A7564	nop
800A7568	bne    v0, zero, La7360 [$800a7360]
800A756C	nop
V1 = hu[S1 + fff4];
V0 = w[800afb74];
800A757C	nop
V0 = V0 < V1;
800A7584	bne    v0, zero, La7360 [$800a7360]
800A7588	nop

La758c:	; 800A758C
800A758C	jal    $8004b3f4
A0 = 0;
800A7594	jal    $system_draw_sync
A0 = 0;
800A759C	jal    $801d43b0
800A75A0	nop
800A75A4	jal    field_flush_sync [$80078fb0]
800A75A8	nop
A0 = w[800c3740];
800A75B4	jal    $system_psyq_put_disp_env
A0 = A0 + 00b8;
A0 = w[800c3740];
800A75C4	jal    system_psyq_put_draw_env
800A75C8	nop
800A75CC	jal    $8004b3f4
A0 = 0;
800A75D4	jal    $system_draw_sync
A0 = 0;
800A75DC	jal    $system_memory_mark_removed_alloc
A0 = S2;
800A75E4	jal    $80031e1c
S2 = 00e0;
800A75EC	jal    funca69d0 [$800a69d0]
800A75F0	nop
800A75F4	jal    func76f14 [$80076f14]
800A75F8	nop
A0 = SP + 0010;
A1 = 0;
V0 = 01e0;
A2 = w[800ad050];
[SP + 0010] = h(0);
[SP + 0014] = h(V0);
[SP + 0016] = h(S2);
A2 = A2 << 08;
800A7620	jal    $system_move_image
[SP + 0012] = h(A2);
800A7628	jal    $system_draw_sync
A0 = 0;
800A7630	jal    $8004b3f4
A0 = 0;
S0 = 800b9a64;
S1 = S0 + 00b8;
[800c3740] = w(S0);
800A764C	jal    $system_psyq_put_disp_env
A0 = S1;
A0 = w[800c3740];
800A765C	jal    system_psyq_put_draw_env
800A7660	nop
V1 = w[800ad04c];
V0 = 0002;
800A7670	beq    v1, v0, La7680 [$800a7680]
800A7674	nop
800A7678	jal    funca6c9c [$800a6c9c]
A0 = 0;

La7680:	; 800A7680
800A7680	jal    $8004b3f4
A0 = 0;
V0 = 800b1a39;
800A7690	addiu  a0, v0, $ffef (=-$11)
[V0 + 0000] = b(0);
800A7698	addiu  v0, v0, $ff37 (=-$c9)
[800c3740] = w(V0);
800A76A4	jal    $system_psyq_put_disp_env
800A76A8	nop
A0 = w[800c3740];
800A76B4	jal    system_psyq_put_draw_env
800A76B8	nop
A0 = SP + 0010;
A1 = 0;
A2 = 0;
V0 = 0100;
[SP + 0012] = h(V0);
V0 = 0140;
[SP + 0010] = h(0);
[SP + 0014] = h(V0);
800A76DC	jal    $system_move_image
[SP + 0016] = h(S2);
800A76E4	jal    $system_draw_sync
A0 = 0;
800A76EC	jal    $8004b3f4
A0 = 0;
[800b9b2d] = b(0);
[800c3740] = w(S0);
800A7704	jal    $system_psyq_put_disp_env
A0 = S1;
A0 = w[800c3740];
800A7714	jal    system_psyq_put_draw_env
800A7718	nop
V0 = w[800af358];
800A7724	nop
800A7728	beq    v0, zero, La7740 [$800a7740]
V0 = 0001;
[800ad028] = w(V0);
800A7738	j      La7748 [$800a7748]
800A773C	nop

La7740:	; 800A7740
[800ad028] = w(0);

La7748:	; 800A7748
800A7748	jal    func77144 [$80077144]
800A774C	nop
V1 = w[800ad04c];
V0 = 0002;
800A775C	beq    v1, v0, La77a8 [$800a77a8]
A0 = 0004;
800A7764	jal    $system_filesystem_set_dir
A1 = 0;
A0 = 0008;
800A7770	jal    $system_memory_set_alloc_user
A1 = 0;
[800ad038] = w(0);
800A7780	jal    func6fb18 [$8006fb18]
800A7784	nop
800A7788	jal    func6fb98 [$8006fb98]
800A778C	nop
V0 = 0020;
[800ad014] = w(V0);
V0 = 0001;
[800ad010] = w(V0);

La77a8:	; 800A77A8
800A77A8	jal    func84d4c [$80084d4c]
800A77AC	nop
V0 = 00ff;
[800c2f0c] = h(V0);
800A77BC	addiu  v0, zero, $ffff (=-$1)
[800ad04c] = w(0);
[800ad044] = w(V0);
////////////////////////////////



////////////////////////////////
// field_load_0592_tim_into_ram()

A0 = 8;
A1 = 0;
system_memory_set_alloc_user();

A0 = 4;
A1 = 0;
system_filesystem_set_dir();

A0 = aa;
system_get_aligned_filesize_by_dir_file_id();

A0 = V0;
A1 = 1;
system_memory_allocate();
mem = V0;

A0 = aa; // "10\0592.tim"
A1 = mem;
A2 = 0;
A3 = 80;
system_load_file_by_dir_file_id();

A0 = 0;
system_cdrom_action_sync();

A0 = mem;
A1 = 380;
A2 = 0;
A3 = 0;
A4 = e8;
A5 = 0;
A6 = 0;
field_load_tim_into_vram();

A0 = 0;
system_draw_sync();

A0 = mem;
system_memory_mark_removed_alloc();
////////////////////////////////



////////////////////////////////
// funca788c()

if( w[800ae74c] != 0 )
{
    [800ae74c] = w(0);

    A0 = 0;
    system_draw_sync();

    A0 = w[800af134];
    system_memory_mark_removed_alloc();

    A0 = w[800af138];
    system_memory_mark_removed_alloc();
}
////////////////////////////////



////////////////////////////////
// funca78e0()

V0 = A0 << 03;

V0 = hu[800ae3e8 + V0];
T0 = w[800acfe0];
V0 = V0 << 03;
T0 = T0 << 02;
V1 = hu[800ae03e + V0];
A3 = hu[800ae040 + V0];
T1 = hu[800ae03c + V0];
T0 = w[800af134 + T0];
V1 = V1 + A2;
T1 = T1 + A1;
A3 = T1 + A3;
A2 = hu[800ae042 + V0];
V0 = A0 << 02;
V0 = V0 + A0;
V0 = V0 << 03;
A0 = T0 + V0;
A1 = T1;
[SP + 0014] = w(T1);
[SP + 001c] = w(A3);
A2 = V1 + A2;
800A7970	addiu  a2, a2, $ffff (=-$1)
800A7974	addiu  v1, v1, $ffff (=-$1)
[SP + 0010] = w(A2);
[SP + 0018] = w(V1);
[SP + 0020] = w(V1);
field_set_quad_uv();
////////////////////////////////



////////////////////////////////
// funca7998

V0 = w[800ae74c];
800A79C4	beq    v0, zero, La804c [$800a804c]

S7 = 006d;
S0 = 0;
S6 = 800af134;
S2 = ffffff;
800A79E4	lui    s5, $ff00
S1 = 0;
A0 = w[800aed64];
V0 = w[800aed54];
A1 = w[800aed6c];
A0 = A0 - V0;
V0 = w[800aed5c];
A0 = A0 >> 10;
A1 = A1 - V0;
800A7A18	jal    length_of_vector_by_x_y [$80099020]
A1 = A1 >> 10;
A1 = w[800aed68];
V1 = w[800aed58];
A0 = V0;
A1 = A1 - V1;
800A7A38	jal    $8004b1d4
A1 = A1 >> 10;
V1 = hu[800aee62];
S4 = V0 & 0fff;
S3 = V1 & 0fff;

loopa7a50:	; 800A7A50
A0 = S0;
A1 = S3 >> 04;
A1 = A1 & 000f;
800A7A5C	jal    funca78e0 [$800a78e0]
A2 = 0;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S6;
A0 = w[A1 + 0000];
800A7A84	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S5;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7AA8	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S5;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 0010;
800A7ACC	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7AD8	bne    v0, zero, loopa7a50 [$800a7a50]
S1 = S1 + 0028;
V0 = S0 < 001d;
800A7AE4	beq    v0, zero, La7b98 [$800a7b98]
V0 = S0 << 02;
S6 = 800af134;
S2 = ffffff;
800A7AFC	lui    s5, $ff00
V0 = V0 + S0;
S1 = V0 << 03;

loopa7b08:	; 800A7B08
A0 = S0;
A1 = 0;
A2 = S4 >> 04;
800A7B14	jal    funca78e0 [$800a78e0]
A2 = A2 & 000f;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S6;
A0 = w[A1 + 0000];
800A7B3C	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S5;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7B60	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S5;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 001d;
800A7B84	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7B90	bne    v0, zero, loopa7b08 [$800a7b08]
S1 = S1 + 0028;

La7b98:	; 800A7B98
V0 = S0 < 0022;
800A7B9C	beq    v0, zero, La7c54 [$800a7c54]
V0 = S0 << 02;
S6 = 800af134;
S2 = ffffff;
800A7BB4	lui    s5, $ff00
V0 = V0 + S0;
S1 = V0 << 03;

loopa7bc0:	; 800A7BC0
A0 = S0;
A1 = S3 & 000f;
A1 = A1 << 03;
800A7BCC	jal    funca78e0 [$800a78e0]
A2 = 0;
S3 = S3 >> 02;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S6;
A0 = w[A1 + 0000];
800A7BF8	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S5;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7C1C	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S5;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 0022;
800A7C40	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7C4C	bne    v0, zero, loopa7bc0 [$800a7bc0]
S1 = S1 + 0028;

La7c54:	; 800A7C54
V0 = S0 < 0027;
800A7C58	beq    v0, zero, La7d10 [$800a7d10]
V0 = S0 << 02;
S5 = 800af134;
S2 = ffffff;
800A7C70	lui    s3, $ff00
V0 = V0 + S0;
S1 = V0 << 03;

loopa7c7c:	; 800A7C7C
A0 = S0;
A1 = S4 & 000f;
A1 = A1 << 03;
800A7C88	jal    funca78e0 [$800a78e0]
A2 = 0;
S4 = S4 >> 02;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S5;
A0 = w[A1 + 0000];
800A7CB4	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S3;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7CD8	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S3;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 0027;
800A7CFC	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7D08	bne    v0, zero, loopa7c7c [$800a7c7c]
S1 = S1 + 0028;

La7d10:	; 800A7D10
V0 = S0 < 0028;
800A7D14	beq    v0, zero, La7e18 [$800a7e18]
V0 = S0 << 02;
S4 = 800af134;
S2 = ffffff;
800A7D2C	lui    s3, $ff00
V0 = V0 + S0;
S1 = V0 << 03;

loopa7d38:	; 800A7D38
V0 = w[800ae034];
800A7D40	nop
V0 = V0 & 000f;
800A7D48	bne    v0, zero, La7d68 [$800a7d68]
800A7D4C	nop
V0 = w[800ae038];
800A7D58	nop
V0 = V0 + 0001;
[800ae038] = w(V0);

La7d68:	; 800A7D68
V0 = w[800ae038];
800A7D70	nop
V0 = V0 < 0003;
800A7D78	bne    v0, zero, La7d88 [$800a7d88]
A0 = S0;
[800ae038] = w(0);

La7d88:	; 800A7D88
A2 = w[800ae038];
A1 = 0;
800A7D94	jal    funca78e0 [$800a78e0]
A2 = A2 << 03;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S4;
A0 = w[A1 + 0000];
800A7DBC	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S3;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7DE0	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S3;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 0028;
800A7E04	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7E10	bne    v0, zero, loopa7d38 [$800a7d38]
S1 = S1 + 0028;

La7e18:	; 800A7E18
V0 = S0 < 002a;
800A7E1C	beq    v0, zero, La7ed8 [$800a7ed8]
V0 = S0 << 02;
S4 = 800af134;
S2 = ffffff;
800A7E34	lui    s3, $ff00
V0 = V0 + S0;
S1 = V0 << 03;

loopa7e40:	; 800A7E40
A0 = S0;
A1 = w[800ae034];
A2 = 0;
A1 = A1 >> 02;
800A7E54	jal    funca78e0 [$800a78e0]
A1 = A1 & 000f;
S0 = S0 + 0001;
A1 = w[800acfe0];
A2 = w[800c3740];
A1 = A1 << 02;
A1 = A1 + S4;
A0 = w[A1 + 0000];
800A7E7C	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = S1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & S2;
V1 = V1 & S3;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7EA0	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A1 + 0000];
V1 = V1 & S3;
V0 = V0 + S1;
V0 = V0 & S2;
V1 = V1 | V0;
V0 = S0 < 002a;
800A7EC4	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A7ED0	bne    v0, zero, loopa7e40 [$800a7e40]
S1 = S1 + 0028;

La7ed8:	; 800A7ED8
V0 = S0 < 002b;
800A7EDC	beq    v0, zero, La7f90 [$800a7f90]
V0 = S0 << 02;
T0 = ffffff;
800A7EEC	lui    t1, $ff00
V0 = V0 + S0;
A1 = V0 << 03;
V0 = w[800ae034];
V1 = 800af134;
T2 = V0 & 0010;
V0 = w[800acfe0];
A2 = w[800c3740];
V0 = V0 << 02;
A3 = V0 + V1;

loopa7f24:	; 800A7F24
800A7F24	bne    t2, zero, La7f80 [$800a7f80]
800A7F28	nop
A0 = w[A3 + 0000];
800A7F30	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = A1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & T0;
V1 = V1 & T1;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7F54	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A3 + 0000];
V1 = V1 & T1;
V0 = V0 + A1;
V0 = V0 & T0;
V1 = V1 | V0;
800A7F74	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);

La7f80:	; 800A7F80
S0 = S0 + 0001;
V0 = S0 < 002b;
800A7F88	bne    v0, zero, loopa7f24 [$800a7f24]
A1 = A1 + 0028;

La7f90:	; 800A7F90
V0 = S0 < S7;
800A7F94	beq    v0, zero, La8034 [$800a8034]
V0 = S0 << 02;
T0 = ffffff;
800A7FA4	lui    t1, $ff00
V0 = V0 + S0;
A1 = V0 << 03;
V1 = 800af134;
V0 = w[800acfe0];
A2 = w[800c3740];
V0 = V0 << 02;
A3 = V0 + V1;

loopa7fd0:	; 800A7FD0
S0 = S0 + 0001;
A0 = w[A3 + 0000];
800A7FD8	lui    at, $0001
AT = A2 + AT;
V0 = w[AT + 80e4];
A0 = A1 + A0;
V1 = w[A0 + 0000];
V0 = V0 & T0;
V1 = V1 & T1;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800A7FFC	lui    at, $0001
AT = A2 + AT;
V1 = w[AT + 80e4];
V0 = w[A3 + 0000];
V1 = V1 & T1;
V0 = V0 + A1;
V0 = V0 & T0;
V1 = V1 | V0;
V0 = S0 < S7;
800A8020	lui    at, $0001
AT = A2 + AT;
[AT + 80e4] = w(V1);
800A802C	bne    v0, zero, loopa7fd0 [$800a7fd0]
A1 = A1 + 0028;

La8034:	; 800A8034
V0 = w[800ae034];
800A803C	nop
V0 = V0 + 0001;
[800ae034] = w(V0);

La804c:	; 800A804C
////////////////////////////////



////////////////////////////////
// funca807c()

field_load_0592_tim_into_ram(); // load texture 0xaa from dir 0x4 into vram

S4 = 0;
[800ae038] = w(0);

A0 = 8;
A1 = 0;
system_memory_set_alloc_user();

A0 = 1108;
A1 = 0;
system_memory_allocate();
[800af134] = w(V0);

A0 = 1108;
A1 = 0;
system_memory_allocate();
[800af138] = w(V0);

FP = 800ae3ea;
S7 = FP - 6;
S5 = 800ae040;

for( int i = 0; i < 6d; ++i )
{
    V0 = w[800af134];
    S0 = V0 + i * 28;
    V0 = w[800af138];
    A0 = S0;
    S6 = V0 + i * 28;
    system_graphic_textured_quad_header();

    [S0 + 4] = b(80);
    [S0 + 5] = b(80);
    [S0 + 6] = b(80);

    A0 = 0;
    A1 = e8;
    system_graphic_get_clut_by_param();

    [S0 + 000e] = h(V0);
    V0 = hu[FP + i * 8 + 0];
    V0 = V0 >> 04;
    V1 = V0 & f;
    if( V1 == 0 )
    {
        S4 = 1;
    }
    else if( V1 == 1 )
    {
        S4 = 2;
    }

    A0 = 0;
    A1 = S4;
    A2 = 0380;
    A3 = 0;
    system_graphic_get_texpage_by_param();
    [S0 + 16] = h(V0);

    A0 = S0;
    A1 = 1;
    system_set_draw_packet_transparency();

    V1 = S7 + i * 8;
    V0 = S7 + i * 8;
    A0 = S7 + i * 8;
    T3 = 800ae03e;
    V0 = hu[V0 + 0004];
    V1 = hu[V1 + 0000];
    A0 = hu[A0 + 0002];
    V0 = V0 << 03;
    A2 = V0 + S5;
    A3 = S5 + V0;
    T0 = S5 + V0;
    V0 = V0 + T3;
    T1 = hu[A2 + 0000];
    T2 = hu[A3 + 0002];
    A3 = hu[T0 + fffc];
    T0 = hu[V0 + 0000];
    A1 = i * 8 + FP;
    [S0 + 0008] = h(V1);
    [S0 + 000a] = h(A0);
    [S0 + 0012] = h(A0);
    [S0 + 0018] = h(V1);
    V1 = V1 + T1;
    A0 = A0 + T2;
    [S0 + 0010] = h(V1);
    [S0 + 001a] = h(A0);
    [S0 + 0020] = h(V1);
    [S0 + 0022] = h(A0);
    V0 = hu[A1 + 0000];
    V1 = V0 & 000f;

    if( V1 == 0 )
    {
        A0 = S0;
        A1 = A3;
        A2 = T0;
        A3 = A1 + T1;
        V0 = A2 + T2;
        800A827C	j      La82d0 [$800a82d0]
    }
    else if( V1 == 1 )
    {
        A0 = S0;
        A1 = A3 + T1 - 1;
        A2 = T0;
        A3 = A3 - 1;
        V0 = A2 + T2;
        800A8298	j      La82d0 [$800a82d0]
    }
    if( V1 == 2 )
    {
        A0 = S0;
        A1 = A3;
        A2 = T0 + T2 - 1;
        A3 = A1 + T1;
        V0 = T0 - 1;
        800A82B0	j      La82d0 [$800a82cc]
    }
    if( V1 == 3 )
    {
        A0 = S0;
        A1 = A3 + T1 - 1;
        A2 = T0 + T2 - 1;
        A3 = A3 - 1;
        V0 = T0 - 1;
        800A827C	j      La82d0 [$800a82d0]
    }
    else
    {
        A0 = S0;
        A3 = S6;
        800A8268	j      La82ec [$800a82ec]
    }

    La82d0:	; 800A82D0
    [SP + 0010] = w(A2);
    [SP + 0014] = w(A1);
    [SP + 0018] = w(V0);
    [SP + 001c] = w(A3);
    [SP + 0020] = w(V0);
    field_set_quad_uv();

    A3 = S6;

    La82ec:	; 800A82EC
    A2 = S0;
    T0 = A2 + 0020;

    loopa82f4:	; 800A82F4
        V0 = w[A2 + 0000];
        V1 = w[A2 + 0004];
        A0 = w[A2 + 0008];
        A1 = w[A2 + 000c];
        [A3 + 0000] = w(V0);
        [A3 + 0004] = w(V1);
        [A3 + 0008] = w(A0);
        [A3 + 000c] = w(A1);
        A2 = A2 + 0010;
        A3 = A3 + 0010;
    800A8318	bne    a2, t0, loopa82f4 [$800a82f4]

    V0 = w[A2 + 0000];
    V1 = w[A2 + 0004];
    [A3 + 0000] = w(V0);
    [A3 + 0004] = w(V1);
}

[800ae74c] = w(1);
////////////////////////////////



////////////////////////////////
// field_particle_create_sprite_packets()

sprite_data = A0;
sprite_id = A1;
tranc = A2;

A0 = sprite_data + 50;
system_graphic_textured_quad_header();

[sprite_data + 54] = b(80);
[sprite_data + 55] = b(80);
[sprite_data + 56] = b(80);

x1 = hu[800ae750 + sprite_id * 18 + 4] << 4 - hu[800ae750 + sprite_id * 18 + 0] << 4;
y1 = hu[800ae750 + sprite_id * 18 + 6] << 4 - hu[800ae750 + sprite_id * 18 + 2] << 4;
x2 = hu[800ae750 + sprite_id * 18 + 4] << 4 + hu[800ae750 + sprite_id * 18 + 0] << 4;
y2 = hu[800ae750 + sprite_id * 18 + 6] << 4 + hu[800ae750 + sprite_id * 18 + 2] << 4;

[sprite_data + a0] = h(x1);
[sprite_data + a2] = h(y1);
[sprite_data + a4] = h(0);

[sprite_data + a8] = h(x2);
[sprite_data + aa] = h(y1);
[sprite_data + ac] = h(0);

[sprite_data + b0] = h(x1);
[sprite_data + b2] = h(y2);
[sprite_data + b4] = h(0);

[sprite_data + b8] = h(x2);
[sprite_data + ba] = h(y2);
[sprite_data + bc] = h(0);

A0 = sprite_data + 50; // addr
A1 = hu[800ae750 + sprite_id * 18 + 8]; // u1
A2 = hu[800ae750 + sprite_id * 18 + a] + 40; // v1
A3 = hu[800ae750 + sprite_id * 18 + c] - 1; // u2
A4 = hu[800ae750 + sprite_id * 18 + e] + 40; // v2
A5 = hu[800ae750 + sprite_id * 18 + 10]; // u3
A6 = hu[800ae750 + sprite_id * 18 + 12] + 3f; // v3
A7 = hu[800ae750 + sprite_id * 18 + 14] - 1; // u4
A8 = hu[800ae750 + sprite_id * 18 + 16] + 3f; // v4
field_set_quad_uv();

A0 = sprite_data + 50;
A1 = 1;
system_set_draw_packet_transparency();

A0 = 0;
A1 = tranc; // Semi Transparency (0=B/2+F/2, 1=B+F, 2=B-F, 3=B+F/4)
A2 = 3c0;
A3 = 140;
system_graphic_get_texpage_by_param();
[sprite_data + 66] = h(V0);

A0 = 100;
A1 = f7;
system_graphic_get_clut_by_param();
[sprite_data + 5e] = h(V0);

// copy quad to second buffer packet
A2 = sprite_data + 78;
A3 = sprite_data + 70;
S2 = sprite_data + 50;

loopa8530:	; 800A8530
    [A2 + 0] = w(w[S2 + 0]);
    [A2 + 4] = w(w[S2 + 4]);
    [A2 + 8] = w(w[S2 + 8]);
    [A2 + c] = w(w[S2 + c]);
    S2 = S2 + 10;
    A2 = A2 + 10;
800A8554	bne    s2, a3, loopa8530 [$800a8530]

[A2 + 0] = w(w[S2 + 0]);
[A2 + 4] = w(w[S2 + 4]);
////////////////////////////////



////////////////////////////////
// funca858c()

flag = A0;

if( w[800ad00c] == 1 )
{
    A0 = 8; // YOSI
    A1 = 0;
    system_memory_set_alloc_user();

    A0 = 8000;
    A1 = flag;
    system_memory_allocate();
    mem = V0;

    T0 = mem;
    A2 = w[800af144];
    loopa85dc:	; 800A85DC
        [T0] = w(w[A2]);
        T0 = T0 + 4;
        A2 = A2 + 4;
    800A8600	bne    a2, w[800af144] + 8000, loopa85dc [$800a85dc]

    A0 = w[800af144];
    system_memory_mark_removed_alloc();

    [800af144] = w(mem);
}
////////////////////////////////



////////////////////////////////
// field_particle_store_texture()

if( w[800ad00c] != 1 )
{
    [800ad00c] = w(1);

    A0 = 8; // YOSI
    A1 = 0;
    system_memory_set_alloc_user();

    A0 = 8000;
    A1 = 1;
    system_memory_allocate();
    [800af144] = w(V0);

    [800af0fc] = h(3c0); // x
    [800af0fe] = h(100); // y
    [800af100] = h(40); // width
    [800af102] = h(100); // height

    A0 = 800af0fc; // rect
    A1 = V0; // where to store
    system_store_image(); // from vram to memory

    A0 = 0; // wait for termination
    system_draw_sync();
}
////////////////////////////////



////////////////////////////////
// field_particle_load_texture()

if( w[800ad00c] != 0 )
{
    [800ad00c] = w(0);

    [800af0fc] = h(3c0);
    [800af0fe] = h(100);
    [800af100] = h(40);
    [800af102] = h(100);

    A0 = 800af0fc; // here
    A1 = w[800af144]; // from this pointer
    system_load_image();

    A0 = 0;
    system_draw_sync();

    A0 = w[800af144];
    system_memory_mark_removed_alloc();
}
////////////////////////////////



////////////////////////////////
// field_particle_clear_arrays()

for( int i = 0; i < 40; ++i )
{
    [800b0984 + i] = b(0);
    [800af5dc + i * 2] = h(-1);
}
////////////////////////////////



////////////////////////////////
// field_particle_remove()

id = A0;

if( bu[800b0984 + id] == 1 )
{
    S0 = w[800c2dec + id * 4];

    for( int i = 0; i < 8; ++i )
    {
        if( h[S0 + i * 78 + 6] != 0 )
        {
            A0 = w[S0 + i * 78 + 2c]; // sprite data
            system_memory_mark_removed_alloc();
        }
    }

    A0 = w[800c2dec + id * 4];
    system_memory_mark_removed_alloc();
}

[800b0984 + id] = b(0);
[800af5dc + id * 2] = h(-1);
////////////////////////////////



////////////////////////////////
// field_particle_reset_ttl_only()

if( bu[800b0984 + A0] == 1 )
{
    V1 = w[800c2dec + A0 * 4];

    for( int i = 0; i < 8; ++i )
    {
        number_of_sprites = h[V1 + i * 78 + 6];

        if( number_of_sprites != 0 )
        {
            [V1 + i * 78 + 4] = h(0); // reset ttl
        }
    }
}
////////////////////////////////



////////////////////////////////
// field_particle_reset_ttl_all()

if(  bu[800b0984 + A0] == 1 )
{
    V1 = w[800c2dec + A0 * 4];

    for( int i = 0; i < 8; ++i )
    {
        number_of_sprites = h[V1 + i * 78 + 6];

        if( number_of_sprites != 0 )
        {
            [V1 + i * 78 + 4] = h(0); // reset ttl

            for( j = 0; j < number_of_sprites; ++j )
            {
                V0 = w[V1 + i * 78 + 2c];
                [V0 + j * c0 + 4] = h(1); // reset ttl for sprites
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// field_particle_clear_all()

for( int i = 0; i < 40; ++i )
{
    A0 = i;
    field_particle_remove();
}

field_sync();
////////////////////////////////



////////////////////////////////
// field_particle_init_default_particle()

[800af518] = w(0);

for( int i = 0; i < 8; ++i )
{
    [800af7a0 + i * 78 + 0] = h(0);
    [800af7a0 + i * 78 + 2] = h(0);
    [800af7a0 + i * 78 + 4] = h(80);
    [800af7a0 + i * 78 + 6] = h(0);
    [800af7a0 + i * 78 + 8] = w(8000);
    [800af7a0 + i * 78 + c] = h(0);
    [800af7a0 + i * 78 + e] = h(0);
    [800af7a0 + i * 78 + 10] = h(0);
    [800af7a0 + i * 78 + 14] = h(0);
    [800af7a0 + i * 78 + 16] = h(-3e8);
    [800af7a0 + i * 78 + 18] = h(0);
    [800af7a0 + i * 78 + 1c] = h(0);
    [800af7a0 + i * 78 + 1e] = h(0);
    [800af7a0 + i * 78 + 20] = h(0);
    [800af7a0 + i * 78 + 24] = h(1);
    [800af7a0 + i * 78 + 26] = h(0);
    [800af7a0 + i * 78 + 28] = h(100);
    [800af7a0 + i * 78 + 2a] = h(0);

    for( int j = 0; j < 8; ++j )
    {
        [800af7a0 + i * 78 + 30 + j * 4 + 0] = h(0);
        [800af7a0 + i * 78 + 30 + j * 4 + 2] = h(0);
    }

    [800af7a0 + i * 78 + 50] = h(800);
    [800af7a0 + i * 78 + 52] = h(A0);
    [800af7a0 + i * 78 + 54] = h(0);
    [800af7a0 + i * 78 + 56] = h(1);
    [800af7a0 + i * 78 + 58] = h(1c);
    [800af7a0 + i * 78 + 5a] = h(1c8);
    [800af7a0 + i * 78 + 5c] = h(1c8);
    [800af7a0 + i * 78 + 5e] = h(1c8);
    [800af7a0 + i * 78 + 62] = h(20);
    [800af7a0 + i * 78 + 64] = h(20);
    [800af7a0 + i * 78 + 66] = h(20);
    [800af7a0 + i * 78 + 6a] = b(80);
    [800af7a0 + i * 78 + 6b] = b(20);
    [800af7a0 + i * 78 + 6c] = b(0);
    [800af7a0 + i * 78 + 6e] = b(-4);
    [800af7a0 + i * 78 + 6f] = b(-1);
    [800af7a0 + i * 78 + 70] = b(0);
    [800af7a0 + i * 78 + 76] = h(0);
}
////////////////////////////////



////////////////////////////////
// field_particle_update()

if( w[800ad00c] == 0 )
{
    // some matrix
    [SP + 10] = w(w[800aef38 + 0])
    [SP + 14] = w(w[800aef38 + 4])
    [SP + 18] = w(w[800aef38 + 8])
    [SP + 1c] = w(w[800aef38 + c])
    [SP + 20] = w(w[800aef38 + 10])
    [SP + 24] = w(w[800aef38 + 14])
    [SP + 28] = w(w[800aef38 + 18])
    [SP + 2c] = w(w[800aef38 + 1c])

    for( int i = 0; i < 40; ++i )
    {
        if( bu[800b0984 + i] == 1 )
        {
            not_fin = 0;
            particle_data = w[800c2dec + i * 4];

            for( int j = 0; j < 8; ++j )
            {
                [SP + 30] = w(0);

                if( h[particle_data + j * 78 + 6] != 0 )
                {
                    if( hu[particle_data + j * 78 + 2] == 0 )
                    {
                        for( int k = 0; k < h[particle_data + j * 78 + 6]; ++k )
                        {
                            sprite_data = w[particle_data + j * 78 + 2c];

                            if( h[sprite_data + k * c0 + 0] == 0 ) // if sprite not inited
                            {
                                if( hu[particle_data + j * 78 + 4] != 0 ) // if ttl exist
                                {
                                    A0 = particle_data + j * 78;
                                    A1 = sprite_data + k * c0;
                                    A2 = SP + 30;
                                    field_particle_sprite_init();

                                    A0 = particle_data + j * 78;
                                    A1 = sprite_data + k * c0;
                                    A2 = SP + 10;
                                    field_particle_sprite_update();

                                    not_fin = 1;
                                }
                            }
                            else
                            {
                                A0 = particle_data + j * 78;
                                A1 = sprite_data + k * c0;
                                A2 = SP + 10;
                                field_particle_sprite_update();

                                not_fin = 1;
                            }
                        }

                        if( hu[particle_data + j * 78 + 4] != 0 )
                        {
                            if( hu[particle_data + j * 78 + 4] != 7fff )
                            {
                                [particle_data + j * 78 + 4] = h(hu[particle_data + j * 78 + 4] - 1);
                            }
                            not_fin = 1;
                        }
                    }
                    else
                    {
                        [particle_data + j * 78 + 2] = h(hu[particle_data + j * 78 + 2] - 1);
                        not_fin = 1;
                    }
                }
            }

            // remove particle if finished
            if( not_fin == 0 )
            {
                A0 = i;
                field_particle_remove();
            }
        }
    }

    if( w[800c1b60] == 0 ) // PC HDD MODE
    {
        A0 = 8006f458; // "PARTICLE  "
        field_debug_add_timer();
    }
}
////////////////////////////////



////////////////////////////////
// field_particle_random()

S0 = A0;

system_get_random_2_bytes();

V1 = V0 * S0;
V0 = V1 + 1;
V0 = V0 >> f;
////////////////////////////////



////////////////////////////////
// field_patricle_find_empty()

for( int i = 0; i < 40; ++i )
{
    if( bu[800b0984 + i] == 0 )
    {
        return i;
    }
}
return -1;
////////////////////////////////



////////////////////////////////
// field_particle_reset_particle_for_entity()

entity_id = A0;
all = A1;

for( int i = 0; i < 40; ++i )
{
    if( h[800af5dc + i * 2] == entity_id )
    {
        V0 = w[800c2dec + i * 4];
        [V0 + 0 * 78 + 2] = h(0); // reset wait
        [V0 + 0 * 78 + 4] = h(0); // reset ttl

        if( all == 0 ) // only particle itself
        {
            A0 = i;
            field_particle_reset_ttl_only();
        }
        else // particle and sprites
        {
            A0 = i;
            field_particle_reset_ttl_all();
        }
    }
}
////////////////////////////////



////////////////////////////////
// field_particle_create_instance()

entity_id = A0;

field_patricle_find_empty();
S3 = V0;

if( S3 == -1 )
{
    return -1;
}

A0 = 8; // YOSI Kiyoshi Yoshii (Main Programmer)
A1 = 0;
system_memory_set_alloc_user();

[800ad01c] = w(entity_id);
[800b0984 + S3] = b(1); // set that we init memory for this id
[800af5dc + S3 * 2] = h(entity_id);

A0 = 3c0;
A1 = 0;
system_memory_allocate();
particle_mem = V0;

[800c2dec + S3 * 4] = w(particle_mem);

// copy particle data into particle instance
into = particle_mem;
from = 800af7a0;
loopa8f10:	; 800A8F10
    [into] = w(w[from]);
    into = into + 4;
    from = from + 4;
800A8F34	bne    from, 800af7a0 + 3c0, loopa8f10 [$800a8f10]

for( int i = 0; i < 8; ++i )
{
    sprite_num = h[particle_mem + i * 78 + 6];

    if( sprite_num > 0 )
    {
        A0 = sprite_num * c0;
        A1 = 0;
        system_memory_allocate();
        sprite_data = V0;

        [particle_mem + i * 78 + 2c] = w(sprite_data);

        for( int j = 0; j < sprite_num; ++j )
        {
            [sprite_data + j * c0 + 0] = h(0);

            A0 = sprite_data + j * c0; // buffer
            A1 = h[particle_mem + i * 78 + 54]; // particle id
            A2 = (((hu[particle_mem + i * 78 + 2a] << 10) >> 18) + 1) & 3; // transparency
            field_particle_create_sprite_packets();
        }
    }
}

return 1;
////////////////////////////////



////////////////////////////////
// field_particle_colour_sum()

A0 = A0 + A1;

if( A0 < 0 )
{
    A0 = 0;
}
else if( A0 >= 100 )
{
    A0 = ff;
}
return A0;
////////////////////////////////



////////////////////////////////
// field_particle_sprite_packet_update()

buffer_id = w[800acfe0];

sprite_data = A0;
camera_matrix = A1;
rotation = A2;
order = A3;
scale_vector = A4;
use_scale = A5;

[SP + 88] = h(0);
[SP + 8a] = h(0);
[SP + 8c] = h(rotation);

A0 = SP + 88; // input rot vector
A1 = SP + 48; // rotation sprite matrix
system_calculate_rotation_matrix();

// add sprite translation
[SP + 5c] = w(w[sprite_data +  8] >> c); // x
[SP + 60] = w(w[sprite_data +  c] >> c); // y
[SP + 64] = w(w[sprite_data + 10] >> c); // z

if( use_scale == 3 )
{
    [SP + 68] = w(w[camera_matrix +  0]);
    [SP + 6c] = w(w[camera_matrix +  4]);
    [SP + 70] = w(w[camera_matrix +  8]);
    [SP + 74] = w(w[camera_matrix +  c]);
    [SP + 78] = w(w[camera_matrix + 10]);
    [SP + 7c] = w(w[camera_matrix + 14]);
    [SP + 80] = w(w[camera_matrix + 18]);
    [SP + 84] = w(w[camera_matrix + 1c]);

    A0 = SP + 68; // camera scale matrix
    A1 = scale_vector;
    system_gte_multiply_matrix_by_vector();

    A0 = SP + 68; // camera scale matrix
    A1 = SP + 48; // sprite matrix
    A2 = SP + 28; // camera sprite matrix
    system_gte_matrix_mult_and_trans();

    A0 = SP + 28; // sprite matrix
    A1 = SP + 48;
    func7372c(); // copy A1 to A0

    // add trans
    [SP + 90] = w(h[sprite_data + 38]);
    [SP + 94] = w(h[sprite_data + 3a]);
    [SP + 98] = w(h[sprite_data + 3c]);

    A0 = SP + 28; // sprite matrix
    A1 = SP + 90;
    system_gte_multiply_matrix_by_vector();

    [sprite_data + buffer_id * 20 + 54] = b(bu[sprite_data + 48]);
    [sprite_data + buffer_id * 20 + 55] = b(bu[sprite_data + 49]);
    [sprite_data + buffer_id * 20 + 56] = b(bu[sprite_data + 4a]);

    A0 = SP + 28;
    system_gte_set_translation_vector();

    A0 = SP + 28;
    A1 = scale_vector;
    system_gte_multiply_matrix_by_vector();

    A0 = SP + 28;
    system_gte_set_rotation_matrix();
}
else
{
    A0 = camera_matrix;
    A1 = SP + 48; // sprite matrix
    A2 = SP + 28; // camera sprite matrix
    system_gte_matrix_mult_and_trans();

    A0 = SP + 28; // sprite matrix
    A1 = SP + 48;
    func7372c(); // copy A1 to A0

    // add trans
    [SP + 90] = w(h[sprite_data + 38]);
    [SP + 94] = w(h[sprite_data + 3a]);
    [SP + 98] = w(h[sprite_data + 3c]);

    A0 = SP + 28;
    A1 = SP + 90;
    system_gte_multiply_matrix_by_vector();

    [sprite_data + buffer_id * 20 + 54] = b(bu[sprite_data + 48]);
    [sprite_data + buffer_id * 20 + 55] = b(bu[sprite_data + 49]);
    [sprite_data + buffer_id * 20 + 56] = b(bu[sprite_data + 4a]);

    A0 = SP + 28;
    system_gte_set_translation_vector();

    A0 = SP + 28;
    system_gte_set_rotation_matrix();
}

A0 = sprite_data + a0; // xyz0
A1 = sprite_data + a8; // xyz1
A2 = sprite_data + b0; // xyz3
A3 = sprite_data + b8; // xyz2
A4 = sprite_data + 50 + buffer_id * 20 +  8; // xy0
A5 = sprite_data + 50 + buffer_id * 20 + 10; // xy1
A6 = sprite_data + 50 + buffer_id * 20 + 18; // xy3
A7 = sprite_data + 50 + buffer_id * 20 + 20; // xy2
A8 = SP + a0; // Interpolation value for depth queing
A9 = SP + a0; // return flags
func4a664(); // transform 4 points by rotation matrix
OTZ = V0;

if( order == 0 )
{
    depth = 1;
}
if( order == 1 )
{
    depth = (OTZ >> w[8004f7a4]) - 10;
}
else if( order == 2 )
{
    depth = OTZ >> w[8004f7a4];
}
else if( order == 3 )
{
    depth = (OTZ >> w[8004f7a4]) + 10;
}

if( ( depth - 1 ) < fff )
{
    otag = w[800c3740];
    [sprite_data + 50 + buffer_id * 20] = w((w[sprite_data + 50 + buffer_id * 20] & ff000000) | (w[otag + cc + depth * 4] & 00ffffff));
    [otag + cc + depth * 4] = w((w[otag + cc + depth * 4] & ff000000) | ((sprite_data + 50 + buffer_id * 20) & 00ffffff));
}
////////////////////////////////



////////////////////////////////
// field_particle_sprite_update()

particle_data = A0;
sprite_data = A1;
matrix = A2;

if( hu[sprite_data + 2] != 0 )
{
    [sprite_data + 2] = h(hu[sprite_data + 2] - 1);

    if( hu[sprite_data + 2] == 0 ) // update after waiting
    {
        [SP + 44] = w(0);
        [SP + 48] = w(0);
        [SP + 4c] = w(0);

        V1 = (hu[particle_data + 2a] >> 4) & 3;
        update_scale = 0;

        if( V1 == 0 )
        {
            entity_id = h[particle_data + 52];
            V1 = w[800aefe4];
            entity_data = w[V1 + entity_id * 5c + 4c];

            // current rotation from entity
            [SP + 28] = h(0);
            [SP + 2a] = h(hu[entity_data + 108]);
            [SP + 2c] = h(0);

            A0 = SP + 28;
            A1 = SP + 30;
            system_calculate_rotation_matrix();

            // current pos from entity
            [SP + 70] = w(h[entity_data + 22]);
            [SP + 74] = w(h[entity_data + 26]);
            [SP + 78] = w(h[entity_data + 2a]);

            [particle_data + 50] = h(1000);
        }
        else if( V1 == 1 )
        {
            A0 = SP + 30;
            A1 = SP + 50;
            A2 = h[particle_data + 72];
            A3 = h[particle_data + 74];
            800A96A8	jal    func1e72cc [$801e72cc]

            A0 = SP + 30;
            system_gte_set_rotation_matrix();

            A0 = SP + 30;
            system_gte_set_translation_vector();

            [SP + 28] = h(hu[particle_data +  c]);
            [SP + 2a] = h(hu[particle_data +  e]);
            [SP + 2c] = h(hu[particle_data + 10]);

            A0 = SP + 28; // input
            A1 = SP + 70; // output
            A2 = SP + b0; // FLAG
            system_gte_rotate_translate_vector();

            // set scale
            [particle_data + 50] = h(1000);
        }
        else if( V1 == 2 )
        {
            entity_id = h[particle_data + 52];
            V1 = w[800aefe4];
            [SP + 30] = w(w[V1 + entity_id * 5c + 2c]);
            [SP + 34] = w(w[V1 + entity_id * 5c + 30]);
            [SP + 38] = w(w[V1 + entity_id * 5c + 34]);
            [SP + 3c] = w(w[V1 + entity_id * 5c + 38]);
            [SP + 40] = w(w[V1 + entity_id * 5c + 3c]);
            [SP + 44] = w(w[V1 + entity_id * 5c + 40]);
            [SP + 48] = w(w[V1 + entity_id * 5c + 44]);
            [SP + 4c] = w(w[V1 + entity_id * 5c + 48]);

            A0 = SP + 30;
            system_gte_set_rotation_matrix();

            A0 = SP + 30;
            system_gte_set_translation_vector();

            [SP + 28] = h(hu[particle_data +  c]);
            [SP + 2a] = h(hu[particle_data +  e]);
            [SP + 2c] = h(hu[particle_data + 10]);

            A0 = SP + 28; // input
            A1 = SP + 70; // output
            A2 = SP + b0; // FLAG
            system_gte_rotate_translate_vector();

            // set scale
            [particle_data + 50] = h(1000);
        }
        else if( V1 == 3 )
        {
            entity_id = h[particle_data + 52];
            V1 = w[800aefe4];
            entity_data = w[V1 + entity_id * 5c + 4c];

            // current rotation from entity
            [SP + 28] = h(0);
            [SP + 2a] = h(hu[entity_data + 108]);
            [SP + 2c] = h(0);

            A0 = SP + 28;
            A1 = SP + 30;
            system_calculate_rotation_matrix();

            // current pos from entity
            [SP + 70] = w(h[entity_data + 22]);
            [SP + 74] = w(h[entity_data + 26]);
            [SP + 78] = w(h[entity_data + 2a]);

            // set scale from entity
            update_scale = 1;
            [particle_data + 50] = h(hu[entity_data + f4]); // scale x from entity
        }

        // add translation vector
        [SP + 44] = w(0);
        [SP + 48] = w(0);
        [SP + 4c] = w(0);

        A0 = SP + 30;
        system_gte_set_rotation_matrix();

        A0 = SP + 30;
        system_gte_set_translation_vector();

        // update speed vector with needed rotation
        [SP + 28] = h(w[sprite_data + 18]);
        [SP + 2a] = h(w[sprite_data + 1c]);
        [SP + 2c] = h(w[sprite_data + 20]);
        A0 = SP + 28;
        A1 = SP + 18; // speed vector
        system_gte_rotate_vector();

        // normalize speed vector
        A0 = SP + 18;
        A1 = sprite_data + 18;
        system_gte_normalize_word_vector_T0_T1_T2_to_word();

        // update speed vector
        [sprite_data + 18] = w(h[particle_data + 24] * ((w[sprite_data + 18] * w[particle_data + 8]) >> c));
        [sprite_data + 1c] = w(h[particle_data + 24] * ((w[sprite_data + 1c] * w[particle_data + 8]) >> c));
        [sprite_data + 20] = w(h[particle_data + 24] * ((w[sprite_data + 20] * w[particle_data + 8]) >> c));

        // scale pos
        if( update_scale == 1 )
        {
            [sprite_data +  8] = w((h[particle_data + 50] * w[sprite_data +  8]) >> c);
            [sprite_data +  c] = w((h[particle_data + 50] * w[sprite_data +  c]) >> c);
            [sprite_data + 10] = w((h[particle_data + 50] * w[sprite_data + 10]) >> c);
        }

        A0 = SP + 30;
        system_gte_set_rotation_matrix();

        A0 = SP + 30;
        system_gte_set_translation_vector();

        // sprite pos
        [SP + 28] = h(w[sprite_data +  8]);
        [SP + 2a] = h(w[sprite_data +  c]);
        [SP + 2c] = h(w[sprite_data + 10]);

        A0 = SP + 28; // input
        A1 = SP + 18; // output sprite pos vector
        A2 = SP + b0; // FLAG
        system_gte_rotate_translate_vector();

        if( update_scale == 1 )
        {
            [SP + 28] = h(w[800af588] - 400);
            [SP + 2a] = h(0 - hu[800aee62]);
            [SP + 2c] = h(0);

            A0 = SP + 28;
            A1 = SP + 50;
            800A98F4	jal    func4aa64 [$8004aa64]

            A0 = SP + 50;
            system_gte_set_rotation_matrix();

            A0 = SP + 50;
            system_gte_set_translation_vector();

            [SP + 80] = w(0);
            [SP + 84] = w(w[SP + 1c]);
            [SP + 88] = w(0);

            A0 = SP + 80;
            A1 = SP + 90;
            800A9920	jal    func49834 [$80049834]

            [SP + 18] = w(w[SP + 90] + w[SP + 18]);
            [SP + 1c] = w(w[SP + 94]);
            [SP + 20] = w(w[SP + 98] + w[SP + 20]);

            [sprite_data +  8] = w((w[SP + 70] + w[SP + 18]) * (1000000 / h[particle_data + 50]));
            [sprite_data +  c] = w((w[SP + 74] + w[SP + 1c]) * (1000000 / h[particle_data + 50]));
            [sprite_data + 10] = w((w[SP + 78] + w[SP + 20]) * (1000000 / h[particle_data + 50]));
        }
        else
        {
            // set pos as needed pos (from entity for example) with inner sprite pos
            [sprite_data +  8] = w((w[SP + 70] + w[SP + 18]) << c);
            [sprite_data +  c] = w((w[SP + 74] + w[SP + 1c]) << c);
            [sprite_data + 10] = w((w[SP + 78] + w[SP + 20]) << c);
        }
    }
}
else
{
    // increment translation
    [sprite_data + 38] = h(hu[sprite_data + 38] + hu[sprite_data + 40]);
    [sprite_data + 3a] = h(hu[sprite_data + 3a] + hu[sprite_data + 42]);
    [sprite_data + 3c] = h(hu[sprite_data + 3c] + hu[sprite_data + 44]);

    // update speed
    [sprite_data + 18] = w(w[sprite_data + 18] + w[sprite_data + 28]);
    [sprite_data + 1c] = w(w[sprite_data + 1c] + w[sprite_data + 2c]);
    [sprite_data + 20] = w(w[sprite_data + 20] + w[sprite_data + 30]);

    // update position
    [sprite_data +  8] = w(w[sprite_data +  8] + w[sprite_data + 18]);
    [sprite_data +  c] = w(w[sprite_data +  c] + w[sprite_data + 1c]);
    [sprite_data + 10] = w(w[sprite_data + 10] + w[sprite_data + 20]);

    // update colours
    A0 = bu[sprite_data + 48]; // r
    A1 = b[sprite_data + 4c];
    field_particle_colour_sum();
    [sprite_data + 48] = b(V0);

    A0 = bu[sprite_data + 49]; // g
    A1 = b[sprite_data + 4d];
    field_particle_colour_sum();
    [sprite_data + 49] = b(V0);

    A0 = bu[sprite_data + 4a]; // b
    A1 = b[sprite_data + 4e];
    field_particle_colour_sum();
    [sprite_data + 4a] = b(V0);

    // create scale vector
    [SP + a0] = w(h[particle_data + 50]);
    [SP + a4] = w(h[particle_data + 50]);
    [SP + a8] = w(h[particle_data + 50]);

    if( hu[sprite_data + 4] != 1 )
    {
        A0 = sprite_data;
        A1 = matrix;
        A2 = h[sprite_data + 6]; // z rotation
        A3 = (hu[particle_data + 2a] >> 1) & 3; // order 0 - bottom, 1 - lower than real, 2 - real, 3 - higher than real
        A4 = SP + a0; // patricle scale vector
        A5 = (hu[particle_data + 2a] >> 4) & 3; // use scale
        field_particle_sprite_packet_update();
    }

    [sprite_data + 4] = h(hu[sprite_data + 4] - 1);

    if( hu[sprite_data + 4] == 0 )
    {
        [sprite_data + 0] = h(0); // set to reinitialize
    }
}
////////////////////////////////



////////////////////////////////
// field_particle_sprite_init()

particle_data = A0;
sprite_data = A1;

[sprite_data + 0] = h(1); // inited

[sprite_data + 2] = h(hu[particle_data + 56] + w[A2 + 0]); // set wait
[A2 + 0] = w(w[A2 + 0] + hu[particle_data + 56]);
[sprite_data + 4] = h(hu[particle_data + 58]);

if( hu[particle_data + 2a] & 0001 )
{
    system_get_random_2_bytes();
    [sprite_data + 6] = h(V0 & fff); // set random rotation
}
else
{
    [sprite_data + 6] = h(hu[particle_data + 76]); // set rotation from particle
}

if( ( hu[particle_data + 2a] & 0080 ) == 0 )
{
    A0 = hu[particle_data + 26];
    field_particle_random();
    src_rnd = V0;
}
else
{
    src_rnd = hu[particle_data + 26];
}

A0 = fff;
field_particle_random();
angle = V0;

A0 = angle;
system_cos();
src_x = (V0 * src_rnd) >> c;

if( ( hu[particle_data + 2a] & 0040 ) == 0 )
{
    A0 = angle;
    system_sin();
    src_z = (V0 * src_rnd) >> c;
}
else
{
    src_z = 0;
}

entity_id = h[particle_data + 52];
V1 = w[800aefe4];
entity_data = w[V1 + entity_id * 5c + 4c];
V0 = (h[800aee62] + h[entity_data + 108]) & fff;

A0 = bu[800ae948 + V0 / 200];

src_x = src_x + h[particle_data + c] + h[particle_data + 30 + A0 * 4 + 0];
src_y = h[particle_data + e];
src_z = src_z + h[particle_data + 10] + h[particle_data + 30 + A0 * 4 + 2];

[sprite_data +  8] = w(src_x);
[sprite_data +  c] = w(src_y);
[sprite_data + 10] = w(src_z);

A0 = hu[particle_data + 28];
field_particle_random();
dst_rnd = V0;

A0 = angle;
system_cos();
dst_x = h[particle_data + 14] + ((V0 * dst_rnd) >> c);

dst_y = h[particle_data + 16];

A0 = angle;
system_sin();
dst_z = h[particle_data + 18] + ((V0 * dst_rnd) >> c);

[sprite_data + 18] = w(dst_x - src_x); // speed x
[sprite_data + 1c] = w(dst_y - src_y); // speed y
[sprite_data + 20] = w(dst_z - src_z); // speed z
[sprite_data + 28] = w(h[particle_data + 1c]); // accel x
[sprite_data + 2c] = w(h[particle_data + 1e]); // accel y
[sprite_data + 30] = w(h[particle_data + 20]); // accel z
[sprite_data + 38] = h(hu[particle_data + 5a]); // x trans
[sprite_data + 3a] = h(hu[particle_data + 5c]); // y trans
[sprite_data + 3c] = h(hu[particle_data + 5e]); // z trans
[sprite_data + 40] = h(hu[particle_data + 62]); // x trans add
[sprite_data + 42] = h(hu[particle_data + 64]); // y trans add
[sprite_data + 44] = h(hu[particle_data + 66]); // x trans add
[sprite_data + 48] = b(bu[particle_data + 6a]); // R.
[sprite_data + 49] = b(bu[particle_data + 6b]); // G.
[sprite_data + 4a] = b(bu[particle_data + 6c]); // B.
[sprite_data + 4c] = b(bu[particle_data + 6e]); // R add.
[sprite_data + 4d] = b(bu[particle_data + 6f]); // G add.
[sprite_data + 4e] = b(bu[particle_data + 70]); // B add.
////////////////////////////////



////////////////////////////////
// funca9eb4()

model_data = A0;

m_parts = w[model_data + 4];

x1 = h[m_parts + 20];
y1 = h[m_parts + 22];
z1 = h[m_parts + 24];
x2 = h[m_parts + 28];
y2 = h[m_parts + 2a];
z2 = h[m_parts + 2c];

dx = x2 - x1;
dy = y2 - y1;
dz = z2 - z1;

if( dx < dy )
{
    A1 = dy;
}
if( A1 < dz )
{
    A1 = dz;
}

[model_data + 18] = h(x1 + dx / 2);
[model_data + 1a] = h(y1 + dy / 2);
[model_data + 1c] = h(z1 + dz / 2);
[model_data + 20] = h(A1 * 2 + 1);
////////////////////////////////



////////////////////////////////
// funca9f4c
800A9F4C	addiu  sp, sp, $ffa8 (=-$58)
[SP + 004c] = w(S5);
S5 = A0;
A0 = S5 + 0018;
A1 = SP + 0010;
[SP + 0040] = w(S2);
S2 = SP + 0028;
A2 = S2;
[SP + 0050] = w(RA);
[SP + 0048] = w(S4);
[SP + 0044] = w(S3);
[SP + 003c] = w(S1);
800A9F7C	jal    $8004a584
[SP + 0038] = w(S0);
V0 = 800af5d0;
800A9F8C	addiu  s0, v0, $ffec (=-$14)
V1 = w[SP + 0010];
A1 = w[SP + 0014];
A2 = w[SP + 0018];
[V0 + 0000] = w(V1);
[800af5d4] = w(A1);
[800af5d8] = w(A2);
800A9FB0	jal    $system_gte_set_rotation_matrix
A0 = S0;
800A9FB8	jal    $system_gte_set_translation_vector
A0 = S0;
S4 = SP + 0020;
A0 = S4;
S3 = SP + 002c;
A1 = S3;
S1 = SP + 0030;
A2 = S1;
S0 = h[S5 + 0020];
A3 = S2;
[SP + 0024] = h(0);
V0 = 0 - S0;
[SP + 0020] = h(V0);
800A9FEC	jal    $8004a4f4
[SP + 0022] = h(V0);
A0 = S4;
A1 = S3;
A2 = S1;
V0 = w[SP + 002c];
A3 = S2;
[SP + 0020] = h(S0);
[SP + 0022] = h(S0);
[SP + 0024] = h(0);
S0 = V0 >> 10;
V0 = V0 << 10;
800AA01C	jal    $8004a4f4
S1 = V0 >> 10;
V1 = w[SP + 002c];
A0 = w[800c2f34];
A1 = V1 >> 10;
V1 = V1 << 10;
A2 = V1 >> 10;
V1 = A0 + 00e0;
S0 = S0 < V1;
800AA044	beq    s0, zero, Laa088 [$800aa088]
800AA048	addiu  v0, zero, $ffff (=-$1)
V1 = 0 - A0;
V1 = V1 < A1;
800AA054	beq    v1, zero, Laa088 [$800aa088]
800AA058	nop
A0 = w[800c2f30];
800AA064	nop
V1 = A0 + 0140;
V1 = S1 < V1;
800AA070	beq    v1, zero, Laa088 [$800aa088]
800AA074	nop
V0 = 0 - A0;
V0 = V0 < A2;
V0 = V0 ^ 0001;
V0 = 0 - V0;

Laa088:	; 800AA088
RA = w[SP + 0050];
S5 = w[SP + 004c];
S4 = w[SP + 0048];
S3 = w[SP + 0044];
S2 = w[SP + 0040];
S1 = w[SP + 003c];
S0 = w[SP + 0038];
SP = SP + 0058;
800AA0A8	jr     ra 
800AA0AC	nop
////////////////////////////////
// funcaa0b0
A0 = w[800af13c];
800AA0B8	addiu  sp, sp, $ffe8 (=-$18)
[SP + 0010] = w(RA);
800AA0C0	jal    $system_memory_mark_removed_alloc
800AA0C4	nop
800AA0C8	jal    $system_draw_sync
A0 = 0;
RA = w[SP + 0010];
SP = SP + 0018;
800AA0D8	jr     ra 
800AA0DC	nop
////////////////////////////////
// funcaa0e0
800AA0E0	addiu  sp, sp, $ffb8 (=-$48)
A0 = 0840;
A1 = 0;
[SP + 0044] = w(RA);
[SP + 0040] = w(FP);
[SP + 003c] = w(S7);
[SP + 0038] = w(S6);
[SP + 0034] = w(S5);
[SP + 0030] = w(S4);
[SP + 002c] = w(S3);
[SP + 0028] = w(S2);
[SP + 0024] = w(S1);
800AA110	jal    $system_memory_allocate
[SP + 0020] = w(S0);
S2 = 0;
S5 = SP + 0018;
S6 = 0080;
FP = 00e0;
S7 = 0070;
S4 = 0318;
S1 = 0;
[800af13c] = w(V0);
V0 = 00ff;
[SP + 0018] = h(0);
[SP + 001a] = h(0);
[SP + 001c] = h(V0);
[SP + 001e] = h(V0);

loopaa150:	; 800AA150
A0 = 0;
A1 = 0;
A2 = 03c0;
800AA15C	jal    $system_graphic_get_texpage_by_param
A3 = 0100;
A1 = 0;
A2 = 0;
A0 = w[800af13c];
A3 = V0 & ffff;
[SP + 0010] = w(S5);
800AA17C	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + S1;
A0 = 0;
A1 = 0;
A2 = 03c0;
800AA190	jal    $system_graphic_get_texpage_by_param
A3 = 0140;
A1 = 0;
A2 = 0;
A0 = w[800af13c];
A3 = V0 & ffff;
[SP + 0010] = w(S5);
A0 = A0 + S1;
800AA1B4	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + 000c;
V0 = w[800af13c];
800AA1C4	nop
S0 = V0 + S4;
800AA1CC	jal    $80043b8c
A0 = S0;
S3 = S0 + 0014;
[S0 + 0004] = b(S6);
[S0 + 0005] = b(S6);
800AA1E0	bne    s2, zero, Laa1f8 [$800aa1f8]
[S0 + 0006] = b(S6);
V0 = 0010;
[S0 + 000c] = b(FP);
800AA1F0	j      Laa208 [$800aa208]
[S0 + 000d] = b(S7);

Laa1f8:	; 800AA1F8
V0 = 0060;
[S0 + 000d] = b(V0);
V0 = 0008;
[S0 + 000c] = b(FP);

Laa208:	; 800AA208
[S0 + 0010] = h(V0);
[S0 + 0012] = h(V0);
A0 = 0100;
A1 = 00f7;
V0 = 00a0;
[S0 + 0008] = h(V0);
800AA220	jal    $800438d0
[S0 + 000a] = h(S7);
[S0 + 000e] = h(V0);
V0 = w[S0 + 0000];
V1 = w[S0 + 0004];
A0 = w[S0 + 0008];
A1 = w[S0 + 000c];
[S3 + 0000] = w(V0);
[S3 + 0004] = w(V1);
[S3 + 0008] = w(A0);
[S3 + 000c] = w(A1);
V0 = w[S0 + 0010];
800AA250	nop
[S3 + 0010] = w(V0);
S4 = S4 + 0028;
S2 = S2 + 0001;
V0 = S2 < 0021;
800AA264	bne    v0, zero, loopaa150 [$800aa150]
S1 = S1 + 0018;
RA = w[SP + 0044];
FP = w[SP + 0040];
S7 = w[SP + 003c];
S6 = w[SP + 0038];
S5 = w[SP + 0034];
S4 = w[SP + 0030];
S3 = w[SP + 002c];
S2 = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0048;
800AA298	jr     ra 
800AA29C	nop
////////////////////////////////
// funcaa2a0
V1 = A0 << 02;
V1 = V1 + A0;
V0 = w[800af13c];
V1 = V1 << 03;
V0 = V1 + V0;
[V0 + 031c] = b(A1);
V0 = w[800af13c];
800AA2C4	nop
V0 = V1 + V0;
[V0 + 031d] = b(A2);
V0 = w[800af13c];
800AA2D8	nop
V0 = V1 + V0;
[V0 + 031e] = b(A3);
V0 = w[800af13c];
800AA2EC	nop
V0 = V1 + V0;
[V0 + 0330] = b(A1);
V0 = w[800af13c];
800AA300	nop
V0 = V1 + V0;
[V0 + 0331] = b(A2);
V0 = w[800af13c];
800AA314	nop
V1 = V1 + V0;
800AA31C	jr     ra 
[V1 + 0332] = b(A3);
////////////////////////////////
// funcaa324
T4 = A0;
800AA328	beq    a3, zero, Laa344 [$800aa344]
A0 = A2;
V0 = 0001;
800AA334	beq    a3, v0, Laa34c [$800aa34c]
800AA338	lui    t3, $00ff
800AA33C	j      Laa358 [$800aa358]
800AA340	nop

Laa344:	; 800AA344
800AA344	j      Laa350 [$800aa350]
800AA348	addiu  a0, a0, $fff4 (=-$c)

Laa34c:	; 800AA34C
800AA34C	addiu  a0, a0, $fffc (=-$4)

Laa350:	; 800AA350
800AA350	addiu  a1, a1, $fffc (=-$4)
800AA354	lui    t3, $00ff

Laa358:	; 800AA358
T3 = T3 | ffff;
V1 = T4 << 02;
V1 = V1 + T4;
V1 = V1 << 03;
800AA368	lui    t0, $ff00
T2 = w[800acfe0];
T1 = w[800af13c];
A3 = w[800c3740];
A2 = T2 << 02;
A2 = A2 + T2;
A2 = A2 << 02;
V0 = A2 + V1;
V0 = T1 + V0;
[V0 + 0320] = h(A1);
A1 = V1 + T1;
A1 = A2 + A1;
V1 = V1 + 0318;
V1 = T1 + V1;
V1 = V1 + A2;
V1 = V1 & T3;
[V0 + 0322] = h(A0);
A0 = w[A1 + 0318];
800AA3BC	lui    at, $0001
AT = A3 + AT;
V0 = w[AT + 80d4];
A0 = A0 & T0;
V0 = V0 & T3;
A0 = A0 | V0;
V0 = T4 << 01;
V0 = V0 + T4;
V0 = V0 << 03;
[A1 + 0318] = w(A0);
800AA3E4	lui    at, $0001
AT = A3 + AT;
A0 = w[AT + 80d4];
V0 = V0 + T1;
A0 = A0 & T0;
A0 = A0 | V1;
V1 = T2 << 01;
V1 = V1 + T2;
V1 = V1 << 02;
V1 = V1 + V0;
800AA40C	lui    at, $0001
AT = A3 + AT;
[AT + 80d4] = w(A0);
V0 = w[V1 + 0000];
A0 = A0 & T3;
V0 = V0 & T0;
V0 = V0 | A0;
[V1 + 0000] = w(V0);
800AA42C	lui    at, $0001
AT = A3 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T3;
V0 = V0 & T0;
V0 = V0 | V1;
800AA444	lui    at, $0001
AT = A3 + AT;
[AT + 80d4] = w(V0);
800AA450	jr     ra 
800AA454	nop
////////////////////////////////
// funcaa458
800AA458	addiu  sp, sp, $ffb8 (=-$48)
A0 = 02f8;
A1 = 0;
[SP + 0044] = w(RA);
[SP + 0040] = w(FP);
[SP + 003c] = w(S7);
[SP + 0038] = w(S6);
[SP + 0034] = w(S5);
[SP + 0030] = w(S4);
[SP + 002c] = w(S3);
[SP + 0028] = w(S2);
[SP + 0024] = w(S1);
800AA488	jal    $system_memory_allocate
[SP + 0020] = w(S0);
A0 = 0400;
[800c2f10] = w(V0);
800AA49C	jal    $system_memory_allocate
A1 = 0;
S1 = 0;
S5 = SP + 0018;
S6 = 0080;
FP = 0070;
S7 = 00e0;
S4 = 0180;
S3 = 0;
[800b12c4] = w(V0);
V0 = 00ff;
[SP + 0018] = h(0);
[SP + 001a] = h(0);
[SP + 001c] = h(V0);
[SP + 001e] = h(V0);

loopaa4dc:	; 800AA4DC
A0 = 0;
A1 = 0;
A2 = 03c0;
800AA4E8	jal    $system_graphic_get_texpage_by_param
A3 = 0140;
A1 = 0;
A2 = 0;
A0 = w[800b12c4];
A3 = V0 & ffff;
[SP + 0010] = w(S5);
800AA508	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + S3;
A0 = 0;
A1 = 0;
A2 = 03c0;
800AA51C	jal    $system_graphic_get_texpage_by_param
A3 = 0140;
A1 = 0;
A2 = 0;
A0 = w[800b12c4];
A3 = V0 & ffff;
[SP + 0010] = w(S5);
A0 = A0 + S3;
800AA540	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + 000c;
V0 = w[800b12c4];
800AA550	nop
S0 = V0 + S4;
800AA558	jal    $80043b8c
A0 = S0;
V0 = 00a0;
S2 = S0 + 0014;
[S0 + 0004] = b(S6);
[S0 + 0005] = b(S6);
[S0 + 0006] = b(S6);
[S0 + 0008] = h(V0);
800AA578	bne    s1, zero, Laa590 [$800aa590]
[S0 + 000a] = h(FP);
V0 = 0010;
[S0 + 000c] = b(S7);
800AA588	j      Laa5a0 [$800aa5a0]
[S0 + 000d] = b(FP);

Laa590:	; 800AA590
V0 = 0060;
[S0 + 000d] = b(V0);
V0 = 0008;
[S0 + 000c] = b(S7);

Laa5a0:	; 800AA5A0
[S0 + 0010] = h(V0);
[S0 + 0012] = h(V0);
A0 = 0100;
800AA5AC	jal    $800438d0
A1 = 00f7;
[S0 + 000e] = h(V0);
V0 = w[S0 + 0000];
V1 = w[S0 + 0004];
A0 = w[S0 + 0008];
A1 = w[S0 + 000c];
[S2 + 0000] = w(V0);
[S2 + 0004] = w(V1);
[S2 + 0008] = w(A0);
[S2 + 000c] = w(A1);
V0 = w[S0 + 0010];
800AA5DC	nop
[S2 + 0010] = w(V0);
S4 = S4 + 0028;
S1 = S1 + 0001;
V0 = S1 < 0004;
800AA5F0	bne    v0, zero, loopaa4dc [$800aa4dc]
S3 = S3 + 0018;
S1 = 0;
FP = 00ff;
S6 = 0080;
S5 = 0078;
S4 = 0;
S2 = 0300;
S3 = 0080;
S7 = 00c8;

Laa618:	; 800AA618
S0 = w[800c2f10];
800AA620	nop
S0 = S0 + S7;
800AA628	jal    $80043b28
A0 = S0;
A0 = 0001;
A1 = 0;
A2 = S2;
A3 = 0100;
V0 = S1 << 07;
V1 = w[800c2f10];
T0 = 00df;
[S0 + 001a] = h(T0);
[S0 + 0008] = h(V0);
[S0 + 0018] = h(V0);
V0 = S1 << 04;
[S0 + 000a] = h(0);
[S0 + 0010] = h(S3);
[S0 + 0012] = h(0);
[S0 + 0020] = h(S3);
[S0 + 0022] = h(T0);
V0 = V0 + V1;
[V0 + 0078] = h(0);
[V0 + 007a] = h(0);
[V0 + 007c] = h(FP);
[V0 + 007e] = h(FP);
[V0 + 0080] = h(0);
[V0 + 0082] = h(0);
[V0 + 0084] = h(FP);
800AA694	jal    $system_graphic_get_texpage_by_param
[V0 + 0086] = h(FP);
A1 = 0;
A2 = 0;
V1 = w[800c2f10];
A3 = V0 & ffff;
A0 = V1 + S4;
V1 = V1 + S5;
800AA6B8	jal    $system_gpu_create_texture_setting_packet
[SP + 0010] = w(V1);
A0 = 0001;
A1 = 0;
A2 = S2;
800AA6CC	jal    $system_graphic_get_texpage_by_param
A3 = 0100;
A1 = 0;
A2 = 0;
V1 = w[800c2f10];
A3 = V0 & ffff;
A0 = V1 + S4;
A0 = A0 + 000c;
V1 = V1 + S5;
V1 = V1 + 0008;
800AA6F8	jal    $system_gpu_create_texture_setting_packet
[SP + 0010] = w(V1);
A0 = S0;
A1 = 0001;
[S0 + 0004] = b(S6);
[S0 + 0005] = b(S6);
800AA710	jal    $system_set_draw_packet_transparency
[S0 + 0006] = b(S6);
A0 = 0001;
A1 = 0;
A2 = S2;
A3 = 0100;
T0 = 00df;
[S0 + 001d] = b(T0);
[S0 + 000c] = b(0);
[S0 + 000d] = b(0);
[S0 + 0014] = b(S6);
[S0 + 0015] = b(0);
[S0 + 001c] = b(0);
[S0 + 0024] = b(S6);
800AA748	jal    $system_graphic_get_texpage_by_param
[S0 + 0025] = b(T0);
A0 = 0;
A1 = 00f6;
800AA758	jal    $800438d0
[S0 + 0016] = h(V0);
V1 = S0 + 0028;
A2 = V1;
A3 = S0 + 0020;
[S0 + 000e] = h(V0);

loopaa770:	; 800AA770
V0 = w[S0 + 0000];
V1 = w[S0 + 0004];
A0 = w[S0 + 0008];
A1 = w[S0 + 000c];
[A2 + 0000] = w(V0);
[A2 + 0004] = w(V1);
[A2 + 0008] = w(A0);
[A2 + 000c] = w(A1);
S0 = S0 + 0010;
800AA794	bne    s0, a3, loopaa770 [$800aa770]
A2 = A2 + 0010;
V0 = w[S0 + 0000];
V1 = w[S0 + 0004];
[A2 + 0000] = w(V0);
[A2 + 0004] = w(V1);
S5 = S5 + 0010;
S4 = S4 + 0018;
S2 = S2 + 0040;
S3 = S3 + 0080;
S1 = S1 + 0001;
V0 = S1 < 0003;
800AA7C4	bne    v0, zero, Laa618 [$800aa618]
S7 = S7 + 0050;
RA = w[SP + 0044];
FP = w[SP + 0040];
S7 = w[SP + 003c];
S6 = w[SP + 0038];
S5 = w[SP + 0034];
S4 = w[SP + 0030];
S3 = w[SP + 002c];
S2 = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0048;
800AA7F8	jr     ra 
800AA7FC	nop
////////////////////////////////
// funcaa800
A1 = 0;
A2 = w[80059a38];
800AA80C	nop
V1 = A2 + A1;

loopaa814:	; 800AA814
V0 = bu[V1 + 2026];
800AA818	nop
800AA81C	bne    v0, a0, Laa834 [$800aa834]
800AA820	nop
V0 = bu[V1 + 1f90];
800AA828	nop
800AA82C	bne    v0, zero, Laa848 [$800aa848]
V0 = 0;

Laa834:	; 800AA834
A1 = A1 + 0001;
V0 = A1 < 0096;
800AA83C	bne    v0, zero, loopaa814 [$800aa814]
V1 = A2 + A1;
800AA844	addiu  v0, zero, $ffff (=-$1)

Laa848:	; 800AA848
800AA848	jr     ra 
800AA84C	nop
////////////////////////////////
// funcaa850
800AA850	addiu  sp, sp, $fff8 (=-$8)
V1 = w[800b1740];
T4 = A0;
[SP + 0000] = w(S0);
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
A0 = w[V0 + 004c];
V0 = w[800c2de8];
V1 = h[A0 + 0022];
800AA894	nop
800AA898	mult   v1, v0
V1 = h[A0 + 002a];
800AA8A0	mflo   a1
V0 = w[800c2eec];
800AA8AC	nop
800AA8B0	mult   v1, v0
T3 = 0;
T2 = ffffff;
800AA8C0	lui    t9, $ff00
T8 = 0;
T7 = 0180;
T1 = 0;
T6 = A1 >> 10;
800AA8D4	mflo   v0
V0 = 0 - V0;
T5 = V0 >> 10;

Laa8e0:	; 800AA8E0
800AA8E0	bne    t3, zero, Laa8f0 [$800aa8f0]
800AA8E4	nop
800AA8E8	addiu  t5, t5, $fff4 (=-$c)
800AA8EC	addiu  t6, t6, $fffc (=-$4)

Laa8f0:	; 800AA8F0
A1 = w[800acfe0];
A2 = w[800b12c4];
V1 = w[800af34c];
A0 = w[800af350];
V0 = A1 << 02;
V0 = V0 + A1;
V0 = V0 << 02;
V0 = V0 + T1;
V0 = A2 + V0;
V1 = T6 + V1;
A0 = T5 + A0;
A1 = A1 & 0001;
[V0 + 0188] = h(V1);
[V0 + 018a] = h(A0);
V0 = A1 << 02;
V0 = V0 + A1;
V0 = V0 << 02;
A2 = T1 + A2;
V0 = V0 + A2;
[V0 + 0184] = b(T4);
V1 = w[800acfe0];
800AA958	nop
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
V1 = w[800b12c4];
V0 = V0 << 02;
V1 = T1 + V1;
V0 = V0 + V1;
[V0 + 0185] = b(T4);
V1 = w[800acfe0];
T3 = T3 + 0001;
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
V1 = w[800b12c4];
V0 = V0 << 02;
V1 = T1 + V1;
V0 = V0 + V1;
[V0 + 0186] = b(T4);
A3 = w[800acfe0];
A0 = w[800b12c4];
T0 = w[800c3740];
A2 = A3 << 02;
A2 = A2 + A3;
A2 = A2 << 02;
A1 = T1 + A0;
A1 = A2 + A1;
T1 = T1 + 0028;
V1 = w[A1 + 0180];
800AA9E4	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T9;
V0 = V0 & T2;
V1 = V1 | V0;
V0 = T8 + A0;
T8 = T8 + 0018;
A0 = A0 + T7;
A0 = A0 + A2;
A0 = A0 & T2;
[A1 + 0180] = w(V1);
V1 = A3 << 01;
V1 = V1 + A3;
V1 = V1 << 02;
V1 = V1 + V0;
800AAA24	lui    at, $0001
AT = T0 + AT;
A1 = w[AT + 80d4];
800AAA30	nop
A1 = A1 & T9;
A1 = A1 | A0;
800AAA3C	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(A1);
V0 = w[V1 + 0000];
A1 = A1 & T2;
V0 = V0 & T9;
V0 = V0 | A1;
[V1 + 0000] = w(V0);
800AAA5C	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T2;
V0 = V0 & T9;
V0 = V0 | V1;
800AAA74	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);
800AAA80	blez   t3, Laa8e0 [$800aa8e0]
T7 = T7 + 0028;
T3 = 0;
T2 = ffffff;
800AAA94	lui    t7, $ff00
T6 = 0;
T5 = 00c8;
T1 = 0;

loopaaaa4:	; 800AAAA4
V1 = w[800acfe0];
800AAAAC	nop
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
V1 = w[800c2f10];
V0 = V0 << 03;
V1 = T1 + V1;
V0 = V0 + V1;
[V0 + 00cc] = b(T4);
V1 = w[800acfe0];
800AAADC	nop
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
V1 = w[800c2f10];
V0 = V0 << 03;
V1 = T1 + V1;
V0 = V0 + V1;
[V0 + 00cd] = b(T4);
V1 = w[800acfe0];
T3 = T3 + 0001;
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
V1 = w[800c2f10];
V0 = V0 << 03;
V1 = T1 + V1;
V0 = V0 + V1;
[V0 + 00ce] = b(T4);
A3 = w[800acfe0];
A0 = w[800c2f10];
T0 = w[800c3740];
A2 = A3 << 02;
A2 = A2 + A3;
A2 = A2 << 03;
A1 = T1 + A0;
A1 = A2 + A1;
T1 = T1 + 0050;
V1 = w[A1 + 00c8];
800AAB68	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T7;
V0 = V0 & T2;
V1 = V1 | V0;
V0 = T6 + A0;
T6 = T6 + 0018;
A0 = A0 + T5;
A0 = A0 + A2;
A0 = A0 & T2;
[A1 + 00c8] = w(V1);
V1 = A3 << 01;
V1 = V1 + A3;
V1 = V1 << 02;
V1 = V1 + V0;
800AABA8	lui    at, $0001
AT = T0 + AT;
A1 = w[AT + 80d4];
800AABB4	nop
A1 = A1 & T7;
A1 = A1 | A0;
800AABC0	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(A1);
V0 = w[V1 + 0000];
A1 = A1 & T2;
V0 = V0 & T7;
V0 = V0 | A1;
[V1 + 0000] = w(V0);
800AABE0	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T2;
V0 = V0 & T7;
V0 = V0 | V1;
800AABF8	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);
V0 = T3 < 0003;
800AAC08	bne    v0, zero, loopaaaa4 [$800aaaa4]
T5 = T5 + 0050;
S0 = w[SP + 0000];
SP = SP + 0008;
800AAC18	jr     ra 
800AAC1C	nop
////////////////////////////////
// funcaac20
V0 = A0 < 0005;
800AAC24	beq    v0, zero, Laacd4 [$800aacd4]
V0 = A0 << 02;
800AAC2C	lui    at, $8007
AT = AT + V0;
V0 = w[AT + f468];
800AAC38	nop
800AAC3C	jr     v0 
800AAC40	nop

V0 = w[80059a38];
800AAC4C	nop
V0 = hu[V0 + 1a16];
800AAC54	j      Laaca4 [$800aaca4]
V0 = V0 & 0008;
V0 = w[80059a38];
800AAC64	nop
V0 = hu[V0 + 1a16];
800AAC6C	j      Laaca4 [$800aaca4]
V0 = V0 & 0010;
V0 = w[80059a38];
800AAC7C	nop
V0 = hu[V0 + 1a16];
800AAC84	j      Laaca4 [$800aaca4]
V0 = V0 & 0020;
V0 = w[80059a38];
800AAC94	nop
V0 = hu[V0 + 1a16];
800AAC9C	nop
V0 = V0 & 0040;

Laaca4:	; 800AACA4
800AACA4	beq    v0, zero, Laacd8 [$800aacd8]
800AACA8	addiu  v0, zero, $ffff (=-$1)
800AACAC	j      Laacd8 [$800aacd8]
V0 = 0;
V0 = w[80059a38];
800AACBC	nop
V0 = hu[V0 + 1a16];
800AACC4	nop
V0 = V0 & 0080;
800AACCC	beq    v0, zero, Laacd8 [$800aacd8]
V0 = 0;

Laacd4:	; 800AACD4
800AACD4	addiu  v0, zero, $ffff (=-$1)

Laacd8:	; 800AACD8
800AACD8	jr     ra 
800AACDC	nop
////////////////////////////////
// funcaace0

A0 = 0802;
800AAD0C	jal    $system_get_aligned_filesize_by_dir_file_id

A0 = V0;
800AAD18	jal    $system_memory_allocate
A1 = 0;
A0 = 0802;
A2 = 0;
[SP + 0028] = w(V0);
A1 = w[SP + 0028];
800AAD30	jal    $system_load_file_by_dir_file_id
A3 = 0080;
800AAD38	jal    $system_cdrom_action_sync
A0 = 0;
A0 = 0f20;
800AAD44	jal    $system_memory_allocate
A1 = 0;
A0 = w[SP + 0028];
800AAD50	jal    $8004702c
[SP + 0030] = w(V0);
800AAD58	jal    $8004703c
A0 = SP + 0010;
800AAD60	beq    v0, zero, Laaf24 [$800aaf24]
800AAD64	nop
V0 = 800aea9a;
S3 = V0;
800AAD74	addiu  fp, v0, $fffe (=-$2)
800AAD78	addiu  s7, s3, $fffc (=-$4)
T0 = 800aea94;
S5 = 0;
[SP + 0038] = w(0);
[SP + 0048] = w(T0);

loopaad90:	; 800AAD90
A0 = w[SP + 0038];
800AAD94	jal    funcaac20 [$800aac20]
800AAD98	nop
800AAD9C	addiu  v1, zero, $ffff (=-$1)
800AADA0	bne    v0, v1, Laaef4 [$800aaef4]
800AADA4	nop
V0 = w[SP + 0020];
800AADAC	nop
800AADB0	beq    v0, zero, Laaef4 [$800aaef4]
800AADB4	nop
V0 = h[S3 + 0000];
S1 = w[SP + 0030];
800AADC0	blez   v0, Laae68 [$800aae68]
S0 = 0;
A3 = S5;
S6 = S7;
S2 = FP;
V0 = 800aea9a;
S4 = S5 + V0;

loopaade0:	; 800AADE0
T0 = 800aea94;
V0 = A3 + T0;
V1 = h[V0 + 0000];
800AADF0	nop
800AADF4	bgez   v1, Laae00 [$800aae00]
A0 = S1;
V1 = V1 + 0003;

Laae00:	; 800AAE00
A2 = h[S2 + 0000];
V0 = h[S6 + 0000];
V1 = V1 >> 02;
[SP + 0050] = w(A3);
V0 = V0 + S0;
A1 = V0 << 02;
A1 = A1 + V0;
A1 = A1 << 04;
A1 = A1 + V1;
V0 = w[SP + 0020];
A1 = A1 << 02;
800AAE2C	jal    $system_memcpy
A1 = A1 + V0;
V0 = h[S2 + 0000];
A3 = w[SP + 0050];
800AAE3C	bgez   v0, Laae48 [$800aae48]
800AAE40	nop
V0 = V0 + 0003;

Laae48:	; 800AAE48
V0 = V0 >> 02;
V0 = V0 << 02;
S1 = S1 + V0;
V0 = h[S4 + 0000];
S0 = S0 + 0001;
V0 = S0 < V0;
800AAE60	bne    v0, zero, loopaade0 [$800aade0]
800AAE64	nop

Laae68:	; 800AAE68
T0 = w[SP + 0048];
800AAE6C	nop
V1 = hu[T0 + 0000];
800AAE74	nop
V1 = V1 << 10;
V0 = V1 >> 10;
V1 = V1 >> 1f;
V0 = V0 + V1;
V0 = V0 >> 01;
V1 = w[SP + 001c];
V0 = V0 + 0300;
[V1 + 0000] = h(V0);
V0 = hu[S7 + 0000];
V1 = w[SP + 001c];
V0 = V0 + 0100;
[V1 + 0002] = h(V0);
V0 = hu[FP + 0000];
800AAEAC	nop
V0 = V0 << 10;
V1 = V0 >> 10;
V0 = V0 >> 1f;
V1 = V1 + V0;
V0 = w[SP + 001c];
V1 = V1 >> 01;
[V0 + 0004] = h(V1);
V1 = w[SP + 001c];
V0 = hu[S3 + 0000];
800AAED4	nop
[V1 + 0006] = h(V0);
A0 = w[SP + 001c];
A1 = w[SP + 0030];
800AAEE4	jal    $8004470c
800AAEE8	nop
800AAEEC	jal    $system_draw_sync
A0 = 0;

Laaef4:	; 800AAEF4
S3 = S3 + 0008;
FP = FP + 0008;
T0 = w[SP + 0048];
S7 = S7 + 0008;
T0 = T0 + 0008;
[SP + 0048] = w(T0);
T0 = w[SP + 0038];
S5 = S5 + 0008;
T0 = T0 + 0001;
V0 = T0 < 0005;
800AAF1C	bne    v0, zero, loopaad90 [$800aad90]
[SP + 0038] = w(T0);

Laaf24:	; 800AAF24
A0 = w[SP + 0028];
800AAF28	jal    $system_memory_mark_removed_alloc
800AAF2C	nop
A0 = w[SP + 0030];
800AAF34	jal    $system_memory_mark_removed_alloc
////////////////////////////////



////////////////////////////////
// funcaaf70

S0 = 0;
A1 = ffff;
S2 = 800ae950;
V0 = w[8004e9f0];
A0 = S2;
V0 = V0 & 3fff;

Laafa8:	; 800AAFA8
V1 = w[A0 + 0000];
800AAFAC	nop
800AAFB0	beq    v1, a1, Lab1d0 [$800ab1d0]
800AAFB4	nop
800AAFB8	beq    v0, v1, Laafc8 [$800aafc8]
A0 = A0 + 0020;
800AAFC0	j      Laafa8 [$800aafa8]
S0 = S0 + 0001;

Laafc8:	; 800AAFC8
S1 = S0 << 05;
V0 = S2 + S1;
A0 = w[V0 + 0010];
800AAFD4	jal    funcaa800 [$800aa800]
800AAFD8	nop
800AAFDC	addiu  v1, zero, $ffff (=-$1)
800AAFE0	beq    v0, v1, Lab1d0 [$800ab1d0]
A0 = 14000;
V0 = S2 + S1;
V1 = S2 + S1;
A2 = S2 + S1;
A3 = S2 + S1;
T0 = S2 + S1;
T1 = w[V0 + 0004];
V0 = 0300;
T2 = w[V1 + 0008];
S0 = w[A2 + 000c];
A2 = w[A3 + 0014];
A3 = w[T0 + 0018];
V1 = 0100;
[SP + 0020] = h(V0);
V0 = 00a0;
[SP + 0022] = h(V1);
[SP + 0024] = h(V0);
[SP + 0026] = h(V1);
[800c2de8] = w(T1);
[800c2eec] = w(T2);
[800af34c] = w(A2);
[800af350] = w(A3);
800AB050	jal    $system_memory_allocate
A1 = 0;
A0 = SP + 0020;
S3 = V0;
800AB060	jal    $80044770
A1 = S3;
800AB068	jal    $system_draw_sync
A0 = 0;
800AB070	jal    $system_cdrom_action_sync
A0 = 0;

A0 = 4;
A1 = 0;
system_filesystem_set_dir();

S0 = S0 + 7fb;

A0 = S0;
system_get_aligned_filesize_by_dir_file_id();

A0 = V0;
800AB094	jal    $system_memory_allocate
A1 = 0;
A0 = S0;
S0 = V0;
A1 = S0;
A2 = 0;
A3 = 0080;
system_load_file_by_dir_file_id();

800AB0B4	jal    $system_cdrom_action_sync
A0 = 0;
A0 = S0;
A1 = 0300;
A2 = 0100;
A3 = 0;
V0 = 00f6;
[SP + 0010] = w(V0);
[SP + 0014] = w(0);
800AB0D8	jal    field_load_tim_into_vram [$8006f9d0]
[SP + 0018] = w(0);
800AB0E0	jal    $system_memory_mark_removed_alloc
A0 = S0;
V0 = S2 + S1;
V1 = w[V0 + 001c];
V0 = 0001;
800AB0F4	bne    v1, v0, Lab104 [$800ab104]
800AB0F8	nop
800AB0FC	jal    funcaace0 [$800aace0]
800AB100	nop

Lab104:	; 800AB104
800AB104	jal    funcaa458 [$800aa458]
S0 = 0;

loopab10c:	; 800AB10C
800AB10C	jal    func73670 [$80073670]
800AB110	nop
800AB114	jal    funcaa850 [$800aa850]
A0 = S0 << 03;
800AB11C	jal    funca5dfc [$800a5dfc]
S0 = S0 + 0001;
V0 = S0 < 0010;
800AB128	bne    v0, zero, loopab10c [$800ab10c]
800AB12C	nop

loopab130:	; 800AB130
800AB130	jal    func73670 [$80073670]
800AB134	nop
800AB138	jal    funcaa850 [$800aa850]
A0 = 0080;
800AB140	jal    funca5dfc [$800a5dfc]
800AB144	nop
800AB148	jal    func73d90 [$80073d90]
800AB14C	nop
V0 = hu[800c2dd4];
800AB158	nop
V0 = V0 & 0100;
800AB160	beq    v0, zero, loopab130 [$800ab130]
800AB164	nop
S0 = 0010;

loopab16c:	; 800AB16C
800AB16C	jal    func73670 [$80073670]
800AB170	nop
800AB174	jal    funcaa850 [$800aa850]
A0 = S0 << 03;
800AB17C	jal    funca5dfc [$800a5dfc]
800AB180	addiu  s0, s0, $ffff (=-$1)
800AB184	bgtz   s0, loopab16c [$800ab16c]
800AB188	nop
800AB18C	jal    $system_draw_sync
A0 = 0;
A0 = w[800c2f10];
800AB19C	jal    $system_memory_mark_removed_alloc
800AB1A0	nop
A0 = w[800b12c4];
800AB1AC	jal    $system_memory_mark_removed_alloc
800AB1B0	nop
A0 = SP + 0020;
800AB1B8	jal    $8004470c
A1 = S3;
800AB1C0	jal    $system_draw_sync
A0 = 0;
800AB1C8	jal    $system_memory_mark_removed_alloc
A0 = S3;

Lab1d0:	; 800AB1D0
////////////////////////////////



////////////////////////////////
// funcab1f0()

[SP + 18] = h(0);
[SP + 1a] = h(0);
[SP + 1c] = h(ff);
[SP + 1e] = h(ff);

for( int i = 0; i < 5; ++i )
{
    A0 = 1;
    A1 = 0;
    A2 = 280 + i * 40;
    A3 = 0;
    system_graphic_get_texpage_by_param();

    A0 = 800af65c + i * 18;
    A1 = 0;
    A2 = 0;
    A3 = V0 & ffff;
    A4 = SP + 18;
    system_gpu_create_texture_setting_packet();

    A0 = 1;
    A1 = 0;
    A2 = 280 + i * 40;
    A3 = 0;
    system_graphic_get_texpage_by_param();

    A0 = 800af65c + i * 18 + c;
    A1 = 0;
    A2 = 0;
    A3 = V0 & ffff;
    A4 = SP + 18;
    system_gpu_create_texture_setting_packet();

    A0 = 800af6d4 + i * 28;
    func43b8c();

    [800af6d4 + i * 28 + 0008] = h(i * 80);
    [800af6d4 + i * 28 + 0004] = b(80);
    [800af6d4 + i * 28 + 0005] = b(80);
    [800af6d4 + i * 28 + 0006] = b(80);
    [800af6d4 + i * 28 + 000a] = h(0);
    [800af6d4 + i * 28 + 000c] = b(0);
    [800af6d4 + i * 28 + 000d] = b(0);
    [800af6d4 + i * 28 + 0010] = h(80);
    [800af6d4 + i * 28 + 0012] = h(e0);

    A0 = 800af6d4 + i * 28;
    A1 = 0;
    system_set_draw_packet_transparency();

    A0 = 0;
    A1 = e8;
    system_graphic_get_clut_by_param();

    [800af6d4 + i * 28 + 000e] = h(V0);
    [800af6e8 + i * 28 + 0000] = w(w[S0 + 0000]);
    [800af6e8 + i * 28 + 0004] = w(w[S0 + 0004]);
    [800af6e8 + i * 28 + 0008] = w(w[S0 + 0008]);
    [800af6e8 + i * 28 + 000c] = w(w[S0 + 000c]);
    [800af6e8 + i * 28 + 0010] = w(w[S0 + 0010]);
}
////////////////////////////////



////////////////////////////////
// funcab3a0
V0 = h[800ad02c];
800AB3A8	nop
800AB3AC	beq    v0, zero, Lab4ac [$800ab4ac]
800AB3B0	nop
T6 = 0;
A3 = ffffff;
800AB3C0	lui    t5, $ff00
T7 = 800af6d4;
800AB3CC	addiu  t8, t7, $ff88 (=-$78)
V0 = w[800acfe0];
T0 = w[800c3740];
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 02;
T4 = V1 + T8;
T3 = V1;
V1 = V0 << 02;
V1 = V1 + V0;
V1 = V1 << 02;
T2 = V1 + T7;
T1 = V1;

loopab408:	; 800AB408
A2 = T4 & A3;
T4 = T4 + 0018;
A1 = T3 + T8;
T3 = T3 + 0018;
A0 = T1 + T7;
T1 = T1 + 0028;
T6 = T6 + 0001;
V1 = w[A0 + 0000];
800AB428	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T5;
V0 = V0 & A3;
V1 = V1 | V0;
[A0 + 0000] = w(V1);
800AB444	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = T2 & A3;
V0 = V0 & T5;
V0 = V0 | V1;
800AB45C	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);
V1 = w[A1 + 0000];
V0 = V0 & A3;
V1 = V1 & T5;
V1 = V1 | V0;
[A1 + 0000] = w(V1);
800AB47C	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
800AB488	nop
V0 = V0 & T5;
V0 = V0 | A2;
800AB494	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);
V0 = T6 < 0005;
800AB4A4	bne    v0, zero, loopab408 [$800ab408]
T2 = T2 + 0028;

Lab4ac:	; 800AB4AC
800AB4AC	jr     ra 
800AB4B0	nop
////////////////////////////////
// funcab4b4
800AB4B4	addiu  sp, sp, $ffe8 (=-$18)
[SP + 0010] = w(RA);
V1 = bu[A0 + 0000];
V0 = bu[A0 + 0001];
V1 = V1 << 08;
V0 = V0 | V1;
A0 = V0;
V0 = V0 + 7ac0;
V0 = V0 & ffff;
V0 = V0 < 0340;
800AB4DC	bne    v0, zero, Lab4f4 [$800ab4f4]
V0 = 0001;
800AB4E4	jal    $8004043c
[A1 + 0000] = w(0);
800AB4EC	j      Lab504 [$800ab504]
800AB4F0	nop

Lab4f4:	; 800AB4F4
[A1 + 0000] = w(V0);
V0 = ffff7ac0;
V0 = A0 + V0;

Lab504:	; 800AB504
RA = w[SP + 0010];
SP = SP + 0018;
800AB50C	jr     ra 
800AB510	nop
////////////////////////////////
// funcab514
800AB514	addiu  v0, zero, $ffff (=-$1)
800AB518	bne    a1, v0, Lab540 [$800ab540]
A3 = 0;
V0 = 00ff;
A3 = 011f;

loopab528:	; 800AB528
[A0 + 0000] = b(V0);
800AB52C	addiu  a3, a3, $ffff (=-$1)
800AB530	bgez   a3, loopab528 [$800ab528]
A0 = A0 + 0001;
800AB538	j      Lab5c0 [$800ab5c0]
800AB53C	nop

Lab540:	; 800AB540
V1 = 0007;
A2 = A0;

loopab548:	; 800AB548
A2 = A2 + 0001;
V0 = hu[A1 + 0000];
A0 = A0 + 0001;
V0 = V0 >> V1;
V0 = V0 & 0001;
V0 = 0 - V0;
800AB560	addiu  v1, v1, $ffff (=-$1)
800AB564	bgez   v1, loopab548 [$800ab548]
[A2 + ffff] = b(V0);
V1 = 000f;
A2 = A0;

loopab574:	; 800AB574
A2 = A2 + 0001;
V0 = hu[A1 + 0000];
800AB57C	nop
V0 = V0 >> V1;
V0 = V0 & 0001;
V0 = 0 - V0;
800AB58C	addiu  v1, v1, $ffff (=-$1)
[A2 + ffff] = b(V0);
V0 = V1 < 0008;
800AB598	beq    v0, zero, loopab574 [$800ab574]
A0 = A0 + 0001;
[A0 + 0000] = b(0);
A0 = A0 + 0001;
[A0 + 0000] = b(0);
A0 = A0 + 0001;
A3 = A3 + 0001;
V0 = A3 < 000f;
800AB5B8	bne    v0, zero, Lab540 [$800ab540]
A1 = A1 + 0002;

Lab5c0:	; 800AB5C0
800AB5C0	jr     ra 
800AB5C4	nop
////////////////////////////////
// funcab5c8
800AB5C8	addiu  sp, sp, $fe58 (=-$1a8)
[SP + 019c] = w(S5);
S5 = A0;
[SP + 0198] = w(S4);
S4 = A1;
[SP + 0194] = w(S3);
S3 = A2;
V1 = SP + 0140;
A1 = SP + 0180;
V0 = 0009;
[SP + 0134] = h(V0);
V0 = 0010;
[SP + 0136] = h(V0);
V0 = S3 << 04;
[SP + 01a0] = w(RA);
[SP + 0190] = w(S2);
[SP + 018c] = w(S1);
[SP + 0188] = w(S0);
[SP + 0132] = h(V0);

loopab614:	; 800AB614
V0 = bu[A0 + 0000];
800AB618	nop
[V1 + 0000] = b(V0);
V1 = V1 + 0001;
V0 = V1 < A1;
800AB628	bne    v0, zero, loopab614 [$800ab614]
A0 = A0 + 0001;
V0 = 011f;
V1 = SP + 012f;

loopab638:	; 800AB638
[V1 + 0000] = b(0);
800AB63C	addiu  v0, v0, $ffff (=-$1)
800AB640	bgez   v0, loopab638 [$800ab638]
800AB644	addiu  v1, v1, $ffff (=-$1)
V0 = w[800aec54];
800AB650	nop
800AB654	bgtz   v0, Lab66c [$800ab66c]
S2 = 0;
800AB65C	j      Lab74c [$800ab74c]
S1 = 0;

loopab664:	; 800AB664
800AB664	j      Lab74c [$800ab74c]
S2 = S2 + 0001;

Lab66c:	; 800AB66C
S1 = 0;
S0 = S4;

loopab674:	; 800AB674
V0 = SP + 0140;
A0 = V0 + S2;
V1 = bu[A0 + 0000];
V0 = 000d;
800AB684	beq    v1, v0, loopab664 [$800ab664]
800AB688	nop
800AB68C	jal    funcab4b4 [$800ab4b4]
A1 = SP + 0180;
A3 = V0;
V1 = w[SP + 0180];
V0 = 0001;
800AB6A0	bne    v1, v0, Lab718 [$800ab718]
S2 = S2 + 0002;
V0 = 92492493;
800AB6B0	mult   a3, v0
A0 = SP + 0138;
A1 = S0;
V0 = 0009;
[SP + 013c] = h(V0);
V0 = 0010;
[SP + 013e] = h(V0);
V0 = A3 >> 1f;
800AB6D0	mfhi   t0
A2 = T0 + A3;
A2 = A2 >> 02;
A2 = A2 - V0;
V1 = A2 << 03;
V1 = V1 - A2;
V1 = A3 - V1;
V0 = V1 << 03;
V0 = V0 + V1;
V0 = V0 + 0380;
A2 = A2 << 04;
A2 = A2 + 0100;
[SP + 013a] = h(A2);
A2 = S3 << 04;
800AB708	jal    $system_move_image
[SP + 0138] = h(V0);
800AB710	j      Lab734 [$800ab734]
800AB714	nop

Lab718:	; 800AB718
A0 = SP + 0010;
800AB71C	jal    funcab514 [$800ab514]
A1 = A3;
[SP + 0130] = h(S0);
A0 = SP + 0130;
800AB72C	jal    $8004470c
A1 = SP + 0010;

Lab734:	; 800AB734
800AB734	jal    $system_draw_sync
A0 = 0;
S1 = S1 + 0001;
V0 = S1 < 001c;
800AB744	bne    v0, zero, loopab674 [$800ab674]
S0 = S0 + 0009;

Lab74c:	; 800AB74C
V0 = 011f;
V1 = SP + 012f;

loopab754:	; 800AB754
[V1 + 0000] = b(0);
800AB758	addiu  v0, v0, $ffff (=-$1)
800AB75C	bgez   v0, loopab754 [$800ab754]
800AB760	addiu  v1, v1, $ffff (=-$1)
V0 = S1 < 001c;
800AB768	beq    v0, zero, Lab7a0 [$800ab7a0]
V0 = S1 << 03;
V0 = V0 + S1;
S0 = V0 + S4;

loopab778:	; 800AB778
[SP + 0130] = h(S0);
A0 = SP + 0130;
800AB780	jal    $8004470c
A1 = SP + 0010;
800AB788	jal    $system_draw_sync
A0 = 0;
S1 = S1 + 0001;
V0 = S1 < 001c;
800AB798	bne    v0, zero, loopab778 [$800ab778]
S0 = S0 + 0009;

Lab7a0:	; 800AB7A0
V1 = w[800aec54];
V0 = S5 + S2;
V1 = V1 - S2;
[800aec54] = w(V1);
RA = w[SP + 01a0];
S5 = w[SP + 019c];
S4 = w[SP + 0198];
S3 = w[SP + 0194];
S2 = w[SP + 0190];
S1 = w[SP + 018c];
S0 = w[SP + 0188];
SP = SP + 01a8;
800AB7D8	jr     ra 
800AB7DC	nop
////////////////////////////////
// funcab7e0
800AB7E0	addiu  sp, sp, $ffe8 (=-$18)
A0 = 0004;
[SP + 0010] = w(RA);
800AB7EC	jal    $system_filesystem_set_dir
A1 = 0;
800AB7F4	jal    $80028548
A0 = 00ab;
[800aec54] = w(V0);
800AB804	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 00ab;
A0 = V0;
800AB810	jal    $system_memory_allocate
A1 = 0001;
A0 = 00ab;
A1 = V0;
A2 = 0;
[800aec40] = w(A1);
800AB82C	jal    $system_load_file_by_dir_file_id
A3 = 0080;
800AB834	jal    $system_cdrom_action_sync
A0 = 0;
800AB83C	jal    $system_get_aligned_filesize_by_dir_file_id
A0 = 00ac;
A0 = V0;
800AB848	jal    $system_memory_allocate
A1 = 0001;
A0 = 00ac;
A1 = V0;
A2 = 0;
[800aec58] = w(A1);
800AB864	jal    $system_load_file_by_dir_file_id
A3 = 0080;
800AB86C	jal    $system_cdrom_action_sync
A0 = 0;
RA = w[SP + 0010];
SP = SP + 0018;
800AB87C	jr     ra 
800AB880	nop
////////////////////////////////
// funcab884
800AB884	addiu  sp, sp, $ffb8 (=-$48)
[SP + 0020] = w(S0);
S0 = 800aec5c;
A0 = S0;
[SP + 0044] = w(RA);
[SP + 0040] = w(FP);
[SP + 003c] = w(S7);
[SP + 0038] = w(S6);
[SP + 0034] = w(S5);
[SP + 0030] = w(S4);
[SP + 002c] = w(S3);
[SP + 0028] = w(S2);
800AB8B8	jal    $80043b50
[SP + 0024] = w(S1);
A0 = 800aecc4;
800AB8C8	jal    $80043b50
800AB8CC	nop
A0 = 0001;
A1 = 0002;
A2 = 03c0;
V0 = 00ff;
V1 = 0280;
[800aec62] = b(V0);
[800aec61] = b(V0);
[800aec60] = b(V0);
[800aec6e] = b(V0);
[800aec6d] = b(V0);
[800aec6c] = b(V0);
[800aece2] = b(V0);
[800aece1] = b(V0);
[800aece0] = b(V0);
[800aecee] = b(V0);
[800aeced] = b(V0);
[800aecec] = b(V0);
V0 = 0018;
[800aec7e] = h(V0);
[800aec8a] = h(V0);
V0 = 00c8;
[800aec7a] = b(0);
[800aec79] = b(0);
[800aec78] = b(0);
[800aec86] = b(0);
[800aec85] = b(0);
[800aec84] = b(0);
[800aecca] = b(0);
[800aecc9] = b(0);
[800aecc8] = b(0);
[800aecd6] = b(0);
[800aecd5] = b(0);
[800aecd4] = b(0);
[800aec64] = h(0);
[800aec66] = h(0);
[800aec70] = h(V1);
[800aec72] = h(0);
[800aec7c] = h(0);
[800aec88] = h(V1);
[800aeccc] = h(0);
[800aecce] = h(V0);
[800aecda] = h(V0);
V0 = 00e0;
[800aece6] = h(V0);
[800aecf2] = h(V0);
V0 = 0002;
[800aecd8] = h(V1);
[800aece4] = h(0);
[800aecf0] = h(V1);
[800aec68] = b(0);
[800aec69] = b(0);
[800aec74] = b(V0);
[800aec75] = b(0);
[800aec80] = b(0);
[800aec81] = b(V0);
[S0 + 0030] = b(V0);
[800aec8d] = b(V0);
[800aecd0] = b(0);
[800aecd1] = b(0);
[800aecdc] = b(V0);
[800aecdd] = b(0);
[800aece8] = b(0);
[800aece9] = b(V0);
[800aecf4] = b(V0);
[800aecf5] = b(V0);
800ABAB0	jal    $system_graphic_get_texpage_by_param
A3 = 0100;
A0 = 0001;
A1 = 0002;
A2 = 03c0;
[800aec76] = h(V0);
800ABACC	jal    $system_graphic_get_texpage_by_param
A3 = 0100;
A0 = 0;
[800aecde] = h(V0);
800ABAE0	jal    $800438d0
A1 = 01ff;
A0 = 0;
[800aec6a] = h(V0);
800ABAF4	jal    $800438d0
A1 = 01ff;
A0 = S0;
[800aecd2] = h(V0);
800ABB08	jal    $system_set_draw_packet_transparency
A1 = 0001;
A0 = 800aecc4;
800ABB18	jal    $system_set_draw_packet_transparency
A1 = 0001;
A2 = S0 + 0034;
V0 = S0 + 0030;
A3 = V0;

loopabb2c:	; 800ABB2C
V0 = w[S0 + 0000];
V1 = w[S0 + 0004];
A0 = w[S0 + 0008];
A1 = w[S0 + 000c];
[A2 + 0000] = w(V0);
[A2 + 0004] = w(V1);
[A2 + 0008] = w(A0);
[A2 + 000c] = w(A1);
S0 = S0 + 0010;
800ABB50	bne    s0, a3, loopabb2c [$800abb2c]
A2 = A2 + 0010;
V0 = w[S0 + 0000];
800ABB5C	nop
[A2 + 0000] = w(V0);
V0 = 800aecf8;
A2 = V0;
800ABB70	addiu  a3, a2, $ffcc (=-$34)
800ABB74	addiu  t0, a2, $fffc (=-$4)

loopabb78:	; 800ABB78
V0 = w[A3 + 0000];
V1 = w[A3 + 0004];
A0 = w[A3 + 0008];
A1 = w[A3 + 000c];
[A2 + 0000] = w(V0);
[A2 + 0004] = w(V1);
[A2 + 0008] = w(A0);
[A2 + 000c] = w(A1);
A3 = A3 + 0010;
800ABB9C	bne    a3, t0, loopabb78 [$800abb78]
A2 = A2 + 0010;
V0 = w[A3 + 0000];
800ABBA8	nop
[A2 + 0000] = w(V0);
A0 = 1000;
800ABBB4	jal    $system_memory_allocate
A1 = 0001;
[800aec44] = w(V0);
S1 = 0;
S2 = 0;

Labbcc:	; 800ABBCC
FP = 0;
S7 = 0030;
S6 = 0;
S4 = 0300;
S0 = w[800aec44];
S3 = 0040;
S0 = S0 + S2;
T1 = S0 + 0060;
[SP + 0018] = w(T1);
A0 = w[SP + 0018];
800ABBF8	jal    $80043b8c
S5 = 0;
A1 = 0;
A0 = w[SP + 0018];
T1 = 0080;
[S0 + 0064] = b(T1);
[S0 + 0065] = b(T1);
800ABC14	jal    $system_set_draw_packet_transparency
[S0 + 0066] = b(T1);
A0 = 0;
800ABC20	jal    $800438d0
A1 = 01ff;
V1 = S1 << 04;
T1 = 0080;
[S0 + 006e] = h(V0);
V0 = 0010;
[S0 + 0072] = h(V0);
V0 = 0040;
[S0 + 006c] = b(0);
[S0 + 006d] = b(V1);
[S0 + 0070] = h(T1);
[S0 + 0068] = h(V0);
[S0 + 006a] = h(V1);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 00b0] = w(V0);
[S0 + 00b4] = w(V1);
[S0 + 00b8] = w(A0);
[S0 + 00bc] = w(A1);
V0 = w[S0 + 0070];
800ABC78	nop
[S0 + 00c0] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 0074] = w(V0);
[S0 + 0078] = w(V1);
[S0 + 007c] = w(A0);
[S0 + 0080] = w(A1);
V0 = w[S0 + 0070];
800ABCA4	nop
[S0 + 0084] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 00c4] = w(V0);
[S0 + 00c8] = w(V1);
[S0 + 00cc] = w(A0);
[S0 + 00d0] = w(A1);
V0 = w[S0 + 0070];
800ABCD0	nop
[S0 + 00d4] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 0088] = w(V0);
[S0 + 008c] = w(V1);
[S0 + 0090] = w(A0);
[S0 + 0094] = w(A1);
V0 = w[S0 + 0070];
800ABCFC	nop
[S0 + 0098] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 00d8] = w(V0);
[S0 + 00dc] = w(V1);
[S0 + 00e0] = w(A0);
[S0 + 00e4] = w(A1);
V0 = w[S0 + 0070];
800ABD28	nop
[S0 + 00e8] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 009c] = w(V0);
[S0 + 00a0] = w(V1);
[S0 + 00a4] = w(A0);
[S0 + 00a8] = w(A1);
V0 = w[S0 + 0070];
800ABD54	nop
[S0 + 00ac] = w(V0);
V0 = w[S0 + 0060];
V1 = w[S0 + 0064];
A0 = w[S0 + 0068];
A1 = w[S0 + 006c];
[S0 + 00ec] = w(V0);
[S0 + 00f0] = w(V1);
[S0 + 00f4] = w(A0);
[S0 + 00f8] = w(A1);
V0 = w[S0 + 0070];
800ABD80	nop
[S0 + 00fc] = w(V0);

loopabd88:	; 800ABD88
A0 = 0001;
A1 = 0;
A2 = S4;
A3 = 0;
V0 = w[800aec44];
FP = FP + 0001;
V0 = S2 + V0;
V0 = V0 + S5;
[V0 + 0068] = h(S3);
800ABDB0	jal    $system_graphic_get_texpage_by_param
[V0 + 00b8] = h(S3);
A1 = 0;
A2 = 0;
A3 = V0 & ffff;
S3 = S3 + 0080;
A0 = w[800aec44];
S5 = S5 + 0014;
[SP + 0010] = w(0);
A0 = A0 + S2;
800ABDDC	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + S6;
A0 = 0001;
A1 = 0;
A2 = S4;
800ABDF0	jal    $system_graphic_get_texpage_by_param
A3 = 0;
A1 = 0;
A2 = 0;
A3 = V0 & ffff;
S6 = S6 + 000c;
A0 = w[800aec44];
S4 = S4 + 0040;
[SP + 0010] = w(0);
A0 = A0 + S2;
800ABE1C	jal    $system_gpu_create_texture_setting_packet
A0 = A0 + S7;
V0 = FP < 0004;
800ABE28	bne    v0, zero, loopabd88 [$800abd88]
S7 = S7 + 000c;
S1 = S1 + 0001;
V0 = S1 < 0010;
800ABE38	bne    v0, zero, Labbcc [$800abbcc]
S2 = S2 + 0100;
RA = w[SP + 0044];
FP = w[SP + 0040];
S7 = w[SP + 003c];
S6 = w[SP + 0038];
S5 = w[SP + 0034];
S4 = w[SP + 0030];
S3 = w[SP + 002c];
S2 = w[SP + 0028];
S1 = w[SP + 0024];
S0 = w[SP + 0020];
SP = SP + 0048;
800ABE6C	jr     ra 
800ABE70	nop
////////////////////////////////
// funcabe74
T3 = ffffff;
T4 = ffffff;
800ABE84	lui    t7, $ff00
T8 = 0;
T1 = 800aecc4;
800ABE94	lui    t2, $ff00
T5 = w[800aec44];
A3 = w[800acfe0];
T0 = w[800c3740];
A0 = A3 << 01;
A0 = A0 + A3;
A0 = A0 << 02;
A0 = A0 + A3;
A0 = A0 << 02;
A2 = A0 + T1;
800ABEC8	addiu  t1, t1, $ff98 (=-$68)
A0 = A0 + T1;
V1 = w[A2 + 0000];
800ABED4	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
V1 = V1 & T2;
V0 = V0 & T3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V1 = A3 + 0001;
V1 = V1 & 0001;
V0 = V1 << 02;
V0 = V0 + V1;
T9 = V0 << 04;
A2 = A2 & T3;
V0 = A3 << 02;
V0 = V0 + A3;
800ABF10	lui    at, $0001
AT = T0 + AT;
A1 = w[AT + 80d4];
T6 = V0 << 04;
A1 = A1 & T2;
A1 = A1 | A2;
800ABF28	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(A1);
V1 = w[A0 + 0000];
A1 = A1 & T3;
V1 = V1 & T2;
V1 = V1 | A1;
[A0 + 0000] = w(V1);
800ABF48	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
A0 = A0 & T3;
V0 = V0 & T2;
V0 = V0 | A0;
800ABF60	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);

loopabf6c:	; 800ABF6C
T3 = 0;
V0 = A3 << 01;
V0 = V0 + A3;
V0 = V0 << 04;
A2 = V0 + T5;
V0 = T6 + 0060;
T2 = T5 + V0;
V0 = T5 + T9;
T1 = 0;
V0 = h[V0 + 006a];
V1 = T5 + T6;
800ABF98	addiu  v0, v0, $ffff (=-$1)
V0 = V0 & 00ff;
[V1 + 006a] = h(V0);
[V1 + 007e] = h(V0);
[V1 + 0092] = h(V0);
[V1 + 00a6] = h(V0);

loopabfb0:	; 800ABFB0
A1 = T2 & T4;
T2 = T2 + 0014;
A0 = T6 + T5;
A0 = T1 + A0;
T1 = T1 + 0014;
V0 = w[A0 + 0060];
800ABFC8	lui    at, $0001
AT = T0 + AT;
V1 = w[AT + 80d4];
V0 = V0 & T7;
V1 = V1 & T4;
V0 = V0 | V1;
[A0 + 0060] = w(V0);
800ABFE4	lui    at, $0001
AT = T0 + AT;
V1 = w[AT + 80d4];
T3 = T3 + 0001;
V1 = V1 & T7;
V1 = V1 | A1;
800ABFFC	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V1);
V0 = w[A2 + 0000];
V1 = V1 & T4;
V0 = V0 & T7;
V0 = V0 | V1;
V1 = A2 & T4;
[A2 + 0000] = w(V0);
800AC020	lui    at, $0001
AT = T0 + AT;
V0 = w[AT + 80d4];
800AC02C	nop
V0 = V0 & T7;
V0 = V0 | V1;
800AC038	lui    at, $0001
AT = T0 + AT;
[AT + 80d4] = w(V0);
V0 = T3 < 0004;
800AC048	bne    v0, zero, loopabfb0 [$800abfb0]
A2 = A2 + 000c;
T8 = T8 + 0100;
V0 = T8 < 1000;
800AC058	bne    v0, zero, loopabf6c [$800abf6c]
T5 = T5 + 0100;
800AC060	jr     ra 
800AC064	nop
////////////////////////////////
// funcac068
800AC068	addiu  sp, sp, $ffd0 (=-$30)
A1 = 0380;
V0 = 01ff;
A2 = 0100;
A0 = w[800aec58];
A3 = 0;
[SP + 002c] = w(RA);
[SP + 0028] = w(S0);
[SP + 0010] = w(V0);
[SP + 0014] = w(0);
800AC094	jal    field_load_tim_into_vram [$8006f9d0]
[SP + 0018] = w(0);
800AC09C	jal    $system_draw_sync
A0 = 0;
A0 = w[800aec58];
800AC0AC	jal    $system_memory_mark_removed_alloc
800AC0B0	nop
A0 = 0200;
800AC0B8	jal    $system_memory_allocate
A1 = 0001;
800AC0C0	addiu  a0, zero, $ffff (=-$1)
V1 = 007f;
S0 = V0;
V0 = S0 + 01fc;

loopac0d0:	; 800AC0D0
[V0 + 0000] = w(A0);
800AC0D4	addiu  v1, v1, $ffff (=-$1)
800AC0D8	bgez   v1, loopac0d0 [$800ac0d0]
800AC0DC	addiu  v0, v0, $fffc (=-$4)
A0 = SP + 0020;
A1 = S0;
V0 = 03c0;
[SP + 0020] = h(V0);
V0 = 0100;
[SP + 0022] = h(V0);
V0 = 0040;
[SP + 0024] = h(V0);
V0 = 0004;
800AC104	jal    $8004470c
[SP + 0026] = h(V0);
800AC10C	jal    $system_draw_sync
A0 = 0;
800AC114	jal    $system_memory_mark_removed_alloc
A0 = S0;
RA = w[SP + 002c];
S0 = w[SP + 0028];
SP = SP + 0030;
800AC128	jr     ra 
800AC12C	nop
////////////////////////////////
// funcac130
V0 = w[8004e9a4];
800AC138	addiu  sp, sp, $ffe0 (=-$20)
800AC13C	beq    v0, zero, Lac178 [$800ac178]
[SP + 0018] = w(RA);
800AC144	jal    funcab7e0 [$800ab7e0]
800AC148	nop
800AC14C	jal    funcab884 [$800ab884]
800AC150	nop
V1 = w[800aec40];
V0 = 000f;
[800aec50] = w(0);
[800aec4c] = w(V0);
[800aec48] = w(V1);

Lac178:	; 800AC178
RA = w[SP + 0018];
SP = SP + 0020;
800AC180	jr     ra 
800AC184	nop
////////////////////////////////
// funcac188
V0 = w[8004e9a4];
800AC190	addiu  sp, sp, $ffe8 (=-$18)
800AC194	beq    v0, zero, Lac1bc [$800ac1bc]
[SP + 0010] = w(RA);
A0 = w[800aec40];
800AC1A4	jal    $system_memory_mark_removed_alloc
800AC1A8	nop
A0 = w[800aec44];
800AC1B4	jal    $system_memory_mark_removed_alloc
800AC1B8	nop

Lac1bc:	; 800AC1BC
RA = w[SP + 0010];
SP = SP + 0018;
800AC1C4	jr     ra 
800AC1C8	nop
////////////////////////////////
// funcac1cc
V0 = w[8004e9a4];
800AC1D4	addiu  sp, sp, $ffe8 (=-$18)
800AC1D8	beq    v0, zero, Lac244 [$800ac244]
[SP + 0010] = w(RA);
V0 = w[800aec50];
800AC1E8	nop
V0 = V0 & 000f;
800AC1F0	bne    v0, zero, Lac22c [$800ac22c]
A1 = 0300;
A2 = w[800aec4c];
A0 = w[800aec48];
800AC208	jal    funcab5c8 [$800ab5c8]
A2 = A2 & 000f;
V1 = w[800aec4c];
[800aec48] = w(V0);
V1 = V1 + 0001;
[800aec4c] = w(V1);

Lac22c:	; 800AC22C
V0 = w[800aec50];
800AC234	nop
V0 = V0 + 0001;
[800aec50] = w(V0);

Lac244:	; 800AC244
RA = w[SP + 0010];
SP = SP + 0018;
800AC24C	jr     ra 
800AC250	nop
////////////////////////////////



////////////////////////////////
// read_two_bytes_signed()
data_138 = w[800af54c];
V0 = hu[data_138 + cc];
script_offset = w[800ad0d8];
return (((bu[script_offset + V0 + A0 + 1] << 8) + bu[script_offset + V0 + A0 + 0]) << 10) >> 10;
////////////////////////////////



////////////////////////////////
// read_two_bytes_unsigned()
data_138 = w[800af54c];
V0 = hu[data_138 + cc];
script_offset = w[800ad0d8];
return (bu[script_offset + V0 + A0 + 1] << 8) | bu[script_offset + V0 + A0 + 0];
////////////////////////////////



////////////////////////////////
// read_two_bytes_with_80()
script_offset = A0

A0 = script_offset;
read_two_bytes_unsigned();

if( V0 & 8000 )
{
    V0 = V0 & 7fff;
}
else
{
    A0 = V0 & ffff;
    get_bytes_from_800C2F3C();
}
return V0;
////////////////////////////////



////////////////////////////////
// funcac2fc
800AC2FC	addiu  sp, sp, $ffe8 (=-$18)
A1 = 0;
A3 = 0001;
A2 = w[80059a38];
A0 = 8006b4bc;
[SP + 0010] = w(RA);

loopac31c:	; 800AC31C
V0 = A2 + A1;
V1 = h[A0 + 0000];
V0 = bu[V0 + 22b1];
800AC328	nop
800AC32C	bne    v1, v0, Lac33c [$800ac33c]
800AC330	nop
800AC334	j      Lac340 [$800ac340]
[A0 + 0000] = h(0);

Lac33c:	; 800AC33C
[A0 + 0000] = h(A3);

Lac340:	; 800AC340
A1 = A1 + 0001;
V0 = A1 < 0003;
800AC348	bne    v0, zero, loopac31c [$800ac31c]
A0 = A0 + 0002;
800AC350	jal    funcace50 [$800ace50]
A0 = 0;
RA = w[SP + 0010];
SP = SP + 0018;
800AC360	jr     ra 
800AC364	nop
////////////////////////////////
// funcac368
800AC368	addiu  sp, sp, $ffd8 (=-$28)
V0 = w[80059a38];
V1 = 8006b4bc;
[SP + 0024] = w(RA);
[SP + 0020] = w(S4);
[SP + 001c] = w(S3);
[SP + 0018] = w(S2);
[SP + 0014] = w(S1);
[SP + 0010] = w(S0);
[8006b4c0] = h(0);
[8006b4be] = h(0);
[V1 + 0000] = h(0);
V0 = bu[V0 + 22b1];
800AC3AC	nop
800AC3B0	bne    v0, zero, Lac41c [$800ac41c]
S0 = 0;
S3 = 00ff;
S2 = V1;
S1 = 80061c20;

loopac3c8:	; 800AC3C8
V0 = w[80059a38];
800AC3D0	nop
V0 = V0 + S0;
V0 = bu[V0 + 22b1];
800AC3DC	nop
800AC3E0	bne    v0, zero, Lac400 [$800ac400]
800AC3E4	nop
A0 = w[S1 + 0000];
800AC3EC	jal    $8001ab84
800AC3F0	nop
800AC3F4	beq    v0, s3, Lac400 [$800ac400]
V0 = 0001;
[S2 + 0000] = h(V0);

Lac400:	; 800AC400
S2 = S2 + 0002;
S0 = S0 + 0001;
V0 = S0 < 0003;
800AC40C	bne    v0, zero, loopac3c8 [$800ac3c8]
S1 = S1 + 0004;
800AC414	j      Lac47c [$800ac47c]
800AC418	nop

Lac41c:	; 800AC41C
S3 = 0001;
S4 = 00ff;
S2 = V1;
S1 = 80061c20;

loopac430:	; 800AC430
V0 = w[80059a38];
800AC438	nop
V0 = V0 + S0;
V0 = bu[V0 + 22b1];
800AC444	nop
800AC448	bne    v0, s3, Lac468 [$800ac468]
800AC44C	nop
A0 = w[S1 + 0000];
800AC454	jal    $8001ab84
800AC458	nop
800AC45C	beq    v0, s4, Lac468 [$800ac468]
800AC460	nop
[S2 + 0000] = h(S3);

Lac468:	; 800AC468
S2 = S2 + 0002;
S0 = S0 + 0001;
V0 = S0 < 0003;
800AC474	bne    v0, zero, loopac430 [$800ac430]
S1 = S1 + 0004;

Lac47c:	; 800AC47C
800AC47C	jal    funcace50 [$800ace50]
A0 = 0001;
RA = w[SP + 0024];
S4 = w[SP + 0020];
S3 = w[SP + 001c];
S2 = w[SP + 0018];
S1 = w[SP + 0014];
S0 = w[SP + 0010];
SP = SP + 0028;
800AC4A0	jr     ra 
800AC4A4	nop
////////////////////////////////
// funcac4a8
800AC4A8	addiu  sp, sp, $ffd8 (=-$28)
[SP + 001c] = w(S3);
S3 = A0;
[SP + 0018] = w(S2);
S2 = 8006f020;
[SP + 0010] = w(S0);
S0 = S3 << 02;
V0 = w[80059a38];
S2 = S0 + S2;
[SP + 0020] = w(RA);
[SP + 0014] = w(S1);
V0 = V0 + S3;
[V0 + 22b1] = b(0);
V0 = w[S2 + 0000];
A1 = w[800aefe4];
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 03;
V1 = V1 - V0;
V1 = V1 << 02;
V0 = 80059ad4;
S0 = S0 + V0;
V1 = V1 + A1;
A0 = w[S0 + 0000];
V1 = w[V1 + 0004];
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V0 = V0 - A0;
V0 = V0 << 02;
V0 = V0 + A1;
A0 = w[V0 + 0004];
[V0 + 0004] = w(V1);
V1 = w[S2 + 0000];
800AC540	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
[V0 + 0004] = w(A0);
V0 = w[S2 + 0000];
800AC56C	nop
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 03;
V1 = V1 - V0;
V0 = w[800aefe4];
V1 = V1 << 02;
V1 = V1 + V0;
V0 = hu[V1 + 0058];
800AC594	nop
V0 = V0 & f07f;
V0 = V0 | 0200;
[V1 + 0058] = h(V0);
V1 = w[S2 + 0000];
800AC5A8	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = hu[V0 + 0058];
800AC5D0	nop
V1 = V1 & ffdf;
[V0 + 0058] = h(V1);
V1 = w[S2 + 0000];
800AC5E0	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
A0 = w[V0 + 004c];
800AC608	nop
V0 = w[A0 + 0000];
800AC610	addiu  v1, zero, $fffe (=-$2)
V0 = V0 & V1;
[A0 + 0000] = w(V0);
A0 = w[S2 + 0000];
A1 = w[S0 + 0000];
800AC624	jal    func9fab4 [$8009fab4]
800AC628	nop
V1 = w[S0 + 0000];
800AC630	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0020];
800AC660	nop
[A0 + 0000] = w(V0);
V1 = w[S0 + 0000];
800AC66C	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0024];
800AC69C	nop
[A0 + 0004] = w(V0);
V1 = w[S0 + 0000];
800AC6A8	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0028];
800AC6D8	nop
[A0 + 0008] = w(V0);
V1 = w[S0 + 0000];
800AC6E4	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800AC70C	nop
V0 = w[V1 + 0000];
800AC714	nop
V0 = V0 | 0400;
[V1 + 0000] = w(V0);
V1 = w[S0 + 0000];
800AC724	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
A0 = w[V0 + 004c];
800AC74C	nop
V0 = w[A0 + 0000];
800AC754	addiu  v1, zero, $fcff (=-$301)
V0 = V0 & V1;
[A0 + 0000] = w(V0);
V1 = w[S2 + 0000];
800AC764	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800AC78C	nop
V0 = w[V1 + 0000];
800AC794	addiu  a0, zero, $e7ff (=-$1801)
V0 = V0 & A0;
[V1 + 0000] = w(V0);
V1 = w[S0 + 0000];
800AC7A4	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800AC7CC	nop
V0 = w[V1 + 0000];
800AC7D4	nop
V0 = V0 & A0;
[V1 + 0000] = w(V0);
V0 = w[S2 + 0000];
A1 = w[800aefe4];
A0 = w[S0 + 0000];
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 03;
V1 = V1 - V0;
V1 = V1 << 02;
V1 = V1 + A1;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V0 = V0 - A0;
V0 = V0 << 02;
V0 = V0 + A1;
V0 = w[V0 + 004c];
V1 = w[V1 + 004c];
V0 = hu[V0 + 0108];
800AC82C	nop
[V1 + 0108] = h(V0);
V0 = w[S2 + 0000];
A1 = w[800aefe4];
A0 = w[S0 + 0000];
V1 = V0 << 01;
V1 = V1 + V0;
V1 = V1 << 03;
V1 = V1 - V0;
V1 = V1 << 02;
V1 = V1 + A1;
V0 = A0 << 01;
V0 = V0 + A0;
V0 = V0 << 03;
V0 = V0 - A0;
V0 = V0 << 02;
V0 = V0 + A1;
V0 = w[V0 + 004c];
V1 = w[V1 + 004c];
V0 = hu[V0 + 0106];
800AC880	nop
[V1 + 0106] = h(V0);
V1 = w[S2 + 0000];
800AC88C	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800AC8B4	nop
V0 = hu[V1 + 00e6];
800AC8BC	nop
[V1 + 00e8] = h(V0);
V1 = w[S0 + 0000];
800AC8C8	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
S1 = 800aefe4;
V0 = hu[V1 + 00e6];
A1 = 0006;
[V1 + 00e8] = h(V0);
V0 = w[S2 + 0000];
V1 = w[S1 + 0000];
A2 = V0 << 01;
A2 = A2 + V0;
A2 = A2 << 03;
A2 = A2 - V0;
V0 = w[800aefe4];
A2 = A2 << 02;
V0 = A2 + V0;
A0 = w[V0 + 0004];
800AC930	jal    func81808 [$80081808]
A2 = V1 + A2;
V0 = w[S0 + 0000];
800AC93C	nop
A2 = V0 << 01;
A2 = A2 + V0;
A2 = A2 << 03;
A2 = A2 - V0;
V0 = w[800aefe4];
A2 = A2 << 02;
V0 = A2 + V0;
A0 = w[V0 + 0004];
V0 = w[V0 + 004c];
V1 = w[S1 + 0000];
A1 = h[V0 + 00e6];
800AC970	jal    func81808 [$80081808]
A2 = V1 + A2;
800AC978	jal    func9f474 [$8009f474]
A0 = S3;
A0 = w[S2 + 0]; // entity id
A1 = 0; // only particle
field_particle_reset_particle_for_entity();
////////////////////////////////



////////////////////////////////
// funcac9ac
800AC9AC	addiu  sp, sp, $ffd8 (=-$28)
[SP + 001c] = w(S3);
S3 = A0;
[SP + 0010] = w(S0);
S0 = 80059ad4;
[SP + 0018] = w(S2);
S2 = S3 << 02;
V0 = w[800af1f0];
A0 = w[800aefe4];
S0 = S2 + S0;
[SP + 0020] = w(RA);
[SP + 0014] = w(S1);
V1 = w[S0 + 0000];
A1 = V0 << 01;
A1 = A1 + V0;
A1 = A1 << 03;
A1 = A1 - V0;
A1 = A1 << 02;
A2 = A1 + A0;
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V0 = V0 << 02;
V0 = V0 + A0;
V0 = w[V0 + 0004];
A0 = w[A2 + 0004];
[A2 + 0004] = w(V0);
V1 = w[S0 + 0000];
800ACA2C	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
[V0 + 0004] = w(A0);
V1 = w[S0 + 0000];
800ACA58	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0020];
800ACA88	nop
[A0 + 0000] = w(V0);
V1 = w[S0 + 0000];
800ACA94	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0024];
800ACAC4	nop
[A0 + 0004] = w(V0);
V1 = w[S0 + 0000];
800ACAD0	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
A0 = w[V0 + 0004];
V0 = w[V1 + 0028];
800ACB00	nop
[A0 + 0008] = w(V0);
V0 = w[800aefe4];
800ACB10	nop
A1 = A1 + V0;
V0 = hu[A1 + 0058];
800ACB1C	nop
V0 = V0 | 0020;
[A1 + 0058] = h(V0);
V1 = w[S0 + 0000];
800ACB2C	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACB54	nop
V0 = w[V1 + 0000];
800ACB5C	nop
V0 = V0 | 0200;
[V1 + 0000] = w(V0);
V1 = w[S0 + 0000];
800ACB6C	addiu  a0, zero, $faff (=-$501)
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
A1 = w[V0 + 004c];
V1 = w[80059a38];
V0 = w[A1 + 0000];
V1 = V1 + S3;
V0 = V0 & A0;
[A1 + 0000] = w(V0);
V0 = 0001;
[V1 + 22b1] = b(V0);
V0 = 8006f020;
S2 = S2 + V0;
V1 = w[S2 + 0000];
800ACBC4	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACBEC	nop
V0 = w[V1 + 0000];
800ACBF4	addiu  a0, zero, $e7ff (=-$1801)
V0 = V0 & A0;
[V1 + 0000] = w(V0);
V1 = w[S0 + 0000];
800ACC04	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACC2C	nop
V0 = w[V1 + 0000];
800ACC34	nop
V0 = V0 & A0;
[V1 + 0000] = w(V0);
V1 = w[S2 + 0000];
800ACC44	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACC6C	nop
V0 = hu[V1 + 00e6];
800ACC74	nop
[V1 + 00e8] = h(V0);
V1 = w[S0 + 0000];
800ACC80	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACCA8	nop
V0 = hu[V1 + 00e6];
800ACCB0	nop
[V1 + 00e8] = h(V0);
V0 = w[S2 + 0000];
S1 = 800aefe4;
A2 = V0 << 01;
A2 = A2 + V0;
A2 = A2 << 03;
A2 = A2 - V0;
V0 = w[800aefe4];
A2 = A2 << 02;
V0 = A2 + V0;
A0 = w[V0 + 0004];
V0 = w[V0 + 004c];
V1 = w[S1 + 0000];
A1 = h[V0 + 00e6];
800ACCF4	jal    func81808 [$80081808]
A2 = V1 + A2;
V0 = w[S0 + 0000];
800ACD00	nop
A2 = V0 << 01;
A2 = A2 + V0;
A2 = A2 << 03;
A2 = A2 - V0;
V0 = w[800aefe4];
A2 = A2 << 02;
V0 = A2 + V0;
A0 = w[V0 + 0004];
V0 = w[V0 + 004c];
V1 = w[S1 + 0000];
A1 = h[V0 + 00e6];
800ACD34	jal    func81808 [$80081808]
A2 = V1 + A2;
A0 = w[S2 + 0000]; // entity id
A1 = 0; // only particle
field_particle_reset_particle_for_entity();

A0 = S3;
800ACD48	jal    func9f474 [$8009f474]
////////////////////////////////



////////////////////////////////
// funcacd70
V0 = w[800b173c];
800ACD78	nop
800ACD7C	beq    v0, zero, Lace48 [$800ace48]
800ACD80	nop
A1 = 0;
T1 = 00ff;
A2 = w[80059a38];
T0 = 0001;
800ACD98	addiu  a3, zero, $faff (=-$501)
A0 = 80059ad4;

loopacda4:	; 800ACDA4
V1 = w[A0 + 0000];
800ACDA8	nop
800ACDAC	beq    v1, t1, Lace38 [$800ace38]
V0 = A2 + A1;
V0 = bu[V0 + 22b1];
800ACDB8	nop
800ACDBC	bne    v0, t0, Lace38 [$800ace38]
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACDE4	nop
V0 = w[V1 + 0000];
800ACDEC	nop
V0 = V0 | 0200;
[V1 + 0000] = w(V0);
V1 = w[A0 + 0000];
800ACDFC	nop
V0 = V1 << 01;
V0 = V0 + V1;
V0 = V0 << 03;
V0 = V0 - V1;
V1 = w[800aefe4];
V0 = V0 << 02;
V0 = V0 + V1;
V1 = w[V0 + 004c];
800ACE24	nop
V0 = w[V1 + 0000];
800ACE2C	nop
V0 = V0 & A3;
[V1 + 0000] = w(V0);

Lace38:	; 800ACE38
A1 = A1 + 0001;
V0 = A1 < 0003;
800ACE40	bne    v0, zero, loopacda4 [$800acda4]
A0 = A0 + 0004;

Lace48:	; 800ACE48
800ACE48	jr     ra 
800ACE4C	nop
////////////////////////////////



////////////////////////////////
// funcace50

V0 = w[800b173c];
S3 = A0;
800ACE70	beq    v0, zero, Lacf20 [$800acf20]

S0 = 0;
S2 = 8006b4bc;
S1 = 80059ad4;

loopace8c:	; 800ACE8C
V1 = w[S1 + 0000];
V0 = 00ff;
800ACE94	beq    v1, v0, Lacf0c [$800acf0c]
A0 = S0 << 02;
V1 = h[S2 + 0000];
V0 = 0001;
800ACEA4	bne    v1, v0, Lacf0c [$800acf0c]
800ACEA8	nop
V1 = w[80059a38];
V0 = w[8006f020 + A0];
V1 = V1 + S0;
[800af1f0] = w(V0);
V0 = bu[V1 + 22b1];
800ACED0	nop
800ACED4	bne    v0, zero, Laceec [$800aceec]
800ACED8	nop
800ACEDC	beq    s3, zero, Lacf04 [$800acf04]
800ACEE0	nop
800ACEE4	j      Lacef4 [$800acef4]
800ACEE8	nop

Laceec:	; 800ACEEC
800ACEEC	bne    s3, zero, Lacf04 [$800acf04]
800ACEF0	nop

Lacef4:	; 800ACEF4
800ACEF4	jal    funcac9ac [$800ac9ac]
A0 = S0;
800ACEFC	j      Lacf10 [$800acf10]
S2 = S2 + 0002;

Lacf04:	; 800ACF04
800ACF04	jal    funcac4a8 [$800ac4a8]
A0 = S0;

Lacf0c:	; 800ACF0C
S2 = S2 + 0002;

Lacf10:	; 800ACF10
S0 = S0 + 0001;
V0 = S0 < 0003;
800ACF18	bne    v0, zero, loopace8c [$800ace8c]
S1 = S1 + 0004;

Lacf20:	; 800ACF20
////////////////////////////////
