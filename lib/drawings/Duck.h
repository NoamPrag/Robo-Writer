#include <Vector.h>
#include <Bezier.h>
#include <Drawing.h>

const Bezier duckCruves[] = {
    Bezier(new Vector[4]{Vector(0.0, 0.0), Vector(-490.0, -41.0), Vector(-745.0, -274.0), Vector(-718.0, -658.0)}),
    Bezier(new Vector[4]{Vector(-718.0, -658.0), Vector(-709.0, -780.0), Vector(-691.0, -864.0), Vector(-642.0, -1007.0)}),
    Bezier(new Vector[4]{Vector(-642.0, -1007.0), Vector(-570.0, -1214.0), Vector(-559.0, -1267.0), Vector(-584.0, -1287.0)}),
    Bezier(new Vector[4]{Vector(-584.0, -1287.0), Vector(-591.0, -1293.0), Vector(-646.0, -1307.0), Vector(-707.0, -1320.0)}),
    Bezier(new Vector[4]{Vector(-707.0, -1320.0), Vector(-942.0, -1368.0), Vector(-1230.0, -1460.0), Vector(-1398.0, -1539.0)}),
    Bezier(new Vector[4]{Vector(-1398.0, -1539.0), Vector(-1526.0, -1600.0), Vector(-1592.0, -1643.0), Vector(-1669.0, -1713.0)}),
    Bezier(new Vector[4]{Vector(-1669.0, -1713.0), Vector(-1704.0, -1746.0), Vector(-1739.0, -1770.0), Vector(-1751.0, -1770.0)}),
    Bezier(new Vector[4]{Vector(-1751.0, -1770.0), Vector(-1779.0, -1770.0), Vector(-1864.0, -1691.0), Vector(-1914.0, -1618.0)}),
    Bezier(new Vector[4]{Vector(-1914.0, -1618.0), Vector(-1935.0, -1586.0), Vector(-1973.0, -1520.0), Vector(-1998.0, -1470.0)}),
    Bezier(new Vector[4]{Vector(-1998.0, -1470.0), Vector(-2046.0, -1375.0), Vector(-2070.0, -1350.0), Vector(-2113.0, -1350.0)}),
    Bezier(new Vector[4]{Vector(-2113.0, -1350.0), Vector(-2158.0, -1350.0), Vector(-2188.0, -1385.0), Vector(-2223.0, -1473.0)}),
    Bezier(new Vector[4]{Vector(-2223.0, -1473.0), Vector(-2333.0, -1758.0), Vector(-2360.0, -2101.0), Vector(-2292.0, -2350.0)}),
    Bezier(new Vector[4]{Vector(-2292.0, -2350.0), Vector(-2265.0, -2447.0), Vector(-2186.0, -2609.0), Vector(-2128.0, -2686.0)}),
    Bezier(new Vector[4]{Vector(-2128.0, -2686.0), Vector(-2004.0, -2852.0), Vector(-1809.0, -2993.0), Vector(-1580.0, -3084.0)}),
    Bezier(new Vector[4]{Vector(-1580.0, -3084.0), Vector(-1558.0, -3092.6666666666665), Vector(-1536.0, -3101.3333333333335), Vector(-1514.0, -3110.0)}),
    Bezier(new Vector[4]{Vector(-1514.0, -3110.0), Vector(-1205.0, -3110.0), Vector(-896.0, -3110.0), Vector(-587.0, -3110.0)}),
    Bezier(new Vector[4]{Vector(-587.0, -3110.0), Vector(260.0, -3110.0), Vector(343.0, -3109.0), Vector(375.0, -3093.0)}),
    Bezier(new Vector[4]{Vector(375.0, -3093.0), Vector(427.0, -3069.0), Vector(582.0, -2918.0), Vector(650.0, -2826.0)}),
    Bezier(new Vector[4]{Vector(650.0, -2826.0), Vector(720.0, -2733.0), Vector(788.0, -2595.0), Vector(818.0, -2490.0)}),
    Bezier(new Vector[4]{Vector(818.0, -2490.0), Vector(845.0, -2396.0), Vector(856.0, -2198.0), Vector(839.0, -2108.0)}),
    Bezier(new Vector[4]{Vector(839.0, -2108.0), Vector(801.0, -1908.0), Vector(698.0, -1700.0), Vector(546.0, -1517.0)}),
    Bezier(new Vector[4]{Vector(546.0, -1517.0), Vector(502.0, -1463.0), Vector(498.0, -1455.0), Vector(504.0, -1422.0)}),
    Bezier(new Vector[4]{Vector(504.0, -1422.0), Vector(516.0, -1353.0), Vector(544.0, -1320.0), Vector(591.0, -1320.0)}),
    Bezier(new Vector[4]{Vector(591.0, -1320.0), Vector(609.0, -1320.0), Vector(672.0, -1309.0), Vector(733.0, -1295.0)}),
    Bezier(new Vector[4]{Vector(733.0, -1295.0), Vector(891.0, -1259.0), Vector(1027.0, -1191.0), Vector(1118.0, -1101.0)}),
    Bezier(new Vector[4]{Vector(1118.0, -1101.0), Vector(1238.0, -983.0), Vector(1273.0, -873.0), Vector(1266.0, -636.0)}),
    Bezier(new Vector[4]{Vector(1266.0, -636.0), Vector(1262.0, -494.0), Vector(1252.0, -464.0), Vector(1202.0, -442.0)}),
    Bezier(new Vector[4]{Vector(1202.0, -442.0), Vector(1161.0, -423.0), Vector(1143.0, -427.0), Vector(1030.0, -485.0)}),
    Bezier(new Vector[4]{Vector(1030.0, -485.0), Vector(971.0, -516.0), Vector(901.0, -545.0), Vector(873.0, -550.0)}),
    Bezier(new Vector[4]{Vector(873.0, -550.0), Vector(846.0, -554.0), Vector(822.0, -557.0), Vector(821.0, -556.0)}),
    Bezier(new Vector[4]{Vector(821.0, -556.0), Vector(820.0, -555.0), Vector(812.0, -519.0), Vector(803.0, -475.0)}),
    Bezier(new Vector[4]{Vector(803.0, -475.0), Vector(780.0, -361.0), Vector(721.0, -245.0), Vector(651.0, -174.0)}),
    Bezier(new Vector[4]{Vector(651.0, -174.0), Vector(512.0, -33.0), Vector(298.0, 24.0), Vector(0.0, 0.0)}),
};

constexpr float duckScaleFactor = 0.004;
const Vector duckOffset = Vector(10, 25);

const Drawing duckDrawing = Drawing(duckCruves, duckScaleFactor, duckOffset);
