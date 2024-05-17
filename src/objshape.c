#include <sm64.h>

void vtx_set(
	Vtx *vtx, int i, SHORT x, SHORT y, SHORT z, SHORT s, SHORT t,
	UCHAR r, UCHAR g, UCHAR b, UCHAR a
)
{
	vtx[i].v.ob[0] = x;
	vtx[i].v.ob[1] = y;
	vtx[i].v.ob[2] = z;
	vtx[i].v.flag  = 0;
	vtx[i].v.tc[0] = s;
	vtx[i].v.tc[1] = t;
	vtx[i].v.cn[0] = r;
	vtx[i].v.cn[1] = g;
	vtx[i].v.cn[2] = b;
	vtx[i].v.cn[3] = a;
}

SHORT roundftos(float x)
{
	if (x >= 0.0) return x + 0.5;
	else return x - 0.5;
}

s8 objshape_803612F0;
