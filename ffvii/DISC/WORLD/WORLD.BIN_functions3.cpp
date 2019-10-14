////////////////////////////////
// wm_load_model_packets_and_scale()

model = A0; // model global offset
S3 = A1;
S4 = A2;

[model + 20] = w(S3);

S3 = S3 + bu[model + 2] * 20; // skip bone matrixes

// go through all parts
for( int i = 0; i < bu[model + 3]; ++i )
{
    A0 = w[model + 1c] + hu[model + 18] + i * 20; // global pointer to part
    A1 = S3; // packets
    A2 = 0; // set pointer to data
    A3 = S4; // use global tex offset
    wm_create_packets_for_model_part();

    S3 = V0; // end of packets
}

A0 = model;
A1 = h[model + 16]; // scale
A2 = 0; // not force
wm_scale_model_all();

return S3;
////////////////////////////////



////////////////////////////////
// wm_create_packets_for_model_part()

part = A0; // pointer to part
packet_start = A1; // place for packets
S2 = A3; // 0

quad_t = bu[part + 4];
triangle_t = bu[part + 5];
quad_t2 = bu[part + 6];
triangle_t2 = bu[part + 7];
triangle_m = bu[part + 8];
quad_m = bu[part + 9];
triangle = bu[part + a];
quads = bu[part + b];

if( A2 != 0 )
{
    [part + 18] = w(part + 20); // after header
}

vertexes = w[part + 18];
texture_coords = vertexes + hu[part + 10];
texture_settings = vertexes + hu[part + 12];
packets_size = hu[part + 16];

[part + 1c] = w(packet_start);

[SP + 30] = w((S2 - ((S2 / 4) * 4)) << 6);
[SP + 38] = w((S2 / 4) << 5);

[SP + 40] = w((S2 - ((S2 / 8) * 8)) << 5);
[SP + 48] = w(((S2 / 8) << 5));

for( int i = 0; i < 2; ++i )
{
    packet = packet_start;
    if( i != 0 )
    {
        packet = packet_start + packets_size;
    }

    texture_control = vertexes + hu[part + 14];
    poly = vertexes + hu[part + e];

    // shaded textured four-point polygon, opaque/semi-transparent, texture-blending
    for( int j = 0; j < quad_t; ++j )
    {
        [packet + 4] = w(w[poly + 4]); // colour 1
        [packet + 10] = w(w[poly + 8]); // colour 2
        [packet + 1c] = w(w[poly + c]); // colour 3
        [packet + 28] = w(w[poly + 10]); // colour 4

        V1 = w[poly + 14];
        [packet + с] = h(hu[texture_coords + (V1 & ff) * 2]); // uv 1
        [packet + 18] = h(hu[texture_coords + ((V1 & ff00) >> 8) * 2]); // uv 2
        [packet + 24] = h(hu[texture_coords + ((V1 & ff0000) >> 10) * 2]); // uv 3
        [packet + 30] = h(hu[texture_coords + ((V1 & ff000000) >> 18) * 2]); // uv 4

        S6 = bu[texture_control];
        texture_control = texture_control + 1;

        S1 = w[texture_settings + (S6 & f) * 4];
        V0 = 0 - (0 < ((S1 & 3f) ^ 2));
        //               y                                        x
        [packet + e] = h(((((S1 << 1) >> 17) + (S2 & V0)) << 6) | ((S1 >> 10) & 3f)); // clut

        system_gpu_get_type(); // check old GPU support
        if( ( V0 == 1 ) || ( V0 == 2 ) )
        {
            [packet + 1a] = h(((S1 & c0) << 3) | ((S6 << 2) & 180) | ((S1 >> 7) & 20) | ((S1 & f00) >> 8)); // texpage
        }
        else
        {
            //                tex page bits      semi trans  tex page Y base            tex page X base
            [packet + 1a] = h(((S1 & c0) << 1) | (S6 & 60) | (((S1 >> 4) & 100) >> 4) | ((S1 & f00) >> 8)); // texpage
        }

        if( ( S1 & 3f ) == 0 )
        {
            off_x = w[SP + 30];
            off_y = w[SP + 38];
        }
        else if( ( S1 & 3f ) == 1 )
        {
            off_x = w[SP + 40];
            off_y = w[SP + 48];
        }
        else
        {
            off_x = 0;
            off_y = 0;
        }

        [packet + 3] = b(c); // size
        [packet + 7] = b(3с); // control
        [packet + c] = b(bu[packet + c] + off_x);
        [packet + d] = b(bu[packet + d] + off_y);
        [packet + 18] = b(bu[packet + 18] + off_x);
        [packet + 19] = b(bu[packet + 19] + off_y);
        [packet + 24] = b(bu[packet + 24] + off_x);
        [packet + 25] = b(bu[packet + 25] + off_y);
        [packet + 30] = b(bu[packet + 30] + off_x);
        [packet + 31] = b(bu[packet + 31] + off_y);

        if( S6 & 10 )
        {
            [packet + 7] = b(3e); // control
        }

        poly = poly + 18;
        packet = packet + 34;
    }

    // shaded textured three-point polygon, opaque/semi-transparent, texture-blending
    for( int j = 0; j < triangle_t; ++j )
    {
        [packet + 4] = w(w[poly + 4]);
        [packet + 16] = w(w[poly + 8]);
        [packet + 1c] = w(w[poly + c]);

        V1 = w[poly + 10];
        [packet + c] = h(hu[texture_coords + (V1 & ff) * 2]);
        [packet + 18] = h(hu[texture_coords + (V1 & ff00) * 2]);
        [packet + 24] = h(hu[texture_coords + (V1 & ff0000) *2]);

        S6 = bu[texture_control];
        texture_control = texture_control + 1;

        S1 = w[texture_settings + (S6 & f) * 4];
        V0 = 0 - (0 < ((S1 & 3f) ^ 2));
        [packet + e] = h(((((S1 << 01) >> 17) + (S2 & V0)) << 6) | ((S1 >> 10) & 3f));

        system_gpu_get_type(); // check old GPU support
        if( ( V0 == 1 ) || ( V0 == 2 ) )
        {
            [packet + 1a] = h(((S1 & c0) << 3) | ((S6 << 2) & 180) | ((S1 >> 7) & 20) | ((S1 & f00) >> 8));
        }
        else
        {
            [packet + 1a] = h(((S1 & c0) << 1) | (S6 & 60) | (((S1 >> 4) & 100) >> 4) | ((S1 & f00) >> 8));
        }

        if( ( S1 & 3f ) == 0 )
        {
            A0 = w[SP + 30];
            A1 = w[SP + 38];
        }
        else if( ( S1 & 3f ) == 1 )
        {
            A0 = w[SP + 40];
            A1 = w[SP + 48];
        }
        else
        {
            A0 = 0;
            A1 = 0;
        }

        [packet + 3] = b(9);
        [packet + 7] = b(34);
        [packet + 7 + 5] = b(bu[packet + 7 + 5] + A0);
        [packet + 7 + 6] = b(bu[packet + 7 + 6] + A1);
        [packet + 7 + 11] = b(bu[packet + 7 + 11] + A0);
        [packet + 7 + 12] = b(bu[packet + 7 + 12] + A1);
        [packet + 7 + 1d] = b(bu[packet + 7 + 1d] + A0);
        [packet + 7 + 1e] = b(bu[packet + 7 + 1e] + A1);

        if( S6 & 10 )
        {
            [packet + 7] = b(36);
        }

        poly = poly + 14;
        packet = packet + 28;
    }

    // textured four-point polygon, opaque/semi-transparent, texture-blending
    for( int j = 0; j < quad_t2; ++j )
    {
        [packet + 4] = w(w[poly + 4]);

        V1 = w[poly + 8];
        [packet + с] = h(hu[texture_coords + (V1 & ff) * 2]); // uv 1
        [packet + 14] = h(hu[texture_coords + ((V1 & ff00) >> 8) * 2]); // uv 2
        [packet + 1c] = h(hu[texture_coords + ((V1 & ff0000) >> 10) * 2]); // uv 3
        [packet + 24] = h(hu[texture_coords + ((V1 & ff000000) >> 18) * 2]); // uv 4

        S4 = bu[texture_control];
        texture_control = texture_control + 1;

        S1 = w[texture_settings + (S4 & f) * 4];
        V0 = 0 - (0 < ((S1 & 3f) ^ 2));
        [packet + e] = h(((((S1 << 01) >> 17) + (S2 & V0)) << 6) | ((S1 >> 10) & 3f));

        system_gpu_get_type(); // check old GPU support
        if( ( V0 == 1 ) || ( V0 == 2 ) )
        {
            [packet + 16] = h(((S1 & c0) << 3) | ((S6 << 2) & 180) | ((S1 >> 7) & 20) | ((S1 & f00) >> 8));
        }
        else
        {
            [packet + 16] = h(((S1 & c0) << 1) | (S6 & 60) | (((S1 >> 4) & 100) >> 4) | ((S1 & f00) >> 8));
        }

        if( ( S1 & 3f ) == 0 )
        {
            A0 = w[SP + 30];
            A1 = w[SP + 38];
        }
        else if( ( S1 & 3f ) == 1 )
        {
            A0 = w[SP + 40];
            A1 = w[SP + 48];
        }
        else
        {
            A0 = 0;
            A1 = 0;
        }

        [packet + 3] = b(9);
        [packet + 7] = b(2c);
        [packet + c] = b(bu[packet + c] + A0);
        [packet + d] = b(bu[packet + d] + A1);
        [packet + 14] = b(bu[packet + 14] + A0);
        [packet + 15] = b(bu[packet + 15] + A1);
        [packet + 1c] = b(bu[packet + 1c] + A0);
        [packet + 1d] = b(bu[packet + 1d] + A1);
        [packet + 24] = b(bu[packet + 24] + A0);
        [packet + 25] = b(bu[packet + 25] + A1);

        if( S4 & 10 )
        {
            [packet + 7] = b(2e);
        }

        poly = poly + c;
        packet = packet + 28;
    }

    // textured three-point polygon, opaque/semi-transparent, texture-blending
    for( int j = 0; j < triangle_t2; ++j )
    {
        [packet + 4] = w(w[poly + 4]);

        V1 = w[poly + 8];
        [packet + c] = h(hu[texture_coords + (V1 & ff) * 2]);
        [packet + 14] = h(hu[texture_coords + ((V1 & ff00) >> 8) * 2]);
        [packet + 1c] = h(hu[texture_coords + ((V1 & ff0000) >> 10) * 2]);

        S4 = bu[texture_control];
        texture_control = texture_control + 1;

        S1 = w[texture_settings + (S4 & f) * 4];
        [packet + e] = h(((((S1 << 1) >> 17) + (S2 & (0 - (0 < ((S1 & 3f) ^ 2))))) << 6) | ((S1 >> 10) & 3f));

        system_gpu_get_type(); // check old GPU support
        if( V0 == 1 || V0 == 2 )
        {
            [packet + 16] = h((((S1 & c0) << 3) | ((S4 << 2) & 180)) | ((S1 >> 7) & 20) | ((S1 & f00) >> 8));
        }
        else
        {
            [packet + 16] = h((((S1 & c0) << 1) | (S4 & 60)) | (((S1 >> 4) & 100) >> 4) | ((S1 & 0f00) >> 8));
        }

        if( ( S1 & 3f ) == 0 )
        {
            A0 = w[SP + 30];
            A1 = w[SP + 38];
        }
        else if( ( S1 & 3f ) == 1 )
        {
            A0 = w[SP + 40];
            A1 = w[SP + 48];
        }
        else
        {
            A0 = 0;
            A1 = 0;
        }

        [packet + 3] = b(7);
        [packet + 7] = b(24);
        [packet + c] = b(bu[packet + c] + A0);
        [packet + d] = b(bu[packet + d] + A1);
        [packet + 14] = b(bu[packet + 14] + A0);
        [packet + 15] = b(bu[packet + 15] + A1);
        [packet + 1c] = b(bu[packet + 1c] + A0);
        [packet + 1d] = b(bu[packet + 1d] + A1);

        if( S4 & 10 )
        {
            [packet + 7] = b(26);
        }

        poly = poly + c;
        packet = packet + 20;
    }

    // monochrome three-point polygon, opaque
    for( int j = 0; j < triangle_m; ++ j )
    {
        [packet + 3] = b(4);
        [packet + 4] = w(w[poly + 4]);
        [packet + 7] = b(20);
        poly = poly + 8;
        packet = packet + 14;
    }

    // monochrome four-point polygon, opaque
    for( int j = 0; j < quad_m; ++j )
    {
        [packet + 3] = b(5);
        [packet + 4] = w(w[poly + 4]);
        [packet + 7] = b(28);
        poly = poly + 8;
        packet = packet + 18;
    }

    // shaded three-point polygon, opaque
    for( int j = 0; j < triangle; ++ j )
    {
        [packet + 3] = b(6);
        [packet + 4] = w(w[poly + 4]);
        [packet + 7] = b(30);
        [packet + c] = w(w[poly + 8]);
        [packet + 14] = w(w[poly + c]);
        poly = poly + 10;
        packet = packet + 1c;
    }

    // shaded four-point polygon, opaque
    for( int j = 0; j < quads; ++j )
    {
        [packet + 3] = b(8);
        [packet + 4] = w(w[poly + 4]);
        [packet + 7] = b(38);
        [packet + c] = w(w[poly + 8]);
        [packet + 14] = w(w[poly + c]);
        [packet + 1c] = w(w[poly + 10]);
        poly = poly + 14;
        packet = packet + 24;
    }
}

return packet_start + packets_size * 2;
////////////////////////////////



////////////////////////////////
// wm_load_textures_to_vram()

tex = A0;

for( int i = 0; i < bu[tex + 4]; ++i )
{
    [SP + 10] = h(hu[tex + 8 + i * c + 4]); // x
    [SP + 12] = h(hu[tex + 8 + i * c + 6]); // y
    [SP + 14] = h(hu[tex + 8 + i * c + 0]); // width
    [SP + 16] = h(hu[tex + 8 + i * c + 2]); // height

    A0 = SP + 10; // rect
    A1 = tex + w[tex + 8 + i * c + 8]; // pointer to data
    system_psyq_load_image();
}
////////////////////////////////



////////////////////////////////
// funcc08a8
800C08A8	addiu  sp, sp, $ffc4 (=-$3c)
[SP + 0020] = w(S2);
S2 = A0;
[SP + 0038] = w(RA);
[SP + 0034] = w(S7);
[SP + 0030] = w(S6);
[SP + 002c] = w(S5);
[SP + 0028] = w(S4);
[SP + 0024] = w(S3);
[SP + 001c] = w(S1);
[SP + 0018] = w(S0);
S5 = w[S2 + 0000];
800C08D8	nop
V0 = S5 & 00ff;
800C08E0	beq    v0, zero, Lc0b18 [$800c0b18]
800C08E4	nop
V0 = hu[S2 + 0018];
V1 = w[S2 + 001c];
800C08F0	nop
A0 = V0 + V1;
V0 = S5 >> 18;
S1 = w[S2 + 0020];
800C0900	beq    v0, zero, Lc0b18 [$800c0b18]
S3 = 0;
800C0908	lui    s4, $1f80
S0 = A0;

Lc0910:	; 800C0910
S6 = w[S0 + 0000];
800C0914	nop
V0 = S6 & 00ff;
800C091C	beq    v0, zero, Lc0b04 [$800c0b04]
800C0920	addiu  v0, zero, $ffff (=-$1)
V1 = S5 << 10;
V1 = V1 >> 18;
800C092C	beq    v1, v0, Lc0aac [$800c0aac]
800C0930	nop
T5 = w[S1 + 0000];
T6 = w[S1 + 0004];
R11R12 = T5;
R13R21 = T6;
T5 = w[S1 + 0008];
T6 = w[S1 + 000c];
T7 = w[S1 + 0010];
R22R23 = T5;
R31R32 = T6;
R33 = T7;
T5 = w[S1 + 0014];
T6 = w[S1 + 0018];
TRX = T5;
T7 = w[S1 + 001c];
TRY = T6;
TRZ = T7;
V0 = S6 << 10;
V0 = V0 >> 13;
T4 = S1 + V0;
T5 = hu[T4 + 0000];
T6 = hu[T4 + 0006];
T7 = hu[T4 + 000c];
IR1 = T5;
IR2 = T6;
IR3 = T7;
800C0998	nop
800C099C	nop
gte_rtir12(); // ir * rotmatrix
V0 = IR1;
A1 = IR2;
S7 = IR3;
T5 = hu[T4 + 0002];
T6 = hu[T4 + 0008];
T7 = hu[T4 + 000e];
IR1 = T5;
IR2 = T6;
IR3 = T7;
800C09C8	nop
800C09CC	nop
gte_rtir12(); // ir * rotmatrix
[S4 + 0000] = h(V0);
[S4 + 0006] = h(A1);
[S4 + 000c] = h(S7);
V0 = IR1;
A1 = IR2;
S7 = IR3;
T5 = hu[T4 + 0004];
T6 = hu[T4 + 000a];
T7 = hu[T4 + 0010];
IR1 = T5;
IR2 = T6;
IR3 = T7;
800C0A04	nop
800C0A08	nop
gte_rtir12(); // ir * rotmatrix
[S4 + 0002] = h(V0);
[S4 + 0008] = h(A1);
[S4 + 000e] = h(S7);
V0 = IR1;
A1 = IR2;
S7 = IR3;
T6 = hu[T4 + 0018];
T5 = hu[T4 + 0014];
T6 = T6 << 10;
T5 = T5 | T6;
VXY0 = T5;
VZ0 = w[T4 + 001c];
800C0A40	nop
800C0A44	nop
gte_rtv0tr(); // v0 * rotmatrix + tr vector
[S4 + 0004] = h(V0);
[S4 + 000a] = h(A1);
[S4 + 0010] = h(S7);
[S4 + 0014] = w(IR1);
[S4 + 0018] = w(IR2);
[S4 + 001c] = w(IR3);
T5 = w[S4 + 0000];
T6 = w[S4 + 0004];
R11R12 = T5;
R13R21 = T6;
T5 = w[S4 + 0008];
T6 = w[S4 + 000c];
T7 = w[S4 + 0010];
R22R23 = T5;
R31R32 = T6;
R33 = T7;
T5 = w[S4 + 0014];
T6 = w[S4 + 0018];
TRX = T5;
T7 = w[S4 + 001c];
TRY = T6;
TRZ = T7;
800C0AA4	j      Lc0afc [$800c0afc]
800C0AA8	nop

