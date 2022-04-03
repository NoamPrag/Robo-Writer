#include <Vector.h>
#include <Bezier.h>
#include <Drawing.h>

const Bezier mustacheCurves[] = {
    Bezier(new Vector[4]{Vector(0.0, 0.0), Vector(-223.0, -18.0), Vector(-380.0, -153.0), Vector(-620.0, -535.0)}),
    Bezier(new Vector[4]{Vector(-620.0, -535.0), Vector(-804.0, -828.0), Vector(-967.0, -899.0), Vector(-1155.0, -770.0)}),
    Bezier(new Vector[4]{Vector(-1155.0, -770.0), Vector(-1208.0, -734.0), Vector(-1237.0, -705.0), Vector(-1292.0, -633.0)}),
    Bezier(new Vector[4]{Vector(-1292.0, -633.0), Vector(-1340.0, -570.0), Vector(-1375.0, -555.0), Vector(-1422.0, -578.0)}),
    Bezier(new Vector[4]{Vector(-1422.0, -578.0), Vector(-1470.0, -603.0), Vector(-1477.0, -634.0), Vector(-1456.0, -727.0)}),
    Bezier(new Vector[4]{Vector(-1456.0, -727.0), Vector(-1399.0, -969.0), Vector(-1261.0, -1182.0), Vector(-1085.0, -1299.0)}),
    Bezier(new Vector[4]{Vector(-1085.0, -1299.0), Vector(-1018.0, -1343.0), Vector(-952.0, -1378.0), Vector(-920.0, -1386.0)}),
    Bezier(new Vector[4]{Vector(-920.0, -1386.0), Vector(-912.0, -1388.0), Vector(-887.0, -1396.0), Vector(-865.0, -1404.0)}),
    Bezier(new Vector[4]{Vector(-865.0, -1404.0), Vector(-734.0, -1451.0), Vector(-493.0, -1455.0), Vector(-290.0, -1415.0)}),
    Bezier(new Vector[4]{Vector(-290.0, -1415.0), Vector(-30.0, -1362.0), Vector(131.0, -1283.0), Vector(300.0, -1124.0)}),
    Bezier(new Vector[4]{Vector(300.0, -1124.0), Vector(318.3333333333333, -1106.6666666666667), Vector(336.6666666666667, -1089.3333333333333), Vector(355.0, -1072.0)}),
    Bezier(new Vector[4]{Vector(355.0, -1072.0), Vector(379.0, -1094.6666666666667), Vector(403.0, -1117.3333333333333), Vector(427.0, -1140.0)}),
    Bezier(new Vector[4]{Vector(427.0, -1140.0), Vector(564.0, -1269.0), Vector(696.0, -1342.0), Vector(870.0, -1386.0)}),
    Bezier(new Vector[4]{Vector(870.0, -1386.0), Vector(1018.0, -1423.0), Vector(1036.0, -1426.0), Vector(1180.0, -1439.0)}),
    Bezier(new Vector[4]{Vector(1180.0, -1439.0), Vector(1601.0, -1476.0), Vector(1925.0, -1298.0), Vector(2094.0, -936.0)}),
    Bezier(new Vector[4]{Vector(2094.0, -936.0), Vector(2141.0, -836.0), Vector(2184.0, -678.0), Vector(2176.0, -637.0)}),
    Bezier(new Vector[4]{Vector(2176.0, -637.0), Vector(2167.0, -590.0), Vector(2143.0, -570.0), Vector(2098.0, -570.0)}),
    Bezier(new Vector[4]{Vector(2098.0, -570.0), Vector(2068.0, -570.0), Vector(2053.0, -576.0), Vector(2034.0, -597.0)}),
    Bezier(new Vector[4]{Vector(2034.0, -597.0), Vector(1874.0, -779.0), Vector(1796.0, -833.0), Vector(1694.0, -831.0)}),
    Bezier(new Vector[4]{Vector(1694.0, -831.0), Vector(1575.0, -830.0), Vector(1454.0, -739.0), Vector(1356.0, -576.0)}),
    Bezier(new Vector[4]{Vector(1356.0, -576.0), Vector(1163.0, -258.0), Vector(995.0, -78.0), Vector(838.0, -23.0)}),
    Bezier(new Vector[4]{Vector(838.0, -23.0), Vector(735.0, 13.0), Vector(512.0, 10.0), Vector(410.0, -29.0)}),
    Bezier(new Vector[4]{Vector(410.0, -29.0), Vector(356.0, -50.0), Vector(346.0, -50.0), Vector(315.0, -33.0)}),
    Bezier(new Vector[4]{Vector(315.0, -33.0), Vector(265.0, -6.0), Vector(121.0, 9.0), Vector(0.0, 0.0)}),
};

constexpr float mustacheScaleFactor = 0.004f;

const Vector mustacheOffset = Vector(0, 25);

const Drawing mustacheDrawing = Drawing(mustacheCurves, mustacheScaleFactor, mustacheOffset);