Lc0aac:	; 800C0AAC
V0 = S6 & ff00;
V0 = V0 << 10;
V0 = V0 >> 13;
V0 = S1 + V0;
T5 = w[V0 + 0000];
T6 = w[V0 + 0004];
R11R12 = T5;
R13R21 = T6;
T5 = w[V0 + 0008];
T6 = w[V0 + 000c];
T7 = w[V0 + 0010];
R22R23 = T5;
R31R32 = T6;
R33 = T7;
T5 = w[V0 + 0014];
T6 = w[V0 + 0018];
TRX = T5;
T7 = w[V0 + 001c];
TRY = T6;
TRZ = T7;

Lc0afc:	; 800C0AFC
800C0AFC	jal    funcc0b48 [$800c0b48]
A0 = S0;

Lc0b04:	; 800C0B04
V0 = S5 >> 18;
S3 = S3 + 0001;
V0 = S3 < V0;
800C0B10	bne    v0, zero, Lc0910 [$800c0910]
S0 = S0 + 0020;

Lc0b18:	; 800C0B18
RA = w[SP + 0038];
S7 = w[SP + 0034];
S6 = w[SP + 0030];
S5 = w[SP + 002c];
S4 = w[SP + 0028];
S3 = w[SP + 0024];
S2 = w[SP + 0020];
S1 = w[SP + 001c];
S0 = w[SP + 0018];
SP = SP + 003c;
800C0B40	jr     ra 
800C0B44	nop
////////////////////////////////


////////////////////////////////
// funcc0b48

S7 = A0;
800C0B54	lui    v1, $aaaa
A2 = bu[S7 + 0002];
V1 = V1 | aaab;
800C0B80	multu  a2, v1
800C0B84	lui    s0, $1f80
S0 = S0 | 0008;
A3 = 0;
V0 = w[S7 + 0018];
800C0B94	lui    s2, $800c
S2 = w[S2 + 7530];
T0 = V0 + 0004;
800C0BA0	mfhi   v0
800C0BA4	lui    a1, $1f80
A1 = A1 | 0008;
V0 = V0 >> 01;
S1 = V0 & 00ff;
800C0BB4	beq    s1, zero, Lc0c0c [$800c0c0c]
800C0BB8	nop

loopc0bbc:	; 800C0BBC
VXY0 = w[T0 + 0000];
VZ0 = w[T0 + 0004];
VXY1 = w[T0 + 0008];
VZ1 = w[T0 + 000c];
VXY2 = w[T0 + 0010];
VZ2 = w[T0 + 0014];
800C0BD4	nop
800C0BD8	nop
gte_RTPT(); // Perspective transform on 3 points
T0 = T0 + 0018;
A3 = A3 + 0001;
[A1 + 0000] = w(SXY0);
[A1 + 0008] = w(SXY1);
[A1 + 0010] = w(SXY2);
[A1 + 0004] = w(SZ1);
[A1 + 000c] = w(SZ2);
[A1 + 0014] = w(SZ3);
V0 = A3 < S1;
800C0C04	bne    v0, zero, loopc0bbc [$800c0bbc]
A1 = A1 + 0018;

Lc0c0c:	; 800C0C0C
V1 = S1 << 01;
A3 = V1 + S1;
V0 = A3 < A2;
800C0C18	beq    v0, zero, Lc0c50 [$800c0c50]
V0 = A3 << 03;

loopc0c20:	; 800C0C20
VXY0 = w[T0 + 0000];
VZ0 = w[T0 + 0004];
800C0C28	nop
800C0C2C	nop
gte_RTPS(); // Perspective transform
T0 = T0 + 0008;
A3 = A3 + 0001;
[A1 + 0000] = w(SXY2);
[A1 + 0004] = w(SZ3);
V0 = A3 < A2;
800C0C48	bne    v0, zero, loopc0c20 [$800c0c20]
A1 = A1 + 0008;

Lc0c50:	; 800C0C50
V0 = bu[800c752c];
A2 = w[S7 + 001c];
800C0C5C	beq    v0, zero, Lc0c70 [$800c0c70]
A3 = 0;
V0 = hu[S7 + 0016];
800C0C68	nop
A2 = A2 + V0;

Lc0c70:	; 800C0C70
FP = w[S7 + 0004];
800C0C74	lui    s6, $ff00
800C0C78	lui    s3, $00ff
S3 = S3 | ffff;
S1 = FP & 00ff;
800C0C84	beq    s1, zero, Lc0d88 [$800c0d88]
V0 = FP & ff00;
T8 = A2 + 002c;

loopc0c90:	; 800C0C90
V1 = w[T0 + 0000];
800C0C94	nop
V0 = V1 & 00ff;
V0 = V0 << 03;
T9 = S0 + V0;
V0 = V1 & ff00;
V0 = V0 >> 05;
T3 = S0 + V0;
V0 = V1 >> 0d;
V0 = V0 & 07f8;
T2 = S0 + V0;
V1 = V1 >> 18;
V1 = V1 << 03;
T1 = S0 + V1;
V0 = w[T9 + 0000];
V1 = w[T3 + 0000];
A0 = w[T2 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 0018;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + ffdc] = w(V0);
[T8 + ffe8] = w(V1);
[T8 + fff4] = w(A0);
T6 = S4 & S6;
T8 = T8 + 0034;
V0 = MAC0;
800C0D08	nop
800C0D0C	bgtz   v0, Lc0d1c [$800c0d1c]
A1 = w[T1 + 0000];
800C0D14	j      Lc0d78 [$800c0d78]
[A2 + 0000] = w(T6);

Lc0d1c:	; 800C0D1C
V1 = w[T9 + 0004];
[T8 + ffcc] = w(A1);
S5 = w[T3 + 0004];
V0 = w[T2 + 0004];
A0 = w[T1 + 0004];
V1 = V1 + S5;
V1 = V1 + V0;
V0 = V1 + A0;
800C0D3C	bgez   v0, Lc0d48 [$800c0d48]
800C0D40	nop
V0 = V0 + 000f;

Lc0d48:	; 800C0D48
V0 = V0 >> 04;
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C0D58	nop
V0 = T5 & S3;
V1 = T6 | V0;
[A2 + 0000] = w(V1);
A0 = A2 & S3;
V1 = T5 & S6;
V1 = V1 | A0;
[T4 + 0000] = w(V1);

Lc0d78:	; 800C0D78
V0 = A3 < S1;
800C0D7C	bne    v0, zero, loopc0c90 [$800c0c90]
A2 = A2 + 0034;
V0 = FP & ff00;

Lc0d88:	; 800C0D88
S1 = V0 >> 08;
800C0D8C	beq    s1, zero, Lc0e7c [$800c0e7c]
A3 = 0;
T8 = A2 + 0020;
T6 = w[T0 + 0000];

loopc0d9c:	; 800C0D9C
800C0D9C	nop
V0 = T6 & 00ff;
V0 = V0 << 03;
T3 = S0 + V0;
V0 = T6 & ff00;
V0 = V0 >> 05;
T2 = S0 + V0;
V1 = T6 >> 0d;
V1 = V1 & 07f8;
A1 = S0 + V1;
V0 = w[T3 + 0000];
V1 = w[T2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 0014;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + ffe8] = w(V0);
[T8 + fff4] = w(V1);
[T8 + 0000] = w(A0);
T8 = T8 + 0028;
V0 = MAC0;
800C0E00	nop
800C0E04	bgtz   v0, Lc0e1c [$800c0e1c]
800C0E08	nop
V0 = S4 & S6;
[A2 + 0000] = w(V0);
800C0E14	j      Lc0e70 [$800c0e70]
T6 = w[T0 + 0000];

Lc0e1c:	; 800C0E1C
SZ1 = w[T3 + 0004];
SZ2 = w[T2 + 0004];
SZ3 = w[A1 + 0004];
800C0E28	nop
800C0E2C	nop
gte_AVSZ3(); // Average of three Z values
T6 = w[T0 + 0000];
V1 = S4 & S6;
S5 = A2 & S3;
V0 = OTZ;
800C0E44	nop
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C0E54	nop
V0 = T5 & S3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = T5 & S6;
V0 = V0 | S5;
[T4 + 0000] = w(V0);

Lc0e70:	; 800C0E70
V0 = A3 < S1;
800C0E74	bne    v0, zero, loopc0d9c [$800c0d9c]
A2 = A2 + 0028;

Lc0e7c:	; 800C0E7C
V0 = FP >> 10;
S1 = V0 & 00ff;
800C0E84	beq    s1, zero, Lc0f84 [$800c0f84]
A3 = 0;
T8 = A2 + 0020;

loopc0e90:	; 800C0E90
V1 = w[T0 + 0000];
800C0E94	nop
V0 = V1 & 00ff;
V0 = V0 << 03;
T9 = S0 + V0;
V0 = V1 & ff00;
V0 = V0 >> 05;
T3 = S0 + V0;
V0 = V1 >> 0d;
V0 = V0 & 07f8;
T2 = S0 + V0;
V1 = V1 >> 18;
V1 = V1 << 03;
T1 = S0 + V1;
V0 = w[T9 + 0000];
V1 = w[T3 + 0000];
A0 = w[T2 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 000c;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + ffe8] = w(V0);
[T8 + fff0] = w(V1);
[T8 + fff8] = w(A0);
T6 = S4 & S6;
T8 = T8 + 0028;
V0 = MAC0;
800C0F08	nop
800C0F0C	bgtz   v0, Lc0f1c [$800c0f1c]
A1 = w[T1 + 0000];
800C0F14	j      Lc0f78 [$800c0f78]
[A2 + 0000] = w(T6);

Lc0f1c:	; 800C0F1C
V1 = w[T9 + 0004];
[T8 + ffd8] = w(A1);
S5 = w[T3 + 0004];
V0 = w[T2 + 0004];
A0 = w[T1 + 0004];
V1 = V1 + S5;
V1 = V1 + V0;
V0 = V1 + A0;
800C0F3C	bgez   v0, Lc0f48 [$800c0f48]
800C0F40	nop
V0 = V0 + 000f;

Lc0f48:	; 800C0F48
V0 = V0 >> 04;
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C0F58	nop
V0 = T5 & S3;
V1 = T6 | V0;
[A2 + 0000] = w(V1);
A0 = A2 & S3;
V1 = T5 & S6;
V1 = V1 | A0;
[T4 + 0000] = w(V1);

Lc0f78:	; 800C0F78
V0 = A3 < S1;
800C0F7C	bne    v0, zero, loopc0e90 [$800c0e90]
A2 = A2 + 0028;

Lc0f84:	; 800C0F84
S1 = FP >> 18;
800C0F88	beq    s1, zero, Lc1070 [$800c1070]
A3 = 0;
T8 = A2 + 0018;
T6 = w[T0 + 0000];

loopc0f98:	; 800C0F98
800C0F98	nop
V0 = T6 & 00ff;
V0 = V0 << 03;
T3 = S0 + V0;
V0 = T6 & ff00;
V0 = V0 >> 05;
T2 = S0 + V0;
V1 = T6 >> 0d;
V1 = V1 & 07f8;
A1 = S0 + V1;
V0 = w[T3 + 0000];
V1 = w[T2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 000c;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + fff0] = w(V0);
[T8 + fff8] = w(V1);
[T8 + 0000] = w(A0);
T8 = T8 + 0020;
V0 = MAC0;
800C0FFC	nop
800C1000	bgtz   v0, Lc1018 [$800c1018]
800C1004	nop
V0 = S4 & S6;
[A2 + 0000] = w(V0);
800C1010	j      Lc1064 [$800c1064]
T6 = w[T0 + 0000];

Lc1018:	; 800C1018
SZ1 = w[T3 + 0004];
SZ2 = w[T2 + 0004];
SZ3 = w[A1 + 0004];
V1 = S4 & S6;
S5 = A2 & S3;
gte_AVSZ3(); // Average of three Z values
T6 = w[T0 + 0000];
V0 = OTZ;
800C1038	nop
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C1048	nop
V0 = T5 & S3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = T5 & S6;
V0 = V0 | S5;
[T4 + 0000] = w(V0);

Lc1064:	; 800C1064
V0 = A3 < S1;
800C1068	bne    v0, zero, loopc0f98 [$800c0f98]
A2 = A2 + 0020;

Lc1070:	; 800C1070
FP = w[S7 + 0008];
800C1074	nop
S1 = FP & 00ff;
800C107C	beq    s1, zero, Lc1164 [$800c1164]
A3 = 0;
T8 = A2 + 0010;
T6 = w[T0 + 0000];

loopc108c:	; 800C108C
800C108C	nop
V0 = T6 & 00ff;
V0 = V0 << 03;
T3 = S0 + V0;
V0 = T6 & ff00;
V0 = V0 >> 05;
T2 = S0 + V0;
V1 = T6 >> 0d;
V1 = V1 & 07f8;
A1 = S0 + V1;
V0 = w[T3 + 0000];
V1 = w[T2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 0008;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + fff8] = w(V0);
[T8 + fffc] = w(V1);
[T8 + 0000] = w(A0);
T8 = T8 + 0014;
V0 = MAC0;
800C10F0	nop
800C10F4	bgtz   v0, Lc110c [$800c110c]
800C10F8	nop
V0 = S4 & S6;
[A2 + 0000] = w(V0);
800C1104	j      Lc1158 [$800c1158]
T6 = w[T0 + 0000];

Lc110c:	; 800C110C
SZ1 = w[T3 + 0004];
SZ2 = w[T2 + 0004];
SZ3 = w[A1 + 0004];
V1 = S4 & S6;
S5 = A2 & S3;
gte_AVSZ3(); // Average of three Z values
T6 = w[T0 + 0000];
V0 = OTZ;
800C112C	nop
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C113C	nop
V0 = T5 & S3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = T5 & S6;
V0 = V0 | S5;
[T4 + 0000] = w(V0);

Lc1158:	; 800C1158
V0 = A3 < S1;
800C115C	bne    v0, zero, loopc108c [$800c108c]
A2 = A2 + 0014;

Lc1164:	; 800C1164
V0 = FP & ff00;
S1 = V0 >> 08;
800C116C	beq    s1, zero, Lc126c [$800c126c]
A3 = 0;
T8 = A2 + 0014;

loopc1178:	; 800C1178
V1 = w[T0 + 0000];
800C117C	nop
V0 = V1 & 00ff;
V0 = V0 << 03;
T9 = S0 + V0;
V0 = V1 & ff00;
V0 = V0 >> 05;
T3 = S0 + V0;
V0 = V1 >> 0d;
V0 = V0 & 07f8;
T2 = S0 + V0;
V1 = V1 >> 18;
V1 = V1 << 03;
T1 = S0 + V1;
V0 = w[T9 + 0000];
V1 = w[T3 + 0000];
A0 = w[T2 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
T0 = T0 + 0008;
A3 = A3 + 0001;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + fff4] = w(V0);
[T8 + fff8] = w(V1);
[T8 + fffc] = w(A0);
T6 = S4 & S6;
T8 = T8 + 0018;
V0 = MAC0;
800C11F0	nop
800C11F4	bgtz   v0, Lc1204 [$800c1204]
A1 = w[T1 + 0000];
800C11FC	j      Lc1260 [$800c1260]
[A2 + 0000] = w(T6);

Lc1204:	; 800C1204
V1 = w[T9 + 0004];
[T8 + ffe8] = w(A1);
S5 = w[T3 + 0004];
V0 = w[T2 + 0004];
A0 = w[T1 + 0004];
V1 = V1 + S5;
V1 = V1 + V0;
V0 = V1 + A0;
800C1224	bgez   v0, Lc1230 [$800c1230]
800C1228	nop
V0 = V0 + 000f;

Lc1230:	; 800C1230
V0 = V0 >> 04;
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C1240	nop
V0 = T5 & S3;
V1 = T6 | V0;
[A2 + 0000] = w(V1);
A0 = A2 & S3;
V1 = T5 & S6;
V1 = V1 | A0;
[T4 + 0000] = w(V1);

Lc1260:	; 800C1260
V0 = A3 < S1;
800C1264	bne    v0, zero, loopc1178 [$800c1178]
A2 = A2 + 0018;

Lc126c:	; 800C126C
V0 = FP >> 10;
S1 = V0 & 00ff;
800C1274	beq    s1, zero, Lc135c [$800c135c]
A3 = 0;
T8 = A2 + 0018;
T6 = w[T0 + 0000];

loopc1284:	; 800C1284
800C1284	nop
V0 = T6 & 00ff;
V0 = V0 << 03;
T3 = S0 + V0;
V0 = T6 & ff00;
V0 = V0 >> 05;
T2 = S0 + V0;
V1 = T6 >> 0d;
V1 = V1 & 07f8;
A1 = S0 + V1;
V0 = w[T3 + 0000];
V1 = w[T2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 0010;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + fff0] = w(V0);
[T8 + fff8] = w(V1);
[T8 + 0000] = w(A0);
T8 = T8 + 001c;
V0 = MAC0;
800C12E8	nop
800C12EC	bgtz   v0, Lc1304 [$800c1304]
800C12F0	nop
V0 = S4 & S6;
[A2 + 0000] = w(V0);
800C12FC	j      Lc1350 [$800c1350]
T6 = w[T0 + 0000];

Lc1304:	; 800C1304
SZ1 = w[T3 + 0004];
SZ2 = w[T2 + 0004];
SZ3 = w[A1 + 0004];
V1 = S4 & S6;
S5 = A2 & S3;
gte_AVSZ3(); // Average of three Z values
T6 = w[T0 + 0000];
V0 = OTZ;
800C1324	nop
V0 = V0 << 02;
T4 = V0 + S2;
A0 = w[T4 + 0000];
800C1334	nop
V0 = A0 & S3;
V1 = V1 | V0;
[A2 + 0000] = w(V1);
V0 = A0 & S6;
V0 = V0 | S5;
[T4 + 0000] = w(V0);

Lc1350:	; 800C1350
V0 = A3 < S1;
800C1354	bne    v0, zero, loopc1284 [$800c1284]
A2 = A2 + 001c;

Lc135c:	; 800C135C
S1 = FP >> 18;
800C1360	beq    s1, zero, Lc1460 [$800c1460]
A3 = 0;
T8 = A2 + 0020;

loopc136c:	; 800C136C
V1 = w[T0 + 0000];
800C1370	nop
V0 = V1 & 00ff;
V0 = V0 << 03;
T9 = S0 + V0;
V0 = V1 & ff00;
V0 = V0 >> 05;
T3 = S0 + V0;
V0 = V1 >> 0d;
V0 = V0 & 07f8;
T2 = S0 + V0;
V1 = V1 >> 18;
V1 = V1 << 03;
T1 = S0 + V1;
V0 = w[T9 + 0000];
V1 = w[T3 + 0000];
A0 = w[T2 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
A3 = A3 + 0001;
T0 = T0 + 0014;
gte_NCLIP(); // Normal clipping
S4 = w[A2 + 0000];
[T8 + ffe8] = w(V0);
[T8 + fff0] = w(V1);
[T8 + fff8] = w(A0);
T6 = S4 & S6;
T8 = T8 + 0024;
V0 = MAC0;
800C13E4	nop
800C13E8	bgtz   v0, Lc13f8 [$800c13f8]
A1 = w[T1 + 0000];
800C13F0	j      Lc1454 [$800c1454]
[A2 + 0000] = w(T6);

Lc13f8:	; 800C13F8
V1 = w[T9 + 0004];
[T8 + ffdc] = w(A1);
S5 = w[T3 + 0004];
V0 = w[T2 + 0004];
A0 = w[T1 + 0004];
V1 = V1 + S5;
V1 = V1 + V0;
V0 = V1 + A0;
800C1418	bgez   v0, Lc1424 [$800c1424]
800C141C	nop
V0 = V0 + 000f;

Lc1424:	; 800C1424
V0 = V0 >> 04;
V0 = V0 << 02;
T4 = V0 + S2;
T5 = w[T4 + 0000];
800C1434	nop
V0 = T5 & S3;
V1 = T6 | V0;
[A2 + 0000] = w(V1);
A0 = A2 & S3;
V1 = T5 & S6;
V1 = V1 | A0;
[T4 + 0000] = w(V1);

Lc1454:	; 800C1454
V0 = A3 < S1;
800C1458	bne    v0, zero, loopc136c [$800c136c]
A2 = A2 + 0024;

Lc1460:	; 800C1460
////////////////////////////////



////////////////////////////////
// wm_calculate_bone_matrixes()

model = A0;
root_matrix = A1;
animation_id = A2;
frame_id = A3;

// if not scaled yet
if( bu[model + 0] == 0 )
{
    return;
}

R11R12 = w[root_matrix + 0];
R13R21 = w[root_matrix + 4];
R22R23 =  w[root_matrix + 8];
R31R32 = w[root_matrix + c];
R33 = w[root_matrix + 10];
TRX = w[root_matrix + 14];
TRY = w[root_matrix + 18];
TRZ = w[root_matrix + 1c];

if( w[1f800000] & 2 )
{
    VXY0 = (hu[model + c] << 10) | hu[model + 8];
    VZ0 = w[model + 10];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [1f800034] = w(IR1);
    [1f800038] = w(IR2);
    [1f80003c] = w(IR3);

    rot_x = b[model + 5];
    sin_x = h[800c7538 + rot_x * 4 + 0];
    cos_x = h[800c7538 + rot_x * 4 + 2];
    rot_y = b[model + 6];
    sin_y = h[800c7538 + rot_y * 4 + 0];
    cos_y = h[800c7538 + rot_y * 4 + 2];
    rot_z = b[model + 7];
    sin_z = h[800c7538 + rot_z * 4 + 0];
    cos_z = h[800c7538 + rot_z * 4 + 2];

    IR0 = -cos_x;
    IR1 = sin_y;
    IR2 = cos_y;
    gte_gpf12(); // General purpose interpolation

    IR1 = MAC1 & ffff; // -cos_x * sin_y + MAC1
    IR2 = sin_x;
    IR3 = MAC2 & ffff; // -cos_x * cos_y + MAC2
    gte_rtir12(); // ir * rotmatrix
    [1f800022] = h(IR1);
    [1f800028] = h(IR2);
    [1f80002e] = h(IR3);

    IR0 = sin_x;
    IR1 = sin_y;
    IR2 = cos_y;
    gte_gpf12(); // General purpose interpolation
    T1 = MAC1 & ffff; // sin_x * sin_y + MAC1
    T2 = MAC2 & ffff; // sin_x * cos_y + MAC2

    IR0 = sin_z;
    IR1 = T1;
    IR2 = cos_x;
    IR3 = T2;
    gte_GPF(); // General Purpose Interpolation
    // MAC1 = sin_z * T1
    // MAC2 = sin_z * cos_x
    // MAC3 = sin_z * T2

    IR0 = cos_z;
    IR1 = cos_y;
    IR2 = 0;
    IR3 = -sin_y;
    gte_gpl12(); // General purpose interpolation

    IR1 = (MAC1 >> c) & ffff; // sin_z * T1 + cos_z * cos_y
    IR2 = (MAC2 >> c) & ffff; // sin_z * cos_x
    IR3 = (MAC3 >> c) & ffff; // sin_z * T2 + cos_z * -sin_y
    gte_rtir12(); // ir * rotmatrix
    [1f800020] = h(IR1);
    [1f800026] = h(IR2);
    [1f80002c] = h(IR3);

    IR0 = cos_z;
    IR1 = T1;
    IR2 = cos_x;
    IR3 = T2;
    gte_GPF(); // General Purpose Interpolation

    IR0 = -sin_z;
    IR1 = cos_y;
    IR2 = 0;
    IR3 = -sin_y;
    gte_gpl12(); // General purpose interpolation

    IR1 = (MAC1 >> c) & ffff; // cos_z * T1 - sin_z * cos_y
    IR2 = (MAC2 >> c) & ffff; // cos_z * cos_x
    IR3 = (MAC3 >> c) & ffff; // cos_z * T2 + sin_z * sin_y
    gte_rtir12(); // ir * rotmatrix
    [1f800024] = h(IR1);
    [1f80002a] = h(IR2);
    [1f800030] = h(IR3);
}
else
{
    [1f800020] = w(w[root_matrix + 0]);
    [1f800024] = w(w[root_matrix + 4]);
    [1f800028] = w(w[root_matrix + 8]);
    [1f80002c] = w(w[root_matrix + c]);
    [1f800030] = w(w[root_matrix + 10]);
    [1f800034] = w(w[root_matrix + 14]);
    [1f800038] = w(w[root_matrix + 18]);
    [1f80003c] = w(w[root_matrix + 1c]);
}

animations = w[model + 1c] + hu[model + 1a];

anim_data = w[animations + animation_id * 10 + c];
frame_trans = anim_data + hu[animations + animation_id * 10 + 6] + frame_id * 2;
static_trans = anim_data + hu[animations + animation_id * 10 + 8];
frame_rot = anim_data + hu[animations + animation_id * 10 + a] + frame_id;

number_of_bones = bu[model + 2];
number_of_frames = hu[animations + animation_id * 10 + 0];

for( int i = 0; i < number_of_bones; ++i )
{
    bones = w[model + 1c];
    length = h[bones + i * 4 + 0];
    parent_id = b[bones + i * 4 + 2]; // may use -1
    has_part = b[bones + i * 4 + 3];

    if( has_part != 0 )
    {
        // if this bone has part then we need to store matrix for it's render
        T3 = w[model + 20] + i * 20; 
    }
    else
    {
        T3 = 0;
    }

    [1f800040 + i * 20 + 14] = w(0);
    [1f800040 + i * 20 + 18] = w(0);
    [1f800040 + i * 20 + 1c] = w(length);

    // may use -1 to address root from 1f800020
    R11R12 = w[1f800040 + parent_id * 20 + 0];
    R13R21 = w[1f800040 + parent_id * 20 + 4];
    R22R23 = w[1f800040 + parent_id * 20 + 8];
    R31R32 = w[1f800040 + parent_id * 20 + c];
    R33 = w[1f800040 + parent_id * 20 + 10];
    TRX = w[1f800040 + parent_id * 20 + 14];
    TRY = w[1f800040 + parent_id * 20 + 18];
    TRZ = w[1f800040 + parent_id * 20 + 1c];

    rot_x = b[anim_data + 4 + i * 8 + 1];
    rot_y = b[anim_data + 4 + i * 8 + 2];
    rot_z = b[anim_data + 4 + i * 8 + 3];

    IR0 = number_of_frames;
    IR1 = rot_x;
    IR2 = rot_y;
    IR3 = rot_z;
    gte_GPF(); // General Purpose Interpolation

    if( A0 & 1 )
    {
        rot_x = bu[frame_rot + number_of_frames * rot_x];
    }
    if( A0 & 2 )
    {
        rot_y = bu[frame_rot + number_of_frames * rot_y];
    }
    if( A0 & 4 )
    {
        rot_z = bu[frame_rot + number_of_frames * rot_z];
    }

    sin_x = h[800c7538 + rot_x * 4 + 0];
    cos_x = h[800c7538 + rot_x * 4 + 2];
    sin_y = h[800c7538 + rot_y * 4 + 0];
    cos_y = h[800c7538 + rot_y * 4 + 2];
    sin_z = h[800c7538 + rot_z * 4 + 0];
    cos_z = h[800c7538 + rot_z * 4 + 2];

    IR0 = cos_x;
    IR1 = sin_y;
    IR2 = cos_y;
    gte_gpf12(); // General purpose interpolation

    IR1 = MAC1 & ffff;
    IR2 = -sin_x;
    IR3 = MAC2 & ffff;
    gte_rtir12(); // ir * rotmatrix
    [1f800040 + i * 20 + 4] = h(IR1);
    [1f800040 + i * 20 + a] = h(IR2);
    [1f800040 + i * 20 + 10] = h(IR3);
    if( T3 != 0 )
    {
        [T3 + 4] = h(IR1);
        [T3 + a] = h(IR2);
        [T3 + 10] = h(IR3);
    }

    IR0 = sin_x;
    IR1 = sin_y;
    IR2 = cos_y;
    gte_gpf12(); // General purpose interpolation

    T1 = MAC1 & ffff;
    T2 = MAC2 & ffff;

    IR0 = sin_z;
    IR1 = T1;
    IR2 = cos_x;
    IR3 = T2;
    gte_GPF(); // General Purpose Interpolation

    IR0 = cos_z;
    IR1 = cos_y;
    IR2 = 0;
    IR3 = -sin_y;
    gte_gpl12(); // General purpose interpolation

    IR1 = (MAC1 >> c) & ffff;
    IR2 = (MAC2 >> c) & ffff;
    IR3 = (MAC3 >> c) & ffff;
    gte_rtir12(); // ir * rotmatrix
    [1f800040 + i * 20 + 0] = h(IR1);
    [1f800040 + i * 20 + 6] = h(IR2);
    [1f800040 + i * 20 + c] = h(IR3);
    if( T3 != 0 )
    {
        [T3 + 0] = h(IR1);
        [T3 + 6] = h(IR2);
        [T3 + c] = h(IR3);
    }

    IR0 = cos_z;
    IR1 = T1;
    IR2 = cos_x;
    IR3 = T2;
    gte_GPF(); // General Purpose Interpolation

    IR0 = sin_z;
    IR1 = -cos_y;
    IR2 = 0;
    IR3 = sin_y;
    gte_gpl12(); // General purpose interpolation

    IR1 = (MAC1 >> c) & ffff;
    IR2 = (MAC2 >> c) & ffff;
    IR3 = (MAC3 >> c) & ffff;
    gte_rtir12(); // ir * rotmatrix
    [1f800040 + i * 20 + 2] = h(IR1);
    [1f800040 + i * 20 + 8] = h(IR2);
    [1f800040 + i * 20 + e] = h(IR3);
    if( T3 != 0 )
    {
        [T3 + 2] = h(IR1);
        [T3 + 8] = h(IR2);
        [T3 + e] = h(IR3);
    }

    if( w[1f800000] & 1 )
    {
        tx = bu[anim_data + 4 + i * 8 + 4];
        ty = bu[anim_data + 4 + i * 8 + 5];
        tz = bu[anim_data + 4 + i * 8 + 6];

        if( A0 & 10 )
        {
            [1f800040 + i * 20 + 14] = w(h[frame_trans + tx * number_of_frames * 2]);
        }
        else if( tx != ff )
        {
            [1f800040 + i * 20 + 14] = w(h[static_trans + tx * 2]);
        }

        if( A0 & 20 )
        {
            [1f800040 + i * 20 + 18] = w(h[frame_trans + ty * number_of_frames * 2]);
        }
        else if( ty != ff )
        {
            [1f800040 + i * 20 + 18] = w(h[static_trans + ty * 2]);
        }

        if( A0 & 40 )
        {
            [1f800040 + i * 20 + 1c] = w(w[1f800040 + i * 20 + 1c] + h[frame_trans + tz * number_of_frames * 2]);
        }
        else if( tz != ff )
        {
            [1f800040 + i * 20 + 1c] = w(w[1f800040 + i * 20 + 1c] + h[static_trans + tz * 2]);
        }
    }

    VXY0 = (hu[1f800040 + i * 20 + 18] << 10) | hu[1f800040 + i * 20 + 14];
    VZ0 = w[1f800040 + i * 20 + 1c];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [1f800040 + i * 20 + 14] = w(IR1);
    [1f800040 + i * 20 + 18] = w(IR2);
    [1f800040 + i * 20 + 1c] = w(IR3);
    if( T3 != 0 )
    {
        [T3 + 14] = w(IR1);
        [T3 + 18] = w(IR2);
        [T3 + 1c] = w(IR3);
    }
}
////////////////////////////////



////////////////////////////////
// wm_scale_model_all()

model = A0;
scale = A1;
force = A2;

number_of_bones = bu[model + 2];
number_of_parts = bu[model + 3];
number_of_animations = bu[model + 4];
part = hu[model + 18];
animation = hu[model + 1a];
bones = w[model + 1c];

for( int i = 0; i < number_of_parts; ++i )
{
    A0 = bones + part + i * 20;
    A1 = scale;
    A2 = force;
    wm_scale_model_vertexes();
}

// rotation matrix
[1f800000] = h(scale);
[1f800002] = h(0);
[1f800004] = h(0);
[1f800006] = h(0);
[1f800008] = h(scale);
[1f80000a] = h(0);
[1f80000c] = h(0);
[1f80000e] = h(0);
[1f800010] = h(scale);
// translation vector
[1f800014] = w(0);
[1f800018] = w(0);
[1f80001c] = w(0);

R11R12 = w[1f800000];
R13R21 = w[1f800004];
R22R23 = w[1f800008];
R31R32 = w[1f80000c];
R33 = w[1f800010];
TRX = w[1f800014];
TRY = w[1f800018];
TRZ = w[1f80001c];

for( int i = 0; i < number_of_bones; ++i )
{
    [1f800020] = h(hu[bones + i * 4 + 0]);
    VXY0 = w[1f800020];
    VZ0 = w[1f800024];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [1f800028] = w(MAC1);
    [1f80002c] = w(MAC2);
    [1f800030] = w(MAC3);
    [bones + i * 4 + 0] = h(hu[1f800028]);
}

for( int i = 0; i < number_of_animations; ++i )
{
    A0 = bones + animation + i * 10;
    A1 = scale;
    A2 = force;
    wm_scale_model_animations();
}
////////////////////////////////



////////////////////////////////
// wm_scale_model_vertexes()

part = A0;
scale = A1;
force = A2;

vertex = w[part + 18];

if( w[vertex + 0] & 00000001 )
{
    if( force == 0 )
    {
        return;
    }
}

// rotation matrix
[1f800000] = h(scale);
[1f800002] = h(0);
[1f800004] = h(0);
[1f800006] = h(0);
[1f800008] = h(scale);
[1f80000a] = h(0);
[1f80000c] = h(0);
[1f80000e] = h(0);
[1f800010] = h(scale);
// translation vector
[1f800014] = w(0);
[1f800018] = w(0);
[1f80001c] = w(0);

R11R12 = w[1f800000];
R13R21 = w[1f800004];
R22R23 = w[1f800008];
R31R32 = w[1f80000c];
R33 = w[1f800010];
TRX = w[1f800014];
TRY = w[1f800018];
TRZ = w[1f80001c];

number_of_vertexes = bu[part + 2];

for( int i = 0; i < number_of_vertexes; ++i )
{
    VXY0 = w[vertex + 4 + i * 8 + 0];
    VZ0 = w[vertex + 4 + i * 8 + 4];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [1f800020] = w(MAC1);
    [1f800024] = w(MAC2);
    [1f800028] = w(MAC3);
    [vertex + 4 + i * 8 + 0] = h(hu[1f800020]);
    [vertex + 4 + i * 8 + 2] = h(hu[1f800024]);
    [vertex + 4 + i * 8 + 4] = h(hu[1f800028]);
}

[vertex + 0] = w(w[vertex + 0] | 00000001);
////////////////////////////////



////////////////////////////////
// wm_scale_model_animations()

animation = A0;
scale = A1;
force = A2;

number_of_frames = hu[animation + 0];
number_of_frames_translation = bu[animation + 3];
number_of_static_translation = bu[animation + 4];
frames_translation_data = hu[animation + 6]
static_translation_data = hu[animation + 8];
animation_data = w[animation + c];

if( w[animation_data + 0] != 0  )
{
    if( force == 0 )
    {
        return;
    }
}

// rotation matrix
[1f800000] = h(scale);
[1f800002] = h(0);
[1f800004] = h(0);
[1f800006] = h(0);
[1f800008] = h(scale);
[1f80000a] = h(0);
[1f80000c] = h(0);
[1f80000e] = h(0);
[1f800010] = h(scale);
// translation vector
[1f800014] = w(0);
[1f800018] = w(0);
[1f80001c] = w(0);

R11R12 = w[1f800000];
R13R21 = w[1f800004];
R22R23 = w[1f800008];
R31R32 = w[1f80000c];
R33 = w[1f800010];
TRX = w[1f800014];
TRY = w[1f800018];
TRZ = w[1f80001c];

for( int i = 0; i < number_of_frames_translation; ++i )
{
    for( int j = 0; j < number_of_frames; ++j )
    {
        [1f800000] = h(hu[animation_data + frames_translation_data + number_of_frames * i * 2 + j * 2]);
        VXY0 = w[1f800000];
        VZ0 = w[1f800004];
        gte_rtv0tr(); // v0 * rotmatrix + tr vector
        [1f800008] = w(MAC1);
        [1f80000c] = w(MAC2);
        [1f800010] = w(MAC3);
        [animation_data + frames_translation_data + number_of_frames * i * 2 + j * 2] = h(hu[1f800008]);
    }
}

for( int i = 0; i < number_of_static_translation; ++i )
{
    [1f800000] = h(hu[animation_data + static_translation_data + i * 2]);
    VXY0 = w[1f800000];
    VZ0 = w[1f800004];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [1f800008] = w(MAC1);
    [1f80000c] = w(MAC2);
    [1f800010] = w(MAC3);
    [animation_data + static_translation_data + i * 2] = h(hu[1f800008]);
}

[animation_data + 0] = w(1);
////////////////////////////////



////////////////////////////////
// wm_apply_model_lighting_to_packet()

model = A0;

number_of_parts = bu[model + 3];
part = w[model + 1c] + hu[model + 18];

S5 = h[A1 + 0];
T1 = h[A1 + 2];
S2 = h[A1 + 4];

[1f800200] = w(bu[A1 + 6]); // apply to all ot only to linked packets

for( int i = 0; i < number_of_parts; ++i )
{
    A0 = part + i * 20;
    A1 = S5;
    A2 = T1;
    A3 = S2;
    wm_apply_poly_lighting_to_packet();
}

return 1;
////////////////////////////////



////////////////////////////////
// wm_apply_poly_lighting_to_packet()

part = A0;

packet = w[part + 1c];
vertexes = w[part + 18];
poly = vertexes + hu[part + e];

if( bu[800c752c] != 0 )
{
    packet = packet + hu[part + 16];
}

IR0 = 10;
T3 = (A1 << 10) >> c;
T2 = (A2 << 10) >> c;
V1 = (A3 << 10) >> c;

if( w[1f800200] & 1 ) // apply to all
{
    for( int i = 0; i < bu[part + 4]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 8];
        IR2 = bu[poly + 9];
        IR3 = bu[poly + a];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + c];
        IR2 = bu[poly + d];
        IR3 = bu[poly + e];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB0);
        [packet + 10] = w(RGB1);
        [packet + 1c] = w(RGB2);

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 10];
        IR2 = bu[poly + 11];
        IR3 = bu[poly + 12];
        gte_gpl12(); // General purpose interpolation
        [packet + 28] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 34;
        poly = poly + 18;
    }

    for( int i = 0; i < bu[part + 5]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 8];
        IR2 = bu[poly + 9];
        IR3 = bu[poly + a];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + c];
        IR2 = bu[poly + d];
        IR3 = bu[poly + e];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB0);
        [packet + 10] = w(RGB1);
        [packet + 1c] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 28;
        poly = poly + 14;
    }

    for( int i = 0; i < bu[part + 6]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 28;
        poly = poly + c;
    }

    for( int i = 0; i < bu[part + 7]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 20;
        poly = poly + c;
    }

    for( int i = 0; i < bu[part + 8]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 14;
        poly = poly + 8;
    }

    for( int i = 0; i < bu[part + 9]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 18;
        poly = poly + 8;
    }

    for( int i = 0; i < bu[part + a]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 8];
        IR2 = bu[poly + 9];
        IR3 = bu[poly + a];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + c];
        IR2 = bu[poly + d];
        IR3 = bu[poly + e];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB0);
        [packet + c] = w(RGB1);
        [packet + 14] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 1c;
        poly = poly + 10;
    }

    for( int i = 0; i < bu[part + b]; ++i )
    {
        A2 = bu[packet + 7];

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 4];
        IR2 = bu[poly + 5];
        IR3 = bu[poly + 6];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 8];
        IR2 = bu[poly + 9];
        IR3 = bu[poly + a];
        gte_gpl12(); // General purpose interpolation

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + c];
        IR2 = bu[poly + d];
        IR3 = bu[poly + e];
        gte_gpl12(); // General purpose interpolation
        [packet + 4] = w(RGB0);
        [packet + c] = w(RGB1);
        [packet + 14] = w(RGB2);

        MAC1 = T3;
        MAC2 = T2;
        MAC3 = V1;
        IR1 = bu[poly + 10];
        IR2 = bu[poly + 11];
        IR3 = bu[poly + 12];
        gte_gpl12(); // General purpose interpolation
        [packet + 1c] = w(RGB2);

        [packet + 7] = b(A2);

        packet = packet + 24;
        poly = poly + 14;
    }
}
else
{
    for( int i = 0; i < bu[part + 4]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 8];
            IR2 = bu[poly + 9];
            IR3 = bu[poly + a];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + c];
            IR2 = bu[poly + d];
            IR3 = bu[poly + e];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB0);
            [packet + 10] = w(RGB1);
            [packet + 1c] = w(RGB2);

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 10];
            IR2 = bu[poly + 11];
            IR3 = bu[poly + 12];
            gte_gpl12(); // General purpose interpolation
            [packet + 28] = w(RGB2);
            [packet + 7] = b(A2);
        }

        packet = packet + 34;
        poly = poly + 18;
    }

    for( int i = 0; i < bu[part + 5]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 8];
            IR2 = bu[poly + 9];
            IR3 = bu[poly + a];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + c];
            IR2 = bu[poly + d];
            IR3 = bu[poly + e];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB0);
            [packet + 10] = w(RGB1);
            [packet + 1c] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 28;
        poly = poly + 14;
    }

    for( int i = 0; i < bu[part + 6]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 28;
        poly = poly + c;
    }

    for( int i = 0; i < bu[part + 7]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 20;
        poly = poly + c;
    }

    for( int i = 0; i < bu[part + 8]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 14;
        poly = poly + 8;
    }

    for( int i = 0; i < bu[part + 9]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 18;
        poly = poly + 8;
    }

    for( int i = 0; i < bu[part + a]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            V0 = ;
            IR1 = bu[poly + 8];
            IR2 = bu[poly + 9];
            IR3 = bu[poly + a];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + c];
            IR2 = bu[poly + d];
            IR3 = bu[poly + e];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB0);
            [packet + c] = w(RGB1);
            [packet + 14] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 1c;
        poly = poly + 10;
    }

    for( int i = 0; i < bu[part + b]; ++i )
    {
        if( ( w[packet + 0] << 8 ) != 0 )
        {
            A2 = bu[packet + 7];

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 4];
            IR2 = bu[poly + 5];
            IR3 = bu[poly + 6];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 8];
            IR2 = bu[poly + 9];
            IR3 = bu[poly + a];
            gte_gpl12(); // General purpose interpolation

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + c];
            IR2 = bu[poly + d];
            IR3 = bu[poly + e];
            gte_gpl12(); // General purpose interpolation
            [packet + 4] = w(RGB0);
            [packet + c] = w(RGB1);
            [packet + 14] = w(RGB2);

            MAC1 = T3;
            MAC2 = T2;
            MAC3 = V1;
            IR1 = bu[poly + 10];
            IR2 = bu[poly + 11];
            IR3 = bu[poly + 12];
            gte_gpl12(); // General purpose interpolation
            [packet + 1c] = w(RGB2);

            [packet + 7] = b(A2);
        }

        packet = packet + 24;
        poly = poly + 14;
    }
}
////////////////////////////////



////////////////////////////////
// wm_calculate_model_lighting()

model = A0;

bone_matrixes = w[model + 20];
part = w[model + 1c] + hu[model + 18];

// background colour
RBK = bu[A1 + 0] << 4;
BBK = bu[A1 + 1] << 4;
GBK = bu[A1 + 2] << 4;

// lighting matrix
[1f800200] = h(bu[A1 + 3] << 4);
[1f800206] = h(bu[A1 + 4] << 4);
[1f80020c] = h(bu[A1 + 5] << 4);
[1f800202] = h(bu[A1 + 6] << 4);
[1f800208] = h(bu[A1 + 7] << 4);
[1f80020e] = h(bu[A1 + 8] << 4);
[1f800204] = h(bu[A1 + 9] << 4);
[1f80020a] = h(bu[A1 + a] << 4);
[1f800210] = h(bu[A1 + b] << 4);
[1f800214] = w(0);
[1f800218] = w(0);
[1f80021c] = w(0);
LR1LR2 = w[1f800200];
LR3LG1 = w[1f800204];
LG2LG3 = w[1f800208];
LB1LB2 = w[1f80020c];
LB3 = w[1f800210];

// rotation matrix
[SP + 10] = h(hu[A1 + c]);
[SP + 12] = h(hu[A1 + e]);
[SP + 14] = h(hu[A1 + 10]);
[SP + 16] = h(hu[A1 + 12]);
[SP + 18] = h(hu[A1 + 14]);
[SP + 1a] = h(hu[A1 + 16]);
[SP + 1c] = h(hu[A1 + 18]);
[SP + 1e] = h(hu[A1 + 1a]);
[SP + 20] = h(hu[A1 + 1c]);
[SP + 24] = w(0);
[SP + 28] = w(0);
[SP + 2c] = w(0);

force = bu[A1 + 1e];

number_of_parts = bu[model + 3];

for( int i = 0; i < number_of_parts; ++i )
{
    if( bu[part + i * 20 + 0] != 0 ) // 0 - not calculate stage lighting and color. 1 - calculate
    {
        if( b[model + 1] != -1 ) // use root matrix
        {
            R11R12 = w[bone_matrixes + 0];
            R13R21 = w[bone_matrixes + 4];
            R22R23 = w[bone_matrixes + 8];
            R31R32 = w[bone_matrixes + c];
            R33 = w[bone_matrixes + 10];

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 0];
            IR2 = hu[bone_matrixes + V0 * 20 + 6];
            IR3 = hu[bone_matrixes + V0 * 20 + c];
            gte_rtir12(); // ir * rotmatrix
            [1f800220] = h(IR1);
            [1f800226] = h(IR2);
            [1f80022c] = h(IR3);

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 2];
            IR2 = hu[bone_matrixes + V0 * 20 + 8];
            IR3 = hu[bone_matrixes + V0 * 20 + e];
            gte_rtir12(); // ir * rotmatrix
            [1f800222] = h(IR1);
            [1f800228] = h(IR2);
            [1f80022e] = h(IR3);

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 4];
            IR2 = hu[bone_matrixes + V0 * 20 + a];
            IR3 = hu[bone_matrixes + V0 * 20 + 10];
            gte_rtir12(); // ir * rotmatrix
            [1f800224] = h(IR1);
            [1f80022a] = h(IR2);
            [1f800230] = h(IR3);

            TRX = w[bone_matrixes + 14];
            TRY = w[bone_matrixes + 18];
            TRZ = w[bone_matrixes + 1c];

            V0 = bu[part + i * 20 + 1];
            VXY0 = (hu[bone_matrixes + V0 * 20 + 18] << 10) | hu[bone_matrixes + V0 * 20 + 14];
            VZ0 = w[bone_matrixes + V0 * 20 + 1c];
            gte_rtv0tr(); // v0 * rotmatrix + tr vector
            [1f800234] = w(IR1);
            [1f800238] = w(IR2);
            [1f80023c] = w(IR3);

            R11R12 = w[SP + 10];
            R13R21 = w[SP + 14];
            R22R23 = w[SP + 18];
            R31R32 = w[SP + 1c];
            R33 = w[SP + 20];

            IR1 = hu[1f800220];
            IR2 = hu[1f800226];
            IR3 = hu[1f80022c];
            gte_rtir12(); // ir * rotmatrix
            [1f800240] = h(IR1);
            [1f800246] = h(IR2);
            [1f80024c] = h(IR3);

            IR1 = hu[1f800222];
            IR2 = hu[1f800228];
            IR3 = hu[1f80022e];
            gte_rtir12(); // ir * rotmatrix
            [1f800242] = h(IR1);
            [1f800248] = h(IR2);
            [1f80024e] = h(IR3);

            IR1 = hu[1f800224];
            IR2 = hu[1f80022a];
            IR3 = hu[1f800230];
            gte_rtir12(); // ir * rotmatrix
            [1f800244] = h(IR1);
            [1f80024a] = h(IR2);
            [1f800250] = h(IR3);

            TRX = w[SP + 24];
            TRY = w[SP + 28];
            TRZ = w[SP + 2c];

            VXY0 = (hu[1f800238] << 10) | hu[1f800234];
            VZ0 = w[1f80023c];
            gte_rtv0tr(); // v0 * rotmatrix + tr vector
            [1f800254] = w(IR1);
            [1f800258] = w(IR2);
            [1f80025c] = w(IR3);

            L11L12 = w[1f800240];
            L13L21 = w[1f800244];
            L22L23 = w[1f800248];
            L31L32 = w[1f80024c];
            L33 = w[1f800250];
        }
        else
        {
            R11R12 = w[SP + 10];
            R13R21 = w[SP + 14];
            R22R23 = w[SP + 18];
            R31R32 = w[SP + 1c];
            R33 = w[SP + 20];

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 0];
            IR2 = hu[bone_matrixes + V0 * 20 + 6];
            IR3 = hu[bone_matrixes + V0 * 20 + c];
            gte_rtir12(); // ir * rotmatrix
            [1f800220 + 0] = h(IR1);
            [1f800220 + 6] = h(IR2);
            [1f800220 + c] = h(IR3);

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 2];
            IR2 = hu[bone_matrixes + V0 * 20 + 8];
            IR3 = hu[bone_matrixes + V0 * 20 + e];
            gte_rtir12(); // ir * rotmatrix
            [1f800222] = h(IR1);
            [1f800228] = h(IR2);
            [1f80022e] = h(IR3);

            V0 = bu[part + i * 20 + 1];
            IR1 = hu[bone_matrixes + V0 * 20 + 4];
            IR2 = hu[bone_matrixes + V0 * 20 + a];
            IR3 = hu[bone_matrixes + V0 * 20 + 10];
            gte_rtir12(); // ir * rotmatrix
            [1f800224] = h(IR1);
            [1f80022a] = h(IR2);
            [1f800230] = h(IR3);

            TRX = w[SP + 24];
            TRY = w[SP + 28];
            TRZ = w[SP + 2c];

            V0 = bu[part + i * 20 + 1];
            VXY0 = (hu[bone_matrixes + V0 * 20 + 18] << 10) | hu[bone_matrixes + V0 * 20 + 14];
            VZ0 = w[bone_matrixes + V0 * 20 + 1с];
            gte_rtv0tr(); // v0 * rotmatrix + tr vector
            [1f800234] = w(IR1);
            [1f800238] = w(IR2);
            [1f80023c] = w(IR3);

            L11L12 = w[1f800220];
            L13L21 = w[1f800224];
            L22L23 = w[1f800228];
            L31L32 = w[1f80022c];
            L33 = w[1f800230];
        }
    }

    A0 = part + i * 20;
    A1 = force; // force lighting calculation
    wm_calculate_part_lighting();
}

return 1;
////////////////////////////////



////////////////////////////////
// wm_calculate_part_lighting()

part = A0;
force = A1;

vertexes = w[part + 18];
poly = vertexes + hu[part + e];

if( w[vertexes + 0] & 2 )
{
    if( force == 0 )
    {
        return;
    }
}

for( int i = 0; i < bu[part + 4]; ++i )
{
    for( int j = 0; j < 4; ++j )
    {
        V0 = bu[poly + 4 + i * 4 + 3];
        VXY0 = w[800c7938 + V0 * 8 + 0];
        VZ0 = w[800c7938 + V0 * 8 + 4];
        RGB = w[poly + 4 + i * 4];
        gte_NCCS(); // Normal color col. v0
        [1f800000] = w(RGB2);
        [poly + 4 + i * 4 + 0] = b(bu[1f800000]);
        [poly + 4 + i * 4 + 1] = b(bu[1f800001]);
        [poly + 4 + i * 4 + 2] = b(bu[1f800002]);
    }
    poly = poly + 18;
}

for( int i = 0; i < bu[part + 5]; ++i )
{
    for( int j = 0; j < 3; ++j )
    {
        V0 = bu[poly + 4 + i * 4 + 3];
        VXY0 = w[800c7938 + V0 * 8 + 0];
        VZ0 = w[800c7938 + V0 * 8 + 4];
        RGB = w[poly + 4 + i * 4];
        gte_NCCS(); // Normal color col. v0
        [1f800000] = w(RGB2);
        [poly + 4 + i * 4 + 0] = b(bu[1f800000]);
        [poly + 4 + i * 4 + 1] = b(bu[1f800001]);
        [poly + 4 + i * 4 + 2] = b(bu[1f800002]);
    }
    poly = poly + 14;
}

for( int i = 0; i < bu[part + 6]; ++i)
{
    V0 = bu[V1 + 1];
    VXY0 = w[800c7938 + V0 * 8 + 0];
    VZ0 = w[800c7938 + V0 * 8 + 4];
    RGB = w[poly + 4];
    gte_NCCS(); // Normal color col. v0
    [1f800000] = w(RGB2);
    [poly + 4] = b(bu[1f800000]);
    [poly + 5] = b(bu[1f800001]);
    [poly + 6] = b(bu[1f800002]);
    poly = poly + c;
}

for( int i = 0; i < bu[part + 7]; ++i )
{
    V0 = bu[poly + 7];
    VXY0 = w[800c7938 + V0 * 8 + 0];
    VZ0 = w[800c7938 + V0 * 8 + 4];
    RGB = w[poly + 4];
    gte_NCCS(); // Normal color col. v0
    [1f800000] = w(RGB2);
    [poly + 4] = b(bu[1f800000]);
    [poly + 5] = b(bu[1f800001]);
    [poly + 6] = b(bu[1f800002]);

    poly = poly + c;
}

for( int i = 0; i < bu[part + 8]; ++i )
{
    V0 = bu[V1 + 1];
    VXY0 = w[800c7938 + V0 * 8 + 0];
    VZ0 = w[800c7938 + V0 * 8 + 4];
    RGB = w[poly + 4];
    gte_NCCS(); // Normal color col. v0
    [1f800000] = w(RGB2);
    [poly + 4] = b(bu[1f800000]);
    [poly + 5] = b(bu[1f800001]);
    [poly + 6] = b(bu[1f800002]);

    poly = poly + 8;
}

for( int i = 0; i < bu[part + 9]; ++i )
{
    V0 = bu[poly + 7]; // command
    VXY0 = w[800c7938 + V0 * 8 + 0];
    VZ0 = w[800c7938 + V0 * 8 + 4];
    RGB = w[poly + 4];
    gte_NCCS(); // Normal color col. v0
    [1f800000] = w(RGB2);
    [poly + 4] = b(bu[1f800000]);
    [poly + 5] = b(bu[1f800001]);
    [poly + 6] = b(bu[1f800002]);

    poly = poly + 8;
}

for( int i = 0; i < bu[part + a]; ++i )
{
    for( int j = 0; j < 3; ++j )
    {
        V0 = bu[poly + 4 + i * 4 + 3];
        VXY0 = w[800c7938 + V0 * 8 + 0];
        VZ0 = w[800c7938 + V0 * 8 + 4];
        RGB = w[poly + 4 + i * 4];
        gte_NCCS(); // Normal color col. v0
        [1f800000] = w(RGB2);
        [poly + 4 + i * 4 + 0] = b(bu[1f800000]);
        [poly + 4 + i * 4 + 1] = b(bu[1f800001]);
        [poly + 4 + i * 4 + 2] = b(bu[1f800002]);
    }
    poly = poly + 10;
}

for( int i = 0; i < bu[part + b]; ++i )
{
    for( int j = 0; j < 4; ++ j )
    {
        V0 = bu[poly + 4 + i * 4 + 3];
        VXY0 = w[800c7938 + V0 * 8 + 0];
        VZ0 = w[800c7938 + V0 * 8 + 4];
        RGB = w[poly + 4 + i * 4 + 0];
        gte_NCCS(); // Normal color col. v0
        [1f800000] = w(RGB2);
        [poly + 4 + i * 4 + 0] = b(bu[1f800000]); // r
        [poly + 4 + i * 4 + 1] = b(bu[1f800001]); // g
        [poly + 4 + i * 4 + 2] = b(bu[1f800002]); // b
    }
    poly = poly + 14;
}

[vertexes + 0] = w(w[vertexes + 0] | 2);
////////////////////////////////



////////////////////////////////
// funcc3db0

T1 = 0;

Lc3db8:	; 800C3DB8
A3 = w[A0 + 001c];
800C3DBC	beq    t1, zero, Lc3dd0 [$800c3dd0]
A2 = 0;
V0 = hu[A0 + 0016];
800C3DC8	nop
A3 = A3 + V0;

Lc3dd0:	; 800C3DD0
T0 = bu[A0 + 0004];
800C3DD4	nop
800C3DD8	beq    t0, zero, Lc3e3c [$800c3e3c]
800C3DDC	nop
V1 = A3 + 0007;

loopc3de4:	; 800C3DE4
800C3DE4	beq    a1, zero, Lc3df8 [$800c3df8]
800C3DE8	nop
V0 = bu[V1 + 0000];
800C3DF0	j      Lc3e04 [$800c3e04]
V0 = V0 | 0002;

Lc3df8:	; 800C3DF8
V0 = bu[V1 + 0000];
800C3DFC	nop
V0 = V0 & 00fd;

Lc3e04:	; 800C3E04
800C3E04	beq    a1, zero, Lc3e18 [$800c3e18]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C3E10	j      Lc3e24 [$800c3e24]
V0 = V0 | 0001;

Lc3e18:	; 800C3E18
V0 = bu[V1 + 0000];
800C3E1C	nop
V0 = V0 & 00fe;

Lc3e24:	; 800C3E24
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0034;
V0 = A2 < T0;
800C3E34	bne    v0, zero, loopc3de4 [$800c3de4]
A3 = A3 + 0034;

Lc3e3c:	; 800C3E3C
T0 = bu[A0 + 0005];
800C3E40	nop
800C3E44	beq    t0, zero, Lc3ea8 [$800c3ea8]
A2 = 0;
V1 = A3 + 0007;

loopc3e50:	; 800C3E50
800C3E50	beq    a1, zero, Lc3e64 [$800c3e64]
800C3E54	nop
V0 = bu[V1 + 0000];
800C3E5C	j      Lc3e70 [$800c3e70]
V0 = V0 | 0002;

Lc3e64:	; 800C3E64
V0 = bu[V1 + 0000];
800C3E68	nop
V0 = V0 & 00fd;

Lc3e70:	; 800C3E70
800C3E70	beq    a1, zero, Lc3e84 [$800c3e84]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C3E7C	j      Lc3e90 [$800c3e90]
V0 = V0 | 0001;

Lc3e84:	; 800C3E84
V0 = bu[V1 + 0000];
800C3E88	nop
V0 = V0 & 00fe;

Lc3e90:	; 800C3E90
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0028;
V0 = A2 < T0;
800C3EA0	bne    v0, zero, loopc3e50 [$800c3e50]
A3 = A3 + 0028;

Lc3ea8:	; 800C3EA8
T0 = bu[A0 + 0006];
800C3EAC	nop
800C3EB0	beq    t0, zero, Lc3f14 [$800c3f14]
A2 = 0;
V1 = A3 + 0007;

loopc3ebc:	; 800C3EBC
800C3EBC	beq    a1, zero, Lc3ed0 [$800c3ed0]
800C3EC0	nop
V0 = bu[V1 + 0000];
800C3EC8	j      Lc3edc [$800c3edc]
V0 = V0 | 0002;

Lc3ed0:	; 800C3ED0
V0 = bu[V1 + 0000];
800C3ED4	nop
V0 = V0 & 00fd;

Lc3edc:	; 800C3EDC
800C3EDC	beq    a1, zero, Lc3ef0 [$800c3ef0]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C3EE8	j      Lc3efc [$800c3efc]
V0 = V0 | 0001;

Lc3ef0:	; 800C3EF0
V0 = bu[V1 + 0000];
800C3EF4	nop
V0 = V0 & 00fe;

Lc3efc:	; 800C3EFC
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0028;
V0 = A2 < T0;
800C3F0C	bne    v0, zero, loopc3ebc [$800c3ebc]
A3 = A3 + 0028;

Lc3f14:	; 800C3F14
T0 = bu[A0 + 0007];
800C3F18	nop
800C3F1C	beq    t0, zero, Lc3f80 [$800c3f80]
A2 = 0;
V1 = A3 + 0007;

loopc3f28:	; 800C3F28
800C3F28	beq    a1, zero, Lc3f3c [$800c3f3c]
800C3F2C	nop
V0 = bu[V1 + 0000];
800C3F34	j      Lc3f48 [$800c3f48]
V0 = V0 | 0002;

Lc3f3c:	; 800C3F3C
V0 = bu[V1 + 0000];
800C3F40	nop
V0 = V0 & 00fd;

Lc3f48:	; 800C3F48
800C3F48	beq    a1, zero, Lc3f5c [$800c3f5c]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C3F54	j      Lc3f68 [$800c3f68]
V0 = V0 | 0001;

Lc3f5c:	; 800C3F5C
V0 = bu[V1 + 0000];

Lc3f60:	; 800C3F60
800C3F60	nop
V0 = V0 & 00fe;

Lc3f68:	; 800C3F68
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0020;
V0 = A2 < T0;
800C3F78	bne    v0, zero, loopc3f28 [$800c3f28]
A3 = A3 + 0020;

Lc3f80:	; 800C3F80
T0 = bu[A0 + 0008];
800C3F84	nop
800C3F88	beq    t0, zero, Lc3fec [$800c3fec]
A2 = 0;
V1 = A3 + 0007;

loopc3f94:	; 800C3F94
800C3F94	beq    a1, zero, Lc3fa8 [$800c3fa8]
800C3F98	nop
V0 = bu[V1 + 0000];
800C3FA0	j      Lc3fb4 [$800c3fb4]
V0 = V0 | 0002;

Lc3fa8:	; 800C3FA8
V0 = bu[V1 + 0000];
800C3FAC	nop
V0 = V0 & 00fd;

Lc3fb4:	; 800C3FB4
800C3FB4	beq    a1, zero, Lc3fc8 [$800c3fc8]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C3FC0	j      Lc3fd4 [$800c3fd4]
V0 = V0 | 0001;

Lc3fc8:	; 800C3FC8
V0 = bu[V1 + 0000];
800C3FCC	nop
V0 = V0 & 00fe;

Lc3fd4:	; 800C3FD4
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0014;
V0 = A2 < T0;
800C3FE4	bne    v0, zero, loopc3f94 [$800c3f94]
A3 = A3 + 0014;

Lc3fec:	; 800C3FEC
T0 = bu[A0 + 0009];
800C3FF0	nop
800C3FF4	beq    t0, zero, Lc4058 [$800c4058]
A2 = 0;
V1 = A3 + 0007;

loopc4000:	; 800C4000
800C4000	beq    a1, zero, Lc4014 [$800c4014]
800C4004	nop
V0 = bu[V1 + 0000];
800C400C	j      Lc4020 [$800c4020]
V0 = V0 | 0002;

Lc4014:	; 800C4014
V0 = bu[V1 + 0000];
800C4018	nop
V0 = V0 & 00fd;

Lc4020:	; 800C4020
800C4020	beq    a1, zero, Lc4034 [$800c4034]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C402C	j      Lc4040 [$800c4040]
V0 = V0 | 0001;

Lc4034:	; 800C4034
V0 = bu[V1 + 0000];
800C4038	nop
V0 = V0 & 00fe;

Lc4040:	; 800C4040
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 0018;
V0 = A2 < T0;
800C4050	bne    v0, zero, loopc4000 [$800c4000]
A3 = A3 + 0018;

Lc4058:	; 800C4058
T0 = bu[A0 + 000a];
800C405C	nop
800C4060	beq    t0, zero, Lc40c4 [$800c40c4]
A2 = 0;
V1 = A3 + 0007;

loopc406c:	; 800C406C
800C406C	beq    a1, zero, Lc4080 [$800c4080]
800C4070	nop
V0 = bu[V1 + 0000];
800C4078	j      Lc408c [$800c408c]
V0 = V0 | 0002;

Lc4080:	; 800C4080
V0 = bu[V1 + 0000];
800C4084	nop
V0 = V0 & 00fd;

Lc408c:	; 800C408C
800C408C	beq    a1, zero, Lc40a0 [$800c40a0]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C4098	j      Lc40ac [$800c40ac]
V0 = V0 | 0001;

Lc40a0:	; 800C40A0
V0 = bu[V1 + 0000];
800C40A4	nop
V0 = V0 & 00fe;

Lc40ac:	; 800C40AC
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V1 = V1 + 001c;
V0 = A2 < T0;
800C40BC	bne    v0, zero, loopc406c [$800c406c]
A3 = A3 + 001c;

Lc40c4:	; 800C40C4
T0 = bu[A0 + 000b];
800C40C8	nop
800C40CC	beq    t0, zero, Lc412c [$800c412c]
A2 = 0;
V1 = A3 + 0007;

loopc40d8:	; 800C40D8
800C40D8	beq    a1, zero, Lc40ec [$800c40ec]
800C40DC	nop
V0 = bu[V1 + 0000];
800C40E4	j      Lc40f8 [$800c40f8]
V0 = V0 | 0002;

Lc40ec:	; 800C40EC
V0 = bu[V1 + 0000];
800C40F0	nop
V0 = V0 & 00fd;

Lc40f8:	; 800C40F8
800C40F8	beq    a1, zero, Lc410c [$800c410c]
[V1 + 0000] = b(V0);
V0 = bu[V1 + 0000];
800C4104	j      Lc4118 [$800c4118]
V0 = V0 | 0001;

Lc410c:	; 800C410C
V0 = bu[V1 + 0000];
800C4110	nop
V0 = V0 & 00fe;

Lc4118:	; 800C4118
[V1 + 0000] = b(V0);
A2 = A2 + 0001;
V0 = A2 < T0;
800C4124	bne    v0, zero, loopc40d8 [$800c40d8]
V1 = V1 + 0024;

Lc412c:	; 800C412C
T1 = T1 + 0001;
V0 = T1 < 0002;
800C4134	bne    v0, zero, Lc3db8 [$800c3db8]
////////////////////////////////



////////////////////////////////
// funcc4148()

model = A0;
// A1 - some struct with data

A0 = bu[A1 + 0];
S0 = 800c8100 + bu[A1 + 1] * 3c;

if( A0 == 0 )
{
    [S0 + 0] = h(hu[A1 + 2]);
    [S0 + 2] = h(hu[A1 + 4]);
    [S0 + 4] = h(hu[A1 + 6]);
    [S0 + 6] = h(hu[A1 + 8]);

    [1f800200] = h(hu[S0 + 0]);
    [1f800202] = h(hu[S0 + 2]);
    [1f800204] = h(hu[S0 + 4]);
    [1f800206] = h(0);

    A0 = 1f800200;
    A1 = 1f800208;
    func3a0b8();

    [S0 + 8] = h(hu[1f800208]);
    [S0 + a] = h(hu[1f80020a]);
    [S0 + c] = h(hu[1f80020c]);

    if( h[1f80020c] != 0 )
    {
        [1f800210] = h(0);
        [1f800212] = h(0);
        [1f800214] = h((h[S0 + 6] * 1000) / h[1f80020c]);
    }
    else if( h[1f80020a] != 0 )
    {
        [1f800210] = h(0);
        [1f800212] = h((h[S0 + 6] * 1000) / h[1f80020a]);
        [1f800214] = h(0);
    }
    else if( h[1f800208] != 0 )
    {
        [1f800210] = h((h[S0 + 6] * 1000) / h[1f800208]);
        [1f800212] = h(0);
        [1f800214] = h(0);
    }
    else
    {
        return 1;
    }

    [S0 + e] = h(hu[1f800210]);
    [S0 + 10] = h(hu[1f800212]);
    [S0 + 12] = h(hu[1f800214]);

    [1f800218] = h(0);

    V1 = h[1f800208 + 0000];
    V0 = h[1f800218 + 0000];

    800C43F0	mult   v1, v0
    V0 = hu[1f800208 + 0002];
    [1f800218 + 0002] = h(0);
    V0 = V0 << 10;
    A2 = V0 >> 10;
    V0 = hu[1f800218 + 0002];
    800C4408	mflo   a0
    V0 = V0 << 10;
    A1 = V0 >> 10;
    800C4414	mult   a2, a1
    S3 = 1000;
    [1f800218 + 0004] = h(S3);
    V0 = hu[1f800208 + 0004];
    800C4424	nop
    V0 = V0 << 10;
    800C442C	mflo   v1
    A0 = A0 + V1;
    V1 = V0 >> 10;
    V0 = V1 << 0c;
    A0 = A0 + V0;
    800C4444	mult   a1, v1
    V1 = A2 << 0c;
    800C4450	mflo   v0
    A1 = V1 - V0;
    S6 = A0 / 1000;
    V0 = hu[1f800208 + 0004];
    V1 = h[1f800218 + 0000];
    V0 = V0 << 10;
    V0 = V0 >> 10;
    800C4474	mult   v1, v0
    V0 = hu[1f800218 + 0004];
    V1 = h[1f800208 + 0000];
    800C4480	mflo   a0
    V0 = V0 << 10;
    V0 = V0 >> 10;
    800C448C	mult   v1, v0
    V0 = A1 / 1000;
    [1f800220 + 0000] = h(V0);
    800C4498	mflo   v0
    A1 = A0 - V0;
    V0 = hu[1f800218 + 0002];
    V1 = h[1f800208 + 0000];
    V0 = V0 << 10;
    V0 = V0 >> 10;
    800C44BC	mult   v1, v0
    V0 = hu[1f800208 + 0002];
    V1 = h[1f800218 + 0000];
    800C44C8	mflo   a0
    V0 = V0 << 10;
    V0 = V0 >> 10;
    800C44D4	mult   v1, v0
    V0 = A1 / 1000;
    [1f800220 + 0002] = h(V0);
    800C44E0	mflo   v0
    A0 = A0 - V0;
    V0 = h[1f800220 + 0000];
    800C44F8	nop
    800C44FC	mult   v0, v0
    V0 = hu[1f800220 + 0002];
    800C4504	mflo   v1
    V0 = V0 << 10;
    V0 = V0 >> 10;
    800C4510	mult   v0, v0
    A0 = A0 / 1000;
    800C4518	mflo   a1
    V0 = A0 << 10;
    V0 = V0 >> 10;
    800C4524	mult   v0, v0
    [1f800220 + 0004] = h(A0);
    V1 = V1 + A1;
    800C4530	mflo   a0
    A0 = V1 + A0;

    system_square_root();
    S1 = V0;

    A0 = 1f800220;
    A1 = 1f800228;
    func3a0b8();

    if( ( h[1f800228] == 0 ) && ( hu[1f80022a] == 0 ) && ( hu[1f80022c] == 0 ) )
    {
        [S0 + 14] = h(S3);
        [S0 + 16] = h(0);
        [S0 + 18] = h(0);
        [S0 + 1a] = h(0);
        [S0 + 1c] = h(S3);
        [S0 + 1e] = h(0);
        [S0 + 20] = h(0);
        [S0 + 22] = h(0);
        [S0 + 24] = h(S3);
    }
    else
    {
        x = h[1f800228];
        y = h[1f80022a];
        z = h[1f80022c];

        xx = x * x;
        yy = y * y;
        zz = z * z;
        xy = x * y;
        xz = x * z;
        yz = y * z;

        V0 = (S1 << 10) >> 10;
        T5 = x * V0;
        T4 = y * V0;
        T1 = z * V0;

        A1 = (S6 << 10) >> 10;
        A0 = 1000 - A1;
        [S0 + 14] = h((xx + (A1 * ((1000000 - xx) / 1000))) / 1000);
        [S0 + 16] = h((((xy / 1000) * A0) - T1) / 1000);
        [S0 + 18] = h((((xz / 1000) * A0) + T4) / 1000);
        [S0 + 1a] = h((((xy / 1000) * A0) + T1) / 1000);
        [S0 + 1c] = h((yy + (A1 * ((1000000 - yy) / 1000))) / 1000);
        [S0 + 1e] = h((((yz / 1000) * A0) - T5) / 1000);
        [S0 + 20] = h((((xz / 1000) * A0) - T4) / 1000);
        [S0 + 22] = h((((yz / 1000) * A0) + T5) / 1000);
        [S0 + 24] = h((zz + (A1 * ((1000000 - zz) / 1000))) / 1000);
    }

    for( int i = 0; i < bu[model + 3]; ++i )
    {
        V1 = w[model + 1c] + hu[model + 18];
        [V1 + i * 20 + 0] = b(0);
    }
    return 1;
}
else if( A0 == 1 )
{
    [1f800218] = h(1000);
    [1f800210] = h(1000);
    [1f800208] = h(1000);
    [1f800224] = w(0);
    [1f800220] = w(0);
    [1f80021c] = w(0);
    [1f800216] = h(0);
    [1f800214] = h(0);
    [1f800212] = h(0);
    [1f80020e] = h(0);
    [1f80020c] = h(0);
    [1f80020a] = h(0);
    [1f800244] = w(0);
    [1f800240] = w(0);
    [1f80023c] = w(0);
    [1f800264] = w(0);
    [1f800260] = w(0);
    [1f80025c] = w(0);
    [1f800200] = h(hu[S0 + 8]);
    [1f800202] = h(hu[S0 + a]);
    [1f800206] = h(0);
    [1f800204] = h(hu[S0 + c]);

    S4 = w[model + 20];
    S3 = w[model + 1c] + hu[model + 18];

    for( int i = 0; i < bu[model + 3]; ++i )
    {
        [1f80021c] = w(0 - h[S0 + e]);
        [1f800220] = w(0 - h[S0 + 10]);
        [1f800224] = w(0 - h[S0 + 12]);
        [1f800228] = h(hu[S0 + 14]);
        [1f80022a] = h(hu[S0 + 16]);
        [1f80022c] = h(hu[S0 + 18]);
        [1f80022e] = h(hu[S0 + 1a]);
        [1f800230] = h(hu[S0 + 1c]);
        [1f800232] = h(hu[S0 + 1e]);
        [1f800234] = h(hu[S0 + 20]);
        [1f800236] = h(hu[S0 + 22]);
        [1f800238] = h(hu[S0 + 24]);

        R11R12 = w[1f800208];
        R13R21 = w[1f80020c];
        R22R23 = w[1f800210];
        R31R32 = w[1f800214];
        R33 = w[1f800218];

        V0 = bu[S3 + i * 20 + 1];
        IR1 = hu[S4 + V0 * 20 + 0];
        IR2 = hu[S4 + V0 * 20 + 6];
        IR3 = hu[S4 + V0 * 20 + c];
        gte_rtir12(); // ir * rotmatrix
        [1f800268 + 0] = h(IR1);
        [1f800268 + 6] = h(IR2);
        [1f800268 + c] = h(IR3);

        V0 = bu[S3 + i * 20 + 1];
        IR1 = hu[S4 + V0 * 20 + 2];
        IR2 = hu[S4 + V0 * 20 + 8];
        IR3 = hu[S4 + V0 * 20 + e];
        gte_rtir12(); // ir * rotmatrix
        [1f80026a + 0] = h(IR1);
        [1f80026a + 6] = h(IR2);
        [1f80026a + c] = h(IR3);

        V0 = bu[S3 + i * 20 + 1];
        IR1 = hu[S4 + V0 * 20 + 4];
        IR2 = hu[S4 + V0 * 20 + a];
        IR3 = hu[S4 + V0 * 20 + 10];
        gte_rtir12(); // ir * rotmatrix
        [1f80026c + 0] = h(IR1);
        [1f80026c + 6] = h(IR2);
        [1f80026c + c] = h(IR3);

        TRX = w[1f80021c];
        TRY = w[1f800220];
        TRZ = w[1f800224];

        V0 = bu[S3 + i * 20 + 1];
        VXY0 = (hu[S4 + V0 * 20 + 18] << 10) | (hu[S4 + V0 * 20 + 14]);
        VZ0 = w[S4 + V0 * 20 + 1c];
        gte_rtv0tr(); // v0 * rotmatrix + tr vector
        [1f80027c] = w(IR1);
        [1f800280] = w(IR2);
        [1f800284] = w(IR3);

        R11R12 = w[1f800228];
        R13R21 = w[1f80022c];
        R22R23 = w[1f800230];
        R31R32 = w[1f800234];
        R33 = w[1f800238];

        IR1 = hu[1f800268 + 0];
        IR2 = hu[1f800268 + 6];
        IR3 = hu[1f800268 + c];
        gte_rtir12(); // ir * rotmatrix
        [1f800268 + 0000] = h(IR1);
        [1f800268 + 0006] = h(IR2);
        [1f800268 + 000c] = h(IR3);

        IR1 = hu[1f80026a];
        IR2 = hu[1f800270];
        IR3 = hu[1f800276];
        gte_rtir12(); // ir * rotmatrix
        [1f80026a] = h(IR1);
        [1f800270] = h(IR2);
        [1f800276] = h(IR3);

        IR1 = hu[1f80026c + 0];
        IR2 = hu[1f80026c + 6];
        IR3 = hu[1f80026c + c];
        gte_rtir12(); // ir * rotmatrix
        [1f80026c + 0000] = h(IR1);
        [1f80026c + 0006] = h(IR2);
        [1f80026c + 000c] = h(IR3);

        TRX = w[1f80023c];
        TRY = w[1f800240];
        TRZ = w[1f800244];

        VXY0 = (hu[1f80027c + 4] << 10) | hu[1f80027c + 0];
        VZ0 = w[1f80027c + 8];
        gte_rtv0tr(); // v0 * rotmatrix + tr vector
        [1f80027c + 0] = w(IR1);
        [1f80027c + 4] = w(IR2);
        [1f80027c + 8] = w(IR3);

        [1f80021c] = w(h[S0 + e]);
        [1f800220] = w(h[S0 + 10]);
        [1f800224] = w(h[S0 + 12]);

        A0 = 1f800228;
        A1 = 1f800248;
        system_transponate_matrix();

        R11R12 = w[S4 + 0];
        R13R21 = w[S4 + 4];
        R22R23 = w[S4 + 8];
        R31R32 = w[S4 + c];
        R33 = w[S4 + 10];

        IR1 = hu[1f800208];
        IR2 = hu[1f80020e];
        IR3 = hu[1f800214];
        gte_rtir12(); // ir * rotmatrix
        [1f800288 + 0] = h(IR1);
        [1f800288 + 6] = h(IR2);
        [1f800288 + c] = h(IR3);

        IR1 = hu[1f80020a];
        IR2 = hu[1f800210];
        IR3 = hu[1f800216];
        gte_rtir12(); // ir * rotmatrix
        [1f80028a + 0] = h(IR1);
        [1f80028a + 6] = h(IR2);
        [1f80028a + c] = h(IR3);

        IR1 = hu[1f80020c];
        IR2 = hu[1f800212];
        IR3 = hu[1f800218];
        gte_rtir12(); // ir * rotmatrix
        [1f80028c + 0] = h(IR1);
        [1f80028c + 6] = h(IR2);
        [1f80028c + c] = h(IR3);

        TRX = w[S4 + 14];
        TRY = w[S4 + 18];
        TRZ = w[S4 + 1c];

        VXY0 = (hu[1f800220] << 10) | hu[1f80021c];
        VZ0 = w[1f800224];
        gte_rtv0tr(); // v0 * rotmatrix + tr vector
        [1f80029c + 0] = w(IR1);
        [1f80029c + 4] = w(IR2);
        [1f80029c + 8] = w(IR3);

        R11R12 = w[1f800288 + 0];
        R13R21 = w[1f800288 + 4];
        R22R23 = w[1f800288 + 8];
        R31R32 = w[1f800288 + c];
        R33 = w[1f800288 + 10];

        IR1 = hu[1f800248 + 0];
        IR2 = hu[1f800248 + 6];
        IR3 = hu[1f800248 + c];
        gte_rtir12(); // ir * rotmatrix
        [1f800288 + 0] = h(IR1);
        [1f800288 + 6] = h(IR2);
        [1f800288 + c] = h(IR3);

        IR1 = hu[1f80024a];
        IR2 = hu[1f800250];
        IR3 = hu[1f800256];
        gte_rtir12(); // ir * rotmatrix
        [1f80028a] = h(IR1);
        [1f800290] = h(IR2);
        [1f800296] = h(IR3);

        IR1 = hu[1f80024c];
        IR2 = hu[1f800252];
        IR3 = hu[1f800258];
        gte_rtir12(); // ir * rotmatrix
        [1f80028c] = h(IR1);
        [1f800292] = h(IR2);
        [1f800298] = h(IR3);

        TRX = w[1f800288 + 14];
        TRY = w[1f800288 + 18];
        TRZ = w[1f800288 + 1c];

        VXY0 = (hu[1f800260] << 10) | hu[1f80025c];
        VZ0 = w[1f800264];
        gte_rtv0tr(); // v0 * rotmatrix + tr vector
        [1f80029c] = w(IR1);
        [1f8002a0] = w(IR2);
        [1f8002a4] = w(IR3);

        A0 = S3 + i * 20;
        A1 = 1f800200;
        A2 = 1f800268;
        A3 = 1f800288;
        funcc4fb4();
    }

    return 0;
}

return 1;
////////////////////////////////



////////////////////////////////
// funcc4fb4()

S0 = w[800c7530];
S3 = A0;

R11R12 = w[A2 + 0];
R13R21 = w[A2 + 4];
R22R23 = w[A2 + 8];
R31R32 = w[A2 + c];
R33 = w[A2 + 10];
TRX = w[A2 + 14];
TRY = w[A2 + 18];
TRZ = w[A2 + 1c];

T9 = bu[S3 + 2];
T8 = w[S3 + 18] + 4;
T7 = w[800c80bc];

A0 = 0;

if( h[A1 + 0] == 0 )
{
    if( h[A1 + 2] == 0 )
    {
        A0 = (h[A1 + 4] ^ fffff000) < 1;
    }
}

V1 = T7;

for( int i = 0; i < T9; ++i )
{
    VXY0 = w[T8 + 0];
    VZ0 = w[T8 + 4];
    gte_rtv0tr(); // v0 * rotmatrix + tr vector
    [V1 + 8] = h(IR1);
    [V1 + a] = h(IR2);
    [V1 + c] = h(IR3);

    if( A0 != 0 )
    {
        if( h[V1 + c] > 0 )
        {
            [V1 + c] = h(0);
        }
    }
    else
    {
        if( h[V1 + c] < 0 )
        {
            [V1 + c] = h(0);
        }
    }

    T8 = T8 + 8;
    V1 = V1 + 10;
}

R11R12 = w[A3 + 0];
R13R21 = w[A3 + 4];
R22R23 = w[A3 + 8];
R31R32 = w[A3 + c];
R33 = w[A3 + 10];
TRX = w[A3 + 14];
TRY = w[A3 + 18];
TRZ = w[A3 + 1c];

V1 = T7;

for( int i = 0; i < T9; ++i )
{
    VXY0 = w[V1 + 8];
    VZ0 = w[V1 + c];
    gte_RTPS(); // Perspective transform
    [V1 + 0] = w(SXY2);
    [V1 + 4] = w(SZ3);

    V1 = V1 + 0010;
}


V0 = bu[800c752c];
T0 = w[S3 + 1c];
T1 = 0;
if( V0 != 0 )
{
    T0 = T0 + hu[S3 + 16];
}

S2 = w[S3 + 0004];
T9 = S2 & 00ff;
if( T9 != 0 )
{
    loopc519c:	; 800C519C
        V0 = w[T8 + 0] & 00ff;
        V0 = V0 << 04;
        T3 = T7 + V0;
        V0 = w[T8 + 0] & ff00;
        V0 = V0 >> 04;
        T2 = T7 + V0;
        V0 = w[T8 + 0] >> 0c;
        V0 = V0 & 0ff0;
        A3 = T7 + V0;
        V1 = w[T8 + 0] >> 18;
        V1 = V1 << 04;
        A2 = T7 + V1;

        V0 = w[T3 + 0];
        V1 = w[T2 + 0];
        A0 = w[A3 + 0];
        A1 = w[A2 + 0];

        SXY0 = V0;
        SXY2P = A0;
        SXY1 = V1;
        gte_NCLIP(); // Normal clipping
        [T0 + 8] = w(V0);
        [T0 + 14] = w(V1);
        [T0 + 20] = w(A0);
        [T0 + 2c] = w(A1);

        if( ( MAC0 <= 0 ) || ( ( h[T3 + c] == 0 ) && ( h[T2 + c] == 0 ) && ( h[A3 + c] == 0 ) && ( h[A2 + c] == 0 ) ))
        {
            [T0 + 0] = w(w[T0 + 0] & ff000000);
        }
        else
        {
            V0 = S0 + (((w[T3 + 4] + w[T2 + 4] + w[A3 + 4] + w[A2 + 4]) / 4) >> 2) << 2;

            [T0 + 0] = w((w[T0 + 0] & ff000000) | (w[V0 + 0] & 00ffffff));
            [V0 + 0] = w((w[V0 + 0] & ff000000) | (T0 & 00ffffff));
        }

        T1 = T1 + 1;
        T0 = T0 + 34;
        T8 = T8 + 18;
        V0 = T1 < T9;
    800C5304	bne    v0, zero, loopc519c [$800c519c]
}

V0 = S2 & ff00;
T9 = V0 >> 08;
800C5314	beq    t9, zero, Lc5454 [$800c5454]
T1 = 0;
800C531C	lui    t5, $ff00
800C5320	lui    t4, $00ff
T4 = T4 | ffff;
T2 = T0 + 0020;

loopc532c:	; 800C532C
V1 = w[T8 + 0000];
T3 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
A3 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A2 = T7 + V0;
V1 = V1 >> 0c;
V1 = V1 & 0ff0;
A1 = T7 + V1;
V0 = w[A3 + 0000];
V1 = w[A2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C5370	nop
800C5374	nop
gte_NCLIP(); // Normal clipping
[T2 + ffe8] = w(V0);
[T2 + fff4] = w(V1);
[T2 + 0000] = w(A0);
V0 = MAC0;
800C538C	nop
800C5390	blez   v0, Lc53c8 [$800c53c8]
800C5394	nop
V0 = h[A3 + 000c];
800C539C	nop
800C53A0	bne    v0, zero, Lc53dc [$800c53dc]
800C53A4	nop
V0 = h[A2 + 000c];
800C53AC	nop
800C53B0	bne    v0, zero, Lc53dc [$800c53dc]
800C53B4	nop
V0 = h[A1 + 000c];
800C53BC	nop
800C53C0	bne    v0, zero, Lc53dc [$800c53dc]
800C53C4	nop

Lc53c8:	; 800C53C8
V0 = w[T0 + 0000];
800C53CC	nop
V0 = V0 & T5;
800C53D4	j      Lc543c [$800c543c]
[T0 + 0000] = w(V0);

Lc53dc:	; 800C53DC
A3 = w[A3 + 0004];
A2 = w[A2 + 0004];
A1 = w[A1 + 0004];
SZ1 = A3;
SZ2 = A2;
SZ3 = A1;
800C53F4	nop
800C53F8	nop
gte_AVSZ3(); // Average of three Z values
A0 = OTZ;
800C5404	nop
A0 = A0 << 02;
A0 = A0 + S0;
V1 = w[T3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T5;
V0 = V0 & T4;
V1 = V1 | V0;
[T3 + 0000] = w(V1);
V0 = w[A0 + 0000];
V1 = T3 & T4;
V0 = V0 & T5;
V0 = V0 | V1;
[A0 + 0000] = w(V0);

Lc543c:	; 800C543C
T1 = T1 + 0001;
T2 = T2 + 0028;
T0 = T0 + 0028;
V0 = T1 < T9;
800C544C	bne    v0, zero, loopc532c [$800c532c]
T8 = T8 + 0014;

Lc5454:	; 800C5454
V0 = S2 >> 10;
T9 = V0 & 00ff;
800C545C	beq    t9, zero, Lc55e4 [$800c55e4]
T1 = 0;
800C5464	lui    s1, $ff00
800C5468	lui    t6, $00ff
T6 = T6 | ffff;
T4 = T0 + 0020;

loopc5474:	; 800C5474
V1 = w[T8 + 0000];
T5 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
T3 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
T2 = T7 + V0;
V0 = V1 >> 0c;
V0 = V0 & 0ff0;
A3 = T7 + V0;
V1 = V1 >> 18;
V1 = V1 << 04;
A2 = T7 + V1;
V0 = w[T3 + 0000];
V1 = w[T2 + 0000];
A0 = w[A3 + 0000];
A1 = w[A2 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C54C8	nop
800C54CC	nop
gte_NCLIP(); // Normal clipping
[T4 + ffe8] = w(V0);
[T4 + fff0] = w(V1);
[T4 + fff8] = w(A0);
[T4 + 0000] = w(A1);
V0 = MAC0;
800C54E8	nop
800C54EC	blez   v0, Lc5534 [$800c5534]
800C54F0	nop
V0 = h[T3 + 000c];
800C54F8	nop
800C54FC	bne    v0, zero, Lc5548 [$800c5548]
800C5500	nop
V0 = h[T2 + 000c];
800C5508	nop
800C550C	bne    v0, zero, Lc5548 [$800c5548]
800C5510	nop
V0 = h[A3 + 000c];
800C5518	nop
800C551C	bne    v0, zero, Lc5548 [$800c5548]
800C5520	nop
V0 = h[A2 + 000c];
800C5528	nop
800C552C	bne    v0, zero, Lc5548 [$800c5548]
800C5530	nop

Lc5534:	; 800C5534
V0 = w[T0 + 0000];
800C5538	nop
V0 = V0 & S1;
800C5540	j      Lc55cc [$800c55cc]
[T0 + 0000] = w(V0);

Lc5548:	; 800C5548
V0 = w[T3 + 0004];
V1 = w[T2 + 0004];
800C5550	nop
V0 = V0 + V1;
V1 = w[A3 + 0004];
A0 = w[A2 + 0004];
V0 = V0 + V1;
V0 = V0 + A0;
V0 = V0 >> 04;
V0 = V0 << 02;
V0 = V0 + S0;
V1 = w[T5 + 0000];
V0 = w[V0 + 0000];
V1 = V1 & S1;
V0 = V0 & T6;
V1 = V1 | V0;
[T5 + 0000] = w(V1);
V1 = w[T3 + 0004];
V0 = w[T2 + 0004];
800C5594	nop
V1 = V1 + V0;
V0 = w[A3 + 0004];
A0 = w[A2 + 0004];
V1 = V1 + V0;
V1 = V1 + A0;
V1 = V1 >> 04;
V1 = V1 << 02;
V1 = V1 + S0;
V0 = w[V1 + 0000];
A0 = T5 & T6;
V0 = V0 & S1;
V0 = V0 | A0;
[V1 + 0000] = w(V0);

Lc55cc:	; 800C55CC
T1 = T1 + 0001;
T4 = T4 + 0028;
T0 = T0 + 0028;
V0 = T1 < T9;
800C55DC	bne    v0, zero, loopc5474 [$800c5474]
T8 = T8 + 000c;

Lc55e4:	; 800C55E4
T9 = S2 >> 18;
800C55E8	beq    t9, zero, Lc5728 [$800c5728]
T1 = 0;
800C55F0	lui    t5, $ff00
800C55F4	lui    t4, $00ff
T4 = T4 | ffff;
T2 = T0 + 0018;

loopc5600:	; 800C5600
V1 = w[T8 + 0000];
T3 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
A3 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A2 = T7 + V0;
V1 = V1 >> 0c;
V1 = V1 & 0ff0;
A1 = T7 + V1;
V0 = w[A3 + 0000];
V1 = w[A2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C5644	nop
800C5648	nop
gte_NCLIP(); // Normal clipping
[T2 + fff0] = w(V0);
[T2 + fff8] = w(V1);
[T2 + 0000] = w(A0);
V0 = MAC0;
800C5660	nop
800C5664	blez   v0, Lc569c [$800c569c]
800C5668	nop
V0 = h[A3 + 000c];
800C5670	nop
800C5674	bne    v0, zero, Lc56b0 [$800c56b0]
800C5678	nop
V0 = h[A2 + 000c];
800C5680	nop
800C5684	bne    v0, zero, Lc56b0 [$800c56b0]
800C5688	nop
V0 = h[A1 + 000c];
800C5690	nop
800C5694	bne    v0, zero, Lc56b0 [$800c56b0]
800C5698	nop

Lc569c:	; 800C569C
V0 = w[T0 + 0000];
800C56A0	nop
V0 = V0 & T5;
800C56A8	j      Lc5710 [$800c5710]
[T0 + 0000] = w(V0);

Lc56b0:	; 800C56B0
A3 = w[A3 + 0004];
A2 = w[A2 + 0004];
A1 = w[A1 + 0004];
SZ1 = A3;
SZ2 = A2;
SZ3 = A1;
800C56C8	nop
800C56CC	nop
gte_AVSZ3(); // Average of three Z values
A0 = OTZ;
800C56D8	nop
A0 = A0 << 02;
A0 = A0 + S0;
V1 = w[T3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T5;
V0 = V0 & T4;
V1 = V1 | V0;
[T3 + 0000] = w(V1);
V0 = w[A0 + 0000];
V1 = T3 & T4;
V0 = V0 & T5;
V0 = V0 | V1;
[A0 + 0000] = w(V0);

Lc5710:	; 800C5710
T1 = T1 + 0001;
T2 = T2 + 0020;
T0 = T0 + 0020;
V0 = T1 < T9;
800C5720	bne    v0, zero, loopc5600 [$800c5600]
T8 = T8 + 000c;

Lc5728:	; 800C5728
S2 = w[S3 + 0008];
800C572C	nop
T9 = S2 & 00ff;
800C5734	beq    t9, zero, Lc5874 [$800c5874]
T1 = 0;
800C573C	lui    t5, $ff00
800C5740	lui    t4, $00ff
T4 = T4 | ffff;
T2 = T0 + 0010;

loopc574c:	; 800C574C
V1 = w[T8 + 0000];
T3 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
A3 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A2 = T7 + V0;
V1 = V1 >> 0c;
V1 = V1 & 0ff0;
A1 = T7 + V1;
V0 = w[A3 + 0000];
V1 = w[A2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C5790	nop
800C5794	nop
gte_NCLIP(); // Normal clipping
[T2 + fff8] = w(V0);
[T2 + fffc] = w(V1);
[T2 + 0000] = w(A0);
V0 = MAC0;
800C57AC	nop
800C57B0	blez   v0, Lc57e8 [$800c57e8]
800C57B4	nop
V0 = h[A3 + 000c];
800C57BC	nop
800C57C0	bne    v0, zero, Lc57fc [$800c57fc]
800C57C4	nop
V0 = h[A2 + 000c];
800C57CC	nop
800C57D0	bne    v0, zero, Lc57fc [$800c57fc]
800C57D4	nop
V0 = h[A1 + 000c];
800C57DC	nop
800C57E0	bne    v0, zero, Lc57fc [$800c57fc]
800C57E4	nop

Lc57e8:	; 800C57E8
V0 = w[T0 + 0000];
800C57EC	nop
V0 = V0 & T5;
800C57F4	j      Lc585c [$800c585c]
[T0 + 0000] = w(V0);

Lc57fc:	; 800C57FC
A3 = w[A3 + 0004];
A2 = w[A2 + 0004];
A1 = w[A1 + 0004];
SZ1 = A3;
SZ2 = A2;
SZ3 = A1;
gte_AVSZ3(); // Average of three Z values
A0 = OTZ;
800C5824	nop
A0 = A0 << 02;
A0 = A0 + S0;
V1 = w[T3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T5;
V0 = V0 & T4;
V1 = V1 | V0;
[T3 + 0000] = w(V1);
V0 = w[A0 + 0000];
V1 = T3 & T4;
V0 = V0 & T5;
V0 = V0 | V1;
[A0 + 0000] = w(V0);

Lc585c:	; 800C585C
T1 = T1 + 0001;
T2 = T2 + 0014;
T0 = T0 + 0014;
V0 = T1 < T9;
800C586C	bne    v0, zero, loopc574c [$800c574c]
T8 = T8 + 0008;

Lc5874:	; 800C5874
V0 = S2 & ff00;
T9 = V0 >> 08;
800C587C	beq    t9, zero, Lc59f4 [$800c59f4]
T1 = 0;
800C5884	lui    s1, $ff00
800C5888	lui    t6, $00ff
T6 = T6 | ffff;
T4 = T0 + 0014;

loopc5894:	; 800C5894
V1 = w[T8 + 0000];
T5 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
T2 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A3 = T7 + V0;
V0 = V1 >> 0c;
V0 = V0 & 0ff0;
A2 = T7 + V0;
V1 = V1 >> 18;
V1 = V1 << 04;
T3 = T7 + V1;
V0 = w[T2 + 0000];
V1 = w[A3 + 0000];
A0 = w[A2 + 0000];
A1 = w[T3 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C58E8	nop
800C58EC	nop
gte_NCLIP(); // Normal clipping
[T4 + fff4] = w(V0);
[T4 + fff8] = w(V1);
[T4 + fffc] = w(A0);
[T4 + 0000] = w(A1);
V0 = MAC0;
800C5908	nop
800C590C	blez   v0, Lc5944 [$800c5944]
800C5910	nop
V0 = h[T2 + 000c];
800C5918	nop
800C591C	bne    v0, zero, Lc5958 [$800c5958]
800C5920	nop
V0 = h[A3 + 000c];
800C5928	nop
800C592C	bne    v0, zero, Lc5958 [$800c5958]
800C5930	nop
V0 = h[A2 + 000c];
800C5938	nop
800C593C	bne    v0, zero, Lc5958 [$800c5958]
800C5940	nop

Lc5944:	; 800C5944
V0 = w[T0 + 0000];
800C5948	nop
V0 = V0 & S1;
800C5950	j      Lc59dc [$800c59dc]
[T0 + 0000] = w(V0);

Lc5958:	; 800C5958
V0 = w[T2 + 0004];
V1 = w[A3 + 0004];
800C5960	nop
V0 = V0 + V1;
V1 = w[A2 + 0004];
A0 = w[T3 + 0004];
V0 = V0 + V1;
V0 = V0 + A0;
V0 = V0 >> 04;
V0 = V0 << 02;
V0 = V0 + S0;
V1 = w[T5 + 0000];
V0 = w[V0 + 0000];
V1 = V1 & S1;
V0 = V0 & T6;
V1 = V1 | V0;
[T5 + 0000] = w(V1);
V1 = w[T2 + 0004];
V0 = w[A3 + 0004];
800C59A4	nop
V1 = V1 + V0;
V0 = w[A2 + 0004];
A0 = w[T3 + 0004];
V1 = V1 + V0;
V1 = V1 + A0;
V1 = V1 >> 04;
V1 = V1 << 02;
V1 = V1 + S0;
V0 = w[V1 + 0000];
A0 = T5 & T6;
V0 = V0 & S1;
V0 = V0 | A0;
[V1 + 0000] = w(V0);

Lc59dc:	; 800C59DC
T1 = T1 + 0001;
T4 = T4 + 0018;
T0 = T0 + 0018;
V0 = T1 < T9;
800C59EC	bne    v0, zero, loopc5894 [$800c5894]
T8 = T8 + 0008;

Lc59f4:	; 800C59F4
V0 = S2 >> 10;
T9 = V0 & 00ff;
800C59FC	beq    t9, zero, Lc5b3c [$800c5b3c]
T1 = 0;
800C5A04	lui    t5, $ff00
800C5A08	lui    t4, $00ff
T4 = T4 | ffff;
T2 = T0 + 0018;

loopc5a14:	; 800C5A14
V1 = w[T8 + 0000];
T3 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
A3 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A2 = T7 + V0;
V1 = V1 >> 0c;
V1 = V1 & 0ff0;
A1 = T7 + V1;
V0 = w[A3 + 0000];
V1 = w[A2 + 0000];
A0 = w[A1 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
gte_NCLIP(); // Normal clipping
[T2 + fff0] = w(V0);
[T2 + fff8] = w(V1);
[T2 + 0000] = w(A0);
V0 = MAC0;
800C5A74	nop
800C5A78	blez   v0, Lc5ab0 [$800c5ab0]
800C5A7C	nop
V0 = h[A3 + 000c];
800C5A84	nop
800C5A88	bne    v0, zero, Lc5ac4 [$800c5ac4]
800C5A8C	nop
V0 = h[A2 + 000c];
800C5A94	nop
800C5A98	bne    v0, zero, Lc5ac4 [$800c5ac4]
800C5A9C	nop
V0 = h[A1 + 000c];
800C5AA4	nop
800C5AA8	bne    v0, zero, Lc5ac4 [$800c5ac4]
800C5AAC	nop

Lc5ab0:	; 800C5AB0
V0 = w[T0 + 0000];
800C5AB4	nop
V0 = V0 & T5;
800C5ABC	j      Lc5b24 [$800c5b24]
[T0 + 0000] = w(V0);

Lc5ac4:	; 800C5AC4
A3 = w[A3 + 0004];
A2 = w[A2 + 0004];
A1 = w[A1 + 0004];
SZ1 = A3;
SZ2 = A2;
SZ3 = A1;
800C5ADC	nop
800C5AE0	nop
gte_AVSZ3(); // Average of three Z values
A0 = OTZ;
800C5AEC	nop
A0 = A0 << 02;
A0 = A0 + S0;
V1 = w[T3 + 0000];
V0 = w[A0 + 0000];
V1 = V1 & T5;
V0 = V0 & T4;
V1 = V1 | V0;
[T3 + 0000] = w(V1);
V0 = w[A0 + 0000];
V1 = T3 & T4;
V0 = V0 & T5;
V0 = V0 | V1;
[A0 + 0000] = w(V0);

Lc5b24:	; 800C5B24
T1 = T1 + 0001;
T2 = T2 + 001c;
T0 = T0 + 001c;
V0 = T1 < T9;
800C5B34	bne    v0, zero, loopc5a14 [$800c5a14]
T8 = T8 + 0010;

Lc5b3c:	; 800C5B3C
T9 = S2 >> 18;
800C5B40	beq    t9, zero, Lc5cb8 [$800c5cb8]
T1 = 0;
800C5B48	lui    s1, $ff00
800C5B4C	lui    t6, $00ff
T6 = T6 | ffff;
T4 = T0 + 0020;

loopc5b58:	; 800C5B58
V1 = w[T8 + 0000];
T5 = T0;
V0 = V1 & 00ff;
V0 = V0 << 04;
T2 = T7 + V0;
V0 = V1 & ff00;
V0 = V0 >> 04;
A3 = T7 + V0;
V0 = V1 >> 0c;
V0 = V0 & 0ff0;
A2 = T7 + V0;
V1 = V1 >> 18;
V1 = V1 << 04;
T3 = T7 + V1;
V0 = w[T2 + 0000];
V1 = w[A3 + 0000];
A0 = w[A2 + 0000];
A1 = w[T3 + 0000];
SXY0 = V0;
SXY2P = A0;
SXY1 = V1;
800C5BAC	nop
800C5BB0	nop
gte_NCLIP(); // Normal clipping
[T4 + ffe8] = w(V0);
[T4 + fff0] = w(V1);
[T4 + fff8] = w(A0);
[T4 + 0000] = w(A1);
V0 = MAC0;
800C5BCC	nop
800C5BD0	blez   v0, Lc5c08 [$800c5c08]
800C5BD4	nop
V0 = h[T2 + 000c];
800C5BDC	nop
800C5BE0	bne    v0, zero, Lc5c1c [$800c5c1c]
800C5BE4	nop
V0 = h[A3 + 000c];
800C5BEC	nop
800C5BF0	bne    v0, zero, Lc5c1c [$800c5c1c]
800C5BF4	nop
V0 = h[A2 + 000c];
800C5BFC	nop
800C5C00	bne    v0, zero, Lc5c1c [$800c5c1c]
800C5C04	nop

Lc5c08:	; 800C5C08
V0 = w[T0 + 0000];
800C5C0C	nop
V0 = V0 & S1;
800C5C14	j      Lc5ca0 [$800c5ca0]
[T0 + 0000] = w(V0);

Lc5c1c:	; 800C5C1C
V0 = w[T2 + 0004];
V1 = w[A3 + 0004];
800C5C24	nop
V0 = V0 + V1;
V1 = w[A2 + 0004];
A0 = w[T3 + 0004];
V0 = V0 + V1;
V0 = V0 + A0;
V0 = V0 >> 04;
V0 = V0 << 02;
V0 = V0 + S0;
V1 = w[T5 + 0000];
V0 = w[V0 + 0000];
V1 = V1 & S1;
V0 = V0 & T6;
V1 = V1 | V0;
[T5 + 0000] = w(V1);
V1 = w[T2 + 0004];
V0 = w[A3 + 0004];
800C5C68	nop
V1 = V1 + V0;
V0 = w[A2 + 0004];
A0 = w[T3 + 0004];
V1 = V1 + V0;
V1 = V1 + A0;
V1 = V1 >> 04;
V1 = V1 << 02;
V1 = V1 + S0;
V0 = w[V1 + 0000];
A0 = T5 & T6;
V0 = V0 & S1;
V0 = V0 | A0;
[V1 + 0000] = w(V0);

Lc5ca0:	; 800C5CA0
T1 = T1 + 0001;
T4 = T4 + 0024;
T0 = T0 + 0024;
V0 = T1 < T9;
800C5CB0	bne    v0, zero, loopc5b58 [$800c5b58]
T8 = T8 + 0014;

Lc5cb8:	; 800C5CB8
////////////////////////////////



////////////////////////////////
// funcc5cd4()

S5 = A0;
V1 = hu[S5 + 0018];
V0 = w[S5 + 001c];
S4 = w[S5 + 0020];
A3 = bu[A1 + 0000];
T0 = bu[A1 + 0001];
A2 = bu[A1 + 0002];
A0 = V1 + V0;
T4 = A3 << 04;
T5 = T0 << 04;
T6 = A2 << 04;
RBK = T4;
BBK = T5;
GBK = T6;
V0 = bu[A1 + 0003];
V1 = 1f800200;
V0 = V0 << 04;
[V1 + 0000] = h(V0);
V0 = bu[A1 + 0004];
800C5D44	nop
V0 = V0 << 04;
[1f800206] = h(V0);
V0 = bu[A1 + 0005];
800C5D58	nop
V0 = V0 << 04;
[1f80020c] = h(V0);
V0 = bu[A1 + 0006];
800C5D6C	nop
V0 = V0 << 04;
[1f800202] = h(V0);
V0 = bu[A1 + 0007];
800C5D80	nop
V0 = V0 << 04;
[1f800208] = h(V0);
V0 = bu[A1 + 0008];
800C5D94	nop
V0 = V0 << 04;
[1f80020e] = h(V0);
V0 = bu[A1 + 0009];
800C5DA8	nop
V0 = V0 << 04;
[1f800204] = h(V0);
V0 = bu[A1 + 000a];
800C5DBC	nop
V0 = V0 << 04;
[1f80020a] = h(V0);
V0 = bu[A1 + 000b];
[1f80021c] = w(0);
[1f800218] = w(0);
[1f800214] = w(0);
V0 = V0 << 04;
[1f800210] = h(V0);
T4 = w[V1 + 0000];
T5 = w[V1 + 0004];
LR1LR2 = T4;
LR3LG1 = T5;
T4 = w[V1 + 0008];
T5 = w[V1 + 000c];
T6 = w[V1 + 0010];
LG2LG3 = T4;
LB1LB2 = T5;
LB3 = T6;
V0 = bu[A1 + 000d];
V1 = bu[A1 + 000c];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0010] = h(V1);
V0 = bu[A1 + 000f];
V1 = bu[A1 + 000e];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0012] = h(V1);
V0 = bu[A1 + 0011];
V1 = bu[A1 + 0010];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0014] = h(V1);
V0 = bu[A1 + 0013];
V1 = bu[A1 + 0012];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0016] = h(V1);
V0 = bu[A1 + 0015];
V1 = bu[A1 + 0014];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0018] = h(V1);
V0 = bu[A1 + 0017];
V1 = bu[A1 + 0016];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 001a] = h(V1);
V0 = bu[A1 + 0019];
V1 = bu[A1 + 0018];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 001c] = h(V1);
V0 = bu[A1 + 001b];
V1 = bu[A1 + 001a];
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 001e] = h(V1);
V0 = bu[A1 + 001d];
V1 = bu[A1 + 001c];
[SP + 002c] = w(0);
[SP + 0028] = w(0);
[SP + 0024] = w(0);
V0 = V0 << 08;
V1 = V1 | V0;
[SP + 0020] = h(V1);
V0 = bu[S5 + 0003];
800C5EE0	nop
800C5EE4	beq    v0, zero, Lc60d8 [$800c60d8]
S1 = 0;
800C5EEC	lui    s3, $1f80
S3 = S3 | 0220;
S2 = SP + 0010;
S0 = A0;

Lc5efc:	; 800C5EFC
V0 = bu[S0 + 0000];
800C5F00	nop
800C5F04	beq    v0, zero, Lc60bc [$800c60bc]
S1 = S1 + 0001;
T4 = w[S2 + 0000];
T5 = w[S2 + 0004];
R11R12 = T4;
R13R21 = T5;
T4 = w[S2 + 0008];
T5 = w[S2 + 000c];
T6 = w[S2 + 0010];
R22R23 = T4;
R31R32 = T5;
R33 = T6;
V0 = bu[S0 + 0001];
800C5F38	nop
V0 = V0 << 05;
V0 = S4 + V0;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
800C5F5C	nop
800C5F60	nop
gte_rtir12(); // ir * rotmatrix
T4 = IR1;
T5 = IR2;
T6 = IR3;
[S3 + 0000] = h(T4);
[S3 + 0006] = h(T5);
[S3 + 000c] = h(T6);
V0 = bu[S0 + 0001];
800C5F84	nop
V0 = V0 << 05;
V0 = S4 + V0;
V0 = V0 + 0002;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
800C5FAC	nop
800C5FB0	nop
gte_rtir12(); // ir * rotmatrix
800C5FB8	lui    a3, $1f80
A3 = A3 | 0222;
T4 = IR1;
T5 = IR2;
T6 = IR3;
[A3 + 0000] = h(T4);
[A3 + 0006] = h(T5);
[A3 + 000c] = h(T6);
V0 = bu[S0 + 0001];
800C5FDC	nop
V0 = V0 << 05;
V0 = S4 + V0;
V0 = V0 + 0004;
T4 = hu[V0 + 0000];
T5 = hu[V0 + 0006];
T6 = hu[V0 + 000c];
IR1 = T4;
IR2 = T5;
IR3 = T6;
800C6004	nop
800C6008	nop
gte_rtir12(); // ir * rotmatrix
800C6010	lui    t0, $1f80
T0 = T0 | 0224;
T4 = IR1;
T5 = IR2;
T6 = IR3;
[T0 + 0000] = h(T4);
[T0 + 0006] = h(T5);
[T0 + 000c] = h(T6);
T4 = w[S2 + 0014];
T5 = w[S2 + 0018];
TRX = T4;
T6 = w[S2 + 001c];
TRY = T5;
TRZ = T6;
V0 = bu[S0 + 0001];
800C604C	nop
V0 = V0 << 05;
V0 = S4 + V0;
V0 = V0 + 0014;

Lc605c:	; 800C605C
T5 = hu[V0 + 0004];
T4 = hu[V0 + 0000];
T5 = T5 << 10;
T4 = T4 | T5;
VXY0 = T4;
VZ0 = w[V0 + 0008];
800C6074	nop
800C6078	nop
gte_rtv0tr(); // v0 * rotmatrix + tr vector
800C6080	lui    a2, $1f80
A2 = A2 | 0234;
[A2 + 0000] = w(IR1);
[A2 + 0004] = w(IR2);
[A2 + 0008] = w(IR3);
T4 = w[S3 + 0000];
T5 = w[S3 + 0004];
L11L12 = T4;
L13L21 = T5;
T4 = w[S3 + 0008];
T5 = w[S3 + 000c];
T6 = w[S3 + 0010];
L22L23 = T4;
L31L32 = T5;
L33 = T6;

Lc60bc:	; 800C60BC
800C60BC	jal    funcc6104 [$800c6104]
A0 = S0;
V0 = bu[S5 + 0003];
800C60C8	nop
V0 = S1 < V0;
800C60D0	bne    v0, zero, Lc5efc [$800c5efc]
S0 = S0 + 0020;

Lc60d8:	; 800C60D8
////////////////////////////////



////////////////////////////////
// funcc6104
T8 = A0;
V0 = hu[T8 + 000e];
V1 = w[T8 + 0018];
800C6110	lui    t6, $800c
T6 = T6 + 7938;
T1 = V0 + V1;
V0 = bu[800c752c];
A3 = w[T8 + 001c];
800C6128	beq    v0, zero, Lc613c [$800c613c]

V0 = hu[T8 + 0016];
800C6134	nop
A3 = A3 + V0;

Lc613c:	; 800C613C
T7 = w[T8 + 0004];
800C6140	nop
T3 = T7 & 00ff;
800C6148	beq    t3, zero, Lc61e0 [$800c61e0]
T0 = 0;
T2 = A3 + 0007;

loopc6154:	; 800C6154
V0 = w[A3 + 0000];
800C6158	nop
800C615C	beq    v0, zero, Lc61c8 [$800c61c8]
800C6160	nop
T4 = T1;
T5 = bu[T2 + 0000];
V1 = 0;
A2 = A3 + 0004;
A1 = 0004;
A0 = T1;

loopc617c:	; 800C617C
V0 = bu[A0 + 0007];
800C6180	nop
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
V0 = T4 + A1;
RGB = w[V0 + 0000];
800C619C	nop
800C61A0	nop
gte_NCCS(); // Normal color col. v0
[A2 + 0000] = w(RGB2);
A2 = A2 + 000c;
A1 = A1 + 0004;
V1 = V1 + 0001;
V0 = V1 < 0004;
800C61BC	bne    v0, zero, loopc617c [$800c617c]
A0 = A0 + 0004;
[T2 + 0000] = b(T5);

Lc61c8:	; 800C61C8
T0 = T0 + 0001;
T2 = T2 + 0034;
A3 = A3 + 0034;
V0 = T0 < T3;
800C61D8	bne    v0, zero, loopc6154 [$800c6154]
T1 = T1 + 0018;

Lc61e0:	; 800C61E0
V0 = T7 & ff00;
T3 = V0 >> 08;
800C61E8	beq    t3, zero, Lc6280 [$800c6280]
T0 = 0;
T2 = A3 + 0007;

loopc61f4:	; 800C61F4
V0 = w[A3 + 0000];
800C61F8	nop
800C61FC	beq    v0, zero, Lc6268 [$800c6268]
800C6200	nop
T4 = T1;
T5 = bu[T2 + 0000];
V1 = 0;
A2 = A3 + 0004;
A1 = 0004;
A0 = T1;

loopc621c:	; 800C621C
V0 = bu[A0 + 0007];
800C6220	nop
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
V0 = T4 + A1;
RGB = w[V0 + 0000];
800C623C	nop
800C6240	nop
gte_NCCS(); // Normal color col. v0
[A2 + 0000] = w(RGB2);
A2 = A2 + 000c;
A1 = A1 + 0004;
V1 = V1 + 0001;
V0 = V1 < 0003;
800C625C	bne    v0, zero, loopc621c [$800c621c]
A0 = A0 + 0004;
[T2 + 0000] = b(T5);

Lc6268:	; 800C6268
T0 = T0 + 0001;
T2 = T2 + 0028;
A3 = A3 + 0028;
V0 = T0 < T3;
800C6278	bne    v0, zero, loopc61f4 [$800c61f4]
T1 = T1 + 0014;

Lc6280:	; 800C6280
V0 = T7 >> 10;
T3 = V0 & 00ff;
800C6288	beq    t3, zero, Lc62f4 [$800c62f4]
T0 = 0;
A2 = T1 + 0004;
A1 = A3 + 0007;

loopc6298:	; 800C6298
V0 = w[A3 + 0000];
800C629C	nop
800C62A0	beq    v0, zero, Lc62d8 [$800c62d8]
A0 = A3 + 0004;
V0 = bu[A2 + 0003];
V1 = bu[A1 + 0000];
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
RGB = w[A2 + 0000];
800C62C4	nop
800C62C8	nop
gte_NCCS(); // Normal color col. v0
[A0 + 0000] = w(RGB2);
[A1 + 0000] = b(V1);

Lc62d8:	; 800C62D8
T0 = T0 + 0001;
A1 = A1 + 0028;
A3 = A3 + 0028;
A2 = A2 + 000c;
V0 = T0 < T3;
800C62EC	bne    v0, zero, loopc6298 [$800c6298]
T1 = T1 + 000c;

Lc62f4:	; 800C62F4
T3 = T7 >> 18;
800C62F8	beq    t3, zero, Lc6364 [$800c6364]
T0 = 0;
A2 = T1 + 0004;
A1 = A3 + 0007;

loopc6308:	; 800C6308
V0 = w[A3 + 0000];
800C630C	nop
800C6310	beq    v0, zero, Lc6348 [$800c6348]
A0 = A3 + 0004;
V0 = bu[A2 + 0003];
V1 = bu[A1 + 0000];
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
RGB = w[A2 + 0000];
800C6334	nop
800C6338	nop
gte_NCCS(); // Normal color col. v0
[A0 + 0000] = w(RGB2);
[A1 + 0000] = b(V1);

Lc6348:	; 800C6348
T0 = T0 + 0001;
A1 = A1 + 0020;
A3 = A3 + 0020;
A2 = A2 + 000c;
V0 = T0 < T3;
800C635C	bne    v0, zero, loopc6308 [$800c6308]
T1 = T1 + 000c;

Lc6364:	; 800C6364
T7 = w[T8 + 0008];
800C6368	nop
T3 = T7 & 00ff;
800C6370	beq    t3, zero, Lc63dc [$800c63dc]
T0 = 0;
A2 = T1 + 0004;
A1 = A3 + 0007;

loopc6380:	; 800C6380
V0 = w[A3 + 0000];
800C6384	nop
800C6388	beq    v0, zero, Lc63c0 [$800c63c0]
A0 = A3 + 0004;
V0 = bu[A2 + 0003];
V1 = bu[A1 + 0000];
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
RGB = w[A2 + 0000];
800C63AC	nop
800C63B0	nop
gte_NCCS(); // Normal color col. v0
[A0 + 0000] = w(RGB2);
[A1 + 0000] = b(V1);

Lc63c0:	; 800C63C0
T0 = T0 + 0001;
A1 = A1 + 0014;
A3 = A3 + 0014;
A2 = A2 + 0008;
V0 = T0 < T3;
800C63D4	bne    v0, zero, loopc6380 [$800c6380]
T1 = T1 + 0008;

Lc63dc:	; 800C63DC
V0 = T7 & ff00;
T3 = V0 >> 08;
800C63E4	beq    t3, zero, Lc6450 [$800c6450]
T0 = 0;
A2 = T1 + 0004;
A1 = A3 + 0007;

loopc63f4:	; 800C63F4
V0 = w[A3 + 0000];
800C63F8	nop
800C63FC	beq    v0, zero, Lc6434 [$800c6434]
A0 = A3 + 0004;
V0 = bu[A2 + 0003];
V1 = bu[A1 + 0000];
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
RGB = w[A2 + 0000];
800C6420	nop
800C6424	nop
gte_NCCS(); // Normal color col. v0
[A0 + 0000] = w(RGB2);
[A1 + 0000] = b(V1);

Lc6434:	; 800C6434
T0 = T0 + 0001;
A1 = A1 + 0018;
A3 = A3 + 0018;
A2 = A2 + 0008;
V0 = T0 < T3;
800C6448	bne    v0, zero, loopc63f4 [$800c63f4]
T1 = T1 + 0008;

Lc6450:	; 800C6450
V0 = T7 >> 10;
T3 = V0 & 00ff;
800C6458	beq    t3, zero, Lc64f0 [$800c64f0]
T0 = 0;
T2 = A3 + 0007;

loopc6464:	; 800C6464
V0 = w[A3 + 0000];
800C6468	nop
800C646C	beq    v0, zero, Lc64d8 [$800c64d8]
800C6470	nop
T4 = T1;
T5 = bu[T2 + 0000];
V1 = 0;
A2 = A3 + 0004;
A1 = 0004;
A0 = T1;

loopc648c:	; 800C648C
V0 = bu[A0 + 0007];
800C6490	nop
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
V0 = T4 + A1;
RGB = w[V0 + 0000];
800C64AC	nop
800C64B0	nop
gte_NCCS(); // Normal color col. v0
[A2 + 0000] = w(RGB2);
A2 = A2 + 0008;
A1 = A1 + 0004;
V1 = V1 + 0001;
V0 = V1 < 0003;
800C64CC	bne    v0, zero, loopc648c [$800c648c]
A0 = A0 + 0004;
[T2 + 0000] = b(T5);

Lc64d8:	; 800C64D8
T0 = T0 + 0001;
T2 = T2 + 001c;
A3 = A3 + 001c;
V0 = T0 < T3;
800C64E8	bne    v0, zero, loopc6464 [$800c6464]
T1 = T1 + 0010;

Lc64f0:	; 800C64F0
T3 = T7 >> 18;
800C64F4	beq    t3, zero, Lc658c [$800c658c]
T0 = 0;
T2 = A3 + 0007;

loopc6500:	; 800C6500
V0 = w[A3 + 0000];
800C6504	nop
800C6508	beq    v0, zero, Lc6574 [$800c6574]
800C650C	nop
T4 = T1;
T5 = bu[T2 + 0000];
V1 = 0;
A2 = A3 + 0004;
A1 = 0004;
A0 = T1;

loopc6528:	; 800C6528
V0 = bu[A0 + 0007];
800C652C	nop
V0 = V0 << 03;
V0 = T6 + V0;
VXY0 = w[V0 + 0000];
VZ0 = w[V0 + 0004];
V0 = T4 + A1;
RGB = w[V0 + 0000];
800C6548	nop
800C654C	nop
gte_NCCS(); // Normal color col. v0
[A2 + 0000] = w(RGB2);
A2 = A2 + 0008;
A1 = A1 + 0004;
V1 = V1 + 0001;
V0 = V1 < 0004;
800C6568	bne    v0, zero, loopc6528 [$800c6528]
A0 = A0 + 0004;
[T2 + 0000] = b(T5);

Lc6574:	; 800C6574
T0 = T0 + 0001;
T2 = T2 + 0024;
A3 = A3 + 0024;
V0 = T0 < T3;
800C6584	bne    v0, zero, loopc6500 [$800c6500]
T1 = T1 + 0014;

Lc658c:	; 800C658C
////////////////////////////////



////////////////////////////////
// wm_get_model_total_render_packets_size()

model = A0;

number_of_bones = bu[model + 2];
number_of_parts = bu[model + 3];

ret = number_of_bones * 20;

part = w[model + 1c] + hu[model + 18];

for( int i = 0; i < number_of_parts; ++i )
{
    ret = ret + hu[part + i * 20 + 16] * 2; // add size of both render packets size
}

return ret;
////////////////////////////////
